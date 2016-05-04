package lms.verify

class PredTests extends TestSuite {
  val under = "prd"

  test("1") {
    trait Prd1 extends Dsl {
      val is_pos = predicate("is_pos", { x: Rep[Int] => x > 0 })
      val is_nat = predicate("is_nat", { x: Rep[Int] => x >= 0})
      toplevel("minus1", { x: Rep[Int] =>
        requires{is_pos(x)}
        ensures{result: Rep[Int] => is_nat(result)}
        x - 1
      })
    }
    check("1", (new Prd1 with Impl).code)
  }
}
