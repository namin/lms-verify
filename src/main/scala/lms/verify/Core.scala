package lms.verify

import scala.virtualization.lms.common._
import java.io.{PrintWriter,StringWriter,FileOutputStream}

trait Dsl extends ScalaOpsPkg with TupledFunctions with UncheckedOps with LiftPrimitives with LiftString with LiftVariables {
  case class TopLevel[A,B](name: String, mA: Manifest[A], mB:Manifest[B], f: Rep[A] => Rep[B], pre: Rep[A] => Rep[Boolean], post: Rep[A] => Rep[B] => Rep[Boolean])
  val rec = new scala.collection.mutable.HashMap[String,TopLevel[_,_]]
  def toplevel[A:Manifest,B:Manifest](name: String)(f: Rep[A] => Rep[B])(pre: Rep[A] => Rep[Boolean])(post: Rep[A] => Rep[B] => Rep[Boolean]): Rep[A] => Rep[B] = {
    val g = (x: Rep[A]) => unchecked[B](name,"(",x,")")
    rec.getOrElseUpdate(name, TopLevel(name, manifest[A], manifest[B], f, pre, post))
    g
  }
}

trait Impl extends Dsl with ScalaOpsPkgExp with TupledFunctionsRecursiveExp with UncheckedOpsExp { self =>
  val codegen = new CCodeGenPkg with CGenVariables with CGenTupledFunctions with CGenUncheckedOps {
    override def remap[A](m: Manifest[A]): String = {
      val tpe = super.remap(m)
      if (tpe.startsWith("int")) "int"
      else if (tpe.startsWith("uint")) "uint"
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
    def exprOf[A](e: Exp[A], m: Map[Sym[_], String] = Map()): String = e match {
      case Const(_) => quote(e)
      case Def(d) => d match {
        case _ => "TODO:Def"+d
      }
      case s@Sym(n) => m.get(s) match {
        case Some(v) => v
        case None => quote(e)
      }
    }

    def emitVerify[A:Manifest, B:Manifest](f: Exp[A] => Exp[B], pre: Exp[A] => Exp[Boolean], post: Exp[A] => Exp[B] => Exp[Boolean], functionName: String, out: PrintWriter): Unit = {
      val s = fresh[A]
      val r = fresh[B]
      val body = reifyBlock(f(s))
      val preBody = reifyBlock(pre(s))
      //val postBody = reifyBlock(post(s)(r))
      val sB = remap(manifest[B])
      withStream(out) {
        val preStr = exprOfBlock("requires", preBody)
        val postStr = ""
        if (!preStr.isEmpty || !postStr.isEmpty) {
          stream.println("/*@")
          stream.println(preStr)
          stream.println(postStr)
          stream.println("*/")
        }

        stream.println(sB+" "+functionName+"("+remapWithRef(s.tp)+" "+quote(s)+") {")
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
      codegen.emitVerify(x.f, x.pre, null, x.name, stream)(mtype(x.mA), mtype(x.mB))
    }
  }
  lazy val code: String = {
    val source = new java.io.StringWriter()
    val stream = new PrintWriter(source)
    emitAll(stream)
    source.toString
  }
}
