#include <limits.h>
//@ predicate inv_vec_Int(int  * x0, int  x1) = ((0<=x1) && \valid(x0+(0..x1-1)));
//@ predicate eq(int  * x14, int  x15, int  * x16, int  x17) = ((x15==x17) && (\forall int x21; (0<=x21<x15) ==> (x14[x21]==x16[x21])));
/*@
requires (inv_vec_Int(x14,x15) && inv_vec_Int(x16,x17));
assigns \nothing;
ensures \result <==> eq(x14, x15, x16, x17);
*/
int eq(int  * x14, int  x15, int  * x16, int  x17) {
  int x19 = x15 == x17;
  int x31;
  if (x19) {
    int x30 = 1;
    /*@ loop invariant (0 <= x22 <= x15);
    loop invariant \forall int x21; (0 <= x21 < x22) ==>  (x14[x21]==x16[x21]);
    loop assigns x22;
    loop variant (x15-x22); */
    for (int x22 = 0; x22 < x15; x22++) {
      int x27 = x14[x22];
      int x28 = x16[x22];
      int x29 = x27 == x28;
      if (!x29) { x30 = 0; break; }
    }
    x31 = x30;
  } else {
    x31 = 0/*false*/;
  }
  return x31;
}
