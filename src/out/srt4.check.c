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
requires ((inv_vec___Int_Int__(x240,x241,x242) && (\forall int  x474; (\forall int  x475; (((((0<=x474) && (x474<x242)) && (0<=x475)) && (x475<x242)) ==> \separated(x240+x474,x241+x475))))) && (x242>0));
ensures (inv_vec___Int_Int__(x240,x241,x242) && (\forall int  x497; (\forall int  x498; (((((0<=x497) && (x497<x242)) && (0<=x498)) && (x498<x242)) ==> \separated(x240+x497,x241+x498)))));
assigns x240[(0..x242-1)], x241[(0..x242-1)];
*/
void insort_pairs(int  * x240, int  * x241, int  x242) {
  int x245 = x242 - 1;
  /*@
  loop invariant 0<=x247<=x245;
  loop invariant (\forall int  x253; (((0<=x253) && (x253<x247)) ==> ((x240[x253]<x240[(x253+1)]) || ((x240[x253]==x240[(x253+1)]) && (x241[x253]<=x241[(x253+1)])))));
  loop invariant ((x247>0) ==> (\forall int  x274; (((x247<=x274) && (x274<x242)) ==> ((x240[(x247-1)]<x240[x274]) || ((x240[(x247-1)]==x240[x274]) && (x241[(x247-1)]<=x241[x274]))))));
  loop assigns x247, x240[(0..x242-1)], x241[(0..x242-1)];
  loop variant x245-x247;
  */
  for(int x247=0; x247 < x245; x247++) {
    int x295 = x247;
    int x296 = x247 + 1;
    /*@
    loop invariant 0<=x298<=x242;
    loop invariant (\forall int  x299; (((x247<=x299) && (x299<x298)) ==> ((x240[x295]<x240[x299]) || ((x240[x295]==x240[x299]) && (x241[x295]<=x241[x299])))));
    loop invariant ((x247<=x295) && (x295<x298));
    loop assigns x298, x295;
    loop variant x242-x298;
    */
    for(int x298=x296; x298 < x242; x298++) {
      int x326 = x240[x298];
      int x327 = x241[x298];
      int x328 = x295;
      int x329 = x240[x328];
      int x330 = x241[x328];
      int x331 = x326 < x329;
      int x332 = x326 == x329;
      int x334;
      if (x332) {
        int x333 = x327 <= x330;
        x334 = x333;
      } else {
        x334 = 0/*false*/;
      }
      int x335 = x331 || x334;
      if (x335) {
        x295 = x298;
      } else {
        //@assert ((x240[x295]<x240[x298]) || ((x240[x295]==x240[x298]) && (x241[x295]<=x241[x298])));
      }
    }
    //@assert ((x240[x295]<x240[(x247+1)]) || ((x240[x295]==x240[(x247+1)]) && (x241[x295]<=x241[(x247+1)])));
    int x369 = x295;
    inswap___Int_Int__(x240,x241,x242,x247,x369);
    //@assert (\forall int  x372; (((0<=x372) && (x372<(x247-1))) ==> ((x240[x372]<x240[(x372+1)]) || ((x240[x372]==x240[(x372+1)]) && (x241[x372]<=x241[(x372+1)])))));
    //@assert (\forall int  x393; (((0<=x393) && (x393<x247)) ==> ((x240[x393]<x240[(x393+1)]) || ((x240[x393]==x240[(x393+1)]) && (x241[x393]<=x241[(x393+1)])))));
    //@assert ((x240[x247]<x240[(x247+1)]) || ((x240[x247]==x240[(x247+1)]) && (x241[x247]<=x241[(x247+1)])));
    //@assert (\forall int  x428; (((0<=x428) && (x428<(x247+1))) ==> ((x240[x428]<x240[(x428+1)]) || ((x240[x428]==x240[(x428+1)]) && (x241[x428]<=x241[(x428+1)])))));
    //@assert (\forall int  x450; ((((x247+1)<=x450) && (x450<x242)) ==> ((x240[x247]<x240[x450]) || ((x240[x247]==x240[x450]) && (x241[x247]<=x241[x450])))));
  }
}
