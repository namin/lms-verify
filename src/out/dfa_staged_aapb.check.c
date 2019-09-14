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
/*@ predicate re_bwd_0(char  * x89, integer  x90, integer  x91) = (x90>=x91);*/
/*@ predicate re_bwd_1(char  * x94, integer  x95, integer  x96) = (((x95==x96) || (('A'==x94[x95]) &&
(x96>=(x95+1)))) || ((('A'==x94[x95]) &&
((x95+1)==(x95+1))) &&
(star_A(x94,(x95+1),x96) || (\exists int x110; ((x95+1)<x110<=x96) && (star_A(x94,(x95+1),x110) &&
(x110>=x96))))));*/
/*@ predicate re_bwd_2(char  * x126, integer  x127, integer  x128) = (((x127==x128) || (('A'==x126[x127]) &&
(x128>=(x127+1)))) || ((('A'==x126[x127]) &&
((x127+1)==(x127+1))) &&
(star_A(x126,(x127+1),x128) || (\exists int x142; ((x127+1)<x142<=x128) && (star_A(x126,(x127+1),x142) &&
(((x142==x128) || (('B'==x126[x142]) &&
(x128>=(x142+1)))) || ((('B'==x126[x142]) &&
((x142+1)==(x142+1))) &&
((x142+1)>=x128))))))));*/
/*@
requires (((strlen(x180)>=0) &&
\valid(x180+(0..strlen(x180)))) &&
(strlen(x180)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x180,0,strlen(x180)));
*/
int dfa(char  * x180) {
  int x182 = 1/*true*/;
  int x183 = 0;
  //@ ghost int x184 = 0;
  char  *x185 = x180;
  /*@
  loop invariant (((((strlen(x180)>=0) &&
  \valid(x180+(0..strlen(x180)))) &&
  ((0<=x184) &&
  (x184<=strlen(x180)))) &&
  (x185==(x180+x184))) &&
  ((strlen((x180+x184))>=0) &&
  \valid((x180+x184)+(0..strlen((x180+x184))))));
  loop invariant (((x183==0) &&
  x182) ==> re_bwd_0(x180,0,x184));
  loop invariant (((x183==1) &&
  x182) ==> re_bwd_1(x180,0,x184));
  loop invariant (((x183==2) &&
  x182) ==> re_bwd_2(x180,0,x184));
  loop invariant ((!x182) ==> (!re_bwd_2(x180,0,x184) ||
  (!re_bwd_1(x180,0,x184) ||
  (!re_bwd_0(x180,0,x184)))));
  loop invariant ((!x182) ==> (!re_bwd_2(x180,0,x184) ||
  (!re_bwd_1(x180,0,x184) ||
  (!re_bwd_0(x180,0,x184)))));
  loop invariant ((!x182) ==> (!re_bwd_2(x180,0,x184) ||
  (!re_bwd_1(x180,0,x184) ||
  (!re_bwd_0(x180,0,x184)))));
  loop invariant (((x183==0) &&
  (!x182)) ==> re_bwd_0(x180,0,(x184-1)));
  loop invariant (((x183==1) &&
  (!x182)) ==> re_bwd_1(x180,0,(x184-1)));
  loop invariant (((x183==2) &&
  (!x182)) ==> re_bwd_2(x180,0,(x184-1)));
  loop invariant ((((x183==2) &&
  (x185[0]=='\0')) &&
  x182) ==> re_0(x180,0,x184));
  loop invariant ((x183==2) || ((x183==1) || (x183==0)));
  loop invariant (((x183==1) &&
  x182) ==> ((x180[0]=='A') &&
  star_A(x180,1,x184)));
  loop assigns x185, x184, x183, x182;
  loop variant strlen(x185);
  */
  for (;;) {
    char  *x187 = x185;
    char x188 = x187[0];
    int x189 = x188 == '\0';
    int x193;
    if (x189) {
      x193 = 0/*false*/;
    } else {
      int x191 = x182;
      x193 = x191;
    }
    if (!x193) break;
    int x334 = x183;
    int x335 = x334 == 2;
    int x508;
    if (x335) {
      /*@assert ((x183==2) ==> re_bwd_2(x180,0,x184));*/
      /*@assert re_bwd_2(x180,0,x184);*/
      char  *x347 = x185;
      x508 = 0/*false*/;
    } else {
      int x350 = x334 == 1;
      int x506;
      if (x350) {
        /*@assert ((x183==1) ==> re_bwd_1(x180,0,x184));*/
        /*@assert re_bwd_1(x180,0,x184);*/
        /*@assert ((x183==1) ==> ((x180[0]=='A') &&
        star_A(x180,1,x184)));*/
        /*@assert ((x180[0]=='A') &&
        star_A(x180,1,x184));*/
        char  *x377 = x185;
        char x378 = x377[0];
        int x379 = 'B' == x378;
        int x450;
        if (x379) {
          /*@assert re_bwd_1(x180,0,x184);*/
          x183 = 2;
          /*@assert (!(x183==1));*/
          /*@assert ((x183==1) ==> ((x180[0]=='A') &&
          star_A(x180,1,(x184+1))));*/
          /*@assert re_bwd_2(x180,0,(x184+1));*/
          /*@assert (((x180+(x184+1))[0]=='\0') ==> re_0(x180,0,(x184+1)));*/
          x450 = 1/*true*/;
        } else {
          int x415 = 'A' == x378;
          int x448;
          if (x415) {
            /*@assert re_bwd_1(x180,0,x184);*/
            x183 = 1;
            /*@ghost lemma_star_A(x180,1,x184,(x184+1));*/
            /*@assert (x180[0]=='A');*/
            /*@assert star_A(x180,1,(x184+1));*/
            /*@assert ((x183==1) ==> ((x180[0]=='A') &&
            star_A(x180,1,(x184+1))));*/
            /*@assert re_bwd_1(x180,0,(x184+1));*/
            x448 = 1/*true*/;
          } else {
            x448 = 0/*false*/;
          }
          x450 = x448;
        }
        x506 = x450;
      } else {
        int x452 = x334 == 0;
        int x504;
        if (x452) {
          /*@assert ((x183==0) ==> re_bwd_0(x180,0,x184));*/
          /*@assert re_bwd_0(x180,0,x184);*/
          char  *x464 = x185;
          char x465 = x464[0];
          int x466 = 'A' == x465;
          int x502;
          if (x466) {
            /*@assert re_bwd_0(x180,0,x184);*/
            x183 = 1;
            /*@assert (x184==0);*/
            /*@assert (x180[0]=='A');*/
            /*@assert star_A(x180,1,1);*/
            /*@assert (x180[0]=='A');*/
            /*@assert star_A(x180,1,(x184+1));*/
            /*@assert ((x183==1) ==> ((x180[0]=='A') &&
            star_A(x180,1,(x184+1))));*/
            /*@assert re_bwd_1(x180,0,(x184+1));*/
            x502 = 1/*true*/;
          } else {
            x502 = 0/*false*/;
          }
          x504 = x502;
        } else {
          x504 = 0/*false*/;
        }
        x506 = x504;
      }
      x508 = x506;
    }
    x182 = x508;
    char  *x510 = x185;
    char  *x511 = x510+1;
    x185 = x511;
    /*@ghost x184 = (x184+1);*/
  }
  char  *x557 = x185;
  char x558 = x557[0];
  int x559 = x558 == '\0';
  int x562;
  if (x559) {
    int x560 = x182;
    x562 = x560;
  } else {
    x562 = 0/*false*/;
  }
  int x566;
  if (x562) {
    int x563 = x183;
    int x564 = x563 == 2;
    x566 = x564;
  } else {
    x566 = 0/*false*/;
  }
  return x566;
}
/*@
requires ((((strlen(x574)>=0) &&
\valid(x574+(0..strlen(x574)))) &&
(((0<=x575) &&
(x575<=x576)) &&
(x576<=strlen(x574)))) &&
star_A(x574,x575,x576));
assigns \nothing;
ensures (\forall int  x630; ((((0<=x575) &&
(x575<=x630)) &&
(x630<x576)) ==> ((x574+x630)[0]=='A')));
*/
void lemma_star_A_all(char  * x574, int  x575, int  x576) {
  int x578 = x575;
  /*@
  loop invariant (((0<=x575) &&
  (x575<=x578)) &&
  (x576<=strlen(x574)));
  loop invariant star_A(x574,x578,x576);
  loop invariant (\forall int  x585; (((x575<=x585) &&
  (x585<x578)) ==> ((x574+x585)[0]=='A')));
  loop assigns x578;
  loop variant (x576-x578);
  */
  for (;;) {
    int x579 = x578;
    int x580 = x579 < x576;
    if (!x580) break;
    int x597 = x578;
    int x598 = x597 + 1;
    x578 = x598;
  }
}
/*@
requires ((((strlen(x640)>=0) &&
\valid(x640+(0..strlen(x640)))) &&
(((0<=x641) &&
(x641<=x642)) &&
(x642<=strlen(x640)))) &&
(\forall int  x690; ((((0<=x641) &&
(x641<=x690)) &&
(x690<x642)) ==> ((x640+x690)[0]=='A'))));
assigns \nothing;
ensures star_A(x640,x641,x642);
*/
void lemma_star_A_from_all(char  * x640, int  x641, int  x642) {
  int x644 = x642;
  /*@
  loop invariant (((0<=x641) &&
  (x641<=x644)) &&
  (x642<=strlen(x640)));
  loop invariant star_A(x640,x644,x642);
  loop invariant (\forall int  x651; ((((0<=x641) &&
  (x641<=x651)) &&
  (x651<x642)) ==> ((x640+x651)[0]=='A')));
  loop assigns x644;
  loop variant x644;
  */
  for (;;) {
    int x645 = x644;
    int x646 = x641 < x645;
    if (!x646) break;
    int x662 = x644;
    int x663 = x662 - 1;
    x644 = x663;
  }
}
/*@
requires (((((strlen(x703)>=0) &&
\valid(x703+(0..strlen(x703)))) &&
((0<=x704) &&
(x704<=x705))) &&
((x704<x705) &&
(x705<=strlen(x703)))) &&
star_A(x703,x704,x705));
assigns \nothing;
ensures star_A(x703,x704,(x705-1));
*/
void lemma_star_A_dec(char  * x703, int  x704, int  x705) {
  /*@ghost lemma_star_A_all(x703,x704,x705);*/
  /*@ghost lemma_star_A_from_all(x703,x704,(x705-1));*/
}
/*@
requires ((((((((strlen(x734)>=0) &&
\valid(x734+(0..strlen(x734)))) &&
((0<=x735) &&
(x735<=x736))) &&
((0<=x736) &&
(x736<x737))) &&
((0<=x737) &&
(x737<=strlen(x734)))) &&
star_A(x734,x735,x736)) &&
star_A(x734,x736,x737)) &&
((x736+1)==x737));
assigns \nothing;
ensures star_A(x734,x735,x737);
*/
void lemma_star_A(char  * x734, int  x735, int  x736, int  x737) {
  int x739 = x736;
  /*@
  loop invariant ((((0<=x735) &&
  (x735<=x739)) &&
  (x739<=x737)) &&
  (x737<=strlen(x734)));
  loop invariant star_A(x734,x739,x737);
  loop invariant star_A(x734,x735,x739);
  loop assigns x739;
  loop variant x739;
  */
  for (;;) {
    int x740 = x739;
    int x741 = x735 < x740;
    if (!x741) break;
    int x749 = x739;
    lemma_star_A_dec(x734,x735,x749);
    /*@assert (x735<x739);*/
    /*@ghost lemma_star_A_all(x734,x735,x739);*/
    /*@assert ((x734+(x739-1))[0]=='A');*/
    /*@assert star_A(x734,x739,x737);*/
    /*@assert star_A(x734,(x739-1),x737);*/
    int x775 = x749 - 1;
    x739 = x775;
  }
}
