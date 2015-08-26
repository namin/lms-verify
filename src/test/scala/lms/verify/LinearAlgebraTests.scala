package lms.verify

class LinearAlgebraTests extends TestSuite {
  val under = "lina"

  test("1") {
    trait Lina1 extends Dsl {
      val N = 100
      val index = toplevel("index",
        { (r: Rep[Int], c: Rep[Int], ra: Rep[Int], ca: Rep[Int]) => r*ca+c },
        { (r: Rep[Int], c: Rep[Int], ra: Rep[Int], ca: Rep[Int]) =>
          ra > 0 && ca > 0 && 0 <= r && r < ra && 0 <= c && c < c &&
          ra < N && ca < N },
        { (r: Rep[Int], c: Rep[Int], ra: Rep[Int], ca: Rep[Int]) => result: Rep[Int] =>
          0 <= result && result < ra*ca })
    }
    check("1", (new Lina1 with Impl).code)
  }
}
