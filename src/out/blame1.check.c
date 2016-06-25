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
  #line 38 "BlameTests.scala"
  /*@assert ((x6%2)==0);*/
  #line 37 "BlameTests.scala"
  int x15 = x6 - 1;
  #line 39 "BlameTests.scala"
  /*@assert ((x15%2)==1);*/
  #line 581 "Effects.scala"
  return x15;
}
