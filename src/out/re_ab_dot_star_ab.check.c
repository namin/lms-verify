#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..strlen(x0))));
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
      int x15 = x0[x13];
      int x16 = 'a' == x15;
      int x17 = 0/*false*/ || x16;
      x18 = x17;
    } else {
      x18 = 0/*false*/;
    }
    int x100;
    if (x18) {
      int x19 = x13 + 1;
      int x20 = x19 < x7;
      int x24;
      if (x20) {
        int x21 = x0[x19];
        int x22 = 'b' == x21;
        int x23 = 0/*false*/ || x22;
        x24 = x23;
      } else {
        x24 = 0/*false*/;
      }
      int x99;
      if (x24) {
        int x25 = x19 + 1;
        int x26 = x25;
        int x27 = x26;
        int x28 = x27 < x7;
        int x32;
        if (x28) {
          int x29 = x0[x27];
          int x30 = 'a' == x29;
          int x31 = 0/*false*/ || x30;
          x32 = x31;
        } else {
          x32 = 0/*false*/;
        }
        int x41;
        if (x32) {
          int x33 = x27 + 1;
          int x34 = x33 < x7;
          int x38;
          if (x34) {
            int x35 = x0[x33];
            int x36 = 'b' == x35;
            int x37 = 0/*false*/ || x36;
            x38 = x37;
          } else {
            x38 = 0/*false*/;
          }
          int x40;
          if (x38) {
            x40 = 1/*true*/;
          } else {
            x40 = 0/*false*/;
          }
          x41 = x40;
        } else {
          x41 = 0/*false*/;
        }
        int x42 = x41;
        int x43 = 0/*false*/;
        /*@
        loop invariant ((((x2+1)+1)<=x26) && (x26<=strlen(x0)));
        loop assigns x26, x42, x43;
        loop variant (strlen(x0)-x26);
        */
        for (;;) {
          int x44 = x43;
          int x45 = !x44;
          int x49;
          if (x45) {
            int x46 = x42;
            int x47 = !x46;
            x49 = x47;
          } else {
            x49 = 0/*false*/;
          }
          int x53;
          if (x49) {
            int x50 = x26;
            int x51 = x50 < x7;
            x53 = x51;
          } else {
            x53 = 0/*false*/;
          }
          if (!x53) break;
          int x55 = x26;
          int x56 = x0[x55];
          int x57 = '.' == x56;
          int x58 = 1/*true*/ || x57;
          int x59 = !x58;
          x43 = x59;
          x26 += 1;
          int x62 = x26;
          int x63 = x62 < x7;
          int x67;
          if (x63) {
            int x64 = x0[x62];
            int x65 = 'a' == x64;
            int x66 = 0/*false*/ || x65;
            x67 = x66;
          } else {
            x67 = 0/*false*/;
          }
          int x76;
          if (x67) {
            int x68 = x62 + 1;
            int x69 = x68 < x7;
            int x73;
            if (x69) {
              int x70 = x0[x68];
              int x71 = 'b' == x70;
              int x72 = 0/*false*/ || x71;
              x73 = x72;
            } else {
              x73 = 0/*false*/;
            }
            int x75;
            if (x73) {
              x75 = 1/*true*/;
            } else {
              x75 = 0/*false*/;
            }
            x76 = x75;
          } else {
            x76 = 0/*false*/;
          }
          x42 = x76;
        }
        int x93 = x43;
        int x94 = !x93;
        int x97;
        if (x94) {
          int x95 = x42;
          x97 = x95;
        } else {
          x97 = 0/*false*/;
        }
        x99 = x97;
      } else {
        x99 = 0/*false*/;
      }
      x100 = x99;
    } else {
      x100 = 0/*false*/;
    }
    x3 = x100;
  }
  int x116 = x3;
  return x116;
}
