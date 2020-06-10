package lms.verify

// copied from http://scala-lms.github.io/tutorials/regex.html
// added a `loop` annotation for each loop
// code is otherwise identical
trait StagedRegexpMatcher extends Dsl {

  /* search for regexp anywhere in text */
  def matchsearch(regexp: String, text: Rep[String]): Rep[Boolean] = {
    if (regexp(0) == '^')
      matchhere(regexp, 1, text, 0)
    else {
      var start = -1
      var found = false
      loop (unit(-1) <= start && start <= text.length, List[Any](start, found), text.length-start) {
      while (!found && start < text.length) {
        start += 1
        found = matchhere(regexp, 0, text, start)
      }}
      found
    }
  }

  /* search for restart of regexp at start of text */
  def matchhere(regexp: String, restart: Int, text: Rep[String], start: Rep[Int]): Rep[Boolean] = {
    if (restart==regexp.length)
      true
    else if (regexp(restart)=='$' && restart+1==regexp.length)
      start==text.length
    else if (restart+2 < regexp.length && regexp(restart+1)=='*' && regexp(restart+2)=='?')
      matchstarquery(regexp(restart), regexp, restart+3, text, start)
    else if (restart+1 < regexp.length && regexp(restart+1)=='*')
      matchstar(regexp(restart), regexp, restart+2, text, start)
    else if (start < text.length && matchchar(regexp(restart), text(start)))
      matchhere(regexp, restart+1, text, start+1)
    else false
  }

  /* search for c* followed by restart of regexp at start of text */
  def matchstar(c: Char, regexp: String, restart: Int, text: Rep[String], start: Rep[Int]): Rep[Boolean] = {
    var sstart = start
    var found = matchhere(regexp, restart, text, sstart)
    var failed = false
    loop (start <= sstart && sstart <= text.length, List[Any](sstart, found, failed), text.length-sstart) {
    while (!failed && !found && sstart < text.length) {
      failed = !matchchar(c, text(sstart))
      sstart += 1
      found = matchhere(regexp, restart, text, sstart)
    }}
    !failed && found
  }

  def matchstarquery(c: Char, regexp: String, restart: Int, text: Rep[String], start: Rep[Int]): Rep[Boolean] = {
    var sqstart = start
    var found = matchhere(regexp, restart, text, sqstart)
    var failed = false
    loop (start <= sqstart && sqstart <= text.length, List[Any](sqstart, found, failed), text.length-sqstart){
    if(!failed && !found && sqstart < text.length) {
        failed = !matchchar(c, text(sqstart))
        found = matchhere(regexp, restart, text, sqstart)
    }}
    !failed && found
  }

  def matchchar(c: Char, t: Rep[Char]): Rep[Boolean] = {
    c == '.' || c == t
  }
}

class RegexTests extends TestSuite {
  val under = "re_"

  def gen(msg: String, re: String) {
    test(msg) {
      trait RegexProg extends StagedRegexpMatcher {
        override def includes = super.includes:+"<string.h>"
        override def autoAssignNothing = false
        def valid_string(s: Rep[String]) = s.length>=0 && valid(s, 0 until s.length+1)

        toplevel("matcher",
          { (s: Rep[String]) => matchsearch(re, s) },
          { (s: Rep[String]) => valid_string(s) },
          { (s: Rep[String]) => (r: Rep[Boolean]) => true })
      }
      check(msg, (new RegexProg with Impl).code)
    }
  }

  gen("begin_a", "^a")
  gen("a_end", "a$")
  gen("a", "a")
  gen("ab_dot_star_ab", "ab.*ab")
  gen("ab_dot_star_query_ab","ab.*?ab")


// exponential code size!!!
/* cloc -by-file re_alpha_*.actual.c
--------------------------------------------------------------------------------
File                              blank        comment           code
--------------------------------------------------------------------------------
re_alpha_j.check.c                    0           5123          57312
re_alpha_i.check.c                    0           2563          28640
re_alpha_h.check.c                    0           1283          14304
re_alpha_g.check.c                    0            643           7136
re_alpha_f.check.c                    0            323           3552
re_alpha_e.check.c                    0            163           1760
re_alpha_d.check.c                    0             83            864
re_alpha_c.check.c                    0             43            416
re_alpha_b.check.c                    0             23            192
re_alpha_a.check.c                    0             13             80
--------------------------------------------------------------------------------
SUM:                                  0          10260         114256
--------------------------------------------------------------------------------
*/
  var r = ""
  for (i <- 0 until 10) {
    val c = ('a'+i).toChar
    r = r+c+c+"*"+"?"
    //gen("alpha_"+c, r)
  }
}
