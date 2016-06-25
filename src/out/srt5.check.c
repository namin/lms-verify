#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, int  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@ predicate eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) = ((x17==x19) &&
(\forall int x23; (0<=x23<x17) ==> (x16[x23]==x18[x23])));*/
/*@
requires (inv_vec_Int(x16,x17) &&
inv_vec_Int(x18,x19));
assigns \nothing;
ensures (inv_vec_Int(x16,x17) &&
inv_vec_Int(x18,x19));
ensures \result <==> eq_vec_Int(x16, x17, x18, x19);
*/
int eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) {
  int x21 = x17 == x19;
  int x33;
  if (x21) {
    int x32 = 1;
    /*@ loop invariant (0 <= x24 <= x17);
    loop invariant \forall int x23; (0 <= x23 < x24) ==>  (x16[x23]==x18[x23]);
    loop assigns x24;
    loop variant (x17-x24); */
    for (int x24 = 0; x24 < x17; x24++) {
      int x29 = x16[x24];
      int x30 = x18[x24];
      int x31 = x29 == x30;
      if (!x31) { x32 = 0; break; }
    }
    x33 = x32;
  } else {
    x33 = 0/*false*/;
  }
  return x33;
}
/*@ predicate inv_vec_vec_Int(int  * * x37, int  * x38, int  x39) = (((x39==0) || ((x39>0) &&
(\valid(x37+(0..x39-1)) &&
\valid(x38+(0..x39-1))))) &&
(\forall int x49; (0<=x49<x39) ==> inv_vec_Int(x37[x49],x38[x49])));*/
/*@
inductive vec_Int_Permut{L1,L2}(int  * * x61, int  * x62, integer  x63) {
  case vec_Int_Permut_refl{L}:
  \forall int  * * x64, int  * x65, integer  x66; vec_Int_Permut{L,L}(x64,x65,x66);
  case vec_Int_Permut_sym{L1,L2}:
  \forall int  * * x70, int  * x71, integer  x72; (vec_Int_Permut{L1,L2}(x70,x71,x72) ==> vec_Int_Permut{L2,L1}(x70,x71,x72));
  case vec_Int_Permut_trans{L1,L2,L3}:
  \forall int  * * x78, int  * x79, integer  x80; ((vec_Int_Permut{L1,L2}(x78,x79,x80) &&
  vec_Int_Permut{L2,L3}(x78,x79,x80)) ==> vec_Int_Permut{L1,L3}(x78,x79,x80));
  case vec_Int_Permut_swap{L1,L2}:
  \forall int  * * x89, int  * x90, integer  x91; (\forall integer  x93; (\forall integer  x94; ((((((0<=x93) &&
  (x93<x91)) &&
  (0<=x94)) &&
  (x94<x91)) &&
  (((\at(eq_vec_Int(\at(x89[x93],L1),\at(x90[x93],L1),\at(x89[x94],L2),\at(x90[x94],L2)),L1) &&
  \at(eq_vec_Int(\at(x89[x93],L1),\at(x90[x93],L1),\at(x89[x94],L2),\at(x90[x94],L2)),L2)) &&
  (\at(eq_vec_Int(\at(x89[x94],L1),\at(x90[x94],L1),\at(x89[x93],L2),\at(x90[x93],L2)),L1) &&
  \at(eq_vec_Int(\at(x89[x94],L1),\at(x90[x94],L1),\at(x89[x93],L2),\at(x90[x93],L2)),L2))) &&
  (\forall integer  x151; (((((0<=x151) &&
  (x151<x91)) &&
  (x151!=x93)) &&
  (x151!=x94)) ==> (\at(eq_vec_Int(\at(x89[x151],L1),\at(x90[x151],L1),\at(x89[x151],L2),\at(x90[x151],L2)),L1) &&
  \at(eq_vec_Int(\at(x89[x151],L1),\at(x90[x151],L1),\at(x89[x151],L2),\at(x90[x151],L2)),L2)))))) ==> vec_Int_Permut{L1,L2}(x89,x90,x91))));
}
*/
/*@
requires ((inv_vec_vec_Int(x197,x198,x199) &&
((((0<=x200) &&
(x200<x199)) &&
(0<=x201)) &&
(x201<x199))) &&
(\forall int  x227; (\forall int  x228; (((((0<=x227) &&
(x227<x199)) &&
(0<=x228)) &&
(x228<x199)) ==> \separated(x197+x227,x198+x228)))));
ensures (((inv_vec_vec_Int(x197,x198,x199) &&
(((\at(eq_vec_Int(\at(x197[x200],Old),\at(x198[x200],Old),\at(x197[x201],Post),\at(x198[x201],Post)),Old) &&
\at(eq_vec_Int(\at(x197[x200],Old),\at(x198[x200],Old),\at(x197[x201],Post),\at(x198[x201],Post)),Post)) &&
(\at(eq_vec_Int(\at(x197[x201],Old),\at(x198[x201],Old),\at(x197[x200],Post),\at(x198[x200],Post)),Old) &&
\at(eq_vec_Int(\at(x197[x201],Old),\at(x198[x201],Old),\at(x197[x200],Post),\at(x198[x200],Post)),Post))) &&
(\forall int  x296; (((((0<=x296) &&
(x296<x199)) &&
(x296!=x200)) &&
(x296!=x201)) ==> (\at(eq_vec_Int(\at(x197[x296],Old),\at(x198[x296],Old),\at(x197[x296],Post),\at(x198[x296],Post)),Old) &&
\at(eq_vec_Int(\at(x197[x296],Old),\at(x198[x296],Old),\at(x197[x296],Post),\at(x198[x296],Post)),Post)))))) &&
vec_Int_Permut{Old,Post}(x197,x198,x199)) &&
(\forall int  x337; (\forall int  x338; (((((0<=x337) &&
(x337<x199)) &&
(0<=x338)) &&
(x338<x199)) ==> \separated(x197+x337,x198+x338)))));
assigns x197[(0..x199-1)], x198[(0..x199-1)];
*/
void inswap_vec_Int(int  * * x197, int  * x198, int  x199, int  x200, int  x201) {
  int  *x204 = x197[x200];
  int x205 = x198[x200];
  int  *x206 = x197[x201];
  int x207 = x198[x201];
  x197[x200] = x206;
  x198[x200] = x207;
  x197[x201] = x204;
  x198[x201] = x205;
}
/*@
requires (inv_vec_vec_Int(x357,x358,x359) &&
(\forall int  x770; (\forall int  x771; (((((0<=x770) &&
(x770<x359)) &&
(0<=x771)) &&
(x771<x359)) ==> \separated(x357+x770,x358+x771)))));
ensures ((inv_vec_vec_Int(x357,x358,x359) &&
(\forall int  x791; (\forall int  x792; (((((0<=x791) &&
(x791<x359)) &&
(0<=x792)) &&
(x792<x359)) ==> \separated(x357+x791,x358+x792))))) &&
((\forall int  x811; (((0<=x811) &&
(x811<(x359-1))) ==> (x358[x811]<=x358[(x811+1)]))) &&
vec_Int_Permut{Old,Post}(x357,x358,x359)));
assigns x357[(0..x359-1)], x358[(0..x359-1)];
*/
void insort_vecs(int  * * x357, int  * x358, int  x359) {
  /*@assert (\forall int x363; (0<=x363<x359) ==> (\forall int x366; (0<=x366<x359) ==> (\forall int x369; (0<=x369<x359) ==> (((x358[x363]<=x358[x366]) &&
  (x358[x366]<=x358[x369])) ==> (x358[x363]<=x358[x369])))));*/
  int x550 = x359 - 1;
  /*@
  loop invariant (x552==0 && x550==-1) || (0<=x552<=x550);
  loop invariant (\forall int  x558; (((0<=x558) &&
  (x558<x552)) ==> (x358[x558]<=x358[(x558+1)])));
  loop invariant ((x552>0) ==> (\forall int  x574; (((x552<=x574) &&
  (x574<x359)) ==> (x358[(x552-1)]<=x358[x574]))));
  loop invariant vec_Int_Permut{Pre,Here}(x357,x358,x359);
  loop invariant (\forall int  x592; (\forall int  x593; (((((0<=x592) &&
  (x592<x359)) &&
  (0<=x593)) &&
  (x593<x359)) ==> \separated(x357+x592,x358+x593))));
  loop invariant (((x359==0) || ((x359>0) &&
  (\valid(x357+(0..x359-1)) &&
  \valid(x358+(0..x359-1))))) &&
  (\forall int x621; (0<=x621<x359) ==> inv_vec_Int(x357[x621],x358[x621])));
  loop assigns x552, x357[(0..x359-1)], x358[(0..x359-1)];
  loop variant x550-x552;
  */
  for(int x552=0; x552 < x550; x552++) {
    int x635 = x552;
    int x636 = x552 + 1;
    /*@
    loop invariant 0<=x638<=x359;
    loop invariant (\forall int  x639; (((x552<=x639) &&
    (x639<x638)) ==> (x358[x635]<=x358[x639])));
    loop invariant ((x552<=x635) &&
    (x635<x638));
    loop assigns x638, x635;
    loop variant x359-x638;
    */
    for(int x638=x636; x638 < x359; x638++) {
      int  *x661 = x357[x638];
      int x662 = x358[x638];
      int x663 = x635;
      int  *x664 = x357[x663];
      int x665 = x358[x663];
      int x666 = x662 <= x665;
      if (x666) {
        x635 = x638;
      } else {
        /*@assert (x358[x635]<=x358[x638]);*/
      }
    }
    /*@assert (x358[x635]<=x358[(x552+1)]);*/
    int x690 = x635;
    inswap_vec_Int(x357,x358,x359,x552,x690);
    /*@assert (\forall int  x693; (((0<=x693) &&
    (x693<(x552-1))) ==> (x358[x693]<=x358[(x693+1)])));*/
    /*@assert (\forall int  x709; (((0<=x709) &&
    (x709<x552)) ==> (x358[x709]<=x358[(x709+1)])));*/
    /*@assert (x358[x552]<=x358[(x552+1)]);*/
    /*@assert (\forall int  x734; (((0<=x734) &&
    (x734<(x552+1))) ==> (x358[x734]<=x358[(x734+1)])));*/
    /*@assert (\forall int  x751; ((((x552+1)<=x751) &&
    (x751<x359)) ==> (x358[x552]<=x358[x751])));*/
  }
}
