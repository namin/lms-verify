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
/*@ predicate inv_matrix_Boolean(int  * x36, int  x37, int  x38) = (((((x37<100) && (x38<100)) && (0<x37)) && (0<x38)) && (((x37*x38)>0) && \valid(x36+(0..(x37*x38)-1))));*/
/*@
requires (((inv_matrix_Boolean(x79,x80,x81) && inv_matrix_Boolean(x82,x83,x84)) && inv_matrix_Boolean(x85,x86,x87)) &&
(((x81==x83) && (x80==x86)) && (x84==x87)));
ensures ((inv_matrix_Boolean(x79,x80,x81) && inv_matrix_Boolean(x82,x83,x84)) && inv_matrix_Boolean(x85,x86,x87));
*/
void mult(int  * x79, int  x80, int  x81, int  * x82, int  x83, int  x84, int  * x85, int  x86, int  x87) {
  /*@
  loop invariant 0<=x92<=x80;
  loop assigns x92, x85[(0..(x86*x87)-1)];
  loop variant x80-x92;
  */
  for(int x92=0; x92 < x80; x92++) {
    /*@
    loop invariant 0<=x94<=x84;
    loop assigns x94, x85[(0..(x86*x87)-1)];
    loop variant x84-x94;
    */
    for(int x94=0; x94 < x84; x94++) {
      int x95 = index(x86,x87,x92,x94);
      x85[x95] = 0/*false*/;
      /*@
      loop invariant 0<=x98<=x81;
      loop assigns x98, x85[(0..(x86*x87)-1)];
      loop variant x81-x98;
      */
      for(int x98=0; x98 < x81; x98++) {
        int x99 = x85[x95];
        int x100 = index(x80,x81,x92,x98);
        int x101 = x79[x100];
        int x104;
        if (x101) {
          int x102 = index(x83,x84,x98,x94);
          int x103 = x82[x102];
          x104 = x103;
        } else {
          x104 = 0/*false*/;
        }
        int x105 = x99 || x104;
        x85[x95] = x105;
      }
    }
  }
}
