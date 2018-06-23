package lms.verify

// WIP
class KMPTest extends TestSuite {
  val under = "kmp_"

  def gen(w: String) {
    test(w) {
      trait KMPProg extends Dsl {
        override def includes = super.includes:+"<string.h>"
        def valid_string(s: Rep[String]) = s.length>=0 && valid(s, 0 until s.length+1)

        def match_range(s: Rep[String], from: Int, to: Int): Rep[Boolean] =
          if (from == to) true
          else s(from) == w(from) && match_range(s, from+1, to)
        val match_w = predicate("match_w",
          { (s: Rep[String]) => match_range(s, 0, w.length) })
        val match_any_w = predicate("match_any_w",
          { (s: Rep[String]) =>
            exists{i: Rep[Int] => 0 <= i && i < s.length && match_w(s)}
          },
          code=false)
        def rematch(w: String, i: Int): Int = {
          if (i == 0) -1 else {
            def rec(jp: Int, kp: Int): Int = {
              if (kp == i) jp else {
                if (w(jp) == w(kp)) {
                  rec(jp + 1, kp + 1)
                } else {
                  rec(0, ((kp - jp) + 1))
                }
              }
            }
            rec(0, 1)
          }
        }
        def gen_inv(cj: Int, s: Rep[String], j: Var[Int], k: Var[Int]): Rep[Boolean] = {
          (readVar(j) == cj) ==> match_range(s+(readVar(k)-cj), 0, cj)
        }
        def gen_case(cj: Int, s: Rep[String], j: Var[Int], k: Var[Int]): Rep[Unit] = {
          if (w(cj) == s(k)) {
            j += 1
            k += 1
          } else {
            val r = rematch(w, cj)
            if (r == -1) {
              j = 0
              k += 1
            } else {
              j = r
            }
          }
        }
        def gen_invs(from: Int, to: Int, s: Rep[String], j: Var[Int], k: Var[Int]): Rep[Boolean] = {
          if (from == to) unit(true) else {
            gen_inv(from, s, j, k) && gen_invs(from+1, to, s, j, k)
          }
        }
        def gen_ifs(from: Int, to: Int, s: Rep[String], j: Var[Int], k: Var[Int]): Rep[Unit] = {
          if (from == to) () else {
            if (j == from) gen_case(from, s, j, k)
            else gen_ifs(from+1, to, s, j, k)
          }
        }
        val matcher = toplevel("matcher",
          { (s: Rep[String]) =>
            var j = 0
            var k = 0
            loop(0 <= readVar(k) && readVar(k) <= s.length &&
              valid_string(s) &&
              0 <= readVar(j) && readVar(j) <= w.length &&
              exists{i: Rep[Int] => 0 <= i && i < k-j && match_w(s)} &&
              gen_invs(1, w.length, s, j, k),
              list_new(readVar(j)::readVar(k)::Nil),
              s.length*w.length - readVar(k)) {
              while (readVar(k) < s.length && readVar(j) < w.length) {
                gen_ifs(0, w.length, s, j, k)
              }
            }
            j==w.length
          },
          { (s: Rep[String]) => valid_string(s) },
          { (s: Rep[String]) => (r: Rep[Boolean]) => unit(true) }
        )
      }
      exec(w, (new KMPProg with Impl).code) // TODO: check
    }
  }
  gen("aab")
}
