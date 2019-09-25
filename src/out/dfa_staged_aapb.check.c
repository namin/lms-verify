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
  //@ ghost int x149 = -1;
  int x150 = x149;
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
  loop invariant ((-1<=x149) &&
  (x149<=x146));
  loop invariant ((x149>=0) ==> (x145==1));
  loop invariant ((x145==1) ==> (x149>=0));
  loop invariant ((x149==-1) ==> (x145!=1));
  loop invariant ((x145!=1) ==> (x149==-1));
  loop invariant (\forall int  x271; (((x149>=0) &&
  (x149<=x271)) ==> ((re_bwd_1(x142,0,x149) &&
  star_A(x142,x149,x271)) ==> re_bwd_1(x142,0,x271))));
  loop invariant (\forall int  x285; ((((x149>=0) &&
  (x149<=x285)) &&
  re_bwd_1(x142,0,x285)) ==> (re_bwd_1(x142,0,x149) &&
  star_A(x142,x149,x285))));
  loop invariant (((x149>=0) &&
  x144) ==> star_A(x142,x149,x146));
  loop assigns x147, x146, x145, x144, x149;
  loop variant strlen(x147);
  */
  for (;;) {
    char  *x151 = x147;
    char x152 = x151[0];
    int x153 = x152 == '\0';
    int x157;
    if (x153) {
      x157 = 0/*false*/;
    } else {
      int x155 = x144;
      x157 = x155;
    }
    if (!x157) break;
    int x309 = x145;
    int x310 = x309 == 2;
    int x433;
    if (x310) {
      /*@assert ((x145==2) ==> re_bwd_2(x142,0,x146));*/
      /*@assert re_bwd_2(x142,0,x146);*/
      char  *x322 = x147;
      x433 = 0/*false*/;
    } else {
      int x325 = x309 == 1;
      int x431;
      if (x325) {
        /*@assert ((x145==1) ==> re_bwd_1(x142,0,x146));*/
        /*@assert re_bwd_1(x142,0,x146);*/
        char  *x337 = x147;
        char x338 = x337[0];
        int x339 = 'B' == x338;
        int x389;
        if (x339) {
          /*@assert re_bwd_1(x142,0,x146);*/
          x145 = 2;
          /*@ghost x149 = -1;*/
          /*@assert re_bwd_2(x142,0,(x146+1));*/
          /*@assert (((x142+(x146+1))[0]=='\0') ==> re_0(x142,0,(x146+1)));*/
          x389 = 1/*true*/;
        } else {
          int x363 = 'A' == x338;
          int x387;
          if (x363) {
            /*@assert re_bwd_1(x142,0,x146);*/
            x145 = 1;
            /*@ghost lemma_star_A(x142,x149,x146,(x146+1));*/
            /*@assert star_A(x142,x149,(x146+1));*/
            /*@assert re_bwd_1(x142,0,(x146+1));*/
            x387 = 1/*true*/;
          } else {
            x387 = 0/*false*/;
          }
          x389 = x387;
        }
        x431 = x389;
      } else {
        int x391 = x309 == 0;
        int x429;
        if (x391) {
          /*@assert ((x145==0) ==> re_bwd_0(x142,0,x146));*/
          /*@assert re_bwd_0(x142,0,x146);*/
          char  *x403 = x147;
          char x404 = x403[0];
          int x405 = 'A' == x404;
          int x427;
          if (x405) {
            /*@assert re_bwd_0(x142,0,x146);*/
            x145 = 1;
            /*@ghost x149 = (x146+1);*/
            /*@assert star_A(x142,(x146+1),(x146+1));*/
            /*@assert re_bwd_1(x142,0,(x146+1));*/
            x427 = 1/*true*/;
          } else {
            x427 = 0/*false*/;
          }
          x429 = x427;
        } else {
          x429 = 0/*false*/;
        }
        x431 = x429;
      }
      x433 = x431;
    }
    x144 = x433;
    char  *x435 = x147;
    char  *x436 = x435+1;
    x147 = x436;
    /*@ghost x146 = (x146+1);*/
  }
  char  *x482 = x147;
  char x483 = x482[0];
  int x484 = x483 == '\0';
  int x487;
  if (x484) {
    int x485 = x144;
    x487 = x485;
  } else {
    x487 = 0/*false*/;
  }
  int x491;
  if (x487) {
    int x488 = x145;
    int x489 = x488 == 2;
    x491 = x489;
  } else {
    x491 = 0/*false*/;
  }
  return x491;
}
/*@
requires ((((strlen(x499)>=0) &&
\valid(x499+(0..strlen(x499)))) &&
(((0<=x500) &&
(x500<=x501)) &&
(x501<=strlen(x499)))) &&
star_A(x499,x500,x501));
assigns \nothing;
ensures (\forall int  x555; ((((0<=x500) &&
(x500<=x555)) &&
(x555<x501)) ==> (('A'==x499[x555]) &&
((x555+1)==(x555+1)))));
*/
void lemma_star_A_all(char  * x499, int  x500, int  x501) {
  int x503 = x500;
  /*@
  loop invariant (((0<=x500) &&
  (x500<=x503)) &&
  (x501<=strlen(x499)));
  loop invariant star_A(x499,x503,x501);
  loop invariant (\forall int  x510; (((x500<=x510) &&
  (x510<x503)) ==> ((x499+x510)[0]=='A')));
  loop assigns x503;
  loop variant (x501-x503);
  */
  for (;;) {
    int x504 = x503;
    int x505 = x504 < x501;
    if (!x505) break;
    int x522 = x503;
    int x523 = x522 + 1;
    x503 = x523;
  }
}
/*@
requires ((((strlen(x567)>=0) &&
\valid(x567+(0..strlen(x567)))) &&
(((0<=x568) &&
(x568<=x569)) &&
(x569<=strlen(x567)))) &&
(\forall int  x619; ((((0<=x568) &&
(x568<=x619)) &&
(x619<x569)) ==> (('A'==x567[x619]) &&
((x619+1)==(x619+1))))));
assigns \nothing;
ensures star_A(x567,x568,x569);
*/
void lemma_star_A_from_all(char  * x567, int  x568, int  x569) {
  int x571 = x569;
  /*@
  loop invariant (((0<=x568) &&
  (x568<=x571)) &&
  (x569<=strlen(x567)));
  loop invariant star_A(x567,x571,x569);
  loop invariant (\forall int  x578; ((((0<=x568) &&
  (x568<=x578)) &&
  (x578<x569)) ==> (('A'==x567[x578]) &&
  ((x578+1)==(x578+1)))));
  loop assigns x571;
  loop variant x571;
  */
  for (;;) {
    int x572 = x571;
    int x573 = x568 < x572;
    if (!x573) break;
    int x591 = x571;
    int x592 = x591 - 1;
    x571 = x592;
  }
}
/*@
requires (((((strlen(x634)>=0) &&
\valid(x634+(0..strlen(x634)))) &&
((0<=x635) &&
(x635<=x636))) &&
((x635<x636) &&
(x636<=strlen(x634)))) &&
star_A(x634,x635,x636));
assigns \nothing;
ensures star_A(x634,x635,(x636-1));
*/
void lemma_star_A_dec(char  * x634, int  x635, int  x636) {
  /*@ghost lemma_star_A_all(x634,x635,x636);*/
  /*@ghost lemma_star_A_from_all(x634,x635,(x636-1));*/
}
/*@
requires ((((((((strlen(x665)>=0) &&
\valid(x665+(0..strlen(x665)))) &&
((0<=x666) &&
(x666<=x667))) &&
((0<=x667) &&
(x667<x668))) &&
((0<=x668) &&
(x668<=strlen(x665)))) &&
star_A(x665,x666,x667)) &&
star_A(x665,x667,x668)) &&
((x667+1)==x668));
assigns \nothing;
ensures star_A(x665,x666,x668);
*/
void lemma_star_A(char  * x665, int  x666, int  x667, int  x668) {
  int x670 = x667;
  /*@
  loop invariant ((((0<=x666) &&
  (x666<=x670)) &&
  (x670<=x668)) &&
  (x668<=strlen(x665)));
  loop invariant star_A(x665,x670,x668);
  loop invariant star_A(x665,x666,x670);
  loop assigns x670;
  loop variant x670;
  */
  for (;;) {
    int x671 = x670;
    int x672 = x666 < x671;
    if (!x672) break;
    int x680 = x670;
    lemma_star_A_dec(x665,x666,x680);
    /*@assert (x666<x670);*/
    /*@ghost lemma_star_A_all(x665,x666,x670);*/
    /*@assert (('A'==x665[(x670-1)]) &&
    (x670==((x670-1)+1)));*/
    /*@assert star_A(x665,x670,x668);*/
    /*@assert star_A(x665,(x670-1),x668);*/
    int x708 = x680 - 1;
    x670 = x708;
  }
}
