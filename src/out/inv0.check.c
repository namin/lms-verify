#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, integer  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@ predicate eq_vec_Int(int  * x15, int  x16, int  * x17, int  x18) = ((x16==x18) &&
(\forall int x22; (0<=x22<x16) ==> (x15[x22]==x17[x22])));*/
/*@
requires (inv_vec_Int(x15,x16) &&
inv_vec_Int(x17,x18));
assigns \nothing;
ensures (inv_vec_Int(x15,x16) &&
inv_vec_Int(x17,x18));
ensures \result <==> eq_vec_Int(x15, x16, x17, x18);
*/
int eq_vec_Int(int  * x15, int  x16, int  * x17, int  x18) {
  int x20 = x16 == x18;
  int x31;
  if (x20) {
    int x30 = 1;
    /*@ loop invariant (0 <= x23 <= x16);
    loop invariant \forall int x22; (0 <= x22 < x23) ==> (x15[x22]==x17[x22]);
    loop invariant x30==1;
    loop assigns x23, x30;
    loop variant (x16-x23); */
    for (int x23 = 0; x23 < x16; x23++) {
      int x27 = x15[x23];
      int x28 = x17[x23];
      int x29 = x27 == x28;
      if (!x29) { x30 = 0; break; }
    }
    x31 = x30;
  } else {
    x31 = 0/*false*/;
  }
  return x31;
}
