#include <limits.h>
#include <string.h>
/*@ predicate match_w(char  * x0) = ((x0[0]=='a') &&
(x0[1]=='a'));*/
/*@
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
/*@ predicate match_any_w(char  * x8) = (\exists integer  x10; (((0<=x10) &&
(x10<strlen(x8))) &&
match_w((x8+x10))));*/
/*@
requires ((strlen(x22)>=0) &&
\valid(x22+(0..(strlen(x22)+1)-1)));
assigns \nothing;
ensures ((((\result ==> match_any_w(x22)) &&
(match_any_w(x22) ==> \result)) &&
((!\result) ==> (!match_any_w(x22)))) &&
((!match_any_w(x22)) ==> (!\result)));
*/
int matcher(char  * x22) {
  int x24 = 0;
  int x25 = 0;
  /*@
  loop invariant (((((((0<=x25) &&
  (x25<=strlen(x22))) &&
  (0<=x24)) &&
  (x24<=2)) &&
  ((strlen(x22)>=0) &&
  \valid(x22+(0..(strlen(x22)+1)-1)))) &&
  (\forall int  x89; (((0<=x89) &&
  (x89<(x25-x24))) ==> (!match_w((x22+x89)))))) &&
  (((x24==1) ==> ((x25>=1) &&
  (x22[(x25-1)]=='a'))) &&
  ((x24==2) ==> ((x25>=2) &&
  ((x22[(x25-2)]=='a') &&
  (x22[(x25-1)]=='a'))))));
  loop assigns x24, x25;
  loop variant ((((strlen(x22)*2)-(2*x25))+2)-x24);
  */
  for (;;) {
    int x26 = x25;
    char x27 = x22[x26];
    int x29 = x27 == '\0';
    int x33;
    if (x29) {
      x33 = 0/*false*/;
    } else {
      int x30 = x24;
      int x31 = x30 < 2;
      x33 = x31;
    }
    if (!x33) break;
    int x35 = x24;
    int x36 = x35 == 0;
    if (x36) {
      int x37 = x25;
      char x38 = x22[x37];
      int x39 = 'a' == x38;
      if (x39) {
        x24 += 1;
        x25 += 1;
      } else {
        x24 = 0;
        x25 += 1;
      }
    } else {
      int x48 = x35 == 1;
      if (x48) {
        int x49 = x25;
        char x50 = x22[x49];
        int x51 = 'a' == x50;
        if (x51) {
          x24 += 1;
          x25 += 1;
        } else {
          x24 = 0;
        }
      } else {
      }
    }
  }
  int x153 = x24;
  int x154 = x153 == 2;
  return x154;
}
