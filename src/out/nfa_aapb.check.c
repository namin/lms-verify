#include <limits.h>
int nfa_1(char  * x12);
/*@
assigns \nothing;
*/
int nfa_0(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == '\0';
  int x10;
  if (x3) {
    x10 = 0/*false*/;
  } else {
    int x4 = 'A' == x2;
    int x8;
    if (x4) {
      char  *x5 = x0+1;
      int x6 = nfa_1(x5);
      x8 = x6;
    } else {
      x8 = 0/*false*/;
    }
    x10 = x8;
  }
  return x10;
}
int nfa_2(char  * x30);
/*@
assigns \nothing;
*/
int nfa_1(char  * x14) {
  char x16 = x14[0];
  int x17 = x16 == '\0';
  int x28;
  if (x17) {
    x28 = 0/*false*/;
  } else {
    int x18 = 'A' == x16;
    int x22;
    if (x18) {
      char  *x19 = x14+1;
      int x20 = nfa_1(x19);
      x22 = x20;
    } else {
      x22 = 0/*false*/;
    }
    int x23 = 'B' == x16;
    int x26;
    if (x23) {
      char  *x19 = x14+1;
      int x24 = nfa_2(x19);
      x26 = x24;
    } else {
      x26 = x22;
    }
    x28 = x26;
  }
  return x28;
}
/*@
assigns \nothing;
*/
int nfa_2(char  * x32) {
  char x34 = x32[0];
  int x35 = x34 == '\0';
  int x36;
  if (x35) {
    x36 = 1/*true*/;
  } else {
    x36 = 0/*false*/;
  }
  return x36;
}
