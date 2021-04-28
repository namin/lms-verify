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

/**
Adapted from
https://github.com/devongovett/regexgen/blob/master/src/regex.js

TODO: simplify regular expression.
*/
trait Dfa2ReLib extends DfaLib with Regexp/*from AutomataTests.scala*/ {
  def union(re1: Option[RE], re2: Option[RE]): Option[RE] = (re1, re2) match {
    case (Some(re1), Some(re2)) => Some(alt(re1, re2))
    case (Some(re1), None) => Some(re1)
    case (None, Some(re2)) => Some(re2)
    case (None, None) => None
  }

  def dfa2re_backwards(dfa: Dfa): Vector[Option[RE]] = {
    val rn = (0 until dfa.finals.size).toVector
    (rn.map{r => _dfa2re(Dfa(rn.map{t => r==t}, dfa.transitions))}).map(_(0))
  }
  def dfa2re(dfa: Dfa): Vector[RE] = (_dfa2re(dfa)).map(_.get)
  def _dfa2re(dfa: Dfa): Vector[Option[RE]] = {
    val a: Array[Array[Option[RE]]] = dfa.transitions.toArray.map{ts => ts.toArray.map{cs => if (cs.isEmpty) None else {
      val xs = cs.toList.map(c)
      Some(many(alt)(xs.head, xs.tail: _*))
    }}}
    val b: Array[Option[RE]] = dfa.finals.toArray.map{b => if (b) Some(id) else None}

    for (n <- dfa.finals.size - 1 to 0 by -1) {
      a(n)(n).foreach{ ann =>
        b(n) = b(n).map{bn => seq(star(ann), bn)}
        for (j <- 0 until n) {
          a(n)(j) = a(n)(j).map{anj => seq(star(ann), anj)}
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
    b.toVector
  }
}

trait Re2Str extends Regexp {
  type RE = String

  def c(c0: Char): RE = c0.toString
  def in(a: Char, b: Char): RE = "["+a+"-"+b+"]"
  def wildcard: RE = "."
  def alt(x: RE, y: RE): RE = "("+x+"|"+y+")"
  def seq(x: RE, y: RE): RE = x+y
  val id: RE = "$"
  def star(x: RE): RE = "("+x+")*"
}

trait Re2Ast extends Regexp {
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
  def star(x: RE): RE = Star(x)

  def len(r: RE): Option[Int] = r match {
    case C(_) => Some(1)
    case R(_,_) => Some(1)
    case W => Some(1)
    case Alt(x, y) => (len(x),len(y)) match {
      case (Some(x),Some(y)) if x==y => Some(x)
      case _ => None
    }
    case Cat(x, y) => (len(x),len(y)) match {
      case (Some(x),Some(y)) => Some(x+y)
      case _ => None
    }
    case I => Some(0)
    case Star(_) => None
  }
}

trait Re2Pr extends Re2Ast with StagedLib with LetrecLib {
  type RF = (Rep[Input], Rep[Int], Rep[Int]) => Rep[Boolean]
  type RU = (Rep[Input], Rep[Int], Rep[Int]) => Rep[Unit]
  type RL = (Rep[Input], Rep[Int], Rep[Int], Rep[Int]) => Rep[Unit]
  val never_match: RF = {(inp,i,n) => unit(false)}
  def re_lemma(name: String, inp: Rep[Input], i: Rep[Int], n: Rep[Int], stop: Rep[Int]): Rep[Unit] =
    toplevelApply[Unit]("lemma_"+name, list(inp, i, n, stop))
  def re_pr(name: String)(inp: Rep[Input], i: Rep[Int], n: Rep[Int]): Rep[Boolean] =
    toplevelApply[Boolean](name, list(inp, i, n))
  def mkpr(name: String, a: RE, f: RF): RF = rec.get(name) match {
    case Some(_) => {
      val r: RF = {(inp,i,j) => toplevelApply[Boolean](name, list(inp,i,j))}
      r
    }
    case None =>
      val r: RF = unwrap3(toplevel(name, wrap3(f), spec=true, code=false))
      if (name.startsWith("star_")) {
        val Star(u) = a
        val C(chr) = u //TODO: generalize?
        val c_all: RU = unwrap3(toplevel("lemma_"+name+"_all", wrap3({(inp:Rep[Input],i:Rep[Int],j:Rep[Int]) =>
          requires(valid_input(inp))
          requires(0<=i && i<=j && j <= inp.length)
          requires(r(inp, i, j))
          ensures{_:Rep[Unit] => forall{m: Rep[Int] => (0<=i && i<=m && m<j) ==> (re2pr(u)(inp, m, m+1))}}
          var x = i
          loop(0 <= i && i <= x && j <= inp.length,
            List[Any](x), j-x) {
            while (x < j) {
              loop_invariant(r(inp, x, j))
              loop_invariant(forall{m: Rep[Int] => (i<=m && m < x) ==> (inp.to(m).first==chr)})
              x = x+1
            }
          }
        }),spec=false,code=true))
        val c_from_all: RU = unwrap3(toplevel("lemma_"+name+"_from_all", wrap3({(inp:Rep[Input],i:Rep[Int],j:Rep[Int]) =>
          requires(valid_input(inp))
          requires(0<=i && i<=j && j <= inp.length)
          requires{forall{m: Rep[Int] => (0<=i && i<=m && m<j) ==> (re2pr(u)(inp, m, m+1))}}
          ensures{_:Rep[Unit] => r(inp, i, j)}
          var x = j
          loop(0 <= i && i <= x && j <= inp.length,
            List[Any](x), x) {
            while (i < x) {
              loop_invariant(r(inp, x, j))
              loop_invariant{forall{m: Rep[Int] => (0<=i && i<=m && m<j) ==> (re2pr(u)(inp, m, m+1))}}
              x = x-1
            }
          }
        }),spec=false,code=true))
        val c_dec: RU = unwrap3(toplevel("lemma_"+name+"_dec", wrap3({(inp:Rep[Input],i:Rep[Int],j:Rep[Int]) =>
          requires(valid_input(inp))
          requires(0<=i && i<=j)
          requires(i<j && j<=inp.length)
          requires(r(inp, i, j))
          ensures{_:Rep[Unit] => r(inp,i,j-1)}
          ghost{c_all(inp,i,j)}
          ghost{c_from_all(inp,i,j-1)}
        }),spec=false,code=true))
        val c: RL = unwrap4(toplevel("lemma_"+name, wrap4({(inp,start,i,j) =>
          requires(valid_input(inp))
          requires(0<=start && start<=i)
          requires(0<=i && i<j)
          requires(0<=j && j<=inp.length)
          requires(r(inp, start, i))
          requires(r(inp, i, j))
          requires(i+1==j)
          ensures{res: Rep[Unit] => r(inp, start, j)}
          var x = i
          loop(0 <= start && start <= x && x <= j && j <= inp.length,
            List[Any](x), x) {
            while (start < x) {
              loop_invariant(r(inp, x, j))
              loop_invariant(r(inp, start, x))
              c_dec(inp, start, x)
              _assert(start<x)
              ghost{c_all(inp, start, x)}
              _assert(re2pr(u)(inp, x-1, x))
              _assert(r(inp, x, j))
              _assert(r(inp, x-1, j))
              x = x-1;
            }
          }
        }), spec=false, code=true))
      }
      r
  }
  def key(r:RE): String = r match {
    case C(c) => c.toString
    case R(a, b) => a.toString+"_to_"+b.toString
    case W => "w"
    case Alt(x, y) => "_or"+key(x)+"_or_"+key(y)+"or_"
    case Cat(x, y) => key(x)+key(y)
    case I => "i"
    case Star(x) => "_s"+key(x)+"s_"
  }
  def re2pr(r: RE): RF = r match {
    case C(c) => {(inp,i,j) => c==inp(i) && j==i+1}
    case R(a, b) => {(inp,i,j) => a<=inp(i) && inp(i)<=b && j==i+1}
    case W => {(inp,i,j) => !inp.to(i).atEnd && j==i+1}
    case Alt(x, y) => {(inp,i,j) => re2pr(x)(inp,i,j) || re2pr(y)(inp,i,j) }
    case Cat(x, y) => (len(x),len(y)) match {
      case (_,Some(ly)) => {(inp,i,j) => i<=j-ly && re2pr(x)(inp,i,j-ly) && re2pr(y)(inp,j-ly,j)}
      case (Some(lx),_) => {(inp,i,j) => re2pr(x)(inp,i,i+lx) && i+lx<=j && re2pr(y)(inp,i+lx,j)}
      case (None,None) => {(inp,i,j) => (i until (j+1)).exists{m =>
      re2pr(x)(inp,i,m) && re2pr(y)(inp,m,j)}}}
    case I => {(inp,i,j) => i==j}
    case Star(x) => {
      lazy val z: RF = { mkpr("star_"+key(x), r, { (inp,i,j) =>
        len(x) match {
          case Some(lx) => (i==j) || (i<j && (re2pr(x)(inp,i,i+lx) && z(inp,i+lx,j)))
          case None => (i==j) || ((i<j) && (i until (j+1)).exists{m =>
            re2pr(x)(inp,i,m) && z(inp,m,j)})}})}
      z
    }
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

trait DfaStagedLib extends DfaLib with StagedLib with Dfa2ReLib with Re2Pr {
  def staged_dfa_accept(dfa: Dfa) = {
    val r0n = ((0 until dfa.finals.size):Range).toVector
    def foldThunks[B:Typ](b: =>Rep[B])(f: ((Unit=>Rep[B]),Int) => Rep[B]): Rep[B] = ((r0n.foldLeft[Unit=>Rep[B]]{(_:Unit) => b}{
      (bt:(Unit=>Rep[B]),r:Int) => (_:Unit) => f(bt,r)
    })(()))
    val dfa_res = dfa2re(dfa)
    val res = dfa_res.map(re2pr)
    val fwd = r0n.map{r:Int => mkpr("re_"+r, dfa_res(r), res(r))}
    val res_bwd = dfa2re_backwards(dfa)
    val bwd = r0n.map{r => res_bwd(r).map{p => mkpr("re_bwd_"+r, p, re2pr(p))}.getOrElse{never_match}}
    val re = fwd(0)
    def sanity(r: Int, t: Int): String = "sanity_"+r+"_"+t
    r0n.foreach{r =>
      r0n.foreach{t =>
          toplevel("lemma_"+sanity(r,t), wrap4({(inp: Rep[Input], i: Rep[Int], m: Rep[Int], j: Rep[Int]) =>
            requires(valid_input(inp))
            requires(inp.length<=Int.MaxValue)
            requires(0<=i && i<=m && m<=j && j < inp.length)
            requires(dfa.transitions(r)(t).foldLeft(unit(false)){
              (b:Rep[Boolean],c:Char) => inp(j)==c || b})
            if (r==t) {
              dfa.transitions(r)(t).foreach{c =>
                requires(re_pr("star_"+c)(inp, m, j))
                requires(forall{x: Rep[Int] => m<=x ==> ((bwd(t)(inp, i, m) && re_pr("star_"+c)(inp, m, x)) ==> bwd(t)(inp, i, x))})
                requires(bwd(t)(inp, i, m))
              }
            }
            requires(bwd(r)(inp, i, j))
            ensures{_:Rep[Unit] => bwd(t)(inp, i, j+1)}
            if (r==t) {
              dfa.transitions(r)(t).foreach{c =>
                ensures{_:Rep[Unit] => re_pr("star_"+c)(inp, m, j+1)}
                ghost{re_lemma("star_"+c, inp, m, j, j+1)}
                _assert(forall{x: Rep[Int] => m<=x ==> ((bwd(t)(inp, i, m) && re_pr("star_"+c)(inp, m, x)) ==> bwd(t)(inp, i, x))})
                _assert(m<=j+1 ==> ((bwd(t)(inp, i, m) && re_pr("star_"+c)(inp, m, j+1)) ==> bwd(t)(inp, i, j+1)))
                _assert(bwd(t)(inp, i, m))
              }
            } else {
              dfa.transitions(t)(t).foreach{c =>
                requires(re_pr("star_"+c)(inp, j+1, j+1))
                _assert(bwd(r)(inp, i, j))
                _assert(dfa.transitions(r)(t).foldLeft(unit(false)){
                  (b:Rep[Boolean],c:Char) => inp(j)==c || b})
                _assert(re_pr("star_"+c)(inp, j+1, j+1))
                requires(bwd(r)(inp, i, m))
                _assert(bwd(r)(inp, i, m))
                dfa.transitions(r)(r).foreach{c0 =>
                  requires(re_pr("star_"+c0)(inp, m, j))
                  _assert(re_pr("star_"+c0)(inp, m, j))
                }
              }
            }
          }),spec=false,code=true)}}
    toplevel("dfa", { inp: Rep[Array[Char]] =>
      requires(valid_input(inp))
      requires(inp.length<=Int.MaxValue) // to avoid overflow error in SPEC!
      ensures{(res: Rep[Boolean]) =>
        ((res ==> re(inp, 0, inp.length)) /*&&
         (re(inp, 0, inp.length) ==> res)*/)
      }
      var m = true
      var id = 0
      val i = ghostVar(0)
      var cur = inp
      val n = inp.length
      var cur_starts_map: Map[(Int,Char),Var[Int]] = Map.empty
      var cur_starts: List[Rep[Any]] = r0n.toList.flatMap{t =>
        dfa.transitions(t)(t).map{c =>
          val cur_start = ghostVar(-1)
          cur_starts_map += ((t,c) -> cur_start)
          readVar(cur_start)
        }
      }
      def tactic(r: Int, t: Int) = {
        dfa.transitions(t)(t).foreach{c =>
          val cur_start = cur_starts_map((t,c))
          if (!(dfa.transitions(t)(r).contains(c))) {
            ghost{cur_start = i+1}
            _assert(re_pr("star_"+c)(inp, i+1, i+1))
          } else {
            _assert(cur_start>=0)
            ghost{re_lemma("star_"+c, inp, cur_start, i, i+1)}
            _assert(re_pr("star_"+c)(inp, cur_start, i+1))
            ghost{re_lemma(sanity(r,t), inp, 0, cur_start, i)}
          }
        }
        if (r != t) {
          dfa.transitions(r)(r).foreach{c =>
            val cur_start = cur_starts_map((r,c))
            ghost{re_lemma(sanity(r,t), inp, 0, cur_start, i)}
            ghost{cur_start = -1}
          }
          if (dfa.transitions(r)(r).isEmpty)
            ghost{re_lemma(sanity(r,t), inp, 0, 0, i)}
        }
      }
      def in_finals = foldThunks(unit(false)){(b,r) =>
        (if (dfa.finals(r)) (id==r) else unit(false)) || b(())}
      loop((valid_input(inp) &&
          ((unit(0) <= i) && (i <= n)) &&
          (cur==inp.to(i)) &&
        valid_input(inp.to(i))),
        List[Any](readVar(cur)::readVar(i)::readVar(id)::readVar(m)::cur_starts: _*),
        cur.length){
      while (!cur.atEnd && m) {
        r0n.foreach{r: Int =>
          loop_invariant{((id == r) && m) ==> (bwd(r)(inp, 0, i))}}
        r0n.foreach{r: Int =>
          loop_invariant{((id == r) && !m) ==> bwd(r)(inp, 0, i-1)}}
        //loop_invariant(!re(inp, 0, i) ==> !re(inp, 0, inp.length))
        loop_invariant{(in_finals && cur.atEnd && m) ==> re(inp, 0, i)}
        //loop_invariant{(!in_finals) ==> !re(inp, 0, i)}
        loop_invariant{((m) ==> (foldThunks(unit(false)){(b,r) => (((bwd(r)(inp, 0, i))) || b(()))}))}
        //loop_invariant{((!m) ==> (foldThunks(unit(true)){(b,r) => ((!(bwd(r)(inp, 0, i))) && b(()))}))}
        loop_invariant{cur.atEnd ==> (inp.length==i)}
        loop_invariant{(!cur.atEnd) ==> (inp.length!=i)}
        loop_invariant{foldThunks(unit(false)){(b,r) => id==r || b(())}}
        r0n.foreach{t: Int => dfa.transitions(t)(t).foreach{c =>
          val cur_start = cur_starts_map((t,c))
          loop_invariant(unit(-1) <= cur_start && cur_start <= i)
          loop_invariant(cur_start>=0 ==> (id==t))
          loop_invariant((id==t) ==> cur_start>=0)
          loop_invariant((cur_start==unit(-1)) ==> (id!=t))
          loop_invariant((id!=t) ==> (cur_start==unit(-1)))
          loop_invariant(forall{j: Rep[Int] => (cur_start>=0 && cur_start<=j) ==> ((bwd(t)(inp, 0, cur_start) && re_pr("star_"+c)(inp, cur_start, j)) ==> bwd(t)(inp, 0, j))})
          loop_invariant((cur_start>=0) ==> bwd(t)(inp, 0, cur_start))
          loop_invariant((cur_start>=0 && m) ==> re_pr("star_"+c)(inp, cur_start, i))
        }}

        m = foldThunks(unit(false)){(b,r) =>
          if (id == r) {
            _assert((id == r) ==> bwd(r)(inp, 0, i))
            _assert(bwd(r)(inp, 0, i))
            foldThunks(unit(false)){(b,t) =>
              val chars = dfa.transitions(r)(t)
              if (chars.has(cur.first)) {
                _assert(bwd(r)(inp, 0, i))
                id = t
                tactic(r,t)
                _assert(bwd(t)(inp, 0, i+1))
                if (dfa.finals(t)) {
                  _assert(inp.to(i+1).atEnd ==> re(inp, 0, i+1))
                }
                unit(true)
              } else b(())
            }
          } else b(())
        }
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
      for ((h,p) <- list(
        ("forward", dfa2re(dfa)),
        ("backward", (dfa2re_backwards(dfa).map(_.get))))) {
        println(h)
        for (i <- 0 until n) {
          println(i+": "+p(i))
        }
      }
    }
  }
  test("1") {
    trait Ex1 extends Dfa2RePrinter with DfaExamples {
      print(dfa1)
    }
    checkOut("aapb", new Ex1 {}, "txt")
  }
  test("2") {
    trait Ex2 extends Dfa2RePrinter with DfaExamples {
      print(dfa2)
    }
    checkOut("2", new Ex2 {}, "txt")
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
  test("2") {
    trait Dfa2 extends DfaStagedLib with NfaExamples with DfaExamples {
      val machine = staged_dfa_accept(dfa2)
    }
    check("2", (new Dfa2 with Impl).code)
  }
  //TODO
  ignore("3") {
    trait Dfa3 extends DfaStagedLib with NfaExamples with DfaExamples {
      val machine = staged_dfa_accept(dfa3)
    }
    check("3", (new Dfa3 with Impl {
      override def orderDeps(xs: Set[String]) = {
        val (stars, rests) = xs.partition(_.startsWith("star_"))
        stars.toList.sortBy(_.length) ++ rests.toList
      }
    }).code)
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
