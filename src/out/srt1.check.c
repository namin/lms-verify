#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, integer  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@
inductive vec_Int_Permut{L1,L2}(int  * x15, integer  x16) {
  case vec_Int_Permut_refl{L}:
  \forall int  * x17, integer  x18; vec_Int_Permut{L,L}(x17,x18);
  case vec_Int_Permut_sym{L1,L2}:
  \forall int  * x22, integer  x23; (vec_Int_Permut{L1,L2}(x22,x23) ==> vec_Int_Permut{L2,L1}(x22,x23));
  case vec_Int_Permut_trans{L1,L2,L3}:
  \forall int  * x29, integer  x30; ((vec_Int_Permut{L1,L2}(x29,x30) &&
  vec_Int_Permut{L2,L3}(x29,x30)) ==> vec_Int_Permut{L1,L3}(x29,x30));
  case vec_Int_Permut_step{L1,L2}:
  \forall int  * x39, integer  x40; (\exists integer  x42; (\exists integer  x43; (((\at((\at(x39[x42],L1)==\at(x39[x43],L2)),L1) &&
  \at((\at(x39[x42],L1)==\at(x39[x43],L2)),L2)) &&
  (\at((\at(x39[x43],L1)==\at(x39[x42],L2)),L1) &&
  \at((\at(x39[x43],L1)==\at(x39[x42],L2)),L2))) &&
  (\forall integer  x59; (((((0<=x59) &&
  (x59<x40)) &&
  (x59!=x42)) &&
  (x59!=x43)) ==> (\at((\at(x39[x59],L1)==\at(x39[x59],L2)),L1) &&
  \at((\at(x39[x59],L1)==\at(x39[x59],L2)),L2)))))));
}
*/
/*@
requires (inv_vec_Int(x79,x80) &&
((((0<=x81) &&
(x81<x80)) &&
(0<=x82)) &&
(x82<x80)));
ensures ((inv_vec_Int(x79,x80) &&
(((\at((\at(x79[x81],Old)==\at(x79[x82],Post)),Old) &&
\at((\at(x79[x81],Old)==\at(x79[x82],Post)),Post)) &&
(\at((\at(x79[x82],Old)==\at(x79[x81],Post)),Old) &&
\at((\at(x79[x82],Old)==\at(x79[x81],Post)),Post))) &&
(\forall int  x120; (((((0<=x120) &&
(x120<x80)) &&
(x120!=x81)) &&
(x120!=x82)) ==> (\at((\at(x79[x120],Old)==\at(x79[x120],Post)),Old) &&
\at((\at(x79[x120],Old)==\at(x79[x120],Post)),Post)))))) &&
vec_Int_Permut{Old,Post}(x79,x80));
assigns x79[(0..x80-1)];
*/
void inswap_Int(int  * x79, int  x80, int  x81, int  x82) {
  int x85 = x79[x81];
  int x86 = x79[x82];
  x79[x81] = x86;
  x79[x82] = x85;
}
/*@
requires inv_vec_Int(x143,x144);
ensures (inv_vec_Int(x143,x144) &&
((\forall int  x412; (((0<=x412) &&
(x412<(x144-1))) ==> (x143[x412]<=x143[(x412+1)]))) &&
vec_Int_Permut{Old,Post}(x143,x144)));
assigns x143[(0..x144-1)];
*/
void insort(int  * x143, int  x144) {
  /*@assert (\forall int x147; (0<=x147<x144) ==> (\forall int x149; (0<=x149<x144) ==> (\forall int x151; (0<=x151<x144) ==> (((x143[x147]<=x143[x149]) &&
  (x143[x149]<=x143[x151])) ==> (x143[x147]<=x143[x151])))));*/
  int x264 = x144 - 1;
  /*@
  loop invariant (x266==0 && x264==-1) || (0<=x266<=x264);
  loop invariant (\forall int  x270; (((0<=x270) &&
  (x270<x266)) ==> (x143[x270]<=x143[(x270+1)])));
  loop invariant ((x266>0) ==> (\forall int  x282; (((x266<=x282) &&
  (x282<x144)) ==> (x143[(x266-1)]<=x143[x282]))));
  loop invariant vec_Int_Permut{Pre,Here}(x143,x144);
  loop invariant ((x144==0) || ((x144>0) &&
  \valid(x143+(0..x144-1))));
  loop assigns x266, x143[(0..x144-1)];
  loop variant x264-x266;
  */
  for(int x266=0; x266 < x264; x266++) {
    int x310 = x266;
    int x311 = x266 + 1;
    /*@
    loop invariant 0<=x313<=x144;
    loop invariant (\forall int  x314; (((x266<=x314) &&
    (x314<x313)) ==> (x143[x310]<=x143[x314])));
    loop invariant ((x266<=x310) &&
    (x310<x313));
    loop assigns x313, x310;
    loop variant x144-x313;
    */
    for(int x313=x311; x313 < x144; x313++) {
      int x330 = x143[x313];
      int x331 = x310;
      int x332 = x143[x331];
      int x333 = x330 <= x332;
      if (x333) {
        x310 = x313;
      } else {
        /*@assert (x143[x310]<=x143[x313]);*/
      }
    }
    /*@assert (x143[x310]<=x143[x311]);*/
    int x352 = x310;
    inswap_Int(x143,x144,x266,x352);
    /*@assert (\forall int  x354; (((0<=x354) &&
    (x354<(x266-1))) ==> (x143[x354]<=x143[(x354+1)])));*/
    /*@assert (\forall int  x366; (((0<=x366) &&
    (x366<x266)) ==> (x143[x366]<=x143[(x366+1)])));*/
    /*@assert (x143[x266]<=x143[x311]);*/
    /*@assert (\forall int  x383; (((0<=x383) &&
    (x383<x311)) ==> (x143[x383]<=x143[(x383+1)])));*/
    /*@assert (\forall int  x395; (((x311<=x395) &&
    (x395<x144)) ==> (x143[x266]<=x143[x395])));*/
  }
}
