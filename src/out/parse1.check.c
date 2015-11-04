#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..strlen(x0))));
assigns \nothing;
*/
int p(char  * x0) {
  char  *x2 = x0;
  int x3 = 1/*true*/;
  int x4 = 0;
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
      x2 = x29;
    } else {
      char x33 = x15;
      char  *x35 = x16;
      int x36 = x4;
      char x34 = x33 - '0';
      int x37 = x36 * 10;
      int x38 = x37 + x34;
      x4 = x38;
      x2 = x35;
    }
  }
  int x45 = x4;
  char  *x46 = x2;
  int x47 = -1;
  x47 = x45;
  int x49 = x47;
  return x49;
}
