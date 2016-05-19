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
requires (((inv_matrix_Boolean(x79,x80,x81) && inv_matrix_Boolean(x82,x83,x84)) && inv_matrix_Boolean(x85,x86,x87)) && ((((x80==x83) && (x80==x86)) && (x81==x84)) && (x81==x87)));
*/
void add(int  * x79, int  x80, int  x81, int  * x82, int  x83, int  x84, int  * x85, int  x86, int  x87) {
  /*@
  loop invariant 0<=x92<=x86;
  loop assigns x92, x85[(0..(x86*x87)-1)];
  loop variant x86-x92;
  */
  for(int x92=0; x92 < x86; x92++) {
    /*@
    loop invariant 0<=x94<=x87;
    loop assigns x94, x85[(0..(x86*x87)-1)];
    loop variant x87-x94;
    */
    for(int x94=0; x94 < x87; x94++) {
      int x95 = index(x80,x81,x92,x94);
      int x96 = x79[x95];
      int x97 = index(x83,x84,x92,x94);
      int x98 = x82[x97];
      int x99 = x96 || x98;
      int x100 = index(x86,x87,x92,x94);
      x85[x100] = x99;
    }
  }
}
/*@
requires ((inv_matrix_Boolean(x126,x127,x128) && inv_matrix_Boolean(x129,x130,x131)) && ((x127==x130) && (x128==x131)));
*/
void scalar_mult(int  x125, int  * x126, int  x127, int  x128, int  * x129, int  x130, int  x131) {
  /*@
  loop invariant 0<=x136<=x130;
  loop assigns x136, x129[(0..(x130*x131)-1)];
  loop variant x130-x136;
  */
  for(int x136=0; x136 < x130; x136++) {
    /*@
    loop invariant 0<=x138<=x131;
    loop assigns x138, x129[(0..(x130*x131)-1)];
    loop variant x131-x138;
    */
    for(int x138=0; x138 < x131; x138++) {
      int x141;
      if (x125) {
        int x139 = index(x127,x128,x136,x138);
        int x140 = x126[x139];
        x141 = x140;
      } else {
        x141 = 0/*false*/;
      }
      int x142 = index(x130,x131,x136,x138);
      x129[x142] = x141;
    }
  }
}
