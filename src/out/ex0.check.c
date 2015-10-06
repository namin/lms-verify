#include <limits.h>
/*@
assigns \nothing;
ensures (\result>x0);
*/
int inc(int  x0) {
  int x2 = x0 + 1;
  return x2;
}
