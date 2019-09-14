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
    int x345;
    if (x239) {
      /*@assert ((x145==2) ==> re_bwd_2(x142,0,x146));*/
      /*@assert re_bwd_2(x142,0,x146);*/
      char  *x251 = x147;
      x345 = 0/*false*/;
    } else {
      int x254 = x238 == 1;
      int x343;
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
        x343 = x308;
      } else {
        int x310 = x238 == 0;
        int x341;
        if (x310) {
          /*@assert ((x145==0) ==> re_bwd_0(x142,0,x146));*/
          /*@assert re_bwd_0(x142,0,x146);*/
          char  *x322 = x147;
          char x323 = x322[0];
          int x324 = 'A' == x323;
          int x339;
          if (x324) {
            /*@assert re_bwd_0(x142,0,x146);*/
            x145 = 1;
            /*@assert star_A(x142,1,1);*/
            /*@assert re_bwd_1(x142,0,(x146+1));*/
            x339 = 1/*true*/;
          } else {
            x339 = 0/*false*/;
          }
          x341 = x339;
        } else {
          x341 = 0/*false*/;
        }
        x343 = x341;
      }
      x345 = x343;
    }
    x144 = x345;
    char  *x347 = x147;
    char  *x348 = x347+1;
    x147 = x348;
    /*@ghost x146 = (x146+1);*/
  }
  char  *x394 = x147;
  char x395 = x394[0];
  int x396 = x395 == '\0';
  int x399;
  if (x396) {
    int x397 = x144;
    x399 = x397;
  } else {
    x399 = 0/*false*/;
  }
  int x403;
  if (x399) {
    int x400 = x145;
    int x401 = x400 == 2;
    x403 = x401;
  } else {
    x403 = 0/*false*/;
  }
  return x403;
}
/*@
requires ((((strlen(x411)>=0) &&
\valid(x411+(0..strlen(x411)))) &&
(((0<=x412) &&
(x412<=x413)) &&
(x413<=strlen(x411)))) &&
star_A(x411,x412,x413));
assigns \nothing;
ensures (\forall int  x467; ((((0<=x412) &&
(x412<=x467)) &&
(x467<x413)) ==> (('A'==x411[x467]) &&
((x467+1)==(x467+1)))));
*/
void lemma_star_A_all(char  * x411, int  x412, int  x413) {
  int x415 = x412;
  /*@
  loop invariant (((0<=x412) &&
  (x412<=x415)) &&
  (x413<=strlen(x411)));
  loop invariant star_A(x411,x415,x413);
  loop invariant (\forall int  x422; (((x412<=x422) &&
  (x422<x415)) ==> ((x411+x422)[0]=='A')));
  loop assigns x415;
  loop variant (x413-x415);
  */
  for (;;) {
    int x416 = x415;
    int x417 = x416 < x413;
    if (!x417) break;
    int x434 = x415;
    int x435 = x434 + 1;
    x415 = x435;
  }
}
/*@
requires ((((strlen(x479)>=0) &&
\valid(x479+(0..strlen(x479)))) &&
(((0<=x480) &&
(x480<=x481)) &&
(x481<=strlen(x479)))) &&
(\forall int  x531; ((((0<=x480) &&
(x480<=x531)) &&
(x531<x481)) ==> (('A'==x479[x531]) &&
((x531+1)==(x531+1))))));
assigns \nothing;
ensures star_A(x479,x480,x481);
*/
void lemma_star_A_from_all(char  * x479, int  x480, int  x481) {
  int x483 = x481;
  /*@
  loop invariant (((0<=x480) &&
  (x480<=x483)) &&
  (x481<=strlen(x479)));
  loop invariant star_A(x479,x483,x481);
  loop invariant (\forall int  x490; ((((0<=x480) &&
  (x480<=x490)) &&
  (x490<x481)) ==> (('A'==x479[x490]) &&
  ((x490+1)==(x490+1)))));
  loop assigns x483;
  loop variant x483;
  */
  for (;;) {
    int x484 = x483;
    int x485 = x480 < x484;
    if (!x485) break;
    int x503 = x483;
    int x504 = x503 - 1;
    x483 = x504;
  }
}
/*@
requires (((((strlen(x546)>=0) &&
\valid(x546+(0..strlen(x546)))) &&
((0<=x547) &&
(x547<=x548))) &&
((x547<x548) &&
(x548<=strlen(x546)))) &&
star_A(x546,x547,x548));
assigns \nothing;
ensures star_A(x546,x547,(x548-1));
*/
void lemma_star_A_dec(char  * x546, int  x547, int  x548) {
  /*@ghost lemma_star_A_all(x546,x547,x548);*/
  /*@ghost lemma_star_A_from_all(x546,x547,(x548-1));*/
}
/*@
requires ((((((((strlen(x577)>=0) &&
\valid(x577+(0..strlen(x577)))) &&
((0<=x578) &&
(x578<=x579))) &&
((0<=x579) &&
(x579<x580))) &&
((0<=x580) &&
(x580<=strlen(x577)))) &&
star_A(x577,x578,x579)) &&
star_A(x577,x579,x580)) &&
((x579+1)==x580));
assigns \nothing;
ensures star_A(x577,x578,x580);
*/
void lemma_star_A(char  * x577, int  x578, int  x579, int  x580) {
  int x582 = x579;
  /*@
  loop invariant ((((0<=x578) &&
  (x578<=x582)) &&
  (x582<=x580)) &&
  (x580<=strlen(x577)));
  loop invariant star_A(x577,x582,x580);
  loop invariant star_A(x577,x578,x582);
  loop assigns x582;
  loop variant x582;
  */
  for (;;) {
    int x583 = x582;
    int x584 = x578 < x583;
    if (!x584) break;
    int x592 = x582;
    lemma_star_A_dec(x577,x578,x592);
    /*@assert (x578<x582);*/
    /*@ghost lemma_star_A_all(x577,x578,x582);*/
    /*@assert (('A'==x577[(x582-1)]) &&
    (x582==((x582-1)+1)));*/
    /*@assert star_A(x577,x582,x580);*/
    /*@assert star_A(x577,(x582-1),x580);*/
    int x620 = x592 - 1;
    x582 = x620;
  }
}
