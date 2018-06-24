#include <limits.h>
#include <string.h>
/*@ predicate match_w(char  * x0) = ((x0[0]=='a') &&
((x0[1]=='a') &&
(x0[2]=='b')));*/
/*@
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
/*@ predicate match_any_w(char  * x11) = (\exists integer  x13; (((0<=x13) &&
(x13<strlen(x11))) &&
match_w(x11)));*/
/*@
requires ((strlen(x23)>=0) &&
\valid(x23+(0..(strlen(x23)+1)-1)));
assigns \nothing;
ensures ((((\result ==> match_any_w(x23)) &&
(match_any_w(x23) ==> \result)) &&
((!\result) ==> (!match_any_w(x23)))) &&
((!match_any_w(x23)) ==> (!\result)));
*/
int matcher(char  * x23) {
  int x25 = 0;
  int x26 = 0;
  /*@
  loop invariant (((((((0<=x26) &&
  (x26<=strlen(x23))) &&
  (0<=x25)) &&
  (x25<=3)) &&
  ((strlen(x23)>=0) &&
  \valid(x23+(0..(strlen(x23)+1)-1)))) &&
  (\exists int  x103; (((0<=x103) &&
  (x103<(x26-x25))) ==> (!match_w((x23+x103)))))) &&
  (((x25==1) ==> ((x26>=1) &&
  (x23[(x26-1)]=='a'))) &&
  (((x25==2) ==> ((x26>=2) &&
  ((x23[(x26-2)]=='a') &&
  (x23[(x26-1)]=='a')))) &&
  ((x25==3) ==> ((x26>=3) &&
  ((x23[(x26-3)]=='a') &&
  ((x23[(x26-2)]=='a') &&
  (x23[(x26-1)]=='b'))))))));
  loop assigns x25, x26;
  loop variant ((((strlen(x23)*2)-(2*x26))+3)-x25);
  */
  for (;;) {
    int x27 = x26;
    char x28 = x23[x27];
    int x30 = x28 == '\0';
    int x34;
    if (x30) {
      x34 = 0/*false*/;
    } else {
      int x31 = x25;
      int x32 = x31 < 3;
      x34 = x32;
    }
    if (!x34) break;
    int x36 = x25;
    int x37 = x36 == 0;
    if (x37) {
      int x38 = x26;
      char x39 = x23[x38];
      int x40 = 'a' == x39;
      if (x40) {
        x25 += 1;
        x26 += 1;
      } else {
        x25 = 0;
        x26 += 1;
      }
    } else {
      int x49 = x36 == 1;
      if (x49) {
        int x50 = x26;
        char x51 = x23[x50];
        int x52 = 'a' == x51;
        if (x52) {
          x25 += 1;
          x26 += 1;
        } else {
          x25 = 0;
        }
      } else {
        int x60 = x36 == 2;
        if (x60) {
          int x61 = x26;
          char x62 = x23[x61];
          int x63 = 'b' == x62;
          if (x63) {
            x25 += 1;
            x26 += 1;
          } else {
            x25 = 1;
          }
        } else {
        }
      }
    }
  }
  int x191 = x25;
  int x192 = x191 == 3;
  return x192;
}
