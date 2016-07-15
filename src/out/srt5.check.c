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
inductive vec_vec_Int_Permut{L1,L2}(int  * * x61, int  * x62, integer  x63) {
  case vec_vec_Int_Permut_refl{L}:
  \forall int  * * x64, int  * x65, integer  x66; vec_vec_Int_Permut{L,L}(x64,x65,x66);
  case vec_vec_Int_Permut_sym{L1,L2}:
  \forall int  * * x70, int  * x71, integer  x72; (vec_vec_Int_Permut{L1,L2}(x70,x71,x72) ==> vec_vec_Int_Permut{L2,L1}(x70,x71,x72));
  case vec_vec_Int_Permut_trans{L1,L2,L3}:
  \forall int  * * x78, int  * x79, integer  x80; ((vec_vec_Int_Permut{L1,L2}(x78,x79,x80) &&
  vec_vec_Int_Permut{L2,L3}(x78,x79,x80)) ==> vec_vec_Int_Permut{L1,L3}(x78,x79,x80));
  case vec_vec_Int_Permut_step{L1,L2}:
  \forall int  * * x89, int  * x90, integer  x91; (\exists integer  x93; (\exists integer  x94; (((\at(eq_vec_Int(\at(x89[x93],L1),\at(x90[x93],L1),\at(x89[x94],L2),\at(x90[x94],L2)),L1) &&
  \at(eq_vec_Int(\at(x89[x93],L1),\at(x90[x93],L1),\at(x89[x94],L2),\at(x90[x94],L2)),L2)) &&
  (\at(eq_vec_Int(\at(x89[x94],L1),\at(x90[x94],L1),\at(x89[x93],L2),\at(x90[x93],L2)),L1) &&
  \at(eq_vec_Int(\at(x89[x94],L1),\at(x90[x94],L1),\at(x89[x93],L2),\at(x90[x93],L2)),L2))) &&
  (\forall integer  x141; (((((0<=x141) &&
  (x141<x91)) &&
  (x141!=x93)) &&
  (x141!=x94)) ==> (\at(eq_vec_Int(\at(x89[x141],L1),\at(x90[x141],L1),\at(x89[x141],L2),\at(x90[x141],L2)),L1) &&
  \at(eq_vec_Int(\at(x89[x141],L1),\at(x90[x141],L1),\at(x89[x141],L2),\at(x90[x141],L2)),L2)))))));
}
*/
/*@
requires ((inv_vec_vec_Int(x183,x184,x185) &&
((((0<=x186) &&
(x186<x185)) &&
(0<=x187)) &&
(x187<x185))) &&
(\forall int  x213; (\forall int  x214; (((((0<=x213) &&
(x213<x185)) &&
(0<=x214)) &&
(x214<x185)) ==> \separated(x183+x213,x184+x214)))));
ensures (((inv_vec_vec_Int(x183,x184,x185) &&
(((\at(eq_vec_Int(\at(x183[x186],Old),\at(x184[x186],Old),\at(x183[x187],Post),\at(x184[x187],Post)),Old) &&
\at(eq_vec_Int(\at(x183[x186],Old),\at(x184[x186],Old),\at(x183[x187],Post),\at(x184[x187],Post)),Post)) &&
(\at(eq_vec_Int(\at(x183[x187],Old),\at(x184[x187],Old),\at(x183[x186],Post),\at(x184[x186],Post)),Old) &&
\at(eq_vec_Int(\at(x183[x187],Old),\at(x184[x187],Old),\at(x183[x186],Post),\at(x184[x186],Post)),Post))) &&
(\forall int  x282; (((((0<=x282) &&
(x282<x185)) &&
(x282!=x186)) &&
(x282!=x187)) ==> (\at(eq_vec_Int(\at(x183[x282],Old),\at(x184[x282],Old),\at(x183[x282],Post),\at(x184[x282],Post)),Old) &&
\at(eq_vec_Int(\at(x183[x282],Old),\at(x184[x282],Old),\at(x183[x282],Post),\at(x184[x282],Post)),Post)))))) &&
vec_vec_Int_Permut{Old,Post}(x183,x184,x185)) &&
(\forall int  x323; (\forall int  x324; (((((0<=x323) &&
(x323<x185)) &&
(0<=x324)) &&
(x324<x185)) ==> \separated(x183+x323,x184+x324)))));
assigns x183[(0..x185-1)], x184[(0..x185-1)];
*/
void inswap_vec_Int(int  * * x183, int  * x184, int  x185, int  x186, int  x187) {
  int  *x190 = x183[x186];
  int x191 = x184[x186];
  int  *x192 = x183[x187];
  int x193 = x184[x187];
  x183[x186] = x192;
  x184[x186] = x193;
  x183[x187] = x190;
  x184[x187] = x191;
}
/*@
requires (inv_vec_vec_Int(x343,x344,x345) &&
(\forall int  x756; (\forall int  x757; (((((0<=x756) &&
(x756<x345)) &&
(0<=x757)) &&
(x757<x345)) ==> \separated(x343+x756,x344+x757)))));
ensures ((inv_vec_vec_Int(x343,x344,x345) &&
(\forall int  x777; (\forall int  x778; (((((0<=x777) &&
(x777<x345)) &&
(0<=x778)) &&
(x778<x345)) ==> \separated(x343+x777,x344+x778))))) &&
((\forall int  x797; (((0<=x797) &&
(x797<(x345-1))) ==> (x344[x797]<=x344[(x797+1)]))) &&
vec_vec_Int_Permut{Old,Post}(x343,x344,x345)));
assigns x343[(0..x345-1)], x344[(0..x345-1)];
*/
void insort_vecs(int  * * x343, int  * x344, int  x345) {
  /*@assert (\forall int x349; (0<=x349<x345) ==> (\forall int x352; (0<=x352<x345) ==> (\forall int x355; (0<=x355<x345) ==> (((x344[x349]<=x344[x352]) &&
  (x344[x352]<=x344[x355])) ==> (x344[x349]<=x344[x355])))));*/
  int x536 = x345 - 1;
  /*@
  loop invariant (x538==0 && x536==-1) || (0<=x538<=x536);
  loop invariant (\forall int  x544; (((0<=x544) &&
  (x544<x538)) ==> (x344[x544]<=x344[(x544+1)])));
  loop invariant ((x538>0) ==> (\forall int  x560; (((x538<=x560) &&
  (x560<x345)) ==> (x344[(x538-1)]<=x344[x560]))));
  loop invariant vec_vec_Int_Permut{Pre,Here}(x343,x344,x345);
  loop invariant (\forall int  x578; (\forall int  x579; (((((0<=x578) &&
  (x578<x345)) &&
  (0<=x579)) &&
  (x579<x345)) ==> \separated(x343+x578,x344+x579))));
  loop invariant (((x345==0) || ((x345>0) &&
  (\valid(x343+(0..x345-1)) &&
  \valid(x344+(0..x345-1))))) &&
  (\forall int x607; (0<=x607<x345) ==> inv_vec_Int(x343[x607],x344[x607])));
  loop assigns x538, x343[(0..x345-1)], x344[(0..x345-1)];
  loop variant x536-x538;
  */
  for(int x538=0; x538 < x536; x538++) {
    int x621 = x538;
    int x622 = x538 + 1;
    /*@
    loop invariant 0<=x624<=x345;
    loop invariant (\forall int  x625; (((x538<=x625) &&
    (x625<x624)) ==> (x344[x621]<=x344[x625])));
    loop invariant ((x538<=x621) &&
    (x621<x624));
    loop assigns x624, x621;
    loop variant x345-x624;
    */
    for(int x624=x622; x624 < x345; x624++) {
      int  *x647 = x343[x624];
      int x648 = x344[x624];
      int x649 = x621;
      int  *x650 = x343[x649];
      int x651 = x344[x649];
      int x652 = x648 <= x651;
      if (x652) {
        x621 = x624;
      } else {
        /*@assert (x344[x621]<=x344[x624]);*/
      }
    }
    /*@assert (x344[x621]<=x344[(x538+1)]);*/
    int x676 = x621;
    inswap_vec_Int(x343,x344,x345,x538,x676);
    /*@assert (\forall int  x679; (((0<=x679) &&
    (x679<(x538-1))) ==> (x344[x679]<=x344[(x679+1)])));*/
    /*@assert (\forall int  x695; (((0<=x695) &&
    (x695<x538)) ==> (x344[x695]<=x344[(x695+1)])));*/
    /*@assert (x344[x538]<=x344[(x538+1)]);*/
    /*@assert (\forall int  x720; (((0<=x720) &&
    (x720<(x538+1))) ==> (x344[x720]<=x344[(x720+1)])));*/
    /*@assert (\forall int  x737; ((((x538+1)<=x737) &&
    (x737<x345)) ==> (x344[x538]<=x344[x737])));*/
  }
}
