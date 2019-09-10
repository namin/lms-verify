package lms.verify

trait ReaderI {
  type Elem = Char
  type Input = Array[Char] // \0-terminated C string
}

trait SimulatedReader extends ReaderI {
  def fromString(s: String): Input =
    (s.toList ++ List(0.toChar)).toArray
  implicit class SimulatedInputOps(s: Input) {
    def first: Elem = s(0)
    def second: Elem = s(1)
    def atEnd: Boolean = s(0) == 0.toChar
    def rest: Input = s.slice(1, s.length)
  }
}

trait Reader extends ReaderI with Dsl {
  override def includes = super.includes:+"<string.h>"

  def valid_input(s: Rep[Input]) = s.length>=0 && valid(s, 0 until s.length+1)

  implicit class InputOps(s: Rep[Input]) {
    def first: Rep[Elem] = s(0)
    def second: Rep[Elem] = s(1)
    def atEnd: Rep[Boolean] = s(0) == unit(0.toChar)
    def rest: Rep[Input] = pointer_plus(s, 1)
    def to(i: Rep[Int]) = pointer_plus(s, i)
    def foreach(f: Rep[Char] => Rep[Unit]) = {
      var t = s
      while (readVar(t).atEnd) {
        f(readVar(t).first)
        t = readVar(t).rest
      }
    }
  }
  implicit def var2input(s: Var[Input]): InputOps = readVar(s)
}
