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
ensures (((((\forall int  x123; ((((0<=x123) &&
(x123<x91)) &&
(x123!=x89)) ==> (x88[x123]==\old(x88[x123])))) &&
(\forall int  x138; (((0<=x138) &&
(x138<(x91*x91))) ==> (x92[x138]==\old(x92[x138]))))) &&
(\forall int  x152; (((0<=x152) &&
(x152<x91)) ==> (x93[x152]==\old(x93[x152]))))) &&
(\forall int  x165; (((0<=x165) &&
(x165<x91)) ==> (MV_Prod(x91,x165,x91,x92,x93)==\old(MV_Prod(x91,x165,x91,x92,x93)))))) &&
(x88[x89]==x90));
assigns x88[x89];
*/
void put(int  * x88, int  x89, int  x90, int  x91, int  * x92, int  * x93) {
  x88[x89] = x90;
}
/*@
requires ((((((x182>0) &&
\valid(x183+(0..(x182*x182)-1))) &&
\valid(x184+(0..x182-1))) &&
\valid(x185+(0..x182-1))) &&
\separated(x183+(0..(x182*x182)-1),x185+(0..x182-1))) &&
\separated(x184+(0..x182-1),x185+(0..x182-1)));
ensures (\forall int  x267; (((0<=x267) &&
(x267<x182)) ==> (x185[x267]==MV_Prod(x182,x267,x182,x183,x184))));
assigns x185[(0..x182-1)];
*/
void mv_prod_impl(int  x182, int  * x183, int  * x184, int  * x185) {
  /*@
  loop invariant 0<=x188<=x182;
  loop invariant (\forall int  x189; (((0<=x189) &&
  (x189<x188)) ==> (x185[x189]==MV_Prod(x182,x189,x182,x183,x184))));
  loop assigns x188, x185[(0..x182-1)];
  loop variant x182-x188;
  */
  for(int x188=0; x188 < x182; x188++) {
    int x205 = 0;
    int x232 = x182 * x188;
    /*@
    loop invariant 0<=x206<=x182;
    loop invariant ((0<=x188) &&
    (x188<x182));
    loop invariant (\forall int  x212; (((0<=x212) &&
    (x212<x188)) ==> (x185[x212]==MV_Prod(x182,x212,x182,x183,x184))));
    loop invariant (x205==MV_Prod(x206,x188,x182,x183,x184));
    loop assigns x206, x205;
    loop variant x182-x206;
    */
    for(int x206=0; x206 < x182; x206++) {
      int x231 = x205;
      int x233 = x232 + x206;
      int x234 = x183[x233];
      int x235 = x184[x206];
      int x236 = x234 * x235;
      int x237 = x231 + x236;
      x205 = x237;
    }
    int x241 = x205;
    put(x185,x188,x241,x182,x183,x184);
  }
}
/*@
requires ((((((((((((((((((((((((((((((((x279>0) &&
\valid(x280+(0..(x279*x279)-1))) &&
\valid(x281+(0..x279-1))) &&
\valid(x282+(0..x279-1))) &&
\separated(x280+(0..(x279*x279)-1),x282+(0..x279-1))) &&
\separated(x281+(0..x279-1),x282+(0..x279-1))) &&
(x279==5)) &&
(x280[0]==1)) &&
(x280[1]==1)) &&
(x280[2]==1)) &&
(x280[3]==1)) &&
(x280[4]==1)) &&
(x280[5]==0)) &&
(x280[6]==0)) &&
(x280[7]==0)) &&
(x280[8]==0)) &&
(x280[9]==0)) &&
(x280[10]==0)) &&
(x280[11]==0)) &&
(x280[12]==1)) &&
(x280[13]==0)) &&
(x280[14]==0)) &&
(x280[15]==0)) &&
(x280[16]==0)) &&
(x280[17]==0)) &&
(x280[18]==0)) &&
(x280[19]==0)) &&
(x280[20]==0)) &&
(x280[21]==0)) &&
(x280[22]==1)) &&
(x280[23]==0)) &&
(x280[24]==1));
ensures (\forall int  x987; (((0<=x987) &&
(x987<x279)) ==> (x282[x987]==MV_Prod(x279,x987,x279,x280,x281))));
assigns x282[(0..x279-1)];
*/
void mv_prod_specialized(int  x279, int  * x280, int  * x281, int  * x282) {
  /*@assert (\forall int  x284; (((0<=x284) &&
  (x284<0)) ==> (x282[x284]==MV_Prod(x279,x284,x279,x280,x281))));*/
  int x297 = 0;
  /*@
  loop invariant 0<=x299<=x279;
  loop invariant (0<x279);
  loop invariant (\forall int  x302; (((0<=x302) &&
  (x302<0)) ==> (x282[x302]==MV_Prod(x279,x302,x279,x280,x281))));
  loop invariant (x297==MV_Prod(x299,0,x279,x280,x281));
  loop assigns x299, x297;
  loop variant x279-x299;
  */
  for(int x299=0; x299 < x279; x299++) {
    int x321 = x297;
    int x322 = x280[x299];
    int x323 = x281[x299];
    int x324 = x322 * x323;
    int x325 = x321 + x324;
    x297 = x325;
  }
  int x329 = x297;
  put(x282,0,x329,x279,x280,x281);
  /*@assert (\forall int  x331; (((0<=x331) &&
  (x331<=0)) ==> (x282[x331]==MV_Prod(x279,x331,x279,x280,x281))));*/
  /*@assert (\forall int  x344; (((0<=x344) &&
  (x344<1)) ==> (x282[x344]==MV_Prod(x279,x344,x279,x280,x281))));*/
  int x357 = 0;
  /*@assert (\forall int  x358; (((0<=x358) &&
  (x358<1)) ==> (x282[x358]==MV_Prod(x279,x358,x279,x280,x281))));*/
  /*@assert (x357==MV_Prod(0,1,x279,x280,x281));*/
  int x376 = x357;
  x357 = x376;
  /*@assert (\forall int  x379; (((0<=x379) &&
  (x379<1)) ==> (x282[x379]==MV_Prod(x279,x379,x279,x280,x281))));*/
  /*@assert (x357==MV_Prod(1,1,x279,x280,x281));*/
  int x397 = x357;
  x357 = x397;
  /*@assert (\forall int  x400; (((0<=x400) &&
  (x400<1)) ==> (x282[x400]==MV_Prod(x279,x400,x279,x280,x281))));*/
  /*@assert (x357==MV_Prod(2,1,x279,x280,x281));*/
  int x418 = x357;
  x357 = x418;
  /*@assert (\forall int  x421; (((0<=x421) &&
  (x421<1)) ==> (x282[x421]==MV_Prod(x279,x421,x279,x280,x281))));*/
  /*@assert (x357==MV_Prod(3,1,x279,x280,x281));*/
  int x439 = x357;
  x357 = x439;
  /*@assert (\forall int  x442; (((0<=x442) &&
  (x442<1)) ==> (x282[x442]==MV_Prod(x279,x442,x279,x280,x281))));*/
  /*@assert (x357==MV_Prod(4,1,x279,x280,x281));*/
  int x460 = x357;
  x357 = x460;
  /*@assert (x357==MV_Prod(x279,1,x279,x280,x281));*/
  int x468 = x357;
  put(x282,1,x468,x279,x280,x281);
  /*@assert (\forall int  x470; (((0<=x470) &&
  (x470<=1)) ==> (x282[x470]==MV_Prod(x279,x470,x279,x280,x281))));*/
  /*@assert (\forall int  x483; (((0<=x483) &&
  (x483<2)) ==> (x282[x483]==MV_Prod(x279,x483,x279,x280,x281))));*/
  int x496 = 0;
  /*@assert (\forall int  x497; (((0<=x497) &&
  (x497<2)) ==> (x282[x497]==MV_Prod(x279,x497,x279,x280,x281))));*/
  /*@assert (x496==MV_Prod(0,2,x279,x280,x281));*/
  int x515 = x496;
  x496 = x515;
  /*@assert (\forall int  x517; (((0<=x517) &&
  (x517<2)) ==> (x282[x517]==MV_Prod(x279,x517,x279,x280,x281))));*/
  /*@assert (x496==MV_Prod(1,2,x279,x280,x281));*/
  int x535 = x496;
  x496 = x535;
  /*@assert (\forall int  x537; (((0<=x537) &&
  (x537<2)) ==> (x282[x537]==MV_Prod(x279,x537,x279,x280,x281))));*/
  /*@assert (x496==MV_Prod(2,2,x279,x280,x281));*/
  int x555 = x496;
  int x419 = x281[2];
  int x556 = x555 + x419;
  x496 = x556;
  /*@assert (\forall int  x558; (((0<=x558) &&
  (x558<2)) ==> (x282[x558]==MV_Prod(x279,x558,x279,x280,x281))));*/
  /*@assert (x496==MV_Prod(3,2,x279,x280,x281));*/
  int x576 = x496;
  x496 = x576;
  /*@assert (\forall int  x578; (((0<=x578) &&
  (x578<2)) ==> (x282[x578]==MV_Prod(x279,x578,x279,x280,x281))));*/
  /*@assert (x496==MV_Prod(4,2,x279,x280,x281));*/
  int x596 = x496;
  x496 = x596;
  /*@assert (x496==MV_Prod(x279,2,x279,x280,x281));*/
  int x603 = x496;
  put(x282,2,x603,x279,x280,x281);
  /*@assert (\forall int  x605; (((0<=x605) &&
  (x605<=2)) ==> (x282[x605]==MV_Prod(x279,x605,x279,x280,x281))));*/
  /*@assert (\forall int  x618; (((0<=x618) &&
  (x618<3)) ==> (x282[x618]==MV_Prod(x279,x618,x279,x280,x281))));*/
  int x631 = 0;
  /*@assert (\forall int  x632; (((0<=x632) &&
  (x632<3)) ==> (x282[x632]==MV_Prod(x279,x632,x279,x280,x281))));*/
  /*@assert (x631==MV_Prod(0,3,x279,x280,x281));*/
  int x650 = x631;
  x631 = x650;
  /*@assert (\forall int  x652; (((0<=x652) &&
  (x652<3)) ==> (x282[x652]==MV_Prod(x279,x652,x279,x280,x281))));*/
  /*@assert (x631==MV_Prod(1,3,x279,x280,x281));*/
  int x670 = x631;
  x631 = x670;
  /*@assert (\forall int  x672; (((0<=x672) &&
  (x672<3)) ==> (x282[x672]==MV_Prod(x279,x672,x279,x280,x281))));*/
  /*@assert (x631==MV_Prod(2,3,x279,x280,x281));*/
  int x690 = x631;
  x631 = x690;
  /*@assert (\forall int  x692; (((0<=x692) &&
  (x692<3)) ==> (x282[x692]==MV_Prod(x279,x692,x279,x280,x281))));*/
  /*@assert (x631==MV_Prod(3,3,x279,x280,x281));*/
  int x710 = x631;
  x631 = x710;
  /*@assert (\forall int  x712; (((0<=x712) &&
  (x712<3)) ==> (x282[x712]==MV_Prod(x279,x712,x279,x280,x281))));*/
  /*@assert (x631==MV_Prod(4,3,x279,x280,x281));*/
  int x730 = x631;
  x631 = x730;
  /*@assert (x631==MV_Prod(x279,3,x279,x280,x281));*/
  int x737 = x631;
  put(x282,3,x737,x279,x280,x281);
  /*@assert (\forall int  x739; (((0<=x739) &&
  (x739<=3)) ==> (x282[x739]==MV_Prod(x279,x739,x279,x280,x281))));*/
  /*@assert (\forall int  x752; (((0<=x752) &&
  (x752<4)) ==> (x282[x752]==MV_Prod(x279,x752,x279,x280,x281))));*/
  int x765 = 0;
  /*@assert (\forall int  x766; (((0<=x766) &&
  (x766<4)) ==> (x282[x766]==MV_Prod(x279,x766,x279,x280,x281))));*/
  /*@assert (x765==MV_Prod(0,4,x279,x280,x281));*/
  int x784 = x765;
  x765 = x784;
  /*@assert (\forall int  x786; (((0<=x786) &&
  (x786<4)) ==> (x282[x786]==MV_Prod(x279,x786,x279,x280,x281))));*/
  /*@assert (x765==MV_Prod(1,4,x279,x280,x281));*/
  int x804 = x765;
  x765 = x804;
  /*@assert (\forall int  x806; (((0<=x806) &&
  (x806<4)) ==> (x282[x806]==MV_Prod(x279,x806,x279,x280,x281))));*/
  /*@assert (x765==MV_Prod(2,4,x279,x280,x281));*/
  int x824 = x765;
  int x825 = x824 + x419;
  x765 = x825;
  /*@assert (\forall int  x827; (((0<=x827) &&
  (x827<4)) ==> (x282[x827]==MV_Prod(x279,x827,x279,x280,x281))));*/
  /*@assert (x765==MV_Prod(3,4,x279,x280,x281));*/
  int x845 = x765;
  x765 = x845;
  /*@assert (\forall int  x847; (((0<=x847) &&
  (x847<4)) ==> (x282[x847]==MV_Prod(x279,x847,x279,x280,x281))));*/
  /*@assert (x765==MV_Prod(4,4,x279,x280,x281));*/
  int x865 = x765;
  int x461 = x281[4];
  int x866 = x865 + x461;
  x765 = x866;
  /*@assert (x765==MV_Prod(x279,4,x279,x280,x281));*/
  int x873 = x765;
  put(x282,4,x873,x279,x280,x281);
  /*@assert (\forall int  x875; (((0<=x875) &&
  (x875<=4)) ==> (x282[x875]==MV_Prod(x279,x875,x279,x280,x281))));*/
}
