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
    int x347;
    if (x239) {
      /*@assert ((x145==2) ==> re_bwd_2(x142,0,x146));*/
      /*@assert re_bwd_2(x142,0,x146);*/
      char  *x251 = x147;
      x347 = 0/*false*/;
    } else {
      int x254 = x238 == 1;
      int x345;
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
        x345 = x308;
      } else {
        int x310 = x238 == 0;
        int x343;
        if (x310) {
          /*@assert ((x145==0) ==> re_bwd_0(x142,0,x146));*/
          /*@assert re_bwd_0(x142,0,x146);*/
          char  *x322 = x147;
          char x323 = x322[0];
          int x324 = 'A' == x323;
          int x341;
          if (x324) {
            /*@assert re_bwd_0(x142,0,x146);*/
            x145 = 1;
            /*@assert star_A(x142,(x146+1),(x146+1));*/
            /*@assert re_bwd_1(x142,0,(x146+1));*/
            x341 = 1/*true*/;
          } else {
            x341 = 0/*false*/;
          }
          x343 = x341;
        } else {
          x343 = 0/*false*/;
        }
        x345 = x343;
      }
      x347 = x345;
    }
    x144 = x347;
    char  *x349 = x147;
    char  *x350 = x349+1;
    x147 = x350;
    /*@ghost x146 = (x146+1);*/
  }
  char  *x396 = x147;
  char x397 = x396[0];
  int x398 = x397 == '\0';
  int x401;
  if (x398) {
    int x399 = x144;
    x401 = x399;
  } else {
    x401 = 0/*false*/;
  }
  int x405;
  if (x401) {
    int x402 = x145;
    int x403 = x402 == 2;
    x405 = x403;
  } else {
    x405 = 0/*false*/;
  }
  return x405;
}
/*@
requires ((((strlen(x413)>=0) &&
\valid(x413+(0..strlen(x413)))) &&
(((0<=x414) &&
(x414<=x415)) &&
(x415<=strlen(x413)))) &&
star_A(x413,x414,x415));
assigns \nothing;
ensures (\forall int  x469; ((((0<=x414) &&
(x414<=x469)) &&
(x469<x415)) ==> (('A'==x413[x469]) &&
((x469+1)==(x469+1)))));
*/
void lemma_star_A_all(char  * x413, int  x414, int  x415) {
  int x417 = x414;
  /*@
  loop invariant (((0<=x414) &&
  (x414<=x417)) &&
  (x415<=strlen(x413)));
  loop invariant star_A(x413,x417,x415);
  loop invariant (\forall int  x424; (((x414<=x424) &&
  (x424<x417)) ==> ((x413+x424)[0]=='A')));
  loop assigns x417;
  loop variant (x415-x417);
  */
  for (;;) {
    int x418 = x417;
    int x419 = x418 < x415;
    if (!x419) break;
    int x436 = x417;
    int x437 = x436 + 1;
    x417 = x437;
  }
}
/*@
requires ((((strlen(x481)>=0) &&
\valid(x481+(0..strlen(x481)))) &&
(((0<=x482) &&
(x482<=x483)) &&
(x483<=strlen(x481)))) &&
(\forall int  x533; ((((0<=x482) &&
(x482<=x533)) &&
(x533<x483)) ==> (('A'==x481[x533]) &&
((x533+1)==(x533+1))))));
assigns \nothing;
ensures star_A(x481,x482,x483);
*/
void lemma_star_A_from_all(char  * x481, int  x482, int  x483) {
  int x485 = x483;
  /*@
  loop invariant (((0<=x482) &&
  (x482<=x485)) &&
  (x483<=strlen(x481)));
  loop invariant star_A(x481,x485,x483);
  loop invariant (\forall int  x492; ((((0<=x482) &&
  (x482<=x492)) &&
  (x492<x483)) ==> (('A'==x481[x492]) &&
  ((x492+1)==(x492+1)))));
  loop assigns x485;
  loop variant x485;
  */
  for (;;) {
    int x486 = x485;
    int x487 = x482 < x486;
    if (!x487) break;
    int x505 = x485;
    int x506 = x505 - 1;
    x485 = x506;
  }
}
/*@
requires (((((strlen(x548)>=0) &&
\valid(x548+(0..strlen(x548)))) &&
((0<=x549) &&
(x549<=x550))) &&
((x549<x550) &&
(x550<=strlen(x548)))) &&
star_A(x548,x549,x550));
assigns \nothing;
ensures star_A(x548,x549,(x550-1));
*/
void lemma_star_A_dec(char  * x548, int  x549, int  x550) {
  /*@ghost lemma_star_A_all(x548,x549,x550);*/
  /*@ghost lemma_star_A_from_all(x548,x549,(x550-1));*/
}
/*@
requires ((((((((strlen(x579)>=0) &&
\valid(x579+(0..strlen(x579)))) &&
((0<=x580) &&
(x580<=x581))) &&
((0<=x581) &&
(x581<x582))) &&
((0<=x582) &&
(x582<=strlen(x579)))) &&
star_A(x579,x580,x581)) &&
star_A(x579,x581,x582)) &&
((x581+1)==x582));
assigns \nothing;
ensures star_A(x579,x580,x582);
*/
void lemma_star_A(char  * x579, int  x580, int  x581, int  x582) {
  int x584 = x581;
  /*@
  loop invariant ((((0<=x580) &&
  (x580<=x584)) &&
  (x584<=x582)) &&
  (x582<=strlen(x579)));
  loop invariant star_A(x579,x584,x582);
  loop invariant star_A(x579,x580,x584);
  loop assigns x584;
  loop variant x584;
  */
  for (;;) {
    int x585 = x584;
    int x586 = x580 < x585;
    if (!x586) break;
    int x594 = x584;
    lemma_star_A_dec(x579,x580,x594);
    /*@assert (x580<x584);*/
    /*@ghost lemma_star_A_all(x579,x580,x584);*/
    /*@assert (('A'==x579[(x584-1)]) &&
    (x584==((x584-1)+1)));*/
    /*@assert star_A(x579,x584,x582);*/
    /*@assert star_A(x579,(x584-1),x582);*/
    int x622 = x594 - 1;
    x584 = x622;
  }
}
