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
        { n: Rep[Int] => result: Rep[Int] => 0 <= result && result < n})

      toplevel("pick_element",
        { (p: Rep[Array[Int]], n: Rep[Int]) =>
          val i = pick_index(n)
          p(i) },
        { (p: Rep[Array[Int]], n: Rep[Int]) =>
          n > 0 && valid(p, 0 until n) },
        { (p: Rep[Array[Int]], n: Rep[Int]) => result: Rep[Int] => unit(true) })

      toplevel("pick_first",
        { p: Rep[Array[Int]] => p(0) },
        { p: Rep[Array[Int]] => valid(p) },
        { p: Rep[Array[Int]] => result: Rep[Int] => result==p(0) })
    }
    check("2", (new Ex2 with Impl).code)
  }

  test("2b") {
    trait Ex2b extends Dsl {
      val first = { n: Rep[Int] => unit(0) }
      val last =  { n: Rep[Int] => n-1 }

      def gen_picker(name: String, f: Rep[Int] => Rep[Int]) = {
      toplevel("picker_"+name,
        { n: Rep[Int] => f(n) },
        { n: Rep[Int] => n > 0 },
        { n: Rep[Int] => result: Rep[Int] => 0 <= result && result < n})
      }

      def gen_pick(name: String, f: Rep[Int] => Rep[Int]) = {
      toplevel("pick_"+name,
        { (p: Rep[Array[Int]], n: Rep[Int]) =>
          val i = f(n)
          p(i) },
        { (p: Rep[Array[Int]], n: Rep[Int]) =>
          n > 0 && valid(p, 0 until n) },
        { (p: Rep[Array[Int]], n: Rep[Int]) => result: Rep[Int] => unit(true) })
      }

      gen_pick("first_element", gen_picker("first", first))
      gen_pick("first_directly", first)
      gen_pick("last_element", gen_picker("last", last))
      gen_pick("last_directly", last)
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

  test("5") {
    trait Ex5 extends Dsl {
      toplevel("array_swap",
        { p: Rep[Array[Int]] =>
          reflectMutableInput(p)
          val tmp = p(0)
          p(0) = p(1)
          p(1) = tmp
        },
        { p: Rep[Array[Int]] => valid(p, 0 until 2) },
        { p: Rep[Array[Int]] => result: Rep[Unit] => p(0)==old(p(1)) && p(1)==old(p(0)) })
    }
    check("5", (new Ex5 with Impl).code)
  }

  test("6") {
    trait Ex6 extends Dsl {
      val inswap = toplevel("inswap",
        { (p: Rep[Array[Int]], i: Rep[Int], j: Rep[Int]) =>
          reflectMutableInput(p)
          assigns(p(i))
          assigns(p(j))
          val tmp = p(i)
          p(i) = p(j)
          p(j) = tmp
        },
        { (p: Rep[Array[Int]], i: Rep[Int], j: Rep[Int]) => valid(p, i) && valid(p, j) },
        { (p: Rep[Array[Int]], i: Rep[Int], j: Rep[Int]) => result: Rep[Unit] => p(i)==old(p(j)) && p(j)==old(p(i)) })

      toplevel("insort",
        { (p: Rep[Array[Int]], n: Rep[Int]) =>
          reflectMutableInput(p)
          assigns(p, 0 until n)
          var m = n
          loop (unit(0) <= m && m <= n &&
            forall{i: Rep[Int] => (m <= i && i < n-1) ==> (p(i) <= p(i+1))} &&
            forall{i: Rep[Int] => (0 <= i && i < m && m <= n-1) ==> (p(i) <= p(m))},
            List(m, p within (0 until n)),
            m) {
            while (m > 1) {
              var maxi = 0
              loop ({i: Rep[Int] => unit(0) <= m && m <= n &&
                0 <= i && i <= m &&
                unit(0) <= maxi && maxi <= m-1 && m-1 < n &&
                forall{j: Rep[Int] => (0 <= j && j < i) ==> (p(j) <= p(maxi))}},
                {i: Rep[Int] => List(i, maxi)},
                {i: Rep[Int] => m-i}) {
                for (i <- 0 until m) {
                  if (p(i) >= p(maxi))
                    maxi = i
                }
              }
              inswap(p, m-1, maxi)
              _assert (forall{i: Rep[Int] => ((m-1 < i) && (i < (n-unit(1)))) ==> (p(i) <= p(i+1))})
              _assert((m <= n-1) ==> (p(m-1) <= p(m)))
              _assert(forall{i: Rep[Int] => (0 <= i && i < m) ==> (p(i) <= p(m-1))})
              m = m - 1
            }
          }
        },
        { (p: Rep[Array[Int]], n: Rep[Int]) => n>0 && valid(p, 0 until n) },
        { (p: Rep[Array[Int]], n: Rep[Int]) => result: Rep[Unit] =>
          forall{i: Rep[Int] => (0 <= i && i < n-1) ==> p(i) <= p(i+1)}
        }
      )
    }
    check("6", (new Ex6 with Impl).code)
  }

  test("7") {
    trait Ex7 extends Dsl {
      toplevel("member",
        { (p: Rep[Array[Int]], n: Rep[Int], v: Rep[Int]) =>
          var r = -1;
          loop ({i: Rep[Int] =>
            ((0 <= i) && (i <= n)) &&
            ((r == -1) ==> !(exists{j: Rep[Int] => 0 <= j && j < i && p(j)==v})) &&
            ((r != -1) ==> (unit(0) <= r && r < i && p(r)==v))},
            {i: Rep[Int] => List(i, r)},
            {i: Rep[Int] => n-i}) {
            for (i <- 0 until n) {
              if (r == -1 && p(i) == v) {
                r=i
              }
            }
          }
          r
        },
        { (p: Rep[Array[Int]], n: Rep[Int], v: Rep[Int]) =>
          n>0 && valid(p, 0 until n)
        },
        { (p: Rep[Array[Int]], n: Rep[Int], v: Rep[Int]) => result: Rep[Int] =>
          ((result == -1) ==> !(exists{i: Rep[Int] => 0 <= i && i < n && p(i)==v})) &&
          ((result != -1) ==> (0 <= result && result < n && p(result)==v))
        })
    }
    check("7", (new Ex7 with Impl).code)
  }
}
