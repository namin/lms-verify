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
/*@ predicate inv_vec___Int_Int__(int  * x8, int  * x9, int  x10) = ((x10==0) || ((x10>0) &&
(\valid(x8+(0..x10-1)) &&
\valid(x9+(0..x10-1)))));*/
/*@
inductive vec___Int_Int___Permut{L1,L2}(int  * x29, int  * x30, integer  x31) {
  case vec___Int_Int___Permut_refl{L}:
  \forall int  * x32, int  * x33, integer  x34; vec___Int_Int___Permut{L,L}(x32,x33,x34);
  case vec___Int_Int___Permut_sym{L1,L2}:
  \forall int  * x38, int  * x39, integer  x40; (vec___Int_Int___Permut{L1,L2}(x38,x39,x40) ==> vec___Int_Int___Permut{L2,L1}(x38,x39,x40));
  case vec___Int_Int___Permut_trans{L1,L2,L3}:
  \forall int  * x46, int  * x47, integer  x48; ((vec___Int_Int___Permut{L1,L2}(x46,x47,x48) &&
  vec___Int_Int___Permut{L2,L3}(x46,x47,x48)) ==> vec___Int_Int___Permut{L1,L3}(x46,x47,x48));
  case vec___Int_Int___Permut_step{L1,L2}:
  \forall int  * x57, int  * x58, integer  x59; (\exists integer  x61; (\exists integer  x62; (((\at(eq___Int_Int__(\at(x57[x61],L1),\at(x58[x61],L1),\at(x57[x62],L2),\at(x58[x62],L2)),L1) &&
  \at(eq___Int_Int__(\at(x57[x61],L1),\at(x58[x61],L1),\at(x57[x62],L2),\at(x58[x62],L2)),L2)) &&
  (\at(eq___Int_Int__(\at(x57[x62],L1),\at(x58[x62],L1),\at(x57[x61],L2),\at(x58[x61],L2)),L1) &&
  \at(eq___Int_Int__(\at(x57[x62],L1),\at(x58[x62],L1),\at(x57[x61],L2),\at(x58[x61],L2)),L2))) &&
  (\forall integer  x109; (((((0<=x109) &&
  (x109<x59)) &&
  (x109!=x61)) &&
  (x109!=x62)) ==> (\at(eq___Int_Int__(\at(x57[x109],L1),\at(x58[x109],L1),\at(x57[x109],L2),\at(x58[x109],L2)),L1) &&
  \at(eq___Int_Int__(\at(x57[x109],L1),\at(x58[x109],L1),\at(x57[x109],L2),\at(x58[x109],L2)),L2)))))));
}
*/
/*@
requires ((inv_vec___Int_Int__(x151,x152,x153) &&
((((0<=x154) &&
(x154<x153)) &&
(0<=x155)) &&
(x155<x153))) &&
(\forall int  x181; (\forall int  x182; (((((0<=x181) &&
(x181<x153)) &&
(0<=x182)) &&
(x182<x153)) ==> \separated(x151+x181,x152+x182)))));
ensures (((inv_vec___Int_Int__(x151,x152,x153) &&
(((\at(eq___Int_Int__(\at(x151[x154],Old),\at(x152[x154],Old),\at(x151[x155],Post),\at(x152[x155],Post)),Old) &&
\at(eq___Int_Int__(\at(x151[x154],Old),\at(x152[x154],Old),\at(x151[x155],Post),\at(x152[x155],Post)),Post)) &&
(\at(eq___Int_Int__(\at(x151[x155],Old),\at(x152[x155],Old),\at(x151[x154],Post),\at(x152[x154],Post)),Old) &&
\at(eq___Int_Int__(\at(x151[x155],Old),\at(x152[x155],Old),\at(x151[x154],Post),\at(x152[x154],Post)),Post))) &&
(\forall int  x250; (((((0<=x250) &&
(x250<x153)) &&
(x250!=x154)) &&
(x250!=x155)) ==> (\at(eq___Int_Int__(\at(x151[x250],Old),\at(x152[x250],Old),\at(x151[x250],Post),\at(x152[x250],Post)),Old) &&
\at(eq___Int_Int__(\at(x151[x250],Old),\at(x152[x250],Old),\at(x151[x250],Post),\at(x152[x250],Post)),Post)))))) &&
vec___Int_Int___Permut{Old,Post}(x151,x152,x153)) &&
(\forall int  x291; (\forall int  x292; (((((0<=x291) &&
(x291<x153)) &&
(0<=x292)) &&
(x292<x153)) ==> \separated(x151+x291,x152+x292)))));
assigns x151[(0..x153-1)], x152[(0..x153-1)];
*/
void inswap___Int_Int__(int  * x151, int  * x152, int  x153, int  x154, int  x155) {
  int x158 = x151[x154];
  int x159 = x152[x154];
  int x160 = x151[x155];
  int x161 = x152[x155];
  x151[x154] = x160;
  x152[x154] = x161;
  x151[x155] = x158;
  x152[x155] = x159;
}
/*@
requires (inv_vec___Int_Int__(x311,x312,x313) &&
(\forall int  x721; (\forall int  x722; (((((0<=x721) &&
(x721<x313)) &&
(0<=x722)) &&
(x722<x313)) ==> \separated(x311+x721,x312+x722)))));
ensures ((inv_vec___Int_Int__(x311,x312,x313) &&
(\forall int  x742; (\forall int  x743; (((((0<=x742) &&
(x742<x313)) &&
(0<=x743)) &&
(x743<x313)) ==> \separated(x311+x742,x312+x743))))) &&
((\forall int  x762; (((0<=x762) &&
(x762<(x313-1))) ==> (x311[x762]<=x311[(x762+1)]))) &&
vec___Int_Int___Permut{Old,Post}(x311,x312,x313)));
assigns x311[(0..x313-1)], x312[(0..x313-1)];
*/
void insort_pairs(int  * x311, int  * x312, int  x313) {
  /*@assert (\forall int x317; (0<=x317<x313) ==> (\forall int x320; (0<=x320<x313) ==> (\forall int x323; (0<=x323<x313) ==> (((x311[x317]<=x311[x320]) &&
  (x311[x320]<=x311[x323])) ==> (x311[x317]<=x311[x323])))));*/
  int x504 = x313 - 1;
  /*@
  loop invariant (x506==0 && x504==-1) || (0<=x506<=x504);
  loop invariant (\forall int  x512; (((0<=x512) &&
  (x512<x506)) ==> (x311[x512]<=x311[(x512+1)])));
  loop invariant ((x506>0) ==> (\forall int  x528; (((x506<=x528) &&
  (x528<x313)) ==> (x311[(x506-1)]<=x311[x528]))));
  loop invariant vec___Int_Int___Permut{Pre,Here}(x311,x312,x313);
  loop invariant (\forall int  x546; (\forall int  x547; (((((0<=x546) &&
  (x546<x313)) &&
  (0<=x547)) &&
  (x547<x313)) ==> \separated(x311+x546,x312+x547))));
  loop invariant ((x313==0) || ((x313>0) &&
  (\valid(x311+(0..x313-1)) &&
  \valid(x312+(0..x313-1)))));
  loop assigns x506, x311[(0..x313-1)], x312[(0..x313-1)];
  loop variant x504-x506;
  */
  for(int x506=0; x506 < x504; x506++) {
    int x586 = x506;
    int x587 = x506 + 1;
    /*@
    loop invariant 0<=x589<=x313;
    loop invariant (\forall int  x590; (((x506<=x590) &&
    (x590<x589)) ==> (x311[x586]<=x311[x590])));
    loop invariant ((x506<=x586) &&
    (x586<x589));
    loop assigns x589, x586;
    loop variant x313-x589;
    */
    for(int x589=x587; x589 < x313; x589++) {
      int x612 = x311[x589];
      int x613 = x312[x589];
      int x614 = x586;
      int x615 = x311[x614];
      int x616 = x312[x614];
      int x617 = x612 <= x615;
      if (x617) {
        x586 = x589;
      } else {
        /*@assert (x311[x586]<=x311[x589]);*/
      }
    }
    /*@assert (x311[x586]<=x311[(x506+1)]);*/
    int x641 = x586;
    inswap___Int_Int__(x311,x312,x313,x506,x641);
    /*@assert (\forall int  x644; (((0<=x644) &&
    (x644<(x506-1))) ==> (x311[x644]<=x311[(x644+1)])));*/
    /*@assert (\forall int  x660; (((0<=x660) &&
    (x660<x506)) ==> (x311[x660]<=x311[(x660+1)])));*/
    /*@assert (x311[x506]<=x311[(x506+1)]);*/
    /*@assert (\forall int  x685; (((0<=x685) &&
    (x685<(x506+1))) ==> (x311[x685]<=x311[(x685+1)])));*/
    /*@assert (\forall int  x702; ((((x506+1)<=x702) &&
    (x702<x313)) ==> (x311[x506]<=x311[x702])));*/
  }
}
