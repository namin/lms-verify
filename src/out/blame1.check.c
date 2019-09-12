#include <limits.h>
/*@
assigns \nothing;
*/
int main(int  x0) {
  #line 44 "BlameTests.scala"
  /*@assert ((x0%2)==1);*/
  #line 37 "BlameTests.scala"
  int x5 = x0 + 1;
  #line 37 "BlameTests.scala"
  /*@assert ((x5%2)==0);*/
  #line 42 "BlameTests.scala"
  int x9 = 2 * x5;
  #line 43 "BlameTests.scala"
  /*@assert ((x9%2)==0);*/
  #line 37 "BlameTests.scala"
  int x13 = x9 - 1;
  #line 37 "BlameTests.scala"
  /*@assert ((x13%2)==1);*/
  #line 581 "Effects.scala"
  return x13;
}
