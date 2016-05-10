#include <limits.h>
//@ predicate eq(int  * x0, int  x1, int  * x2, int  x3) = ((x1==x3) && (\forall int x7; (0<=x7<x1) ==> (x0[x7]==x2[x7])));
/*@
requires (((0<=x1) && \valid(x0+(0..x1-1))) && ((0<=x3) && \valid(x2+(0..x3-1))));
assigns \nothing;
ensures \result <==> eq(x0, x1, x2, x3);
*/
int eq(int  * x0, int  x1, int  * x2, int  x3) {
  int x5 = x1 == x3;
  int x17;
  if (x5) {
    int x16 = 1;
    /*@ loop invariant (0 <= x8 <= x1);
    loop invariant \forall int x7; (0 <= x7 < x8) ==>  (x0[x7]==x2[x7]);
    loop assigns x8;
    loop variant (x1-x8); */
    for (int x8 = 0; x8 < x1; x8++) {
      int x13 = x0[x8];
      int x14 = x2[x8];
      int x15 = x13 == x14;
      if (!x15) { x16 = 0; break; }
    }
    x17 = x16;
  } else {
    x17 = 0/*false*/;
  }
  return x17;
}
