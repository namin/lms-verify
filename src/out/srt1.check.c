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
ensures ((\forall int  x311; (((0<=x311) && (x311<(x121-1))) ==> (x120[x311]<=x120[(x311+1)]))) && Int_Permut{Old,Post}(x120,x121));
assigns x120[(0..x121-1)];
*/
void insort_Int(int  * x120, int  x121) {
  int x127 = x121;
  /*@
  loop invariant (((((0<=x127) && (x127<=x121)) && ((x127<(x121-1)) ==> (\forall int  x256; (((x127<=x256) && (x256<(x121-1))) ==> (x120[x256]<=x120[(x256+1)]))))) && (\forall int  x273; ((((0<=x273) && (x273<x127)) && (x127<=(x121-1))) ==> (x120[x273]<=x120[x127])))) && Int_Permut{Pre,Here}(x120,x121));
  loop assigns x127, x120[(0..x121-1)];
  loop variant x127;
  */
  for (;;) {
    int x128 = x127;
    int x129 = x128 > 1;
    if (!x129) break;
    int x131 = 0;
    int x132 = x127;
    /*@
    loop invariant (((((((((0<=x127) && (x127<=x121)) && (0<=x134)) && (x134<=x127)) && (0<=x131)) && (x131<=(x127-1))) && ((x127-1)<x121)) && (\forall int  x172; (((0<=x172) && (x172<x134)) ==> (x120[x172]<=x120[x131])))) && Int_Permut{Pre,Here}(x120,x121));
    loop assigns x134, x131;
    loop variant (x127-x134);
    */
    for(int x134=0; x134 < x132; x134++) {
      int x135 = x131;
      int x136 = x120[x135];
      int x137 = x120[x134];
      int x138 = x136 <= x137;
      if (x138) {
        x131 = x134;
      } else {
      }
    }
    int x197 = x131;
    int x196 = x132 - 1;
    inswap_Int(x120,x196,x197,x121);
    //@assert (\forall int  x199; ((((x127-1)<x199) && (x199<(x121-1))) ==> (x120[x199]<=x120[(x199+1)])));
    //@assert ((x127<=(x121-1)) ==> (x120[(x127-1)]<=x120[x127]));
    //@assert (\forall int  x228; (((0<=x228) && (x228<x127)) ==> (x120[x228]<=x120[(x127-1)])));
    x127 = x196;
  }
}
