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
requires (inv_vec___Int_Int__(x325,x326,x327) && (\forall int  x547; (\forall int  x548; (((((0<=x547) && (x547<x327)) && (0<=x548)) && (x548<x327)) ==> \separated(x325+x547,x326+x548)))));
ensures ((inv_vec___Int_Int__(x325,x326,x327) && (\forall int  x568; (\forall int  x569; (((((0<=x568) && (x568<x327)) && (0<=x569)) && (x569<x327)) ==> \separated(x325+x568,x326+x569))))) && ((\forall int  x588; (((0<=x588) && (x588<(x327-1))) ==> (x325[x588]<=x325[(x588+1)]))) && __Int_Int___Permut{Old,Post}(x325,x326,x327)));
assigns x325[(0..x327-1)], x326[(0..x327-1)];
*/
void insort_pairs(int  * x325, int  * x326, int  x327) {
  int x330 = x327 - 1;
  /*@
  loop invariant (x332==0 && x330==-1) || (0<=x332<=x330);
  loop invariant (\forall int  x338; (((0<=x338) && (x338<x332)) ==> (x325[x338]<=x325[(x338+1)])));
  loop invariant ((x332>0) ==> (\forall int  x354; (((x332<=x354) && (x354<x327)) ==> (x325[(x332-1)]<=x325[x354]))));
  loop invariant __Int_Int___Permut{Pre,Here}(x325,x326,x327);
  loop invariant (\forall int  x372; (\forall int  x373; (((((0<=x372) && (x372<x327)) && (0<=x373)) && (x373<x327)) ==> \separated(x325+x372,x326+x373))));
  loop invariant ((x327==0) || ((x327>0) && (\valid(x325+(0..x327-1)) && \valid(x326+(0..x327-1)))));
  loop assigns x332, x325[(0..x327-1)], x326[(0..x327-1)];
  loop variant x330-x332;
  */
  for(int x332=0; x332 < x330; x332++) {
    int x412 = x332;
    int x413 = x332 + 1;
    /*@
    loop invariant 0<=x415<=x327;
    loop invariant (\forall int  x416; (((x332<=x416) && (x416<x415)) ==> (x325[x412]<=x325[x416])));
    loop invariant ((x332<=x412) && (x412<x415));
    loop assigns x415, x412;
    loop variant x327-x415;
    */
    for(int x415=x413; x415 < x327; x415++) {
      int x438 = x325[x415];
      int x439 = x326[x415];
      int x440 = x412;
      int x441 = x325[x440];
      int x442 = x326[x440];
      int x443 = x438 <= x441;
      if (x443) {
        x412 = x415;
      } else {
        //@assert (x325[x412]<=x325[x415]);
      }
    }
    //@assert (x325[x412]<=x325[(x332+1)]);
    int x467 = x412;
    inswap___Int_Int__(x325,x326,x327,x332,x467);
    //@assert (\forall int  x470; (((0<=x470) && (x470<(x332-1))) ==> (x325[x470]<=x325[(x470+1)])));
    //@assert (\forall int  x486; (((0<=x486) && (x486<x332)) ==> (x325[x486]<=x325[(x486+1)])));
    //@assert (x325[x332]<=x325[(x332+1)]);
    //@assert (\forall int  x511; (((0<=x511) && (x511<(x332+1))) ==> (x325[x511]<=x325[(x511+1)])));
    //@assert (\forall int  x528; ((((x332+1)<=x528) && (x528<x327)) ==> (x325[x332]<=x325[x528])));
  }
}
