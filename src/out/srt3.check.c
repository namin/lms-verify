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
requires (inv_vec___Int_Int__(x325,x326,x327) && (\forall int  x735; (\forall int  x736; (((((0<=x735) && (x735<x327)) && (0<=x736)) && (x736<x327)) ==> \separated(x325+x735,x326+x736)))));
ensures ((inv_vec___Int_Int__(x325,x326,x327) && (\forall int  x756; (\forall int  x757; (((((0<=x756) && (x756<x327)) && (0<=x757)) && (x757<x327)) ==> \separated(x325+x756,x326+x757))))) && ((\forall int  x776; (((0<=x776) && (x776<(x327-1))) ==> (x325[x776]<=x325[(x776+1)]))) && __Int_Int___Permut{Old,Post}(x325,x326,x327)));
assigns x325[(0..x327-1)], x326[(0..x327-1)];
*/
void insort_pairs(int  * x325, int  * x326, int  x327) {
  //@assert (\forall int x331; (0<=x331<x327) ==> (\forall int x334; (0<=x334<x327) ==> (\forall int x337; (0<=x337<x327) ==> (((x325[x331]<=x325[x334]) && (x325[x334]<=x325[x337])) ==> (x325[x331]<=x325[x337])))));
  int x518 = x327 - 1;
  /*@
  loop invariant (x520==0 && x518==-1) || (0<=x520<=x518);
  loop invariant (\forall int  x526; (((0<=x526) && (x526<x520)) ==> (x325[x526]<=x325[(x526+1)])));
  loop invariant ((x520>0) ==> (\forall int  x542; (((x520<=x542) && (x542<x327)) ==> (x325[(x520-1)]<=x325[x542]))));
  loop invariant __Int_Int___Permut{Pre,Here}(x325,x326,x327);
  loop invariant (\forall int  x560; (\forall int  x561; (((((0<=x560) && (x560<x327)) && (0<=x561)) && (x561<x327)) ==> \separated(x325+x560,x326+x561))));
  loop invariant ((x327==0) || ((x327>0) && (\valid(x325+(0..x327-1)) && \valid(x326+(0..x327-1)))));
  loop assigns x520, x325[(0..x327-1)], x326[(0..x327-1)];
  loop variant x518-x520;
  */
  for(int x520=0; x520 < x518; x520++) {
    int x600 = x520;
    int x601 = x520 + 1;
    /*@
    loop invariant 0<=x603<=x327;
    loop invariant (\forall int  x604; (((x520<=x604) && (x604<x603)) ==> (x325[x600]<=x325[x604])));
    loop invariant ((x520<=x600) && (x600<x603));
    loop assigns x603, x600;
    loop variant x327-x603;
    */
    for(int x603=x601; x603 < x327; x603++) {
      int x626 = x325[x603];
      int x627 = x326[x603];
      int x628 = x600;
      int x629 = x325[x628];
      int x630 = x326[x628];
      int x631 = x626 <= x629;
      if (x631) {
        x600 = x603;
      } else {
        //@assert (x325[x600]<=x325[x603]);
      }
    }
    //@assert (x325[x600]<=x325[(x520+1)]);
    int x655 = x600;
    inswap___Int_Int__(x325,x326,x327,x520,x655);
    //@assert (\forall int  x658; (((0<=x658) && (x658<(x520-1))) ==> (x325[x658]<=x325[(x658+1)])));
    //@assert (\forall int  x674; (((0<=x674) && (x674<x520)) ==> (x325[x674]<=x325[(x674+1)])));
    //@assert (x325[x520]<=x325[(x520+1)]);
    //@assert (\forall int  x699; (((0<=x699) && (x699<(x520+1))) ==> (x325[x699]<=x325[(x699+1)])));
    //@assert (\forall int  x716; ((((x520+1)<=x716) && (x716<x327)) ==> (x325[x520]<=x325[x716])));
  }
}
