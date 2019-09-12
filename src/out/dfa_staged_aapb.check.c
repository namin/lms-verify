#include <limits.h>
#include <string.h>
/*@ predicate star_A(char  * x51, integer  x52, integer  x53) = (\exists integer  x55; ((((x52<x55) &&
(x55<=x53)) ==> ((('A'==x51[x52]) &&
(x55==(x52+1))) &&
star_A(x51,x55,x53))) || (x52==x53)));*/
/*@ predicate re_0(char  * x0, integer  x1, integer  x2) = (\exists integer  x4; ((((x1<=x4) &&
(x4<=x2)) &&
(('A'==x0[x1]) &&
(x4==(x1+1)))) &&
(\exists integer  x17; ((((x4<=x17) &&
(x17<=x2)) &&
star_A(x0,x4,x17)) &&
(\exists integer  x25; ((((x17<=x25) &&
(x25<=x2)) &&
(('B'==x0[x17]) &&
(x25==(x17+1)))) &&
(x25==x2)))))));*/
/*@ predicate re_1(char  * x74, integer  x75, integer  x76) = (\exists integer  x78; ((((x75<=x78) &&
(x78<=x76)) &&
star_A(x74,x75,x78)) &&
(\exists integer  x85; ((((x78<=x85) &&
(x85<=x76)) &&
(('B'==x74[x78]) &&
(x85==(x78+1)))) &&
(x85==x76)))));*/
/*@ predicate re_2(char  * x107, integer  x108, integer  x109) = (x108==x109);*/
/*@ predicate re_bwd_0(char  * x112, integer  x113, integer  x114) = (x113==x114);*/
/*@ predicate re_bwd_1(char  * x117, integer  x118, integer  x119) = (\exists integer  x121; ((((x118<=x121) &&
(x121<=x119)) &&
(('A'==x117[x118]) &&
(x121==(x118+1)))) &&
(\exists integer  x134; ((((x121<=x134) &&
(x134<=x119)) &&
star_A(x117,x121,x134)) &&
(x134==x119)))));*/
/*@ predicate re_bwd_2(char  * x150, integer  x151, integer  x152) = (\exists integer  x154; ((((x151<=x154) &&
(x154<=x152)) &&
(('A'==x150[x151]) &&
(x154==(x151+1)))) &&
(\exists integer  x167; ((((x154<=x167) &&
(x167<=x152)) &&
star_A(x150,x154,x167)) &&
(\exists integer  x174; ((((x167<=x174) &&
(x174<=x152)) &&
(('B'==x150[x167]) &&
(x174==(x167+1)))) &&
(x174==x152)))))));*/
/*@ predicate star_starting_A(char  * x269, integer  x270, integer  x271) = ((((x270==x271) || (('A'==x269[x270]) &&
(x271>=(x270+1)))) || (\exists integer  x280; (((x270<x280) &&
(x280<=x271)) ==> ((('A'==x269[x270]) &&
(x280==(x270+1))) &&
star_starting_A(x269,x280,x271))))) || (x271>=x270));*/
/*@ predicate re0(char  * x200, integer  x201, integer  x202) = (((x201==x202) || (('A'==x200[x201]) &&
(x202>=(x201+1)))) || (\exists integer  x211; ((((x201<=x211) &&
(x211<=x202)) &&
(('A'==x200[x201]) &&
(x211==(x201+1)))) &&
(star_starting_A(x200,x211,x202) || (\exists integer  x225; ((((x211<=x225) &&
(x225<=x202)) &&
star_A(x200,x211,x225)) &&
(((x225==x202) || (('B'==x200[x225]) &&
(x202>=(x225+1)))) || (\exists integer  x240; ((((x225<=x240) &&
(x240<=x202)) &&
(('B'==x200[x225]) &&
(x240==(x225+1)))) &&
(x202>=x240))))))))));*/
/*@
requires (((strlen(x300)>=0) &&
\valid(x300+(0..(strlen(x300)+1)-1))) &&
(strlen(x300)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x300,0,strlen(x300)));
*/
int dfa(char  * x300) {
  int x302 = 1/*true*/;
  int x303 = 0;
  //@ ghost int x304 = 0;
  char  *x305 = x300;
  /*@
  loop invariant ((((((((strlen(x300)>=0) &&
  \valid(x300+(0..(strlen(x300)+1)-1))) &&
  ((0<=x304) &&
  (x304<=strlen(x300)))) &&
  (x305==(x300+x304))) &&
  ((strlen((x300+x304))>=0) &&
  \valid((x300+x304)+(0..(strlen((x300+x304))+1)-1)))) &&
  (x302 ==> (((x303==2) ==> re_bwd_2(x300,0,x304)) &&
  (((x303==1) ==> re_bwd_1(x300,0,x304)) &&
  ((x303==0) ==> re_bwd_0(x300,0,x304)))))) &&
  ((x303==2) ==> (re_bwd_2(x300,0,x304) ==> re_0(x300,0,x304)))) &&
  ((x303==2) || ((x303==1) || (x303==0))));
  loop assigns x305, x304, x303, x302;
  loop variant strlen(x305);
  */
  for (;;) {
    char  *x307 = x305;
    char x308 = x307[0];
    int x309 = x308 == '\0';
    int x313;
    if (x309) {
      x313 = 0/*false*/;
    } else {
      int x311 = x302;
      x313 = x311;
    }
    if (!x313) break;
    char  *x315 = x305;
    int x317 = x303;
    int x318 = x317 == 0;
    int x324;
    if (x318) {
      char x316 = x315[0];
      int x319 = 'A' == x316;
      int x322;
      if (x319) {
        x303 = 1;
        x322 = 1/*true*/;
      } else {
        x322 = 0/*false*/;
      }
      x324 = x322;
    } else {
      x324 = 0/*false*/;
    }
    int x325 = x303;
    int x326 = x325 == 1;
    int x335;
    if (x326) {
      char x316 = x315[0];
      int x319 = 'A' == x316;
      int x329;
      if (x319) {
        x303 = 1;
        x329 = 1/*true*/;
      } else {
        x329 = 0/*false*/;
      }
      int x330 = 'B' == x316;
      int x333;
      if (x330) {
        x303 = 2;
        x333 = 1/*true*/;
      } else {
        x333 = x329;
      }
      x335 = x333;
    } else {
      x335 = x324;
    }
    int x336 = x303;
    int x337 = x336 == 2;
    int x338;
    if (x337) {
      x338 = 0/*false*/;
    } else {
      x338 = x335;
    }
    x302 = x338;
    //@ ghost int x340 = x304;
    //@ ghost int x341 = x340 + 1;
    //@ ghost x304 = x341;
    char  *x343 = x315+1;
    x305 = x343;
  }
  int x428 = x303;
  char  *x429 = x305;
  char x430 = x429[0];
  int x431 = x430 == '\0';
  int x434;
  if (x431) {
    int x432 = x302;
    x434 = x432;
  } else {
    x434 = 0/*false*/;
  }
  int x436;
  if (x434) {
    int x435 = 2 == x428;
    x436 = x435;
  } else {
    x436 = 0/*false*/;
  }
  return x436;
}
