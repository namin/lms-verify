package lms.verify

class InvariantTests extends TestSuite {
  val under = "inv"

  trait Vecs extends Dsl with DataOps {
    class Vec[T:Iso](val a: Pointer[T], val n: Rep[Int]) {
      def apply(i: Rep[Int]) = a(i)
      def valid = n==0 || (n>0 && a.valid(0 until n))
      def length = n
      def foreach(f: (T,Rep[Int]) => Rep[Unit]) = for (i <- 0 until n) f(a(i),i)
      def fold[U:Typ](z: Rep[U])(f: (Rep[U], T, Rep[Int]) => Rep[U]) = {
        var acc = z; this.foreach{(x,i) => acc = f(acc,x,i)}; acc
      }
      def count(p: T => Rep[Boolean]): Rep[Int] = {
        this.fold(0){(r,x,i) =>
          loop_invariant{0 <= r && r <= i};
          r+(if (p(x)) 1 else 0)
        }
      }
    }
    implicit def vecIso[T:Iso](implicit ev: Inv[Vec[T]]) = isodata[Vec[T],(Pointer[T],Rep[Int])](
      "vec_" + implicitly[Iso[T]].id,
      {x: Vec[T] => (x.a, x.n)},
      {x: (Pointer[T],Rep[Int]) => new Vec(x._1, x._2)}
    )
    implicit def vecInv[T:Inv] = invariant[Vec[T]] { x =>
      x.valid && ((0 until x.n) forall {i => x(i).check})
    }
    implicit def vecEq[T:Eq:Iso] = equality[Vec[T]] { (x, y) =>
      x.n == y.n && ((0 until x.n) forall {i => x(i) deep_equal y(i)})
    }
  }

  test("0") {
    trait Inv0 extends Vecs {
      implicitly[Eq[Vec[Rep[Int]]]]
    }
    check("0", (new Inv0 with Impl).code)
  }

  test("1") {
    trait Inv1 extends Vecs {
      implicitly[Eq[Vec[Vec[Rep[Int]]]]]
    }
    check("1", (new Inv1 with Impl).code)
  }

  test("2") {
    trait Inv2 extends Vecs {
      toplevel("sum", { x: Vec[Rep[Int]] =>
        var r = 0;
        for (i <- 0 until x.n) {
          val a = x(i) // memory safe because invariant on x is auto-required
          r = r+a // verifies except for overflow
        }
        r: Rep[Int]
      })
    }
    check("2", (new Inv2 with Impl).code)
  }

  test("3") {
    trait Inv3 extends Vecs {
      toplevel("count_pos", { xs: Vec[Rep[Int]] =>
        xs.count{_ > 0}
      })
    }
    check("3", (new Inv3 with Impl).code)
  }

  test("4") {
    trait Inv4 extends Vecs {
      toplevel("count_pos", { xss: Vec[Vec[Rep[Int]]] =>
        xss.count{xs => xs.count{_ > 0} > 0}
      })
    }
    check("4", (new Inv4 with Impl).code)
  }
}
