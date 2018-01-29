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
(\forall int  x895; (\forall int  x896; (((((0<=x895) &&
(x895<x313)) &&
(0<=x896)) &&
(x896<x313)) ==> \separated(x311+x895,x312+x896)))));
ensures ((inv_vec___Int_Int__(x311,x312,x313) &&
(\forall int  x916; (\forall int  x917; (((((0<=x916) &&
(x916<x313)) &&
(0<=x917)) &&
(x917<x313)) ==> \separated(x311+x916,x312+x917))))) &&
((\forall int  x936; (((0<=x936) &&
(x936<(x313-1))) ==> ((x311[x936]<x311[(x936+1)]) || ((x311[x936]==x311[(x936+1)]) &&
(x312[x936]<=x312[(x936+1)]))))) &&
vec___Int_Int___Permut{Old,Post}(x311,x312,x313)));
assigns x311[(0..x313-1)], x312[(0..x313-1)];
*/
void insort_pairs(int  * x311, int  * x312, int  x313) {
  /*@assert (\forall int x317; (0<=x317<x313) ==> (\forall int x320; (0<=x320<x313) ==> (\forall int x323; (0<=x323<x313) ==> ((((x311[x317]<x311[x320]) || ((x311[x317]==x311[x320]) &&
  (x312[x317]<=x312[x320]))) &&
  ((x311[x320]<x311[x323]) || ((x311[x320]==x311[x323]) &&
  (x312[x320]<=x312[x323])))) ==> ((x311[x317]<x311[x323]) || ((x311[x317]==x311[x323]) &&
  (x312[x317]<=x312[x323])))))));*/
  int x624 = x313 - 1;
  /*@
  loop invariant (x626==0 && x624==-1) || (0<=x626<=x624);
  loop invariant (\forall int  x632; (((0<=x632) &&
  (x632<x626)) ==> ((x311[x632]<x311[(x632+1)]) || ((x311[x632]==x311[(x632+1)]) &&
  (x312[x632]<=x312[(x632+1)])))));
  loop invariant ((x626>0) ==> (\forall int  x653; (((x626<=x653) &&
  (x653<x313)) ==> ((x311[(x626-1)]<x311[x653]) || ((x311[(x626-1)]==x311[x653]) &&
  (x312[(x626-1)]<=x312[x653]))))));
  loop invariant vec___Int_Int___Permut{Pre,Here}(x311,x312,x313);
  loop invariant (\forall int  x676; (\forall int  x677; (((((0<=x676) &&
  (x676<x313)) &&
  (0<=x677)) &&
  (x677<x313)) ==> \separated(x311+x676,x312+x677))));
  loop invariant ((x313==0) || ((x313>0) &&
  (\valid(x311+(0..x313-1)) &&
  \valid(x312+(0..x313-1)))));
  loop assigns x626, x311[(0..x313-1)], x312[(0..x313-1)];
  loop variant x624-x626;
  */
  for(int x626=0; x626 < x624; x626++) {
    int x716 = x626;
    int x717 = x626 + 1;
    /*@
    loop invariant 0<=x719<=x313;
    loop invariant (\forall int  x720; (((x626<=x720) &&
    (x720<x719)) ==> ((x311[x716]<x311[x720]) || ((x311[x716]==x311[x720]) &&
    (x312[x716]<=x312[x720])))));
    loop invariant ((x626<=x716) &&
    (x716<x719));
    loop assigns x719, x716;
    loop variant x313-x719;
    */
    for(int x719=x717; x719 < x313; x719++) {
      int x747 = x311[x719];
      int x748 = x312[x719];
      int x749 = x716;
      int x750 = x311[x749];
      int x751 = x312[x749];
      int x752 = x747 < x750;
      int x753 = x747 == x750;
      int x755;
      if (x753) {
        int x754 = x748 <= x751;
        x755 = x754;
      } else {
        x755 = 0/*false*/;
      }
      int x756 = x752 || x755;
      if (x756) {
        x716 = x719;
      } else {
        /*@assert ((x311[x716]<x311[x719]) || ((x311[x716]==x311[x719]) &&
        (x312[x716]<=x312[x719])));*/
      }
    }
    /*@assert ((x311[x716]<x311[(x626+1)]) || ((x311[x716]==x311[(x626+1)]) &&
    (x312[x716]<=x312[(x626+1)])));*/
    int x790 = x716;
    inswap___Int_Int__(x311,x312,x313,x626,x790);
    /*@assert (\forall int  x793; (((0<=x793) &&
    (x793<(x626-1))) ==> ((x311[x793]<x311[(x793+1)]) || ((x311[x793]==x311[(x793+1)]) &&
    (x312[x793]<=x312[(x793+1)])))));*/
    /*@assert (\forall int  x814; (((0<=x814) &&
    (x814<x626)) ==> ((x311[x814]<x311[(x814+1)]) || ((x311[x814]==x311[(x814+1)]) &&
    (x312[x814]<=x312[(x814+1)])))));*/
    /*@assert ((x311[x626]<x311[(x626+1)]) || ((x311[x626]==x311[(x626+1)]) &&
    (x312[x626]<=x312[(x626+1)])));*/
    /*@assert (\forall int  x849; (((0<=x849) &&
    (x849<(x626+1))) ==> ((x311[x849]<x311[(x849+1)]) || ((x311[x849]==x311[(x849+1)]) &&
    (x312[x849]<=x312[(x849+1)])))));*/
    /*@assert (\forall int  x871; ((((x626+1)<=x871) &&
    (x871<x313)) ==> ((x311[x626]<x311[x871]) || ((x311[x626]==x311[x871]) &&
    (x312[x626]<=x312[x871])))));*/
  }
}
