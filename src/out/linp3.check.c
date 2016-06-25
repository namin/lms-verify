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
requires (((((inv_matrix_Boolean(x79,x80,x81) &&
inv_matrix_Boolean(x82,x83,x84)) &&
inv_matrix_Boolean(x85,x86,x87)) &&
((x86==x80) &&
(x87==x81))) &&
((x86==x83) &&
(x87==x84))) &&
((\forall int  x141; (\forall int  x142; ((((0<=x141) &&
(x141<(x86*x87))) &&
((0<=x142) &&
(x142<(x80*x81)))) ==> \separated(x85+x141,x79+x142)))) &&
(\forall int  x161; (\forall int  x162; ((((0<=x161) &&
(x161<(x86*x87))) &&
((0<=x162) &&
(x162<(x83*x84)))) ==> \separated(x85+x161,x82+x162))))));
ensures (((inv_matrix_Boolean(x79,x80,x81) &&
inv_matrix_Boolean(x82,x83,x84)) &&
inv_matrix_Boolean(x85,x86,x87)) &&
(\forall int  x188; (((0<=x188) &&
(x188<(x86*x87))) ==> (x85[x188]==(x79[x188] || x82[x188])))));
*/
void add(int  * x79, int  x80, int  x81, int  * x82, int  x83, int  x84, int  * x85, int  x86, int  x87) {
  /*@assert \separated(x85+0,x79+0);*/
  /*@assert \separated(x85+0,x82+0);*/
  int x89 = x86 * x87;
  /*@
  loop invariant 0<=x97<=x89;
  loop invariant (\forall int  x98; (((0<=x98) &&
  (x98<x97)) ==> (x85[x98]==(x79[x98] || x82[x98]))));
  loop assigns x97, x85[(0..x89-1)];
  loop variant x89-x97;
  */
  for(int x97=0; x97 < x89; x97++) {
    int x112 = x79[x97];
    int x113 = x82[x97];
    int x114 = x112 || x113;
    x85[x97] = x114;
    /*@assert \separated(x85+x97,x79+x97);*/
    /*@assert \separated(x85+x97,x82+x97);*/
  }
}
/*@
requires (((inv_matrix_Boolean(x204,x205,x206) &&
inv_matrix_Boolean(x207,x208,x209)) &&
((x208==x205) &&
(x209==x206))) &&
(\forall int  x248; (\forall int  x249; ((((0<=x248) &&
(x248<(x208*x209))) &&
((0<=x249) &&
(x249<(x205*x206)))) ==> \separated(x207+x248,x204+x249)))));
ensures (((inv_matrix_Boolean(x204,x205,x206) &&
inv_matrix_Boolean(x207,x208,x209)) &&
(\forall int  x274; (((0<=x274) &&
(x274<(x208*x209))) ==> (x207[x274]==(x203 &&
x204[x274]))))) &&
((x203==\false) ==> (\forall int x289; (0<=x289<x208) ==> (\forall int x292; (0<=x292<x209) ==> (x207[((x289*x209)+x292)]==\false)))));
*/
void scalar_mult(int  x203, int  * x204, int  x205, int  x206, int  * x207, int  x208, int  x209) {
  /*@assert \separated(x207+0,x204+0);*/
  int x211 = x208 * x209;
  /*@
  loop invariant 0<=x216<=x211;
  loop invariant (\forall int  x217; (((0<=x217) &&
  (x217<x216)) ==> (x207[x217]==(x203 &&
  x204[x217]))));
  loop assigns x216, x207[(0..x211-1)];
  loop variant x211-x216;
  */
  for(int x216=0; x216 < x211; x216++) {
    int x231;
    if (x203) {
      int x230 = x204[x216];
      x231 = x230;
    } else {
      x231 = 0/*false*/;
    }
    x207[x216] = x231;
    /*@assert \separated(x207+x216,x204+x216);*/
  }
}
