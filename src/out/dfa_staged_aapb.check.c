#include <limits.h>
#include <string.h>
/*@ logic char  * re_0(char  * x0) = (((((((((x0[0]=='A')) ? ((x0+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : (re_0((((x0[0]=='A')) ? ((x0+1)) : ((char*)0)))))==(char*)0)) ? (((((((x0[0]=='A')) ? ((x0+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : (re_0((((x0[0]=='A')) ? ((x0+1)) : ((char*)0)))))) : (((((((x0[0]=='A')) ? ((x0+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : (re_0((((x0[0]=='A')) ? ((x0+1)) : ((char*)0)))))));*/
/*@ logic char  * re_1(char  * x15) = ((((((x15[0]=='A')) ? ((x15+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : ((((re_0((((x15[0]=='A')) ? ((x15+1)) : ((char*)0)))==(char*)0)) ? ((char*)0) : (((((((re_0((((x15[0]=='A')) ? ((x15+1)) : ((char*)0)))[0]=='B')) ? ((re_0((((x15[0]=='A')) ? ((x15+1)) : ((char*)0)))+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : ((((re_0((((x15[0]=='A')) ? ((x15+1)) : ((char*)0)))[0]=='B')) ? ((re_0((((x15[0]=='A')) ? ((x15+1)) : ((char*)0)))+1)) : ((char*)0))))))));*/
/*@ logic char  * re_2(char  * x37) = (((re_0(x37)==(char*)0)) ? ((char*)0) : (((((((re_0(x37)[0]=='B')) ? ((re_0(x37)+1)) : ((char*)0))==(char*)0)) ? ((char*)0) : ((((re_0(x37)[0]=='B')) ? ((re_0(x37)+1)) : ((char*)0))))));*/
/*@ logic char  * re_3(char  * x51) = x51;*/
/*@
requires ((strlen(x53)>=0) &&
\valid(x53+(0..(strlen(x53)+1)-1)));
assigns \nothing;
ensures (\result==((re_1(x53)!=(char*)0) &&
(re_1(x53)[0]=='\0')));
*/
int dfa(char  * x53) {
  int x55 = 1/*true*/;
  int x56 = 0;
  char  *x57 = x53;
  /*@
  loop invariant ((((strlen(x57)>=0) &&
  \valid(x57+(0..(strlen(x57)+1)-1))) &&
  (((x56==2) ==> ((re_3(x57)!=(char*)0) &&
  (re_1(x53)!=(char*)0))) &&
  (((x56==1) ==> ((re_2(x57)!=(char*)0) &&
  (re_1(x53)!=(char*)0))) &&
  ((x56==0) ==> ((re_1(x57)!=(char*)0) &&
  (re_1(x53)!=(char*)0)))))) &&
  ((x56==2) || ((x56==1) || (x56==0))));
  loop assigns x57, x56, x55;
  loop variant strlen(x57);
  */
  for (;;) {
    char  *x58 = x57;
    char x59 = x58[0];
    int x60 = x59 == '\0';
    int x64;
    if (x60) {
      x64 = 0/*false*/;
    } else {
      int x62 = x55;
      x64 = x62;
    }
    if (!x64) break;
    char  *x66 = x57;
    char x67 = x66[0];
    char x68 = x67;
    int x69 = x56;
    int x70 = x69 == 0;
    if (x70) {
      /*@assert ((re_1(x57)!=(char*)0) &&
      (re_1(x53)!=(char*)0));*/
      char x80 = x68;
      int x81 = 'A' == x80;
      int x94;
      if (x81) {
        x56 = 1;
        /*@assert ((re_2((x57+1))!=(char*)0) &&
        (re_1(x53)!=(char*)0));*/
        x94 = 1/*true*/;
      } else {
        x94 = 0/*false*/;
      }
      x55 = x94;
    } else {
    }
    int x98 = x56;
    int x99 = x98 == 1;
    if (x99) {
      /*@assert ((re_2(x57)!=(char*)0) &&
      (re_1(x53)!=(char*)0));*/
      char x109 = x68;
      int x110 = 'A' == x109;
      int x123;
      if (x110) {
        x56 = 1;
        /*@assert ((re_2((x57+1))!=(char*)0) &&
        (re_1(x53)!=(char*)0));*/
        x123 = 1/*true*/;
      } else {
        x123 = 0/*false*/;
      }
      int x124 = 'B' == x109;
      int x137;
      if (x124) {
        x56 = 2;
        /*@assert ((re_3((x57+1))!=(char*)0) &&
        (re_1(x53)!=(char*)0));*/
        x137 = 1/*true*/;
      } else {
        x137 = x123;
      }
      x55 = x137;
    } else {
    }
    int x141 = x56;
    int x142 = x141 == 2;
    if (x142) {
      /*@assert ((re_3(x57)!=(char*)0) &&
      (re_1(x53)!=(char*)0));*/
      x55 = 0/*false*/;
    } else {
    }
    char  *x155 = x66+1;
    x57 = x155;
  }
  int x222 = x56;
  char  *x223 = x57;
  char x224 = x223[0];
  int x225 = x224 == '\0';
  int x227;
  if (x225) {
    int x226 = 2 == x222;
    x227 = x226;
  } else {
    x227 = 0/*false*/;
  }
  return x227;
}
