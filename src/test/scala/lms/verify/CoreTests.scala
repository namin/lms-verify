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
      val pick_index = toplevel("pick_index",
        { n: Rep[Int] => 0 },
        { n: Rep[Int] => n > 0 },
        { n: Rep[Int] => result: Rep[Int] => 0 <= result && result < n},
        assignsNothing=true)

      toplevel("pick_element",
        { (p: Rep[Array[Int]], n: Rep[Int]) =>
          val i = pick_index(n)
          p(i) },
        { (p: Rep[Array[Int]], n: Rep[Int]) =>
          n > 0 && validArray(p, n) },
        { (p: Rep[Array[Int]], n: Rep[Int]) => result: Rep[Int] => unit(true) },
        assignsNothing=true)

      toplevel("pick_first",
        { p: Rep[Array[Int]] => p(0) },
        { p: Rep[Array[Int]] => valid(p) },
        { p: Rep[Array[Int]] => result: Rep[Int] => result==p(0) },
        assignsNothing=true)
    }
    check("2", (new Ex2 with Impl).code)
  }

  test("2b") {
    trait Ex2b extends Dsl {
      val first = { n: Rep[Int] => unit(0) }
      val last =  { n: Rep[Int] => n-1 }

      def gen_picker(name: String, f: Rep[Int] => Rep[Int]) = {
      toplevel("pick_"+name,
        { n: Rep[Int] => f(n) },
        { n: Rep[Int] => n > 0 },
        { n: Rep[Int] => result: Rep[Int] => 0 <= result && result < n},
        assignsNothing=true)
      }

      def gen_pick(name: String, f: Rep[Int] => Rep[Int]) = {
      toplevel("pick_"+name,
        { (p: Rep[Array[Int]], n: Rep[Int]) =>
          val i = f(n)
          p(i) },
        { (p: Rep[Array[Int]], n: Rep[Int]) =>
          n > 0 && validArray(p, n) },
        { (p: Rep[Array[Int]], n: Rep[Int]) => result: Rep[Int] => unit(true) },
        assignsNothing=true)
      }

      gen_pick("first_element", gen_picker("first", first))
      gen_pick("first", first)
      gen_pick("last_element", gen_picker("last", last))
      gen_pick("last", last)
    }
    check("2b", (new Ex2b with Impl).code)
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

  test("4") {
    trait Ex4 extends Dsl {
      lazy val plus: (Rep[Int],Rep[Int]) => Rep[Int] = toplevel("plus",
        { (a: Rep[Int], b: Rep[Int]) => if (a==0) b else plus(a-1,b+1) },
        { (a: Rep[Int], b: Rep[Int]) => a>=0 },
        { (a: Rep[Int], b: Rep[Int]) => result: Rep[Int] => result==a+b})
      plus
    }
    check("4", (new Ex4 with Impl).code)
  }
}
