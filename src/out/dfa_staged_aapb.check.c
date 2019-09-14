#include <limits.h>
#include <string.h>
/*@ predicate star_A(char  * x29, integer  x30, integer  x31) = ((x30==x31) || ((x30<x31) &&
((('A'==x29[x30]) &&
((x30+1)==(x30+1))) &&
star_A(x29,(x30+1),x31))));*/
void lemma_star_A_from_all(char  * x47, int  x48, int  x49);
void lemma_star_A_all(char  * x51, int  x52, int  x53);
void lemma_star_A(char  * x55, int  x56, int  x57, int  x58);
void lemma_star_A_dec(char  * x60, int  x61, int  x62);
/*@ predicate re_0(char  * x0, integer  x1, integer  x2) = (((('A'==x0[x1]) &&
((x1+1)==(x1+1))) &&
((x1+1)<=x2)) &&
((((x1+1)<=(x2-1)) &&
star_A(x0,(x1+1),(x2-1))) &&
((((x2-1)<=x2) &&
(('B'==x0[(x2-1)]) &&
(x2==((x2-1)+1)))) &&
(x2>=x2))));*/
/*@ predicate re_1(char  * x64, integer  x65, integer  x66) = (((x65<=(x66-1)) &&
star_A(x64,x65,(x66-1))) &&
((((x66-1)<=x66) &&
(('B'==x64[(x66-1)]) &&
(x66==((x66-1)+1)))) &&
(x66>=x66)));*/
/*@ predicate re_2(char  * x84, integer  x85, integer  x86) = (x85>=x86);*/
/*@ predicate re_bwd_0(char  * x89, integer  x90, integer  x91) = (x90>=x91);*/
/*@ predicate re_bwd_1(char  * x94, integer  x95, integer  x96) = (((('A'==x94[x95]) &&
((x95+1)==(x95+1))) &&
((x95+1)<=x96)) &&
((((x95+1)<=x96) &&
star_A(x94,(x95+1),x96)) &&
(x96>=x96)));*/
/*@ predicate re_bwd_2(char  * x113, integer  x114, integer  x115) = (((('A'==x113[x114]) &&
((x114+1)==(x114+1))) &&
((x114+1)<=x115)) &&
((((x114+1)<=(x115-1)) &&
star_A(x113,(x114+1),(x115-1))) &&
((((x115-1)<=x115) &&
(('B'==x113[(x115-1)]) &&
(x115==((x115-1)+1)))) &&
(x115>=x115))));*/
/*@
requires (((strlen(x142)>=0) &&
\valid(x142+(0..strlen(x142)))) &&
(strlen(x142)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x142,0,strlen(x142)));
*/
int dfa(char  * x142) {
  int x144 = 1/*true*/;
  int x145 = 0;
  //@ ghost int x146 = 0;
  char  *x147 = x142;
  /*@
  loop invariant (((((strlen(x142)>=0) &&
  \valid(x142+(0..strlen(x142)))) &&
  ((0<=x146) &&
  (x146<=strlen(x142)))) &&
  (x147==(x142+x146))) &&
  ((strlen((x142+x146))>=0) &&
  \valid((x142+x146)+(0..strlen((x142+x146))))));
  loop invariant (((x145==0) &&
  x144) ==> re_bwd_0(x142,0,x146));
  loop invariant (((x145==1) &&
  x144) ==> re_bwd_1(x142,0,x146));
  loop invariant (((x145==2) &&
  x144) ==> re_bwd_2(x142,0,x146));
  loop invariant (((x145==0) &&
  (!x144)) ==> re_bwd_0(x142,0,(x146-1)));
  loop invariant (((x145==1) &&
  (!x144)) ==> re_bwd_1(x142,0,(x146-1)));
  loop invariant (((x145==2) &&
  (!x144)) ==> re_bwd_2(x142,0,(x146-1)));
  loop invariant ((((x145==2) &&
  (x147[0]=='\0')) &&
  x144) ==> re_0(x142,0,x146));
  loop invariant ((x145==2) || ((x145==1) || (x145==0)));
  loop assigns x147, x146, x145, x144;
  loop variant strlen(x147);
  */
  for (;;) {
    char  *x149 = x147;
    char x150 = x149[0];
    int x151 = x150 == '\0';
    int x155;
    if (x151) {
      x155 = 0/*false*/;
    } else {
      int x153 = x144;
      x155 = x153;
    }
    if (!x155) break;
    int x238 = x145;
    int x239 = x238 == 2;
    int x342;
    if (x239) {
      /*@assert ((x145==2) ==> re_bwd_2(x142,0,x146));*/
      /*@assert re_bwd_2(x142,0,x146);*/
      char  *x251 = x147;
      x342 = 0/*false*/;
    } else {
      int x254 = x238 == 1;
      int x340;
      if (x254) {
        /*@assert ((x145==1) ==> re_bwd_1(x142,0,x146));*/
        /*@assert re_bwd_1(x142,0,x146);*/
        char  *x266 = x147;
        char x267 = x266[0];
        int x268 = 'B' == x267;
        int x308;
        if (x268) {
          /*@assert re_bwd_1(x142,0,x146);*/
          x145 = 2;
          /*@assert re_bwd_2(x142,0,(x146+1));*/
          /*@assert (((x142+(x146+1))[0]=='\0') ==> re_0(x142,0,(x146+1)));*/
          x308 = 1/*true*/;
        } else {
          int x289 = 'A' == x267;
          int x306;
          if (x289) {
            /*@assert re_bwd_1(x142,0,x146);*/
            x145 = 1;
            /*@ghost lemma_star_A(x142,1,x146,(x146+1));*/
            /*@assert re_bwd_1(x142,0,(x146+1));*/
            x306 = 1/*true*/;
          } else {
            x306 = 0/*false*/;
          }
          x308 = x306;
        }
        x340 = x308;
      } else {
        int x310 = x238 == 0;
        int x338;
        if (x310) {
          /*@assert ((x145==0) ==> re_bwd_0(x142,0,x146));*/
          /*@assert re_bwd_0(x142,0,x146);*/
          char  *x322 = x147;
          char x323 = x322[0];
          int x324 = 'A' == x323;
          int x336;
          if (x324) {
            /*@assert re_bwd_0(x142,0,x146);*/
            x145 = 1;
            /*@assert re_bwd_1(x142,0,(x146+1));*/
            x336 = 1/*true*/;
          } else {
            x336 = 0/*false*/;
          }
          x338 = x336;
        } else {
          x338 = 0/*false*/;
        }
        x340 = x338;
      }
      x342 = x340;
    }
    x144 = x342;
    char  *x344 = x147;
    char  *x345 = x344+1;
    x147 = x345;
    /*@ghost x146 = (x146+1);*/
  }
  char  *x391 = x147;
  char x392 = x391[0];
  int x393 = x392 == '\0';
  int x396;
  if (x393) {
    int x394 = x144;
    x396 = x394;
  } else {
    x396 = 0/*false*/;
  }
  int x400;
  if (x396) {
    int x397 = x145;
    int x398 = x397 == 2;
    x400 = x398;
  } else {
    x400 = 0/*false*/;
  }
  return x400;
}
/*@
requires ((((strlen(x408)>=0) &&
\valid(x408+(0..strlen(x408)))) &&
(((0<=x409) &&
(x409<=x410)) &&
(x410<=strlen(x408)))) &&
star_A(x408,x409,x410));
assigns \nothing;
ensures (\forall int  x464; ((((0<=x409) &&
(x409<=x464)) &&
(x464<x410)) ==> (('A'==x408[x464]) &&
((x464+1)==(x464+1)))));
*/
void lemma_star_A_all(char  * x408, int  x409, int  x410) {
  int x412 = x409;
  /*@
  loop invariant (((0<=x409) &&
  (x409<=x412)) &&
  (x410<=strlen(x408)));
  loop invariant star_A(x408,x412,x410);
  loop invariant (\forall int  x419; (((x409<=x419) &&
  (x419<x412)) ==> ((x408+x419)[0]=='A')));
  loop assigns x412;
  loop variant (x410-x412);
  */
  for (;;) {
    int x413 = x412;
    int x414 = x413 < x410;
    if (!x414) break;
    int x431 = x412;
    int x432 = x431 + 1;
    x412 = x432;
  }
}
/*@
requires ((((strlen(x476)>=0) &&
\valid(x476+(0..strlen(x476)))) &&
(((0<=x477) &&
(x477<=x478)) &&
(x478<=strlen(x476)))) &&
(\forall int  x528; ((((0<=x477) &&
(x477<=x528)) &&
(x528<x478)) ==> (('A'==x476[x528]) &&
((x528+1)==(x528+1))))));
assigns \nothing;
ensures star_A(x476,x477,x478);
*/
void lemma_star_A_from_all(char  * x476, int  x477, int  x478) {
  int x480 = x478;
  /*@
  loop invariant (((0<=x477) &&
  (x477<=x480)) &&
  (x478<=strlen(x476)));
  loop invariant star_A(x476,x480,x478);
  loop invariant (\forall int  x487; ((((0<=x477) &&
  (x477<=x487)) &&
  (x487<x478)) ==> (('A'==x476[x487]) &&
  ((x487+1)==(x487+1)))));
  loop assigns x480;
  loop variant x480;
  */
  for (;;) {
    int x481 = x480;
    int x482 = x477 < x481;
    if (!x482) break;
    int x500 = x480;
    int x501 = x500 - 1;
    x480 = x501;
  }
}
/*@
requires (((((strlen(x543)>=0) &&
\valid(x543+(0..strlen(x543)))) &&
((0<=x544) &&
(x544<=x545))) &&
((x544<x545) &&
(x545<=strlen(x543)))) &&
star_A(x543,x544,x545));
assigns \nothing;
ensures star_A(x543,x544,(x545-1));
*/
void lemma_star_A_dec(char  * x543, int  x544, int  x545) {
  /*@ghost lemma_star_A_all(x543,x544,x545);*/
  /*@ghost lemma_star_A_from_all(x543,x544,(x545-1));*/
}
/*@
requires ((((((((strlen(x574)>=0) &&
\valid(x574+(0..strlen(x574)))) &&
((0<=x575) &&
(x575<=x576))) &&
((0<=x576) &&
(x576<x577))) &&
((0<=x577) &&
(x577<=strlen(x574)))) &&
star_A(x574,x575,x576)) &&
star_A(x574,x576,x577)) &&
((x576+1)==x577));
assigns \nothing;
ensures star_A(x574,x575,x577);
*/
void lemma_star_A(char  * x574, int  x575, int  x576, int  x577) {
  int x579 = x576;
  /*@
  loop invariant ((((0<=x575) &&
  (x575<=x579)) &&
  (x579<=x577)) &&
  (x577<=strlen(x574)));
  loop invariant star_A(x574,x579,x577);
  loop invariant star_A(x574,x575,x579);
  loop assigns x579;
  loop variant x579;
  */
  for (;;) {
    int x580 = x579;
    int x581 = x575 < x580;
    if (!x581) break;
    int x589 = x579;
    lemma_star_A_dec(x574,x575,x589);
    /*@assert (x575<x579);*/
    /*@ghost lemma_star_A_all(x574,x575,x579);*/
    /*@assert (('A'==x574[(x579-1)]) &&
    (x579==((x579-1)+1)));*/
    /*@assert star_A(x574,x579,x577);*/
    /*@assert star_A(x574,(x579-1),x577);*/
    int x617 = x589 - 1;
    x579 = x617;
  }
}
