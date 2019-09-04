#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, integer  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@ predicate eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) = ((x17==x19) &&
(\forall int x23; (0<=x23<x17) ==> (x16[x23]==x18[x23])));*/
/*@
requires (inv_vec_Int(x16,x17) &&
inv_vec_Int(x18,x19));
assigns \nothing;
ensures (inv_vec_Int(x16,x17) &&
inv_vec_Int(x18,x19));
ensures \result <==> eq_vec_Int(x16, x17, x18, x19);
*/
int eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) {
  int x21 = x17 == x19;
  int x33;
  if (x21) {
    int x32 = 1;
    /*@ loop invariant (0 <= x24 <= x17);
    loop invariant \forall int x23; (0 <= x23 < x24) ==> (x16[x23]==x18[x23]);
    loop invariant x32==1;
    loop assigns x24, x32;
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
/*@ predicate inv_vec_vec_Int(int  * * x37, int  * x38, integer  x39) = (((x39==0) || ((x39>0) &&
(\valid(x37+(0..x39-1)) &&
\valid(x38+(0..x39-1))))) &&
(\forall int x49; (0<=x49<x39) ==> inv_vec_Int(x37[x49],x38[x49])));*/
/*@ predicate eq_vec_vec_Int(int  * * x61, int  * x62, int  x63, int  * * x64, int  * x65, int  x66) = ((x63==x66) &&
(\forall int x70; (0<=x70<x63) ==> eq_vec_Int(x61[x70],x62[x70],x64[x70],x65[x70])));*/
/*@
requires (inv_vec_vec_Int(x61,x62,x63) &&
inv_vec_vec_Int(x64,x65,x66));
assigns \nothing;
ensures (inv_vec_vec_Int(x61,x62,x63) &&
inv_vec_vec_Int(x64,x65,x66));
ensures \result <==> eq_vec_vec_Int(x61, x62, x63, x64, x65, x66);
*/
int eq_vec_vec_Int(int  * * x61, int  * x62, int  x63, int  * * x64, int  * x65, int  x66) {
  int x68 = x63 == x66;
  int x84;
  if (x68) {
    int x83 = 1;
    /*@ loop invariant (0 <= x71 <= x63);
    loop invariant \forall int x70; (0 <= x70 < x71) ==> eq_vec_Int(x61[x70],x62[x70],x64[x70],x65[x70]);
    loop invariant x83==1;
    loop assigns x71, x83;
    loop variant (x63-x71); */
    for (int x71 = 0; x71 < x63; x71++) {
      int  *x78 = x61[x71];
      int x79 = x62[x71];
      int  *x80 = x64[x71];
      int x81 = x65[x71];
      int x82 = eq_vec_Int(x78,x79,x80,x81);
      if (!x82) { x83 = 0; break; }
    }
    x84 = x83;
  } else {
    x84 = 0/*false*/;
  }
  return x84;
}
