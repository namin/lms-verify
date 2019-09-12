#include <limits.h>
/*@
requires ((x1>0) &&
\valid(x0+(0..x1-1)));
assigns \nothing;
ensures (((\result==-1) ==> (!(\exists int  x56; (((0<=x56) &&
(x56<x1)) &&
(x0[x56]==x2))))) &&
((\result!=-1) ==> (((0<=\result) &&
(\result<x1)) &&
(x0[\result]==x2))));
*/
int member(int  * x0, int  x1, int  x2) {
  int x4 = -1;
  /*@
  loop invariant ((((0<=x6) &&
  (x6<=x1)) &&
  ((x4==-1) ==> (!(\exists int  x22; (((0<=x22) &&
  (x22<x6)) &&
  (x0[x22]==x2)))))) &&
  ((x4!=-1) ==> (((0<=x4) &&
  (x4<x6)) &&
  (x0[x4]==x2))));
  loop assigns x6, x4;
  loop variant (x1-x6);
  */
  for(int x6=0; x6 < x1; x6++) {
    int x7 = x4;
    int x8 = x7 == -1;
    int x11;
    if (x8) {
      int x9 = x0[x6];
      int x10 = x9 == x2;
      x11 = x10;
    } else {
      x11 = 0/*false*/;
    }
    if (x11) {
      x4 = x6;
    } else {
    }
  }
  int x50 = x4;
  return x50;
}
