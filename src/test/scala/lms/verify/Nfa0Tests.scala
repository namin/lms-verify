package lms.verify

object nfa0 {

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
    def next(m: Int): List[Int] = {
      (0 until transitions.length).filter(transitions(m)(_).nonEmpty).toList
    }
    def reachable(r: Int, t: Int): Boolean = {
      System.out.println("r:"+r)
      System.out.println("t:"+t)
      var seen: Set[Int] = Set.empty
      var queue: List[Int] = next(r)
      while (queue.nonEmpty) {
        val m = queue.head
        System.out.println("m:"+m)
        if (m==t) return true
        queue = queue.tail
        if (!seen.contains(m)) {
          seen += m
          queue = next(m):::queue
        }
      }
      false
    }
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

trait CommonLib {
  type CharSet = Set[Char]
  def set[A](xs: A*) = Set(xs: _*)
  def list[A](xs: A*) = List(xs: _*)
}

trait StagedLib extends Dsl with Reader with CommonLib {
  def infix_has(cs: CharSet, c: Rep[Char]) =
    cs.foldLeft(unit(false))(_ || _==c)
}

trait NfaStagedLib extends NfaLib with DfaLib with LetrecLib with StagedLib {
  def splitc(nfa: Nfa, cur: StSet, c: Rep[Char], k: StSet => Rep[Boolean]): Rep[Boolean] = {
    nexts(nfa, cur).foldLeft{unit(false)}{(r: Rep[Boolean], kv: (StSet, CharSet)) =>
      val ss = kv._1
      val cs = kv._2
      if (cs.has(c)) k(ss) else r
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

trait DfaStagedLib extends DfaLib with StagedLib {
  def staged_dfa_accept(dfa: Dfa) = {
    val r0n = ((0 until dfa.finals.size):Range).toVector
    def foldThunks[B:Typ](b: =>Rep[B])(f: ((Unit=>Rep[B]),Int) => Rep[B]): Rep[B] = ((r0n.foldLeft[Unit=>Rep[B]]{(_:Unit) => b}{
      (bt:(Unit=>Rep[B]),r:Int) => (_:Unit) => f(bt,r)
    })(()))
    toplevel("dfa", { inp: Rep[Array[Char]] =>
      requires(valid_input(inp))
      requires(inp.length<=Int.MaxValue) // to avoid overflow error in SPEC!
      var m = true
      var id = 0
      val i = ghostVar(0)
      var cur = inp
      val n = inp.length
      def in_finals = foldThunks(unit(false)){(b,r) =>
        (if (dfa.finals(r)) (id==r) else unit(false)) || b(())}
      loop((valid_input(inp) &&
          ((unit(0) <= i) && (i <= n)) &&
          (cur==inp.to(i)) &&
        valid_input(inp.to(i))),
        List[Any](readVar(cur),readVar(i),readVar(id),readVar(m)),
        cur.length){
      while (!cur.atEnd && m) {
        loop_invariant{cur.atEnd ==> (inp.length==i)}
        loop_invariant{(!cur.atEnd) ==> (inp.length!=i)}
        loop_invariant{foldThunks(unit(false)){(b,r) => id==r || b(())}}

        cur = cur.rest
        ghost{i = i+1}
      }}
      val res = cur.atEnd && m && in_finals
      _assert(cur.atEnd || !m)
      res
    })
  }
}

trait DfaExamples extends DfaLib {
  val dfa1 = Dfa(Vector(false, false, true), Vector(
    Vector(Set(), Set('A'), Set()),
    Vector(Set(), Set('A'), Set('B')),
    Vector(Set(), Set(), Set())))

  val dfa2 = Dfa(Vector(false, false, false, true), Vector(
    Vector(Set(), Set('W'), Set(), Set()),
    Vector(Set(), Set('X'), Set('Y'), Set()),
    Vector(Set(), Set(), Set('Y'), Set('Z')),
    Vector(Set(), Set(), Set(), Set())))

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
}

class Dfa0Tests extends TestSuite {
  val under = "nfa2dfa_"
  test("1") {
    trait Dfa1 extends nfa0.DfaLib with nfa0.NfaExamples with nfa0.DfaExamples {
      val res = nfa2dfa(nfa1)
      println(res)
    }
    lazy val ex = new Dfa1 {}
    checkOut("aapb", ex, "scala")
    assert(ex.res == ex.dfa1)
  }
  test("3") {
    trait Dfa3 extends nfa0.DfaLib with nfa0.NfaExamples with nfa0.DfaExamples {
      val res = nfa2dfa(nfa3)
      println(res)
    }
    lazy val ex = new Dfa3 {}
    checkOut("3", ex, "scala")
    assert(ex.res == ex.dfa3)
  }
}

class StagedDfa0Tests extends TestSuite {
  val under = "dfa0_staged_"
  test("1") {
    trait Dfa1 extends nfa0.DfaStagedLib with nfa0.NfaExamples with nfa0.DfaExamples {
      val machine = staged_dfa_accept(dfa1)
    }
    check("aapb", (new Dfa1 with Impl).code)
  }
  test("2") {
    trait Dfa2 extends nfa0.DfaStagedLib with nfa0.NfaExamples with nfa0.DfaExamples {
      val machine = staged_dfa_accept(dfa2)
    }
    check("2", (new Dfa2 with Impl).code)
  }
  test("3") {
    trait Dfa3 extends nfa0.DfaStagedLib with nfa0.NfaExamples with nfa0.DfaExamples {
      val machine = staged_dfa_accept(dfa3)
    }
    check("3", (new Dfa3 with Impl).code)
  }
}

class Nfa0Tests extends TestSuite {
  val under = "nfa_"
  test("1") {
    trait Nfa1 extends nfa0.NfaStagedLib with nfa0.NfaExamples {
      val machine = staged_accept(nfa1)
    }
    check("aapb", (new Nfa1 with Impl).code)
  }
  test("2") {
    trait Nfa2 extends nfa0.NfaStagedLib with nfa0.NfaExamples {
      val machine = staged_accept(nfa2)
    }
    check("aapb", (new Nfa2 with Impl).code)
  }
  test("3") {
    trait Nfa3 extends nfa0.NfaStagedLib with nfa0.NfaExamples {
      val machine = staged_accept(nfa3)
    }
    check("3", (new Nfa3 with Impl).code)
  }
}
