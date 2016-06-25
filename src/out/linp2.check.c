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
/*@ predicate inv_matrix_Boolean(int  * x36, int  x37, int  x38) = (((((x37<100) &&
(x38<100)) &&
(0<x37)) &&
(0<x38)) &&
(((x37*x38)>0) &&
\valid(x36+(0..(x37*x38)-1))));*/
/*@
requires (((inv_matrix_Boolean(x79,x80,x81) &&
inv_matrix_Boolean(x82,x83,x84)) &&
inv_matrix_Boolean(x85,x86,x87)) &&
((((x80==x83) &&
(x80==x86)) &&
(x81==x84)) &&
(x81==x87)));
ensures ((inv_matrix_Boolean(x79,x80,x81) &&
inv_matrix_Boolean(x82,x83,x84)) &&
inv_matrix_Boolean(x85,x86,x87));
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
requires ((inv_matrix_Boolean(x130,x131,x132) &&
inv_matrix_Boolean(x133,x134,x135)) &&
((x131==x134) &&
(x132==x135)));
ensures (inv_matrix_Boolean(x130,x131,x132) &&
inv_matrix_Boolean(x133,x134,x135));
*/
void scalar_mult(int  x129, int  * x130, int  x131, int  x132, int  * x133, int  x134, int  x135) {
  /*@
  loop invariant 0<=x140<=x134;
  loop assigns x140, x133[(0..(x134*x135)-1)];
  loop variant x134-x140;
  */
  for(int x140=0; x140 < x134; x140++) {
    /*@
    loop invariant 0<=x142<=x135;
    loop assigns x142, x133[(0..(x134*x135)-1)];
    loop variant x135-x142;
    */
    for(int x142=0; x142 < x135; x142++) {
      int x145;
      if (x129) {
        int x143 = index(x131,x132,x140,x142);
        int x144 = x130[x143];
        x145 = x144;
      } else {
        x145 = 0/*false*/;
      }
      int x146 = index(x134,x135,x140,x142);
      x133[x146] = x145;
    }
  }
}
