#include <limits.h>
/*@
assigns \nothing;
ensures (\result>x0);
*/
int main(int  x0) {
  #line 37 "BlameTests.scala"
  //@assert (x0<100);
  #line 33 "BlameTests.scala"
  int x4 = x0 + 1;
  #line 32 "BlameTests.scala"
  //@assert ((x0+1)>x0);
  #line 581 "Effects.scala"
  return x4;
}
