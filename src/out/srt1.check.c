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
  \forall int  * x24, integer  x25; (\forall integer  x27; (\forall integer  x28; ((((((((0<=x27) && (x27<x25)) && (0<=x28)) && (x28<x25)) && (\at(x24[x27],L1)==\at(x24[x28],L2))) && (\at(x24[x28],L1)==\at(x24[x27],L2))) && (\forall integer  x53; (((((0<=x53) && (x53<x25)) && (x53!=x27)) && (x53!=x28)) ==> (\at(x24[x53],L1)==\at(x24[x53],L2))))) ==> Int_Permut{L1,L2}(x24,x25))));
}
*/
/*@
requires ((((((x83>0) && (0<=x81)) && (x81<x83)) && (0<=x82)) && (x82<x83)) && \valid(x80+(0..x83-1)));
ensures (((x80[x81]==\old(x80[x82])) && (x80[x82]==\old(x80[x81]))) && Int_Permut{Old,Post}(x80,x83));
assigns x80[x81], x80[x82];
*/
void inswap(int  * x80, int  x81, int  x82, int  x83) {
  int x85 = x80[x81];
  int x86 = x80[x82];
  x80[x81] = x86;
  x80[x82] = x85;
}
