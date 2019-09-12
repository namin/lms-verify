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
(\forall int  x695; (\forall int  x696; (((((0<=x695) &&
(x695<x216)) &&
(0<=x696)) &&
(x696<x216)) ==> \separated(x214+x695,x215+x696)))));
ensures ((inv_vec___Int_Int__(x214,x215,x216) &&
(\forall int  x712; (\forall int  x713; (((((0<=x712) &&
(x712<x216)) &&
(0<=x713)) &&
(x713<x216)) ==> \separated(x214+x712,x215+x713))))) &&
((\forall int  x727; (((0<=x727) &&
(x727<(x216-1))) ==> ((x214[x727]<x214[(x727+1)]) || ((x214[x727]==x214[(x727+1)]) &&
(x215[x727]<=x215[(x727+1)]))))) &&
vec___Int_Int___Permut{Old,Post}(x214,x215,x216)));
assigns x214[(0..x216-1)], x215[(0..x216-1)];
*/
void insort_pairs(int  * x214, int  * x215, int  x216) {
  /*@assert (\forall int x219; (0<=x219<x216) ==> (\forall int x221; (0<=x221<x216) ==> (\forall int x223; (0<=x223<x216) ==> ((((x214[x219]<x214[x221]) || ((x214[x219]==x214[x221]) &&
  (x215[x219]<=x215[x221]))) &&
  ((x214[x221]<x214[x223]) || ((x214[x221]==x214[x223]) &&
  (x215[x221]<=x215[x223])))) ==> ((x214[x219]<x214[x223]) || ((x214[x219]==x214[x223]) &&
  (x215[x219]<=x215[x223])))))));*/
  /*@
  loop invariant (x466==0 && x464==-1) || (0<=x466<=x464);
  loop invariant (\forall int  x471; (((0<=x471) &&
  (x471<x466)) ==> ((x214[x471]<x214[(x471+1)]) || ((x214[x471]==x214[(x471+1)]) &&
  (x215[x471]<=x215[(x471+1)])))));
  loop invariant ((x466>0) ==> (\forall int  x489; (((x466<=x489) &&
  (x489<x216)) ==> ((x214[(x466-1)]<x214[x489]) || ((x214[(x466-1)]==x214[x489]) &&
  (x215[(x466-1)]<=x215[x489]))))));
  loop invariant vec___Int_Int___Permut{Pre,Here}(x214,x215,x216);
  loop invariant (\forall int  x509; (\forall int  x510; (((((0<=x509) &&
  (x509<x216)) &&
  (0<=x510)) &&
  (x510<x216)) ==> \separated(x214+x509,x215+x510))));
  loop invariant ((x216==0) || ((x216>0) &&
  (\valid(x214+(0..x216-1)) &&
  \valid(x215+(0..x216-1)))));
  loop assigns x466, x214[(0..x216-1)], x215[(0..x216-1)];
  loop variant x464-x466;
  */
  for(int x466=0; x466 < x464; x466++) {
    int x541 = x466;
    /*@
    loop invariant 0<=x544<=x216;
    loop invariant (\forall int  x545; (((x466<=x545) &&
    (x545<x544)) ==> ((x214[x541]<x214[x545]) || ((x214[x541]==x214[x545]) &&
    (x215[x541]<=x215[x545])))));
    loop invariant ((x466<=x541) &&
    (x541<x544));
    loop assigns x544, x541;
    loop variant x216-x544;
    */
    for(int x544=x542; x544 < x216; x544++) {
      int x567 = x214[x544];
      int x568 = x215[x544];
      int x569 = x541;
      int x570 = x214[x569];
      int x571 = x215[x569];
      int x572 = x567 < x570;
      int x573 = x567 == x570;
      int x575;
      if (x573) {
        int x574 = x568 <= x571;
        x575 = x574;
      } else {
        x575 = 0/*false*/;
      }
      int x576 = x572 || x575;
      if (x576) {
        x541 = x544;
      } else {
        /*@assert ((x214[x541]<x214[x544]) || ((x214[x541]==x214[x544]) &&
        (x215[x541]<=x215[x544])));*/
      }
    }
    /*@assert ((x214[x541]<x214[(x466+1)]) || ((x214[x541]==x214[(x466+1)]) &&
    (x215[x541]<=x215[(x466+1)])));*/
    int x607 = x541;
    inswap___Int_Int__(x214,x215,x216,x466,x607);
    /*@assert (\forall int  x609; (((0<=x609) &&
    (x609<(x466-1))) ==> ((x214[x609]<x214[(x609+1)]) || ((x214[x609]==x214[(x609+1)]) &&
    (x215[x609]<=x215[(x609+1)])))));*/
    /*@assert (\forall int  x627; (((0<=x627) &&
    (x627<x466)) ==> ((x214[x627]<x214[(x627+1)]) || ((x214[x627]==x214[(x627+1)]) &&
    (x215[x627]<=x215[(x627+1)])))));*/
    /*@assert ((x214[x466]<x214[(x466+1)]) || ((x214[x466]==x214[(x466+1)]) &&
    (x215[x466]<=x215[(x466+1)])));*/
    /*@assert (\forall int  x656; (((0<=x656) &&
    (x656<(x466+1))) ==> ((x214[x656]<x214[(x656+1)]) || ((x214[x656]==x214[(x656+1)]) &&
    (x215[x656]<=x215[(x656+1)])))));*/
    /*@assert (\forall int  x674; ((((x466+1)<=x674) &&
    (x674<x216)) ==> ((x214[x466]<x214[x674]) || ((x214[x466]==x214[x674]) &&
    (x215[x466]<=x215[x674])))));*/
  }
}
