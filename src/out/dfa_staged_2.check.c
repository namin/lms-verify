#include <limits.h>
#include <string.h>
void lemma_star_Y_all(char  * x65, int  x66, int  x67);
void lemma_star_X_from_all(char  * x69, int  x70, int  x71);
void lemma_star_Y(char  * x73, int  x74, int  x75, int  x76);
void lemma_star_Y_dec(char  * x78, int  x79, int  x80);
/*@ predicate star_X(char  * x82, integer  x83, integer  x84) = ((x83==x84) || ((x83<x84) &&
((('X'==x82[x83]) &&
((x83+1)==(x83+1))) &&
star_X(x82,(x83+1),x84))));*/
void lemma_star_Y_from_all(char  * x100, int  x101, int  x102);
void lemma_star_X(char  * x104, int  x105, int  x106, int  x107);
/*@ predicate star_Y(char  * x109, integer  x110, integer  x111) = ((x110==x111) || ((x110<x111) &&
((('Y'==x109[x110]) &&
((x110+1)==(x110+1))) &&
star_Y(x109,(x110+1),x111))));*/
void lemma_star_X_dec(char  * x127, int  x128, int  x129);
void lemma_star_X_all(char  * x131, int  x132, int  x133);
/*@ predicate re_0(char  * x0, integer  x1, integer  x2) = (((('W'==x0[x1]) &&
((x1+1)==(x1+1))) &&
((x1+1)<=x2)) &&
(\exists int x13; (x1<x13<=x2) && (star_X(x0,(x1+1),x13) &&
(((('Y'==x0[x13]) &&
((x13+1)==(x13+1))) &&
((x13+1)<=x2)) &&
((((x13+1)<=(x2-1)) &&
star_Y(x0,(x13+1),(x2-1))) &&
((((x2-1)<=x2) &&
(('Z'==x0[(x2-1)]) &&
(x2==((x2-1)+1)))) &&
(x2>=x2)))))));*/
/*@ predicate re_1(char  * x135, integer  x136, integer  x137) = (\exists int x141; (x136<=x141<=x137) && (star_X(x135,x136,x141) &&
(((('Y'==x135[x141]) &&
((x141+1)==(x141+1))) &&
((x141+1)<=x137)) &&
((((x141+1)<=(x137-1)) &&
star_Y(x135,(x141+1),(x137-1))) &&
((((x137-1)<=x137) &&
(('Z'==x135[(x137-1)]) &&
(x137==((x137-1)+1)))) &&
(x137>=x137))))));*/
/*@ predicate re_2(char  * x191, integer  x192, integer  x193) = (((x192<=(x193-1)) &&
star_Y(x191,x192,(x193-1))) &&
((((x193-1)<=x193) &&
(('Z'==x191[(x193-1)]) &&
(x193==((x193-1)+1)))) &&
(x193>=x193)));*/
/*@ predicate re_3(char  * x211, integer  x212, integer  x213) = (x212>=x213);*/
/*@ predicate re_bwd_0(char  * x216, integer  x217, integer  x218) = (x217>=x218);*/
/*@ predicate re_bwd_1(char  * x221, integer  x222, integer  x223) = (((('W'==x221[x222]) &&
((x222+1)==(x222+1))) &&
((x222+1)<=x223)) &&
((((x222+1)<=x223) &&
star_X(x221,(x222+1),x223)) &&
(x223>=x223)));*/
/*@ predicate re_bwd_2(char  * x240, integer  x241, integer  x242) = (((('W'==x240[x241]) &&
((x241+1)==(x241+1))) &&
((x241+1)<=x242)) &&
(\exists int x253; (x241<x253<=x242) && (star_X(x240,(x241+1),x253) &&
(((('Y'==x240[x253]) &&
((x253+1)==(x253+1))) &&
((x253+1)<=x242)) &&
((((x253+1)<=x242) &&
star_Y(x240,(x253+1),x242)) &&
(x242>=x242))))));*/
/*@ predicate re_bwd_3(char  * x294, integer  x295, integer  x296) = (((('W'==x294[x295]) &&
((x295+1)==(x295+1))) &&
((x295+1)<=x296)) &&
(\exists int x307; (x295<x307<=x296) && (star_X(x294,(x295+1),x307) &&
(((('Y'==x294[x307]) &&
((x307+1)==(x307+1))) &&
((x307+1)<=x296)) &&
((((x307+1)<=(x296-1)) &&
star_Y(x294,(x307+1),(x296-1))) &&
((((x296-1)<=x296) &&
(('Z'==x294[(x296-1)]) &&
(x296==((x296-1)+1)))) &&
(x296>=x296)))))));*/
/*@
requires \false;
assigns \nothing;
ensures re_bwd_0(x359,x360,(x362+1));
*/
void lemma_sanity_0_0(char  * x359, int  x360, int  x361, int  x362) {
}
/*@
requires ((((((((strlen(x384)>=0) &&
\valid(x384+(0..strlen(x384)))) &&
(strlen(x384)<=INT_MAX)) &&
((((0<=x385) &&
(x385<=x386)) &&
(x386<=x387)) &&
(x387<strlen(x384)))) &&
(x384[x387]=='W')) &&
re_bwd_0(x384,x385,x387)) &&
star_X(x384,(x387+1),(x387+1))) &&
re_bwd_0(x384,x385,x386));
assigns \nothing;
ensures re_bwd_1(x384,x385,(x387+1));
*/
void lemma_sanity_0_1(char  * x384, int  x385, int  x386, int  x387) {
  /*@assert re_bwd_0(x384,x385,x387);*/
  /*@assert (x384[x387]=='W');*/
  /*@assert star_X(x384,(x387+1),(x387+1));*/
  /*@assert re_bwd_0(x384,x385,x386);*/
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_2(x425,x426,(x428+1));
*/
void lemma_sanity_0_2(char  * x425, int  x426, int  x427, int  x428) {
  /*@assert re_bwd_0(x425,x426,x428);*/
  /*@assert \false;*/
  /*@assert star_Y(x425,(x428+1),(x428+1));*/
  /*@assert re_bwd_0(x425,x426,x427);*/
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_3(x460,x461,(x463+1));
*/
void lemma_sanity_0_3(char  * x460, int  x461, int  x462, int  x463) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_0(x485,x486,(x488+1));
*/
void lemma_sanity_1_0(char  * x485, int  x486, int  x487, int  x488) {
}
/*@
requires (((((((((strlen(x510)>=0) &&
\valid(x510+(0..strlen(x510)))) &&
(strlen(x510)<=INT_MAX)) &&
((((0<=x511) &&
(x511<=x512)) &&
(x512<=x513)) &&
(x513<strlen(x510)))) &&
(x510[x513]=='X')) &&
star_X(x510,x512,x513)) &&
(\forall int  x566; ((x512<=x566) ==> ((re_bwd_1(x510,x511,x512) &&
star_X(x510,x512,x566)) ==> re_bwd_1(x510,x511,x566))))) &&
re_bwd_1(x510,x511,x512)) &&
re_bwd_1(x510,x511,x513));
assigns \nothing;
ensures (re_bwd_1(x510,x511,(x513+1)) &&
star_X(x510,x512,(x513+1)));
*/
void lemma_sanity_1_1(char  * x510, int  x511, int  x512, int  x513) {
  /*@ghost lemma_star_X(x510,x512,x513,(x513+1));*/
  /*@assert (\forall int  x519; ((x512<=x519) ==> ((re_bwd_1(x510,x511,x512) &&
  star_X(x510,x512,x519)) ==> re_bwd_1(x510,x511,x519))));*/
  /*@assert ((x512<=(x513+1)) ==> ((re_bwd_1(x510,x511,x512) &&
  star_X(x510,x512,(x513+1))) ==> re_bwd_1(x510,x511,(x513+1))));*/
  /*@assert re_bwd_1(x510,x511,x512);*/
}
/*@
requires (((((((((strlen(x587)>=0) &&
\valid(x587+(0..strlen(x587)))) &&
(strlen(x587)<=INT_MAX)) &&
((((0<=x588) &&
(x588<=x589)) &&
(x589<=x590)) &&
(x590<strlen(x587)))) &&
(x587[x590]=='Y')) &&
re_bwd_1(x587,x588,x590)) &&
star_Y(x587,(x590+1),(x590+1))) &&
re_bwd_1(x587,x588,x589)) &&
star_X(x587,x589,x590));
assigns \nothing;
ensures re_bwd_2(x587,x588,(x590+1));
*/
void lemma_sanity_1_2(char  * x587, int  x588, int  x589, int  x590) {
  /*@assert re_bwd_1(x587,x588,x590);*/
  /*@assert (x587[x590]=='Y');*/
  /*@assert star_Y(x587,(x590+1),(x590+1));*/
  /*@assert re_bwd_1(x587,x588,x589);*/
  /*@assert star_X(x587,x589,x590);*/
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_3(x637,x638,(x640+1));
*/
void lemma_sanity_1_3(char  * x637, int  x638, int  x639, int  x640) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_0(x663,x664,(x666+1));
*/
void lemma_sanity_2_0(char  * x663, int  x664, int  x665, int  x666) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_1(x688,x689,(x691+1));
*/
void lemma_sanity_2_1(char  * x688, int  x689, int  x690, int  x691) {
  /*@assert re_bwd_2(x688,x689,x691);*/
  /*@assert \false;*/
  /*@assert star_X(x688,(x691+1),(x691+1));*/
  /*@assert re_bwd_2(x688,x689,x690);*/
  /*@assert star_Y(x688,x690,x691);*/
}
/*@
requires (((((((((strlen(x731)>=0) &&
\valid(x731+(0..strlen(x731)))) &&
(strlen(x731)<=INT_MAX)) &&
((((0<=x732) &&
(x732<=x733)) &&
(x733<=x734)) &&
(x734<strlen(x731)))) &&
(x731[x734]=='Y')) &&
star_Y(x731,x733,x734)) &&
(\forall int  x787; ((x733<=x787) ==> ((re_bwd_2(x731,x732,x733) &&
star_Y(x731,x733,x787)) ==> re_bwd_2(x731,x732,x787))))) &&
re_bwd_2(x731,x732,x733)) &&
re_bwd_2(x731,x732,x734));
assigns \nothing;
ensures (re_bwd_2(x731,x732,(x734+1)) &&
star_Y(x731,x733,(x734+1)));
*/
void lemma_sanity_2_2(char  * x731, int  x732, int  x733, int  x734) {
  /*@ghost lemma_star_Y(x731,x733,x734,(x734+1));*/
  /*@assert (\forall int  x740; ((x733<=x740) ==> ((re_bwd_2(x731,x732,x733) &&
  star_Y(x731,x733,x740)) ==> re_bwd_2(x731,x732,x740))));*/
  /*@assert ((x733<=(x734+1)) ==> ((re_bwd_2(x731,x732,x733) &&
  star_Y(x731,x733,(x734+1))) ==> re_bwd_2(x731,x732,(x734+1))));*/
  /*@assert re_bwd_2(x731,x732,x733);*/
}
/*@
requires ((((((strlen(x808)>=0) &&
\valid(x808+(0..strlen(x808)))) &&
(strlen(x808)<=INT_MAX)) &&
((((0<=x809) &&
(x809<=x810)) &&
(x810<=x811)) &&
(x811<strlen(x808)))) &&
(x808[x811]=='Z')) &&
re_bwd_2(x808,x809,x811));
assigns \nothing;
ensures re_bwd_3(x808,x809,(x811+1));
*/
void lemma_sanity_2_3(char  * x808, int  x809, int  x810, int  x811) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_0(x838,x839,(x841+1));
*/
void lemma_sanity_3_0(char  * x838, int  x839, int  x840, int  x841) {
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_1(x863,x864,(x866+1));
*/
void lemma_sanity_3_1(char  * x863, int  x864, int  x865, int  x866) {
  /*@assert re_bwd_3(x863,x864,x866);*/
  /*@assert \false;*/
  /*@assert star_X(x863,(x866+1),(x866+1));*/
  /*@assert re_bwd_3(x863,x864,x865);*/
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_2(x902,x903,(x905+1));
*/
void lemma_sanity_3_2(char  * x902, int  x903, int  x904, int  x905) {
  /*@assert re_bwd_3(x902,x903,x905);*/
  /*@assert \false;*/
  /*@assert star_Y(x902,(x905+1),(x905+1));*/
  /*@assert re_bwd_3(x902,x903,x904);*/
}
/*@
requires \false;
assigns \nothing;
ensures re_bwd_3(x941,x942,(x944+1));
*/
void lemma_sanity_3_3(char  * x941, int  x942, int  x943, int  x944) {
}
/*@
requires (((strlen(x967)>=0) &&
\valid(x967+(0..strlen(x967)))) &&
(strlen(x967)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x967,0,strlen(x967)));
*/
int dfa(char  * x967) {
  int x969 = 1/*true*/;
  int x970 = 0;
  //@ ghost int x971 = 0;
  char  *x972 = x967;
  //@ ghost int x974 = -1;
  int x975 = x974;
  //@ ghost int x976 = -1;
  int x977 = x976;
  /*@
  loop invariant (((((strlen(x967)>=0) &&
  \valid(x967+(0..strlen(x967)))) &&
  ((0<=x971) &&
  (x971<=strlen(x967)))) &&
  (x972==(x967+x971))) &&
  ((strlen((x967+x971))>=0) &&
  \valid((x967+x971)+(0..strlen((x967+x971))))));
  loop invariant (((x970==0) &&
  x969) ==> re_bwd_0(x967,0,x971));
  loop invariant (((x970==1) &&
  x969) ==> re_bwd_1(x967,0,x971));
  loop invariant (((x970==2) &&
  x969) ==> re_bwd_2(x967,0,x971));
  loop invariant (((x970==3) &&
  x969) ==> re_bwd_3(x967,0,x971));
  loop invariant (((x970==0) &&
  (!x969)) ==> re_bwd_0(x967,0,(x971-1)));
  loop invariant (((x970==1) &&
  (!x969)) ==> re_bwd_1(x967,0,(x971-1)));
  loop invariant (((x970==2) &&
  (!x969)) ==> re_bwd_2(x967,0,(x971-1)));
  loop invariant (((x970==3) &&
  (!x969)) ==> re_bwd_3(x967,0,(x971-1)));
  loop invariant ((((x970==3) &&
  (x972[0]=='\0')) &&
  x969) ==> re_0(x967,0,x971));
  loop invariant ((x970==3) || ((x970==2) || ((x970==1) || (x970==0))));
  loop invariant ((-1<=x974) &&
  (x974<=x971));
  loop invariant ((x974>=0) ==> (x970==1));
  loop invariant ((x970==1) ==> (x974>=0));
  loop invariant ((x974==-1) ==> (x970!=1));
  loop invariant ((x970!=1) ==> (x974==-1));
  loop invariant (\forall int  x1120; (((x974>=0) &&
  (x974<=x1120)) ==> ((re_bwd_1(x967,0,x974) &&
  star_X(x967,x974,x1120)) ==> re_bwd_1(x967,0,x1120))));
  loop invariant ((x974>=0) ==> re_bwd_1(x967,0,x974));
  loop invariant (((x974>=0) &&
  x969) ==> star_X(x967,x974,x971));
  loop invariant ((-1<=x976) &&
  (x976<=x971));
  loop invariant ((x976>=0) ==> (x970==2));
  loop invariant ((x970==2) ==> (x976>=0));
  loop invariant ((x976==-1) ==> (x970!=2));
  loop invariant ((x970!=2) ==> (x976==-1));
  loop invariant (\forall int  x1179; (((x976>=0) &&
  (x976<=x1179)) ==> ((re_bwd_2(x967,0,x976) &&
  star_Y(x967,x976,x1179)) ==> re_bwd_2(x967,0,x1179))));
  loop invariant ((x976>=0) ==> re_bwd_2(x967,0,x976));
  loop invariant (((x976>=0) &&
  x969) ==> star_Y(x967,x976,x971));
  loop assigns x972, x971, x970, x969, x974, x976;
  loop variant strlen(x972);
  */
  for (;;) {
    char  *x978 = x972;
    char x979 = x978[0];
    int x980 = x979 == '\0';
    int x984;
    if (x980) {
      x984 = 0/*false*/;
    } else {
      int x982 = x969;
      x984 = x982;
    }
    if (!x984) break;
    int x1207 = x970;
    int x1208 = x1207 == 3;
    int x1432;
    if (x1208) {
      /*@assert ((x970==3) ==> re_bwd_3(x967,0,x971));*/
      /*@assert re_bwd_3(x967,0,x971);*/
      char  *x1220 = x972;
      x1432 = 0/*false*/;
    } else {
      int x1223 = x1207 == 2;
      int x1430;
      if (x1223) {
        /*@assert ((x970==2) ==> re_bwd_2(x967,0,x971));*/
        /*@assert re_bwd_2(x967,0,x971);*/
        char  *x1235 = x972;
        char x1236 = x1235[0];
        int x1237 = 'Z' == x1236;
        int x1301;
        if (x1237) {
          /*@assert re_bwd_2(x967,0,x971);*/
          x970 = 3;
          /*@ghost lemma_sanity_2_3(x967,0,x976,x971);*/
          /*@ghost x976 = -1;*/
          /*@assert re_bwd_3(x967,0,(x971+1));*/
          /*@assert (((x967+(x971+1))[0]=='\0') ==> re_0(x967,0,(x971+1)));*/
          x1301 = 1/*true*/;
        } else {
          int x1266 = 'Y' == x1236;
          int x1299;
          if (x1266) {
            /*@assert re_bwd_2(x967,0,x971);*/
            x970 = 2;
            /*@assert (x976>=0);*/
            /*@ghost lemma_star_Y(x967,x976,x971,(x971+1));*/
            /*@assert star_Y(x967,x976,(x971+1));*/
            /*@ghost lemma_sanity_2_2(x967,0,x976,x971);*/
            /*@assert re_bwd_2(x967,0,(x971+1));*/
            x1299 = 1/*true*/;
          } else {
            x1299 = 0/*false*/;
          }
          x1301 = x1299;
        }
        x1430 = x1301;
      } else {
        int x1303 = x1207 == 1;
        int x1428;
        if (x1303) {
          /*@assert ((x970==1) ==> re_bwd_1(x967,0,x971));*/
          /*@assert re_bwd_1(x967,0,x971);*/
          char  *x1315 = x972;
          char x1316 = x1315[0];
          int x1317 = 'Y' == x1316;
          int x1382;
          if (x1317) {
            /*@assert re_bwd_1(x967,0,x971);*/
            x970 = 2;
            /*@ghost x976 = (x971+1);*/
            /*@assert star_Y(x967,(x971+1),(x971+1));*/
            /*@ghost lemma_sanity_1_2(x967,0,x974,x971);*/
            /*@ghost x974 = -1;*/
            /*@assert re_bwd_2(x967,0,(x971+1));*/
            x1382 = 1/*true*/;
          } else {
            int x1347 = 'X' == x1316;
            int x1380;
            if (x1347) {
              /*@assert re_bwd_1(x967,0,x971);*/
              x970 = 1;
              /*@assert (x974>=0);*/
              /*@ghost lemma_star_X(x967,x974,x971,(x971+1));*/
              /*@assert star_X(x967,x974,(x971+1));*/
              /*@ghost lemma_sanity_1_1(x967,0,x974,x971);*/
              /*@assert re_bwd_1(x967,0,(x971+1));*/
              x1380 = 1/*true*/;
            } else {
              x1380 = 0/*false*/;
            }
            x1382 = x1380;
          }
          x1428 = x1382;
        } else {
          int x1384 = x1207 == 0;
          int x1426;
          if (x1384) {
            /*@assert ((x970==0) ==> re_bwd_0(x967,0,x971));*/
            /*@assert re_bwd_0(x967,0,x971);*/
            char  *x1396 = x972;
            char x1397 = x1396[0];
            int x1398 = 'W' == x1397;
            int x1424;
            if (x1398) {
              /*@assert re_bwd_0(x967,0,x971);*/
              x970 = 1;
              /*@ghost x974 = (x971+1);*/
              /*@assert star_X(x967,(x971+1),(x971+1));*/
              /*@ghost lemma_sanity_0_1(x967,0,0,x971);*/
              /*@assert re_bwd_1(x967,0,(x971+1));*/
              x1424 = 1/*true*/;
            } else {
              x1424 = 0/*false*/;
            }
            x1426 = x1424;
          } else {
            x1426 = 0/*false*/;
          }
          x1428 = x1426;
        }
        x1430 = x1428;
      }
      x1432 = x1430;
    }
    x969 = x1432;
    char  *x1434 = x972;
    char  *x1435 = x1434+1;
    x972 = x1435;
    /*@ghost x971 = (x971+1);*/
  }
  char  *x1481 = x972;
  char x1482 = x1481[0];
  int x1483 = x1482 == '\0';
  int x1486;
  if (x1483) {
    int x1484 = x969;
    x1486 = x1484;
  } else {
    x1486 = 0/*false*/;
  }
  int x1490;
  if (x1486) {
    int x1487 = x970;
    int x1488 = x1487 == 3;
    x1490 = x1488;
  } else {
    x1490 = 0/*false*/;
  }
  return x1490;
}
/*@
requires ((((strlen(x1497)>=0) &&
\valid(x1497+(0..strlen(x1497)))) &&
(((0<=x1498) &&
(x1498<=x1499)) &&
(x1499<=strlen(x1497)))) &&
star_X(x1497,x1498,x1499));
assigns \nothing;
ensures (\forall int  x1553; ((((0<=x1498) &&
(x1498<=x1553)) &&
(x1553<x1499)) ==> (('X'==x1497[x1553]) &&
((x1553+1)==(x1553+1)))));
*/
void lemma_star_X_all(char  * x1497, int  x1498, int  x1499) {
  int x1501 = x1498;
  /*@
  loop invariant (((0<=x1498) &&
  (x1498<=x1501)) &&
  (x1499<=strlen(x1497)));
  loop invariant star_X(x1497,x1501,x1499);
  loop invariant (\forall int  x1508; (((x1498<=x1508) &&
  (x1508<x1501)) ==> ((x1497+x1508)[0]=='X')));
  loop assigns x1501;
  loop variant (x1499-x1501);
  */
  for (;;) {
    int x1502 = x1501;
    int x1503 = x1502 < x1499;
    if (!x1503) break;
    int x1520 = x1501;
    int x1521 = x1520 + 1;
    x1501 = x1521;
  }
}
/*@
requires ((((strlen(x1565)>=0) &&
\valid(x1565+(0..strlen(x1565)))) &&
(((0<=x1566) &&
(x1566<=x1567)) &&
(x1567<=strlen(x1565)))) &&
(\forall int  x1617; ((((0<=x1566) &&
(x1566<=x1617)) &&
(x1617<x1567)) ==> (('X'==x1565[x1617]) &&
((x1617+1)==(x1617+1))))));
assigns \nothing;
ensures star_X(x1565,x1566,x1567);
*/
void lemma_star_X_from_all(char  * x1565, int  x1566, int  x1567) {
  int x1569 = x1567;
  /*@
  loop invariant (((0<=x1566) &&
  (x1566<=x1569)) &&
  (x1567<=strlen(x1565)));
  loop invariant star_X(x1565,x1569,x1567);
  loop invariant (\forall int  x1576; ((((0<=x1566) &&
  (x1566<=x1576)) &&
  (x1576<x1567)) ==> (('X'==x1565[x1576]) &&
  ((x1576+1)==(x1576+1)))));
  loop assigns x1569;
  loop variant x1569;
  */
  for (;;) {
    int x1570 = x1569;
    int x1571 = x1566 < x1570;
    if (!x1571) break;
    int x1589 = x1569;
    int x1590 = x1589 - 1;
    x1569 = x1590;
  }
}
/*@
requires (((((strlen(x1632)>=0) &&
\valid(x1632+(0..strlen(x1632)))) &&
((0<=x1633) &&
(x1633<=x1634))) &&
((x1633<x1634) &&
(x1634<=strlen(x1632)))) &&
star_X(x1632,x1633,x1634));
assigns \nothing;
ensures star_X(x1632,x1633,(x1634-1));
*/
void lemma_star_X_dec(char  * x1632, int  x1633, int  x1634) {
  /*@ghost lemma_star_X_all(x1632,x1633,x1634);*/
  /*@ghost lemma_star_X_from_all(x1632,x1633,(x1634-1));*/
}
/*@
requires ((((((((strlen(x1663)>=0) &&
\valid(x1663+(0..strlen(x1663)))) &&
((0<=x1664) &&
(x1664<=x1665))) &&
((0<=x1665) &&
(x1665<x1666))) &&
((0<=x1666) &&
(x1666<=strlen(x1663)))) &&
star_X(x1663,x1664,x1665)) &&
star_X(x1663,x1665,x1666)) &&
((x1665+1)==x1666));
assigns \nothing;
ensures star_X(x1663,x1664,x1666);
*/
void lemma_star_X(char  * x1663, int  x1664, int  x1665, int  x1666) {
  int x1668 = x1665;
  /*@
  loop invariant ((((0<=x1664) &&
  (x1664<=x1668)) &&
  (x1668<=x1666)) &&
  (x1666<=strlen(x1663)));
  loop invariant star_X(x1663,x1668,x1666);
  loop invariant star_X(x1663,x1664,x1668);
  loop assigns x1668;
  loop variant x1668;
  */
  for (;;) {
    int x1669 = x1668;
    int x1670 = x1664 < x1669;
    if (!x1670) break;
    int x1678 = x1668;
    lemma_star_X_dec(x1663,x1664,x1678);
    /*@assert (x1664<x1668);*/
    /*@ghost lemma_star_X_all(x1663,x1664,x1668);*/
    /*@assert (('X'==x1663[(x1668-1)]) &&
    (x1668==((x1668-1)+1)));*/
    /*@assert star_X(x1663,x1668,x1666);*/
    /*@assert star_X(x1663,(x1668-1),x1666);*/
    int x1706 = x1678 - 1;
    x1668 = x1706;
  }
}
/*@
requires ((((strlen(x1754)>=0) &&
\valid(x1754+(0..strlen(x1754)))) &&
(((0<=x1755) &&
(x1755<=x1756)) &&
(x1756<=strlen(x1754)))) &&
star_Y(x1754,x1755,x1756));
assigns \nothing;
ensures (\forall int  x1810; ((((0<=x1755) &&
(x1755<=x1810)) &&
(x1810<x1756)) ==> (('Y'==x1754[x1810]) &&
((x1810+1)==(x1810+1)))));
*/
void lemma_star_Y_all(char  * x1754, int  x1755, int  x1756) {
  int x1758 = x1755;
  /*@
  loop invariant (((0<=x1755) &&
  (x1755<=x1758)) &&
  (x1756<=strlen(x1754)));
  loop invariant star_Y(x1754,x1758,x1756);
  loop invariant (\forall int  x1765; (((x1755<=x1765) &&
  (x1765<x1758)) ==> ((x1754+x1765)[0]=='Y')));
  loop assigns x1758;
  loop variant (x1756-x1758);
  */
  for (;;) {
    int x1759 = x1758;
    int x1760 = x1759 < x1756;
    if (!x1760) break;
    int x1777 = x1758;
    int x1778 = x1777 + 1;
    x1758 = x1778;
  }
}
/*@
requires ((((strlen(x1822)>=0) &&
\valid(x1822+(0..strlen(x1822)))) &&
(((0<=x1823) &&
(x1823<=x1824)) &&
(x1824<=strlen(x1822)))) &&
(\forall int  x1874; ((((0<=x1823) &&
(x1823<=x1874)) &&
(x1874<x1824)) ==> (('Y'==x1822[x1874]) &&
((x1874+1)==(x1874+1))))));
assigns \nothing;
ensures star_Y(x1822,x1823,x1824);
*/
void lemma_star_Y_from_all(char  * x1822, int  x1823, int  x1824) {
  int x1826 = x1824;
  /*@
  loop invariant (((0<=x1823) &&
  (x1823<=x1826)) &&
  (x1824<=strlen(x1822)));
  loop invariant star_Y(x1822,x1826,x1824);
  loop invariant (\forall int  x1833; ((((0<=x1823) &&
  (x1823<=x1833)) &&
  (x1833<x1824)) ==> (('Y'==x1822[x1833]) &&
  ((x1833+1)==(x1833+1)))));
  loop assigns x1826;
  loop variant x1826;
  */
  for (;;) {
    int x1827 = x1826;
    int x1828 = x1823 < x1827;
    if (!x1828) break;
    int x1846 = x1826;
    int x1847 = x1846 - 1;
    x1826 = x1847;
  }
}
/*@
requires (((((strlen(x1889)>=0) &&
\valid(x1889+(0..strlen(x1889)))) &&
((0<=x1890) &&
(x1890<=x1891))) &&
((x1890<x1891) &&
(x1891<=strlen(x1889)))) &&
star_Y(x1889,x1890,x1891));
assigns \nothing;
ensures star_Y(x1889,x1890,(x1891-1));
*/
void lemma_star_Y_dec(char  * x1889, int  x1890, int  x1891) {
  /*@ghost lemma_star_Y_all(x1889,x1890,x1891);*/
  /*@ghost lemma_star_Y_from_all(x1889,x1890,(x1891-1));*/
}
/*@
requires ((((((((strlen(x1920)>=0) &&
\valid(x1920+(0..strlen(x1920)))) &&
((0<=x1921) &&
(x1921<=x1922))) &&
((0<=x1922) &&
(x1922<x1923))) &&
((0<=x1923) &&
(x1923<=strlen(x1920)))) &&
star_Y(x1920,x1921,x1922)) &&
star_Y(x1920,x1922,x1923)) &&
((x1922+1)==x1923));
assigns \nothing;
ensures star_Y(x1920,x1921,x1923);
*/
void lemma_star_Y(char  * x1920, int  x1921, int  x1922, int  x1923) {
  int x1925 = x1922;
  /*@
  loop invariant ((((0<=x1921) &&
  (x1921<=x1925)) &&
  (x1925<=x1923)) &&
  (x1923<=strlen(x1920)));
  loop invariant star_Y(x1920,x1925,x1923);
  loop invariant star_Y(x1920,x1921,x1925);
  loop assigns x1925;
  loop variant x1925;
  */
  for (;;) {
    int x1926 = x1925;
    int x1927 = x1921 < x1926;
    if (!x1927) break;
    int x1935 = x1925;
    lemma_star_Y_dec(x1920,x1921,x1935);
    /*@assert (x1921<x1925);*/
    /*@ghost lemma_star_Y_all(x1920,x1921,x1925);*/
    /*@assert (('Y'==x1920[(x1925-1)]) &&
    (x1925==((x1925-1)+1)));*/
    /*@assert star_Y(x1920,x1925,x1923);*/
    /*@assert star_Y(x1920,(x1925-1),x1923);*/
    int x1963 = x1935 - 1;
    x1925 = x1963;
  }
}
