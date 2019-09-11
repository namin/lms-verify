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
/*@
requires (((strlen(x785)>=0) &&
\valid(x785+(0..(strlen(x785)+1)-1))) &&
(strlen(x785)<=INT_MAX));
assigns \nothing;
ensures (\result ==> re_0(x785,0,strlen(x785)));
*/
int dfa(char  * x785) {
  int x787 = 1/*true*/;
  int x788 = 0;
  int x789 = 0;
  int x790 = strlen(x785);
  /*@
  loop invariant (((((((strlen(x785)>=0) &&
  \valid(x785+(0..(strlen(x785)+1)-1))) &&
  ((0<=x789) &&
  (x789<=x790))) &&
  ((strlen((x785+x789))>=0) &&
  \valid((x785+x789)+(0..(strlen((x785+x789))+1)-1)))) &&
  (x787 ==> (((x788==4) ==> re_bwd_4(x785,0,x789)) &&
  (((x788==3) ==> re_bwd_3(x785,0,x789)) &&
  (((x788==2) ==> re_bwd_2(x785,0,x789)) &&
  (((x788==1) ==> re_bwd_1(x785,0,x789)) &&
  ((x788==0) ==> re_bwd_0(x785,0,x789)))))))) &&
  ((x788==4) ==> (re_bwd_4(x785,0,x789) ==> re_0(x785,0,x789)))) &&
  ((x788==4) || ((x788==3) || ((x788==2) || ((x788==1) || (x788==0))))));
  loop assigns x789, x788, x787;
  loop variant (x790-x789);
  */
  for (;;) {
    int x791 = x789;
    int x792 = x791 < x790;
    int x795;
    if (x792) {
      int x793 = x787;
      x795 = x793;
    } else {
      x795 = 0/*false*/;
    }
    if (!x795) break;
    int x797 = x789;
    char x798 = x785[x797];
    char x799 = x798;
    x787 = 0/*false*/;
    int x801 = x787;
    int x806;
    if (x801) {
      x806 = 0/*false*/;
    } else {
      int x803 = x788;
      int x804 = x803 == 0;
      x806 = x804;
    }
    if (x806) {
      /*@assert ((x788==0) ==> re_bwd_0(x785,0,x789));*/
      /*@assert re_bwd_0(x785,0,x789);*/
      char x818 = x799;
      int x819 = 'A' == x818;
      if (x819) {
        /*@assert re_bwd_1(x785,0,(x789+1));*/
        x788 = 1;
        x787 = 1/*true*/;
        /*@assert re_bwd_1(x785,0,(x789+1));*/
        /*@assert ((x788==1) ==> re_bwd_1(x785,0,(x789+1)));*/
      } else {
      }
    } else {
    }
    int x844 = x787;
    int x849;
    if (x844) {
      x849 = 0/*false*/;
    } else {
      int x846 = x788;
      int x847 = x846 == 1;
      x849 = x847;
    }
    if (x849) {
      /*@assert ((x788==1) ==> re_bwd_1(x785,0,x789));*/
      /*@assert re_bwd_1(x785,0,x789);*/
      char x861 = x799;
      int x862 = 'A' == x861;
      if (x862) {
        /*@assert re_bwd_1(x785,0,(x789+1));*/
        x788 = 1;
        x787 = 1/*true*/;
        /*@assert re_bwd_1(x785,0,(x789+1));*/
        /*@assert ((x788==1) ==> re_bwd_1(x785,0,(x789+1)));*/
      } else {
      }
      int x885 = 'B' == x861;
      if (x885) {
        /*@assert re_bwd_2(x785,0,(x789+1));*/
        x788 = 2;
        x787 = 1/*true*/;
        /*@assert re_bwd_2(x785,0,(x789+1));*/
        /*@assert ((x788==2) ==> re_bwd_2(x785,0,(x789+1)));*/
      } else {
      }
    } else {
    }
    int x910 = x787;
    int x915;
    if (x910) {
      x915 = 0/*false*/;
    } else {
      int x912 = x788;
      int x913 = x912 == 2;
      x915 = x913;
    }
    if (x915) {
      /*@assert ((x788==2) ==> re_bwd_2(x785,0,x789));*/
      /*@assert re_bwd_2(x785,0,x789);*/
      char x927 = x799;
      int x928 = 'B' == x927;
      if (x928) {
        /*@assert re_bwd_2(x785,0,(x789+1));*/
        x788 = 2;
        x787 = 1/*true*/;
        /*@assert re_bwd_2(x785,0,(x789+1));*/
        /*@assert ((x788==2) ==> re_bwd_2(x785,0,(x789+1)));*/
      } else {
      }
      int x951 = 'C' == x927;
      if (x951) {
        /*@assert re_bwd_3(x785,0,(x789+1));*/
        x788 = 3;
        x787 = 1/*true*/;
        /*@assert re_bwd_3(x785,0,(x789+1));*/
        /*@assert ((x788==3) ==> re_bwd_3(x785,0,(x789+1)));*/
      } else {
      }
    } else {
    }
    int x976 = x787;
    int x981;
    if (x976) {
      x981 = 0/*false*/;
    } else {
      int x978 = x788;
      int x979 = x978 == 3;
      x981 = x979;
    }
    if (x981) {
      /*@assert ((x788==3) ==> re_bwd_3(x785,0,x789));*/
      /*@assert re_bwd_3(x785,0,x789);*/
      char x993 = x799;
      int x994 = 'B' == x993;
      if (x994) {
        /*@assert re_bwd_2(x785,0,(x789+1));*/
        x788 = 2;
        x787 = 1/*true*/;
        /*@assert re_bwd_2(x785,0,(x789+1));*/
        /*@assert ((x788==2) ==> re_bwd_2(x785,0,(x789+1)));*/
      } else {
      }
      int x1017 = 'C' == x993;
      if (x1017) {
        /*@assert re_bwd_3(x785,0,(x789+1));*/
        x788 = 3;
        x787 = 1/*true*/;
        /*@assert re_bwd_3(x785,0,(x789+1));*/
        /*@assert ((x788==3) ==> re_bwd_3(x785,0,(x789+1)));*/
      } else {
      }
      int x1040 = 'D' == x993;
      if (x1040) {
        /*@assert re_bwd_4(x785,0,(x789+1));*/
        x788 = 4;
        x787 = 1/*true*/;
        /*@assert re_bwd_4(x785,0,(x789+1));*/
        /*@assert ((x788==4) ==> re_bwd_4(x785,0,(x789+1)));*/
      } else {
      }
    } else {
    }
    int x1065 = x787;
    int x1070;
    if (x1065) {
      x1070 = 0/*false*/;
    } else {
      int x1067 = x788;
      int x1068 = x1067 == 4;
      x1070 = x1068;
    }
    if (x1070) {
      /*@assert ((x788==4) ==> re_bwd_4(x785,0,x789));*/
      /*@assert re_bwd_4(x785,0,x789);*/
      char x1082 = x799;
      int x1083 = 'D' == x1082;
      if (x1083) {
        /*@assert re_bwd_4(x785,0,(x789+1));*/
        x788 = 4;
        x787 = 1/*true*/;
        /*@assert re_bwd_4(x785,0,(x789+1));*/
        /*@assert ((x788==4) ==> re_bwd_4(x785,0,(x789+1)));*/
      } else {
      }
    } else {
    }
    /*@assert (x787 ==> (((x788==4) ==> re_bwd_4(x785,0,(x789+1))) &&
    (((x788==3) ==> re_bwd_3(x785,0,(x789+1))) &&
    (((x788==2) ==> re_bwd_2(x785,0,(x789+1))) &&
    (((x788==1) ==> re_bwd_1(x785,0,(x789+1))) &&
    ((x788==0) ==> re_bwd_0(x785,0,(x789+1))))))));*/
    int x1135 = x797 + 1;
    x789 = x1135;
    /*@assert (x787 ==> (((x788==4) ==> re_bwd_4(x785,0,x789)) &&
    (((x788==3) ==> re_bwd_3(x785,0,x789)) &&
    (((x788==2) ==> re_bwd_2(x785,0,x789)) &&
    (((x788==1) ==> re_bwd_1(x785,0,x789)) &&
    ((x788==0) ==> re_bwd_0(x785,0,x789)))))));*/
  }
  int x1253 = x788;
  int x1254 = x789;
  int x1255 = x1254 == x790;
  int x1258;
  if (x1255) {
    int x1256 = x787;
    x1258 = x1256;
  } else {
    x1258 = 0/*false*/;
  }
  int x1260;
  if (x1258) {
    int x1259 = 4 == x1253;
    x1260 = x1259;
  } else {
    x1260 = 0/*false*/;
  }
  return x1260;
}
