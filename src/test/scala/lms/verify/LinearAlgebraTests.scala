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
}
