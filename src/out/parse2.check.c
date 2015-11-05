#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..strlen(x0))));
assigns \nothing;
ensures ((\result==-1) || (0<=\result));
*/
int p(char  * x0) {
  char  *x5 = x0;
  int x6 = 1/*true*/;
  int x7 = 0;
  int x2 = INT_MAX;
  int x3 = x2 / 10;
  int x4 = x3 - 10;
  /*@
  loop invariant (((strlen(x5)>=0) && \valid(x5+(0..strlen(x5)))) && ((x7==-1) || (0<=x7)));
  loop assigns x5, x6, x7;
  */
  for (;;) {
    int x8 = x6;
    if (!x8) break;
    char  *x10 = x5;
    int x17 = 1/*true*/;
    char x18 = '\0';
    char  *x19 = 0/*null*/;
    char x11 = x10[0];
    int x12 = x11 == '\0';
    if (x12) {
      x19 = x10;
    } else {
      int x13 = x11 >= '0';
      int x15;
      if (x13) {
        int x14 = x11 <= '9';
        x15 = x14;
      } else {
        x15 = 0/*false*/;
      }
      if (x15) {
        x17 = 0/*false*/;
        x18 = x11;
        char  *x16 = x10+1;
        x19 = x16;
      } else {
        x19 = x10;
      }
    }
    int x31 = x17;
    if (x31) {
      char  *x32 = x19;
      x6 = 0/*false*/;
    } else {
      char x35 = x18;
      char  *x37 = x19;
      int x38 = x7;
      int x39 = x38 < 0;
      int x44;
      if (x39) {
        x44 = x38;
      } else {
        int x40 = x38 > x4;
        int x43;
        if (x40) {
          x43 = -1;
        } else {
          char x36 = x35 - '0';
          int x41 = x38 * 10;
          int x42 = x41 + x36;
          x43 = x42;
        }
        x44 = x43;
      }
      x7 = x44;
      x5 = x37;
    }
  }
  int x70 = x7;
  char  *x71 = x5;
  int x72 = -1;
  x72 = x70;
  int x74 = x72;
  return x74;
}
