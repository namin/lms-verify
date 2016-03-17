#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..(strlen(x0)+1)-1)));
*/
int matcher(char  * x0) {
  int x2 = -1;
  int x3 = 0/*false*/;
  int x7 = strlen(x0);
  /*@
  loop invariant ((-1<=x2) && (x2<=strlen(x0)));
  loop assigns x2, x3;
  loop variant (strlen(x0)-x2);
  */
  for (;;) {
    int x4 = x3;
    int x5 = !x4;
    int x10;
    if (x5) {
      int x6 = x2;
      int x8 = x6 < x7;
      x10 = x8;
    } else {
      x10 = 0/*false*/;
    }
    if (!x10) break;
    x2 += 1;
    int x13 = x2;
    int x14 = x13 < x7;
    int x18;
    if (x14) {
      char x15 = x0[x13];
      int x16 = 'a' == x15;
      int x17 = 0/*false*/ || x16;
      x18 = x17;
    } else {
      x18 = 0/*false*/;
    }
    int x20;
    if (x18) {
      x20 = 1/*true*/;
    } else {
      x20 = 0/*false*/;
    }
    x3 = x20;
  }
  int x40 = x3;
  return x40;
}
