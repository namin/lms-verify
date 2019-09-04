#include <limits.h>
#include <string.h>
/*@ predicate match_w(char  * x0) = ((x0[0]=='a') &&
(x0[1]=='a'));*/
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..(strlen(x0)+1)-1)));
assigns \nothing;
ensures \result <==> match_w(x0);
*/
int match_w(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == 'a';
  int x7;
  if (x3) {
    char x4 = x0[1];
    int x5 = x4 == 'a';
    int x6;
    if (x5) {
      x6 = 1/*true*/;
    } else {
      x6 = 0/*false*/;
    }
    x7 = x6;
  } else {
    x7 = 0/*false*/;
  }
  return x7;
}
/*@ predicate match_any_w(char  * x17) = (\exists int x21; (0<=x21<strlen(x17)) && match_w((x17+x21)));*/
/*@
requires ((strlen(x17)>=0) &&
\valid(x17+(0..(strlen(x17)+1)-1)));
assigns \nothing;
ensures \result <==> match_any_w(x17);
*/
int match_any_w(char  * x17) {
  int x19 = strlen(x17);
  int x28 = 0;
  /*@ loop invariant (0 <= x22 <= strlen(x17));
  loop invariant !(\exists int x21; (0 <= x21 < x22) && match_w((x17+x21)));
  loop invariant x28==0;
  loop assigns x22, x28;
  loop variant (strlen(x17)-x22); */
  for (int x22 = 0; x22 < strlen(x17); x22++) {
    char  *x26 = x17+x22;
    int x27 = match_w(x26);
    if (x27) { x28 = 1; break; }
  }
  return x28;
}
/*@
requires (((strlen(x38)>=0) &&
\valid(x38+(0..(strlen(x38)+1)-1))) &&
(((strlen(x38)*2)+2)<=INT_MAX));
assigns \nothing;
ensures ((((\result ==> match_any_w(x38)) &&
(match_any_w(x38) ==> \result)) &&
((!\result) ==> (!match_any_w(x38)))) &&
((!match_any_w(x38)) ==> (!\result)));
*/
int matcher(char  * x38) {
  int x40 = 0;
  int x41 = 0;
  /*@
  loop invariant (((((((0<=x41) &&
  (x41<=strlen(x38))) &&
  (0<=x40)) &&
  (x40<=2)) &&
  ((strlen(x38)>=0) &&
  \valid(x38+(0..(strlen(x38)+1)-1)))) &&
  (\forall int  x105; (((0<=x105) &&
  (x105<(x41-x40))) ==> (!match_w((x38+x105)))))) &&
  (((x40==1) ==> ((x41>=1) &&
  (x38[(x41-1)]=='a'))) &&
  ((x40==2) ==> ((x41>=2) &&
  ((x38[(x41-2)]=='a') &&
  (x38[(x41-1)]=='a'))))));
  loop assigns x40, x41;
  loop variant (((strlen(x38)*2)-(x41*2))+x40);
  */
  for (;;) {
    int x42 = x41;
    char x43 = x38[x42];
    int x45 = x43 == '\0';
    int x49;
    if (x45) {
      x49 = 0/*false*/;
    } else {
      int x46 = x40;
      int x47 = x46 < 2;
      x49 = x47;
    }
    if (!x49) break;
    int x51 = x40;
    int x52 = x51 == 0;
    if (x52) {
      int x53 = x41;
      char x54 = x38[x53];
      int x55 = 'a' == x54;
      if (x55) {
        x40 += 1;
        x41 += 1;
      } else {
        x40 = 0;
        x41 += 1;
      }
    } else {
      int x64 = x51 == 1;
      if (x64) {
        int x65 = x41;
        char x66 = x38[x65];
        int x67 = 'a' == x66;
        if (x67) {
          x40 += 1;
          x41 += 1;
        } else {
          x40 = 0;
        }
      } else {
      }
    }
  }
  int x168 = x40;
  int x169 = x168 == 2;
  return x169;
}
