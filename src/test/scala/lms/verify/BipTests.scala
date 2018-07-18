package lms.verify

class BipTests extends TestSuite {
  val under = "bip_"

  test("cesar1") {
    trait Program extends Dsl {
      override def includes = super.includes:+"<string.h>"

      val req = { s: Rep[Int] => 0 <= s && s <= 26 }

      def gencypher(n: String, p: Rep[Int] => Rep[Boolean], f: Rep[Int] => Rep[Int]) = toplevel(n, { s: Rep[Int] =>
        requires(req(s))
        ensures{r: Rep[Int] => req(r)}
        f(s)
      }, spec=true, code=true)

      val cypher = gencypher("cypher", req, { s: Rep[Int] => if (s==26) 0 else s+1 })

      val decypher = gencypher("decypher", req, { s: Rep[Int] => if (s==0) 26 else s-1 })

      def routine_requires(s1: Rep[Array[Int]], s2: Rep[Array[Int]], s3: Rep[Array[Int]], n: Rep[Int]) = {
        requires(n > 0)
        requires(valid(s1, 0 until n))
        requires(valid(s2, 0 until n))
        requires(valid(s3, 0 until n))
        requires(
          forall{i1: Rep[Int] => (0 <= i1 && i1 < n) ==> (
          forall{i2: Rep[Int] => (0 <= i2 && i2 < n) ==> (
          forall{i3: Rep[Int] => (0 <= i3 && i3 < n) ==> (
            separated(s1,i1,s2,i2) &&
            separated(s1,i1,s3,i3) &&
              separated(s2,i2,s3,i3))})})})
      }

      def gencode(s: String, f: Rep[Int] => Rep[Int]) = toplevel(s, {
        (s1: Rep[Array[Int]], s2: Rep[Array[Int]], s3: Rep[Array[Int]], n: Rep[Int]) =>
        routine_requires(s1, s2, s3, n)
        requires(forall{i: Rep[Int] => (0 <= i && i < n) ==> req(s1(i))})
        ensures{_ : Rep[Unit] => forall{i: Rep[Int] => (0 <= i && i < n) ==>
          (s2(i) == f(s1(i)))}}
        ensures{_ : Rep[Unit] => forall{i: Rep[Int] => (0 <= i && i < n) ==>
          req(s2(i))}}
        ensures{_ : Rep[Unit] => forall{i: Rep[Int] => (0 <= i && i < n) ==>
          (old(s1(i))==s1(i))}}
        ensures{_ : Rep[Unit] => forall{i: Rep[Int] => (0 <= i && i < n) ==>
          (old(s3(i))==s3(i))}}
        reflectMutableInput(s2)
        assigns(s2, 0 until n)
        for(i <- 0 until n) {
          loop_invariant(forall{j: Rep[Int] => (0 <= j && j < n) ==>
            req(s1(j))
          })
          loop_invariant(forall{j: Rep[Int] => (0 <= j && j < n) ==>
            (at(s1(j),"Pre")==s1(j))
          })
          loop_invariant(forall{j: Rep[Int] => (0 <= j && j < n) ==>
            (at(s3(j),"Pre")==s3(j))
          })
          loop_invariant(forall{j: Rep[Int] => (0 <= j && j < i) ==>
            (s2(j) == f(s1(j)))
          })
          loop_assigns(list_new(i::(s2 within (0 until n))::Nil))
          s2(i) = f(s1(i))
          _assert(s2(i) == f(s1(i)))
        }
      })

      val encode = gencode("encode", cypher)
      val decode = gencode("decode", decypher)

      val autoencode = toplevel("autoencode", {
        (s1: Rep[Array[Int]], s2: Rep[Array[Int]], s3: Rep[Array[Int]], n: Rep[Int]) =>
        routine_requires(s1, s2, s3, n)
        requires(forall{i: Rep[Int] => (0 <= i && i < n) ==> req(s1(i))})
        ensures{_ : Rep[Unit] => forall{i: Rep[Int] => (0 <= i && i < n) ==>
          (s3(i)==s1(i))}}
        ensures{_ : Rep[Unit] => forall{i: Rep[Int] => (0 <= i && i < n) ==>
          (old(s1(i))==s1(i))}}
        reflectMutableInput(s2)
        assigns(s2, 0 until n)
        reflectMutableInput(s3)
        assigns(s3, 0 until n)
        encode(s1, s2, s3, n)
        decode(s2, s3, s1, n)
        //_assert(forall{i: Rep[Int] => (0 <= i && i < n) ==> (at(s1(i),"Pre")==s1(i))})
        //_assert(forall{i: Rep[Int] => (0 <= i && i < n) ==> (s2(i)==cypher(s1(i)))})
        //_assert(forall{i: Rep[Int] => (0 <= i && i < n) ==> (s3(i)==decypher(s2(i)))})
        //_assert(forall{i: Rep[Int] => (0 <= i && i < n) ==> (s3(i)==decypher(cypher((s1(i)))))})
        //_assert(forall{i: Rep[Int] => (0 <= i && i < n) ==> (s3(i)==s1(i))});
      })
    }
    check("cesar1", (new Program with Impl).code)
  }
}
