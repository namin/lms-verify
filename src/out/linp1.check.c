#include <limits.h>
/*@
requires ((((((((0<x0) &&
(x0<100)) &&
(0<x1)) &&
(x1<100)) &&
(0<=x2)) &&
(0<=x3)) &&
(x2<x0)) &&
(x3<x1));
assigns \nothing;
ensures ((0<=\result) &&
(\result<(x0*x1)));
*/
int index(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x2 * x1;
  int x6 = x5 + x3;
  return x6;
}
/*@ predicate inv_matrix_Boolean(int  * x26, integer  x27, integer  x28) = (((((x27<100) &&
(x28<100)) &&
(0<x27)) &&
(0<x28)) &&
(((x27*x28)>0) &&
\valid(x26+(0..(x27*x28)-1))));*/
/*@
requires (((inv_matrix_Boolean(x63,x64,x65) &&
inv_matrix_Boolean(x66,x67,x68)) &&
inv_matrix_Boolean(x69,x70,x71)) &&
(((x65==x67) &&
(x64==x70)) &&
(x68==x71)));
ensures ((inv_matrix_Boolean(x63,x64,x65) &&
inv_matrix_Boolean(x66,x67,x68)) &&
inv_matrix_Boolean(x69,x70,x71));
*/
void mult(int  * x63, int  x64, int  x65, int  * x66, int  x67, int  x68, int  * x69, int  x70, int  x71) {
  /*@
  loop invariant 0<=x76<=x64;
  loop assigns x76, x69[(0..(x70*x71)-1)];
  loop variant x64-x76;
  */
  for(int x76=0; x76 < x64; x76++) {
    /*@
    loop invariant 0<=x78<=x68;
    loop assigns x78, x69[(0..(x70*x71)-1)];
    loop variant x68-x78;
    */
    for(int x78=0; x78 < x68; x78++) {
      int x79 = index(x70,x71,x76,x78);
      x69[x79] = 0/*false*/;
      /*@
      loop invariant 0<=x82<=x65;
      loop assigns x82, x69[(0..(x70*x71)-1)];
      loop variant x65-x82;
      */
      for(int x82=0; x82 < x65; x82++) {
        int x83 = x69[x79];
        int x84 = index(x64,x65,x76,x82);
        int x85 = x63[x84];
        int x88;
        if (x85) {
          int x86 = index(x67,x68,x82,x78);
          int x87 = x66[x86];
          x88 = x87;
        } else {
          x88 = 0/*false*/;
        }
        int x89 = x83 || x88;
        x69[x79] = x89;
      }
    }
  }
}
