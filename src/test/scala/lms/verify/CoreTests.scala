package lms.verify

class CoreTests extends TestSuite {
  val under = "ex"

  test("0") {
    trait Ex0 extends Dsl {
      toplevel("inc")
      { x: Rep[Int] => x + 1 }
      { x: Rep[Int] => unit(true) }
      { x: Rep[Int] => result: Rep[Int] => result > x }
    }
    check("0", (new Ex0 with Impl).code)
  }

}
