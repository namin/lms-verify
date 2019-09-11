#include <limits.h>
#include <string.h>
int  nfa_1(char  * x12);
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
int  nfa_2(char  * x30);
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
int  nfa_3(char  * x48);
/*@
assigns \nothing;
*/
int nfa_2(char  * x32) {
  char x34 = x32[0];
  int x35 = x34 == '\0';
  int x46;
  if (x35) {
    x46 = 0/*false*/;
  } else {
    int x36 = 'B' == x34;
    int x40;
    if (x36) {
      char  *x37 = x32+1;
      int x38 = nfa_2(x37);
      x40 = x38;
    } else {
      x40 = 0/*false*/;
    }
    int x41 = 'C' == x34;
    int x44;
    if (x41) {
      char  *x37 = x32+1;
      int x42 = nfa_3(x37);
      x44 = x42;
    } else {
      x44 = x40;
    }
    x46 = x44;
  }
  return x46;
}
int  nfa_4(char  * x70);
/*@
assigns \nothing;
*/
int nfa_3(char  * x50) {
  char x52 = x50[0];
  int x53 = x52 == '\0';
  int x68;
  if (x53) {
    x68 = 0/*false*/;
  } else {
    int x54 = 'B' == x52;
    int x58;
    if (x54) {
      char  *x55 = x50+1;
      int x56 = nfa_2(x55);
      x58 = x56;
    } else {
      x58 = 0/*false*/;
    }
    int x59 = 'C' == x52;
    int x62;
    if (x59) {
      char  *x55 = x50+1;
      int x60 = nfa_3(x55);
      x62 = x60;
    } else {
      x62 = x58;
    }
    int x63 = 'D' == x52;
    int x66;
    if (x63) {
      char  *x55 = x50+1;
      int x64 = nfa_4(x55);
      x66 = x64;
    } else {
      x66 = x62;
    }
    x68 = x66;
  }
  return x68;
}
/*@
assigns \nothing;
*/
int nfa_4(char  * x72) {
  char x74 = x72[0];
  int x75 = x74 == '\0';
  int x82;
  if (x75) {
    x82 = 1/*true*/;
  } else {
    int x76 = 'D' == x74;
    int x80;
    if (x76) {
      char  *x77 = x72+1;
      int x78 = nfa_4(x77);
      x80 = x78;
    } else {
      x80 = 0/*false*/;
    }
    x82 = x80;
  }
  return x82;
}
