#include <limits.h>
/*@ predicate unchanged{K,L}(int  * x0, integer  x1) = (\forall integer  x3; (((0<=x3) &&
(x3<x1)) ==> (\at(x0[x3],K)==\at(x0[x3],L))));*/
/*@
axiomatic MV_Prod {
  logic integer  MV_Prod{L}(integer  x16, integer  x17, integer  x18, int  * x19, int  * x20) reads x19[(0..(x18*x18)-1)], x20[(0..x18-1)];
  axiom MV_Prod_Empty{L}:
  \forall integer  x28, integer  x29, integer  x30, int  * x31, int  * x32; (((!((0<x28) &&
  (x28<=x30))) || (!((0<=x29) &&
  (x29<x30)))) ==> (MV_Prod{L}(x28,x29,x30,x31,x32)==0));
  axiom MV_Prod_One{L}:
  \forall integer  x47, integer  x48, integer  x49, int  * x50, int  * x51; (((((0<x47) &&
  (x47<=x49)) &&
  (0<=x48)) &&
  (x48<x49)) ==> (MV_Prod{L}(x47,x48,x49,x50,x51)==(MV_Prod{L}((x47-1),x48,x49,x50,x51)+(x50[((x49*x48)+(x47-1))]*x51[(x47-1)]))));
  axiom MV_Prod_Read{L1,L2}:
  \forall integer  x72, integer  x73, integer  x74, int  * x75, int  * x76; ((unchanged{L1,L2}(x75,(x74*x74)) &&
  unchanged{L1,L2}(x76,x74)) ==> (MV_Prod{L1}(x72,x73,x74,x75,x76)==MV_Prod{L2}(x72,x73,x74,x75,x76)));
}
*/
/*@
requires (((((((x91>0) &&
\valid(x92+(0..(x91*x91)-1))) &&
\valid(x93+(0..x91-1))) &&
\valid(x88+(0..x91-1))) &&
\separated(x92+(0..(x91*x91)-1),x88+(0..x91-1))) &&
\separated(x93+(0..x91-1),x88+(0..x91-1))) &&
((0<=x89) &&
(x89<x91)));
ensures (((((\forall int  x124; ((((0<=x124) &&
(x124<x91)) &&
(x124!=x89)) ==> (x88[x124]==\old(x88[x124])))) &&
(\forall int  x139; (((0<=x139) &&
(x139<(x91*x91))) ==> (x92[x139]==\old(x92[x139]))))) &&
(\forall int  x153; (((0<=x153) &&
(x153<x91)) ==> (x93[x153]==\old(x93[x153]))))) &&
(\forall int  x166; (((0<=x166) &&
(x166<x91)) ==> (MV_Prod(x91,x166,x91,x92,x93)==\old(MV_Prod(x91,x166,x91,x92,x93)))))) &&
(x88[x89]==x90));
assigns x88[x89];
*/
void put(int  * x88, int  x89, int  x90, int  x91, int  * x92, int  * x93) {
  x88[x89] = x90;
  int x96 = x88[x89];
}
/*@
requires ((((((x183>0) &&
\valid(x184+(0..(x183*x183)-1))) &&
\valid(x185+(0..x183-1))) &&
\valid(x186+(0..x183-1))) &&
\separated(x184+(0..(x183*x183)-1),x186+(0..x183-1))) &&
\separated(x185+(0..x183-1),x186+(0..x183-1)));
ensures (\forall int  x268; (((0<=x268) &&
(x268<x183)) ==> (x186[x268]==MV_Prod(x183,x268,x183,x184,x185))));
assigns x186[(0..x183-1)];
*/
void mv_prod_impl(int  x183, int  * x184, int  * x185, int  * x186) {
  /*@
  loop invariant 0<=x189<=x183;
  loop invariant (\forall int  x190; (((0<=x190) &&
  (x190<x189)) ==> (x186[x190]==MV_Prod(x183,x190,x183,x184,x185))));
  loop assigns x189, x186[(0..x183-1)];
  loop variant x183-x189;
  */
  for(int x189=0; x189 < x183; x189++) {
    int x206 = 0;
    int x233 = x183 * x189;
    /*@
    loop invariant 0<=x207<=x183;
    loop invariant ((0<=x189) &&
    (x189<x183));
    loop invariant (\forall int  x213; (((0<=x213) &&
    (x213<x189)) ==> (x186[x213]==MV_Prod(x183,x213,x183,x184,x185))));
    loop invariant (x206==MV_Prod(x207,x189,x183,x184,x185));
    loop assigns x207, x206;
    loop variant x183-x207;
    */
    for(int x207=0; x207 < x183; x207++) {
      int x232 = x206;
      int x234 = x233 + x207;
      int x235 = x184[x234];
      int x236 = x185[x207];
      int x237 = x235 * x236;
      int x238 = x232 + x237;
      x206 = x238;
    }
    int x242 = x206;
    put(x186,x189,x242,x183,x184,x185);
  }
}
/*@
requires ((((((((((((((((((((((((((((((((x280>0) &&
\valid(x281+(0..(x280*x280)-1))) &&
\valid(x282+(0..x280-1))) &&
\valid(x283+(0..x280-1))) &&
\separated(x281+(0..(x280*x280)-1),x283+(0..x280-1))) &&
\separated(x282+(0..x280-1),x283+(0..x280-1))) &&
(x280==5)) &&
(x281[0]==1)) &&
(x281[1]==1)) &&
(x281[2]==1)) &&
(x281[3]==1)) &&
(x281[4]==1)) &&
(x281[5]==0)) &&
(x281[6]==0)) &&
(x281[7]==0)) &&
(x281[8]==0)) &&
(x281[9]==0)) &&
(x281[10]==0)) &&
(x281[11]==0)) &&
(x281[12]==1)) &&
(x281[13]==0)) &&
(x281[14]==0)) &&
(x281[15]==0)) &&
(x281[16]==0)) &&
(x281[17]==0)) &&
(x281[18]==0)) &&
(x281[19]==0)) &&
(x281[20]==0)) &&
(x281[21]==0)) &&
(x281[22]==1)) &&
(x281[23]==0)) &&
(x281[24]==1));
ensures (\forall int  x988; (((0<=x988) &&
(x988<x280)) ==> (x283[x988]==MV_Prod(x280,x988,x280,x281,x282))));
assigns x283[(0..x280-1)];
*/
void mv_prod_specialized(int  x280, int  * x281, int  * x282, int  * x283) {
  /*@assert (\forall int  x285; (((0<=x285) &&
  (x285<0)) ==> (x283[x285]==MV_Prod(x280,x285,x280,x281,x282))));*/
  int x298 = 0;
  /*@
  loop invariant 0<=x300<=x280;
  loop invariant (0<x280);
  loop invariant (\forall int  x303; (((0<=x303) &&
  (x303<0)) ==> (x283[x303]==MV_Prod(x280,x303,x280,x281,x282))));
  loop invariant (x298==MV_Prod(x300,0,x280,x281,x282));
  loop assigns x300, x298;
  loop variant x280-x300;
  */
  for(int x300=0; x300 < x280; x300++) {
    int x322 = x298;
    int x323 = x281[x300];
    int x324 = x282[x300];
    int x325 = x323 * x324;
    int x326 = x322 + x325;
    x298 = x326;
  }
  int x330 = x298;
  put(x283,0,x330,x280,x281,x282);
  /*@assert (\forall int  x332; (((0<=x332) &&
  (x332<=0)) ==> (x283[x332]==MV_Prod(x280,x332,x280,x281,x282))));*/
  /*@assert (\forall int  x345; (((0<=x345) &&
  (x345<1)) ==> (x283[x345]==MV_Prod(x280,x345,x280,x281,x282))));*/
  int x358 = 0;
  /*@assert (\forall int  x359; (((0<=x359) &&
  (x359<1)) ==> (x283[x359]==MV_Prod(x280,x359,x280,x281,x282))));*/
  /*@assert (x358==MV_Prod(0,1,x280,x281,x282));*/
  int x377 = x358;
  x358 = x377;
  /*@assert (\forall int  x380; (((0<=x380) &&
  (x380<1)) ==> (x283[x380]==MV_Prod(x280,x380,x280,x281,x282))));*/
  /*@assert (x358==MV_Prod(1,1,x280,x281,x282));*/
  int x398 = x358;
  x358 = x398;
  /*@assert (\forall int  x401; (((0<=x401) &&
  (x401<1)) ==> (x283[x401]==MV_Prod(x280,x401,x280,x281,x282))));*/
  /*@assert (x358==MV_Prod(2,1,x280,x281,x282));*/
  int x419 = x358;
  x358 = x419;
  /*@assert (\forall int  x422; (((0<=x422) &&
  (x422<1)) ==> (x283[x422]==MV_Prod(x280,x422,x280,x281,x282))));*/
  /*@assert (x358==MV_Prod(3,1,x280,x281,x282));*/
  int x440 = x358;
  x358 = x440;
  /*@assert (\forall int  x443; (((0<=x443) &&
  (x443<1)) ==> (x283[x443]==MV_Prod(x280,x443,x280,x281,x282))));*/
  /*@assert (x358==MV_Prod(4,1,x280,x281,x282));*/
  int x461 = x358;
  x358 = x461;
  /*@assert (x358==MV_Prod(x280,1,x280,x281,x282));*/
  int x469 = x358;
  put(x283,1,x469,x280,x281,x282);
  /*@assert (\forall int  x471; (((0<=x471) &&
  (x471<=1)) ==> (x283[x471]==MV_Prod(x280,x471,x280,x281,x282))));*/
  /*@assert (\forall int  x484; (((0<=x484) &&
  (x484<2)) ==> (x283[x484]==MV_Prod(x280,x484,x280,x281,x282))));*/
  int x497 = 0;
  /*@assert (\forall int  x498; (((0<=x498) &&
  (x498<2)) ==> (x283[x498]==MV_Prod(x280,x498,x280,x281,x282))));*/
  /*@assert (x497==MV_Prod(0,2,x280,x281,x282));*/
  int x516 = x497;
  x497 = x516;
  /*@assert (\forall int  x518; (((0<=x518) &&
  (x518<2)) ==> (x283[x518]==MV_Prod(x280,x518,x280,x281,x282))));*/
  /*@assert (x497==MV_Prod(1,2,x280,x281,x282));*/
  int x536 = x497;
  x497 = x536;
  /*@assert (\forall int  x538; (((0<=x538) &&
  (x538<2)) ==> (x283[x538]==MV_Prod(x280,x538,x280,x281,x282))));*/
  /*@assert (x497==MV_Prod(2,2,x280,x281,x282));*/
  int x556 = x497;
  int x420 = x282[2];
  int x557 = x556 + x420;
  x497 = x557;
  /*@assert (\forall int  x559; (((0<=x559) &&
  (x559<2)) ==> (x283[x559]==MV_Prod(x280,x559,x280,x281,x282))));*/
  /*@assert (x497==MV_Prod(3,2,x280,x281,x282));*/
  int x577 = x497;
  x497 = x577;
  /*@assert (\forall int  x579; (((0<=x579) &&
  (x579<2)) ==> (x283[x579]==MV_Prod(x280,x579,x280,x281,x282))));*/
  /*@assert (x497==MV_Prod(4,2,x280,x281,x282));*/
  int x597 = x497;
  x497 = x597;
  /*@assert (x497==MV_Prod(x280,2,x280,x281,x282));*/
  int x604 = x497;
  put(x283,2,x604,x280,x281,x282);
  /*@assert (\forall int  x606; (((0<=x606) &&
  (x606<=2)) ==> (x283[x606]==MV_Prod(x280,x606,x280,x281,x282))));*/
  /*@assert (\forall int  x619; (((0<=x619) &&
  (x619<3)) ==> (x283[x619]==MV_Prod(x280,x619,x280,x281,x282))));*/
  int x632 = 0;
  /*@assert (\forall int  x633; (((0<=x633) &&
  (x633<3)) ==> (x283[x633]==MV_Prod(x280,x633,x280,x281,x282))));*/
  /*@assert (x632==MV_Prod(0,3,x280,x281,x282));*/
  int x651 = x632;
  x632 = x651;
  /*@assert (\forall int  x653; (((0<=x653) &&
  (x653<3)) ==> (x283[x653]==MV_Prod(x280,x653,x280,x281,x282))));*/
  /*@assert (x632==MV_Prod(1,3,x280,x281,x282));*/
  int x671 = x632;
  x632 = x671;
  /*@assert (\forall int  x673; (((0<=x673) &&
  (x673<3)) ==> (x283[x673]==MV_Prod(x280,x673,x280,x281,x282))));*/
  /*@assert (x632==MV_Prod(2,3,x280,x281,x282));*/
  int x691 = x632;
  x632 = x691;
  /*@assert (\forall int  x693; (((0<=x693) &&
  (x693<3)) ==> (x283[x693]==MV_Prod(x280,x693,x280,x281,x282))));*/
  /*@assert (x632==MV_Prod(3,3,x280,x281,x282));*/
  int x711 = x632;
  x632 = x711;
  /*@assert (\forall int  x713; (((0<=x713) &&
  (x713<3)) ==> (x283[x713]==MV_Prod(x280,x713,x280,x281,x282))));*/
  /*@assert (x632==MV_Prod(4,3,x280,x281,x282));*/
  int x731 = x632;
  x632 = x731;
  /*@assert (x632==MV_Prod(x280,3,x280,x281,x282));*/
  int x738 = x632;
  put(x283,3,x738,x280,x281,x282);
  /*@assert (\forall int  x740; (((0<=x740) &&
  (x740<=3)) ==> (x283[x740]==MV_Prod(x280,x740,x280,x281,x282))));*/
  /*@assert (\forall int  x753; (((0<=x753) &&
  (x753<4)) ==> (x283[x753]==MV_Prod(x280,x753,x280,x281,x282))));*/
  int x766 = 0;
  /*@assert (\forall int  x767; (((0<=x767) &&
  (x767<4)) ==> (x283[x767]==MV_Prod(x280,x767,x280,x281,x282))));*/
  /*@assert (x766==MV_Prod(0,4,x280,x281,x282));*/
  int x785 = x766;
  x766 = x785;
  /*@assert (\forall int  x787; (((0<=x787) &&
  (x787<4)) ==> (x283[x787]==MV_Prod(x280,x787,x280,x281,x282))));*/
  /*@assert (x766==MV_Prod(1,4,x280,x281,x282));*/
  int x805 = x766;
  x766 = x805;
  /*@assert (\forall int  x807; (((0<=x807) &&
  (x807<4)) ==> (x283[x807]==MV_Prod(x280,x807,x280,x281,x282))));*/
  /*@assert (x766==MV_Prod(2,4,x280,x281,x282));*/
  int x825 = x766;
  int x826 = x825 + x420;
  x766 = x826;
  /*@assert (\forall int  x828; (((0<=x828) &&
  (x828<4)) ==> (x283[x828]==MV_Prod(x280,x828,x280,x281,x282))));*/
  /*@assert (x766==MV_Prod(3,4,x280,x281,x282));*/
  int x846 = x766;
  x766 = x846;
  /*@assert (\forall int  x848; (((0<=x848) &&
  (x848<4)) ==> (x283[x848]==MV_Prod(x280,x848,x280,x281,x282))));*/
  /*@assert (x766==MV_Prod(4,4,x280,x281,x282));*/
  int x866 = x766;
  int x462 = x282[4];
  int x867 = x866 + x462;
  x766 = x867;
  /*@assert (x766==MV_Prod(x280,4,x280,x281,x282));*/
  int x874 = x766;
  put(x283,4,x874,x280,x281,x282);
  /*@assert (\forall int  x876; (((0<=x876) &&
  (x876<=4)) ==> (x283[x876]==MV_Prod(x280,x876,x280,x281,x282))));*/
}
