#include <limits.h>
#include <string.h>
/*@ predicate match_w(char  * x0) = ((x0[0]=='a') &&
(x0[1]=='a'));*/
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0))));
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
/*@ predicate match_any_w(char  * x14) = (\exists int x18; (0<=x18<strlen(x14)) && match_w((x14+x18)));*/
/*@
requires ((strlen(x14)>=0) &&
\valid(x14+(0..strlen(x14))));
assigns \nothing;
ensures \result <==> match_any_w(x14);
*/
int match_any_w(char  * x14) {
  int x24 = 0;
  /*@ loop invariant (0 <= x19 <= strlen(x14));
  loop invariant !(\exists int x18; (0 <= x18 < x19) && match_w((x14+x18)));
  loop invariant x24==0;
  loop assigns x19, x24;
  loop variant (strlen(x14)-x19); */
  for (int x19 = 0; x19 < strlen(x14); x19++) {
    char  *x22 = x14+x19;
    int x23 = match_w(x22);
    if (x23) { x24 = 1; break; }
  }
  return x24;
}
/*@
requires (((strlen(x30)>=0) &&
\valid(x30+(0..strlen(x30)))) &&
(((strlen(x30)*2)+2)<=INT_MAX));
assigns \nothing;
ensures ((((\result ==> match_any_w(x30)) &&
(match_any_w(x30) ==> \result)) &&
((!\result) ==> (!match_any_w(x30)))) &&
((!match_any_w(x30)) ==> (!\result)));
*/
int matcher(char  * x30) {
  int x32 = 0;
  int x33 = 0;
  /*@
  loop invariant (((((((0<=x33) &&
  (x33<=strlen(x30))) &&
  (0<=x32)) &&
  (x32<=2)) &&
  ((strlen(x30)>=0) &&
  \valid(x30+(0..strlen(x30))))) &&
  (\forall int  x91; (((0<=x91) &&
  (x91<(x33-x32))) ==> (!match_w((x30+x91)))))) &&
  (((x32==1) ==> ((x33>=1) &&
  (x30[(x33-1)]=='a'))) &&
  ((x32==2) ==> ((x33>=2) &&
  ((x30[(x33-2)]=='a') &&
  (x30[(x33-1)]=='a'))))));
  loop assigns x32, x33;
  loop variant (((strlen(x30)*2)-(x33*2))+x32);
  */
  for (;;) {
    int x34 = x33;
    char x35 = x30[x34];
    int x37 = x35 == '\0';
    int x41;
    if (x37) {
      x41 = 0/*false*/;
    } else {
      int x38 = x32;
      int x39 = x38 < 2;
      x41 = x39;
    }
    if (!x41) break;
    int x43 = x32;
    int x44 = x43 == 0;
    if (x44) {
      int x45 = x33;
      char x46 = x30[x45];
      int x47 = 'a' == x46;
      if (x47) {
        x32 += 1;
        x33 += 1;
      } else {
        x32 = 0;
        x33 += 1;
      }
    } else {
      int x56 = x43 == 1;
      if (x56) {
        int x57 = x33;
        char x58 = x30[x57];
        int x59 = 'a' == x58;
        if (x59) {
          x32 += 1;
          x33 += 1;
        } else {
          x32 = 0;
        }
      } else {
      }
    }
  }
  int x139 = x32;
  int x140 = x139 == 2;
  return x140;
}
