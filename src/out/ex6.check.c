/*@
requires (\valid(x0+x1) && \valid(x0+x2));
ensures ((x0[x1]==\old(x0[x2])) && (x0[x2]==\old(x0[x1])));
*/
void inswap(int  * x0, int  x1, int  x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}
/*@
requires \valid(x21+(0..x22-1));
*/
void insort(int  * x21, int  x22) {
  int x24 = x22;
  for (;;) {
    int x25 = x24;
    int x26 = x25 > 1;
    if (!x26) break;
    int x28 = 0;
    int x29 = x24;
    for(int x31=0; x31 < x29; x31++) {
      int x32 = x21[x31];
      int x33 = x28;
      int x34 = x21[x33];
      int x35 = x32 >= x34;
      if (x35) {
        x28 = x31;
      } else {
      }
    }
    int x42 = x28;
    int x41 = x29 - 1;
    inswap(x21,x41,x42);
    x24 -= 1;
  }
}
