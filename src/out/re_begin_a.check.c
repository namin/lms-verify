#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..strlen(x0))));
*/
int matcher(char  * x0) {
  int x2 = strlen(x0);
  int x3 = 0 < x2;
  int x7;
  if (x3) {
    int x4 = x0[0];
    int x5 = 'a' == x4;
    int x6 = 0/*false*/ || x5;
    x7 = x6;
  } else {
    x7 = 0/*false*/;
  }
  int x8;
  if (x7) {
    x8 = 1/*true*/;
  } else {
    x8 = 0/*false*/;
  }
  return x8;
}
