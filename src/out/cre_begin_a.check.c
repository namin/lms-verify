#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0))));
*/
int matcher_begin_a(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == '\0';
  int x6;
  if (x3) {
    x6 = 0/*false*/;
  } else {
    int x5 = 'a' == x2;
    x6 = x5;
  }
  int x8;
  if (x6) {
    x8 = 1/*true*/;
  } else {
    x8 = 0/*false*/;
  }
  return x8;
}
