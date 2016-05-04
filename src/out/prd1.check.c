#include <limits.h>
/*@
requires (x0>0);
assigns \nothing;
ensures (\result>=0);
*/
int minus1(int  x0) {
  int x2 = x0 - 1;
  return x2;
}
