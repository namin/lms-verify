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
requires \false;
assigns \nothing;
ensures re_bwd_0(x142,x143,(x145+1));
*/
void lemma_sanity_0_0(char  * x142, int  x143, int  x144, int  x145) {
}
/*@
requires ((((((((strlen(x167)>=0) &&
\valid(x167+(0..strlen(x167)))) &&
(strlen(x167)<=INT_MAX)) &&
((((0<=x168) &&
(x168<=x169)) &&
(x169<=x170)) &&
(x170<strlen(x167)))) &&
(x167[x170]=='A')) &&
re_bwd_0(x167,x168,x170)) &&
star_A(x167,(x170+1),(x170+1))) &&
re_bwd_0(x167,x168,x169));
assigns \nothing;
ensures re_bwd_1(x167,x168,(x170+1));
*/
void lemma_sanity_0_1(char  * x167, int  x168, int  x169, int  x170) {
  /*@assert re_bwd_0(x167,x168,x170);*/
  /*@assert (x167[x170]=='A');*/
  /*@assert star_A(x167,(x170+1),(x170+1));*/
  /*@assert re_bwd_0(x167,x168,x169);*/
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_2(x208,x209,(x211+1));
*/
void lemma_sanity_0_2(char  * x208, int  x209, int  x210, int  x211) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_0(x233,x234,(x236+1));
*/
void lemma_sanity_1_0(char  * x233, int  x234, int  x235, int  x236) {
}
/*@
requires (((((((((strlen(x258)>=0) &&
\valid(x258+(0..strlen(x258)))) &&
(strlen(x258)<=INT_MAX)) &&
((((0<=x259) &&
(x259<=x260)) &&
(x260<=x261)) &&
(x261<strlen(x258)))) &&
(x258[x261]=='A')) &&
star_A(x258,x260,x261)) &&
(\forall int  x314; ((x260<=x314) ==> ((re_bwd_1(x258,x259,x260) &&
star_A(x258,x260,x314)) ==> re_bwd_1(x258,x259,x314))))) &&
re_bwd_1(x258,x259,x260)) &&
re_bwd_1(x258,x259,x261));
assigns \nothing;
ensures (re_bwd_1(x258,x259,(x261+1)) &&
star_A(x258,x260,(x261+1)));
*/
void lemma_sanity_1_1(char  * x258, int  x259, int  x260, int  x261) {
  /*@ghost lemma_star_A(x258,x260,x261,(x261+1));*/
  /*@assert (\forall int  x267; ((x260<=x267) ==> ((re_bwd_1(x258,x259,x260) &&
  star_A(x258,x260,x267)) ==> re_bwd_1(x258,x259,x267))));*/
  /*@assert ((x260<=(x261+1)) ==> ((re_bwd_1(x258,x259,x260) &&
  star_A(x258,x260,(x261+1))) ==> re_bwd_1(x258,x259,(x261+1))));*/
  /*@assert re_bwd_1(x258,x259,x260);*/
}
/*@
requires ((((((strlen(x335)>=0) &&
\valid(x335+(0..strlen(x335)))) &&
(strlen(x335)<=INT_MAX)) &&
((((0<=x336) &&
(x336<=x337)) &&
(x337<=x338)) &&
(x338<strlen(x335)))) &&
(x335[x338]=='B')) &&
re_bwd_1(x335,x336,x338));
assigns \nothing;
ensures re_bwd_2(x335,x336,(x338+1));
*/
void lemma_sanity_1_2(char  * x335, int  x336, int  x337, int  x338) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_0(x365,x366,(x368+1));
*/
void lemma_sanity_2_0(char  * x365, int  x366, int  x367, int  x368) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_1(x390,x391,(x393+1));
*/
void lemma_sanity_2_1(char  * x390, int  x391, int  x392, int  x393) {
  /*@assert re_bwd_2(x390,x391,x393);*/
  /*@assert \false;*/
  /*@assert star_A(x390,(x393+1),(x393+1));*/
  /*@assert re_bwd_2(x390,x391,x392);*/
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_2(x429,x430,(x432+1));
*/
void lemma_sanity_2_2(char  * x429, int  x430, int  x431, int  x432) {
}
/*@
requires (((strlen(x455)>=0) &&
\valid(x455+(0..strlen(x455)))) &&
(strlen(x455)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x455,0,strlen(x455)));
*/
int dfa(char  * x455) {
  int x457 = 1/*true*/;
  int x458 = 0;
  //@ ghost int x459 = 0;
  char  *x460 = x455;
  //@ ghost int x462 = -1;
  int x463 = x462;
  /*@
  loop invariant (((((strlen(x455)>=0) &&
  \valid(x455+(0..strlen(x455)))) &&
  ((0<=x459) &&
  (x459<=strlen(x455)))) &&
  (x460==(x455+x459))) &&
  ((strlen((x455+x459))>=0) &&
  \valid((x455+x459)+(0..strlen((x455+x459))))));
  loop invariant (((x458==0) &&
  x457) ==> re_bwd_0(x455,0,x459));
  loop invariant (((x458==1) &&
  x457) ==> re_bwd_1(x455,0,x459));
  loop invariant (((x458==2) &&
  x457) ==> re_bwd_2(x455,0,x459));
  loop invariant (((x458==0) &&
  (!x457)) ==> re_bwd_0(x455,0,(x459-1)));
  loop invariant (((x458==1) &&
  (!x457)) ==> re_bwd_1(x455,0,(x459-1)));
  loop invariant (((x458==2) &&
  (!x457)) ==> re_bwd_2(x455,0,(x459-1)));
  loop invariant ((((x458==2) &&
  (x460[0]=='\0')) &&
  x457) ==> re_0(x455,0,x459));
  loop invariant ((x458==2) || ((x458==1) || (x458==0)));
  loop invariant ((-1<=x462) &&
  (x462<=x459));
  loop invariant ((x462>=0) ==> (x458==1));
  loop invariant ((x458==1) ==> (x462>=0));
  loop invariant ((x462==-1) ==> (x458!=1));
  loop invariant ((x458!=1) ==> (x462==-1));
  loop invariant (\forall int  x584; (((x462>=0) &&
  (x462<=x584)) ==> ((re_bwd_1(x455,0,x462) &&
  star_A(x455,x462,x584)) ==> re_bwd_1(x455,0,x584))));
  loop invariant ((x462>=0) ==> re_bwd_1(x455,0,x462));
  loop invariant (((x462>=0) &&
  x457) ==> star_A(x455,x462,x459));
  loop assigns x460, x459, x458, x457, x462;
  loop variant strlen(x460);
  */
  for (;;) {
    char  *x464 = x460;
    char x465 = x464[0];
    int x466 = x465 == '\0';
    int x470;
    if (x466) {
      x470 = 0/*false*/;
    } else {
      int x468 = x457;
      x470 = x468;
    }
    if (!x470) break;
    int x612 = x458;
    int x613 = x612 == 2;
    int x754;
    if (x613) {
      /*@assert ((x458==2) ==> re_bwd_2(x455,0,x459));*/
      /*@assert re_bwd_2(x455,0,x459);*/
      char  *x625 = x460;
      x754 = 0/*false*/;
    } else {
      int x628 = x612 == 1;
      int x752;
      if (x628) {
        /*@assert ((x458==1) ==> re_bwd_1(x455,0,x459));*/
        /*@assert re_bwd_1(x455,0,x459);*/
        char  *x640 = x460;
        char x641 = x640[0];
        int x642 = 'B' == x641;
        int x706;
        if (x642) {
          /*@assert re_bwd_1(x455,0,x459);*/
          x458 = 2;
          /*@ghost lemma_sanity_1_2(x455,0,x462,x459);*/
          /*@ghost x462 = -1;*/
          /*@assert re_bwd_2(x455,0,(x459+1));*/
          /*@assert (((x455+(x459+1))[0]=='\0') ==> re_0(x455,0,(x459+1)));*/
          x706 = 1/*true*/;
        } else {
          int x671 = 'A' == x641;
          int x704;
          if (x671) {
            /*@assert re_bwd_1(x455,0,x459);*/
            x458 = 1;
            /*@assert (x462>=0);*/
            /*@ghost lemma_star_A(x455,x462,x459,(x459+1));*/
            /*@assert star_A(x455,x462,(x459+1));*/
            /*@ghost lemma_sanity_1_1(x455,0,x462,x459);*/
            /*@assert re_bwd_1(x455,0,(x459+1));*/
            x704 = 1/*true*/;
          } else {
            x704 = 0/*false*/;
          }
          x706 = x704;
        }
        x752 = x706;
      } else {
        int x708 = x612 == 0;
        int x750;
        if (x708) {
          /*@assert ((x458==0) ==> re_bwd_0(x455,0,x459));*/
          /*@assert re_bwd_0(x455,0,x459);*/
          char  *x720 = x460;
          char x721 = x720[0];
          int x722 = 'A' == x721;
          int x748;
          if (x722) {
            /*@assert re_bwd_0(x455,0,x459);*/
            x458 = 1;
            /*@ghost x462 = (x459+1);*/
            /*@assert star_A(x455,(x459+1),(x459+1));*/
            /*@ghost lemma_sanity_0_1(x455,0,0,x459);*/
            /*@assert re_bwd_1(x455,0,(x459+1));*/
            x748 = 1/*true*/;
          } else {
            x748 = 0/*false*/;
          }
          x750 = x748;
        } else {
          x750 = 0/*false*/;
        }
        x752 = x750;
      }
      x754 = x752;
    }
    x457 = x754;
    char  *x756 = x460;
    char  *x757 = x756+1;
    x460 = x757;
    /*@ghost x459 = (x459+1);*/
  }
  char  *x803 = x460;
  char x804 = x803[0];
  int x805 = x804 == '\0';
  int x808;
  if (x805) {
    int x806 = x457;
    x808 = x806;
  } else {
    x808 = 0/*false*/;
  }
  int x812;
  if (x808) {
    int x809 = x458;
    int x810 = x809 == 2;
    x812 = x810;
  } else {
    x812 = 0/*false*/;
  }
  return x812;
}
/*@
requires ((((strlen(x819)>=0) &&
\valid(x819+(0..strlen(x819)))) &&
(((0<=x820) &&
(x820<=x821)) &&
(x821<=strlen(x819)))) &&
star_A(x819,x820,x821));
assigns \nothing;
ensures (\forall int  x875; ((((0<=x820) &&
(x820<=x875)) &&
(x875<x821)) ==> (('A'==x819[x875]) &&
((x875+1)==(x875+1)))));
*/
void lemma_star_A_all(char  * x819, int  x820, int  x821) {
  int x823 = x820;
  /*@
  loop invariant (((0<=x820) &&
  (x820<=x823)) &&
  (x821<=strlen(x819)));
  loop invariant star_A(x819,x823,x821);
  loop invariant (\forall int  x830; (((x820<=x830) &&
  (x830<x823)) ==> ((x819+x830)[0]=='A')));
  loop assigns x823;
  loop variant (x821-x823);
  */
  for (;;) {
    int x824 = x823;
    int x825 = x824 < x821;
    if (!x825) break;
    int x842 = x823;
    int x843 = x842 + 1;
    x823 = x843;
  }
}
/*@
requires ((((strlen(x887)>=0) &&
\valid(x887+(0..strlen(x887)))) &&
(((0<=x888) &&
(x888<=x889)) &&
(x889<=strlen(x887)))) &&
(\forall int  x939; ((((0<=x888) &&
(x888<=x939)) &&
(x939<x889)) ==> (('A'==x887[x939]) &&
((x939+1)==(x939+1))))));
assigns \nothing;
ensures star_A(x887,x888,x889);
*/
void lemma_star_A_from_all(char  * x887, int  x888, int  x889) {
  int x891 = x889;
  /*@
  loop invariant (((0<=x888) &&
  (x888<=x891)) &&
  (x889<=strlen(x887)));
  loop invariant star_A(x887,x891,x889);
  loop invariant (\forall int  x898; ((((0<=x888) &&
  (x888<=x898)) &&
  (x898<x889)) ==> (('A'==x887[x898]) &&
  ((x898+1)==(x898+1)))));
  loop assigns x891;
  loop variant x891;
  */
  for (;;) {
    int x892 = x891;
    int x893 = x888 < x892;
    if (!x893) break;
    int x911 = x891;
    int x912 = x911 - 1;
    x891 = x912;
  }
}
/*@
requires (((((strlen(x954)>=0) &&
\valid(x954+(0..strlen(x954)))) &&
((0<=x955) &&
(x955<=x956))) &&
((x955<x956) &&
(x956<=strlen(x954)))) &&
star_A(x954,x955,x956));
assigns \nothing;
ensures star_A(x954,x955,(x956-1));
*/
void lemma_star_A_dec(char  * x954, int  x955, int  x956) {
  /*@ghost lemma_star_A_all(x954,x955,x956);*/
  /*@ghost lemma_star_A_from_all(x954,x955,(x956-1));*/
}
/*@
requires ((((((((strlen(x985)>=0) &&
\valid(x985+(0..strlen(x985)))) &&
((0<=x986) &&
(x986<=x987))) &&
((0<=x987) &&
(x987<x988))) &&
((0<=x988) &&
(x988<=strlen(x985)))) &&
star_A(x985,x986,x987)) &&
star_A(x985,x987,x988)) &&
((x987+1)==x988));
assigns \nothing;
ensures star_A(x985,x986,x988);
*/
void lemma_star_A(char  * x985, int  x986, int  x987, int  x988) {
  int x990 = x987;
  /*@
  loop invariant ((((0<=x986) &&
  (x986<=x990)) &&
  (x990<=x988)) &&
  (x988<=strlen(x985)));
  loop invariant star_A(x985,x990,x988);
  loop invariant star_A(x985,x986,x990);
  loop assigns x990;
  loop variant x990;
  */
  for (;;) {
    int x991 = x990;
    int x992 = x986 < x991;
    if (!x992) break;
    int x1000 = x990;
    lemma_star_A_dec(x985,x986,x1000);
    /*@assert (x986<x990);*/
    /*@ghost lemma_star_A_all(x985,x986,x990);*/
    /*@assert (('A'==x985[(x990-1)]) &&
    (x990==((x990-1)+1)));*/
    /*@assert star_A(x985,x990,x988);*/
    /*@assert star_A(x985,(x990-1),x988);*/
    int x1028 = x1000 - 1;
    x990 = x1028;
  }
}
