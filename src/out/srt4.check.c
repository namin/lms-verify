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
/*@
inductive __Int_Int___Permut{L1,L2}(int  * x8, int  * x9, integer  x10) {
  case __Int_Int___Permut_refl{L}:
  \forall int  * x11, int  * x12, integer  x13; __Int_Int___Permut{L,L}(x11,x12,x13);
  case __Int_Int___Permut_sym{L1,L2}:
  \forall int  * x17, int  * x18, integer  x19; (__Int_Int___Permut{L1,L2}(x17,x18,x19) ==> __Int_Int___Permut{L2,L1}(x17,x18,x19));
  case __Int_Int___Permut_trans{L1,L2,L3}:
  \forall int  * x25, int  * x26, integer  x27; ((__Int_Int___Permut{L1,L2}(x25,x26,x27) && __Int_Int___Permut{L2,L3}(x25,x26,x27)) ==> __Int_Int___Permut{L1,L3}(x25,x26,x27));
  case __Int_Int___Permut_swap{L1,L2}:
  \forall int  * x36, int  * x37, integer  x38; (\forall integer  x40; (\forall integer  x41; ((((((((0<=x40) && (x40<x38)) && (0<=x41)) && (x41<x38)) && eq___Int_Int__(\at(x36[x40],L1),\at(x37[x40],L1),\at(x36[x41],L2),\at(x37[x41],L2))) && eq___Int_Int__(\at(x36[x41],L1),\at(x37[x41],L1),\at(x36[x40],L2),\at(x37[x40],L2))) && (\forall integer  x74; (((((0<=x74) && (x74<x38)) && (x74!=x40)) && (x74!=x41)) ==> eq___Int_Int__(\at(x36[x74],L1),\at(x37[x74],L1),\at(x36[x74],L2),\at(x37[x74],L2))))) ==> __Int_Int___Permut{L1,L2}(x36,x37,x38))));
}
*/
/*@
requires (((((((x109>0) && (0<=x107)) && (x107<x109)) && (0<=x108)) && (x108<x109)) && (\valid(x105+(0..x109-1)) && \valid(x106+(0..x109-1)))) && (\forall int  x139; (\forall int  x140; (((((0<=x139) && (x139<x109)) && (0<=x140)) && (x140<x109)) ==> \separated(x105+x139,x106+x140)))));
ensures ((((eq___Int_Int__(x105[x107],x106[x107],\old(x105[x108]),\old(x106[x108])) && eq___Int_Int__(x105[x108],x106[x108],\old(x105[x107]),\old(x106[x107]))) && (\forall int  x175; ((((0<=x175) && (x175<x109)) && ((x175!=x107) && (x175!=x108))) ==> eq___Int_Int__(x105[x175],x106[x175],\old(x105[x175]),\old(x106[x175]))))) && __Int_Int___Permut{Old,Post}(x105,x106,x109)) && (\forall int  x199; (\forall int  x200; (((((0<=x199) && (x199<x109)) && (0<=x200)) && (x200<x109)) ==> \separated(x105+x199,x106+x200)))));
assigns x105[(0..x109-1)], x106[(0..x109-1)];
*/
void inswap___Int_Int__(int  * x105, int  * x106, int  x107, int  x108, int  x109) {
  int x112 = x105[x107];
  int x113 = x106[x107];
  int x114 = x105[x108];
  int x115 = x106[x108];
  x105[x107] = x114;
  x106[x107] = x115;
  x105[x108] = x112;
  x106[x108] = x113;
}
/*@
requires (((x221>0) && (\valid(x219+(0..x221-1)) && \valid(x220+(0..x221-1)))) && (\forall int  x512; (\forall int  x513; (((((0<=x512) && (x512<x221)) && (0<=x513)) && (x513<x221)) ==> \separated(x219+x512,x220+x513)))));
ensures (((\forall int  x532; (((0<=x532) && (x532<(x221-1))) ==> ((x219[x532]<x219[(x532+1)]) || ((x219[x532]==x219[(x532+1)]) && (x220[x532]<=x220[(x532+1)]))))) && __Int_Int___Permut{Old,Post}(x219,x220,x221)) && (\forall int  x554; (\forall int  x555; (((((0<=x554) && (x554<x221)) && (0<=x555)) && (x555<x221)) ==> \separated(x219+x554,x220+x555)))));
assigns x219[(0..x221-1)], x220[(0..x221-1)];
*/
void insort_pairs(int  * x219, int  * x220, int  x221) {
  int x224 = x221;
  /*@
  loop invariant ((((((0<=x224) && (x224<=x221)) && ((x224<(x221-1)) ==> (\forall int  x421; (((x224<=x421) && (x421<(x221-1))) ==> ((x219[x421]<x219[(x421+1)]) || ((x219[x421]==x219[(x421+1)]) && (x220[x421]<=x220[(x421+1)]))))))) && (\forall int  x445; ((((0<=x445) && (x445<x224)) && (x224<=(x221-1))) ==> ((x219[x445]<x219[x224]) || ((x219[x445]==x219[x224]) && (x220[x445]<=x220[x224])))))) && __Int_Int___Permut{Pre,Here}(x219,x220,x221)) && (\forall int  x475; (\forall int  x476; (((((0<=x475) && (x475<x221)) && (0<=x476)) && (x476<x221)) ==> \separated(x219+x475,x220+x476)))));
  loop assigns x224, x219[(0..x221-1)], x220[(0..x221-1)];
  loop variant x224;
  */
  for (;;) {
    int x225 = x224;
    int x226 = x225 > 1;
    if (!x226) break;
    int x228 = 0;
    int x229 = x224;
    /*@
    loop invariant ((((((((((0<=x224) && (x224<=x221)) && (0<=x231)) && (x231<=x224)) && (0<=x228)) && (x228<=(x224-1))) && ((x224-1)<x221)) && (\forall int  x289; (((0<=x289) && (x289<x231)) ==> ((x219[x289]<x219[x228]) || ((x219[x289]==x219[x228]) && (x220[x289]<=x220[x228])))))) && __Int_Int___Permut{Pre,Here}(x219,x220,x221)) && (\forall int  x313; (\forall int  x314; (((((0<=x313) && (x313<x221)) && (0<=x314)) && (x314<x221)) ==> \separated(x219+x313,x220+x314)))));
    loop assigns x231, x228;
    loop variant (x224-x231);
    */
    for(int x231=0; x231 < x229; x231++) {
      int x232 = x228;
      int x233 = x219[x232];
      int x234 = x220[x232];
      int x235 = x219[x231];
      int x236 = x220[x231];
      int x237 = x233 < x235;
      int x238 = x233 == x235;
      int x240;
      if (x238) {
        int x239 = x234 <= x236;
        x240 = x239;
      } else {
        x240 = 0/*false*/;
      }
      int x241 = x237 || x240;
      if (x241) {
        x228 = x231;
      } else {
        //@assert ((x219[x231]<x219[x228]) || ((x219[x231]==x219[x228]) && (x220[x231]<=x220[x228])));
      }
    }
    int x341 = x228;
    int x340 = x229 - 1;
    inswap___Int_Int__(x219,x220,x340,x341,x221);
    //@assert (\forall int  x343; ((((x224-1)<x343) && (x343<(x221-1))) ==> ((x219[x343]<x219[(x343+1)]) || ((x219[x343]==x219[(x343+1)]) && (x220[x343]<=x220[(x343+1)])))));
    //@assert ((x224<=(x221-1)) ==> ((x219[(x224-1)]<x219[x224]) || ((x219[(x224-1)]==x219[x224]) && (x220[(x224-1)]<=x220[x224]))));
    //@assert (\forall int  x386; (((0<=x386) && (x386<x224)) ==> ((x219[x386]<x219[(x224-1)]) || ((x219[x386]==x219[(x224-1)]) && (x220[x386]<=x220[(x224-1)])))));
    x224 = x340;
  }
}
