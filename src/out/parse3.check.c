#include <limits.h>
#include <string.h>
char  * p_HTTP(char  * x1206);
char  * p_ContentLength(char  * x1208);
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..(strlen(x0)+1)-1)));
assigns \nothing;
*/
int p(char  * x0) {
  int x2 = -1;
  char  *x3 = p_HTTP(x0);
  int x5 = 1/*true*/;
  int x6 = 0;
  char  *x7 = 0/*null*/;
  int x8 = 1/*true*/;
  int x9 = 0;
  char  *x10 = 0/*null*/;
  int x11 = 1/*true*/;
  int x12 = 0;
  char  *x13 = 0/*null*/;
  int x14 = 1/*true*/;
  int x15 = 0;
  char  *x16 = 0/*null*/;
  int x17 = 1/*true*/;
  char  *x19 = 0/*null*/;
  int x20 = 1/*true*/;
  char  *x22 = 0/*null*/;
  int x23 = 1/*true*/;
  char x24 = '\0';
  char  *x25 = 0/*null*/;
  int x26 = 1/*true*/;
  char  *x28 = 0/*null*/;
  int x29 = 1/*true*/;
  char  *x31 = 0/*null*/;
  int x4 = 0 != x3;
  if (x4) {
    x29 = 0/*false*/;
    x31 = x3;
  } else {
    x31 = x0;
  }
  int x39 = x29;
  if (x39) {
    char  *x40 = x31;
    x28 = x40;
  } else {
    char  *x44 = x31;
    int x51 = 1/*true*/;
    char x52 = '\0';
    char  *x53 = 0/*null*/;
    char x45 = x44[0];
    int x46 = x45 == '\0';
    if (x46) {
      x53 = x44;
    } else {
      int x47 = x45 >= '0';
      int x49;
      if (x47) {
        int x48 = x45 <= '9';
        x49 = x48;
      } else {
        x49 = 0/*false*/;
      }
      if (x49) {
        x51 = 0/*false*/;
        x52 = x45;
        char  *x50 = x44+1;
        x53 = x50;
      } else {
        x53 = x44;
      }
    }
    int x65 = x51;
    if (x65) {
      char  *x66 = x53;
      x28 = x66;
    } else {
      char x69 = x52;
      char  *x70 = x53;
      char  *x71 = x70;
      int x72 = 1/*true*/;
      /*@
      loop invariant ((strlen(x71)>=0) && \valid(x71+(0..(strlen(x71)+1)-1)));
      loop assigns x71, x72;
      */
      for (;;) {
        int x73 = x72;
        if (!x73) break;
        char  *x75 = x71;
        char x76 = x75[0];
        int x77 = x76 == '\0';
        if (x77) {
          x72 = 0/*false*/;
        } else {
          int x78 = x76 >= '0';
          int x80;
          if (x78) {
            int x79 = x76 <= '9';
            x80 = x79;
          } else {
            x80 = 0/*false*/;
          }
          if (x80) {
            char  *x81 = x75+1;
            x71 = x81;
          } else {
            x72 = 0/*false*/;
          }
        }
      }
      char  *x107 = x71;
      x26 = 0/*false*/;
      x28 = x107;
    }
  }
  int x115 = x26;
  if (x115) {
    char  *x116 = x28;
    x25 = x116;
  } else {
    char  *x120 = x28;
    char x121 = x120[0];
    int x122 = x121 == '\0';
    if (x122) {
      x25 = x120;
    } else {
      int x123 = x121 == '.';
      if (x123) {
        x23 = 0/*false*/;
        x24 = x121;
        char  *x124 = x120+1;
        x25 = x124;
      } else {
        x25 = x120;
      }
    }
  }
  int x138 = x23;
  if (x138) {
    char  *x139 = x25;
    x22 = x139;
  } else {
    char x142 = x24;
    char  *x143 = x25;
    int x150 = 1/*true*/;
    char x151 = '\0';
    char  *x152 = 0/*null*/;
    char x144 = x143[0];
    int x145 = x144 == '\0';
    if (x145) {
      x152 = x143;
    } else {
      int x146 = x144 >= '0';
      int x148;
      if (x146) {
        int x147 = x144 <= '9';
        x148 = x147;
      } else {
        x148 = 0/*false*/;
      }
      if (x148) {
        x150 = 0/*false*/;
        x151 = x144;
        char  *x149 = x143+1;
        x152 = x149;
      } else {
        x152 = x143;
      }
    }
    int x164 = x150;
    if (x164) {
      char  *x165 = x152;
      x22 = x165;
    } else {
      char x168 = x151;
      char  *x169 = x152;
      char  *x170 = x169;
      int x171 = 1/*true*/;
      /*@
      loop invariant ((strlen(x170)>=0) && \valid(x170+(0..(strlen(x170)+1)-1)));
      loop assigns x170, x171;
      */
      for (;;) {
        int x172 = x171;
        if (!x172) break;
        char  *x174 = x170;
        char x175 = x174[0];
        int x176 = x175 == '\0';
        if (x176) {
          x171 = 0/*false*/;
        } else {
          int x177 = x175 >= '0';
          int x179;
          if (x177) {
            int x178 = x175 <= '9';
            x179 = x178;
          } else {
            x179 = 0/*false*/;
          }
          if (x179) {
            char  *x180 = x174+1;
            x170 = x180;
          } else {
            x171 = 0/*false*/;
          }
        }
      }
      char  *x206 = x170;
      x20 = 0/*false*/;
      x22 = x206;
    }
  }
  int x214 = x20;
  if (x214) {
    char  *x215 = x22;
    x19 = x215;
  } else {
    char  *x219 = x22;
    char  *x220 = x219;
    int x221 = 1/*true*/;
    /*@
    loop invariant ((strlen(x220)>=0) && \valid(x220+(0..(strlen(x220)+1)-1)));
    loop assigns x220, x221;
    */
    for (;;) {
      int x222 = x221;
      if (!x222) break;
      char  *x224 = x220;
      char x225 = x224[0];
      int x226 = x225 == '\0';
      if (x226) {
        x221 = 0/*false*/;
      } else {
        int x227 = x225 == ' ';
        if (x227) {
          char  *x228 = x224+1;
          x220 = x228;
        } else {
          x221 = 0/*false*/;
        }
      }
    }
    char  *x254 = x220;
    x17 = 0/*false*/;
    x19 = x254;
  }
  int x260 = x17;
  if (x260) {
    char  *x261 = x19;
    x16 = x261;
  } else {
    char  *x265 = x19;
    int x272 = 1/*true*/;
    int x273 = 0;
    char  *x274 = 0/*null*/;
    int x275 = 1/*true*/;
    char x276 = '\0';
    char  *x277 = 0/*null*/;
    char x266 = x265[0];
    int x267 = x266 == '\0';
    if (x267) {
      x277 = x265;
    } else {
      int x268 = x266 >= '0';
      int x270;
      if (x268) {
        int x269 = x266 <= '9';
        x270 = x269;
      } else {
        x270 = 0/*false*/;
      }
      if (x270) {
        x275 = 0/*false*/;
        x276 = x266;
        char  *x271 = x265+1;
        x277 = x271;
      } else {
        x277 = x265;
      }
    }
    int x289 = x275;
    if (x289) {
      char  *x290 = x277;
      x274 = x290;
    } else {
      char x293 = x276;
      char  *x295 = x277;
      x272 = 0/*false*/;
      char x294 = x293 - '0';
      x273 = x294;
      x274 = x295;
    }
    int x301 = x272;
    if (x301) {
      char  *x302 = x274;
      x16 = x302;
    } else {
      int x305 = x273;
      char  *x306 = x274;
      char  *x307 = x306;
      int x308 = 1/*true*/;
      int x309 = x305;
      int x342 = INT_MAX;
      int x343 = x342 / 10;
      int x344 = x343 - 10;
      /*@
      loop invariant (((strlen(x307)>=0) && \valid(x307+(0..(strlen(x307)+1)-1))) && ((x309==-1) || (0<=x309)));
      loop assigns x307, x308, x309;
      */
      for (;;) {
        int x310 = x308;
        if (!x310) break;
        char  *x312 = x307;
        int x319 = 1/*true*/;
        char x320 = '\0';
        char  *x321 = 0/*null*/;
        char x313 = x312[0];
        int x314 = x313 == '\0';
        if (x314) {
          x321 = x312;
        } else {
          int x315 = x313 >= '0';
          int x317;
          if (x315) {
            int x316 = x313 <= '9';
            x317 = x316;
          } else {
            x317 = 0/*false*/;
          }
          if (x317) {
            x319 = 0/*false*/;
            x320 = x313;
            char  *x318 = x312+1;
            x321 = x318;
          } else {
            x321 = x312;
          }
        }
        int x333 = x319;
        if (x333) {
          char  *x334 = x321;
          x308 = 0/*false*/;
        } else {
          char x337 = x320;
          char  *x339 = x321;
          int x340 = x309;
          int x341 = x340 < 0;
          int x349;
          if (x341) {
            x349 = x340;
          } else {
            int x345 = x340 > x344;
            int x348;
            if (x345) {
              x348 = -1;
            } else {
              char x338 = x337 - '0';
              int x346 = x340 * 10;
              int x347 = x346 + x338;
              x348 = x347;
            }
            x349 = x348;
          }
          x309 = x349;
          x307 = x339;
        }
      }
      int x377 = x309;
      char  *x378 = x307;
      x14 = 0/*false*/;
      x15 = x377;
      x16 = x378;
    }
  }
  int x386 = x14;
  if (x386) {
    char  *x387 = x16;
    x13 = x387;
  } else {
    int x390 = x15;
    char  *x391 = x16;
    char  *x392 = x391;
    int x393 = 1/*true*/;
    /*@
    loop invariant ((strlen(x392)>=0) && \valid(x392+(0..(strlen(x392)+1)-1)));
    loop assigns x392, x393;
    */
    for (;;) {
      int x394 = x393;
      if (!x394) break;
      char  *x396 = x392;
      char x397 = x396[0];
      int x398 = x397 == '\0';
      if (x398) {
        x393 = 0/*false*/;
      } else {
        int x399 = x397 != '\n';
        if (x399) {
          char  *x400 = x396+1;
          x392 = x400;
        } else {
          x393 = 0/*false*/;
        }
      }
    }
    char  *x426 = x392;
    int x427 = 1/*true*/;
    char  *x429 = 0/*null*/;
    x427 = 0/*false*/;
    x429 = x426;
    int x433 = x427;
    if (x433) {
      char  *x434 = x429;
      x13 = x434;
    } else {
      char  *x438 = x429;
      int x443 = 1/*true*/;
      char x444 = '\0';
      char  *x445 = 0/*null*/;
      char x439 = x438[0];
      int x440 = x439 == '\0';
      if (x440) {
        x445 = x438;
      } else {
        int x441 = x439 == '\n';
        if (x441) {
          x443 = 0/*false*/;
          x444 = x439;
          char  *x442 = x438+1;
          x445 = x442;
        } else {
          x445 = x438;
        }
      }
      int x457 = x443;
      if (x457) {
        char  *x458 = x445;
        x13 = x458;
      } else {
        char x461 = x444;
        char  *x462 = x445;
        x11 = 0/*false*/;
        x12 = x390;
        x13 = x462;
      }
    }
  }
  int x472 = x11;
  if (x472) {
    char  *x473 = x13;
    x10 = x473;
  } else {
    int x476 = x12;
    char  *x477 = x13;
    char  *x478 = x477;
    int x479 = 1/*true*/;
    int x480 = 0;
    int x342 = INT_MAX;
    int x343 = x342 / 10;
    int x344 = x343 - 10;
    int x1007 = -2 == -2;
    /*@
    loop invariant ((strlen(x478)>=0) && \valid(x478+(0..(strlen(x478)+1)-1)));
    loop assigns x478, x479, x480;
    */
    for (;;) {
      int x481 = x479;
      if (!x481) break;
      char  *x483 = x478;
      char  *x484 = p_ContentLength(x483);
      int x486 = 1/*true*/;
      int x487 = 0;
      char  *x488 = 0/*null*/;
      int x489 = 1/*true*/;
      int x490 = 0;
      char  *x491 = 0/*null*/;
      int x492 = 1/*true*/;
      int x493 = 0;
      char  *x494 = 0/*null*/;
      int x495 = 1/*true*/;
      int x496 = 0;
      char  *x497 = 0/*null*/;
      int x498 = 1/*true*/;
      int x499 = 0;
      char  *x500 = 0/*null*/;
      int x501 = 1/*true*/;
      char  *x503 = 0/*null*/;
      int x485 = 0 != x484;
      if (x485) {
        x501 = 0/*false*/;
        x503 = x484;
      } else {
        x503 = x483;
      }
      int x511 = x501;
      if (x511) {
        char  *x512 = x503;
      } else {
        char  *x515 = x503;
        x498 = 0/*false*/;
        x499 = 1;
        x500 = x515;
      }
      int x521 = x498;
      if (x521) {
        char  *x522 = x483;
        int x523 = 1/*true*/;
        /*@
        loop invariant ((strlen(x522)>=0) && \valid(x522+(0..(strlen(x522)+1)-1)));
        loop assigns x522, x523;
        */
        for (;;) {
          int x524 = x523;
          if (!x524) break;
          char  *x526 = x522;
          int x537 = 1/*true*/;
          char x538 = '\0';
          char  *x539 = 0/*null*/;
          char x527 = x526[0];
          int x528 = x527 == '\0';
          if (x528) {
          } else {
            int x529 = x527 >= 'a';
            int x531;
            if (x529) {
              int x530 = x527 <= 'z';
              x531 = x530;
            } else {
              x531 = 0/*false*/;
            }
            int x532 = x527 >= 'A';
            int x534;
            if (x532) {
              int x533 = x527 <= 'Z';
              x534 = x533;
            } else {
              x534 = 0/*false*/;
            }
            int x535 = x531 || x534;
            if (x535) {
              x537 = 0/*false*/;
              x538 = x527;
              char  *x536 = x526+1;
              x539 = x536;
            } else {
            }
          }
          int x547 = x537;
          char x549 = x538;
          char  *x550 = x539;
          if (x547) {
            if (x528) {
              x523 = 0/*false*/;
            } else {
              int x548 = x527 == '-';
              if (x548) {
                char  *x536 = x526+1;
                x522 = x536;
              } else {
                x523 = 0/*false*/;
              }
            }
          } else {
            x522 = x550;
          }
        }
        char  *x580 = x522;
        x495 = 0/*false*/;
        x496 = 0;
        x497 = x580;
      } else {
        int x585 = x499;
        char  *x586 = x500;
        x495 = 0/*false*/;
        x496 = x585;
        x497 = x586;
      }
      int x592 = x495;
      if (x592) {
        char  *x593 = x497;
        x494 = x593;
      } else {
        int x596 = x496;
        char  *x597 = x497;
        char  *x598 = x597;
        int x599 = 1/*true*/;
        /*@
        loop invariant ((strlen(x598)>=0) && \valid(x598+(0..(strlen(x598)+1)-1)));
        loop assigns x598, x599;
        */
        for (;;) {
          int x600 = x599;
          if (!x600) break;
          char  *x602 = x598;
          char x603 = x602[0];
          int x604 = x603 == '\0';
          if (x604) {
            x599 = 0/*false*/;
          } else {
            int x605 = x603 == ' ';
            if (x605) {
              char  *x606 = x602+1;
              x598 = x606;
            } else {
              x599 = 0/*false*/;
            }
          }
        }
        char  *x632 = x598;
        x492 = 0/*false*/;
        x493 = x596;
        x494 = x632;
      }
      int x638 = x492;
      if (x638) {
        char  *x639 = x494;
        x491 = x639;
      } else {
        int x642 = x493;
        char  *x643 = x494;
        int x648 = 1/*true*/;
        char x649 = '\0';
        char  *x650 = 0/*null*/;
        char x644 = x643[0];
        int x645 = x644 == '\0';
        if (x645) {
          x650 = x643;
        } else {
          int x646 = x644 == ':';
          if (x646) {
            x648 = 0/*false*/;
            x649 = x644;
            char  *x647 = x643+1;
            x650 = x647;
          } else {
            x650 = x643;
          }
        }
        int x662 = x648;
        if (x662) {
          char  *x663 = x650;
          x491 = x663;
        } else {
          char x666 = x649;
          char  *x667 = x650;
          x489 = 0/*false*/;
          x490 = x642;
          x491 = x667;
        }
      }
      int x675 = x489;
      if (x675) {
        char  *x676 = x491;
        x488 = x676;
      } else {
        int x679 = x490;
        char  *x680 = x491;
        char  *x681 = x680;
        int x682 = 1/*true*/;
        /*@
        loop invariant ((strlen(x681)>=0) && \valid(x681+(0..(strlen(x681)+1)-1)));
        loop assigns x681, x682;
        */
        for (;;) {
          int x683 = x682;
          if (!x683) break;
          char  *x685 = x681;
          char x686 = x685[0];
          int x687 = x686 == '\0';
          if (x687) {
            x682 = 0/*false*/;
          } else {
            int x688 = x686 == ' ';
            if (x688) {
              char  *x689 = x685+1;
              x681 = x689;
            } else {
              x682 = 0/*false*/;
            }
          }
        }
        char  *x715 = x681;
        x486 = 0/*false*/;
        x487 = x679;
        x488 = x715;
      }
      int x721 = x486;
      if (x721) {
        char  *x722 = x488;
        x479 = 0/*false*/;
      } else {
        int x725 = x487;
        char  *x726 = x488;
        char  *x734 = x726;
        int x735 = 1/*true*/;
        /*@
        loop invariant ((strlen(x734)>=0) && \valid(x734+(0..(strlen(x734)+1)-1)));
        loop assigns x734, x735;
        */
        for (;;) {
          int x736 = x735;
          if (!x736) break;
          char  *x738 = x734;
          char x739 = x738[0];
          int x740 = x739 == '\0';
          if (x740) {
            x735 = 0/*false*/;
          } else {
            int x741 = x739 != '\n';
            if (x741) {
              char  *x742 = x738+1;
              x734 = x742;
            } else {
              x735 = 0/*false*/;
            }
          }
        }
        char  *x768 = x734;
        int x727 = x725 == 1;
        if (x727) {
          int x769 = 1/*true*/;
          int x770 = 0;
          char  *x771 = 0/*null*/;
          int x772 = 1/*true*/;
          int x773 = 0;
          char  *x774 = 0/*null*/;
          int x775 = 1/*true*/;
          int x776 = 0;
          char  *x777 = 0/*null*/;
          int x778 = 1/*true*/;
          char x779 = '\0';
          char  *x780 = 0/*null*/;
          char x728 = x726[0];
          int x729 = x728 == '\0';
          if (x729) {
            x780 = x726;
          } else {
            int x730 = x728 >= '0';
            int x732;
            if (x730) {
              int x731 = x728 <= '9';
              x732 = x731;
            } else {
              x732 = 0/*false*/;
            }
            if (x732) {
              x778 = 0/*false*/;
              x779 = x728;
              char  *x733 = x726+1;
              x780 = x733;
            } else {
              x780 = x726;
            }
          }
          int x792 = x778;
          if (x792) {
            char  *x793 = x780;
            x777 = x793;
          } else {
            char x796 = x779;
            char  *x798 = x780;
            x775 = 0/*false*/;
            char x797 = x796 - '0';
            x776 = x797;
            x777 = x798;
          }
          int x804 = x775;
          if (x804) {
            char  *x805 = x777;
            x774 = x805;
          } else {
            int x808 = x776;
            char  *x809 = x777;
            char  *x810 = x809;
            int x811 = 1/*true*/;
            int x812 = x808;
            /*@
            loop invariant (((strlen(x810)>=0) && \valid(x810+(0..(strlen(x810)+1)-1))) && ((x812==-1) || (0<=x812)));
            loop assigns x810, x811, x812;
            */
            for (;;) {
              int x813 = x811;
              if (!x813) break;
              char  *x815 = x810;
              int x822 = 1/*true*/;
              char x823 = '\0';
              char  *x824 = 0/*null*/;
              char x816 = x815[0];
              int x817 = x816 == '\0';
              if (x817) {
                x824 = x815;
              } else {
                int x818 = x816 >= '0';
                int x820;
                if (x818) {
                  int x819 = x816 <= '9';
                  x820 = x819;
                } else {
                  x820 = 0/*false*/;
                }
                if (x820) {
                  x822 = 0/*false*/;
                  x823 = x816;
                  char  *x821 = x815+1;
                  x824 = x821;
                } else {
                  x824 = x815;
                }
              }
              int x836 = x822;
              if (x836) {
                char  *x837 = x824;
                x811 = 0/*false*/;
              } else {
                char x840 = x823;
                char  *x842 = x824;
                int x843 = x812;
                int x844 = x843 < 0;
                int x849;
                if (x844) {
                  x849 = x843;
                } else {
                  int x845 = x843 > x344;
                  int x848;
                  if (x845) {
                    x848 = -1;
                  } else {
                    char x841 = x840 - '0';
                    int x846 = x843 * 10;
                    int x847 = x846 + x841;
                    x848 = x847;
                  }
                  x849 = x848;
                }
                x812 = x849;
                x810 = x842;
              }
            }
            int x877 = x812;
            char  *x878 = x810;
            x772 = 0/*false*/;
            x773 = x877;
            x774 = x878;
          }
          int x884 = x772;
          if (x884) {
            char  *x885 = x774;
            x771 = x885;
          } else {
            int x888 = x773;
            char  *x889 = x774;
            char  *x890 = x889;
            int x891 = 1/*true*/;
            /*@
            loop invariant ((strlen(x890)>=0) && \valid(x890+(0..(strlen(x890)+1)-1)));
            loop assigns x890, x891;
            */
            for (;;) {
              int x892 = x891;
              if (!x892) break;
              char  *x894 = x890;
              char x895 = x894[0];
              int x896 = x895 == '\0';
              if (x896) {
                x891 = 0/*false*/;
              } else {
                int x897 = x895 == ' ';
                if (x897) {
                  char  *x898 = x894+1;
                  x890 = x898;
                } else {
                  x891 = 0/*false*/;
                }
              }
            }
            char  *x924 = x890;
            x769 = 0/*false*/;
            x770 = x888;
            x771 = x924;
          }
          int x930 = x769;
          if (x930) {
            char  *x931 = x771;
            x479 = 0/*false*/;
          } else {
            int x934 = x770;
            char  *x935 = x771;
            int x940 = 1/*true*/;
            char x941 = '\0';
            char  *x942 = 0/*null*/;
            char x936 = x935[0];
            int x937 = x936 == '\0';
            if (x937) {
              x942 = x935;
            } else {
              int x938 = x936 == '\n';
              if (x938) {
                x940 = 0/*false*/;
                x941 = x936;
                char  *x939 = x935+1;
                x942 = x939;
              } else {
                x942 = x935;
              }
            }
            int x954 = x940;
            if (x954) {
              char  *x955 = x942;
              x479 = 0/*false*/;
            } else {
              char x958 = x941;
              char  *x959 = x942;
              int x960 = x480;
              int x961 = x934 == -2;
              int x962;
              if (x961) {
                x962 = x960;
              } else {
                x962 = x934;
              }
              x480 = x962;
              x478 = x959;
            }
          }
        } else {
          int x970 = 1/*true*/;
          char  *x972 = 0/*null*/;
          x970 = 0/*false*/;
          x972 = x768;
          int x976 = x970;
          if (x976) {
            char  *x977 = x972;
            x479 = 0/*false*/;
          } else {
            char  *x981 = x972;
            int x986 = 1/*true*/;
            char x987 = '\0';
            char  *x988 = 0/*null*/;
            char x982 = x981[0];
            int x983 = x982 == '\0';
            if (x983) {
              x988 = x981;
            } else {
              int x984 = x982 == '\n';
              if (x984) {
                x986 = 0/*false*/;
                x987 = x982;
                char  *x985 = x981+1;
                x988 = x985;
              } else {
                x988 = x981;
              }
            }
            int x1000 = x986;
            if (x1000) {
              char  *x1001 = x988;
              x479 = 0/*false*/;
            } else {
              char x1004 = x987;
              char  *x1005 = x988;
              int x1006 = x480;
              int x1008;
              if (x1007) {
                x1008 = x1006;
              } else {
                x1008 = -2;
              }
              x480 = x1008;
              x478 = x1005;
            }
          }
        }
      }
    }
    int x1037 = x480;
    char  *x1038 = x478;
    x8 = 0/*false*/;
    x9 = x1037;
    x10 = x1038;
  }
  int x1044 = x8;
  if (x1044) {
    char  *x1045 = x10;
    x7 = x1045;
  } else {
    int x1048 = x9;
    char  *x1049 = x10;
    int x1054 = 1/*true*/;
    char x1055 = '\0';
    char  *x1056 = 0/*null*/;
    char x1050 = x1049[0];
    int x1051 = x1050 == '\0';
    if (x1051) {
      x1056 = x1049;
    } else {
      int x1052 = x1050 == '\n';
      if (x1052) {
        x1054 = 0/*false*/;
        x1055 = x1050;
        char  *x1053 = x1049+1;
        x1056 = x1053;
      } else {
        x1056 = x1049;
      }
    }
    int x1068 = x1054;
    if (x1068) {
      char  *x1069 = x1056;
      x7 = x1069;
    } else {
      char x1072 = x1055;
      char  *x1073 = x1056;
      x5 = 0/*false*/;
      x6 = x1048;
      x7 = x1073;
    }
  }
  int x1081 = x5;
  if (x1081) {
    char  *x1082 = x7;
  } else {
    int x1084 = x6;
    char  *x1085 = x7;
    int x1087 = 1/*true*/;
    char  *x1088 = x1085;
    /*@
    loop invariant ((0<=x1090) && ((strlen(x1088)>=0) && \valid(x1088+(0..(strlen(x1088)+1)-1))));
    loop assigns x1090, x1087, x1088;
    loop variant (x1084-x1090);
    */
    for(int x1090=0; x1090 < x1084; x1090++) {
      int x1091 = x1087;
      if (x1091) {
        char  *x1092 = x1088;
        char x1093 = x1092[0];
        int x1094 = x1093 == '\0';
        if (x1094) {
          x1087 = 0/*false*/;
        } else {
          if (1/*true*/) {
            char  *x1095 = x1092+1;
            x1088 = x1095;
          } else {
            x1087 = 0/*false*/;
          }
        }
      } else {
      }
    }
    int x1128 = x1087;
    char  *x1129 = x1088;
    int x1086 = x1084 < 0;
    if (x1086) {
    } else {
      int x1130 = 1/*true*/;
      int x1131 = 0;
      char  *x1132 = 0/*null*/;
      int x1133 = 1/*true*/;
      char  *x1135 = 0/*null*/;
      if (x1128) {
        x1133 = 0/*false*/;
        x1135 = x1129;
      } else {
        x1135 = x1085;
      }
      int x1143 = x1133;
      if (x1143) {
        char  *x1144 = x1135;
        x1132 = x1144;
      } else {
        char  *x1148 = x1135;
        x1130 = 0/*false*/;
        x1131 = x1084;
        x1132 = x1148;
      }
      int x1154 = x1130;
      if (x1154) {
        char  *x1155 = x1132;
      } else {
        int x1157 = x1131;
        char  *x1158 = x1132;
        int x1163 = 1/*true*/;
        char x1164 = '\0';
        char  *x1165 = 0/*null*/;
        char x1159 = x1158[0];
        int x1160 = x1159 == '\0';
        if (x1160) {
          x1165 = x1158;
        } else {
          int x1161 = x1159 == '\n';
          if (x1161) {
            x1163 = 0/*false*/;
            x1164 = x1159;
            char  *x1162 = x1158+1;
            x1165 = x1162;
          } else {
            x1165 = x1158;
          }
        }
        int x1177 = x1163;
        if (x1177) {
          char  *x1178 = x1165;
        } else {
          char x1180 = x1164;
          char  *x1181 = x1165;
          char x1182 = x1181[0];
          int x1183 = x1182 == '\0';
          if (x1183) {
            x2 = x1157;
          } else {
          }
        }
      }
    }
  }
  int x1195 = x2;
  return x1195;
}
/*@
requires ((strlen(x1210)>=0) && \valid(x1210+(0..(strlen(x1210)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_HTTP(char  * x1210) {
  char  *x1212 = x1210;
  int x1217 = 1/*true*/;
  char x1218 = '\0';
  char  *x1219 = 0/*null*/;
  char x1213 = x1210[0];
  int x1214 = x1213 == '\0';
  if (x1214) {
    x1219 = x1210;
  } else {
    int x1215 = x1213 == 'H';
    if (x1215) {
      x1217 = 0/*false*/;
      x1218 = x1213;
      char  *x1216 = x1210+1;
      x1219 = x1216;
    } else {
      x1219 = x1210;
    }
  }
  int x1231 = x1217;
  if (x1231) {
    char  *x1232 = x1219;
    x1212 = 0;
  } else {
    char x1235 = x1218;
    char  *x1236 = x1219;
    int x1241 = 1/*true*/;
    char x1242 = '\0';
    char  *x1243 = 0/*null*/;
    char x1237 = x1236[0];
    int x1238 = x1237 == '\0';
    if (x1238) {
      x1243 = x1236;
    } else {
      int x1239 = x1237 == 'T';
      if (x1239) {
        x1241 = 0/*false*/;
        x1242 = x1237;
        char  *x1240 = x1236+1;
        x1243 = x1240;
      } else {
        x1243 = x1236;
      }
    }
    int x1255 = x1241;
    if (x1255) {
      char  *x1256 = x1243;
      x1212 = 0;
    } else {
      char x1259 = x1242;
      char  *x1260 = x1243;
      int x1265 = 1/*true*/;
      char x1266 = '\0';
      char  *x1267 = 0/*null*/;
      char x1261 = x1260[0];
      int x1262 = x1261 == '\0';
      if (x1262) {
        x1267 = x1260;
      } else {
        int x1263 = x1261 == 'T';
        if (x1263) {
          x1265 = 0/*false*/;
          x1266 = x1261;
          char  *x1264 = x1260+1;
          x1267 = x1264;
        } else {
          x1267 = x1260;
        }
      }
      int x1279 = x1265;
      if (x1279) {
        char  *x1280 = x1267;
        x1212 = 0;
      } else {
        char x1283 = x1266;
        char  *x1284 = x1267;
        int x1289 = 1/*true*/;
        char x1290 = '\0';
        char  *x1291 = 0/*null*/;
        char x1285 = x1284[0];
        int x1286 = x1285 == '\0';
        if (x1286) {
          x1291 = x1284;
        } else {
          int x1287 = x1285 == 'P';
          if (x1287) {
            x1289 = 0/*false*/;
            x1290 = x1285;
            char  *x1288 = x1284+1;
            x1291 = x1288;
          } else {
            x1291 = x1284;
          }
        }
        int x1303 = x1289;
        if (x1303) {
          char  *x1304 = x1291;
          x1212 = 0;
        } else {
          char x1307 = x1290;
          char  *x1308 = x1291;
          int x1313 = 1/*true*/;
          char x1314 = '\0';
          char  *x1315 = 0/*null*/;
          char x1309 = x1308[0];
          int x1310 = x1309 == '\0';
          if (x1310) {
            x1315 = x1308;
          } else {
            int x1311 = x1309 == '/';
            if (x1311) {
              x1313 = 0/*false*/;
              x1314 = x1309;
              char  *x1312 = x1308+1;
              x1315 = x1312;
            } else {
              x1315 = x1308;
            }
          }
          int x1327 = x1313;
          if (x1327) {
            char  *x1328 = x1315;
            x1212 = 0;
          } else {
            char x1331 = x1314;
            char  *x1332 = x1315;
            x1212 = x1332;
          }
        }
      }
    }
  }
  char  *x1344 = x1212;
  return x1344;
}
/*@
requires ((strlen(x1366)>=0) && \valid(x1366+(0..(strlen(x1366)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_ContentLength(char  * x1366) {
  char  *x1368 = x1366;
  int x1373 = 1/*true*/;
  char x1374 = '\0';
  char  *x1375 = 0/*null*/;
  char x1369 = x1366[0];
  int x1370 = x1369 == '\0';
  if (x1370) {
    x1375 = x1366;
  } else {
    int x1371 = x1369 == 'C';
    if (x1371) {
      x1373 = 0/*false*/;
      x1374 = x1369;
      char  *x1372 = x1366+1;
      x1375 = x1372;
    } else {
      x1375 = x1366;
    }
  }
  int x1387 = x1373;
  if (x1387) {
    char  *x1388 = x1375;
    x1368 = 0;
  } else {
    char x1391 = x1374;
    char  *x1392 = x1375;
    int x1397 = 1/*true*/;
    char x1398 = '\0';
    char  *x1399 = 0/*null*/;
    char x1393 = x1392[0];
    int x1394 = x1393 == '\0';
    if (x1394) {
      x1399 = x1392;
    } else {
      int x1395 = x1393 == 'o';
      if (x1395) {
        x1397 = 0/*false*/;
        x1398 = x1393;
        char  *x1396 = x1392+1;
        x1399 = x1396;
      } else {
        x1399 = x1392;
      }
    }
    int x1411 = x1397;
    if (x1411) {
      char  *x1412 = x1399;
      x1368 = 0;
    } else {
      char x1415 = x1398;
      char  *x1416 = x1399;
      int x1421 = 1/*true*/;
      char x1422 = '\0';
      char  *x1423 = 0/*null*/;
      char x1417 = x1416[0];
      int x1418 = x1417 == '\0';
      if (x1418) {
        x1423 = x1416;
      } else {
        int x1419 = x1417 == 'n';
        if (x1419) {
          x1421 = 0/*false*/;
          x1422 = x1417;
          char  *x1420 = x1416+1;
          x1423 = x1420;
        } else {
          x1423 = x1416;
        }
      }
      int x1435 = x1421;
      if (x1435) {
        char  *x1436 = x1423;
        x1368 = 0;
      } else {
        char x1439 = x1422;
        char  *x1440 = x1423;
        int x1445 = 1/*true*/;
        char x1446 = '\0';
        char  *x1447 = 0/*null*/;
        char x1441 = x1440[0];
        int x1442 = x1441 == '\0';
        if (x1442) {
          x1447 = x1440;
        } else {
          int x1443 = x1441 == 't';
          if (x1443) {
            x1445 = 0/*false*/;
            x1446 = x1441;
            char  *x1444 = x1440+1;
            x1447 = x1444;
          } else {
            x1447 = x1440;
          }
        }
        int x1459 = x1445;
        if (x1459) {
          char  *x1460 = x1447;
          x1368 = 0;
        } else {
          char x1463 = x1446;
          char  *x1464 = x1447;
          int x1469 = 1/*true*/;
          char x1470 = '\0';
          char  *x1471 = 0/*null*/;
          char x1465 = x1464[0];
          int x1466 = x1465 == '\0';
          if (x1466) {
            x1471 = x1464;
          } else {
            int x1467 = x1465 == 'e';
            if (x1467) {
              x1469 = 0/*false*/;
              x1470 = x1465;
              char  *x1468 = x1464+1;
              x1471 = x1468;
            } else {
              x1471 = x1464;
            }
          }
          int x1483 = x1469;
          if (x1483) {
            char  *x1484 = x1471;
            x1368 = 0;
          } else {
            char x1487 = x1470;
            char  *x1488 = x1471;
            int x1493 = 1/*true*/;
            char x1494 = '\0';
            char  *x1495 = 0/*null*/;
            char x1489 = x1488[0];
            int x1490 = x1489 == '\0';
            if (x1490) {
              x1495 = x1488;
            } else {
              int x1491 = x1489 == 'n';
              if (x1491) {
                x1493 = 0/*false*/;
                x1494 = x1489;
                char  *x1492 = x1488+1;
                x1495 = x1492;
              } else {
                x1495 = x1488;
              }
            }
            int x1507 = x1493;
            if (x1507) {
              char  *x1508 = x1495;
              x1368 = 0;
            } else {
              char x1511 = x1494;
              char  *x1512 = x1495;
              int x1517 = 1/*true*/;
              char x1518 = '\0';
              char  *x1519 = 0/*null*/;
              char x1513 = x1512[0];
              int x1514 = x1513 == '\0';
              if (x1514) {
                x1519 = x1512;
              } else {
                int x1515 = x1513 == 't';
                if (x1515) {
                  x1517 = 0/*false*/;
                  x1518 = x1513;
                  char  *x1516 = x1512+1;
                  x1519 = x1516;
                } else {
                  x1519 = x1512;
                }
              }
              int x1531 = x1517;
              if (x1531) {
                char  *x1532 = x1519;
                x1368 = 0;
              } else {
                char x1535 = x1518;
                char  *x1536 = x1519;
                int x1541 = 1/*true*/;
                char x1542 = '\0';
                char  *x1543 = 0/*null*/;
                char x1537 = x1536[0];
                int x1538 = x1537 == '\0';
                if (x1538) {
                  x1543 = x1536;
                } else {
                  int x1539 = x1537 == '-';
                  if (x1539) {
                    x1541 = 0/*false*/;
                    x1542 = x1537;
                    char  *x1540 = x1536+1;
                    x1543 = x1540;
                  } else {
                    x1543 = x1536;
                  }
                }
                int x1555 = x1541;
                if (x1555) {
                  char  *x1556 = x1543;
                  x1368 = 0;
                } else {
                  char x1559 = x1542;
                  char  *x1560 = x1543;
                  int x1565 = 1/*true*/;
                  char x1566 = '\0';
                  char  *x1567 = 0/*null*/;
                  char x1561 = x1560[0];
                  int x1562 = x1561 == '\0';
                  if (x1562) {
                    x1567 = x1560;
                  } else {
                    int x1563 = x1561 == 'L';
                    if (x1563) {
                      x1565 = 0/*false*/;
                      x1566 = x1561;
                      char  *x1564 = x1560+1;
                      x1567 = x1564;
                    } else {
                      x1567 = x1560;
                    }
                  }
                  int x1579 = x1565;
                  if (x1579) {
                    char  *x1580 = x1567;
                    x1368 = 0;
                  } else {
                    char x1583 = x1566;
                    char  *x1584 = x1567;
                    int x1589 = 1/*true*/;
                    char x1590 = '\0';
                    char  *x1591 = 0/*null*/;
                    char x1585 = x1584[0];
                    int x1586 = x1585 == '\0';
                    if (x1586) {
                      x1591 = x1584;
                    } else {
                      int x1587 = x1585 == 'e';
                      if (x1587) {
                        x1589 = 0/*false*/;
                        x1590 = x1585;
                        char  *x1588 = x1584+1;
                        x1591 = x1588;
                      } else {
                        x1591 = x1584;
                      }
                    }
                    int x1603 = x1589;
                    if (x1603) {
                      char  *x1604 = x1591;
                      x1368 = 0;
                    } else {
                      char x1607 = x1590;
                      char  *x1608 = x1591;
                      int x1613 = 1/*true*/;
                      char x1614 = '\0';
                      char  *x1615 = 0/*null*/;
                      char x1609 = x1608[0];
                      int x1610 = x1609 == '\0';
                      if (x1610) {
                        x1615 = x1608;
                      } else {
                        int x1611 = x1609 == 'n';
                        if (x1611) {
                          x1613 = 0/*false*/;
                          x1614 = x1609;
                          char  *x1612 = x1608+1;
                          x1615 = x1612;
                        } else {
                          x1615 = x1608;
                        }
                      }
                      int x1627 = x1613;
                      if (x1627) {
                        char  *x1628 = x1615;
                        x1368 = 0;
                      } else {
                        char x1631 = x1614;
                        char  *x1632 = x1615;
                        int x1637 = 1/*true*/;
                        char x1638 = '\0';
                        char  *x1639 = 0/*null*/;
                        char x1633 = x1632[0];
                        int x1634 = x1633 == '\0';
                        if (x1634) {
                          x1639 = x1632;
                        } else {
                          int x1635 = x1633 == 'g';
                          if (x1635) {
                            x1637 = 0/*false*/;
                            x1638 = x1633;
                            char  *x1636 = x1632+1;
                            x1639 = x1636;
                          } else {
                            x1639 = x1632;
                          }
                        }
                        int x1651 = x1637;
                        if (x1651) {
                          char  *x1652 = x1639;
                          x1368 = 0;
                        } else {
                          char x1655 = x1638;
                          char  *x1656 = x1639;
                          int x1661 = 1/*true*/;
                          char x1662 = '\0';
                          char  *x1663 = 0/*null*/;
                          char x1657 = x1656[0];
                          int x1658 = x1657 == '\0';
                          if (x1658) {
                            x1663 = x1656;
                          } else {
                            int x1659 = x1657 == 't';
                            if (x1659) {
                              x1661 = 0/*false*/;
                              x1662 = x1657;
                              char  *x1660 = x1656+1;
                              x1663 = x1660;
                            } else {
                              x1663 = x1656;
                            }
                          }
                          int x1675 = x1661;
                          if (x1675) {
                            char  *x1676 = x1663;
                            x1368 = 0;
                          } else {
                            char x1679 = x1662;
                            char  *x1680 = x1663;
                            int x1685 = 1/*true*/;
                            char x1686 = '\0';
                            char  *x1687 = 0/*null*/;
                            char x1681 = x1680[0];
                            int x1682 = x1681 == '\0';
                            if (x1682) {
                              x1687 = x1680;
                            } else {
                              int x1683 = x1681 == 'h';
                              if (x1683) {
                                x1685 = 0/*false*/;
                                x1686 = x1681;
                                char  *x1684 = x1680+1;
                                x1687 = x1684;
                              } else {
                                x1687 = x1680;
                              }
                            }
                            int x1699 = x1685;
                            if (x1699) {
                              char  *x1700 = x1687;
                              x1368 = 0;
                            } else {
                              char x1703 = x1686;
                              char  *x1704 = x1687;
                              x1368 = x1704;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  char  *x1734 = x1368;
  return x1734;
}
