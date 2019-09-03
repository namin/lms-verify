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
match_w((x11+x13))));*/
/*@
requires (((strlen(x25)>=0) &&
\valid(x25+(0..(strlen(x25)+1)-1))) &&
(((strlen(x25)*2)+3)<=INT_MAX));
assigns \nothing;
ensures ((((\result ==> match_any_w(x25)) &&
(match_any_w(x25) ==> \result)) &&
((!\result) ==> (!match_any_w(x25)))) &&
((!match_any_w(x25)) ==> (!\result)));
*/
int matcher(char  * x25) {
  int x27 = 0;
  int x28 = 0;
  /*@
  loop invariant (((((((0<=x28) &&
  (x28<=strlen(x25))) &&
  (0<=x27)) &&
  (x27<=3)) &&
  ((strlen(x25)>=0) &&
  \valid(x25+(0..(strlen(x25)+1)-1)))) &&
  (\forall int  x105; (((0<=x105) &&
  (x105<(x28-x27))) ==> (!match_w((x25+x105)))))) &&
  (((x27==1) ==> ((x28>=1) &&
  (x25[(x28-1)]=='a'))) &&
  (((x27==2) ==> ((x28>=2) &&
  ((x25[(x28-2)]=='a') &&
  (x25[(x28-1)]=='a')))) &&
  ((x27==3) ==> ((x28>=3) &&
  ((x25[(x28-3)]=='a') &&
  ((x25[(x28-2)]=='a') &&
  (x25[(x28-1)]=='b'))))))));
  loop assigns x27, x28;
  loop variant (((strlen(x25)*2)-(x28*2))+x27);
  */
  for (;;) {
    int x29 = x28;
    char x30 = x25[x29];
    int x32 = x30 == '\0';
    int x36;
    if (x32) {
      x36 = 0/*false*/;
    } else {
      int x33 = x27;
      int x34 = x33 < 3;
      x36 = x34;
    }
    if (!x36) break;
    int x38 = x27;
    int x39 = x38 == 0;
    if (x39) {
      int x40 = x28;
      char x41 = x25[x40];
      int x42 = 'a' == x41;
      if (x42) {
        x27 += 1;
        x28 += 1;
      } else {
        x27 = 0;
        x28 += 1;
      }
    } else {
      int x51 = x38 == 1;
      if (x51) {
        int x52 = x28;
        char x53 = x25[x52];
        int x54 = 'a' == x53;
        if (x54) {
          x27 += 1;
          x28 += 1;
        } else {
          x27 = 0;
        }
      } else {
        int x62 = x38 == 2;
        if (x62) {
          int x63 = x28;
          char x64 = x25[x63];
          int x65 = 'b' == x64;
          if (x65) {
            x27 += 1;
            x28 += 1;
          } else {
            x27 = 1;
          }
        } else {
        }
      }
    }
  }
  int x192 = x27;
  int x193 = x192 == 3;
  return x193;
}
