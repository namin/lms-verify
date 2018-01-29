package lms.verify

import scala.lms.common._
import scala.reflect.SourceContext
import java.io.{PrintWriter,StringWriter,FileOutputStream}

trait VerifyOps extends Base with BooleanOps {
  def includes: List[String] = List("<limits.h>")
  def autoAssignNothing: Boolean = true

  def id_of(xs: List[String]) = xs.mkString("__", "_", "__")
  class TypeMember {
    type T
  }
  trait Iso[T] {
    def id: String
    def memList: List[TypeMember]
    def typList: List[Typ[_]]
    def toRepList(x:T): List[Rep[_]]
    def fromRepList(xs: List[Rep[_]]): T
    def check(x:T): Rep[Boolean]
  }
  trait Iso1[T] extends Iso[T] {
    type G
    val typ: Typ[G]
    def toRep(x:T): Rep[G]
    def fromRep(x: Rep[G]): T
    override def memList = List(new TypeMember { type T = G })
    override def typList = List(typ)
    override def toRepList(x: T) = List(toRep(x))
    override def fromRepList(xs: List[Rep[_]]) = fromRep(xs(0).asInstanceOf[Rep[G]])
  }
  implicit def iso1_unit: Iso1[Unit] = new Iso1[Unit] {
    override type G = Unit
    override val typ = implicitly[Typ[Unit]]
    override def toRep(x: Unit) = unit(x)
    override def fromRep(x: Rep[Unit]) = ()
    override def id = typ.toString
    override def check(x: Unit) = unit(true)
  }
  implicit def iso1_id[B:Typ]: Iso1[Rep[B]] = new Iso1[Rep[B]] {
    override type G = B
    override val typ = implicitly[Typ[G]]
    override def toRep(x: Rep[G]) = x
    override def fromRep(x: Rep[G]) = x
    override def id = typ.toString // TODO: should be valid C identifier, e.g. no generic bracket chars [ ]
    override def check(x: Rep[G]) = unit(true)
  }
  class IsoTup(isos: List[Iso[_]]) {
    val n = isos.length
    val lengths: List[Int] = for (iso <- isos) yield iso.typList.length
    val offsets: List[Int] = (for (i <- 0 to n) yield (lengths.slice(0, i).sum)).toList
    def id = id_of(isos.map(_.id))
    def memList = isos.flatMap(_.memList)
    def typList = isos.flatMap(_.typList)
    def slice(xs: List[Rep[_]])(i: Int) = xs.slice(offsets(i), offsets(i+1))
  }
  implicit def iso_tup2[A1,A2](implicit iso1: Iso[A1], iso2: Iso[A2]): Iso[(A1,A2)] = new Iso[(A1,A2)] {
    val isoTup = new IsoTup(List(iso1, iso2))
    override def id = isoTup.id
    override def memList = isoTup.memList
    override def typList = isoTup.typList
    override def toRepList(x:(A1,A2)) = iso1.toRepList(x._1) ++ iso2.toRepList(x._2)
    override def fromRepList(xs: List[Rep[_]]) = {
      val slice = isoTup.slice(xs)_
      (iso1.fromRepList(slice(0)), iso2.fromRepList(slice(1)))
    }
    override def check(x:(A1,A2)) = iso1.check(x._1) && iso2.check(x._2)
  }
  implicit def iso_tup3[A1,A2,A3](implicit iso1: Iso[A1], iso2: Iso[A2], iso3: Iso[A3]): Iso[(A1,A2,A3)] = new Iso[(A1,A2,A3)] {
    val isoTup = new IsoTup(List(iso1, iso2, iso3))
    override def id = isoTup.id
    override def memList = isoTup.memList
    override def typList = isoTup.typList
    override def toRepList(x:(A1,A2,A3)) = iso1.toRepList(x._1) ++ iso2.toRepList(x._2) ++ iso3.toRepList(x._3)
    override def fromRepList(xs: List[Rep[_]]) = {
      val slice = isoTup.slice(xs)_
      (iso1.fromRepList(slice(0)), iso2.fromRepList(slice(1)), iso3.fromRepList(slice(2)))
    }
    override def check(x:(A1,A2,A3)) = iso1.check(x._1) && iso2.check(x._2) && iso3.check(x._3)
  }
  implicit def iso_tup4[A1,A2,A3,A4](implicit iso1: Iso[A1], iso2: Iso[A2], iso3: Iso[A3], iso4: Iso[A4]): Iso[(A1,A2,A3,A4)] = new Iso[(A1,A2,A3,A4)] {
    val isoTup = new IsoTup(List(iso1, iso2, iso3, iso4))
    override def id = isoTup.id
    override def memList = isoTup.memList
    override def typList = isoTup.typList
    override def toRepList(x:(A1,A2,A3,A4)) = iso1.toRepList(x._1) ++ iso2.toRepList(x._2) ++ iso3.toRepList(x._3) ++ iso4.toRepList(x._4)
    override def fromRepList(xs: List[Rep[_]]) = {
      val slice = isoTup.slice(xs)_
      (iso1.fromRepList(slice(0)), iso2.fromRepList(slice(1)), iso3.fromRepList(slice(2)), iso4.fromRepList(slice(3)))
    }
    override def check(x:(A1,A2,A3,A4)) = iso1.check(x._1) && iso2.check(x._2) && iso3.check(x._3) && iso4.check(x._4)
  }
  implicit def iso_tup9[A1,A2,A3,A4,A5,A6,A7,A8,A9](implicit iso1: Iso[A1], iso2: Iso[A2], iso3: Iso[A3], iso4: Iso[A4], iso5: Iso[A5], iso6: Iso[A6], iso7: Iso[A7], iso8: Iso[A8], iso9: Iso[A9]): Iso[(A1,A2,A3,A4,A5,A6,A7,A8,A9)] = new Iso[(A1,A2,A3,A4,A5,A6,A7,A8,A9)] {
    val isoTup = new IsoTup(List(iso1, iso2, iso3, iso4, iso5, iso6, iso7, iso8, iso9))
    override def id = isoTup.id
    override def memList = isoTup.memList
    override def typList = isoTup.typList
    override def toRepList(x:(A1,A2,A3,A4,A5,A6,A7,A8,A9)) = iso1.toRepList(x._1) ++ iso2.toRepList(x._2) ++ iso3.toRepList(x._3) ++ iso4.toRepList(x._4) ++ iso5.toRepList(x._5) ++ iso6.toRepList(x._6) ++ iso7.toRepList(x._7) ++ iso8.toRepList(x._8) ++ iso9.toRepList(x._9)
    override def fromRepList(xs: List[Rep[_]]) = {
      val slice = isoTup.slice(xs)_
      (iso1.fromRepList(slice(0)), iso2.fromRepList(slice(1)), iso3.fromRepList(slice(2)), iso4.fromRepList(slice(3)), iso5.fromRepList(slice(4)), iso6.fromRepList(slice(5)), iso7.fromRepList(slice(6)), iso8.fromRepList(slice(7)), iso9.fromRepList(slice(8)))
    }
    override def check(x:(A1,A2,A3,A4,A5,A6,A7,A8,A9)) = iso1.check(x._1) && iso2.check(x._2) && iso3.check(x._3) && iso4.check(x._4) && iso5.check(x._5) && iso6.check(x._6) && iso7.check(x._7) && iso8.check(x._8) && iso9.check(x._9)
  }

  sealed abstract class Snip
  case class TopLevel[B](name: String, mAs: List[Typ[_]], mB:Typ[B], f: List[Rep[_]] => Rep[B], spec: Boolean, code: Boolean) extends Snip
  object TopLevel {
    def apply[B](name: String, mAs: List[Typ[_]], mB:Typ[B], f: List[Rep[_]] => Rep[B]): TopLevel[B] =
      TopLevel(name, mAs, mB, f, spec=false, code=true)
  }
  val rec = new scala.collection.mutable.LinkedHashMap[String,Snip]
  def mkTopLevel[B](name: String, mAs: List[Typ[_]], mB:Typ[B], f: List[Rep[_]] => Rep[B], pre: List[Rep[_]] => Rep[Boolean], post: List[Rep[_]] => Rep[B] => Rep[Boolean]) =
    TopLevel(name, mAs, mB, {xs =>
      requires{pre(xs)}
      ensures{r: Rep[B] => post(xs)(r)}(mB)
      f(xs)
    })
  def wrapf[A,B](f: A => B)(implicit ia: Iso[A], ib: Iso1[B]): List[Rep[_]] => Rep[ib.G] = {xs =>
    val a = ia.fromRepList(xs)
    requires{ia.check(a)}
    ensures{r: Rep[ib.G] => ia.check(a)}(ib.typ)
    ensures{r: Rep[ib.G] => ib.check(ib.fromRep(r))}(ib.typ)
    val b = f(a)
    ib.toRep(b)
  }
  def toplevel[A:Iso,B:Iso1](name: String, f: A => B, spec: Boolean = false, code: Boolean = true): A => B = {
    val ia = implicitly[Iso[A]]
    val ib = implicitly[Iso1[B]]
    val g = (x: A) => ib.fromRep(toplevelApply[ib.G](name, ia.toRepList(x))(ib.typ))
    rec.getOrElseUpdate(name, TopLevel(name, ia.typList, ib.typ, wrapf(f)(ia, ib), spec, code))
    g
  }
  def toplevel[A:Iso,B:Iso1](name: String, f: A => B, pre: A => Rep[Boolean], post: A => B => Rep[Boolean]): A => B = {
    val ia = implicitly[Iso[A]]
    val ib = implicitly[Iso1[B]]
    val g = (x: A) => ib.fromRep(toplevelApply[ib.G](name, ia.toRepList(x))(ib.typ))
    rec.getOrElseUpdate(name, mkTopLevel(name, ia.typList, ib.typ, wrapf(f)(ia, ib), xs => pre(ia.fromRepList(xs)), (xs: List[Rep[_]]) => (r: Rep[ib.G]) => post(ia.fromRepList(xs))(ib.fromRep(r))))
    g
  }

  def wrap2[A1,A2,B](f: (A1,A2) => B): ((A1,A2)) => B = {(x: (A1,A2)) => f(x._1, x._2)}
  def unwrap2[A1,A2,B](g: ((A1,A2)) => B): (A1,A2) => B = {(x1: A1, x2: A2) => g((x1, x2))}
  def wrap3[A1,A2,A3,B](f: (A1,A2,A3) => B): ((A1,A2,A3)) => B = {(x: (A1,A2,A3)) => f(x._1, x._2, x._3)}
  def unwrap3[A1,A2,A3,B](g: ((A1,A2,A3)) => B): (A1,A2,A3) => B = {(x1: A1, x2: A2, x3: A3) => g((x1, x2, x3))}
  def wrap4[A1,A2,A3,A4,B](f: (A1,A2,A3,A4) => B): ((A1,A2,A3,A4)) => B = {(x: (A1,A2,A3,A4)) => f(x._1, x._2, x._3, x._4)}
  def unwrap4[A1,A2,A3,A4,B](g: ((A1,A2,A3,A4)) => B): (A1,A2,A3,A4) => B = {(x1: A1, x2: A2, x3: A3, x4: A4) => g((x1, x2, x3, x4))}
  def wrap9[A1,A2,A3,A4,A5,A6,A7,A8,A9,B](f: (A1,A2,A3,A4,A5,A6,A7,A8,A9) => B): ((A1,A2,A3,A4,A5,A6,A7,A8,A9)) => B = {(x: (A1,A2,A3,A4,A5,A6,A7,A8,A9)) => f(x._1, x._2, x._3, x._4, x._5, x._6, x._7, x._8, x._9)}
  def unwrap9[A1,A2,A3,A4,A5,A6,A7,A8,A9,B](g: ((A1,A2,A3,A4,A5,A6,A7,A8,A9)) => B): (A1,A2,A3,A4,A5,A6,A7,A8,A9) => B = {(x1: A1, x2: A2, x3: A3, x4: A4, x5: A5, x6: A6, x7: A7, x8: A8, x9: A9) => g((x1, x2, x3, x4, x5, x6, x7, x8, x9))}

  def toplevel[A1:Iso,A2:Iso,B:Iso1](name: String, f: (A1,A2) => B): (A1,A2) => B = {
    unwrap2(toplevel(name, wrap2(f)))
  }
  def toplevel[A1:Iso,A2:Iso,A3:Iso,B:Iso1](name: String, f: (A1, A2, A3) => B): (A1, A2, A3) => B = {
    unwrap3(toplevel(name, wrap3(f)))
  }
  def toplevel[A1:Iso,A2:Iso,A3:Iso,A4:Iso,B:Iso1](name: String, f: (A1,A2,A3,A4) => B): (A1,A2,A3,A4) => B = {
    unwrap4(toplevel(name, wrap4(f)))
  }
  def toplevel[A1:Iso,A2:Iso,B:Iso1](name: String, f: (A1,A2) => B, pre: (A1,A2) => Rep[Boolean], post: (A1,A2) => B => Rep[Boolean]): (A1,A2) => B = {
    unwrap2(toplevel(name, wrap2(f), wrap2(pre), wrap2(post)))
  }
  def toplevel[A1:Iso,A2:Iso,A3:Iso,B:Iso1](name: String, f: (A1,A2,A3) => B, pre: (A1,A2,A3) => Rep[Boolean], post: (A1,A2,A3) => B => Rep[Boolean]): (A1,A2,A3) => B = {
    unwrap3(toplevel(name, wrap3(f), wrap3(pre), wrap3(post)))
  }
  def toplevel[A1:Iso,A2:Iso,A3:Iso,A4:Iso,B:Iso1](name: String, f: (A1,A2,A3,A4) => B, pre: (A1,A2,A3,A4) => Rep[Boolean], post: (A1,A2,A3,A4) => B => Rep[Boolean]): (A1,A2,A3,A4) => B = {
    unwrap4(toplevel(name, wrap4(f), wrap4(pre), wrap4(post)))
  }
  def toplevel[A1:Iso,A2:Iso,A3:Iso,A4:Iso,A5:Iso,A6:Iso,A7:Iso,A8:Iso,A9:Iso,B:Iso1](name: String, f: (A1,A2,A3,A4,A5,A6,A7,A8,A9) => B, pre: (A1,A2,A3,A4,A5,A6,A7,A8,A9) => Rep[Boolean], post: (A1,A2,A3,A4,A5,A6,A7,A8,A9) => B => Rep[Boolean]): (A1,A2,A3,A4,A5,A6,A7,A8,A9) => B = {
    unwrap9(toplevel(name, wrap9(f), wrap9(pre), wrap9(post)))
  }

  implicit def anyTyp: Typ[Any]
  def infix_arrayTyp[T](t: Typ[T]) = typ_arrayTyp[T](t)
  def typ_arrayTyp[T](t: Typ[T]): Typ[Array[T]]

  def valid[A](p: Rep[A]): Rep[Boolean]
  def valid[A](p: Rep[A], r: Rep[Any]): Rep[Boolean]
  def old[A:Typ](v: Rep[A]): Rep[A]
  def separated[A,B](p1: Rep[A], i1: Rep[Int], p2: Rep[B], i2: Rep[Int]): Rep[Boolean]

  def reflectMutableInput[A](v: Rep[A]): Rep[A]
  def reflectMutableInput[A](v: Rep[A], r: Rep[Range]): Rep[A]

  def assigns(s: Rep[Any]): Unit
  def assigns(s: Rep[Any], r: Rep[Any]): Unit

  def requires(c: => Rep[Boolean]): Unit
  def ensures[B:Typ](c: Rep[B] => Rep[Boolean]): Unit

  def toplevelApply[B:Typ](name: String, args: List[Rep[_]]): Rep[B]
  def exists[A:Typ](f: Rep[A] => Rep[Boolean]): Rep[Boolean]
  def forall[A:Typ](f: Rep[A] => Rep[Boolean]): Rep[Boolean]
  def infix_==>(a: Rep[Boolean], b: Rep[Boolean]): Rep[Boolean]
  def infix_within[A](p: Rep[Array[A]], r: Rep[Range]): Rep[Any]

  def loop(invariant: Rep[Int] => Rep[Boolean], assigns: Rep[Int] => Rep[List[Any]], variant: Rep[Int] => Rep[Int])(l: Rep[Unit]): Rep[Unit]
  def loop(invariant: => Rep[Boolean], assigns: => Rep[List[Any]], variant: => Rep[Int])(l: Rep[Unit]): Rep[Unit]
  def loop_invariant(invariant: => Rep[Boolean]): Unit
  def loop_assigns(s: => Rep[List[Any]]): Unit

  def _assert(cond: =>Rep[Boolean])(implicit pos: SourceContext): Rep[Unit]

  def predicate[A:Iso](name: String, f: A => Rep[Boolean], code: Boolean=true): A => Rep[Boolean] = {
    toplevel(name, f, spec=true, code=code)
  }
  def predicate[A1:Iso,A2:Iso](name: String, f: (A1,A2) => Rep[Boolean]): (A1,A2) => Rep[Boolean] = {
    unwrap2(toplevel(name, wrap2(f), spec=true))
  }

  implicit class RangeForall(r: Rep[Range]) {
    def forall(f: Rep[Int] => Rep[Boolean]): Rep[Boolean] = range_forall(r, f)
  }
  def range_forall(r: Rep[Range], f: Rep[Int] => Rep[Boolean]): Rep[Boolean]


  type Lc = String
  type Lc1 = Product1[Lc]
  implicit def lc1: Lc1 = Tuple1("L")
  implicit def lc2: (Lc,Lc) = ("L1","L2")
  implicit def lc3: (Lc,Lc,Lc) = ("L1","L2","L3")
  def lc_id[A<:Product](a: A): String =
    a.productIterator.map(_.toString).mkString("{", ",", "}")
  def logic[A<:Product,B:Iso,R:Iso1](id: String, ks: (A => B => R) => Unit)
      (implicit a0: A):
      (A => B => R) = {
    val ib = implicitly[Iso[B]]
    val ir = implicitly[Iso1[R]]
    val r = {a: A => b: B =>
      ir.fromRep(toplevelApply[ir.G](
        id+lc_id(a),
        ib.toRepList(b))(ir.typ))
    }
    _add_logic(id, lc_id(a0), a0.productArity, ib.typList, ir.typ, ks(r))
    r
  }
  def add_axiom[A<:Product,B:Iso,R:Iso1](id: String, k: A => B => R)(implicit a0: A): Unit = {
    val ib = implicitly[Iso[B]]
    val ir = implicitly[Iso1[R]]
    val name = id+lc_id(a0)
    _add_axiom[ir.G](name, a0.productArity, ib.typList, ir.typ, {xs => ir.toRep(k(a0)(ib.fromRepList(xs)))})
  }
  def inductive[A<:Product,B:Iso](id: String, ks: (A => B => Rep[Boolean]) => Unit)(implicit a0: A) =
    logic(id, ks)(implicitly[Iso[B]], iso1_id[Boolean], a0)
  def add_case[A<:Product,B:Iso](id: String, k: A => B => Rep[Boolean])(implicit a0: A) =
    add_axiom(id, k)(implicitly[Iso[B]], iso1_id[Boolean], a0)
  def at[A:Iso](a: A, lc: Lc): A = {
    val ia = implicitly[Iso[A]]
    ia.fromRepList(ia.toRepList(a).zip(ia.typList.zip(ia.memList)).map{case (x,(t,m)) => _at(x.asInstanceOf[Rep[m.T]], lc)(t.asInstanceOf[Typ[m.T]])})
  }
  def old[A:Iso](a: A): A = {
    val ia = implicitly[Iso[A]]
    ia.fromRepList(ia.toRepList(a).zip(ia.typList.zip(ia.memList)).map{case (x,(t,m)) => old[m.T](x.asInstanceOf[Rep[m.T]])(t.asInstanceOf[Typ[m.T]])})
  }
  def assigns[A:Iso](a: A): Unit = {
    val ia = implicitly[Iso[A]]
    ia.toRepList(a).foreach{x => assigns(x)}
  }

  case class Logic[B](name: String, suffix: String, bs: List[Typ[_]], rt: Typ[B], ks: List[TopLevel[B]]) extends Snip
  def _add_logic[B](name: String, suffix: String, n: Int, bs: List[Typ[_]], rt: Typ[B], ks: => Unit): Unit = {
    assert (pendingAxioms.isEmpty)
    ks
    val r = Logic[B](name, suffix, bs, rt, pendingAxioms.reverse.asInstanceOf[List[TopLevel[B]]])
    pendingAxioms = Nil
    rec.getOrElseUpdate(name, r)
    ()
  }
  var pendingAxioms: List[Axiom] = Nil
  type Axiom = TopLevel[_]
  def _add_axiom[B](name: String, n: Int, bs: List[Typ[_]], rt: Typ[B], k: List[Rep[_]] => Rep[B]): Unit = {
    pendingAxioms = TopLevel[B](name, bs, rt, k, true, false) :: pendingAxioms
  }

  def _at[A:Typ](a: Rep[A], lc: Lc): Rep[A]
}

trait VerifyOpsExp extends VerifyOps with EffectExp with RangeOpsExp with LiftBoolean with ListOpsExp with BooleanOpsExpOpt {
  implicit def anyTyp: Typ[Any] = manifestTyp
  def typ_arrayTyp[T](t: Typ[T]) = t.arrayTyp

  var suspendCSE: Boolean = false
  def reifySpec[A:Typ](block: => Exp[A]): Block[A] = {
    val savedCSE = suspendCSE
    suspendCSE = true
    try {
      reifyEffects(block)
    } finally {
      suspendCSE = savedCSE
    }
  }

  override protected implicit def toAtom[T:Typ](d: Def[T])(implicit pos: SourceContext): Exp[T] = {
    def a = super.toAtom[T](d)(implicitly[Typ[T]], pos)
    if (suspendCSE) d match {
      case _:Reify[_] => a
      case _:Reflect[_] => a
      case _ => reflectEffect(d)
    } else a
  }

  case class Valid[A](p: Rep[A], r: Option[Rep[Any]]) extends Def[Boolean]
  case class Old[A](v: Rep[A]) extends Def[A]
  case class Separated[A,B](p1: Rep[A], i1: Rep[Int], p2: Rep[B], i2: Rep[Int]) extends Def[Boolean]

  def valid[A](p: Rep[A]): Rep[Boolean] = Valid[A](p, None)
  def valid[A](p: Rep[A], r: Rep[Any]): Rep[Boolean] = Valid[A](p, Some(r))
  def old[A:Typ](v: Rep[A]): Rep[A] = Old[A](v)
  def separated[A,B](p1: Rep[A], i1: Rep[Int], p2: Rep[B], i2: Rep[Int]) = Separated[A,B](p1, i1, p2, i2)

  def reflectMutableInput[A](v: Rep[A]): Rep[A] =
    reflectMutableSym(v.asInstanceOf[Sym[A]])
  val inputs = new scala.collection.mutable.LinkedHashMap[Sym[Any], Rep[Range]]
  def reflectMutableInput[A](v: Rep[A], r: Rep[Range]): Rep[A] = {
    inputs += (v.asInstanceOf[Sym[Any]] -> r)
    reflectMutableInput(v)
  }

  case class Loc(s: Rep[Any], r: Option[Rep[Any]])
  var locs: List[Loc] = Nil
  def assigns(s: Rep[Any]): Unit = {
    locs = Loc(s, None)::locs
  }
  def assigns(s: Rep[Any], r: Rep[Any]): Unit = {
    locs = Loc(s, Some(r))::locs
  }

  case class Cond(t: () => Exp[Boolean])
  case class PostCond[A:Typ](t: Exp[A] => Exp[Boolean]) {
    def apply[B:Typ](r: Exp[B]) = {
      assert (implicitly[Typ[B]] == implicitly[Typ[A]])
      Cond{() => t(r.asInstanceOf[Exp[A]])}
    }
  }
  var preconds: List[Cond] = Nil
  def requires(c: => Rep[Boolean]): Unit = {
    preconds = Cond{() => c}::preconds
  }
  var postconds: List[PostCond[_]] = Nil
  def ensures[B:Typ](c: Rep[B] => Rep[Boolean]): Unit = {
    postconds = PostCond(c)::postconds
  }
  def reifyConds(cs: List[Cond]): Block[Boolean] = {
    reifySpec(cs.foldRight[Exp[Boolean]](unit(true)){case (Cond(t), b) => boolean_and(b, t())})
  }

  case class ToplevelApply[B:Typ](name: String, args: List[Rep[_]]) extends Def[B]
  val eff = new scala.collection.mutable.LinkedHashMap[String,(List[Sym[Any]], Summary)]
  def toplevelApply[B:Typ](name: String, args: List[Rep[_]]): Rep[B] = {
    if (suspendCSE) { // in spec
      rec.get(name) match {
        case Some(t:TopLevel[_]) if !t.spec =>
          // inline and ignore contract???
          val oldPreconds = preconds
          val oldPostconds = postconds
          try {
            return t.f(args).asInstanceOf[Rep[B]]
          } finally {
            preconds = oldPreconds
            postconds = oldPostconds
          }
        case _ =>
      }
    }
    eff.get(name) match {
      case Some((params,es)) =>
        val m = params.zip(args.map{x => x match {
          case s:Sym[Any] => s
          case _ => null
        }}).toMap
        val es2 = replaceInSummary(m, es)
        reflectEffect(ToplevelApply[B](name, args), es2)
      case None => reflectEffect(ToplevelApply[B](name, args))
    }
  }
  def replaceInSummary(m: Map[Sym[Any], Sym[Any]], es: Summary) = {
    def r1(x: Sym[Any]): List[Sym[Any]] = m.get(x) match {
      case Some(y) if y != null => y::Nil
      case _ => Nil
    }
    def r(xs: List[Sym[Any]]) = xs.flatMap(r1)
    Summary(es.maySimple, es.mstSimple, es.mayGlobal, es.mstGlobal, es.resAlloc, es.control, r(es.mayRead), r(es.mstRead), r(es.mayWrite), r(es.mstWrite))
  }

  case class Quantifier[A:Typ](k: String, x: Sym[A], y: Block[Boolean]) extends Def[Boolean]
  def quantifier[A:Typ](k: String, f: Rep[A] => Rep[Boolean]): Rep[Boolean] = {
    val x = fresh[A]
    val y = reifySpec(f(x))
    Quantifier(k, x, y)
  }
  def exists[A:Typ](f: Rep[A] => Rep[Boolean]): Rep[Boolean] =
    quantifier("\\exists", f)
  def forall[A:Typ](f: Rep[A] => Rep[Boolean]): Rep[Boolean] =
    quantifier("\\forall", f)
  case class Implies(a: Rep[Boolean], b: Rep[Boolean]) extends Def[Boolean]
  def infix_==>(a: Rep[Boolean], b: Rep[Boolean]): Rep[Boolean] = Implies(a, b)

  case class Within[A](p: Rep[Array[A]], r: Rep[Range]) extends Def[Any]
  def infix_within[A](p: Rep[Array[A]], r: Rep[Range]): Rep[Any] = Within[A](p, r)

  case class RangeForall(start: Exp[Int], end: Exp[Int], j: Sym[Int], i: Sym[Int], spec: Block[Boolean], body: Block[Boolean]) extends Def[Boolean]
  override def range_forall(r: Rep[Range], f: Rep[Int] => Rep[Boolean]): Rep[Boolean] = {
    val j = fresh[Int]
    val i = fresh[Int]
    val y = reifySpec(f(j))
    val a = reifyEffects(f(i)) // TODO: check no effects?
    y.res match {
      case Const(true) => Const(true)
      case Def(Reify(Const(true), _, _)) => Const(true)
      case _ =>
        reflectEffect(RangeForall(r.start, r.end, j, i, y, a), summarizeEffects(a).star)
    }
  }

  case class Loop(invariant: Block[Boolean], assigns: Block[List[Any]], variant: Block[Int]) extends Def[Unit]
  val loops = new scala.collection.mutable.LinkedHashMap[Sym[_], Loop]
  val loopsDone = new scala.collection.mutable.LinkedHashSet[Sym[_]]
  def loop(invariant: Rep[Int] => Rep[Boolean], assigns: Rep[Int] => Rep[List[Any]], variant: Rep[Int] => Rep[Int])(l: Rep[Unit]): Rep[Unit] = {
    val i = l match {
      case Def(Reflect(RangeForeach(_, _, i, _), _, _)) => i
    }
    loop(invariant(i), assigns(i), variant(i))(l)
  }
  def loop(invariant: => Rep[Boolean], assigns: => Rep[List[Any]], variant: => Rep[Int])(l: Rep[Unit]): Rep[Unit] = {
    val s = l.asInstanceOf[Sym[_]]
    val y1 = reifySpec(invariant)
    val y2 = reifySpec(assigns)
    val y3 = reifySpec(variant)
    val r = Loop(y1, y2, y3)
    loops.getOrElseUpdate(l.asInstanceOf[Sym[Unit]], r)
    l
  }

  val loopsExtraInvariants = new scala.collection.mutable.LinkedHashMap[Sym[_], List[Block[Boolean]]]
  var lp_invariants: List[Block[Boolean]] = Nil
  def loop_invariant(c: => Rep[Boolean]): Unit = {
    lp_invariants = reifySpec(c)::lp_invariants
  }
  val loopsExtraAssigns = new scala.collection.mutable.LinkedHashMap[Sym[_], List[Block[List[Any]]]]
  var lp_assigns: List[Block[List[Any]]] = Nil
  def loop_assigns(c: => Rep[List[Any]]): Unit = {
    lp_assigns = reifySpec(c)::lp_assigns
  }
  def reifyInvariants(b: => Exp[Unit]): Exp[Unit] = {
    val save_invariants = lp_invariants
    val save_assigns = lp_assigns
    lp_invariants = Nil
    lp_assigns = Nil
    try {
      val r = b
      if (!lp_invariants.isEmpty)
        loopsExtraInvariants.getOrElseUpdate(r.asInstanceOf[Sym[Unit]], lp_invariants)
      if (!lp_assigns.isEmpty)
        loopsExtraAssigns.getOrElseUpdate(r.asInstanceOf[Sym[Unit]], lp_assigns)
      return r
    } finally {
      lp_invariants = save_invariants
      lp_assigns = save_assigns
    }
  }
  override def range_foreach(r: Exp[Range], block: Exp[Int] => Exp[Unit])(implicit pos: SourceContext) : Exp[Unit] = {
    reifyInvariants{super.range_foreach(r, block)(pos)}
  }

  case class Assert(y: Block[Boolean]) extends Def[Unit]
  def _assert(cond: =>Rep[Boolean])(implicit pos: SourceContext): Rep[Unit] = {
    val y = reifySpec(cond)
    val r = reflectEffect(Assert(y))
    r
  }

  override def syms(e: Any): List[Sym[Any]] = e match {
    case Assert(y) => syms(y)
    case Quantifier(k, x, y) => syms(y)
    case RangeForall(start, end, j, i, spec, body) => syms(start):::syms(end):::syms(spec):::syms(body)
    case _ => super.syms(e)
  }

  override def boundSyms(e: Any): List[Sym[Any]] = e match {
    case Assert(y) => effectSyms(y)
    case Quantifier(k, x, y) => syms(x) ::: effectSyms(y)
    case RangeForall(start, end, j, i, y, z) => j :: i :: effectSyms(y) ::: effectSyms(z)
    case _ => super.boundSyms(e)
  }

  override def symsFreq(e: Any): List[(Sym[Any], Double)] = e match {
    case Assert(y) => freqCold(y)
    case Quantifier(k, x, y) => freqCold(y)
    case RangeForall(start, end, j, i, y, z) => freqNormal(start):::freqNormal(end):::freqCold(y):::freqHot(z)
    case _ => super.symsFreq(e)
  }

  case class At[A](a: Rep[A], lc: Lc) extends Def[A]
  def _at[A:Typ](a: Exp[A], lc: Lc): Exp[A] = At[A](a, lc)
}

trait Dsl extends VerifyOps with ScalaOpsPkg with TupledFunctions with UncheckedOps with LiftPrimitives with LiftString with LiftVariables with LiftBoolean with LiftNumeric with ZeroVal {
  implicit def repStrToSeqOps(a: Rep[String]) = new SeqOpsCls(a.asInstanceOf[Rep[Seq[Char]]])
  override def infix_&&(lhs: Rep[Boolean], rhs: => Rep[Boolean])(implicit pos: SourceContext): Rep[Boolean] = __ifThenElse(lhs, rhs, unit(false))
}

trait Impl extends Dsl with VerifyOpsExp with ScalaOpsPkgExp with IfThenElseExpOpt with TupledFunctionsRecursiveExp with UncheckedOpsExp with ZeroValExp { self =>
  val codegen = new CCodeGenPkg with CGenVariables with CGenTupledFunctions with CGenUncheckedOps {
    var emitFileAndLine: Boolean = false
    override def quote(x: Exp[Any]) = x match {
      case Const(true) => "1/*true*/"
      case Const(false) => "0/*false*/"
      case Const(null) => "0/*null*/"
      case Const(c: Char) if c==0.toChar => "'\\0'"
      case Const(c: Char) if c=='\r' => "'\\r'"
      case Const(s: String) =>
        // undo CCodegen
        super.quote(x).stripPrefix("string(").stripSuffix(")")
      case _ => super.quote(x)
    }

    override def remap[A](m: Typ[A]): String = {
      val s = m.toString
      if (s.startsWith("Array["))
        return remapWithRef(m.typeArguments.head)
      val tpe = super.remap(m)
      if (tpe.startsWith("int") || tpe.startsWith("uint") || tpe=="bool")
        if (s == "Char") "char" else "int"
      else if (tpe == "string") "char "
      else tpe
    }
    override def remapWithRef[A](m: Typ[A]): String = {
      val r = super.remapWithRef[A](m)
      // the remapping in core LMS seems very convoluted...
      if (inAxiom && r.startsWith("int")) {
        if (r.contains("*")) r.replace("integer ", "int ") else r.replace("int ", "integer ")
      } else r
    }
    override def isPrimitiveType(tpe: String): Boolean = {
      tpe match {
        case "int" | "uint" | "char" => true
        case _ => super.isPrimitiveType(tpe)
      }
    }
    override def emitValDef(sym: Sym[Any], rhs: String): Unit = {
      if (!isVoidType(sym.tp)) super.emitValDef(sym, rhs)
      else emitVoid(rhs)
    }
    override def emitVarDef(sym: Sym[Variable[Any]], rhs: String): Unit = {
      if (!isVoidVar(sym)) super.emitVarDef(sym, rhs)
      else emitVoid(rhs)
    }
    override def emitAssignment(sym: Sym[Any], rhs: String): Unit = {
      if (!isVoidVar(sym)) super.emitAssignment(sym, rhs)
      else emitVoid(rhs)
    }
    def isVoidVar(sym: Sym[Any]) = isVoidType(sym.tp.typeArguments.head)
    def emitVoid(rhs: String): Unit = {
      if (rhs.contains("("))
        stream.println(rhs + ";")
    }

    val default_m =  Map[Sym[_], String]()
    val emitted = new scala.collection.mutable.LinkedHashSet[Sym[_]]
    def exprOfBlock[A](kw: String, e: Block[A], m: Map[Sym[_], String] = Map(), end:String = ""): String = {
      val r = exprOfBlock(e, m)
      r match {
        case "\\true" => ""
        case _ => kw + " " + r + ";" + end
      }
    }
    def exprOfBlock[A](e: Block[A], m: Map[Sym[_], String]): String =
      exprOf(e.res, m)
    def exprOfDef[A](d: Def[A], m: Map[Sym[_], String]): String = d match {
      case ToplevelApply(name, es) => name+"("+es.map(exprOf(_, m)).mkString(",")+")"
      case Old(v) => "\\old("+exprOf(v, m)+")"
      case Valid(p, or) => or match {
        case None => "\\valid("+exprOf(p, m)+")"
        case Some(r) => "\\valid("+exprOf(p, m)+"+"+exprOf(r, m)+")"
      }
      case Separated(p1, i1, p2, i2) => "\\separated("+exprOf(p1, m)+"+"+exprOf(i1, m)+","+exprOf(p2, m)+"+"+exprOf(i2, m)+")"
      case At(a, lc) => "\\at("+exprOf(a, m)+","+lc+")"
      case Until(a, b) => b match {
        case Const(c:Int) => "("+exprOf(a, m)+".."+(c-1)+")"
        case Def(IntPlus(c1, Const(1))) => "("+exprOf(a, m)+".."+exprOf(c1, m)+")"
        case _ => "("+exprOf(a, m)+".."+exprOf(b, m)+"-1)"
      }
      case Quantifier(k, x, y) => "("+k+" "+remapWithRef(x.tp)+" "+quote(x)+"; "+exprOfBlock(y, m)+")"
      case Implies(a, b) => "("+exprOf(a, m)+" ==> "+exprOf(b, m)+")"
      case Within(p, r) => exprOf(p, m)+"["+exprOf(r, m)+"]"
      case Equal(a, b) => "("+exprOf(a, m)+"=="+exprOf(b, m)+")"
      case NotEqual(a, b) => "("+exprOf(a, m)+"!="+exprOf(b, m)+")"
      case OrderingGTEQ(a, b) => "("+exprOf(a, m)+">="+exprOf(b, m)+")"
      case OrderingGT(a, b) => "("+exprOf(a, m)+">"+exprOf(b, m)+")"
      case OrderingLTEQ(a, b) => "("+exprOf(a, m)+"<="+exprOf(b, m)+")"
      case OrderingLT(a, b) => "("+exprOf(a, m)+"<"+exprOf(b, m)+")"
      case BooleanAnd(a, b) => "("+exprOf(a, m)+" &&\n"+exprOf(b, m)+")"
      case IfThenElse(a, Block(Const(true)), Block(Const(false))) => exprOf(a, m)
      case IfThenElse(a, Block(Def(Reify(Const(true), _, _))), Block(Const(false))) => exprOf(a, m)
      case IfThenElse(a, b, Block(Const(false))) => "("+exprOf(a, m)+" &&\n "+exprOfBlock(b, m)+")"
      case BooleanOr(a, b) => "("+exprOf(a, m)+" || "+exprOf(b, m)+")"
      case BooleanNegate(a) => "(!"+exprOf(a, m)+")"
      case ObjIntMaxValue() => "INT_MAX"
      case ObjIntMinValue() => "INT_MIN"
      case IntPlus(a, b) => "("+exprOf(a, m)+"+"+exprOf(b, m)+")"
      case IntMinus(a, b) => "("+exprOf(a, m)+"-"+exprOf(b, m)+")"
      case IntTimes(a, b) => "("+exprOf(a, m)+"*"+exprOf(b, m)+")"
      case IntMod(a, b) => "("+exprOf(a, m)+"%"+exprOf(b, m)+")"
      case IntBinaryAnd(a, b) => "("+exprOf(a, m)+"&"+exprOf(b, m)+")"
      case ArrayApply(p, i) => exprOf(p, m)+"["+exprOf(i, m)+"]"
      case Reify(r, _, _) => exprOf(r, m)
      case Reflect(r, _, _) => exprOfDef(r, m)
      case ReadVar(Variable(s@Sym(n))) => if (isVoidVar(s)) "" else quote(s)
      case ListNew(xs) => xs.map(exprOf(_, m)).filter(_.nonEmpty).mkString(", ")
      // FIXME: only works for strings / Seq[Char] / Array[Char]
      case SeqLength(x) => "strlen("+exprOf(x, m)+")"
      case ArrayLength(x) => "strlen("+exprOf(x, m)+")"
      case RangeForall(z, n, j, _, y, _) =>
        s"(\\forall int ${exprOf(j, m)}; (${exprOf(z, m)}<=${exprOf(j,m)}<${exprOf(n,m)}) ==> ${exprOfBlock(y, m)})"
      case _ => "TODO:Def:"+d
    }
    def exprOf[A](e: Exp[A], m: Map[Sym[_], String] = Map()): String = e match {
      case Const(b: Boolean) => "\\"+b.toString
      case Const(_) => quote(e)
      case s@Sym(n) => s match {
        case Def(d) if !emitted(s) => exprOfDef(d, m)
        case _ => m.get(s) match {
          case Some(v) => v
          case None => quote(e)
        }
      }
    }

    override def emitNode(sym: Sym[Any], rhs: Def[Any]) = {
      emitted += sym
      if (emitFileAndLine && !rhs.isInstanceOf[Reflect[_]]) {
        val s = quotePos(sym).split("//")(0).split(":")
        stream.println(s"""#line ${s(1)} "${s(0)}" """)
      }
      def printExtraLoopInvariants() = loopsExtraInvariants.get(sym) match {
        case None =>
        case Some(ys) => ys.reverse.foreach{ y =>
          stream.println(exprOfBlock("loop invariant", y))
        }
      }
      def printLoopAssigns(s: String) = stream.println(loopsExtraAssigns.get(sym) match {
        case None => s
        case Some(ys) =>
          // ignore s for now, because if auto-inferred, it includes the full pointer
          // even though we assign only to indices
          ys.reverse.map(exprOfBlock(_, default_m)).mkString("loop assigns ", ", ", ";")
      })
      rhs match {
        case ToplevelApply(name, args) => emitValDef(sym, name+args.map(quote).mkString("(", ",", ")"))
        case Assert(y) => stream.println(exprOfBlock("/*@assert", y, end="*/"))
        case ArrayApply(x,n) => emitValDef(sym, quote(x) + "[" + quote(n) + "]")
        case ArrayUpdate(x,n,y) => stream.println(quote(x) + "[" + quote(n) + "] = " + quote(y) + ";")
        // TODO: the LMS C codegen should be updated to use emitAssignment instead
        case Assign(Variable(a), b) => emitAssignment(a.asInstanceOf[Sym[Variable[Any]]], quote(b))
        case SeqLength(x) =>
          // FIXME: only works for strings / Seq[Char]
          emitValDef(sym, "strlen("+quote(x)+")")
        case SeqApply(x,n) => emitValDef(sym, quote(x) + "[" + quote(n) + "]")
        case _ if loops.contains(sym) && !loopsDone.contains(sym) =>
          loopsDone += sym
          val Loop(invariant, assigns, variant) = loops.get(sym).get
          stream.println("/*@")
          stream.println(exprOfBlock("loop invariant", invariant))
          printExtraLoopInvariants()
          printLoopAssigns(exprOfBlock("loop assigns", assigns))
          if (!variant.res.isInstanceOf[Const[_]])
            stream.println(exprOfBlock("loop variant", variant))
          stream.println("*/")
          super.emitNode(sym, rhs)
        case RangeForeach(start, end, i, body) if !loopsDone.contains(sym) =>
          loopsDone += sym
          stream.println("/*@")
          end match {
            case Def(IntMinus(_,Const(1))) =>
              stream.println("loop invariant ("+quote(i)+"==0 && "+quote(end)+"==-1) || (0<="+quote(i)+"<="+quote(end)+");")
            case _ =>
              stream.println("loop invariant 0<="+quote(i)+"<="+quote(end)+";")
          }
          val s = summarizeEffects(body)
          val xs = for (x <- s.mayWrite) yield (inputs.get(x) match {
            case Some(r) => quote(x)+"["+exprOf(r)+"]"
            case None => quote(x)
          })
          printExtraLoopInvariants()
          printLoopAssigns("loop assigns "+quote(i)+(if (xs.isEmpty) "" else ", ")+xs.mkString(", ")+";")
          stream.println("loop variant "+quote(end)+"-"+quote(i)+";")
          stream.println("*/")
          super.emitNode(sym, rhs)
        case RangeForall(start, end, j, i, y, body) =>
          gen"""int $sym = 1;
               |/*@ loop invariant (0 <= $i <= $end);
               |    loop invariant \forall int $j; (0 <= $j < $i) ==> ${exprOfBlock("", y)}
               |    loop assigns $i;
               |    loop variant ($end-$i); */
               |for (int $i = $start; $i < $end; $i++) {
               |  ${nestedBlock(body)}
               |  if (!${getBlockResult(body)}) { $sym = 0; break; }
               |}"""
        case _ => super.emitNode(sym, rhs)
      }
    }

    def emitHeader[B](functionName: String, out: PrintWriter)(mAs: List[Typ[_]], mB: Typ[B]): Unit = {
      val args = mAs.map(fresh(_))
      val r = fresh[B](mB)
      val sB = remapWithRef(mB).trim()
      val sig = functionName+"("+(args.map(s => remapWithRef(s.tp)+" "+quote(s))).mkString(", ")+")"
      withStream(out) {
        stream.println(sB+" "+sig+";");
      }
    }

    var inAxiom: Boolean = false;
    def emitLogic[B](x: Logic[B], out: PrintWriter): Unit = {
      inAxiom = true
      withStream(out) {
        stream.println("/*@")
        val args = x.bs.map(fresh(_))
        val sig = x.name+x.suffix+"("+(args.map(s => remapWithRef(s.tp)+" "+quote(s))).mkString(", ")+")"
        stream.println(s"inductive $sig {")
        x.ks.foreach{ k =>
          emitVerify[B](k.f, x.name+"_"+k.name, spec=true, code=false, axiom=true, out)(k.mAs, k.mB)
        }
        stream.println("}")
        stream.println("*/")
      }
      inAxiom = false
    }

    def emitVerify[B](f: List[Exp[_]] => Exp[B], functionName: String, spec: Boolean, code: Boolean, axiom: Boolean, out: PrintWriter)(mAs: List[Typ[_]], mB: Typ[B]): Unit = {
      val args = mAs.map(fresh(_))
      val r = fresh[B](mB)
      val oldFns = rec.keys.toSet
      val body = reifyBlock(f(args))(mB)
      eff.getOrElseUpdate(functionName, (args, summarizeEffects(body)))
      val preBody = reifyConds(preconds)
      preconds = Nil
      val postBody = reifyConds(postconds.map{f => f(r)(mB)})
      postconds = Nil
      val sB = remapWithRef(mB).trim()
      val y = getBlockResult(body)
      val assignsNothing = autoAssignNothing && {
        val s = summarizeEffects(body)
        s.mayWrite.isEmpty && s.mstWrite.isEmpty
      }
      val customAssignsStr =
        if (!locs.isEmpty) {
          assert(!assignsNothing)
          locs.reverse.map{ case Loc(s, or) =>
            or match {
              case None => exprOf(s)
              case Some(r) => exprOf(s)+"["+exprOf(r)+"]"
            }
          }.mkString("assigns ", ", ", ";")
        } else ""
      locs = Nil // reset

      val fns = rec.keys.toSet -- oldFns
      fns.foreach { case k =>
        val t = rec(k)
        t match {
          case (x:TopLevel[_]) if (!x.spec) =>
            if (x.code)
              emitHeader(x.name, out)(x.mAs, mtype(x.mB))
        } // other cases (spec and ind) are TODOs...
      }
      val sig_args = (args.map(s => remapWithRef(s.tp)+" "+quote(s))).mkString(", ")
      val sig = functionName+"("+sig_args+")"
      val sig_app = functionName+"("+(args.map(s => quote(s))).mkString(", ")+")"
      withStream(out) {
        if (spec) {
          if (!axiom)
            stream.println("/*@ predicate "+sig+" = "+exprOfBlock[B](body, default_m)+";*/")
          else {
            stream.println(s"case $functionName:")
            if (args.nonEmpty) stream.print(s"\\forall $sig_args; ")
            stream.println(exprOfBlock[B](body, default_m)+";")
          }
        }
        if (code) {
          val preStr = exprOfBlock("requires", preBody)
          val postStr = exprOfBlock("ensures", postBody, Map(r -> "\\result"))
          if (!preStr.isEmpty || assignsNothing || !customAssignsStr.isEmpty || !postStr.isEmpty || spec) {
            stream.println("/*@")
            stream.println(preStr)
            if (assignsNothing) stream.println("assigns \\nothing;")
            stream.println(postStr)
            if (spec) {
              stream.println("ensures \\result <==> "+sig_app+";")
            }
            if (!customAssignsStr.isEmpty) stream.println(customAssignsStr)
            stream.println("*/")
          }

          stream.println(sB+" "+sig+" {")
          emitBlock(body)

          if (remap(y.tp) != "void")
            stream.println("return " + quote(y) + ";")

          stream.println("}")
        }
      }
    }
    val IR: self.type = self
  }
  def emitAll(stream: java.io.PrintWriter): Unit = {
    assert(codegen ne null) //careful about initialization order
    includes.foreach { i => stream.println("#include "+i) }
    rec.foreach { case (k,s) => s match {
      case (x:TopLevel[_]) =>
        codegen.emitVerify(x.f, x.name, x.spec, x.code, axiom=false, stream)(x.mAs, mtype(x.mB))
      case (x:Logic[_]) =>
        codegen.emitLogic(x, stream)
    }}
  }
  lazy val code: String = {
    val source = new java.io.StringWriter()
    val stream = new PrintWriter(source)
    emitAll(stream)
    source.toString
  }
}
