#include <limits.h>
/*@
assigns \nothing;
*/
int dfa(char  * x0) {
  int x2 = 1/*true*/;
  int x3 = 0;
  char  *x4 = x0;
  for (;;) {
    char  *x5 = x4;
    char x6 = x5[0];
    int x7 = x6 == '\0';
    int x11;
    if (x7) {
      x11 = 0/*false*/;
    } else {
      int x9 = x2;
      x11 = x9;
    }
    if (!x11) break;
    char  *x13 = x4;
    char x14 = x13[0];
    char x15 = x14;
    int x16 = x3;
    int x17 = x16 == 0;
    if (x17) {
      /*@assert (0==0);*/
      /*@assert (0==1);*/
      char x24 = x15;
      int x25 = 'A' == x24;
      int x28;
      if (x25) {
        x3 = 1;
        x28 = 1/*true*/;
      } else {
        x28 = 0/*false*/;
      }
      /*@assert (0==2);*/
      x2 = x28;
    } else {
    }
    int x35 = x3;
    int x36 = x35 == 1;
    if (x36) {
      /*@assert (1==0);*/
      /*@assert (1==1);*/
      char x43 = x15;
      int x44 = 'A' == x43;
      int x47;
      if (x44) {
        x3 = 1;
        x47 = 1/*true*/;
      } else {
        x47 = 0/*false*/;
      }
      /*@assert (1==2);*/
      int x51 = 'B' == x43;
      int x54;
      if (x51) {
        x3 = 2;
        x54 = 1/*true*/;
      } else {
        x54 = x47;
      }
      x2 = x54;
    } else {
    }
    int x58 = x3;
    int x59 = x58 == 2;
    if (x59) {
      /*@assert (2==0);*/
      /*@assert (2==1);*/
      /*@assert (2==2);*/
      x2 = 0/*false*/;
    } else {
    }
    char  *x72 = x13+1;
    x4 = x72;
  }
  char  *x76 = x4;
  char x77 = x76[0];
  int x78 = x77 == '\0';
  int x82;
  if (x78) {
    int x79 = x3;
    int x80 = 2 == x79;
    x82 = x80;
  } else {
    x82 = 0/*false*/;
  }
  return x82;
}
