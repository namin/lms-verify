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
//@ predicate inv_vec_vec_Int(int  * * x39, int  * x40, int  x41) = (((0<=x41) && ((x41==0) || ((x41>0) && (\valid(x39+(0..x41-1)) && \valid(x40+(0..x41-1)))))) && (\forall int x53; (0<=x53<x41) ==> inv_vec_Int(x39[x53],x40[x53])));
//@ predicate eq_vec_vec_Int(int  * * x65, int  * x66, int  x67, int  * * x68, int  * x69, int  x70) = ((x67==x70) && (\forall int x74; (0<=x74<x67) ==> eq_vec_Int(x65[x74],x66[x74],x68[x74],x69[x74])));
/*@
requires (inv_vec_vec_Int(x65,x66,x67) && inv_vec_vec_Int(x68,x69,x70));
assigns \nothing;
ensures \result <==> eq_vec_vec_Int(x65, x66, x67, x68, x69, x70);
*/
int eq_vec_vec_Int(int  * * x65, int  * x66, int  x67, int  * * x68, int  * x69, int  x70) {
  int x72 = x67 == x70;
  int x88;
  if (x72) {
    int x87 = 1;
    /*@ loop invariant (0 <= x75 <= x67);
    loop invariant \forall int x74; (0 <= x74 < x75) ==>  eq_vec_Int(x65[x74],x66[x74],x68[x74],x69[x74]);
    loop assigns x75;
    loop variant (x67-x75); */
    for (int x75 = 0; x75 < x67; x75++) {
      int  *x82 = x65[x75];
      int x83 = x66[x75];
      int  *x84 = x68[x75];
      int x85 = x69[x75];
      int x86 = eq_vec_Int(x82,x83,x84,x85);
      if (!x86) { x87 = 0; break; }
    }
    x88 = x87;
  } else {
    x88 = 0/*false*/;
  }
  return x88;
}
