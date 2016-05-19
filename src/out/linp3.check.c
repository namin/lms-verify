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
requires (((((inv_matrix_Boolean(x76,x77,x78) && inv_matrix_Boolean(x79,x80,x81)) && inv_matrix_Boolean(x82,x83,x84)) && ((x83==x77) && (x84==x78))) && ((x83==x80) && (x84==x81))) && ((\forall int  x138; (\forall int  x139; ((((0<=x138) && (x138<(x83*x84))) && ((0<=x139) && (x139<(x77*x78)))) ==> \separated(x82+x138,x76+x139)))) && (\forall int  x158; (\forall int  x159; ((((0<=x158) && (x158<(x83*x84))) && ((0<=x159) && (x159<(x80*x81)))) ==> \separated(x82+x158,x79+x159))))));
*/
void add(int  * x76, int  x77, int  x78, int  * x79, int  x80, int  x81, int  * x82, int  x83, int  x84) {
  //@assert \separated(x82+0,x76+0);
  //@assert \separated(x82+0,x79+0);
  int x86 = x83 * x84;
  /*@
  loop invariant 0<=x94<=x86;
  loop invariant (\forall int  x95; (((0<=x95) && (x95<x94)) ==> (x82[x95]==(x76[x95] || x79[x95]))));
  loop assigns x94, x82[(0..x86-1)];
  loop variant x86-x94;
  */
  for(int x94=0; x94 < x86; x94++) {
    int x109 = x76[x94];
    int x110 = x79[x94];
    int x111 = x109 || x110;
    x82[x94] = x111;
    //@assert \separated(x82+x94,x76+x94);
    //@assert \separated(x82+x94,x79+x94);
  }
}
/*@
requires (((inv_matrix_Boolean(x182,x183,x184) && inv_matrix_Boolean(x185,x186,x187)) && ((x186==x183) && (x187==x184))) && (\forall int  x226; (\forall int  x227; ((((0<=x226) && (x226<(x186*x187))) && ((0<=x227) && (x227<(x183*x184)))) ==> \separated(x185+x226,x182+x227)))));
*/
void scalar_mult(int  x181, int  * x182, int  x183, int  x184, int  * x185, int  x186, int  x187) {
  //@assert \separated(x185+0,x182+0);
  int x189 = x186 * x187;
  /*@
  loop invariant 0<=x194<=x189;
  loop invariant (\forall int  x195; (((0<=x195) && (x195<x194)) ==> (x185[x195]==(x181 && x182[x195]))));
  loop assigns x194, x185[(0..x189-1)];
  loop variant x189-x194;
  */
  for(int x194=0; x194 < x189; x194++) {
    int x209;
    if (x181) {
      int x208 = x182[x194];
      x209 = x208;
    } else {
      x209 = 0/*false*/;
    }
    x185[x194] = x209;
    //@assert \separated(x185+x194,x182+x194);
  }
}
