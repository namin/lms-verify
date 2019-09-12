#include <limits.h>
#include <string.h>
/*@ predicate star_A(char  * x39, integer  x40, integer  x41) = (\exists integer  x43; ((((x40<x43) &&
(x43<=x41)) ==> ((('A'==x39[x40]) &&
(x43==(x40+1))) &&
star_A(x39,x43,x41))) || (x40==x41)));*/
/*@ predicate re_0(char  * x0, integer  x1, integer  x2) = (\exists integer  x4; ((((x1<=x4) &&
(x4<=x2)) &&
(('A'==x0[x1]) &&
(x4==(x1+1)))) &&
(\exists integer  x14; ((((x4<=x14) &&
(x14<=x2)) &&
star_A(x0,x4,x14)) &&
(\exists integer  x21; ((((x14<=x21) &&
(x21<=x2)) &&
(('B'==x0[x14]) &&
(x21==(x14+1)))) &&
(x21==x2)))))));*/
/*@ predicate re_1(char  * x60, integer  x61, integer  x62) = (\exists integer  x64; ((((x61<=x64) &&
(x64<=x62)) &&
star_A(x60,x61,x64)) &&
(\exists integer  x70; ((((x64<=x70) &&
(x70<=x62)) &&
(('B'==x60[x64]) &&
(x70==(x64+1)))) &&
(x70==x62)))));*/
/*@ predicate re_2(char  * x85, integer  x86, integer  x87) = (x86==x87);*/
/*@ predicate re_bwd_0(char  * x90, integer  x91, integer  x92) = (x91==x92);*/
/*@ predicate re_bwd_1(char  * x95, integer  x96, integer  x97) = (\exists integer  x99; ((((x96<=x99) &&
(x99<=x97)) &&
(('A'==x95[x96]) &&
(x99==(x96+1)))) &&
(\exists integer  x109; ((((x99<=x109) &&
(x109<=x97)) &&
star_A(x95,x99,x109)) &&
(x109==x97)))));*/
/*@ predicate re_bwd_2(char  * x120, integer  x121, integer  x122) = (\exists integer  x124; ((((x121<=x124) &&
(x124<=x122)) &&
(('A'==x120[x121]) &&
(x124==(x121+1)))) &&
(\exists integer  x134; ((((x124<=x134) &&
(x134<=x122)) &&
star_A(x120,x124,x134)) &&
(\exists integer  x140; ((((x134<=x140) &&
(x140<=x122)) &&
(('B'==x120[x134]) &&
(x140==(x134+1)))) &&
(x140==x122)))))));*/
/*@ predicate star_starting_A(char  * x208, integer  x209, integer  x210) = ((((x209==x210) || (('A'==x208[x209]) &&
(x210>=(x209+1)))) || (\exists integer  x219; (((x209<x219) &&
(x219<=x210)) ==> ((('A'==x208[x209]) &&
(x219==(x209+1))) &&
star_starting_A(x208,x219,x210))))) || (x210>=x209));*/
/*@ predicate re0(char  * x157, integer  x158, integer  x159) = (((x158==x159) || (('A'==x157[x158]) &&
(x159>=(x158+1)))) || (\exists integer  x168; ((((x158<=x168) &&
(x168<=x159)) &&
(('A'==x157[x158]) &&
(x168==(x158+1)))) &&
(star_starting_A(x157,x168,x159) || (\exists integer  x176; ((((x168<=x176) &&
(x176<=x159)) &&
star_A(x157,x168,x176)) &&
(((x176==x159) || (('B'==x157[x176]) &&
(x159>=(x176+1)))) || (\exists integer  x189; ((((x176<=x189) &&
(x189<=x159)) &&
(('B'==x157[x176]) &&
(x189==(x176+1)))) &&
(x159>=x189))))))))));*/
/*@
requires (((strlen(x234)>=0) &&
\valid(x234+(0..strlen(x234)))) &&
(strlen(x234)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x234,0,strlen(x234)));
*/
int dfa(char  * x234) {
  int x236 = 1/*true*/;
  int x237 = 0;
  //@ ghost int x238 = 0;
  char  *x239 = x234;
  /*@
  loop invariant ((((((((strlen(x234)>=0) &&
  \valid(x234+(0..strlen(x234)))) &&
  ((0<=x238) &&
  (x238<=strlen(x234)))) &&
  (x239==(x234+x238))) &&
  ((strlen((x234+x238))>=0) &&
  \valid((x234+x238)+(0..strlen((x234+x238)))))) &&
  (x236 ==> (((x237==2) ==> re_bwd_2(x234,0,x238)) &&
  (((x237==1) ==> re_bwd_1(x234,0,x238)) &&
  ((x237==0) ==> re_bwd_0(x234,0,x238)))))) &&
  ((x237==2) ==> (re_bwd_2(x234,0,x238) ==> re_0(x234,0,x238)))) &&
  ((x237==2) || ((x237==1) || (x237==0))));
  loop assigns x239, x238, x237, x236;
  loop variant strlen(x239);
  */
  for (;;) {
    char  *x241 = x239;
    char x242 = x241[0];
    int x243 = x242 == '\0';
    int x247;
    if (x243) {
      x247 = 0/*false*/;
    } else {
      int x245 = x236;
      x247 = x245;
    }
    if (!x247) break;
    char  *x249 = x239;
    int x251 = x237;
    int x252 = x251 == 0;
    int x258;
    if (x252) {
      char x250 = x249[0];
      int x253 = 'A' == x250;
      int x256;
      if (x253) {
        x237 = 1;
        x256 = 1/*true*/;
      } else {
        x256 = 0/*false*/;
      }
      x258 = x256;
    } else {
      x258 = 0/*false*/;
    }
    int x259 = x237;
    int x260 = x259 == 1;
    int x269;
    if (x260) {
      char x250 = x249[0];
      int x253 = 'A' == x250;
      int x263;
      if (x253) {
        x237 = 1;
        x263 = 1/*true*/;
      } else {
        x263 = 0/*false*/;
      }
      int x264 = 'B' == x250;
      int x267;
      if (x264) {
        x237 = 2;
        x267 = 1/*true*/;
      } else {
        x267 = x263;
      }
      x269 = x267;
    } else {
      x269 = x258;
    }
    int x270 = x237;
    int x271 = x270 == 2;
    int x272;
    if (x271) {
      x272 = 0/*false*/;
    } else {
      x272 = x269;
    }
    x236 = x272;
    /*@assert (x236 ==> (((x237==2) ==> re_bwd_2(x234,0,(x238+1))) &&
    (((x237==1) ==> re_bwd_1(x234,0,(x238+1))) &&
    ((x237==0) ==> re_bwd_0(x234,0,(x238+1))))));*/
    //@ ghost int x293 = x238;
    //@ ghost int x294 = x293 + 1;
    //@ ghost x238 = x294;
    char  *x296 = x249+1;
    x239 = x296;
    /*@assert (x236 ==> (((x237==2) ==> re_bwd_2(x234,0,x238)) &&
    (((x237==1) ==> re_bwd_1(x234,0,x238)) &&
    ((x237==0) ==> re_bwd_0(x234,0,x238)))));*/
  }
  int x390 = x237;
  char  *x391 = x239;
  char x392 = x391[0];
  int x393 = x392 == '\0';
  int x396;
  if (x393) {
    int x394 = x236;
    x396 = x394;
  } else {
    x396 = 0/*false*/;
  }
  int x398;
  if (x396) {
    int x397 = 2 == x390;
    x398 = x397;
  } else {
    x398 = 0/*false*/;
  }
  return x398;
}
