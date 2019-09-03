#include <limits.h>
#include <string.h>
/*@ predicate match_w(char  * x0) = ((x0[0]=='a') &&
((x0[1]=='a') &&
((x0[2]=='b') &&
((x0[3]=='a') &&
(x0[4]=='a')))));*/
/*@
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
/*@ predicate match_any_w(char  * x17) = (\exists integer  x19; (((0<=x19) &&
(x19<strlen(x17))) &&
match_w((x17+x19))));*/
/*@
requires (((strlen(x31)>=0) &&
\valid(x31+(0..(strlen(x31)+1)-1))) &&
(((strlen(x31)*2)+3)<=INT_MAX));
assigns \nothing;
ensures ((((\result ==> match_any_w(x31)) &&
(match_any_w(x31) ==> \result)) &&
((!\result) ==> (!match_any_w(x31)))) &&
((!match_any_w(x31)) ==> (!\result)));
*/
int matcher(char  * x31) {
  int x33 = 0;
  int x34 = 0;
  /*@
  loop invariant (((((((0<=x34) &&
  (x34<=strlen(x31))) &&
  (0<=x33)) &&
  (x33<=5)) &&
  ((strlen(x31)>=0) &&
  \valid(x31+(0..(strlen(x31)+1)-1)))) &&
  (\forall int  x137; (((0<=x137) &&
  (x137<(x34-x33))) ==> (!match_w((x31+x137)))))) &&
  (((x33==1) ==> ((x34>=1) &&
  (x31[(x34-1)]=='a'))) &&
  (((x33==2) ==> ((x34>=2) &&
  ((x31[(x34-2)]=='a') &&
  (x31[(x34-1)]=='a')))) &&
  (((x33==3) ==> ((x34>=3) &&
  ((x31[(x34-3)]=='a') &&
  ((x31[(x34-2)]=='a') &&
  (x31[(x34-1)]=='b'))))) &&
  (((x33==4) ==> ((x34>=4) &&
  ((x31[(x34-4)]=='a') &&
  ((x31[(x34-3)]=='a') &&
  ((x31[(x34-2)]=='b') &&
  (x31[(x34-1)]=='a')))))) &&
  ((x33==5) ==> ((x34>=5) &&
  ((x31[(x34-5)]=='a') &&
  ((x31[(x34-4)]=='a') &&
  ((x31[(x34-3)]=='b') &&
  ((x31[(x34-2)]=='a') &&
  (x31[(x34-1)]=='a'))))))))))));
  loop assigns x33, x34;
  loop variant (((strlen(x31)*2)-(x34*2))+x33);
  */
  for (;;) {
    int x35 = x34;
    char x36 = x31[x35];
    int x38 = x36 == '\0';
    int x42;
    if (x38) {
      x42 = 0/*false*/;
    } else {
      int x39 = x33;
      int x40 = x39 < 5;
      x42 = x40;
    }
    if (!x42) break;
    int x44 = x33;
    int x45 = x44 == 0;
    if (x45) {
      int x46 = x34;
      char x47 = x31[x46];
      int x48 = 'a' == x47;
      if (x48) {
        x33 += 1;
        x34 += 1;
      } else {
        x33 = 0;
        x34 += 1;
      }
    } else {
      int x57 = x44 == 1;
      if (x57) {
        int x58 = x34;
        char x59 = x31[x58];
        int x60 = 'a' == x59;
        if (x60) {
          x33 += 1;
          x34 += 1;
        } else {
          x33 = 0;
        }
      } else {
        int x68 = x44 == 2;
        if (x68) {
          int x69 = x34;
          char x70 = x31[x69];
          int x71 = 'b' == x70;
          if (x71) {
            x33 += 1;
            x34 += 1;
          } else {
            x33 = 1;
          }
        } else {
          int x79 = x44 == 3;
          if (x79) {
            int x80 = x34;
            char x81 = x31[x80];
            int x82 = 'a' == x81;
            if (x82) {
              x33 += 1;
              x34 += 1;
            } else {
              x33 = 0;
            }
          } else {
            int x90 = x44 == 4;
            if (x90) {
              int x91 = x34;
              char x92 = x31[x91];
              int x93 = 'a' == x92;
              if (x93) {
                x33 += 1;
                x34 += 1;
              } else {
                x33 = 1;
              }
            } else {
            }
          }
        }
      }
    }
  }
  int x287 = x33;
  int x288 = x287 == 5;
  return x288;
}
