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
requires (((((((x109>0) && (0<=x107)) && (x107<x109)) && (0<=x108)) && (x108<x109)) && (\valid(x105+(0..x109-1)) && \valid(x106+(0..x109-1)))) && (\forall int  x138; (\forall int  x139; (((((0<=x138) && (x138<2)) && (0<=x139)) && (x139<2)) && \separated(x105+x138,x106+x139)))));
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
requires (((x180>0) && (\valid(x178+(0..x180-1)) && \valid(x179+(0..x180-1)))) && (\forall int  x403; (\forall int  x404; (((((0<=x403) && (x403<2)) && (0<=x404)) && (x404<2)) && \separated(x178+x403,x179+x404)))));
ensures ((\forall int  x424; (((0<=x424) && (x424<(x180-1))) ==> ((x178[x424]<=x178[(x424+1)]) && (x179[x424]<=x179[(x424+1)])))) && __Int_Int___Permut{Old,Post}(x178,x179,x180));
assigns x178[(0..x180-1)], x179[(0..x180-1)];
*/
void insort_pairs(int  * x178, int  * x179, int  x180) {
  int x183 = x180;
  /*@
  loop invariant (((((0<=x183) && (x183<=x180)) && ((x183<(x180-1)) ==> (\forall int  x336; (((x183<=x336) && (x336<(x180-1))) ==> ((x178[x336]<=x178[(x336+1)]) && (x179[x336]<=x179[(x336+1)])))))) && (\forall int  x358; ((((0<=x358) && (x358<x183)) && (x183<=(x180-1))) ==> ((x178[x358]<=x178[x183]) && (x179[x358]<=x179[x183]))))) && __Int_Int___Permut{Pre,Here}(x178,x179,x180));
  loop assigns x183, x178[(0..x180-1)], x179[(0..x180-1)];
  loop variant x183;
  */
  for (;;) {
    int x184 = x183;
    int x185 = x184 > 1;
    if (!x185) break;
    int x187 = 0;
    int x188 = x183;
    /*@
    loop invariant (((((((((0<=x183) && (x183<=x180)) && (0<=x190)) && (x190<=x183)) && (0<=x187)) && (x187<=(x183-1))) && ((x183-1)<x180)) && (\forall int  x232; (((0<=x232) && (x232<x190)) ==> ((x178[x232]<=x178[x187]) && (x179[x232]<=x179[x187]))))) && __Int_Int___Permut{Pre,Here}(x178,x179,x180));
    loop assigns x190, x187;
    loop variant (x183-x190);
    */
    for(int x190=0; x190 < x188; x190++) {
      int x191 = x187;
      int x192 = x178[x191];
      int x193 = x179[x191];
      int x194 = x178[x190];
      int x195 = x179[x190];
      int x196 = x192 <= x194;
      int x198;
      if (x196) {
        int x197 = x193 <= x195;
        x198 = x197;
      } else {
        x198 = 0/*false*/;
      }
      if (x198) {
        x187 = x190;
      } else {
      }
    }
    int x262 = x187;
    int x261 = x188 - 1;
    inswap___Int_Int__(x178,x179,x261,x262,x180);
    //@assert (\forall int  x264; ((((x183-1)<x264) && (x264<(x180-1))) ==> ((x178[x264]<=x178[(x264+1)]) && (x179[x264]<=x179[(x264+1)]))));
    //@assert ((x183<=(x180-1)) ==> ((x178[(x183-1)]<=x178[x183]) && (x179[(x183-1)]<=x179[x183])));
    //@assert (\forall int  x303; (((0<=x303) && (x303<x183)) ==> ((x178[x303]<=x178[(x183-1)]) && (x179[x303]<=x179[(x183-1)]))));
    x183 = x261;
  }
}
