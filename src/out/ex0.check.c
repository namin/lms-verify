#include <limits.h>
/*@
requires (x0<INT_MAX);
assigns \nothing;
ensures (\result>x0);
*/
int inc(int  x0) {
  int x2 = x0 + 1;
  return x2;
}
