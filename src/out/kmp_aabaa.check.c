#include <limits.h>
#include <string.h>
/*@ predicate match_w(char  * x0) = ((x0[0]=='a') &&
((x0[1]=='a') &&
((x0[2]=='b') &&
((x0[3]=='a') &&
(x0[4]=='a')))));*/
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..(strlen(x0)+1)-1)));
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
/*@ predicate match_any_w(char  * x26) = (\exists int x30; (0<=x30<strlen(x26)) && match_w((x26+x30)));*/
/*@
requires ((strlen(x26)>=0) &&
\valid(x26+(0..(strlen(x26)+1)-1)));
assigns \nothing;
ensures \result <==> match_any_w(x26);
*/
int match_any_w(char  * x26) {
  int x28 = strlen(x26);
  int x37 = 0;
  /*@ loop invariant (0 <= x31 <= strlen(x26));
  loop invariant !(\exists int x30; (0 <= x30 < x31) && match_w((x26+x30)));
  loop invariant x37==0;
  loop assigns x31, x37;
  loop variant (strlen(x26)-x31); */
  for (int x31 = 0; x31 < strlen(x26); x31++) {
    char  *x35 = x26+x31;
    int x36 = match_w(x35);
    if (x36) { x37 = 1; break; }
  }
  return x37;
}
/*@
requires (((strlen(x47)>=0) &&
\valid(x47+(0..(strlen(x47)+1)-1))) &&
(((strlen(x47)*2)+5)<=INT_MAX));
assigns \nothing;
ensures ((((\result ==> match_any_w(x47)) &&
(match_any_w(x47) ==> \result)) &&
((!\result) ==> (!match_any_w(x47)))) &&
((!match_any_w(x47)) ==> (!\result)));
*/
int matcher(char  * x47) {
  int x49 = 0;
  int x50 = 0;
  /*@
  loop invariant (((((((0<=x50) &&
  (x50<=strlen(x47))) &&
  (0<=x49)) &&
  (x49<=5)) &&
  ((strlen(x47)>=0) &&
  \valid(x47+(0..(strlen(x47)+1)-1)))) &&
  (\forall int  x153; (((0<=x153) &&
  (x153<(x50-x49))) ==> (!match_w((x47+x153)))))) &&
  (((x49==1) ==> ((x50>=1) &&
  (x47[(x50-1)]=='a'))) &&
  (((x49==2) ==> ((x50>=2) &&
  ((x47[(x50-2)]=='a') &&
  (x47[(x50-1)]=='a')))) &&
  (((x49==3) ==> ((x50>=3) &&
  ((x47[(x50-3)]=='a') &&
  ((x47[(x50-2)]=='a') &&
  (x47[(x50-1)]=='b'))))) &&
  (((x49==4) ==> ((x50>=4) &&
  ((x47[(x50-4)]=='a') &&
  ((x47[(x50-3)]=='a') &&
  ((x47[(x50-2)]=='b') &&
  (x47[(x50-1)]=='a')))))) &&
  ((x49==5) ==> ((x50>=5) &&
  ((x47[(x50-5)]=='a') &&
  ((x47[(x50-4)]=='a') &&
  ((x47[(x50-3)]=='b') &&
  ((x47[(x50-2)]=='a') &&
  (x47[(x50-1)]=='a'))))))))))));
  loop assigns x49, x50;
  loop variant (((strlen(x47)*2)-(x50*2))+x49);
  */
  for (;;) {
    int x51 = x50;
    char x52 = x47[x51];
    int x54 = x52 == '\0';
    int x58;
    if (x54) {
      x58 = 0/*false*/;
    } else {
      int x55 = x49;
      int x56 = x55 < 5;
      x58 = x56;
    }
    if (!x58) break;
    int x60 = x49;
    int x61 = x60 == 0;
    if (x61) {
      int x62 = x50;
      char x63 = x47[x62];
      int x64 = 'a' == x63;
      if (x64) {
        x49 += 1;
        x50 += 1;
      } else {
        x49 = 0;
        x50 += 1;
      }
    } else {
      int x73 = x60 == 1;
      if (x73) {
        int x74 = x50;
        char x75 = x47[x74];
        int x76 = 'a' == x75;
        if (x76) {
          x49 += 1;
          x50 += 1;
        } else {
          x49 = 0;
        }
      } else {
        int x84 = x60 == 2;
        if (x84) {
          int x85 = x50;
          char x86 = x47[x85];
          int x87 = 'b' == x86;
          if (x87) {
            x49 += 1;
            x50 += 1;
          } else {
            x49 = 1;
          }
        } else {
          int x95 = x60 == 3;
          if (x95) {
            int x96 = x50;
            char x97 = x47[x96];
            int x98 = 'a' == x97;
            if (x98) {
              x49 += 1;
              x50 += 1;
            } else {
              x49 = 0;
            }
          } else {
            int x106 = x60 == 4;
            if (x106) {
              int x107 = x50;
              char x108 = x47[x107];
              int x109 = 'a' == x108;
              if (x109) {
                x49 += 1;
                x50 += 1;
              } else {
                x49 = 1;
              }
            } else {
            }
          }
        }
      }
    }
  }
  int x303 = x49;
  int x304 = x303 == 5;
  return x304;
}
