#include <limits.h>
/*@
assigns \nothing;
ensures (((\result>=x0) && (\result>=x1)) && ((\result==x0) || (\result==x1)));
*/
int max(int  x0, int  x1) {
  int x3 = x0 > x1;
  int x4;
  if (x3) {
    x4 = x0;
  } else {
    x4 = x1;
  }
  return x4;
}
