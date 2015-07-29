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
