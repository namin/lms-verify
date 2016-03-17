package lms.verify

import scala.reflect.SourceContext

/*
Run frama-c as follows to see source information for verified and failed goals:
  frama-c -quiet -wp-print -wp -wp-rte -wp-prover alt-ergo,cvc4,z3 src/out/blame*.c | egrep "Goal|Prove"
*/


class BlameTests extends TestSuite {
  val under = "blame"

  test("0") {
    trait Blame0 extends Dsl with ShallowContracts {
      val inc = 
        shallow  { x: Rep[Int] => x + 1 }
        .require { x: Rep[Int] => x < 100 }
        .ensure  { x: Rep[Int] => result: Rep[Int] => result > x }
      toplevel("main",
        { x: Rep[Int] => inc(x) },
        { x: Rep[Int] => true },
        { x: Rep[Int] => result: Rep[Int] => result > x })

    }
    val o = (new Blame0 with Impl)
    o.codegen.emitFileAndLine = true
    check("0", o.code)
  }

  test("1") {
    trait Blame1 extends Dsl with ShallowContracts {
      type IntFunc = FuncShallow[Rep[Int],Rep[Int]]
      def even(x: Rep[Int]): Rep[Boolean] = (x%2) == 0
      def odd(x: Rep[Int]): Rep[Boolean] = (x%2) == 1
      val inc = 
        shallow    { f: IntFunc => shallow { x: Rep[Int] => f(x+1)-1 } }
        .requiring { f: IntFunc => f.require(even).ensure(x => even) }
        .ensuring  { f: IntFunc => res: IntFunc => res.require(odd).ensure(x => odd) }
      toplevel("main",
        { x: Rep[Int] => 
          val id = shallow { x: Rep[Int] => x }
          val f2 = inc(id)
          f2(x)
        },
        { x: Rep[Int] => true },
        { x: Rep[Int] => result: Rep[Int] => true })

    }
    val o = (new Blame1 with Impl)
    o.codegen.emitFileAndLine = true
    check("1", o.code)
  }


}
