#include <limits.h>
/*@ predicate unchanged{K,L}(int  * x0, integer  x1) = (\forall integer  x3; (((0<=x3) &&
(x3<x1)) ==> (\at(x0[x3],K)==\at(x0[x3],L))));*/
/*@
axiomatic MV_Prod {
  logic integer  MV_Prod{L}(integer  x13, integer  x14, integer  x15, int  * x16, int  * x17) reads x16[(0..(x15*x15)-1)], x17[(0..x15-1)];
  axiom MV_Prod_Empty{L}:
  \forall integer  x24, integer  x25, integer  x26, int  * x27, int  * x28; (((!((0<x24) &&
  (x24<=x26))) || (!((0<=x25) &&
  (x25<x26)))) ==> (MV_Prod{L}(x24,x25,x26,x27,x28)==0));
  axiom MV_Prod_One{L}:
  \forall integer  x43, integer  x44, integer  x45, int  * x46, int  * x47; (((((0<x43) &&
  (x43<=x45)) &&
  (0<=x44)) &&
  (x44<x45)) ==> (MV_Prod{L}(x43,x44,x45,x46,x47)==(MV_Prod{L}((x43-1),x44,x45,x46,x47)+(x46[((x45*x44)+(x43-1))]*x47[(x43-1)]))));
  axiom MV_Prod_Read{L1,L2}:
  \forall integer  x68, integer  x69, integer  x70, int  * x71, int  * x72; ((unchanged{L1,L2}(x71,(x70*x70)) &&
  unchanged{L1,L2}(x72,x70)) ==> (MV_Prod{L1}(x68,x69,x70,x71,x72)==MV_Prod{L2}(x68,x69,x70,x71,x72)));
}
*/
/*@
requires (((((((x87>0) &&
\valid(x88+(0..(x87*x87)-1))) &&
\valid(x89+(0..x87-1))) &&
\valid(x84+(0..x87-1))) &&
\separated(x88+(0..(x87*x87)-1),x84+(0..x87-1))) &&
\separated(x89+(0..x87-1),x84+(0..x87-1))) &&
((0<=x85) &&
(x85<x87)));
ensures (((((\forall int  x112; ((((0<=x112) &&
(x112<x87)) &&
(x112!=x85)) ==> (x84[x112]==\old(x84[x112])))) &&
(\forall int  x124; (((0<=x124) &&
(x124<(x87*x87))) ==> (x88[x124]==\old(x88[x124]))))) &&
(\forall int  x134; (((0<=x134) &&
(x134<x87)) ==> (x89[x134]==\old(x89[x134]))))) &&
(\forall int  x144; (((0<=x144) &&
(x144<x87)) ==> (MV_Prod(x87,x144,x87,x88,x89)==\old(MV_Prod(x87,x144,x87,x88,x89)))))) &&
(x84[x85]==x86));
assigns x84[x85];
*/
void put(int  * x84, int  x85, int  x86, int  x87, int  * x88, int  * x89) {
  x84[x85] = x86;
}
/*@
requires ((((((x160>0) &&
\valid(x161+(0..(x160*x160)-1))) &&
\valid(x162+(0..x160-1))) &&
\valid(x163+(0..x160-1))) &&
\separated(x161+(0..(x160*x160)-1),x163+(0..x160-1))) &&
\separated(x162+(0..x160-1),x163+(0..x160-1)));
ensures (\forall int  x231; (((0<=x231) &&
(x231<x160)) ==> (x163[x231]==MV_Prod(x160,x231,x160,x161,x162))));
assigns x163[(0..x160-1)];
*/
void mv_prod_impl(int  x160, int  * x161, int  * x162, int  * x163) {
  /*@
  loop invariant 0<=x166<=x160;
  loop invariant (\forall int  x167; (((0<=x167) &&
  (x167<x166)) ==> (x163[x167]==MV_Prod(x160,x167,x160,x161,x162))));
  loop assigns x166, x163[(0..x160-1)];
  loop variant x160-x166;
  */
  for(int x166=0; x166 < x160; x166++) {
    int x180 = 0;
    int x203 = x160 * x166;
    /*@
    loop invariant 0<=x181<=x160;
    loop invariant ((0<=x166) &&
    (x166<x160));
    loop invariant (\forall int  x185; (((0<=x185) &&
    (x185<x166)) ==> (x163[x185]==MV_Prod(x160,x185,x160,x161,x162))));
    loop invariant (x180==MV_Prod(x181,x166,x160,x161,x162));
    loop assigns x181, x180;
    loop variant x160-x181;
    */
    for(int x181=0; x181 < x160; x181++) {
      int x202 = x180;
      int x204 = x203 + x181;
      int x205 = x161[x204];
      int x206 = x162[x181];
      int x207 = x205 * x206;
      int x208 = x202 + x207;
      x180 = x208;
    }
    int x212 = x180;
    put(x163,x166,x212,x160,x161,x162);
  }
}
/*@
requires ((((((((((((((((((((((((((((((((x241>0) &&
\valid(x242+(0..(x241*x241)-1))) &&
\valid(x243+(0..x241-1))) &&
\valid(x244+(0..x241-1))) &&
\separated(x242+(0..(x241*x241)-1),x244+(0..x241-1))) &&
\separated(x243+(0..x241-1),x244+(0..x241-1))) &&
(x241==5)) &&
(x242[0]==1)) &&
(x242[1]==1)) &&
(x242[2]==1)) &&
(x242[3]==1)) &&
(x242[4]==1)) &&
(x242[5]==0)) &&
(x242[6]==0)) &&
(x242[7]==0)) &&
(x242[8]==0)) &&
(x242[9]==0)) &&
(x242[10]==0)) &&
(x242[11]==0)) &&
(x242[12]==1)) &&
(x242[13]==0)) &&
(x242[14]==0)) &&
(x242[15]==0)) &&
(x242[16]==0)) &&
(x242[17]==0)) &&
(x242[18]==0)) &&
(x242[19]==0)) &&
(x242[20]==0)) &&
(x242[21]==0)) &&
(x242[22]==1)) &&
(x242[23]==0)) &&
(x242[24]==1));
ensures (\forall int  x879; (((0<=x879) &&
(x879<x241)) ==> (x244[x879]==MV_Prod(x241,x879,x241,x242,x243))));
assigns x244[(0..x241-1)];
*/
void mv_prod_specialized(int  x241, int  * x242, int  * x243, int  * x244) {
  /*@assert (\forall int  x246; (((0<=x246) &&
  (x246<0)) ==> (x244[x246]==MV_Prod(x241,x246,x241,x242,x243))));*/
  int x257 = 0;
  /*@
  loop invariant 0<=x259<=x241;
  loop invariant (0<x241);
  loop invariant (\forall int  x261; (((0<=x261) &&
  (x261<0)) ==> (x244[x261]==MV_Prod(x241,x261,x241,x242,x243))));
  loop invariant (x257==MV_Prod(x259,0,x241,x242,x243));
  loop assigns x259, x257;
  loop variant x241-x259;
  */
  for(int x259=0; x259 < x241; x259++) {
    int x278 = x257;
    int x279 = x242[x259];
    int x280 = x243[x259];
    int x281 = x279 * x280;
    int x282 = x278 + x281;
    x257 = x282;
  }
  int x286 = x257;
  put(x244,0,x286,x241,x242,x243);
  /*@assert (\forall int  x288; (((0<=x288) &&
  (x288<=0)) ==> (x244[x288]==MV_Prod(x241,x288,x241,x242,x243))));*/
  /*@assert (\forall int  x299; (((0<=x299) &&
  (x299<1)) ==> (x244[x299]==MV_Prod(x241,x299,x241,x242,x243))));*/
  int x310 = 0;
  /*@assert (\forall int  x311; (((0<=x311) &&
  (x311<1)) ==> (x244[x311]==MV_Prod(x241,x311,x241,x242,x243))));*/
  /*@assert (x310==MV_Prod(0,1,x241,x242,x243));*/
  int x327 = x310;
  x310 = x327;
  /*@assert (\forall int  x330; (((0<=x330) &&
  (x330<1)) ==> (x244[x330]==MV_Prod(x241,x330,x241,x242,x243))));*/
  /*@assert (x310==MV_Prod(1,1,x241,x242,x243));*/
  int x346 = x310;
  x310 = x346;
  /*@assert (\forall int  x349; (((0<=x349) &&
  (x349<1)) ==> (x244[x349]==MV_Prod(x241,x349,x241,x242,x243))));*/
  /*@assert (x310==MV_Prod(2,1,x241,x242,x243));*/
  int x365 = x310;
  x310 = x365;
  /*@assert (\forall int  x368; (((0<=x368) &&
  (x368<1)) ==> (x244[x368]==MV_Prod(x241,x368,x241,x242,x243))));*/
  /*@assert (x310==MV_Prod(3,1,x241,x242,x243));*/
  int x384 = x310;
  x310 = x384;
  /*@assert (\forall int  x387; (((0<=x387) &&
  (x387<1)) ==> (x244[x387]==MV_Prod(x241,x387,x241,x242,x243))));*/
  /*@assert (x310==MV_Prod(4,1,x241,x242,x243));*/
  int x403 = x310;
  x310 = x403;
  /*@assert (x310==MV_Prod(x241,1,x241,x242,x243));*/
  int x411 = x310;
  put(x244,1,x411,x241,x242,x243);
  /*@assert (\forall int  x413; (((0<=x413) &&
  (x413<=1)) ==> (x244[x413]==MV_Prod(x241,x413,x241,x242,x243))));*/
  /*@assert (\forall int  x424; (((0<=x424) &&
  (x424<2)) ==> (x244[x424]==MV_Prod(x241,x424,x241,x242,x243))));*/
  int x435 = 0;
  /*@assert (\forall int  x436; (((0<=x436) &&
  (x436<2)) ==> (x244[x436]==MV_Prod(x241,x436,x241,x242,x243))));*/
  /*@assert (x435==MV_Prod(0,2,x241,x242,x243));*/
  int x452 = x435;
  x435 = x452;
  /*@assert (\forall int  x454; (((0<=x454) &&
  (x454<2)) ==> (x244[x454]==MV_Prod(x241,x454,x241,x242,x243))));*/
  /*@assert (x435==MV_Prod(1,2,x241,x242,x243));*/
  int x470 = x435;
  x435 = x470;
  /*@assert (\forall int  x472; (((0<=x472) &&
  (x472<2)) ==> (x244[x472]==MV_Prod(x241,x472,x241,x242,x243))));*/
  /*@assert (x435==MV_Prod(2,2,x241,x242,x243));*/
  int x488 = x435;
  int x366 = x243[2];
  int x489 = x488 + x366;
  x435 = x489;
  /*@assert (\forall int  x491; (((0<=x491) &&
  (x491<2)) ==> (x244[x491]==MV_Prod(x241,x491,x241,x242,x243))));*/
  /*@assert (x435==MV_Prod(3,2,x241,x242,x243));*/
  int x507 = x435;
  x435 = x507;
  /*@assert (\forall int  x509; (((0<=x509) &&
  (x509<2)) ==> (x244[x509]==MV_Prod(x241,x509,x241,x242,x243))));*/
  /*@assert (x435==MV_Prod(4,2,x241,x242,x243));*/
  int x525 = x435;
  x435 = x525;
  /*@assert (x435==MV_Prod(x241,2,x241,x242,x243));*/
  int x532 = x435;
  put(x244,2,x532,x241,x242,x243);
  /*@assert (\forall int  x534; (((0<=x534) &&
  (x534<=2)) ==> (x244[x534]==MV_Prod(x241,x534,x241,x242,x243))));*/
  /*@assert (\forall int  x545; (((0<=x545) &&
  (x545<3)) ==> (x244[x545]==MV_Prod(x241,x545,x241,x242,x243))));*/
  int x556 = 0;
  /*@assert (\forall int  x557; (((0<=x557) &&
  (x557<3)) ==> (x244[x557]==MV_Prod(x241,x557,x241,x242,x243))));*/
  /*@assert (x556==MV_Prod(0,3,x241,x242,x243));*/
  int x573 = x556;
  x556 = x573;
  /*@assert (\forall int  x575; (((0<=x575) &&
  (x575<3)) ==> (x244[x575]==MV_Prod(x241,x575,x241,x242,x243))));*/
  /*@assert (x556==MV_Prod(1,3,x241,x242,x243));*/
  int x591 = x556;
  x556 = x591;
  /*@assert (\forall int  x593; (((0<=x593) &&
  (x593<3)) ==> (x244[x593]==MV_Prod(x241,x593,x241,x242,x243))));*/
  /*@assert (x556==MV_Prod(2,3,x241,x242,x243));*/
  int x609 = x556;
  x556 = x609;
  /*@assert (\forall int  x611; (((0<=x611) &&
  (x611<3)) ==> (x244[x611]==MV_Prod(x241,x611,x241,x242,x243))));*/
  /*@assert (x556==MV_Prod(3,3,x241,x242,x243));*/
  int x627 = x556;
  x556 = x627;
  /*@assert (\forall int  x629; (((0<=x629) &&
  (x629<3)) ==> (x244[x629]==MV_Prod(x241,x629,x241,x242,x243))));*/
  /*@assert (x556==MV_Prod(4,3,x241,x242,x243));*/
  int x645 = x556;
  x556 = x645;
  /*@assert (x556==MV_Prod(x241,3,x241,x242,x243));*/
  int x652 = x556;
  put(x244,3,x652,x241,x242,x243);
  /*@assert (\forall int  x654; (((0<=x654) &&
  (x654<=3)) ==> (x244[x654]==MV_Prod(x241,x654,x241,x242,x243))));*/
  /*@assert (\forall int  x665; (((0<=x665) &&
  (x665<4)) ==> (x244[x665]==MV_Prod(x241,x665,x241,x242,x243))));*/
  int x676 = 0;
  /*@assert (\forall int  x677; (((0<=x677) &&
  (x677<4)) ==> (x244[x677]==MV_Prod(x241,x677,x241,x242,x243))));*/
  /*@assert (x676==MV_Prod(0,4,x241,x242,x243));*/
  int x693 = x676;
  x676 = x693;
  /*@assert (\forall int  x695; (((0<=x695) &&
  (x695<4)) ==> (x244[x695]==MV_Prod(x241,x695,x241,x242,x243))));*/
  /*@assert (x676==MV_Prod(1,4,x241,x242,x243));*/
  int x711 = x676;
  x676 = x711;
  /*@assert (\forall int  x713; (((0<=x713) &&
  (x713<4)) ==> (x244[x713]==MV_Prod(x241,x713,x241,x242,x243))));*/
  /*@assert (x676==MV_Prod(2,4,x241,x242,x243));*/
  int x729 = x676;
  int x730 = x729 + x366;
  x676 = x730;
  /*@assert (\forall int  x732; (((0<=x732) &&
  (x732<4)) ==> (x244[x732]==MV_Prod(x241,x732,x241,x242,x243))));*/
  /*@assert (x676==MV_Prod(3,4,x241,x242,x243));*/
  int x748 = x676;
  x676 = x748;
  /*@assert (\forall int  x750; (((0<=x750) &&
  (x750<4)) ==> (x244[x750]==MV_Prod(x241,x750,x241,x242,x243))));*/
  /*@assert (x676==MV_Prod(4,4,x241,x242,x243));*/
  int x766 = x676;
  int x404 = x243[4];
  int x767 = x766 + x404;
  x676 = x767;
  /*@assert (x676==MV_Prod(x241,4,x241,x242,x243));*/
  int x774 = x676;
  put(x244,4,x774,x241,x242,x243);
  /*@assert (\forall int  x776; (((0<=x776) &&
  (x776<=4)) ==> (x244[x776]==MV_Prod(x241,x776,x241,x242,x243))));*/
}
