#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..(strlen(x0)+1)-1)));
*/
int matcher_a(char  * x0) {
  int x2 = 0/*false*/;
  int x3 = 1/*true*/;
  char  *x4 = x0;
  /*@
  loop invariant ((strlen(x4)>=0) &&
  \valid(x4+(0..(strlen(x4)+1)-1)));
  loop assigns x2, x3, x4;
  loop variant ((strlen(x4)+(((!x2)) ? (1) : (0)))+((x3) ? (1) : (0)));
  */
  for (;;) {
    int x5 = x2;
    int x9;
    if (x5) {
      x9 = 0/*false*/;
    } else {
      int x7 = x3;
      x9 = x7;
    }
    if (!x9) break;
    char  *x11 = x4;
    char x12 = x11[0];
    int x13 = x12 == '\0';
    int x16;
    if (x13) {
      x16 = 0/*false*/;
    } else {
      int x15 = 'a' == x12;
      x16 = x15;
    }
    int x18;
    if (x16) {
      x18 = 1/*true*/;
    } else {
      x18 = 0/*false*/;
    }
    x2 = x18;
    int x20 = x2;
    if (x20) {
    } else {
      int x14 = !x13;
      x3 = x14;
      int x23 = x3;
      if (x23) {
        char  *x17 = x11+1;
        x4 = x17;
      } else {
      }
    }
  }
  int x56 = x2;
  return x56;
}
