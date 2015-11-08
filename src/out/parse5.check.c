#include <limits.h>
#include <string.h>
char  * p_chunked(char  * x1730);
char  * p_TransferEncoding(char  * x1732);
char  * p_ContentLength(char  * x1734);
char  * p_HTTP(char  * x1736);
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..strlen(x0))));
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
      loop invariant ((strlen(x71)>=0) && \valid(x71+(0..strlen(x71))));
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
      char  *x105 = x71;
      x26 = 0/*false*/;
      x28 = x105;
    }
  }
  int x113 = x26;
  if (x113) {
    char  *x114 = x28;
    x25 = x114;
  } else {
    char  *x118 = x28;
    char x119 = x118[0];
    int x120 = x119 == '\0';
    if (x120) {
      x25 = x118;
    } else {
      int x121 = x119 == '.';
      if (x121) {
        x23 = 0/*false*/;
        x24 = x119;
        char  *x122 = x118+1;
        x25 = x122;
      } else {
        x25 = x118;
      }
    }
  }
  int x136 = x23;
  if (x136) {
    char  *x137 = x25;
    x22 = x137;
  } else {
    char x140 = x24;
    char  *x141 = x25;
    int x148 = 1/*true*/;
    char x149 = '\0';
    char  *x150 = 0/*null*/;
    char x142 = x141[0];
    int x143 = x142 == '\0';
    if (x143) {
      x150 = x141;
    } else {
      int x144 = x142 >= '0';
      int x146;
      if (x144) {
        int x145 = x142 <= '9';
        x146 = x145;
      } else {
        x146 = 0/*false*/;
      }
      if (x146) {
        x148 = 0/*false*/;
        x149 = x142;
        char  *x147 = x141+1;
        x150 = x147;
      } else {
        x150 = x141;
      }
    }
    int x162 = x148;
    if (x162) {
      char  *x163 = x150;
      x22 = x163;
    } else {
      char x166 = x149;
      char  *x167 = x150;
      char  *x168 = x167;
      int x169 = 1/*true*/;
      /*@
      loop invariant ((strlen(x168)>=0) && \valid(x168+(0..strlen(x168))));
      loop assigns x168, x169;
      */
      for (;;) {
        int x170 = x169;
        if (!x170) break;
        char  *x172 = x168;
        char x173 = x172[0];
        int x174 = x173 == '\0';
        if (x174) {
          x169 = 0/*false*/;
        } else {
          int x175 = x173 >= '0';
          int x177;
          if (x175) {
            int x176 = x173 <= '9';
            x177 = x176;
          } else {
            x177 = 0/*false*/;
          }
          if (x177) {
            char  *x178 = x172+1;
            x168 = x178;
          } else {
            x169 = 0/*false*/;
          }
        }
      }
      char  *x202 = x168;
      x20 = 0/*false*/;
      x22 = x202;
    }
  }
  int x210 = x20;
  if (x210) {
    char  *x211 = x22;
    x19 = x211;
  } else {
    char  *x215 = x22;
    char  *x216 = x215;
    int x217 = 1/*true*/;
    /*@
    loop invariant ((strlen(x216)>=0) && \valid(x216+(0..strlen(x216))));
    loop assigns x216, x217;
    */
    for (;;) {
      int x218 = x217;
      if (!x218) break;
      char  *x220 = x216;
      char x221 = x220[0];
      int x222 = x221 == '\0';
      if (x222) {
        x217 = 0/*false*/;
      } else {
        int x223 = x221 == ' ';
        if (x223) {
          char  *x224 = x220+1;
          x216 = x224;
        } else {
          x217 = 0/*false*/;
        }
      }
    }
    char  *x248 = x216;
    x17 = 0/*false*/;
    x19 = x248;
  }
  int x254 = x17;
  if (x254) {
    char  *x255 = x19;
    x16 = x255;
  } else {
    char  *x259 = x19;
    int x266 = 1/*true*/;
    int x267 = 0;
    char  *x268 = 0/*null*/;
    int x269 = 1/*true*/;
    char x270 = '\0';
    char  *x271 = 0/*null*/;
    char x260 = x259[0];
    int x261 = x260 == '\0';
    if (x261) {
      x271 = x259;
    } else {
      int x262 = x260 >= '0';
      int x264;
      if (x262) {
        int x263 = x260 <= '9';
        x264 = x263;
      } else {
        x264 = 0/*false*/;
      }
      if (x264) {
        x269 = 0/*false*/;
        x270 = x260;
        char  *x265 = x259+1;
        x271 = x265;
      } else {
        x271 = x259;
      }
    }
    int x283 = x269;
    if (x283) {
      char  *x284 = x271;
      x268 = x284;
    } else {
      char x287 = x270;
      char  *x289 = x271;
      x266 = 0/*false*/;
      char x288 = x287 - '0';
      x267 = x288;
      x268 = x289;
    }
    int x295 = x266;
    if (x295) {
      char  *x296 = x268;
      x16 = x296;
    } else {
      int x299 = x267;
      char  *x300 = x268;
      char  *x301 = x300;
      int x302 = 1/*true*/;
      int x303 = x299;
      int x336 = INT_MAX;
      int x337 = x336 / 10;
      int x338 = x337 - 10;
      /*@
      loop invariant (((strlen(x301)>=0) && \valid(x301+(0..strlen(x301)))) && ((x303==-1) || (0<=x303)));
      loop assigns x301, x302, x303;
      */
      for (;;) {
        int x304 = x302;
        if (!x304) break;
        char  *x306 = x301;
        int x313 = 1/*true*/;
        char x314 = '\0';
        char  *x315 = 0/*null*/;
        char x307 = x306[0];
        int x308 = x307 == '\0';
        if (x308) {
          x315 = x306;
        } else {
          int x309 = x307 >= '0';
          int x311;
          if (x309) {
            int x310 = x307 <= '9';
            x311 = x310;
          } else {
            x311 = 0/*false*/;
          }
          if (x311) {
            x313 = 0/*false*/;
            x314 = x307;
            char  *x312 = x306+1;
            x315 = x312;
          } else {
            x315 = x306;
          }
        }
        int x327 = x313;
        if (x327) {
          char  *x328 = x315;
          x302 = 0/*false*/;
        } else {
          char x331 = x314;
          char  *x333 = x315;
          int x334 = x303;
          int x335 = x334 < 0;
          int x343;
          if (x335) {
            x343 = x334;
          } else {
            int x339 = x334 > x338;
            int x342;
            if (x339) {
              x342 = -1;
            } else {
              char x332 = x331 - '0';
              int x340 = x334 * 10;
              int x341 = x340 + x332;
              x342 = x341;
            }
            x343 = x342;
          }
          x303 = x343;
          x301 = x333;
        }
      }
      int x369 = x303;
      char  *x370 = x301;
      x14 = 0/*false*/;
      x15 = x369;
      x16 = x370;
    }
  }
  int x378 = x14;
  if (x378) {
    char  *x379 = x16;
    x13 = x379;
  } else {
    int x382 = x15;
    char  *x383 = x16;
    char  *x384 = x383;
    int x385 = 1/*true*/;
    /*@
    loop invariant ((strlen(x384)>=0) && \valid(x384+(0..strlen(x384))));
    loop assigns x384, x385;
    */
    for (;;) {
      int x386 = x385;
      if (!x386) break;
      char  *x388 = x384;
      char x389 = x388[0];
      int x390 = x389 == '\0';
      if (x390) {
        x385 = 0/*false*/;
      } else {
        int x391 = x389 != '\n';
        if (x391) {
          char  *x392 = x388+1;
          x384 = x392;
        } else {
          x385 = 0/*false*/;
        }
      }
    }
    char  *x416 = x384;
    int x417 = 1/*true*/;
    char  *x419 = 0/*null*/;
    x417 = 0/*false*/;
    x419 = x416;
    int x423 = x417;
    if (x423) {
      char  *x424 = x419;
      x13 = x424;
    } else {
      char  *x428 = x419;
      int x433 = 1/*true*/;
      char x434 = '\0';
      char  *x435 = 0/*null*/;
      char x429 = x428[0];
      int x430 = x429 == '\0';
      if (x430) {
        x435 = x428;
      } else {
        int x431 = x429 == '\n';
        if (x431) {
          x433 = 0/*false*/;
          x434 = x429;
          char  *x432 = x428+1;
          x435 = x432;
        } else {
          x435 = x428;
        }
      }
      int x447 = x433;
      if (x447) {
        char  *x448 = x435;
        x13 = x448;
      } else {
        char x451 = x434;
        char  *x452 = x435;
        x11 = 0/*false*/;
        x12 = x382;
        x13 = x452;
      }
    }
  }
  int x462 = x11;
  if (x462) {
    char  *x463 = x13;
    x10 = x463;
  } else {
    int x466 = x12;
    char  *x467 = x13;
    char  *x468 = x467;
    int x469 = 1/*true*/;
    int x470 = 0;
    int x336 = INT_MAX;
    int x337 = x336 / 10;
    int x338 = x337 - 10;
    int x1133 = -2 == -2;
    /*@
    loop invariant ((strlen(x468)>=0) && \valid(x468+(0..strlen(x468))));
    loop assigns x468, x469, x470;
    */
    for (;;) {
      int x471 = x469;
      if (!x471) break;
      char  *x473 = x468;
      char  *x474 = p_ContentLength(x473);
      int x476 = 1/*true*/;
      int x477 = 0;
      char  *x478 = 0/*null*/;
      int x479 = 1/*true*/;
      int x480 = 0;
      char  *x481 = 0/*null*/;
      int x482 = 1/*true*/;
      int x483 = 0;
      char  *x484 = 0/*null*/;
      int x485 = 1/*true*/;
      int x486 = 0;
      char  *x487 = 0/*null*/;
      int x488 = 1/*true*/;
      int x489 = 0;
      char  *x490 = 0/*null*/;
      int x491 = 1/*true*/;
      int x492 = 0;
      char  *x493 = 0/*null*/;
      int x494 = 1/*true*/;
      char  *x496 = 0/*null*/;
      int x475 = 0 != x474;
      if (x475) {
        x494 = 0/*false*/;
        x496 = x474;
      } else {
        x496 = x473;
      }
      int x504 = x494;
      if (x504) {
        char  *x505 = x496;
      } else {
        char  *x508 = x496;
        x491 = 0/*false*/;
        x492 = 1;
        x493 = x508;
      }
      int x514 = x491;
      if (x514) {
        char  *x515 = p_TransferEncoding(x473);
        int x517 = 1/*true*/;
        char  *x519 = 0/*null*/;
        int x516 = 0 != x515;
        if (x516) {
          x517 = 0/*false*/;
          x519 = x515;
        } else {
          x519 = x473;
        }
        int x527 = x517;
        if (x527) {
          char  *x528 = x519;
        } else {
          char  *x531 = x519;
          x488 = 0/*false*/;
          x489 = 2;
          x490 = x531;
        }
      } else {
        int x538 = x492;
        char  *x539 = x493;
        x488 = 0/*false*/;
        x489 = x538;
        x490 = x539;
      }
      int x545 = x488;
      if (x545) {
        char  *x546 = x473;
        int x547 = 1/*true*/;
        /*@
        loop invariant ((strlen(x546)>=0) && \valid(x546+(0..strlen(x546))));
        loop assigns x546, x547;
        */
        for (;;) {
          int x548 = x547;
          if (!x548) break;
          char  *x550 = x546;
          int x561 = 1/*true*/;
          char x562 = '\0';
          char  *x563 = 0/*null*/;
          char x551 = x550[0];
          int x552 = x551 == '\0';
          if (x552) {
          } else {
            int x553 = x551 >= 'a';
            int x555;
            if (x553) {
              int x554 = x551 <= 'z';
              x555 = x554;
            } else {
              x555 = 0/*false*/;
            }
            int x556 = x551 >= 'A';
            int x558;
            if (x556) {
              int x557 = x551 <= 'Z';
              x558 = x557;
            } else {
              x558 = 0/*false*/;
            }
            int x559 = x555 || x558;
            if (x559) {
              x561 = 0/*false*/;
              x562 = x551;
              char  *x560 = x550+1;
              x563 = x560;
            } else {
            }
          }
          int x571 = x561;
          char x573 = x562;
          char  *x574 = x563;
          if (x571) {
            if (x552) {
              x547 = 0/*false*/;
            } else {
              int x572 = x551 == '-';
              if (x572) {
                char  *x560 = x550+1;
                x546 = x560;
              } else {
                x547 = 0/*false*/;
              }
            }
          } else {
            x546 = x574;
          }
        }
        char  *x602 = x546;
        x485 = 0/*false*/;
        x486 = 0;
        x487 = x602;
      } else {
        int x607 = x489;
        char  *x608 = x490;
        x485 = 0/*false*/;
        x486 = x607;
        x487 = x608;
      }
      int x614 = x485;
      if (x614) {
        char  *x615 = x487;
        x484 = x615;
      } else {
        int x618 = x486;
        char  *x619 = x487;
        char  *x620 = x619;
        int x621 = 1/*true*/;
        /*@
        loop invariant ((strlen(x620)>=0) && \valid(x620+(0..strlen(x620))));
        loop assigns x620, x621;
        */
        for (;;) {
          int x622 = x621;
          if (!x622) break;
          char  *x624 = x620;
          char x625 = x624[0];
          int x626 = x625 == '\0';
          if (x626) {
            x621 = 0/*false*/;
          } else {
            int x627 = x625 == ' ';
            if (x627) {
              char  *x628 = x624+1;
              x620 = x628;
            } else {
              x621 = 0/*false*/;
            }
          }
        }
        char  *x652 = x620;
        x482 = 0/*false*/;
        x483 = x618;
        x484 = x652;
      }
      int x658 = x482;
      if (x658) {
        char  *x659 = x484;
        x481 = x659;
      } else {
        int x662 = x483;
        char  *x663 = x484;
        int x668 = 1/*true*/;
        char x669 = '\0';
        char  *x670 = 0/*null*/;
        char x664 = x663[0];
        int x665 = x664 == '\0';
        if (x665) {
          x670 = x663;
        } else {
          int x666 = x664 == ':';
          if (x666) {
            x668 = 0/*false*/;
            x669 = x664;
            char  *x667 = x663+1;
            x670 = x667;
          } else {
            x670 = x663;
          }
        }
        int x682 = x668;
        if (x682) {
          char  *x683 = x670;
          x481 = x683;
        } else {
          char x686 = x669;
          char  *x687 = x670;
          x479 = 0/*false*/;
          x480 = x662;
          x481 = x687;
        }
      }
      int x695 = x479;
      if (x695) {
        char  *x696 = x481;
        x478 = x696;
      } else {
        int x699 = x480;
        char  *x700 = x481;
        char  *x701 = x700;
        int x702 = 1/*true*/;
        /*@
        loop invariant ((strlen(x701)>=0) && \valid(x701+(0..strlen(x701))));
        loop assigns x701, x702;
        */
        for (;;) {
          int x703 = x702;
          if (!x703) break;
          char  *x705 = x701;
          char x706 = x705[0];
          int x707 = x706 == '\0';
          if (x707) {
            x702 = 0/*false*/;
          } else {
            int x708 = x706 == ' ';
            if (x708) {
              char  *x709 = x705+1;
              x701 = x709;
            } else {
              x702 = 0/*false*/;
            }
          }
        }
        char  *x733 = x701;
        x476 = 0/*false*/;
        x477 = x699;
        x478 = x733;
      }
      int x739 = x476;
      if (x739) {
        char  *x740 = x478;
        x469 = 0/*false*/;
      } else {
        int x743 = x477;
        char  *x744 = x478;
        char  *x746 = p_chunked(x744);
        char  *x755 = x744;
        int x756 = 1/*true*/;
        /*@
        loop invariant ((strlen(x755)>=0) && \valid(x755+(0..strlen(x755))));
        loop assigns x755, x756;
        */
        for (;;) {
          int x757 = x756;
          if (!x757) break;
          char  *x759 = x755;
          char x760 = x759[0];
          int x761 = x760 == '\0';
          if (x761) {
            x756 = 0/*false*/;
          } else {
            int x762 = x760 != '\n';
            if (x762) {
              char  *x763 = x759+1;
              x755 = x763;
            } else {
              x756 = 0/*false*/;
            }
          }
        }
        char  *x787 = x755;
        int x745 = x743 == 2;
        if (x745) {
          int x788 = 1/*true*/;
          int x789 = 0;
          char  *x790 = 0/*null*/;
          int x791 = 1/*true*/;
          int x792 = 0;
          char  *x793 = 0/*null*/;
          int x794 = 1/*true*/;
          char  *x796 = 0/*null*/;
          int x747 = 0 != x746;
          if (x747) {
            x794 = 0/*false*/;
            x796 = x746;
          } else {
            x796 = x744;
          }
          int x804 = x794;
          if (x804) {
            char  *x805 = x796;
            x793 = x805;
          } else {
            char  *x809 = x796;
            x791 = 0/*false*/;
            x792 = -3;
            x793 = x809;
          }
          int x815 = x791;
          if (x815) {
            char  *x816 = x793;
            x790 = x816;
          } else {
            int x819 = x792;
            char  *x820 = x793;
            char  *x821 = x820;
            int x822 = 1/*true*/;
            /*@
            loop invariant ((strlen(x821)>=0) && \valid(x821+(0..strlen(x821))));
            loop assigns x821, x822;
            */
            for (;;) {
              int x823 = x822;
              if (!x823) break;
              char  *x825 = x821;
              char x826 = x825[0];
              int x827 = x826 == '\0';
              if (x827) {
                x822 = 0/*false*/;
              } else {
                int x828 = x826 == ' ';
                if (x828) {
                  char  *x829 = x825+1;
                  x821 = x829;
                } else {
                  x822 = 0/*false*/;
                }
              }
            }
            char  *x853 = x821;
            x788 = 0/*false*/;
            x789 = x819;
            x790 = x853;
          }
          int x859 = x788;
          if (x859) {
            char  *x860 = x790;
            x469 = 0/*false*/;
          } else {
            int x863 = x789;
            char  *x864 = x790;
            int x869 = 1/*true*/;
            char x870 = '\0';
            char  *x871 = 0/*null*/;
            char x865 = x864[0];
            int x866 = x865 == '\0';
            if (x866) {
              x871 = x864;
            } else {
              int x867 = x865 == '\n';
              if (x867) {
                x869 = 0/*false*/;
                x870 = x865;
                char  *x868 = x864+1;
                x871 = x868;
              } else {
                x871 = x864;
              }
            }
            int x883 = x869;
            if (x883) {
              char  *x884 = x871;
              x469 = 0/*false*/;
            } else {
              char x887 = x870;
              char  *x888 = x871;
              int x889 = x470;
              int x890 = x863 == -2;
              int x891;
              if (x890) {
                x891 = x889;
              } else {
                x891 = x863;
              }
              x470 = x891;
              x468 = x888;
            }
          }
        } else {
          int x748 = x743 == 1;
          if (x748) {
            int x899 = 1/*true*/;
            int x900 = 0;
            char  *x901 = 0/*null*/;
            int x902 = 1/*true*/;
            int x903 = 0;
            char  *x904 = 0/*null*/;
            int x905 = 1/*true*/;
            int x906 = 0;
            char  *x907 = 0/*null*/;
            int x908 = 1/*true*/;
            char x909 = '\0';
            char  *x910 = 0/*null*/;
            char x749 = x744[0];
            int x750 = x749 == '\0';
            if (x750) {
              x910 = x744;
            } else {
              int x751 = x749 >= '0';
              int x753;
              if (x751) {
                int x752 = x749 <= '9';
                x753 = x752;
              } else {
                x753 = 0/*false*/;
              }
              if (x753) {
                x908 = 0/*false*/;
                x909 = x749;
                char  *x754 = x744+1;
                x910 = x754;
              } else {
                x910 = x744;
              }
            }
            int x922 = x908;
            if (x922) {
              char  *x923 = x910;
              x907 = x923;
            } else {
              char x926 = x909;
              char  *x928 = x910;
              x905 = 0/*false*/;
              char x927 = x926 - '0';
              x906 = x927;
              x907 = x928;
            }
            int x934 = x905;
            if (x934) {
              char  *x935 = x907;
              x904 = x935;
            } else {
              int x938 = x906;
              char  *x939 = x907;
              char  *x940 = x939;
              int x941 = 1/*true*/;
              int x942 = x938;
              /*@
              loop invariant (((strlen(x940)>=0) && \valid(x940+(0..strlen(x940)))) && ((x942==-1) || (0<=x942)));
              loop assigns x940, x941, x942;
              */
              for (;;) {
                int x943 = x941;
                if (!x943) break;
                char  *x945 = x940;
                int x952 = 1/*true*/;
                char x953 = '\0';
                char  *x954 = 0/*null*/;
                char x946 = x945[0];
                int x947 = x946 == '\0';
                if (x947) {
                  x954 = x945;
                } else {
                  int x948 = x946 >= '0';
                  int x950;
                  if (x948) {
                    int x949 = x946 <= '9';
                    x950 = x949;
                  } else {
                    x950 = 0/*false*/;
                  }
                  if (x950) {
                    x952 = 0/*false*/;
                    x953 = x946;
                    char  *x951 = x945+1;
                    x954 = x951;
                  } else {
                    x954 = x945;
                  }
                }
                int x966 = x952;
                if (x966) {
                  char  *x967 = x954;
                  x941 = 0/*false*/;
                } else {
                  char x970 = x953;
                  char  *x972 = x954;
                  int x973 = x942;
                  int x974 = x973 < 0;
                  int x979;
                  if (x974) {
                    x979 = x973;
                  } else {
                    int x975 = x973 > x338;
                    int x978;
                    if (x975) {
                      x978 = -1;
                    } else {
                      char x971 = x970 - '0';
                      int x976 = x973 * 10;
                      int x977 = x976 + x971;
                      x978 = x977;
                    }
                    x979 = x978;
                  }
                  x942 = x979;
                  x940 = x972;
                }
              }
              int x1005 = x942;
              char  *x1006 = x940;
              x902 = 0/*false*/;
              x903 = x1005;
              x904 = x1006;
            }
            int x1012 = x902;
            if (x1012) {
              char  *x1013 = x904;
              x901 = x1013;
            } else {
              int x1016 = x903;
              char  *x1017 = x904;
              char  *x1018 = x1017;
              int x1019 = 1/*true*/;
              /*@
              loop invariant ((strlen(x1018)>=0) && \valid(x1018+(0..strlen(x1018))));
              loop assigns x1018, x1019;
              */
              for (;;) {
                int x1020 = x1019;
                if (!x1020) break;
                char  *x1022 = x1018;
                char x1023 = x1022[0];
                int x1024 = x1023 == '\0';
                if (x1024) {
                  x1019 = 0/*false*/;
                } else {
                  int x1025 = x1023 == ' ';
                  if (x1025) {
                    char  *x1026 = x1022+1;
                    x1018 = x1026;
                  } else {
                    x1019 = 0/*false*/;
                  }
                }
              }
              char  *x1050 = x1018;
              x899 = 0/*false*/;
              x900 = x1016;
              x901 = x1050;
            }
            int x1056 = x899;
            if (x1056) {
              char  *x1057 = x901;
              x469 = 0/*false*/;
            } else {
              int x1060 = x900;
              char  *x1061 = x901;
              int x1066 = 1/*true*/;
              char x1067 = '\0';
              char  *x1068 = 0/*null*/;
              char x1062 = x1061[0];
              int x1063 = x1062 == '\0';
              if (x1063) {
                x1068 = x1061;
              } else {
                int x1064 = x1062 == '\n';
                if (x1064) {
                  x1066 = 0/*false*/;
                  x1067 = x1062;
                  char  *x1065 = x1061+1;
                  x1068 = x1065;
                } else {
                  x1068 = x1061;
                }
              }
              int x1080 = x1066;
              if (x1080) {
                char  *x1081 = x1068;
                x469 = 0/*false*/;
              } else {
                char x1084 = x1067;
                char  *x1085 = x1068;
                int x1086 = x470;
                int x1087 = x1060 == -2;
                int x1088;
                if (x1087) {
                  x1088 = x1086;
                } else {
                  x1088 = x1060;
                }
                x470 = x1088;
                x468 = x1085;
              }
            }
          } else {
            int x1096 = 1/*true*/;
            char  *x1098 = 0/*null*/;
            x1096 = 0/*false*/;
            x1098 = x787;
            int x1102 = x1096;
            if (x1102) {
              char  *x1103 = x1098;
              x469 = 0/*false*/;
            } else {
              char  *x1107 = x1098;
              int x1112 = 1/*true*/;
              char x1113 = '\0';
              char  *x1114 = 0/*null*/;
              char x1108 = x1107[0];
              int x1109 = x1108 == '\0';
              if (x1109) {
                x1114 = x1107;
              } else {
                int x1110 = x1108 == '\n';
                if (x1110) {
                  x1112 = 0/*false*/;
                  x1113 = x1108;
                  char  *x1111 = x1107+1;
                  x1114 = x1111;
                } else {
                  x1114 = x1107;
                }
              }
              int x1126 = x1112;
              if (x1126) {
                char  *x1127 = x1114;
                x469 = 0/*false*/;
              } else {
                char x1130 = x1113;
                char  *x1131 = x1114;
                int x1132 = x470;
                int x1134;
                if (x1133) {
                  x1134 = x1132;
                } else {
                  x1134 = -2;
                }
                x470 = x1134;
                x468 = x1131;
              }
            }
          }
        }
      }
    }
    int x1163 = x470;
    char  *x1164 = x468;
    x8 = 0/*false*/;
    x9 = x1163;
    x10 = x1164;
  }
  int x1170 = x8;
  if (x1170) {
    char  *x1171 = x10;
    x7 = x1171;
  } else {
    int x1174 = x9;
    char  *x1175 = x10;
    int x1180 = 1/*true*/;
    char x1181 = '\0';
    char  *x1182 = 0/*null*/;
    char x1176 = x1175[0];
    int x1177 = x1176 == '\0';
    if (x1177) {
      x1182 = x1175;
    } else {
      int x1178 = x1176 == '\n';
      if (x1178) {
        x1180 = 0/*false*/;
        x1181 = x1176;
        char  *x1179 = x1175+1;
        x1182 = x1179;
      } else {
        x1182 = x1175;
      }
    }
    int x1194 = x1180;
    if (x1194) {
      char  *x1195 = x1182;
      x7 = x1195;
    } else {
      char x1198 = x1181;
      char  *x1199 = x1182;
      x5 = 0/*false*/;
      x6 = x1174;
      x7 = x1199;
    }
  }
  int x1207 = x5;
  if (x1207) {
    char  *x1208 = x7;
  } else {
    int x1210 = x6;
    char  *x1211 = x7;
    char  *x1213 = x1211;
    int x1214 = 1/*true*/;
    int x1215 = 0;
    int x336 = INT_MAX;
    int x1375 = x336 / 16;
    int x1376 = x1375 - 16;
    /*@
    loop invariant (((strlen(x1213)>=0) && \valid(x1213+(0..strlen(x1213)))) && ((x1215==-1) || (0<=x1215)));
    loop assigns x1213, x1214, x1215;
    */
    for (;;) {
      int x1216 = x1214;
      if (!x1216) break;
      char  *x1218 = x1213;
      int x1225 = 1/*true*/;
      int x1226 = 0;
      char  *x1227 = 0/*null*/;
      int x1228 = 1/*true*/;
      int x1229 = 0;
      char  *x1230 = 0/*null*/;
      int x1231 = 1/*true*/;
      int x1232 = 0;
      char  *x1233 = 0/*null*/;
      int x1234 = 1/*true*/;
      int x1235 = 0;
      char  *x1236 = 0/*null*/;
      int x1237 = 1/*true*/;
      char x1238 = '\0';
      char  *x1239 = 0/*null*/;
      char x1219 = x1218[0];
      int x1220 = x1219 == '\0';
      if (x1220) {
        x1239 = x1218;
      } else {
        int x1221 = x1219 >= '0';
        int x1223;
        if (x1221) {
          int x1222 = x1219 <= '9';
          x1223 = x1222;
        } else {
          x1223 = 0/*false*/;
        }
        if (x1223) {
          x1237 = 0/*false*/;
          x1238 = x1219;
          char  *x1224 = x1218+1;
          x1239 = x1224;
        } else {
          x1239 = x1218;
        }
      }
      int x1251 = x1237;
      if (x1251) {
        char  *x1252 = x1239;
      } else {
        char x1254 = x1238;
        char  *x1256 = x1239;
        x1234 = 0/*false*/;
        char x1255 = x1254 - '0';
        x1235 = x1255;
        x1236 = x1256;
      }
      int x1262 = x1234;
      if (x1262) {
        int x1266 = 1/*true*/;
        char x1267 = '\0';
        char  *x1268 = 0/*null*/;
        if (x1220) {
          x1268 = x1218;
        } else {
          int x1263 = x1219 >= 'a';
          int x1265;
          if (x1263) {
            int x1264 = x1219 <= 'f';
            x1265 = x1264;
          } else {
            x1265 = 0/*false*/;
          }
          if (x1265) {
            x1266 = 0/*false*/;
            x1267 = x1219;
            char  *x1224 = x1218+1;
            x1268 = x1224;
          } else {
            x1268 = x1218;
          }
        }
        int x1280 = x1266;
        if (x1280) {
          char  *x1281 = x1268;
          x1233 = x1281;
        } else {
          char x1284 = x1267;
          char  *x1287 = x1268;
          x1231 = 0/*false*/;
          char x1285 = x1284 - 'a';
          int x1286 = 10 + x1285;
          x1232 = x1286;
          x1233 = x1287;
        }
      } else {
        int x1294 = x1235;
        char  *x1295 = x1236;
        x1231 = 0/*false*/;
        x1232 = x1294;
        x1233 = x1295;
      }
      int x1301 = x1231;
      if (x1301) {
        char  *x1302 = x1233;
        x1230 = x1302;
      } else {
        int x1305 = x1232;
        char  *x1306 = x1233;
        char  *x1307 = x1306;
        int x1308 = 1/*true*/;
        int x1309 = x1305;
        /*@
        loop invariant (((strlen(x1307)>=0) && \valid(x1307+(0..strlen(x1307)))) && ((x1309==-1) || (0<=x1309)));
        loop assigns x1307, x1308, x1309;
        */
        for (;;) {
          int x1310 = x1308;
          if (!x1310) break;
          char  *x1312 = x1307;
          int x1319 = 1/*true*/;
          int x1320 = 0;
          char  *x1321 = 0/*null*/;
          int x1322 = 1/*true*/;
          char x1323 = '\0';
          char  *x1324 = 0/*null*/;
          char x1313 = x1312[0];
          int x1314 = x1313 == '\0';
          if (x1314) {
            x1324 = x1312;
          } else {
            int x1315 = x1313 >= '0';
            int x1317;
            if (x1315) {
              int x1316 = x1313 <= '9';
              x1317 = x1316;
            } else {
              x1317 = 0/*false*/;
            }
            if (x1317) {
              x1322 = 0/*false*/;
              x1323 = x1313;
              char  *x1318 = x1312+1;
              x1324 = x1318;
            } else {
              x1324 = x1312;
            }
          }
          int x1336 = x1322;
          if (x1336) {
            char  *x1337 = x1324;
          } else {
            char x1339 = x1323;
            char  *x1341 = x1324;
            x1319 = 0/*false*/;
            char x1340 = x1339 - '0';
            x1320 = x1340;
            x1321 = x1341;
          }
          int x1347 = x1319;
          if (x1347) {
            int x1351 = 1/*true*/;
            char x1352 = '\0';
            char  *x1353 = 0/*null*/;
            if (x1314) {
              x1353 = x1312;
            } else {
              int x1348 = x1313 >= 'a';
              int x1350;
              if (x1348) {
                int x1349 = x1313 <= 'f';
                x1350 = x1349;
              } else {
                x1350 = 0/*false*/;
              }
              if (x1350) {
                x1351 = 0/*false*/;
                x1352 = x1313;
                char  *x1318 = x1312+1;
                x1353 = x1318;
              } else {
                x1353 = x1312;
              }
            }
            int x1365 = x1351;
            if (x1365) {
              char  *x1366 = x1353;
              x1308 = 0/*false*/;
            } else {
              char x1369 = x1352;
              char  *x1372 = x1353;
              int x1373 = x1309;
              int x1374 = x1373 < 0;
              int x1381;
              if (x1374) {
                x1381 = x1373;
              } else {
                int x1377 = x1373 > x1376;
                int x1380;
                if (x1377) {
                  x1380 = -1;
                } else {
                  char x1370 = x1369 - 'a';
                  int x1371 = 10 + x1370;
                  int x1378 = x1373 * 16;
                  int x1379 = x1378 + x1371;
                  x1380 = x1379;
                }
                x1381 = x1380;
              }
              x1309 = x1381;
              x1307 = x1372;
            }
          } else {
            int x1387 = x1320;
            char  *x1388 = x1321;
            int x1389 = x1309;
            int x1390 = x1389 < 0;
            int x1395;
            if (x1390) {
              x1395 = x1389;
            } else {
              int x1391 = x1389 > x1376;
              int x1394;
              if (x1391) {
                x1394 = -1;
              } else {
                int x1392 = x1389 * 16;
                int x1393 = x1392 + x1387;
                x1394 = x1393;
              }
              x1395 = x1394;
            }
            x1309 = x1395;
            x1307 = x1388;
          }
        }
        int x1421 = x1309;
        char  *x1422 = x1307;
        x1228 = 0/*false*/;
        x1229 = x1421;
        x1230 = x1422;
      }
      int x1428 = x1228;
      if (x1428) {
        char  *x1429 = x1230;
        x1227 = x1429;
      } else {
        int x1432 = x1229;
        char  *x1433 = x1230;
        int x1438 = 1/*true*/;
        char x1439 = '\0';
        char  *x1440 = 0/*null*/;
        char x1434 = x1433[0];
        int x1435 = x1434 == '\0';
        if (x1435) {
          x1440 = x1433;
        } else {
          int x1436 = x1434 == '\n';
          if (x1436) {
            x1438 = 0/*false*/;
            x1439 = x1434;
            char  *x1437 = x1433+1;
            x1440 = x1437;
          } else {
            x1440 = x1433;
          }
        }
        int x1452 = x1438;
        if (x1452) {
          char  *x1453 = x1440;
          x1227 = x1453;
        } else {
          char x1456 = x1439;
          char  *x1457 = x1440;
          x1225 = 0/*false*/;
          x1226 = x1432;
          x1227 = x1457;
        }
      }
      int x1465 = x1225;
      if (x1465) {
        char  *x1466 = x1227;
        x1214 = 0/*false*/;
      } else {
        int x1469 = x1226;
        char  *x1470 = x1227;
        int x1472 = 1/*true*/;
        char  *x1473 = x1470;
        /*@
        loop invariant ((0<=x1475) && ((strlen(x1473)>=0) && \valid(x1473+(0..strlen(x1473)))));
        loop assigns x1475, x1472, x1473;
        loop variant (x1226-x1475);
        */
        for(int x1475=0; x1475 < x1469; x1475++) {
          int x1476 = x1472;
          if (x1476) {
            char  *x1477 = x1473;
            char x1478 = x1477[0];
            int x1479 = x1478 == '\0';
            if (x1479) {
              x1472 = 0/*false*/;
            } else {
              if (1/*true*/) {
                char  *x1480 = x1477+1;
                x1473 = x1480;
              } else {
                x1472 = 0/*false*/;
              }
            }
          } else {
          }
        }
        int x1510 = x1472;
        char  *x1511 = x1473;
        int x1471 = x1469 < 0;
        if (x1471) {
          x1214 = 0/*false*/;
        } else {
          int x1514 = 1/*true*/;
          int x1515 = 0;
          char  *x1516 = 0/*null*/;
          int x1517 = 1/*true*/;
          char  *x1519 = 0/*null*/;
          if (x1510) {
            x1517 = 0/*false*/;
            x1519 = x1511;
          } else {
            x1519 = x1470;
          }
          int x1527 = x1517;
          if (x1527) {
            char  *x1528 = x1519;
            x1516 = x1528;
          } else {
            char  *x1532 = x1519;
            x1514 = 0/*false*/;
            x1515 = x1469;
            x1516 = x1532;
          }
          int x1538 = x1514;
          if (x1538) {
            char  *x1539 = x1516;
            x1214 = 0/*false*/;
          } else {
            int x1542 = x1515;
            char  *x1543 = x1516;
            int x1548 = 1/*true*/;
            char x1549 = '\0';
            char  *x1550 = 0/*null*/;
            char x1544 = x1543[0];
            int x1545 = x1544 == '\0';
            if (x1545) {
              x1550 = x1543;
            } else {
              int x1546 = x1544 == '\n';
              if (x1546) {
                x1548 = 0/*false*/;
                x1549 = x1544;
                char  *x1547 = x1543+1;
                x1550 = x1547;
              } else {
                x1550 = x1543;
              }
            }
            int x1562 = x1548;
            if (x1562) {
              char  *x1563 = x1550;
              x1214 = 0/*false*/;
            } else {
              char x1566 = x1549;
              char  *x1567 = x1550;
              int x1568 = x1215;
              int x1569 = x1568 < 0;
              int x1574;
              if (x1569) {
                x1574 = x1568;
              } else {
                int x1570 = x336 - x1542;
                int x1571 = x1568 > x1570;
                int x1573;
                if (x1571) {
                  x1573 = -1;
                } else {
                  int x1572 = x1568 + x1542;
                  x1573 = x1572;
                }
                x1574 = x1573;
              }
              x1215 = x1574;
              x1213 = x1567;
            }
          }
        }
      }
    }
    int x1606 = x1215;
    char  *x1607 = x1213;
    int x1609 = 1/*true*/;
    char  *x1610 = x1211;
    /*@
    loop invariant ((0<=x1612) && ((strlen(x1610)>=0) && \valid(x1610+(0..strlen(x1610)))));
    loop assigns x1612, x1609, x1610;
    loop variant (x6-x1612);
    */
    for(int x1612=0; x1612 < x1210; x1612++) {
      int x1613 = x1609;
      if (x1613) {
        char  *x1614 = x1610;
        char x1615 = x1614[0];
        int x1616 = x1615 == '\0';
        if (x1616) {
          x1609 = 0/*false*/;
        } else {
          if (1/*true*/) {
            char  *x1617 = x1614+1;
            x1610 = x1617;
          } else {
            x1609 = 0/*false*/;
          }
        }
      } else {
      }
    }
    int x1647 = x1609;
    char  *x1648 = x1610;
    int x1212 = x1210 == -3;
    if (x1212) {
      char x1649 = x1607[0];
      int x1650 = x1649 == '\0';
      if (x1650) {
        x2 = x1606;
      } else {
      }
    } else {
      int x1608 = x1210 < 0;
      if (x1608) {
      } else {
        int x1655 = 1/*true*/;
        int x1656 = 0;
        char  *x1657 = 0/*null*/;
        int x1658 = 1/*true*/;
        char  *x1660 = 0/*null*/;
        if (x1647) {
          x1658 = 0/*false*/;
          x1660 = x1648;
        } else {
          x1660 = x1211;
        }
        int x1668 = x1658;
        if (x1668) {
          char  *x1669 = x1660;
          x1657 = x1669;
        } else {
          char  *x1673 = x1660;
          x1655 = 0/*false*/;
          x1656 = x1210;
          x1657 = x1673;
        }
        int x1679 = x1655;
        if (x1679) {
          char  *x1680 = x1657;
        } else {
          int x1682 = x1656;
          char  *x1683 = x1657;
          int x1688 = 1/*true*/;
          char x1689 = '\0';
          char  *x1690 = 0/*null*/;
          char x1684 = x1683[0];
          int x1685 = x1684 == '\0';
          if (x1685) {
            x1690 = x1683;
          } else {
            int x1686 = x1684 == '\n';
            if (x1686) {
              x1688 = 0/*false*/;
              x1689 = x1684;
              char  *x1687 = x1683+1;
              x1690 = x1687;
            } else {
              x1690 = x1683;
            }
          }
          int x1702 = x1688;
          if (x1702) {
            char  *x1703 = x1690;
          } else {
            char x1705 = x1689;
            char  *x1706 = x1690;
            char x1707 = x1706[0];
            int x1708 = x1707 == '\0';
            if (x1708) {
              x2 = x1682;
            } else {
            }
          }
        }
      }
    }
  }
  int x1722 = x2;
  return x1722;
}
/*@
requires ((strlen(x1738)>=0) && \valid(x1738+(0..strlen(x1738))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_HTTP(char  * x1738) {
  char  *x1740 = x1738;
  int x1745 = 1/*true*/;
  char x1746 = '\0';
  char  *x1747 = 0/*null*/;
  char x1741 = x1738[0];
  int x1742 = x1741 == '\0';
  if (x1742) {
    x1747 = x1738;
  } else {
    int x1743 = x1741 == 'H';
    if (x1743) {
      x1745 = 0/*false*/;
      x1746 = x1741;
      char  *x1744 = x1738+1;
      x1747 = x1744;
    } else {
      x1747 = x1738;
    }
  }
  int x1759 = x1745;
  if (x1759) {
    char  *x1760 = x1747;
    x1740 = 0;
  } else {
    char x1763 = x1746;
    char  *x1764 = x1747;
    int x1769 = 1/*true*/;
    char x1770 = '\0';
    char  *x1771 = 0/*null*/;
    char x1765 = x1764[0];
    int x1766 = x1765 == '\0';
    if (x1766) {
      x1771 = x1764;
    } else {
      int x1767 = x1765 == 'T';
      if (x1767) {
        x1769 = 0/*false*/;
        x1770 = x1765;
        char  *x1768 = x1764+1;
        x1771 = x1768;
      } else {
        x1771 = x1764;
      }
    }
    int x1783 = x1769;
    if (x1783) {
      char  *x1784 = x1771;
      x1740 = 0;
    } else {
      char x1787 = x1770;
      char  *x1788 = x1771;
      int x1793 = 1/*true*/;
      char x1794 = '\0';
      char  *x1795 = 0/*null*/;
      char x1789 = x1788[0];
      int x1790 = x1789 == '\0';
      if (x1790) {
        x1795 = x1788;
      } else {
        int x1791 = x1789 == 'T';
        if (x1791) {
          x1793 = 0/*false*/;
          x1794 = x1789;
          char  *x1792 = x1788+1;
          x1795 = x1792;
        } else {
          x1795 = x1788;
        }
      }
      int x1807 = x1793;
      if (x1807) {
        char  *x1808 = x1795;
        x1740 = 0;
      } else {
        char x1811 = x1794;
        char  *x1812 = x1795;
        int x1817 = 1/*true*/;
        char x1818 = '\0';
        char  *x1819 = 0/*null*/;
        char x1813 = x1812[0];
        int x1814 = x1813 == '\0';
        if (x1814) {
          x1819 = x1812;
        } else {
          int x1815 = x1813 == 'P';
          if (x1815) {
            x1817 = 0/*false*/;
            x1818 = x1813;
            char  *x1816 = x1812+1;
            x1819 = x1816;
          } else {
            x1819 = x1812;
          }
        }
        int x1831 = x1817;
        if (x1831) {
          char  *x1832 = x1819;
          x1740 = 0;
        } else {
          char x1835 = x1818;
          char  *x1836 = x1819;
          int x1841 = 1/*true*/;
          char x1842 = '\0';
          char  *x1843 = 0/*null*/;
          char x1837 = x1836[0];
          int x1838 = x1837 == '\0';
          if (x1838) {
            x1843 = x1836;
          } else {
            int x1839 = x1837 == '/';
            if (x1839) {
              x1841 = 0/*false*/;
              x1842 = x1837;
              char  *x1840 = x1836+1;
              x1843 = x1840;
            } else {
              x1843 = x1836;
            }
          }
          int x1855 = x1841;
          if (x1855) {
            char  *x1856 = x1843;
            x1740 = 0;
          } else {
            char x1859 = x1842;
            char  *x1860 = x1843;
            x1740 = x1860;
          }
        }
      }
    }
  }
  char  *x1872 = x1740;
  return x1872;
}
/*@
requires ((strlen(x1888)>=0) && \valid(x1888+(0..strlen(x1888))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_ContentLength(char  * x1888) {
  char  *x1890 = x1888;
  int x1895 = 1/*true*/;
  char x1896 = '\0';
  char  *x1897 = 0/*null*/;
  char x1891 = x1888[0];
  int x1892 = x1891 == '\0';
  if (x1892) {
    x1897 = x1888;
  } else {
    int x1893 = x1891 == 'C';
    if (x1893) {
      x1895 = 0/*false*/;
      x1896 = x1891;
      char  *x1894 = x1888+1;
      x1897 = x1894;
    } else {
      x1897 = x1888;
    }
  }
  int x1909 = x1895;
  if (x1909) {
    char  *x1910 = x1897;
    x1890 = 0;
  } else {
    char x1913 = x1896;
    char  *x1914 = x1897;
    int x1919 = 1/*true*/;
    char x1920 = '\0';
    char  *x1921 = 0/*null*/;
    char x1915 = x1914[0];
    int x1916 = x1915 == '\0';
    if (x1916) {
      x1921 = x1914;
    } else {
      int x1917 = x1915 == 'o';
      if (x1917) {
        x1919 = 0/*false*/;
        x1920 = x1915;
        char  *x1918 = x1914+1;
        x1921 = x1918;
      } else {
        x1921 = x1914;
      }
    }
    int x1933 = x1919;
    if (x1933) {
      char  *x1934 = x1921;
      x1890 = 0;
    } else {
      char x1937 = x1920;
      char  *x1938 = x1921;
      int x1943 = 1/*true*/;
      char x1944 = '\0';
      char  *x1945 = 0/*null*/;
      char x1939 = x1938[0];
      int x1940 = x1939 == '\0';
      if (x1940) {
        x1945 = x1938;
      } else {
        int x1941 = x1939 == 'n';
        if (x1941) {
          x1943 = 0/*false*/;
          x1944 = x1939;
          char  *x1942 = x1938+1;
          x1945 = x1942;
        } else {
          x1945 = x1938;
        }
      }
      int x1957 = x1943;
      if (x1957) {
        char  *x1958 = x1945;
        x1890 = 0;
      } else {
        char x1961 = x1944;
        char  *x1962 = x1945;
        int x1967 = 1/*true*/;
        char x1968 = '\0';
        char  *x1969 = 0/*null*/;
        char x1963 = x1962[0];
        int x1964 = x1963 == '\0';
        if (x1964) {
          x1969 = x1962;
        } else {
          int x1965 = x1963 == 't';
          if (x1965) {
            x1967 = 0/*false*/;
            x1968 = x1963;
            char  *x1966 = x1962+1;
            x1969 = x1966;
          } else {
            x1969 = x1962;
          }
        }
        int x1981 = x1967;
        if (x1981) {
          char  *x1982 = x1969;
          x1890 = 0;
        } else {
          char x1985 = x1968;
          char  *x1986 = x1969;
          int x1991 = 1/*true*/;
          char x1992 = '\0';
          char  *x1993 = 0/*null*/;
          char x1987 = x1986[0];
          int x1988 = x1987 == '\0';
          if (x1988) {
            x1993 = x1986;
          } else {
            int x1989 = x1987 == 'e';
            if (x1989) {
              x1991 = 0/*false*/;
              x1992 = x1987;
              char  *x1990 = x1986+1;
              x1993 = x1990;
            } else {
              x1993 = x1986;
            }
          }
          int x2005 = x1991;
          if (x2005) {
            char  *x2006 = x1993;
            x1890 = 0;
          } else {
            char x2009 = x1992;
            char  *x2010 = x1993;
            int x2015 = 1/*true*/;
            char x2016 = '\0';
            char  *x2017 = 0/*null*/;
            char x2011 = x2010[0];
            int x2012 = x2011 == '\0';
            if (x2012) {
              x2017 = x2010;
            } else {
              int x2013 = x2011 == 'n';
              if (x2013) {
                x2015 = 0/*false*/;
                x2016 = x2011;
                char  *x2014 = x2010+1;
                x2017 = x2014;
              } else {
                x2017 = x2010;
              }
            }
            int x2029 = x2015;
            if (x2029) {
              char  *x2030 = x2017;
              x1890 = 0;
            } else {
              char x2033 = x2016;
              char  *x2034 = x2017;
              int x2039 = 1/*true*/;
              char x2040 = '\0';
              char  *x2041 = 0/*null*/;
              char x2035 = x2034[0];
              int x2036 = x2035 == '\0';
              if (x2036) {
                x2041 = x2034;
              } else {
                int x2037 = x2035 == 't';
                if (x2037) {
                  x2039 = 0/*false*/;
                  x2040 = x2035;
                  char  *x2038 = x2034+1;
                  x2041 = x2038;
                } else {
                  x2041 = x2034;
                }
              }
              int x2053 = x2039;
              if (x2053) {
                char  *x2054 = x2041;
                x1890 = 0;
              } else {
                char x2057 = x2040;
                char  *x2058 = x2041;
                int x2063 = 1/*true*/;
                char x2064 = '\0';
                char  *x2065 = 0/*null*/;
                char x2059 = x2058[0];
                int x2060 = x2059 == '\0';
                if (x2060) {
                  x2065 = x2058;
                } else {
                  int x2061 = x2059 == '-';
                  if (x2061) {
                    x2063 = 0/*false*/;
                    x2064 = x2059;
                    char  *x2062 = x2058+1;
                    x2065 = x2062;
                  } else {
                    x2065 = x2058;
                  }
                }
                int x2077 = x2063;
                if (x2077) {
                  char  *x2078 = x2065;
                  x1890 = 0;
                } else {
                  char x2081 = x2064;
                  char  *x2082 = x2065;
                  int x2087 = 1/*true*/;
                  char x2088 = '\0';
                  char  *x2089 = 0/*null*/;
                  char x2083 = x2082[0];
                  int x2084 = x2083 == '\0';
                  if (x2084) {
                    x2089 = x2082;
                  } else {
                    int x2085 = x2083 == 'L';
                    if (x2085) {
                      x2087 = 0/*false*/;
                      x2088 = x2083;
                      char  *x2086 = x2082+1;
                      x2089 = x2086;
                    } else {
                      x2089 = x2082;
                    }
                  }
                  int x2101 = x2087;
                  if (x2101) {
                    char  *x2102 = x2089;
                    x1890 = 0;
                  } else {
                    char x2105 = x2088;
                    char  *x2106 = x2089;
                    int x2111 = 1/*true*/;
                    char x2112 = '\0';
                    char  *x2113 = 0/*null*/;
                    char x2107 = x2106[0];
                    int x2108 = x2107 == '\0';
                    if (x2108) {
                      x2113 = x2106;
                    } else {
                      int x2109 = x2107 == 'e';
                      if (x2109) {
                        x2111 = 0/*false*/;
                        x2112 = x2107;
                        char  *x2110 = x2106+1;
                        x2113 = x2110;
                      } else {
                        x2113 = x2106;
                      }
                    }
                    int x2125 = x2111;
                    if (x2125) {
                      char  *x2126 = x2113;
                      x1890 = 0;
                    } else {
                      char x2129 = x2112;
                      char  *x2130 = x2113;
                      int x2135 = 1/*true*/;
                      char x2136 = '\0';
                      char  *x2137 = 0/*null*/;
                      char x2131 = x2130[0];
                      int x2132 = x2131 == '\0';
                      if (x2132) {
                        x2137 = x2130;
                      } else {
                        int x2133 = x2131 == 'n';
                        if (x2133) {
                          x2135 = 0/*false*/;
                          x2136 = x2131;
                          char  *x2134 = x2130+1;
                          x2137 = x2134;
                        } else {
                          x2137 = x2130;
                        }
                      }
                      int x2149 = x2135;
                      if (x2149) {
                        char  *x2150 = x2137;
                        x1890 = 0;
                      } else {
                        char x2153 = x2136;
                        char  *x2154 = x2137;
                        int x2159 = 1/*true*/;
                        char x2160 = '\0';
                        char  *x2161 = 0/*null*/;
                        char x2155 = x2154[0];
                        int x2156 = x2155 == '\0';
                        if (x2156) {
                          x2161 = x2154;
                        } else {
                          int x2157 = x2155 == 'g';
                          if (x2157) {
                            x2159 = 0/*false*/;
                            x2160 = x2155;
                            char  *x2158 = x2154+1;
                            x2161 = x2158;
                          } else {
                            x2161 = x2154;
                          }
                        }
                        int x2173 = x2159;
                        if (x2173) {
                          char  *x2174 = x2161;
                          x1890 = 0;
                        } else {
                          char x2177 = x2160;
                          char  *x2178 = x2161;
                          int x2183 = 1/*true*/;
                          char x2184 = '\0';
                          char  *x2185 = 0/*null*/;
                          char x2179 = x2178[0];
                          int x2180 = x2179 == '\0';
                          if (x2180) {
                            x2185 = x2178;
                          } else {
                            int x2181 = x2179 == 't';
                            if (x2181) {
                              x2183 = 0/*false*/;
                              x2184 = x2179;
                              char  *x2182 = x2178+1;
                              x2185 = x2182;
                            } else {
                              x2185 = x2178;
                            }
                          }
                          int x2197 = x2183;
                          if (x2197) {
                            char  *x2198 = x2185;
                            x1890 = 0;
                          } else {
                            char x2201 = x2184;
                            char  *x2202 = x2185;
                            int x2207 = 1/*true*/;
                            char x2208 = '\0';
                            char  *x2209 = 0/*null*/;
                            char x2203 = x2202[0];
                            int x2204 = x2203 == '\0';
                            if (x2204) {
                              x2209 = x2202;
                            } else {
                              int x2205 = x2203 == 'h';
                              if (x2205) {
                                x2207 = 0/*false*/;
                                x2208 = x2203;
                                char  *x2206 = x2202+1;
                                x2209 = x2206;
                              } else {
                                x2209 = x2202;
                              }
                            }
                            int x2221 = x2207;
                            if (x2221) {
                              char  *x2222 = x2209;
                              x1890 = 0;
                            } else {
                              char x2225 = x2208;
                              char  *x2226 = x2209;
                              x1890 = x2226;
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
  char  *x2256 = x1890;
  return x2256;
}
/*@
requires ((strlen(x2272)>=0) && \valid(x2272+(0..strlen(x2272))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_TransferEncoding(char  * x2272) {
  char  *x2274 = x2272;
  int x2279 = 1/*true*/;
  char x2280 = '\0';
  char  *x2281 = 0/*null*/;
  char x2275 = x2272[0];
  int x2276 = x2275 == '\0';
  if (x2276) {
    x2281 = x2272;
  } else {
    int x2277 = x2275 == 'T';
    if (x2277) {
      x2279 = 0/*false*/;
      x2280 = x2275;
      char  *x2278 = x2272+1;
      x2281 = x2278;
    } else {
      x2281 = x2272;
    }
  }
  int x2293 = x2279;
  if (x2293) {
    char  *x2294 = x2281;
    x2274 = 0;
  } else {
    char x2297 = x2280;
    char  *x2298 = x2281;
    int x2303 = 1/*true*/;
    char x2304 = '\0';
    char  *x2305 = 0/*null*/;
    char x2299 = x2298[0];
    int x2300 = x2299 == '\0';
    if (x2300) {
      x2305 = x2298;
    } else {
      int x2301 = x2299 == 'r';
      if (x2301) {
        x2303 = 0/*false*/;
        x2304 = x2299;
        char  *x2302 = x2298+1;
        x2305 = x2302;
      } else {
        x2305 = x2298;
      }
    }
    int x2317 = x2303;
    if (x2317) {
      char  *x2318 = x2305;
      x2274 = 0;
    } else {
      char x2321 = x2304;
      char  *x2322 = x2305;
      int x2327 = 1/*true*/;
      char x2328 = '\0';
      char  *x2329 = 0/*null*/;
      char x2323 = x2322[0];
      int x2324 = x2323 == '\0';
      if (x2324) {
        x2329 = x2322;
      } else {
        int x2325 = x2323 == 'a';
        if (x2325) {
          x2327 = 0/*false*/;
          x2328 = x2323;
          char  *x2326 = x2322+1;
          x2329 = x2326;
        } else {
          x2329 = x2322;
        }
      }
      int x2341 = x2327;
      if (x2341) {
        char  *x2342 = x2329;
        x2274 = 0;
      } else {
        char x2345 = x2328;
        char  *x2346 = x2329;
        int x2351 = 1/*true*/;
        char x2352 = '\0';
        char  *x2353 = 0/*null*/;
        char x2347 = x2346[0];
        int x2348 = x2347 == '\0';
        if (x2348) {
          x2353 = x2346;
        } else {
          int x2349 = x2347 == 'n';
          if (x2349) {
            x2351 = 0/*false*/;
            x2352 = x2347;
            char  *x2350 = x2346+1;
            x2353 = x2350;
          } else {
            x2353 = x2346;
          }
        }
        int x2365 = x2351;
        if (x2365) {
          char  *x2366 = x2353;
          x2274 = 0;
        } else {
          char x2369 = x2352;
          char  *x2370 = x2353;
          int x2375 = 1/*true*/;
          char x2376 = '\0';
          char  *x2377 = 0/*null*/;
          char x2371 = x2370[0];
          int x2372 = x2371 == '\0';
          if (x2372) {
            x2377 = x2370;
          } else {
            int x2373 = x2371 == 's';
            if (x2373) {
              x2375 = 0/*false*/;
              x2376 = x2371;
              char  *x2374 = x2370+1;
              x2377 = x2374;
            } else {
              x2377 = x2370;
            }
          }
          int x2389 = x2375;
          if (x2389) {
            char  *x2390 = x2377;
            x2274 = 0;
          } else {
            char x2393 = x2376;
            char  *x2394 = x2377;
            int x2399 = 1/*true*/;
            char x2400 = '\0';
            char  *x2401 = 0/*null*/;
            char x2395 = x2394[0];
            int x2396 = x2395 == '\0';
            if (x2396) {
              x2401 = x2394;
            } else {
              int x2397 = x2395 == 'f';
              if (x2397) {
                x2399 = 0/*false*/;
                x2400 = x2395;
                char  *x2398 = x2394+1;
                x2401 = x2398;
              } else {
                x2401 = x2394;
              }
            }
            int x2413 = x2399;
            if (x2413) {
              char  *x2414 = x2401;
              x2274 = 0;
            } else {
              char x2417 = x2400;
              char  *x2418 = x2401;
              int x2423 = 1/*true*/;
              char x2424 = '\0';
              char  *x2425 = 0/*null*/;
              char x2419 = x2418[0];
              int x2420 = x2419 == '\0';
              if (x2420) {
                x2425 = x2418;
              } else {
                int x2421 = x2419 == 'e';
                if (x2421) {
                  x2423 = 0/*false*/;
                  x2424 = x2419;
                  char  *x2422 = x2418+1;
                  x2425 = x2422;
                } else {
                  x2425 = x2418;
                }
              }
              int x2437 = x2423;
              if (x2437) {
                char  *x2438 = x2425;
                x2274 = 0;
              } else {
                char x2441 = x2424;
                char  *x2442 = x2425;
                int x2447 = 1/*true*/;
                char x2448 = '\0';
                char  *x2449 = 0/*null*/;
                char x2443 = x2442[0];
                int x2444 = x2443 == '\0';
                if (x2444) {
                  x2449 = x2442;
                } else {
                  int x2445 = x2443 == 'r';
                  if (x2445) {
                    x2447 = 0/*false*/;
                    x2448 = x2443;
                    char  *x2446 = x2442+1;
                    x2449 = x2446;
                  } else {
                    x2449 = x2442;
                  }
                }
                int x2461 = x2447;
                if (x2461) {
                  char  *x2462 = x2449;
                  x2274 = 0;
                } else {
                  char x2465 = x2448;
                  char  *x2466 = x2449;
                  int x2471 = 1/*true*/;
                  char x2472 = '\0';
                  char  *x2473 = 0/*null*/;
                  char x2467 = x2466[0];
                  int x2468 = x2467 == '\0';
                  if (x2468) {
                    x2473 = x2466;
                  } else {
                    int x2469 = x2467 == '-';
                    if (x2469) {
                      x2471 = 0/*false*/;
                      x2472 = x2467;
                      char  *x2470 = x2466+1;
                      x2473 = x2470;
                    } else {
                      x2473 = x2466;
                    }
                  }
                  int x2485 = x2471;
                  if (x2485) {
                    char  *x2486 = x2473;
                    x2274 = 0;
                  } else {
                    char x2489 = x2472;
                    char  *x2490 = x2473;
                    int x2495 = 1/*true*/;
                    char x2496 = '\0';
                    char  *x2497 = 0/*null*/;
                    char x2491 = x2490[0];
                    int x2492 = x2491 == '\0';
                    if (x2492) {
                      x2497 = x2490;
                    } else {
                      int x2493 = x2491 == 'E';
                      if (x2493) {
                        x2495 = 0/*false*/;
                        x2496 = x2491;
                        char  *x2494 = x2490+1;
                        x2497 = x2494;
                      } else {
                        x2497 = x2490;
                      }
                    }
                    int x2509 = x2495;
                    if (x2509) {
                      char  *x2510 = x2497;
                      x2274 = 0;
                    } else {
                      char x2513 = x2496;
                      char  *x2514 = x2497;
                      int x2519 = 1/*true*/;
                      char x2520 = '\0';
                      char  *x2521 = 0/*null*/;
                      char x2515 = x2514[0];
                      int x2516 = x2515 == '\0';
                      if (x2516) {
                        x2521 = x2514;
                      } else {
                        int x2517 = x2515 == 'n';
                        if (x2517) {
                          x2519 = 0/*false*/;
                          x2520 = x2515;
                          char  *x2518 = x2514+1;
                          x2521 = x2518;
                        } else {
                          x2521 = x2514;
                        }
                      }
                      int x2533 = x2519;
                      if (x2533) {
                        char  *x2534 = x2521;
                        x2274 = 0;
                      } else {
                        char x2537 = x2520;
                        char  *x2538 = x2521;
                        int x2543 = 1/*true*/;
                        char x2544 = '\0';
                        char  *x2545 = 0/*null*/;
                        char x2539 = x2538[0];
                        int x2540 = x2539 == '\0';
                        if (x2540) {
                          x2545 = x2538;
                        } else {
                          int x2541 = x2539 == 'c';
                          if (x2541) {
                            x2543 = 0/*false*/;
                            x2544 = x2539;
                            char  *x2542 = x2538+1;
                            x2545 = x2542;
                          } else {
                            x2545 = x2538;
                          }
                        }
                        int x2557 = x2543;
                        if (x2557) {
                          char  *x2558 = x2545;
                          x2274 = 0;
                        } else {
                          char x2561 = x2544;
                          char  *x2562 = x2545;
                          int x2567 = 1/*true*/;
                          char x2568 = '\0';
                          char  *x2569 = 0/*null*/;
                          char x2563 = x2562[0];
                          int x2564 = x2563 == '\0';
                          if (x2564) {
                            x2569 = x2562;
                          } else {
                            int x2565 = x2563 == 'o';
                            if (x2565) {
                              x2567 = 0/*false*/;
                              x2568 = x2563;
                              char  *x2566 = x2562+1;
                              x2569 = x2566;
                            } else {
                              x2569 = x2562;
                            }
                          }
                          int x2581 = x2567;
                          if (x2581) {
                            char  *x2582 = x2569;
                            x2274 = 0;
                          } else {
                            char x2585 = x2568;
                            char  *x2586 = x2569;
                            int x2591 = 1/*true*/;
                            char x2592 = '\0';
                            char  *x2593 = 0/*null*/;
                            char x2587 = x2586[0];
                            int x2588 = x2587 == '\0';
                            if (x2588) {
                              x2593 = x2586;
                            } else {
                              int x2589 = x2587 == 'd';
                              if (x2589) {
                                x2591 = 0/*false*/;
                                x2592 = x2587;
                                char  *x2590 = x2586+1;
                                x2593 = x2590;
                              } else {
                                x2593 = x2586;
                              }
                            }
                            int x2605 = x2591;
                            if (x2605) {
                              char  *x2606 = x2593;
                              x2274 = 0;
                            } else {
                              char x2609 = x2592;
                              char  *x2610 = x2593;
                              int x2615 = 1/*true*/;
                              char x2616 = '\0';
                              char  *x2617 = 0/*null*/;
                              char x2611 = x2610[0];
                              int x2612 = x2611 == '\0';
                              if (x2612) {
                                x2617 = x2610;
                              } else {
                                int x2613 = x2611 == 'i';
                                if (x2613) {
                                  x2615 = 0/*false*/;
                                  x2616 = x2611;
                                  char  *x2614 = x2610+1;
                                  x2617 = x2614;
                                } else {
                                  x2617 = x2610;
                                }
                              }
                              int x2629 = x2615;
                              if (x2629) {
                                char  *x2630 = x2617;
                                x2274 = 0;
                              } else {
                                char x2633 = x2616;
                                char  *x2634 = x2617;
                                int x2639 = 1/*true*/;
                                char x2640 = '\0';
                                char  *x2641 = 0/*null*/;
                                char x2635 = x2634[0];
                                int x2636 = x2635 == '\0';
                                if (x2636) {
                                  x2641 = x2634;
                                } else {
                                  int x2637 = x2635 == 'n';
                                  if (x2637) {
                                    x2639 = 0/*false*/;
                                    x2640 = x2635;
                                    char  *x2638 = x2634+1;
                                    x2641 = x2638;
                                  } else {
                                    x2641 = x2634;
                                  }
                                }
                                int x2653 = x2639;
                                if (x2653) {
                                  char  *x2654 = x2641;
                                  x2274 = 0;
                                } else {
                                  char x2657 = x2640;
                                  char  *x2658 = x2641;
                                  int x2663 = 1/*true*/;
                                  char x2664 = '\0';
                                  char  *x2665 = 0/*null*/;
                                  char x2659 = x2658[0];
                                  int x2660 = x2659 == '\0';
                                  if (x2660) {
                                    x2665 = x2658;
                                  } else {
                                    int x2661 = x2659 == 'g';
                                    if (x2661) {
                                      x2663 = 0/*false*/;
                                      x2664 = x2659;
                                      char  *x2662 = x2658+1;
                                      x2665 = x2662;
                                    } else {
                                      x2665 = x2658;
                                    }
                                  }
                                  int x2677 = x2663;
                                  if (x2677) {
                                    char  *x2678 = x2665;
                                    x2274 = 0;
                                  } else {
                                    char x2681 = x2664;
                                    char  *x2682 = x2665;
                                    x2274 = x2682;
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
  char  *x2718 = x2274;
  return x2718;
}
/*@
requires ((strlen(x2734)>=0) && \valid(x2734+(0..strlen(x2734))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_chunked(char  * x2734) {
  char  *x2736 = x2734;
  int x2741 = 1/*true*/;
  char x2742 = '\0';
  char  *x2743 = 0/*null*/;
  char x2737 = x2734[0];
  int x2738 = x2737 == '\0';
  if (x2738) {
    x2743 = x2734;
  } else {
    int x2739 = x2737 == 'c';
    if (x2739) {
      x2741 = 0/*false*/;
      x2742 = x2737;
      char  *x2740 = x2734+1;
      x2743 = x2740;
    } else {
      x2743 = x2734;
    }
  }
  int x2755 = x2741;
  if (x2755) {
    char  *x2756 = x2743;
    x2736 = 0;
  } else {
    char x2759 = x2742;
    char  *x2760 = x2743;
    int x2765 = 1/*true*/;
    char x2766 = '\0';
    char  *x2767 = 0/*null*/;
    char x2761 = x2760[0];
    int x2762 = x2761 == '\0';
    if (x2762) {
      x2767 = x2760;
    } else {
      int x2763 = x2761 == 'h';
      if (x2763) {
        x2765 = 0/*false*/;
        x2766 = x2761;
        char  *x2764 = x2760+1;
        x2767 = x2764;
      } else {
        x2767 = x2760;
      }
    }
    int x2779 = x2765;
    if (x2779) {
      char  *x2780 = x2767;
      x2736 = 0;
    } else {
      char x2783 = x2766;
      char  *x2784 = x2767;
      int x2789 = 1/*true*/;
      char x2790 = '\0';
      char  *x2791 = 0/*null*/;
      char x2785 = x2784[0];
      int x2786 = x2785 == '\0';
      if (x2786) {
        x2791 = x2784;
      } else {
        int x2787 = x2785 == 'u';
        if (x2787) {
          x2789 = 0/*false*/;
          x2790 = x2785;
          char  *x2788 = x2784+1;
          x2791 = x2788;
        } else {
          x2791 = x2784;
        }
      }
      int x2803 = x2789;
      if (x2803) {
        char  *x2804 = x2791;
        x2736 = 0;
      } else {
        char x2807 = x2790;
        char  *x2808 = x2791;
        int x2813 = 1/*true*/;
        char x2814 = '\0';
        char  *x2815 = 0/*null*/;
        char x2809 = x2808[0];
        int x2810 = x2809 == '\0';
        if (x2810) {
          x2815 = x2808;
        } else {
          int x2811 = x2809 == 'n';
          if (x2811) {
            x2813 = 0/*false*/;
            x2814 = x2809;
            char  *x2812 = x2808+1;
            x2815 = x2812;
          } else {
            x2815 = x2808;
          }
        }
        int x2827 = x2813;
        if (x2827) {
          char  *x2828 = x2815;
          x2736 = 0;
        } else {
          char x2831 = x2814;
          char  *x2832 = x2815;
          int x2837 = 1/*true*/;
          char x2838 = '\0';
          char  *x2839 = 0/*null*/;
          char x2833 = x2832[0];
          int x2834 = x2833 == '\0';
          if (x2834) {
            x2839 = x2832;
          } else {
            int x2835 = x2833 == 'k';
            if (x2835) {
              x2837 = 0/*false*/;
              x2838 = x2833;
              char  *x2836 = x2832+1;
              x2839 = x2836;
            } else {
              x2839 = x2832;
            }
          }
          int x2851 = x2837;
          if (x2851) {
            char  *x2852 = x2839;
            x2736 = 0;
          } else {
            char x2855 = x2838;
            char  *x2856 = x2839;
            int x2861 = 1/*true*/;
            char x2862 = '\0';
            char  *x2863 = 0/*null*/;
            char x2857 = x2856[0];
            int x2858 = x2857 == '\0';
            if (x2858) {
              x2863 = x2856;
            } else {
              int x2859 = x2857 == 'e';
              if (x2859) {
                x2861 = 0/*false*/;
                x2862 = x2857;
                char  *x2860 = x2856+1;
                x2863 = x2860;
              } else {
                x2863 = x2856;
              }
            }
            int x2875 = x2861;
            if (x2875) {
              char  *x2876 = x2863;
              x2736 = 0;
            } else {
              char x2879 = x2862;
              char  *x2880 = x2863;
              int x2885 = 1/*true*/;
              char x2886 = '\0';
              char  *x2887 = 0/*null*/;
              char x2881 = x2880[0];
              int x2882 = x2881 == '\0';
              if (x2882) {
                x2887 = x2880;
              } else {
                int x2883 = x2881 == 'd';
                if (x2883) {
                  x2885 = 0/*false*/;
                  x2886 = x2881;
                  char  *x2884 = x2880+1;
                  x2887 = x2884;
                } else {
                  x2887 = x2880;
                }
              }
              int x2899 = x2885;
              if (x2899) {
                char  *x2900 = x2887;
                x2736 = 0;
              } else {
                char x2903 = x2886;
                char  *x2904 = x2887;
                x2736 = x2904;
              }
            }
          }
        }
      }
    }
  }
  char  *x2920 = x2736;
  return x2920;
}
