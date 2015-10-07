package lms.verify

import scala.reflect.SourceContext

/*
Run frama-c as follows to see source information for verified and failed goals:
  frama-c -quiet -wp-print -wp -wp-rte -wp-prover alt-ergo,cvc4,z3 src/out/blame*.c | egrep "Goal|Prove"
*/

class BlameTests extends TestSuite {
  val under = "blame"

  test("0") {
    trait Blame0 extends Dsl {
      trait FuncInline[A,B] {
        def apply(x: Rep[A])(implicit callerPos: SourceContext): Rep[B]
      }
      def inline[A:Manifest:Typ,B:Manifest:Typ](name: String, 
        f: Rep[A] => Rep[B], pre: Rep[A] => Rep[Boolean], 
        post: Rep[A] => Rep[B] => Rep[Boolean])(implicit calleePos: SourceContext) = 
      new FuncInline[A,B] {
        def apply(x: Rep[A])(implicit callerPos: SourceContext) = {
          // blame precondition on caller
          _assert(pre(x))(callerPos) 
          val res = f(x)
          // blame postcondition on callee
          _assert(post(x)(res))(calleePos)
          res
        }
      }

      val inc = inline("inc",
        { x: Rep[Int] => x + 1 },
        { x: Rep[Int] => x < 100 },
        { x: Rep[Int] => result: Rep[Int] => result > x })
      toplevel("main",
        { x: Rep[Int] => inc(x) },
        { x: Rep[Int] => true },
        { x: Rep[Int] => result: Rep[Int] => result > x })

    }
    val o = (new Blame0 with Impl)
    o.codegen.emitFileAndLine = true
    check("0", o.code)
  }
}
