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
/*@ predicate inv_vec_vec_Int(int  * * x35, int  * x36, integer  x37) = (((x37==0) || ((x37>0) &&
(\valid(x35+(0..x37-1)) &&
\valid(x36+(0..x37-1))))) &&
(\forall int x47; (0<=x47<x37) ==> inv_vec_Int(x35[x47],x36[x47])));*/
/*@ predicate eq_vec_vec_Int(int  * * x58, int  * x59, int  x60, int  * * x61, int  * x62, int  x63) = ((x60==x63) &&
(\forall int x67; (0<=x67<x60) ==> eq_vec_Int(x58[x67],x59[x67],x61[x67],x62[x67])));*/
/*@
requires (inv_vec_vec_Int(x58,x59,x60) &&
inv_vec_vec_Int(x61,x62,x63));
assigns \nothing;
ensures (inv_vec_vec_Int(x58,x59,x60) &&
inv_vec_vec_Int(x61,x62,x63));
ensures \result <==> eq_vec_vec_Int(x58, x59, x60, x61, x62, x63);
*/
int eq_vec_vec_Int(int  * * x58, int  * x59, int  x60, int  * * x61, int  * x62, int  x63) {
  int x65 = x60 == x63;
  int x80;
  if (x65) {
    int x79 = 1;
    /*@ loop invariant (0 <= x68 <= x60);
    loop invariant \forall int x67; (0 <= x67 < x68) ==> eq_vec_Int(x58[x67],x59[x67],x61[x67],x62[x67]);
    loop invariant x79==1;
    loop assigns x68, x79;
    loop variant (x60-x68); */
    for (int x68 = 0; x68 < x60; x68++) {
      int  *x74 = x58[x68];
      int x75 = x59[x68];
      int  *x76 = x61[x68];
      int x77 = x62[x68];
      int x78 = eq_vec_Int(x74,x75,x76,x77);
      if (!x78) { x79 = 0; break; }
    }
    x80 = x79;
  } else {
    x80 = 0/*false*/;
  }
  return x80;
}
