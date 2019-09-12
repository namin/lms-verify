#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0))));
assigns \nothing;
*/
int p(char  * x0) {
  char  *x2 = x0;
  int x3 = 1/*true*/;
  int x4 = 0;
  /*@
  loop invariant ((strlen(x2)>=0) &&
  \valid(x2+(0..strlen(x2))));
  loop assigns x2, x3, x4;
  */
  for (;;) {
    int x5 = x3;
    if (!x5) break;
    char  *x7 = x2;
    int x14 = 1/*true*/;
    char x15 = '\0';
    char  *x16 = 0/*null*/;
    char x8 = x7[0];
    int x9 = x8 == '\0';
    if (x9) {
      x16 = x7;
    } else {
      int x10 = x8 >= '0';
      int x12;
      if (x10) {
        int x11 = x8 <= '9';
        x12 = x11;
      } else {
        x12 = 0/*false*/;
      }
      if (x12) {
        x14 = 0/*false*/;
        x15 = x8;
        char  *x13 = x7+1;
        x16 = x13;
      } else {
        x16 = x7;
      }
    }
    int x28 = x14;
    if (x28) {
      char  *x29 = x16;
      x3 = 0/*false*/;
    } else {
      char x32 = x15;
      char  *x34 = x16;
      int x35 = x4;
      char x33 = x32 - '0';
      int x36 = x35 * 10;
      int x37 = x36 + x33;
      x4 = x37;
      x2 = x34;
    }
  }
  int x58 = x4;
  char  *x59 = x2;
  int x60 = -1;
  x60 = x58;
  int x62 = x60;
  return x62;
}
