package lms.verify

import scala.lms.common._
import scala.reflect.SourceContext
import java.io.{PrintWriter,StringWriter,FileOutputStream}


trait ShallowContracts extends Dsl {
  
  var blameContext: Option[(SourceContext,SourceContext)] = None

  def withBlameContext[T](caller: SourceContext, callee: SourceContext)(f: => T): T = {
    // only save the topmost one
    val save = blameContext; blameContext = blameContext.orElse(Some(caller,callee))
    try f finally blameContext = save
  }
  def withFlippedBlameContext[T](caller: SourceContext, callee: SourceContext)(f: => T): T =
    withBlameContext(caller,callee) {
      blameContext = Some(blameContext.get._2,blameContext.get._1); f
    }

  trait FuncShallow[A,B] { o =>    
    def calleePos: SourceContext
    def apply(x: A)(implicit callerPos: SourceContext): B
    def require(pre: A => Rep[Boolean])(implicit contractPos: SourceContext) = new FuncShallow[A,B] {
      def calleePos = o.calleePos
      val parent = blameContext
      def apply(x: A)(implicit callerPos: SourceContext): B = {
        // blame precondition on caller
        //_assert(pre(x))(parent.getOrElse(callerPos,calleePos)._1) // callerPos
        // NOTE: it seems sensible to always blame the *current* caller (?)
        _assert(pre(x))(callerPos) // callerPos
        o.apply(x)(callerPos)
      }
    }
    def ensure(post: A => B => Rep[Boolean])(implicit contractPos: SourceContext) = new FuncShallow[A,B] {
      def calleePos = o.calleePos
      val parent = blameContext
      def apply(x: A)(implicit callerPos: SourceContext): B = {
        val res = o.apply(x)(callerPos)
        // blame postcondition on callee
        // NOTE: this will be (alternatingly, even/odd left of arrow) either
        // the caller or callee of the original contract
        _assert(post(x)(res))(parent.getOrElse(callerPos,calleePos)._2) // calleePos
        res
      }
    }
    def requiring(pre: A => A)(implicit contractPos: SourceContext) = new FuncShallow[A,B] {
      def calleePos = o.calleePos
      def apply(x: A)(implicit callerPos: SourceContext): B =
        withFlippedBlameContext(callerPos,calleePos) {
          o.apply(pre(x))(callerPos)
        }
    }
    def ensuring(post: A => B => B)(implicit contractPos: SourceContext) = new FuncShallow[A,B] {
      def calleePos = o.calleePos
      def apply(x: A)(implicit callerPos: SourceContext): B =
        withBlameContext(callerPos,calleePos) {
          post(x)(o.apply(x)(callerPos))
        }
    }
  }
  def shallow[A,B](f: A => B)(implicit pos: SourceContext) = 
    new FuncShallow[A,B] {
      def calleePos = pos
      def apply(x: A)(implicit callerPos: SourceContext): B = f(x)
    }

  def inline[A,B](name: String, 
    f: A => B, pre: A => Rep[Boolean], 
    post: A => B => Rep[Boolean])(implicit pos: SourceContext) = 
  new FuncShallow[A,B] {
    def calleePos = pos
    def apply(x: A)(implicit callerPos: SourceContext) = {
      // blame precondition on caller
      _assert(pre(x))(callerPos) 
      val res = f(x)
      // blame postcondition on callee
      _assert(post(x)(res))(calleePos)
      res
    }
  }
}

