#include <limits.h>
#include <string.h>
/*@ logic char  * star_0_0(char  * x0) = (((((((((x0[0]=='A')) ? ((x0+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : (star_0_0((((x0[0]=='A')) ? ((x0+1)) : ((char*)0)))))==(char*)0)) ? (x0) : (((((((x0[0]=='A')) ? ((x0+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : (star_0_0((((x0[0]=='A')) ? ((x0+1)) : ((char*)0)))))));*/
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..(strlen(x0)+1)-1)));
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
/*@ logic char  * star_1_0(char  * x24) = (((((((((x24[0]=='A')) ? ((x24+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : (star_1_0((((x24[0]=='A')) ? ((x24+1)) : ((char*)0)))))==(char*)0)) ? (x24) : (((((((x24[0]=='A')) ? ((x24+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : (star_1_0((((x24[0]=='A')) ? ((x24+1)) : ((char*)0)))))));*/
/*@
requires ((strlen(x24)>=0) &&
\valid(x24+(0..(strlen(x24)+1)-1)));
assigns \nothing;
ensures \result == star_1_0(x24);
*/
char  * star_1_0(char  * x24) {
  char x26 = x24[0];
  int x27 = x26 == 'A';
  char  *x29;
  if (x27) {
    char  *x28 = x24+1;
    x29 = x28;
  } else {
    x29 = 0/*null*/;
  }
  int x31 = x29 == 0/*null*/;
  char  *x34;
  if (x31) {
    x34 = 0/*null*/;
  } else {
    char  *x32 = star_1_0(x29);
    x34 = x32;
  }
  int x36 = x34 == 0/*null*/;
  char  *x37;
  if (x36) {
    x37 = x24;
  } else {
    x37 = x34;
  }
  return x37;
}
/*@ logic char  * star_2_0(char  * x48) = (((((((((x48[0]=='A')) ? ((x48+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : (star_2_0((((x48[0]=='A')) ? ((x48+1)) : ((char*)0)))))==(char*)0)) ? (x48) : (((((((x48[0]=='A')) ? ((x48+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : (star_2_0((((x48[0]=='A')) ? ((x48+1)) : ((char*)0)))))));*/
/*@
requires ((strlen(x48)>=0) &&
\valid(x48+(0..(strlen(x48)+1)-1)));
assigns \nothing;
ensures \result == star_2_0(x48);
*/
char  * star_2_0(char  * x48) {
  char x50 = x48[0];
  int x51 = x50 == 'A';
  char  *x53;
  if (x51) {
    char  *x52 = x48+1;
    x53 = x52;
  } else {
    x53 = 0/*null*/;
  }
  int x55 = x53 == 0/*null*/;
  char  *x58;
  if (x55) {
    x58 = 0/*null*/;
  } else {
    char  *x56 = star_2_0(x53);
    x58 = x56;
  }
  int x60 = x58 == 0/*null*/;
  char  *x61;
  if (x60) {
    x61 = x48;
  } else {
    x61 = x58;
  }
  return x61;
}
/*@
requires ((strlen(x72)>=0) &&
\valid(x72+(0..(strlen(x72)+1)-1)));
assigns \nothing;
ensures (\result==((((((((x72[0]=='A')) ? ((x72+1)) : ((char*)0))!=(char*)0)) ? ((((star_0_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))!=(char*)0)) ? (((((((star_0_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))[0]=='B')) ? ((star_0_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))+1)) : ((char*)0))!=(char*)0)) ? ((((star_0_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))[0]=='B')) ? ((star_0_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))+1)) : ((char*)0))) : ((char*)0))) : ((char*)0))) : ((char*)0))!=(char*)0) &&
(((((((x72[0]=='A')) ? ((x72+1)) : ((char*)0))!=(char*)0)) ? ((((star_0_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))!=(char*)0)) ? (((((((star_0_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))[0]=='B')) ? ((star_0_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))+1)) : ((char*)0))!=(char*)0)) ? ((((star_0_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))[0]=='B')) ? ((star_0_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))+1)) : ((char*)0))) : ((char*)0))) : ((char*)0))) : ((char*)0))[0]=='\0')));
*/
int dfa(char  * x72) {
  int x74 = 1/*true*/;
  int x75 = 0;
  char  *x76 = x72;
  /*@
  loop invariant ((((strlen(x76)>=0) &&
  \valid(x76+(0..(strlen(x76)+1)-1))) &&
  (((x75==2) ==> (((((((x72[0]=='A')) ? ((x72+1)) : ((char*)0))!=(char*)0)) ? ((((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))!=(char*)0)) ? (((((((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))[0]=='B')) ? ((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))+1)) : ((char*)0))!=(char*)0)) ? ((((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))[0]=='B')) ? ((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))+1)) : ((char*)0))) : ((char*)0))) : ((char*)0))) : ((char*)0))==x76)) &&
  (((x75==1) ==> (((((((x72[0]=='A')) ? ((x72+1)) : ((char*)0))!=(char*)0)) ? ((((star_1_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))!=(char*)0)) ? (star_1_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))) : ((char*)0))) : ((char*)0))==x76)) &&
  ((x75==0) ==> (x72==x76))))) &&
  ((x75==2) || ((x75==1) || (x75==0))));
  loop assigns x76, x75, x74;
  loop variant strlen(x76);
  */
  for (;;) {
    char  *x77 = x76;
    char x78 = x77[0];
    int x79 = x78 == '\0';
    int x83;
    if (x79) {
      x83 = 0/*false*/;
    } else {
      int x81 = x74;
      x83 = x81;
    }
    if (!x83) break;
    char  *x85 = x76;
    char x86 = x85[0];
    char x87 = x86;
    int x88 = x75;
    int x89 = x88 == 0;
    if (x89) {
      /*@assert (x72!=(char*)0);*/
      char x93 = x87;
      int x94 = 'A' == x93;
      int x111;
      if (x94) {
        x75 = 1;
        /*@assert (((((((x72[0]=='A')) ? ((x72+1)) : ((char*)0))!=(char*)0)) ? ((((star_1_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))!=(char*)0)) ? (star_1_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))) : ((char*)0))) : ((char*)0))!=(char*)0);*/
        x111 = 1/*true*/;
      } else {
        x111 = 0/*false*/;
      }
      x74 = x111;
    } else {
    }
    int x115 = x75;
    int x116 = x115 == 1;
    if (x116) {
      /*@assert (((((((x72[0]=='A')) ? ((x72+1)) : ((char*)0))!=(char*)0)) ? ((((star_1_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))!=(char*)0)) ? (star_1_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))) : ((char*)0))) : ((char*)0))!=(char*)0);*/
      char x131 = x87;
      int x132 = 'A' == x131;
      int x149;
      if (x132) {
        x75 = 1;
        /*@assert (((((((x72[0]=='A')) ? ((x72+1)) : ((char*)0))!=(char*)0)) ? ((((star_1_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))!=(char*)0)) ? (star_1_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))) : ((char*)0))) : ((char*)0))!=(char*)0);*/
        x149 = 1/*true*/;
      } else {
        x149 = 0/*false*/;
      }
      int x150 = 'B' == x131;
      int x175;
      if (x150) {
        x75 = 2;
        /*@assert (((((((x72[0]=='A')) ? ((x72+1)) : ((char*)0))!=(char*)0)) ? ((((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))!=(char*)0)) ? (((((((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))[0]=='B')) ? ((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))+1)) : ((char*)0))!=(char*)0)) ? ((((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))[0]=='B')) ? ((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))+1)) : ((char*)0))) : ((char*)0))) : ((char*)0))) : ((char*)0))!=(char*)0);*/
        x175 = 1/*true*/;
      } else {
        x175 = x149;
      }
      x74 = x175;
    } else {
    }
    int x179 = x75;
    int x180 = x179 == 2;
    if (x180) {
      /*@assert (((((((x72[0]=='A')) ? ((x72+1)) : ((char*)0))!=(char*)0)) ? ((((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))!=(char*)0)) ? (((((((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))[0]=='B')) ? ((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))+1)) : ((char*)0))!=(char*)0)) ? ((((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))[0]=='B')) ? ((star_2_0((((x72[0]=='A')) ? ((x72+1)) : ((char*)0)))+1)) : ((char*)0))) : ((char*)0))) : ((char*)0))) : ((char*)0))!=(char*)0);*/
      x74 = 0/*false*/;
    } else {
    }
    char  *x206 = x85+1;
    x76 = x206;
  }
  char  *x288 = x76;
  char x289 = x288[0];
  int x290 = x289 == '\0';
  int x294;
  if (x290) {
    int x291 = x75;
    int x292 = 2 == x291;
    x294 = x292;
  } else {
    x294 = 0/*false*/;
  }
  return x294;
}
