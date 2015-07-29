/*@
requires (\valid(x0+ (0..(x1+1)-1)) && \valid(x0+ (0..(x2+1)-1)));
ensures ((x0[x1]==\old(x0[x2])) && (x0[x2]==\old(x0[x1])));
*/
void inswap(int  * x0, int  x1, int  x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}
/*@
requires \valid(x23+ (0..x24-1));
*/
void insort(int  * x23, int  x24) {
  int x26 = x24;
  for (;;) {
    int x27 = x26;
    int x28 = x27 > 1;
    if (!x28) break;
    int x30 = 0;
    int x31 = x26;
    for(int x33=0; x33 < x31; x33++) {
      int x34 = x23[x33];
      int x35 = x30;
      int x36 = x23[x35];
      int x37 = x34 >= x36;
      if (x37) {
        x30 = x33;
      } else {
      }
    }
    int x44 = x30;
    int x43 = x31 - 1;
    inswap(x23,x43,x44);
    x26 -= 1;
  }
}
