#include <limits.h>
//@ predicate inv_vec_Int(int  * x0, int  x1) = ((x1==0) || ((x1>0) && \valid(x0+(0..x1-1))));
//@ predicate eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) = ((x17==x19) && (\forall int x23; (0<=x23<x17) ==> (x16[x23]==x18[x23])));
/*@
requires (inv_vec_Int(x16,x17) && inv_vec_Int(x18,x19));
assigns \nothing;
ensures \result <==> eq_vec_Int(x16, x17, x18, x19);
*/
int eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) {
  int x21 = x17 == x19;
  int x33;
  if (x21) {
    int x32 = 1;
    /*@ loop invariant (0 <= x24 <= x17);
    loop invariant \forall int x23; (0 <= x23 < x24) ==>  (x16[x23]==x18[x23]);
    loop assigns x24;
    loop variant (x17-x24); */
    for (int x24 = 0; x24 < x17; x24++) {
      int x29 = x16[x24];
      int x30 = x18[x24];
      int x31 = x29 == x30;
      if (!x31) { x32 = 0; break; }
    }
    x33 = x32;
  } else {
    x33 = 0/*false*/;
  }
  return x33;
}
