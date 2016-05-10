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
        int x404 = x398 == '\n';
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
      int x445 = 1/*true*/;
      char x446 = '\0';
      char  *x447 = 0/*null*/;
      char x441 = x440[0];
      int x442 = x441 == '\0';
      if (x442) {
        x447 = x440;
      } else {
        int x443 = x441 == '\n';
        if (x443) {
          x445 = 0/*false*/;
          x446 = x441;
          char  *x444 = x440+1;
          x447 = x444;
        } else {
          x447 = x440;
        }
      }
      int x459 = x445;
      if (x459) {
        char  *x460 = x447;
        x13 = x460;
      } else {
        char x463 = x446;
        char  *x464 = x447;
        x11 = 0/*false*/;
        x12 = x391;
        x13 = x464;
      }
    }
  }
  int x474 = x11;
  if (x474) {
    char  *x475 = x13;
    x10 = x475;
  } else {
    int x478 = x12;
    char  *x479 = x13;
    char  *x480 = x479;
    int x481 = 1/*true*/;
    int x482 = 0;
    int x343 = INT_MAX;
    int x344 = x343 / 10;
    int x345 = x344 - 10;
    int x1011 = -2 == -2;
    /*@
    loop invariant ((strlen(x480)>=0) && \valid(x480+(0..(strlen(x480)+1)-1)));
    loop assigns x480, x481, x482;
    */
    for (;;) {
      int x483 = x481;
      if (!x483) break;
      char  *x485 = x480;
      char  *x486 = p_ContentLength(x485);
      int x488 = 1/*true*/;
      int x489 = 0;
      char  *x490 = 0/*null*/;
      int x491 = 1/*true*/;
      int x492 = 0;
      char  *x493 = 0/*null*/;
      int x494 = 1/*true*/;
      int x495 = 0;
      char  *x496 = 0/*null*/;
      int x497 = 1/*true*/;
      int x498 = 0;
      char  *x499 = 0/*null*/;
      int x500 = 1/*true*/;
      int x501 = 0;
      char  *x502 = 0/*null*/;
      int x503 = 1/*true*/;
      char  *x505 = 0/*null*/;
      int x506 = 0 == x486;
      if (x506) {
        x505 = x485;
      } else {
        x503 = 0/*false*/;
        x505 = x486;
      }
      int x514 = x503;
      if (x514) {
        char  *x515 = x505;
      } else {
        char  *x518 = x505;
        x500 = 0/*false*/;
        x501 = 1;
        x502 = x518;
      }
      int x524 = x500;
      if (x524) {
        char  *x525 = x485;
        int x526 = 1/*true*/;
        /*@
        loop invariant ((strlen(x525)>=0) && \valid(x525+(0..(strlen(x525)+1)-1)));
        loop assigns x525, x526;
        */
        for (;;) {
          int x527 = x526;
          if (!x527) break;
          char  *x529 = x525;
          int x540 = 1/*true*/;
          char x541 = '\0';
          char  *x542 = 0/*null*/;
          char x530 = x529[0];
          int x531 = x530 == '\0';
          if (x531) {
          } else {
            int x532 = x530 >= 'a';
            int x534;
            if (x532) {
              int x533 = x530 <= 'z';
              x534 = x533;
            } else {
              x534 = 0/*false*/;
            }
            int x535 = x530 >= 'A';
            int x537;
            if (x535) {
              int x536 = x530 <= 'Z';
              x537 = x536;
            } else {
              x537 = 0/*false*/;
            }
            int x538 = x534 || x537;
            if (x538) {
              x540 = 0/*false*/;
              x541 = x530;
              char  *x539 = x529+1;
              x542 = x539;
            } else {
            }
          }
          int x550 = x540;
          char x552 = x541;
          char  *x553 = x542;
          if (x550) {
            if (x531) {
              x526 = 0/*false*/;
            } else {
              int x551 = x530 == '-';
              if (x551) {
                char  *x539 = x529+1;
                x525 = x539;
              } else {
                x526 = 0/*false*/;
              }
            }
          } else {
            x525 = x553;
          }
        }
        char  *x583 = x525;
        x497 = 0/*false*/;
        x498 = 0;
        x499 = x583;
      } else {
        int x588 = x501;
        char  *x589 = x502;
        x497 = 0/*false*/;
        x498 = x588;
        x499 = x589;
      }
      int x595 = x497;
      if (x595) {
        char  *x596 = x499;
        x496 = x596;
      } else {
        int x599 = x498;
        char  *x600 = x499;
        char  *x601 = x600;
        int x602 = 1/*true*/;
        /*@
        loop invariant ((strlen(x601)>=0) && \valid(x601+(0..(strlen(x601)+1)-1)));
        loop assigns x601, x602;
        */
        for (;;) {
          int x603 = x602;
          if (!x603) break;
          char  *x605 = x601;
          char x606 = x605[0];
          int x607 = x606 == '\0';
          if (x607) {
            x602 = 0/*false*/;
          } else {
            int x608 = x606 == ' ';
            if (x608) {
              char  *x609 = x605+1;
              x601 = x609;
            } else {
              x602 = 0/*false*/;
            }
          }
        }
        char  *x635 = x601;
        x494 = 0/*false*/;
        x495 = x599;
        x496 = x635;
      }
      int x641 = x494;
      if (x641) {
        char  *x642 = x496;
        x493 = x642;
      } else {
        int x645 = x495;
        char  *x646 = x496;
        int x651 = 1/*true*/;
        char x652 = '\0';
        char  *x653 = 0/*null*/;
        char x647 = x646[0];
        int x648 = x647 == '\0';
        if (x648) {
          x653 = x646;
        } else {
          int x649 = x647 == ':';
          if (x649) {
            x651 = 0/*false*/;
            x652 = x647;
            char  *x650 = x646+1;
            x653 = x650;
          } else {
            x653 = x646;
          }
        }
        int x665 = x651;
        if (x665) {
          char  *x666 = x653;
          x493 = x666;
        } else {
          char x669 = x652;
          char  *x670 = x653;
          x491 = 0/*false*/;
          x492 = x645;
          x493 = x670;
        }
      }
      int x678 = x491;
      if (x678) {
        char  *x679 = x493;
        x490 = x679;
      } else {
        int x682 = x492;
        char  *x683 = x493;
        char  *x684 = x683;
        int x685 = 1/*true*/;
        /*@
        loop invariant ((strlen(x684)>=0) && \valid(x684+(0..(strlen(x684)+1)-1)));
        loop assigns x684, x685;
        */
        for (;;) {
          int x686 = x685;
          if (!x686) break;
          char  *x688 = x684;
          char x689 = x688[0];
          int x690 = x689 == '\0';
          if (x690) {
            x685 = 0/*false*/;
          } else {
            int x691 = x689 == ' ';
            if (x691) {
              char  *x692 = x688+1;
              x684 = x692;
            } else {
              x685 = 0/*false*/;
            }
          }
        }
        char  *x718 = x684;
        x488 = 0/*false*/;
        x489 = x682;
        x490 = x718;
      }
      int x724 = x488;
      if (x724) {
        char  *x725 = x490;
        x481 = 0/*false*/;
      } else {
        int x728 = x489;
        char  *x729 = x490;
        char  *x737 = x729;
        int x738 = 1/*true*/;
        /*@
        loop invariant ((strlen(x737)>=0) && \valid(x737+(0..(strlen(x737)+1)-1)));
        loop assigns x737, x738;
        */
        for (;;) {
          int x739 = x738;
          if (!x739) break;
          char  *x741 = x737;
          char x742 = x741[0];
          int x743 = x742 == '\0';
          if (x743) {
            x738 = 0/*false*/;
          } else {
            int x748 = x742 == '\n';
            if (x748) {
              x738 = 0/*false*/;
            } else {
              char  *x745 = x741+1;
              x737 = x745;
            }
          }
        }
        char  *x772 = x737;
        int x730 = x728 == 1;
        if (x730) {
          int x773 = 1/*true*/;
          int x774 = 0;
          char  *x775 = 0/*null*/;
          int x776 = 1/*true*/;
          int x777 = 0;
          char  *x778 = 0/*null*/;
          int x779 = 1/*true*/;
          int x780 = 0;
          char  *x781 = 0/*null*/;
          int x782 = 1/*true*/;
          char x783 = '\0';
          char  *x784 = 0/*null*/;
          char x731 = x729[0];
          int x732 = x731 == '\0';
          if (x732) {
            x784 = x729;
          } else {
            int x733 = x731 >= '0';
            int x735;
            if (x733) {
              int x734 = x731 <= '9';
              x735 = x734;
            } else {
              x735 = 0/*false*/;
            }
            if (x735) {
              x782 = 0/*false*/;
              x783 = x731;
              char  *x736 = x729+1;
              x784 = x736;
            } else {
              x784 = x729;
            }
          }
          int x796 = x782;
          if (x796) {
            char  *x797 = x784;
            x781 = x797;
          } else {
            char x800 = x783;
            char  *x802 = x784;
            x779 = 0/*false*/;
            char x801 = x800 - '0';
            x780 = x801;
            x781 = x802;
          }
          int x808 = x779;
          if (x808) {
            char  *x809 = x781;
            x778 = x809;
          } else {
            int x812 = x780;
            char  *x813 = x781;
            char  *x814 = x813;
            int x815 = 1/*true*/;
            int x816 = x812;
            /*@
            loop invariant (((strlen(x814)>=0) && \valid(x814+(0..(strlen(x814)+1)-1))) && ((x816==-1) || (0<=x816)));
            loop assigns x814, x815, x816;
            */
            for (;;) {
              int x817 = x815;
              if (!x817) break;
              char  *x819 = x814;
              int x826 = 1/*true*/;
              char x827 = '\0';
              char  *x828 = 0/*null*/;
              char x820 = x819[0];
              int x821 = x820 == '\0';
              if (x821) {
                x828 = x819;
              } else {
                int x822 = x820 >= '0';
                int x824;
                if (x822) {
                  int x823 = x820 <= '9';
                  x824 = x823;
                } else {
                  x824 = 0/*false*/;
                }
                if (x824) {
                  x826 = 0/*false*/;
                  x827 = x820;
                  char  *x825 = x819+1;
                  x828 = x825;
                } else {
                  x828 = x819;
                }
              }
              int x840 = x826;
              if (x840) {
                char  *x841 = x828;
                x815 = 0/*false*/;
              } else {
                char x844 = x827;
                char  *x846 = x828;
                int x847 = x816;
                int x848 = x847 < 0;
                int x853;
                if (x848) {
                  x853 = x847;
                } else {
                  int x849 = x847 > x345;
                  int x852;
                  if (x849) {
                    x852 = -1;
                  } else {
                    char x845 = x844 - '0';
                    int x850 = x847 * 10;
                    int x851 = x850 + x845;
                    x852 = x851;
                  }
                  x853 = x852;
                }
                x816 = x853;
                x814 = x846;
              }
            }
            int x881 = x816;
            char  *x882 = x814;
            x776 = 0/*false*/;
            x777 = x881;
            x778 = x882;
          }
          int x888 = x776;
          if (x888) {
            char  *x889 = x778;
            x775 = x889;
          } else {
            int x892 = x777;
            char  *x893 = x778;
            char  *x894 = x893;
            int x895 = 1/*true*/;
            /*@
            loop invariant ((strlen(x894)>=0) && \valid(x894+(0..(strlen(x894)+1)-1)));
            loop assigns x894, x895;
            */
            for (;;) {
              int x896 = x895;
              if (!x896) break;
              char  *x898 = x894;
              char x899 = x898[0];
              int x900 = x899 == '\0';
              if (x900) {
                x895 = 0/*false*/;
              } else {
                int x901 = x899 == ' ';
                if (x901) {
                  char  *x902 = x898+1;
                  x894 = x902;
                } else {
                  x895 = 0/*false*/;
                }
              }
            }
            char  *x928 = x894;
            x773 = 0/*false*/;
            x774 = x892;
            x775 = x928;
          }
          int x934 = x773;
          if (x934) {
            char  *x935 = x775;
            x481 = 0/*false*/;
          } else {
            int x938 = x774;
            char  *x939 = x775;
            int x944 = 1/*true*/;
            char x945 = '\0';
            char  *x946 = 0/*null*/;
            char x940 = x939[0];
            int x941 = x940 == '\0';
            if (x941) {
              x946 = x939;
            } else {
              int x942 = x940 == '\n';
              if (x942) {
                x944 = 0/*false*/;
                x945 = x940;
                char  *x943 = x939+1;
                x946 = x943;
              } else {
                x946 = x939;
              }
            }
            int x958 = x944;
            if (x958) {
              char  *x959 = x946;
              x481 = 0/*false*/;
            } else {
              char x962 = x945;
              char  *x963 = x946;
              int x964 = x482;
              int x965 = x938 == -2;
              int x966;
              if (x965) {
                x966 = x964;
              } else {
                x966 = x938;
              }
              x482 = x966;
              x480 = x963;
            }
          }
        } else {
          int x974 = 1/*true*/;
          char  *x976 = 0/*null*/;
          x974 = 0/*false*/;
          x976 = x772;
          int x980 = x974;
          if (x980) {
            char  *x981 = x976;
            x481 = 0/*false*/;
          } else {
            char  *x985 = x976;
            int x990 = 1/*true*/;
            char x991 = '\0';
            char  *x992 = 0/*null*/;
            char x986 = x985[0];
            int x987 = x986 == '\0';
            if (x987) {
              x992 = x985;
            } else {
              int x988 = x986 == '\n';
              if (x988) {
                x990 = 0/*false*/;
                x991 = x986;
                char  *x989 = x985+1;
                x992 = x989;
              } else {
                x992 = x985;
              }
            }
            int x1004 = x990;
            if (x1004) {
              char  *x1005 = x992;
              x481 = 0/*false*/;
            } else {
              char x1008 = x991;
              char  *x1009 = x992;
              int x1010 = x482;
              int x1012;
              if (x1011) {
                x1012 = x1010;
              } else {
                x1012 = -2;
              }
              x482 = x1012;
              x480 = x1009;
            }
          }
        }
      }
    }
    int x1041 = x482;
    char  *x1042 = x480;
    x8 = 0/*false*/;
    x9 = x1041;
    x10 = x1042;
  }
  int x1048 = x8;
  if (x1048) {
    char  *x1049 = x10;
    x7 = x1049;
  } else {
    int x1052 = x9;
    char  *x1053 = x10;
    int x1058 = 1/*true*/;
    char x1059 = '\0';
    char  *x1060 = 0/*null*/;
    char x1054 = x1053[0];
    int x1055 = x1054 == '\0';
    if (x1055) {
      x1060 = x1053;
    } else {
      int x1056 = x1054 == '\n';
      if (x1056) {
        x1058 = 0/*false*/;
        x1059 = x1054;
        char  *x1057 = x1053+1;
        x1060 = x1057;
      } else {
        x1060 = x1053;
      }
    }
    int x1072 = x1058;
    if (x1072) {
      char  *x1073 = x1060;
      x7 = x1073;
    } else {
      char x1076 = x1059;
      char  *x1077 = x1060;
      x5 = 0/*false*/;
      x6 = x1052;
      x7 = x1077;
    }
  }
  int x1085 = x5;
  if (x1085) {
    char  *x1086 = x7;
  } else {
    int x1088 = x6;
    char  *x1089 = x7;
    int x1091 = 1/*true*/;
    char  *x1092 = x1089;
    /*@
    loop invariant ((0<=x1094) && ((strlen(x1092)>=0) && \valid(x1092+(0..(strlen(x1092)+1)-1))));
    loop assigns x1094, x1091, x1092;
    loop variant (x1088-x1094);
    */
    for(int x1094=0; x1094 < x1088; x1094++) {
      int x1095 = x1091;
      if (x1095) {
        char  *x1096 = x1092;
        char x1097 = x1096[0];
        int x1098 = x1097 == '\0';
        if (x1098) {
          x1091 = 0/*false*/;
        } else {
          char  *x1099 = x1096+1;
          x1092 = x1099;
        }
      } else {
      }
    }
    int x1128 = x1091;
    char  *x1129 = x1092;
    int x1090 = x1088 < 0;
    if (x1090) {
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
        x1135 = x1089;
      }
      int x1143 = x1133;
      if (x1143) {
        char  *x1144 = x1135;
        x1132 = x1144;
      } else {
        char  *x1148 = x1135;
        x1130 = 0/*false*/;
        x1131 = x1088;
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
