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
(x2==x2))));*/
/*@ predicate re_1(char  * x64, integer  x65, integer  x66) = (((x65<=(x66-1)) &&
star_A(x64,x65,(x66-1))) &&
((((x66-1)<=x66) &&
(('B'==x64[(x66-1)]) &&
(x66==((x66-1)+1)))) &&
(x66==x66)));*/
/*@ predicate re_2(char  * x84, integer  x85, integer  x86) = (x85==x86);*/
/*@ predicate re_bwd_0(char  * x89, integer  x90, integer  x91) = (x90==x91);*/
/*@ predicate re_bwd_1(char  * x94, integer  x95, integer  x96) = (((('A'==x94[x95]) &&
((x95+1)==(x95+1))) &&
((x95+1)<=x96)) &&
((((x95+1)<=x96) &&
star_A(x94,(x95+1),x96)) &&
(x96==x96)));*/
/*@ predicate re_bwd_2(char  * x113, integer  x114, integer  x115) = (((('A'==x113[x114]) &&
((x114+1)==(x114+1))) &&
((x114+1)<=x115)) &&
((((x114+1)<=(x115-1)) &&
star_A(x113,(x114+1),(x115-1))) &&
((((x115-1)<=x115) &&
(('B'==x113[(x115-1)]) &&
(x115==((x115-1)+1)))) &&
(x115==x115))));*/
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
  loop invariant (x457 ==> (re_bwd_2(x455,0,x459) || (re_bwd_1(x455,0,x459) || re_bwd_0(x455,0,x459))));
  loop invariant ((x460[0]=='\0') ==> (strlen(x455)==x459));
  loop invariant ((!(x460[0]=='\0')) ==> (strlen(x455)!=x459));
  loop invariant ((x458==2) || ((x458==1) || (x458==0)));
  loop invariant ((-1<=x462) &&
  (x462<=x459));
  loop invariant ((x462>=0) ==> (x458==1));
  loop invariant ((x458==1) ==> (x462>=0));
  loop invariant ((x462==-1) ==> (x458!=1));
  loop invariant ((x458!=1) ==> (x462==-1));
  loop invariant (\forall int  x608; (((x462>=0) &&
  (x462<=x608)) ==> ((re_bwd_1(x455,0,x462) &&
  star_A(x455,x462,x608)) ==> re_bwd_1(x455,0,x608))));
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
    int x636 = x458;
    int x637 = x636 == 2;
    int x778;
    if (x637) {
      /*@assert ((x458==2) ==> re_bwd_2(x455,0,x459));*/
      /*@assert re_bwd_2(x455,0,x459);*/
      char  *x649 = x460;
      x778 = 0/*false*/;
    } else {
      int x652 = x636 == 1;
      int x776;
      if (x652) {
        /*@assert ((x458==1) ==> re_bwd_1(x455,0,x459));*/
        /*@assert re_bwd_1(x455,0,x459);*/
        char  *x664 = x460;
        char x665 = x664[0];
        int x666 = 'B' == x665;
        int x730;
        if (x666) {
          /*@assert re_bwd_1(x455,0,x459);*/
          x458 = 2;
          /*@ghost lemma_sanity_1_2(x455,0,x462,x459);*/
          /*@ghost x462 = -1;*/
          /*@assert re_bwd_2(x455,0,(x459+1));*/
          /*@assert (((x455+(x459+1))[0]=='\0') ==> re_0(x455,0,(x459+1)));*/
          x730 = 1/*true*/;
        } else {
          int x695 = 'A' == x665;
          int x728;
          if (x695) {
            /*@assert re_bwd_1(x455,0,x459);*/
            x458 = 1;
            /*@assert (x462>=0);*/
            /*@ghost lemma_star_A(x455,x462,x459,(x459+1));*/
            /*@assert star_A(x455,x462,(x459+1));*/
            /*@ghost lemma_sanity_1_1(x455,0,x462,x459);*/
            /*@assert re_bwd_1(x455,0,(x459+1));*/
            x728 = 1/*true*/;
          } else {
            x728 = 0/*false*/;
          }
          x730 = x728;
        }
        x776 = x730;
      } else {
        int x732 = x636 == 0;
        int x774;
        if (x732) {
          /*@assert ((x458==0) ==> re_bwd_0(x455,0,x459));*/
          /*@assert re_bwd_0(x455,0,x459);*/
          char  *x744 = x460;
          char x745 = x744[0];
          int x746 = 'A' == x745;
          int x772;
          if (x746) {
            /*@assert re_bwd_0(x455,0,x459);*/
            x458 = 1;
            /*@ghost x462 = (x459+1);*/
            /*@assert star_A(x455,(x459+1),(x459+1));*/
            /*@ghost lemma_sanity_0_1(x455,0,0,x459);*/
            /*@assert re_bwd_1(x455,0,(x459+1));*/
            x772 = 1/*true*/;
          } else {
            x772 = 0/*false*/;
          }
          x774 = x772;
        } else {
          x774 = 0/*false*/;
        }
        x776 = x774;
      }
      x778 = x776;
    }
    x457 = x778;
    char  *x780 = x460;
    char  *x781 = x780+1;
    x460 = x781;
    /*@ghost x459 = (x459+1);*/
  }
  char  *x827 = x460;
  char x828 = x827[0];
  int x829 = x828 == '\0';
  int x832;
  if (x829) {
    int x830 = x457;
    x832 = x830;
  } else {
    x832 = 0/*false*/;
  }
  int x836;
  if (x832) {
    int x833 = x458;
    int x834 = x833 == 2;
    x836 = x834;
  } else {
    x836 = 0/*false*/;
  }
  /*@assert ((x460[0]=='\0') || (!x457));*/
  return x836;
}
/*@
requires ((((strlen(x851)>=0) &&
\valid(x851+(0..strlen(x851)))) &&
(((0<=x852) &&
(x852<=x853)) &&
(x853<=strlen(x851)))) &&
star_A(x851,x852,x853));
assigns \nothing;
ensures (\forall int  x907; ((((0<=x852) &&
(x852<=x907)) &&
(x907<x853)) ==> (('A'==x851[x907]) &&
((x907+1)==(x907+1)))));
*/
void lemma_star_A_all(char  * x851, int  x852, int  x853) {
  int x855 = x852;
  /*@
  loop invariant (((0<=x852) &&
  (x852<=x855)) &&
  (x853<=strlen(x851)));
  loop invariant star_A(x851,x855,x853);
  loop invariant (\forall int  x862; (((x852<=x862) &&
  (x862<x855)) ==> ((x851+x862)[0]=='A')));
  loop assigns x855;
  loop variant (x853-x855);
  */
  for (;;) {
    int x856 = x855;
    int x857 = x856 < x853;
    if (!x857) break;
    int x874 = x855;
    int x875 = x874 + 1;
    x855 = x875;
  }
}
/*@
requires ((((strlen(x919)>=0) &&
\valid(x919+(0..strlen(x919)))) &&
(((0<=x920) &&
(x920<=x921)) &&
(x921<=strlen(x919)))) &&
(\forall int  x971; ((((0<=x920) &&
(x920<=x971)) &&
(x971<x921)) ==> (('A'==x919[x971]) &&
((x971+1)==(x971+1))))));
assigns \nothing;
ensures star_A(x919,x920,x921);
*/
void lemma_star_A_from_all(char  * x919, int  x920, int  x921) {
  int x923 = x921;
  /*@
  loop invariant (((0<=x920) &&
  (x920<=x923)) &&
  (x921<=strlen(x919)));
  loop invariant star_A(x919,x923,x921);
  loop invariant (\forall int  x930; ((((0<=x920) &&
  (x920<=x930)) &&
  (x930<x921)) ==> (('A'==x919[x930]) &&
  ((x930+1)==(x930+1)))));
  loop assigns x923;
  loop variant x923;
  */
  for (;;) {
    int x924 = x923;
    int x925 = x920 < x924;
    if (!x925) break;
    int x943 = x923;
    int x944 = x943 - 1;
    x923 = x944;
  }
}
/*@
requires (((((strlen(x986)>=0) &&
\valid(x986+(0..strlen(x986)))) &&
((0<=x987) &&
(x987<=x988))) &&
((x987<x988) &&
(x988<=strlen(x986)))) &&
star_A(x986,x987,x988));
assigns \nothing;
ensures star_A(x986,x987,(x988-1));
*/
void lemma_star_A_dec(char  * x986, int  x987, int  x988) {
  /*@ghost lemma_star_A_all(x986,x987,x988);*/
  /*@ghost lemma_star_A_from_all(x986,x987,(x988-1));*/
}
/*@
requires ((((((((strlen(x1017)>=0) &&
\valid(x1017+(0..strlen(x1017)))) &&
((0<=x1018) &&
(x1018<=x1019))) &&
((0<=x1019) &&
(x1019<x1020))) &&
((0<=x1020) &&
(x1020<=strlen(x1017)))) &&
star_A(x1017,x1018,x1019)) &&
star_A(x1017,x1019,x1020)) &&
((x1019+1)==x1020));
assigns \nothing;
ensures star_A(x1017,x1018,x1020);
*/
void lemma_star_A(char  * x1017, int  x1018, int  x1019, int  x1020) {
  int x1022 = x1019;
  /*@
  loop invariant ((((0<=x1018) &&
  (x1018<=x1022)) &&
  (x1022<=x1020)) &&
  (x1020<=strlen(x1017)));
  loop invariant star_A(x1017,x1022,x1020);
  loop invariant star_A(x1017,x1018,x1022);
  loop assigns x1022;
  loop variant x1022;
  */
  for (;;) {
    int x1023 = x1022;
    int x1024 = x1018 < x1023;
    if (!x1024) break;
    int x1032 = x1022;
    lemma_star_A_dec(x1017,x1018,x1032);
    /*@assert (x1018<x1022);*/
    /*@ghost lemma_star_A_all(x1017,x1018,x1022);*/
    /*@assert (('A'==x1017[(x1022-1)]) &&
    (x1022==((x1022-1)+1)));*/
    /*@assert star_A(x1017,x1022,x1020);*/
    /*@assert star_A(x1017,(x1022-1),x1020);*/
    int x1060 = x1032 - 1;
    x1022 = x1060;
  }
}
