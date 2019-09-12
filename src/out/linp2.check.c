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
((((x64==x67) &&
(x64==x70)) &&
(x65==x68)) &&
(x65==x71)));
ensures ((inv_matrix_Boolean(x63,x64,x65) &&
inv_matrix_Boolean(x66,x67,x68)) &&
inv_matrix_Boolean(x69,x70,x71));
*/
void add(int  * x63, int  x64, int  x65, int  * x66, int  x67, int  x68, int  * x69, int  x70, int  x71) {
  /*@
  loop invariant 0<=x76<=x70;
  loop assigns x76, x69[(0..(x70*x71)-1)];
  loop variant x70-x76;
  */
  for(int x76=0; x76 < x70; x76++) {
    /*@
    loop invariant 0<=x78<=x71;
    loop assigns x78, x69[(0..(x70*x71)-1)];
    loop variant x71-x78;
    */
    for(int x78=0; x78 < x71; x78++) {
      int x79 = index(x64,x65,x76,x78);
      int x80 = x63[x79];
      int x81 = index(x67,x68,x76,x78);
      int x82 = x66[x81];
      int x83 = x80 || x82;
      int x84 = index(x70,x71,x76,x78);
      x69[x84] = x83;
    }
  }
}
/*@
requires ((inv_matrix_Boolean(x111,x112,x113) &&
inv_matrix_Boolean(x114,x115,x116)) &&
((x112==x115) &&
(x113==x116)));
ensures (inv_matrix_Boolean(x111,x112,x113) &&
inv_matrix_Boolean(x114,x115,x116));
*/
void scalar_mult(int  x110, int  * x111, int  x112, int  x113, int  * x114, int  x115, int  x116) {
  /*@
  loop invariant 0<=x121<=x115;
  loop assigns x121, x114[(0..(x115*x116)-1)];
  loop variant x115-x121;
  */
  for(int x121=0; x121 < x115; x121++) {
    /*@
    loop invariant 0<=x123<=x116;
    loop assigns x123, x114[(0..(x115*x116)-1)];
    loop variant x116-x123;
    */
    for(int x123=0; x123 < x116; x123++) {
      int x126;
      if (x110) {
        int x124 = index(x112,x113,x121,x123);
        int x125 = x111[x124];
        x126 = x125;
      } else {
        x126 = 0/*false*/;
      }
      int x127 = index(x115,x116,x121,x123);
      x114[x127] = x126;
    }
  }
}
