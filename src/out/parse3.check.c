#include <limits.h>
#include <string.h>
char  * p_HTTP(char  * x1096);
char  * p_(char  * x1098);
char  * p_ContentLength(char  * x1100);
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0))));
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
  int x32 = 0 == x3;
  if (x32) {
    x31 = x0;
  } else {
    x29 = 0/*false*/;
    x31 = x3;
  }
  int x40 = x29;
  if (x40) {
    char  *x41 = x31;
    x28 = x41;
  } else {
    char  *x45 = x31;
    int x52 = 1/*true*/;
    char x53 = '\0';
    char  *x54 = 0/*null*/;
    char x46 = x45[0];
    int x47 = x46 == '\0';
    if (x47) {
      x54 = x45;
    } else {
      int x48 = x46 >= '0';
      int x50;
      if (x48) {
        int x49 = x46 <= '9';
        x50 = x49;
      } else {
        x50 = 0/*false*/;
      }
      if (x50) {
        x52 = 0/*false*/;
        x53 = x46;
        char  *x51 = x45+1;
        x54 = x51;
      } else {
        x54 = x45;
      }
    }
    int x66 = x52;
    if (x66) {
      char  *x67 = x54;
      x28 = x67;
    } else {
      char x70 = x53;
      char  *x71 = x54;
      char  *x72 = x71;
      int x73 = 1/*true*/;
      /*@
      loop invariant ((strlen(x72)>=0) &&
      \valid(x72+(0..strlen(x72))));
      loop assigns x72, x73;
      */
      for (;;) {
        int x74 = x73;
        if (!x74) break;
        char  *x76 = x72;
        char x77 = x76[0];
        int x78 = x77 == '\0';
        if (x78) {
          x73 = 0/*false*/;
        } else {
          int x79 = x77 >= '0';
          int x81;
          if (x79) {
            int x80 = x77 <= '9';
            x81 = x80;
          } else {
            x81 = 0/*false*/;
          }
          if (x81) {
            char  *x82 = x76+1;
            x72 = x82;
          } else {
            x73 = 0/*false*/;
          }
        }
      }
      char  *x106 = x72;
      x26 = 0/*false*/;
      x28 = x106;
    }
  }
  int x114 = x26;
  if (x114) {
    char  *x115 = x28;
    x25 = x115;
  } else {
    char  *x119 = x28;
    char x120 = x119[0];
    int x121 = x120 == '\0';
    if (x121) {
      x25 = x119;
    } else {
      int x122 = x120 == '.';
      if (x122) {
        x23 = 0/*false*/;
        x24 = x120;
        char  *x123 = x119+1;
        x25 = x123;
      } else {
        x25 = x119;
      }
    }
  }
  int x137 = x23;
  if (x137) {
    char  *x138 = x25;
    x22 = x138;
  } else {
    char x141 = x24;
    char  *x142 = x25;
    int x149 = 1/*true*/;
    char x150 = '\0';
    char  *x151 = 0/*null*/;
    char x143 = x142[0];
    int x144 = x143 == '\0';
    if (x144) {
      x151 = x142;
    } else {
      int x145 = x143 >= '0';
      int x147;
      if (x145) {
        int x146 = x143 <= '9';
        x147 = x146;
      } else {
        x147 = 0/*false*/;
      }
      if (x147) {
        x149 = 0/*false*/;
        x150 = x143;
        char  *x148 = x142+1;
        x151 = x148;
      } else {
        x151 = x142;
      }
    }
    int x163 = x149;
    if (x163) {
      char  *x164 = x151;
      x22 = x164;
    } else {
      char x167 = x150;
      char  *x168 = x151;
      char  *x169 = x168;
      int x170 = 1/*true*/;
      /*@
      loop invariant ((strlen(x169)>=0) &&
      \valid(x169+(0..strlen(x169))));
      loop assigns x169, x170;
      */
      for (;;) {
        int x171 = x170;
        if (!x171) break;
        char  *x173 = x169;
        char x174 = x173[0];
        int x175 = x174 == '\0';
        if (x175) {
          x170 = 0/*false*/;
        } else {
          int x176 = x174 >= '0';
          int x178;
          if (x176) {
            int x177 = x174 <= '9';
            x178 = x177;
          } else {
            x178 = 0/*false*/;
          }
          if (x178) {
            char  *x179 = x173+1;
            x169 = x179;
          } else {
            x170 = 0/*false*/;
          }
        }
      }
      char  *x203 = x169;
      x20 = 0/*false*/;
      x22 = x203;
    }
  }
  int x211 = x20;
  if (x211) {
    char  *x212 = x22;
    x19 = x212;
  } else {
    char  *x216 = x22;
    char  *x217 = x216;
    int x218 = 1/*true*/;
    /*@
    loop invariant ((strlen(x217)>=0) &&
    \valid(x217+(0..strlen(x217))));
    loop assigns x217, x218;
    */
    for (;;) {
      int x219 = x218;
      if (!x219) break;
      char  *x221 = x217;
      char x222 = x221[0];
      int x223 = x222 == '\0';
      if (x223) {
        x218 = 0/*false*/;
      } else {
        int x224 = x222 == ' ';
        if (x224) {
          char  *x225 = x221+1;
          x217 = x225;
        } else {
          x218 = 0/*false*/;
        }
      }
    }
    char  *x249 = x217;
    x17 = 0/*false*/;
    x19 = x249;
  }
  int x255 = x17;
  if (x255) {
    char  *x256 = x19;
    x16 = x256;
  } else {
    char  *x260 = x19;
    int x267 = 1/*true*/;
    int x268 = 0;
    char  *x269 = 0/*null*/;
    int x270 = 1/*true*/;
    char x271 = '\0';
    char  *x272 = 0/*null*/;
    char x261 = x260[0];
    int x262 = x261 == '\0';
    if (x262) {
      x272 = x260;
    } else {
      int x263 = x261 >= '0';
      int x265;
      if (x263) {
        int x264 = x261 <= '9';
        x265 = x264;
      } else {
        x265 = 0/*false*/;
      }
      if (x265) {
        x270 = 0/*false*/;
        x271 = x261;
        char  *x266 = x260+1;
        x272 = x266;
      } else {
        x272 = x260;
      }
    }
    int x284 = x270;
    if (x284) {
      char  *x285 = x272;
      x269 = x285;
    } else {
      char x288 = x271;
      char  *x290 = x272;
      x267 = 0/*false*/;
      char x289 = x288 - '0';
      x268 = x289;
      x269 = x290;
    }
    int x296 = x267;
    if (x296) {
      char  *x297 = x269;
      x16 = x297;
    } else {
      int x300 = x268;
      char  *x301 = x269;
      char  *x302 = x301;
      int x303 = 1/*true*/;
      int x304 = x300;
      int x337 = INT_MAX;
      int x338 = x337 / 10;
      int x339 = x338 - 10;
      /*@
      loop invariant (((strlen(x302)>=0) &&
      \valid(x302+(0..strlen(x302)))) &&
      ((x304==-1) || (0<=x304)));
      loop assigns x302, x303, x304;
      */
      for (;;) {
        int x305 = x303;
        if (!x305) break;
        char  *x307 = x302;
        int x314 = 1/*true*/;
        char x315 = '\0';
        char  *x316 = 0/*null*/;
        char x308 = x307[0];
        int x309 = x308 == '\0';
        if (x309) {
          x316 = x307;
        } else {
          int x310 = x308 >= '0';
          int x312;
          if (x310) {
            int x311 = x308 <= '9';
            x312 = x311;
          } else {
            x312 = 0/*false*/;
          }
          if (x312) {
            x314 = 0/*false*/;
            x315 = x308;
            char  *x313 = x307+1;
            x316 = x313;
          } else {
            x316 = x307;
          }
        }
        int x328 = x314;
        if (x328) {
          char  *x329 = x316;
          x303 = 0/*false*/;
        } else {
          char x332 = x315;
          char  *x334 = x316;
          int x335 = x304;
          int x336 = x335 < 0;
          int x344;
          if (x336) {
            x344 = x335;
          } else {
            int x340 = x335 > x339;
            int x343;
            if (x340) {
              x343 = -1;
            } else {
              char x333 = x332 - '0';
              int x341 = x335 * 10;
              int x342 = x341 + x333;
              x343 = x342;
            }
            x344 = x343;
          }
          x304 = x344;
          x302 = x334;
        }
      }
      int x370 = x304;
      char  *x371 = x302;
      x14 = 0/*false*/;
      x15 = x370;
      x16 = x371;
    }
  }
  int x379 = x14;
  if (x379) {
    char  *x380 = x16;
    x13 = x380;
  } else {
    int x383 = x15;
    char  *x384 = x16;
    char  *x385 = x384;
    int x386 = 1/*true*/;
    /*@
    loop invariant ((strlen(x385)>=0) &&
    \valid(x385+(0..strlen(x385))));
    loop assigns x385, x386;
    */
    for (;;) {
      int x387 = x386;
      if (!x387) break;
      char  *x389 = x385;
      char x390 = x389[0];
      int x391 = x390 == '\0';
      if (x391) {
        x386 = 0/*false*/;
      } else {
        int x396 = x390 == '\r';
        if (x396) {
          x386 = 0/*false*/;
        } else {
          char  *x393 = x389+1;
          x385 = x393;
        }
      }
    }
    char  *x418 = x385;
    int x419 = 1/*true*/;
    char  *x421 = 0/*null*/;
    x419 = 0/*false*/;
    x421 = x418;
    int x425 = x419;
    if (x425) {
      char  *x426 = x421;
      x13 = x426;
    } else {
      char  *x430 = x421;
      char  *x431 = p_(x430);
      int x433 = 1/*true*/;
      char  *x435 = 0/*null*/;
      int x436 = 0 == x431;
      if (x436) {
        x435 = x430;
      } else {
        x433 = 0/*false*/;
        x435 = x431;
      }
      int x444 = x433;
      if (x444) {
        char  *x445 = x435;
        x13 = x445;
      } else {
        char  *x449 = x435;
        x11 = 0/*false*/;
        x12 = x383;
        x13 = x449;
      }
    }
  }
  int x459 = x11;
  if (x459) {
    char  *x460 = x13;
    x10 = x460;
  } else {
    int x463 = x12;
    char  *x464 = x13;
    char  *x465 = x464;
    int x466 = 1/*true*/;
    int x467 = 0;
    int x337 = INT_MAX;
    int x338 = x337 / 10;
    int x339 = x338 - 10;
    int x953 = -2 == -2;
    /*@
    loop invariant ((strlen(x465)>=0) &&
    \valid(x465+(0..strlen(x465))));
    loop assigns x465, x466, x467;
    */
    for (;;) {
      int x468 = x466;
      if (!x468) break;
      char  *x470 = x465;
      char  *x471 = p_ContentLength(x470);
      int x473 = 1/*true*/;
      int x474 = 0;
      char  *x475 = 0/*null*/;
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
      char  *x490 = 0/*null*/;
      int x491 = 0 == x471;
      if (x491) {
        x490 = x470;
      } else {
        x488 = 0/*false*/;
        x490 = x471;
      }
      int x499 = x488;
      if (x499) {
        char  *x500 = x490;
      } else {
        char  *x503 = x490;
        x485 = 0/*false*/;
        x486 = 1;
        x487 = x503;
      }
      int x509 = x485;
      if (x509) {
        char  *x510 = x470;
        int x511 = 1/*true*/;
        /*@
        loop invariant ((strlen(x510)>=0) &&
        \valid(x510+(0..strlen(x510))));
        loop assigns x510, x511;
        */
        for (;;) {
          int x512 = x511;
          if (!x512) break;
          char  *x514 = x510;
          char x515 = x514[0];
          int x516 = x515 == '\0';
          if (x516) {
            x511 = 0/*false*/;
          } else {
            int x518 = x515 == ':';
            int x520;
            if (x518) {
              x520 = 0/*false*/;
            } else {
              int x519 = x515 != ' ';
              x520 = x519;
            }
            if (x520) {
              char  *x521 = x514+1;
              x510 = x521;
            } else {
              x511 = 0/*false*/;
            }
          }
        }
        char  *x545 = x510;
        x482 = 0/*false*/;
        x483 = 0;
        x484 = x545;
      } else {
        int x550 = x486;
        char  *x551 = x487;
        x482 = 0/*false*/;
        x483 = x550;
        x484 = x551;
      }
      int x557 = x482;
      if (x557) {
        char  *x558 = x484;
        x481 = x558;
      } else {
        int x561 = x483;
        char  *x562 = x484;
        char  *x563 = x562;
        int x564 = 1/*true*/;
        /*@
        loop invariant ((strlen(x563)>=0) &&
        \valid(x563+(0..strlen(x563))));
        loop assigns x563, x564;
        */
        for (;;) {
          int x565 = x564;
          if (!x565) break;
          char  *x567 = x563;
          char x568 = x567[0];
          int x569 = x568 == '\0';
          if (x569) {
            x564 = 0/*false*/;
          } else {
            int x570 = x568 == ' ';
            if (x570) {
              char  *x571 = x567+1;
              x563 = x571;
            } else {
              x564 = 0/*false*/;
            }
          }
        }
        char  *x595 = x563;
        x479 = 0/*false*/;
        x480 = x561;
        x481 = x595;
      }
      int x601 = x479;
      if (x601) {
        char  *x602 = x481;
        x478 = x602;
      } else {
        int x605 = x480;
        char  *x606 = x481;
        int x611 = 1/*true*/;
        char x612 = '\0';
        char  *x613 = 0/*null*/;
        char x607 = x606[0];
        int x608 = x607 == '\0';
        if (x608) {
          x613 = x606;
        } else {
          int x609 = x607 == ':';
          if (x609) {
            x611 = 0/*false*/;
            x612 = x607;
            char  *x610 = x606+1;
            x613 = x610;
          } else {
            x613 = x606;
          }
        }
        int x625 = x611;
        if (x625) {
          char  *x626 = x613;
          x478 = x626;
        } else {
          char x629 = x612;
          char  *x630 = x613;
          x476 = 0/*false*/;
          x477 = x605;
          x478 = x630;
        }
      }
      int x638 = x476;
      if (x638) {
        char  *x639 = x478;
        x475 = x639;
      } else {
        int x642 = x477;
        char  *x643 = x478;
        char  *x644 = x643;
        int x645 = 1/*true*/;
        /*@
        loop invariant ((strlen(x644)>=0) &&
        \valid(x644+(0..strlen(x644))));
        loop assigns x644, x645;
        */
        for (;;) {
          int x646 = x645;
          if (!x646) break;
          char  *x648 = x644;
          char x649 = x648[0];
          int x650 = x649 == '\0';
          if (x650) {
            x645 = 0/*false*/;
          } else {
            int x651 = x649 == ' ';
            if (x651) {
              char  *x652 = x648+1;
              x644 = x652;
            } else {
              x645 = 0/*false*/;
            }
          }
        }
        char  *x676 = x644;
        x473 = 0/*false*/;
        x474 = x642;
        x475 = x676;
      }
      int x682 = x473;
      if (x682) {
        char  *x683 = x475;
        x466 = 0/*false*/;
      } else {
        int x686 = x474;
        char  *x687 = x475;
        char  *x695 = x687;
        int x696 = 1/*true*/;
        /*@
        loop invariant ((strlen(x695)>=0) &&
        \valid(x695+(0..strlen(x695))));
        loop assigns x695, x696;
        */
        for (;;) {
          int x697 = x696;
          if (!x697) break;
          char  *x699 = x695;
          char x700 = x699[0];
          int x701 = x700 == '\0';
          if (x701) {
            x696 = 0/*false*/;
          } else {
            int x706 = x700 == '\r';
            if (x706) {
              x696 = 0/*false*/;
            } else {
              char  *x703 = x699+1;
              x695 = x703;
            }
          }
        }
        char  *x728 = x695;
        int x688 = x686 == 1;
        if (x688) {
          int x729 = 1/*true*/;
          int x730 = 0;
          char  *x731 = 0/*null*/;
          int x732 = 1/*true*/;
          int x733 = 0;
          char  *x734 = 0/*null*/;
          int x735 = 1/*true*/;
          int x736 = 0;
          char  *x737 = 0/*null*/;
          int x738 = 1/*true*/;
          char x739 = '\0';
          char  *x740 = 0/*null*/;
          char x689 = x687[0];
          int x690 = x689 == '\0';
          if (x690) {
            x740 = x687;
          } else {
            int x691 = x689 >= '0';
            int x693;
            if (x691) {
              int x692 = x689 <= '9';
              x693 = x692;
            } else {
              x693 = 0/*false*/;
            }
            if (x693) {
              x738 = 0/*false*/;
              x739 = x689;
              char  *x694 = x687+1;
              x740 = x694;
            } else {
              x740 = x687;
            }
          }
          int x752 = x738;
          if (x752) {
            char  *x753 = x740;
            x737 = x753;
          } else {
            char x756 = x739;
            char  *x758 = x740;
            x735 = 0/*false*/;
            char x757 = x756 - '0';
            x736 = x757;
            x737 = x758;
          }
          int x764 = x735;
          if (x764) {
            char  *x765 = x737;
            x734 = x765;
          } else {
            int x768 = x736;
            char  *x769 = x737;
            char  *x770 = x769;
            int x771 = 1/*true*/;
            int x772 = x768;
            /*@
            loop invariant (((strlen(x770)>=0) &&
            \valid(x770+(0..strlen(x770)))) &&
            ((x772==-1) || (0<=x772)));
            loop assigns x770, x771, x772;
            */
            for (;;) {
              int x773 = x771;
              if (!x773) break;
              char  *x775 = x770;
              int x782 = 1/*true*/;
              char x783 = '\0';
              char  *x784 = 0/*null*/;
              char x776 = x775[0];
              int x777 = x776 == '\0';
              if (x777) {
                x784 = x775;
              } else {
                int x778 = x776 >= '0';
                int x780;
                if (x778) {
                  int x779 = x776 <= '9';
                  x780 = x779;
                } else {
                  x780 = 0/*false*/;
                }
                if (x780) {
                  x782 = 0/*false*/;
                  x783 = x776;
                  char  *x781 = x775+1;
                  x784 = x781;
                } else {
                  x784 = x775;
                }
              }
              int x796 = x782;
              if (x796) {
                char  *x797 = x784;
                x771 = 0/*false*/;
              } else {
                char x800 = x783;
                char  *x802 = x784;
                int x803 = x772;
                int x804 = x803 < 0;
                int x809;
                if (x804) {
                  x809 = x803;
                } else {
                  int x805 = x803 > x339;
                  int x808;
                  if (x805) {
                    x808 = -1;
                  } else {
                    char x801 = x800 - '0';
                    int x806 = x803 * 10;
                    int x807 = x806 + x801;
                    x808 = x807;
                  }
                  x809 = x808;
                }
                x772 = x809;
                x770 = x802;
              }
            }
            int x835 = x772;
            char  *x836 = x770;
            x732 = 0/*false*/;
            x733 = x835;
            x734 = x836;
          }
          int x842 = x732;
          if (x842) {
            char  *x843 = x734;
            x731 = x843;
          } else {
            int x846 = x733;
            char  *x847 = x734;
            char  *x848 = x847;
            int x849 = 1/*true*/;
            /*@
            loop invariant ((strlen(x848)>=0) &&
            \valid(x848+(0..strlen(x848))));
            loop assigns x848, x849;
            */
            for (;;) {
              int x850 = x849;
              if (!x850) break;
              char  *x852 = x848;
              char x853 = x852[0];
              int x854 = x853 == '\0';
              if (x854) {
                x849 = 0/*false*/;
              } else {
                int x855 = x853 == ' ';
                if (x855) {
                  char  *x856 = x852+1;
                  x848 = x856;
                } else {
                  x849 = 0/*false*/;
                }
              }
            }
            char  *x880 = x848;
            x729 = 0/*false*/;
            x730 = x846;
            x731 = x880;
          }
          int x886 = x729;
          if (x886) {
            char  *x887 = x731;
            x466 = 0/*false*/;
          } else {
            int x890 = x730;
            char  *x891 = x731;
            char  *x892 = p_(x891);
            int x894 = 1/*true*/;
            char  *x896 = 0/*null*/;
            int x897 = 0 == x892;
            if (x897) {
              x896 = x891;
            } else {
              x894 = 0/*false*/;
              x896 = x892;
            }
            int x905 = x894;
            if (x905) {
              char  *x906 = x896;
              x466 = 0/*false*/;
            } else {
              char  *x910 = x896;
              int x911 = x467;
              int x912 = x890 == -2;
              int x913;
              if (x912) {
                x913 = x911;
              } else {
                x913 = x890;
              }
              x467 = x913;
              x465 = x910;
            }
          }
        } else {
          int x921 = 1/*true*/;
          char  *x923 = 0/*null*/;
          x921 = 0/*false*/;
          x923 = x728;
          int x927 = x921;
          if (x927) {
            char  *x928 = x923;
            x466 = 0/*false*/;
          } else {
            char  *x932 = x923;
            char  *x933 = p_(x932);
            int x935 = 1/*true*/;
            char  *x937 = 0/*null*/;
            int x938 = 0 == x933;
            if (x938) {
              x937 = x932;
            } else {
              x935 = 0/*false*/;
              x937 = x933;
            }
            int x946 = x935;
            if (x946) {
              char  *x947 = x937;
              x466 = 0/*false*/;
            } else {
              char  *x951 = x937;
              int x952 = x467;
              int x954;
              if (x953) {
                x954 = x952;
              } else {
                x954 = -2;
              }
              x467 = x954;
              x465 = x951;
            }
          }
        }
      }
    }
    int x981 = x467;
    char  *x982 = x465;
    x8 = 0/*false*/;
    x9 = x981;
    x10 = x982;
  }
  int x988 = x8;
  if (x988) {
    char  *x989 = x10;
    x7 = x989;
  } else {
    int x992 = x9;
    char  *x993 = x10;
    char  *x994 = p_(x993);
    int x996 = 1/*true*/;
    char  *x998 = 0/*null*/;
    int x999 = 0 == x994;
    if (x999) {
      x998 = x993;
    } else {
      x996 = 0/*false*/;
      x998 = x994;
    }
    int x1007 = x996;
    if (x1007) {
      char  *x1008 = x998;
      x7 = x1008;
    } else {
      char  *x1012 = x998;
      x5 = 0/*false*/;
      x6 = x992;
      x7 = x1012;
    }
  }
  int x1020 = x5;
  if (x1020) {
    char  *x1021 = x7;
  } else {
    int x1023 = x6;
    char  *x1024 = x7;
    int x1026 = 1/*true*/;
    char  *x1027 = x1024;
    /*@
    loop invariant ((0<=x1029) &&
    ((strlen(x1027)>=0) &&
    \valid(x1027+(0..strlen(x1027)))));
    loop assigns x1029, x1026, x1027;
    loop variant (x6-x1029);
    */
    for(int x1029=0; x1029 < x1023; x1029++) {
      int x1030 = x1026;
      if (x1030) {
        char  *x1031 = x1027;
        char x1032 = x1031[0];
        int x1033 = x1032 == '\0';
        if (x1033) {
          x1026 = 0/*false*/;
        } else {
          char  *x1034 = x1031+1;
          x1027 = x1034;
        }
      } else {
      }
    }
    int x1060 = x1026;
    char  *x1061 = x1027;
    int x1025 = x1023 < 0;
    if (x1025) {
    } else {
      int x1062 = 1/*true*/;
      char  *x1064 = 0/*null*/;
      if (x1060) {
        x1062 = 0/*false*/;
        x1064 = x1061;
      } else {
        x1064 = x1024;
      }
      int x1072 = x1062;
      if (x1072) {
        char  *x1073 = x1064;
      } else {
        char  *x1076 = x1064;
        char x1077 = x1076[0];
        int x1078 = x1077 == '\0';
        if (x1078) {
          x2 = x1023;
        } else {
        }
      }
    }
  }
  int x1088 = x2;
  return x1088;
}
/*@
requires ((strlen(x1102)>=0) &&
\valid(x1102+(0..strlen(x1102))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..strlen(\result)))));
*/
char  * p_HTTP(char  * x1102) {
  char  *x1104 = x1102;
  int x1109 = 1/*true*/;
  char x1110 = '\0';
  char  *x1111 = 0/*null*/;
  char x1105 = x1102[0];
  int x1106 = x1105 == '\0';
  if (x1106) {
    x1111 = x1102;
  } else {
    int x1107 = x1105 == 'H';
    if (x1107) {
      x1109 = 0/*false*/;
      x1110 = x1105;
      char  *x1108 = x1102+1;
      x1111 = x1108;
    } else {
      x1111 = x1102;
    }
  }
  int x1123 = x1109;
  if (x1123) {
    char  *x1124 = x1111;
    x1104 = 0;
  } else {
    char x1127 = x1110;
    char  *x1128 = x1111;
    int x1133 = 1/*true*/;
    char x1134 = '\0';
    char  *x1135 = 0/*null*/;
    char x1129 = x1128[0];
    int x1130 = x1129 == '\0';
    if (x1130) {
      x1135 = x1128;
    } else {
      int x1131 = x1129 == 'T';
      if (x1131) {
        x1133 = 0/*false*/;
        x1134 = x1129;
        char  *x1132 = x1128+1;
        x1135 = x1132;
      } else {
        x1135 = x1128;
      }
    }
    int x1147 = x1133;
    if (x1147) {
      char  *x1148 = x1135;
      x1104 = 0;
    } else {
      char x1151 = x1134;
      char  *x1152 = x1135;
      int x1157 = 1/*true*/;
      char x1158 = '\0';
      char  *x1159 = 0/*null*/;
      char x1153 = x1152[0];
      int x1154 = x1153 == '\0';
      if (x1154) {
        x1159 = x1152;
      } else {
        int x1155 = x1153 == 'T';
        if (x1155) {
          x1157 = 0/*false*/;
          x1158 = x1153;
          char  *x1156 = x1152+1;
          x1159 = x1156;
        } else {
          x1159 = x1152;
        }
      }
      int x1171 = x1157;
      if (x1171) {
        char  *x1172 = x1159;
        x1104 = 0;
      } else {
        char x1175 = x1158;
        char  *x1176 = x1159;
        int x1181 = 1/*true*/;
        char x1182 = '\0';
        char  *x1183 = 0/*null*/;
        char x1177 = x1176[0];
        int x1178 = x1177 == '\0';
        if (x1178) {
          x1183 = x1176;
        } else {
          int x1179 = x1177 == 'P';
          if (x1179) {
            x1181 = 0/*false*/;
            x1182 = x1177;
            char  *x1180 = x1176+1;
            x1183 = x1180;
          } else {
            x1183 = x1176;
          }
        }
        int x1195 = x1181;
        if (x1195) {
          char  *x1196 = x1183;
          x1104 = 0;
        } else {
          char x1199 = x1182;
          char  *x1200 = x1183;
          int x1205 = 1/*true*/;
          char x1206 = '\0';
          char  *x1207 = 0/*null*/;
          char x1201 = x1200[0];
          int x1202 = x1201 == '\0';
          if (x1202) {
            x1207 = x1200;
          } else {
            int x1203 = x1201 == '/';
            if (x1203) {
              x1205 = 0/*false*/;
              x1206 = x1201;
              char  *x1204 = x1200+1;
              x1207 = x1204;
            } else {
              x1207 = x1200;
            }
          }
          int x1219 = x1205;
          if (x1219) {
            char  *x1220 = x1207;
            x1104 = 0;
          } else {
            char x1223 = x1206;
            char  *x1224 = x1207;
            x1104 = x1224;
          }
        }
      }
    }
  }
  char  *x1236 = x1104;
  return x1236;
}
/*@
requires ((strlen(x1252)>=0) &&
\valid(x1252+(0..strlen(x1252))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..strlen(\result)))));
*/
char  * p_(char  * x1252) {
  char  *x1254 = x1252;
  int x1259 = 1/*true*/;
  char x1260 = '\0';
  char  *x1261 = 0/*null*/;
  char x1255 = x1252[0];
  int x1256 = x1255 == '\0';
  if (x1256) {
    x1261 = x1252;
  } else {
    int x1257 = x1255 == '\r';
    if (x1257) {
      x1259 = 0/*false*/;
      x1260 = x1255;
      char  *x1258 = x1252+1;
      x1261 = x1258;
    } else {
      x1261 = x1252;
    }
  }
  int x1273 = x1259;
  if (x1273) {
    char  *x1274 = x1261;
    x1254 = 0;
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
      int x1281 = x1279 == '\n';
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
      x1254 = 0;
    } else {
      char x1301 = x1284;
      char  *x1302 = x1285;
      x1254 = x1302;
    }
  }
  char  *x1308 = x1254;
  return x1308;
}
/*@
requires ((strlen(x1324)>=0) &&
\valid(x1324+(0..strlen(x1324))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..strlen(\result)))));
*/
char  * p_ContentLength(char  * x1324) {
  char  *x1326 = x1324;
  int x1331 = 1/*true*/;
  char x1332 = '\0';
  char  *x1333 = 0/*null*/;
  char x1327 = x1324[0];
  int x1328 = x1327 == '\0';
  if (x1328) {
    x1333 = x1324;
  } else {
    int x1329 = x1327 == 'C';
    if (x1329) {
      x1331 = 0/*false*/;
      x1332 = x1327;
      char  *x1330 = x1324+1;
      x1333 = x1330;
    } else {
      x1333 = x1324;
    }
  }
  int x1345 = x1331;
  if (x1345) {
    char  *x1346 = x1333;
    x1326 = 0;
  } else {
    char x1349 = x1332;
    char  *x1350 = x1333;
    int x1355 = 1/*true*/;
    char x1356 = '\0';
    char  *x1357 = 0/*null*/;
    char x1351 = x1350[0];
    int x1352 = x1351 == '\0';
    if (x1352) {
      x1357 = x1350;
    } else {
      int x1353 = x1351 == 'o';
      if (x1353) {
        x1355 = 0/*false*/;
        x1356 = x1351;
        char  *x1354 = x1350+1;
        x1357 = x1354;
      } else {
        x1357 = x1350;
      }
    }
    int x1369 = x1355;
    if (x1369) {
      char  *x1370 = x1357;
      x1326 = 0;
    } else {
      char x1373 = x1356;
      char  *x1374 = x1357;
      int x1379 = 1/*true*/;
      char x1380 = '\0';
      char  *x1381 = 0/*null*/;
      char x1375 = x1374[0];
      int x1376 = x1375 == '\0';
      if (x1376) {
        x1381 = x1374;
      } else {
        int x1377 = x1375 == 'n';
        if (x1377) {
          x1379 = 0/*false*/;
          x1380 = x1375;
          char  *x1378 = x1374+1;
          x1381 = x1378;
        } else {
          x1381 = x1374;
        }
      }
      int x1393 = x1379;
      if (x1393) {
        char  *x1394 = x1381;
        x1326 = 0;
      } else {
        char x1397 = x1380;
        char  *x1398 = x1381;
        int x1403 = 1/*true*/;
        char x1404 = '\0';
        char  *x1405 = 0/*null*/;
        char x1399 = x1398[0];
        int x1400 = x1399 == '\0';
        if (x1400) {
          x1405 = x1398;
        } else {
          int x1401 = x1399 == 't';
          if (x1401) {
            x1403 = 0/*false*/;
            x1404 = x1399;
            char  *x1402 = x1398+1;
            x1405 = x1402;
          } else {
            x1405 = x1398;
          }
        }
        int x1417 = x1403;
        if (x1417) {
          char  *x1418 = x1405;
          x1326 = 0;
        } else {
          char x1421 = x1404;
          char  *x1422 = x1405;
          int x1427 = 1/*true*/;
          char x1428 = '\0';
          char  *x1429 = 0/*null*/;
          char x1423 = x1422[0];
          int x1424 = x1423 == '\0';
          if (x1424) {
            x1429 = x1422;
          } else {
            int x1425 = x1423 == 'e';
            if (x1425) {
              x1427 = 0/*false*/;
              x1428 = x1423;
              char  *x1426 = x1422+1;
              x1429 = x1426;
            } else {
              x1429 = x1422;
            }
          }
          int x1441 = x1427;
          if (x1441) {
            char  *x1442 = x1429;
            x1326 = 0;
          } else {
            char x1445 = x1428;
            char  *x1446 = x1429;
            int x1451 = 1/*true*/;
            char x1452 = '\0';
            char  *x1453 = 0/*null*/;
            char x1447 = x1446[0];
            int x1448 = x1447 == '\0';
            if (x1448) {
              x1453 = x1446;
            } else {
              int x1449 = x1447 == 'n';
              if (x1449) {
                x1451 = 0/*false*/;
                x1452 = x1447;
                char  *x1450 = x1446+1;
                x1453 = x1450;
              } else {
                x1453 = x1446;
              }
            }
            int x1465 = x1451;
            if (x1465) {
              char  *x1466 = x1453;
              x1326 = 0;
            } else {
              char x1469 = x1452;
              char  *x1470 = x1453;
              int x1475 = 1/*true*/;
              char x1476 = '\0';
              char  *x1477 = 0/*null*/;
              char x1471 = x1470[0];
              int x1472 = x1471 == '\0';
              if (x1472) {
                x1477 = x1470;
              } else {
                int x1473 = x1471 == 't';
                if (x1473) {
                  x1475 = 0/*false*/;
                  x1476 = x1471;
                  char  *x1474 = x1470+1;
                  x1477 = x1474;
                } else {
                  x1477 = x1470;
                }
              }
              int x1489 = x1475;
              if (x1489) {
                char  *x1490 = x1477;
                x1326 = 0;
              } else {
                char x1493 = x1476;
                char  *x1494 = x1477;
                int x1499 = 1/*true*/;
                char x1500 = '\0';
                char  *x1501 = 0/*null*/;
                char x1495 = x1494[0];
                int x1496 = x1495 == '\0';
                if (x1496) {
                  x1501 = x1494;
                } else {
                  int x1497 = x1495 == '-';
                  if (x1497) {
                    x1499 = 0/*false*/;
                    x1500 = x1495;
                    char  *x1498 = x1494+1;
                    x1501 = x1498;
                  } else {
                    x1501 = x1494;
                  }
                }
                int x1513 = x1499;
                if (x1513) {
                  char  *x1514 = x1501;
                  x1326 = 0;
                } else {
                  char x1517 = x1500;
                  char  *x1518 = x1501;
                  int x1523 = 1/*true*/;
                  char x1524 = '\0';
                  char  *x1525 = 0/*null*/;
                  char x1519 = x1518[0];
                  int x1520 = x1519 == '\0';
                  if (x1520) {
                    x1525 = x1518;
                  } else {
                    int x1521 = x1519 == 'L';
                    if (x1521) {
                      x1523 = 0/*false*/;
                      x1524 = x1519;
                      char  *x1522 = x1518+1;
                      x1525 = x1522;
                    } else {
                      x1525 = x1518;
                    }
                  }
                  int x1537 = x1523;
                  if (x1537) {
                    char  *x1538 = x1525;
                    x1326 = 0;
                  } else {
                    char x1541 = x1524;
                    char  *x1542 = x1525;
                    int x1547 = 1/*true*/;
                    char x1548 = '\0';
                    char  *x1549 = 0/*null*/;
                    char x1543 = x1542[0];
                    int x1544 = x1543 == '\0';
                    if (x1544) {
                      x1549 = x1542;
                    } else {
                      int x1545 = x1543 == 'e';
                      if (x1545) {
                        x1547 = 0/*false*/;
                        x1548 = x1543;
                        char  *x1546 = x1542+1;
                        x1549 = x1546;
                      } else {
                        x1549 = x1542;
                      }
                    }
                    int x1561 = x1547;
                    if (x1561) {
                      char  *x1562 = x1549;
                      x1326 = 0;
                    } else {
                      char x1565 = x1548;
                      char  *x1566 = x1549;
                      int x1571 = 1/*true*/;
                      char x1572 = '\0';
                      char  *x1573 = 0/*null*/;
                      char x1567 = x1566[0];
                      int x1568 = x1567 == '\0';
                      if (x1568) {
                        x1573 = x1566;
                      } else {
                        int x1569 = x1567 == 'n';
                        if (x1569) {
                          x1571 = 0/*false*/;
                          x1572 = x1567;
                          char  *x1570 = x1566+1;
                          x1573 = x1570;
                        } else {
                          x1573 = x1566;
                        }
                      }
                      int x1585 = x1571;
                      if (x1585) {
                        char  *x1586 = x1573;
                        x1326 = 0;
                      } else {
                        char x1589 = x1572;
                        char  *x1590 = x1573;
                        int x1595 = 1/*true*/;
                        char x1596 = '\0';
                        char  *x1597 = 0/*null*/;
                        char x1591 = x1590[0];
                        int x1592 = x1591 == '\0';
                        if (x1592) {
                          x1597 = x1590;
                        } else {
                          int x1593 = x1591 == 'g';
                          if (x1593) {
                            x1595 = 0/*false*/;
                            x1596 = x1591;
                            char  *x1594 = x1590+1;
                            x1597 = x1594;
                          } else {
                            x1597 = x1590;
                          }
                        }
                        int x1609 = x1595;
                        if (x1609) {
                          char  *x1610 = x1597;
                          x1326 = 0;
                        } else {
                          char x1613 = x1596;
                          char  *x1614 = x1597;
                          int x1619 = 1/*true*/;
                          char x1620 = '\0';
                          char  *x1621 = 0/*null*/;
                          char x1615 = x1614[0];
                          int x1616 = x1615 == '\0';
                          if (x1616) {
                            x1621 = x1614;
                          } else {
                            int x1617 = x1615 == 't';
                            if (x1617) {
                              x1619 = 0/*false*/;
                              x1620 = x1615;
                              char  *x1618 = x1614+1;
                              x1621 = x1618;
                            } else {
                              x1621 = x1614;
                            }
                          }
                          int x1633 = x1619;
                          if (x1633) {
                            char  *x1634 = x1621;
                            x1326 = 0;
                          } else {
                            char x1637 = x1620;
                            char  *x1638 = x1621;
                            int x1643 = 1/*true*/;
                            char x1644 = '\0';
                            char  *x1645 = 0/*null*/;
                            char x1639 = x1638[0];
                            int x1640 = x1639 == '\0';
                            if (x1640) {
                              x1645 = x1638;
                            } else {
                              int x1641 = x1639 == 'h';
                              if (x1641) {
                                x1643 = 0/*false*/;
                                x1644 = x1639;
                                char  *x1642 = x1638+1;
                                x1645 = x1642;
                              } else {
                                x1645 = x1638;
                              }
                            }
                            int x1657 = x1643;
                            if (x1657) {
                              char  *x1658 = x1645;
                              x1326 = 0;
                            } else {
                              char x1661 = x1644;
                              char  *x1662 = x1645;
                              x1326 = x1662;
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
  char  *x1692 = x1326;
  return x1692;
}
