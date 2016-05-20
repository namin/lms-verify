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
  }

  test("1") {
    trait Srt1 extends Sorting {
      val Permut = permut[Rep[Int]]
      val inswap = toplevel("inswap", { (p: Pointer[Rep[Int]], i: Rep[Int], j: Rep[Int], n: Rep[Int]) =>
        requires(n>0 && 0 <= i && i < n && 0 <= j && j < n)
        requires(p.valid(0 until n))
        ensures{result: Rep[Unit] => (p(i) == old(p(j))) && (p(j) == old(p(i)))}
        ensures{result: Rep[Unit] => Permut(("Old","Post"))((p, n))}
        p.reflectMutableInput
        assigns(p(i))
        assigns(p(j))
        val tmp = p(i)
        p(i) = p(j)
        p(j) = tmp
        unit(())
      })
    }
    check("1", (new Srt1 with Impl).code)
  }
}
