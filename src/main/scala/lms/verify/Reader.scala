package lms.verify

trait Reader extends Dsl {
  def valid_input(s: Rep[Input]) = s.length>=0 && valid(s, 0 until s.length+1)

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
}
