#include <limits.h>
#include <string.h>
char  * p_chunked(char  * x1794);
char  * p_TransferEncoding(char  * x1796);
char  * p_ContentLength(char  * x1798);
char  * p_HTTP(char  * x1800);
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
  int x21 = 0;
  char  *x22 = 0/*null*/;
  int x23 = 1/*true*/;
  char x24 = '\0';
  char  *x25 = 0/*null*/;
  int x26 = 1/*true*/;
  int x27 = 0;
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
    int x52 = 0;
    char  *x53 = 0/*null*/;
    int x54 = 1/*true*/;
    char x55 = '\0';
    char  *x56 = 0/*null*/;
    char x45 = x44[0];
    int x46 = x45 == '\0';
    if (x46) {
      x56 = x44;
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
        x54 = 0/*false*/;
        x55 = x45;
        char  *x50 = x44+1;
        x56 = x50;
      } else {
        x56 = x44;
      }
    }
    int x68 = x54;
    if (x68) {
      char  *x69 = x56;
      x53 = x69;
    } else {
      char x72 = x55;
      char  *x74 = x56;
      x51 = 0/*false*/;
      char x73 = x72 - '0';
      x52 = x73;
      x53 = x74;
    }
    int x80 = x51;
    if (x80) {
      char  *x81 = x53;
      x28 = x81;
    } else {
      int x84 = x52;
      char  *x85 = x53;
      char  *x86 = x85;
      int x87 = 1/*true*/;
      int x88 = x84;
      int x121 = INT_MAX;
      int x122 = x121 / 10;
      int x123 = x122 - 10;
      /*@
      loop invariant ((strlen(x86)>=0) && \valid(x86+(0..strlen(x86))));
      loop assigns x86, x87, x88;
      */
      for (;;) {
        int x89 = x87;
        if (!x89) break;
        char  *x91 = x86;
        int x98 = 1/*true*/;
        char x99 = '\0';
        char  *x100 = 0/*null*/;
        char x92 = x91[0];
        int x93 = x92 == '\0';
        if (x93) {
          x100 = x91;
        } else {
          int x94 = x92 >= '0';
          int x96;
          if (x94) {
            int x95 = x92 <= '9';
            x96 = x95;
          } else {
            x96 = 0/*false*/;
          }
          if (x96) {
            x98 = 0/*false*/;
            x99 = x92;
            char  *x97 = x91+1;
            x100 = x97;
          } else {
            x100 = x91;
          }
        }
        int x112 = x98;
        if (x112) {
          char  *x113 = x100;
          x87 = 0/*false*/;
        } else {
          char x116 = x99;
          char  *x118 = x100;
          int x119 = x88;
          int x120 = x119 < 0;
          int x128;
          if (x120) {
            x128 = x119;
          } else {
            int x124 = x119 > x123;
            int x127;
            if (x124) {
              x127 = -1;
            } else {
              char x117 = x116 - '0';
              int x125 = x119 * 10;
              int x126 = x125 + x117;
              x127 = x126;
            }
            x128 = x127;
          }
          x88 = x128;
          x86 = x118;
        }
      }
      int x149 = x88;
      char  *x150 = x86;
      x26 = 0/*false*/;
      x27 = x149;
      x28 = x150;
    }
  }
  int x158 = x26;
  if (x158) {
    char  *x159 = x28;
    x25 = x159;
  } else {
    int x162 = x27;
    char  *x163 = x28;
    char x164 = x163[0];
    int x165 = x164 == '\0';
    if (x165) {
      x25 = x163;
    } else {
      int x166 = x164 == '.';
      if (x166) {
        x23 = 0/*false*/;
        x24 = x164;
        char  *x167 = x163+1;
        x25 = x167;
      } else {
        x25 = x163;
      }
    }
  }
  int x181 = x23;
  if (x181) {
    char  *x182 = x25;
    x22 = x182;
  } else {
    char x185 = x24;
    char  *x186 = x25;
    int x193 = 1/*true*/;
    int x194 = 0;
    char  *x195 = 0/*null*/;
    int x196 = 1/*true*/;
    char x197 = '\0';
    char  *x198 = 0/*null*/;
    char x187 = x186[0];
    int x188 = x187 == '\0';
    if (x188) {
      x198 = x186;
    } else {
      int x189 = x187 >= '0';
      int x191;
      if (x189) {
        int x190 = x187 <= '9';
        x191 = x190;
      } else {
        x191 = 0/*false*/;
      }
      if (x191) {
        x196 = 0/*false*/;
        x197 = x187;
        char  *x192 = x186+1;
        x198 = x192;
      } else {
        x198 = x186;
      }
    }
    int x210 = x196;
    if (x210) {
      char  *x211 = x198;
      x195 = x211;
    } else {
      char x214 = x197;
      char  *x216 = x198;
      x193 = 0/*false*/;
      char x215 = x214 - '0';
      x194 = x215;
      x195 = x216;
    }
    int x222 = x193;
    if (x222) {
      char  *x223 = x195;
      x22 = x223;
    } else {
      int x226 = x194;
      char  *x227 = x195;
      char  *x228 = x227;
      int x229 = 1/*true*/;
      int x230 = x226;
      int x121 = INT_MAX;
      int x122 = x121 / 10;
      int x123 = x122 - 10;
      /*@
      loop invariant ((strlen(x228)>=0) && \valid(x228+(0..strlen(x228))));
      loop assigns x228, x229, x230;
      */
      for (;;) {
        int x231 = x229;
        if (!x231) break;
        char  *x233 = x228;
        int x240 = 1/*true*/;
        char x241 = '\0';
        char  *x242 = 0/*null*/;
        char x234 = x233[0];
        int x235 = x234 == '\0';
        if (x235) {
          x242 = x233;
        } else {
          int x236 = x234 >= '0';
          int x238;
          if (x236) {
            int x237 = x234 <= '9';
            x238 = x237;
          } else {
            x238 = 0/*false*/;
          }
          if (x238) {
            x240 = 0/*false*/;
            x241 = x234;
            char  *x239 = x233+1;
            x242 = x239;
          } else {
            x242 = x233;
          }
        }
        int x254 = x240;
        if (x254) {
          char  *x255 = x242;
          x229 = 0/*false*/;
        } else {
          char x258 = x241;
          char  *x260 = x242;
          int x261 = x230;
          int x262 = x261 < 0;
          int x267;
          if (x262) {
            x267 = x261;
          } else {
            int x263 = x261 > x123;
            int x266;
            if (x263) {
              x266 = -1;
            } else {
              char x259 = x258 - '0';
              int x264 = x261 * 10;
              int x265 = x264 + x259;
              x266 = x265;
            }
            x267 = x266;
          }
          x230 = x267;
          x228 = x260;
        }
      }
      int x288 = x230;
      char  *x289 = x228;
      x20 = 0/*false*/;
      x21 = x288;
      x22 = x289;
    }
  }
  int x297 = x20;
  if (x297) {
    char  *x298 = x22;
    x19 = x298;
  } else {
    int x301 = x21;
    char  *x302 = x22;
    char  *x303 = x302;
    int x304 = 1/*true*/;
    /*@
    loop invariant ((strlen(x303)>=0) && \valid(x303+(0..strlen(x303))));
    loop assigns x303, x304;
    */
    for (;;) {
      int x305 = x304;
      if (!x305) break;
      char  *x307 = x303;
      char x308 = x307[0];
      int x309 = x308 == '\0';
      if (x309) {
        x304 = 0/*false*/;
      } else {
        int x310 = x308 == ' ';
        if (x310) {
          char  *x311 = x307+1;
          x303 = x311;
        } else {
          x304 = 0/*false*/;
        }
      }
    }
    char  *x335 = x303;
    x17 = 0/*false*/;
    x19 = x335;
  }
  int x341 = x17;
  if (x341) {
    char  *x342 = x19;
    x16 = x342;
  } else {
    char  *x346 = x19;
    int x353 = 1/*true*/;
    int x354 = 0;
    char  *x355 = 0/*null*/;
    int x356 = 1/*true*/;
    char x357 = '\0';
    char  *x358 = 0/*null*/;
    char x347 = x346[0];
    int x348 = x347 == '\0';
    if (x348) {
      x358 = x346;
    } else {
      int x349 = x347 >= '0';
      int x351;
      if (x349) {
        int x350 = x347 <= '9';
        x351 = x350;
      } else {
        x351 = 0/*false*/;
      }
      if (x351) {
        x356 = 0/*false*/;
        x357 = x347;
        char  *x352 = x346+1;
        x358 = x352;
      } else {
        x358 = x346;
      }
    }
    int x370 = x356;
    if (x370) {
      char  *x371 = x358;
      x355 = x371;
    } else {
      char x374 = x357;
      char  *x376 = x358;
      x353 = 0/*false*/;
      char x375 = x374 - '0';
      x354 = x375;
      x355 = x376;
    }
    int x382 = x353;
    if (x382) {
      char  *x383 = x355;
      x16 = x383;
    } else {
      int x386 = x354;
      char  *x387 = x355;
      char  *x388 = x387;
      int x389 = 1/*true*/;
      int x390 = x386;
      int x121 = INT_MAX;
      int x122 = x121 / 10;
      int x123 = x122 - 10;
      /*@
      loop invariant ((strlen(x388)>=0) && \valid(x388+(0..strlen(x388))));
      loop assigns x388, x389, x390;
      */
      for (;;) {
        int x391 = x389;
        if (!x391) break;
        char  *x393 = x388;
        int x400 = 1/*true*/;
        char x401 = '\0';
        char  *x402 = 0/*null*/;
        char x394 = x393[0];
        int x395 = x394 == '\0';
        if (x395) {
          x402 = x393;
        } else {
          int x396 = x394 >= '0';
          int x398;
          if (x396) {
            int x397 = x394 <= '9';
            x398 = x397;
          } else {
            x398 = 0/*false*/;
          }
          if (x398) {
            x400 = 0/*false*/;
            x401 = x394;
            char  *x399 = x393+1;
            x402 = x399;
          } else {
            x402 = x393;
          }
        }
        int x414 = x400;
        if (x414) {
          char  *x415 = x402;
          x389 = 0/*false*/;
        } else {
          char x418 = x401;
          char  *x420 = x402;
          int x421 = x390;
          int x422 = x421 < 0;
          int x427;
          if (x422) {
            x427 = x421;
          } else {
            int x423 = x421 > x123;
            int x426;
            if (x423) {
              x426 = -1;
            } else {
              char x419 = x418 - '0';
              int x424 = x421 * 10;
              int x425 = x424 + x419;
              x426 = x425;
            }
            x427 = x426;
          }
          x390 = x427;
          x388 = x420;
        }
      }
      int x448 = x390;
      char  *x449 = x388;
      x14 = 0/*false*/;
      x15 = x448;
      x16 = x449;
    }
  }
  int x457 = x14;
  if (x457) {
    char  *x458 = x16;
    x13 = x458;
  } else {
    int x461 = x15;
    char  *x462 = x16;
    char  *x463 = x462;
    int x464 = 1/*true*/;
    /*@
    loop invariant ((strlen(x463)>=0) && \valid(x463+(0..strlen(x463))));
    loop assigns x463, x464;
    */
    for (;;) {
      int x465 = x464;
      if (!x465) break;
      char  *x467 = x463;
      char x468 = x467[0];
      int x469 = x468 == '\0';
      if (x469) {
        x464 = 0/*false*/;
      } else {
        int x470 = x468 != '\n';
        if (x470) {
          char  *x471 = x467+1;
          x463 = x471;
        } else {
          x464 = 0/*false*/;
        }
      }
    }
    char  *x495 = x463;
    int x496 = 1/*true*/;
    char  *x498 = 0/*null*/;
    x496 = 0/*false*/;
    x498 = x495;
    int x502 = x496;
    if (x502) {
      char  *x503 = x498;
      x13 = x503;
    } else {
      char  *x507 = x498;
      int x512 = 1/*true*/;
      char x513 = '\0';
      char  *x514 = 0/*null*/;
      char x508 = x507[0];
      int x509 = x508 == '\0';
      if (x509) {
        x514 = x507;
      } else {
        int x510 = x508 == '\n';
        if (x510) {
          x512 = 0/*false*/;
          x513 = x508;
          char  *x511 = x507+1;
          x514 = x511;
        } else {
          x514 = x507;
        }
      }
      int x526 = x512;
      if (x526) {
        char  *x527 = x514;
        x13 = x527;
      } else {
        char x530 = x513;
        char  *x531 = x514;
        x11 = 0/*false*/;
        x12 = x461;
        x13 = x531;
      }
    }
  }
  int x541 = x11;
  if (x541) {
    char  *x542 = x13;
    x10 = x542;
  } else {
    int x545 = x12;
    char  *x546 = x13;
    char  *x547 = x546;
    int x548 = 1/*true*/;
    int x549 = 0;
    int x121 = INT_MAX;
    int x122 = x121 / 10;
    int x123 = x122 - 10;
    int x1207 = -2 == -2;
    /*@
    loop invariant ((strlen(x547)>=0) && \valid(x547+(0..strlen(x547))));
    loop assigns x547, x548, x549;
    */
    for (;;) {
      int x550 = x548;
      if (!x550) break;
      char  *x552 = x547;
      char  *x553 = p_ContentLength(x552);
      int x555 = 1/*true*/;
      int x556 = 0;
      char  *x557 = 0/*null*/;
      int x558 = 1/*true*/;
      int x559 = 0;
      char  *x560 = 0/*null*/;
      int x561 = 1/*true*/;
      int x562 = 0;
      char  *x563 = 0/*null*/;
      int x564 = 1/*true*/;
      int x565 = 0;
      char  *x566 = 0/*null*/;
      int x567 = 1/*true*/;
      int x568 = 0;
      char  *x569 = 0/*null*/;
      int x570 = 1/*true*/;
      int x571 = 0;
      char  *x572 = 0/*null*/;
      int x573 = 1/*true*/;
      char  *x575 = 0/*null*/;
      int x554 = 0 != x553;
      if (x554) {
        x573 = 0/*false*/;
        x575 = x553;
      } else {
        x575 = x552;
      }
      int x583 = x573;
      if (x583) {
        char  *x584 = x575;
      } else {
        char  *x587 = x575;
        x570 = 0/*false*/;
        x571 = 1;
        x572 = x587;
      }
      int x593 = x570;
      if (x593) {
        char  *x594 = p_TransferEncoding(x552);
        int x596 = 1/*true*/;
        char  *x598 = 0/*null*/;
        int x595 = 0 != x594;
        if (x595) {
          x596 = 0/*false*/;
          x598 = x594;
        } else {
          x598 = x552;
        }
        int x606 = x596;
        if (x606) {
          char  *x607 = x598;
        } else {
          char  *x610 = x598;
          x567 = 0/*false*/;
          x568 = 2;
          x569 = x610;
        }
      } else {
        int x617 = x571;
        char  *x618 = x572;
        x567 = 0/*false*/;
        x568 = x617;
        x569 = x618;
      }
      int x624 = x567;
      if (x624) {
        char  *x625 = x552;
        int x626 = 1/*true*/;
        /*@
        loop invariant ((strlen(x625)>=0) && \valid(x625+(0..strlen(x625))));
        loop assigns x625, x626;
        */
        for (;;) {
          int x627 = x626;
          if (!x627) break;
          char  *x629 = x625;
          int x640 = 1/*true*/;
          char x641 = '\0';
          char  *x642 = 0/*null*/;
          char x630 = x629[0];
          int x631 = x630 == '\0';
          if (x631) {
          } else {
            int x632 = x630 >= 'a';
            int x634;
            if (x632) {
              int x633 = x630 <= 'z';
              x634 = x633;
            } else {
              x634 = 0/*false*/;
            }
            int x635 = x630 >= 'A';
            int x637;
            if (x635) {
              int x636 = x630 <= 'Z';
              x637 = x636;
            } else {
              x637 = 0/*false*/;
            }
            int x638 = x634 || x637;
            if (x638) {
              x640 = 0/*false*/;
              x641 = x630;
              char  *x639 = x629+1;
              x642 = x639;
            } else {
            }
          }
          int x650 = x640;
          char x652 = x641;
          char  *x653 = x642;
          if (x650) {
            if (x631) {
              x626 = 0/*false*/;
            } else {
              int x651 = x630 == '-';
              if (x651) {
                char  *x639 = x629+1;
                x625 = x639;
              } else {
                x626 = 0/*false*/;
              }
            }
          } else {
            x625 = x653;
          }
        }
        char  *x681 = x625;
        x564 = 0/*false*/;
        x565 = 0;
        x566 = x681;
      } else {
        int x686 = x568;
        char  *x687 = x569;
        x564 = 0/*false*/;
        x565 = x686;
        x566 = x687;
      }
      int x693 = x564;
      if (x693) {
        char  *x694 = x566;
        x563 = x694;
      } else {
        int x697 = x565;
        char  *x698 = x566;
        char  *x699 = x698;
        int x700 = 1/*true*/;
        /*@
        loop invariant ((strlen(x699)>=0) && \valid(x699+(0..strlen(x699))));
        loop assigns x699, x700;
        */
        for (;;) {
          int x701 = x700;
          if (!x701) break;
          char  *x703 = x699;
          char x704 = x703[0];
          int x705 = x704 == '\0';
          if (x705) {
            x700 = 0/*false*/;
          } else {
            int x706 = x704 == ' ';
            if (x706) {
              char  *x707 = x703+1;
              x699 = x707;
            } else {
              x700 = 0/*false*/;
            }
          }
        }
        char  *x731 = x699;
        x561 = 0/*false*/;
        x562 = x697;
        x563 = x731;
      }
      int x737 = x561;
      if (x737) {
        char  *x738 = x563;
        x560 = x738;
      } else {
        int x741 = x562;
        char  *x742 = x563;
        int x747 = 1/*true*/;
        char x748 = '\0';
        char  *x749 = 0/*null*/;
        char x743 = x742[0];
        int x744 = x743 == '\0';
        if (x744) {
          x749 = x742;
        } else {
          int x745 = x743 == ':';
          if (x745) {
            x747 = 0/*false*/;
            x748 = x743;
            char  *x746 = x742+1;
            x749 = x746;
          } else {
            x749 = x742;
          }
        }
        int x761 = x747;
        if (x761) {
          char  *x762 = x749;
          x560 = x762;
        } else {
          char x765 = x748;
          char  *x766 = x749;
          x558 = 0/*false*/;
          x559 = x741;
          x560 = x766;
        }
      }
      int x774 = x558;
      if (x774) {
        char  *x775 = x560;
        x557 = x775;
      } else {
        int x778 = x559;
        char  *x779 = x560;
        char  *x780 = x779;
        int x781 = 1/*true*/;
        /*@
        loop invariant ((strlen(x780)>=0) && \valid(x780+(0..strlen(x780))));
        loop assigns x780, x781;
        */
        for (;;) {
          int x782 = x781;
          if (!x782) break;
          char  *x784 = x780;
          char x785 = x784[0];
          int x786 = x785 == '\0';
          if (x786) {
            x781 = 0/*false*/;
          } else {
            int x787 = x785 == ' ';
            if (x787) {
              char  *x788 = x784+1;
              x780 = x788;
            } else {
              x781 = 0/*false*/;
            }
          }
        }
        char  *x812 = x780;
        x555 = 0/*false*/;
        x556 = x778;
        x557 = x812;
      }
      int x818 = x555;
      if (x818) {
        char  *x819 = x557;
        x548 = 0/*false*/;
      } else {
        int x822 = x556;
        char  *x823 = x557;
        char  *x825 = p_chunked(x823);
        char  *x834 = x823;
        int x835 = 1/*true*/;
        /*@
        loop invariant ((strlen(x834)>=0) && \valid(x834+(0..strlen(x834))));
        loop assigns x834, x835;
        */
        for (;;) {
          int x836 = x835;
          if (!x836) break;
          char  *x838 = x834;
          char x839 = x838[0];
          int x840 = x839 == '\0';
          if (x840) {
            x835 = 0/*false*/;
          } else {
            int x841 = x839 != '\n';
            if (x841) {
              char  *x842 = x838+1;
              x834 = x842;
            } else {
              x835 = 0/*false*/;
            }
          }
        }
        char  *x866 = x834;
        int x824 = x822 == 2;
        if (x824) {
          int x867 = 1/*true*/;
          int x868 = 0;
          char  *x869 = 0/*null*/;
          int x870 = 1/*true*/;
          int x871 = 0;
          char  *x872 = 0/*null*/;
          int x873 = 1/*true*/;
          char  *x875 = 0/*null*/;
          int x826 = 0 != x825;
          if (x826) {
            x873 = 0/*false*/;
            x875 = x825;
          } else {
            x875 = x823;
          }
          int x883 = x873;
          if (x883) {
            char  *x884 = x875;
            x872 = x884;
          } else {
            char  *x888 = x875;
            x870 = 0/*false*/;
            x871 = -3;
            x872 = x888;
          }
          int x894 = x870;
          if (x894) {
            char  *x895 = x872;
            x869 = x895;
          } else {
            int x898 = x871;
            char  *x899 = x872;
            char  *x900 = x899;
            int x901 = 1/*true*/;
            /*@
            loop invariant ((strlen(x900)>=0) && \valid(x900+(0..strlen(x900))));
            loop assigns x900, x901;
            */
            for (;;) {
              int x902 = x901;
              if (!x902) break;
              char  *x904 = x900;
              char x905 = x904[0];
              int x906 = x905 == '\0';
              if (x906) {
                x901 = 0/*false*/;
              } else {
                int x907 = x905 == ' ';
                if (x907) {
                  char  *x908 = x904+1;
                  x900 = x908;
                } else {
                  x901 = 0/*false*/;
                }
              }
            }
            char  *x932 = x900;
            x867 = 0/*false*/;
            x868 = x898;
            x869 = x932;
          }
          int x938 = x867;
          if (x938) {
            char  *x939 = x869;
            x548 = 0/*false*/;
          } else {
            int x942 = x868;
            char  *x943 = x869;
            int x948 = 1/*true*/;
            char x949 = '\0';
            char  *x950 = 0/*null*/;
            char x944 = x943[0];
            int x945 = x944 == '\0';
            if (x945) {
              x950 = x943;
            } else {
              int x946 = x944 == '\n';
              if (x946) {
                x948 = 0/*false*/;
                x949 = x944;
                char  *x947 = x943+1;
                x950 = x947;
              } else {
                x950 = x943;
              }
            }
            int x962 = x948;
            if (x962) {
              char  *x963 = x950;
              x548 = 0/*false*/;
            } else {
              char x966 = x949;
              char  *x967 = x950;
              int x968 = x549;
              int x969 = x942 == -2;
              int x970;
              if (x969) {
                x970 = x968;
              } else {
                x970 = x942;
              }
              x549 = x970;
              x547 = x967;
            }
          }
        } else {
          int x827 = x822 == 1;
          if (x827) {
            int x978 = 1/*true*/;
            int x979 = 0;
            char  *x980 = 0/*null*/;
            int x981 = 1/*true*/;
            int x982 = 0;
            char  *x983 = 0/*null*/;
            int x984 = 1/*true*/;
            int x985 = 0;
            char  *x986 = 0/*null*/;
            int x987 = 1/*true*/;
            char x988 = '\0';
            char  *x989 = 0/*null*/;
            char x828 = x823[0];
            int x829 = x828 == '\0';
            if (x829) {
              x989 = x823;
            } else {
              int x830 = x828 >= '0';
              int x832;
              if (x830) {
                int x831 = x828 <= '9';
                x832 = x831;
              } else {
                x832 = 0/*false*/;
              }
              if (x832) {
                x987 = 0/*false*/;
                x988 = x828;
                char  *x833 = x823+1;
                x989 = x833;
              } else {
                x989 = x823;
              }
            }
            int x1001 = x987;
            if (x1001) {
              char  *x1002 = x989;
              x986 = x1002;
            } else {
              char x1005 = x988;
              char  *x1007 = x989;
              x984 = 0/*false*/;
              char x1006 = x1005 - '0';
              x985 = x1006;
              x986 = x1007;
            }
            int x1013 = x984;
            if (x1013) {
              char  *x1014 = x986;
              x983 = x1014;
            } else {
              int x1017 = x985;
              char  *x1018 = x986;
              char  *x1019 = x1018;
              int x1020 = 1/*true*/;
              int x1021 = x1017;
              /*@
              loop invariant ((strlen(x1019)>=0) && \valid(x1019+(0..strlen(x1019))));
              loop assigns x1019, x1020, x1021;
              */
              for (;;) {
                int x1022 = x1020;
                if (!x1022) break;
                char  *x1024 = x1019;
                int x1031 = 1/*true*/;
                char x1032 = '\0';
                char  *x1033 = 0/*null*/;
                char x1025 = x1024[0];
                int x1026 = x1025 == '\0';
                if (x1026) {
                  x1033 = x1024;
                } else {
                  int x1027 = x1025 >= '0';
                  int x1029;
                  if (x1027) {
                    int x1028 = x1025 <= '9';
                    x1029 = x1028;
                  } else {
                    x1029 = 0/*false*/;
                  }
                  if (x1029) {
                    x1031 = 0/*false*/;
                    x1032 = x1025;
                    char  *x1030 = x1024+1;
                    x1033 = x1030;
                  } else {
                    x1033 = x1024;
                  }
                }
                int x1045 = x1031;
                if (x1045) {
                  char  *x1046 = x1033;
                  x1020 = 0/*false*/;
                } else {
                  char x1049 = x1032;
                  char  *x1051 = x1033;
                  int x1052 = x1021;
                  int x1053 = x1052 < 0;
                  int x1058;
                  if (x1053) {
                    x1058 = x1052;
                  } else {
                    int x1054 = x1052 > x123;
                    int x1057;
                    if (x1054) {
                      x1057 = -1;
                    } else {
                      char x1050 = x1049 - '0';
                      int x1055 = x1052 * 10;
                      int x1056 = x1055 + x1050;
                      x1057 = x1056;
                    }
                    x1058 = x1057;
                  }
                  x1021 = x1058;
                  x1019 = x1051;
                }
              }
              int x1079 = x1021;
              char  *x1080 = x1019;
              x981 = 0/*false*/;
              x982 = x1079;
              x983 = x1080;
            }
            int x1086 = x981;
            if (x1086) {
              char  *x1087 = x983;
              x980 = x1087;
            } else {
              int x1090 = x982;
              char  *x1091 = x983;
              char  *x1092 = x1091;
              int x1093 = 1/*true*/;
              /*@
              loop invariant ((strlen(x1092)>=0) && \valid(x1092+(0..strlen(x1092))));
              loop assigns x1092, x1093;
              */
              for (;;) {
                int x1094 = x1093;
                if (!x1094) break;
                char  *x1096 = x1092;
                char x1097 = x1096[0];
                int x1098 = x1097 == '\0';
                if (x1098) {
                  x1093 = 0/*false*/;
                } else {
                  int x1099 = x1097 == ' ';
                  if (x1099) {
                    char  *x1100 = x1096+1;
                    x1092 = x1100;
                  } else {
                    x1093 = 0/*false*/;
                  }
                }
              }
              char  *x1124 = x1092;
              x978 = 0/*false*/;
              x979 = x1090;
              x980 = x1124;
            }
            int x1130 = x978;
            if (x1130) {
              char  *x1131 = x980;
              x548 = 0/*false*/;
            } else {
              int x1134 = x979;
              char  *x1135 = x980;
              int x1140 = 1/*true*/;
              char x1141 = '\0';
              char  *x1142 = 0/*null*/;
              char x1136 = x1135[0];
              int x1137 = x1136 == '\0';
              if (x1137) {
                x1142 = x1135;
              } else {
                int x1138 = x1136 == '\n';
                if (x1138) {
                  x1140 = 0/*false*/;
                  x1141 = x1136;
                  char  *x1139 = x1135+1;
                  x1142 = x1139;
                } else {
                  x1142 = x1135;
                }
              }
              int x1154 = x1140;
              if (x1154) {
                char  *x1155 = x1142;
                x548 = 0/*false*/;
              } else {
                char x1158 = x1141;
                char  *x1159 = x1142;
                int x1160 = x549;
                int x1161 = x1134 == -2;
                int x1162;
                if (x1161) {
                  x1162 = x1160;
                } else {
                  x1162 = x1134;
                }
                x549 = x1162;
                x547 = x1159;
              }
            }
          } else {
            int x1170 = 1/*true*/;
            char  *x1172 = 0/*null*/;
            x1170 = 0/*false*/;
            x1172 = x866;
            int x1176 = x1170;
            if (x1176) {
              char  *x1177 = x1172;
              x548 = 0/*false*/;
            } else {
              char  *x1181 = x1172;
              int x1186 = 1/*true*/;
              char x1187 = '\0';
              char  *x1188 = 0/*null*/;
              char x1182 = x1181[0];
              int x1183 = x1182 == '\0';
              if (x1183) {
                x1188 = x1181;
              } else {
                int x1184 = x1182 == '\n';
                if (x1184) {
                  x1186 = 0/*false*/;
                  x1187 = x1182;
                  char  *x1185 = x1181+1;
                  x1188 = x1185;
                } else {
                  x1188 = x1181;
                }
              }
              int x1200 = x1186;
              if (x1200) {
                char  *x1201 = x1188;
                x548 = 0/*false*/;
              } else {
                char x1204 = x1187;
                char  *x1205 = x1188;
                int x1206 = x549;
                int x1208;
                if (x1207) {
                  x1208 = x1206;
                } else {
                  x1208 = -2;
                }
                x549 = x1208;
                x547 = x1205;
              }
            }
          }
        }
      }
    }
    int x1237 = x549;
    char  *x1238 = x547;
    x8 = 0/*false*/;
    x9 = x1237;
    x10 = x1238;
  }
  int x1244 = x8;
  if (x1244) {
    char  *x1245 = x10;
    x7 = x1245;
  } else {
    int x1248 = x9;
    char  *x1249 = x10;
    int x1254 = 1/*true*/;
    char x1255 = '\0';
    char  *x1256 = 0/*null*/;
    char x1250 = x1249[0];
    int x1251 = x1250 == '\0';
    if (x1251) {
      x1256 = x1249;
    } else {
      int x1252 = x1250 == '\n';
      if (x1252) {
        x1254 = 0/*false*/;
        x1255 = x1250;
        char  *x1253 = x1249+1;
        x1256 = x1253;
      } else {
        x1256 = x1249;
      }
    }
    int x1268 = x1254;
    if (x1268) {
      char  *x1269 = x1256;
      x7 = x1269;
    } else {
      char x1272 = x1255;
      char  *x1273 = x1256;
      x5 = 0/*false*/;
      x6 = x1248;
      x7 = x1273;
    }
  }
  int x1281 = x5;
  if (x1281) {
    char  *x1282 = x7;
  } else {
    int x1284 = x6;
    char  *x1285 = x7;
    char  *x1287 = x1285;
    int x1288 = 1/*true*/;
    int x1289 = 0;
    int x121 = INT_MAX;
    int x1449 = x121 / 16;
    int x1450 = x1449 - 16;
    /*@
    loop invariant ((strlen(x1287)>=0) && \valid(x1287+(0..strlen(x1287))));
    loop assigns x1287, x1288, x1289;
    */
    for (;;) {
      int x1290 = x1288;
      if (!x1290) break;
      char  *x1292 = x1287;
      int x1299 = 1/*true*/;
      int x1300 = 0;
      char  *x1301 = 0/*null*/;
      int x1302 = 1/*true*/;
      int x1303 = 0;
      char  *x1304 = 0/*null*/;
      int x1305 = 1/*true*/;
      int x1306 = 0;
      char  *x1307 = 0/*null*/;
      int x1308 = 1/*true*/;
      int x1309 = 0;
      char  *x1310 = 0/*null*/;
      int x1311 = 1/*true*/;
      char x1312 = '\0';
      char  *x1313 = 0/*null*/;
      char x1293 = x1292[0];
      int x1294 = x1293 == '\0';
      if (x1294) {
        x1313 = x1292;
      } else {
        int x1295 = x1293 >= '0';
        int x1297;
        if (x1295) {
          int x1296 = x1293 <= '9';
          x1297 = x1296;
        } else {
          x1297 = 0/*false*/;
        }
        if (x1297) {
          x1311 = 0/*false*/;
          x1312 = x1293;
          char  *x1298 = x1292+1;
          x1313 = x1298;
        } else {
          x1313 = x1292;
        }
      }
      int x1325 = x1311;
      if (x1325) {
        char  *x1326 = x1313;
      } else {
        char x1328 = x1312;
        char  *x1330 = x1313;
        x1308 = 0/*false*/;
        char x1329 = x1328 - '0';
        x1309 = x1329;
        x1310 = x1330;
      }
      int x1336 = x1308;
      if (x1336) {
        int x1340 = 1/*true*/;
        char x1341 = '\0';
        char  *x1342 = 0/*null*/;
        if (x1294) {
          x1342 = x1292;
        } else {
          int x1337 = x1293 >= 'a';
          int x1339;
          if (x1337) {
            int x1338 = x1293 <= 'f';
            x1339 = x1338;
          } else {
            x1339 = 0/*false*/;
          }
          if (x1339) {
            x1340 = 0/*false*/;
            x1341 = x1293;
            char  *x1298 = x1292+1;
            x1342 = x1298;
          } else {
            x1342 = x1292;
          }
        }
        int x1354 = x1340;
        if (x1354) {
          char  *x1355 = x1342;
          x1307 = x1355;
        } else {
          char x1358 = x1341;
          char  *x1361 = x1342;
          x1305 = 0/*false*/;
          char x1359 = x1358 - 'a';
          int x1360 = 10 + x1359;
          x1306 = x1360;
          x1307 = x1361;
        }
      } else {
        int x1368 = x1309;
        char  *x1369 = x1310;
        x1305 = 0/*false*/;
        x1306 = x1368;
        x1307 = x1369;
      }
      int x1375 = x1305;
      if (x1375) {
        char  *x1376 = x1307;
        x1304 = x1376;
      } else {
        int x1379 = x1306;
        char  *x1380 = x1307;
        char  *x1381 = x1380;
        int x1382 = 1/*true*/;
        int x1383 = x1379;
        /*@
        loop invariant ((strlen(x1381)>=0) && \valid(x1381+(0..strlen(x1381))));
        loop assigns x1381, x1382, x1383;
        */
        for (;;) {
          int x1384 = x1382;
          if (!x1384) break;
          char  *x1386 = x1381;
          int x1393 = 1/*true*/;
          int x1394 = 0;
          char  *x1395 = 0/*null*/;
          int x1396 = 1/*true*/;
          char x1397 = '\0';
          char  *x1398 = 0/*null*/;
          char x1387 = x1386[0];
          int x1388 = x1387 == '\0';
          if (x1388) {
            x1398 = x1386;
          } else {
            int x1389 = x1387 >= '0';
            int x1391;
            if (x1389) {
              int x1390 = x1387 <= '9';
              x1391 = x1390;
            } else {
              x1391 = 0/*false*/;
            }
            if (x1391) {
              x1396 = 0/*false*/;
              x1397 = x1387;
              char  *x1392 = x1386+1;
              x1398 = x1392;
            } else {
              x1398 = x1386;
            }
          }
          int x1410 = x1396;
          if (x1410) {
            char  *x1411 = x1398;
          } else {
            char x1413 = x1397;
            char  *x1415 = x1398;
            x1393 = 0/*false*/;
            char x1414 = x1413 - '0';
            x1394 = x1414;
            x1395 = x1415;
          }
          int x1421 = x1393;
          if (x1421) {
            int x1425 = 1/*true*/;
            char x1426 = '\0';
            char  *x1427 = 0/*null*/;
            if (x1388) {
              x1427 = x1386;
            } else {
              int x1422 = x1387 >= 'a';
              int x1424;
              if (x1422) {
                int x1423 = x1387 <= 'f';
                x1424 = x1423;
              } else {
                x1424 = 0/*false*/;
              }
              if (x1424) {
                x1425 = 0/*false*/;
                x1426 = x1387;
                char  *x1392 = x1386+1;
                x1427 = x1392;
              } else {
                x1427 = x1386;
              }
            }
            int x1439 = x1425;
            if (x1439) {
              char  *x1440 = x1427;
              x1382 = 0/*false*/;
            } else {
              char x1443 = x1426;
              char  *x1446 = x1427;
              int x1447 = x1383;
              int x1448 = x1447 < 0;
              int x1455;
              if (x1448) {
                x1455 = x1447;
              } else {
                int x1451 = x1447 > x1450;
                int x1454;
                if (x1451) {
                  x1454 = -1;
                } else {
                  char x1444 = x1443 - 'a';
                  int x1445 = 10 + x1444;
                  int x1452 = x1447 * 16;
                  int x1453 = x1452 + x1445;
                  x1454 = x1453;
                }
                x1455 = x1454;
              }
              x1383 = x1455;
              x1381 = x1446;
            }
          } else {
            int x1461 = x1394;
            char  *x1462 = x1395;
            int x1463 = x1383;
            int x1464 = x1463 < 0;
            int x1469;
            if (x1464) {
              x1469 = x1463;
            } else {
              int x1465 = x1463 > x1450;
              int x1468;
              if (x1465) {
                x1468 = -1;
              } else {
                int x1466 = x1463 * 16;
                int x1467 = x1466 + x1461;
                x1468 = x1467;
              }
              x1469 = x1468;
            }
            x1383 = x1469;
            x1381 = x1462;
          }
        }
        int x1490 = x1383;
        char  *x1491 = x1381;
        x1302 = 0/*false*/;
        x1303 = x1490;
        x1304 = x1491;
      }
      int x1497 = x1302;
      if (x1497) {
        char  *x1498 = x1304;
        x1301 = x1498;
      } else {
        int x1501 = x1303;
        char  *x1502 = x1304;
        int x1507 = 1/*true*/;
        char x1508 = '\0';
        char  *x1509 = 0/*null*/;
        char x1503 = x1502[0];
        int x1504 = x1503 == '\0';
        if (x1504) {
          x1509 = x1502;
        } else {
          int x1505 = x1503 == '\n';
          if (x1505) {
            x1507 = 0/*false*/;
            x1508 = x1503;
            char  *x1506 = x1502+1;
            x1509 = x1506;
          } else {
            x1509 = x1502;
          }
        }
        int x1521 = x1507;
        if (x1521) {
          char  *x1522 = x1509;
          x1301 = x1522;
        } else {
          char x1525 = x1508;
          char  *x1526 = x1509;
          x1299 = 0/*false*/;
          x1300 = x1501;
          x1301 = x1526;
        }
      }
      int x1534 = x1299;
      if (x1534) {
        char  *x1535 = x1301;
        x1288 = 0/*false*/;
      } else {
        int x1538 = x1300;
        char  *x1539 = x1301;
        int x1541 = 1/*true*/;
        char  *x1542 = x1539;
        /*@
        loop invariant ((0<=x1544) && ((strlen(x1542)>=0) && \valid(x1542+(0..strlen(x1542)))));
        loop assigns x1544, x1541, x1542;
        loop variant (x1300-x1544);
        */
        for(int x1544=0; x1544 < x1538; x1544++) {
          int x1545 = x1541;
          if (x1545) {
            char  *x1546 = x1542;
            char x1547 = x1546[0];
            int x1548 = x1547 == '\0';
            if (x1548) {
              x1541 = 0/*false*/;
            } else {
              if (1/*true*/) {
                char  *x1549 = x1546+1;
                x1542 = x1549;
              } else {
                x1541 = 0/*false*/;
              }
            }
          } else {
          }
        }
        int x1579 = x1541;
        char  *x1580 = x1542;
        int x1540 = x1538 < 0;
        if (x1540) {
          x1288 = 0/*false*/;
        } else {
          int x1583 = 1/*true*/;
          int x1584 = 0;
          char  *x1585 = 0/*null*/;
          int x1586 = 1/*true*/;
          char  *x1588 = 0/*null*/;
          if (x1579) {
            x1586 = 0/*false*/;
            x1588 = x1580;
          } else {
            x1588 = x1539;
          }
          int x1596 = x1586;
          if (x1596) {
            char  *x1597 = x1588;
            x1585 = x1597;
          } else {
            char  *x1601 = x1588;
            x1583 = 0/*false*/;
            x1584 = x1538;
            x1585 = x1601;
          }
          int x1607 = x1583;
          if (x1607) {
            char  *x1608 = x1585;
            x1288 = 0/*false*/;
          } else {
            int x1611 = x1584;
            char  *x1612 = x1585;
            int x1617 = 1/*true*/;
            char x1618 = '\0';
            char  *x1619 = 0/*null*/;
            char x1613 = x1612[0];
            int x1614 = x1613 == '\0';
            if (x1614) {
              x1619 = x1612;
            } else {
              int x1615 = x1613 == '\n';
              if (x1615) {
                x1617 = 0/*false*/;
                x1618 = x1613;
                char  *x1616 = x1612+1;
                x1619 = x1616;
              } else {
                x1619 = x1612;
              }
            }
            int x1631 = x1617;
            if (x1631) {
              char  *x1632 = x1619;
              x1288 = 0/*false*/;
            } else {
              char x1635 = x1618;
              char  *x1636 = x1619;
              int x1637 = x1289;
              int x1638 = x1637 < 0;
              int x1643;
              if (x1638) {
                x1643 = x1637;
              } else {
                int x1639 = x121 - x1611;
                int x1640 = x1637 > x1639;
                int x1642;
                if (x1640) {
                  x1642 = -1;
                } else {
                  int x1641 = x1637 + x1611;
                  x1642 = x1641;
                }
                x1643 = x1642;
              }
              x1289 = x1643;
              x1287 = x1636;
            }
          }
        }
      }
    }
    int x1670 = x1289;
    char  *x1671 = x1287;
    int x1673 = 1/*true*/;
    char  *x1674 = x1285;
    /*@
    loop invariant ((0<=x1676) && ((strlen(x1674)>=0) && \valid(x1674+(0..strlen(x1674)))));
    loop assigns x1676, x1673, x1674;
    loop variant (x6-x1676);
    */
    for(int x1676=0; x1676 < x1284; x1676++) {
      int x1677 = x1673;
      if (x1677) {
        char  *x1678 = x1674;
        char x1679 = x1678[0];
        int x1680 = x1679 == '\0';
        if (x1680) {
          x1673 = 0/*false*/;
        } else {
          if (1/*true*/) {
            char  *x1681 = x1678+1;
            x1674 = x1681;
          } else {
            x1673 = 0/*false*/;
          }
        }
      } else {
      }
    }
    int x1711 = x1673;
    char  *x1712 = x1674;
    int x1286 = x1284 == -3;
    if (x1286) {
      char x1713 = x1671[0];
      int x1714 = x1713 == '\0';
      if (x1714) {
        x2 = x1670;
      } else {
      }
    } else {
      int x1672 = x1284 < 0;
      if (x1672) {
      } else {
        int x1719 = 1/*true*/;
        int x1720 = 0;
        char  *x1721 = 0/*null*/;
        int x1722 = 1/*true*/;
        char  *x1724 = 0/*null*/;
        if (x1711) {
          x1722 = 0/*false*/;
          x1724 = x1712;
        } else {
          x1724 = x1285;
        }
        int x1732 = x1722;
        if (x1732) {
          char  *x1733 = x1724;
          x1721 = x1733;
        } else {
          char  *x1737 = x1724;
          x1719 = 0/*false*/;
          x1720 = x1284;
          x1721 = x1737;
        }
        int x1743 = x1719;
        if (x1743) {
          char  *x1744 = x1721;
        } else {
          int x1746 = x1720;
          char  *x1747 = x1721;
          int x1752 = 1/*true*/;
          char x1753 = '\0';
          char  *x1754 = 0/*null*/;
          char x1748 = x1747[0];
          int x1749 = x1748 == '\0';
          if (x1749) {
            x1754 = x1747;
          } else {
            int x1750 = x1748 == '\n';
            if (x1750) {
              x1752 = 0/*false*/;
              x1753 = x1748;
              char  *x1751 = x1747+1;
              x1754 = x1751;
            } else {
              x1754 = x1747;
            }
          }
          int x1766 = x1752;
          if (x1766) {
            char  *x1767 = x1754;
          } else {
            char x1769 = x1753;
            char  *x1770 = x1754;
            char x1771 = x1770[0];
            int x1772 = x1771 == '\0';
            if (x1772) {
              x2 = x1746;
            } else {
            }
          }
        }
      }
    }
  }
  int x1786 = x2;
  return x1786;
}
/*@
requires ((strlen(x1802)>=0) && \valid(x1802+(0..strlen(x1802))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_HTTP(char  * x1802) {
  char  *x1804 = x1802;
  int x1809 = 1/*true*/;
  char x1810 = '\0';
  char  *x1811 = 0/*null*/;
  char x1805 = x1802[0];
  int x1806 = x1805 == '\0';
  if (x1806) {
    x1811 = x1802;
  } else {
    int x1807 = x1805 == 'H';
    if (x1807) {
      x1809 = 0/*false*/;
      x1810 = x1805;
      char  *x1808 = x1802+1;
      x1811 = x1808;
    } else {
      x1811 = x1802;
    }
  }
  int x1823 = x1809;
  if (x1823) {
    char  *x1824 = x1811;
    x1804 = 0;
  } else {
    char x1827 = x1810;
    char  *x1828 = x1811;
    int x1833 = 1/*true*/;
    char x1834 = '\0';
    char  *x1835 = 0/*null*/;
    char x1829 = x1828[0];
    int x1830 = x1829 == '\0';
    if (x1830) {
      x1835 = x1828;
    } else {
      int x1831 = x1829 == 'T';
      if (x1831) {
        x1833 = 0/*false*/;
        x1834 = x1829;
        char  *x1832 = x1828+1;
        x1835 = x1832;
      } else {
        x1835 = x1828;
      }
    }
    int x1847 = x1833;
    if (x1847) {
      char  *x1848 = x1835;
      x1804 = 0;
    } else {
      char x1851 = x1834;
      char  *x1852 = x1835;
      int x1857 = 1/*true*/;
      char x1858 = '\0';
      char  *x1859 = 0/*null*/;
      char x1853 = x1852[0];
      int x1854 = x1853 == '\0';
      if (x1854) {
        x1859 = x1852;
      } else {
        int x1855 = x1853 == 'T';
        if (x1855) {
          x1857 = 0/*false*/;
          x1858 = x1853;
          char  *x1856 = x1852+1;
          x1859 = x1856;
        } else {
          x1859 = x1852;
        }
      }
      int x1871 = x1857;
      if (x1871) {
        char  *x1872 = x1859;
        x1804 = 0;
      } else {
        char x1875 = x1858;
        char  *x1876 = x1859;
        int x1881 = 1/*true*/;
        char x1882 = '\0';
        char  *x1883 = 0/*null*/;
        char x1877 = x1876[0];
        int x1878 = x1877 == '\0';
        if (x1878) {
          x1883 = x1876;
        } else {
          int x1879 = x1877 == 'P';
          if (x1879) {
            x1881 = 0/*false*/;
            x1882 = x1877;
            char  *x1880 = x1876+1;
            x1883 = x1880;
          } else {
            x1883 = x1876;
          }
        }
        int x1895 = x1881;
        if (x1895) {
          char  *x1896 = x1883;
          x1804 = 0;
        } else {
          char x1899 = x1882;
          char  *x1900 = x1883;
          int x1905 = 1/*true*/;
          char x1906 = '\0';
          char  *x1907 = 0/*null*/;
          char x1901 = x1900[0];
          int x1902 = x1901 == '\0';
          if (x1902) {
            x1907 = x1900;
          } else {
            int x1903 = x1901 == '/';
            if (x1903) {
              x1905 = 0/*false*/;
              x1906 = x1901;
              char  *x1904 = x1900+1;
              x1907 = x1904;
            } else {
              x1907 = x1900;
            }
          }
          int x1919 = x1905;
          if (x1919) {
            char  *x1920 = x1907;
            x1804 = 0;
          } else {
            char x1923 = x1906;
            char  *x1924 = x1907;
            x1804 = x1924;
          }
        }
      }
    }
  }
  char  *x1936 = x1804;
  return x1936;
}
/*@
requires ((strlen(x1952)>=0) && \valid(x1952+(0..strlen(x1952))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_ContentLength(char  * x1952) {
  char  *x1954 = x1952;
  int x1959 = 1/*true*/;
  char x1960 = '\0';
  char  *x1961 = 0/*null*/;
  char x1955 = x1952[0];
  int x1956 = x1955 == '\0';
  if (x1956) {
    x1961 = x1952;
  } else {
    int x1957 = x1955 == 'C';
    if (x1957) {
      x1959 = 0/*false*/;
      x1960 = x1955;
      char  *x1958 = x1952+1;
      x1961 = x1958;
    } else {
      x1961 = x1952;
    }
  }
  int x1973 = x1959;
  if (x1973) {
    char  *x1974 = x1961;
    x1954 = 0;
  } else {
    char x1977 = x1960;
    char  *x1978 = x1961;
    int x1983 = 1/*true*/;
    char x1984 = '\0';
    char  *x1985 = 0/*null*/;
    char x1979 = x1978[0];
    int x1980 = x1979 == '\0';
    if (x1980) {
      x1985 = x1978;
    } else {
      int x1981 = x1979 == 'o';
      if (x1981) {
        x1983 = 0/*false*/;
        x1984 = x1979;
        char  *x1982 = x1978+1;
        x1985 = x1982;
      } else {
        x1985 = x1978;
      }
    }
    int x1997 = x1983;
    if (x1997) {
      char  *x1998 = x1985;
      x1954 = 0;
    } else {
      char x2001 = x1984;
      char  *x2002 = x1985;
      int x2007 = 1/*true*/;
      char x2008 = '\0';
      char  *x2009 = 0/*null*/;
      char x2003 = x2002[0];
      int x2004 = x2003 == '\0';
      if (x2004) {
        x2009 = x2002;
      } else {
        int x2005 = x2003 == 'n';
        if (x2005) {
          x2007 = 0/*false*/;
          x2008 = x2003;
          char  *x2006 = x2002+1;
          x2009 = x2006;
        } else {
          x2009 = x2002;
        }
      }
      int x2021 = x2007;
      if (x2021) {
        char  *x2022 = x2009;
        x1954 = 0;
      } else {
        char x2025 = x2008;
        char  *x2026 = x2009;
        int x2031 = 1/*true*/;
        char x2032 = '\0';
        char  *x2033 = 0/*null*/;
        char x2027 = x2026[0];
        int x2028 = x2027 == '\0';
        if (x2028) {
          x2033 = x2026;
        } else {
          int x2029 = x2027 == 't';
          if (x2029) {
            x2031 = 0/*false*/;
            x2032 = x2027;
            char  *x2030 = x2026+1;
            x2033 = x2030;
          } else {
            x2033 = x2026;
          }
        }
        int x2045 = x2031;
        if (x2045) {
          char  *x2046 = x2033;
          x1954 = 0;
        } else {
          char x2049 = x2032;
          char  *x2050 = x2033;
          int x2055 = 1/*true*/;
          char x2056 = '\0';
          char  *x2057 = 0/*null*/;
          char x2051 = x2050[0];
          int x2052 = x2051 == '\0';
          if (x2052) {
            x2057 = x2050;
          } else {
            int x2053 = x2051 == 'e';
            if (x2053) {
              x2055 = 0/*false*/;
              x2056 = x2051;
              char  *x2054 = x2050+1;
              x2057 = x2054;
            } else {
              x2057 = x2050;
            }
          }
          int x2069 = x2055;
          if (x2069) {
            char  *x2070 = x2057;
            x1954 = 0;
          } else {
            char x2073 = x2056;
            char  *x2074 = x2057;
            int x2079 = 1/*true*/;
            char x2080 = '\0';
            char  *x2081 = 0/*null*/;
            char x2075 = x2074[0];
            int x2076 = x2075 == '\0';
            if (x2076) {
              x2081 = x2074;
            } else {
              int x2077 = x2075 == 'n';
              if (x2077) {
                x2079 = 0/*false*/;
                x2080 = x2075;
                char  *x2078 = x2074+1;
                x2081 = x2078;
              } else {
                x2081 = x2074;
              }
            }
            int x2093 = x2079;
            if (x2093) {
              char  *x2094 = x2081;
              x1954 = 0;
            } else {
              char x2097 = x2080;
              char  *x2098 = x2081;
              int x2103 = 1/*true*/;
              char x2104 = '\0';
              char  *x2105 = 0/*null*/;
              char x2099 = x2098[0];
              int x2100 = x2099 == '\0';
              if (x2100) {
                x2105 = x2098;
              } else {
                int x2101 = x2099 == 't';
                if (x2101) {
                  x2103 = 0/*false*/;
                  x2104 = x2099;
                  char  *x2102 = x2098+1;
                  x2105 = x2102;
                } else {
                  x2105 = x2098;
                }
              }
              int x2117 = x2103;
              if (x2117) {
                char  *x2118 = x2105;
                x1954 = 0;
              } else {
                char x2121 = x2104;
                char  *x2122 = x2105;
                int x2127 = 1/*true*/;
                char x2128 = '\0';
                char  *x2129 = 0/*null*/;
                char x2123 = x2122[0];
                int x2124 = x2123 == '\0';
                if (x2124) {
                  x2129 = x2122;
                } else {
                  int x2125 = x2123 == '-';
                  if (x2125) {
                    x2127 = 0/*false*/;
                    x2128 = x2123;
                    char  *x2126 = x2122+1;
                    x2129 = x2126;
                  } else {
                    x2129 = x2122;
                  }
                }
                int x2141 = x2127;
                if (x2141) {
                  char  *x2142 = x2129;
                  x1954 = 0;
                } else {
                  char x2145 = x2128;
                  char  *x2146 = x2129;
                  int x2151 = 1/*true*/;
                  char x2152 = '\0';
                  char  *x2153 = 0/*null*/;
                  char x2147 = x2146[0];
                  int x2148 = x2147 == '\0';
                  if (x2148) {
                    x2153 = x2146;
                  } else {
                    int x2149 = x2147 == 'L';
                    if (x2149) {
                      x2151 = 0/*false*/;
                      x2152 = x2147;
                      char  *x2150 = x2146+1;
                      x2153 = x2150;
                    } else {
                      x2153 = x2146;
                    }
                  }
                  int x2165 = x2151;
                  if (x2165) {
                    char  *x2166 = x2153;
                    x1954 = 0;
                  } else {
                    char x2169 = x2152;
                    char  *x2170 = x2153;
                    int x2175 = 1/*true*/;
                    char x2176 = '\0';
                    char  *x2177 = 0/*null*/;
                    char x2171 = x2170[0];
                    int x2172 = x2171 == '\0';
                    if (x2172) {
                      x2177 = x2170;
                    } else {
                      int x2173 = x2171 == 'e';
                      if (x2173) {
                        x2175 = 0/*false*/;
                        x2176 = x2171;
                        char  *x2174 = x2170+1;
                        x2177 = x2174;
                      } else {
                        x2177 = x2170;
                      }
                    }
                    int x2189 = x2175;
                    if (x2189) {
                      char  *x2190 = x2177;
                      x1954 = 0;
                    } else {
                      char x2193 = x2176;
                      char  *x2194 = x2177;
                      int x2199 = 1/*true*/;
                      char x2200 = '\0';
                      char  *x2201 = 0/*null*/;
                      char x2195 = x2194[0];
                      int x2196 = x2195 == '\0';
                      if (x2196) {
                        x2201 = x2194;
                      } else {
                        int x2197 = x2195 == 'n';
                        if (x2197) {
                          x2199 = 0/*false*/;
                          x2200 = x2195;
                          char  *x2198 = x2194+1;
                          x2201 = x2198;
                        } else {
                          x2201 = x2194;
                        }
                      }
                      int x2213 = x2199;
                      if (x2213) {
                        char  *x2214 = x2201;
                        x1954 = 0;
                      } else {
                        char x2217 = x2200;
                        char  *x2218 = x2201;
                        int x2223 = 1/*true*/;
                        char x2224 = '\0';
                        char  *x2225 = 0/*null*/;
                        char x2219 = x2218[0];
                        int x2220 = x2219 == '\0';
                        if (x2220) {
                          x2225 = x2218;
                        } else {
                          int x2221 = x2219 == 'g';
                          if (x2221) {
                            x2223 = 0/*false*/;
                            x2224 = x2219;
                            char  *x2222 = x2218+1;
                            x2225 = x2222;
                          } else {
                            x2225 = x2218;
                          }
                        }
                        int x2237 = x2223;
                        if (x2237) {
                          char  *x2238 = x2225;
                          x1954 = 0;
                        } else {
                          char x2241 = x2224;
                          char  *x2242 = x2225;
                          int x2247 = 1/*true*/;
                          char x2248 = '\0';
                          char  *x2249 = 0/*null*/;
                          char x2243 = x2242[0];
                          int x2244 = x2243 == '\0';
                          if (x2244) {
                            x2249 = x2242;
                          } else {
                            int x2245 = x2243 == 't';
                            if (x2245) {
                              x2247 = 0/*false*/;
                              x2248 = x2243;
                              char  *x2246 = x2242+1;
                              x2249 = x2246;
                            } else {
                              x2249 = x2242;
                            }
                          }
                          int x2261 = x2247;
                          if (x2261) {
                            char  *x2262 = x2249;
                            x1954 = 0;
                          } else {
                            char x2265 = x2248;
                            char  *x2266 = x2249;
                            int x2271 = 1/*true*/;
                            char x2272 = '\0';
                            char  *x2273 = 0/*null*/;
                            char x2267 = x2266[0];
                            int x2268 = x2267 == '\0';
                            if (x2268) {
                              x2273 = x2266;
                            } else {
                              int x2269 = x2267 == 'h';
                              if (x2269) {
                                x2271 = 0/*false*/;
                                x2272 = x2267;
                                char  *x2270 = x2266+1;
                                x2273 = x2270;
                              } else {
                                x2273 = x2266;
                              }
                            }
                            int x2285 = x2271;
                            if (x2285) {
                              char  *x2286 = x2273;
                              x1954 = 0;
                            } else {
                              char x2289 = x2272;
                              char  *x2290 = x2273;
                              x1954 = x2290;
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
  char  *x2320 = x1954;
  return x2320;
}
/*@
requires ((strlen(x2336)>=0) && \valid(x2336+(0..strlen(x2336))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_TransferEncoding(char  * x2336) {
  char  *x2338 = x2336;
  int x2343 = 1/*true*/;
  char x2344 = '\0';
  char  *x2345 = 0/*null*/;
  char x2339 = x2336[0];
  int x2340 = x2339 == '\0';
  if (x2340) {
    x2345 = x2336;
  } else {
    int x2341 = x2339 == 'T';
    if (x2341) {
      x2343 = 0/*false*/;
      x2344 = x2339;
      char  *x2342 = x2336+1;
      x2345 = x2342;
    } else {
      x2345 = x2336;
    }
  }
  int x2357 = x2343;
  if (x2357) {
    char  *x2358 = x2345;
    x2338 = 0;
  } else {
    char x2361 = x2344;
    char  *x2362 = x2345;
    int x2367 = 1/*true*/;
    char x2368 = '\0';
    char  *x2369 = 0/*null*/;
    char x2363 = x2362[0];
    int x2364 = x2363 == '\0';
    if (x2364) {
      x2369 = x2362;
    } else {
      int x2365 = x2363 == 'r';
      if (x2365) {
        x2367 = 0/*false*/;
        x2368 = x2363;
        char  *x2366 = x2362+1;
        x2369 = x2366;
      } else {
        x2369 = x2362;
      }
    }
    int x2381 = x2367;
    if (x2381) {
      char  *x2382 = x2369;
      x2338 = 0;
    } else {
      char x2385 = x2368;
      char  *x2386 = x2369;
      int x2391 = 1/*true*/;
      char x2392 = '\0';
      char  *x2393 = 0/*null*/;
      char x2387 = x2386[0];
      int x2388 = x2387 == '\0';
      if (x2388) {
        x2393 = x2386;
      } else {
        int x2389 = x2387 == 'a';
        if (x2389) {
          x2391 = 0/*false*/;
          x2392 = x2387;
          char  *x2390 = x2386+1;
          x2393 = x2390;
        } else {
          x2393 = x2386;
        }
      }
      int x2405 = x2391;
      if (x2405) {
        char  *x2406 = x2393;
        x2338 = 0;
      } else {
        char x2409 = x2392;
        char  *x2410 = x2393;
        int x2415 = 1/*true*/;
        char x2416 = '\0';
        char  *x2417 = 0/*null*/;
        char x2411 = x2410[0];
        int x2412 = x2411 == '\0';
        if (x2412) {
          x2417 = x2410;
        } else {
          int x2413 = x2411 == 'n';
          if (x2413) {
            x2415 = 0/*false*/;
            x2416 = x2411;
            char  *x2414 = x2410+1;
            x2417 = x2414;
          } else {
            x2417 = x2410;
          }
        }
        int x2429 = x2415;
        if (x2429) {
          char  *x2430 = x2417;
          x2338 = 0;
        } else {
          char x2433 = x2416;
          char  *x2434 = x2417;
          int x2439 = 1/*true*/;
          char x2440 = '\0';
          char  *x2441 = 0/*null*/;
          char x2435 = x2434[0];
          int x2436 = x2435 == '\0';
          if (x2436) {
            x2441 = x2434;
          } else {
            int x2437 = x2435 == 's';
            if (x2437) {
              x2439 = 0/*false*/;
              x2440 = x2435;
              char  *x2438 = x2434+1;
              x2441 = x2438;
            } else {
              x2441 = x2434;
            }
          }
          int x2453 = x2439;
          if (x2453) {
            char  *x2454 = x2441;
            x2338 = 0;
          } else {
            char x2457 = x2440;
            char  *x2458 = x2441;
            int x2463 = 1/*true*/;
            char x2464 = '\0';
            char  *x2465 = 0/*null*/;
            char x2459 = x2458[0];
            int x2460 = x2459 == '\0';
            if (x2460) {
              x2465 = x2458;
            } else {
              int x2461 = x2459 == 'f';
              if (x2461) {
                x2463 = 0/*false*/;
                x2464 = x2459;
                char  *x2462 = x2458+1;
                x2465 = x2462;
              } else {
                x2465 = x2458;
              }
            }
            int x2477 = x2463;
            if (x2477) {
              char  *x2478 = x2465;
              x2338 = 0;
            } else {
              char x2481 = x2464;
              char  *x2482 = x2465;
              int x2487 = 1/*true*/;
              char x2488 = '\0';
              char  *x2489 = 0/*null*/;
              char x2483 = x2482[0];
              int x2484 = x2483 == '\0';
              if (x2484) {
                x2489 = x2482;
              } else {
                int x2485 = x2483 == 'e';
                if (x2485) {
                  x2487 = 0/*false*/;
                  x2488 = x2483;
                  char  *x2486 = x2482+1;
                  x2489 = x2486;
                } else {
                  x2489 = x2482;
                }
              }
              int x2501 = x2487;
              if (x2501) {
                char  *x2502 = x2489;
                x2338 = 0;
              } else {
                char x2505 = x2488;
                char  *x2506 = x2489;
                int x2511 = 1/*true*/;
                char x2512 = '\0';
                char  *x2513 = 0/*null*/;
                char x2507 = x2506[0];
                int x2508 = x2507 == '\0';
                if (x2508) {
                  x2513 = x2506;
                } else {
                  int x2509 = x2507 == 'r';
                  if (x2509) {
                    x2511 = 0/*false*/;
                    x2512 = x2507;
                    char  *x2510 = x2506+1;
                    x2513 = x2510;
                  } else {
                    x2513 = x2506;
                  }
                }
                int x2525 = x2511;
                if (x2525) {
                  char  *x2526 = x2513;
                  x2338 = 0;
                } else {
                  char x2529 = x2512;
                  char  *x2530 = x2513;
                  int x2535 = 1/*true*/;
                  char x2536 = '\0';
                  char  *x2537 = 0/*null*/;
                  char x2531 = x2530[0];
                  int x2532 = x2531 == '\0';
                  if (x2532) {
                    x2537 = x2530;
                  } else {
                    int x2533 = x2531 == '-';
                    if (x2533) {
                      x2535 = 0/*false*/;
                      x2536 = x2531;
                      char  *x2534 = x2530+1;
                      x2537 = x2534;
                    } else {
                      x2537 = x2530;
                    }
                  }
                  int x2549 = x2535;
                  if (x2549) {
                    char  *x2550 = x2537;
                    x2338 = 0;
                  } else {
                    char x2553 = x2536;
                    char  *x2554 = x2537;
                    int x2559 = 1/*true*/;
                    char x2560 = '\0';
                    char  *x2561 = 0/*null*/;
                    char x2555 = x2554[0];
                    int x2556 = x2555 == '\0';
                    if (x2556) {
                      x2561 = x2554;
                    } else {
                      int x2557 = x2555 == 'E';
                      if (x2557) {
                        x2559 = 0/*false*/;
                        x2560 = x2555;
                        char  *x2558 = x2554+1;
                        x2561 = x2558;
                      } else {
                        x2561 = x2554;
                      }
                    }
                    int x2573 = x2559;
                    if (x2573) {
                      char  *x2574 = x2561;
                      x2338 = 0;
                    } else {
                      char x2577 = x2560;
                      char  *x2578 = x2561;
                      int x2583 = 1/*true*/;
                      char x2584 = '\0';
                      char  *x2585 = 0/*null*/;
                      char x2579 = x2578[0];
                      int x2580 = x2579 == '\0';
                      if (x2580) {
                        x2585 = x2578;
                      } else {
                        int x2581 = x2579 == 'n';
                        if (x2581) {
                          x2583 = 0/*false*/;
                          x2584 = x2579;
                          char  *x2582 = x2578+1;
                          x2585 = x2582;
                        } else {
                          x2585 = x2578;
                        }
                      }
                      int x2597 = x2583;
                      if (x2597) {
                        char  *x2598 = x2585;
                        x2338 = 0;
                      } else {
                        char x2601 = x2584;
                        char  *x2602 = x2585;
                        int x2607 = 1/*true*/;
                        char x2608 = '\0';
                        char  *x2609 = 0/*null*/;
                        char x2603 = x2602[0];
                        int x2604 = x2603 == '\0';
                        if (x2604) {
                          x2609 = x2602;
                        } else {
                          int x2605 = x2603 == 'c';
                          if (x2605) {
                            x2607 = 0/*false*/;
                            x2608 = x2603;
                            char  *x2606 = x2602+1;
                            x2609 = x2606;
                          } else {
                            x2609 = x2602;
                          }
                        }
                        int x2621 = x2607;
                        if (x2621) {
                          char  *x2622 = x2609;
                          x2338 = 0;
                        } else {
                          char x2625 = x2608;
                          char  *x2626 = x2609;
                          int x2631 = 1/*true*/;
                          char x2632 = '\0';
                          char  *x2633 = 0/*null*/;
                          char x2627 = x2626[0];
                          int x2628 = x2627 == '\0';
                          if (x2628) {
                            x2633 = x2626;
                          } else {
                            int x2629 = x2627 == 'o';
                            if (x2629) {
                              x2631 = 0/*false*/;
                              x2632 = x2627;
                              char  *x2630 = x2626+1;
                              x2633 = x2630;
                            } else {
                              x2633 = x2626;
                            }
                          }
                          int x2645 = x2631;
                          if (x2645) {
                            char  *x2646 = x2633;
                            x2338 = 0;
                          } else {
                            char x2649 = x2632;
                            char  *x2650 = x2633;
                            int x2655 = 1/*true*/;
                            char x2656 = '\0';
                            char  *x2657 = 0/*null*/;
                            char x2651 = x2650[0];
                            int x2652 = x2651 == '\0';
                            if (x2652) {
                              x2657 = x2650;
                            } else {
                              int x2653 = x2651 == 'd';
                              if (x2653) {
                                x2655 = 0/*false*/;
                                x2656 = x2651;
                                char  *x2654 = x2650+1;
                                x2657 = x2654;
                              } else {
                                x2657 = x2650;
                              }
                            }
                            int x2669 = x2655;
                            if (x2669) {
                              char  *x2670 = x2657;
                              x2338 = 0;
                            } else {
                              char x2673 = x2656;
                              char  *x2674 = x2657;
                              int x2679 = 1/*true*/;
                              char x2680 = '\0';
                              char  *x2681 = 0/*null*/;
                              char x2675 = x2674[0];
                              int x2676 = x2675 == '\0';
                              if (x2676) {
                                x2681 = x2674;
                              } else {
                                int x2677 = x2675 == 'i';
                                if (x2677) {
                                  x2679 = 0/*false*/;
                                  x2680 = x2675;
                                  char  *x2678 = x2674+1;
                                  x2681 = x2678;
                                } else {
                                  x2681 = x2674;
                                }
                              }
                              int x2693 = x2679;
                              if (x2693) {
                                char  *x2694 = x2681;
                                x2338 = 0;
                              } else {
                                char x2697 = x2680;
                                char  *x2698 = x2681;
                                int x2703 = 1/*true*/;
                                char x2704 = '\0';
                                char  *x2705 = 0/*null*/;
                                char x2699 = x2698[0];
                                int x2700 = x2699 == '\0';
                                if (x2700) {
                                  x2705 = x2698;
                                } else {
                                  int x2701 = x2699 == 'n';
                                  if (x2701) {
                                    x2703 = 0/*false*/;
                                    x2704 = x2699;
                                    char  *x2702 = x2698+1;
                                    x2705 = x2702;
                                  } else {
                                    x2705 = x2698;
                                  }
                                }
                                int x2717 = x2703;
                                if (x2717) {
                                  char  *x2718 = x2705;
                                  x2338 = 0;
                                } else {
                                  char x2721 = x2704;
                                  char  *x2722 = x2705;
                                  int x2727 = 1/*true*/;
                                  char x2728 = '\0';
                                  char  *x2729 = 0/*null*/;
                                  char x2723 = x2722[0];
                                  int x2724 = x2723 == '\0';
                                  if (x2724) {
                                    x2729 = x2722;
                                  } else {
                                    int x2725 = x2723 == 'g';
                                    if (x2725) {
                                      x2727 = 0/*false*/;
                                      x2728 = x2723;
                                      char  *x2726 = x2722+1;
                                      x2729 = x2726;
                                    } else {
                                      x2729 = x2722;
                                    }
                                  }
                                  int x2741 = x2727;
                                  if (x2741) {
                                    char  *x2742 = x2729;
                                    x2338 = 0;
                                  } else {
                                    char x2745 = x2728;
                                    char  *x2746 = x2729;
                                    x2338 = x2746;
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
  char  *x2782 = x2338;
  return x2782;
}
/*@
requires ((strlen(x2798)>=0) && \valid(x2798+(0..strlen(x2798))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_chunked(char  * x2798) {
  char  *x2800 = x2798;
  int x2805 = 1/*true*/;
  char x2806 = '\0';
  char  *x2807 = 0/*null*/;
  char x2801 = x2798[0];
  int x2802 = x2801 == '\0';
  if (x2802) {
    x2807 = x2798;
  } else {
    int x2803 = x2801 == 'c';
    if (x2803) {
      x2805 = 0/*false*/;
      x2806 = x2801;
      char  *x2804 = x2798+1;
      x2807 = x2804;
    } else {
      x2807 = x2798;
    }
  }
  int x2819 = x2805;
  if (x2819) {
    char  *x2820 = x2807;
    x2800 = 0;
  } else {
    char x2823 = x2806;
    char  *x2824 = x2807;
    int x2829 = 1/*true*/;
    char x2830 = '\0';
    char  *x2831 = 0/*null*/;
    char x2825 = x2824[0];
    int x2826 = x2825 == '\0';
    if (x2826) {
      x2831 = x2824;
    } else {
      int x2827 = x2825 == 'h';
      if (x2827) {
        x2829 = 0/*false*/;
        x2830 = x2825;
        char  *x2828 = x2824+1;
        x2831 = x2828;
      } else {
        x2831 = x2824;
      }
    }
    int x2843 = x2829;
    if (x2843) {
      char  *x2844 = x2831;
      x2800 = 0;
    } else {
      char x2847 = x2830;
      char  *x2848 = x2831;
      int x2853 = 1/*true*/;
      char x2854 = '\0';
      char  *x2855 = 0/*null*/;
      char x2849 = x2848[0];
      int x2850 = x2849 == '\0';
      if (x2850) {
        x2855 = x2848;
      } else {
        int x2851 = x2849 == 'u';
        if (x2851) {
          x2853 = 0/*false*/;
          x2854 = x2849;
          char  *x2852 = x2848+1;
          x2855 = x2852;
        } else {
          x2855 = x2848;
        }
      }
      int x2867 = x2853;
      if (x2867) {
        char  *x2868 = x2855;
        x2800 = 0;
      } else {
        char x2871 = x2854;
        char  *x2872 = x2855;
        int x2877 = 1/*true*/;
        char x2878 = '\0';
        char  *x2879 = 0/*null*/;
        char x2873 = x2872[0];
        int x2874 = x2873 == '\0';
        if (x2874) {
          x2879 = x2872;
        } else {
          int x2875 = x2873 == 'n';
          if (x2875) {
            x2877 = 0/*false*/;
            x2878 = x2873;
            char  *x2876 = x2872+1;
            x2879 = x2876;
          } else {
            x2879 = x2872;
          }
        }
        int x2891 = x2877;
        if (x2891) {
          char  *x2892 = x2879;
          x2800 = 0;
        } else {
          char x2895 = x2878;
          char  *x2896 = x2879;
          int x2901 = 1/*true*/;
          char x2902 = '\0';
          char  *x2903 = 0/*null*/;
          char x2897 = x2896[0];
          int x2898 = x2897 == '\0';
          if (x2898) {
            x2903 = x2896;
          } else {
            int x2899 = x2897 == 'k';
            if (x2899) {
              x2901 = 0/*false*/;
              x2902 = x2897;
              char  *x2900 = x2896+1;
              x2903 = x2900;
            } else {
              x2903 = x2896;
            }
          }
          int x2915 = x2901;
          if (x2915) {
            char  *x2916 = x2903;
            x2800 = 0;
          } else {
            char x2919 = x2902;
            char  *x2920 = x2903;
            int x2925 = 1/*true*/;
            char x2926 = '\0';
            char  *x2927 = 0/*null*/;
            char x2921 = x2920[0];
            int x2922 = x2921 == '\0';
            if (x2922) {
              x2927 = x2920;
            } else {
              int x2923 = x2921 == 'e';
              if (x2923) {
                x2925 = 0/*false*/;
                x2926 = x2921;
                char  *x2924 = x2920+1;
                x2927 = x2924;
              } else {
                x2927 = x2920;
              }
            }
            int x2939 = x2925;
            if (x2939) {
              char  *x2940 = x2927;
              x2800 = 0;
            } else {
              char x2943 = x2926;
              char  *x2944 = x2927;
              int x2949 = 1/*true*/;
              char x2950 = '\0';
              char  *x2951 = 0/*null*/;
              char x2945 = x2944[0];
              int x2946 = x2945 == '\0';
              if (x2946) {
                x2951 = x2944;
              } else {
                int x2947 = x2945 == 'd';
                if (x2947) {
                  x2949 = 0/*false*/;
                  x2950 = x2945;
                  char  *x2948 = x2944+1;
                  x2951 = x2948;
                } else {
                  x2951 = x2944;
                }
              }
              int x2963 = x2949;
              if (x2963) {
                char  *x2964 = x2951;
                x2800 = 0;
              } else {
                char x2967 = x2950;
                char  *x2968 = x2951;
                x2800 = x2968;
              }
            }
          }
        }
      }
    }
  }
  char  *x2984 = x2800;
  return x2984;
}
