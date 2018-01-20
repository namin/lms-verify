#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..(strlen(x0)+1)-1)));
*/
int matcher(char  * x0) {
  int x2 = strlen(x0);
  int x3 = 0 < x2;
  int x6;
  if (x3) {
    char x4 = x0[0];
    int x5 = 'a' == x4;
    x6 = x5;
  } else {
    x6 = 0/*false*/;
  }
  int x8;
  if (x6) {
    x8 = 1/*true*/;
  } else {
    x8 = 0/*false*/;
  }
  return x8;
}
