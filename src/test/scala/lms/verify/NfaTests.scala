package lms.verify

trait NfaLib {
  type St = Int
  type StSet = Set[St]
  def empty_ss = Set.empty[St]
  type CharMap[T] = Map[Char,T]
  type Transitions = CharMap[StSet]
  def empty_t = Map.empty[Char,StSet]
  case class Nfa(start: St, finals: StSet, next: St => Transitions)

  def find_states(sym: Char, nfa: Nfa, m: St): StSet =
    nfa.next(m).getOrElse(sym, Set.empty[St])

  def flat_map(f: St => StSet, ss: StSet): StSet =
    ss.foldRight(Set.empty[St]){case (s: St, t: StSet) => f(s).union(t)}
  def nextss(curs: StSet, sym: Char, nfa: Nfa): StSet = flat_map(find_states(sym, nfa, _), curs)

  def accept(nfa: Nfa, inp: Seq[Char]): Boolean = {
    def step(cur: StSet, cs: Seq[Char]): Boolean =
      if (cs.isEmpty) !nfa.finals.intersect(cur).isEmpty
      else step(nextss(cur, cs.head, nfa), cs.tail)
    step(Set(nfa.start), inp)
  }
}

trait LetrecLib {
  def letrec[A,B,C](same: (A,A) => Boolean, rhs: (A => B) => A => Int => B, body: (A => B) => C, pre: Option[Int => B] = None): C = {
    def infix_get[B](m: List[(A,B)], x: A): Option[B] =
      m.find{kv => same(kv._1,x)}.map(_._2)
    var seen: List[(A,Int)] = Nil
    var table: List[(A,B)] = Nil
    def resolve(index: A): B =
      (table.get(index), seen.get(index)) match {
        case (Some(r), _) => r
        case (None, None) =>
          val id = seen.size
          seen = (index -> id)::seen
          val r = rhs(resolve)(index)(id)
          table = (index -> r)::table
          r
        case (None, Some(id)) => pre.get(id)
      }
    body(resolve)
  }
}

trait DfaLib extends NfaLib with CommonLib with LetrecLib {
  type StSetMap[T] = Map[StSet,T]
  def empty_ssm = Map.empty:StSetMap[CharSet]

  def next_states(nfa: Nfa, s: St): StSetMap[CharSet] =
    nfa.next(s).foldLeft(empty_ssm){(ssm, kv) =>
      val c = kv._1
      val v = kv._2
        ssm.get(v) match {
          case None => ssm + (v -> Set(c))
          case Some(s) => ssm + (v -> (s + c))
        }
    }

  def mergeMaps(maps: StSetMap[CharSet]*): StSetMap[CharSet] =
    maps.foldLeft(empty_ssm){
      (r: StSetMap[CharSet], m: StSetMap[CharSet]) =>
      m.foldLeft(r){
        (dict: StSetMap[CharSet], (kv: (StSet,CharSet))) =>
        val k = kv._1; val v = kv._2
        dict + (k -> (v.union(dict.getOrElse(k, Set.empty[Char]))))
      }}

  def nexts(nfa: Nfa, cur: StSet): StSetMap[CharSet] =
    cur.foldLeft(empty_ssm){
      (ssm: StSetMap[CharSet], st: St) =>
      mergeMaps(ssm, next_states(nfa, st))
    }

  case class Dfa(finals: Vector[Boolean], transitions: Vector[Vector[CharSet]]) {
    override def toString = "Dfa("+finals+", Vector(\n"+
    transitions.map{ts => ts.map{cs => cs.map("'"+_+"'")}}.mkString(",\n")+"))"
  }
  def nfa2dfa(nfa: Nfa): Dfa = {
    import scala.collection.mutable.ArrayBuffer

    def grow[A](x: ArrayBuffer[A], size: Int, v: A) = {
      (for (i <- 0 until (size-x.size)) yield
        x += v
      )
      x
    }

    val finals: ArrayBuffer[Boolean] = new ArrayBuffer[Boolean]()
    val transitions: ArrayBuffer[ArrayBuffer[CharSet]] = new ArrayBuffer[ArrayBuffer[CharSet]]()
    def rhs(step: (StSet => Int))(cur: StSet)(id: Int) = {
      grow(finals, id+1, false)
      grow(transitions, id+1, null)
      finals(id) = !(cur intersect nfa.finals).isEmpty
      transitions(id) = new ArrayBuffer[CharSet](id+1)
      nexts(nfa, cur).foldLeft{()}{(r: Unit, kv: (StSet, CharSet)) =>
        val ss = kv._1
        val cs = kv._2
        val next_id = step(ss)
        grow(transitions(id), next_id+1, Set[Char]())
        transitions(id)(next_id) = cs
      }
      id
    }
    letrec({(x:StSet,y:StSet) => x==y}, rhs,
      {(resolve: (StSet => Int)) =>
        resolve(set(nfa.start))},
      Some{(id: Int) => id})
    val finalsVec = finals.toVector
    val transitionsVec = transitions.toVector.map{ts => grow(ts, finalsVec.size, Set[Char]()).toVector}
    Dfa(finalsVec, transitionsVec)
  }
}

/**
Adapted from Regexp in AutomataTests.scala
*/
trait Re {
  type RE

  val id: RE
  def c(c0: Char): RE
  def in(a: Char, b: Char): RE
  def alt(x: RE, y: RE): RE
  def seq(x: RE, y: RE): RE
  def star(x: RE)(resolve: RE => RE): RE
  def opt(x: RE): RE = alt(x, id)
  def many(f: (RE, RE) => RE)(x: RE, xs: RE*): RE = xs.length match {
    case 0 => x
    case 1 => f(x, xs(0))
    case n => f(x, many(f)(xs(0), xs.slice(1, n) : _*))
  }
}

/**
Adapted from
https://github.com/devongovett/regexgen/blob/master/src/regex.js

TODO: simplify regular expression.
*/
trait Dfa2ReLib extends DfaLib with Re {
  def union(re1: Option[RE], re2: Option[RE]): Option[RE] = (re1, re2) match {
    case (Some(re1), Some(re2)) => Some(alt(re1, re2))
    case (Some(re1), None) => Some(re1)
    case (None, Some(re2)) => Some(re2)
    case (None, None) => None
  }

  def dfa2re(dfa: Dfa)(resolve: RE => RE): Vector[RE] = {
    val a: Array[Array[Option[RE]]] = dfa.transitions.toArray.map{ts => ts.toArray.map{cs => if (cs.isEmpty) None else {
      val xs = cs.toList.map(c)
      Some(many(alt)(xs.head, xs.tail: _*))
    }}}
    val b: Array[Option[RE]] = dfa.finals.toArray.map{b => if (b) Some(id) else None}

    for (n <- dfa.finals.size - 1 to 0 by -1) {
      a(n)(n).foreach{ ann =>
        b(n) = b(n).map{bn => seq(star(ann)(resolve), bn)}
        for (j <- 0 until n) {
          a(n)(j) = a(n)(j).map{anj => seq(star(ann)(resolve), anj)}
        }
      }
      for (i <- 0 until n) {
        a(i)(n).foreach{ ain =>
          b(i) = union(b(i), b(n).map{bn => seq(ain, bn)})
          for (j <- 0 until n) {
            a(i)(j) = union(a(i)(j), a(n)(j).map{anj => seq(ain, anj)})
          }
        }
      }
    }
    b.toVector.map(_.get)
  }
}

trait Re2Str extends Re {
  type RE = String

  def c(c0: Char): RE = c0.toString
  def in(a: Char, b: Char): RE = "["+a+"-"+b+"]"
  def wildcard: RE = "."
  def alt(x: RE, y: RE): RE = "("+x+"|"+y+")"
  def seq(x: RE, y: RE): RE = x+y
  val id: RE = "$"
  def star(x: RE)(resolve: RE => RE): RE = "("+x+")*"
}

trait Re2Spec extends Re with StagedLib with LetrecLib {
  case class RE(id: String, f: Rep[Input] => Rep[Input])

  def c(c0: Char): RE = {RE(c0.toString, {cs: Rep[Input] =>
    if (cs.first==c0) cs.rest else unit(null)})}
  def in(a: Char, b: Char): RE = {RE("["+a+"-"+b+"]", {cs: Rep[Input] =>
    if (a<=cs.first && cs.first<=b) cs.rest else unit(null)})}
  def wildcard: RE = {RE(".", {cs: Rep[Input] =>
    if (cs.atEnd) unit(null) else cs.rest})}
  def alt(x: RE, y: RE): RE = {RE("("+x.id+"|"+y.id+")", {cs: Rep[Input] =>
    val cx = x.f(cs)
    if (cx != unit(null)) cx else y.f(cx)})}
  def seq(x: RE, y: RE): RE = {RE(x.id+y.id, {cs: Rep[Input] =>
    val cx = x.f(cs)
    if (cx != unit(null)) y.f(cx) else unit(null)})}
  val id: RE = {RE("$", {cs: Rep[Input] => if (cs.atEnd) cs else unit(null)})}
  def star(x: RE)(resolve: RE => RE): RE = {
    lazy val star_x: RE = resolve(RE("("+x.id+")*",
      {cs => alt(seq(x, star_x), id).f(cs)}))
    star_x
  }
  def sameRe(x: RE, y: RE) = x.id==y.id
}

trait Re2Ast extends Re {
  abstract class RE
  case class C(c0: Char) extends RE
  case class R(a: Char, b: Char) extends RE
  case object W extends RE
  case class Alt(x: RE, y: RE) extends RE
  case class Cat(x: RE, y: RE) extends RE
  case object I extends RE
  case class Star(x: RE) extends RE
  def c(c0: Char): RE = C(c0)
  def in(a: Char, b: Char): RE = R(a, b)
  def wildcard: RE = W
  def alt(x: RE, y: RE): RE = Alt(x, y)
  def seq(x: RE, y: RE): RE = Cat(x, y)
  val id: RE = I
  def star(x: RE)(resolve: RE => RE): RE = Star(x)
}

trait Re2Pr extends Re with Re2Ast with StagedLib with LetrecLib {
  type RF = (Rep[Input], Rep[Int], Rep[Int]) => Rep[Boolean]
  // redoing letrec...
  var prtable: Set[String] = set()
  def mkpr(name: String, f: RF): RF = {
    if (prtable.contains(name)) {
      val r: RF = {(inp,i,j) =>
        toplevelApply[Boolean](name, list(inp, i, j))}
      r
    } else {
      prtable += name
      val r: RF = unwrap3(toplevel(name, wrap3(f), spec=true, code=false))
      r
    }
  }
  def re2pr(r: RE): RF = r match {
    case C(c) => {(inp,i,j) => c==inp(i) && j==i+1}
    case R(a, b) => {(inp,i,j) => a<=inp(i) && inp(i)<=b && j==i+1}
    case W => {(inp,i,j) => !inp.to(i).atEnd && j==i+1}
    case Alt(x, y) => {(inp,i,j) => re2pr(x)(inp,i,j) || re2pr(y)(inp,i,j) }
    case Cat(x, y) => {(inp,i,j) => exists{m: Rep[Int] =>
      i <= m && m <= j && re2pr(x)(inp,i,m) && re2pr(y)(inp,m,j)}}
    case I => {(inp,i,j) => i==j}
    case Star(C(c)) => {
      lazy val rec: RF = { mkpr("star_"+c, { (inp, i, j) =>
        (c==inp(i) && rec(inp, i+1, j)) || (i==j)}) }
      {(inp,i,j) => rec(inp,i,j)}
    }
  }
}

trait CommonLib {
  type CharSet = Set[Char]
  def set[A](xs: A*) = Set(xs: _*)
  def list[A](xs: A*) = List(xs: _*)
}

trait StagedLib extends Dsl with Reader with CommonLib {
  def infix_contains(cs: CharSet, c: Rep[Char]) =
    cs.foldLeft(unit(false))(_ || _==c)
}

trait NfaStagedLib extends NfaLib with DfaLib with LetrecLib with StagedLib {
  def splitc(nfa: Nfa, cur: StSet, c: Rep[Char], k: StSet => Rep[Boolean]): Rep[Boolean] = {
    nexts(nfa, cur).foldLeft{unit(false)}{(r: Rep[Boolean], kv: (StSet, CharSet)) =>
      val ss = kv._1
      val cs = kv._2
      if (cs.contains(c)) k(ss) else r
    }
  }
  def staged_accept(nfa: Nfa) = {
    def rhs(step: (StSet => Rep[Array[Char]] => Rep[Boolean]))(ss: StSet)(id: Int) = toplevel("nfa_"+id, {(cs: Rep[Array[Char]]) =>
      if (cs.atEnd) unit(!(ss intersect nfa.finals).isEmpty)
      else splitc(nfa, ss, cs.first, {(ss: StSet) => step(ss)(cs.rest) })})
    letrec({(x:StSet,y:StSet) => x==y}, rhs,
      {(resolve: (StSet => Rep[Array[Char]] => Rep[Boolean])) =>
        resolve(set(nfa.start))})
  }
}

trait DfaStagedLib extends DfaLib with StagedLib with Dfa2ReLib with Re2Pr {
  def staged_dfa_accept(dfa: Dfa) = {
    val r0n = ((0 until dfa.finals.size):Range).toVector
    val res = dfa2re(dfa)(null).map(re2pr)
    val fwd = r0n.map{r:Int => mkpr("re_"+r, res(r))}
    val re = fwd(0)
    def matching(re: RF, inp: Rep[Input], i: Rep[Int], j: Rep[Int]): Rep[Boolean] = re(inp, i, j)
    def re_invariant(r: Int, inp: Rep[Input], i: Rep[Int]): Rep[Boolean] = (matching(fwd(r), inp, i, inp.length) ==> matching(re, inp, i, inp.length))
    def re_invariants(id: Rep[Int], inp: Rep[Input], i: Rep[Int]): Rep[Boolean] = r0n.foldLeft(unit(true)){(b,r) =>
      ((id == r) ==> (re_invariant(r, inp, i))) && b
    }
    def final_invariant(r: Int, inp: Rep[Input], i: Rep[Int]): Rep[Boolean] =
      ((i==inp.length) ==> matching(re, inp, 0, inp.length))
    def finals_invariants(id: Rep[Int], inp: Rep[Input], i: Rep[Int]): Rep[Boolean] = r0n.foldLeft(unit(true)){(b,r) =>
      if (dfa.finals(r)) ((id == r) ==> final_invariant(r, inp, i)) else b
    }
    def id_invariant(id: Var[Int]): Rep[Boolean] = r0n.foldLeft(unit(false)){(b,r) =>
      (id == r) || b
    }
    toplevel("dfa", { inp: Rep[Array[Char]] =>
      requires(valid_input(inp))
      ensures{(res: Rep[Boolean]) => res ==> matching(re, inp, 0, inp.length)}
      var matched = true
      var id = 0
      var i = 0
      val n = inp.length
      loop((valid_input(inp) &&
        valid_input(inp.to(i)) &&
        re_invariants(id, inp, i) &&
        finals_invariants(id, inp, i) &&
        id_invariant(id)),
        List[Any](i, id, matched),
        n-i) {
        while (i<n && matched) {
          var c = inp(i)
          r0n.foldLeft(unit(())){(b,r) =>
            if (id == r) {
              _assert(re_invariant(r, inp, i))
              matched =
                r0n.foldLeft(unit(false)){(b,t) =>
                  val chars = dfa.transitions(r)(t)
                  if (chars.nonEmpty && chars.contains(c)) {
                    id = t
                    _assert(re_invariant(t, inp, i+1))
                    if (dfa.finals(t)) {
                      _assert(final_invariant(r, inp, i+1))
                    }
                    unit(true)
                  } else b
                }
            } else b
          }
          i = i+1
        }}
      val finalId = readVar(id)
      val res = i==n && r0n.foldLeft(unit(false)){(b: Rep[Boolean],r: Int) => if (dfa.finals(r)) (r==finalId || b) else b}
      _assert(res ==> matching(re, inp, 0, inp.length))
      res
    })
  }
}

trait DfaExamples extends DfaLib {
  val dfa1 = Dfa(Vector(false, false, true), Vector(
    Vector(Set(), Set('A'), Set()),
    Vector(Set(), Set('A'), Set('B')),
    Vector(Set(), Set(), Set())))

  val dfa3 = Dfa(Vector(false, false, false, false, true), Vector(
    Vector(Set(), Set('A'), Set(), Set(), Set()),
    Vector(Set(), Set('A'), Set('B'), Set(), Set()),
    Vector(Set(), Set(), Set('B'), Set('C'), Set()),
    Vector(Set(), Set(), Set('B'), Set('C'), Set('D')),
    Vector(Set(), Set(), Set(), Set(), Set('D'))))

}

trait NfaExamples extends NfaLib with CommonLib {
  val nfa1 = Nfa(1, set(3), {s => s match {
    case 1 => Map(('A' -> set(2)))
    case 2 => Map(('A' -> set(2)), ('B' -> set(3)))
    case 3 => empty_t
  }})

  // equivalent
  val nfa2 = Nfa(1, set(3), {s => s match {
    case 1 => Map(('A' -> set(1,2)))
    case 2 => Map(('A' -> set(1,2)), ('B' -> set(3)))
    case 3 => empty_t
  }})

  val nfa3 = Nfa(1, set(5), {s => s match {
    case 1 => Map(('A' -> set(1, 2)))
    case 2 => Map(('B' -> set(2, 3)))
    case 3 => Map(('C' -> set(2, 3, 4)))
    case 4 => Map(('D' -> set(5)))
    case 5 => Map(('D' -> set(5)))
  }})
}

class DfaTests extends TestSuite {
  val under = "nfa2dfa_"

  test("1") {
    trait Dfa1 extends DfaLib with NfaExamples with DfaExamples {
      val res = nfa2dfa(nfa1)
      println(res)
    }
    lazy val ex = new Dfa1 {}
    checkOut("aapb", ex, "scala")
    assert(ex.res == ex.dfa1)
  }

  test("3") {
    trait Dfa3 extends DfaLib with NfaExamples with DfaExamples {
      val res = nfa2dfa(nfa3)
      println(res)
    }
    lazy val ex = new Dfa3 {}
    checkOut("3", ex, "scala")
    assert(ex.res == ex.dfa3)
  }
}

class Dfa2ReTests extends TestSuite {
  val under = "dfa2re_"
  trait Dfa2RePrinter extends Dfa2ReLib with Re2Str {
    def print(dfa: Dfa) {
      val n = dfa.finals.size
      val p = dfa2re(dfa)(null)
      for (i <- 0 until n) {
        println(i+": "+p(i))
      }
    }
  }
  test("1") {
    trait Ex1 extends Dfa2RePrinter with DfaExamples {
      print(dfa1)
    }
    checkOut("aapb", new Ex1 {}, "txt")
  }
  test("3") {
    trait Ex3 extends Dfa2RePrinter with DfaExamples {
      print(dfa3)
    }
    checkOut("3", new Ex3 {}, "txt")
  }
}

class StagedDfaTests extends TestSuite {
  val under = "dfa_staged_"

  test("1") {
    trait Dfa1 extends DfaStagedLib with NfaExamples with DfaExamples {
      val machine = staged_dfa_accept(dfa1)
    }
    check("aapb", (new Dfa1 with Impl).code)
  }

  test("3") {
    trait Dfa3 extends DfaStagedLib with NfaExamples with DfaExamples {
      val machine = staged_dfa_accept(dfa3)
    }
    check("3", (new Dfa3 with Impl).code)
  }
}

class NfaTests extends TestSuite {
  val under = "nfa_"

  test("1") {
    trait Nfa1 extends NfaStagedLib with NfaExamples {
      val machine = staged_accept(nfa1)
    }
    check("aapb", (new Nfa1 with Impl).code)
  }

  test("2") {
    trait Nfa2 extends NfaStagedLib with NfaExamples {
      val machine = staged_accept(nfa2)
    }
    check("aapb", (new Nfa2 with Impl).code)
  }

  test("3") {
    trait Nfa3 extends NfaStagedLib with NfaExamples {
      val machine = staged_accept(nfa3)
    }
    check("3", (new Nfa3 with Impl).code)
  }
}
