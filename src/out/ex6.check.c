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
requires ((x22>0) && \valid(x21+(0..x22-1)));
ensures (\forall int  x255; (((0<=x255) && (x255<(x22-1))) ==> (x21[x255]<=x21[(x255+1)])));
assigns x21[(0..x22-1)];
*/
void insort(int  * x21, int  x22) {
  int x25 = x22;
  /*@
  loop invariant ((((0<=x25) && (x25<=x22)) && (\forall int  x216; (((x25<=x216) && (x216<(x22-1))) ==> (x21[x216]<=x21[(x216+1)])))) && (\forall int  x229; ((((0<=x229) && (x229<x25)) && (x25<=(x22-1))) ==> (x21[x229]<=x21[x25]))));
  loop assigns x25, x21[(0..x22-1)];
  loop variant x25;
  */
  for (;;) {
    int x26 = x25;
    int x27 = x26 > 1;
    if (!x27) break;
    int x29 = 0;
    int x30 = x25;
    /*@
    loop invariant ((((((((0<=x25) && (x25<=x22)) && (0<=x32)) && (x32<=x25)) && (0<=x29)) && (x29<=(x25-1))) && ((x25-1)<x22)) && (\forall int  x58; (((0<=x58) && (x58<x32)) ==> (x21[x58]<=x21[x29]))));
    loop assigns x32, x29;
    loop variant (x25-x32);
    */
    for(int x32=0; x32 < x30; x32++) {
      int x33 = x21[x32];
      int x34 = x29;
      int x35 = x21[x34];
      int x36 = x33 >= x35;
      if (x36) {
        x29 = x32;
      } else {
      }
    }
    //@assert (\forall int  x77; (((0<=x77) && (x77<x25)) ==> (x21[x77]<=x21[x29])));
    //@assert (((0<=x29) && (x29<=(x25-1))) && ((x25-1)<x22));
    //@assert (\forall int  x100; ((((x25-1)<x100) && (x100<(x22-1))) ==> (x21[x100]<=x21[(x100+1)])));
    //@assert (\forall int  x115; ((((0<=x115) && (x115<=(x25-1))) && (x25<=(x22-1))) ==> ((x21[x115]<=x21[x29]) && (x21[x29]<=x21[x25]))));
    //@assert ((x25<=(x22-1)) ==> (x21[x29]<=x21[x25]));
    int x144 = x29;
    int x143 = x30 - 1;
    inswap(x21,x143,x144);
    //@assert (\forall int  x146; ((((x25-1)<x146) && (x146<(x22-1))) ==> (x21[x146]<=x21[(x146+1)])));
    //@assert (\forall int  x160; (((0<=x160) && (x160<x25)) ==> (x21[x160]<=x21[(x25-1)])));
    //@assert (\forall int  x173; ((((x25-1)<x173) && (x173<(x22-1))) ==> (x21[x173]<=x21[(x173+1)])));
    //@assert ((x25<=(x22-1)) ==> (x21[(x25-1)]<=x21[x25]));
    //@assert (\forall int  x196; (((0<=x196) && (x196<x25)) ==> (x21[x196]<=x21[(x25-1)])));
    x25 = x143;
  }
}
