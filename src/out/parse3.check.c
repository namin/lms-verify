#include <limits.h>
#include <string.h>
char  * p_HTTP(char  * x1176);
char  * p_ContentLength(char  * x1178);
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
    int x985 = -2 == -2;
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
      char  *x493 = 0/*null*/;
      int x475 = 0 != x474;
      if (x475) {
        x491 = 0/*false*/;
        x493 = x474;
      } else {
        x493 = x473;
      }
      int x501 = x491;
      if (x501) {
        char  *x502 = x493;
      } else {
        char  *x505 = x493;
        x488 = 0/*false*/;
        x489 = 1;
        x490 = x505;
      }
      int x511 = x488;
      if (x511) {
        char  *x512 = x473;
        int x513 = 1/*true*/;
        /*@
        loop invariant ((strlen(x512)>=0) && \valid(x512+(0..strlen(x512))));
        loop assigns x512, x513;
        */
        for (;;) {
          int x514 = x513;
          if (!x514) break;
          char  *x516 = x512;
          int x527 = 1/*true*/;
          char x528 = '\0';
          char  *x529 = 0/*null*/;
          char x517 = x516[0];
          int x518 = x517 == '\0';
          if (x518) {
          } else {
            int x519 = x517 >= 'a';
            int x521;
            if (x519) {
              int x520 = x517 <= 'z';
              x521 = x520;
            } else {
              x521 = 0/*false*/;
            }
            int x522 = x517 >= 'A';
            int x524;
            if (x522) {
              int x523 = x517 <= 'Z';
              x524 = x523;
            } else {
              x524 = 0/*false*/;
            }
            int x525 = x521 || x524;
            if (x525) {
              x527 = 0/*false*/;
              x528 = x517;
              char  *x526 = x516+1;
              x529 = x526;
            } else {
            }
          }
          int x537 = x527;
          char x539 = x528;
          char  *x540 = x529;
          if (x537) {
            if (x518) {
              x513 = 0/*false*/;
            } else {
              int x538 = x517 == '-';
              if (x538) {
                char  *x526 = x516+1;
                x512 = x526;
              } else {
                x513 = 0/*false*/;
              }
            }
          } else {
            x512 = x540;
          }
        }
        char  *x568 = x512;
        x485 = 0/*false*/;
        x486 = 0;
        x487 = x568;
      } else {
        int x573 = x489;
        char  *x574 = x490;
        x485 = 0/*false*/;
        x486 = x573;
        x487 = x574;
      }
      int x580 = x485;
      if (x580) {
        char  *x581 = x487;
        x484 = x581;
      } else {
        int x584 = x486;
        char  *x585 = x487;
        char  *x586 = x585;
        int x587 = 1/*true*/;
        /*@
        loop invariant ((strlen(x586)>=0) && \valid(x586+(0..strlen(x586))));
        loop assigns x586, x587;
        */
        for (;;) {
          int x588 = x587;
          if (!x588) break;
          char  *x590 = x586;
          char x591 = x590[0];
          int x592 = x591 == '\0';
          if (x592) {
            x587 = 0/*false*/;
          } else {
            int x593 = x591 == ' ';
            if (x593) {
              char  *x594 = x590+1;
              x586 = x594;
            } else {
              x587 = 0/*false*/;
            }
          }
        }
        char  *x618 = x586;
        x482 = 0/*false*/;
        x483 = x584;
        x484 = x618;
      }
      int x624 = x482;
      if (x624) {
        char  *x625 = x484;
        x481 = x625;
      } else {
        int x628 = x483;
        char  *x629 = x484;
        int x634 = 1/*true*/;
        char x635 = '\0';
        char  *x636 = 0/*null*/;
        char x630 = x629[0];
        int x631 = x630 == '\0';
        if (x631) {
          x636 = x629;
        } else {
          int x632 = x630 == ':';
          if (x632) {
            x634 = 0/*false*/;
            x635 = x630;
            char  *x633 = x629+1;
            x636 = x633;
          } else {
            x636 = x629;
          }
        }
        int x648 = x634;
        if (x648) {
          char  *x649 = x636;
          x481 = x649;
        } else {
          char x652 = x635;
          char  *x653 = x636;
          x479 = 0/*false*/;
          x480 = x628;
          x481 = x653;
        }
      }
      int x661 = x479;
      if (x661) {
        char  *x662 = x481;
        x478 = x662;
      } else {
        int x665 = x480;
        char  *x666 = x481;
        char  *x667 = x666;
        int x668 = 1/*true*/;
        /*@
        loop invariant ((strlen(x667)>=0) && \valid(x667+(0..strlen(x667))));
        loop assigns x667, x668;
        */
        for (;;) {
          int x669 = x668;
          if (!x669) break;
          char  *x671 = x667;
          char x672 = x671[0];
          int x673 = x672 == '\0';
          if (x673) {
            x668 = 0/*false*/;
          } else {
            int x674 = x672 == ' ';
            if (x674) {
              char  *x675 = x671+1;
              x667 = x675;
            } else {
              x668 = 0/*false*/;
            }
          }
        }
        char  *x699 = x667;
        x476 = 0/*false*/;
        x477 = x665;
        x478 = x699;
      }
      int x705 = x476;
      if (x705) {
        char  *x706 = x478;
        x469 = 0/*false*/;
      } else {
        int x709 = x477;
        char  *x710 = x478;
        char  *x718 = x710;
        int x719 = 1/*true*/;
        /*@
        loop invariant ((strlen(x718)>=0) && \valid(x718+(0..strlen(x718))));
        loop assigns x718, x719;
        */
        for (;;) {
          int x720 = x719;
          if (!x720) break;
          char  *x722 = x718;
          char x723 = x722[0];
          int x724 = x723 == '\0';
          if (x724) {
            x719 = 0/*false*/;
          } else {
            int x725 = x723 != '\n';
            if (x725) {
              char  *x726 = x722+1;
              x718 = x726;
            } else {
              x719 = 0/*false*/;
            }
          }
        }
        char  *x750 = x718;
        int x711 = x709 == 1;
        if (x711) {
          int x751 = 1/*true*/;
          int x752 = 0;
          char  *x753 = 0/*null*/;
          int x754 = 1/*true*/;
          int x755 = 0;
          char  *x756 = 0/*null*/;
          int x757 = 1/*true*/;
          int x758 = 0;
          char  *x759 = 0/*null*/;
          int x760 = 1/*true*/;
          char x761 = '\0';
          char  *x762 = 0/*null*/;
          char x712 = x710[0];
          int x713 = x712 == '\0';
          if (x713) {
            x762 = x710;
          } else {
            int x714 = x712 >= '0';
            int x716;
            if (x714) {
              int x715 = x712 <= '9';
              x716 = x715;
            } else {
              x716 = 0/*false*/;
            }
            if (x716) {
              x760 = 0/*false*/;
              x761 = x712;
              char  *x717 = x710+1;
              x762 = x717;
            } else {
              x762 = x710;
            }
          }
          int x774 = x760;
          if (x774) {
            char  *x775 = x762;
            x759 = x775;
          } else {
            char x778 = x761;
            char  *x780 = x762;
            x757 = 0/*false*/;
            char x779 = x778 - '0';
            x758 = x779;
            x759 = x780;
          }
          int x786 = x757;
          if (x786) {
            char  *x787 = x759;
            x756 = x787;
          } else {
            int x790 = x758;
            char  *x791 = x759;
            char  *x792 = x791;
            int x793 = 1/*true*/;
            int x794 = x790;
            /*@
            loop invariant (((strlen(x792)>=0) && \valid(x792+(0..strlen(x792)))) && ((x794==-1) || (0<=x794)));
            loop assigns x792, x793, x794;
            */
            for (;;) {
              int x795 = x793;
              if (!x795) break;
              char  *x797 = x792;
              int x804 = 1/*true*/;
              char x805 = '\0';
              char  *x806 = 0/*null*/;
              char x798 = x797[0];
              int x799 = x798 == '\0';
              if (x799) {
                x806 = x797;
              } else {
                int x800 = x798 >= '0';
                int x802;
                if (x800) {
                  int x801 = x798 <= '9';
                  x802 = x801;
                } else {
                  x802 = 0/*false*/;
                }
                if (x802) {
                  x804 = 0/*false*/;
                  x805 = x798;
                  char  *x803 = x797+1;
                  x806 = x803;
                } else {
                  x806 = x797;
                }
              }
              int x818 = x804;
              if (x818) {
                char  *x819 = x806;
                x793 = 0/*false*/;
              } else {
                char x822 = x805;
                char  *x824 = x806;
                int x825 = x794;
                int x826 = x825 < 0;
                int x831;
                if (x826) {
                  x831 = x825;
                } else {
                  int x827 = x825 > x338;
                  int x830;
                  if (x827) {
                    x830 = -1;
                  } else {
                    char x823 = x822 - '0';
                    int x828 = x825 * 10;
                    int x829 = x828 + x823;
                    x830 = x829;
                  }
                  x831 = x830;
                }
                x794 = x831;
                x792 = x824;
              }
            }
            int x857 = x794;
            char  *x858 = x792;
            x754 = 0/*false*/;
            x755 = x857;
            x756 = x858;
          }
          int x864 = x754;
          if (x864) {
            char  *x865 = x756;
            x753 = x865;
          } else {
            int x868 = x755;
            char  *x869 = x756;
            char  *x870 = x869;
            int x871 = 1/*true*/;
            /*@
            loop invariant ((strlen(x870)>=0) && \valid(x870+(0..strlen(x870))));
            loop assigns x870, x871;
            */
            for (;;) {
              int x872 = x871;
              if (!x872) break;
              char  *x874 = x870;
              char x875 = x874[0];
              int x876 = x875 == '\0';
              if (x876) {
                x871 = 0/*false*/;
              } else {
                int x877 = x875 == ' ';
                if (x877) {
                  char  *x878 = x874+1;
                  x870 = x878;
                } else {
                  x871 = 0/*false*/;
                }
              }
            }
            char  *x902 = x870;
            x751 = 0/*false*/;
            x752 = x868;
            x753 = x902;
          }
          int x908 = x751;
          if (x908) {
            char  *x909 = x753;
            x469 = 0/*false*/;
          } else {
            int x912 = x752;
            char  *x913 = x753;
            int x918 = 1/*true*/;
            char x919 = '\0';
            char  *x920 = 0/*null*/;
            char x914 = x913[0];
            int x915 = x914 == '\0';
            if (x915) {
              x920 = x913;
            } else {
              int x916 = x914 == '\n';
              if (x916) {
                x918 = 0/*false*/;
                x919 = x914;
                char  *x917 = x913+1;
                x920 = x917;
              } else {
                x920 = x913;
              }
            }
            int x932 = x918;
            if (x932) {
              char  *x933 = x920;
              x469 = 0/*false*/;
            } else {
              char x936 = x919;
              char  *x937 = x920;
              int x938 = x470;
              int x939 = x912 == -2;
              int x940;
              if (x939) {
                x940 = x938;
              } else {
                x940 = x912;
              }
              x470 = x940;
              x468 = x937;
            }
          }
        } else {
          int x948 = 1/*true*/;
          char  *x950 = 0/*null*/;
          x948 = 0/*false*/;
          x950 = x750;
          int x954 = x948;
          if (x954) {
            char  *x955 = x950;
            x469 = 0/*false*/;
          } else {
            char  *x959 = x950;
            int x964 = 1/*true*/;
            char x965 = '\0';
            char  *x966 = 0/*null*/;
            char x960 = x959[0];
            int x961 = x960 == '\0';
            if (x961) {
              x966 = x959;
            } else {
              int x962 = x960 == '\n';
              if (x962) {
                x964 = 0/*false*/;
                x965 = x960;
                char  *x963 = x959+1;
                x966 = x963;
              } else {
                x966 = x959;
              }
            }
            int x978 = x964;
            if (x978) {
              char  *x979 = x966;
              x469 = 0/*false*/;
            } else {
              char x982 = x965;
              char  *x983 = x966;
              int x984 = x470;
              int x986;
              if (x985) {
                x986 = x984;
              } else {
                x986 = -2;
              }
              x470 = x986;
              x468 = x983;
            }
          }
        }
      }
    }
    int x1013 = x470;
    char  *x1014 = x468;
    x8 = 0/*false*/;
    x9 = x1013;
    x10 = x1014;
  }
  int x1020 = x8;
  if (x1020) {
    char  *x1021 = x10;
    x7 = x1021;
  } else {
    int x1024 = x9;
    char  *x1025 = x10;
    int x1030 = 1/*true*/;
    char x1031 = '\0';
    char  *x1032 = 0/*null*/;
    char x1026 = x1025[0];
    int x1027 = x1026 == '\0';
    if (x1027) {
      x1032 = x1025;
    } else {
      int x1028 = x1026 == '\n';
      if (x1028) {
        x1030 = 0/*false*/;
        x1031 = x1026;
        char  *x1029 = x1025+1;
        x1032 = x1029;
      } else {
        x1032 = x1025;
      }
    }
    int x1044 = x1030;
    if (x1044) {
      char  *x1045 = x1032;
      x7 = x1045;
    } else {
      char x1048 = x1031;
      char  *x1049 = x1032;
      x5 = 0/*false*/;
      x6 = x1024;
      x7 = x1049;
    }
  }
  int x1057 = x5;
  if (x1057) {
    char  *x1058 = x7;
  } else {
    int x1060 = x6;
    char  *x1061 = x7;
    int x1063 = 1/*true*/;
    char  *x1064 = x1061;
    /*@
    loop invariant ((0<=x1066) && ((strlen(x1064)>=0) && \valid(x1064+(0..strlen(x1064)))));
    loop assigns x1066, x1063, x1064;
    loop variant (x6-x1066);
    */
    for(int x1066=0; x1066 < x1060; x1066++) {
      int x1067 = x1063;
      if (x1067) {
        char  *x1068 = x1064;
        char x1069 = x1068[0];
        int x1070 = x1069 == '\0';
        if (x1070) {
          x1063 = 0/*false*/;
        } else {
          if (1/*true*/) {
            char  *x1071 = x1068+1;
            x1064 = x1071;
          } else {
            x1063 = 0/*false*/;
          }
        }
      } else {
      }
    }
    int x1101 = x1063;
    char  *x1102 = x1064;
    int x1062 = x1060 < 0;
    if (x1062) {
    } else {
      int x1103 = 1/*true*/;
      int x1104 = 0;
      char  *x1105 = 0/*null*/;
      int x1106 = 1/*true*/;
      char  *x1108 = 0/*null*/;
      if (x1101) {
        x1106 = 0/*false*/;
        x1108 = x1102;
      } else {
        x1108 = x1061;
      }
      int x1116 = x1106;
      if (x1116) {
        char  *x1117 = x1108;
        x1105 = x1117;
      } else {
        char  *x1121 = x1108;
        x1103 = 0/*false*/;
        x1104 = x1060;
        x1105 = x1121;
      }
      int x1127 = x1103;
      if (x1127) {
        char  *x1128 = x1105;
      } else {
        int x1130 = x1104;
        char  *x1131 = x1105;
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
        } else {
          char x1153 = x1137;
          char  *x1154 = x1138;
          char x1155 = x1154[0];
          int x1156 = x1155 == '\0';
          if (x1156) {
            x2 = x1130;
          } else {
          }
        }
      }
    }
  }
  int x1168 = x2;
  return x1168;
}
/*@
requires ((strlen(x1180)>=0) && \valid(x1180+(0..strlen(x1180))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_HTTP(char  * x1180) {
  char  *x1182 = x1180;
  int x1187 = 1/*true*/;
  char x1188 = '\0';
  char  *x1189 = 0/*null*/;
  char x1183 = x1180[0];
  int x1184 = x1183 == '\0';
  if (x1184) {
    x1189 = x1180;
  } else {
    int x1185 = x1183 == 'H';
    if (x1185) {
      x1187 = 0/*false*/;
      x1188 = x1183;
      char  *x1186 = x1180+1;
      x1189 = x1186;
    } else {
      x1189 = x1180;
    }
  }
  int x1201 = x1187;
  if (x1201) {
    char  *x1202 = x1189;
    x1182 = 0;
  } else {
    char x1205 = x1188;
    char  *x1206 = x1189;
    int x1211 = 1/*true*/;
    char x1212 = '\0';
    char  *x1213 = 0/*null*/;
    char x1207 = x1206[0];
    int x1208 = x1207 == '\0';
    if (x1208) {
      x1213 = x1206;
    } else {
      int x1209 = x1207 == 'T';
      if (x1209) {
        x1211 = 0/*false*/;
        x1212 = x1207;
        char  *x1210 = x1206+1;
        x1213 = x1210;
      } else {
        x1213 = x1206;
      }
    }
    int x1225 = x1211;
    if (x1225) {
      char  *x1226 = x1213;
      x1182 = 0;
    } else {
      char x1229 = x1212;
      char  *x1230 = x1213;
      int x1235 = 1/*true*/;
      char x1236 = '\0';
      char  *x1237 = 0/*null*/;
      char x1231 = x1230[0];
      int x1232 = x1231 == '\0';
      if (x1232) {
        x1237 = x1230;
      } else {
        int x1233 = x1231 == 'T';
        if (x1233) {
          x1235 = 0/*false*/;
          x1236 = x1231;
          char  *x1234 = x1230+1;
          x1237 = x1234;
        } else {
          x1237 = x1230;
        }
      }
      int x1249 = x1235;
      if (x1249) {
        char  *x1250 = x1237;
        x1182 = 0;
      } else {
        char x1253 = x1236;
        char  *x1254 = x1237;
        int x1259 = 1/*true*/;
        char x1260 = '\0';
        char  *x1261 = 0/*null*/;
        char x1255 = x1254[0];
        int x1256 = x1255 == '\0';
        if (x1256) {
          x1261 = x1254;
        } else {
          int x1257 = x1255 == 'P';
          if (x1257) {
            x1259 = 0/*false*/;
            x1260 = x1255;
            char  *x1258 = x1254+1;
            x1261 = x1258;
          } else {
            x1261 = x1254;
          }
        }
        int x1273 = x1259;
        if (x1273) {
          char  *x1274 = x1261;
          x1182 = 0;
        } else {
          char x1277 = x1260;
          char  *x1278 = x1261;
          int x1283 = 1/*true*/;
          char x1284 = '\0';
          char  *x1285 = 0/*null*/;
          char x1279 = x1278[0];
          int x1280 = x1279 == '\0';
          if (x1280) {
            x1285 = x1278;
          } else {
            int x1281 = x1279 == '/';
            if (x1281) {
              x1283 = 0/*false*/;
              x1284 = x1279;
              char  *x1282 = x1278+1;
              x1285 = x1282;
            } else {
              x1285 = x1278;
            }
          }
          int x1297 = x1283;
          if (x1297) {
            char  *x1298 = x1285;
            x1182 = 0;
          } else {
            char x1301 = x1284;
            char  *x1302 = x1285;
            x1182 = x1302;
          }
        }
      }
    }
  }
  char  *x1314 = x1182;
  return x1314;
}
/*@
requires ((strlen(x1330)>=0) && \valid(x1330+(0..strlen(x1330))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_ContentLength(char  * x1330) {
  char  *x1332 = x1330;
  int x1337 = 1/*true*/;
  char x1338 = '\0';
  char  *x1339 = 0/*null*/;
  char x1333 = x1330[0];
  int x1334 = x1333 == '\0';
  if (x1334) {
    x1339 = x1330;
  } else {
    int x1335 = x1333 == 'C';
    if (x1335) {
      x1337 = 0/*false*/;
      x1338 = x1333;
      char  *x1336 = x1330+1;
      x1339 = x1336;
    } else {
      x1339 = x1330;
    }
  }
  int x1351 = x1337;
  if (x1351) {
    char  *x1352 = x1339;
    x1332 = 0;
  } else {
    char x1355 = x1338;
    char  *x1356 = x1339;
    int x1361 = 1/*true*/;
    char x1362 = '\0';
    char  *x1363 = 0/*null*/;
    char x1357 = x1356[0];
    int x1358 = x1357 == '\0';
    if (x1358) {
      x1363 = x1356;
    } else {
      int x1359 = x1357 == 'o';
      if (x1359) {
        x1361 = 0/*false*/;
        x1362 = x1357;
        char  *x1360 = x1356+1;
        x1363 = x1360;
      } else {
        x1363 = x1356;
      }
    }
    int x1375 = x1361;
    if (x1375) {
      char  *x1376 = x1363;
      x1332 = 0;
    } else {
      char x1379 = x1362;
      char  *x1380 = x1363;
      int x1385 = 1/*true*/;
      char x1386 = '\0';
      char  *x1387 = 0/*null*/;
      char x1381 = x1380[0];
      int x1382 = x1381 == '\0';
      if (x1382) {
        x1387 = x1380;
      } else {
        int x1383 = x1381 == 'n';
        if (x1383) {
          x1385 = 0/*false*/;
          x1386 = x1381;
          char  *x1384 = x1380+1;
          x1387 = x1384;
        } else {
          x1387 = x1380;
        }
      }
      int x1399 = x1385;
      if (x1399) {
        char  *x1400 = x1387;
        x1332 = 0;
      } else {
        char x1403 = x1386;
        char  *x1404 = x1387;
        int x1409 = 1/*true*/;
        char x1410 = '\0';
        char  *x1411 = 0/*null*/;
        char x1405 = x1404[0];
        int x1406 = x1405 == '\0';
        if (x1406) {
          x1411 = x1404;
        } else {
          int x1407 = x1405 == 't';
          if (x1407) {
            x1409 = 0/*false*/;
            x1410 = x1405;
            char  *x1408 = x1404+1;
            x1411 = x1408;
          } else {
            x1411 = x1404;
          }
        }
        int x1423 = x1409;
        if (x1423) {
          char  *x1424 = x1411;
          x1332 = 0;
        } else {
          char x1427 = x1410;
          char  *x1428 = x1411;
          int x1433 = 1/*true*/;
          char x1434 = '\0';
          char  *x1435 = 0/*null*/;
          char x1429 = x1428[0];
          int x1430 = x1429 == '\0';
          if (x1430) {
            x1435 = x1428;
          } else {
            int x1431 = x1429 == 'e';
            if (x1431) {
              x1433 = 0/*false*/;
              x1434 = x1429;
              char  *x1432 = x1428+1;
              x1435 = x1432;
            } else {
              x1435 = x1428;
            }
          }
          int x1447 = x1433;
          if (x1447) {
            char  *x1448 = x1435;
            x1332 = 0;
          } else {
            char x1451 = x1434;
            char  *x1452 = x1435;
            int x1457 = 1/*true*/;
            char x1458 = '\0';
            char  *x1459 = 0/*null*/;
            char x1453 = x1452[0];
            int x1454 = x1453 == '\0';
            if (x1454) {
              x1459 = x1452;
            } else {
              int x1455 = x1453 == 'n';
              if (x1455) {
                x1457 = 0/*false*/;
                x1458 = x1453;
                char  *x1456 = x1452+1;
                x1459 = x1456;
              } else {
                x1459 = x1452;
              }
            }
            int x1471 = x1457;
            if (x1471) {
              char  *x1472 = x1459;
              x1332 = 0;
            } else {
              char x1475 = x1458;
              char  *x1476 = x1459;
              int x1481 = 1/*true*/;
              char x1482 = '\0';
              char  *x1483 = 0/*null*/;
              char x1477 = x1476[0];
              int x1478 = x1477 == '\0';
              if (x1478) {
                x1483 = x1476;
              } else {
                int x1479 = x1477 == 't';
                if (x1479) {
                  x1481 = 0/*false*/;
                  x1482 = x1477;
                  char  *x1480 = x1476+1;
                  x1483 = x1480;
                } else {
                  x1483 = x1476;
                }
              }
              int x1495 = x1481;
              if (x1495) {
                char  *x1496 = x1483;
                x1332 = 0;
              } else {
                char x1499 = x1482;
                char  *x1500 = x1483;
                int x1505 = 1/*true*/;
                char x1506 = '\0';
                char  *x1507 = 0/*null*/;
                char x1501 = x1500[0];
                int x1502 = x1501 == '\0';
                if (x1502) {
                  x1507 = x1500;
                } else {
                  int x1503 = x1501 == '-';
                  if (x1503) {
                    x1505 = 0/*false*/;
                    x1506 = x1501;
                    char  *x1504 = x1500+1;
                    x1507 = x1504;
                  } else {
                    x1507 = x1500;
                  }
                }
                int x1519 = x1505;
                if (x1519) {
                  char  *x1520 = x1507;
                  x1332 = 0;
                } else {
                  char x1523 = x1506;
                  char  *x1524 = x1507;
                  int x1529 = 1/*true*/;
                  char x1530 = '\0';
                  char  *x1531 = 0/*null*/;
                  char x1525 = x1524[0];
                  int x1526 = x1525 == '\0';
                  if (x1526) {
                    x1531 = x1524;
                  } else {
                    int x1527 = x1525 == 'L';
                    if (x1527) {
                      x1529 = 0/*false*/;
                      x1530 = x1525;
                      char  *x1528 = x1524+1;
                      x1531 = x1528;
                    } else {
                      x1531 = x1524;
                    }
                  }
                  int x1543 = x1529;
                  if (x1543) {
                    char  *x1544 = x1531;
                    x1332 = 0;
                  } else {
                    char x1547 = x1530;
                    char  *x1548 = x1531;
                    int x1553 = 1/*true*/;
                    char x1554 = '\0';
                    char  *x1555 = 0/*null*/;
                    char x1549 = x1548[0];
                    int x1550 = x1549 == '\0';
                    if (x1550) {
                      x1555 = x1548;
                    } else {
                      int x1551 = x1549 == 'e';
                      if (x1551) {
                        x1553 = 0/*false*/;
                        x1554 = x1549;
                        char  *x1552 = x1548+1;
                        x1555 = x1552;
                      } else {
                        x1555 = x1548;
                      }
                    }
                    int x1567 = x1553;
                    if (x1567) {
                      char  *x1568 = x1555;
                      x1332 = 0;
                    } else {
                      char x1571 = x1554;
                      char  *x1572 = x1555;
                      int x1577 = 1/*true*/;
                      char x1578 = '\0';
                      char  *x1579 = 0/*null*/;
                      char x1573 = x1572[0];
                      int x1574 = x1573 == '\0';
                      if (x1574) {
                        x1579 = x1572;
                      } else {
                        int x1575 = x1573 == 'n';
                        if (x1575) {
                          x1577 = 0/*false*/;
                          x1578 = x1573;
                          char  *x1576 = x1572+1;
                          x1579 = x1576;
                        } else {
                          x1579 = x1572;
                        }
                      }
                      int x1591 = x1577;
                      if (x1591) {
                        char  *x1592 = x1579;
                        x1332 = 0;
                      } else {
                        char x1595 = x1578;
                        char  *x1596 = x1579;
                        int x1601 = 1/*true*/;
                        char x1602 = '\0';
                        char  *x1603 = 0/*null*/;
                        char x1597 = x1596[0];
                        int x1598 = x1597 == '\0';
                        if (x1598) {
                          x1603 = x1596;
                        } else {
                          int x1599 = x1597 == 'g';
                          if (x1599) {
                            x1601 = 0/*false*/;
                            x1602 = x1597;
                            char  *x1600 = x1596+1;
                            x1603 = x1600;
                          } else {
                            x1603 = x1596;
                          }
                        }
                        int x1615 = x1601;
                        if (x1615) {
                          char  *x1616 = x1603;
                          x1332 = 0;
                        } else {
                          char x1619 = x1602;
                          char  *x1620 = x1603;
                          int x1625 = 1/*true*/;
                          char x1626 = '\0';
                          char  *x1627 = 0/*null*/;
                          char x1621 = x1620[0];
                          int x1622 = x1621 == '\0';
                          if (x1622) {
                            x1627 = x1620;
                          } else {
                            int x1623 = x1621 == 't';
                            if (x1623) {
                              x1625 = 0/*false*/;
                              x1626 = x1621;
                              char  *x1624 = x1620+1;
                              x1627 = x1624;
                            } else {
                              x1627 = x1620;
                            }
                          }
                          int x1639 = x1625;
                          if (x1639) {
                            char  *x1640 = x1627;
                            x1332 = 0;
                          } else {
                            char x1643 = x1626;
                            char  *x1644 = x1627;
                            int x1649 = 1/*true*/;
                            char x1650 = '\0';
                            char  *x1651 = 0/*null*/;
                            char x1645 = x1644[0];
                            int x1646 = x1645 == '\0';
                            if (x1646) {
                              x1651 = x1644;
                            } else {
                              int x1647 = x1645 == 'h';
                              if (x1647) {
                                x1649 = 0/*false*/;
                                x1650 = x1645;
                                char  *x1648 = x1644+1;
                                x1651 = x1648;
                              } else {
                                x1651 = x1644;
                              }
                            }
                            int x1663 = x1649;
                            if (x1663) {
                              char  *x1664 = x1651;
                              x1332 = 0;
                            } else {
                              char x1667 = x1650;
                              char  *x1668 = x1651;
                              x1332 = x1668;
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
  char  *x1698 = x1332;
  return x1698;
}
