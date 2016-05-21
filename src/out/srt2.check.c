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
void inswap_Int(int  * x80, int  x81, int  x82, int  x83) {
  int x85 = x80[x81];
  int x86 = x80[x82];
  x80[x81] = x86;
  x80[x82] = x85;
}
/*@
requires ((x121>0) && \valid(x120+(0..x121-1)));
ensures ((\forall int  x309; (((0<=x309) && (x309<(x121-1))) ==> (x120[x309]>=x120[(x309+1)]))) && Int_Permut{Old,Post}(x120,x121));
assigns x120[(0..x121-1)];
*/
void insort(int  * x120, int  x121) {
  int x124 = x121;
  /*@
  loop invariant (((((0<=x124) && (x124<=x121)) && ((x124<(x121-1)) ==> (\forall int  x254; (((x124<=x254) && (x254<(x121-1))) ==> (x120[x254]>=x120[(x254+1)]))))) && (\forall int  x271; ((((0<=x271) && (x271<x124)) && (x124<=(x121-1))) ==> (x120[x271]>=x120[x124])))) && Int_Permut{Pre,Here}(x120,x121));
  loop assigns x124, x120[(0..x121-1)];
  loop variant x124;
  */
  for (;;) {
    int x125 = x124;
    int x126 = x125 > 1;
    if (!x126) break;
    int x128 = 0;
    int x129 = x124;
    /*@
    loop invariant (((((((((0<=x124) && (x124<=x121)) && (0<=x131)) && (x131<=x124)) && (0<=x128)) && (x128<=(x124-1))) && ((x124-1)<x121)) && (\forall int  x170; (((0<=x170) && (x170<x131)) ==> (x120[x170]>=x120[x128])))) && Int_Permut{Pre,Here}(x120,x121));
    loop assigns x131, x128;
    loop variant (x124-x131);
    */
    for(int x131=0; x131 < x129; x131++) {
      int x132 = x120[x131];
      int x133 = x128;
      int x134 = x120[x133];
      int x135 = x132 >= x134;
      if (x135) {
      } else {
        x128 = x131;
      }
    }
    int x195 = x128;
    int x194 = x129 - 1;
    inswap_Int(x120,x194,x195,x121);
    //@assert (\forall int  x197; ((((x124-1)<x197) && (x197<(x121-1))) ==> (x120[x197]>=x120[(x197+1)])));
    //@assert ((x124<=(x121-1)) ==> (x120[(x124-1)]>=x120[x124]));
    //@assert (\forall int  x226; (((0<=x226) && (x226<x124)) ==> (x120[x226]>=x120[(x124-1)])));
    x124 = x194;
  }
}
