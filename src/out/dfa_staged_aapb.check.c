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
requires ((((((strlen(x167)>=0) &&
\valid(x167+(0..strlen(x167)))) &&
(strlen(x167)<=INT_MAX)) &&
((((0<=x168) &&
(x168<=x169)) &&
(x169<=x170)) &&
(x170<strlen(x167)))) &&
(x167[x170]=='A')) &&
re_bwd_0(x167,x168,x170));
assigns \nothing;
ensures re_bwd_1(x167,x168,(x170+1));
*/
void lemma_sanity_0_1(char  * x167, int  x168, int  x169, int  x170) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_2(x196,x197,(x199+1));
*/
void lemma_sanity_0_2(char  * x196, int  x197, int  x198, int  x199) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_0(x221,x222,(x224+1));
*/
void lemma_sanity_1_0(char  * x221, int  x222, int  x223, int  x224) {
}
/*@
requires (((((((((strlen(x246)>=0) &&
\valid(x246+(0..strlen(x246)))) &&
(strlen(x246)<=INT_MAX)) &&
((((0<=x247) &&
(x247<=x248)) &&
(x248<=x249)) &&
(x249<strlen(x246)))) &&
(x246[x249]=='A')) &&
star_A(x246,x248,x249)) &&
(\forall int  x302; ((x248<=x302) ==> ((re_bwd_1(x246,x247,x248) &&
star_A(x246,x248,x302)) ==> re_bwd_1(x246,x247,x302))))) &&
re_bwd_1(x246,x247,x248)) &&
re_bwd_1(x246,x247,x249));
assigns \nothing;
ensures (re_bwd_1(x246,x247,(x249+1)) &&
star_A(x246,x248,(x249+1)));
*/
void lemma_sanity_1_1(char  * x246, int  x247, int  x248, int  x249) {
  /*@ghost lemma_star_A(x246,x248,x249,(x249+1));*/
  /*@assert (\forall int  x255; ((x248<=x255) ==> ((re_bwd_1(x246,x247,x248) &&
  star_A(x246,x248,x255)) ==> re_bwd_1(x246,x247,x255))));*/
  /*@assert ((x248<=(x249+1)) ==> ((re_bwd_1(x246,x247,x248) &&
  star_A(x246,x248,(x249+1))) ==> re_bwd_1(x246,x247,(x249+1))));*/
  /*@assert re_bwd_1(x246,x247,x248);*/
}
/*@
requires ((((((strlen(x323)>=0) &&
\valid(x323+(0..strlen(x323)))) &&
(strlen(x323)<=INT_MAX)) &&
((((0<=x324) &&
(x324<=x325)) &&
(x325<=x326)) &&
(x326<strlen(x323)))) &&
(x323[x326]=='B')) &&
re_bwd_1(x323,x324,x326));
assigns \nothing;
ensures re_bwd_2(x323,x324,(x326+1));
*/
void lemma_sanity_1_2(char  * x323, int  x324, int  x325, int  x326) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_0(x353,x354,(x356+1));
*/
void lemma_sanity_2_0(char  * x353, int  x354, int  x355, int  x356) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_1(x378,x379,(x381+1));
*/
void lemma_sanity_2_1(char  * x378, int  x379, int  x380, int  x381) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_2(x404,x405,(x407+1));
*/
void lemma_sanity_2_2(char  * x404, int  x405, int  x406, int  x407) {
}
/*@
requires (((strlen(x430)>=0) &&
\valid(x430+(0..strlen(x430)))) &&
(strlen(x430)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x430,0,strlen(x430)));
*/
int dfa(char  * x430) {
  int x432 = 1/*true*/;
  int x433 = 0;
  //@ ghost int x434 = 0;
  char  *x435 = x430;
  //@ ghost int x437 = -1;
  int x438 = x437;
  /*@
  loop invariant (((((strlen(x430)>=0) &&
  \valid(x430+(0..strlen(x430)))) &&
  ((0<=x434) &&
  (x434<=strlen(x430)))) &&
  (x435==(x430+x434))) &&
  ((strlen((x430+x434))>=0) &&
  \valid((x430+x434)+(0..strlen((x430+x434))))));
  loop invariant (((x433==0) &&
  x432) ==> re_bwd_0(x430,0,x434));
  loop invariant (((x433==1) &&
  x432) ==> re_bwd_1(x430,0,x434));
  loop invariant (((x433==2) &&
  x432) ==> re_bwd_2(x430,0,x434));
  loop invariant (((x433==0) &&
  (!x432)) ==> re_bwd_0(x430,0,(x434-1)));
  loop invariant (((x433==1) &&
  (!x432)) ==> re_bwd_1(x430,0,(x434-1)));
  loop invariant (((x433==2) &&
  (!x432)) ==> re_bwd_2(x430,0,(x434-1)));
  loop invariant ((((x433==2) &&
  (x435[0]=='\0')) &&
  x432) ==> re_0(x430,0,x434));
  loop invariant ((x433==2) || ((x433==1) || (x433==0)));
  loop invariant ((-1<=x437) &&
  (x437<=x434));
  loop invariant ((x437>=0) ==> (x433==1));
  loop invariant ((x433==1) ==> (x437>=0));
  loop invariant ((x437==-1) ==> (x433!=1));
  loop invariant ((x433!=1) ==> (x437==-1));
  loop invariant (\forall int  x559; (((x437>=0) &&
  (x437<=x559)) ==> ((re_bwd_1(x430,0,x437) &&
  star_A(x430,x437,x559)) ==> re_bwd_1(x430,0,x559))));
  loop invariant ((x437>=0) ==> re_bwd_1(x430,0,x437));
  loop invariant (((x437>=0) &&
  x432) ==> star_A(x430,x437,x434));
  loop assigns x435, x434, x433, x432, x437;
  loop variant strlen(x435);
  */
  for (;;) {
    char  *x439 = x435;
    char x440 = x439[0];
    int x441 = x440 == '\0';
    int x445;
    if (x441) {
      x445 = 0/*false*/;
    } else {
      int x443 = x432;
      x445 = x443;
    }
    if (!x445) break;
    int x587 = x433;
    int x588 = x587 == 2;
    int x724;
    if (x588) {
      /*@assert ((x433==2) ==> re_bwd_2(x430,0,x434));*/
      /*@assert re_bwd_2(x430,0,x434);*/
      char  *x600 = x435;
      x724 = 0/*false*/;
    } else {
      int x603 = x587 == 1;
      int x722;
      if (x603) {
        /*@assert ((x433==1) ==> re_bwd_1(x430,0,x434));*/
        /*@assert re_bwd_1(x430,0,x434);*/
        char  *x615 = x435;
        char x616 = x615[0];
        int x617 = 'B' == x616;
        int x676;
        if (x617) {
          /*@assert re_bwd_1(x430,0,x434);*/
          x433 = 2;
          /*@ghost lemma_sanity_1_2(x430,0,0,x434);*/
          /*@ghost x437 = -1;*/
          /*@assert re_bwd_2(x430,0,(x434+1));*/
          /*@assert (((x430+(x434+1))[0]=='\0') ==> re_0(x430,0,(x434+1)));*/
          x676 = 1/*true*/;
        } else {
          int x645 = 'A' == x616;
          int x674;
          if (x645) {
            /*@assert re_bwd_1(x430,0,x434);*/
            x433 = 1;
            /*@ghost lemma_star_A(x430,x437,x434,(x434+1));*/
            /*@assert star_A(x430,x437,(x434+1));*/
            /*@ghost lemma_sanity_1_1(x430,0,x437,x434);*/
            /*@assert re_bwd_1(x430,0,(x434+1));*/
            x674 = 1/*true*/;
          } else {
            x674 = 0/*false*/;
          }
          x676 = x674;
        }
        x722 = x676;
      } else {
        int x678 = x587 == 0;
        int x720;
        if (x678) {
          /*@assert ((x433==0) ==> re_bwd_0(x430,0,x434));*/
          /*@assert re_bwd_0(x430,0,x434);*/
          char  *x690 = x435;
          char x691 = x690[0];
          int x692 = 'A' == x691;
          int x718;
          if (x692) {
            /*@assert re_bwd_0(x430,0,x434);*/
            x433 = 1;
            /*@ghost x437 = (x434+1);*/
            /*@assert star_A(x430,(x434+1),(x434+1));*/
            /*@ghost lemma_sanity_0_1(x430,0,0,x434);*/
            /*@assert re_bwd_1(x430,0,(x434+1));*/
            x718 = 1/*true*/;
          } else {
            x718 = 0/*false*/;
          }
          x720 = x718;
        } else {
          x720 = 0/*false*/;
        }
        x722 = x720;
      }
      x724 = x722;
    }
    x432 = x724;
    char  *x726 = x435;
    char  *x727 = x726+1;
    x435 = x727;
    /*@ghost x434 = (x434+1);*/
  }
  char  *x773 = x435;
  char x774 = x773[0];
  int x775 = x774 == '\0';
  int x778;
  if (x775) {
    int x776 = x432;
    x778 = x776;
  } else {
    x778 = 0/*false*/;
  }
  int x782;
  if (x778) {
    int x779 = x433;
    int x780 = x779 == 2;
    x782 = x780;
  } else {
    x782 = 0/*false*/;
  }
  return x782;
}
/*@
requires ((((strlen(x789)>=0) &&
\valid(x789+(0..strlen(x789)))) &&
(((0<=x790) &&
(x790<=x791)) &&
(x791<=strlen(x789)))) &&
star_A(x789,x790,x791));
assigns \nothing;
ensures (\forall int  x845; ((((0<=x790) &&
(x790<=x845)) &&
(x845<x791)) ==> (('A'==x789[x845]) &&
((x845+1)==(x845+1)))));
*/
void lemma_star_A_all(char  * x789, int  x790, int  x791) {
  int x793 = x790;
  /*@
  loop invariant (((0<=x790) &&
  (x790<=x793)) &&
  (x791<=strlen(x789)));
  loop invariant star_A(x789,x793,x791);
  loop invariant (\forall int  x800; (((x790<=x800) &&
  (x800<x793)) ==> ((x789+x800)[0]=='A')));
  loop assigns x793;
  loop variant (x791-x793);
  */
  for (;;) {
    int x794 = x793;
    int x795 = x794 < x791;
    if (!x795) break;
    int x812 = x793;
    int x813 = x812 + 1;
    x793 = x813;
  }
}
/*@
requires ((((strlen(x857)>=0) &&
\valid(x857+(0..strlen(x857)))) &&
(((0<=x858) &&
(x858<=x859)) &&
(x859<=strlen(x857)))) &&
(\forall int  x909; ((((0<=x858) &&
(x858<=x909)) &&
(x909<x859)) ==> (('A'==x857[x909]) &&
((x909+1)==(x909+1))))));
assigns \nothing;
ensures star_A(x857,x858,x859);
*/
void lemma_star_A_from_all(char  * x857, int  x858, int  x859) {
  int x861 = x859;
  /*@
  loop invariant (((0<=x858) &&
  (x858<=x861)) &&
  (x859<=strlen(x857)));
  loop invariant star_A(x857,x861,x859);
  loop invariant (\forall int  x868; ((((0<=x858) &&
  (x858<=x868)) &&
  (x868<x859)) ==> (('A'==x857[x868]) &&
  ((x868+1)==(x868+1)))));
  loop assigns x861;
  loop variant x861;
  */
  for (;;) {
    int x862 = x861;
    int x863 = x858 < x862;
    if (!x863) break;
    int x881 = x861;
    int x882 = x881 - 1;
    x861 = x882;
  }
}
/*@
requires (((((strlen(x924)>=0) &&
\valid(x924+(0..strlen(x924)))) &&
((0<=x925) &&
(x925<=x926))) &&
((x925<x926) &&
(x926<=strlen(x924)))) &&
star_A(x924,x925,x926));
assigns \nothing;
ensures star_A(x924,x925,(x926-1));
*/
void lemma_star_A_dec(char  * x924, int  x925, int  x926) {
  /*@ghost lemma_star_A_all(x924,x925,x926);*/
  /*@ghost lemma_star_A_from_all(x924,x925,(x926-1));*/
}
/*@
requires ((((((((strlen(x955)>=0) &&
\valid(x955+(0..strlen(x955)))) &&
((0<=x956) &&
(x956<=x957))) &&
((0<=x957) &&
(x957<x958))) &&
((0<=x958) &&
(x958<=strlen(x955)))) &&
star_A(x955,x956,x957)) &&
star_A(x955,x957,x958)) &&
((x957+1)==x958));
assigns \nothing;
ensures star_A(x955,x956,x958);
*/
void lemma_star_A(char  * x955, int  x956, int  x957, int  x958) {
  int x960 = x957;
  /*@
  loop invariant ((((0<=x956) &&
  (x956<=x960)) &&
  (x960<=x958)) &&
  (x958<=strlen(x955)));
  loop invariant star_A(x955,x960,x958);
  loop invariant star_A(x955,x956,x960);
  loop assigns x960;
  loop variant x960;
  */
  for (;;) {
    int x961 = x960;
    int x962 = x956 < x961;
    if (!x962) break;
    int x970 = x960;
    lemma_star_A_dec(x955,x956,x970);
    /*@assert (x956<x960);*/
    /*@ghost lemma_star_A_all(x955,x956,x960);*/
    /*@assert (('A'==x955[(x960-1)]) &&
    (x960==((x960-1)+1)));*/
    /*@assert star_A(x955,x960,x958);*/
    /*@assert star_A(x955,(x960-1),x958);*/
    int x998 = x970 - 1;
    x960 = x998;
  }
}
