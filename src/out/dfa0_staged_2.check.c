#include <limits.h>
#include <string.h>
/*@
requires (((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0)))) &&
(strlen(x0)<=INT_MAX));
assigns \nothing;
*/
int dfa(char  * x0) {
  int x2 = 1/*true*/;
  int x3 = 0;
  //@ ghost int x4 = 0;
  char  *x5 = x0;
  /*@
  loop invariant (((((strlen(x0)>=0) &&
  \valid(x0+(0..strlen(x0)))) &&
  ((0<=x4) &&
  (x4<=strlen(x0)))) &&
  (x5==(x0+x4))) &&
  ((strlen((x0+x4))>=0) &&
  \valid((x0+x4)+(0..strlen((x0+x4))))));
  loop invariant ((x5[0]=='\0') ==> (strlen(x0)==x4));
  loop invariant ((!(x5[0]=='\0')) ==> (strlen(x0)!=x4));
  loop invariant ((x3==3) || ((x3==2) || ((x3==1) || (x3==0))));
  loop assigns x5, x4, x3, x2;
  loop variant strlen(x5);
  */
  for (;;) {
    char  *x7 = x5;
    char x8 = x7[0];
    int x9 = x8 == '\0';
    int x13;
    if (x9) {
      x13 = 0/*false*/;
    } else {
      int x11 = x2;
      x13 = x11;
    }
    if (!x13) break;
    char  *x39 = x5;
    char  *x40 = x39+1;
    x5 = x40;
    /*@ghost x4 = (x4+1);*/
  }
  char  *x86 = x5;
  char x87 = x86[0];
  int x88 = x87 == '\0';
  int x91;
  if (x88) {
    int x89 = x2;
    x91 = x89;
  } else {
    x91 = 0/*false*/;
  }
  int x95;
  if (x91) {
    int x92 = x3;
    int x93 = x92 == 3;
    x95 = x93;
  } else {
    x95 = 0/*false*/;
  }
  /*@assert ((x5[0]=='\0') || (!x2));*/
  return x95;
}
