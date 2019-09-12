#include <limits.h>
#include <string.h>
char  * p_chunked(char  * x1598);
char  * p_(char  * x1600);
char  * p_TransferEncoding(char  * x1602);
char  * p_ContentLength(char  * x1604);
char  * p_HTTP(char  * x1606);
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
    int x1098 = -2 == -2;
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
      int x489 = 0;
      char  *x490 = 0/*null*/;
      int x491 = 1/*true*/;
      char  *x493 = 0/*null*/;
      int x494 = 0 == x471;
      if (x494) {
        x493 = x470;
      } else {
        x491 = 0/*false*/;
        x493 = x471;
      }
      int x502 = x491;
      if (x502) {
        char  *x503 = x493;
      } else {
        char  *x506 = x493;
        x488 = 0/*false*/;
        x489 = 1;
        x490 = x506;
      }
      int x512 = x488;
      if (x512) {
        char  *x513 = p_TransferEncoding(x470);
        int x515 = 1/*true*/;
        char  *x517 = 0/*null*/;
        int x518 = 0 == x513;
        if (x518) {
          x517 = x470;
        } else {
          x515 = 0/*false*/;
          x517 = x513;
        }
        int x526 = x515;
        if (x526) {
          char  *x527 = x517;
        } else {
          char  *x530 = x517;
          x485 = 0/*false*/;
          x486 = 2;
          x487 = x530;
        }
      } else {
        int x537 = x489;
        char  *x538 = x490;
        x485 = 0/*false*/;
        x486 = x537;
        x487 = x538;
      }
      int x544 = x485;
      if (x544) {
        char  *x545 = x470;
        int x546 = 1/*true*/;
        /*@
        loop invariant ((strlen(x545)>=0) &&
        \valid(x545+(0..strlen(x545))));
        loop assigns x545, x546;
        */
        for (;;) {
          int x547 = x546;
          if (!x547) break;
          char  *x549 = x545;
          char x550 = x549[0];
          int x551 = x550 == '\0';
          if (x551) {
            x546 = 0/*false*/;
          } else {
            int x553 = x550 == ':';
            int x555;
            if (x553) {
              x555 = 0/*false*/;
            } else {
              int x554 = x550 != ' ';
              x555 = x554;
            }
            if (x555) {
              char  *x556 = x549+1;
              x545 = x556;
            } else {
              x546 = 0/*false*/;
            }
          }
        }
        char  *x580 = x545;
        x482 = 0/*false*/;
        x483 = 0;
        x484 = x580;
      } else {
        int x585 = x486;
        char  *x586 = x487;
        x482 = 0/*false*/;
        x483 = x585;
        x484 = x586;
      }
      int x592 = x482;
      if (x592) {
        char  *x593 = x484;
        x481 = x593;
      } else {
        int x596 = x483;
        char  *x597 = x484;
        char  *x598 = x597;
        int x599 = 1/*true*/;
        /*@
        loop invariant ((strlen(x598)>=0) &&
        \valid(x598+(0..strlen(x598))));
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
        char  *x630 = x598;
        x479 = 0/*false*/;
        x480 = x596;
        x481 = x630;
      }
      int x636 = x479;
      if (x636) {
        char  *x637 = x481;
        x478 = x637;
      } else {
        int x640 = x480;
        char  *x641 = x481;
        int x646 = 1/*true*/;
        char x647 = '\0';
        char  *x648 = 0/*null*/;
        char x642 = x641[0];
        int x643 = x642 == '\0';
        if (x643) {
          x648 = x641;
        } else {
          int x644 = x642 == ':';
          if (x644) {
            x646 = 0/*false*/;
            x647 = x642;
            char  *x645 = x641+1;
            x648 = x645;
          } else {
            x648 = x641;
          }
        }
        int x660 = x646;
        if (x660) {
          char  *x661 = x648;
          x478 = x661;
        } else {
          char x664 = x647;
          char  *x665 = x648;
          x476 = 0/*false*/;
          x477 = x640;
          x478 = x665;
        }
      }
      int x673 = x476;
      if (x673) {
        char  *x674 = x478;
        x475 = x674;
      } else {
        int x677 = x477;
        char  *x678 = x478;
        char  *x679 = x678;
        int x680 = 1/*true*/;
        /*@
        loop invariant ((strlen(x679)>=0) &&
        \valid(x679+(0..strlen(x679))));
        loop assigns x679, x680;
        */
        for (;;) {
          int x681 = x680;
          if (!x681) break;
          char  *x683 = x679;
          char x684 = x683[0];
          int x685 = x684 == '\0';
          if (x685) {
            x680 = 0/*false*/;
          } else {
            int x686 = x684 == ' ';
            if (x686) {
              char  *x687 = x683+1;
              x679 = x687;
            } else {
              x680 = 0/*false*/;
            }
          }
        }
        char  *x711 = x679;
        x473 = 0/*false*/;
        x474 = x677;
        x475 = x711;
      }
      int x717 = x473;
      if (x717) {
        char  *x718 = x475;
        x466 = 0/*false*/;
      } else {
        int x721 = x474;
        char  *x722 = x475;
        char  *x724 = p_chunked(x722);
        char  *x733 = x722;
        int x734 = 1/*true*/;
        /*@
        loop invariant ((strlen(x733)>=0) &&
        \valid(x733+(0..strlen(x733))));
        loop assigns x733, x734;
        */
        for (;;) {
          int x735 = x734;
          if (!x735) break;
          char  *x737 = x733;
          char x738 = x737[0];
          int x739 = x738 == '\0';
          if (x739) {
            x734 = 0/*false*/;
          } else {
            int x744 = x738 == '\r';
            if (x744) {
              x734 = 0/*false*/;
            } else {
              char  *x741 = x737+1;
              x733 = x741;
            }
          }
        }
        char  *x766 = x733;
        int x723 = x721 == 2;
        if (x723) {
          int x767 = 1/*true*/;
          int x768 = 0;
          char  *x769 = 0/*null*/;
          int x770 = 1/*true*/;
          int x771 = 0;
          char  *x772 = 0/*null*/;
          int x773 = 1/*true*/;
          char  *x775 = 0/*null*/;
          int x776 = 0 == x724;
          if (x776) {
            x775 = x722;
          } else {
            x773 = 0/*false*/;
            x775 = x724;
          }
          int x784 = x773;
          if (x784) {
            char  *x785 = x775;
            x772 = x785;
          } else {
            char  *x789 = x775;
            x770 = 0/*false*/;
            x771 = -3;
            x772 = x789;
          }
          int x795 = x770;
          if (x795) {
            char  *x796 = x772;
            x769 = x796;
          } else {
            int x799 = x771;
            char  *x800 = x772;
            char  *x801 = x800;
            int x802 = 1/*true*/;
            /*@
            loop invariant ((strlen(x801)>=0) &&
            \valid(x801+(0..strlen(x801))));
            loop assigns x801, x802;
            */
            for (;;) {
              int x803 = x802;
              if (!x803) break;
              char  *x805 = x801;
              char x806 = x805[0];
              int x807 = x806 == '\0';
              if (x807) {
                x802 = 0/*false*/;
              } else {
                int x808 = x806 == ' ';
                if (x808) {
                  char  *x809 = x805+1;
                  x801 = x809;
                } else {
                  x802 = 0/*false*/;
                }
              }
            }
            char  *x833 = x801;
            x767 = 0/*false*/;
            x768 = x799;
            x769 = x833;
          }
          int x839 = x767;
          if (x839) {
            char  *x840 = x769;
            x466 = 0/*false*/;
          } else {
            int x843 = x768;
            char  *x844 = x769;
            char  *x845 = p_(x844);
            int x847 = 1/*true*/;
            char  *x849 = 0/*null*/;
            int x850 = 0 == x845;
            if (x850) {
              x849 = x844;
            } else {
              x847 = 0/*false*/;
              x849 = x845;
            }
            int x858 = x847;
            if (x858) {
              char  *x859 = x849;
              x466 = 0/*false*/;
            } else {
              char  *x863 = x849;
              int x864 = x467;
              int x865 = x843 == -2;
              int x866;
              if (x865) {
                x866 = x864;
              } else {
                x866 = x843;
              }
              x467 = x866;
              x465 = x863;
            }
          }
        } else {
          int x726 = x721 == 1;
          if (x726) {
            int x874 = 1/*true*/;
            int x875 = 0;
            char  *x876 = 0/*null*/;
            int x877 = 1/*true*/;
            int x878 = 0;
            char  *x879 = 0/*null*/;
            int x880 = 1/*true*/;
            int x881 = 0;
            char  *x882 = 0/*null*/;
            int x883 = 1/*true*/;
            char x884 = '\0';
            char  *x885 = 0/*null*/;
            char x727 = x722[0];
            int x728 = x727 == '\0';
            if (x728) {
              x885 = x722;
            } else {
              int x729 = x727 >= '0';
              int x731;
              if (x729) {
                int x730 = x727 <= '9';
                x731 = x730;
              } else {
                x731 = 0/*false*/;
              }
              if (x731) {
                x883 = 0/*false*/;
                x884 = x727;
                char  *x732 = x722+1;
                x885 = x732;
              } else {
                x885 = x722;
              }
            }
            int x897 = x883;
            if (x897) {
              char  *x898 = x885;
              x882 = x898;
            } else {
              char x901 = x884;
              char  *x903 = x885;
              x880 = 0/*false*/;
              char x902 = x901 - '0';
              x881 = x902;
              x882 = x903;
            }
            int x909 = x880;
            if (x909) {
              char  *x910 = x882;
              x879 = x910;
            } else {
              int x913 = x881;
              char  *x914 = x882;
              char  *x915 = x914;
              int x916 = 1/*true*/;
              int x917 = x913;
              /*@
              loop invariant (((strlen(x915)>=0) &&
              \valid(x915+(0..strlen(x915)))) &&
              ((x917==-1) || (0<=x917)));
              loop assigns x915, x916, x917;
              */
              for (;;) {
                int x918 = x916;
                if (!x918) break;
                char  *x920 = x915;
                int x927 = 1/*true*/;
                char x928 = '\0';
                char  *x929 = 0/*null*/;
                char x921 = x920[0];
                int x922 = x921 == '\0';
                if (x922) {
                  x929 = x920;
                } else {
                  int x923 = x921 >= '0';
                  int x925;
                  if (x923) {
                    int x924 = x921 <= '9';
                    x925 = x924;
                  } else {
                    x925 = 0/*false*/;
                  }
                  if (x925) {
                    x927 = 0/*false*/;
                    x928 = x921;
                    char  *x926 = x920+1;
                    x929 = x926;
                  } else {
                    x929 = x920;
                  }
                }
                int x941 = x927;
                if (x941) {
                  char  *x942 = x929;
                  x916 = 0/*false*/;
                } else {
                  char x945 = x928;
                  char  *x947 = x929;
                  int x948 = x917;
                  int x949 = x948 < 0;
                  int x954;
                  if (x949) {
                    x954 = x948;
                  } else {
                    int x950 = x948 > x339;
                    int x953;
                    if (x950) {
                      x953 = -1;
                    } else {
                      char x946 = x945 - '0';
                      int x951 = x948 * 10;
                      int x952 = x951 + x946;
                      x953 = x952;
                    }
                    x954 = x953;
                  }
                  x917 = x954;
                  x915 = x947;
                }
              }
              int x980 = x917;
              char  *x981 = x915;
              x877 = 0/*false*/;
              x878 = x980;
              x879 = x981;
            }
            int x987 = x877;
            if (x987) {
              char  *x988 = x879;
              x876 = x988;
            } else {
              int x991 = x878;
              char  *x992 = x879;
              char  *x993 = x992;
              int x994 = 1/*true*/;
              /*@
              loop invariant ((strlen(x993)>=0) &&
              \valid(x993+(0..strlen(x993))));
              loop assigns x993, x994;
              */
              for (;;) {
                int x995 = x994;
                if (!x995) break;
                char  *x997 = x993;
                char x998 = x997[0];
                int x999 = x998 == '\0';
                if (x999) {
                  x994 = 0/*false*/;
                } else {
                  int x1000 = x998 == ' ';
                  if (x1000) {
                    char  *x1001 = x997+1;
                    x993 = x1001;
                  } else {
                    x994 = 0/*false*/;
                  }
                }
              }
              char  *x1025 = x993;
              x874 = 0/*false*/;
              x875 = x991;
              x876 = x1025;
            }
            int x1031 = x874;
            if (x1031) {
              char  *x1032 = x876;
              x466 = 0/*false*/;
            } else {
              int x1035 = x875;
              char  *x1036 = x876;
              char  *x1037 = p_(x1036);
              int x1039 = 1/*true*/;
              char  *x1041 = 0/*null*/;
              int x1042 = 0 == x1037;
              if (x1042) {
                x1041 = x1036;
              } else {
                x1039 = 0/*false*/;
                x1041 = x1037;
              }
              int x1050 = x1039;
              if (x1050) {
                char  *x1051 = x1041;
                x466 = 0/*false*/;
              } else {
                char  *x1055 = x1041;
                int x1056 = x467;
                int x1057 = x1035 == -2;
                int x1058;
                if (x1057) {
                  x1058 = x1056;
                } else {
                  x1058 = x1035;
                }
                x467 = x1058;
                x465 = x1055;
              }
            }
          } else {
            int x1066 = 1/*true*/;
            char  *x1068 = 0/*null*/;
            x1066 = 0/*false*/;
            x1068 = x766;
            int x1072 = x1066;
            if (x1072) {
              char  *x1073 = x1068;
              x466 = 0/*false*/;
            } else {
              char  *x1077 = x1068;
              char  *x1078 = p_(x1077);
              int x1080 = 1/*true*/;
              char  *x1082 = 0/*null*/;
              int x1083 = 0 == x1078;
              if (x1083) {
                x1082 = x1077;
              } else {
                x1080 = 0/*false*/;
                x1082 = x1078;
              }
              int x1091 = x1080;
              if (x1091) {
                char  *x1092 = x1082;
                x466 = 0/*false*/;
              } else {
                char  *x1096 = x1082;
                int x1097 = x467;
                int x1099;
                if (x1098) {
                  x1099 = x1097;
                } else {
                  x1099 = -2;
                }
                x467 = x1099;
                x465 = x1096;
              }
            }
          }
        }
      }
    }
    int x1128 = x467;
    char  *x1129 = x465;
    x8 = 0/*false*/;
    x9 = x1128;
    x10 = x1129;
  }
  int x1135 = x8;
  if (x1135) {
    char  *x1136 = x10;
    x7 = x1136;
  } else {
    int x1139 = x9;
    char  *x1140 = x10;
    char  *x1141 = p_(x1140);
    int x1143 = 1/*true*/;
    char  *x1145 = 0/*null*/;
    int x1146 = 0 == x1141;
    if (x1146) {
      x1145 = x1140;
    } else {
      x1143 = 0/*false*/;
      x1145 = x1141;
    }
    int x1154 = x1143;
    if (x1154) {
      char  *x1155 = x1145;
      x7 = x1155;
    } else {
      char  *x1159 = x1145;
      x5 = 0/*false*/;
      x6 = x1139;
      x7 = x1159;
    }
  }
  int x1167 = x5;
  if (x1167) {
    char  *x1168 = x7;
  } else {
    int x1170 = x6;
    char  *x1171 = x7;
    char  *x1173 = x1171;
    int x1174 = 1/*true*/;
    int x1175 = 0;
    int x337 = INT_MAX;
    int x1335 = x337 / 16;
    int x1336 = x1335 - 16;
    /*@
    loop invariant (((strlen(x1173)>=0) &&
    \valid(x1173+(0..strlen(x1173)))) &&
    ((x1175==-1) || (0<=x1175)));
    loop assigns x1173, x1174, x1175;
    */
    for (;;) {
      int x1176 = x1174;
      if (!x1176) break;
      char  *x1178 = x1173;
      int x1185 = 1/*true*/;
      int x1186 = 0;
      char  *x1187 = 0/*null*/;
      int x1188 = 1/*true*/;
      int x1189 = 0;
      char  *x1190 = 0/*null*/;
      int x1191 = 1/*true*/;
      int x1192 = 0;
      char  *x1193 = 0/*null*/;
      int x1194 = 1/*true*/;
      int x1195 = 0;
      char  *x1196 = 0/*null*/;
      int x1197 = 1/*true*/;
      char x1198 = '\0';
      char  *x1199 = 0/*null*/;
      char x1179 = x1178[0];
      int x1180 = x1179 == '\0';
      if (x1180) {
        x1199 = x1178;
      } else {
        int x1181 = x1179 >= '0';
        int x1183;
        if (x1181) {
          int x1182 = x1179 <= '9';
          x1183 = x1182;
        } else {
          x1183 = 0/*false*/;
        }
        if (x1183) {
          x1197 = 0/*false*/;
          x1198 = x1179;
          char  *x1184 = x1178+1;
          x1199 = x1184;
        } else {
          x1199 = x1178;
        }
      }
      int x1211 = x1197;
      if (x1211) {
        char  *x1212 = x1199;
      } else {
        char x1214 = x1198;
        char  *x1216 = x1199;
        x1194 = 0/*false*/;
        char x1215 = x1214 - '0';
        x1195 = x1215;
        x1196 = x1216;
      }
      int x1222 = x1194;
      if (x1222) {
        int x1226 = 1/*true*/;
        char x1227 = '\0';
        char  *x1228 = 0/*null*/;
        if (x1180) {
          x1228 = x1178;
        } else {
          int x1223 = x1179 >= 'a';
          int x1225;
          if (x1223) {
            int x1224 = x1179 <= 'f';
            x1225 = x1224;
          } else {
            x1225 = 0/*false*/;
          }
          if (x1225) {
            x1226 = 0/*false*/;
            x1227 = x1179;
            char  *x1184 = x1178+1;
            x1228 = x1184;
          } else {
            x1228 = x1178;
          }
        }
        int x1240 = x1226;
        if (x1240) {
          char  *x1241 = x1228;
          x1193 = x1241;
        } else {
          char x1244 = x1227;
          char  *x1247 = x1228;
          x1191 = 0/*false*/;
          char x1245 = x1244 - 'a';
          int x1246 = 10 + x1245;
          x1192 = x1246;
          x1193 = x1247;
        }
      } else {
        int x1254 = x1195;
        char  *x1255 = x1196;
        x1191 = 0/*false*/;
        x1192 = x1254;
        x1193 = x1255;
      }
      int x1261 = x1191;
      if (x1261) {
        char  *x1262 = x1193;
        x1190 = x1262;
      } else {
        int x1265 = x1192;
        char  *x1266 = x1193;
        char  *x1267 = x1266;
        int x1268 = 1/*true*/;
        int x1269 = x1265;
        /*@
        loop invariant (((strlen(x1267)>=0) &&
        \valid(x1267+(0..strlen(x1267)))) &&
        ((x1269==-1) || (0<=x1269)));
        loop assigns x1267, x1268, x1269;
        */
        for (;;) {
          int x1270 = x1268;
          if (!x1270) break;
          char  *x1272 = x1267;
          int x1279 = 1/*true*/;
          int x1280 = 0;
          char  *x1281 = 0/*null*/;
          int x1282 = 1/*true*/;
          char x1283 = '\0';
          char  *x1284 = 0/*null*/;
          char x1273 = x1272[0];
          int x1274 = x1273 == '\0';
          if (x1274) {
            x1284 = x1272;
          } else {
            int x1275 = x1273 >= '0';
            int x1277;
            if (x1275) {
              int x1276 = x1273 <= '9';
              x1277 = x1276;
            } else {
              x1277 = 0/*false*/;
            }
            if (x1277) {
              x1282 = 0/*false*/;
              x1283 = x1273;
              char  *x1278 = x1272+1;
              x1284 = x1278;
            } else {
              x1284 = x1272;
            }
          }
          int x1296 = x1282;
          if (x1296) {
            char  *x1297 = x1284;
          } else {
            char x1299 = x1283;
            char  *x1301 = x1284;
            x1279 = 0/*false*/;
            char x1300 = x1299 - '0';
            x1280 = x1300;
            x1281 = x1301;
          }
          int x1307 = x1279;
          if (x1307) {
            int x1311 = 1/*true*/;
            char x1312 = '\0';
            char  *x1313 = 0/*null*/;
            if (x1274) {
              x1313 = x1272;
            } else {
              int x1308 = x1273 >= 'a';
              int x1310;
              if (x1308) {
                int x1309 = x1273 <= 'f';
                x1310 = x1309;
              } else {
                x1310 = 0/*false*/;
              }
              if (x1310) {
                x1311 = 0/*false*/;
                x1312 = x1273;
                char  *x1278 = x1272+1;
                x1313 = x1278;
              } else {
                x1313 = x1272;
              }
            }
            int x1325 = x1311;
            if (x1325) {
              char  *x1326 = x1313;
              x1268 = 0/*false*/;
            } else {
              char x1329 = x1312;
              char  *x1332 = x1313;
              int x1333 = x1269;
              int x1334 = x1333 < 0;
              int x1341;
              if (x1334) {
                x1341 = x1333;
              } else {
                int x1337 = x1333 > x1336;
                int x1340;
                if (x1337) {
                  x1340 = -1;
                } else {
                  char x1330 = x1329 - 'a';
                  int x1331 = 10 + x1330;
                  int x1338 = x1333 * 16;
                  int x1339 = x1338 + x1331;
                  x1340 = x1339;
                }
                x1341 = x1340;
              }
              x1269 = x1341;
              x1267 = x1332;
            }
          } else {
            int x1347 = x1280;
            char  *x1348 = x1281;
            int x1349 = x1269;
            int x1350 = x1349 < 0;
            int x1355;
            if (x1350) {
              x1355 = x1349;
            } else {
              int x1351 = x1349 > x1336;
              int x1354;
              if (x1351) {
                x1354 = -1;
              } else {
                int x1352 = x1349 * 16;
                int x1353 = x1352 + x1347;
                x1354 = x1353;
              }
              x1355 = x1354;
            }
            x1269 = x1355;
            x1267 = x1348;
          }
        }
        int x1381 = x1269;
        char  *x1382 = x1267;
        x1188 = 0/*false*/;
        x1189 = x1381;
        x1190 = x1382;
      }
      int x1388 = x1188;
      if (x1388) {
        char  *x1389 = x1190;
        x1187 = x1389;
      } else {
        int x1392 = x1189;
        char  *x1393 = x1190;
        char  *x1394 = p_(x1393);
        int x1396 = 1/*true*/;
        char  *x1398 = 0/*null*/;
        int x1399 = 0 == x1394;
        if (x1399) {
          x1398 = x1393;
        } else {
          x1396 = 0/*false*/;
          x1398 = x1394;
        }
        int x1407 = x1396;
        if (x1407) {
          char  *x1408 = x1398;
          x1187 = x1408;
        } else {
          char  *x1412 = x1398;
          x1185 = 0/*false*/;
          x1186 = x1392;
          x1187 = x1412;
        }
      }
      int x1420 = x1185;
      if (x1420) {
        char  *x1421 = x1187;
        x1174 = 0/*false*/;
      } else {
        int x1424 = x1186;
        char  *x1425 = x1187;
        int x1427 = 1/*true*/;
        char  *x1428 = x1425;
        /*@
        loop invariant ((0<=x1430) &&
        ((strlen(x1428)>=0) &&
        \valid(x1428+(0..strlen(x1428)))));
        loop assigns x1430, x1427, x1428;
        loop variant (x1186-x1430);
        */
        for(int x1430=0; x1430 < x1424; x1430++) {
          int x1431 = x1427;
          if (x1431) {
            char  *x1432 = x1428;
            char x1433 = x1432[0];
            int x1434 = x1433 == '\0';
            if (x1434) {
              x1427 = 0/*false*/;
            } else {
              char  *x1435 = x1432+1;
              x1428 = x1435;
            }
          } else {
          }
        }
        int x1461 = x1427;
        char  *x1462 = x1428;
        int x1426 = x1424 < 0;
        if (x1426) {
          x1174 = 0/*false*/;
        } else {
          int x1465 = 1/*true*/;
          char  *x1467 = 0/*null*/;
          if (x1461) {
            x1465 = 0/*false*/;
            x1467 = x1462;
          } else {
            x1467 = x1425;
          }
          int x1475 = x1465;
          if (x1475) {
            char  *x1476 = x1467;
            x1174 = 0/*false*/;
          } else {
            char  *x1480 = x1467;
            int x1481 = x1175;
            int x1482 = x1481 < 0;
            int x1487;
            if (x1482) {
              x1487 = x1481;
            } else {
              int x1483 = x337 - x1424;
              int x1484 = x1481 > x1483;
              int x1486;
              if (x1484) {
                x1486 = -1;
              } else {
                int x1485 = x1481 + x1424;
                x1486 = x1485;
              }
              x1487 = x1486;
            }
            x1175 = x1487;
            x1173 = x1480;
          }
        }
      }
    }
    int x1517 = x1175;
    char  *x1518 = x1173;
    int x1520 = 1/*true*/;
    char  *x1521 = x1171;
    /*@
    loop invariant ((0<=x1523) &&
    ((strlen(x1521)>=0) &&
    \valid(x1521+(0..strlen(x1521)))));
    loop assigns x1523, x1520, x1521;
    loop variant (x6-x1523);
    */
    for(int x1523=0; x1523 < x1170; x1523++) {
      int x1524 = x1520;
      if (x1524) {
        char  *x1525 = x1521;
        char x1526 = x1525[0];
        int x1527 = x1526 == '\0';
        if (x1527) {
          x1520 = 0/*false*/;
        } else {
          char  *x1528 = x1525+1;
          x1521 = x1528;
        }
      } else {
      }
    }
    int x1554 = x1520;
    char  *x1555 = x1521;
    int x1172 = x1170 == -3;
    if (x1172) {
      char x1556 = x1518[0];
      int x1557 = x1556 == '\0';
      if (x1557) {
        x2 = x1517;
      } else {
      }
    } else {
      int x1519 = x1170 < 0;
      if (x1519) {
      } else {
        int x1562 = 1/*true*/;
        char  *x1564 = 0/*null*/;
        if (x1554) {
          x1562 = 0/*false*/;
          x1564 = x1555;
        } else {
          x1564 = x1171;
        }
        int x1572 = x1562;
        if (x1572) {
          char  *x1573 = x1564;
        } else {
          char  *x1576 = x1564;
          char x1577 = x1576[0];
          int x1578 = x1577 == '\0';
          if (x1578) {
            x2 = x1170;
          } else {
          }
        }
      }
    }
  }
  int x1590 = x2;
  return x1590;
}
/*@
requires ((strlen(x1608)>=0) &&
\valid(x1608+(0..strlen(x1608))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..strlen(\result)))));
*/
char  * p_HTTP(char  * x1608) {
  char  *x1610 = x1608;
  int x1615 = 1/*true*/;
  char x1616 = '\0';
  char  *x1617 = 0/*null*/;
  char x1611 = x1608[0];
  int x1612 = x1611 == '\0';
  if (x1612) {
    x1617 = x1608;
  } else {
    int x1613 = x1611 == 'H';
    if (x1613) {
      x1615 = 0/*false*/;
      x1616 = x1611;
      char  *x1614 = x1608+1;
      x1617 = x1614;
    } else {
      x1617 = x1608;
    }
  }
  int x1629 = x1615;
  if (x1629) {
    char  *x1630 = x1617;
    x1610 = 0;
  } else {
    char x1633 = x1616;
    char  *x1634 = x1617;
    int x1639 = 1/*true*/;
    char x1640 = '\0';
    char  *x1641 = 0/*null*/;
    char x1635 = x1634[0];
    int x1636 = x1635 == '\0';
    if (x1636) {
      x1641 = x1634;
    } else {
      int x1637 = x1635 == 'T';
      if (x1637) {
        x1639 = 0/*false*/;
        x1640 = x1635;
        char  *x1638 = x1634+1;
        x1641 = x1638;
      } else {
        x1641 = x1634;
      }
    }
    int x1653 = x1639;
    if (x1653) {
      char  *x1654 = x1641;
      x1610 = 0;
    } else {
      char x1657 = x1640;
      char  *x1658 = x1641;
      int x1663 = 1/*true*/;
      char x1664 = '\0';
      char  *x1665 = 0/*null*/;
      char x1659 = x1658[0];
      int x1660 = x1659 == '\0';
      if (x1660) {
        x1665 = x1658;
      } else {
        int x1661 = x1659 == 'T';
        if (x1661) {
          x1663 = 0/*false*/;
          x1664 = x1659;
          char  *x1662 = x1658+1;
          x1665 = x1662;
        } else {
          x1665 = x1658;
        }
      }
      int x1677 = x1663;
      if (x1677) {
        char  *x1678 = x1665;
        x1610 = 0;
      } else {
        char x1681 = x1664;
        char  *x1682 = x1665;
        int x1687 = 1/*true*/;
        char x1688 = '\0';
        char  *x1689 = 0/*null*/;
        char x1683 = x1682[0];
        int x1684 = x1683 == '\0';
        if (x1684) {
          x1689 = x1682;
        } else {
          int x1685 = x1683 == 'P';
          if (x1685) {
            x1687 = 0/*false*/;
            x1688 = x1683;
            char  *x1686 = x1682+1;
            x1689 = x1686;
          } else {
            x1689 = x1682;
          }
        }
        int x1701 = x1687;
        if (x1701) {
          char  *x1702 = x1689;
          x1610 = 0;
        } else {
          char x1705 = x1688;
          char  *x1706 = x1689;
          int x1711 = 1/*true*/;
          char x1712 = '\0';
          char  *x1713 = 0/*null*/;
          char x1707 = x1706[0];
          int x1708 = x1707 == '\0';
          if (x1708) {
            x1713 = x1706;
          } else {
            int x1709 = x1707 == '/';
            if (x1709) {
              x1711 = 0/*false*/;
              x1712 = x1707;
              char  *x1710 = x1706+1;
              x1713 = x1710;
            } else {
              x1713 = x1706;
            }
          }
          int x1725 = x1711;
          if (x1725) {
            char  *x1726 = x1713;
            x1610 = 0;
          } else {
            char x1729 = x1712;
            char  *x1730 = x1713;
            x1610 = x1730;
          }
        }
      }
    }
  }
  char  *x1742 = x1610;
  return x1742;
}
/*@
requires ((strlen(x1758)>=0) &&
\valid(x1758+(0..strlen(x1758))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..strlen(\result)))));
*/
char  * p_(char  * x1758) {
  char  *x1760 = x1758;
  int x1765 = 1/*true*/;
  char x1766 = '\0';
  char  *x1767 = 0/*null*/;
  char x1761 = x1758[0];
  int x1762 = x1761 == '\0';
  if (x1762) {
    x1767 = x1758;
  } else {
    int x1763 = x1761 == '\r';
    if (x1763) {
      x1765 = 0/*false*/;
      x1766 = x1761;
      char  *x1764 = x1758+1;
      x1767 = x1764;
    } else {
      x1767 = x1758;
    }
  }
  int x1779 = x1765;
  if (x1779) {
    char  *x1780 = x1767;
    x1760 = 0;
  } else {
    char x1783 = x1766;
    char  *x1784 = x1767;
    int x1789 = 1/*true*/;
    char x1790 = '\0';
    char  *x1791 = 0/*null*/;
    char x1785 = x1784[0];
    int x1786 = x1785 == '\0';
    if (x1786) {
      x1791 = x1784;
    } else {
      int x1787 = x1785 == '\n';
      if (x1787) {
        x1789 = 0/*false*/;
        x1790 = x1785;
        char  *x1788 = x1784+1;
        x1791 = x1788;
      } else {
        x1791 = x1784;
      }
    }
    int x1803 = x1789;
    if (x1803) {
      char  *x1804 = x1791;
      x1760 = 0;
    } else {
      char x1807 = x1790;
      char  *x1808 = x1791;
      x1760 = x1808;
    }
  }
  char  *x1814 = x1760;
  return x1814;
}
/*@
requires ((strlen(x1830)>=0) &&
\valid(x1830+(0..strlen(x1830))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..strlen(\result)))));
*/
char  * p_ContentLength(char  * x1830) {
  char  *x1832 = x1830;
  int x1837 = 1/*true*/;
  char x1838 = '\0';
  char  *x1839 = 0/*null*/;
  char x1833 = x1830[0];
  int x1834 = x1833 == '\0';
  if (x1834) {
    x1839 = x1830;
  } else {
    int x1835 = x1833 == 'C';
    if (x1835) {
      x1837 = 0/*false*/;
      x1838 = x1833;
      char  *x1836 = x1830+1;
      x1839 = x1836;
    } else {
      x1839 = x1830;
    }
  }
  int x1851 = x1837;
  if (x1851) {
    char  *x1852 = x1839;
    x1832 = 0;
  } else {
    char x1855 = x1838;
    char  *x1856 = x1839;
    int x1861 = 1/*true*/;
    char x1862 = '\0';
    char  *x1863 = 0/*null*/;
    char x1857 = x1856[0];
    int x1858 = x1857 == '\0';
    if (x1858) {
      x1863 = x1856;
    } else {
      int x1859 = x1857 == 'o';
      if (x1859) {
        x1861 = 0/*false*/;
        x1862 = x1857;
        char  *x1860 = x1856+1;
        x1863 = x1860;
      } else {
        x1863 = x1856;
      }
    }
    int x1875 = x1861;
    if (x1875) {
      char  *x1876 = x1863;
      x1832 = 0;
    } else {
      char x1879 = x1862;
      char  *x1880 = x1863;
      int x1885 = 1/*true*/;
      char x1886 = '\0';
      char  *x1887 = 0/*null*/;
      char x1881 = x1880[0];
      int x1882 = x1881 == '\0';
      if (x1882) {
        x1887 = x1880;
      } else {
        int x1883 = x1881 == 'n';
        if (x1883) {
          x1885 = 0/*false*/;
          x1886 = x1881;
          char  *x1884 = x1880+1;
          x1887 = x1884;
        } else {
          x1887 = x1880;
        }
      }
      int x1899 = x1885;
      if (x1899) {
        char  *x1900 = x1887;
        x1832 = 0;
      } else {
        char x1903 = x1886;
        char  *x1904 = x1887;
        int x1909 = 1/*true*/;
        char x1910 = '\0';
        char  *x1911 = 0/*null*/;
        char x1905 = x1904[0];
        int x1906 = x1905 == '\0';
        if (x1906) {
          x1911 = x1904;
        } else {
          int x1907 = x1905 == 't';
          if (x1907) {
            x1909 = 0/*false*/;
            x1910 = x1905;
            char  *x1908 = x1904+1;
            x1911 = x1908;
          } else {
            x1911 = x1904;
          }
        }
        int x1923 = x1909;
        if (x1923) {
          char  *x1924 = x1911;
          x1832 = 0;
        } else {
          char x1927 = x1910;
          char  *x1928 = x1911;
          int x1933 = 1/*true*/;
          char x1934 = '\0';
          char  *x1935 = 0/*null*/;
          char x1929 = x1928[0];
          int x1930 = x1929 == '\0';
          if (x1930) {
            x1935 = x1928;
          } else {
            int x1931 = x1929 == 'e';
            if (x1931) {
              x1933 = 0/*false*/;
              x1934 = x1929;
              char  *x1932 = x1928+1;
              x1935 = x1932;
            } else {
              x1935 = x1928;
            }
          }
          int x1947 = x1933;
          if (x1947) {
            char  *x1948 = x1935;
            x1832 = 0;
          } else {
            char x1951 = x1934;
            char  *x1952 = x1935;
            int x1957 = 1/*true*/;
            char x1958 = '\0';
            char  *x1959 = 0/*null*/;
            char x1953 = x1952[0];
            int x1954 = x1953 == '\0';
            if (x1954) {
              x1959 = x1952;
            } else {
              int x1955 = x1953 == 'n';
              if (x1955) {
                x1957 = 0/*false*/;
                x1958 = x1953;
                char  *x1956 = x1952+1;
                x1959 = x1956;
              } else {
                x1959 = x1952;
              }
            }
            int x1971 = x1957;
            if (x1971) {
              char  *x1972 = x1959;
              x1832 = 0;
            } else {
              char x1975 = x1958;
              char  *x1976 = x1959;
              int x1981 = 1/*true*/;
              char x1982 = '\0';
              char  *x1983 = 0/*null*/;
              char x1977 = x1976[0];
              int x1978 = x1977 == '\0';
              if (x1978) {
                x1983 = x1976;
              } else {
                int x1979 = x1977 == 't';
                if (x1979) {
                  x1981 = 0/*false*/;
                  x1982 = x1977;
                  char  *x1980 = x1976+1;
                  x1983 = x1980;
                } else {
                  x1983 = x1976;
                }
              }
              int x1995 = x1981;
              if (x1995) {
                char  *x1996 = x1983;
                x1832 = 0;
              } else {
                char x1999 = x1982;
                char  *x2000 = x1983;
                int x2005 = 1/*true*/;
                char x2006 = '\0';
                char  *x2007 = 0/*null*/;
                char x2001 = x2000[0];
                int x2002 = x2001 == '\0';
                if (x2002) {
                  x2007 = x2000;
                } else {
                  int x2003 = x2001 == '-';
                  if (x2003) {
                    x2005 = 0/*false*/;
                    x2006 = x2001;
                    char  *x2004 = x2000+1;
                    x2007 = x2004;
                  } else {
                    x2007 = x2000;
                  }
                }
                int x2019 = x2005;
                if (x2019) {
                  char  *x2020 = x2007;
                  x1832 = 0;
                } else {
                  char x2023 = x2006;
                  char  *x2024 = x2007;
                  int x2029 = 1/*true*/;
                  char x2030 = '\0';
                  char  *x2031 = 0/*null*/;
                  char x2025 = x2024[0];
                  int x2026 = x2025 == '\0';
                  if (x2026) {
                    x2031 = x2024;
                  } else {
                    int x2027 = x2025 == 'L';
                    if (x2027) {
                      x2029 = 0/*false*/;
                      x2030 = x2025;
                      char  *x2028 = x2024+1;
                      x2031 = x2028;
                    } else {
                      x2031 = x2024;
                    }
                  }
                  int x2043 = x2029;
                  if (x2043) {
                    char  *x2044 = x2031;
                    x1832 = 0;
                  } else {
                    char x2047 = x2030;
                    char  *x2048 = x2031;
                    int x2053 = 1/*true*/;
                    char x2054 = '\0';
                    char  *x2055 = 0/*null*/;
                    char x2049 = x2048[0];
                    int x2050 = x2049 == '\0';
                    if (x2050) {
                      x2055 = x2048;
                    } else {
                      int x2051 = x2049 == 'e';
                      if (x2051) {
                        x2053 = 0/*false*/;
                        x2054 = x2049;
                        char  *x2052 = x2048+1;
                        x2055 = x2052;
                      } else {
                        x2055 = x2048;
                      }
                    }
                    int x2067 = x2053;
                    if (x2067) {
                      char  *x2068 = x2055;
                      x1832 = 0;
                    } else {
                      char x2071 = x2054;
                      char  *x2072 = x2055;
                      int x2077 = 1/*true*/;
                      char x2078 = '\0';
                      char  *x2079 = 0/*null*/;
                      char x2073 = x2072[0];
                      int x2074 = x2073 == '\0';
                      if (x2074) {
                        x2079 = x2072;
                      } else {
                        int x2075 = x2073 == 'n';
                        if (x2075) {
                          x2077 = 0/*false*/;
                          x2078 = x2073;
                          char  *x2076 = x2072+1;
                          x2079 = x2076;
                        } else {
                          x2079 = x2072;
                        }
                      }
                      int x2091 = x2077;
                      if (x2091) {
                        char  *x2092 = x2079;
                        x1832 = 0;
                      } else {
                        char x2095 = x2078;
                        char  *x2096 = x2079;
                        int x2101 = 1/*true*/;
                        char x2102 = '\0';
                        char  *x2103 = 0/*null*/;
                        char x2097 = x2096[0];
                        int x2098 = x2097 == '\0';
                        if (x2098) {
                          x2103 = x2096;
                        } else {
                          int x2099 = x2097 == 'g';
                          if (x2099) {
                            x2101 = 0/*false*/;
                            x2102 = x2097;
                            char  *x2100 = x2096+1;
                            x2103 = x2100;
                          } else {
                            x2103 = x2096;
                          }
                        }
                        int x2115 = x2101;
                        if (x2115) {
                          char  *x2116 = x2103;
                          x1832 = 0;
                        } else {
                          char x2119 = x2102;
                          char  *x2120 = x2103;
                          int x2125 = 1/*true*/;
                          char x2126 = '\0';
                          char  *x2127 = 0/*null*/;
                          char x2121 = x2120[0];
                          int x2122 = x2121 == '\0';
                          if (x2122) {
                            x2127 = x2120;
                          } else {
                            int x2123 = x2121 == 't';
                            if (x2123) {
                              x2125 = 0/*false*/;
                              x2126 = x2121;
                              char  *x2124 = x2120+1;
                              x2127 = x2124;
                            } else {
                              x2127 = x2120;
                            }
                          }
                          int x2139 = x2125;
                          if (x2139) {
                            char  *x2140 = x2127;
                            x1832 = 0;
                          } else {
                            char x2143 = x2126;
                            char  *x2144 = x2127;
                            int x2149 = 1/*true*/;
                            char x2150 = '\0';
                            char  *x2151 = 0/*null*/;
                            char x2145 = x2144[0];
                            int x2146 = x2145 == '\0';
                            if (x2146) {
                              x2151 = x2144;
                            } else {
                              int x2147 = x2145 == 'h';
                              if (x2147) {
                                x2149 = 0/*false*/;
                                x2150 = x2145;
                                char  *x2148 = x2144+1;
                                x2151 = x2148;
                              } else {
                                x2151 = x2144;
                              }
                            }
                            int x2163 = x2149;
                            if (x2163) {
                              char  *x2164 = x2151;
                              x1832 = 0;
                            } else {
                              char x2167 = x2150;
                              char  *x2168 = x2151;
                              x1832 = x2168;
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
  char  *x2198 = x1832;
  return x2198;
}
/*@
requires ((strlen(x2214)>=0) &&
\valid(x2214+(0..strlen(x2214))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..strlen(\result)))));
*/
char  * p_TransferEncoding(char  * x2214) {
  char  *x2216 = x2214;
  int x2221 = 1/*true*/;
  char x2222 = '\0';
  char  *x2223 = 0/*null*/;
  char x2217 = x2214[0];
  int x2218 = x2217 == '\0';
  if (x2218) {
    x2223 = x2214;
  } else {
    int x2219 = x2217 == 'T';
    if (x2219) {
      x2221 = 0/*false*/;
      x2222 = x2217;
      char  *x2220 = x2214+1;
      x2223 = x2220;
    } else {
      x2223 = x2214;
    }
  }
  int x2235 = x2221;
  if (x2235) {
    char  *x2236 = x2223;
    x2216 = 0;
  } else {
    char x2239 = x2222;
    char  *x2240 = x2223;
    int x2245 = 1/*true*/;
    char x2246 = '\0';
    char  *x2247 = 0/*null*/;
    char x2241 = x2240[0];
    int x2242 = x2241 == '\0';
    if (x2242) {
      x2247 = x2240;
    } else {
      int x2243 = x2241 == 'r';
      if (x2243) {
        x2245 = 0/*false*/;
        x2246 = x2241;
        char  *x2244 = x2240+1;
        x2247 = x2244;
      } else {
        x2247 = x2240;
      }
    }
    int x2259 = x2245;
    if (x2259) {
      char  *x2260 = x2247;
      x2216 = 0;
    } else {
      char x2263 = x2246;
      char  *x2264 = x2247;
      int x2269 = 1/*true*/;
      char x2270 = '\0';
      char  *x2271 = 0/*null*/;
      char x2265 = x2264[0];
      int x2266 = x2265 == '\0';
      if (x2266) {
        x2271 = x2264;
      } else {
        int x2267 = x2265 == 'a';
        if (x2267) {
          x2269 = 0/*false*/;
          x2270 = x2265;
          char  *x2268 = x2264+1;
          x2271 = x2268;
        } else {
          x2271 = x2264;
        }
      }
      int x2283 = x2269;
      if (x2283) {
        char  *x2284 = x2271;
        x2216 = 0;
      } else {
        char x2287 = x2270;
        char  *x2288 = x2271;
        int x2293 = 1/*true*/;
        char x2294 = '\0';
        char  *x2295 = 0/*null*/;
        char x2289 = x2288[0];
        int x2290 = x2289 == '\0';
        if (x2290) {
          x2295 = x2288;
        } else {
          int x2291 = x2289 == 'n';
          if (x2291) {
            x2293 = 0/*false*/;
            x2294 = x2289;
            char  *x2292 = x2288+1;
            x2295 = x2292;
          } else {
            x2295 = x2288;
          }
        }
        int x2307 = x2293;
        if (x2307) {
          char  *x2308 = x2295;
          x2216 = 0;
        } else {
          char x2311 = x2294;
          char  *x2312 = x2295;
          int x2317 = 1/*true*/;
          char x2318 = '\0';
          char  *x2319 = 0/*null*/;
          char x2313 = x2312[0];
          int x2314 = x2313 == '\0';
          if (x2314) {
            x2319 = x2312;
          } else {
            int x2315 = x2313 == 's';
            if (x2315) {
              x2317 = 0/*false*/;
              x2318 = x2313;
              char  *x2316 = x2312+1;
              x2319 = x2316;
            } else {
              x2319 = x2312;
            }
          }
          int x2331 = x2317;
          if (x2331) {
            char  *x2332 = x2319;
            x2216 = 0;
          } else {
            char x2335 = x2318;
            char  *x2336 = x2319;
            int x2341 = 1/*true*/;
            char x2342 = '\0';
            char  *x2343 = 0/*null*/;
            char x2337 = x2336[0];
            int x2338 = x2337 == '\0';
            if (x2338) {
              x2343 = x2336;
            } else {
              int x2339 = x2337 == 'f';
              if (x2339) {
                x2341 = 0/*false*/;
                x2342 = x2337;
                char  *x2340 = x2336+1;
                x2343 = x2340;
              } else {
                x2343 = x2336;
              }
            }
            int x2355 = x2341;
            if (x2355) {
              char  *x2356 = x2343;
              x2216 = 0;
            } else {
              char x2359 = x2342;
              char  *x2360 = x2343;
              int x2365 = 1/*true*/;
              char x2366 = '\0';
              char  *x2367 = 0/*null*/;
              char x2361 = x2360[0];
              int x2362 = x2361 == '\0';
              if (x2362) {
                x2367 = x2360;
              } else {
                int x2363 = x2361 == 'e';
                if (x2363) {
                  x2365 = 0/*false*/;
                  x2366 = x2361;
                  char  *x2364 = x2360+1;
                  x2367 = x2364;
                } else {
                  x2367 = x2360;
                }
              }
              int x2379 = x2365;
              if (x2379) {
                char  *x2380 = x2367;
                x2216 = 0;
              } else {
                char x2383 = x2366;
                char  *x2384 = x2367;
                int x2389 = 1/*true*/;
                char x2390 = '\0';
                char  *x2391 = 0/*null*/;
                char x2385 = x2384[0];
                int x2386 = x2385 == '\0';
                if (x2386) {
                  x2391 = x2384;
                } else {
                  int x2387 = x2385 == 'r';
                  if (x2387) {
                    x2389 = 0/*false*/;
                    x2390 = x2385;
                    char  *x2388 = x2384+1;
                    x2391 = x2388;
                  } else {
                    x2391 = x2384;
                  }
                }
                int x2403 = x2389;
                if (x2403) {
                  char  *x2404 = x2391;
                  x2216 = 0;
                } else {
                  char x2407 = x2390;
                  char  *x2408 = x2391;
                  int x2413 = 1/*true*/;
                  char x2414 = '\0';
                  char  *x2415 = 0/*null*/;
                  char x2409 = x2408[0];
                  int x2410 = x2409 == '\0';
                  if (x2410) {
                    x2415 = x2408;
                  } else {
                    int x2411 = x2409 == '-';
                    if (x2411) {
                      x2413 = 0/*false*/;
                      x2414 = x2409;
                      char  *x2412 = x2408+1;
                      x2415 = x2412;
                    } else {
                      x2415 = x2408;
                    }
                  }
                  int x2427 = x2413;
                  if (x2427) {
                    char  *x2428 = x2415;
                    x2216 = 0;
                  } else {
                    char x2431 = x2414;
                    char  *x2432 = x2415;
                    int x2437 = 1/*true*/;
                    char x2438 = '\0';
                    char  *x2439 = 0/*null*/;
                    char x2433 = x2432[0];
                    int x2434 = x2433 == '\0';
                    if (x2434) {
                      x2439 = x2432;
                    } else {
                      int x2435 = x2433 == 'E';
                      if (x2435) {
                        x2437 = 0/*false*/;
                        x2438 = x2433;
                        char  *x2436 = x2432+1;
                        x2439 = x2436;
                      } else {
                        x2439 = x2432;
                      }
                    }
                    int x2451 = x2437;
                    if (x2451) {
                      char  *x2452 = x2439;
                      x2216 = 0;
                    } else {
                      char x2455 = x2438;
                      char  *x2456 = x2439;
                      int x2461 = 1/*true*/;
                      char x2462 = '\0';
                      char  *x2463 = 0/*null*/;
                      char x2457 = x2456[0];
                      int x2458 = x2457 == '\0';
                      if (x2458) {
                        x2463 = x2456;
                      } else {
                        int x2459 = x2457 == 'n';
                        if (x2459) {
                          x2461 = 0/*false*/;
                          x2462 = x2457;
                          char  *x2460 = x2456+1;
                          x2463 = x2460;
                        } else {
                          x2463 = x2456;
                        }
                      }
                      int x2475 = x2461;
                      if (x2475) {
                        char  *x2476 = x2463;
                        x2216 = 0;
                      } else {
                        char x2479 = x2462;
                        char  *x2480 = x2463;
                        int x2485 = 1/*true*/;
                        char x2486 = '\0';
                        char  *x2487 = 0/*null*/;
                        char x2481 = x2480[0];
                        int x2482 = x2481 == '\0';
                        if (x2482) {
                          x2487 = x2480;
                        } else {
                          int x2483 = x2481 == 'c';
                          if (x2483) {
                            x2485 = 0/*false*/;
                            x2486 = x2481;
                            char  *x2484 = x2480+1;
                            x2487 = x2484;
                          } else {
                            x2487 = x2480;
                          }
                        }
                        int x2499 = x2485;
                        if (x2499) {
                          char  *x2500 = x2487;
                          x2216 = 0;
                        } else {
                          char x2503 = x2486;
                          char  *x2504 = x2487;
                          int x2509 = 1/*true*/;
                          char x2510 = '\0';
                          char  *x2511 = 0/*null*/;
                          char x2505 = x2504[0];
                          int x2506 = x2505 == '\0';
                          if (x2506) {
                            x2511 = x2504;
                          } else {
                            int x2507 = x2505 == 'o';
                            if (x2507) {
                              x2509 = 0/*false*/;
                              x2510 = x2505;
                              char  *x2508 = x2504+1;
                              x2511 = x2508;
                            } else {
                              x2511 = x2504;
                            }
                          }
                          int x2523 = x2509;
                          if (x2523) {
                            char  *x2524 = x2511;
                            x2216 = 0;
                          } else {
                            char x2527 = x2510;
                            char  *x2528 = x2511;
                            int x2533 = 1/*true*/;
                            char x2534 = '\0';
                            char  *x2535 = 0/*null*/;
                            char x2529 = x2528[0];
                            int x2530 = x2529 == '\0';
                            if (x2530) {
                              x2535 = x2528;
                            } else {
                              int x2531 = x2529 == 'd';
                              if (x2531) {
                                x2533 = 0/*false*/;
                                x2534 = x2529;
                                char  *x2532 = x2528+1;
                                x2535 = x2532;
                              } else {
                                x2535 = x2528;
                              }
                            }
                            int x2547 = x2533;
                            if (x2547) {
                              char  *x2548 = x2535;
                              x2216 = 0;
                            } else {
                              char x2551 = x2534;
                              char  *x2552 = x2535;
                              int x2557 = 1/*true*/;
                              char x2558 = '\0';
                              char  *x2559 = 0/*null*/;
                              char x2553 = x2552[0];
                              int x2554 = x2553 == '\0';
                              if (x2554) {
                                x2559 = x2552;
                              } else {
                                int x2555 = x2553 == 'i';
                                if (x2555) {
                                  x2557 = 0/*false*/;
                                  x2558 = x2553;
                                  char  *x2556 = x2552+1;
                                  x2559 = x2556;
                                } else {
                                  x2559 = x2552;
                                }
                              }
                              int x2571 = x2557;
                              if (x2571) {
                                char  *x2572 = x2559;
                                x2216 = 0;
                              } else {
                                char x2575 = x2558;
                                char  *x2576 = x2559;
                                int x2581 = 1/*true*/;
                                char x2582 = '\0';
                                char  *x2583 = 0/*null*/;
                                char x2577 = x2576[0];
                                int x2578 = x2577 == '\0';
                                if (x2578) {
                                  x2583 = x2576;
                                } else {
                                  int x2579 = x2577 == 'n';
                                  if (x2579) {
                                    x2581 = 0/*false*/;
                                    x2582 = x2577;
                                    char  *x2580 = x2576+1;
                                    x2583 = x2580;
                                  } else {
                                    x2583 = x2576;
                                  }
                                }
                                int x2595 = x2581;
                                if (x2595) {
                                  char  *x2596 = x2583;
                                  x2216 = 0;
                                } else {
                                  char x2599 = x2582;
                                  char  *x2600 = x2583;
                                  int x2605 = 1/*true*/;
                                  char x2606 = '\0';
                                  char  *x2607 = 0/*null*/;
                                  char x2601 = x2600[0];
                                  int x2602 = x2601 == '\0';
                                  if (x2602) {
                                    x2607 = x2600;
                                  } else {
                                    int x2603 = x2601 == 'g';
                                    if (x2603) {
                                      x2605 = 0/*false*/;
                                      x2606 = x2601;
                                      char  *x2604 = x2600+1;
                                      x2607 = x2604;
                                    } else {
                                      x2607 = x2600;
                                    }
                                  }
                                  int x2619 = x2605;
                                  if (x2619) {
                                    char  *x2620 = x2607;
                                    x2216 = 0;
                                  } else {
                                    char x2623 = x2606;
                                    char  *x2624 = x2607;
                                    x2216 = x2624;
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
  char  *x2660 = x2216;
  return x2660;
}
/*@
requires ((strlen(x2676)>=0) &&
\valid(x2676+(0..strlen(x2676))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..strlen(\result)))));
*/
char  * p_chunked(char  * x2676) {
  char  *x2678 = x2676;
  int x2683 = 1/*true*/;
  char x2684 = '\0';
  char  *x2685 = 0/*null*/;
  char x2679 = x2676[0];
  int x2680 = x2679 == '\0';
  if (x2680) {
    x2685 = x2676;
  } else {
    int x2681 = x2679 == 'c';
    if (x2681) {
      x2683 = 0/*false*/;
      x2684 = x2679;
      char  *x2682 = x2676+1;
      x2685 = x2682;
    } else {
      x2685 = x2676;
    }
  }
  int x2697 = x2683;
  if (x2697) {
    char  *x2698 = x2685;
    x2678 = 0;
  } else {
    char x2701 = x2684;
    char  *x2702 = x2685;
    int x2707 = 1/*true*/;
    char x2708 = '\0';
    char  *x2709 = 0/*null*/;
    char x2703 = x2702[0];
    int x2704 = x2703 == '\0';
    if (x2704) {
      x2709 = x2702;
    } else {
      int x2705 = x2703 == 'h';
      if (x2705) {
        x2707 = 0/*false*/;
        x2708 = x2703;
        char  *x2706 = x2702+1;
        x2709 = x2706;
      } else {
        x2709 = x2702;
      }
    }
    int x2721 = x2707;
    if (x2721) {
      char  *x2722 = x2709;
      x2678 = 0;
    } else {
      char x2725 = x2708;
      char  *x2726 = x2709;
      int x2731 = 1/*true*/;
      char x2732 = '\0';
      char  *x2733 = 0/*null*/;
      char x2727 = x2726[0];
      int x2728 = x2727 == '\0';
      if (x2728) {
        x2733 = x2726;
      } else {
        int x2729 = x2727 == 'u';
        if (x2729) {
          x2731 = 0/*false*/;
          x2732 = x2727;
          char  *x2730 = x2726+1;
          x2733 = x2730;
        } else {
          x2733 = x2726;
        }
      }
      int x2745 = x2731;
      if (x2745) {
        char  *x2746 = x2733;
        x2678 = 0;
      } else {
        char x2749 = x2732;
        char  *x2750 = x2733;
        int x2755 = 1/*true*/;
        char x2756 = '\0';
        char  *x2757 = 0/*null*/;
        char x2751 = x2750[0];
        int x2752 = x2751 == '\0';
        if (x2752) {
          x2757 = x2750;
        } else {
          int x2753 = x2751 == 'n';
          if (x2753) {
            x2755 = 0/*false*/;
            x2756 = x2751;
            char  *x2754 = x2750+1;
            x2757 = x2754;
          } else {
            x2757 = x2750;
          }
        }
        int x2769 = x2755;
        if (x2769) {
          char  *x2770 = x2757;
          x2678 = 0;
        } else {
          char x2773 = x2756;
          char  *x2774 = x2757;
          int x2779 = 1/*true*/;
          char x2780 = '\0';
          char  *x2781 = 0/*null*/;
          char x2775 = x2774[0];
          int x2776 = x2775 == '\0';
          if (x2776) {
            x2781 = x2774;
          } else {
            int x2777 = x2775 == 'k';
            if (x2777) {
              x2779 = 0/*false*/;
              x2780 = x2775;
              char  *x2778 = x2774+1;
              x2781 = x2778;
            } else {
              x2781 = x2774;
            }
          }
          int x2793 = x2779;
          if (x2793) {
            char  *x2794 = x2781;
            x2678 = 0;
          } else {
            char x2797 = x2780;
            char  *x2798 = x2781;
            int x2803 = 1/*true*/;
            char x2804 = '\0';
            char  *x2805 = 0/*null*/;
            char x2799 = x2798[0];
            int x2800 = x2799 == '\0';
            if (x2800) {
              x2805 = x2798;
            } else {
              int x2801 = x2799 == 'e';
              if (x2801) {
                x2803 = 0/*false*/;
                x2804 = x2799;
                char  *x2802 = x2798+1;
                x2805 = x2802;
              } else {
                x2805 = x2798;
              }
            }
            int x2817 = x2803;
            if (x2817) {
              char  *x2818 = x2805;
              x2678 = 0;
            } else {
              char x2821 = x2804;
              char  *x2822 = x2805;
              int x2827 = 1/*true*/;
              char x2828 = '\0';
              char  *x2829 = 0/*null*/;
              char x2823 = x2822[0];
              int x2824 = x2823 == '\0';
              if (x2824) {
                x2829 = x2822;
              } else {
                int x2825 = x2823 == 'd';
                if (x2825) {
                  x2827 = 0/*false*/;
                  x2828 = x2823;
                  char  *x2826 = x2822+1;
                  x2829 = x2826;
                } else {
                  x2829 = x2822;
                }
              }
              int x2841 = x2827;
              if (x2841) {
                char  *x2842 = x2829;
                x2678 = 0;
              } else {
                char x2845 = x2828;
                char  *x2846 = x2829;
                x2678 = x2846;
              }
            }
          }
        }
      }
    }
  }
  char  *x2862 = x2678;
  return x2862;
}
