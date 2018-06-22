package lms.verify

class ShonanTests extends TestSuite {
  val under = "shonan"

  trait Shonan extends Dsl { dsl =>
    val unchanged = predicate[(Lc,Lc),(Rep[Array[Int]], Rep[Int])]("unchanged", { ls: (Lc,Lc) => t: (Rep[Array[Int]], Rep[Int]) =>
      val (k, l) = ls
      val (a, n) = t
      forall{i: Rep[Int] =>
        ((0 <= i && i < n) ==>
         (at(a(i),k) == at(a(i),l)))
      }
    })(iso_tup2[Rep[Array[Int]], Rep[Int]], ("K", "L"))

    type Prod = (Rep[Int],Rep[Int],Rep[Int],Rep[Array[Int]],Rep[Array[Int]])

    val mv_prod = logic[Lc1,Prod,Rep[Int]]("MV_Prod", { p =>
      val (c,r,n,m,v) = p
      list_new(infix_within(m, (0 until n*n))::infix_within(v, (0 until n))::Nil)
    }, { mv_prod =>
      add_axiom[Lc1,(Prod)]("Empty", { ls => p =>
        val (c,r,n,m,v) = p
        ((!(0 < c && c <= n)) || (!(0 <= r && r < n))) ==>
        (mv_prod(ls)(p)==0)
      })
      add_axiom[Lc1,(Prod)]("One", { ls => p =>
        val (c,r,n,m,v) = p
        (0 < c && c <= n && 0 <= r && r < n) ==> (
          mv_prod(ls)(c, r, n, m, v) ==
            mv_prod(ls)(c-1, r, n, m, v) +
            (m(n*r+(c-1)) * v(c-1)))
      })
      add_axiom[(Lc,Lc),(Prod)]("Read", { ls => p =>
        val (k,l) = ls
        val (c,r,n,m,v) = p
        ((unchanged(ls)(m, n*n) && unchanged(ls)(v, n)) ==>
         (mv_prod(Tuple1(k))(p) == mv_prod(Tuple1(l))(p)))
      })
    })

    def mvp(p: Prod) = mv_prod(Tuple1(""))(p)
  }

  test("1") {
    trait Program extends Shonan {
      def requires_mvprod(n: Rep[Int], m: Rep[Array[Int]], v: Rep[Array[Int]], o: Rep[Array[Int]]) = {
        reflectMutableInput(o)
        requires(n > 0)
        requires(valid(m, 0 until n*n))
        requires(valid(v, 0 until n))
        requires(valid(o, 0 until n))
        requires(separated(m, 0 until n*n, o, 0 until n))
        requires(separated(v, 0 until n, o, 0 until n))
      }
      def ensures_mvprod(n: Rep[Int], m: Rep[Array[Int]], v: Rep[Array[Int]], o: Rep[Array[Int]]) = {
        assigns(o, 0 until n)
        ensures{_:Rep[Unit] => forall{i: Rep[Int] => ((0 <= i && i < n) ==> (o(i) == mvp((n, i, n, m, v))))}}
      }

      val put = toplevel("put",
        { (
          o: Rep[Array[Int]],
          i: Rep[Int],
          a: Rep[Int],
          n: Rep[Int],
          m: Rep[Array[Int]],
          v: Rep[Array[Int]]
        ) =>
          requires_mvprod(n, m, v, o)
          requires(0 <= i && i < n)

          o(i) = a
          ensures{_:Rep[Unit] => forall{j: Rep[Int] => ((0 <= j && j < n && j != i) ==>  (o(j) == old(o(j))))}}
          ensures{_:Rep[Unit] => forall{j: Rep[Int] => ((0 <= j && j < (n*n)) ==> (m(j) == old(m(j))))}}
          ensures{_:Rep[Unit] => forall{j: Rep[Int] => ((0 <= j && j < n) ==> (v(j) == old(v(j))))}}
          ensures{_:Rep[Unit] => forall{j: Rep[Int] => ((0 <= j && j < n) ==> (mvp(n, j, n, m, v) == old(mvp(n, j, n, m, v))))}}
          ensures{_:Rep[Unit] => o(i)==a}
          assigns(o,i)
        })

      val mv_prod_impl = toplevel("mv_prod_impl",
        { (
          n: Rep[Int],
          m: Rep[Array[Int]],
          v: Rep[Array[Int]],
          o: Rep[Array[Int]]
        ) =>
          requires_mvprod(n, m, v, o)

          for (r <- 0 until n) {
            loop_invariant(forall{i: Rep[Int] => ((0 <= i && i < r) ==> (o(i) == mvp((n, i, n, m, v))))})
            loop_assigns(list_new(r::(o within (0 until n))::Nil))
            var t = 0
            for (c <- 0 until n) {
              loop_invariant(0 <= r && r < n)
              loop_invariant(forall{i: Rep[Int] => ((0 <= i && i < r) ==> (o(i) == mvp((n, i, n, m, v))))})
              loop_invariant(t == mvp((c, r, n, m, v)))
              loop_assigns(list_new(c::(readVar(t)::Nil)))
              t = t + (m(n*r+c) * v(c))
            }
            put(o, r, t, n, m, v)
          }

          ensures_mvprod(n, m, v, o)
        }
      )

      val n0 = 5
      val m0 = Array(
        1, 1, 1, 1, 1,
        0, 0, 0, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 1, 0, 1)
      val mv_prod_specialized = toplevel("mv_prod_specialized",
        { (
          n: Rep[Int],
          m: Rep[Array[Int]],
          v: Rep[Array[Int]],
          o: Rep[Array[Int]]
        ) =>
          requires_mvprod(n, m, v, o)
          requires(n==n0)
          for (i <- (0 until n0*n0):Range) {
            requires(m(i) == m0(i))
          }

          for (r <- (0 until n0):Range) {
            _assert(forall{i: Rep[Int] => ((0 <= i && i < r) ==> (o(i) == mvp((n, i, n, m, v))))})
            val row = for (c <- (0 until n0):Range) yield m0(r*n0+c)
            val sparse = row.count(_ != 0) < 3
            var t = 0
            if (sparse) {
              for (c <- (0 until n0):Range) {
                _assert(forall{i: Rep[Int] => ((0 <= i && i < r) ==> (o(i) == mvp((n, i, n, m, v))))})
                _assert(t == mvp((c, r, n, m, v)))
                t = t + (m0(n0*r+c) * v(c))
              }
              _assert(t == mvp((n, r, n, m, v)))
            } else {
              for (c <- 0 until n) {
                loop_invariant(0 <= r && r < n)
                loop_invariant(forall{i: Rep[Int] => ((0 <= i && i < r) ==> (o(i) == mvp((n, i, n, m, v))))})
                loop_invariant(t == mvp((c, r, n, m, v)))
                loop_assigns(list_new(c::(readVar(t)::Nil)))
                t = t + (m(n*r+c) * v(c))
              }
            }
            put(o, r, t, n, m, v)
            _assert(forall{i: Rep[Int] => ((0 <= i && i <= r) ==> (o(i) == mvp((n, i, n, m, v))))})
          }
          ensures_mvprod(n, m, v, o)
        }
      )
    }
    check("1", (new Program with Impl).code)
  }
}
