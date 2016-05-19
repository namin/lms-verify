#include <limits.h>
/*@
requires ((((((((0<x0) && (x0<100)) && (0<x1)) && (x1<100)) && (0<=x2)) && (0<=x3)) && (x2<x0)) && (x3<x1));
assigns \nothing;
ensures ((0<=\result) && (\result<(x0*x1)));
*/
int index(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x2 * x1;
  int x6 = x5 + x3;
  return x6;
}
//@ predicate inv_matrix_Boolean(int  * x36, int  x37, int  x38) = (((((x37<100) && (x38<100)) && (0<x37)) && (0<x38)) && (((x37*x38)>0) && \valid(x36+(0..(x37*x38)-1))));
/*@
requires ((((inv_matrix_Boolean(x76,x77,x78) && inv_matrix_Boolean(x79,x80,x81)) && inv_matrix_Boolean(x82,x83,x84)) && ((x83==x77) && (x84==x78))) && ((x83==x80) && (x84==x81)));
*/
void add(int  * x76, int  x77, int  x78, int  * x79, int  x80, int  x81, int  * x82, int  x83, int  x84) {
  int x86 = x83 * x84;
  /*@
  loop invariant 0<=x88<=x86;
  loop assigns x88, x82[(0..x86-1)];
  loop variant x86-x88;
  */
  for(int x88=0; x88 < x86; x88++) {
    int x89 = x76[x88];
    int x90 = x79[x88];
    int x91 = x89 || x90;
    x82[x88] = x91;
  }
}
/*@
requires ((inv_matrix_Boolean(x114,x115,x116) && inv_matrix_Boolean(x117,x118,x119)) && ((x118==x115) && (x119==x116)));
*/
void scalar_mult(int  x113, int  * x114, int  x115, int  x116, int  * x117, int  x118, int  x119) {
  int x121 = x118 * x119;
  /*@
  loop invariant 0<=x123<=x121;
  loop assigns x123, x117[(0..x121-1)];
  loop variant x121-x123;
  */
  for(int x123=0; x123 < x121; x123++) {
    int x125;
    if (x113) {
      int x124 = x114[x123];
      x125 = x124;
    } else {
      x125 = 0/*false*/;
    }
    x117[x123] = x125;
  }
}
