#include <limits.h>
#include <string.h>
char  * p_HTTP(char  * x1126);
char  * p_(char  * x1128);
char  * p_ContentLength(char  * x1130);
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
      loop invariant ((strlen(x72)>=0) && \valid(x72+(0..(strlen(x72)+1)-1)));
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
      char  *x108 = x72;
      x26 = 0/*false*/;
      x28 = x108;
    }
  }
  int x116 = x26;
  if (x116) {
    char  *x117 = x28;
    x25 = x117;
  } else {
    char  *x121 = x28;
    char x122 = x121[0];
    int x123 = x122 == '\0';
    if (x123) {
      x25 = x121;
    } else {
      int x124 = x122 == '.';
      if (x124) {
        x23 = 0/*false*/;
        x24 = x122;
        char  *x125 = x121+1;
        x25 = x125;
      } else {
        x25 = x121;
      }
    }
  }
  int x139 = x23;
  if (x139) {
    char  *x140 = x25;
    x22 = x140;
  } else {
    char x143 = x24;
    char  *x144 = x25;
    int x151 = 1/*true*/;
    char x152 = '\0';
    char  *x153 = 0/*null*/;
    char x145 = x144[0];
    int x146 = x145 == '\0';
    if (x146) {
      x153 = x144;
    } else {
      int x147 = x145 >= '0';
      int x149;
      if (x147) {
        int x148 = x145 <= '9';
        x149 = x148;
      } else {
        x149 = 0/*false*/;
      }
      if (x149) {
        x151 = 0/*false*/;
        x152 = x145;
        char  *x150 = x144+1;
        x153 = x150;
      } else {
        x153 = x144;
      }
    }
    int x165 = x151;
    if (x165) {
      char  *x166 = x153;
      x22 = x166;
    } else {
      char x169 = x152;
      char  *x170 = x153;
      char  *x171 = x170;
      int x172 = 1/*true*/;
      /*@
      loop invariant ((strlen(x171)>=0) && \valid(x171+(0..(strlen(x171)+1)-1)));
      loop assigns x171, x172;
      */
      for (;;) {
        int x173 = x172;
        if (!x173) break;
        char  *x175 = x171;
        char x176 = x175[0];
        int x177 = x176 == '\0';
        if (x177) {
          x172 = 0/*false*/;
        } else {
          int x178 = x176 >= '0';
          int x180;
          if (x178) {
            int x179 = x176 <= '9';
            x180 = x179;
          } else {
            x180 = 0/*false*/;
          }
          if (x180) {
            char  *x181 = x175+1;
            x171 = x181;
          } else {
            x172 = 0/*false*/;
          }
        }
      }
      char  *x207 = x171;
      x20 = 0/*false*/;
      x22 = x207;
    }
  }
  int x215 = x20;
  if (x215) {
    char  *x216 = x22;
    x19 = x216;
  } else {
    char  *x220 = x22;
    char  *x221 = x220;
    int x222 = 1/*true*/;
    /*@
    loop invariant ((strlen(x221)>=0) && \valid(x221+(0..(strlen(x221)+1)-1)));
    loop assigns x221, x222;
    */
    for (;;) {
      int x223 = x222;
      if (!x223) break;
      char  *x225 = x221;
      char x226 = x225[0];
      int x227 = x226 == '\0';
      if (x227) {
        x222 = 0/*false*/;
      } else {
        int x228 = x226 == ' ';
        if (x228) {
          char  *x229 = x225+1;
          x221 = x229;
        } else {
          x222 = 0/*false*/;
        }
      }
    }
    char  *x255 = x221;
    x17 = 0/*false*/;
    x19 = x255;
  }
  int x261 = x17;
  if (x261) {
    char  *x262 = x19;
    x16 = x262;
  } else {
    char  *x266 = x19;
    int x273 = 1/*true*/;
    int x274 = 0;
    char  *x275 = 0/*null*/;
    int x276 = 1/*true*/;
    char x277 = '\0';
    char  *x278 = 0/*null*/;
    char x267 = x266[0];
    int x268 = x267 == '\0';
    if (x268) {
      x278 = x266;
    } else {
      int x269 = x267 >= '0';
      int x271;
      if (x269) {
        int x270 = x267 <= '9';
        x271 = x270;
      } else {
        x271 = 0/*false*/;
      }
      if (x271) {
        x276 = 0/*false*/;
        x277 = x267;
        char  *x272 = x266+1;
        x278 = x272;
      } else {
        x278 = x266;
      }
    }
    int x290 = x276;
    if (x290) {
      char  *x291 = x278;
      x275 = x291;
    } else {
      char x294 = x277;
      char  *x296 = x278;
      x273 = 0/*false*/;
      char x295 = x294 - '0';
      x274 = x295;
      x275 = x296;
    }
    int x302 = x273;
    if (x302) {
      char  *x303 = x275;
      x16 = x303;
    } else {
      int x306 = x274;
      char  *x307 = x275;
      char  *x308 = x307;
      int x309 = 1/*true*/;
      int x310 = x306;
      int x343 = INT_MAX;
      int x344 = x343 / 10;
      int x345 = x344 - 10;
      /*@
      loop invariant (((strlen(x308)>=0) && \valid(x308+(0..(strlen(x308)+1)-1))) && ((x310==-1) || (0<=x310)));
      loop assigns x308, x309, x310;
      */
      for (;;) {
        int x311 = x309;
        if (!x311) break;
        char  *x313 = x308;
        int x320 = 1/*true*/;
        char x321 = '\0';
        char  *x322 = 0/*null*/;
        char x314 = x313[0];
        int x315 = x314 == '\0';
        if (x315) {
          x322 = x313;
        } else {
          int x316 = x314 >= '0';
          int x318;
          if (x316) {
            int x317 = x314 <= '9';
            x318 = x317;
          } else {
            x318 = 0/*false*/;
          }
          if (x318) {
            x320 = 0/*false*/;
            x321 = x314;
            char  *x319 = x313+1;
            x322 = x319;
          } else {
            x322 = x313;
          }
        }
        int x334 = x320;
        if (x334) {
          char  *x335 = x322;
          x309 = 0/*false*/;
        } else {
          char x338 = x321;
          char  *x340 = x322;
          int x341 = x310;
          int x342 = x341 < 0;
          int x350;
          if (x342) {
            x350 = x341;
          } else {
            int x346 = x341 > x345;
            int x349;
            if (x346) {
              x349 = -1;
            } else {
              char x339 = x338 - '0';
              int x347 = x341 * 10;
              int x348 = x347 + x339;
              x349 = x348;
            }
            x350 = x349;
          }
          x310 = x350;
          x308 = x340;
        }
      }
      int x378 = x310;
      char  *x379 = x308;
      x14 = 0/*false*/;
      x15 = x378;
      x16 = x379;
    }
  }
  int x387 = x14;
  if (x387) {
    char  *x388 = x16;
    x13 = x388;
  } else {
    int x391 = x15;
    char  *x392 = x16;
    char  *x393 = x392;
    int x394 = 1/*true*/;
    /*@
    loop invariant ((strlen(x393)>=0) && \valid(x393+(0..(strlen(x393)+1)-1)));
    loop assigns x393, x394;
    */
    for (;;) {
      int x395 = x394;
      if (!x395) break;
      char  *x397 = x393;
      char x398 = x397[0];
      int x399 = x398 == '\0';
      if (x399) {
        x394 = 0/*false*/;
      } else {
        int x404 = x398 == '\r';
        if (x404) {
          x394 = 0/*false*/;
        } else {
          char  *x401 = x397+1;
          x393 = x401;
        }
      }
    }
    char  *x428 = x393;
    int x429 = 1/*true*/;
    char  *x431 = 0/*null*/;
    x429 = 0/*false*/;
    x431 = x428;
    int x435 = x429;
    if (x435) {
      char  *x436 = x431;
      x13 = x436;
    } else {
      char  *x440 = x431;
      char  *x441 = p_(x440);
      int x443 = 1/*true*/;
      char  *x445 = 0/*null*/;
      int x446 = 0 == x441;
      if (x446) {
        x445 = x440;
      } else {
        x443 = 0/*false*/;
        x445 = x441;
      }
      int x454 = x443;
      if (x454) {
        char  *x455 = x445;
        x13 = x455;
      } else {
        char  *x459 = x445;
        x11 = 0/*false*/;
        x12 = x391;
        x13 = x459;
      }
    }
  }
  int x469 = x11;
  if (x469) {
    char  *x470 = x13;
    x10 = x470;
  } else {
    int x473 = x12;
    char  *x474 = x13;
    char  *x475 = x474;
    int x476 = 1/*true*/;
    int x477 = 0;
    int x343 = INT_MAX;
    int x344 = x343 / 10;
    int x345 = x344 - 10;
    int x975 = -2 == -2;
    /*@
    loop invariant ((strlen(x475)>=0) && \valid(x475+(0..(strlen(x475)+1)-1)));
    loop assigns x475, x476, x477;
    */
    for (;;) {
      int x478 = x476;
      if (!x478) break;
      char  *x480 = x475;
      char  *x481 = p_ContentLength(x480);
      int x483 = 1/*true*/;
      int x484 = 0;
      char  *x485 = 0/*null*/;
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
      char  *x500 = 0/*null*/;
      int x501 = 0 == x481;
      if (x501) {
        x500 = x480;
      } else {
        x498 = 0/*false*/;
        x500 = x481;
      }
      int x509 = x498;
      if (x509) {
        char  *x510 = x500;
      } else {
        char  *x513 = x500;
        x495 = 0/*false*/;
        x496 = 1;
        x497 = x513;
      }
      int x519 = x495;
      if (x519) {
        char  *x520 = x480;
        int x521 = 1/*true*/;
        /*@
        loop invariant ((strlen(x520)>=0) && \valid(x520+(0..(strlen(x520)+1)-1)));
        loop assigns x520, x521;
        */
        for (;;) {
          int x522 = x521;
          if (!x522) break;
          char  *x524 = x520;
          char x525 = x524[0];
          int x526 = x525 == '\0';
          if (x526) {
            x521 = 0/*false*/;
          } else {
            int x528 = x525 == ':';
            int x530;
            if (x528) {
              x530 = 0/*false*/;
            } else {
              int x529 = x525 != ' ';
              x530 = x529;
            }
            if (x530) {
              char  *x531 = x524+1;
              x520 = x531;
            } else {
              x521 = 0/*false*/;
            }
          }
        }
        char  *x557 = x520;
        x492 = 0/*false*/;
        x493 = 0;
        x494 = x557;
      } else {
        int x562 = x496;
        char  *x563 = x497;
        x492 = 0/*false*/;
        x493 = x562;
        x494 = x563;
      }
      int x569 = x492;
      if (x569) {
        char  *x570 = x494;
        x491 = x570;
      } else {
        int x573 = x493;
        char  *x574 = x494;
        char  *x575 = x574;
        int x576 = 1/*true*/;
        /*@
        loop invariant ((strlen(x575)>=0) && \valid(x575+(0..(strlen(x575)+1)-1)));
        loop assigns x575, x576;
        */
        for (;;) {
          int x577 = x576;
          if (!x577) break;
          char  *x579 = x575;
          char x580 = x579[0];
          int x581 = x580 == '\0';
          if (x581) {
            x576 = 0/*false*/;
          } else {
            int x582 = x580 == ' ';
            if (x582) {
              char  *x583 = x579+1;
              x575 = x583;
            } else {
              x576 = 0/*false*/;
            }
          }
        }
        char  *x609 = x575;
        x489 = 0/*false*/;
        x490 = x573;
        x491 = x609;
      }
      int x615 = x489;
      if (x615) {
        char  *x616 = x491;
        x488 = x616;
      } else {
        int x619 = x490;
        char  *x620 = x491;
        int x625 = 1/*true*/;
        char x626 = '\0';
        char  *x627 = 0/*null*/;
        char x621 = x620[0];
        int x622 = x621 == '\0';
        if (x622) {
          x627 = x620;
        } else {
          int x623 = x621 == ':';
          if (x623) {
            x625 = 0/*false*/;
            x626 = x621;
            char  *x624 = x620+1;
            x627 = x624;
          } else {
            x627 = x620;
          }
        }
        int x639 = x625;
        if (x639) {
          char  *x640 = x627;
          x488 = x640;
        } else {
          char x643 = x626;
          char  *x644 = x627;
          x486 = 0/*false*/;
          x487 = x619;
          x488 = x644;
        }
      }
      int x652 = x486;
      if (x652) {
        char  *x653 = x488;
        x485 = x653;
      } else {
        int x656 = x487;
        char  *x657 = x488;
        char  *x658 = x657;
        int x659 = 1/*true*/;
        /*@
        loop invariant ((strlen(x658)>=0) && \valid(x658+(0..(strlen(x658)+1)-1)));
        loop assigns x658, x659;
        */
        for (;;) {
          int x660 = x659;
          if (!x660) break;
          char  *x662 = x658;
          char x663 = x662[0];
          int x664 = x663 == '\0';
          if (x664) {
            x659 = 0/*false*/;
          } else {
            int x665 = x663 == ' ';
            if (x665) {
              char  *x666 = x662+1;
              x658 = x666;
            } else {
              x659 = 0/*false*/;
            }
          }
        }
        char  *x692 = x658;
        x483 = 0/*false*/;
        x484 = x656;
        x485 = x692;
      }
      int x698 = x483;
      if (x698) {
        char  *x699 = x485;
        x476 = 0/*false*/;
      } else {
        int x702 = x484;
        char  *x703 = x485;
        char  *x711 = x703;
        int x712 = 1/*true*/;
        /*@
        loop invariant ((strlen(x711)>=0) && \valid(x711+(0..(strlen(x711)+1)-1)));
        loop assigns x711, x712;
        */
        for (;;) {
          int x713 = x712;
          if (!x713) break;
          char  *x715 = x711;
          char x716 = x715[0];
          int x717 = x716 == '\0';
          if (x717) {
            x712 = 0/*false*/;
          } else {
            int x722 = x716 == '\r';
            if (x722) {
              x712 = 0/*false*/;
            } else {
              char  *x719 = x715+1;
              x711 = x719;
            }
          }
        }
        char  *x746 = x711;
        int x704 = x702 == 1;
        if (x704) {
          int x747 = 1/*true*/;
          int x748 = 0;
          char  *x749 = 0/*null*/;
          int x750 = 1/*true*/;
          int x751 = 0;
          char  *x752 = 0/*null*/;
          int x753 = 1/*true*/;
          int x754 = 0;
          char  *x755 = 0/*null*/;
          int x756 = 1/*true*/;
          char x757 = '\0';
          char  *x758 = 0/*null*/;
          char x705 = x703[0];
          int x706 = x705 == '\0';
          if (x706) {
            x758 = x703;
          } else {
            int x707 = x705 >= '0';
            int x709;
            if (x707) {
              int x708 = x705 <= '9';
              x709 = x708;
            } else {
              x709 = 0/*false*/;
            }
            if (x709) {
              x756 = 0/*false*/;
              x757 = x705;
              char  *x710 = x703+1;
              x758 = x710;
            } else {
              x758 = x703;
            }
          }
          int x770 = x756;
          if (x770) {
            char  *x771 = x758;
            x755 = x771;
          } else {
            char x774 = x757;
            char  *x776 = x758;
            x753 = 0/*false*/;
            char x775 = x774 - '0';
            x754 = x775;
            x755 = x776;
          }
          int x782 = x753;
          if (x782) {
            char  *x783 = x755;
            x752 = x783;
          } else {
            int x786 = x754;
            char  *x787 = x755;
            char  *x788 = x787;
            int x789 = 1/*true*/;
            int x790 = x786;
            /*@
            loop invariant (((strlen(x788)>=0) && \valid(x788+(0..(strlen(x788)+1)-1))) && ((x790==-1) || (0<=x790)));
            loop assigns x788, x789, x790;
            */
            for (;;) {
              int x791 = x789;
              if (!x791) break;
              char  *x793 = x788;
              int x800 = 1/*true*/;
              char x801 = '\0';
              char  *x802 = 0/*null*/;
              char x794 = x793[0];
              int x795 = x794 == '\0';
              if (x795) {
                x802 = x793;
              } else {
                int x796 = x794 >= '0';
                int x798;
                if (x796) {
                  int x797 = x794 <= '9';
                  x798 = x797;
                } else {
                  x798 = 0/*false*/;
                }
                if (x798) {
                  x800 = 0/*false*/;
                  x801 = x794;
                  char  *x799 = x793+1;
                  x802 = x799;
                } else {
                  x802 = x793;
                }
              }
              int x814 = x800;
              if (x814) {
                char  *x815 = x802;
                x789 = 0/*false*/;
              } else {
                char x818 = x801;
                char  *x820 = x802;
                int x821 = x790;
                int x822 = x821 < 0;
                int x827;
                if (x822) {
                  x827 = x821;
                } else {
                  int x823 = x821 > x345;
                  int x826;
                  if (x823) {
                    x826 = -1;
                  } else {
                    char x819 = x818 - '0';
                    int x824 = x821 * 10;
                    int x825 = x824 + x819;
                    x826 = x825;
                  }
                  x827 = x826;
                }
                x790 = x827;
                x788 = x820;
              }
            }
            int x855 = x790;
            char  *x856 = x788;
            x750 = 0/*false*/;
            x751 = x855;
            x752 = x856;
          }
          int x862 = x750;
          if (x862) {
            char  *x863 = x752;
            x749 = x863;
          } else {
            int x866 = x751;
            char  *x867 = x752;
            char  *x868 = x867;
            int x869 = 1/*true*/;
            /*@
            loop invariant ((strlen(x868)>=0) && \valid(x868+(0..(strlen(x868)+1)-1)));
            loop assigns x868, x869;
            */
            for (;;) {
              int x870 = x869;
              if (!x870) break;
              char  *x872 = x868;
              char x873 = x872[0];
              int x874 = x873 == '\0';
              if (x874) {
                x869 = 0/*false*/;
              } else {
                int x875 = x873 == ' ';
                if (x875) {
                  char  *x876 = x872+1;
                  x868 = x876;
                } else {
                  x869 = 0/*false*/;
                }
              }
            }
            char  *x902 = x868;
            x747 = 0/*false*/;
            x748 = x866;
            x749 = x902;
          }
          int x908 = x747;
          if (x908) {
            char  *x909 = x749;
            x476 = 0/*false*/;
          } else {
            int x912 = x748;
            char  *x913 = x749;
            char  *x914 = p_(x913);
            int x916 = 1/*true*/;
            char  *x918 = 0/*null*/;
            int x919 = 0 == x914;
            if (x919) {
              x918 = x913;
            } else {
              x916 = 0/*false*/;
              x918 = x914;
            }
            int x927 = x916;
            if (x927) {
              char  *x928 = x918;
              x476 = 0/*false*/;
            } else {
              char  *x932 = x918;
              int x933 = x477;
              int x934 = x912 == -2;
              int x935;
              if (x934) {
                x935 = x933;
              } else {
                x935 = x912;
              }
              x477 = x935;
              x475 = x932;
            }
          }
        } else {
          int x943 = 1/*true*/;
          char  *x945 = 0/*null*/;
          x943 = 0/*false*/;
          x945 = x746;
          int x949 = x943;
          if (x949) {
            char  *x950 = x945;
            x476 = 0/*false*/;
          } else {
            char  *x954 = x945;
            char  *x955 = p_(x954);
            int x957 = 1/*true*/;
            char  *x959 = 0/*null*/;
            int x960 = 0 == x955;
            if (x960) {
              x959 = x954;
            } else {
              x957 = 0/*false*/;
              x959 = x955;
            }
            int x968 = x957;
            if (x968) {
              char  *x969 = x959;
              x476 = 0/*false*/;
            } else {
              char  *x973 = x959;
              int x974 = x477;
              int x976;
              if (x975) {
                x976 = x974;
              } else {
                x976 = -2;
              }
              x477 = x976;
              x475 = x973;
            }
          }
        }
      }
    }
    int x1005 = x477;
    char  *x1006 = x475;
    x8 = 0/*false*/;
    x9 = x1005;
    x10 = x1006;
  }
  int x1012 = x8;
  if (x1012) {
    char  *x1013 = x10;
    x7 = x1013;
  } else {
    int x1016 = x9;
    char  *x1017 = x10;
    char  *x1018 = p_(x1017);
    int x1020 = 1/*true*/;
    char  *x1022 = 0/*null*/;
    int x1023 = 0 == x1018;
    if (x1023) {
      x1022 = x1017;
    } else {
      x1020 = 0/*false*/;
      x1022 = x1018;
    }
    int x1031 = x1020;
    if (x1031) {
      char  *x1032 = x1022;
      x7 = x1032;
    } else {
      char  *x1036 = x1022;
      x5 = 0/*false*/;
      x6 = x1016;
      x7 = x1036;
    }
  }
  int x1044 = x5;
  if (x1044) {
    char  *x1045 = x7;
  } else {
    int x1047 = x6;
    char  *x1048 = x7;
    int x1050 = 1/*true*/;
    char  *x1051 = x1048;
    /*@
    loop invariant ((0<=x1053) && ((strlen(x1051)>=0) && \valid(x1051+(0..(strlen(x1051)+1)-1))));
    loop assigns x1053, x1050, x1051;
    loop variant (x1047-x1053);
    */
    for(int x1053=0; x1053 < x1047; x1053++) {
      int x1054 = x1050;
      if (x1054) {
        char  *x1055 = x1051;
        char x1056 = x1055[0];
        int x1057 = x1056 == '\0';
        if (x1057) {
          x1050 = 0/*false*/;
        } else {
          char  *x1058 = x1055+1;
          x1051 = x1058;
        }
      } else {
      }
    }
    int x1087 = x1050;
    char  *x1088 = x1051;
    int x1049 = x1047 < 0;
    if (x1049) {
    } else {
      int x1089 = 1/*true*/;
      char  *x1091 = 0/*null*/;
      if (x1087) {
        x1089 = 0/*false*/;
        x1091 = x1088;
      } else {
        x1091 = x1048;
      }
      int x1099 = x1089;
      if (x1099) {
        char  *x1100 = x1091;
      } else {
        char  *x1103 = x1091;
        char x1104 = x1103[0];
        int x1105 = x1104 == '\0';
        if (x1105) {
          x2 = x1047;
        } else {
        }
      }
    }
  }
  int x1115 = x2;
  return x1115;
}
/*@
requires ((strlen(x1132)>=0) && \valid(x1132+(0..(strlen(x1132)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_HTTP(char  * x1132) {
  char  *x1134 = x1132;
  int x1139 = 1/*true*/;
  char x1140 = '\0';
  char  *x1141 = 0/*null*/;
  char x1135 = x1132[0];
  int x1136 = x1135 == '\0';
  if (x1136) {
    x1141 = x1132;
  } else {
    int x1137 = x1135 == 'H';
    if (x1137) {
      x1139 = 0/*false*/;
      x1140 = x1135;
      char  *x1138 = x1132+1;
      x1141 = x1138;
    } else {
      x1141 = x1132;
    }
  }
  int x1153 = x1139;
  if (x1153) {
    char  *x1154 = x1141;
    x1134 = 0;
  } else {
    char x1157 = x1140;
    char  *x1158 = x1141;
    int x1163 = 1/*true*/;
    char x1164 = '\0';
    char  *x1165 = 0/*null*/;
    char x1159 = x1158[0];
    int x1160 = x1159 == '\0';
    if (x1160) {
      x1165 = x1158;
    } else {
      int x1161 = x1159 == 'T';
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
      x1134 = 0;
    } else {
      char x1181 = x1164;
      char  *x1182 = x1165;
      int x1187 = 1/*true*/;
      char x1188 = '\0';
      char  *x1189 = 0/*null*/;
      char x1183 = x1182[0];
      int x1184 = x1183 == '\0';
      if (x1184) {
        x1189 = x1182;
      } else {
        int x1185 = x1183 == 'T';
        if (x1185) {
          x1187 = 0/*false*/;
          x1188 = x1183;
          char  *x1186 = x1182+1;
          x1189 = x1186;
        } else {
          x1189 = x1182;
        }
      }
      int x1201 = x1187;
      if (x1201) {
        char  *x1202 = x1189;
        x1134 = 0;
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
          int x1209 = x1207 == 'P';
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
          x1134 = 0;
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
            int x1233 = x1231 == '/';
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
            x1134 = 0;
          } else {
            char x1253 = x1236;
            char  *x1254 = x1237;
            x1134 = x1254;
          }
        }
      }
    }
  }
  char  *x1266 = x1134;
  return x1266;
}
/*@
requires ((strlen(x1288)>=0) && \valid(x1288+(0..(strlen(x1288)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_(char  * x1288) {
  char  *x1290 = x1288;
  int x1295 = 1/*true*/;
  char x1296 = '\0';
  char  *x1297 = 0/*null*/;
  char x1291 = x1288[0];
  int x1292 = x1291 == '\0';
  if (x1292) {
    x1297 = x1288;
  } else {
    int x1293 = x1291 == '\r';
    if (x1293) {
      x1295 = 0/*false*/;
      x1296 = x1291;
      char  *x1294 = x1288+1;
      x1297 = x1294;
    } else {
      x1297 = x1288;
    }
  }
  int x1309 = x1295;
  if (x1309) {
    char  *x1310 = x1297;
    x1290 = 0;
  } else {
    char x1313 = x1296;
    char  *x1314 = x1297;
    int x1319 = 1/*true*/;
    char x1320 = '\0';
    char  *x1321 = 0/*null*/;
    char x1315 = x1314[0];
    int x1316 = x1315 == '\0';
    if (x1316) {
      x1321 = x1314;
    } else {
      int x1317 = x1315 == '\n';
      if (x1317) {
        x1319 = 0/*false*/;
        x1320 = x1315;
        char  *x1318 = x1314+1;
        x1321 = x1318;
      } else {
        x1321 = x1314;
      }
    }
    int x1333 = x1319;
    if (x1333) {
      char  *x1334 = x1321;
      x1290 = 0;
    } else {
      char x1337 = x1320;
      char  *x1338 = x1321;
      x1290 = x1338;
    }
  }
  char  *x1344 = x1290;
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
