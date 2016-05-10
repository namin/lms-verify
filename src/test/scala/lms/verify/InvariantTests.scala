package lms.verify

class InvariantTests extends TestSuite {
  val under = "inv"

  trait Vectors extends Dsl {
    // TODO: generalize whatever works into a library
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
      def reflectMutable = pmt.foreach{case (a,(m,t)) =>
        implicit val t1 = t.asInstanceOf[Typ[m.T]]
        val a1 = a.asInstanceOf[Rep[Array[m.T]]]
        reflectMutableInput(a1)
      }
    }
    def infix_arrayTyp[T](t: Typ[T]) = ???
    implicit def iso_pointer[T:Iso]: Iso[Pointer[T]] = new Iso[Pointer[T]] {
      val iso = implicitly[Iso[T]]
      val mt = iso.memList zip iso.typList
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
    implicit class CheckOps[T:Inv](v: T) {
      def check: Rep[Boolean] = {
        val o = implicitly[Inv[T]]
        o.check(v)
      }
    }
    trait Eq[T] {
      def eq(a: T, b: T): Rep[Boolean]
    }
    def equality[T](f: (T, T) => Rep[Boolean]) = new Eq[T] {
      override def eq(a: T, b: T) = f(a,b)
    }
    implicit class EqOps[T:Eq](a: T) {
      def deep_equal(b: T): Rep[Boolean] = {
        val o = implicitly[Eq[T]]
        o.eq(a, b)
      }
    }
    implicit class RangeForall(r: Rep[Range]) {
      def forall(f: Rep[Int] => Rep[Boolean]): Rep[Boolean] = ???
    }

    class Vec[T:Iso](val a: Pointer[T], val n: Rep[Int]) {
      def apply(i: Rep[Int]) = a(i)
    }

    implicit def vecInv[T:Inv] = invariant[Vec[T]] { x =>
      unit(0) <= x.n && ((unit(0) until x.n).forall{i: Rep[Int] => x(i).check})
    }
    implicit def vecEq[T:Eq] = equality[Vec[T]] { (x, y) =>
      x.n == y.n && ((unit(0) until x.n).forall{i: Rep[Int] => x(i) deep_equal y(i)})
    }
  }
  test("0") {

  }
}
