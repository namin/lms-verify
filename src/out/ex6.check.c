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
requires ((x23>0) && \valid(x22+(0..x23-1)));
ensures (\forall int  x174; (((0<=x174) && (x174<(x23-1))) ==> (x22[x174]<=x22[(x174+1)])));
assigns x22[(0..x23-1)];
*/
void insort(int  * x22, int  x23) {
  int x26 = x23;
  /*@
  loop invariant ((((0<=x26) && (x26<=x23)) && (\forall int  x130; (((x26<=x130) && (x130<(x23-1))) ==> (x22[x130]<=x22[(x130+1)])))) && (\forall int  x143; ((((0<=x143) && (x143<x26)) && (x26<=(x23-1))) ==> (x22[x143]<=x22[x26]))));
  loop assigns x26, x22[(0..x23-1)];
  loop variant x26;
  */
  for (;;) {
    int x27 = x26;
    int x28 = x27 > 1;
    if (!x28) break;
    int x30 = 0;
    int x31 = x26;
    /*@
    loop invariant ((((((((0<=x26) && (x26<=x23)) && (0<=x33)) && (x33<=x26)) && (0<=x30)) && (x30<=(x26-1))) && ((x26-1)<x23)) && (\forall int  x62; (((0<=x62) && (x62<x33)) ==> (x22[x62]<=x22[x30]))));
    loop assigns x33, x30;
    loop variant (x26-x33);
    */
    for(int x33=0; x33 < x31; x33++) {
      int x34 = x22[x33];
      int x35 = x30;
      int x36 = x22[x35];
      int x37 = x34 >= x36;
      if (x37) {
        x30 = x33;
      } else {
      }
    }
    int x82 = x30;
    int x81 = x31 - 1;
    inswap(x22,x81,x82);
    //@assert (\forall int  x84; ((((x26-1)<x84) && (x84<(x23-1))) ==> (x22[x84]<=x22[(x84+1)])));
    //@assert ((x26<=(x23-1)) ==> (x22[(x26-1)]<=x22[x26]));
    //@assert (\forall int  x108; (((0<=x108) && (x108<x26)) ==> (x22[x108]<=x22[(x26-1)])));
    x26 = x81;
  }
}
