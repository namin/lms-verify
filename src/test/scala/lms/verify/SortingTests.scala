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
        requires(separation(p, n))
        ensures{result: Rep[Unit] => (p(i) deep_equal old(p(j))) && (p(j) deep_equal old(p(i)))}
        ensures{result: Rep[Unit] => forall{x: Rep[Int] => ((0 <= x && x < n) && (x != i && x != j)) ==> (p(x) deep_equal old(p(x)))}}
        ensures{result: Rep[Unit] => Permut(("Old","Post"))((p, n))}
        ensures{result: Rep[Unit] => separation(p, n)}
        p.reflectMutableInput
        p.assigns(0 until n) // less precise, but helps insort in non-first class pointer case...
        //assigns(p(i))
        //assigns(p(j))
        val tmp = p(i)
        p(i) = p(j)
        p(j) = tmp
        unit(())
      })
      val insort = { (p: Pointer[T], n: Rep[Int]) =>
        requires(n>0 && p.valid(0 until n))
        requires(separation(p, n))
        ensures{result: Rep[Unit] => forall{i: Rep[Int] => (0 <= i && i < n-1) ==> (p(i) cmp p(i+1))}}
        ensures{result: Rep[Unit] => Permut(("Old","Post"))((p, n))}
        ensures{result: Rep[Unit] => separation(p, n)}
        p.reflectMutableInput
        p.assigns(0 until n)
        var m = n
        loop (unit(0) <= m && m <= n &&
          ((m < n-1) ==> (forall{i: Rep[Int] => (m <= i && i < n-1) ==> (p(i) cmp p(i+1))})) &&
          forall{i: Rep[Int] => (0 <= i && i < m && m <= n-1) ==> (p(i) cmp p(m))} &&
          Permut(("Pre","Here"))((p, n)) &&
          separation(p, n),
          list_new(readVar(m)::(p within (0 until n))),
          readVar(m)) {
            while (m > 1) {
              var maxi = 0
              loop ({i: Rep[Int] => unit(0) <= m && m <= n &&
                0 <= i && i <= m &&
                unit(0) <= maxi && maxi <= m-1 && m-1 < n &&
                forall{j: Rep[Int] => (0 <= j && j < i) ==> (p(j) cmp p(maxi))} &&
                Permut(("Pre","Here"))((p, n)) &&
                separation(p, n)},
                {i: Rep[Int] => List(i, maxi)},
                {i: Rep[Int] => m-i}) {
                for (i <- 0 until m) {
                  if (p(maxi) cmp p(i)) {
                    maxi = i
                  } else {
                    _assert(p(i) cmp p(maxi))
                  }
                }
              }
              inswap(p, m-1, maxi, n)
              _assert(forall{i: Rep[Int] => ((m-1 < i) && (i < (n-unit(1)))) ==> (p(i) cmp p(i+1))})
              _assert((m <= n-1) ==> (p(m-1) cmp p(m)))
              _assert(forall{i: Rep[Int] => (0 <= i && i < m) ==> (p(i) cmp p(m-1))})
              m = m - 1
            }
        }
      }
    }

    def pointWise[T](p: (T,T) => Rep[Boolean]) = { (a: (T,T), b: (T,T)) =>
      p(a._1, b._1) && p(a._2, b._2)
    }
    implicit def eq_pair[T:Eq:Iso] = equality[(T,T)](pointWise(_ deep_equal _))
    def separation[T:Iso](x: Pointer[T], n: Rep[Int]): Rep[Boolean] = {
      val pn: Int = x.p.size
      and_list((for (i <- 0 until pn: Range; j <- (i+1) until pn: Range) yield {
        val (a01,(m01,t01)) = x.pmt(i)
        val (a02,(m02,t02)) = x.pmt(j)
        implicit val t1 = t01.asInstanceOf[Typ[m01.T]]
        val a1 = a01.asInstanceOf[Rep[Array[m01.T]]]
        implicit val t2 = t02.asInstanceOf[Typ[m02.T]]
        val a2 = a02.asInstanceOf[Rep[Array[m02.T]]]
        forall{i1: Rep[Int] => forall{i2: Rep[Int] =>
          (0 <= i1 && i1 < n && 0 <= i2 && i2 < n) ==>
          separated(a1, i1, a2, i2)
        }}}).toList)
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

  test("3") {
    trait Srt3 extends Sorting {
      val r = new Routine[(Rep[Int],Rep[Int])]({ (a: (Rep[Int],Rep[Int]), b: (Rep[Int],Rep[Int])) =>
        (a._1<=b._1)
      })
      toplevel("insort_pairs", r.insort)
    }
    check("3", (new Srt3 with Impl).code)
  }

  test("4") {
    trait Srt4 extends Sorting {
      val r = new Routine[(Rep[Int],Rep[Int])]({ (a: (Rep[Int],Rep[Int]), b: (Rep[Int],Rep[Int])) =>
        (a._1 < b._1) || ((a._1==b._1) && b._1 <= b._2)
      })
      toplevel("insort_pairs", r.insort)
    }
    check("4", (new Srt4 with Impl).code)
  }

  test("5") {
    trait Srt5 extends Sorting {
      val r = new Routine[(Rep[Int],Rep[Int])]({ (a: (Rep[Int],Rep[Int]), b: (Rep[Int],Rep[Int])) =>
        (a._1<=b._1) || (a._2<=b._2)
      })
      toplevel("insort_pairs", r.insort)
    }
    check("5", (new Srt5 with Impl).code)
  }
}
