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
      ): Rep[X] = self.apply(
        (t: Rep[T], in: Rep[Input]) => success(t, in),
        (nxt: Rep[Input]) => that.apply(
          success,
          failure
        )
      )
    }

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
        next => rdr = next
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

  def rep[T: Typ, R: Typ](p: Parser[T], z: Rep[R], f: (Rep[R], Rep[T]) => Rep[R]) = Parser[R] { input =>
    var in = input
    var c = unit(true); var a = z
    //loop (valid_input(in), List[Any](in, c, a), 1) {
    while (c) {
      p(in).apply[Unit](
        (x, next) => { a = f(a, x); in = next },
        next => { c = false; in = next })
    }//}
    ParseResultCPS.Success(a, in)
  }
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
}
