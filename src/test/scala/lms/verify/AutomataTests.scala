package lms.verify

// ported from github.com/namin/lms-regexp

import scala.lms.common._
import scala.lms.internal.NestedBlockTraversal
import scala.lms.util.ClosureCompare
import scala.reflect.SourceContext

// from ../common/FunctionsDef.scala

trait FunctionsExternalDef extends FunctionsExp with BlockExp with ClosureCompare {
  case class DefineFun[A,B](res: Block[B])(val arg: Sym[A]) extends Def[A=>B]

  override def syms(e: Any): List[Sym[Any]] = e match {
    case DefineFun(y) => syms(y)
    case _ => super.syms(e)
  }

  override def boundSyms(e: Any): List[Sym[Any]] = e match {
    case f@DefineFun(y) => f.arg::effectSyms(y)
    case _ => super.boundSyms(e)
  }

  override def symsFreq(e: Any): List[(Sym[Any], Double)] = e match {
    case DefineFun(y) => freqHot(y)
    case _ => super.symsFreq(e)
  }

  var extfunTable: List[(Sym[_], Any)] = List()
  override def doLambda[A:Typ,B:Typ](f: Exp[A]=>Exp[B])(implicit pos: SourceContext): Exp[A=>B] = {
    var can = canonicalize(f)

    extfunTable.find(_._2 == can) match {
      case Some((funSym, _)) =>
        funSym.asInstanceOf[Sym[A=>B]]
      case _ =>
        val funSym = fresh[A=>B]
        val argSym = fresh[A]

        extfunTable = (funSym,can)::extfunTable

        val y = reifyEffects(f(argSym))

        createDefinition(funSym, DefineFun[A,B](y)(argSym))
        funSym
    }
  }
}

// from Lib.scala

case class Automaton[@specialized(Char) I, @specialized(Boolean,Byte) O](out: O, next: I => Automaton[I,O])

// from Base.scala

trait Regexp {
  type RE

  val id: RE
  def c(c0: Char): RE
  def in(a: Char, b: Char): RE
  def alt(x: RE, y: RE): RE
  def seq(x: RE, y: RE): RE
  def star(x: RE): RE

  def opt(x: RE): RE = alt(x, id)
  def plus(x: RE): RE =  seq(x, star(x))
  def many(f: (RE, RE) => RE)(x: RE, xs: RE*): RE = xs.length match {
    case 0 => x
    case 1 => f(x, xs(0))
    case n => f(x, many(f)(xs(0), xs.slice(1, n) : _*))
  }
}

// from Automata.scala

trait DFAOps extends Base with PrimitiveOps {
  implicit def dfaStateTyp: Typ[DfaState]

  type DfaState = Automaton[Char,Byte]

  type DIO = Rep[DfaState]

  def dfa_trans(f: Rep[Char] => DIO): DIO = dfa_trans(false)(f)
  def dfa_trans(e: Boolean)(f: Rep[Char] => DIO): DIO
}


trait DFAOpsExp extends BaseExp with PrimitiveOpsExp with DFAOps { this: Functions =>
  implicit def dfaStateTyp: Typ[DfaState]   = manifestTyp

  case class DFAState(e: Boolean, f: Rep[Char => DfaState]) extends Def[DfaState]

  def dfa_trans(e: Boolean)(f: Rep[Char] => DIO): DIO = DFAState(e, doLambda(f))
}


trait StabilityCalculator extends NestedBlockTraversal {
  val IR: DFAOpsExp with FunctionsExternalDef
  import IR._

  def stable(e: Boolean, sym: Sym[Any], dfa: DFAState): Boolean = {
    var processed = Set[Sym[Any]]()

    def rec(x: (Sym[Any], DFAState)): Boolean = {
      val sym = x._1
      val dfa = x._2
      if (processed.contains(sym)) return true
      if (dfa.e != e) return false
      processed += sym
      dfa.f match {
        case Def(g@DefineFun(y)) =>
          getFreeVarBlock(y.asInstanceOf[Block[Any]], List(g.arg)).collect{case sym@Def(dfa:DFAState) =>
            (sym,dfa)}.forall(rec)
      }
    }

    rec(sym, dfa)
  }
}


trait NFAtoDFA extends DFAOps with ClosureCompare { this: Dsl with Functions =>
  type NIO = List[NTrans]

  case class NTrans(c: CharSet, e: () => Boolean, s: () => NIO) extends Ordered[NTrans] {
    override def compare(o: NTrans) = {
      val i = this.c.compare(o.c)
      if (i != 0) i else {
        val i2 = this.e().compare(o.e())
        if (i2 != 0) i2 else {
          val tf = canonicalize(this.s())
          val of = canonicalize(o.s())
          if (tf == of) 0 else tf.compare(of)
	      }
      }
    }
  }

  def trans(c: CharSet)(s: () => NIO): NIO = scala.collection.immutable.List(NTrans(c, () => false, s))

  def guard(cond: CharSet, found: => Boolean = false)(e: => NIO): NIO = {
    scala.collection.immutable.List(NTrans(cond, () => found, () => e))
  }

  def guards(conds: List[CharSet], found: Boolean = false)(e: => NIO): NIO = {
    conds.flatMap(guard(_, found)(e))
  }

  def stop(): NIO = Nil


  sealed abstract class CharSet extends Ordered[CharSet] {
    override def compare(o: CharSet) = (this,o) match {
      case (W,W) => 0
      case (W,_) => 1
      case (_,W) => -1
      case (R(a1,b1),R(a2,b2)) if a1 == a2 => b1.compare(b2)
      case (R(a1,_),R(a2,_)) => a1.compare(a2)
      case (R(_,_),C(_)) => -1
      case (C(_),R(_,_)) => 1
      case (C(c1),C(c2)) => c1.compare(c2)
    }
  }
  case class R(a: Char, b: Char) extends CharSet
  case class C(c: Char) extends CharSet
  case object W extends CharSet

  def r(a: Char, b: Char) = {
    assert(a <= b)
    if (a == b) C(a) else R(a, b)
  }

  def infix_contains(s: CharSet, c: Rep[Char]): Rep[Boolean] = s match {
    case C(c1) => c == c1
    case R(a, b) => a <= c && c <= b
    case W => unit(true)
  }

  def infix_knowing(s1: CharSet, s2: CharSet): Option[CharSet] = (s1,s2) match {
    case (W,_) => Some(W)
    case (C(c1),C(c2)) if c1 == c2 => Some(W)
    case (R(a1,b1),R(a2,b2)) if a2 <= a1 && b1 <= b2 => Some(W)
    case (C(c1),R(a2,b2)) if a2 <= c1 && c1 <= b2 => Some(W)
    case (R(a1,b1),R(a2,b2)) if a1 <= a2 && a2 <= b1 && b1 <= b2 => Some(r(a2, b1))
    case (R(a1,b1),R(a2,b2)) if a2 <= a1 && a1 <= b2 && b2 <= b1 => Some(r(a1, b2))
    case (R(a1,b1),C(c2)) if a1 <= c2 && c2 <= b1 => Some(s1)
    case _ => None
  }

  def infix_knowing_not(s1: CharSet, s2: CharSet): Option[CharSet] = (s1,s2) match {
    case (C(c1), C(c2)) if c1 == c2 => None
    case (R(a1,b1),R(a2,b2)) if a2 <= a1 && b1 <= b2 => None
    case (C(c1),R(a2,b2)) if a2 <= c1 && c1 <= b2 => None
    case (R(a1,b1),R(a2,b2)) if a1 <= a2 && a2 <= b1 && b1 <= b2 => Some(r(a1, a2))
    case (R(a1,b1),R(a2,b2)) if a2 <= a1 && a1 <= b2 && b2 <= b1 => Some(r(b2, b1))
    case _ => Some(s1)
  }

  def exploreNFA[A:Typ](xs: NIO, cin: Rep[Char])(k: (Boolean, NIO) => Rep[A]): Rep[A] = xs match {
    case Nil => k(false, Nil)
    case NTrans(W, e, s)::rest =>
      val (xs1, xs2) = xs.partition(_.c != W)
      exploreNFA(xs1,cin)((flag,acc) => k(flag || xs2.exists(_.e()), acc ++ xs2.flatMap(_.s())))
    case NTrans(cset, e, s)::rest =>
      if (cset contains cin) {
        val xs1 = for (NTrans(rcset, re, rs) <- rest;
		       kcset <- rcset knowing cset) yield
			 NTrans(kcset,re,rs)
        exploreNFA(xs1,cin)((flag,acc) => k(flag || e(), acc ++ s()))
      } else {
        val xs1 = for (NTrans(rcset, re, rs) <- rest;
		       kcset <- rcset knowing_not cset) yield
			 NTrans(kcset,re,rs)
        exploreNFA(xs1, cin)(k)
      }
  }


  def convertNFAtoDFA(in: (NIO, Boolean)): DIO = {

    def iterate(flag: Boolean, state: NIO): DIO = {
      val state_cooked = if (state.isEmpty) state else {
        val state_sorted = state.sorted
        state_sorted.head :: (for ((s,sn) <- (state_sorted zip state_sorted.tail)
             if s.compare(sn) != 0) yield sn)
      }
      //println("// cooked state: " + state_cooked)
      dfa_trans(flag){ c: Rep[Char] => exploreNFA(state_cooked, c) { iterate }
    }}

    iterate(in._2, in._1)
  }
}

trait RegexpToNFA extends Regexp { this: NFAtoDFA =>
  type RE = (() => (NIO, Boolean)) => (NIO, Boolean)

  def wrap(cset: CharSet): RE = { nio: (() => (NIO, Boolean)) =>
    (guard(cset, nio()._2)(nio()._1), false)
  }

  def c(c0: Char): RE = wrap(C(c0))
  def in(a: Char, b: Char): RE = wrap(r(a, b))
  val wildcard: RE = wrap(W)

  def alt(x: RE, y: RE): RE = { nio: (() => (NIO, Boolean)) =>
    val (nx, ex) = x(nio)
    val (ny, ey) = y(nio)
    (nx ++ ny, ex || ey)
  }

  def seq(x: RE, y: RE): RE = { nio: (() => (NIO, Boolean)) =>
    x(() => y(nio))
  }

  val id = {nio: (() => (NIO, Boolean)) => nio()}

  def star(x: RE): RE = { nio: (() => (NIO, Boolean)) =>
    val (nn, en) = nio()
    def rec(): (NIO, Boolean) = {
      val (nx, ex) = x(rec)
      (nn ++ nx, en || ex)
    }
    rec()
  }

  def convertREtoDFA(re: RE): DIO = convertNFAtoDFA(re(() => (Nil, true)))
}

trait DslAutomata extends DFAOps with NFAtoDFA with RegexpToNFA with Functions with Dsl

trait ImplAutomata extends DslAutomata with DFAOpsExp with FunctionsExternalDef with Impl with IfThenElseExpExtra /*with IfThenElseFatExp*/ { self =>
  override val codegen = new CCodeGenDslAutomata {
    val IR: self.type = self
  }
}

trait CCodeGenDslAutomata extends CCodeGenDsl {
  val IR: ImplAutomata

  import java.io.{File, FileWriter, PrintWriter}

  import IR._

  // hack to work with CompileScala
  def pack(dio: => DIO): (Exp[String] => Exp[Boolean]) = {
    (x: Exp[String]) => dio.asInstanceOf[Exp[Boolean]]
  }
  override def emitSource[A,B](f: Exp[A] => Exp[B], className: String, out: PrintWriter)(implicit mA: Typ[A], mB: Typ[B]): List[(Sym[Any], Any)] = {
    emitAutomata(f(null).asInstanceOf[DIO], className, out)
    scala.collection.immutable.List()
  }

  class Collector extends NestedBlockTraversal with StabilityCalculator {
    val IR: CCodeGenDslAutomata.this.IR.type = CCodeGenDslAutomata.this.IR

    var stableStates: Set[Sym[Any]] = scala.collection.immutable.Set[Sym[Any]]()
    override def traverseStm(stm: Stm) = stm match {
      case TP(sym, rhs) => rhs match {
        case dfa@DFAState(b, f) =>
          if (stable(b, sym, dfa)) stableStates += sym
        case _ =>
      }
    }
  }

  var dfaStableStates: Set[Sym[Any]] = _
  var firstFun: Boolean = true
  var booleanStage: Boolean = false

  override def emitNode(sym: Sym[Any], rhs: Def[Any]) = rhs match {
    case g@DefineFun(y) =>
      stream.println((if (firstFun) "if" else "else if")+" (id == "+sym.id+") {")
      firstFun = false
      emitValDef(g.arg, "c")
      emitBlock(y)
      stream.println(quote(getBlockResult(y)))
      stream.println("}")
    case dfa@DFAState(b,f) =>
    case _ => super.emitNode(sym, rhs)
  }

  override def quote(x: Exp[Any]) : String = x match {
    case Def(dfa@DFAState(b,Sym(fn))) =>
      if (booleanStage) b.toString
      else if (dfaStableStates.contains(x.asInstanceOf[Sym[Any]])) { "return " + b }
      else fn.toString
    case _ => super.quote(x)
  }

  override def emitForwardDef[A:Typ](args: List[Typ[_]], functionName: String, out: PrintWriter) = {
  }

  def emitAutomata(automaton: DIO, className: String, out: PrintWriter) {
    val block = reifyBlock(automaton)
    val collector = new Collector()
    collector.traverseBlock(block)
    dfaStableStates = collector.stableStates

    withStream(out) {
      stream.println("class "+className+" extends (String=>Boolean) {")
      stream.println("def apply(input: String): Boolean = {")
      stream.println("val n = input.length")
      booleanStage = true
      stream.println("if (n == 0) return " + quote(getBlockResult(block)))
      booleanStage = false
      stream.println("var id = " + quote(getBlockResult(block)))
      stream.println("var i = 0")
      stream.println("val n_dec = n-1")
      stream.println("while (i < n_dec) {")
      stream.println("val c = input.charAt(i)")
      stream.println("id =")

      firstFun = true
      booleanStage = false
      emitBlock(block)
      stream.println("else { throw new RuntimeException(\"invalid state \" + id) }")
      stream.println("i += 1")
      stream.println("}")

      stream.println("val c = input.charAt(i)")
      firstFun = true
      booleanStage = true
      emitBlock(block)
      stream.println("else { throw new RuntimeException(\"invalid state \" + id) }")

      stream.println("}")
      stream.println("}")
    }
  }
}

/*
import org.scalatest._

class TestRegexp extends Suite {
  trait BaseExamples extends Regexp {
    lazy val digit = in('0', '9')
    lazy val usd = many(seq)(c('u'), c('s'), c('d'), c(' '), opt(alt(c('+'), c('-'))),
      plus(digit), c('.'), digit, digit)
  }

  trait Examples extends BaseExamples with DSL {
    val aab = many(seq)(star(wildcard), c('A'), c('A'), c('B'))
    val aabx = many(seq)(star(wildcard), c('A'), c('A'), c('B'), star(c('X')))
    val aabany = many(seq)(star(wildcard), c('A'), c('A'), c('B'), star(wildcard))
    val fool = alt(seq(wildcard, opt(c('B'))), seq(wildcard, opt(c('A'))))
    val fool2 = many(alt)(seq(wildcard, opt(c('B'))), seq(wildcard, opt(c('C'))), seq(wildcard, c('A')))
    val fool3 = many(alt)(seq(wildcard, opt(c('B'))), seq(wildcard, opt(c('C'))), seq(c('X'), c('A')))
    val any = many(seq)(star(wildcard), opt(c('A')), star(wildcard))
  }

  trait Evaluator extends DSL with Impl {
    def recompile(re: RE) = {
      val f = (x: Rep[Unit]) => convertREtoDFA(re)
      dumpGeneratedCode = true
      val fc = compile(f)
      fc
    }
    def begmatch(fc: Unit => DfaState)(input: String): Boolean = {
      var state = fc()
      var i = 0
      val n = input.length
      while ((state.out % 2 != 1) && (i < n)) {
        state = state.next(input.charAt(i))
        i += 1
      }
      state.out % 2 == 1
    }
    def fullmatch(fc: Unit => DfaState)(input: String): Boolean = {
      var state = fc()
      var i = 0
      val n = input.length
      while ((state.out & 2) != 2 && (i < n)) {
        state = state.next(input.charAt(i))
        i += 1
      }
      state.out % 2 == 1
    }
  }

  def testAAB = {
    val exs = new Examples with Evaluator
    val fc = exs.recompile(exs.aab)

    expect(true){exs.fullmatch(fc)("AAB")}
    expect(true){exs.fullmatch(fc)("XYZAAB")}
    expect(true){exs.fullmatch(fc)("XYZABAAB")}
    expect(false){exs.fullmatch(fc)("XYZAABX")}
    expect(true){exs.begmatch(fc)("XYZAABX")}
    expect(false){exs.begmatch(fc)("XYZABX")}
    expect(false){exs.begmatch(fc)("")}
    expect(false){exs.fullmatch(fc)("")}
  }

  def testAABX = {
    val exs = new Examples with Evaluator
    val fc = exs.recompile(exs.aabx)

    expect(true){exs.fullmatch(fc)("AAB")}
    expect(true){exs.fullmatch(fc)("XYZAAB")}
    expect(true){exs.fullmatch(fc)("XYZABAAB")}
    expect(true){exs.fullmatch(fc)("XYZAABX")}
    expect(true){exs.begmatch(fc)("XYZAABX")}
    expect(false){exs.begmatch(fc)("XYZABX")}
    expect(false){exs.begmatch(fc)("")}
    expect(false){exs.fullmatch(fc)("")}
  }

  def testAABany = {
    val exs = new Examples with Evaluator
    val fc = exs.recompile(exs.aabany)

    expect(true){exs.fullmatch(fc)("AAB")}
    expect(true){exs.fullmatch(fc)("XYZAAB")}
    expect(true){exs.fullmatch(fc)("XYZABAAB")}
    expect(true){exs.fullmatch(fc)("XYZAABX")}
    expect(true){exs.fullmatch(fc)("XYZAABXYZ")}
    expect(true){exs.begmatch(fc)("XYZAABX")}
    expect(false){exs.begmatch(fc)("XYZABX")}
    expect(false){exs.begmatch(fc)("")}
    expect(false){exs.fullmatch(fc)("")}
  }

  def testUSD = {
    val exs = new Examples with Evaluator
    val fc = exs.recompile(exs.usd)

    expect(true){exs.fullmatch(fc)("usd 1234.00")}
    expect(true){exs.fullmatch(fc)("usd 1234.01")}
    expect(false){exs.fullmatch(fc)("usd 1234.01  ")}
    expect(true){exs.begmatch(fc)("usd 1234.01  ")}
    expect(false){exs.fullmatch(fc)("usd1234.00")}
    expect(false){exs.fullmatch(fc)("usd 1234")}
    expect(false){exs.begmatch(fc)("  usd 1234.01  ")}
    expect(false){exs.begmatch(fc)("")}
    expect(false){exs.fullmatch(fc)("")}
  }

  def testFool = {
    val exs = new Examples with Evaluator
    val fc = exs.recompile(exs.fool)

    expect(false){exs.begmatch(fc)("")}
    expect(false){exs.fullmatch(fc)("")}
    expect(true){exs.fullmatch(fc)("X")}
    expect(true){exs.fullmatch(fc)("XA")}
    expect(true){exs.fullmatch(fc)("XB")}
    expect(false){exs.fullmatch(fc)("XC")}
  }

  def testFool2 = {
    val exs = new Examples with Evaluator
    val fc = exs.recompile(exs.fool2)

    expect(false){exs.begmatch(fc)("")}
    expect(false){exs.fullmatch(fc)("")}
    expect(true){exs.fullmatch(fc)("X")}
    expect(true){exs.fullmatch(fc)("XA")}
    expect(true){exs.fullmatch(fc)("XB")}
    expect(true){exs.fullmatch(fc)("XC")}
    expect(false){exs.fullmatch(fc)("XD")}
  }

  def testFool3 = {
    val exs = new Examples with Evaluator
    val fc = exs.recompile(exs.fool3)

    expect(false){exs.begmatch(fc)("")}
    expect(false){exs.fullmatch(fc)("")}
    expect(true){exs.fullmatch(fc)("X")}
    expect(true){exs.fullmatch(fc)("XA")}
    expect(true){exs.fullmatch(fc)("XB")}
    expect(true){exs.fullmatch(fc)("XC")}
    expect(false){exs.fullmatch(fc)("YA")}
    expect(true){exs.fullmatch(fc)("YB")}
    expect(true){exs.fullmatch(fc)("YC")}
    expect(false){exs.fullmatch(fc)("XD")}
  }

  def testAny = {
    val exs = new Examples with Evaluator
    val fc = exs.recompile(exs.any)

    expect(true){exs.begmatch(fc)("")}
    expect(true){exs.fullmatch(fc)("")}
    expect(true){exs.begmatch(fc)("X")}
    expect(true){exs.fullmatch(fc)("X")}
    expect(true){exs.begmatch(fc)("XX")}
    expect(true){exs.fullmatch(fc)("XX")}
  }
}

class TestOpt extends Suite {
  trait Examples extends DSL {
    val aab = many(seq)(star(wildcard), c('A'), c('A'), c('B'))
    val aabany = many(seq)(star(wildcard), c('A'), c('A'), c('B'), star(wildcard))
  }

  trait Evaluator extends DSL with ImplOpt {
    def recompile(re: RE) = {
      val f = codegen.pack(convertREtoDFA(re))
      val fc = compile(f)
      fc
    }
  }

  def testEvalAAB = {
    val exs = new Examples with Evaluator
    val fc = exs.recompile(exs.aab)

    expect(true){fc("AAB")}
    expect(true){fc("XYZAAB")}
    expect(true){fc("XYZABAAB")}
    expect(false){fc("XYZAABX")}
    expect(false){fc("")}
  }

  def testEvalAABany = {
    val exs = new Examples with Evaluator
    val fc = exs.recompile(exs.aabany)

    expect(true){fc("AAB")}
    expect(true){fc("XYZAAB")}
    expect(true){fc("XYZABAAB")}
    expect(true){fc("XYZAABX")}
    expect(false){fc("XYZABX")}
    expect(false){fc("")}
  }
}
*/
