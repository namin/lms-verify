#include <limits.h>
#include <string.h>
/*@ predicate star_A(char  * x51, integer  x52, integer  x53) = (((('A'==x51[x52]) &&
(x53>0)) &&
star_A(x51,0,(x53-1))) || (x52==x53));*/
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
/*@ predicate re_1(char  * x66, integer  x67, integer  x68) = (\exists integer  x70; ((((x67<=x70) &&
(x70<=x68)) &&
star_A(x66,x67,x70)) &&
(\exists integer  x78; ((((x70<=x78) &&
(x78<=x68)) &&
(('B'==x66[x70]) &&
(x78==(x70+1)))) &&
(x78==x68)))));*/
/*@ predicate re_2(char  * x100, integer  x101, integer  x102) = (x101==x102);*/
/*@ predicate re_bwd_0(char  * x105, integer  x106, integer  x107) = (x106==x107);*/
/*@ predicate re_bwd_1(char  * x110, integer  x111, integer  x112) = (\exists integer  x114; ((((x111<=x114) &&
(x114<=x112)) &&
(('A'==x110[x111]) &&
(x114==(x111+1)))) &&
(\exists integer  x127; ((((x114<=x127) &&
(x127<=x112)) &&
star_A(x110,x114,x127)) &&
(x127==x112)))));*/
/*@ predicate re_bwd_2(char  * x144, integer  x145, integer  x146) = (\exists integer  x148; ((((x145<=x148) &&
(x148<=x146)) &&
(('A'==x144[x145]) &&
(x148==(x145+1)))) &&
(\exists integer  x161; ((((x148<=x161) &&
(x161<=x146)) &&
star_A(x144,x148,x161)) &&
(\exists integer  x169; ((((x161<=x169) &&
(x169<=x146)) &&
(('B'==x144[x161]) &&
(x169==(x161+1)))) &&
(x169==x146)))))));*/
/*@
requires (((strlen(x195)>=0) &&
\valid(x195+(0..(strlen(x195)+1)-1))) &&
(strlen(x195)<100));
assigns \nothing;
ensures (\result ==> re_0(x195,0,strlen(x195)));
*/
int dfa(char  * x195) {
  int x197 = 1/*true*/;
  int x198 = 0;
  int x199 = 0;
  int x200 = strlen(x195);
  /*@
  loop invariant (((((((strlen(x195)>=0) &&
  \valid(x195+(0..(strlen(x195)+1)-1))) &&
  ((0<=x199) &&
  (x199<=x200))) &&
  ((strlen((x195+x199))>=0) &&
  \valid((x195+x199)+(0..(strlen((x195+x199))+1)-1)))) &&
  (x197 ==> (((x198==2) ==> re_bwd_2(x195,0,x199)) &&
  (((x198==1) ==> re_bwd_1(x195,0,x199)) &&
  ((x198==0) ==> re_bwd_0(x195,0,x199)))))) &&
  ((x198==2) ==> (re_bwd_2(x195,0,x199) ==> re_0(x195,0,x199)))) &&
  ((x198==2) || ((x198==1) || (x198==0))));
  loop assigns x199, x198, x197;
  loop variant (x200-x199);
  */
  for (;;) {
    int x201 = x199;
    int x202 = x201 < x200;
    int x205;
    if (x202) {
      int x203 = x197;
      x205 = x203;
    } else {
      x205 = 0/*false*/;
    }
    if (!x205) break;
    int x207 = x199;
    char x208 = x195[x207];
    char x209 = x208;
    x197 = 0/*false*/;
    int x211 = x197;
    int x216;
    if (x211) {
      x216 = 0/*false*/;
    } else {
      int x213 = x198;
      int x214 = x213 == 0;
      x216 = x214;
    }
    if (x216) {
      /*@assert ((x198==0) ==> re_bwd_0(x195,0,x199));*/
      /*@assert re_bwd_0(x195,0,x199);*/
      char x228 = x209;
      int x229 = 'A' == x228;
      if (x229) {
        /*@assert re_bwd_1(x195,0,(x199+1));*/
        x198 = 1;
        x197 = 1/*true*/;
        /*@assert re_bwd_1(x195,0,(x199+1));*/
        /*@assert ((x198==1) ==> re_bwd_1(x195,0,(x199+1)));*/
      } else {
      }
    } else {
    }
    int x254 = x197;
    int x259;
    if (x254) {
      x259 = 0/*false*/;
    } else {
      int x256 = x198;
      int x257 = x256 == 1;
      x259 = x257;
    }
    if (x259) {
      /*@assert ((x198==1) ==> re_bwd_1(x195,0,x199));*/
      /*@assert re_bwd_1(x195,0,x199);*/
      char x271 = x209;
      int x272 = 'A' == x271;
      if (x272) {
        /*@assert re_bwd_1(x195,0,(x199+1));*/
        x198 = 1;
        x197 = 1/*true*/;
        /*@assert re_bwd_1(x195,0,(x199+1));*/
        /*@assert ((x198==1) ==> re_bwd_1(x195,0,(x199+1)));*/
      } else {
      }
      int x295 = 'B' == x271;
      if (x295) {
        /*@assert re_bwd_2(x195,0,(x199+1));*/
        x198 = 2;
        x197 = 1/*true*/;
        /*@assert re_bwd_2(x195,0,(x199+1));*/
        /*@assert ((x198==2) ==> re_bwd_2(x195,0,(x199+1)));*/
      } else {
      }
    } else {
    }
    int x320 = x197;
    int x325;
    if (x320) {
      x325 = 0/*false*/;
    } else {
      int x322 = x198;
      int x323 = x322 == 2;
      x325 = x323;
    }
    if (x325) {
      /*@assert ((x198==2) ==> re_bwd_2(x195,0,x199));*/
      /*@assert re_bwd_2(x195,0,x199);*/
    } else {
    }
    /*@assert (x197 ==> (((x198==2) ==> re_bwd_2(x195,0,(x199+1))) &&
    (((x198==1) ==> re_bwd_1(x195,0,(x199+1))) &&
    ((x198==0) ==> re_bwd_0(x195,0,(x199+1))))));*/
    int x358 = x207 + 1;
    x199 = x358;
    /*@assert (x197 ==> (((x198==2) ==> re_bwd_2(x195,0,x199)) &&
    (((x198==1) ==> re_bwd_1(x195,0,x199)) &&
    ((x198==0) ==> re_bwd_0(x195,0,x199)))));*/
  }
  int x454 = x198;
  int x455 = x199;
  int x456 = x455 == x200;
  int x459;
  if (x456) {
    int x457 = x197;
    x459 = x457;
  } else {
    x459 = 0/*false*/;
  }
  int x461;
  if (x459) {
    int x460 = 2 == x454;
    x461 = x460;
  } else {
    x461 = 0/*false*/;
  }
  return x461;
}
