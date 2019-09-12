#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, integer  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@ predicate eq_vec_Int(int  * x15, int  x16, int  * x17, int  x18) = ((x16==x18) &&
(\forall int x22; (0<=x22<x16) ==> (x15[x22]==x17[x22])));*/
/*@
requires (inv_vec_Int(x15,x16) &&
inv_vec_Int(x17,x18));
assigns \nothing;
ensures (inv_vec_Int(x15,x16) &&
inv_vec_Int(x17,x18));
ensures \result <==> eq_vec_Int(x15, x16, x17, x18);
*/
int eq_vec_Int(int  * x15, int  x16, int  * x17, int  x18) {
  int x20 = x16 == x18;
  int x31;
  if (x20) {
    int x30 = 1;
    /*@ loop invariant (0 <= x23 <= x16);
    loop invariant \forall int x22; (0 <= x22 < x23) ==> (x15[x22]==x17[x22]);
    loop invariant x30==1;
    loop assigns x23, x30;
    loop variant (x16-x23); */
    for (int x23 = 0; x23 < x16; x23++) {
      int x27 = x15[x23];
      int x28 = x17[x23];
      int x29 = x27 == x28;
      if (!x29) { x30 = 0; break; }
    }
    x31 = x30;
  } else {
    x31 = 0/*false*/;
  }
  return x31;
}
/*@ predicate inv_vec_vec_Int(int  * * x35, int  * x36, integer  x37) = (((x37==0) || ((x37>0) &&
(\valid(x35+(0..x37-1)) &&
\valid(x36+(0..x37-1))))) &&
(\forall int x47; (0<=x47<x37) ==> inv_vec_Int(x35[x47],x36[x47])));*/
/*@
inductive vec_vec_Int_Permut{L1,L2}(int  * * x58, int  * x59, integer  x60) {
  case vec_vec_Int_Permut_refl{L}:
  \forall int  * * x61, int  * x62, integer  x63; vec_vec_Int_Permut{L,L}(x61,x62,x63);
  case vec_vec_Int_Permut_sym{L1,L2}:
  \forall int  * * x67, int  * x68, integer  x69; (vec_vec_Int_Permut{L1,L2}(x67,x68,x69) ==> vec_vec_Int_Permut{L2,L1}(x67,x68,x69));
  case vec_vec_Int_Permut_trans{L1,L2,L3}:
  \forall int  * * x75, int  * x76, integer  x77; ((vec_vec_Int_Permut{L1,L2}(x75,x76,x77) &&
  vec_vec_Int_Permut{L2,L3}(x75,x76,x77)) ==> vec_vec_Int_Permut{L1,L3}(x75,x76,x77));
  case vec_vec_Int_Permut_step{L1,L2}:
  \forall int  * * x86, int  * x87, integer  x88; (\exists integer  x90; (\exists integer  x91; (((\at(eq_vec_Int(\at(x86[x90],L1),\at(x87[x90],L1),\at(x86[x91],L2),\at(x87[x91],L2)),L1) &&
  \at(eq_vec_Int(\at(x86[x90],L1),\at(x87[x90],L1),\at(x86[x91],L2),\at(x87[x91],L2)),L2)) &&
  (\at(eq_vec_Int(\at(x86[x91],L1),\at(x87[x91],L1),\at(x86[x90],L2),\at(x87[x90],L2)),L1) &&
  \at(eq_vec_Int(\at(x86[x91],L1),\at(x87[x91],L1),\at(x86[x90],L2),\at(x87[x90],L2)),L2))) &&
  (\forall integer  x113; (((((0<=x113) &&
  (x113<x88)) &&
  (x113!=x90)) &&
  (x113!=x91)) ==> (\at(eq_vec_Int(\at(x86[x113],L1),\at(x87[x113],L1),\at(x86[x113],L2),\at(x87[x113],L2)),L1) &&
  \at(eq_vec_Int(\at(x86[x113],L1),\at(x87[x113],L1),\at(x86[x113],L2),\at(x87[x113],L2)),L2)))))));
}
*/
/*@
requires ((inv_vec_vec_Int(x136,x137,x138) &&
((((0<=x139) &&
(x139<x138)) &&
(0<=x140)) &&
(x140<x138))) &&
(\forall int  x163; (\forall int  x164; (((((0<=x163) &&
(x163<x138)) &&
(0<=x164)) &&
(x164<x138)) ==> \separated(x136+x163,x137+x164)))));
ensures (((inv_vec_vec_Int(x136,x137,x138) &&
(((\at(eq_vec_Int(\at(x136[x139],Old),\at(x137[x139],Old),\at(x136[x140],Post),\at(x137[x140],Post)),Old) &&
\at(eq_vec_Int(\at(x136[x139],Old),\at(x137[x139],Old),\at(x136[x140],Post),\at(x137[x140],Post)),Post)) &&
(\at(eq_vec_Int(\at(x136[x140],Old),\at(x137[x140],Old),\at(x136[x139],Post),\at(x137[x139],Post)),Old) &&
\at(eq_vec_Int(\at(x136[x140],Old),\at(x137[x140],Old),\at(x136[x139],Post),\at(x137[x139],Post)),Post))) &&
(\forall int  x204; (((((0<=x204) &&
(x204<x138)) &&
(x204!=x139)) &&
(x204!=x140)) ==> (\at(eq_vec_Int(\at(x136[x204],Old),\at(x137[x204],Old),\at(x136[x204],Post),\at(x137[x204],Post)),Old) &&
\at(eq_vec_Int(\at(x136[x204],Old),\at(x137[x204],Old),\at(x136[x204],Post),\at(x137[x204],Post)),Post)))))) &&
vec_vec_Int_Permut{Old,Post}(x136,x137,x138)) &&
(\forall int  x229; (\forall int  x230; (((((0<=x229) &&
(x229<x138)) &&
(0<=x230)) &&
(x230<x138)) ==> \separated(x136+x229,x137+x230)))));
assigns x136[(0..x138-1)], x137[(0..x138-1)];
*/
void inswap_vec_Int(int  * * x136, int  * x137, int  x138, int  x139, int  x140) {
  int  *x143 = x136[x139];
  int x144 = x137[x139];
  int  *x145 = x136[x140];
  int x146 = x137[x140];
  x136[x139] = x145;
  x137[x139] = x146;
  x136[x140] = x143;
  x137[x140] = x144;
}
/*@
requires (inv_vec_vec_Int(x245,x246,x247) &&
(\forall int  x590; (\forall int  x591; (((((0<=x590) &&
(x590<x247)) &&
(0<=x591)) &&
(x591<x247)) ==> \separated(x245+x590,x246+x591)))));
ensures ((inv_vec_vec_Int(x245,x246,x247) &&
(\forall int  x607; (\forall int  x608; (((((0<=x607) &&
(x607<x247)) &&
(0<=x608)) &&
(x608<x247)) ==> \separated(x245+x607,x246+x608))))) &&
((\forall int  x622; (((0<=x622) &&
(x622<(x247-1))) ==> (x246[x622]<=x246[(x622+1)]))) &&
vec_vec_Int_Permut{Old,Post}(x245,x246,x247)));
assigns x245[(0..x247-1)], x246[(0..x247-1)];
*/
void insort_vecs(int  * * x245, int  * x246, int  x247) {
  /*@assert (\forall int x250; (0<=x250<x247) ==> (\forall int x252; (0<=x252<x247) ==> (\forall int x254; (0<=x254<x247) ==> (((x246[x250]<=x246[x252]) &&
  (x246[x252]<=x246[x254])) ==> (x246[x250]<=x246[x254])))));*/
  /*@
  loop invariant (x401==0 && x399==-1) || (0<=x401<=x399);
  loop invariant (\forall int  x406; (((0<=x406) &&
  (x406<x401)) ==> (x246[x406]<=x246[(x406+1)])));
  loop invariant ((x401>0) ==> (\forall int  x420; (((x401<=x420) &&
  (x420<x247)) ==> (x246[(x401-1)]<=x246[x420]))));
  loop invariant vec_vec_Int_Permut{Pre,Here}(x245,x246,x247);
  loop invariant (\forall int  x436; (\forall int  x437; (((((0<=x436) &&
  (x436<x247)) &&
  (0<=x437)) &&
  (x437<x247)) ==> \separated(x245+x436,x246+x437))));
  loop invariant (((x247==0) || ((x247>0) &&
  (\valid(x245+(0..x247-1)) &&
  \valid(x246+(0..x247-1))))) &&
  (\forall int x458; (0<=x458<x247) ==> inv_vec_Int(x245[x458],x246[x458])));
  loop assigns x401, x245[(0..x247-1)], x246[(0..x247-1)];
  loop variant x399-x401;
  */
  for(int x401=0; x401 < x399; x401++) {
    int x472 = x401;
    /*@
    loop invariant 0<=x475<=x247;
    loop invariant (\forall int  x476; (((x401<=x476) &&
    (x476<x475)) ==> (x246[x472]<=x246[x476])));
    loop invariant ((x401<=x472) &&
    (x472<x475));
    loop assigns x475, x472;
    loop variant x247-x475;
    */
    for(int x475=x473; x475 < x247; x475++) {
      int  *x494 = x245[x475];
      int x495 = x246[x475];
      int x496 = x472;
      int  *x497 = x245[x496];
      int x498 = x246[x496];
      int x499 = x495 <= x498;
      if (x499) {
        x472 = x475;
      } else {
        /*@assert (x246[x472]<=x246[x475]);*/
      }
    }
    /*@assert (x246[x472]<=x246[(x401+1)]);*/
    int x522 = x472;
    inswap_vec_Int(x245,x246,x247,x401,x522);
    /*@assert (\forall int  x524; (((0<=x524) &&
    (x524<(x401-1))) ==> (x246[x524]<=x246[(x524+1)])));*/
    /*@assert (\forall int  x538; (((0<=x538) &&
    (x538<x401)) ==> (x246[x538]<=x246[(x538+1)])));*/
    /*@assert (x246[x401]<=x246[(x401+1)]);*/
    /*@assert (\forall int  x559; (((0<=x559) &&
    (x559<(x401+1))) ==> (x246[x559]<=x246[(x559+1)])));*/
    /*@assert (\forall int  x573; ((((x401+1)<=x573) &&
    (x573<x247)) ==> (x246[x401]<=x246[x573])));*/
  }
}
