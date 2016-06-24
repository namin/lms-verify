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
  \forall int  * x57, int  * x58, integer  x59; (\forall integer  x61; (\forall integer  x62; ((((((0<=x61) && (x61<x59)) && (0<=x62)) && (x62<x59)) && (((\at(eq___Int_Int__(\at(x57[x61],L1),\at(x58[x61],L1),\at(x57[x62],L2),\at(x58[x62],L2)),L1) && \at(eq___Int_Int__(\at(x57[x61],L1),\at(x58[x61],L1),\at(x57[x62],L2),\at(x58[x62],L2)),L2)) && (\at(eq___Int_Int__(\at(x57[x62],L1),\at(x58[x62],L1),\at(x57[x61],L2),\at(x58[x61],L2)),L1) && \at(eq___Int_Int__(\at(x57[x62],L1),\at(x58[x62],L1),\at(x57[x61],L2),\at(x58[x61],L2)),L2))) && (\forall integer  x119; (((((0<=x119) && (x119<x59)) && (x119!=x61)) && (x119!=x62)) ==> (\at(eq___Int_Int__(\at(x57[x119],L1),\at(x58[x119],L1),\at(x57[x119],L2),\at(x58[x119],L2)),L1) && \at(eq___Int_Int__(\at(x57[x119],L1),\at(x58[x119],L1),\at(x57[x119],L2),\at(x58[x119],L2)),L2)))))) ==> __Int_Int___Permut{L1,L2}(x57,x58,x59))));
}
*/
/*@
requires ((inv_vec___Int_Int__(x165,x166,x167) && ((((0<=x168) && (x168<x167)) && (0<=x169)) && (x169<x167))) && (\forall int  x195; (\forall int  x196; (((((0<=x195) && (x195<x167)) && (0<=x196)) && (x196<x167)) ==> \separated(x165+x195,x166+x196)))));
ensures (((inv_vec___Int_Int__(x165,x166,x167) && (((\at(eq___Int_Int__(\at(x165[x168],Old),\at(x166[x168],Old),\at(x165[x169],Post),\at(x166[x169],Post)),Old) && \at(eq___Int_Int__(\at(x165[x168],Old),\at(x166[x168],Old),\at(x165[x169],Post),\at(x166[x169],Post)),Post)) && (\at(eq___Int_Int__(\at(x165[x169],Old),\at(x166[x169],Old),\at(x165[x168],Post),\at(x166[x168],Post)),Old) && \at(eq___Int_Int__(\at(x165[x169],Old),\at(x166[x169],Old),\at(x165[x168],Post),\at(x166[x168],Post)),Post))) && (\forall int  x264; (((((0<=x264) && (x264<x167)) && (x264!=x168)) && (x264!=x169)) ==> (\at(eq___Int_Int__(\at(x165[x264],Old),\at(x166[x264],Old),\at(x165[x264],Post),\at(x166[x264],Post)),Old) && \at(eq___Int_Int__(\at(x165[x264],Old),\at(x166[x264],Old),\at(x165[x264],Post),\at(x166[x264],Post)),Post)))))) && __Int_Int___Permut{Old,Post}(x165,x166,x167)) && (\forall int  x305; (\forall int  x306; (((((0<=x305) && (x305<x167)) && (0<=x306)) && (x306<x167)) ==> \separated(x165+x305,x166+x306)))));
assigns x165[(0..x167-1)], x166[(0..x167-1)];
*/
void inswap___Int_Int__(int  * x165, int  * x166, int  x167, int  x168, int  x169) {
  int x172 = x165[x168];
  int x173 = x166[x168];
  int x174 = x165[x169];
  int x175 = x166[x169];
  x165[x168] = x174;
  x166[x168] = x175;
  x165[x169] = x172;
  x166[x169] = x173;
}
/*@
requires (inv_vec___Int_Int__(x325,x326,x327) && (\forall int  x601; (\forall int  x602; (((((0<=x601) && (x601<x327)) && (0<=x602)) && (x602<x327)) ==> \separated(x325+x601,x326+x602)))));
ensures ((inv_vec___Int_Int__(x325,x326,x327) && (\forall int  x622; (\forall int  x623; (((((0<=x622) && (x622<x327)) && (0<=x623)) && (x623<x327)) ==> \separated(x325+x622,x326+x623))))) && ((\forall int  x642; (((0<=x642) && (x642<(x327-1))) ==> ((x325[x642]<x325[(x642+1)]) || ((x325[x642]==x325[(x642+1)]) && (x326[x642]<=x326[(x642+1)]))))) && __Int_Int___Permut{Old,Post}(x325,x326,x327)));
assigns x325[(0..x327-1)], x326[(0..x327-1)];
*/
void insort_pairs(int  * x325, int  * x326, int  x327) {
  int x330 = x327 - 1;
  /*@
  loop invariant (x332==0 && x330==-1) || (0<=x332<=x330);
  loop invariant (\forall int  x338; (((0<=x338) && (x338<x332)) ==> ((x325[x338]<x325[(x338+1)]) || ((x325[x338]==x325[(x338+1)]) && (x326[x338]<=x326[(x338+1)])))));
  loop invariant ((x332>0) ==> (\forall int  x359; (((x332<=x359) && (x359<x327)) ==> ((x325[(x332-1)]<x325[x359]) || ((x325[(x332-1)]==x325[x359]) && (x326[(x332-1)]<=x326[x359]))))));
  loop invariant __Int_Int___Permut{Pre,Here}(x325,x326,x327);
  loop invariant (\forall int  x382; (\forall int  x383; (((((0<=x382) && (x382<x327)) && (0<=x383)) && (x383<x327)) ==> \separated(x325+x382,x326+x383))));
  loop invariant ((x327==0) || ((x327>0) && (\valid(x325+(0..x327-1)) && \valid(x326+(0..x327-1)))));
  loop assigns x332, x325[(0..x327-1)], x326[(0..x327-1)];
  loop variant x330-x332;
  */
  for(int x332=0; x332 < x330; x332++) {
    int x422 = x332;
    int x423 = x332 + 1;
    /*@
    loop invariant 0<=x425<=x327;
    loop invariant (\forall int  x426; (((x332<=x426) && (x426<x425)) ==> ((x325[x422]<x325[x426]) || ((x325[x422]==x325[x426]) && (x326[x422]<=x326[x426])))));
    loop invariant ((x332<=x422) && (x422<x425));
    loop assigns x425, x422;
    loop variant x327-x425;
    */
    for(int x425=x423; x425 < x327; x425++) {
      int x453 = x325[x425];
      int x454 = x326[x425];
      int x455 = x422;
      int x456 = x325[x455];
      int x457 = x326[x455];
      int x458 = x453 < x456;
      int x459 = x453 == x456;
      int x461;
      if (x459) {
        int x460 = x454 <= x457;
        x461 = x460;
      } else {
        x461 = 0/*false*/;
      }
      int x462 = x458 || x461;
      if (x462) {
        x422 = x425;
      } else {
        //@assert ((x325[x422]<x325[x425]) || ((x325[x422]==x325[x425]) && (x326[x422]<=x326[x425])));
      }
    }
    //@assert ((x325[x422]<x325[(x332+1)]) || ((x325[x422]==x325[(x332+1)]) && (x326[x422]<=x326[(x332+1)])));
    int x496 = x422;
    inswap___Int_Int__(x325,x326,x327,x332,x496);
    //@assert (\forall int  x499; (((0<=x499) && (x499<(x332-1))) ==> ((x325[x499]<x325[(x499+1)]) || ((x325[x499]==x325[(x499+1)]) && (x326[x499]<=x326[(x499+1)])))));
    //@assert (\forall int  x520; (((0<=x520) && (x520<x332)) ==> ((x325[x520]<x325[(x520+1)]) || ((x325[x520]==x325[(x520+1)]) && (x326[x520]<=x326[(x520+1)])))));
    //@assert ((x325[x332]<x325[(x332+1)]) || ((x325[x332]==x325[(x332+1)]) && (x326[x332]<=x326[(x332+1)])));
    //@assert (\forall int  x555; (((0<=x555) && (x555<(x332+1))) ==> ((x325[x555]<x325[(x555+1)]) || ((x325[x555]==x325[(x555+1)]) && (x326[x555]<=x326[(x555+1)])))));
    //@assert (\forall int  x577; ((((x332+1)<=x577) && (x577<x327)) ==> ((x325[x332]<x325[x577]) || ((x325[x332]==x325[x577]) && (x326[x332]<=x326[x577])))));
  }
}
