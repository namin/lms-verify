#include <limits.h>
#include <string.h>
/*@ predicate star_A(char  * x51, integer  x52, integer  x53) = (\exists integer  x55; ((((x52<x55) &&
(x55<=x53)) ==> ((('A'==x51[x52]) &&
(x55==(x52+1))) &&
star_A(x51,x55,x53))) || (x52==x53)));*/
/*@ predicate re_0(char  * x0, integer  x1, integer  x2) = (\exists integer  x4; ((((x1<=x4) &&
(x4<=x2)) &&
(('A'==x0[x1]) &&
(x4==(x1+1)))) &&
(\exists integer  x17; ((((x4<=x17) &&
(x17<=x2)) &&
star_A(x0,x4,x17)) &&
(\exists integer  x25; ((((x17<=x25) &&
(x25<=x2)) &&
(('B'==x0[x17]) &&
(x25==(x17+1)))) &&
(x25==x2)))))));*/
/*@ predicate re_1(char  * x74, integer  x75, integer  x76) = (\exists integer  x78; ((((x75<=x78) &&
(x78<=x76)) &&
star_A(x74,x75,x78)) &&
(\exists integer  x85; ((((x78<=x85) &&
(x85<=x76)) &&
(('B'==x74[x78]) &&
(x85==(x78+1)))) &&
(x85==x76)))));*/
/*@ predicate re_2(char  * x107, integer  x108, integer  x109) = (x108==x109);*/
/*@ predicate re_bwd_0(char  * x112, integer  x113, integer  x114) = (x113==x114);*/
/*@ predicate re_bwd_1(char  * x117, integer  x118, integer  x119) = (\exists integer  x121; ((((x118<=x121) &&
(x121<=x119)) &&
(('A'==x117[x118]) &&
(x121==(x118+1)))) &&
(\exists integer  x134; ((((x121<=x134) &&
(x134<=x119)) &&
star_A(x117,x121,x134)) &&
(x134==x119)))));*/
/*@ predicate re_bwd_2(char  * x150, integer  x151, integer  x152) = (\exists integer  x154; ((((x151<=x154) &&
(x154<=x152)) &&
(('A'==x150[x151]) &&
(x154==(x151+1)))) &&
(\exists integer  x167; ((((x154<=x167) &&
(x167<=x152)) &&
star_A(x150,x154,x167)) &&
(\exists integer  x174; ((((x167<=x174) &&
(x174<=x152)) &&
(('B'==x150[x167]) &&
(x174==(x167+1)))) &&
(x174==x152)))))));*/
/*@
requires (((strlen(x200)>=0) &&
\valid(x200+(0..(strlen(x200)+1)-1))) &&
(strlen(x200)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x200,0,strlen(x200)));
*/
int dfa(char  * x200) {
  int x202 = 1/*true*/;
  int x203 = 0;
  int x204 = 0;
  int x205 = strlen(x200);
  /*@
  loop invariant (((((((strlen(x200)>=0) &&
  \valid(x200+(0..(strlen(x200)+1)-1))) &&
  ((0<=x204) &&
  (x204<=x205))) &&
  ((strlen((x200+x204))>=0) &&
  \valid((x200+x204)+(0..(strlen((x200+x204))+1)-1)))) &&
  (x202 ==> (((x203==2) ==> re_bwd_2(x200,0,x204)) &&
  (((x203==1) ==> re_bwd_1(x200,0,x204)) &&
  ((x203==0) ==> re_bwd_0(x200,0,x204)))))) &&
  ((x203==2) ==> (re_bwd_2(x200,0,x204) ==> re_0(x200,0,x204)))) &&
  ((x203==2) || ((x203==1) || (x203==0))));
  loop assigns x204, x203, x202;
  loop variant (x205-x204);
  */
  for (;;) {
    int x206 = x204;
    int x207 = x206 < x205;
    int x210;
    if (x207) {
      int x208 = x202;
      x210 = x208;
    } else {
      x210 = 0/*false*/;
    }
    if (!x210) break;
    int x212 = x204;
    x202 = 0/*false*/;
    int x215 = x202;
    int x220;
    if (x215) {
      x220 = 0/*false*/;
    } else {
      int x217 = x203;
      int x218 = x217 == 0;
      x220 = x218;
    }
    if (x220) {
      /*@assert ((x203==0) ==> re_bwd_0(x200,0,x204));*/
      /*@assert re_bwd_0(x200,0,x204);*/
      char x213 = x200[x212];
      int x232 = 'A' == x213;
      if (x232) {
        /*@assert re_bwd_1(x200,0,(x204+1));*/
        x203 = 1;
        x202 = 1/*true*/;
        /*@assert re_bwd_1(x200,0,(x204+1));*/
        /*@assert ((x203==1) ==> re_bwd_1(x200,0,(x204+1)));*/
      } else {
      }
    } else {
    }
    int x257 = x202;
    int x262;
    if (x257) {
      x262 = 0/*false*/;
    } else {
      int x259 = x203;
      int x260 = x259 == 1;
      x262 = x260;
    }
    if (x262) {
      /*@assert ((x203==1) ==> re_bwd_1(x200,0,x204));*/
      /*@assert re_bwd_1(x200,0,x204);*/
      char x213 = x200[x212];
      int x232 = 'A' == x213;
      if (x232) {
        /*@assert re_bwd_1(x200,0,(x204+1));*/
        x203 = 1;
        x202 = 1/*true*/;
        /*@assert re_bwd_1(x200,0,(x204+1));*/
        /*@assert ((x203==1) ==> re_bwd_1(x200,0,(x204+1)));*/
      } else {
      }
      int x296 = 'B' == x213;
      if (x296) {
        /*@assert re_bwd_2(x200,0,(x204+1));*/
        x203 = 2;
        x202 = 1/*true*/;
        /*@assert re_bwd_2(x200,0,(x204+1));*/
        /*@assert ((x203==2) ==> re_bwd_2(x200,0,(x204+1)));*/
      } else {
      }
    } else {
    }
    int x321 = x202;
    int x326;
    if (x321) {
      x326 = 0/*false*/;
    } else {
      int x323 = x203;
      int x324 = x323 == 2;
      x326 = x324;
    }
    if (x326) {
      /*@assert ((x203==2) ==> re_bwd_2(x200,0,x204));*/
      /*@assert re_bwd_2(x200,0,x204);*/
    } else {
    }
    /*@assert (x202 ==> (((x203==2) ==> re_bwd_2(x200,0,(x204+1))) &&
    (((x203==1) ==> re_bwd_1(x200,0,(x204+1))) &&
    ((x203==0) ==> re_bwd_0(x200,0,(x204+1))))));*/
    int x359 = x212 + 1;
    x204 = x359;
    /*@assert (x202 ==> (((x203==2) ==> re_bwd_2(x200,0,x204)) &&
    (((x203==1) ==> re_bwd_1(x200,0,x204)) &&
    ((x203==0) ==> re_bwd_0(x200,0,x204)))));*/
  }
  int x455 = x203;
  int x456 = x204;
  int x457 = x456 == x205;
  int x460;
  if (x457) {
    int x458 = x202;
    x460 = x458;
  } else {
    x460 = 0/*false*/;
  }
  int x462;
  if (x460) {
    int x461 = 2 == x455;
    x462 = x461;
  } else {
    x462 = 0/*false*/;
  }
  return x462;
}
