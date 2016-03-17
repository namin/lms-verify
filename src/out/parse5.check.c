#include <limits.h>
#include <string.h>
char  * p_chunked(char  * x1769);
char  * p_TransferEncoding(char  * x1771);
char  * p_ContentLength(char  * x1773);
char  * p_HTTP(char  * x1775);
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
    int x1157 = -2 == -2;
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
      int x502 = 0;
      char  *x503 = 0/*null*/;
      int x504 = 1/*true*/;
      char  *x506 = 0/*null*/;
      int x485 = 0 != x484;
      if (x485) {
        x504 = 0/*false*/;
        x506 = x484;
      } else {
        x506 = x483;
      }
      int x514 = x504;
      if (x514) {
        char  *x515 = x506;
      } else {
        char  *x518 = x506;
        x501 = 0/*false*/;
        x502 = 1;
        x503 = x518;
      }
      int x524 = x501;
      if (x524) {
        char  *x525 = p_TransferEncoding(x483);
        int x527 = 1/*true*/;
        char  *x529 = 0/*null*/;
        int x526 = 0 != x525;
        if (x526) {
          x527 = 0/*false*/;
          x529 = x525;
        } else {
          x529 = x483;
        }
        int x537 = x527;
        if (x537) {
          char  *x538 = x529;
        } else {
          char  *x541 = x529;
          x498 = 0/*false*/;
          x499 = 2;
          x500 = x541;
        }
      } else {
        int x548 = x502;
        char  *x549 = x503;
        x498 = 0/*false*/;
        x499 = x548;
        x500 = x549;
      }
      int x555 = x498;
      if (x555) {
        char  *x556 = x483;
        int x557 = 1/*true*/;
        /*@
        loop invariant ((strlen(x556)>=0) && \valid(x556+(0..(strlen(x556)+1)-1)));
        loop assigns x556, x557;
        */
        for (;;) {
          int x558 = x557;
          if (!x558) break;
          char  *x560 = x556;
          int x571 = 1/*true*/;
          char x572 = '\0';
          char  *x573 = 0/*null*/;
          char x561 = x560[0];
          int x562 = x561 == '\0';
          if (x562) {
          } else {
            int x563 = x561 >= 'a';
            int x565;
            if (x563) {
              int x564 = x561 <= 'z';
              x565 = x564;
            } else {
              x565 = 0/*false*/;
            }
            int x566 = x561 >= 'A';
            int x568;
            if (x566) {
              int x567 = x561 <= 'Z';
              x568 = x567;
            } else {
              x568 = 0/*false*/;
            }
            int x569 = x565 || x568;
            if (x569) {
              x571 = 0/*false*/;
              x572 = x561;
              char  *x570 = x560+1;
              x573 = x570;
            } else {
            }
          }
          int x581 = x571;
          char x583 = x572;
          char  *x584 = x573;
          if (x581) {
            if (x562) {
              x557 = 0/*false*/;
            } else {
              int x582 = x561 == '-';
              if (x582) {
                char  *x570 = x560+1;
                x556 = x570;
              } else {
                x557 = 0/*false*/;
              }
            }
          } else {
            x556 = x584;
          }
        }
        char  *x614 = x556;
        x495 = 0/*false*/;
        x496 = 0;
        x497 = x614;
      } else {
        int x619 = x499;
        char  *x620 = x500;
        x495 = 0/*false*/;
        x496 = x619;
        x497 = x620;
      }
      int x626 = x495;
      if (x626) {
        char  *x627 = x497;
        x494 = x627;
      } else {
        int x630 = x496;
        char  *x631 = x497;
        char  *x632 = x631;
        int x633 = 1/*true*/;
        /*@
        loop invariant ((strlen(x632)>=0) && \valid(x632+(0..(strlen(x632)+1)-1)));
        loop assigns x632, x633;
        */
        for (;;) {
          int x634 = x633;
          if (!x634) break;
          char  *x636 = x632;
          char x637 = x636[0];
          int x638 = x637 == '\0';
          if (x638) {
            x633 = 0/*false*/;
          } else {
            int x639 = x637 == ' ';
            if (x639) {
              char  *x640 = x636+1;
              x632 = x640;
            } else {
              x633 = 0/*false*/;
            }
          }
        }
        char  *x666 = x632;
        x492 = 0/*false*/;
        x493 = x630;
        x494 = x666;
      }
      int x672 = x492;
      if (x672) {
        char  *x673 = x494;
        x491 = x673;
      } else {
        int x676 = x493;
        char  *x677 = x494;
        int x682 = 1/*true*/;
        char x683 = '\0';
        char  *x684 = 0/*null*/;
        char x678 = x677[0];
        int x679 = x678 == '\0';
        if (x679) {
          x684 = x677;
        } else {
          int x680 = x678 == ':';
          if (x680) {
            x682 = 0/*false*/;
            x683 = x678;
            char  *x681 = x677+1;
            x684 = x681;
          } else {
            x684 = x677;
          }
        }
        int x696 = x682;
        if (x696) {
          char  *x697 = x684;
          x491 = x697;
        } else {
          char x700 = x683;
          char  *x701 = x684;
          x489 = 0/*false*/;
          x490 = x676;
          x491 = x701;
        }
      }
      int x709 = x489;
      if (x709) {
        char  *x710 = x491;
        x488 = x710;
      } else {
        int x713 = x490;
        char  *x714 = x491;
        char  *x715 = x714;
        int x716 = 1/*true*/;
        /*@
        loop invariant ((strlen(x715)>=0) && \valid(x715+(0..(strlen(x715)+1)-1)));
        loop assigns x715, x716;
        */
        for (;;) {
          int x717 = x716;
          if (!x717) break;
          char  *x719 = x715;
          char x720 = x719[0];
          int x721 = x720 == '\0';
          if (x721) {
            x716 = 0/*false*/;
          } else {
            int x722 = x720 == ' ';
            if (x722) {
              char  *x723 = x719+1;
              x715 = x723;
            } else {
              x716 = 0/*false*/;
            }
          }
        }
        char  *x749 = x715;
        x486 = 0/*false*/;
        x487 = x713;
        x488 = x749;
      }
      int x755 = x486;
      if (x755) {
        char  *x756 = x488;
        x479 = 0/*false*/;
      } else {
        int x759 = x487;
        char  *x760 = x488;
        char  *x762 = p_chunked(x760);
        char  *x771 = x760;
        int x772 = 1/*true*/;
        /*@
        loop invariant ((strlen(x771)>=0) && \valid(x771+(0..(strlen(x771)+1)-1)));
        loop assigns x771, x772;
        */
        for (;;) {
          int x773 = x772;
          if (!x773) break;
          char  *x775 = x771;
          char x776 = x775[0];
          int x777 = x776 == '\0';
          if (x777) {
            x772 = 0/*false*/;
          } else {
            int x778 = x776 != '\n';
            if (x778) {
              char  *x779 = x775+1;
              x771 = x779;
            } else {
              x772 = 0/*false*/;
            }
          }
        }
        char  *x805 = x771;
        int x761 = x759 == 2;
        if (x761) {
          int x806 = 1/*true*/;
          int x807 = 0;
          char  *x808 = 0/*null*/;
          int x809 = 1/*true*/;
          int x810 = 0;
          char  *x811 = 0/*null*/;
          int x812 = 1/*true*/;
          char  *x814 = 0/*null*/;
          int x763 = 0 != x762;
          if (x763) {
            x812 = 0/*false*/;
            x814 = x762;
          } else {
            x814 = x760;
          }
          int x822 = x812;
          if (x822) {
            char  *x823 = x814;
            x811 = x823;
          } else {
            char  *x827 = x814;
            x809 = 0/*false*/;
            x810 = -3;
            x811 = x827;
          }
          int x833 = x809;
          if (x833) {
            char  *x834 = x811;
            x808 = x834;
          } else {
            int x837 = x810;
            char  *x838 = x811;
            char  *x839 = x838;
            int x840 = 1/*true*/;
            /*@
            loop invariant ((strlen(x839)>=0) && \valid(x839+(0..(strlen(x839)+1)-1)));
            loop assigns x839, x840;
            */
            for (;;) {
              int x841 = x840;
              if (!x841) break;
              char  *x843 = x839;
              char x844 = x843[0];
              int x845 = x844 == '\0';
              if (x845) {
                x840 = 0/*false*/;
              } else {
                int x846 = x844 == ' ';
                if (x846) {
                  char  *x847 = x843+1;
                  x839 = x847;
                } else {
                  x840 = 0/*false*/;
                }
              }
            }
            char  *x873 = x839;
            x806 = 0/*false*/;
            x807 = x837;
            x808 = x873;
          }
          int x879 = x806;
          if (x879) {
            char  *x880 = x808;
            x479 = 0/*false*/;
          } else {
            int x883 = x807;
            char  *x884 = x808;
            int x889 = 1/*true*/;
            char x890 = '\0';
            char  *x891 = 0/*null*/;
            char x885 = x884[0];
            int x886 = x885 == '\0';
            if (x886) {
              x891 = x884;
            } else {
              int x887 = x885 == '\n';
              if (x887) {
                x889 = 0/*false*/;
                x890 = x885;
                char  *x888 = x884+1;
                x891 = x888;
              } else {
                x891 = x884;
              }
            }
            int x903 = x889;
            if (x903) {
              char  *x904 = x891;
              x479 = 0/*false*/;
            } else {
              char x907 = x890;
              char  *x908 = x891;
              int x909 = x480;
              int x910 = x883 == -2;
              int x911;
              if (x910) {
                x911 = x909;
              } else {
                x911 = x883;
              }
              x480 = x911;
              x478 = x908;
            }
          }
        } else {
          int x764 = x759 == 1;
          if (x764) {
            int x919 = 1/*true*/;
            int x920 = 0;
            char  *x921 = 0/*null*/;
            int x922 = 1/*true*/;
            int x923 = 0;
            char  *x924 = 0/*null*/;
            int x925 = 1/*true*/;
            int x926 = 0;
            char  *x927 = 0/*null*/;
            int x928 = 1/*true*/;
            char x929 = '\0';
            char  *x930 = 0/*null*/;
            char x765 = x760[0];
            int x766 = x765 == '\0';
            if (x766) {
              x930 = x760;
            } else {
              int x767 = x765 >= '0';
              int x769;
              if (x767) {
                int x768 = x765 <= '9';
                x769 = x768;
              } else {
                x769 = 0/*false*/;
              }
              if (x769) {
                x928 = 0/*false*/;
                x929 = x765;
                char  *x770 = x760+1;
                x930 = x770;
              } else {
                x930 = x760;
              }
            }
            int x942 = x928;
            if (x942) {
              char  *x943 = x930;
              x927 = x943;
            } else {
              char x946 = x929;
              char  *x948 = x930;
              x925 = 0/*false*/;
              char x947 = x946 - '0';
              x926 = x947;
              x927 = x948;
            }
            int x954 = x925;
            if (x954) {
              char  *x955 = x927;
              x924 = x955;
            } else {
              int x958 = x926;
              char  *x959 = x927;
              char  *x960 = x959;
              int x961 = 1/*true*/;
              int x962 = x958;
              /*@
              loop invariant (((strlen(x960)>=0) && \valid(x960+(0..(strlen(x960)+1)-1))) && ((x962==-1) || (0<=x962)));
              loop assigns x960, x961, x962;
              */
              for (;;) {
                int x963 = x961;
                if (!x963) break;
                char  *x965 = x960;
                int x972 = 1/*true*/;
                char x973 = '\0';
                char  *x974 = 0/*null*/;
                char x966 = x965[0];
                int x967 = x966 == '\0';
                if (x967) {
                  x974 = x965;
                } else {
                  int x968 = x966 >= '0';
                  int x970;
                  if (x968) {
                    int x969 = x966 <= '9';
                    x970 = x969;
                  } else {
                    x970 = 0/*false*/;
                  }
                  if (x970) {
                    x972 = 0/*false*/;
                    x973 = x966;
                    char  *x971 = x965+1;
                    x974 = x971;
                  } else {
                    x974 = x965;
                  }
                }
                int x986 = x972;
                if (x986) {
                  char  *x987 = x974;
                  x961 = 0/*false*/;
                } else {
                  char x990 = x973;
                  char  *x992 = x974;
                  int x993 = x962;
                  int x994 = x993 < 0;
                  int x999;
                  if (x994) {
                    x999 = x993;
                  } else {
                    int x995 = x993 > x344;
                    int x998;
                    if (x995) {
                      x998 = -1;
                    } else {
                      char x991 = x990 - '0';
                      int x996 = x993 * 10;
                      int x997 = x996 + x991;
                      x998 = x997;
                    }
                    x999 = x998;
                  }
                  x962 = x999;
                  x960 = x992;
                }
              }
              int x1027 = x962;
              char  *x1028 = x960;
              x922 = 0/*false*/;
              x923 = x1027;
              x924 = x1028;
            }
            int x1034 = x922;
            if (x1034) {
              char  *x1035 = x924;
              x921 = x1035;
            } else {
              int x1038 = x923;
              char  *x1039 = x924;
              char  *x1040 = x1039;
              int x1041 = 1/*true*/;
              /*@
              loop invariant ((strlen(x1040)>=0) && \valid(x1040+(0..(strlen(x1040)+1)-1)));
              loop assigns x1040, x1041;
              */
              for (;;) {
                int x1042 = x1041;
                if (!x1042) break;
                char  *x1044 = x1040;
                char x1045 = x1044[0];
                int x1046 = x1045 == '\0';
                if (x1046) {
                  x1041 = 0/*false*/;
                } else {
                  int x1047 = x1045 == ' ';
                  if (x1047) {
                    char  *x1048 = x1044+1;
                    x1040 = x1048;
                  } else {
                    x1041 = 0/*false*/;
                  }
                }
              }
              char  *x1074 = x1040;
              x919 = 0/*false*/;
              x920 = x1038;
              x921 = x1074;
            }
            int x1080 = x919;
            if (x1080) {
              char  *x1081 = x921;
              x479 = 0/*false*/;
            } else {
              int x1084 = x920;
              char  *x1085 = x921;
              int x1090 = 1/*true*/;
              char x1091 = '\0';
              char  *x1092 = 0/*null*/;
              char x1086 = x1085[0];
              int x1087 = x1086 == '\0';
              if (x1087) {
                x1092 = x1085;
              } else {
                int x1088 = x1086 == '\n';
                if (x1088) {
                  x1090 = 0/*false*/;
                  x1091 = x1086;
                  char  *x1089 = x1085+1;
                  x1092 = x1089;
                } else {
                  x1092 = x1085;
                }
              }
              int x1104 = x1090;
              if (x1104) {
                char  *x1105 = x1092;
                x479 = 0/*false*/;
              } else {
                char x1108 = x1091;
                char  *x1109 = x1092;
                int x1110 = x480;
                int x1111 = x1084 == -2;
                int x1112;
                if (x1111) {
                  x1112 = x1110;
                } else {
                  x1112 = x1084;
                }
                x480 = x1112;
                x478 = x1109;
              }
            }
          } else {
            int x1120 = 1/*true*/;
            char  *x1122 = 0/*null*/;
            x1120 = 0/*false*/;
            x1122 = x805;
            int x1126 = x1120;
            if (x1126) {
              char  *x1127 = x1122;
              x479 = 0/*false*/;
            } else {
              char  *x1131 = x1122;
              int x1136 = 1/*true*/;
              char x1137 = '\0';
              char  *x1138 = 0/*null*/;
              char x1132 = x1131[0];
              int x1133 = x1132 == '\0';
              if (x1133) {
                x1138 = x1131;
              } else {
                int x1134 = x1132 == '\n';
                if (x1134) {
                  x1136 = 0/*false*/;
                  x1137 = x1132;
                  char  *x1135 = x1131+1;
                  x1138 = x1135;
                } else {
                  x1138 = x1131;
                }
              }
              int x1150 = x1136;
              if (x1150) {
                char  *x1151 = x1138;
                x479 = 0/*false*/;
              } else {
                char x1154 = x1137;
                char  *x1155 = x1138;
                int x1156 = x480;
                int x1158;
                if (x1157) {
                  x1158 = x1156;
                } else {
                  x1158 = -2;
                }
                x480 = x1158;
                x478 = x1155;
              }
            }
          }
        }
      }
    }
    int x1189 = x480;
    char  *x1190 = x478;
    x8 = 0/*false*/;
    x9 = x1189;
    x10 = x1190;
  }
  int x1196 = x8;
  if (x1196) {
    char  *x1197 = x10;
    x7 = x1197;
  } else {
    int x1200 = x9;
    char  *x1201 = x10;
    int x1206 = 1/*true*/;
    char x1207 = '\0';
    char  *x1208 = 0/*null*/;
    char x1202 = x1201[0];
    int x1203 = x1202 == '\0';
    if (x1203) {
      x1208 = x1201;
    } else {
      int x1204 = x1202 == '\n';
      if (x1204) {
        x1206 = 0/*false*/;
        x1207 = x1202;
        char  *x1205 = x1201+1;
        x1208 = x1205;
      } else {
        x1208 = x1201;
      }
    }
    int x1220 = x1206;
    if (x1220) {
      char  *x1221 = x1208;
      x7 = x1221;
    } else {
      char x1224 = x1207;
      char  *x1225 = x1208;
      x5 = 0/*false*/;
      x6 = x1200;
      x7 = x1225;
    }
  }
  int x1233 = x5;
  if (x1233) {
    char  *x1234 = x7;
  } else {
    int x1236 = x6;
    char  *x1237 = x7;
    char  *x1239 = x1237;
    int x1240 = 1/*true*/;
    int x1241 = 0;
    int x342 = INT_MAX;
    int x1401 = x342 / 16;
    int x1402 = x1401 - 16;
    /*@
    loop invariant (((strlen(x1239)>=0) && \valid(x1239+(0..(strlen(x1239)+1)-1))) && ((x1241==-1) || (0<=x1241)));
    loop assigns x1239, x1240, x1241;
    */
    for (;;) {
      int x1242 = x1240;
      if (!x1242) break;
      char  *x1244 = x1239;
      int x1251 = 1/*true*/;
      int x1252 = 0;
      char  *x1253 = 0/*null*/;
      int x1254 = 1/*true*/;
      int x1255 = 0;
      char  *x1256 = 0/*null*/;
      int x1257 = 1/*true*/;
      int x1258 = 0;
      char  *x1259 = 0/*null*/;
      int x1260 = 1/*true*/;
      int x1261 = 0;
      char  *x1262 = 0/*null*/;
      int x1263 = 1/*true*/;
      char x1264 = '\0';
      char  *x1265 = 0/*null*/;
      char x1245 = x1244[0];
      int x1246 = x1245 == '\0';
      if (x1246) {
        x1265 = x1244;
      } else {
        int x1247 = x1245 >= '0';
        int x1249;
        if (x1247) {
          int x1248 = x1245 <= '9';
          x1249 = x1248;
        } else {
          x1249 = 0/*false*/;
        }
        if (x1249) {
          x1263 = 0/*false*/;
          x1264 = x1245;
          char  *x1250 = x1244+1;
          x1265 = x1250;
        } else {
          x1265 = x1244;
        }
      }
      int x1277 = x1263;
      if (x1277) {
        char  *x1278 = x1265;
      } else {
        char x1280 = x1264;
        char  *x1282 = x1265;
        x1260 = 0/*false*/;
        char x1281 = x1280 - '0';
        x1261 = x1281;
        x1262 = x1282;
      }
      int x1288 = x1260;
      if (x1288) {
        int x1292 = 1/*true*/;
        char x1293 = '\0';
        char  *x1294 = 0/*null*/;
        if (x1246) {
          x1294 = x1244;
        } else {
          int x1289 = x1245 >= 'a';
          int x1291;
          if (x1289) {
            int x1290 = x1245 <= 'f';
            x1291 = x1290;
          } else {
            x1291 = 0/*false*/;
          }
          if (x1291) {
            x1292 = 0/*false*/;
            x1293 = x1245;
            char  *x1250 = x1244+1;
            x1294 = x1250;
          } else {
            x1294 = x1244;
          }
        }
        int x1306 = x1292;
        if (x1306) {
          char  *x1307 = x1294;
          x1259 = x1307;
        } else {
          char x1310 = x1293;
          char  *x1313 = x1294;
          x1257 = 0/*false*/;
          char x1311 = x1310 - 'a';
          int x1312 = 10 + x1311;
          x1258 = x1312;
          x1259 = x1313;
        }
      } else {
        int x1320 = x1261;
        char  *x1321 = x1262;
        x1257 = 0/*false*/;
        x1258 = x1320;
        x1259 = x1321;
      }
      int x1327 = x1257;
      if (x1327) {
        char  *x1328 = x1259;
        x1256 = x1328;
      } else {
        int x1331 = x1258;
        char  *x1332 = x1259;
        char  *x1333 = x1332;
        int x1334 = 1/*true*/;
        int x1335 = x1331;
        /*@
        loop invariant (((strlen(x1333)>=0) && \valid(x1333+(0..(strlen(x1333)+1)-1))) && ((x1335==-1) || (0<=x1335)));
        loop assigns x1333, x1334, x1335;
        */
        for (;;) {
          int x1336 = x1334;
          if (!x1336) break;
          char  *x1338 = x1333;
          int x1345 = 1/*true*/;
          int x1346 = 0;
          char  *x1347 = 0/*null*/;
          int x1348 = 1/*true*/;
          char x1349 = '\0';
          char  *x1350 = 0/*null*/;
          char x1339 = x1338[0];
          int x1340 = x1339 == '\0';
          if (x1340) {
            x1350 = x1338;
          } else {
            int x1341 = x1339 >= '0';
            int x1343;
            if (x1341) {
              int x1342 = x1339 <= '9';
              x1343 = x1342;
            } else {
              x1343 = 0/*false*/;
            }
            if (x1343) {
              x1348 = 0/*false*/;
              x1349 = x1339;
              char  *x1344 = x1338+1;
              x1350 = x1344;
            } else {
              x1350 = x1338;
            }
          }
          int x1362 = x1348;
          if (x1362) {
            char  *x1363 = x1350;
          } else {
            char x1365 = x1349;
            char  *x1367 = x1350;
            x1345 = 0/*false*/;
            char x1366 = x1365 - '0';
            x1346 = x1366;
            x1347 = x1367;
          }
          int x1373 = x1345;
          if (x1373) {
            int x1377 = 1/*true*/;
            char x1378 = '\0';
            char  *x1379 = 0/*null*/;
            if (x1340) {
              x1379 = x1338;
            } else {
              int x1374 = x1339 >= 'a';
              int x1376;
              if (x1374) {
                int x1375 = x1339 <= 'f';
                x1376 = x1375;
              } else {
                x1376 = 0/*false*/;
              }
              if (x1376) {
                x1377 = 0/*false*/;
                x1378 = x1339;
                char  *x1344 = x1338+1;
                x1379 = x1344;
              } else {
                x1379 = x1338;
              }
            }
            int x1391 = x1377;
            if (x1391) {
              char  *x1392 = x1379;
              x1334 = 0/*false*/;
            } else {
              char x1395 = x1378;
              char  *x1398 = x1379;
              int x1399 = x1335;
              int x1400 = x1399 < 0;
              int x1407;
              if (x1400) {
                x1407 = x1399;
              } else {
                int x1403 = x1399 > x1402;
                int x1406;
                if (x1403) {
                  x1406 = -1;
                } else {
                  char x1396 = x1395 - 'a';
                  int x1397 = 10 + x1396;
                  int x1404 = x1399 * 16;
                  int x1405 = x1404 + x1397;
                  x1406 = x1405;
                }
                x1407 = x1406;
              }
              x1335 = x1407;
              x1333 = x1398;
            }
          } else {
            int x1413 = x1346;
            char  *x1414 = x1347;
            int x1415 = x1335;
            int x1416 = x1415 < 0;
            int x1421;
            if (x1416) {
              x1421 = x1415;
            } else {
              int x1417 = x1415 > x1402;
              int x1420;
              if (x1417) {
                x1420 = -1;
              } else {
                int x1418 = x1415 * 16;
                int x1419 = x1418 + x1413;
                x1420 = x1419;
              }
              x1421 = x1420;
            }
            x1335 = x1421;
            x1333 = x1414;
          }
        }
        int x1449 = x1335;
        char  *x1450 = x1333;
        x1254 = 0/*false*/;
        x1255 = x1449;
        x1256 = x1450;
      }
      int x1456 = x1254;
      if (x1456) {
        char  *x1457 = x1256;
        x1253 = x1457;
      } else {
        int x1460 = x1255;
        char  *x1461 = x1256;
        int x1466 = 1/*true*/;
        char x1467 = '\0';
        char  *x1468 = 0/*null*/;
        char x1462 = x1461[0];
        int x1463 = x1462 == '\0';
        if (x1463) {
          x1468 = x1461;
        } else {
          int x1464 = x1462 == '\n';
          if (x1464) {
            x1466 = 0/*false*/;
            x1467 = x1462;
            char  *x1465 = x1461+1;
            x1468 = x1465;
          } else {
            x1468 = x1461;
          }
        }
        int x1480 = x1466;
        if (x1480) {
          char  *x1481 = x1468;
          x1253 = x1481;
        } else {
          char x1484 = x1467;
          char  *x1485 = x1468;
          x1251 = 0/*false*/;
          x1252 = x1460;
          x1253 = x1485;
        }
      }
      int x1493 = x1251;
      if (x1493) {
        char  *x1494 = x1253;
        x1240 = 0/*false*/;
      } else {
        int x1497 = x1252;
        char  *x1498 = x1253;
        int x1500 = 1/*true*/;
        char  *x1501 = x1498;
        /*@
        loop invariant ((0<=x1503) && ((strlen(x1501)>=0) && \valid(x1501+(0..(strlen(x1501)+1)-1))));
        loop assigns x1503, x1500, x1501;
        loop variant (x1497-x1503);
        */
        for(int x1503=0; x1503 < x1497; x1503++) {
          int x1504 = x1500;
          if (x1504) {
            char  *x1505 = x1501;
            char x1506 = x1505[0];
            int x1507 = x1506 == '\0';
            if (x1507) {
              x1500 = 0/*false*/;
            } else {
              if (1/*true*/) {
                char  *x1508 = x1505+1;
                x1501 = x1508;
              } else {
                x1500 = 0/*false*/;
              }
            }
          } else {
          }
        }
        int x1541 = x1500;
        char  *x1542 = x1501;
        int x1499 = x1497 < 0;
        if (x1499) {
          x1240 = 0/*false*/;
        } else {
          int x1545 = 1/*true*/;
          int x1546 = 0;
          char  *x1547 = 0/*null*/;
          int x1548 = 1/*true*/;
          char  *x1550 = 0/*null*/;
          if (x1541) {
            x1548 = 0/*false*/;
            x1550 = x1542;
          } else {
            x1550 = x1498;
          }
          int x1558 = x1548;
          if (x1558) {
            char  *x1559 = x1550;
            x1547 = x1559;
          } else {
            char  *x1563 = x1550;
            x1545 = 0/*false*/;
            x1546 = x1497;
            x1547 = x1563;
          }
          int x1569 = x1545;
          if (x1569) {
            char  *x1570 = x1547;
            x1240 = 0/*false*/;
          } else {
            int x1573 = x1546;
            char  *x1574 = x1547;
            int x1579 = 1/*true*/;
            char x1580 = '\0';
            char  *x1581 = 0/*null*/;
            char x1575 = x1574[0];
            int x1576 = x1575 == '\0';
            if (x1576) {
              x1581 = x1574;
            } else {
              int x1577 = x1575 == '\n';
              if (x1577) {
                x1579 = 0/*false*/;
                x1580 = x1575;
                char  *x1578 = x1574+1;
                x1581 = x1578;
              } else {
                x1581 = x1574;
              }
            }
            int x1593 = x1579;
            if (x1593) {
              char  *x1594 = x1581;
              x1240 = 0/*false*/;
            } else {
              char x1597 = x1580;
              char  *x1598 = x1581;
              int x1599 = x1241;
              int x1600 = x1599 < 0;
              int x1605;
              if (x1600) {
                x1605 = x1599;
              } else {
                int x1601 = x342 - x1573;
                int x1602 = x1599 > x1601;
                int x1604;
                if (x1602) {
                  x1604 = -1;
                } else {
                  int x1603 = x1599 + x1573;
                  x1604 = x1603;
                }
                x1605 = x1604;
              }
              x1241 = x1605;
              x1239 = x1598;
            }
          }
        }
      }
    }
    int x1639 = x1241;
    char  *x1640 = x1239;
    int x1642 = 1/*true*/;
    char  *x1643 = x1237;
    /*@
    loop invariant ((0<=x1645) && ((strlen(x1643)>=0) && \valid(x1643+(0..(strlen(x1643)+1)-1))));
    loop assigns x1645, x1642, x1643;
    loop variant (x1236-x1645);
    */
    for(int x1645=0; x1645 < x1236; x1645++) {
      int x1646 = x1642;
      if (x1646) {
        char  *x1647 = x1643;
        char x1648 = x1647[0];
        int x1649 = x1648 == '\0';
        if (x1649) {
          x1642 = 0/*false*/;
        } else {
          if (1/*true*/) {
            char  *x1650 = x1647+1;
            x1643 = x1650;
          } else {
            x1642 = 0/*false*/;
          }
        }
      } else {
      }
    }
    int x1683 = x1642;
    char  *x1684 = x1643;
    int x1238 = x1236 == -3;
    if (x1238) {
      char x1685 = x1640[0];
      int x1686 = x1685 == '\0';
      if (x1686) {
        x2 = x1639;
      } else {
      }
    } else {
      int x1641 = x1236 < 0;
      if (x1641) {
      } else {
        int x1691 = 1/*true*/;
        int x1692 = 0;
        char  *x1693 = 0/*null*/;
        int x1694 = 1/*true*/;
        char  *x1696 = 0/*null*/;
        if (x1683) {
          x1694 = 0/*false*/;
          x1696 = x1684;
        } else {
          x1696 = x1237;
        }
        int x1704 = x1694;
        if (x1704) {
          char  *x1705 = x1696;
          x1693 = x1705;
        } else {
          char  *x1709 = x1696;
          x1691 = 0/*false*/;
          x1692 = x1236;
          x1693 = x1709;
        }
        int x1715 = x1691;
        if (x1715) {
          char  *x1716 = x1693;
        } else {
          int x1718 = x1692;
          char  *x1719 = x1693;
          int x1724 = 1/*true*/;
          char x1725 = '\0';
          char  *x1726 = 0/*null*/;
          char x1720 = x1719[0];
          int x1721 = x1720 == '\0';
          if (x1721) {
            x1726 = x1719;
          } else {
            int x1722 = x1720 == '\n';
            if (x1722) {
              x1724 = 0/*false*/;
              x1725 = x1720;
              char  *x1723 = x1719+1;
              x1726 = x1723;
            } else {
              x1726 = x1719;
            }
          }
          int x1738 = x1724;
          if (x1738) {
            char  *x1739 = x1726;
          } else {
            char x1741 = x1725;
            char  *x1742 = x1726;
            char x1743 = x1742[0];
            int x1744 = x1743 == '\0';
            if (x1744) {
              x2 = x1718;
            } else {
            }
          }
        }
      }
    }
  }
  int x1758 = x2;
  return x1758;
}
/*@
requires ((strlen(x1777)>=0) && \valid(x1777+(0..(strlen(x1777)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_HTTP(char  * x1777) {
  char  *x1779 = x1777;
  int x1784 = 1/*true*/;
  char x1785 = '\0';
  char  *x1786 = 0/*null*/;
  char x1780 = x1777[0];
  int x1781 = x1780 == '\0';
  if (x1781) {
    x1786 = x1777;
  } else {
    int x1782 = x1780 == 'H';
    if (x1782) {
      x1784 = 0/*false*/;
      x1785 = x1780;
      char  *x1783 = x1777+1;
      x1786 = x1783;
    } else {
      x1786 = x1777;
    }
  }
  int x1798 = x1784;
  if (x1798) {
    char  *x1799 = x1786;
    x1779 = 0;
  } else {
    char x1802 = x1785;
    char  *x1803 = x1786;
    int x1808 = 1/*true*/;
    char x1809 = '\0';
    char  *x1810 = 0/*null*/;
    char x1804 = x1803[0];
    int x1805 = x1804 == '\0';
    if (x1805) {
      x1810 = x1803;
    } else {
      int x1806 = x1804 == 'T';
      if (x1806) {
        x1808 = 0/*false*/;
        x1809 = x1804;
        char  *x1807 = x1803+1;
        x1810 = x1807;
      } else {
        x1810 = x1803;
      }
    }
    int x1822 = x1808;
    if (x1822) {
      char  *x1823 = x1810;
      x1779 = 0;
    } else {
      char x1826 = x1809;
      char  *x1827 = x1810;
      int x1832 = 1/*true*/;
      char x1833 = '\0';
      char  *x1834 = 0/*null*/;
      char x1828 = x1827[0];
      int x1829 = x1828 == '\0';
      if (x1829) {
        x1834 = x1827;
      } else {
        int x1830 = x1828 == 'T';
        if (x1830) {
          x1832 = 0/*false*/;
          x1833 = x1828;
          char  *x1831 = x1827+1;
          x1834 = x1831;
        } else {
          x1834 = x1827;
        }
      }
      int x1846 = x1832;
      if (x1846) {
        char  *x1847 = x1834;
        x1779 = 0;
      } else {
        char x1850 = x1833;
        char  *x1851 = x1834;
        int x1856 = 1/*true*/;
        char x1857 = '\0';
        char  *x1858 = 0/*null*/;
        char x1852 = x1851[0];
        int x1853 = x1852 == '\0';
        if (x1853) {
          x1858 = x1851;
        } else {
          int x1854 = x1852 == 'P';
          if (x1854) {
            x1856 = 0/*false*/;
            x1857 = x1852;
            char  *x1855 = x1851+1;
            x1858 = x1855;
          } else {
            x1858 = x1851;
          }
        }
        int x1870 = x1856;
        if (x1870) {
          char  *x1871 = x1858;
          x1779 = 0;
        } else {
          char x1874 = x1857;
          char  *x1875 = x1858;
          int x1880 = 1/*true*/;
          char x1881 = '\0';
          char  *x1882 = 0/*null*/;
          char x1876 = x1875[0];
          int x1877 = x1876 == '\0';
          if (x1877) {
            x1882 = x1875;
          } else {
            int x1878 = x1876 == '/';
            if (x1878) {
              x1880 = 0/*false*/;
              x1881 = x1876;
              char  *x1879 = x1875+1;
              x1882 = x1879;
            } else {
              x1882 = x1875;
            }
          }
          int x1894 = x1880;
          if (x1894) {
            char  *x1895 = x1882;
            x1779 = 0;
          } else {
            char x1898 = x1881;
            char  *x1899 = x1882;
            x1779 = x1899;
          }
        }
      }
    }
  }
  char  *x1911 = x1779;
  return x1911;
}
/*@
requires ((strlen(x1933)>=0) && \valid(x1933+(0..(strlen(x1933)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_ContentLength(char  * x1933) {
  char  *x1935 = x1933;
  int x1940 = 1/*true*/;
  char x1941 = '\0';
  char  *x1942 = 0/*null*/;
  char x1936 = x1933[0];
  int x1937 = x1936 == '\0';
  if (x1937) {
    x1942 = x1933;
  } else {
    int x1938 = x1936 == 'C';
    if (x1938) {
      x1940 = 0/*false*/;
      x1941 = x1936;
      char  *x1939 = x1933+1;
      x1942 = x1939;
    } else {
      x1942 = x1933;
    }
  }
  int x1954 = x1940;
  if (x1954) {
    char  *x1955 = x1942;
    x1935 = 0;
  } else {
    char x1958 = x1941;
    char  *x1959 = x1942;
    int x1964 = 1/*true*/;
    char x1965 = '\0';
    char  *x1966 = 0/*null*/;
    char x1960 = x1959[0];
    int x1961 = x1960 == '\0';
    if (x1961) {
      x1966 = x1959;
    } else {
      int x1962 = x1960 == 'o';
      if (x1962) {
        x1964 = 0/*false*/;
        x1965 = x1960;
        char  *x1963 = x1959+1;
        x1966 = x1963;
      } else {
        x1966 = x1959;
      }
    }
    int x1978 = x1964;
    if (x1978) {
      char  *x1979 = x1966;
      x1935 = 0;
    } else {
      char x1982 = x1965;
      char  *x1983 = x1966;
      int x1988 = 1/*true*/;
      char x1989 = '\0';
      char  *x1990 = 0/*null*/;
      char x1984 = x1983[0];
      int x1985 = x1984 == '\0';
      if (x1985) {
        x1990 = x1983;
      } else {
        int x1986 = x1984 == 'n';
        if (x1986) {
          x1988 = 0/*false*/;
          x1989 = x1984;
          char  *x1987 = x1983+1;
          x1990 = x1987;
        } else {
          x1990 = x1983;
        }
      }
      int x2002 = x1988;
      if (x2002) {
        char  *x2003 = x1990;
        x1935 = 0;
      } else {
        char x2006 = x1989;
        char  *x2007 = x1990;
        int x2012 = 1/*true*/;
        char x2013 = '\0';
        char  *x2014 = 0/*null*/;
        char x2008 = x2007[0];
        int x2009 = x2008 == '\0';
        if (x2009) {
          x2014 = x2007;
        } else {
          int x2010 = x2008 == 't';
          if (x2010) {
            x2012 = 0/*false*/;
            x2013 = x2008;
            char  *x2011 = x2007+1;
            x2014 = x2011;
          } else {
            x2014 = x2007;
          }
        }
        int x2026 = x2012;
        if (x2026) {
          char  *x2027 = x2014;
          x1935 = 0;
        } else {
          char x2030 = x2013;
          char  *x2031 = x2014;
          int x2036 = 1/*true*/;
          char x2037 = '\0';
          char  *x2038 = 0/*null*/;
          char x2032 = x2031[0];
          int x2033 = x2032 == '\0';
          if (x2033) {
            x2038 = x2031;
          } else {
            int x2034 = x2032 == 'e';
            if (x2034) {
              x2036 = 0/*false*/;
              x2037 = x2032;
              char  *x2035 = x2031+1;
              x2038 = x2035;
            } else {
              x2038 = x2031;
            }
          }
          int x2050 = x2036;
          if (x2050) {
            char  *x2051 = x2038;
            x1935 = 0;
          } else {
            char x2054 = x2037;
            char  *x2055 = x2038;
            int x2060 = 1/*true*/;
            char x2061 = '\0';
            char  *x2062 = 0/*null*/;
            char x2056 = x2055[0];
            int x2057 = x2056 == '\0';
            if (x2057) {
              x2062 = x2055;
            } else {
              int x2058 = x2056 == 'n';
              if (x2058) {
                x2060 = 0/*false*/;
                x2061 = x2056;
                char  *x2059 = x2055+1;
                x2062 = x2059;
              } else {
                x2062 = x2055;
              }
            }
            int x2074 = x2060;
            if (x2074) {
              char  *x2075 = x2062;
              x1935 = 0;
            } else {
              char x2078 = x2061;
              char  *x2079 = x2062;
              int x2084 = 1/*true*/;
              char x2085 = '\0';
              char  *x2086 = 0/*null*/;
              char x2080 = x2079[0];
              int x2081 = x2080 == '\0';
              if (x2081) {
                x2086 = x2079;
              } else {
                int x2082 = x2080 == 't';
                if (x2082) {
                  x2084 = 0/*false*/;
                  x2085 = x2080;
                  char  *x2083 = x2079+1;
                  x2086 = x2083;
                } else {
                  x2086 = x2079;
                }
              }
              int x2098 = x2084;
              if (x2098) {
                char  *x2099 = x2086;
                x1935 = 0;
              } else {
                char x2102 = x2085;
                char  *x2103 = x2086;
                int x2108 = 1/*true*/;
                char x2109 = '\0';
                char  *x2110 = 0/*null*/;
                char x2104 = x2103[0];
                int x2105 = x2104 == '\0';
                if (x2105) {
                  x2110 = x2103;
                } else {
                  int x2106 = x2104 == '-';
                  if (x2106) {
                    x2108 = 0/*false*/;
                    x2109 = x2104;
                    char  *x2107 = x2103+1;
                    x2110 = x2107;
                  } else {
                    x2110 = x2103;
                  }
                }
                int x2122 = x2108;
                if (x2122) {
                  char  *x2123 = x2110;
                  x1935 = 0;
                } else {
                  char x2126 = x2109;
                  char  *x2127 = x2110;
                  int x2132 = 1/*true*/;
                  char x2133 = '\0';
                  char  *x2134 = 0/*null*/;
                  char x2128 = x2127[0];
                  int x2129 = x2128 == '\0';
                  if (x2129) {
                    x2134 = x2127;
                  } else {
                    int x2130 = x2128 == 'L';
                    if (x2130) {
                      x2132 = 0/*false*/;
                      x2133 = x2128;
                      char  *x2131 = x2127+1;
                      x2134 = x2131;
                    } else {
                      x2134 = x2127;
                    }
                  }
                  int x2146 = x2132;
                  if (x2146) {
                    char  *x2147 = x2134;
                    x1935 = 0;
                  } else {
                    char x2150 = x2133;
                    char  *x2151 = x2134;
                    int x2156 = 1/*true*/;
                    char x2157 = '\0';
                    char  *x2158 = 0/*null*/;
                    char x2152 = x2151[0];
                    int x2153 = x2152 == '\0';
                    if (x2153) {
                      x2158 = x2151;
                    } else {
                      int x2154 = x2152 == 'e';
                      if (x2154) {
                        x2156 = 0/*false*/;
                        x2157 = x2152;
                        char  *x2155 = x2151+1;
                        x2158 = x2155;
                      } else {
                        x2158 = x2151;
                      }
                    }
                    int x2170 = x2156;
                    if (x2170) {
                      char  *x2171 = x2158;
                      x1935 = 0;
                    } else {
                      char x2174 = x2157;
                      char  *x2175 = x2158;
                      int x2180 = 1/*true*/;
                      char x2181 = '\0';
                      char  *x2182 = 0/*null*/;
                      char x2176 = x2175[0];
                      int x2177 = x2176 == '\0';
                      if (x2177) {
                        x2182 = x2175;
                      } else {
                        int x2178 = x2176 == 'n';
                        if (x2178) {
                          x2180 = 0/*false*/;
                          x2181 = x2176;
                          char  *x2179 = x2175+1;
                          x2182 = x2179;
                        } else {
                          x2182 = x2175;
                        }
                      }
                      int x2194 = x2180;
                      if (x2194) {
                        char  *x2195 = x2182;
                        x1935 = 0;
                      } else {
                        char x2198 = x2181;
                        char  *x2199 = x2182;
                        int x2204 = 1/*true*/;
                        char x2205 = '\0';
                        char  *x2206 = 0/*null*/;
                        char x2200 = x2199[0];
                        int x2201 = x2200 == '\0';
                        if (x2201) {
                          x2206 = x2199;
                        } else {
                          int x2202 = x2200 == 'g';
                          if (x2202) {
                            x2204 = 0/*false*/;
                            x2205 = x2200;
                            char  *x2203 = x2199+1;
                            x2206 = x2203;
                          } else {
                            x2206 = x2199;
                          }
                        }
                        int x2218 = x2204;
                        if (x2218) {
                          char  *x2219 = x2206;
                          x1935 = 0;
                        } else {
                          char x2222 = x2205;
                          char  *x2223 = x2206;
                          int x2228 = 1/*true*/;
                          char x2229 = '\0';
                          char  *x2230 = 0/*null*/;
                          char x2224 = x2223[0];
                          int x2225 = x2224 == '\0';
                          if (x2225) {
                            x2230 = x2223;
                          } else {
                            int x2226 = x2224 == 't';
                            if (x2226) {
                              x2228 = 0/*false*/;
                              x2229 = x2224;
                              char  *x2227 = x2223+1;
                              x2230 = x2227;
                            } else {
                              x2230 = x2223;
                            }
                          }
                          int x2242 = x2228;
                          if (x2242) {
                            char  *x2243 = x2230;
                            x1935 = 0;
                          } else {
                            char x2246 = x2229;
                            char  *x2247 = x2230;
                            int x2252 = 1/*true*/;
                            char x2253 = '\0';
                            char  *x2254 = 0/*null*/;
                            char x2248 = x2247[0];
                            int x2249 = x2248 == '\0';
                            if (x2249) {
                              x2254 = x2247;
                            } else {
                              int x2250 = x2248 == 'h';
                              if (x2250) {
                                x2252 = 0/*false*/;
                                x2253 = x2248;
                                char  *x2251 = x2247+1;
                                x2254 = x2251;
                              } else {
                                x2254 = x2247;
                              }
                            }
                            int x2266 = x2252;
                            if (x2266) {
                              char  *x2267 = x2254;
                              x1935 = 0;
                            } else {
                              char x2270 = x2253;
                              char  *x2271 = x2254;
                              x1935 = x2271;
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
  char  *x2301 = x1935;
  return x2301;
}
/*@
requires ((strlen(x2323)>=0) && \valid(x2323+(0..(strlen(x2323)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_TransferEncoding(char  * x2323) {
  char  *x2325 = x2323;
  int x2330 = 1/*true*/;
  char x2331 = '\0';
  char  *x2332 = 0/*null*/;
  char x2326 = x2323[0];
  int x2327 = x2326 == '\0';
  if (x2327) {
    x2332 = x2323;
  } else {
    int x2328 = x2326 == 'T';
    if (x2328) {
      x2330 = 0/*false*/;
      x2331 = x2326;
      char  *x2329 = x2323+1;
      x2332 = x2329;
    } else {
      x2332 = x2323;
    }
  }
  int x2344 = x2330;
  if (x2344) {
    char  *x2345 = x2332;
    x2325 = 0;
  } else {
    char x2348 = x2331;
    char  *x2349 = x2332;
    int x2354 = 1/*true*/;
    char x2355 = '\0';
    char  *x2356 = 0/*null*/;
    char x2350 = x2349[0];
    int x2351 = x2350 == '\0';
    if (x2351) {
      x2356 = x2349;
    } else {
      int x2352 = x2350 == 'r';
      if (x2352) {
        x2354 = 0/*false*/;
        x2355 = x2350;
        char  *x2353 = x2349+1;
        x2356 = x2353;
      } else {
        x2356 = x2349;
      }
    }
    int x2368 = x2354;
    if (x2368) {
      char  *x2369 = x2356;
      x2325 = 0;
    } else {
      char x2372 = x2355;
      char  *x2373 = x2356;
      int x2378 = 1/*true*/;
      char x2379 = '\0';
      char  *x2380 = 0/*null*/;
      char x2374 = x2373[0];
      int x2375 = x2374 == '\0';
      if (x2375) {
        x2380 = x2373;
      } else {
        int x2376 = x2374 == 'a';
        if (x2376) {
          x2378 = 0/*false*/;
          x2379 = x2374;
          char  *x2377 = x2373+1;
          x2380 = x2377;
        } else {
          x2380 = x2373;
        }
      }
      int x2392 = x2378;
      if (x2392) {
        char  *x2393 = x2380;
        x2325 = 0;
      } else {
        char x2396 = x2379;
        char  *x2397 = x2380;
        int x2402 = 1/*true*/;
        char x2403 = '\0';
        char  *x2404 = 0/*null*/;
        char x2398 = x2397[0];
        int x2399 = x2398 == '\0';
        if (x2399) {
          x2404 = x2397;
        } else {
          int x2400 = x2398 == 'n';
          if (x2400) {
            x2402 = 0/*false*/;
            x2403 = x2398;
            char  *x2401 = x2397+1;
            x2404 = x2401;
          } else {
            x2404 = x2397;
          }
        }
        int x2416 = x2402;
        if (x2416) {
          char  *x2417 = x2404;
          x2325 = 0;
        } else {
          char x2420 = x2403;
          char  *x2421 = x2404;
          int x2426 = 1/*true*/;
          char x2427 = '\0';
          char  *x2428 = 0/*null*/;
          char x2422 = x2421[0];
          int x2423 = x2422 == '\0';
          if (x2423) {
            x2428 = x2421;
          } else {
            int x2424 = x2422 == 's';
            if (x2424) {
              x2426 = 0/*false*/;
              x2427 = x2422;
              char  *x2425 = x2421+1;
              x2428 = x2425;
            } else {
              x2428 = x2421;
            }
          }
          int x2440 = x2426;
          if (x2440) {
            char  *x2441 = x2428;
            x2325 = 0;
          } else {
            char x2444 = x2427;
            char  *x2445 = x2428;
            int x2450 = 1/*true*/;
            char x2451 = '\0';
            char  *x2452 = 0/*null*/;
            char x2446 = x2445[0];
            int x2447 = x2446 == '\0';
            if (x2447) {
              x2452 = x2445;
            } else {
              int x2448 = x2446 == 'f';
              if (x2448) {
                x2450 = 0/*false*/;
                x2451 = x2446;
                char  *x2449 = x2445+1;
                x2452 = x2449;
              } else {
                x2452 = x2445;
              }
            }
            int x2464 = x2450;
            if (x2464) {
              char  *x2465 = x2452;
              x2325 = 0;
            } else {
              char x2468 = x2451;
              char  *x2469 = x2452;
              int x2474 = 1/*true*/;
              char x2475 = '\0';
              char  *x2476 = 0/*null*/;
              char x2470 = x2469[0];
              int x2471 = x2470 == '\0';
              if (x2471) {
                x2476 = x2469;
              } else {
                int x2472 = x2470 == 'e';
                if (x2472) {
                  x2474 = 0/*false*/;
                  x2475 = x2470;
                  char  *x2473 = x2469+1;
                  x2476 = x2473;
                } else {
                  x2476 = x2469;
                }
              }
              int x2488 = x2474;
              if (x2488) {
                char  *x2489 = x2476;
                x2325 = 0;
              } else {
                char x2492 = x2475;
                char  *x2493 = x2476;
                int x2498 = 1/*true*/;
                char x2499 = '\0';
                char  *x2500 = 0/*null*/;
                char x2494 = x2493[0];
                int x2495 = x2494 == '\0';
                if (x2495) {
                  x2500 = x2493;
                } else {
                  int x2496 = x2494 == 'r';
                  if (x2496) {
                    x2498 = 0/*false*/;
                    x2499 = x2494;
                    char  *x2497 = x2493+1;
                    x2500 = x2497;
                  } else {
                    x2500 = x2493;
                  }
                }
                int x2512 = x2498;
                if (x2512) {
                  char  *x2513 = x2500;
                  x2325 = 0;
                } else {
                  char x2516 = x2499;
                  char  *x2517 = x2500;
                  int x2522 = 1/*true*/;
                  char x2523 = '\0';
                  char  *x2524 = 0/*null*/;
                  char x2518 = x2517[0];
                  int x2519 = x2518 == '\0';
                  if (x2519) {
                    x2524 = x2517;
                  } else {
                    int x2520 = x2518 == '-';
                    if (x2520) {
                      x2522 = 0/*false*/;
                      x2523 = x2518;
                      char  *x2521 = x2517+1;
                      x2524 = x2521;
                    } else {
                      x2524 = x2517;
                    }
                  }
                  int x2536 = x2522;
                  if (x2536) {
                    char  *x2537 = x2524;
                    x2325 = 0;
                  } else {
                    char x2540 = x2523;
                    char  *x2541 = x2524;
                    int x2546 = 1/*true*/;
                    char x2547 = '\0';
                    char  *x2548 = 0/*null*/;
                    char x2542 = x2541[0];
                    int x2543 = x2542 == '\0';
                    if (x2543) {
                      x2548 = x2541;
                    } else {
                      int x2544 = x2542 == 'E';
                      if (x2544) {
                        x2546 = 0/*false*/;
                        x2547 = x2542;
                        char  *x2545 = x2541+1;
                        x2548 = x2545;
                      } else {
                        x2548 = x2541;
                      }
                    }
                    int x2560 = x2546;
                    if (x2560) {
                      char  *x2561 = x2548;
                      x2325 = 0;
                    } else {
                      char x2564 = x2547;
                      char  *x2565 = x2548;
                      int x2570 = 1/*true*/;
                      char x2571 = '\0';
                      char  *x2572 = 0/*null*/;
                      char x2566 = x2565[0];
                      int x2567 = x2566 == '\0';
                      if (x2567) {
                        x2572 = x2565;
                      } else {
                        int x2568 = x2566 == 'n';
                        if (x2568) {
                          x2570 = 0/*false*/;
                          x2571 = x2566;
                          char  *x2569 = x2565+1;
                          x2572 = x2569;
                        } else {
                          x2572 = x2565;
                        }
                      }
                      int x2584 = x2570;
                      if (x2584) {
                        char  *x2585 = x2572;
                        x2325 = 0;
                      } else {
                        char x2588 = x2571;
                        char  *x2589 = x2572;
                        int x2594 = 1/*true*/;
                        char x2595 = '\0';
                        char  *x2596 = 0/*null*/;
                        char x2590 = x2589[0];
                        int x2591 = x2590 == '\0';
                        if (x2591) {
                          x2596 = x2589;
                        } else {
                          int x2592 = x2590 == 'c';
                          if (x2592) {
                            x2594 = 0/*false*/;
                            x2595 = x2590;
                            char  *x2593 = x2589+1;
                            x2596 = x2593;
                          } else {
                            x2596 = x2589;
                          }
                        }
                        int x2608 = x2594;
                        if (x2608) {
                          char  *x2609 = x2596;
                          x2325 = 0;
                        } else {
                          char x2612 = x2595;
                          char  *x2613 = x2596;
                          int x2618 = 1/*true*/;
                          char x2619 = '\0';
                          char  *x2620 = 0/*null*/;
                          char x2614 = x2613[0];
                          int x2615 = x2614 == '\0';
                          if (x2615) {
                            x2620 = x2613;
                          } else {
                            int x2616 = x2614 == 'o';
                            if (x2616) {
                              x2618 = 0/*false*/;
                              x2619 = x2614;
                              char  *x2617 = x2613+1;
                              x2620 = x2617;
                            } else {
                              x2620 = x2613;
                            }
                          }
                          int x2632 = x2618;
                          if (x2632) {
                            char  *x2633 = x2620;
                            x2325 = 0;
                          } else {
                            char x2636 = x2619;
                            char  *x2637 = x2620;
                            int x2642 = 1/*true*/;
                            char x2643 = '\0';
                            char  *x2644 = 0/*null*/;
                            char x2638 = x2637[0];
                            int x2639 = x2638 == '\0';
                            if (x2639) {
                              x2644 = x2637;
                            } else {
                              int x2640 = x2638 == 'd';
                              if (x2640) {
                                x2642 = 0/*false*/;
                                x2643 = x2638;
                                char  *x2641 = x2637+1;
                                x2644 = x2641;
                              } else {
                                x2644 = x2637;
                              }
                            }
                            int x2656 = x2642;
                            if (x2656) {
                              char  *x2657 = x2644;
                              x2325 = 0;
                            } else {
                              char x2660 = x2643;
                              char  *x2661 = x2644;
                              int x2666 = 1/*true*/;
                              char x2667 = '\0';
                              char  *x2668 = 0/*null*/;
                              char x2662 = x2661[0];
                              int x2663 = x2662 == '\0';
                              if (x2663) {
                                x2668 = x2661;
                              } else {
                                int x2664 = x2662 == 'i';
                                if (x2664) {
                                  x2666 = 0/*false*/;
                                  x2667 = x2662;
                                  char  *x2665 = x2661+1;
                                  x2668 = x2665;
                                } else {
                                  x2668 = x2661;
                                }
                              }
                              int x2680 = x2666;
                              if (x2680) {
                                char  *x2681 = x2668;
                                x2325 = 0;
                              } else {
                                char x2684 = x2667;
                                char  *x2685 = x2668;
                                int x2690 = 1/*true*/;
                                char x2691 = '\0';
                                char  *x2692 = 0/*null*/;
                                char x2686 = x2685[0];
                                int x2687 = x2686 == '\0';
                                if (x2687) {
                                  x2692 = x2685;
                                } else {
                                  int x2688 = x2686 == 'n';
                                  if (x2688) {
                                    x2690 = 0/*false*/;
                                    x2691 = x2686;
                                    char  *x2689 = x2685+1;
                                    x2692 = x2689;
                                  } else {
                                    x2692 = x2685;
                                  }
                                }
                                int x2704 = x2690;
                                if (x2704) {
                                  char  *x2705 = x2692;
                                  x2325 = 0;
                                } else {
                                  char x2708 = x2691;
                                  char  *x2709 = x2692;
                                  int x2714 = 1/*true*/;
                                  char x2715 = '\0';
                                  char  *x2716 = 0/*null*/;
                                  char x2710 = x2709[0];
                                  int x2711 = x2710 == '\0';
                                  if (x2711) {
                                    x2716 = x2709;
                                  } else {
                                    int x2712 = x2710 == 'g';
                                    if (x2712) {
                                      x2714 = 0/*false*/;
                                      x2715 = x2710;
                                      char  *x2713 = x2709+1;
                                      x2716 = x2713;
                                    } else {
                                      x2716 = x2709;
                                    }
                                  }
                                  int x2728 = x2714;
                                  if (x2728) {
                                    char  *x2729 = x2716;
                                    x2325 = 0;
                                  } else {
                                    char x2732 = x2715;
                                    char  *x2733 = x2716;
                                    x2325 = x2733;
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
      }
    }
  }
  char  *x2769 = x2325;
  return x2769;
}
/*@
requires ((strlen(x2791)>=0) && \valid(x2791+(0..(strlen(x2791)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_chunked(char  * x2791) {
  char  *x2793 = x2791;
  int x2798 = 1/*true*/;
  char x2799 = '\0';
  char  *x2800 = 0/*null*/;
  char x2794 = x2791[0];
  int x2795 = x2794 == '\0';
  if (x2795) {
    x2800 = x2791;
  } else {
    int x2796 = x2794 == 'c';
    if (x2796) {
      x2798 = 0/*false*/;
      x2799 = x2794;
      char  *x2797 = x2791+1;
      x2800 = x2797;
    } else {
      x2800 = x2791;
    }
  }
  int x2812 = x2798;
  if (x2812) {
    char  *x2813 = x2800;
    x2793 = 0;
  } else {
    char x2816 = x2799;
    char  *x2817 = x2800;
    int x2822 = 1/*true*/;
    char x2823 = '\0';
    char  *x2824 = 0/*null*/;
    char x2818 = x2817[0];
    int x2819 = x2818 == '\0';
    if (x2819) {
      x2824 = x2817;
    } else {
      int x2820 = x2818 == 'h';
      if (x2820) {
        x2822 = 0/*false*/;
        x2823 = x2818;
        char  *x2821 = x2817+1;
        x2824 = x2821;
      } else {
        x2824 = x2817;
      }
    }
    int x2836 = x2822;
    if (x2836) {
      char  *x2837 = x2824;
      x2793 = 0;
    } else {
      char x2840 = x2823;
      char  *x2841 = x2824;
      int x2846 = 1/*true*/;
      char x2847 = '\0';
      char  *x2848 = 0/*null*/;
      char x2842 = x2841[0];
      int x2843 = x2842 == '\0';
      if (x2843) {
        x2848 = x2841;
      } else {
        int x2844 = x2842 == 'u';
        if (x2844) {
          x2846 = 0/*false*/;
          x2847 = x2842;
          char  *x2845 = x2841+1;
          x2848 = x2845;
        } else {
          x2848 = x2841;
        }
      }
      int x2860 = x2846;
      if (x2860) {
        char  *x2861 = x2848;
        x2793 = 0;
      } else {
        char x2864 = x2847;
        char  *x2865 = x2848;
        int x2870 = 1/*true*/;
        char x2871 = '\0';
        char  *x2872 = 0/*null*/;
        char x2866 = x2865[0];
        int x2867 = x2866 == '\0';
        if (x2867) {
          x2872 = x2865;
        } else {
          int x2868 = x2866 == 'n';
          if (x2868) {
            x2870 = 0/*false*/;
            x2871 = x2866;
            char  *x2869 = x2865+1;
            x2872 = x2869;
          } else {
            x2872 = x2865;
          }
        }
        int x2884 = x2870;
        if (x2884) {
          char  *x2885 = x2872;
          x2793 = 0;
        } else {
          char x2888 = x2871;
          char  *x2889 = x2872;
          int x2894 = 1/*true*/;
          char x2895 = '\0';
          char  *x2896 = 0/*null*/;
          char x2890 = x2889[0];
          int x2891 = x2890 == '\0';
          if (x2891) {
            x2896 = x2889;
          } else {
            int x2892 = x2890 == 'k';
            if (x2892) {
              x2894 = 0/*false*/;
              x2895 = x2890;
              char  *x2893 = x2889+1;
              x2896 = x2893;
            } else {
              x2896 = x2889;
            }
          }
          int x2908 = x2894;
          if (x2908) {
            char  *x2909 = x2896;
            x2793 = 0;
          } else {
            char x2912 = x2895;
            char  *x2913 = x2896;
            int x2918 = 1/*true*/;
            char x2919 = '\0';
            char  *x2920 = 0/*null*/;
            char x2914 = x2913[0];
            int x2915 = x2914 == '\0';
            if (x2915) {
              x2920 = x2913;
            } else {
              int x2916 = x2914 == 'e';
              if (x2916) {
                x2918 = 0/*false*/;
                x2919 = x2914;
                char  *x2917 = x2913+1;
                x2920 = x2917;
              } else {
                x2920 = x2913;
              }
            }
            int x2932 = x2918;
            if (x2932) {
              char  *x2933 = x2920;
              x2793 = 0;
            } else {
              char x2936 = x2919;
              char  *x2937 = x2920;
              int x2942 = 1/*true*/;
              char x2943 = '\0';
              char  *x2944 = 0/*null*/;
              char x2938 = x2937[0];
              int x2939 = x2938 == '\0';
              if (x2939) {
                x2944 = x2937;
              } else {
                int x2940 = x2938 == 'd';
                if (x2940) {
                  x2942 = 0/*false*/;
                  x2943 = x2938;
                  char  *x2941 = x2937+1;
                  x2944 = x2941;
                } else {
                  x2944 = x2937;
                }
              }
              int x2956 = x2942;
              if (x2956) {
                char  *x2957 = x2944;
                x2793 = 0;
              } else {
                char x2960 = x2943;
                char  *x2961 = x2944;
                x2793 = x2961;
              }
            }
          }
        }
      }
    }
  }
  char  *x2977 = x2793;
  return x2977;
}
