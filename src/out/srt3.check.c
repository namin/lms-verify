#include <limits.h>
//@ predicate eq___Int_Int__(int  x0, int  x1, int  x2, int  x3) = ((x0==x2) && (x1==x3));
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
//@ predicate inv_vec___Int_Int__(int  * x8, int  * x9, int  x10) = ((x10==0) || ((x10>0) && (\valid(x8+(0..x10-1)) && \valid(x9+(0..x10-1)))));
/*@
inductive __Int_Int___Permut{L1,L2}(int  * x29, int  * x30, integer  x31) {
  case __Int_Int___Permut_refl{L}:
  \forall int  * x32, int  * x33, integer  x34; __Int_Int___Permut{L,L}(x32,x33,x34);
  case __Int_Int___Permut_sym{L1,L2}:
  \forall int  * x38, int  * x39, integer  x40; (__Int_Int___Permut{L1,L2}(x38,x39,x40) ==> __Int_Int___Permut{L2,L1}(x38,x39,x40));
  case __Int_Int___Permut_trans{L1,L2,L3}:
  \forall int  * x46, int  * x47, integer  x48; ((__Int_Int___Permut{L1,L2}(x46,x47,x48) && __Int_Int___Permut{L2,L3}(x46,x47,x48)) ==> __Int_Int___Permut{L1,L3}(x46,x47,x48));
  case __Int_Int___Permut_swap{L1,L2}:
  \forall int  * x57, int  * x58, integer  x59; (\forall integer  x61; (\forall integer  x62; ((((((((0<=x61) && (x61<x59)) && (0<=x62)) && (x62<x59)) && eq___Int_Int__(\at(x57[x61],L1),\at(x58[x61],L1),\at(x57[x62],L2),\at(x58[x62],L2))) && eq___Int_Int__(\at(x57[x62],L1),\at(x58[x62],L1),\at(x57[x61],L2),\at(x58[x61],L2))) && (\forall integer  x95; (((((0<=x95) && (x95<x59)) && (x95!=x61)) && (x95!=x62)) ==> eq___Int_Int__(\at(x57[x95],L1),\at(x58[x95],L1),\at(x57[x95],L2),\at(x58[x95],L2))))) ==> __Int_Int___Permut{L1,L2}(x57,x58,x59))));
}
*/
/*@
requires ((inv_vec___Int_Int__(x126,x127,x128) && ((((0<=x129) && (x129<x128)) && (0<=x130)) && (x130<x128))) && (\forall int  x156; (\forall int  x157; (((((0<=x156) && (x156<x128)) && (0<=x157)) && (x157<x128)) ==> \separated(x126+x156,x127+x157)))));
ensures ((((inv_vec___Int_Int__(x126,x127,x128) && (eq___Int_Int__(x126[x129],x127[x129],\old(x126[x130]),\old(x127[x130])) && eq___Int_Int__(x126[x130],x127[x130],\old(x126[x129]),\old(x127[x129])))) && (\forall int  x196; ((((0<=x196) && (x196<x128)) && ((x196!=x129) && (x196!=x130))) ==> eq___Int_Int__(x126[x196],x127[x196],\old(x126[x196]),\old(x127[x196]))))) && __Int_Int___Permut{Old,Post}(x126,x127,x128)) && (\forall int  x220; (\forall int  x221; (((((0<=x220) && (x220<x128)) && (0<=x221)) && (x221<x128)) ==> \separated(x126+x220,x127+x221)))));
assigns x126[(0..x128-1)], x127[(0..x128-1)];
*/
void inswap___Int_Int__(int  * x126, int  * x127, int  x128, int  x129, int  x130) {
  int x133 = x126[x129];
  int x134 = x127[x129];
  int x135 = x126[x130];
  int x136 = x127[x130];
  x126[x129] = x135;
  x127[x129] = x136;
  x126[x130] = x133;
  x127[x130] = x134;
}
/*@
requires ((inv_vec___Int_Int__(x240,x241,x242) && (\forall int  x427; (\forall int  x428; (((((0<=x427) && (x427<x242)) && (0<=x428)) && (x428<x242)) ==> \separated(x240+x427,x241+x428))))) && (x242>0));
ensures (inv_vec___Int_Int__(x240,x241,x242) && (\forall int  x450; (\forall int  x451; (((((0<=x450) && (x450<x242)) && (0<=x451)) && (x451<x242)) ==> \separated(x240+x450,x241+x451)))));
assigns x240[(0..x242-1)], x241[(0..x242-1)];
*/
void insort_pairs(int  * x240, int  * x241, int  x242) {
  int x245 = x242 - 1;
  /*@
  loop invariant ((0<=x247) && (x247<=x245));
  loop invariant (\forall int  x248; (((0<=x248) && (x248<x247)) ==> (x240[x248]<=x240[(x248+1)])));
  loop invariant ((x247>0) ==> (\forall int  x264; (((x247<=x264) && (x264<x242)) ==> (x240[(x247-1)]<=x240[x264]))));
  loop assigns x247, x240[(0..x242-1)], x241[(0..x242-1)];
  loop variant (x245-x247);
  */
  for(int x247=0; x247 < x245; x247++) {
    int x280 = x247;
    int x281 = x247 + 1;
    /*@
    loop invariant 0<=x283<=x242;
    loop invariant (\forall int  x284; (((x247<=x284) && (x284<x283)) ==> (x240[x280]<=x240[x284])));
    loop invariant ((x247<=x280) && (x280<x283));
    loop assigns x283, x280;
    loop variant x242-x283;
    */
    for(int x283=x281; x283 < x242; x283++) {
      int x306 = x240[x283];
      int x307 = x241[x283];
      int x308 = x280;
      int x309 = x240[x308];
      int x310 = x241[x308];
      int x311 = x306 <= x309;
      if (x311) {
        x280 = x283;
      } else {
        //@assert (x240[x280]<=x240[x283]);
      }
    }
    //@assert (x240[x280]<=x240[(x247+1)]);
    int x335 = x280;
    inswap___Int_Int__(x240,x241,x242,x247,x335);
    //@assert (\forall int  x338; (((0<=x338) && (x338<(x247-1))) ==> (x240[x338]<=x240[(x338+1)])));
    //@assert (\forall int  x354; (((0<=x354) && (x354<x247)) ==> (x240[x354]<=x240[(x354+1)])));
    //@assert (x240[x247]<=x240[(x247+1)]);
    //@assert (\forall int  x379; (((0<=x379) && (x379<(x247+1))) ==> (x240[x379]<=x240[(x379+1)])));
    //@assert (\forall int  x396; ((((x247+1)<=x396) && (x396<x242)) ==> (x240[x247]<=x240[x396])));
  }
}
