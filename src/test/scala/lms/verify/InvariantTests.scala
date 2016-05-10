package lms.verify

class InvariantTests extends TestSuite {
  val under = "inv"

  trait Vectors extends Dsl with DataOps {
    class Vec[T:Iso](val a: Pointer[T], val n: Rep[Int]) {
      def apply(i: Rep[Int]) = a(i)
    }
    implicit def vecIso[T:Iso](implicit ev: Inv[Vec[T]]) = isodata[Vec[T],(Pointer[T],Rep[Int])](
      {x: Vec[T] => (x.a, x.n)},
      {x: (Pointer[T],Rep[Int]) => new Vec(x._1, x._2)}
    )

    implicit def vecInv[T:Inv] = invariant[Vec[T]] { x =>
      unit(0) <= x.n && ((unit(0) until x.n).forall{i: Rep[Int] => x(i).check})
    }
    implicit def vecEq[T:Eq] = equality[Vec[T]] { (x, y) =>
      x.n == y.n && ((unit(0) until x.n).forall{i: Rep[Int] => x(i) deep_equal y(i)})
    }
  }
  test("0") {

  }
}
