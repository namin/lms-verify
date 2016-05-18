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
requires (((inv_matrix_Boolean(x76,x77,x78) && inv_matrix_Boolean(x79,x80,x81)) && inv_matrix_Boolean(x82,x83,x84)) && (((x78==x80) && (x77==x83)) && (x81==x84)));
*/
void mult(int  * x76, int  x77, int  x78, int  * x79, int  x80, int  x81, int  * x82, int  x83, int  x84) {
  /*@
  loop invariant 0<=x89<=x77;
  loop assigns x89, x82[(0..(x83*x84)-1)];
  loop variant x77-x89;
  */
  for(int x89=0; x89 < x77; x89++) {
    /*@
    loop invariant 0<=x91<=x81;
    loop assigns x91, x82[(0..(x83*x84)-1)];
    loop variant x81-x91;
    */
    for(int x91=0; x91 < x81; x91++) {
      int x92 = index(x83,x84,x89,x91);
      x82[x92] = 0/*false*/;
      /*@
      loop invariant 0<=x95<=x78;
      loop assigns x95, x82[(0..(x83*x84)-1)];
      loop variant x78-x95;
      */
      for(int x95=0; x95 < x78; x95++) {
        int x96 = x82[x92];
        int x97 = index(x77,x78,x89,x95);
        int x98 = x76[x97];
        int x101;
        if (x98) {
          int x99 = index(x80,x81,x95,x91);
          int x100 = x79[x99];
          x101 = x100;
        } else {
          x101 = 0/*false*/;
        }
        int x102 = x96 || x101;
        x82[x92] = x102;
      }
    }
  }
}
