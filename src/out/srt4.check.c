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
requires (inv_vec___Int_Int__(x325,x326,x327) && (\forall int  x909; (\forall int  x910; (((((0<=x909) && (x909<x327)) && (0<=x910)) && (x910<x327)) ==> \separated(x325+x909,x326+x910)))));
ensures ((inv_vec___Int_Int__(x325,x326,x327) && (\forall int  x930; (\forall int  x931; (((((0<=x930) && (x930<x327)) && (0<=x931)) && (x931<x327)) ==> \separated(x325+x930,x326+x931))))) && ((\forall int  x950; (((0<=x950) && (x950<(x327-1))) ==> ((x325[x950]<x325[(x950+1)]) || ((x325[x950]==x325[(x950+1)]) && (x326[x950]<=x326[(x950+1)]))))) && __Int_Int___Permut{Old,Post}(x325,x326,x327)));
assigns x325[(0..x327-1)], x326[(0..x327-1)];
*/
void insort_pairs(int  * x325, int  * x326, int  x327) {
  //@assert (\forall int x331; (0<=x331<x327) ==> (\forall int x334; (0<=x334<x327) ==> (\forall int x337; (0<=x337<x327) ==> ((((x325[x331]<x325[x334]) || ((x325[x331]==x325[x334]) && (x326[x331]<=x326[x334]))) && ((x325[x334]<x325[x337]) || ((x325[x334]==x325[x337]) && (x326[x334]<=x326[x337])))) ==> ((x325[x331]<x325[x337]) || ((x325[x331]==x325[x337]) && (x326[x331]<=x326[x337])))))));
  int x638 = x327 - 1;
  /*@
  loop invariant (x640==0 && x638==-1) || (0<=x640<=x638);
  loop invariant (\forall int  x646; (((0<=x646) && (x646<x640)) ==> ((x325[x646]<x325[(x646+1)]) || ((x325[x646]==x325[(x646+1)]) && (x326[x646]<=x326[(x646+1)])))));
  loop invariant ((x640>0) ==> (\forall int  x667; (((x640<=x667) && (x667<x327)) ==> ((x325[(x640-1)]<x325[x667]) || ((x325[(x640-1)]==x325[x667]) && (x326[(x640-1)]<=x326[x667]))))));
  loop invariant __Int_Int___Permut{Pre,Here}(x325,x326,x327);
  loop invariant (\forall int  x690; (\forall int  x691; (((((0<=x690) && (x690<x327)) && (0<=x691)) && (x691<x327)) ==> \separated(x325+x690,x326+x691))));
  loop invariant ((x327==0) || ((x327>0) && (\valid(x325+(0..x327-1)) && \valid(x326+(0..x327-1)))));
  loop assigns x640, x325[(0..x327-1)], x326[(0..x327-1)];
  loop variant x638-x640;
  */
  for(int x640=0; x640 < x638; x640++) {
    int x730 = x640;
    int x731 = x640 + 1;
    /*@
    loop invariant 0<=x733<=x327;
    loop invariant (\forall int  x734; (((x640<=x734) && (x734<x733)) ==> ((x325[x730]<x325[x734]) || ((x325[x730]==x325[x734]) && (x326[x730]<=x326[x734])))));
    loop invariant ((x640<=x730) && (x730<x733));
    loop assigns x733, x730;
    loop variant x327-x733;
    */
    for(int x733=x731; x733 < x327; x733++) {
      int x761 = x325[x733];
      int x762 = x326[x733];
      int x763 = x730;
      int x764 = x325[x763];
      int x765 = x326[x763];
      int x766 = x761 < x764;
      int x767 = x761 == x764;
      int x769;
      if (x767) {
        int x768 = x762 <= x765;
        x769 = x768;
      } else {
        x769 = 0/*false*/;
      }
      int x770 = x766 || x769;
      if (x770) {
        x730 = x733;
      } else {
        //@assert ((x325[x730]<x325[x733]) || ((x325[x730]==x325[x733]) && (x326[x730]<=x326[x733])));
      }
    }
    //@assert ((x325[x730]<x325[(x640+1)]) || ((x325[x730]==x325[(x640+1)]) && (x326[x730]<=x326[(x640+1)])));
    int x804 = x730;
    inswap___Int_Int__(x325,x326,x327,x640,x804);
    //@assert (\forall int  x807; (((0<=x807) && (x807<(x640-1))) ==> ((x325[x807]<x325[(x807+1)]) || ((x325[x807]==x325[(x807+1)]) && (x326[x807]<=x326[(x807+1)])))));
    //@assert (\forall int  x828; (((0<=x828) && (x828<x640)) ==> ((x325[x828]<x325[(x828+1)]) || ((x325[x828]==x325[(x828+1)]) && (x326[x828]<=x326[(x828+1)])))));
    //@assert ((x325[x640]<x325[(x640+1)]) || ((x325[x640]==x325[(x640+1)]) && (x326[x640]<=x326[(x640+1)])));
    //@assert (\forall int  x863; (((0<=x863) && (x863<(x640+1))) ==> ((x325[x863]<x325[(x863+1)]) || ((x325[x863]==x325[(x863+1)]) && (x326[x863]<=x326[(x863+1)])))));
    //@assert (\forall int  x885; ((((x640+1)<=x885) && (x885<x327)) ==> ((x325[x640]<x325[x885]) || ((x325[x640]==x325[x885]) && (x326[x640]<=x326[x885])))));
  }
}
