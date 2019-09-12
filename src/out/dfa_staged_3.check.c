#include <limits.h>
#include <string.h>
/*@ predicate star_A(char  * x93, integer  x94, integer  x95) = ((x94==x95) || (\exists integer  x98; (((x94<x98) &&
(x98<=x95)) ==> ((('A'==x93[x94]) &&
(x98==(x94+1))) &&
star_A(x93,x98,x95)))));*/
/*@ predicate star_D(char  * x114, integer  x115, integer  x116) = ((x115==x116) || (\exists integer  x119; (((x115<x119) &&
(x119<=x116)) ==> ((('D'==x114[x115]) &&
(x119==(x115+1))) &&
star_D(x114,x119,x116)))));*/
/*@ predicate star_C(char  * x135, integer  x136, integer  x137) = ((x136==x137) || (\exists integer  x140; (((x136<x140) &&
(x140<=x137)) ==> ((('C'==x135[x136]) &&
(x140==(x136+1))) &&
star_C(x135,x140,x137)))));*/
/*@ predicate star__orB_or_C_sCs_Bor_(char  * x156, integer  x157, integer  x158) = ((x157==x158) || (\exists integer  x161; (((x157<x161) &&
(x161<=x158)) ==> (((('B'==x156[x157]) &&
(x161==(x157+1))) || (\exists integer  x170; ((((x157<=x170) &&
(x170<=x161)) &&
(('C'==x156[x157]) &&
(x170==(x157+1)))) &&
(\exists integer  x178; ((((x170<=x178) &&
(x178<=x161)) &&
star_C(x156,x170,x178)) &&
(('B'==x156[x178]) &&
(x161==(x178+1)))))))) &&
star__orB_or_C_sCs_Bor_(x156,x161,x158)))));*/
/*@ predicate re_0(char  * x0, integer  x1, integer  x2) = (\exists integer  x4; ((((x1<=x4) &&
(x4<=x2)) &&
(('A'==x0[x1]) &&
(x4==(x1+1)))) &&
(\exists integer  x14; ((((x4<=x14) &&
(x14<=x2)) &&
star_A(x0,x4,x14)) &&
(\exists integer  x21; ((((x14<=x21) &&
(x21<=x2)) &&
(('B'==x0[x14]) &&
(x21==(x14+1)))) &&
(\exists integer  x31; ((((x21<=x31) &&
(x31<=x2)) &&
star__orB_or_C_sCs_Bor_(x0,x21,x31)) &&
(\exists integer  x38; ((((x31<=x38) &&
(x38<=x2)) &&
(('C'==x0[x31]) &&
(x38==(x31+1)))) &&
(\exists integer  x48; ((((x38<=x48) &&
(x48<=x2)) &&
star_C(x0,x38,x48)) &&
(\exists integer  x55; ((((x48<=x55) &&
(x55<=x2)) &&
(('D'==x0[x48]) &&
(x55==(x48+1)))) &&
(\exists integer  x65; ((((x55<=x65) &&
(x65<=x2)) &&
star_D(x0,x55,x65)) &&
(x65==x2)))))))))))))))));*/
/*@ predicate re_1(char  * x201, integer  x202, integer  x203) = (\exists integer  x205; ((((x202<=x205) &&
(x205<=x203)) &&
star_A(x201,x202,x205)) &&
(\exists integer  x211; ((((x205<=x211) &&
(x211<=x203)) &&
(('B'==x201[x205]) &&
(x211==(x205+1)))) &&
(\exists integer  x221; ((((x211<=x221) &&
(x221<=x203)) &&
star__orB_or_C_sCs_Bor_(x201,x211,x221)) &&
(\exists integer  x227; ((((x221<=x227) &&
(x227<=x203)) &&
(('C'==x201[x221]) &&
(x227==(x221+1)))) &&
(\exists integer  x237; ((((x227<=x237) &&
(x237<=x203)) &&
star_C(x201,x227,x237)) &&
(\exists integer  x243; ((((x237<=x243) &&
(x243<=x203)) &&
(('D'==x201[x237]) &&
(x243==(x237+1)))) &&
(\exists integer  x253; ((((x243<=x253) &&
(x253<=x203)) &&
star_D(x201,x243,x253)) &&
(x253==x203)))))))))))))));*/
/*@ predicate re_2(char  * x274, integer  x275, integer  x276) = (\exists integer  x278; ((((x275<=x278) &&
(x278<=x276)) &&
star__orB_or_C_sCs_Bor_(x274,x275,x278)) &&
(\exists integer  x284; ((((x278<=x284) &&
(x284<=x276)) &&
(('C'==x274[x278]) &&
(x284==(x278+1)))) &&
(\exists integer  x294; ((((x284<=x294) &&
(x294<=x276)) &&
star_C(x274,x284,x294)) &&
(\exists integer  x300; ((((x294<=x300) &&
(x300<=x276)) &&
(('D'==x274[x294]) &&
(x300==(x294+1)))) &&
(\exists integer  x310; ((((x300<=x310) &&
(x310<=x276)) &&
star_D(x274,x300,x310)) &&
(x310==x276)))))))))));*/
/*@ predicate re_3(char  * x327, integer  x328, integer  x329) = (\exists integer  x331; ((((x328<=x331) &&
(x331<=x329)) &&
star_C(x327,x328,x331)) &&
(\exists integer  x337; ((((x331<=x337) &&
(x337<=x329)) &&
(('D'==x327[x331]) &&
(x337==(x331+1)))) &&
(\exists integer  x347; ((((x337<=x347) &&
(x347<=x329)) &&
star_D(x327,x337,x347)) &&
(x347==x329)))))));*/
/*@ predicate re_4(char  * x360, integer  x361, integer  x362) = (\exists integer  x364; ((((x361<=x364) &&
(x364<=x362)) &&
star_D(x360,x361,x364)) &&
(x364==x362)));*/
/*@ predicate re_bwd_0(char  * x373, integer  x374, integer  x375) = (x374==x375);*/
/*@ predicate re_bwd_1(char  * x378, integer  x379, integer  x380) = (\exists integer  x382; ((((x379<=x382) &&
(x382<=x380)) &&
(('A'==x378[x379]) &&
(x382==(x379+1)))) &&
(\exists integer  x392; ((((x382<=x392) &&
(x392<=x380)) &&
star_A(x378,x382,x392)) &&
(x392==x380)))));*/
/*@ predicate re_bwd_2(char  * x403, integer  x404, integer  x405) = (\exists integer  x407; ((((x404<=x407) &&
(x407<=x405)) &&
(('A'==x403[x404]) &&
(x407==(x404+1)))) &&
(\exists integer  x417; ((((x407<=x417) &&
(x417<=x405)) &&
star_A(x403,x407,x417)) &&
(\exists integer  x423; ((((x417<=x423) &&
(x423<=x405)) &&
(('B'==x403[x417]) &&
(x423==(x417+1)))) &&
(\exists integer  x433; ((((x423<=x433) &&
(x433<=x405)) &&
star__orB_or_C_sCs_Bor_(x403,x423,x433)) &&
(x433==x405)))))))));*/
/*@ predicate re_bwd_3(char  * x448, integer  x449, integer  x450) = (\exists integer  x452; ((((x449<=x452) &&
(x452<=x450)) &&
(('A'==x448[x449]) &&
(x452==(x449+1)))) &&
(\exists integer  x462; ((((x452<=x462) &&
(x462<=x450)) &&
star_A(x448,x452,x462)) &&
(\exists integer  x468; ((((x462<=x468) &&
(x468<=x450)) &&
(('B'==x448[x462]) &&
(x468==(x462+1)))) &&
(\exists integer  x478; ((((x468<=x478) &&
(x478<=x450)) &&
star__orB_or_C_sCs_Bor_(x448,x468,x478)) &&
(\exists integer  x484; ((((x478<=x484) &&
(x484<=x450)) &&
(('C'==x448[x478]) &&
(x484==(x478+1)))) &&
(\exists integer  x494; ((((x484<=x494) &&
(x494<=x450)) &&
star_C(x448,x484,x494)) &&
(x494==x450)))))))))))));*/
/*@ predicate re_bwd_4(char  * x513, integer  x514, integer  x515) = (\exists integer  x517; ((((x514<=x517) &&
(x517<=x515)) &&
(('A'==x513[x514]) &&
(x517==(x514+1)))) &&
(\exists integer  x527; ((((x517<=x527) &&
(x527<=x515)) &&
star_A(x513,x517,x527)) &&
(\exists integer  x533; ((((x527<=x533) &&
(x533<=x515)) &&
(('B'==x513[x527]) &&
(x533==(x527+1)))) &&
(\exists integer  x543; ((((x533<=x543) &&
(x543<=x515)) &&
star__orB_or_C_sCs_Bor_(x513,x533,x543)) &&
(\exists integer  x549; ((((x543<=x549) &&
(x549<=x515)) &&
(('C'==x513[x543]) &&
(x549==(x543+1)))) &&
(\exists integer  x559; ((((x549<=x559) &&
(x559<=x515)) &&
star_C(x513,x549,x559)) &&
(\exists integer  x565; ((((x559<=x565) &&
(x565<=x515)) &&
(('D'==x513[x559]) &&
(x565==(x559+1)))) &&
(\exists integer  x575; ((((x565<=x575) &&
(x575<=x515)) &&
star_D(x513,x565,x575)) &&
(x575==x515)))))))))))))))));*/
/*@ predicate star_starting_D(char  * x719, integer  x720, integer  x721) = ((((x720==x721) || (('D'==x719[x720]) &&
(x721>=(x720+1)))) || (\exists integer  x730; (((x720<x730) &&
(x730<=x721)) ==> ((('D'==x719[x720]) &&
(x730==(x720+1))) &&
star_starting_D(x719,x730,x721))))) || (x721>=x720));*/
/*@ predicate star_starting_A(char  * x745, integer  x746, integer  x747) = ((((x746==x747) || (('A'==x745[x746]) &&
(x747>=(x746+1)))) || (\exists integer  x756; (((x746<x756) &&
(x756<=x747)) ==> ((('A'==x745[x746]) &&
(x756==(x746+1))) &&
star_starting_A(x745,x756,x747))))) || (x747>=x746));*/
/*@ predicate star_starting_C(char  * x771, integer  x772, integer  x773) = ((((x772==x773) || (('C'==x771[x772]) &&
(x773>=(x772+1)))) || (\exists integer  x782; (((x772<x782) &&
(x782<=x773)) ==> ((('C'==x771[x772]) &&
(x782==(x772+1))) &&
star_starting_C(x771,x782,x773))))) || (x773>=x772));*/
/*@ predicate star_starting__orB_or_C_sCs_Bor_(char  * x797, integer  x798, integer  x799) = (((((x798==x799) || (('B'==x797[x798]) &&
(x799>=(x798+1)))) || (((x798==x799) || (('C'==x797[x798]) &&
(x799>=(x798+1)))) || (\exists integer  x811; ((((x798<=x811) &&
(x811<=x799)) &&
(('C'==x797[x798]) &&
(x811==(x798+1)))) &&
(star_starting_C(x797,x811,x799) || (\exists integer  x819; ((((x811<=x819) &&
(x819<=x799)) &&
star_C(x797,x811,x819)) &&
((x819==x799) || (('B'==x797[x819]) &&
(x799>=(x819+1))))))))))) || (\exists integer  x839; (((x798<x839) &&
(x839<=x799)) ==> (((('B'==x797[x798]) &&
(x839==(x798+1))) || (\exists integer  x845; ((((x798<=x845) &&
(x845<=x839)) &&
(('C'==x797[x798]) &&
(x845==(x798+1)))) &&
(\exists integer  x852; ((((x845<=x852) &&
(x852<=x839)) &&
star_C(x797,x845,x852)) &&
(('B'==x797[x852]) &&
(x839==(x852+1)))))))) &&
star_starting__orB_or_C_sCs_Bor_(x797,x839,x799))))) || (x799>=x798));*/
/*@ predicate re0(char  * x598, integer  x599, integer  x600) = (((x599==x600) || (('A'==x598[x599]) &&
(x600>=(x599+1)))) || (\exists integer  x609; ((((x599<=x609) &&
(x609<=x600)) &&
(('A'==x598[x599]) &&
(x609==(x599+1)))) &&
(star_starting_A(x598,x609,x600) || (\exists integer  x617; ((((x609<=x617) &&
(x617<=x600)) &&
star_A(x598,x609,x617)) &&
(((x617==x600) || (('B'==x598[x617]) &&
(x600>=(x617+1)))) || (\exists integer  x630; ((((x617<=x630) &&
(x630<=x600)) &&
(('B'==x598[x617]) &&
(x630==(x617+1)))) &&
(star_starting__orB_or_C_sCs_Bor_(x598,x630,x600) || (\exists integer  x638; ((((x630<=x638) &&
(x638<=x600)) &&
star__orB_or_C_sCs_Bor_(x598,x630,x638)) &&
(((x638==x600) || (('C'==x598[x638]) &&
(x600>=(x638+1)))) || (\exists integer  x651; ((((x638<=x651) &&
(x651<=x600)) &&
(('C'==x598[x638]) &&
(x651==(x638+1)))) &&
(star_starting_C(x598,x651,x600) || (\exists integer  x659; ((((x651<=x659) &&
(x659<=x600)) &&
star_C(x598,x651,x659)) &&
(((x659==x600) || (('D'==x598[x659]) &&
(x600>=(x659+1)))) || (\exists integer  x672; ((((x659<=x672) &&
(x672<=x600)) &&
(('D'==x598[x659]) &&
(x672==(x659+1)))) &&
(star_starting_D(x598,x672,x600) || (\exists integer  x680; ((((x672<=x680) &&
(x680<=x600)) &&
star_D(x598,x672,x680)) &&
(x600>=x680)))))))))))))))))))))))));*/
/*@
requires (((strlen(x877)>=0) &&
\valid(x877+(0..strlen(x877)))) &&
(strlen(x877)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x877,0,strlen(x877)));
*/
int dfa(char  * x877) {
  int x879 = 1/*true*/;
  int x880 = 0;
  //@ ghost int x881 = 0;
  char  *x882 = x877;
  /*@
  loop invariant (((((((((strlen(x877)>=0) &&
  \valid(x877+(0..strlen(x877)))) &&
  ((0<=x881) &&
  (x881<=strlen(x877)))) &&
  (x882==(x877+x881))) &&
  ((strlen((x877+x881))>=0) &&
  \valid((x877+x881)+(0..strlen((x877+x881)))))) &&
  (x879 ==> (((x880==4) ==> re_bwd_4(x877,0,x881)) &&
  (((x880==3) ==> re_bwd_3(x877,0,x881)) &&
  (((x880==2) ==> re_bwd_2(x877,0,x881)) &&
  (((x880==1) ==> re_bwd_1(x877,0,x881)) &&
  ((x880==0) ==> re_bwd_0(x877,0,x881)))))))) &&
  (x879 ==> re0(x877,0,x881))) &&
  ((x880==4) ==> (re_bwd_4(x877,0,x881) ==> re_0(x877,0,x881)))) &&
  ((x880==4) || ((x880==3) || ((x880==2) || ((x880==1) || (x880==0))))));
  loop assigns x882, x881, x880, x879;
  loop variant strlen(x882);
  */
  for (;;) {
    char  *x884 = x882;
    char x885 = x884[0];
    int x886 = x885 == '\0';
    int x890;
    if (x886) {
      x890 = 0/*false*/;
    } else {
      int x888 = x879;
      x890 = x888;
    }
    if (!x890) break;
    /*@assert (x879 ==> (((x880==4) ==> re_bwd_4(x877,0,x881)) &&
    (((x880==3) ==> re_bwd_3(x877,0,x881)) &&
    (((x880==2) ==> re_bwd_2(x877,0,x881)) &&
    (((x880==1) ==> re_bwd_1(x877,0,x881)) &&
    ((x880==0) ==> re_bwd_0(x877,0,x881)))))));*/
    /*@assert (((x880==4) ==> re_bwd_4(x877,0,x881)) &&
    (((x880==3) ==> re_bwd_3(x877,0,x881)) &&
    (((x880==2) ==> re_bwd_2(x877,0,x881)) &&
    (((x880==1) ==> re_bwd_1(x877,0,x881)) &&
    ((x880==0) ==> re_bwd_0(x877,0,x881))))));*/
    char  *x942 = x882;
    int x944 = x880;
    int x945 = x944 == 4;
    int x1160;
    if (x945) {
      char x943 = x942[0];
      int x946 = 'D' == x943;
      int x967;
      if (x946) {
        /*@assert re_bwd_4(x877,0,(x881+1));*/
        x880 = 4;
        /*@assert re_bwd_4(x877,0,(x881+1));*/
        /*@assert ((x880==4) ==> re_bwd_4(x877,0,(x881+1)));*/
        x967 = 1/*true*/;
      } else {
        x967 = 0/*false*/;
      }
      x1160 = x967;
    } else {
      int x969 = x944 == 3;
      int x1158;
      if (x969) {
        char x943 = x942[0];
        int x946 = 'D' == x943;
        int x1036;
        if (x946) {
          /*@assert re_bwd_4(x877,0,(x881+1));*/
          x880 = 4;
          /*@assert re_bwd_4(x877,0,(x881+1));*/
          /*@assert ((x880==4) ==> re_bwd_4(x877,0,(x881+1)));*/
          x1036 = 1/*true*/;
        } else {
          int x990 = 'C' == x943;
          int x1034;
          if (x990) {
            /*@assert re_bwd_3(x877,0,(x881+1));*/
            x880 = 3;
            /*@assert re_bwd_3(x877,0,(x881+1));*/
            /*@assert ((x880==3) ==> re_bwd_3(x877,0,(x881+1)));*/
            x1034 = 1/*true*/;
          } else {
            int x1011 = 'B' == x943;
            int x1032;
            if (x1011) {
              /*@assert re_bwd_2(x877,0,(x881+1));*/
              x880 = 2;
              /*@assert re_bwd_2(x877,0,(x881+1));*/
              /*@assert ((x880==2) ==> re_bwd_2(x877,0,(x881+1)));*/
              x1032 = 1/*true*/;
            } else {
              x1032 = 0/*false*/;
            }
            x1034 = x1032;
          }
          x1036 = x1034;
        }
        x1158 = x1036;
      } else {
        int x1038 = x944 == 2;
        int x1156;
        if (x1038) {
          char x943 = x942[0];
          int x990 = 'C' == x943;
          int x1081;
          if (x990) {
            /*@assert re_bwd_3(x877,0,(x881+1));*/
            x880 = 3;
            /*@assert re_bwd_3(x877,0,(x881+1));*/
            /*@assert ((x880==3) ==> re_bwd_3(x877,0,(x881+1)));*/
            x1081 = 1/*true*/;
          } else {
            int x1011 = 'B' == x943;
            int x1079;
            if (x1011) {
              /*@assert re_bwd_2(x877,0,(x881+1));*/
              x880 = 2;
              /*@assert re_bwd_2(x877,0,(x881+1));*/
              /*@assert ((x880==2) ==> re_bwd_2(x877,0,(x881+1)));*/
              x1079 = 1/*true*/;
            } else {
              x1079 = 0/*false*/;
            }
            x1081 = x1079;
          }
          x1156 = x1081;
        } else {
          int x1083 = x944 == 1;
          int x1154;
          if (x1083) {
            char x943 = x942[0];
            int x1011 = 'B' == x943;
            int x1127;
            if (x1011) {
              /*@assert re_bwd_2(x877,0,(x881+1));*/
              x880 = 2;
              /*@assert re_bwd_2(x877,0,(x881+1));*/
              /*@assert ((x880==2) ==> re_bwd_2(x877,0,(x881+1)));*/
              x1127 = 1/*true*/;
            } else {
              int x1104 = 'A' == x943;
              int x1125;
              if (x1104) {
                /*@assert re_bwd_1(x877,0,(x881+1));*/
                x880 = 1;
                /*@assert re_bwd_1(x877,0,(x881+1));*/
                /*@assert ((x880==1) ==> re_bwd_1(x877,0,(x881+1)));*/
                x1125 = 1/*true*/;
              } else {
                x1125 = 0/*false*/;
              }
              x1127 = x1125;
            }
            x1154 = x1127;
          } else {
            int x1129 = x944 == 0;
            int x1152;
            if (x1129) {
              char x943 = x942[0];
              int x1104 = 'A' == x943;
              int x1150;
              if (x1104) {
                /*@assert re_bwd_1(x877,0,(x881+1));*/
                x880 = 1;
                /*@assert re_bwd_1(x877,0,(x881+1));*/
                /*@assert ((x880==1) ==> re_bwd_1(x877,0,(x881+1)));*/
                x1150 = 1/*true*/;
              } else {
                x1150 = 0/*false*/;
              }
              x1152 = x1150;
            } else {
              x1152 = 0/*false*/;
            }
            x1154 = x1152;
          }
          x1156 = x1154;
        }
        x1158 = x1156;
      }
      x1160 = x1158;
    }
    x879 = x1160;
    /*@assert (x879 ==> (((x880==4) ==> re_bwd_4(x877,0,(x881+1))) &&
    (((x880==3) ==> re_bwd_3(x877,0,(x881+1))) &&
    (((x880==2) ==> re_bwd_2(x877,0,(x881+1))) &&
    (((x880==1) ==> re_bwd_1(x877,0,(x881+1))) &&
    ((x880==0) ==> re_bwd_0(x877,0,(x881+1))))))));*/
    //@ ghost int x1189 = x881;
    //@ ghost int x1190 = x1189 + 1;
    //@ ghost x881 = x1190;
    char  *x1192 = x942+1;
    x882 = x1192;
    /*@assert (x879 ==> (((x880==4) ==> re_bwd_4(x877,0,x881)) &&
    (((x880==3) ==> re_bwd_3(x877,0,x881)) &&
    (((x880==2) ==> re_bwd_2(x877,0,x881)) &&
    (((x880==1) ==> re_bwd_1(x877,0,x881)) &&
    ((x880==0) ==> re_bwd_0(x877,0,x881)))))));*/
  }
  int x1312 = x880;
  char  *x1313 = x882;
  char x1314 = x1313[0];
  int x1315 = x1314 == '\0';
  int x1318;
  if (x1315) {
    int x1316 = x879;
    x1318 = x1316;
  } else {
    x1318 = 0/*false*/;
  }
  int x1320;
  if (x1318) {
    int x1319 = 4 == x1312;
    x1320 = x1319;
  } else {
    x1320 = 0/*false*/;
  }
  return x1320;
}
