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
  //@ ghost int x7 = -1;
  int x8 = x7;
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
  loop invariant ((x3==2) || ((x3==1) || (x3==0)));
  loop invariant ((-1<=x7) &&
  (x7<=x4));
  loop invariant ((x7>=0) ==> (x3==1));
  loop invariant ((x3==1) ==> (x7>=0));
  loop invariant ((x7==-1) ==> (x3!=1));
  loop invariant ((x3!=1) ==> (x7==-1));
  loop assigns x5, x4, x3, x2, x7;
  loop variant strlen(x5);
  */
  for (;;) {
    char  *x9 = x5;
    char x10 = x9[0];
    int x11 = x10 == '\0';
    int x15;
    if (x11) {
      x15 = 0/*false*/;
    } else {
      int x13 = x2;
      x15 = x13;
    }
    if (!x15) break;
    char  *x70 = x5;
    char  *x71 = x70+1;
    x5 = x71;
    /*@ghost x4 = (x4+1);*/
  }
  char  *x117 = x5;
  char x118 = x117[0];
  int x119 = x118 == '\0';
  int x122;
  if (x119) {
    int x120 = x2;
    x122 = x120;
  } else {
    x122 = 0/*false*/;
  }
  int x126;
  if (x122) {
    int x123 = x3;
    int x124 = x123 == 2;
    x126 = x124;
  } else {
    x126 = 0/*false*/;
  }
  /*@assert ((x5[0]=='\0') || (!x2));*/
  return x126;
}
