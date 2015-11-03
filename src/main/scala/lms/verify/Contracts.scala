package lms.verify

import scala.lms.common._
import scala.reflect.SourceContext
import java.io.{PrintWriter,StringWriter,FileOutputStream}


trait ShallowContracts extends Dsl {
  trait FuncShallow[A,B] { o =>
    def apply(x: A)(implicit callerPos: SourceContext): B
    def require(pre: A => Rep[Boolean])(implicit calleePos: SourceContext) = new FuncShallow[A,B] {
      def apply(x: A)(implicit callerPos: SourceContext): B = {
        // blame precondition on caller
        _assert(pre(x))(callerPos) 
        o.apply(x)(callerPos)
      }
    }
    def ensure(post: A => B => Rep[Boolean])(implicit calleePos: SourceContext) = new FuncShallow[A,B] {
      def apply(x: A)(implicit callerPos: SourceContext): B = {
        val res = o.apply(x)(callerPos)
        // blame postcondition on callee
        _assert(post(x)(res))(calleePos)
        res
      }
    }
    def requiring(pre: A => A)(implicit calleePos: SourceContext) = new FuncShallow[A,B] {
      def apply(x: A)(implicit callerPos: SourceContext): B = {
        o.apply(pre(x))(callerPos)
      }
    }
    def ensuring(post: A => B => B)(implicit calleePos: SourceContext) = new FuncShallow[A,B] {
      def apply(x: A)(implicit callerPos: SourceContext): B = {
        post(x)(o.apply(x)(callerPos))
      }
    }
  }
  def shallow[A,B](f: A => B)(implicit calleePos: SourceContext) = 
    new FuncShallow[A,B] {
      def apply(x: A)(implicit callerPos: SourceContext): B = f(x)
    }

  def inline[A,B](name: String, 
    f: A => B, pre: A => Rep[Boolean], 
    post: A => B => Rep[Boolean])(implicit calleePos: SourceContext) = 
  new FuncShallow[A,B] {
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

