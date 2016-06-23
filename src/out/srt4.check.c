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
requires (inv_vec___Int_Int__(x240,x241,x242) && (\forall int  x527; (\forall int  x528; (((((0<=x527) && (x527<x242)) && (0<=x528)) && (x528<x242)) ==> \separated(x240+x527,x241+x528)))));
ensures (((inv_vec___Int_Int__(x240,x241,x242) && (\forall int  x548; (((0<=x548) && (x548<(x242-1))) ==> ((x240[x548]<x240[(x548+1)]) || ((x240[x548]==x240[(x548+1)]) && (x241[x548]<=x241[(x548+1)])))))) && __Int_Int___Permut{Old,Post}(x240,x241,x242)) && (\forall int  x571; (\forall int  x572; (((((0<=x571) && (x571<x242)) && (0<=x572)) && (x572<x242)) ==> \separated(x240+x571,x241+x572)))));
assigns x240[(0..x242-1)], x241[(0..x242-1)];
*/
void insort_pairs(int  * x240, int  * x241, int  x242) {
  int x245 = x242;
  /*@
  loop invariant ((((((0<=x245) && (x245<=x242)) && ((x245<(x242-1)) ==> (\forall int  x442; (((x245<=x442) && (x442<(x242-1))) ==> ((x240[x442]<x240[(x442+1)]) || ((x240[x442]==x240[(x442+1)]) && (x241[x442]<=x241[(x442+1)]))))))) && (\forall int  x466; ((((0<=x466) && (x466<x245)) && (x245<=(x242-1))) ==> ((x240[x466]<x240[x245]) || ((x240[x466]==x240[x245]) && (x241[x466]<=x241[x245])))))) && __Int_Int___Permut{Pre,Here}(x240,x241,x242)) && (\forall int  x496; (\forall int  x497; (((((0<=x496) && (x496<x242)) && (0<=x497)) && (x497<x242)) ==> \separated(x240+x496,x241+x497)))));
  loop assigns x245, x240[(0..x242-1)], x241[(0..x242-1)];
  loop variant x245;
  */
  for (;;) {
    int x246 = x245;
    int x247 = x246 > 1;
    if (!x247) break;
    int x249 = 0;
    int x250 = x245;
    /*@
    loop invariant ((((((((((0<=x245) && (x245<=x242)) && (0<=x252)) && (x252<=x245)) && (0<=x249)) && (x249<=(x245-1))) && ((x245-1)<x242)) && (\forall int  x310; (((0<=x310) && (x310<x252)) ==> ((x240[x310]<x240[x249]) || ((x240[x310]==x240[x249]) && (x241[x310]<=x241[x249])))))) && __Int_Int___Permut{Pre,Here}(x240,x241,x242)) && (\forall int  x334; (\forall int  x335; (((((0<=x334) && (x334<x242)) && (0<=x335)) && (x335<x242)) ==> \separated(x240+x334,x241+x335)))));
    loop assigns x252, x249;
    loop variant (x245-x252);
    */
    for(int x252=0; x252 < x250; x252++) {
      int x253 = x249;
      int x254 = x240[x253];
      int x255 = x241[x253];
      int x256 = x240[x252];
      int x257 = x241[x252];
      int x258 = x254 < x256;
      int x259 = x254 == x256;
      int x261;
      if (x259) {
        int x260 = x255 <= x257;
        x261 = x260;
      } else {
        x261 = 0/*false*/;
      }
      int x262 = x258 || x261;
      if (x262) {
        x249 = x252;
      } else {
        //@assert ((x240[x252]<x240[x249]) || ((x240[x252]==x240[x249]) && (x241[x252]<=x241[x249])));
      }
    }
    int x362 = x249;
    int x361 = x250 - 1;
    inswap___Int_Int__(x240,x241,x242,x361,x362);
    //@assert (\forall int  x364; ((((x245-1)<x364) && (x364<(x242-1))) ==> ((x240[x364]<x240[(x364+1)]) || ((x240[x364]==x240[(x364+1)]) && (x241[x364]<=x241[(x364+1)])))));
    //@assert ((x245<=(x242-1)) ==> ((x240[(x245-1)]<x240[x245]) || ((x240[(x245-1)]==x240[x245]) && (x241[(x245-1)]<=x241[x245]))));
    //@assert (\forall int  x407; (((0<=x407) && (x407<x245)) ==> ((x240[x407]<x240[(x245-1)]) || ((x240[x407]==x240[(x245-1)]) && (x241[x407]<=x241[(x245-1)])))));
    x245 = x361;
  }
}
