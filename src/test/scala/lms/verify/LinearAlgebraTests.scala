package lms.verify

class LinearAlgebraTests extends TestSuite {
  val under = "lina"

  test("1") {
    trait Lina1 extends Dsl {
      val N = 100
      val index = toplevel("index",
        { (r: Rep[Int], c: Rep[Int], ra: Rep[Int], ca: Rep[Int]) => r*ca+c },
        { (r: Rep[Int], c: Rep[Int], ra: Rep[Int], ca: Rep[Int]) =>
          ra > 0 && ca > 0 && 0 <= r && r < ra && 0 <= c && c < ca &&
          ra < N && ca < N },
        { (r: Rep[Int], c: Rep[Int], ra: Rep[Int], ca: Rep[Int]) => result: Rep[Int] =>
          0 <= result && result < ra*ca })

      val mm_mult = toplevel("mm_mult",
        { (ma: Rep[Array[Int]], ra: Rep[Int], ca: Rep[Int],
           mb: Rep[Array[Int]], rb: Rep[Int], cb: Rep[Int],
           mc: Rep[Array[Int]], rc: Rep[Int], cc: Rep[Int]) =>
          reflectMutableInput(mc)
          loop(
            {r: Rep[Int] => ra == rc && unit(0) <= r && r <= ra},
            {r: Rep[Int] => List(r, mc within (0 until rc*cc))},
            {r: Rep[Int] => ra-r}) {
            for (r <- 0 until ra) {
              loop(
                {c: Rep[Int] => cc == cb && unit(0) <= c && c <= cb},
                {c: Rep[Int] => List(c, mc within (0 until rc*cc))},
                {c: Rep[Int] => cb-c}) {
                for (c <- 0 until cb) {
                  mc(index(r, c, rc, cc)) = 0
                  loop(
                    {i: Rep[Int] => rb==ca && unit(0) <= i && i <= ca},
                    {i: Rep[Int] => List(i, mc within (0 until rc*cc))},
                    {i: Rep[Int] => ca-i}) {
                    for (i <- 0 until ca) {
                      mc(index(r, c, rc, cc)) = mc(index(r, c, rc, cc)) + ma(index(r, i, ra, ca)) * mb(index(i, c, rb, cb))
                    }
                  }
                }
              }
            }
          }
        },
        { (ma: Rep[Array[Int]], ra: Rep[Int], ca: Rep[Int],
           mb: Rep[Array[Int]], rb: Rep[Int], cb: Rep[Int],
           mc: Rep[Array[Int]], rc: Rep[Int], cc: Rep[Int]) =>
          ra > 0 && ca > 0 && rb > 0 && cc > 0 &&
          ca == rb && ra == rc && cc == cb &&
          ra < N && ca < N && rb < N && cb < N && rc < N && cc < N &&
          valid(ma, 0 until ra*ca) &&
          valid(mb, 0 until rb*cb) &&
          valid(mc, 0 until rc*cc)
        },
        { (ma: Rep[Array[Int]], ra: Rep[Int], ca: Rep[Int],
           mb: Rep[Array[Int]], rb: Rep[Int], cb: Rep[Int],
           mc: Rep[Array[Int]], rc: Rep[Int], cc: Rep[Int]) =>
          result: Rep[Unit] =>
          unit(true)
        })
    }
    check("1", (new Lina1 with Impl).code)
  }

  test("1b") {
    trait Lina1b extends Dsl {
      val N = 100
      val index = toplevel("index",
        { (r: Rep[Int], c: Rep[Int], ra: Rep[Int], ca: Rep[Int]) => r*ca+c },
        { (r: Rep[Int], c: Rep[Int], ra: Rep[Int], ca: Rep[Int]) =>
          ra > 0 && ca > 0 && 0 <= r && r < ra && 0 <= c && c < ca &&
          ra < N && ca < N },
        { (r: Rep[Int], c: Rep[Int], ra: Rep[Int], ca: Rep[Int]) => result: Rep[Int] =>
          0 <= result && result < ra*ca })

      case class Matrix(m: Rep[Array[Int]], r: Rep[Int], c: Rep[Int]) extends {
        def req: Rep[Boolean] = r > 0 && c > 0 && r < N && c < N && valid(m, 0 until r*c)
      }
      def toplevel_matrix(name: String, f: (Matrix, Matrix, Matrix) => Rep[Unit], pre: (Matrix, Matrix, Matrix) => Rep[Boolean], post: (Matrix, Matrix, Matrix) => Rep[Unit] => Rep[Boolean]): (Matrix, Matrix, Matrix) => Rep[Unit] = {
        val g = toplevel(name, (m1: Rep[Array[Int]], r1: Rep[Int], c1: Rep[Int], m2: Rep[Array[Int]], r2: Rep[Int], c2: Rep[Int], m3: Rep[Array[Int]], r3: Rep[Int], c3: Rep[Int]) => f(Matrix(m1, r1, c1), Matrix(m2, r2, c2), Matrix(m3, r3, c3)), (m1: Rep[Array[Int]], r1: Rep[Int], c1: Rep[Int], m2: Rep[Array[Int]], r2: Rep[Int], c2: Rep[Int], m3: Rep[Array[Int]], r3: Rep[Int], c3: Rep[Int]) => pre(Matrix(m1, r1, c1), Matrix(m2, r2, c2), Matrix(m3, r3, c3)), (m1: Rep[Array[Int]], r1: Rep[Int], c1: Rep[Int], m2: Rep[Array[Int]], r2: Rep[Int], c2: Rep[Int], m3: Rep[Array[Int]], r3: Rep[Int], c3: Rep[Int]) => post(Matrix(m1, r1, c1), Matrix(m2, r2, c2), Matrix(m3, r3, c3)))
        (a: Matrix, b: Matrix, o: Matrix) => g(a.m, a.r, a.c, b.m, b.r, b.c, o.m, o.r, o.c)
      }

      val mm_mult = toplevel_matrix("mm_mult",
        { (a: Matrix, b: Matrix, o: Matrix) =>
          reflectMutableInput(o.m)
          loop(
            {r: Rep[Int] => a.r == o.r && unit(0) <= r && r <= a.r},
            {r: Rep[Int] => List(r, o.m within (0 until o.r*o.c))},
            {r: Rep[Int] => a.r-r}) {
            for (r <- 0 until a.r) {
              loop(
                {c: Rep[Int] => o.c == b.c && unit(0) <= c && c <= b.c},
                {c: Rep[Int] => List(c, o.m within (0 until o.r*o.c))},
                {c: Rep[Int] => b.c-c}) {
                for (c <- 0 until b.c) {
                  o.m(index(r, c, o.r, o.c)) = 0
                  loop(
                    {i: Rep[Int] => b.r==a.c && unit(0) <= i && i <= a.c},
                    {i: Rep[Int] => List(i, o.m within (0 until o.r*o.c))},
                    {i: Rep[Int] => a.c-i}) {
                    for (i <- 0 until a.c) {
                      o.m(index(r, c, o.r, o.c)) = o.m(index(r, c, o.r, o.c)) + a.m(index(r, i, a.r, a.c)) * b.m(index(i, c, b.r, b.c))
                    }
                  }
                }
              }
            }
          }
        },
        { (a: Matrix, b: Matrix, o: Matrix) =>
          a.req &&
          b.req &&
          o.req &&
          a.c == b.r && a.r == o.r && o.c == b.c
        },
        { (a: Matrix, b: Matrix, o: Matrix) =>
          result: Rep[Unit] =>
          unit(true)
        })
    }
    check("1b", (new Lina1b with Impl).code)
  }
}