#include <limits.h>
#include <string.h>
/*@ predicate match_w(char  * x0) = ((x0[0]=='a') &&
((x0[1]=='a') &&
(x0[2]=='b')));*/
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0))));
assigns \nothing;
ensures \result <==> match_w(x0);
*/
int match_w(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == 'a';
  int x10;
  if (x3) {
    char x4 = x0[1];
    int x5 = x4 == 'a';
    int x9;
    if (x5) {
      char x6 = x0[2];
      int x7 = x6 == 'b';
      int x8;
      if (x7) {
        x8 = 1/*true*/;
      } else {
        x8 = 0/*false*/;
      }
      x9 = x8;
    } else {
      x9 = 0/*false*/;
    }
    x10 = x9;
  } else {
    x10 = 0/*false*/;
  }
  return x10;
}
/*@ predicate match_any_w(char  * x17) = (\exists int x21; (0<=x21<strlen(x17)) && match_w((x17+x21)));*/
/*@
requires ((strlen(x17)>=0) &&
\valid(x17+(0..strlen(x17))));
assigns \nothing;
ensures \result <==> match_any_w(x17);
*/
int match_any_w(char  * x17) {
  int x27 = 0;
  /*@ loop invariant (0 <= x22 <= strlen(x17));
  loop invariant !(\exists int x21; (0 <= x21 < x22) && match_w((x17+x21)));
  loop invariant x27==0;
  loop assigns x22, x27;
  loop variant (strlen(x17)-x22); */
  for (int x22 = 0; x22 < strlen(x17); x22++) {
    char  *x25 = x17+x22;
    int x26 = match_w(x25);
    if (x26) { x27 = 1; break; }
  }
  return x27;
}
/*@
requires (((strlen(x33)>=0) &&
\valid(x33+(0..strlen(x33)))) &&
(((strlen(x33)*2)+3)<=INT_MAX));
assigns \nothing;
ensures ((((\result ==> match_any_w(x33)) &&
(match_any_w(x33) ==> \result)) &&
((!\result) ==> (!match_any_w(x33)))) &&
((!match_any_w(x33)) ==> (!\result)));
*/
int matcher(char  * x33) {
  int x35 = 0;
  int x36 = 0;
  /*@
  loop invariant (((((((0<=x36) &&
  (x36<=strlen(x33))) &&
  (0<=x35)) &&
  (x35<=3)) &&
  ((strlen(x33)>=0) &&
  \valid(x33+(0..strlen(x33))))) &&
  (\forall int  x107; (((0<=x107) &&
  (x107<(x36-x35))) ==> (!match_w((x33+x107)))))) &&
  (((x35==1) ==> ((x36>=1) &&
  (x33[(x36-1)]=='a'))) &&
  (((x35==2) ==> ((x36>=2) &&
  ((x33[(x36-2)]=='a') &&
  (x33[(x36-1)]=='a')))) &&
  ((x35==3) ==> ((x36>=3) &&
  ((x33[(x36-3)]=='a') &&
  ((x33[(x36-2)]=='a') &&
  (x33[(x36-1)]=='b'))))))));
  loop assigns x35, x36;
  loop variant (((strlen(x33)*2)-(x36*2))+x35);
  */
  for (;;) {
    int x37 = x36;
    char x38 = x33[x37];
    int x40 = x38 == '\0';
    int x44;
    if (x40) {
      x44 = 0/*false*/;
    } else {
      int x41 = x35;
      int x42 = x41 < 3;
      x44 = x42;
    }
    if (!x44) break;
    int x46 = x35;
    int x47 = x46 == 0;
    if (x47) {
      int x48 = x36;
      char x49 = x33[x48];
      int x50 = 'a' == x49;
      if (x50) {
        x35 += 1;
        x36 += 1;
      } else {
        x35 = 0;
        x36 += 1;
      }
    } else {
      int x59 = x46 == 1;
      if (x59) {
        int x60 = x36;
        char x61 = x33[x60];
        int x62 = 'a' == x61;
        if (x62) {
          x35 += 1;
          x36 += 1;
        } else {
          x35 = 0;
        }
      } else {
        int x70 = x46 == 2;
        if (x70) {
          int x71 = x36;
          char x72 = x33[x71];
          int x73 = 'b' == x72;
          if (x73) {
            x35 += 1;
            x36 += 1;
          } else {
            x35 = 1;
          }
        } else {
        }
      }
    }
  }
  int x167 = x35;
  int x168 = x167 == 3;
  return x168;
}
