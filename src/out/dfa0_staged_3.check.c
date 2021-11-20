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
  loop invariant ((x3==4) || ((x3==3) || ((x3==2) || ((x3==1) || (x3==0)))));
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
    char  *x41 = x5;
    char  *x42 = x41+1;
    x5 = x42;
    /*@ghost x4 = (x4+1);*/
  }
  char  *x88 = x5;
  char x89 = x88[0];
  int x90 = x89 == '\0';
  int x93;
  if (x90) {
    int x91 = x2;
    x93 = x91;
  } else {
    x93 = 0/*false*/;
  }
  int x97;
  if (x93) {
    int x94 = x3;
    int x95 = x94 == 4;
    x97 = x95;
  } else {
    x97 = 0/*false*/;
  }
  /*@assert ((x5[0]=='\0') || (!x2));*/
  return x97;
}
