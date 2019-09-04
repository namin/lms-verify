#include <limits.h>
#include <string.h>
/*@ predicate match_w(char  * x0) = ((x0[0]=='a') &&
((x0[1]=='a') &&
(x0[2]=='b')));*/
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..(strlen(x0)+1)-1)));
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
/*@ predicate match_any_w(char  * x20) = (\exists int x24; (0<=x24<strlen(x20)) && match_w((x20+x24)));*/
/*@
requires ((strlen(x20)>=0) &&
\valid(x20+(0..(strlen(x20)+1)-1)));
assigns \nothing;
ensures \result <==> match_any_w(x20);
*/
int match_any_w(char  * x20) {
  int x22 = strlen(x20);
  int x31 = 0;
  /*@ loop invariant (0 <= x25 <= strlen(x20));
  loop invariant !(\exists int x24; (0 <= x24 < x25) && match_w((x20+x24)));
  loop invariant x31==0;
  loop assigns x25, x31;
  loop variant (strlen(x20)-x25); */
  for (int x25 = 0; x25 < strlen(x20); x25++) {
    char  *x29 = x20+x25;
    int x30 = match_w(x29);
    if (x30) { x31 = 1; break; }
  }
  return x31;
}
/*@
requires (((strlen(x41)>=0) &&
\valid(x41+(0..(strlen(x41)+1)-1))) &&
(((strlen(x41)*2)+3)<=INT_MAX));
assigns \nothing;
ensures ((((\result ==> match_any_w(x41)) &&
(match_any_w(x41) ==> \result)) &&
((!\result) ==> (!match_any_w(x41)))) &&
((!match_any_w(x41)) ==> (!\result)));
*/
int matcher(char  * x41) {
  int x43 = 0;
  int x44 = 0;
  /*@
  loop invariant (((((((0<=x44) &&
  (x44<=strlen(x41))) &&
  (0<=x43)) &&
  (x43<=3)) &&
  ((strlen(x41)>=0) &&
  \valid(x41+(0..(strlen(x41)+1)-1)))) &&
  (\forall int  x121; (((0<=x121) &&
  (x121<(x44-x43))) ==> (!match_w((x41+x121)))))) &&
  (((x43==1) ==> ((x44>=1) &&
  (x41[(x44-1)]=='a'))) &&
  (((x43==2) ==> ((x44>=2) &&
  ((x41[(x44-2)]=='a') &&
  (x41[(x44-1)]=='a')))) &&
  ((x43==3) ==> ((x44>=3) &&
  ((x41[(x44-3)]=='a') &&
  ((x41[(x44-2)]=='a') &&
  (x41[(x44-1)]=='b'))))))));
  loop assigns x43, x44;
  loop variant (((strlen(x41)*2)-(x44*2))+x43);
  */
  for (;;) {
    int x45 = x44;
    char x46 = x41[x45];
    int x48 = x46 == '\0';
    int x52;
    if (x48) {
      x52 = 0/*false*/;
    } else {
      int x49 = x43;
      int x50 = x49 < 3;
      x52 = x50;
    }
    if (!x52) break;
    int x54 = x43;
    int x55 = x54 == 0;
    if (x55) {
      int x56 = x44;
      char x57 = x41[x56];
      int x58 = 'a' == x57;
      if (x58) {
        x43 += 1;
        x44 += 1;
      } else {
        x43 = 0;
        x44 += 1;
      }
    } else {
      int x67 = x54 == 1;
      if (x67) {
        int x68 = x44;
        char x69 = x41[x68];
        int x70 = 'a' == x69;
        if (x70) {
          x43 += 1;
          x44 += 1;
        } else {
          x43 = 0;
        }
      } else {
        int x78 = x54 == 2;
        if (x78) {
          int x79 = x44;
          char x80 = x41[x79];
          int x81 = 'b' == x80;
          if (x81) {
            x43 += 1;
            x44 += 1;
          } else {
            x43 = 1;
          }
        } else {
        }
      }
    }
  }
  int x208 = x43;
  int x209 = x208 == 3;
  return x209;
}
