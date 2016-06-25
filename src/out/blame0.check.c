#include <limits.h>
/*@
assigns \nothing;
ensures (\result>x0);
*/
int main(int  x0) {
  #line 21 "BlameTests.scala"
  /*@assert (x0<100);*/
  #line 17 "BlameTests.scala"
  int x5 = x0 + 1;
  #line 16 "BlameTests.scala"
  /*@assert (x5>x0);*/
  #line 581 "Effects.scala"
  return x5;
}
