#include <limits.h>
/*@
assigns \nothing;
*/
int main(int  x0) {
  #line 44 "BlameTests.scala"
  //@assert ((x0%2)==1);
  #line 37 "BlameTests.scala"
  //@assert (((x0+1)%2)==0);
  #line 38 "BlameTests.scala"
  //@assert (((x0+1)%2)==0);
  #line 37 "BlameTests.scala"
  int x5 = x0 + 1;
  #line 37 "BlameTests.scala"
  int x10 = x5 - 1;
  #line 39 "BlameTests.scala"
  //@assert ((((x0+1)-1)%2)==1);
  #line 581 "Effects.scala"
  return x10;
}
