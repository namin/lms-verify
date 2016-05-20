#include <limits.h>
/*@
requires ((((((x3>0) && (0<=x1)) && (x1<x3)) && (0<=x2)) && (x2<x3)) && \valid(x0+(0..x3-1)));
ensures ((x0[x1]==\old(x0[x2])) && (x0[x2]==\old(x0[x1])));
assigns x0[x1], x0[x2];
*/
void inswap(int  * x0, int  x1, int  x2, int  x3) {
  int x5 = x0[x1];
  int x6 = x0[x2];
  x0[x1] = x6;
  x0[x2] = x5;
}
