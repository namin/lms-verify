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
  \forall int  * x57, int  * x58, integer  x59; (\forall integer  x61; (\forall integer  x62; ((((((0<=x61) && (x61<x59)) && (0<=x62)) && (x62<x59)) && ((eq___Int_Int__(\at(x57[x61],L1),\at(x58[x61],L1),\at(x57[x62],L2),\at(x58[x62],L2)) && eq___Int_Int__(\at(x57[x62],L1),\at(x58[x62],L1),\at(x57[x61],L2),\at(x58[x61],L2))) && (\forall integer  x93; (((((0<=x93) && (x93<x59)) && (x93!=x61)) && (x93!=x62)) ==> eq___Int_Int__(\at(x57[x93],L1),\at(x58[x93],L1),\at(x57[x93],L2),\at(x58[x93],L2)))))) ==> __Int_Int___Permut{L1,L2}(x57,x58,x59))));
}
*/
/*@
requires ((inv_vec___Int_Int__(x126,x127,x128) && ((((0<=x129) && (x129<x128)) && (0<=x130)) && (x130<x128))) && (\forall int  x156; (\forall int  x157; (((((0<=x156) && (x156<x128)) && (0<=x157)) && (x157<x128)) ==> \separated(x126+x156,x127+x157)))));
ensures (((inv_vec___Int_Int__(x126,x127,x128) && ((eq___Int_Int__(\at(x126[x129],Old),\at(x127[x129],Old),\at(x126[x130],Post),\at(x127[x130],Post)) && eq___Int_Int__(\at(x126[x130],Old),\at(x127[x130],Old),\at(x126[x129],Post),\at(x127[x129],Post))) && (\forall int  x199; (((((0<=x199) && (x199<x128)) && (x199!=x129)) && (x199!=x130)) ==> eq___Int_Int__(\at(x126[x199],Old),\at(x127[x199],Old),\at(x126[x199],Post),\at(x127[x199],Post)))))) && __Int_Int___Permut{Old,Post}(x126,x127,x128)) && (\forall int  x227; (\forall int  x228; (((((0<=x227) && (x227<x128)) && (0<=x228)) && (x228<x128)) ==> \separated(x126+x227,x127+x228)))));
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
requires ((inv_vec___Int_Int__(x247,x248,x249) && (\forall int  x427; (\forall int  x428; (((((0<=x427) && (x427<x249)) && (0<=x428)) && (x428<x249)) ==> \separated(x247+x427,x248+x428))))) && (x249>0));
ensures (inv_vec___Int_Int__(x247,x248,x249) && (\forall int  x450; (\forall int  x451; (((((0<=x450) && (x450<x249)) && (0<=x451)) && (x451<x249)) ==> \separated(x247+x450,x248+x451)))));
assigns x247[(0..x249-1)], x248[(0..x249-1)];
*/
void insort_pairs(int  * x247, int  * x248, int  x249) {
  int x252 = x249 - 1;
  /*@
  loop invariant 0<=x254<=x252;
  loop invariant (\forall int  x260; (((0<=x260) && (x260<x254)) ==> (x247[x260]<=x247[(x260+1)])));
  loop invariant ((x254>0) ==> (\forall int  x276; (((x254<=x276) && (x276<x249)) ==> (x247[(x254-1)]<=x247[x276]))));
  loop assigns x254, x247[(0..x249-1)], x248[(0..x249-1)];
  loop variant x252-x254;
  */
  for(int x254=0; x254 < x252; x254++) {
    int x292 = x254;
    int x293 = x254 + 1;
    /*@
    loop invariant 0<=x295<=x249;
    loop invariant (\forall int  x296; (((x254<=x296) && (x296<x295)) ==> (x247[x292]<=x247[x296])));
    loop invariant ((x254<=x292) && (x292<x295));
    loop assigns x295, x292;
    loop variant x249-x295;
    */
    for(int x295=x293; x295 < x249; x295++) {
      int x318 = x247[x295];
      int x319 = x248[x295];
      int x320 = x292;
      int x321 = x247[x320];
      int x322 = x248[x320];
      int x323 = x318 <= x321;
      if (x323) {
        x292 = x295;
      } else {
        //@assert (x247[x292]<=x247[x295]);
      }
    }
    //@assert (x247[x292]<=x247[(x254+1)]);
    int x347 = x292;
    inswap___Int_Int__(x247,x248,x249,x254,x347);
    //@assert (\forall int  x350; (((0<=x350) && (x350<(x254-1))) ==> (x247[x350]<=x247[(x350+1)])));
    //@assert (\forall int  x366; (((0<=x366) && (x366<x254)) ==> (x247[x366]<=x247[(x366+1)])));
    //@assert (x247[x254]<=x247[(x254+1)]);
    //@assert (\forall int  x391; (((0<=x391) && (x391<(x254+1))) ==> (x247[x391]<=x247[(x391+1)])));
    //@assert (\forall int  x408; ((((x254+1)<=x408) && (x408<x249)) ==> (x247[x254]<=x247[x408])));
  }
}
