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
requires (((((inv_matrix_Boolean(x63,x64,x65) &&
inv_matrix_Boolean(x66,x67,x68)) &&
inv_matrix_Boolean(x69,x70,x71)) &&
((x70==x64) &&
(x71==x65))) &&
((x70==x67) &&
(x71==x68))) &&
((\forall int  x121; (\forall int  x122; ((((0<=x121) &&
(x121<(x70*x71))) &&
((0<=x122) &&
(x122<(x64*x65)))) ==> \separated(x69+x121,x63+x122)))) &&
(\forall int  x136; (\forall int  x137; ((((0<=x136) &&
(x136<(x70*x71))) &&
((0<=x137) &&
(x137<(x67*x68)))) ==> \separated(x69+x136,x66+x137))))));
ensures (((inv_matrix_Boolean(x63,x64,x65) &&
inv_matrix_Boolean(x66,x67,x68)) &&
inv_matrix_Boolean(x69,x70,x71)) &&
(\forall int  x157; (((0<=x157) &&
(x157<(x70*x71))) ==> (x69[x157]==(x63[x157] || x66[x157])))));
*/
void add(int  * x63, int  x64, int  x65, int  * x66, int  x67, int  x68, int  * x69, int  x70, int  x71) {
  /*@assert \separated(x69+0,x63+0);*/
  /*@assert \separated(x69+0,x66+0);*/
  /*@
  loop invariant 0<=x81<=x73;
  loop invariant (\forall int  x82; (((0<=x82) &&
  (x82<x81)) ==> (x69[x82]==(x63[x82] || x66[x82]))));
  loop assigns x81, x69[(0..(x70*x71)-1)];
  loop variant x73-x81;
  */
  for(int x81=0; x81 < x73; x81++) {
    int x94 = x63[x81];
    int x95 = x66[x81];
    int x96 = x94 || x95;
    x69[x81] = x96;
    /*@assert \separated(x69+x81,x63+x81);*/
    /*@assert \separated(x69+x81,x66+x81);*/
  }
}
/*@
requires (((inv_matrix_Boolean(x172,x173,x174) &&
inv_matrix_Boolean(x175,x176,x177)) &&
((x176==x173) &&
(x177==x174))) &&
(\forall int  x213; (\forall int  x214; ((((0<=x213) &&
(x213<(x176*x177))) &&
((0<=x214) &&
(x214<(x173*x174)))) ==> \separated(x175+x213,x172+x214)))));
ensures (((inv_matrix_Boolean(x172,x173,x174) &&
inv_matrix_Boolean(x175,x176,x177)) &&
(\forall int  x233; (((0<=x233) &&
(x233<(x176*x177))) ==> (x175[x233]==(x171 &&
x172[x233]))))) &&
((x171==\false) ==> (\forall int x247; (0<=x247<x176) ==> (\forall int x250; (0<=x250<x177) ==> (x175[((x247*x177)+x250)]==\false)))));
*/
void scalar_mult(int  x171, int  * x172, int  x173, int  x174, int  * x175, int  x176, int  x177) {
  /*@assert \separated(x175+0,x172+0);*/
  /*@
  loop invariant 0<=x184<=x179;
  loop invariant (\forall int  x185; (((0<=x185) &&
  (x185<x184)) ==> (x175[x185]==(x171 &&
  x172[x185]))));
  loop assigns x184, x175[(0..(x176*x177)-1)];
  loop variant x179-x184;
  */
  for(int x184=0; x184 < x179; x184++) {
    int x197;
    if (x171) {
      int x196 = x172[x184];
      x197 = x196;
    } else {
      x197 = 0/*false*/;
    }
    x175[x184] = x197;
    /*@assert \separated(x175+x184,x172+x184);*/
  }
}
