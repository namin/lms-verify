#include <limits.h>
#include <string.h>
/*@ predicate star_A(char  * x121, integer  x122, integer  x123) = (\exists integer  x125; ((((x122<x125) &&
(x125<=x123)) ==> ((('A'==x121[x122]) &&
(x125==(x122+1))) &&
star_A(x121,x125,x123))) || (x122==x123)));*/
/*@ predicate star_D(char  * x144, integer  x145, integer  x146) = (\exists integer  x148; ((((x145<x148) &&
(x148<=x146)) ==> ((('D'==x144[x145]) &&
(x148==(x145+1))) &&
star_D(x144,x148,x146))) || (x145==x146)));*/
/*@ predicate star_C(char  * x167, integer  x168, integer  x169) = (\exists integer  x171; ((((x168<x171) &&
(x171<=x169)) ==> ((('C'==x167[x168]) &&
(x171==(x168+1))) &&
star_C(x167,x171,x169))) || (x168==x169)));*/
/*@ predicate star__orB_or_C_sCs_Bor_(char  * x190, integer  x191, integer  x192) = (\exists integer  x194; ((((x191<x194) &&
(x194<=x192)) ==> (((('B'==x190[x191]) &&
(x194==(x191+1))) || (\exists integer  x205; ((((x191<=x205) &&
(x205<=x194)) &&
(('C'==x190[x191]) &&
(x205==(x191+1)))) &&
(\exists integer  x218; ((((x205<=x218) &&
(x218<=x194)) &&
star_C(x190,x205,x218)) &&
(('B'==x190[x218]) &&
(x194==(x218+1)))))))) &&
star__orB_or_C_sCs_Bor_(x190,x194,x192))) || (x191==x192)));*/
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
(\exists integer  x38; ((((x25<=x38) &&
(x38<=x2)) &&
star__orB_or_C_sCs_Bor_(x0,x25,x38)) &&
(\exists integer  x46; ((((x38<=x46) &&
(x46<=x2)) &&
(('C'==x0[x38]) &&
(x46==(x38+1)))) &&
(\exists integer  x59; ((((x46<=x59) &&
(x59<=x2)) &&
star_C(x0,x46,x59)) &&
(\exists integer  x67; ((((x59<=x67) &&
(x67<=x2)) &&
(('D'==x0[x59]) &&
(x67==(x59+1)))) &&
(\exists integer  x80; ((((x67<=x80) &&
(x80<=x2)) &&
star_D(x0,x67,x80)) &&
(x80==x2)))))))))))))))));*/
/*@ predicate re_1(char  * x248, integer  x249, integer  x250) = (\exists integer  x252; ((((x249<=x252) &&
(x252<=x250)) &&
star_A(x248,x249,x252)) &&
(\exists integer  x259; ((((x252<=x259) &&
(x259<=x250)) &&
(('B'==x248[x252]) &&
(x259==(x252+1)))) &&
(\exists integer  x272; ((((x259<=x272) &&
(x272<=x250)) &&
star__orB_or_C_sCs_Bor_(x248,x259,x272)) &&
(\exists integer  x279; ((((x272<=x279) &&
(x279<=x250)) &&
(('C'==x248[x272]) &&
(x279==(x272+1)))) &&
(\exists integer  x292; ((((x279<=x292) &&
(x292<=x250)) &&
star_C(x248,x279,x292)) &&
(\exists integer  x299; ((((x292<=x299) &&
(x299<=x250)) &&
(('D'==x248[x292]) &&
(x299==(x292+1)))) &&
(\exists integer  x312; ((((x299<=x312) &&
(x312<=x250)) &&
star_D(x248,x299,x312)) &&
(x312==x250)))))))))))))));*/
/*@ predicate re_2(char  * x348, integer  x349, integer  x350) = (\exists integer  x352; ((((x349<=x352) &&
(x352<=x350)) &&
star__orB_or_C_sCs_Bor_(x348,x349,x352)) &&
(\exists integer  x359; ((((x352<=x359) &&
(x359<=x350)) &&
(('C'==x348[x352]) &&
(x359==(x352+1)))) &&
(\exists integer  x372; ((((x359<=x372) &&
(x372<=x350)) &&
star_C(x348,x359,x372)) &&
(\exists integer  x379; ((((x372<=x379) &&
(x379<=x350)) &&
(('D'==x348[x372]) &&
(x379==(x372+1)))) &&
(\exists integer  x392; ((((x379<=x392) &&
(x392<=x350)) &&
star_D(x348,x379,x392)) &&
(x392==x350)))))))))));*/
/*@ predicate re_3(char  * x420, integer  x421, integer  x422) = (\exists integer  x424; ((((x421<=x424) &&
(x424<=x422)) &&
star_C(x420,x421,x424)) &&
(\exists integer  x431; ((((x424<=x431) &&
(x431<=x422)) &&
(('D'==x420[x424]) &&
(x431==(x424+1)))) &&
(\exists integer  x444; ((((x431<=x444) &&
(x444<=x422)) &&
star_D(x420,x431,x444)) &&
(x444==x422)))))));*/
/*@ predicate re_4(char  * x464, integer  x465, integer  x466) = (\exists integer  x468; ((((x465<=x468) &&
(x468<=x466)) &&
star_D(x464,x465,x468)) &&
(x468==x466)));*/
/*@ predicate re_bwd_0(char  * x480, integer  x481, integer  x482) = (x481==x482);*/
/*@ predicate re_bwd_1(char  * x485, integer  x486, integer  x487) = (\exists integer  x489; ((((x486<=x489) &&
(x489<=x487)) &&
(('A'==x485[x486]) &&
(x489==(x486+1)))) &&
(\exists integer  x502; ((((x489<=x502) &&
(x502<=x487)) &&
star_A(x485,x489,x502)) &&
(x502==x487)))));*/
/*@ predicate re_bwd_2(char  * x518, integer  x519, integer  x520) = (\exists integer  x522; ((((x519<=x522) &&
(x522<=x520)) &&
(('A'==x518[x519]) &&
(x522==(x519+1)))) &&
(\exists integer  x535; ((((x522<=x535) &&
(x535<=x520)) &&
star_A(x518,x522,x535)) &&
(\exists integer  x542; ((((x535<=x542) &&
(x542<=x520)) &&
(('B'==x518[x535]) &&
(x542==(x535+1)))) &&
(\exists integer  x555; ((((x542<=x555) &&
(x555<=x520)) &&
star__orB_or_C_sCs_Bor_(x518,x542,x555)) &&
(x555==x520)))))))));*/
/*@ predicate re_bwd_3(char  * x579, integer  x580, integer  x581) = (\exists integer  x583; ((((x580<=x583) &&
(x583<=x581)) &&
(('A'==x579[x580]) &&
(x583==(x580+1)))) &&
(\exists integer  x596; ((((x583<=x596) &&
(x596<=x581)) &&
star_A(x579,x583,x596)) &&
(\exists integer  x603; ((((x596<=x603) &&
(x603<=x581)) &&
(('B'==x579[x596]) &&
(x603==(x596+1)))) &&
(\exists integer  x616; ((((x603<=x616) &&
(x616<=x581)) &&
star__orB_or_C_sCs_Bor_(x579,x603,x616)) &&
(\exists integer  x623; ((((x616<=x623) &&
(x623<=x581)) &&
(('C'==x579[x616]) &&
(x623==(x616+1)))) &&
(\exists integer  x636; ((((x623<=x636) &&
(x636<=x581)) &&
star_C(x579,x623,x636)) &&
(x636==x581)))))))))))));*/
/*@ predicate re_bwd_4(char  * x668, integer  x669, integer  x670) = (\exists integer  x672; ((((x669<=x672) &&
(x672<=x670)) &&
(('A'==x668[x669]) &&
(x672==(x669+1)))) &&
(\exists integer  x685; ((((x672<=x685) &&
(x685<=x670)) &&
star_A(x668,x672,x685)) &&
(\exists integer  x692; ((((x685<=x692) &&
(x692<=x670)) &&
(('B'==x668[x685]) &&
(x692==(x685+1)))) &&
(\exists integer  x705; ((((x692<=x705) &&
(x705<=x670)) &&
star__orB_or_C_sCs_Bor_(x668,x692,x705)) &&
(\exists integer  x712; ((((x705<=x712) &&
(x712<=x670)) &&
(('C'==x668[x705]) &&
(x712==(x705+1)))) &&
(\exists integer  x725; ((((x712<=x725) &&
(x725<=x670)) &&
star_C(x668,x712,x725)) &&
(\exists integer  x732; ((((x725<=x732) &&
(x732<=x670)) &&
(('D'==x668[x725]) &&
(x732==(x725+1)))) &&
(\exists integer  x745; ((((x732<=x745) &&
(x745<=x670)) &&
star_D(x668,x732,x745)) &&
(x745==x670)))))))))))))))));*/
/*@ predicate star_starting_D(char  * x945, integer  x946, integer  x947) = ((((x946==x947) || (('D'==x945[x946]) &&
(x947>=(x946+1)))) || (\exists integer  x956; (((x946<x956) &&
(x956<=x947)) ==> ((('D'==x945[x946]) &&
(x956==(x946+1))) &&
star_starting_D(x945,x956,x947))))) || (x947>=x946));*/
/*@ predicate star_starting_A(char  * x976, integer  x977, integer  x978) = ((((x977==x978) || (('A'==x976[x977]) &&
(x978>=(x977+1)))) || (\exists integer  x987; (((x977<x987) &&
(x987<=x978)) ==> ((('A'==x976[x977]) &&
(x987==(x977+1))) &&
star_starting_A(x976,x987,x978))))) || (x978>=x977));*/
/*@ predicate star_starting_C(char  * x1007, integer  x1008, integer  x1009) = ((((x1008==x1009) || (('C'==x1007[x1008]) &&
(x1009>=(x1008+1)))) || (\exists integer  x1018; (((x1008<x1018) &&
(x1018<=x1009)) ==> ((('C'==x1007[x1008]) &&
(x1018==(x1008+1))) &&
star_starting_C(x1007,x1018,x1009))))) || (x1009>=x1008));*/
/*@ predicate star_starting__orB_or_C_sCs_Bor_(char  * x1038, integer  x1039, integer  x1040) = (((((x1039==x1040) || (('B'==x1038[x1039]) &&
(x1040>=(x1039+1)))) || (((x1039==x1040) || (('C'==x1038[x1039]) &&
(x1040>=(x1039+1)))) || (\exists integer  x1052; ((((x1039<=x1052) &&
(x1052<=x1040)) &&
(('C'==x1038[x1039]) &&
(x1052==(x1039+1)))) &&
(star_starting_C(x1038,x1052,x1040) || (\exists integer  x1066; ((((x1052<=x1066) &&
(x1066<=x1040)) &&
star_C(x1038,x1052,x1066)) &&
((x1066==x1040) || (('B'==x1038[x1066]) &&
(x1040>=(x1066+1))))))))))) || (\exists integer  x1092; (((x1039<x1092) &&
(x1092<=x1040)) ==> (((('B'==x1038[x1039]) &&
(x1092==(x1039+1))) || (\exists integer  x1103; ((((x1039<=x1103) &&
(x1103<=x1092)) &&
(('C'==x1038[x1039]) &&
(x1103==(x1039+1)))) &&
(\exists integer  x1116; ((((x1103<=x1116) &&
(x1116<=x1092)) &&
star_C(x1038,x1103,x1116)) &&
(('B'==x1038[x1116]) &&
(x1092==(x1116+1)))))))) &&
star_starting__orB_or_C_sCs_Bor_(x1038,x1092,x1040))))) || (x1040>=x1039));*/
/*@ predicate re0(char  * x785, integer  x786, integer  x787) = (((x786==x787) || (('A'==x785[x786]) &&
(x787>=(x786+1)))) || (\exists integer  x796; ((((x786<=x796) &&
(x796<=x787)) &&
(('A'==x785[x786]) &&
(x796==(x786+1)))) &&
(star_starting_A(x785,x796,x787) || (\exists integer  x810; ((((x796<=x810) &&
(x810<=x787)) &&
star_A(x785,x796,x810)) &&
(((x810==x787) || (('B'==x785[x810]) &&
(x787>=(x810+1)))) || (\exists integer  x825; ((((x810<=x825) &&
(x825<=x787)) &&
(('B'==x785[x810]) &&
(x825==(x810+1)))) &&
(star_starting__orB_or_C_sCs_Bor_(x785,x825,x787) || (\exists integer  x839; ((((x825<=x839) &&
(x839<=x787)) &&
star__orB_or_C_sCs_Bor_(x785,x825,x839)) &&
(((x839==x787) || (('C'==x785[x839]) &&
(x787>=(x839+1)))) || (\exists integer  x854; ((((x839<=x854) &&
(x854<=x787)) &&
(('C'==x785[x839]) &&
(x854==(x839+1)))) &&
(star_starting_C(x785,x854,x787) || (\exists integer  x868; ((((x854<=x868) &&
(x868<=x787)) &&
star_C(x785,x854,x868)) &&
(((x868==x787) || (('D'==x785[x868]) &&
(x787>=(x868+1)))) || (\exists integer  x883; ((((x868<=x883) &&
(x883<=x787)) &&
(('D'==x785[x868]) &&
(x883==(x868+1)))) &&
(star_starting_D(x785,x883,x787) || (\exists integer  x897; ((((x883<=x897) &&
(x897<=x787)) &&
star_D(x785,x883,x897)) &&
(x787>=x897)))))))))))))))))))))))));*/
/*@
requires (((strlen(x1147)>=0) &&
\valid(x1147+(0..(strlen(x1147)+1)-1))) &&
(strlen(x1147)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x1147,0,strlen(x1147)));
*/
int dfa(char  * x1147) {
  int x1149 = 1/*true*/;
  int x1150 = 0;
  //@ ghost int x1151 = 0;
  char  *x1152 = x1147;
  /*@
  loop invariant ((((((((strlen(x1147)>=0) &&
  \valid(x1147+(0..(strlen(x1147)+1)-1))) &&
  ((0<=x1151) &&
  (x1151<=strlen(x1147)))) &&
  (x1152==(x1147+x1151))) &&
  ((strlen((x1147+x1151))>=0) &&
  \valid((x1147+x1151)+(0..(strlen((x1147+x1151))+1)-1)))) &&
  (x1149 ==> (((x1150==4) ==> re_bwd_4(x1147,0,x1151)) &&
  (((x1150==3) ==> re_bwd_3(x1147,0,x1151)) &&
  (((x1150==2) ==> re_bwd_2(x1147,0,x1151)) &&
  (((x1150==1) ==> re_bwd_1(x1147,0,x1151)) &&
  ((x1150==0) ==> re_bwd_0(x1147,0,x1151)))))))) &&
  ((x1150==4) ==> (re_bwd_4(x1147,0,x1151) ==> re_0(x1147,0,x1151)))) &&
  ((x1150==4) || ((x1150==3) || ((x1150==2) || ((x1150==1) || (x1150==0))))));
  loop assigns x1152, x1151, x1150, x1149;
  loop variant strlen(x1152);
  */
  for (;;) {
    char  *x1154 = x1152;
    char x1155 = x1154[0];
    int x1156 = x1155 == '\0';
    int x1160;
    if (x1156) {
      x1160 = 0/*false*/;
    } else {
      int x1158 = x1149;
      x1160 = x1158;
    }
    if (!x1160) break;
    char  *x1162 = x1152;
    int x1164 = x1150;
    int x1165 = x1164 == 0;
    int x1171;
    if (x1165) {
      char x1163 = x1162[0];
      int x1166 = 'A' == x1163;
      int x1169;
      if (x1166) {
        x1150 = 1;
        x1169 = 1/*true*/;
      } else {
        x1169 = 0/*false*/;
      }
      x1171 = x1169;
    } else {
      x1171 = 0/*false*/;
    }
    int x1172 = x1150;
    int x1173 = x1172 == 1;
    int x1182;
    if (x1173) {
      char x1163 = x1162[0];
      int x1166 = 'A' == x1163;
      int x1176;
      if (x1166) {
        x1150 = 1;
        x1176 = 1/*true*/;
      } else {
        x1176 = 0/*false*/;
      }
      int x1177 = 'B' == x1163;
      int x1180;
      if (x1177) {
        x1150 = 2;
        x1180 = 1/*true*/;
      } else {
        x1180 = x1176;
      }
      x1182 = x1180;
    } else {
      x1182 = x1171;
    }
    int x1183 = x1150;
    int x1184 = x1183 == 2;
    int x1193;
    if (x1184) {
      char x1163 = x1162[0];
      int x1177 = 'B' == x1163;
      int x1187;
      if (x1177) {
        x1150 = 2;
        x1187 = 1/*true*/;
      } else {
        x1187 = 0/*false*/;
      }
      int x1188 = 'C' == x1163;
      int x1191;
      if (x1188) {
        x1150 = 3;
        x1191 = 1/*true*/;
      } else {
        x1191 = x1187;
      }
      x1193 = x1191;
    } else {
      x1193 = x1182;
    }
    int x1194 = x1150;
    int x1195 = x1194 == 3;
    int x1207;
    if (x1195) {
      char x1163 = x1162[0];
      int x1177 = 'B' == x1163;
      int x1198;
      if (x1177) {
        x1150 = 2;
        x1198 = 1/*true*/;
      } else {
        x1198 = 0/*false*/;
      }
      int x1188 = 'C' == x1163;
      int x1201;
      if (x1188) {
        x1150 = 3;
        x1201 = 1/*true*/;
      } else {
        x1201 = x1198;
      }
      int x1202 = 'D' == x1163;
      int x1205;
      if (x1202) {
        x1150 = 4;
        x1205 = 1/*true*/;
      } else {
        x1205 = x1201;
      }
      x1207 = x1205;
    } else {
      x1207 = x1193;
    }
    int x1208 = x1150;
    int x1209 = x1208 == 4;
    int x1214;
    if (x1209) {
      char x1163 = x1162[0];
      int x1202 = 'D' == x1163;
      int x1212;
      if (x1202) {
        x1150 = 4;
        x1212 = 1/*true*/;
      } else {
        x1212 = 0/*false*/;
      }
      x1214 = x1212;
    } else {
      x1214 = x1207;
    }
    x1149 = x1214;
    //@ ghost int x1216 = x1151;
    //@ ghost int x1217 = x1216 + 1;
    //@ ghost x1151 = x1217;
    char  *x1219 = x1162+1;
    x1152 = x1219;
  }
  int x1318 = x1150;
  char  *x1319 = x1152;
  char x1320 = x1319[0];
  int x1321 = x1320 == '\0';
  int x1324;
  if (x1321) {
    int x1322 = x1149;
    x1324 = x1322;
  } else {
    x1324 = 0/*false*/;
  }
  int x1326;
  if (x1324) {
    int x1325 = 4 == x1318;
    x1326 = x1325;
  } else {
    x1326 = 0/*false*/;
  }
  return x1326;
}
