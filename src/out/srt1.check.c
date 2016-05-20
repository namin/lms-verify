#include <limits.h>
/*@
inductive Int_Permut{L1,L2}(int  * x0, integer  x1) {
  case Int_Permut_refl{L}:
  \forall int  * x2, integer  x3; Int_Permut{L,L}(x2,x3);
  case Int_Permut_sym{L1,L2}:
  \forall int  * x7, integer  x8; (Int_Permut{L1,L2}(x7,x8) ==> Int_Permut{L2,L1}(x7,x8));
  case Int_Permut_trans{L1,L2,L3}:
  \forall int  * x14, integer  x15; ((Int_Permut{L1,L2}(x14,x15) && Int_Permut{L2,L3}(x14,x15)) ==> Int_Permut{L1,L3}(x14,x15));
  case Int_Permut_swap{L1,L2}:
  \forall int  * x24, integer  x25; (\forall integer  x27; (\forall integer  x28; ((((((((0<=x27) && (x27<x25)) && (0<=x28)) && (x28<x25)) && \false) && \false) && (\forall integer  x51; (((((0<=x51) && (x51<x25)) && (x51!=x27)) && (x51!=x28)) ==> \false))) ==> Int_Permut{L1,L2}(x24,x25))));
}
*/
/*@
requires ((((((x80>0) && (0<=x78)) && (x78<x80)) && (0<=x79)) && (x79<x80)) && \valid(x77+(0..x80-1)));
ensures (((x77[x78]==\old(x77[x79])) && (x77[x79]==\old(x77[x78]))) && Int_Permut{Old,Post}(x77,x80));
assigns x77[x78], x77[x79];
*/
void inswap(int  * x77, int  x78, int  x79, int  x80) {
  int x82 = x77[x78];
  int x83 = x77[x79];
  x77[x78] = x83;
  x77[x79] = x82;
}
