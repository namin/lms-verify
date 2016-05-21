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
requires (((((((x109>0) && (0<=x107)) && (x107<x109)) && (0<=x108)) && (x108<x109)) && (\valid(x105+(0..x109-1)) && \valid(x106+(0..x109-1)))) && (\forall int  x138; (\forall int  x139; (((((0<=x138) && (x138<x109)) && (0<=x139)) && (x139<x109)) ==> \separated(x105+x138,x106+x139)))));
ensures ((eq___Int_Int__(x105[x107],x106[x107],\old(x105[x108]),\old(x106[x108])) && eq___Int_Int__(x105[x108],x106[x108],\old(x105[x107]),\old(x106[x107]))) && __Int_Int___Permut{Old,Post}(x105,x106,x109));
assigns x105[x107], x106[x107], x105[x108], x106[x108];
*/
void inswap___Int_Int__(int  * x105, int  * x106, int  x107, int  x108, int  x109) {
  int x111 = x105[x107];
  int x112 = x106[x107];
  int x113 = x105[x108];
  int x114 = x106[x108];
  x105[x107] = x113;
  x106[x107] = x114;
  x105[x108] = x111;
  x106[x108] = x112;
}
/*@
requires (((x179>0) && (\valid(x177+(0..x179-1)) && \valid(x178+(0..x179-1)))) && (\forall int  x447; (\forall int  x448; (((((0<=x447) && (x447<x179)) && (0<=x448)) && (x448<x179)) ==> \separated(x177+x447,x178+x448)))));
ensures (((\forall int  x467; (((0<=x467) && (x467<(x179-1))) ==> ((x177[x467]<=x177[(x467+1)]) || (x178[x467]<=x178[(x467+1)])))) && __Int_Int___Permut{Old,Post}(x177,x178,x179)) && (\forall int  x486; (\forall int  x487; (((((0<=x486) && (x486<x179)) && (0<=x487)) && (x487<x179)) ==> \separated(x177+x486,x178+x487)))));
assigns x177[(0..x179-1)], x178[(0..x179-1)];
*/
void insort_pairs(int  * x177, int  * x178, int  x179) {
  int x182 = x179;
  /*@
  loop invariant ((((((0<=x182) && (x182<=x179)) && ((x182<(x179-1)) ==> (\forall int  x362; (((x182<=x362) && (x362<(x179-1))) ==> ((x177[x362]<=x177[(x362+1)]) || (x178[x362]<=x178[(x362+1)])))))) && (\forall int  x383; ((((0<=x383) && (x383<x182)) && (x182<=(x179-1))) ==> ((x177[x383]<=x177[x182]) || (x178[x383]<=x178[x182]))))) && __Int_Int___Permut{Pre,Here}(x177,x178,x179)) && (\forall int  x410; (\forall int  x411; (((((0<=x410) && (x410<x179)) && (0<=x411)) && (x411<x179)) ==> \separated(x177+x410,x178+x411)))));
  loop assigns x182, x177[(0..x179-1)], x178[(0..x179-1)];
  loop variant x182;
  */
  for (;;) {
    int x183 = x182;
    int x184 = x183 > 1;
    if (!x184) break;
    int x186 = 0;
    int x187 = x182;
    /*@
    loop invariant ((((((((((0<=x182) && (x182<=x179)) && (0<=x189)) && (x189<=x182)) && (0<=x186)) && (x186<=(x182-1))) && ((x182-1)<x179)) && (\forall int  x242; (((0<=x242) && (x242<x189)) ==> ((x177[x242]<=x177[x186]) || (x178[x242]<=x178[x186]))))) && __Int_Int___Permut{Pre,Here}(x177,x178,x179)) && (\forall int  x263; (\forall int  x264; (((((0<=x263) && (x263<x179)) && (0<=x264)) && (x264<x179)) ==> \separated(x177+x263,x178+x264)))));
    loop assigns x189, x186;
    loop variant (x182-x189);
    */
    for(int x189=0; x189 < x187; x189++) {
      int x190 = x186;
      int x191 = x177[x190];
      int x192 = x178[x190];
      int x193 = x177[x189];
      int x194 = x178[x189];
      int x195 = x191 <= x193;
      int x196 = x192 <= x194;
      int x197 = x195 || x196;
      if (x197) {
        x186 = x189;
      } else {
        //@assert ((x177[x189]<=x177[x186]) || (x178[x189]<=x178[x186]));
      }
    }
    int x291 = x186;
    int x290 = x187 - 1;
    inswap___Int_Int__(x177,x178,x290,x291,x179);
    //@assert (\forall int  x293; ((((x182-1)<x293) && (x293<(x179-1))) ==> ((x177[x293]<=x177[(x293+1)]) || (x178[x293]<=x178[(x293+1)]))));
    //@assert ((x182<=(x179-1)) ==> ((x177[(x182-1)]<=x177[x182]) || (x178[(x182-1)]<=x178[x182])));
    //@assert (\forall int  x330; (((0<=x330) && (x330<x182)) ==> ((x177[x330]<=x177[(x182-1)]) || (x178[x330]<=x178[(x182-1)]))));
    x182 = x290;
  }
}
