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
requires ((inv_vec___Int_Int__(x247,x248,x249) && (\forall int  x502; (\forall int  x503; (((((0<=x502) && (x502<x249)) && (0<=x503)) && (x503<x249)) ==> \separated(x247+x502,x248+x503))))) && (x249>0));
ensures ((inv_vec___Int_Int__(x247,x248,x249) && (\forall int  x525; (\forall int  x526; (((((0<=x525) && (x525<x249)) && (0<=x526)) && (x526<x249)) ==> \separated(x247+x525,x248+x526))))) && ((\forall int  x545; (((0<=x545) && (x545<(x249-1))) ==> ((x247[x545]<x247[(x545+1)]) || ((x247[x545]==x247[(x545+1)]) && (x248[x545]<=x248[(x545+1)]))))) && __Int_Int___Permut{Old,Post}(x247,x248,x249)));
assigns x247[(0..x249-1)], x248[(0..x249-1)];
*/
void insort_pairs(int  * x247, int  * x248, int  x249) {
  int x252 = x249 - 1;
  /*@
  loop invariant 0<=x254<=x252;
  loop invariant (\forall int  x260; (((0<=x260) && (x260<x254)) ==> ((x247[x260]<x247[(x260+1)]) || ((x247[x260]==x247[(x260+1)]) && (x248[x260]<=x248[(x260+1)])))));
  loop invariant ((x254>0) ==> (\forall int  x281; (((x254<=x281) && (x281<x249)) ==> ((x247[(x254-1)]<x247[x281]) || ((x247[(x254-1)]==x247[x281]) && (x248[(x254-1)]<=x248[x281]))))));
  loop invariant __Int_Int___Permut{Pre,Here}(x247,x248,x249);
  loop invariant (\forall int  x304; (\forall int  x305; (((((0<=x304) && (x304<x249)) && (0<=x305)) && (x305<x249)) ==> \separated(x247+x304,x248+x305))));
  loop assigns x254, x247[(0..x249-1)], x248[(0..x249-1)];
  loop variant x252-x254;
  */
  for(int x254=0; x254 < x252; x254++) {
    int x323 = x254;
    int x324 = x254 + 1;
    /*@
    loop invariant 0<=x326<=x249;
    loop invariant (\forall int  x327; (((x254<=x327) && (x327<x326)) ==> ((x247[x323]<x247[x327]) || ((x247[x323]==x247[x327]) && (x248[x323]<=x248[x327])))));
    loop invariant ((x254<=x323) && (x323<x326));
    loop assigns x326, x323;
    loop variant x249-x326;
    */
    for(int x326=x324; x326 < x249; x326++) {
      int x354 = x247[x326];
      int x355 = x248[x326];
      int x356 = x323;
      int x357 = x247[x356];
      int x358 = x248[x356];
      int x359 = x354 < x357;
      int x360 = x354 == x357;
      int x362;
      if (x360) {
        int x361 = x355 <= x358;
        x362 = x361;
      } else {
        x362 = 0/*false*/;
      }
      int x363 = x359 || x362;
      if (x363) {
        x323 = x326;
      } else {
        //@assert ((x247[x323]<x247[x326]) || ((x247[x323]==x247[x326]) && (x248[x323]<=x248[x326])));
      }
    }
    //@assert ((x247[x323]<x247[(x254+1)]) || ((x247[x323]==x247[(x254+1)]) && (x248[x323]<=x248[(x254+1)])));
    int x397 = x323;
    inswap___Int_Int__(x247,x248,x249,x254,x397);
    //@assert (\forall int  x400; (((0<=x400) && (x400<(x254-1))) ==> ((x247[x400]<x247[(x400+1)]) || ((x247[x400]==x247[(x400+1)]) && (x248[x400]<=x248[(x400+1)])))));
    //@assert (\forall int  x421; (((0<=x421) && (x421<x254)) ==> ((x247[x421]<x247[(x421+1)]) || ((x247[x421]==x247[(x421+1)]) && (x248[x421]<=x248[(x421+1)])))));
    //@assert ((x247[x254]<x247[(x254+1)]) || ((x247[x254]==x247[(x254+1)]) && (x248[x254]<=x248[(x254+1)])));
    //@assert (\forall int  x456; (((0<=x456) && (x456<(x254+1))) ==> ((x247[x456]<x247[(x456+1)]) || ((x247[x456]==x247[(x456+1)]) && (x248[x456]<=x248[(x456+1)])))));
    //@assert (\forall int  x478; ((((x254+1)<=x478) && (x478<x249)) ==> ((x247[x254]<x247[x478]) || ((x247[x254]==x247[x478]) && (x248[x254]<=x248[x478])))));
  }
}
