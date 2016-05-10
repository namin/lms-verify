#include <limits.h>
//@ predicate inv_vec_Int(int  * x0, int  x1) = ((0<=x1) && ((x1==0) || ((x1>0) && \valid(x0+(0..x1-1)))));
//@ predicate eq_vec_Int(int  * x18, int  x19, int  * x20, int  x21) = ((x19==x21) && (\forall int x25; (0<=x25<x19) ==> (x18[x25]==x20[x25])));
/*@
requires (inv_vec_Int(x18,x19) && inv_vec_Int(x20,x21));
assigns \nothing;
ensures \result <==> eq_vec_Int(x18, x19, x20, x21);
*/
int eq_vec_Int(int  * x18, int  x19, int  * x20, int  x21) {
  int x23 = x19 == x21;
  int x35;
  if (x23) {
    int x34 = 1;
    /*@ loop invariant (0 <= x26 <= x19);
    loop invariant \forall int x25; (0 <= x25 < x26) ==>  (x18[x25]==x20[x25]);
    loop assigns x26;
    loop variant (x19-x26); */
    for (int x26 = 0; x26 < x19; x26++) {
      int x31 = x18[x26];
      int x32 = x20[x26];
      int x33 = x31 == x32;
      if (!x33) { x34 = 0; break; }
    }
    x35 = x34;
  } else {
    x35 = 0/*false*/;
  }
  return x35;
}
