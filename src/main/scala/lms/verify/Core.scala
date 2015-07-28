package lms.verify

import scala.virtualization.lms.common._
import java.io.{PrintWriter,StringWriter,FileOutputStream}

trait VerifyOps extends Base with UncheckedOps {
  case class TopLevel[B](name: String, mAs: List[Manifest[_]], mB:Manifest[B], f: List[Rep[_]] => Rep[B], pre: List[Rep[_]] => Rep[Boolean], post: List[Rep[_]] => Rep[B] => Rep[Boolean], assignsNothing: Boolean)
  val rec = new scala.collection.mutable.LinkedHashMap[String,TopLevel[_]]
  def toplevel[A:Manifest,B:Manifest](name: String, f: Rep[A] => Rep[B], pre: Rep[A] => Rep[Boolean], post: Rep[A] => Rep[B] => Rep[Boolean]): Rep[A] => Rep[B] = toplevel(name, f, pre, post, false)
  def toplevel[A:Manifest,B:Manifest](name: String, f: Rep[A] => Rep[B], pre: Rep[A] => Rep[Boolean], post: Rep[A] => Rep[B] => Rep[Boolean], assignsNothing: Boolean): Rep[A] => Rep[B] = {
    val g = (x: Rep[A]) => unchecked[B](name,"(",x,")")
    rec.getOrElseUpdate(name, TopLevel(name, List(manifest[A]), manifest[B], xs => f(xs.head.asInstanceOf[Rep[A]]), xs => pre(xs.head.asInstanceOf[Rep[A]]), (xs: List[Rep[_]]) => (r: Rep[B]) => post(xs.head.asInstanceOf[Rep[A]])(r), assignsNothing))
    g
  }
  def toplevel[A1:Manifest,A2:Manifest,B:Manifest](name: String, f: (Rep[A1], Rep[A2]) => Rep[B], pre: (Rep[A1], Rep[A2]) => Rep[Boolean], post: (Rep[A1], Rep[A2]) => Rep[B] => Rep[Boolean]): (Rep[A1], Rep[A2]) => Rep[B] = toplevel(name, f, pre, post, false)
  def toplevel[A1:Manifest,A2:Manifest,B:Manifest](name: String, f: (Rep[A1], Rep[A2]) => Rep[B], pre: (Rep[A1], Rep[A2]) => Rep[Boolean], post: (Rep[A1], Rep[A2]) => Rep[B] => Rep[Boolean], assignsNothing: Boolean): (Rep[A1], Rep[A2]) => Rep[B] = {
    val g = (x1: Rep[A1], x2: Rep[A2]) => unchecked[B](name,"(",x1,",",x2,")")
    rec.getOrElseUpdate(name, TopLevel(name, List(manifest[A1], manifest[A2]), manifest[B], xs => f(xs.head.asInstanceOf[Rep[A1]], xs.tail.head.asInstanceOf[Rep[A2]]), xs => pre(xs.head.asInstanceOf[Rep[A1]], xs.tail.head.asInstanceOf[Rep[A2]]), (xs: List[Rep[_]]) => (r: Rep[B]) => post(xs.head.asInstanceOf[Rep[A1]], xs.tail.head.asInstanceOf[Rep[A2]])(r), assignsNothing))
    g
  }

  def validArray[A](p: Rep[Array[A]], n: Rep[Int]): Rep[Boolean]
  def valid[A](p: Rep[A]): Rep[Boolean]
}

trait VerifyOpsExp extends VerifyOps with BaseExp {
  case class ValidArray[A](p: Rep[Array[A]], n: Rep[Int]) extends Def[Boolean]
  case class Valid[A](p: Rep[A]) extends Def[Boolean]

  def validArray[A](p: Rep[Array[A]], n: Rep[Int]): Rep[Boolean] = ValidArray(p, n)
  def valid[A](p: Rep[A]): Rep[Boolean] = Valid(p)
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
    def exprOfBlock(kw: String, e: Block[Boolean], m: Map[Sym[_], String] = Map()): String = {
      val r = exprOf(e.res, m)
      r match {
        case "true" => ""
        case _ => kw + " " + r + ";"
      }
    }
    def exprOf[A](e: Exp[A], m: Map[Sym[_], String]): String = e match {
      case Const(_) => quote(e)
      case Def(d) => d match {
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
        case _ => "TODO:Def:"+d
      }
      case s@Sym(n) => m.get(s) match {
        case Some(v) => v
        case None => quote(e)
      }
    }

    override def emitNode(sym: Sym[Any], rhs: Def[Any]) = {
      rhs match {
        case ArrayApply(x,n) => emitValDef(sym, quote(x) + "[" + quote(n) + "]")
        case ArrayUpdate(x,n,y) => stream.println(quote(x) + "[" + quote(n) + "] =" + quote(y) + ";")
        case _ => super.emitNode(sym, rhs)
      }
    }

    def emitVerify[B](f: List[Exp[_]] => Exp[B], pre: List[Exp[_]] => Exp[Boolean], post: List[Exp[_]] => Exp[B] => Exp[Boolean], assignsNothing: Boolean, functionName: String, out: PrintWriter)(mAs: List[Manifest[_]], mB: Manifest[B]): Unit = {
      val args = mAs.map(fresh(_))
      val r = fresh[B](mB)
      val body = reifyBlock(f(args))(mB)
      val preBody = reifyBlock(pre(args))
      val postBody = reifyBlock(post(args)(r))
      val sB = remap(mB)
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

        val y = getBlockResult(body)
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
      codegen.emitVerify(x.f, x.pre, x.post.asInstanceOf[List[Exp[_]] => Exp[_] => Exp[Boolean]], x.assignsNothing, x.name, stream)(x.mAs, mtype(x.mB))
    }
  }
  lazy val code: String = {
    val source = new java.io.StringWriter()
    val stream = new PrintWriter(source)
    emitAll(stream)
    source.toString
  }
}
