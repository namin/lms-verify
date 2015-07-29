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
requires \valid(x21+(0..x22-1));
assigns x21[(0..x22-1)];
*/
void insort(int  * x21, int  x22) {
  int x25 = x22;
  for (;;) {
    int x26 = x25;
    int x27 = x26 > 1;
    if (!x27) break;
    int x29 = 0;
    int x30 = x25;
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
    int x43 = x29;
    int x42 = x30 - 1;
    inswap(x21,x42,x43);
    x25 -= 1;
  }
}
