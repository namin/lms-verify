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
  char  *x205 = x200;
  /*@
  loop invariant ((((((((strlen(x200)>=0) &&
  \valid(x200+(0..(strlen(x200)+1)-1))) &&
  ((0<=x204) &&
  (x204<=strlen(x200)))) &&
  (x205==(x200+x204))) &&
  ((strlen((x200+x204))>=0) &&
  \valid((x200+x204)+(0..(strlen((x200+x204))+1)-1)))) &&
  (x202 ==> (((x203==2) ==> re_bwd_2(x200,0,x204)) &&
  (((x203==1) ==> re_bwd_1(x200,0,x204)) &&
  ((x203==0) ==> re_bwd_0(x200,0,x204)))))) &&
  ((x203==2) ==> (re_bwd_2(x200,0,x204) ==> re_0(x200,0,x204)))) &&
  ((x203==2) || ((x203==1) || (x203==0))));
  loop assigns x205, x204, x203, x202;
  loop variant strlen(x205);
  */
  for (;;) {
    char  *x207 = x205;
    char x208 = x207[0];
    int x209 = x208 == '\0';
    int x213;
    if (x209) {
      x213 = 0/*false*/;
    } else {
      int x211 = x202;
      x213 = x211;
    }
    if (!x213) break;
    char  *x215 = x205;
    x202 = 0/*false*/;
    int x218 = x202;
    int x223;
    if (x218) {
      x223 = 0/*false*/;
    } else {
      int x220 = x203;
      int x221 = x220 == 0;
      x223 = x221;
    }
    if (x223) {
      /*@assert ((x203==0) ==> re_bwd_0(x200,0,x204));*/
      /*@assert re_bwd_0(x200,0,x204);*/
      char x216 = x215[0];
      int x235 = 'A' == x216;
      if (x235) {
        /*@assert re_bwd_1(x200,0,(x204+1));*/
        x203 = 1;
        x202 = 1/*true*/;
        /*@assert re_bwd_1(x200,0,(x204+1));*/
        /*@assert ((x203==1) ==> re_bwd_1(x200,0,(x204+1)));*/
      } else {
      }
    } else {
    }
    int x260 = x202;
    int x265;
    if (x260) {
      x265 = 0/*false*/;
    } else {
      int x262 = x203;
      int x263 = x262 == 1;
      x265 = x263;
    }
    if (x265) {
      /*@assert ((x203==1) ==> re_bwd_1(x200,0,x204));*/
      /*@assert re_bwd_1(x200,0,x204);*/
      char x216 = x215[0];
      int x235 = 'A' == x216;
      if (x235) {
        /*@assert re_bwd_1(x200,0,(x204+1));*/
        x203 = 1;
        x202 = 1/*true*/;
        /*@assert re_bwd_1(x200,0,(x204+1));*/
        /*@assert ((x203==1) ==> re_bwd_1(x200,0,(x204+1)));*/
      } else {
      }
      int x299 = 'B' == x216;
      if (x299) {
        /*@assert re_bwd_2(x200,0,(x204+1));*/
        x203 = 2;
        x202 = 1/*true*/;
        /*@assert re_bwd_2(x200,0,(x204+1));*/
        /*@assert ((x203==2) ==> re_bwd_2(x200,0,(x204+1)));*/
      } else {
      }
    } else {
    }
    int x324 = x202;
    int x329;
    if (x324) {
      x329 = 0/*false*/;
    } else {
      int x326 = x203;
      int x327 = x326 == 2;
      x329 = x327;
    }
    if (x329) {
      /*@assert ((x203==2) ==> re_bwd_2(x200,0,x204));*/
      /*@assert re_bwd_2(x200,0,x204);*/
    } else {
    }
    /*@assert (x202 ==> (((x203==2) ==> re_bwd_2(x200,0,(x204+1))) &&
    (((x203==1) ==> re_bwd_1(x200,0,(x204+1))) &&
    ((x203==0) ==> re_bwd_0(x200,0,(x204+1))))));*/
    int x362 = x204;
    int x363 = x362 + 1;
    x204 = x363;
    char  *x365 = x215+1;
    x205 = x365;
    /*@assert (x202 ==> (((x203==2) ==> re_bwd_2(x200,0,x204)) &&
    (((x203==1) ==> re_bwd_1(x200,0,x204)) &&
    ((x203==0) ==> re_bwd_0(x200,0,x204)))));*/
  }
  int x468 = x203;
  int x469 = x204;
  int x206 = strlen(x200);
  int x470 = x469 == x206;
  int x473;
  if (x470) {
    int x471 = x202;
    x473 = x471;
  } else {
    x473 = 0/*false*/;
  }
  int x475;
  if (x473) {
    int x474 = 2 == x468;
    x475 = x474;
  } else {
    x475 = 0/*false*/;
  }
  return x475;
}
