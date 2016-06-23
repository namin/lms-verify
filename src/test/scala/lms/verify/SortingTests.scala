package lms.verify

class SortingTests extends TestSuite {
  val under = "srt"

  trait Sorting extends Dsl with DataOps {
    class Vec[T:Iso](val a: Pointer[T], val n: Rep[Int]) {
      def apply(i: Rep[Int]) = a(i)
      def valid = n==0 || (n>0 && a.valid(0 until n))
      def length = n
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
    def infix_reflectMutable[T:Iso](v: Vec[T]): Unit = {
      val (p, n) = (v.a, v.n)
      requires(separation(p, n))
      ensures{result: Rep[Unit] => separation(p, n)}
      p.reflectMutableInput
      p.assigns(0 until n)
    }

    def permut[T:Iso:Eq] = inductive[(Lc,Lc),Vec[T]](
      implicitly[Iso[T]].id+"_Permut", { p =>
        add_case[Lc1,Vec[T]]("refl", { ls => v =>
          p((ls._1,ls._1))(v)
        })
        add_case[(Lc,Lc),Vec[T]]("sym", { ls => v =>
          (p((ls._1, ls._2))(v)) ==> (p((ls._2, ls._1))(v))
        })
        add_case[(Lc,Lc,Lc),Vec[T]]("trans", {ls => v =>
          ((p((ls._1, ls._2))(v)) && (p((ls._2, ls._3))(v))) ==>
          (p((ls._1, ls._3))(v))
        })
        add_case[(Lc,Lc),Vec[T]]("swap", { ls => v =>
          val (l1,l2) = ls
          val (a,n) = (v.a, v.n)
          forall{i: Rep[Int] => forall{j: Rep[Int] =>
            (0 <= i && i < n && 0 <= j && j < n &&
              ((at(a(i),l1)) deep_equal (at(a(j),l2))) &&
              ((at(a(j),l1)) deep_equal (at(a(i),l2))) &&
              forall{k: Rep[Int] =>
                (0 <= k && k < n && k != i && k != j) ==>
                ((at(a(k),l1)) deep_equal (at(a(k),l2)))}) ==>
            (p(ls)(v))
          }}
        })
      })

    class Routine[T:Iso:Eq](infix_cmp: (T,T) => Rep[Boolean]) {
      def id = implicitly[Iso[T]].id
      def id_by(s: String) = id+(if (s.isEmpty) "" else "_by_"+s)
      val Permut = permut[T]
      val inswap = toplevel("inswap_"+id, { (v: Vec[T], i: Rep[Int], j: Rep[Int]) =>
        val (p, n) = (v.a, v.n)
        requires(0 <= i && i < n && 0 <= j && j < n)
        ensures{result: Rep[Unit] => (p(i) deep_equal old(p(j))) && (p(j) deep_equal old(p(i)))}
        ensures{result: Rep[Unit] => forall{x: Rep[Int] => ((0 <= x && x < n) && (x != i && x != j)) ==> (p(x) deep_equal old(p(x)))}}
        ensures{result: Rep[Unit] => Permut(("Old","Post"))(v)}
        v.reflectMutable
        val tmp = p(i)
        p(i) = p(j)
        p(j) = tmp
        unit(())
      })
      val insort = { (v: Vec[T]) =>
        val (p, n) = (v.a, v.n)
        ensures{result: Rep[Unit] => forall{i: Rep[Int] => (0 <= i && i < n-1) ==> (p(i) cmp p(i+1))}}
        ensures{result: Rep[Unit] => Permut(("Old","Post"))(v)}
        v.reflectMutable
        var m = n
        loop (unit(0) <= m && m <= n &&
          ((m < n-1) ==> (forall{i: Rep[Int] => (m <= i && i < n-1) ==> (p(i) cmp p(i+1))})) &&
          forall{i: Rep[Int] => (0 <= i && i < m && m <= n-1) ==> (p(i) cmp p(m))} &&
          Permut(("Pre","Here"))(v) &&
          separation(p, n),
          list_new(readVar(m)::(p within (0 until n))),
          readVar(m)) {
            while (m > 1) {
              var maxi = 0
              loop ({i: Rep[Int] => unit(0) <= m && m <= n &&
                0 <= i && i <= m &&
                unit(0) <= maxi && maxi <= m-1 && m-1 < n &&
                forall{j: Rep[Int] => (0 <= j && j < i) ==> (p(j) cmp p(maxi))} &&
                Permut(("Pre","Here"))(v) &&
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
              inswap(v, m-1, maxi)
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
        (a._1 < b._1) || ((a._1==b._1) && (a._2 <= b._2))
      })
      toplevel("insort_pairs", r.insort)
    }
    check("4", (new Srt4 with Impl).code)
  }
}
