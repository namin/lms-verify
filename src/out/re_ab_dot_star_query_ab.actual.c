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
    int x72;
    if (x17) {
      int x18 = x13 + 1;
      int x19 = x18 < x7;
      int x22;
      if (x19) {
        char x20 = x0[x18];
        int x21 = 'b' == x20;
        x22 = x21;
      } else {
        x22 = 0/*false*/;
      }
      int x71;
      if (x22) {
        int x23 = x18 + 1;
        int x24 = x23;
        int x25 = x24;
        int x26 = x25 < x7;
        int x29;
        if (x26) {
          char x27 = x0[x25];
          int x28 = 'a' == x27;
          x29 = x28;
        } else {
          x29 = 0/*false*/;
        }
        int x37;
        if (x29) {
          int x30 = x25 + 1;
          int x31 = x30 < x7;
          int x34;
          if (x31) {
            char x32 = x0[x30];
            int x33 = 'b' == x32;
            x34 = x33;
          } else {
            x34 = 0/*false*/;
          }
          int x36;
          if (x34) {
            x36 = 1/*true*/;
          } else {
            x36 = 0/*false*/;
          }
          x37 = x36;
        } else {
          x37 = 0/*false*/;
        }
        int x38 = x37;
        int x39 = 0/*false*/;
        int x40 = x39;
        int x45;
        if (x40) {
          x45 = 0/*false*/;
        } else {
          int x42 = x38;
          int x43 = !x42;
          x45 = x43;
        }
        int x46;
        if (x45) {
          x46 = x26;
        } else {
          x46 = 0/*false*/;
        }
        /*@
        loop invariant ((x23<=x24) &&
        (x24<=x7));
        loop assigns x24, x38, x39;
        loop variant (x7-x24);
        */
        if (x46) {
          x39 = 0/*false*/;
          x38 = x37;
        } else {
        }
        int x65 = x39;
        int x69;
        if (x65) {
          x69 = 0/*false*/;
        } else {
          int x67 = x38;
          x69 = x67;
        }
        x71 = x69;
      } else {
        x71 = 0/*false*/;
      }
      x72 = x71;
    } else {
      x72 = 0/*false*/;
    }
    x3 = x72;
  }
  int x88 = x3;
  return x88;
}
