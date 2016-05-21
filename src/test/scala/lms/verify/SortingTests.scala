package lms.verify

class SortingTests extends TestSuite {
  val under = "srt"

  trait Sorting extends Dsl with DataOps {
    def permut[T:Iso:Eq] = inductive[(Lc,Lc),(Pointer[T],Rep[Int])](
      implicitly[Iso[T]].id+"_Permut", { p =>
        add_case[Lc1,(Pointer[T],Rep[Int])]("refl", { ls => an =>
          p((ls._1,ls._1))(an)
        })
        add_case[(Lc,Lc),(Pointer[T],Rep[Int])]("sym", { ls => an =>
          (p((ls._1, ls._2))(an)) ==> (p((ls._2, ls._1))(an))
        })
        add_case[(Lc,Lc,Lc),(Pointer[T],Rep[Int])]("trans", {ls => an =>
          ((p((ls._1, ls._2))(an)) && (p((ls._2, ls._3))(an))) ==>
          (p((ls._1, ls._3))(an))
        })
        add_case[(Lc,Lc),(Pointer[T],Rep[Int])]("swap", { ls => an =>
          val (l1,l2) = ls
          val (a,n) = an
          forall{i: Rep[Int] => forall{j: Rep[Int] =>
            (0 <= i && i < n && 0 <= j && j < n &&
              ((at(a(i),l1)) deep_equal (at(a(j),l2))) &&
              ((at(a(j),l1)) deep_equal (at(a(i),l2))) &&
              forall{k: Rep[Int] =>
                (0 <= k && k < n && k != i && k != j) ==>
                ((at(a(k),l1)) deep_equal (at(a(k),l2)))}) ==>
            (p(ls)(an))
          }}
        })
      })

    class Routine[T:Iso:Eq](infix_cmp: (T,T) => Rep[Boolean]) {
      def id = implicitly[Iso[T]].id
      def id_by(s: String) = id+(if (s.isEmpty) "" else "_by_"+s)
      val Permut = permut[T]
      val inswap = toplevel("inswap_"+id, { (p: Pointer[T], i: Rep[Int], j: Rep[Int], n: Rep[Int]) =>
        requires(n>0 && 0 <= i && i < n && 0 <= j && j < n)
        requires(p.valid(0 until n))
        ensures{result: Rep[Unit] => (p(i) deep_equal old(p(j))) && (p(j) deep_equal old(p(i)))}
        ensures{result: Rep[Unit] => Permut(("Old","Post"))((p, n))}
        p.reflectMutableInput
        assigns(p(i))
        assigns(p(j))
        val tmp = p(i)
        p(i) = p(j)
        p(j) = tmp
        unit(())
      })
      val insort = { (p: Pointer[T], n: Rep[Int]) =>
        requires(n>0 && p.valid(0 until n))
        val x = p(0) cmp p(1)
        ensures{result: Rep[Unit] => forall{i: Rep[Int] => (0 <= i && i < n-1) ==> (p(i) cmp p(i+1))}}
        ensures{result: Rep[Unit] => Permut(("Old","Post"))((p, n))}
        p.reflectMutableInput
        p.assigns(0 until n)
        var m = n
        loop (unit(0) <= m && m <= n &&
          ((m < n-1) ==> (forall{i: Rep[Int] => (m <= i && i < n-1) ==> (p(i) cmp p(i+1))})) &&
          forall{i: Rep[Int] => (0 <= i && i < m && m <= n-1) ==> (p(i) cmp p(m))} &&
          Permut(("Pre","Here"))((p, n)),
          list_new(readVar(m)::(p within (0 until n))),
          readVar(m)) {
            while (m > 1) {
              var maxi = 0
              loop ({i: Rep[Int] => unit(0) <= m && m <= n &&
                0 <= i && i <= m &&
                unit(0) <= maxi && maxi <= m-1 && m-1 < n &&
                forall{j: Rep[Int] => (0 <= j && j < i) ==> (p(j) cmp p(maxi))} &&
                Permut(("Pre","Here"))((p, n))},
                {i: Rep[Int] => List(i, maxi)},
                {i: Rep[Int] => m-i}) {
                for (i <- 0 until m) {
                  if (p(maxi) cmp p(i))
                    maxi = i
                }
              }
              inswap(p, m-1, maxi, n)
              _assert (forall{i: Rep[Int] => ((m-1 < i) && (i < (n-unit(1)))) ==> (p(i) cmp p(i+1))})
              _assert((m <= n-1) ==> (p(m-1) cmp p(m)))
              _assert(forall{i: Rep[Int] => (0 <= i && i < m) ==> (p(i) cmp p(m-1))})
              m = m - 1
            }
        }
      }
    }
  }

  test("1") {
    trait Srt1 extends Sorting {
      val r = new Routine[Rep[Int]](_ <= _)
      toplevel("insort", r.insort)
    }
    check("1", (new Srt1 with Impl).code)
  }

  test("2") {
    trait Srt2 extends Sorting {
      val r = new Routine[Rep[Int]](_ >= _)
      toplevel("insort", r.insort)
    }
    check("2", (new Srt2 with Impl).code)
  }
}