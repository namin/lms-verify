package lms.verify

class LinearAlgebraTests extends TestSuite {
  val under = "linp"

  trait Matrices extends Dsl with DataOps {
    val N = 100
    // like for the low-level versions, verifying that the calculated index
    // is within the valid range only works when it's extracted out...
    val index_fun = toplevel("index",
      { (rows: Rep[Int], cols: Rep[Int], r: Rep[Int], c: Rep[Int]) =>
        requires(0 < rows && rows < N && 0 < cols && cols < N && 0 <= r && 0 <= c && r < rows && c < cols)
        ensures{result: Rep[Int] => 0 <= result && result < rows*cols}
        r*cols+c
      })

    class Matrix[T:Iso](val a: Pointer[T], val rows: Rep[Int], val cols: Rep[Int]) {
      def size = rows*cols
      def index(r: Rep[Int], c: Rep[Int]) = index_fun(rows, cols, r, c)
      def apply(r: Rep[Int], c: Rep[Int]) = a(index(r,c))
      def update(p: (Rep[Int],Rep[Int]), v: T): Rep[Unit] = {
        val r = p._1; val c = p._2
        a(index(r, c)) = v
      }
      def valid = size>0 && a.valid(0 until size)
      def reflectMutableInput = a.reflectMutableInput(0 until size)
      def setEach(f: (Rep[Int], Rep[Int]) => T) = {
        this.reflectMutableInput
        for (r <- 0 until this.rows) {
          for (c <- 0 until this.cols) {
            this((r,c)) = f(r,c)
          }
        }
      }
      def setFrom[A:Iso](f: List[A] => T, ms: List[Matrix[A]])(implicit eq: Eq[T]) = {
        def r(i: Rep[Int]): T = f(ms.map{m => m.a(i)})
        ms.foreach{m => requires(this.rows == m.rows && this.cols == m.cols)}
        // TODO: higher-level separation?
        requires(and_list(ms.map{m => forall{i: Rep[Int] => forall{j: Rep[Int] =>
          ((0 <= i && i < this.size) && (0 <= j && j < m.size)) ==>
          separated(this.a, i, m.a, j)
        }}}))
        this.reflectMutableInput
        // for the From2 example, it helps to reinforce separation...
        ms.foreach{m => _assert(separated(this.a, 0, m.a, 0))}
        for (i <- 0 until this.size) {
          loop_invariant{forall{j: Rep[Int] => (0 <= j && j < i) ==> (
            this.a(j) deep_equal r(j)
          )}}
          this.a(i) = r(i)
          // ditto for From2...
          ms.foreach{m => _assert(separated(this.a, i, m.a, i))}
        }
      }
      def setFrom1[A:Iso](f: A => T, m: Matrix[A])(implicit eq: Eq[T]) = {
        setFrom[A]({ms => f(ms(0))}, scala.collection.immutable.List(m))
      }
      def setFrom2[A:Iso](f: (A,A) => T, m1: Matrix[A], m2: Matrix[A])(implicit eq: Eq[T]) = {
        setFrom[A]({ms => f(ms(0), ms(1))}, scala.collection.immutable.List(m1, m2))
      }
    }
    implicit def matrixIso[T:Iso](implicit ev: Inv[Matrix[T]]) = isodata[Matrix[T],(Pointer[T],Rep[Int],Rep[Int])](
      "matrix_" + implicitly[Iso[T]].id,
      {x: Matrix[T] => (x.a, x.rows, x.cols)},
      {x: (Pointer[T],Rep[Int],Rep[Int]) => new Matrix(x._1, x._2, x._3)}
    )
    implicit def matrixInv[T:Inv] = invariant[Matrix[T]] { x =>
      x.rows < N && x.cols < N && // needed for overflow in index calculation
      0 < x.rows && 0 < x.cols && x.valid && (
      (0 until x.rows).forall{ r => (0 until x.cols).forall{ c => x(r,c).check }})
    }
    implicit def matrixEq[T:Eq:Iso] = equality[Matrix[T]] { (x, y) =>
      x.rows == y.rows && x.cols == y.cols && (
        (0 until x.rows).forall{ r => (0 until x.cols).forall{ c =>
          x(r,c) deep_equal y(r,c) }})
    }
  }

  trait BoolAlgebra extends Dsl {
    type X = Rep[Boolean]
    def zero: Rep[Boolean] = unit(false)
    def infix_+(x1: X, x2: X): X = x1 || x2
    def infix_*(x1: X, x2: X): X = x1 && x2
  }

  test("1") {
    trait Linp1 extends Matrices with BoolAlgebra {
      toplevel("mult", { (a: Matrix[X], b: Matrix[X], o: Matrix[X]) =>
        requires(a.cols == b.rows && a.rows == o.rows && b.cols == o.cols)
        o.reflectMutableInput
        for (r <- 0 until a.rows) {
          for (c <- 0 until b.cols) {
            o((r,c)) = zero
            for (i <- 0 until a.cols) {
              o((r,c)) = o(r,c) + a(r,i) * b(i,c)
            }
          }
        }
      })
    }
    check("1", (new Linp1 with Impl).code)
  }

  test("2") {
    trait Linp2 extends Matrices with BoolAlgebra {
      val add = toplevel("add", { (a: Matrix[X], b: Matrix[X], o: Matrix[X]) =>
        requires(a.rows == b.rows && a.rows == o.rows && a.cols == b.cols && a.cols == o.cols)
        o.setEach{ (r: Rep[Int], c: Rep[Int]) =>
          a(r,c) + b(r,c)
        }
      })
      val scalar_mult = toplevel("scalar_mult", { (a: X, b: Matrix[X], o: Matrix[X]) =>
        requires(b.rows == o.rows && b.cols == o.cols)
        o.setEach{ (r: Rep[Int], c: Rep[Int]) =>
          a*b(r,c)
        }
      })
    }
    check("2", (new Linp2 with Impl).code)
  }

  test("3") {
    trait Linp3 extends Matrices with BoolAlgebra {
      val add = toplevel("add", { (a: Matrix[X], b: Matrix[X], o: Matrix[X]) =>
        o.setFrom2({ (ai: X, bi: X) => ai + bi }, a, b)
      })
      val scalar_mult = toplevel("scalar_mult", { (a: X, b: Matrix[X], o: Matrix[X]) =>
        o.setFrom1({ (bi: X) => a*bi }, b)
      })
    }
    check("3", (new Linp3 with Impl).code)
  }
}

class LowLinearAlgebraTests extends TestSuite {
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
            {r: Rep[Int] => unit(0) <= r && r <= ra},
            {r: Rep[Int] => List(r, mc within (0 until rc*cc))},
            {r: Rep[Int] => ra-r}) {
            for (r <- 0 until ra) {
              loop(
                {c: Rep[Int] => unit(0) <= c && c <= cb},
                {c: Rep[Int] => List(c, mc within (0 until rc*cc))},
                {c: Rep[Int] => cb-c}) {
                for (c <- 0 until cb) {
                  mc(index(r, c, rc, cc)) = 0
                  loop(
                    {i: Rep[Int] => unit(0) <= i && i <= ca},
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
        class Aux(i: Rep[Int]) {
          def apply(j: Rep[Int]) = m(index(i, j, r, c))
          def update(j: Rep[Int], v: Rep[Int]) = m(index(i, j, r, c)) = v
        }
        def apply(i: Rep[Int]) = new Aux(i)
      }

      def toplevel_matrix(name: String, f: (Matrix, Matrix, Matrix) => Rep[Unit], pre: (Matrix, Matrix, Matrix) => Rep[Boolean], post: (Matrix, Matrix, Matrix) => Rep[Unit] => Rep[Boolean]): (Matrix, Matrix, Matrix) => Rep[Unit] = {
        val g = toplevel(name,
          (m1: Rep[Array[Int]], r1: Rep[Int], c1: Rep[Int], m2: Rep[Array[Int]], r2: Rep[Int], c2: Rep[Int], m3: Rep[Array[Int]], r3: Rep[Int], c3: Rep[Int]) => f(Matrix(m1, r1, c1), Matrix(m2, r2, c2), Matrix(m3, r3, c3)),
          {(m1: Rep[Array[Int]], r1: Rep[Int], c1: Rep[Int], m2: Rep[Array[Int]], r2: Rep[Int], c2: Rep[Int], m3: Rep[Array[Int]], r3: Rep[Int], c3: Rep[Int]) =>
            val o1 = Matrix(m1, r1, c1)
            val o2 = Matrix(m2, r2, c2)
            val o3 = Matrix(m3, r3, c3)
            o1.req && o2.req && o3.req && pre(o1, o2, o3)},
          (m1: Rep[Array[Int]], r1: Rep[Int], c1: Rep[Int], m2: Rep[Array[Int]], r2: Rep[Int], c2: Rep[Int], m3: Rep[Array[Int]], r3: Rep[Int], c3: Rep[Int]) => post(Matrix(m1, r1, c1), Matrix(m2, r2, c2), Matrix(m3, r3, c3)))
        (a: Matrix, b: Matrix, o: Matrix) => g(a.m, a.r, a.c, b.m, b.r, b.c, o.m, o.r, o.c)
      }

      val mm_mult = toplevel_matrix("mm_mult",
        { (a: Matrix, b: Matrix, o: Matrix) =>
          reflectMutableInput(o.m, 0 until o.r*o.c)
          for (r <- 0 until a.r) {
            for (c <- 0 until b.c) {
              o(r)(c) = 0
              for (i <- 0 until a.c) {
                o(r)(c) = o(r)(c) + a(r)(i) * b(i)(c)
              }
            }
          }
        },
        { (a: Matrix, b: Matrix, o: Matrix) =>
          a.c == b.r && a.r == o.r && o.c == b.c
        },
        { (a: Matrix, b: Matrix, o: Matrix) =>
          result: Rep[Unit] =>
          unit(true)
        })
    }
    check("1b", (new Lina1b with Impl).code)
  }

  test("2") {
    trait Lina2 extends Dsl {
      def index_where(suffix: String, predicate: Rep[Int] => Rep[Boolean]) = {
        toplevel("index_where_" + suffix,
          { (v: Rep[Array[Int]], n: Rep[Int], o: Rep[Array[Int]]) =>
            reflectMutableInput(o)
            assigns(o, 0 until n)
            var r = 0
            loop({i: Rep[Int] => unit(0) <= i && i <= n &&
              unit(0) <= r && r <= i &&
              forall{j: Rep[Int] => (0 <= j && j < r) ==> (0 <= o(j) && o(j) < i)} &&
              forall{j: Rep[Int] => (0 < j && j < r) ==> (o(j-1) < o(j))}},
              {i: Rep[Int] => List(i, r, o within (0 until n))},
              {i: Rep[Int] => n-i}) {
              for (i <- 0 until n) {
                if (predicate(v(i))) {
                  o(r) = i
                  r += 1
                }
              }
            }
            r: Rep[Int]
          },
          { (v: Rep[Array[Int]], n: Rep[Int], o: Rep[Array[Int]]) => n > 0 && valid(v, 0 until n) && valid(o, 0 until n)},
          { (v: Rep[Array[Int]], n: Rep[Int], o: Rep[Array[Int]]) => (result: Rep[Int]) =>
            0 <= result && result <= n &&
            forall{i: Rep[Int] => (0 <= i && i < result) ==> (0 <= o(i) && o(i) < n)} &&
            forall{i: Rep[Int] => (0 < i && i < result) ==> (o(i-1) < o(i))}
          })
      }
      def even(n: Rep[Int]) = n % 2 == 0

      val index_where_even = index_where("even", even)
    }

    check("2", (new Lina2 with Impl).code)
  }
}
