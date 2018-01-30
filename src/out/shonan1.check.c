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
ensures (\forall int  x1014; (((0<=x1014) &&
(x1014<x280)) ==> (x283[x1014]==MV_Prod(x280,x1014,x280,x281,x282))));
assigns x283[(0..x280-1)];
*/
void mv_prod_specialized(int  x280, int  * x281, int  * x282, int  * x283) {
  /*@assert (\forall int  x285; (((0<=x285) &&
  (x285<0)) ==> (x283[x285]==MV_Prod(x280,x285,x280,x281,x282))));*/
  int x298 = 0;
  int x323 = x280 * 0;
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
    int x324 = x323 + x300;
    int x325 = x281[x324];
    int x326 = x282[x300];
    int x327 = x325 * x326;
    int x328 = x322 + x327;
    x298 = x328;
  }
  int x332 = x298;
  put(x283,0,x332,x280,x281,x282);
  /*@assert (\forall int  x334; (((0<=x334) &&
  (x334<=0)) ==> (x283[x334]==MV_Prod(x280,x334,x280,x281,x282))));*/
  /*@assert (\forall int  x347; (((0<=x347) &&
  (x347<1)) ==> (x283[x347]==MV_Prod(x280,x347,x280,x281,x282))));*/
  int x360 = 0;
  /*@assert (\forall int  x361; (((0<=x361) &&
  (x361<1)) ==> (x283[x361]==MV_Prod(x280,x361,x280,x281,x282))));*/
  /*@assert (x360==MV_Prod(0,1,x280,x281,x282));*/
  int x379 = x360;
  int x380 = x282[0];
  int x381 = 0 * x380;
  int x382 = x379 + x381;
  x360 = x382;
  /*@assert (\forall int  x384; (((0<=x384) &&
  (x384<1)) ==> (x283[x384]==MV_Prod(x280,x384,x280,x281,x282))));*/
  /*@assert (x360==MV_Prod(1,1,x280,x281,x282));*/
  int x402 = x360;
  int x403 = x282[1];
  int x404 = 0 * x403;
  int x405 = x402 + x404;
  x360 = x405;
  /*@assert (\forall int  x407; (((0<=x407) &&
  (x407<1)) ==> (x283[x407]==MV_Prod(x280,x407,x280,x281,x282))));*/
  /*@assert (x360==MV_Prod(2,1,x280,x281,x282));*/
  int x425 = x360;
  int x426 = x282[2];
  int x427 = 0 * x426;
  int x428 = x425 + x427;
  x360 = x428;
  /*@assert (\forall int  x430; (((0<=x430) &&
  (x430<1)) ==> (x283[x430]==MV_Prod(x280,x430,x280,x281,x282))));*/
  /*@assert (x360==MV_Prod(3,1,x280,x281,x282));*/
  int x448 = x360;
  int x449 = x282[3];
  int x450 = 0 * x449;
  int x451 = x448 + x450;
  x360 = x451;
  /*@assert (\forall int  x453; (((0<=x453) &&
  (x453<1)) ==> (x283[x453]==MV_Prod(x280,x453,x280,x281,x282))));*/
  /*@assert (x360==MV_Prod(4,1,x280,x281,x282));*/
  int x471 = x360;
  int x472 = x282[4];
  int x473 = 0 * x472;
  int x474 = x471 + x473;
  x360 = x474;
  /*@assert (x360==MV_Prod(x280,1,x280,x281,x282));*/
  int x481 = x360;
  put(x283,1,x481,x280,x281,x282);
  /*@assert (\forall int  x483; (((0<=x483) &&
  (x483<=1)) ==> (x283[x483]==MV_Prod(x280,x483,x280,x281,x282))));*/
  /*@assert (\forall int  x496; (((0<=x496) &&
  (x496<2)) ==> (x283[x496]==MV_Prod(x280,x496,x280,x281,x282))));*/
  int x509 = 0;
  /*@assert (\forall int  x510; (((0<=x510) &&
  (x510<2)) ==> (x283[x510]==MV_Prod(x280,x510,x280,x281,x282))));*/
  /*@assert (x509==MV_Prod(0,2,x280,x281,x282));*/
  int x528 = x509;
  int x529 = x528 + x381;
  x509 = x529;
  /*@assert (\forall int  x531; (((0<=x531) &&
  (x531<2)) ==> (x283[x531]==MV_Prod(x280,x531,x280,x281,x282))));*/
  /*@assert (x509==MV_Prod(1,2,x280,x281,x282));*/
  int x549 = x509;
  int x550 = x549 + x404;
  x509 = x550;
  /*@assert (\forall int  x552; (((0<=x552) &&
  (x552<2)) ==> (x283[x552]==MV_Prod(x280,x552,x280,x281,x282))));*/
  /*@assert (x509==MV_Prod(2,2,x280,x281,x282));*/
  int x570 = x509;
  int x571 = 1 * x426;
  int x572 = x570 + x571;
  x509 = x572;
  /*@assert (\forall int  x574; (((0<=x574) &&
  (x574<2)) ==> (x283[x574]==MV_Prod(x280,x574,x280,x281,x282))));*/
  /*@assert (x509==MV_Prod(3,2,x280,x281,x282));*/
  int x592 = x509;
  int x593 = x592 + x450;
  x509 = x593;
  /*@assert (\forall int  x595; (((0<=x595) &&
  (x595<2)) ==> (x283[x595]==MV_Prod(x280,x595,x280,x281,x282))));*/
  /*@assert (x509==MV_Prod(4,2,x280,x281,x282));*/
  int x613 = x509;
  int x614 = x613 + x473;
  x509 = x614;
  /*@assert (x509==MV_Prod(x280,2,x280,x281,x282));*/
  int x621 = x509;
  put(x283,2,x621,x280,x281,x282);
  /*@assert (\forall int  x623; (((0<=x623) &&
  (x623<=2)) ==> (x283[x623]==MV_Prod(x280,x623,x280,x281,x282))));*/
  /*@assert (\forall int  x636; (((0<=x636) &&
  (x636<3)) ==> (x283[x636]==MV_Prod(x280,x636,x280,x281,x282))));*/
  int x649 = 0;
  /*@assert (\forall int  x650; (((0<=x650) &&
  (x650<3)) ==> (x283[x650]==MV_Prod(x280,x650,x280,x281,x282))));*/
  /*@assert (x649==MV_Prod(0,3,x280,x281,x282));*/
  int x668 = x649;
  int x669 = x668 + x381;
  x649 = x669;
  /*@assert (\forall int  x671; (((0<=x671) &&
  (x671<3)) ==> (x283[x671]==MV_Prod(x280,x671,x280,x281,x282))));*/
  /*@assert (x649==MV_Prod(1,3,x280,x281,x282));*/
  int x689 = x649;
  int x690 = x689 + x404;
  x649 = x690;
  /*@assert (\forall int  x692; (((0<=x692) &&
  (x692<3)) ==> (x283[x692]==MV_Prod(x280,x692,x280,x281,x282))));*/
  /*@assert (x649==MV_Prod(2,3,x280,x281,x282));*/
  int x710 = x649;
  int x711 = x710 + x427;
  x649 = x711;
  /*@assert (\forall int  x713; (((0<=x713) &&
  (x713<3)) ==> (x283[x713]==MV_Prod(x280,x713,x280,x281,x282))));*/
  /*@assert (x649==MV_Prod(3,3,x280,x281,x282));*/
  int x731 = x649;
  int x732 = x731 + x450;
  x649 = x732;
  /*@assert (\forall int  x734; (((0<=x734) &&
  (x734<3)) ==> (x283[x734]==MV_Prod(x280,x734,x280,x281,x282))));*/
  /*@assert (x649==MV_Prod(4,3,x280,x281,x282));*/
  int x752 = x649;
  int x753 = x752 + x473;
  x649 = x753;
  /*@assert (x649==MV_Prod(x280,3,x280,x281,x282));*/
  int x760 = x649;
  put(x283,3,x760,x280,x281,x282);
  /*@assert (\forall int  x762; (((0<=x762) &&
  (x762<=3)) ==> (x283[x762]==MV_Prod(x280,x762,x280,x281,x282))));*/
  /*@assert (\forall int  x775; (((0<=x775) &&
  (x775<4)) ==> (x283[x775]==MV_Prod(x280,x775,x280,x281,x282))));*/
  int x788 = 0;
  /*@assert (\forall int  x789; (((0<=x789) &&
  (x789<4)) ==> (x283[x789]==MV_Prod(x280,x789,x280,x281,x282))));*/
  /*@assert (x788==MV_Prod(0,4,x280,x281,x282));*/
  int x807 = x788;
  int x808 = x807 + x381;
  x788 = x808;
  /*@assert (\forall int  x810; (((0<=x810) &&
  (x810<4)) ==> (x283[x810]==MV_Prod(x280,x810,x280,x281,x282))));*/
  /*@assert (x788==MV_Prod(1,4,x280,x281,x282));*/
  int x828 = x788;
  int x829 = x828 + x404;
  x788 = x829;
  /*@assert (\forall int  x831; (((0<=x831) &&
  (x831<4)) ==> (x283[x831]==MV_Prod(x280,x831,x280,x281,x282))));*/
  /*@assert (x788==MV_Prod(2,4,x280,x281,x282));*/
  int x849 = x788;
  int x850 = x849 + x571;
  x788 = x850;
  /*@assert (\forall int  x852; (((0<=x852) &&
  (x852<4)) ==> (x283[x852]==MV_Prod(x280,x852,x280,x281,x282))));*/
  /*@assert (x788==MV_Prod(3,4,x280,x281,x282));*/
  int x870 = x788;
  int x871 = x870 + x450;
  x788 = x871;
  /*@assert (\forall int  x873; (((0<=x873) &&
  (x873<4)) ==> (x283[x873]==MV_Prod(x280,x873,x280,x281,x282))));*/
  /*@assert (x788==MV_Prod(4,4,x280,x281,x282));*/
  int x891 = x788;
  int x892 = 1 * x472;
  int x893 = x891 + x892;
  x788 = x893;
  /*@assert (x788==MV_Prod(x280,4,x280,x281,x282));*/
  int x900 = x788;
  put(x283,4,x900,x280,x281,x282);
  /*@assert (\forall int  x902; (((0<=x902) &&
  (x902<=4)) ==> (x283[x902]==MV_Prod(x280,x902,x280,x281,x282))));*/
}
