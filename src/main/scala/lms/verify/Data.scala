package lms.verify

trait DataOps extends Dsl { self =>
  def and_list(bs: List[Rep[Boolean]]): Rep[Boolean] =
    bs.foldLeft[Rep[Boolean]](unit(true)){case (a,b) => boolean_and(a,b)}
  class Pointer[T:Iso](val p: List[Rep[Array[_]]]) {
    val iso = implicitly[Iso[T]]
    val pmt = p zip (iso.memList zip iso.typList)
    def apply(i: Rep[Int]) = iso.fromRepList(pmt.map{case (a,(m,t)) =>
      implicit val t1 = t.asInstanceOf[Typ[m.T]]
      val a1 = a.asInstanceOf[Rep[Array[m.T]]]
      a1(i)
    })
    def update(i: Rep[Int], v: T) = {
      val vs = iso.toRepList(v)
      (pmt zip vs).foreach{case ((a,(m,t)),b) =>
        implicit val t1 = t.asInstanceOf[Typ[m.T]]
        val a1 = a.asInstanceOf[Rep[Array[m.T]]]
        val b1 = b.asInstanceOf[Rep[m.T]]
        a1(i) = b1
      }
    }
    def valid(r: Rep[Range]) = and_list(pmt.map{case (a,(m,t)) =>
      implicit val t1 = t.asInstanceOf[Typ[m.T]]
      val a1 = a.asInstanceOf[Rep[Array[m.T]]]
      self.valid(a1, r)
    })
    def reflectMutableInput = pmt.foreach{case (a,(m,t)) =>
      implicit val t1 = t.asInstanceOf[Typ[m.T]]
      val a1 = a.asInstanceOf[Rep[Array[m.T]]]
      self.reflectMutableInput(a1)
    }
    def reflectMutableInput(r: Rep[Range]) = pmt.foreach{case (a,(m,t)) =>
      implicit val t1 = t.asInstanceOf[Typ[m.T]]
      val a1 = a.asInstanceOf[Rep[Array[m.T]]]
      self.reflectMutableInput(a1, r)
    }
    def assigns(r: Rep[Range]) = pmt.foreach{case (a,(m,t)) =>
      implicit val t1 = t.asInstanceOf[Typ[m.T]]
      val a1 = a.asInstanceOf[Rep[Array[m.T]]]
      self.assigns(a1, r)
    }
    def within(r: Rep[Range]): List[Rep[Any]] = pmt.map{case (a,(m,t)) =>
      implicit val t1 = t.asInstanceOf[Typ[m.T]]
      val a1 = a.asInstanceOf[Rep[Array[m.T]]]
      infix_within[m.T](a1, r)
    }
  }
  def separated[T1:Iso,T2:Iso](p1: Pointer[T1], i1: Rep[Int], p2: Pointer[T2], i2: Rep[Int]): Rep[Boolean] = and_list(p1.pmt.map{case (a01,(m01,t01)) =>
    implicit val t1 = t01.asInstanceOf[Typ[m01.T]]
    val a1 = a01.asInstanceOf[Rep[Array[m01.T]]]
    and_list(p2.pmt.map{case (a02,(m02,t02)) =>
      implicit val t2 = t02.asInstanceOf[Typ[m02.T]]
      val a2 = a02.asInstanceOf[Rep[Array[m02.T]]]
      separated(a1, i1, a2, i2)})
    })

  implicit def iso_pointer[T:Iso]: Iso[Pointer[T]] = new Iso[Pointer[T]] {
    val iso = implicitly[Iso[T]]
    val mt = iso.memList zip iso.typList
    def id = "p_"+iso.id
    def memList = iso.memList.map{m => new TypeMember { type T = Array[m.T] }}
    def typList = mt.map{case (m,t) =>
      val t1 = t.asInstanceOf[Typ[m.T]]
      t1.arrayTyp
    }
    def toRepList(x: Pointer[T]) = x.p
    def fromRepList(xs: List[Rep[_]]) = new Pointer(xs.asInstanceOf[List[Rep[Array[_]]]])
    def check(x: Pointer[T]) = unit(true)
  }
  trait Inv[T] {
    def check(v: T): Rep[Boolean]
  }
  def invariant[T](f: T => Rep[Boolean]): Inv[T] = new Inv[T] {
    override def check(v: T) = f(v)
  }
  implicit def inv_iso[T:Iso]: Inv[T] = new Inv[T] {
    override def check(v: T) = implicitly[Iso[T]].check(v)
  }
  implicit class CheckOps[T:Inv](v: T) {
    def check: Rep[Boolean] = {
      val o = implicitly[Inv[T]]
      o.check(v)
    }
  }
  trait Eq[T] {
    def eq(a: T, b: T): Rep[Boolean]
  }
  def equality[T:Iso](f: (T, T) => Rep[Boolean]) = new Eq[T] {
    val eq_fun: (T, T) => Rep[Boolean] = predicate("eq_"+implicitly[Iso[T]].id, {(a: T, b: T) => f(a, b)})
    override def eq(a: T, b: T) = eq_fun(a, b)
  }
  implicit def eq_rep[T:Typ]: Eq[Rep[T]] = new Eq[Rep[T]] {
    override def eq(a: Rep[T], b: Rep[T]) = __equal(a,b)
  }
  implicit class EqOps[T:Eq](a: T) {
    def deep_equal(b: T): Rep[Boolean] = {
      val o = implicitly[Eq[T]]
      o.eq(a, b)
    }
  }

  implicit def isodata[A:Inv,B:Iso](id0: String, ab: A => B, ba: B => A): Iso[A] = new Iso[A] {
    val ib = implicitly[Iso[B]]
    val inv_check: A => Rep[Boolean] = predicate("inv_"+id0,{x0: A => x0.check},code=false)(this)
    override def id = id0
    override def memList = ib.memList
    override def typList = ib.typList
    override def toRepList(x: A) = ib.toRepList(ab(x))
    override def fromRepList(xs: List[Rep[_]]) = ba(ib.fromRepList(xs))
    override def check(x: A) = inv_check(x)
  }
}
