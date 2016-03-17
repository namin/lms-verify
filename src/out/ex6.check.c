#include <limits.h>
/*@
requires (\valid(x0+x1) && \valid(x0+x2));
ensures ((x0[x1]==\old(x0[x2])) && (x0[x2]==\old(x0[x1])));
assigns x0[x1], x0[x2];
*/
void inswap(int  * x0, int  x1, int  x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}
/*@
requires ((x26>0) && \valid(x25+(0..x26-1)));
ensures (\forall int  x203; (((0<=x203) && (x203<(x26-1))) ==> (x25[x203]<=x25[(x203+1)])));
assigns x25[(0..x26-1)];
*/
void insort(int  * x25, int  x26) {
  int x29 = x26;
  /*@
  loop invariant ((((0<=x29) && (x29<=x26)) && (\forall int  x152; (((x29<=x152) && (x152<(x26-1))) ==> (x25[x152]<=x25[(x152+1)])))) && (\forall int  x168; ((((0<=x168) && (x168<x29)) && (x29<=(x26-1))) ==> (x25[x168]<=x25[x29]))));
  loop assigns x29, x25[(0..x26-1)];
  loop variant x29;
  */
  for (;;) {
    int x30 = x29;
    int x31 = x30 > 1;
    if (!x31) break;
    int x33 = 0;
    int x34 = x29;
    /*@
    loop invariant ((((((((0<=x29) && (x29<=x26)) && (0<=x36)) && (x36<=x29)) && (0<=x33)) && (x33<=(x29-1))) && ((x29-1)<x26)) && (\forall int  x74; (((0<=x74) && (x74<x36)) ==> (x25[x74]<=x25[x33]))));
    loop assigns x36, x33;
    loop variant (x29-x36);
    */
    for(int x36=0; x36 < x34; x36++) {
      int x37 = x25[x36];
      int x38 = x33;
      int x39 = x25[x38];
      int x40 = x37 >= x39;
      if (x40) {
        x33 = x36;
      } else {
      }
    }
    int x96 = x33;
    int x95 = x34 - 1;
    inswap(x25,x95,x96);
    //@assert (\forall int  x98; ((((x29-1)<x98) && (x98<(x26-1))) ==> (x25[x98]<=x25[(x98+1)])));
    //@assert ((x29<=(x26-1)) ==> (x25[(x29-1)]<=x25[x29]));
    //@assert (\forall int  x127; (((0<=x127) && (x127<x29)) ==> (x25[x127]<=x25[(x29-1)])));
    x29 = x95;
  }
}
