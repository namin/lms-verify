#include <limits.h>
/*@ predicate eq___Int_Int__(int  x0, int  x1, int  x2, int  x3) = ((x0==x2) &&
(x1==x3));*/
/*@
assigns \nothing;
ensures \result <==> eq___Int_Int__(x0, x1, x2, x3);
*/
int eq___Int_Int__(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x0 == x2;
  int x7;
  if (x5) {
    int x6 = x1 == x3;
    x7 = x6;
  } else {
    x7 = 0/*false*/;
  }
  return x7;
}
/*@ predicate inv_vec___Int_Int__(int  * x8, int  * x9, integer  x10) = ((x10==0) || ((x10>0) &&
(\valid(x8+(0..x10-1)) &&
\valid(x9+(0..x10-1)))));*/
/*@
inductive vec___Int_Int___Permut{L1,L2}(int  * x28, int  * x29, integer  x30) {
  case vec___Int_Int___Permut_refl{L}:
  \forall int  * x31, int  * x32, integer  x33; vec___Int_Int___Permut{L,L}(x31,x32,x33);
  case vec___Int_Int___Permut_sym{L1,L2}:
  \forall int  * x37, int  * x38, integer  x39; (vec___Int_Int___Permut{L1,L2}(x37,x38,x39) ==> vec___Int_Int___Permut{L2,L1}(x37,x38,x39));
  case vec___Int_Int___Permut_trans{L1,L2,L3}:
  \forall int  * x45, int  * x46, integer  x47; ((vec___Int_Int___Permut{L1,L2}(x45,x46,x47) &&
  vec___Int_Int___Permut{L2,L3}(x45,x46,x47)) ==> vec___Int_Int___Permut{L1,L3}(x45,x46,x47));
  case vec___Int_Int___Permut_step{L1,L2}:
  \forall int  * x56, int  * x57, integer  x58; (\exists integer  x60; (\exists integer  x61; (((\at(eq___Int_Int__(\at(x56[x60],L1),\at(x57[x60],L1),\at(x56[x61],L2),\at(x57[x61],L2)),L1) &&
  \at(eq___Int_Int__(\at(x56[x60],L1),\at(x57[x60],L1),\at(x56[x61],L2),\at(x57[x61],L2)),L2)) &&
  (\at(eq___Int_Int__(\at(x56[x61],L1),\at(x57[x61],L1),\at(x56[x60],L2),\at(x57[x60],L2)),L1) &&
  \at(eq___Int_Int__(\at(x56[x61],L1),\at(x57[x61],L1),\at(x56[x60],L2),\at(x57[x60],L2)),L2))) &&
  (\forall integer  x83; (((((0<=x83) &&
  (x83<x58)) &&
  (x83!=x60)) &&
  (x83!=x61)) ==> (\at(eq___Int_Int__(\at(x56[x83],L1),\at(x57[x83],L1),\at(x56[x83],L2),\at(x57[x83],L2)),L1) &&
  \at(eq___Int_Int__(\at(x56[x83],L1),\at(x57[x83],L1),\at(x56[x83],L2),\at(x57[x83],L2)),L2)))))));
}
*/
/*@
requires ((inv_vec___Int_Int__(x106,x107,x108) &&
((((0<=x109) &&
(x109<x108)) &&
(0<=x110)) &&
(x110<x108))) &&
(\forall int  x133; (\forall int  x134; (((((0<=x133) &&
(x133<x108)) &&
(0<=x134)) &&
(x134<x108)) ==> \separated(x106+x133,x107+x134)))));
ensures (((inv_vec___Int_Int__(x106,x107,x108) &&
(((\at(eq___Int_Int__(\at(x106[x109],Old),\at(x107[x109],Old),\at(x106[x110],Post),\at(x107[x110],Post)),Old) &&
\at(eq___Int_Int__(\at(x106[x109],Old),\at(x107[x109],Old),\at(x106[x110],Post),\at(x107[x110],Post)),Post)) &&
(\at(eq___Int_Int__(\at(x106[x110],Old),\at(x107[x110],Old),\at(x106[x109],Post),\at(x107[x109],Post)),Old) &&
\at(eq___Int_Int__(\at(x106[x110],Old),\at(x107[x110],Old),\at(x106[x109],Post),\at(x107[x109],Post)),Post))) &&
(\forall int  x173; (((((0<=x173) &&
(x173<x108)) &&
(x173!=x109)) &&
(x173!=x110)) ==> (\at(eq___Int_Int__(\at(x106[x173],Old),\at(x107[x173],Old),\at(x106[x173],Post),\at(x107[x173],Post)),Old) &&
\at(eq___Int_Int__(\at(x106[x173],Old),\at(x107[x173],Old),\at(x106[x173],Post),\at(x107[x173],Post)),Post)))))) &&
vec___Int_Int___Permut{Old,Post}(x106,x107,x108)) &&
(\forall int  x198; (\forall int  x199; (((((0<=x198) &&
(x198<x108)) &&
(0<=x199)) &&
(x199<x108)) ==> \separated(x106+x198,x107+x199)))));
assigns x106[(0..x108-1)], x107[(0..x108-1)];
*/
void inswap___Int_Int__(int  * x106, int  * x107, int  x108, int  x109, int  x110) {
  int x113 = x106[x109];
  int x114 = x107[x109];
  int x115 = x106[x110];
  int x116 = x107[x110];
  x106[x109] = x115;
  x107[x109] = x116;
  x106[x110] = x113;
  x107[x110] = x114;
}
/*@
requires (inv_vec___Int_Int__(x214,x215,x216) &&
(\forall int  x555; (\forall int  x556; (((((0<=x555) &&
(x555<x216)) &&
(0<=x556)) &&
(x556<x216)) ==> \separated(x214+x555,x215+x556)))));
ensures ((inv_vec___Int_Int__(x214,x215,x216) &&
(\forall int  x572; (\forall int  x573; (((((0<=x572) &&
(x572<x216)) &&
(0<=x573)) &&
(x573<x216)) ==> \separated(x214+x572,x215+x573))))) &&
((\forall int  x587; (((0<=x587) &&
(x587<(x216-1))) ==> (x214[x587]<=x214[(x587+1)]))) &&
vec___Int_Int___Permut{Old,Post}(x214,x215,x216)));
assigns x214[(0..x216-1)], x215[(0..x216-1)];
*/
void insort_pairs(int  * x214, int  * x215, int  x216) {
  /*@assert (\forall int x219; (0<=x219<x216) ==> (\forall int x221; (0<=x221<x216) ==> (\forall int x223; (0<=x223<x216) ==> (((x214[x219]<=x214[x221]) &&
  (x214[x221]<=x214[x223])) ==> (x214[x219]<=x214[x223])))));*/
  /*@
  loop invariant (x370==0 && x368==-1) || (0<=x370<=x368);
  loop invariant (\forall int  x375; (((0<=x375) &&
  (x375<x370)) ==> (x214[x375]<=x214[(x375+1)])));
  loop invariant ((x370>0) ==> (\forall int  x389; (((x370<=x389) &&
  (x389<x216)) ==> (x214[(x370-1)]<=x214[x389]))));
  loop invariant vec___Int_Int___Permut{Pre,Here}(x214,x215,x216);
  loop invariant (\forall int  x405; (\forall int  x406; (((((0<=x405) &&
  (x405<x216)) &&
  (0<=x406)) &&
  (x406<x216)) ==> \separated(x214+x405,x215+x406))));
  loop invariant ((x216==0) || ((x216>0) &&
  (\valid(x214+(0..x216-1)) &&
  \valid(x215+(0..x216-1)))));
  loop assigns x370, x214[(0..x216-1)], x215[(0..x216-1)];
  loop variant x368-x370;
  */
  for(int x370=0; x370 < x368; x370++) {
    int x437 = x370;
    /*@
    loop invariant 0<=x440<=x216;
    loop invariant (\forall int  x441; (((x370<=x441) &&
    (x441<x440)) ==> (x214[x437]<=x214[x441])));
    loop invariant ((x370<=x437) &&
    (x437<x440));
    loop assigns x440, x437;
    loop variant x216-x440;
    */
    for(int x440=x438; x440 < x216; x440++) {
      int x459 = x214[x440];
      int x460 = x215[x440];
      int x461 = x437;
      int x462 = x214[x461];
      int x463 = x215[x461];
      int x464 = x459 <= x462;
      if (x464) {
        x437 = x440;
      } else {
        /*@assert (x214[x437]<=x214[x440]);*/
      }
    }
    /*@assert (x214[x437]<=x214[(x370+1)]);*/
    int x487 = x437;
    inswap___Int_Int__(x214,x215,x216,x370,x487);
    /*@assert (\forall int  x489; (((0<=x489) &&
    (x489<(x370-1))) ==> (x214[x489]<=x214[(x489+1)])));*/
    /*@assert (\forall int  x503; (((0<=x503) &&
    (x503<x370)) ==> (x214[x503]<=x214[(x503+1)])));*/
    /*@assert (x214[x370]<=x214[(x370+1)]);*/
    /*@assert (\forall int  x524; (((0<=x524) &&
    (x524<(x370+1))) ==> (x214[x524]<=x214[(x524+1)])));*/
    /*@assert (\forall int  x538; ((((x370+1)<=x538) &&
    (x538<x216)) ==> (x214[x370]<=x214[x538])));*/
  }
}
