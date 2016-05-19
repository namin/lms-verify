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
ensures (\forall int  x182; (((0<=x182) && (x182<(x83*x84))) ==> (x82[x182]==(x76[x182] || x79[x182]))));
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
requires (((inv_matrix_Boolean(x197,x198,x199) && inv_matrix_Boolean(x200,x201,x202)) && ((x201==x198) && (x202==x199))) && (\forall int  x241; (\forall int  x242; ((((0<=x241) && (x241<(x201*x202))) && ((0<=x242) && (x242<(x198*x199)))) ==> \separated(x200+x241,x197+x242)))));
ensures ((\forall int  x264; (((0<=x264) && (x264<(x201*x202))) ==> (x200[x264]==(x196 && x197[x264])))) && ((x196==0) ==> (x200[0]==0)));
*/
void scalar_mult(int  x196, int  * x197, int  x198, int  x199, int  * x200, int  x201, int  x202) {
  //@assert \separated(x200+0,x197+0);
  int x204 = x201 * x202;
  /*@
  loop invariant 0<=x209<=x204;
  loop invariant (\forall int  x210; (((0<=x210) && (x210<x209)) ==> (x200[x210]==(x196 && x197[x210]))));
  loop assigns x209, x200[(0..x204-1)];
  loop variant x204-x209;
  */
  for(int x209=0; x209 < x204; x209++) {
    int x224;
    if (x196) {
      int x223 = x197[x209];
      x224 = x223;
    } else {
      x224 = 0/*false*/;
    }
    x200[x209] = x224;
    //@assert \separated(x200+x209,x197+x209);
  }
}
