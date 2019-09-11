#include <limits.h>
#include <string.h>
/*@ predicate star_A(char  * x121, integer  x122, integer  x123) = (\exists integer  x125; ((((x122<x125) &&
(x125<=x123)) ==> ((('A'==x121[x122]) &&
(x125==(x122+1))) &&
star_A(x121,x125,x123))) || (x122==x123)));*/
/*@ predicate star__orB_or_C_sCs_Bor_(char  * x144, integer  x145, integer  x146) = (\exists integer  x148; ((((x145<x148) &&
(x148<=x146)) ==> (((('B'==x144[x145]) &&
(x148==(x145+1))) || (\exists integer  x159; ((((x145<=x159) &&
(x159<=x148)) &&
(('C'==x144[x145]) &&
(x159==(x145+1)))) &&
(\exists integer  x172; ((((x159<=x172) &&
(x172<=x148)) &&
star_C(x144,x159,x172)) &&
(('B'==x144[x172]) &&
(x148==(x172+1)))))))) &&
star__orB_or_C_sCs_Bor_(x144,x148,x146))) || (x145==x146)));*/
/*@ predicate star_D(char  * x203, integer  x204, integer  x205) = (\exists integer  x207; ((((x204<x207) &&
(x207<=x205)) ==> ((('D'==x203[x204]) &&
(x207==(x204+1))) &&
star_D(x203,x207,x205))) || (x204==x205)));*/
/*@ predicate star_C(char  * x226, integer  x227, integer  x228) = (\exists integer  x230; ((((x227<x230) &&
(x230<=x228)) ==> ((('C'==x226[x227]) &&
(x230==(x227+1))) &&
star_C(x226,x230,x228))) || (x227==x228)));*/
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
/*@ predicate re_1(char  * x249, integer  x250, integer  x251) = (\exists integer  x253; ((((x250<=x253) &&
(x253<=x251)) &&
star_A(x249,x250,x253)) &&
(\exists integer  x260; ((((x253<=x260) &&
(x260<=x251)) &&
(('B'==x249[x253]) &&
(x260==(x253+1)))) &&
(\exists integer  x273; ((((x260<=x273) &&
(x273<=x251)) &&
star__orB_or_C_sCs_Bor_(x249,x260,x273)) &&
(\exists integer  x280; ((((x273<=x280) &&
(x280<=x251)) &&
(('C'==x249[x273]) &&
(x280==(x273+1)))) &&
(\exists integer  x293; ((((x280<=x293) &&
(x293<=x251)) &&
star_C(x249,x280,x293)) &&
(\exists integer  x300; ((((x293<=x300) &&
(x300<=x251)) &&
(('D'==x249[x293]) &&
(x300==(x293+1)))) &&
(\exists integer  x313; ((((x300<=x313) &&
(x313<=x251)) &&
star_D(x249,x300,x313)) &&
(x313==x251)))))))))))))));*/
/*@ predicate re_2(char  * x349, integer  x350, integer  x351) = (\exists integer  x353; ((((x350<=x353) &&
(x353<=x351)) &&
star__orB_or_C_sCs_Bor_(x349,x350,x353)) &&
(\exists integer  x360; ((((x353<=x360) &&
(x360<=x351)) &&
(('C'==x349[x353]) &&
(x360==(x353+1)))) &&
(\exists integer  x373; ((((x360<=x373) &&
(x373<=x351)) &&
star_C(x349,x360,x373)) &&
(\exists integer  x380; ((((x373<=x380) &&
(x380<=x351)) &&
(('D'==x349[x373]) &&
(x380==(x373+1)))) &&
(\exists integer  x393; ((((x380<=x393) &&
(x393<=x351)) &&
star_D(x349,x380,x393)) &&
(x393==x351)))))))))));*/
/*@ predicate re_3(char  * x421, integer  x422, integer  x423) = (\exists integer  x425; ((((x422<=x425) &&
(x425<=x423)) &&
star_C(x421,x422,x425)) &&
(\exists integer  x432; ((((x425<=x432) &&
(x432<=x423)) &&
(('D'==x421[x425]) &&
(x432==(x425+1)))) &&
(\exists integer  x445; ((((x432<=x445) &&
(x445<=x423)) &&
star_D(x421,x432,x445)) &&
(x445==x423)))))));*/
/*@ predicate re_4(char  * x465, integer  x466, integer  x467) = (\exists integer  x469; ((((x466<=x469) &&
(x469<=x467)) &&
star_D(x465,x466,x469)) &&
(x469==x467)));*/
/*@ predicate re_bwd_0(char  * x481, integer  x482, integer  x483) = (x482==x483);*/
/*@ predicate re_bwd_1(char  * x486, integer  x487, integer  x488) = (\exists integer  x490; ((((x487<=x490) &&
(x490<=x488)) &&
(('A'==x486[x487]) &&
(x490==(x487+1)))) &&
(\exists integer  x503; ((((x490<=x503) &&
(x503<=x488)) &&
star_A(x486,x490,x503)) &&
(x503==x488)))));*/
/*@ predicate re_bwd_2(char  * x519, integer  x520, integer  x521) = (\exists integer  x523; ((((x520<=x523) &&
(x523<=x521)) &&
(('A'==x519[x520]) &&
(x523==(x520+1)))) &&
(\exists integer  x536; ((((x523<=x536) &&
(x536<=x521)) &&
star_A(x519,x523,x536)) &&
(\exists integer  x543; ((((x536<=x543) &&
(x543<=x521)) &&
(('B'==x519[x536]) &&
(x543==(x536+1)))) &&
(\exists integer  x556; ((((x543<=x556) &&
(x556<=x521)) &&
star__orB_or_C_sCs_Bor_(x519,x543,x556)) &&
(x556==x521)))))))));*/
/*@ predicate re_bwd_3(char  * x580, integer  x581, integer  x582) = (\exists integer  x584; ((((x581<=x584) &&
(x584<=x582)) &&
(('A'==x580[x581]) &&
(x584==(x581+1)))) &&
(\exists integer  x597; ((((x584<=x597) &&
(x597<=x582)) &&
star_A(x580,x584,x597)) &&
(\exists integer  x604; ((((x597<=x604) &&
(x604<=x582)) &&
(('B'==x580[x597]) &&
(x604==(x597+1)))) &&
(\exists integer  x617; ((((x604<=x617) &&
(x617<=x582)) &&
star__orB_or_C_sCs_Bor_(x580,x604,x617)) &&
(\exists integer  x624; ((((x617<=x624) &&
(x624<=x582)) &&
(('C'==x580[x617]) &&
(x624==(x617+1)))) &&
(\exists integer  x637; ((((x624<=x637) &&
(x637<=x582)) &&
star_C(x580,x624,x637)) &&
(x637==x582)))))))))))));*/
/*@ predicate re_bwd_4(char  * x669, integer  x670, integer  x671) = (\exists integer  x673; ((((x670<=x673) &&
(x673<=x671)) &&
(('A'==x669[x670]) &&
(x673==(x670+1)))) &&
(\exists integer  x686; ((((x673<=x686) &&
(x686<=x671)) &&
star_A(x669,x673,x686)) &&
(\exists integer  x693; ((((x686<=x693) &&
(x693<=x671)) &&
(('B'==x669[x686]) &&
(x693==(x686+1)))) &&
(\exists integer  x706; ((((x693<=x706) &&
(x706<=x671)) &&
star__orB_or_C_sCs_Bor_(x669,x693,x706)) &&
(\exists integer  x713; ((((x706<=x713) &&
(x713<=x671)) &&
(('C'==x669[x706]) &&
(x713==(x706+1)))) &&
(\exists integer  x726; ((((x713<=x726) &&
(x726<=x671)) &&
star_C(x669,x713,x726)) &&
(\exists integer  x733; ((((x726<=x733) &&
(x733<=x671)) &&
(('D'==x669[x726]) &&
(x733==(x726+1)))) &&
(\exists integer  x746; ((((x733<=x746) &&
(x746<=x671)) &&
star_D(x669,x733,x746)) &&
(x746==x671)))))))))))))))));*/
/*@
requires (((strlen(x786)>=0) &&
\valid(x786+(0..(strlen(x786)+1)-1))) &&
(strlen(x786)<100));
assigns \nothing;
ensures (\result ==> re_0(x786,0,strlen(x786)));
*/
int dfa(char  * x786) {
  int x788 = 1/*true*/;
  int x789 = 0;
  int x790 = 0;
  int x791 = strlen(x786);
  /*@
  loop invariant (((((((strlen(x786)>=0) &&
  \valid(x786+(0..(strlen(x786)+1)-1))) &&
  ((0<=x790) &&
  (x790<=x791))) &&
  ((strlen((x786+x790))>=0) &&
  \valid((x786+x790)+(0..(strlen((x786+x790))+1)-1)))) &&
  (x788 ==> (((x789==4) ==> re_bwd_4(x786,0,x790)) &&
  (((x789==3) ==> re_bwd_3(x786,0,x790)) &&
  (((x789==2) ==> re_bwd_2(x786,0,x790)) &&
  (((x789==1) ==> re_bwd_1(x786,0,x790)) &&
  ((x789==0) ==> re_bwd_0(x786,0,x790)))))))) &&
  ((x789==4) ==> (re_bwd_4(x786,0,x790) ==> re_0(x786,0,x790)))) &&
  ((x789==4) || ((x789==3) || ((x789==2) || ((x789==1) || (x789==0))))));
  loop assigns x790, x789, x788;
  loop variant (x791-x790);
  */
  for (;;) {
    int x792 = x790;
    int x793 = x792 < x791;
    int x796;
    if (x793) {
      int x794 = x788;
      x796 = x794;
    } else {
      x796 = 0/*false*/;
    }
    if (!x796) break;
    int x798 = x790;
    char x799 = x786[x798];
    char x800 = x799;
    x788 = 0/*false*/;
    int x802 = x788;
    int x807;
    if (x802) {
      x807 = 0/*false*/;
    } else {
      int x804 = x789;
      int x805 = x804 == 0;
      x807 = x805;
    }
    if (x807) {
      /*@assert ((x789==0) ==> re_bwd_0(x786,0,x790));*/
      /*@assert re_bwd_0(x786,0,x790);*/
      char x819 = x800;
      int x820 = 'A' == x819;
      if (x820) {
        /*@assert re_bwd_1(x786,0,(x790+1));*/
        x789 = 1;
        x788 = 1/*true*/;
        /*@assert re_bwd_1(x786,0,(x790+1));*/
        /*@assert ((x789==1) ==> re_bwd_1(x786,0,(x790+1)));*/
      } else {
      }
    } else {
    }
    int x845 = x788;
    int x850;
    if (x845) {
      x850 = 0/*false*/;
    } else {
      int x847 = x789;
      int x848 = x847 == 1;
      x850 = x848;
    }
    if (x850) {
      /*@assert ((x789==1) ==> re_bwd_1(x786,0,x790));*/
      /*@assert re_bwd_1(x786,0,x790);*/
      char x862 = x800;
      int x863 = 'A' == x862;
      if (x863) {
        /*@assert re_bwd_1(x786,0,(x790+1));*/
        x789 = 1;
        x788 = 1/*true*/;
        /*@assert re_bwd_1(x786,0,(x790+1));*/
        /*@assert ((x789==1) ==> re_bwd_1(x786,0,(x790+1)));*/
      } else {
      }
      int x886 = 'B' == x862;
      if (x886) {
        /*@assert re_bwd_2(x786,0,(x790+1));*/
        x789 = 2;
        x788 = 1/*true*/;
        /*@assert re_bwd_2(x786,0,(x790+1));*/
        /*@assert ((x789==2) ==> re_bwd_2(x786,0,(x790+1)));*/
      } else {
      }
    } else {
    }
    int x911 = x788;
    int x916;
    if (x911) {
      x916 = 0/*false*/;
    } else {
      int x913 = x789;
      int x914 = x913 == 2;
      x916 = x914;
    }
    if (x916) {
      /*@assert ((x789==2) ==> re_bwd_2(x786,0,x790));*/
      /*@assert re_bwd_2(x786,0,x790);*/
      char x928 = x800;
      int x929 = 'B' == x928;
      if (x929) {
        /*@assert re_bwd_2(x786,0,(x790+1));*/
        x789 = 2;
        x788 = 1/*true*/;
        /*@assert re_bwd_2(x786,0,(x790+1));*/
        /*@assert ((x789==2) ==> re_bwd_2(x786,0,(x790+1)));*/
      } else {
      }
      int x952 = 'C' == x928;
      if (x952) {
        /*@assert re_bwd_3(x786,0,(x790+1));*/
        x789 = 3;
        x788 = 1/*true*/;
        /*@assert re_bwd_3(x786,0,(x790+1));*/
        /*@assert ((x789==3) ==> re_bwd_3(x786,0,(x790+1)));*/
      } else {
      }
    } else {
    }
    int x977 = x788;
    int x982;
    if (x977) {
      x982 = 0/*false*/;
    } else {
      int x979 = x789;
      int x980 = x979 == 3;
      x982 = x980;
    }
    if (x982) {
      /*@assert ((x789==3) ==> re_bwd_3(x786,0,x790));*/
      /*@assert re_bwd_3(x786,0,x790);*/
      char x994 = x800;
      int x995 = 'B' == x994;
      if (x995) {
        /*@assert re_bwd_2(x786,0,(x790+1));*/
        x789 = 2;
        x788 = 1/*true*/;
        /*@assert re_bwd_2(x786,0,(x790+1));*/
        /*@assert ((x789==2) ==> re_bwd_2(x786,0,(x790+1)));*/
      } else {
      }
      int x1018 = 'C' == x994;
      if (x1018) {
        /*@assert re_bwd_3(x786,0,(x790+1));*/
        x789 = 3;
        x788 = 1/*true*/;
        /*@assert re_bwd_3(x786,0,(x790+1));*/
        /*@assert ((x789==3) ==> re_bwd_3(x786,0,(x790+1)));*/
      } else {
      }
      int x1041 = 'D' == x994;
      if (x1041) {
        /*@assert re_bwd_4(x786,0,(x790+1));*/
        x789 = 4;
        x788 = 1/*true*/;
        /*@assert re_bwd_4(x786,0,(x790+1));*/
        /*@assert ((x789==4) ==> re_bwd_4(x786,0,(x790+1)));*/
      } else {
      }
    } else {
    }
    int x1066 = x788;
    int x1071;
    if (x1066) {
      x1071 = 0/*false*/;
    } else {
      int x1068 = x789;
      int x1069 = x1068 == 4;
      x1071 = x1069;
    }
    if (x1071) {
      /*@assert ((x789==4) ==> re_bwd_4(x786,0,x790));*/
      /*@assert re_bwd_4(x786,0,x790);*/
      char x1083 = x800;
      int x1084 = 'D' == x1083;
      if (x1084) {
        /*@assert re_bwd_4(x786,0,(x790+1));*/
        x789 = 4;
        x788 = 1/*true*/;
        /*@assert re_bwd_4(x786,0,(x790+1));*/
        /*@assert ((x789==4) ==> re_bwd_4(x786,0,(x790+1)));*/
      } else {
      }
    } else {
    }
    /*@assert (x788 ==> (((x789==4) ==> re_bwd_4(x786,0,(x790+1))) &&
    (((x789==3) ==> re_bwd_3(x786,0,(x790+1))) &&
    (((x789==2) ==> re_bwd_2(x786,0,(x790+1))) &&
    (((x789==1) ==> re_bwd_1(x786,0,(x790+1))) &&
    ((x789==0) ==> re_bwd_0(x786,0,(x790+1))))))));*/
    int x1136 = x798 + 1;
    x790 = x1136;
    /*@assert (x788 ==> (((x789==4) ==> re_bwd_4(x786,0,x790)) &&
    (((x789==3) ==> re_bwd_3(x786,0,x790)) &&
    (((x789==2) ==> re_bwd_2(x786,0,x790)) &&
    (((x789==1) ==> re_bwd_1(x786,0,x790)) &&
    ((x789==0) ==> re_bwd_0(x786,0,x790)))))));*/
  }
  int x1254 = x789;
  int x1255 = x790;
  int x1256 = x1255 == x791;
  int x1259;
  if (x1256) {
    int x1257 = x788;
    x1259 = x1257;
  } else {
    x1259 = 0/*false*/;
  }
  int x1261;
  if (x1259) {
    int x1260 = 4 == x1254;
    x1261 = x1260;
  } else {
    x1261 = 0/*false*/;
  }
  return x1261;
}
