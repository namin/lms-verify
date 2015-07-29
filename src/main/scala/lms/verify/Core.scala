package lms.verify

import scala.virtualization.lms.common._
import java.io.{PrintWriter,StringWriter,FileOutputStream}

trait VerifyOps extends Base {
  case class TopLevel[B](name: String, mAs: List[Manifest[_]], mB:Manifest[B], f: List[Rep[_]] => Rep[B], pre: List[Rep[_]] => Rep[Boolean], post: List[Rep[_]] => Rep[B] => Rep[Boolean])
  val rec = new scala.collection.mutable.LinkedHashMap[String,TopLevel[_]]
  def toplevel[A:Manifest,B:Manifest](name: String, f: Rep[A] => Rep[B], pre: Rep[A] => Rep[Boolean], post: Rep[A] => Rep[B] => Rep[Boolean]): Rep[A] => Rep[B] = {
    val g = (x: Rep[A]) => toplevelApply[B](name, List(x))
    rec.getOrElseUpdate(name, TopLevel(name, List(manifest[A]), manifest[B], xs => f(xs(0).asInstanceOf[Rep[A]]), xs => pre(xs(0).asInstanceOf[Rep[A]]), (xs: List[Rep[_]]) => (r: Rep[B]) => post(xs(0).asInstanceOf[Rep[A]])(r)))
    g
  }
  def toplevel[A1:Manifest,A2:Manifest,B:Manifest](name: String, f: (Rep[A1], Rep[A2]) => Rep[B], pre: (Rep[A1], Rep[A2]) => Rep[Boolean], post: (Rep[A1], Rep[A2]) => Rep[B] => Rep[Boolean]): (Rep[A1], Rep[A2]) => Rep[B] = {
    val g = (x1: Rep[A1], x2: Rep[A2]) => toplevelApply[B](name, List(x1, x2))
    rec.getOrElseUpdate(name, TopLevel(name, List(manifest[A1], manifest[A2]), manifest[B], xs => f(xs(0).asInstanceOf[Rep[A1]], xs(1).asInstanceOf[Rep[A2]]), xs => pre(xs(0).asInstanceOf[Rep[A1]], xs(1).asInstanceOf[Rep[A2]]), (xs: List[Rep[_]]) => (r: Rep[B]) => post(xs(0).asInstanceOf[Rep[A1]], xs(1).asInstanceOf[Rep[A2]])(r)))
    g
  }
  def toplevel[A1:Manifest,A2:Manifest,A3:Manifest,B:Manifest](name: String, f: (Rep[A1], Rep[A2], Rep[A3]) => Rep[B], pre: (Rep[A1], Rep[A2], Rep[A3]) => Rep[Boolean], post: (Rep[A1], Rep[A2], Rep[A3]) => Rep[B] => Rep[Boolean]): (Rep[A1], Rep[A2], Rep[A3]) => Rep[B] = {
    val g = (x1: Rep[A1], x2: Rep[A2], x3: Rep[A3]) => toplevelApply[B](name, List(x1, x2, x3))
    rec.getOrElseUpdate(name, TopLevel(name, List(manifest[A1], manifest[A2], manifest[A3]), manifest[B], xs => f(xs(0).asInstanceOf[Rep[A1]], xs(1).asInstanceOf[Rep[A2]], xs(2).asInstanceOf[Rep[A3]]), xs => pre(xs(0).asInstanceOf[Rep[A1]], xs(1).asInstanceOf[Rep[A2]], xs(2).asInstanceOf[Rep[A3]]), (xs: List[Rep[_]]) => (r: Rep[B]) => post(xs(0).asInstanceOf[Rep[A1]], xs(1).asInstanceOf[Rep[A2]], xs(2).asInstanceOf[Rep[A3]])(r)))
    g
  }

  def validArray[A](p: Rep[Array[A]], n: Rep[Int]): Rep[Boolean]
  def valid[A](p: Rep[A]): Rep[Boolean]
  def old[A:Manifest](v: Rep[A]): Rep[A]

  def reflectMutableInput[A](v: Rep[A]): Rep[A]

  def toplevelApply[B:Manifest](name: String, args: List[Rep[_]]): Rep[B]
}

trait VerifyOpsExp extends VerifyOps with EffectExp {
  case class ValidArray[A](p: Rep[Array[A]], n: Rep[Int]) extends Def[Boolean]
  case class Valid[A](p: Rep[A]) extends Def[Boolean]
  case class Old[A:Manifest](v: Rep[A]) extends Def[A]

  def validArray[A](p: Rep[Array[A]], n: Rep[Int]): Rep[Boolean] = ValidArray(p, n)
  def valid[A](p: Rep[A]): Rep[Boolean] = Valid(p)
  def old[A:Manifest](v: Rep[A]): Rep[A] = Old(v)

  def reflectMutableInput[A](v: Rep[A]): Rep[A] =
    reflectMutableSym(v.asInstanceOf[Sym[A]])

  case class ToplevelApply[B:Manifest](name: String, args: List[Rep[_]]) extends Def[B]
  val eff = new scala.collection.mutable.LinkedHashMap[String,(List[Sym[Any]], Summary)]
  def toplevelApply[B:Manifest](name: String, args: List[Rep[_]]): Rep[B] = {
    eff.get(name) match {
      case Some((params, es)) =>
        //val m = params.zip(args.map(_.asInstanceOf[Sym[Any]])).toMap
        //val es2 = replaceInSummary(m, es)
        reflectEffect(ToplevelApply(name, args), es)
      case None => reflectEffect(ToplevelApply(name, args))
    }
  }
  def replaceInSummary(m: Map[Sym[Any], Sym[Any]], es: Summary) = {
    def r1(x: Sym[Any]) = m.get(x) match {
      case Some(y) if y != null => y
      case None => x
    }
    def r(xs: List[Sym[Any]]) = xs.map(r1)
    Summary(es.maySimple, es.mstSimple, es.mayGlobal, es.mstGlobal, es.resAlloc, es.control, r(es.mayRead), r(es.mstRead), r(es.mayWrite), r(es.mstWrite))
  }
}

trait Dsl extends VerifyOps with ScalaOpsPkg with TupledFunctions with UncheckedOps with LiftPrimitives with LiftString with LiftVariables

trait Impl extends Dsl with VerifyOpsExp with ScalaOpsPkgExp with TupledFunctionsRecursiveExp with UncheckedOpsExp { self =>
  val codegen = new CCodeGenPkg with CGenVariables with CGenTupledFunctions with CGenUncheckedOps {
    override def remap[A](m: Manifest[A]): String = {
      if (m.toString.startsWith("Array["))
        return remap(m.typeArguments.head)+" "
      val tpe = super.remap(m)
      if (tpe.startsWith("int") || tpe.startsWith("uint") || tpe=="bool") "int"
      else tpe
    }
    override def isPrimitiveType(tpe: String): Boolean = {
      tpe match {
        case "int" | "uint" => true
        case _ => super.isPrimitiveType(tpe)
      }
    }
    override def emitValDef(sym: Sym[Any], rhs: String): Unit = {
      if (!isVoidType(sym.tp))
        stream.println(remapWithRef(sym.tp) + quote(sym) + " = " + rhs + ";")
      else stream.println(rhs + ";")
    }

    def exprOfBlock(kw: String, e: Block[Boolean], m: Map[Sym[_], String] = Map()): String = {
      val r = exprOf(e.res, m)
      r match {
        case "true" => ""
        case _ => kw + " " + r + ";"
      }
    }
    def exprOfDef[A](d: Def[A], m: Map[Sym[_], String]): String = d match {
      case Old(v) => "\\old("+exprOf(v, m)+")"
      case Valid(p) => "\\valid("+exprOf(p, m)+")"
      case ValidArray(p,n) => "\\valid("+exprOf(p, m)+"+ (0.."+exprOf(n, m)+"-1))"
      case Equal(a, b) => "("+exprOf(a, m)+"=="+exprOf(b, m)+")"
      case OrderingGTEQ(a, b) => "("+exprOf(a, m)+">="+exprOf(b, m)+")"
      case OrderingGT(a, b) => "("+exprOf(a, m)+">"+exprOf(b, m)+")"
      case OrderingLTEQ(a, b) => "("+exprOf(a, m)+"<="+exprOf(b, m)+")"
      case OrderingLT(a, b) => "("+exprOf(a, m)+"<"+exprOf(b, m)+")"
      case BooleanAnd(a, b) => "("+exprOf(a, m)+" && "+exprOf(b, m)+")"
      case BooleanOr(a, b) => "("+exprOf(a, m)+" || "+exprOf(b, m)+")"
      case IntPlus(a, b) => "("+exprOf(a, m)+"+"+exprOf(b, m)+")"
      case IntTimes(a, b) => "("+exprOf(a, m)+"*"+exprOf(b, m)+")"
      case ArrayApply(p, i) => exprOf(p, m)+"["+exprOf(i, m)+"]"
      case Reify(r, _, _) => exprOf(r, m)
      case Reflect(r, _, _) => exprOfDef(r, m)
      case _ => "TODO:Def:"+d
    }
    def exprOf[A](e: Exp[A], m: Map[Sym[_], String]): String = e match {
      case Const(_) => quote(e)
      case Def(d) => exprOfDef(d, m)
      case s@Sym(n) => m.get(s) match {
        case Some(v) => v
        case None => quote(e)
      }
    }

    override def emitNode(sym: Sym[Any], rhs: Def[Any]) = {
      rhs match {
        case ToplevelApply(name, args) => emitValDef(sym, name+args.map(quote).mkString("(", ",", ")"))
        case ArrayApply(x,n) => emitValDef(sym, quote(x) + "[" + quote(n) + "]")
        case ArrayUpdate(x,n,y) => stream.println(quote(x) + "[" + quote(n) + "] = " + quote(y) + ";")
        case _ => super.emitNode(sym, rhs)
      }
    }

    def emitVerify[B](f: List[Exp[_]] => Exp[B], pre: List[Exp[_]] => Exp[Boolean], post: List[Exp[_]] => Exp[B] => Exp[Boolean], functionName: String, out: PrintWriter)(mAs: List[Manifest[_]], mB: Manifest[B]): Unit = {
      val args = mAs.map(fresh(_))
      val r = fresh[B](mB)
      val body = reifyBlock(f(args))(mB)
      eff.getOrElseUpdate(functionName, (args, summarizeEffects(body)))
      val preBody = reifyBlock(pre(args))
      val postBody = reifyBlock(post(args)(r))
      val sB = remap(mB)
      val y = getBlockResult(body)
      val assignsNothing = getBlockResultFull(body) match {
        case Def(Reify(_, s, _)) => s.mayWrite.isEmpty && s.mstWrite.isEmpty
        case _ => true
      }
      withStream(out) {
        val preStr = exprOfBlock("requires", preBody)
        val postStr = exprOfBlock("ensures", postBody, Map(r -> "\\result"))
        if (!preStr.isEmpty || assignsNothing || !postStr.isEmpty) {
         stream.println("/*@")
         stream.println(preStr)
         if (assignsNothing) stream.println("assigns \\nothing;")
         stream.println(postStr)
         stream.println("*/")
        }

        stream.println(sB+" "+functionName+"("+(args.map(s => remapWithRef(s.tp)+" "+quote(s))).mkString(", ")+") {")
        emitBlock(body)

        if (remap(y.tp) != "void")
          stream.println("return " + quote(y) + ";")

        stream.println("}")
      }
    }
    val IR: self.type = self
  }
  def emitAll(stream: java.io.PrintWriter): Unit = {
    assert(codegen ne null) //careful about initialization order
    rec.foreach { case (k,x) =>
      //stream.println("/* FILE: " + x.name + ".c */")
      //for ((_,v) <- rec) codegen.emitForwardDef(mtype(v.mA)::Nil, v.name, stream)(mtype(v.mB))
      codegen.emitVerify(x.f, x.pre, x.post.asInstanceOf[List[Exp[_]] => Exp[_] => Exp[Boolean]], x.name, stream)(x.mAs, mtype(x.mB))
    }
  }
  lazy val code: String = {
    val source = new java.io.StringWriter()
    val stream = new PrintWriter(source)
    emitAll(stream)
    source.toString
  }
}
