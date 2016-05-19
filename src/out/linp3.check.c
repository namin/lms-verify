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
requires (((((inv_matrix_Boolean(x79,x80,x81) && inv_matrix_Boolean(x82,x83,x84)) && inv_matrix_Boolean(x85,x86,x87)) && ((x86==x80) && (x87==x81))) && ((x86==x83) && (x87==x84))) && ((\forall int  x141; (\forall int  x142; ((((0<=x141) && (x141<(x86*x87))) && ((0<=x142) && (x142<(x80*x81)))) ==> \separated(x85+x141,x79+x142)))) && (\forall int  x161; (\forall int  x162; ((((0<=x161) && (x161<(x86*x87))) && ((0<=x162) && (x162<(x83*x84)))) ==> \separated(x85+x161,x82+x162))))));
ensures (\forall int  x185; (((0<=x185) && (x185<(x86*x87))) ==> (x85[x185]==(x79[x185] || x82[x185]))));
*/
void add(int  * x79, int  x80, int  x81, int  * x82, int  x83, int  x84, int  * x85, int  x86, int  x87) {
  //@assert \separated(x85+0,x79+0);
  //@assert \separated(x85+0,x82+0);
  int x89 = x86 * x87;
  /*@
  loop invariant 0<=x97<=x89;
  loop invariant (\forall int  x98; (((0<=x98) && (x98<x97)) ==> (x85[x98]==(x79[x98] || x82[x98]))));
  loop assigns x97, x85[(0..x89-1)];
  loop variant x89-x97;
  */
  for(int x97=0; x97 < x89; x97++) {
    int x112 = x79[x97];
    int x113 = x82[x97];
    int x114 = x112 || x113;
    x85[x97] = x114;
    //@assert \separated(x85+x97,x79+x97);
    //@assert \separated(x85+x97,x82+x97);
  }
}
/*@
requires (((inv_matrix_Boolean(x200,x201,x202) && inv_matrix_Boolean(x203,x204,x205)) && ((x204==x201) && (x205==x202))) && (\forall int  x244; (\forall int  x245; ((((0<=x244) && (x244<(x204*x205))) && ((0<=x245) && (x245<(x201*x202)))) ==> \separated(x203+x244,x200+x245)))));
ensures ((\forall int  x267; (((0<=x267) && (x267<(x204*x205))) ==> (x203[x267]==(x199 && x200[x267])))) && ((x199==\false) ==> (\forall int x281; (0<=x281<x204) ==> (\forall int x284; (0<=x284<x205) ==> (x203[((x281*x205)+x284)]==\false)))));
*/
void scalar_mult(int  x199, int  * x200, int  x201, int  x202, int  * x203, int  x204, int  x205) {
  //@assert \separated(x203+0,x200+0);
  int x207 = x204 * x205;
  /*@
  loop invariant 0<=x212<=x207;
  loop invariant (\forall int  x213; (((0<=x213) && (x213<x212)) ==> (x203[x213]==(x199 && x200[x213]))));
  loop assigns x212, x203[(0..x207-1)];
  loop variant x207-x212;
  */
  for(int x212=0; x212 < x207; x212++) {
    int x227;
    if (x199) {
      int x226 = x200[x212];
      x227 = x226;
    } else {
      x227 = 0/*false*/;
    }
    x203[x212] = x227;
    //@assert \separated(x203+x212,x200+x212);
  }
}
