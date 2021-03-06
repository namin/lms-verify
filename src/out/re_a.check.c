#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0))));
*/
int matcher(char  * x0) {
  int x2 = -1;
  int x3 = 0/*false*/;
  int x7 = strlen(x0);
  /*@
  loop invariant ((-1<=x2) &&
  (x2<=x7));
  loop assigns x2, x3;
  loop variant (x7-x2);
  */
  for (;;) {
    int x4 = x3;
    int x10;
    if (x4) {
      x10 = 0/*false*/;
    } else {
      int x6 = x2;
      int x8 = x6 < x7;
      x10 = x8;
    }
    if (!x10) break;
    x2 += 1;
    int x13 = x2;
    int x14 = x13 < x7;
    int x17;
    if (x14) {
      char x15 = x0[x13];
      int x16 = 'a' == x15;
      x17 = x16;
    } else {
      x17 = 0/*false*/;
    }
    int x19;
    if (x17) {
      x19 = 1/*true*/;
    } else {
      x19 = 0/*false*/;
    }
    x3 = x19;
  }
  int x35 = x3;
  return x35;
}
