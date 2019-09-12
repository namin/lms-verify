#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0))));
*/
int matcher_a_end(char  * x0) {
  int x2 = 0/*false*/;
  int x3 = 1/*true*/;
  char  *x4 = x0;
  /*@
  loop invariant ((strlen(x4)>=0) &&
  \valid(x4+(0..strlen(x4))));
  loop assigns x2, x3, x4;
  loop variant ((strlen(x4)+((x2) ? (0) : (1)))+((x3) ? (1) : (0)));
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
    int x20;
    if (x16) {
      char  *x17 = x11+1;
      char x18 = x17[0];
      int x19 = x18 == '\0';
      x20 = x19;
    } else {
      x20 = 0/*false*/;
    }
    x2 = x20;
    int x22 = x2;
    if (x22) {
    } else {
      int x14 = !x13;
      x3 = x14;
      int x25 = x3;
      if (x25) {
        char  *x17 = x11+1;
        x4 = x17;
      } else {
      }
    }
  }
  int x56 = x2;
  return x56;
}
