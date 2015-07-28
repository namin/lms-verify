package lms.verify

class CoreTests extends TestSuite {
  val under = "ex"

  test("0") {
    trait Ex0 extends Dsl {
      toplevel("inc",
        { x: Rep[Int] => x + 1 },
        { x: Rep[Int] => unit(true) },
        { x: Rep[Int] => result: Rep[Int] => result > x })
    }
    check("0", (new Ex0 with Impl).code)
  }

  test("1") {
    trait Ex1 extends Dsl {
      toplevel("max",
        { (x: Rep[Int], y: Rep[Int]) => if (x > y) x else y },
        { (x: Rep[Int], y: Rep[Int]) => unit(true) },
        { (x: Rep[Int], y: Rep[Int]) => result: Rep[Int] =>
          result >= x && result >= y &&
          (result == x || result == y)
        })
    }
    check("1", (new Ex1 with Impl).code)
  }
  
  test("2") {
    trait Ex2 extends Dsl {
      toplevel("pick_index",
        { n: Rep[Int] => 0 },
        { n: Rep[Int] => n > 0 },
        { n: Rep[Int] => result: Rep[Int] => 0 <= result && result < n})
    }
    check("2", (new Ex2 with Impl).code)
  }

  test("3") {
    trait Ex3 extends Dsl {
      val square = toplevel("square",
        { x: Rep[Int] => x*x },
        { x: Rep[Int] => unit(true) },
        { x: Rep[Int] => result: Rep[Int] => result==x*x})

      toplevel("pow4",
        { x: Rep[Int] => square(square(x)) },
        { x: Rep[Int] => unit(true) },
        { x: Rep[Int] => result: Rep[Int] => result==x*x*x*x})

      toplevel("pow4b",
        { x: Rep[Int] => square(x)*square(x) },
        { x: Rep[Int] => unit(true) },
        { x: Rep[Int] => result: Rep[Int] => result==x*x*x*x})
    }
    check("3", (new Ex3 with Impl).code)
  }

}
