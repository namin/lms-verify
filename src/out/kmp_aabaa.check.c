#include <limits.h>
#include <string.h>
/*@ predicate match_w(char  * x0) = ((x0[0]=='a') &&
((x0[1]=='a') &&
((x0[2]=='b') &&
((x0[3]=='a') &&
(x0[4]=='a')))));*/
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0))));
assigns \nothing;
ensures \result <==> match_w(x0);
*/
int match_w(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == 'a';
  int x16;
  if (x3) {
    char x4 = x0[1];
    int x5 = x4 == 'a';
    int x15;
    if (x5) {
      char x6 = x0[2];
      int x7 = x6 == 'b';
      int x14;
      if (x7) {
        char x8 = x0[3];
        int x9 = x8 == 'a';
        int x13;
        if (x9) {
          char x10 = x0[4];
          int x11 = x10 == 'a';
          int x12;
          if (x11) {
            x12 = 1/*true*/;
          } else {
            x12 = 0/*false*/;
          }
          x13 = x12;
        } else {
          x13 = 0/*false*/;
        }
        x14 = x13;
      } else {
        x14 = 0/*false*/;
      }
      x15 = x14;
    } else {
      x15 = 0/*false*/;
    }
    x16 = x15;
  } else {
    x16 = 0/*false*/;
  }
  return x16;
}
/*@ predicate match_any_w(char  * x23) = (\exists int x27; (0<=x27<strlen(x23)) && match_w((x23+x27)));*/
/*@
requires ((strlen(x23)>=0) &&
\valid(x23+(0..strlen(x23))));
assigns \nothing;
ensures \result <==> match_any_w(x23);
*/
int match_any_w(char  * x23) {
  int x25 = strlen(x23);
  int x33 = 0;
  /*@ loop invariant (0 <= x28 <= strlen(x23));
  loop invariant !(\exists int x27; (0 <= x27 < x28) && match_w((x23+x27)));
  loop invariant x33==0;
  loop assigns x28, x33;
  loop variant (strlen(x23)-x28); */
  for (int x28 = 0; x28 < strlen(x23); x28++) {
    char  *x31 = x23+x28;
    int x32 = match_w(x31);
    if (x32) { x33 = 1; break; }
  }
  return x33;
}
/*@
requires (((strlen(x39)>=0) &&
\valid(x39+(0..strlen(x39)))) &&
(((strlen(x39)*2)+5)<=INT_MAX));
assigns \nothing;
ensures ((((\result ==> match_any_w(x39)) &&
(match_any_w(x39) ==> \result)) &&
((!\result) ==> (!match_any_w(x39)))) &&
((!match_any_w(x39)) ==> (!\result)));
*/
int matcher(char  * x39) {
  int x41 = 0;
  int x42 = 0;
  /*@
  loop invariant (((((((0<=x42) &&
  (x42<=strlen(x39))) &&
  (0<=x41)) &&
  (x41<=5)) &&
  ((strlen(x39)>=0) &&
  \valid(x39+(0..strlen(x39))))) &&
  (\forall int  x139; (((0<=x139) &&
  (x139<(x42-x41))) ==> (!match_w((x39+x139)))))) &&
  (((x41==1) ==> ((x42>=1) &&
  (x39[(x42-1)]=='a'))) &&
  (((x41==2) ==> ((x42>=2) &&
  ((x39[(x42-2)]=='a') &&
  (x39[(x42-1)]=='a')))) &&
  (((x41==3) ==> ((x42>=3) &&
  ((x39[(x42-3)]=='a') &&
  ((x39[(x42-2)]=='a') &&
  (x39[(x42-1)]=='b'))))) &&
  (((x41==4) ==> ((x42>=4) &&
  ((x39[(x42-4)]=='a') &&
  ((x39[(x42-3)]=='a') &&
  ((x39[(x42-2)]=='b') &&
  (x39[(x42-1)]=='a')))))) &&
  ((x41==5) ==> ((x42>=5) &&
  ((x39[(x42-5)]=='a') &&
  ((x39[(x42-4)]=='a') &&
  ((x39[(x42-3)]=='b') &&
  ((x39[(x42-2)]=='a') &&
  (x39[(x42-1)]=='a'))))))))))));
  loop assigns x41, x42;
  loop variant (((strlen(x39)*2)-(x42*2))+x41);
  */
  for (;;) {
    int x43 = x42;
    char x44 = x39[x43];
    int x46 = x44 == '\0';
    int x50;
    if (x46) {
      x50 = 0/*false*/;
    } else {
      int x47 = x41;
      int x48 = x47 < 5;
      x50 = x48;
    }
    if (!x50) break;
    int x52 = x41;
    int x53 = x52 == 0;
    if (x53) {
      int x54 = x42;
      char x55 = x39[x54];
      int x56 = 'a' == x55;
      if (x56) {
        x41 += 1;
        x42 += 1;
      } else {
        x41 = 0;
        x42 += 1;
      }
    } else {
      int x65 = x52 == 1;
      if (x65) {
        int x66 = x42;
        char x67 = x39[x66];
        int x68 = 'a' == x67;
        if (x68) {
          x41 += 1;
          x42 += 1;
        } else {
          x41 = 0;
        }
      } else {
        int x76 = x52 == 2;
        if (x76) {
          int x77 = x42;
          char x78 = x39[x77];
          int x79 = 'b' == x78;
          if (x79) {
            x41 += 1;
            x42 += 1;
          } else {
            x41 = 1;
          }
        } else {
          int x87 = x52 == 3;
          if (x87) {
            int x88 = x42;
            char x89 = x39[x88];
            int x90 = 'a' == x89;
            if (x90) {
              x41 += 1;
              x42 += 1;
            } else {
              x41 = 0;
            }
          } else {
            int x98 = x52 == 4;
            if (x98) {
              int x99 = x42;
              char x100 = x39[x99];
              int x101 = 'a' == x100;
              if (x101) {
                x41 += 1;
                x42 += 1;
              } else {
                x41 = 1;
              }
            } else {
            }
          }
        }
      }
    }
  }
  int x223 = x41;
  int x224 = x223 == 5;
  return x224;
}
