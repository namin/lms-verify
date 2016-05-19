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
requires (((inv_matrix_Boolean(x76,x77,x78) && inv_matrix_Boolean(x79,x80,x81)) && inv_matrix_Boolean(x82,x83,x84)) && ((((x77==x80) && (x77==x83)) && (x78==x81)) && (x78==x84)));
*/
void add(int  * x76, int  x77, int  x78, int  * x79, int  x80, int  x81, int  * x82, int  x83, int  x84) {
  /*@
  loop invariant 0<=x89<=x83;
  loop assigns x89, x82[(0..(x83*x84)-1)];
  loop variant x83-x89;
  */
  for(int x89=0; x89 < x83; x89++) {
    /*@
    loop invariant 0<=x91<=x84;
    loop assigns x91, x82[(0..(x83*x84)-1)];
    loop variant x84-x91;
    */
    for(int x91=0; x91 < x84; x91++) {
      int x92 = index(x77,x78,x89,x91);
      int x93 = x76[x92];
      int x94 = index(x80,x81,x89,x91);
      int x95 = x79[x94];
      int x96 = x93 || x95;
      int x97 = index(x83,x84,x89,x91);
      x82[x97] = x96;
    }
  }
}
/*@
requires ((inv_matrix_Boolean(x123,x124,x125) && inv_matrix_Boolean(x126,x127,x128)) && ((x124==x127) && (x125==x128)));
*/
void scalar_mult(int  x122, int  * x123, int  x124, int  x125, int  * x126, int  x127, int  x128) {
  /*@
  loop invariant 0<=x133<=x127;
  loop assigns x133, x126[(0..(x127*x128)-1)];
  loop variant x127-x133;
  */
  for(int x133=0; x133 < x127; x133++) {
    /*@
    loop invariant 0<=x135<=x128;
    loop assigns x135, x126[(0..(x127*x128)-1)];
    loop variant x128-x135;
    */
    for(int x135=0; x135 < x128; x135++) {
      int x138;
      if (x122) {
        int x136 = index(x124,x125,x133,x135);
        int x137 = x123[x136];
        x138 = x137;
      } else {
        x138 = 0/*false*/;
      }
      int x139 = index(x127,x128,x133,x135);
      x126[x139] = x138;
    }
  }
}
