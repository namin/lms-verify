#include <limits.h>
//@ predicate inv(int  * x0, int  x1) = ((0<=x1) && \valid(x0+(0..x1-1)));
//@ predicate eq(int  * x28, int  x29, int  * x30, int  x31) = ((x29==x31) && (\forall int x35; (0<=x35<x29) ==> (x28[x35]==x30[x35])));
/*@
requires (((0<=x29) && \valid(x28+(0..x29-1))) && ((0<=x31) && \valid(x30+(0..x31-1))));
assigns \nothing;
ensures \result <==> eq(x28, x29, x30, x31);
*/
int eq(int  * x28, int  x29, int  * x30, int  x31) {
  int x33 = x29 == x31;
  int x45;
  if (x33) {
    int x44 = 1;
    /*@ loop invariant (0 <= x36 <= x29);
    loop invariant \forall int x35; (0 <= x35 < x36) ==>  (x28[x35]==x30[x35]);
    loop assigns x36;
    loop variant (x29-x36); */
    for (int x36 = 0; x36 < x29; x36++) {
      int x41 = x28[x36];
      int x42 = x30[x36];
      int x43 = x41 == x42;
      if (!x43) { x44 = 0; break; }
    }
    x45 = x44;
  } else {
    x45 = 0/*false*/;
  }
  return x45;
}
