#include <limits.h>
/*@
requires (x0>=0);
assigns \nothing;
ensures (\result==(x0+x1));
*/
int plus(int  x0, int  x1) {
  int x3 = x0 == 0;
  int x8;
  if (x3) {
    x8 = x1;
  } else {
    int x4 = x0 - 1;
    int x5 = x1 + 1;
    int x6 = plus(x4,x5);
    x8 = x6;
  }
  return x8;
}
