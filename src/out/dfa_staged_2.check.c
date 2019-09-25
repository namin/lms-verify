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
(x2==x2)))))));*/
/*@ predicate re_1(char  * x135, integer  x136, integer  x137) = (\exists int x141; (x136<=x141<=x137) && (star_X(x135,x136,x141) &&
(((('Y'==x135[x141]) &&
((x141+1)==(x141+1))) &&
((x141+1)<=x137)) &&
((((x141+1)<=(x137-1)) &&
star_Y(x135,(x141+1),(x137-1))) &&
((((x137-1)<=x137) &&
(('Z'==x135[(x137-1)]) &&
(x137==((x137-1)+1)))) &&
(x137==x137))))));*/
/*@ predicate re_2(char  * x191, integer  x192, integer  x193) = (((x192<=(x193-1)) &&
star_Y(x191,x192,(x193-1))) &&
((((x193-1)<=x193) &&
(('Z'==x191[(x193-1)]) &&
(x193==((x193-1)+1)))) &&
(x193==x193)));*/
/*@ predicate re_3(char  * x211, integer  x212, integer  x213) = (x212==x213);*/
/*@ predicate re_bwd_0(char  * x216, integer  x217, integer  x218) = (x217==x218);*/
/*@ predicate re_bwd_1(char  * x221, integer  x222, integer  x223) = (((('W'==x221[x222]) &&
((x222+1)==(x222+1))) &&
((x222+1)<=x223)) &&
((((x222+1)<=x223) &&
star_X(x221,(x222+1),x223)) &&
(x223==x223)));*/
/*@ predicate re_bwd_2(char  * x240, integer  x241, integer  x242) = (((('W'==x240[x241]) &&
((x241+1)==(x241+1))) &&
((x241+1)<=x242)) &&
(\exists int x253; (x241<x253<=x242) && (star_X(x240,(x241+1),x253) &&
(((('Y'==x240[x253]) &&
((x253+1)==(x253+1))) &&
((x253+1)<=x242)) &&
((((x253+1)<=x242) &&
star_Y(x240,(x253+1),x242)) &&
(x242==x242))))));*/
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
(x296==x296)))))));*/
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
  loop invariant (x969 ==> (re_bwd_3(x967,0,x971) || (re_bwd_2(x967,0,x971) || (re_bwd_1(x967,0,x971) || re_bwd_0(x967,0,x971)))));
  loop invariant ((x972[0]=='\0') ==> (strlen(x967)==x971));
  loop invariant ((!(x972[0]=='\0')) ==> (strlen(x967)!=x971));
  loop invariant ((x970==3) || ((x970==2) || ((x970==1) || (x970==0))));
  loop invariant ((-1<=x974) &&
  (x974<=x971));
  loop invariant ((x974>=0) ==> (x970==1));
  loop invariant ((x970==1) ==> (x974>=0));
  loop invariant ((x974==-1) ==> (x970!=1));
  loop invariant ((x970!=1) ==> (x974==-1));
  loop invariant (\forall int  x1146; (((x974>=0) &&
  (x974<=x1146)) ==> ((re_bwd_1(x967,0,x974) &&
  star_X(x967,x974,x1146)) ==> re_bwd_1(x967,0,x1146))));
  loop invariant ((x974>=0) ==> re_bwd_1(x967,0,x974));
  loop invariant (((x974>=0) &&
  x969) ==> star_X(x967,x974,x971));
  loop invariant ((-1<=x976) &&
  (x976<=x971));
  loop invariant ((x976>=0) ==> (x970==2));
  loop invariant ((x970==2) ==> (x976>=0));
  loop invariant ((x976==-1) ==> (x970!=2));
  loop invariant ((x970!=2) ==> (x976==-1));
  loop invariant (\forall int  x1205; (((x976>=0) &&
  (x976<=x1205)) ==> ((re_bwd_2(x967,0,x976) &&
  star_Y(x967,x976,x1205)) ==> re_bwd_2(x967,0,x1205))));
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
    int x1233 = x970;
    int x1234 = x1233 == 3;
    int x1458;
    if (x1234) {
      /*@assert ((x970==3) ==> re_bwd_3(x967,0,x971));*/
      /*@assert re_bwd_3(x967,0,x971);*/
      char  *x1246 = x972;
      x1458 = 0/*false*/;
    } else {
      int x1249 = x1233 == 2;
      int x1456;
      if (x1249) {
        /*@assert ((x970==2) ==> re_bwd_2(x967,0,x971));*/
        /*@assert re_bwd_2(x967,0,x971);*/
        char  *x1261 = x972;
        char x1262 = x1261[0];
        int x1263 = 'Z' == x1262;
        int x1327;
        if (x1263) {
          /*@assert re_bwd_2(x967,0,x971);*/
          x970 = 3;
          /*@ghost lemma_sanity_2_3(x967,0,x976,x971);*/
          /*@ghost x976 = -1;*/
          /*@assert re_bwd_3(x967,0,(x971+1));*/
          /*@assert (((x967+(x971+1))[0]=='\0') ==> re_0(x967,0,(x971+1)));*/
          x1327 = 1/*true*/;
        } else {
          int x1292 = 'Y' == x1262;
          int x1325;
          if (x1292) {
            /*@assert re_bwd_2(x967,0,x971);*/
            x970 = 2;
            /*@assert (x976>=0);*/
            /*@ghost lemma_star_Y(x967,x976,x971,(x971+1));*/
            /*@assert star_Y(x967,x976,(x971+1));*/
            /*@ghost lemma_sanity_2_2(x967,0,x976,x971);*/
            /*@assert re_bwd_2(x967,0,(x971+1));*/
            x1325 = 1/*true*/;
          } else {
            x1325 = 0/*false*/;
          }
          x1327 = x1325;
        }
        x1456 = x1327;
      } else {
        int x1329 = x1233 == 1;
        int x1454;
        if (x1329) {
          /*@assert ((x970==1) ==> re_bwd_1(x967,0,x971));*/
          /*@assert re_bwd_1(x967,0,x971);*/
          char  *x1341 = x972;
          char x1342 = x1341[0];
          int x1343 = 'Y' == x1342;
          int x1408;
          if (x1343) {
            /*@assert re_bwd_1(x967,0,x971);*/
            x970 = 2;
            /*@ghost x976 = (x971+1);*/
            /*@assert star_Y(x967,(x971+1),(x971+1));*/
            /*@ghost lemma_sanity_1_2(x967,0,x974,x971);*/
            /*@ghost x974 = -1;*/
            /*@assert re_bwd_2(x967,0,(x971+1));*/
            x1408 = 1/*true*/;
          } else {
            int x1373 = 'X' == x1342;
            int x1406;
            if (x1373) {
              /*@assert re_bwd_1(x967,0,x971);*/
              x970 = 1;
              /*@assert (x974>=0);*/
              /*@ghost lemma_star_X(x967,x974,x971,(x971+1));*/
              /*@assert star_X(x967,x974,(x971+1));*/
              /*@ghost lemma_sanity_1_1(x967,0,x974,x971);*/
              /*@assert re_bwd_1(x967,0,(x971+1));*/
              x1406 = 1/*true*/;
            } else {
              x1406 = 0/*false*/;
            }
            x1408 = x1406;
          }
          x1454 = x1408;
        } else {
          int x1410 = x1233 == 0;
          int x1452;
          if (x1410) {
            /*@assert ((x970==0) ==> re_bwd_0(x967,0,x971));*/
            /*@assert re_bwd_0(x967,0,x971);*/
            char  *x1422 = x972;
            char x1423 = x1422[0];
            int x1424 = 'W' == x1423;
            int x1450;
            if (x1424) {
              /*@assert re_bwd_0(x967,0,x971);*/
              x970 = 1;
              /*@ghost x974 = (x971+1);*/
              /*@assert star_X(x967,(x971+1),(x971+1));*/
              /*@ghost lemma_sanity_0_1(x967,0,0,x971);*/
              /*@assert re_bwd_1(x967,0,(x971+1));*/
              x1450 = 1/*true*/;
            } else {
              x1450 = 0/*false*/;
            }
            x1452 = x1450;
          } else {
            x1452 = 0/*false*/;
          }
          x1454 = x1452;
        }
        x1456 = x1454;
      }
      x1458 = x1456;
    }
    x969 = x1458;
    char  *x1460 = x972;
    char  *x1461 = x1460+1;
    x972 = x1461;
    /*@ghost x971 = (x971+1);*/
  }
  char  *x1507 = x972;
  char x1508 = x1507[0];
  int x1509 = x1508 == '\0';
  int x1512;
  if (x1509) {
    int x1510 = x969;
    x1512 = x1510;
  } else {
    x1512 = 0/*false*/;
  }
  int x1516;
  if (x1512) {
    int x1513 = x970;
    int x1514 = x1513 == 3;
    x1516 = x1514;
  } else {
    x1516 = 0/*false*/;
  }
  /*@assert ((x972[0]=='\0') || (!x969));*/
  return x1516;
}
/*@
requires ((((strlen(x1531)>=0) &&
\valid(x1531+(0..strlen(x1531)))) &&
(((0<=x1532) &&
(x1532<=x1533)) &&
(x1533<=strlen(x1531)))) &&
star_X(x1531,x1532,x1533));
assigns \nothing;
ensures (\forall int  x1587; ((((0<=x1532) &&
(x1532<=x1587)) &&
(x1587<x1533)) ==> (('X'==x1531[x1587]) &&
((x1587+1)==(x1587+1)))));
*/
void lemma_star_X_all(char  * x1531, int  x1532, int  x1533) {
  int x1535 = x1532;
  /*@
  loop invariant (((0<=x1532) &&
  (x1532<=x1535)) &&
  (x1533<=strlen(x1531)));
  loop invariant star_X(x1531,x1535,x1533);
  loop invariant (\forall int  x1542; (((x1532<=x1542) &&
  (x1542<x1535)) ==> ((x1531+x1542)[0]=='X')));
  loop assigns x1535;
  loop variant (x1533-x1535);
  */
  for (;;) {
    int x1536 = x1535;
    int x1537 = x1536 < x1533;
    if (!x1537) break;
    int x1554 = x1535;
    int x1555 = x1554 + 1;
    x1535 = x1555;
  }
}
/*@
requires ((((strlen(x1599)>=0) &&
\valid(x1599+(0..strlen(x1599)))) &&
(((0<=x1600) &&
(x1600<=x1601)) &&
(x1601<=strlen(x1599)))) &&
(\forall int  x1651; ((((0<=x1600) &&
(x1600<=x1651)) &&
(x1651<x1601)) ==> (('X'==x1599[x1651]) &&
((x1651+1)==(x1651+1))))));
assigns \nothing;
ensures star_X(x1599,x1600,x1601);
*/
void lemma_star_X_from_all(char  * x1599, int  x1600, int  x1601) {
  int x1603 = x1601;
  /*@
  loop invariant (((0<=x1600) &&
  (x1600<=x1603)) &&
  (x1601<=strlen(x1599)));
  loop invariant star_X(x1599,x1603,x1601);
  loop invariant (\forall int  x1610; ((((0<=x1600) &&
  (x1600<=x1610)) &&
  (x1610<x1601)) ==> (('X'==x1599[x1610]) &&
  ((x1610+1)==(x1610+1)))));
  loop assigns x1603;
  loop variant x1603;
  */
  for (;;) {
    int x1604 = x1603;
    int x1605 = x1600 < x1604;
    if (!x1605) break;
    int x1623 = x1603;
    int x1624 = x1623 - 1;
    x1603 = x1624;
  }
}
/*@
requires (((((strlen(x1666)>=0) &&
\valid(x1666+(0..strlen(x1666)))) &&
((0<=x1667) &&
(x1667<=x1668))) &&
((x1667<x1668) &&
(x1668<=strlen(x1666)))) &&
star_X(x1666,x1667,x1668));
assigns \nothing;
ensures star_X(x1666,x1667,(x1668-1));
*/
void lemma_star_X_dec(char  * x1666, int  x1667, int  x1668) {
  /*@ghost lemma_star_X_all(x1666,x1667,x1668);*/
  /*@ghost lemma_star_X_from_all(x1666,x1667,(x1668-1));*/
}
/*@
requires ((((((((strlen(x1697)>=0) &&
\valid(x1697+(0..strlen(x1697)))) &&
((0<=x1698) &&
(x1698<=x1699))) &&
((0<=x1699) &&
(x1699<x1700))) &&
((0<=x1700) &&
(x1700<=strlen(x1697)))) &&
star_X(x1697,x1698,x1699)) &&
star_X(x1697,x1699,x1700)) &&
((x1699+1)==x1700));
assigns \nothing;
ensures star_X(x1697,x1698,x1700);
*/
void lemma_star_X(char  * x1697, int  x1698, int  x1699, int  x1700) {
  int x1702 = x1699;
  /*@
  loop invariant ((((0<=x1698) &&
  (x1698<=x1702)) &&
  (x1702<=x1700)) &&
  (x1700<=strlen(x1697)));
  loop invariant star_X(x1697,x1702,x1700);
  loop invariant star_X(x1697,x1698,x1702);
  loop assigns x1702;
  loop variant x1702;
  */
  for (;;) {
    int x1703 = x1702;
    int x1704 = x1698 < x1703;
    if (!x1704) break;
    int x1712 = x1702;
    lemma_star_X_dec(x1697,x1698,x1712);
    /*@assert (x1698<x1702);*/
    /*@ghost lemma_star_X_all(x1697,x1698,x1702);*/
    /*@assert (('X'==x1697[(x1702-1)]) &&
    (x1702==((x1702-1)+1)));*/
    /*@assert star_X(x1697,x1702,x1700);*/
    /*@assert star_X(x1697,(x1702-1),x1700);*/
    int x1740 = x1712 - 1;
    x1702 = x1740;
  }
}
/*@
requires ((((strlen(x1788)>=0) &&
\valid(x1788+(0..strlen(x1788)))) &&
(((0<=x1789) &&
(x1789<=x1790)) &&
(x1790<=strlen(x1788)))) &&
star_Y(x1788,x1789,x1790));
assigns \nothing;
ensures (\forall int  x1844; ((((0<=x1789) &&
(x1789<=x1844)) &&
(x1844<x1790)) ==> (('Y'==x1788[x1844]) &&
((x1844+1)==(x1844+1)))));
*/
void lemma_star_Y_all(char  * x1788, int  x1789, int  x1790) {
  int x1792 = x1789;
  /*@
  loop invariant (((0<=x1789) &&
  (x1789<=x1792)) &&
  (x1790<=strlen(x1788)));
  loop invariant star_Y(x1788,x1792,x1790);
  loop invariant (\forall int  x1799; (((x1789<=x1799) &&
  (x1799<x1792)) ==> ((x1788+x1799)[0]=='Y')));
  loop assigns x1792;
  loop variant (x1790-x1792);
  */
  for (;;) {
    int x1793 = x1792;
    int x1794 = x1793 < x1790;
    if (!x1794) break;
    int x1811 = x1792;
    int x1812 = x1811 + 1;
    x1792 = x1812;
  }
}
/*@
requires ((((strlen(x1856)>=0) &&
\valid(x1856+(0..strlen(x1856)))) &&
(((0<=x1857) &&
(x1857<=x1858)) &&
(x1858<=strlen(x1856)))) &&
(\forall int  x1908; ((((0<=x1857) &&
(x1857<=x1908)) &&
(x1908<x1858)) ==> (('Y'==x1856[x1908]) &&
((x1908+1)==(x1908+1))))));
assigns \nothing;
ensures star_Y(x1856,x1857,x1858);
*/
void lemma_star_Y_from_all(char  * x1856, int  x1857, int  x1858) {
  int x1860 = x1858;
  /*@
  loop invariant (((0<=x1857) &&
  (x1857<=x1860)) &&
  (x1858<=strlen(x1856)));
  loop invariant star_Y(x1856,x1860,x1858);
  loop invariant (\forall int  x1867; ((((0<=x1857) &&
  (x1857<=x1867)) &&
  (x1867<x1858)) ==> (('Y'==x1856[x1867]) &&
  ((x1867+1)==(x1867+1)))));
  loop assigns x1860;
  loop variant x1860;
  */
  for (;;) {
    int x1861 = x1860;
    int x1862 = x1857 < x1861;
    if (!x1862) break;
    int x1880 = x1860;
    int x1881 = x1880 - 1;
    x1860 = x1881;
  }
}
/*@
requires (((((strlen(x1923)>=0) &&
\valid(x1923+(0..strlen(x1923)))) &&
((0<=x1924) &&
(x1924<=x1925))) &&
((x1924<x1925) &&
(x1925<=strlen(x1923)))) &&
star_Y(x1923,x1924,x1925));
assigns \nothing;
ensures star_Y(x1923,x1924,(x1925-1));
*/
void lemma_star_Y_dec(char  * x1923, int  x1924, int  x1925) {
  /*@ghost lemma_star_Y_all(x1923,x1924,x1925);*/
  /*@ghost lemma_star_Y_from_all(x1923,x1924,(x1925-1));*/
}
/*@
requires ((((((((strlen(x1954)>=0) &&
\valid(x1954+(0..strlen(x1954)))) &&
((0<=x1955) &&
(x1955<=x1956))) &&
((0<=x1956) &&
(x1956<x1957))) &&
((0<=x1957) &&
(x1957<=strlen(x1954)))) &&
star_Y(x1954,x1955,x1956)) &&
star_Y(x1954,x1956,x1957)) &&
((x1956+1)==x1957));
assigns \nothing;
ensures star_Y(x1954,x1955,x1957);
*/
void lemma_star_Y(char  * x1954, int  x1955, int  x1956, int  x1957) {
  int x1959 = x1956;
  /*@
  loop invariant ((((0<=x1955) &&
  (x1955<=x1959)) &&
  (x1959<=x1957)) &&
  (x1957<=strlen(x1954)));
  loop invariant star_Y(x1954,x1959,x1957);
  loop invariant star_Y(x1954,x1955,x1959);
  loop assigns x1959;
  loop variant x1959;
  */
  for (;;) {
    int x1960 = x1959;
    int x1961 = x1955 < x1960;
    if (!x1961) break;
    int x1969 = x1959;
    lemma_star_Y_dec(x1954,x1955,x1969);
    /*@assert (x1955<x1959);*/
    /*@ghost lemma_star_Y_all(x1954,x1955,x1959);*/
    /*@assert (('Y'==x1954[(x1959-1)]) &&
    (x1959==((x1959-1)+1)));*/
    /*@assert star_Y(x1954,x1959,x1957);*/
    /*@assert star_Y(x1954,(x1959-1),x1957);*/
    int x1997 = x1969 - 1;
    x1959 = x1997;
  }
}
