#include <limits.h>
/*@
assigns \nothing;
*/
int main(int  x0) {
  #line 44 "BlameTests.scala"
  /*@assert ((x0%2)==1);*/
  #line 37 "BlameTests.scala"
  int x6 = x0 + 1;
  #line 37 "BlameTests.scala"
  /*@assert ((x6%2)==0);*/
  #line 42 "BlameTests.scala"
  int x11 = 2 * x6;
  #line 43 "BlameTests.scala"
  /*@assert ((x11%2)==0);*/
  #line 37 "BlameTests.scala"
  int x16 = x11 - 1;
  #line 37 "BlameTests.scala"
  /*@assert ((x16%2)==1);*/
  #line 581 "Effects.scala"
  return x16;
}
