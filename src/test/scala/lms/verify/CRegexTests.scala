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

trait StagedCRegexpMatcher extends Dsl with Reader {
  // TODO
}
