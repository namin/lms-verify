package lms.verify

// inspired by http://manojo.github.io/2015/09/04/staged-parser-combinators-recursion/

trait StagedParser extends Dsl {
  override def includes = super.includes:+"<string.h>"
  def valid_input(s: Rep[Input]) = s.length>=0 && valid(s, 0 until s.length+1)

  // Reader
  type Elem = Char
  type Input = Array[Char] // \0-terminated C string
  implicit class InputOps(s: Rep[Input]) {
    def first: Rep[Elem] = s(0)
    def atEnd: Rep[Boolean] = s(0) == unit(0.toChar)
    def rest: Rep[Input] = /*s+1*/uncheckedPure[Input](s, "+1")
    def foreach(f: Rep[Char] => Rep[Unit]) = {
      var t = s
      while (readVar(t).atEnd) {
        f(readVar(t).first)
        t = readVar(t).rest
      }
    }
  }
  implicit def var2input(s: Var[Input]): InputOps = readVar(s)

  // Parser Result
  abstract class ParseResultCPS[T: Typ] { self =>

    def apply[X: Typ](
      success: (Rep[T], Rep[Input]) => Rep[X],
      failure: Rep[Input] => Rep[X]
    ): Rep[X]

    def map[U: Typ](f: Rep[T] => Rep[U]) = new ParseResultCPS[U] {
      def apply[X: Typ](
        success: (Rep[U], Rep[Input]) => Rep[X],
        failure: Rep[Input] => Rep[X]
      ): Rep[X] = self.apply(
        (t: Rep[T], in: Rep[Input]) => success(f(t), in),
        failure
      )
    }

    def flatMapWithNext[U: Typ](f: (Rep[T], Rep[Input]) => ParseResultCPS[U])
        = new ParseResultCPS[U] {

      def apply[X: Typ](
        success: (Rep[U], Rep[Input]) => Rep[X],
        failure: Rep[Input] => Rep[X]
      ): Rep[X] = self.apply(
        (t: Rep[T], in: Rep[Input]) => f(t, in).apply(success, failure),
        failure
      )
    }

    def orElse(that: => ParseResultCPS[T]) = new ParseResultCPS[T] {
      def apply[X: Typ](
        success: (Rep[T], Rep[Input]) => Rep[X],
        failure: Rep[Input] => Rep[X]
      ): Rep[X] = {
        var isEmpty = unit(true); var value = zeroVal[T]; var rdr = zeroVal[Input]

        self.apply[Unit](
          (x, next) => { isEmpty = unit(false); value = x; rdr = next },
          next => ()
        )

        if (isEmpty) that.apply(success, failure) else success(value, rdr)
      }
    }

/*

This definition of orElse causes code duplication of `that` for each
nested flatmap in `self.

    def orElse(that: => ParseResultCPS[T]) = new ParseResultCPS[T] {
      def apply[X: Typ](
        success: (Rep[T], Rep[Input]) => Rep[X],
        failure: Rep[Input] => Rep[X]
      ): Rep[X] = self.apply(
        (t: Rep[T], in: Rep[Input]) => success(t, in),
        (nxt: Rep[Input]) => that.apply(
          success,
          failure
        )
      )
    }
 */

    def toResult(default: Rep[T]): Rep[T] = {
      var value = default
      self.apply(
        (t, _) => value = t,
        _ => unit(())
      )
      value
    }
  }

  case class ParseResultCPSCond[T: Typ](
    cond: Rep[Boolean],
    t: ParseResultCPS[T],
    e: ParseResultCPS[T]
  ) extends ParseResultCPS[T] { self =>

    def apply[X: Typ](
      success: (Rep[T], Rep[Input]) => Rep[X],
      failure: Rep[Input] => Rep[X]
    ): Rep[X] = if (cond) t(success, failure) else e(success, failure)


    override def map[U: Typ](f: Rep[T] => Rep[U]) = new ParseResultCPS[U] {
      def apply[X: Typ](
        success: (Rep[U], Rep[Input]) => Rep[X],
        failure: Rep[Input] => Rep[X]
      ): Rep[X] = {
        var isEmpty = unit(true); var value = zeroVal[T]; var rdr = zeroVal[Input]

        self.apply[Unit](
          (x, next) => { isEmpty = unit(false); value = x; rdr = next },
          next => rdr = next
        )

        if (isEmpty) failure(rdr) else success(f(value), rdr)
      }
    }

    override def flatMapWithNext[U: Typ](f: (Rep[T], Rep[Input]) => ParseResultCPS[U])
        = new ParseResultCPS[U] {

      def apply[X: Typ](
        success: (Rep[U], Rep[Input]) => Rep[X],
        failure: Rep[Input] => Rep[X]
      ): Rep[X] = {

        var isEmpty = unit(true); var value = zeroVal[T]; var rdr = zeroVal[Input]

        self.apply[Unit](
          (x, next) => { isEmpty = unit(false); value = x; rdr = next },
          next => rdr = next
        )

        if (isEmpty) failure(rdr) else f(value, rdr).apply(success, failure)
      }
    }

    override def orElse(that: => ParseResultCPS[T]): ParseResultCPS[T] = {
      var isEmpty = unit(true); var value = zeroVal[T]; var rdr = zeroVal[Input]

      self.apply[Unit](
        (x, next) => { isEmpty = unit(false); value = x; rdr = next },
        next => ()
      )

      conditional(isEmpty, that, ParseResultCPS.Success(value, rdr))
    }
  }

  object ParseResultCPS {
    def Success[T: Typ](t: Rep[T], next: Rep[Input]) = new ParseResultCPS[T] {
      def apply[X: Typ](
        success: (Rep[T], Rep[Input]) => Rep[X],
        failure: (Rep[Input]) => Rep[X]
      ): Rep[X] = success(t, next)
    }

    def Failure[T: Typ](next: Rep[Input]) = new ParseResultCPS[T] {
      def apply[X: Typ](
        success: (Rep[T], Rep[Input]) => Rep[X],
        failure: (Rep[Input]) => Rep[X]
      ): Rep[X] = failure(next)
    }
  }

  def conditional[T: Typ](
    cond: Rep[Boolean],
    thenp: => ParseResultCPS[T],
    elsep: => ParseResultCPS[T]
  ): ParseResultCPS[T] = ParseResultCPSCond(cond, thenp, elsep)

  // Parser
  abstract class Parser[T: Typ]
      extends (Rep[Input] => ParseResultCPS[T]) {

    private def flatMap[U: Typ](f: Rep[T] => Parser[U]) = Parser[U] { input =>
      this(input) flatMapWithNext { (res, rdr) => f(res)(rdr) }
    }

    def >>[U: Typ](f: Rep[T] => Parser[U]) = flatMap(f)

    def ~[U: Typ](that: => Parser[U]): Parser[(T, U)] =
      for (l <- this; r <- that) yield make_tuple2(l, r)

    def ~>[U: Typ](that: => Parser[U]): Parser[U] =
      this flatMap { l => that }

    def <~[U: Typ](that: => Parser[U]): Parser[T] =
      for (l <- this; r <- that) yield l

    def map[U: Typ](f: Rep[T] => Rep[U]) = Parser[U] { input =>
      this(input) map f
    }

    def ^^[U: Typ](f: Rep[T] => Rep[U]) = map(f)

    def ^^^[U: Typ](u: Rep[U]) = map(x => u)

    def | (that: => Parser[T]) = Parser[T] { input =>
      this(input) orElse that(input)
    }
  }

  def __ifThenElse[A: Typ](
    cond: Rep[Boolean],
    thenp: => Parser[A],
    elsep: => Parser[A]
  ): Parser[A] = Parser[A] { input => conditional(cond, thenp(input), elsep(input)) }

  object Parser {
    def apply[T: Typ](f: Rep[Input] => ParseResultCPS[T]) = new Parser[T] {
      def apply(in: Rep[Input]) = f(in)
    }

    def phrase[T: Typ](p: => Parser[T], in: Rep[Input], default: Rep[T]): Rep[T] =
      p(in).toResult(default)
  }

  // CharParsers
  def acceptIf(p: Rep[Elem] => Rep[Boolean]) = Parser[Elem] { in =>
    conditional(
      in.atEnd,
      ParseResultCPS.Failure[Elem](in),
      conditional(
        p(in.first),
        ParseResultCPS.Success(in.first, in.rest),
        ParseResultCPS.Failure[Elem](in)
      )
    )
  }

  def accept(e: Rep[Elem]): Parser[Elem] = acceptIf(_ == e)

  def isLetter(c: Rep[Char]): Rep[Boolean] =
    (c >= unit('a') && c <= unit('z')) ||
    (c >= unit('A') && c <= unit('Z'))

  def letter: Parser[Char] = acceptIf(isLetter)

  def isDigit(c: Rep[Char]): Rep[Boolean] =
    c >= unit('0') && c <= unit('9')

  def digit: Parser[Char] = acceptIf(isDigit)
  def digit2Int: Parser[Int] = digit map (c => (c - unit('0')).asInstanceOf[Rep[Int]])

  def rep[T: Typ, R: Typ](p: Parser[T], z: Rep[R], f: (Rep[R], Rep[T]) => Rep[R], pz: Option[Rep[R] => Rep[Boolean]] = None) = Parser[R] { input =>
    var in = input
    var c = unit(true); var a = z
    loop (valid_input(in) && (pz.map(_(a)).getOrElse(true)), List[Any](in, c, a), 0) {
    while (c) {
      p(in).apply[Unit](
        (x, next) => { a = f(a, x); in = next },
        next => { c = false })
    }}
    ParseResultCPS.Success(a, in)
  }
}

// toy HTTP parser inspired by http://dl.acm.org/authorize?N80783
// also see https://github.com/manojo/experiments/blob/simple/src/main/scala/lms/parsing/examples/HttpParser.scala
//
// to avoid dealing with data structures, just returns
//   the content length of the payload if parse successful
//   -1 otherwise
trait HttpParser extends StagedParser {  import Parser._
  def accept(cs: List[Char]): Parser[Unit] = cs match {
    case Nil => Parser { i => ParseResultCPS.Success((), i) }
    case x :: xs => accept(x) ~> accept(xs)
  }
  def accept(s: String): Parser[Unit] = accept(s.toList)

/*

Alternative definition of `accept`. Generates less code, but arguably
more low-level.

    def accept(s: String) = Parser[Unit] { input =>
      var in = input
      var ok = unit(true)
      for (i <- (0 until s.length):Range) {
        if (ok) {
          if (in.atEnd) ok = false
          else if (in.first != s(i)) ok = false
          else in = in.rest
        }
      }
      conditional(
        ok,
        ParseResultCPS.Success((), in),
        ParseResultCPS.Failure(input))
    }
 */

  def repUnit[T: Typ](p: Parser[T]) =
    rep(p, (), { (a: Rep[Unit], x: Rep[T]) => a })

  def repN[T: Typ](p: Parser[T], n: Rep[Int]) = Parser[Unit] { input =>
    var ok = unit(true)
    var in = input
    loop(
      { i: Rep[Int] => 0<=i && valid_input(in) },
      { i: Rep[Int] => List(i, ok, in) },
      { i: Rep[Int] => n-i }) {
    for (i <- 0 until n)
      if (ok)
        p(in).apply[Unit](
          (_, next) => { in = next },
          next => { ok = false })
    }
    conditional(ok, ParseResultCPS.Success((), in), ParseResultCPS.Failure(input))
  }

  val OVERFLOW = -1
  def num(c: Parser[Int], b: Int): Parser[Int] =
    c >> { z: Rep[Int] =>
      rep(c, z, { (a: Rep[Int], x: Rep[Int]) =>
        if (a<0) a
        else if (a>Int.MaxValue / b - b) OVERFLOW
        else a*b+x
      }, Some({ a: Rep[Int] => (a == OVERFLOW) || (0 <= a) }))
    }

  def nat: Parser[Int] = num(digit2Int, 10)
  def acceptNat: Parser[Unit] =
    digit >> { z: Rep[Char] => repUnit(digit) }

  def anyChar: Parser[Char] = acceptIf(c => true)
  def wildChar: Parser[Char] = acceptIf(c => c != '\n')
  def acceptNewline: Parser[Unit] = accept("\n")
  def acceptLine: Parser[Unit] = repUnit(wildChar) ~> acceptNewline
  def whitespaces: Parser[Unit] = repUnit(accept(' '))

  def status: Parser[Int] =
    (accept("HTTP/") ~> acceptNat ~> accept('.') ~> acceptNat  ~> whitespaces) ~>
    nat <~ acceptLine

  val CONTENT_LENGTH = 1
  def headerMap: List[(String, Int)] = ("Content-Length", CONTENT_LENGTH)::Nil
  val OTHER_HEADER = 0
  def headerName: Parser[Int] =
    ((for ((h,i) <- headerMap) yield (accept(h) ^^^ i)).reduce(_ | _)) |
    (repUnit(letter | accept('-')) ^^^ OTHER_HEADER)

  val NO_VALUE = -2
  def headerValue(h: Rep[Int]) =
    if (h==CONTENT_LENGTH) (nat <~ whitespaces <~ acceptNewline)
    else (acceptLine ^^^ NO_VALUE)

  def header: Parser[Int] =
    (headerName <~ whitespaces <~ accept(':') <~ whitespaces) >> headerValue

  def headers: Parser[Int] =
    rep(header, 0, { (a: Rep[Int], x: Rep[Int]) => if (x==NO_VALUE) a else x })

  def acceptBody(n: Rep[Int]): Parser[Int] =
    if (n<0) Parser[Int] { input => ParseResultCPS.Failure(input) }
    else repN(anyChar, n) ^^^ n

  def http: Parser[Int] =
    ((status ~> headers <~ acceptNewline) >> acceptBody) <~ acceptNewline

  def top = toplevel("p",
    { in: Rep[Input] =>
      var r = unit(-1)
      http(in).apply(
        (v, next) => if (next.atEnd) r = v,
        _ => unit(()))
      r
    },
    { in: Rep[Input] => valid_input(in) },
    { in: Rep[Input] => result: Rep[Int] => unit(true) })
}

trait ChunkedHttpParser extends HttpParser { import Parser._
  val TRANSFER_ENCODING = 2
  override def headerMap = super.headerMap :+ ("Transfer-Encoding", TRANSFER_ENCODING)

  val CHUNKED = -3
  override def headerValue(h: Rep[Int]) =
    if (h==TRANSFER_ENCODING) (accept("chunked") ^^^ CHUNKED) <~ whitespaces <~ acceptNewline
    else super.headerValue(h)

  override def acceptBody(n: Rep[Int]): Parser[Int] =
    if (n==CHUNKED) chunkedBody else super.acceptBody(n)

  def acceptChunk: Parser[Int] =
    nat >> super.acceptBody // TODO: change nat to hex

  def chunkedBody: Parser[Int] =
    rep(acceptChunk, 0, { (a: Rep[Int], x: Rep[Int]) => a+x })
}

class ParserTests extends TestSuite {
  val under = "parse"

  test("0") {
    trait P0 extends StagedParser { import Parser._
      val p = toplevel("p",
        { in: Rep[Input] => phrase(digit2Int, in, -1) },
        { in: Rep[Input] => valid_input(in) },
        { in: Rep[Input] => result: Rep[Int] =>
          result == -1 || (0 <= result && result <= 9)
        })
    }
    check("0", (new P0 with Impl).code)
  }

  // overflow failures
  test("1") {
    trait P1 extends StagedParser { import Parser._
      val p = toplevel("p",
        { in: Rep[Input] =>
          phrase(rep(digit2Int, 0, { (a: Rep[Int], x: Rep[Int]) => a*10+x }), in, -1)
        },
        { in: Rep[Input] => valid_input(in) },
        { in: Rep[Input] => result: Rep[Int] => unit(true) })
    }
    check("1", (new P1 with Impl).code)
  }

  // overflow verifies
  test("2") {
    trait P2 extends StagedParser { import Parser._
      val p = toplevel("p",
        { in: Rep[Input] =>
          val m = Int.MaxValue / 10 - 10
          phrase(
            rep(digit2Int, 0,
              { (a: Rep[Int], x: Rep[Int]) =>
                if (a<0) a
                else if (a>m) -1
                else a*10+x
              },
              Some({ a: Rep[Int] => (a == -1) || (0 <= a) })),
            in, -1)
        },
        { in: Rep[Input] => valid_input(in) },
        { in: Rep[Input] => result: Rep[Int] =>
          (result == -1) || (0 <= result)
        })
    }
    check("2", (new P2 with Impl).code)
  }

  test("3") {
    trait P3 extends HttpParser {
      val p = top
    }
    check("3", (new P3 with Impl).code)
  }
}
