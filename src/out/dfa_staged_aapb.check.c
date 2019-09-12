#include <limits.h>
#include <string.h>
/*@ predicate star_A(char  * x39, integer  x40, integer  x41) = ((x40==x41) || (\exists integer  x44; (((x40<x44) &&
(x44<=x41)) ==> ((('A'==x39[x40]) &&
(x44==(x40+1))) &&
star_A(x39,x44,x41)))));*/
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
ensures ((\result ==> re_0(x234,0,strlen(x234))) &&
(re_0(x234,0,strlen(x234)) ==> \result));
*/
int dfa(char  * x234) {
  int x236 = 1/*true*/;
  int x237 = 0;
  //@ ghost int x238 = 0;
  char  *x239 = x234;
  /*@
  loop invariant (((((((((((strlen(x234)>=0) &&
  \valid(x234+(0..strlen(x234)))) &&
  ((0<=x238) &&
  (x238<=strlen(x234)))) &&
  (x239==(x234+x238))) &&
  ((strlen((x234+x238))>=0) &&
  \valid((x234+x238)+(0..strlen((x234+x238)))))) &&
  (x236 ==> (((x237==2) ==> (re_bwd_2(x234,0,x238) &&
  (!re_bwd_1(x234,0,x238) ||
  (!re_bwd_0(x234,0,x238))))) &&
  (((x237==1) ==> (re_bwd_1(x234,0,x238) &&
  (!re_bwd_2(x234,0,x238) ||
  (!re_bwd_0(x234,0,x238))))) &&
  ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
  (!re_bwd_2(x234,0,x238) ||
  (!re_bwd_1(x234,0,x238))))))))) &&
  (x236 ==> re0(x234,0,x238))) &&
  (re0(x234,0,x238) ==> (re_bwd_2(x234,0,x238) || (re_bwd_1(x234,0,x238) || re_bwd_0(x234,0,x238))))) &&
  ((!x236) ==> (!(re_bwd_2(x234,0,x238) || (re_bwd_1(x234,0,x238) || re_bwd_0(x234,0,x238)))))) &&
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
    /*@assert (x236 ==> (((x237==2) ==> (re_bwd_2(x234,0,x238) &&
    (!re_bwd_1(x234,0,x238) ||
    (!re_bwd_0(x234,0,x238))))) &&
    (((x237==1) ==> (re_bwd_1(x234,0,x238) &&
    (!re_bwd_2(x234,0,x238) ||
    (!re_bwd_0(x234,0,x238))))) &&
    ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
    (!re_bwd_2(x234,0,x238) ||
    (!re_bwd_1(x234,0,x238))))))));*/
    /*@assert (((x237==2) ==> (re_bwd_2(x234,0,x238) &&
    (!re_bwd_1(x234,0,x238) ||
    (!re_bwd_0(x234,0,x238))))) &&
    (((x237==1) ==> (re_bwd_1(x234,0,x238) &&
    (!re_bwd_2(x234,0,x238) ||
    (!re_bwd_0(x234,0,x238))))) &&
    ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
    (!re_bwd_2(x234,0,x238) ||
    (!re_bwd_1(x234,0,x238)))))));*/
    char  *x305 = x239;
    x236 = 0/*false*/;
    int x308 = x236;
    int x313;
    if (x308) {
      x313 = 0/*false*/;
    } else {
      int x310 = x237;
      int x311 = x310 == 0;
      x313 = x311;
    }
    if (x313) {
      /*@assert (((x237==2) ==> (re_bwd_2(x234,0,x238) &&
      (!re_bwd_1(x234,0,x238) ||
      (!re_bwd_0(x234,0,x238))))) &&
      (((x237==1) ==> (re_bwd_1(x234,0,x238) &&
      (!re_bwd_2(x234,0,x238) ||
      (!re_bwd_0(x234,0,x238))))) &&
      ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
      (!re_bwd_2(x234,0,x238) ||
      (!re_bwd_1(x234,0,x238)))))));*/
      /*@assert ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
      (!re_bwd_2(x234,0,x238) ||
      (!re_bwd_1(x234,0,x238)))));*/
      char x306 = x305[0];
      int x355 = 'A' == x306;
      if (x355) {
        x237 = 1;
        x236 = 1/*true*/;
      } else {
      }
    } else {
    }
    int x362 = x236;
    int x367;
    if (x362) {
      x367 = 0/*false*/;
    } else {
      int x364 = x237;
      int x365 = x364 == 1;
      x367 = x365;
    }
    if (x367) {
      /*@assert (((x237==2) ==> (re_bwd_2(x234,0,x238) &&
      (!re_bwd_1(x234,0,x238) ||
      (!re_bwd_0(x234,0,x238))))) &&
      (((x237==1) ==> (re_bwd_1(x234,0,x238) &&
      (!re_bwd_2(x234,0,x238) ||
      (!re_bwd_0(x234,0,x238))))) &&
      ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
      (!re_bwd_2(x234,0,x238) ||
      (!re_bwd_1(x234,0,x238)))))));*/
      /*@assert ((x237==1) ==> (re_bwd_1(x234,0,x238) &&
      (!re_bwd_2(x234,0,x238) ||
      (!re_bwd_0(x234,0,x238)))));*/
      char x306 = x305[0];
      int x355 = 'A' == x306;
      if (x355) {
        x237 = 1;
        x236 = 1/*true*/;
      } else {
      }
      int x413 = 'B' == x306;
      if (x413) {
        x237 = 2;
        x236 = 1/*true*/;
      } else {
      }
    } else {
    }
    int x420 = x236;
    int x425;
    if (x420) {
      x425 = 0/*false*/;
    } else {
      int x422 = x237;
      int x423 = x422 == 2;
      x425 = x423;
    }
    if (x425) {
      /*@assert (((x237==2) ==> (re_bwd_2(x234,0,x238) &&
      (!re_bwd_1(x234,0,x238) ||
      (!re_bwd_0(x234,0,x238))))) &&
      (((x237==1) ==> (re_bwd_1(x234,0,x238) &&
      (!re_bwd_2(x234,0,x238) ||
      (!re_bwd_0(x234,0,x238))))) &&
      ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
      (!re_bwd_2(x234,0,x238) ||
      (!re_bwd_1(x234,0,x238)))))));*/
      /*@assert ((x237==2) ==> (re_bwd_2(x234,0,x238) &&
      (!re_bwd_1(x234,0,x238) ||
      (!re_bwd_0(x234,0,x238)))));*/
    } else {
    }
    if (x420) {
    } else {
      int x469 = x237;
      int x470 = x469 == 0;
      if (x470) {
        /*@assert ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_1(x234,0,x238)))));*/
        /*@assert (re_bwd_0(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_1(x234,0,x238))));*/
        /*@assert (!re_bwd_0(x234,0,(x238+1)));*/
      } else {
      }
      int x504 = x469 == 1;
      if (x504) {
        /*@assert ((x237==1) ==> (re_bwd_1(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238)))));*/
        /*@assert (re_bwd_1(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238))));*/
        /*@assert (!re_bwd_0(x234,0,(x238+1)));*/
      } else {
      }
      int x538 = x469 == 2;
      if (x538) {
        /*@assert ((x237==2) ==> (re_bwd_2(x234,0,x238) &&
        (!re_bwd_1(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238)))));*/
        /*@assert (re_bwd_2(x234,0,x238) &&
        (!re_bwd_1(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238))));*/
        /*@assert (!re_bwd_0(x234,0,(x238+1)));*/
      } else {
      }
      if (x470) {
        /*@assert ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_1(x234,0,x238)))));*/
        /*@assert (re_bwd_0(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_1(x234,0,x238))));*/
        /*@assert (!(x239[0]=='A'));*/
        /*@assert (!re_bwd_1(x234,0,(x238+1)));*/
      } else {
      }
      if (x504) {
        /*@assert ((x237==1) ==> (re_bwd_1(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238)))));*/
        /*@assert (re_bwd_1(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238))));*/
        /*@assert (!(x239[0]=='A'));*/
        /*@assert (!re_bwd_1(x234,0,(x238+1)));*/
      } else {
      }
      if (x538) {
        /*@assert ((x237==2) ==> (re_bwd_2(x234,0,x238) &&
        (!re_bwd_1(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238)))));*/
        /*@assert (re_bwd_2(x234,0,x238) &&
        (!re_bwd_1(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238))));*/
        /*@assert (!re_bwd_1(x234,0,(x238+1)));*/
      } else {
      }
      if (x470) {
        /*@assert ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_1(x234,0,x238)))));*/
        /*@assert (re_bwd_0(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_1(x234,0,x238))));*/
        /*@assert (!re_bwd_2(x234,0,(x238+1)));*/
      } else {
      }
      if (x504) {
        /*@assert ((x237==1) ==> (re_bwd_1(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238)))));*/
        /*@assert (re_bwd_1(x234,0,x238) &&
        (!re_bwd_2(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238))));*/
        /*@assert (!(x239[0]=='B'));*/
        /*@assert (!re_bwd_2(x234,0,(x238+1)));*/
      } else {
      }
      if (x538) {
        /*@assert ((x237==2) ==> (re_bwd_2(x234,0,x238) &&
        (!re_bwd_1(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238)))));*/
        /*@assert (re_bwd_2(x234,0,x238) &&
        (!re_bwd_1(x234,0,x238) ||
        (!re_bwd_0(x234,0,x238))));*/
        /*@assert (!re_bwd_2(x234,0,(x238+1)));*/
      } else {
      }
      /*@assert (!(re_bwd_2(x234,0,(x238+1)) || (re_bwd_1(x234,0,(x238+1)) || re_bwd_0(x234,0,(x238+1)))));*/
    }
    /*@assert ((!x236) ==> (!(re_bwd_2(x234,0,(x238+1)) || (re_bwd_1(x234,0,(x238+1)) || re_bwd_0(x234,0,(x238+1))))));*/
    /*@assert ((!(re_bwd_2(x234,0,(x238+1)) || (re_bwd_1(x234,0,(x238+1)) || re_bwd_0(x234,0,(x238+1))))) ==> (!re0(x234,0,(x238+1))));*/
    /*@assert (x236 ==> (((x237==2) ==> (re_bwd_2(x234,0,(x238+1)) &&
    (!re_bwd_1(x234,0,(x238+1)) ||
    (!re_bwd_0(x234,0,(x238+1)))))) &&
    (((x237==1) ==> (re_bwd_1(x234,0,(x238+1)) &&
    (!re_bwd_2(x234,0,(x238+1)) ||
    (!re_bwd_0(x234,0,(x238+1)))))) &&
    ((x237==0) ==> (re_bwd_0(x234,0,(x238+1)) &&
    (!re_bwd_2(x234,0,(x238+1)) ||
    (!re_bwd_1(x234,0,(x238+1)))))))));*/
    //@ ghost int x845 = x238;
    //@ ghost int x846 = x845 + 1;
    //@ ghost x238 = x846;
    char  *x848 = x305+1;
    x239 = x848;
    /*@assert (x236 ==> (((x237==2) ==> (re_bwd_2(x234,0,x238) &&
    (!re_bwd_1(x234,0,x238) ||
    (!re_bwd_0(x234,0,x238))))) &&
    (((x237==1) ==> (re_bwd_1(x234,0,x238) &&
    (!re_bwd_2(x234,0,x238) ||
    (!re_bwd_0(x234,0,x238))))) &&
    ((x237==0) ==> (re_bwd_0(x234,0,x238) &&
    (!re_bwd_2(x234,0,x238) ||
    (!re_bwd_1(x234,0,x238))))))));*/
  }
  int x992 = x237;
  char  *x993 = x239;
  char x994 = x993[0];
  int x995 = x994 == '\0';
  int x998;
  if (x995) {
    int x996 = x236;
    x998 = x996;
  } else {
    x998 = 0/*false*/;
  }
  int x1000;
  if (x998) {
    int x999 = 2 == x992;
    x1000 = x999;
  } else {
    x1000 = 0/*false*/;
  }
  /*@assert (re0(x234,0,x238) ==> x1000);*/
  /*@assert ((x239[0]=='\0') ==> (x238==strlen(x234)));*/
  /*@assert (re0(x234,0,strlen(x234)) ==> x1000);*/
  return x1000;
}
