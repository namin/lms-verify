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
  //@ ghost int x9 = -1;
  int x10 = x9;
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
  loop invariant ((-1<=x7) &&
  (x7<=x4));
  loop invariant ((x7>=0) ==> (x3==1));
  loop invariant ((x3==1) ==> (x7>=0));
  loop invariant ((x7==-1) ==> (x3!=1));
  loop invariant ((x3!=1) ==> (x7==-1));
  loop invariant ((-1<=x9) &&
  (x9<=x4));
  loop invariant ((x9>=0) ==> (x3==2));
  loop invariant ((x3==2) ==> (x9>=0));
  loop invariant ((x9==-1) ==> (x3!=2));
  loop invariant ((x3!=2) ==> (x9==-1));
  loop assigns x5, x4, x3, x2, x7, x9;
  loop variant strlen(x5);
  */
  for (;;) {
    char  *x11 = x5;
    char x12 = x11[0];
    int x13 = x12 == '\0';
    int x17;
    if (x13) {
      x17 = 0/*false*/;
    } else {
      int x15 = x2;
      x17 = x15;
    }
    if (!x17) break;
    char  *x105 = x5;
    char  *x106 = x105+1;
    x5 = x106;
    /*@ghost x4 = (x4+1);*/
  }
  char  *x152 = x5;
  char x153 = x152[0];
  int x154 = x153 == '\0';
  int x157;
  if (x154) {
    int x155 = x2;
    x157 = x155;
  } else {
    x157 = 0/*false*/;
  }
  int x161;
  if (x157) {
    int x158 = x3;
    int x159 = x158 == 3;
    x161 = x159;
  } else {
    x161 = 0/*false*/;
  }
  /*@assert ((x5[0]=='\0') || (!x2));*/
  return x161;
}
