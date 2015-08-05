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
ensures (\forall int  x163; (((0<=x163) && (x163<(x22-1))) ==> (x21[x163]<=x21[(x163+1)])));
assigns x21[(0..x22-1)];
*/
void insort(int  * x21, int  x22) {
  int x25 = x22;
  /*@
  loop invariant ((((0<=x25) && (x25<=x22)) && (\forall int  x124; (((x25<=x124) && (x124<(x22-1))) ==> (x21[x124]<=x21[(x124+1)])))) && (\forall int  x137; ((((0<=x137) && (x137<x25)) && (x25<=(x22-1))) ==> (x21[x137]<=x21[x25]))));
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
    int x78 = x29;
    int x77 = x30 - 1;
    inswap(x21,x77,x78);
    //@assert (\forall int  x80; ((((x25-1)<x80) && (x80<(x22-1))) ==> (x21[x80]<=x21[(x80+1)])));
    //@assert ((x25<=(x22-1)) ==> (x21[(x25-1)]<=x21[x25]));
    //@assert (\forall int  x104; (((0<=x104) && (x104<x25)) ==> (x21[x104]<=x21[(x25-1)])));
    x25 = x77;
  }
}
