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
requires ((inv_vec___Int_Int__(x240,x241,x242) && (\forall int  x420; (\forall int  x421; (((((0<=x420) && (x420<x242)) && (0<=x421)) && (x421<x242)) ==> \separated(x240+x420,x241+x421))))) && (x242>0));
ensures (inv_vec___Int_Int__(x240,x241,x242) && (\forall int  x443; (\forall int  x444; (((((0<=x443) && (x443<x242)) && (0<=x444)) && (x444<x242)) ==> \separated(x240+x443,x241+x444)))));
assigns x240[(0..x242-1)], x241[(0..x242-1)];
*/
void insort_pairs(int  * x240, int  * x241, int  x242) {
  int x245 = x242 - 1;
  /*@
  loop invariant 0<=x247<=x245;
  loop invariant (\forall int  x253; (((0<=x253) && (x253<x247)) ==> (x240[x253]<=x240[(x253+1)])));
  loop invariant ((x247>0) ==> (\forall int  x269; (((x247<=x269) && (x269<x242)) ==> (x240[(x247-1)]<=x240[x269]))));
  loop assigns x247, x240[(0..x242-1)], x241[(0..x242-1)];
  loop variant x245-x247;
  */
  for(int x247=0; x247 < x245; x247++) {
    int x285 = x247;
    int x286 = x247 + 1;
    /*@
    loop invariant 0<=x288<=x242;
    loop invariant (\forall int  x289; (((x247<=x289) && (x289<x288)) ==> (x240[x285]<=x240[x289])));
    loop invariant ((x247<=x285) && (x285<x288));
    loop assigns x288, x285;
    loop variant x242-x288;
    */
    for(int x288=x286; x288 < x242; x288++) {
      int x311 = x240[x288];
      int x312 = x241[x288];
      int x313 = x285;
      int x314 = x240[x313];
      int x315 = x241[x313];
      int x316 = x311 <= x314;
      if (x316) {
        x285 = x288;
      } else {
        //@assert (x240[x285]<=x240[x288]);
      }
    }
    //@assert (x240[x285]<=x240[(x247+1)]);
    int x340 = x285;
    inswap___Int_Int__(x240,x241,x242,x247,x340);
    //@assert (\forall int  x343; (((0<=x343) && (x343<(x247-1))) ==> (x240[x343]<=x240[(x343+1)])));
    //@assert (\forall int  x359; (((0<=x359) && (x359<x247)) ==> (x240[x359]<=x240[(x359+1)])));
    //@assert (x240[x247]<=x240[(x247+1)]);
    //@assert (\forall int  x384; (((0<=x384) && (x384<(x247+1))) ==> (x240[x384]<=x240[(x384+1)])));
    //@assert (\forall int  x401; ((((x247+1)<=x401) && (x401<x242)) ==> (x240[x247]<=x240[x401])));
  }
}
