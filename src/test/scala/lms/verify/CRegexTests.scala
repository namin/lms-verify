package lms.verify

// see lms-verify/src/out/re.c for original interpreter
trait CRegexpMatcher extends SimulatedReader {
  def matchsearch(r: Input, s: Input): Boolean = {
    if (r.first == '^')
      matchhere(r.rest, s)
    else {
      var found = false
      var continue = true
      var cur_s = s
      while (!found && continue) {
        found = matchhere(r, cur_s)
        if (!found) {
          continue = !cur_s.atEnd
          if (continue) cur_s = cur_s.rest
        }
      }
      found
    }
  }
  def matchhere(r: Input, s: Input): Boolean = {
    if (r.atEnd)
      true
    else if (r.second == '*')
      matchstar(r.first, r.rest.rest, s)
    else if (r.first == '$' && r.rest.atEnd)
      s.atEnd
    else if (!s.atEnd && (r.first == '.' || r.first == s.first))
      matchhere(r.rest, s.rest)
    else
      false
  }
  def matchstar(c: Char, r: Input, s: Input): Boolean = {
    var found = false
    var continue = true
    var cur_s = s
    while (!found && continue) {
      found = matchhere(r, cur_s)
      if (!found) {
        continue = !cur_s.atEnd
        if (continue) {
          continue = cur_s.first == c  || c == '.'
          cur_s = cur_s.rest
        }
      }
    }
    found
  }
}

class CRegexpMatcherTest extends TestSuite with CRegexpMatcher {
  val under = "cre_"

  def testmatch(regexp: String, text: String, expected: Boolean) {
    test(s"""matchsearch("$regexp", "$text") == $expected""") {
      assertResult(expected){matchsearch(fromString(regexp), fromString(text))}
    }
  }

  testmatch("^hello$", "hello", true)
  testmatch("^hello$", "hell", false)
  testmatch("hell", "hello", true);
  testmatch("hell", "hell", true);
  testmatch("hel*", "he", true);
  testmatch("hel*$", "hello", false);
  testmatch("hel*", "yo hello", true);
  testmatch("ab", "hello ab hello", true);
  testmatch("^ab", "hello ab hello", false);
  testmatch("a*b", "hello aab hello", true);
  testmatch("^ab*", "abcd", true);
  testmatch("^ab*", "a", true);
  testmatch("^ab*", "ac", true);
  testmatch("^ab*", "bac", false);
  testmatch("^ab*$", "ac", false);
}

trait StagedCRegexpMatcher extends Dsl with Reader with SimulatedReader {
  def matchsearch(r: Input, s: Rep[Input]): Rep[Boolean] = {
    if (r.first == '^')
      matchhere(r.rest, s)
    else {
      var found = unit(false)
      var continue = unit(true)
      var cur_s = s
      loop (valid_input(cur_s), List[Any](found, continue, cur_s), cur_s.length+(if (!found) 1 else 0)+(if (continue) 1 else 0)) {
      while (!found && continue) {
        found = matchhere(r, cur_s)
        if (!found) {
          continue = !cur_s.atEnd
          if (continue) cur_s = cur_s.rest
        }
      }}
      found
    }
  }
  def matchhere(r: Input, s: Rep[Input]): Rep[Boolean] = {
    if (r.atEnd)
      true
    else if (r.second == '*')
      matchstar(r.first, r.rest.rest, s)
    else if (r.first == '$' && r.rest.atEnd)
      s.atEnd
    else if (!s.atEnd && (r.first == '.' || r.first == s.first))
      matchhere(r.rest, s.rest)
    else
      false
  }
  def matchstar(c: Char, r: Input, s: Rep[Input]): Rep[Boolean] = {
    var found = unit(false)
    var continue = unit(true)
    var cur_s = s
    loop (valid_input(cur_s), List[Any](found, continue, cur_s), cur_s.length+(if (!found) 1 else 0)+(if (continue) 1 else 0)) {
    while (!found && continue) {
      found = matchhere(r, cur_s)
      if (!found) {
        continue = !cur_s.atEnd
        if (continue) {
          continue = cur_s.first == c  || c == '.'
          cur_s = cur_s.rest
        }
      }
    }}
    found
  }
}

class CRegexTests extends TestSuite {
  val under = "cre_"

  def gen(msg: String, re: String) {
    test(msg) {
      trait RegexProg extends StagedCRegexpMatcher {
        override def autoAssignNothing = false

        toplevel("matcher_"+msg,
          { (s: Rep[Input]) => matchsearch(fromString(re), s) },
          { (s: Rep[Input]) => valid_input(s) },
          { (s: Rep[Input]) => (r: Rep[Boolean]) => true })
      }
      check(msg, (new RegexProg with Impl).code)
    }
  }

  gen("begin_a", "^a")
  gen("a_end", "a$")
  gen("a", "a")
  gen("ab_dot_star_ab", "ab.*ab")
}
