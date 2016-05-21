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
ensures ((((x80[x81]==\old(x80[x82])) && (x80[x82]==\old(x80[x81]))) && (\forall int  x118; ((((0<=x118) && (x118<x83)) && ((x118!=x81) && (x118!=x82))) ==> (x80[x118]==\old(x80[x118]))))) && Int_Permut{Old,Post}(x80,x83));
assigns x80[(0..x83-1)];
*/
void inswap_Int(int  * x80, int  x81, int  x82, int  x83) {
  int x86 = x80[x81];
  int x87 = x80[x82];
  x80[x81] = x87;
  x80[x82] = x86;
}
/*@
requires ((x141>0) && \valid(x140+(0..x141-1)));
ensures ((\forall int  x337; (((0<=x337) && (x337<(x141-1))) ==> (x140[x337]<=x140[(x337+1)]))) && Int_Permut{Old,Post}(x140,x141));
assigns x140[(0..x141-1)];
*/
void insort(int  * x140, int  x141) {
  int x144 = x141;
  /*@
  loop invariant (((((0<=x144) && (x144<=x141)) && ((x144<(x141-1)) ==> (\forall int  x281; (((x144<=x281) && (x281<(x141-1))) ==> (x140[x281]<=x140[(x281+1)]))))) && (\forall int  x298; ((((0<=x298) && (x298<x144)) && (x144<=(x141-1))) ==> (x140[x298]<=x140[x144])))) && Int_Permut{Pre,Here}(x140,x141));
  loop assigns x144, x140[(0..x141-1)];
  loop variant x144;
  */
  for (;;) {
    int x145 = x144;
    int x146 = x145 > 1;
    if (!x146) break;
    int x148 = 0;
    int x149 = x144;
    /*@
    loop invariant (((((((((0<=x144) && (x144<=x141)) && (0<=x151)) && (x151<=x144)) && (0<=x148)) && (x148<=(x144-1))) && ((x144-1)<x141)) && (\forall int  x196; (((0<=x196) && (x196<x151)) ==> (x140[x196]<=x140[x148])))) && Int_Permut{Pre,Here}(x140,x141));
    loop assigns x151, x148;
    loop variant (x144-x151);
    */
    for(int x151=0; x151 < x149; x151++) {
      int x152 = x148;
      int x153 = x140[x152];
      int x154 = x140[x151];
      int x155 = x153 <= x154;
      if (x155) {
        x148 = x151;
      } else {
        //@assert (x140[x151]<=x140[x148]);
      }
    }
    int x222 = x148;
    int x221 = x149 - 1;
    inswap_Int(x140,x221,x222,x141);
    //@assert (\forall int  x224; ((((x144-1)<x224) && (x224<(x141-1))) ==> (x140[x224]<=x140[(x224+1)])));
    //@assert ((x144<=(x141-1)) ==> (x140[(x144-1)]<=x140[x144]));
    //@assert (\forall int  x253; (((0<=x253) && (x253<x144)) ==> (x140[x253]<=x140[(x144-1)])));
    x144 = x221;
  }
}
