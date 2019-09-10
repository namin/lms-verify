#include <limits.h>
/*@ predicate star_0_0(char  * x0) = (((((((((x0[0]=='A')) ? ((x0+1)) : (0/*null*/))==0/*null*/)) ? (0/*null*/) : (star_0_0((((x0[0]=='A')) ? ((x0+1)) : (0/*null*/)))))==0/*null*/)) ? (x0) : (((((((x0[0]=='A')) ? ((x0+1)) : (0/*null*/))==0/*null*/)) ? (0/*null*/) : (star_0_0((((x0[0]=='A')) ? ((x0+1)) : (0/*null*/)))))));*/
/*@
assigns \nothing;
ensures \result == star_0_0(x0);
*/
char  * star_0_0(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == 'A';
  char  *x5;
  if (x3) {
    char  *x4 = x0+1;
    x5 = x4;
  } else {
    x5 = 0/*null*/;
  }
  int x7 = x5 == 0/*null*/;
  char  *x10;
  if (x7) {
    x10 = 0/*null*/;
  } else {
    char  *x8 = star_0_0(x5);
    x10 = x8;
  }
  int x12 = x10 == 0/*null*/;
  char  *x13;
  if (x12) {
    x13 = x0;
  } else {
    x13 = x10;
  }
  return x13;
}
/*@
assigns \nothing;
ensures ((\result ==> (((((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/))==0/*null*/)) ? (0/*null*/) : ((((star_0_0((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/)))==0/*null*/)) ? (0/*null*/) : (((((((star_0_0((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/)))[0]=='B')) ? ((star_0_0((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/)))+1)) : (0/*null*/))==0/*null*/)) ? (0/*null*/) : ((((star_0_0((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/)))[0]=='B')) ? ((star_0_0((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/)))+1)) : (0/*null*/))))))))[0]=='\0')) &&
((((((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/))==0/*null*/)) ? (0/*null*/) : ((((star_0_0((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/)))==0/*null*/)) ? (0/*null*/) : (((((((star_0_0((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/)))[0]=='B')) ? ((star_0_0((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/)))+1)) : (0/*null*/))==0/*null*/)) ? (0/*null*/) : ((((star_0_0((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/)))[0]=='B')) ? ((star_0_0((((x15[0]=='A')) ? ((x15+1)) : (0/*null*/)))+1)) : (0/*null*/))))))))[0]=='\0')==\result));
*/
int dfa(char  * x15) {
  char x17 = x15[0];
  int x18 = x17 == 'A';
  char  *x20;
  if (x18) {
    char  *x19 = x15+1;
    x20 = x19;
  } else {
    x20 = 0/*null*/;
  }
  int x22 = x20 == 0/*null*/;
  char  *x35;
  if (x22) {
    x35 = 0/*null*/;
  } else {
    char  *x23 = star_0_0(x20);
    int x25 = x23 == 0/*null*/;
    char  *x33;
    if (x25) {
      x33 = 0/*null*/;
    } else {
      char x26 = x23[0];
      int x27 = x26 == 'B';
      char  *x29;
      if (x27) {
        char  *x28 = x23+1;
        x29 = x28;
      } else {
        x29 = 0/*null*/;
      }
      int x31 = x29 == 0/*null*/;
      char  *x32;
      if (x31) {
        x32 = 0/*null*/;
      } else {
        x32 = x29;
      }
      x33 = x32;
    }
    x35 = x33;
  }
  int x38 = 1/*true*/;
  int x39 = 0;
  char  *x40 = x15;
  for (;;) {
    char  *x41 = x40;
    char x42 = x41[0];
    int x43 = x42 == '\0';
    int x47;
    if (x43) {
      x47 = 0/*false*/;
    } else {
      int x45 = x38;
      x47 = x45;
    }
    if (!x47) break;
    char  *x49 = x40;
    char x50 = x49[0];
    char x51 = x50;
    int x52 = x39;
    int x53 = x52 == 0;
    if (x53) {
      char x54 = x51;
      int x55 = 'A' == x54;
      int x58;
      if (x55) {
        x39 = 1;
        x58 = 1/*true*/;
      } else {
        x58 = 0/*false*/;
      }
      x38 = x58;
    } else {
    }
    int x62 = x39;
    int x63 = x62 == 1;
    if (x63) {
      char x64 = x51;
      int x65 = 'A' == x64;
      int x68;
      if (x65) {
        x39 = 1;
        x68 = 1/*true*/;
      } else {
        x68 = 0/*false*/;
      }
      int x69 = 'B' == x64;
      int x72;
      if (x69) {
        x39 = 2;
        x72 = 1/*true*/;
      } else {
        x72 = x68;
      }
      x38 = x72;
    } else {
    }
    int x76 = x39;
    int x77 = x76 == 2;
    if (x77) {
      x38 = 0/*false*/;
    } else {
    }
    char  *x81 = x49+1;
    x40 = x81;
  }
  char  *x85 = x40;
  char x86 = x85[0];
  int x87 = x86 == '\0';
  int x91;
  if (x87) {
    int x88 = x39;
    int x89 = 2 == x88;
    x91 = x89;
  } else {
    x91 = 0/*false*/;
  }
  return x91;
}
