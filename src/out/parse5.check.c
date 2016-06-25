#include <limits.h>
#include <string.h>
char  * p_chunked(char  * x1637);
char  * p_(char  * x1639);
char  * p_TransferEncoding(char  * x1641);
char  * p_ContentLength(char  * x1643);
char  * p_HTTP(char  * x1645);
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..(strlen(x0)+1)-1)));
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
      \valid(x72+(0..(strlen(x72)+1)-1)));
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
      loop invariant ((strlen(x171)>=0) &&
      \valid(x171+(0..(strlen(x171)+1)-1)));
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
    loop invariant ((strlen(x221)>=0) &&
    \valid(x221+(0..(strlen(x221)+1)-1)));
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
      loop invariant (((strlen(x308)>=0) &&
      \valid(x308+(0..(strlen(x308)+1)-1))) &&
      ((x310==-1) || (0<=x310)));
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
    loop invariant ((strlen(x393)>=0) &&
    \valid(x393+(0..(strlen(x393)+1)-1)));
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
    int x1122 = -2 == -2;
    /*@
    loop invariant ((strlen(x475)>=0) &&
    \valid(x475+(0..(strlen(x475)+1)-1)));
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
      int x499 = 0;
      char  *x500 = 0/*null*/;
      int x501 = 1/*true*/;
      char  *x503 = 0/*null*/;
      int x504 = 0 == x481;
      if (x504) {
        x503 = x480;
      } else {
        x501 = 0/*false*/;
        x503 = x481;
      }
      int x512 = x501;
      if (x512) {
        char  *x513 = x503;
      } else {
        char  *x516 = x503;
        x498 = 0/*false*/;
        x499 = 1;
        x500 = x516;
      }
      int x522 = x498;
      if (x522) {
        char  *x523 = p_TransferEncoding(x480);
        int x525 = 1/*true*/;
        char  *x527 = 0/*null*/;
        int x528 = 0 == x523;
        if (x528) {
          x527 = x480;
        } else {
          x525 = 0/*false*/;
          x527 = x523;
        }
        int x536 = x525;
        if (x536) {
          char  *x537 = x527;
        } else {
          char  *x540 = x527;
          x495 = 0/*false*/;
          x496 = 2;
          x497 = x540;
        }
      } else {
        int x547 = x499;
        char  *x548 = x500;
        x495 = 0/*false*/;
        x496 = x547;
        x497 = x548;
      }
      int x554 = x495;
      if (x554) {
        char  *x555 = x480;
        int x556 = 1/*true*/;
        /*@
        loop invariant ((strlen(x555)>=0) &&
        \valid(x555+(0..(strlen(x555)+1)-1)));
        loop assigns x555, x556;
        */
        for (;;) {
          int x557 = x556;
          if (!x557) break;
          char  *x559 = x555;
          char x560 = x559[0];
          int x561 = x560 == '\0';
          if (x561) {
            x556 = 0/*false*/;
          } else {
            int x563 = x560 == ':';
            int x565;
            if (x563) {
              x565 = 0/*false*/;
            } else {
              int x564 = x560 != ' ';
              x565 = x564;
            }
            if (x565) {
              char  *x566 = x559+1;
              x555 = x566;
            } else {
              x556 = 0/*false*/;
            }
          }
        }
        char  *x592 = x555;
        x492 = 0/*false*/;
        x493 = 0;
        x494 = x592;
      } else {
        int x597 = x496;
        char  *x598 = x497;
        x492 = 0/*false*/;
        x493 = x597;
        x494 = x598;
      }
      int x604 = x492;
      if (x604) {
        char  *x605 = x494;
        x491 = x605;
      } else {
        int x608 = x493;
        char  *x609 = x494;
        char  *x610 = x609;
        int x611 = 1/*true*/;
        /*@
        loop invariant ((strlen(x610)>=0) &&
        \valid(x610+(0..(strlen(x610)+1)-1)));
        loop assigns x610, x611;
        */
        for (;;) {
          int x612 = x611;
          if (!x612) break;
          char  *x614 = x610;
          char x615 = x614[0];
          int x616 = x615 == '\0';
          if (x616) {
            x611 = 0/*false*/;
          } else {
            int x617 = x615 == ' ';
            if (x617) {
              char  *x618 = x614+1;
              x610 = x618;
            } else {
              x611 = 0/*false*/;
            }
          }
        }
        char  *x644 = x610;
        x489 = 0/*false*/;
        x490 = x608;
        x491 = x644;
      }
      int x650 = x489;
      if (x650) {
        char  *x651 = x491;
        x488 = x651;
      } else {
        int x654 = x490;
        char  *x655 = x491;
        int x660 = 1/*true*/;
        char x661 = '\0';
        char  *x662 = 0/*null*/;
        char x656 = x655[0];
        int x657 = x656 == '\0';
        if (x657) {
          x662 = x655;
        } else {
          int x658 = x656 == ':';
          if (x658) {
            x660 = 0/*false*/;
            x661 = x656;
            char  *x659 = x655+1;
            x662 = x659;
          } else {
            x662 = x655;
          }
        }
        int x674 = x660;
        if (x674) {
          char  *x675 = x662;
          x488 = x675;
        } else {
          char x678 = x661;
          char  *x679 = x662;
          x486 = 0/*false*/;
          x487 = x654;
          x488 = x679;
        }
      }
      int x687 = x486;
      if (x687) {
        char  *x688 = x488;
        x485 = x688;
      } else {
        int x691 = x487;
        char  *x692 = x488;
        char  *x693 = x692;
        int x694 = 1/*true*/;
        /*@
        loop invariant ((strlen(x693)>=0) &&
        \valid(x693+(0..(strlen(x693)+1)-1)));
        loop assigns x693, x694;
        */
        for (;;) {
          int x695 = x694;
          if (!x695) break;
          char  *x697 = x693;
          char x698 = x697[0];
          int x699 = x698 == '\0';
          if (x699) {
            x694 = 0/*false*/;
          } else {
            int x700 = x698 == ' ';
            if (x700) {
              char  *x701 = x697+1;
              x693 = x701;
            } else {
              x694 = 0/*false*/;
            }
          }
        }
        char  *x727 = x693;
        x483 = 0/*false*/;
        x484 = x691;
        x485 = x727;
      }
      int x733 = x483;
      if (x733) {
        char  *x734 = x485;
        x476 = 0/*false*/;
      } else {
        int x737 = x484;
        char  *x738 = x485;
        char  *x740 = p_chunked(x738);
        char  *x749 = x738;
        int x750 = 1/*true*/;
        /*@
        loop invariant ((strlen(x749)>=0) &&
        \valid(x749+(0..(strlen(x749)+1)-1)));
        loop assigns x749, x750;
        */
        for (;;) {
          int x751 = x750;
          if (!x751) break;
          char  *x753 = x749;
          char x754 = x753[0];
          int x755 = x754 == '\0';
          if (x755) {
            x750 = 0/*false*/;
          } else {
            int x760 = x754 == '\r';
            if (x760) {
              x750 = 0/*false*/;
            } else {
              char  *x757 = x753+1;
              x749 = x757;
            }
          }
        }
        char  *x784 = x749;
        int x739 = x737 == 2;
        if (x739) {
          int x785 = 1/*true*/;
          int x786 = 0;
          char  *x787 = 0/*null*/;
          int x788 = 1/*true*/;
          int x789 = 0;
          char  *x790 = 0/*null*/;
          int x791 = 1/*true*/;
          char  *x793 = 0/*null*/;
          int x794 = 0 == x740;
          if (x794) {
            x793 = x738;
          } else {
            x791 = 0/*false*/;
            x793 = x740;
          }
          int x802 = x791;
          if (x802) {
            char  *x803 = x793;
            x790 = x803;
          } else {
            char  *x807 = x793;
            x788 = 0/*false*/;
            x789 = -3;
            x790 = x807;
          }
          int x813 = x788;
          if (x813) {
            char  *x814 = x790;
            x787 = x814;
          } else {
            int x817 = x789;
            char  *x818 = x790;
            char  *x819 = x818;
            int x820 = 1/*true*/;
            /*@
            loop invariant ((strlen(x819)>=0) &&
            \valid(x819+(0..(strlen(x819)+1)-1)));
            loop assigns x819, x820;
            */
            for (;;) {
              int x821 = x820;
              if (!x821) break;
              char  *x823 = x819;
              char x824 = x823[0];
              int x825 = x824 == '\0';
              if (x825) {
                x820 = 0/*false*/;
              } else {
                int x826 = x824 == ' ';
                if (x826) {
                  char  *x827 = x823+1;
                  x819 = x827;
                } else {
                  x820 = 0/*false*/;
                }
              }
            }
            char  *x853 = x819;
            x785 = 0/*false*/;
            x786 = x817;
            x787 = x853;
          }
          int x859 = x785;
          if (x859) {
            char  *x860 = x787;
            x476 = 0/*false*/;
          } else {
            int x863 = x786;
            char  *x864 = x787;
            char  *x865 = p_(x864);
            int x867 = 1/*true*/;
            char  *x869 = 0/*null*/;
            int x870 = 0 == x865;
            if (x870) {
              x869 = x864;
            } else {
              x867 = 0/*false*/;
              x869 = x865;
            }
            int x878 = x867;
            if (x878) {
              char  *x879 = x869;
              x476 = 0/*false*/;
            } else {
              char  *x883 = x869;
              int x884 = x477;
              int x885 = x863 == -2;
              int x886;
              if (x885) {
                x886 = x884;
              } else {
                x886 = x863;
              }
              x477 = x886;
              x475 = x883;
            }
          }
        } else {
          int x742 = x737 == 1;
          if (x742) {
            int x894 = 1/*true*/;
            int x895 = 0;
            char  *x896 = 0/*null*/;
            int x897 = 1/*true*/;
            int x898 = 0;
            char  *x899 = 0/*null*/;
            int x900 = 1/*true*/;
            int x901 = 0;
            char  *x902 = 0/*null*/;
            int x903 = 1/*true*/;
            char x904 = '\0';
            char  *x905 = 0/*null*/;
            char x743 = x738[0];
            int x744 = x743 == '\0';
            if (x744) {
              x905 = x738;
            } else {
              int x745 = x743 >= '0';
              int x747;
              if (x745) {
                int x746 = x743 <= '9';
                x747 = x746;
              } else {
                x747 = 0/*false*/;
              }
              if (x747) {
                x903 = 0/*false*/;
                x904 = x743;
                char  *x748 = x738+1;
                x905 = x748;
              } else {
                x905 = x738;
              }
            }
            int x917 = x903;
            if (x917) {
              char  *x918 = x905;
              x902 = x918;
            } else {
              char x921 = x904;
              char  *x923 = x905;
              x900 = 0/*false*/;
              char x922 = x921 - '0';
              x901 = x922;
              x902 = x923;
            }
            int x929 = x900;
            if (x929) {
              char  *x930 = x902;
              x899 = x930;
            } else {
              int x933 = x901;
              char  *x934 = x902;
              char  *x935 = x934;
              int x936 = 1/*true*/;
              int x937 = x933;
              /*@
              loop invariant (((strlen(x935)>=0) &&
              \valid(x935+(0..(strlen(x935)+1)-1))) &&
              ((x937==-1) || (0<=x937)));
              loop assigns x935, x936, x937;
              */
              for (;;) {
                int x938 = x936;
                if (!x938) break;
                char  *x940 = x935;
                int x947 = 1/*true*/;
                char x948 = '\0';
                char  *x949 = 0/*null*/;
                char x941 = x940[0];
                int x942 = x941 == '\0';
                if (x942) {
                  x949 = x940;
                } else {
                  int x943 = x941 >= '0';
                  int x945;
                  if (x943) {
                    int x944 = x941 <= '9';
                    x945 = x944;
                  } else {
                    x945 = 0/*false*/;
                  }
                  if (x945) {
                    x947 = 0/*false*/;
                    x948 = x941;
                    char  *x946 = x940+1;
                    x949 = x946;
                  } else {
                    x949 = x940;
                  }
                }
                int x961 = x947;
                if (x961) {
                  char  *x962 = x949;
                  x936 = 0/*false*/;
                } else {
                  char x965 = x948;
                  char  *x967 = x949;
                  int x968 = x937;
                  int x969 = x968 < 0;
                  int x974;
                  if (x969) {
                    x974 = x968;
                  } else {
                    int x970 = x968 > x345;
                    int x973;
                    if (x970) {
                      x973 = -1;
                    } else {
                      char x966 = x965 - '0';
                      int x971 = x968 * 10;
                      int x972 = x971 + x966;
                      x973 = x972;
                    }
                    x974 = x973;
                  }
                  x937 = x974;
                  x935 = x967;
                }
              }
              int x1002 = x937;
              char  *x1003 = x935;
              x897 = 0/*false*/;
              x898 = x1002;
              x899 = x1003;
            }
            int x1009 = x897;
            if (x1009) {
              char  *x1010 = x899;
              x896 = x1010;
            } else {
              int x1013 = x898;
              char  *x1014 = x899;
              char  *x1015 = x1014;
              int x1016 = 1/*true*/;
              /*@
              loop invariant ((strlen(x1015)>=0) &&
              \valid(x1015+(0..(strlen(x1015)+1)-1)));
              loop assigns x1015, x1016;
              */
              for (;;) {
                int x1017 = x1016;
                if (!x1017) break;
                char  *x1019 = x1015;
                char x1020 = x1019[0];
                int x1021 = x1020 == '\0';
                if (x1021) {
                  x1016 = 0/*false*/;
                } else {
                  int x1022 = x1020 == ' ';
                  if (x1022) {
                    char  *x1023 = x1019+1;
                    x1015 = x1023;
                  } else {
                    x1016 = 0/*false*/;
                  }
                }
              }
              char  *x1049 = x1015;
              x894 = 0/*false*/;
              x895 = x1013;
              x896 = x1049;
            }
            int x1055 = x894;
            if (x1055) {
              char  *x1056 = x896;
              x476 = 0/*false*/;
            } else {
              int x1059 = x895;
              char  *x1060 = x896;
              char  *x1061 = p_(x1060);
              int x1063 = 1/*true*/;
              char  *x1065 = 0/*null*/;
              int x1066 = 0 == x1061;
              if (x1066) {
                x1065 = x1060;
              } else {
                x1063 = 0/*false*/;
                x1065 = x1061;
              }
              int x1074 = x1063;
              if (x1074) {
                char  *x1075 = x1065;
                x476 = 0/*false*/;
              } else {
                char  *x1079 = x1065;
                int x1080 = x477;
                int x1081 = x1059 == -2;
                int x1082;
                if (x1081) {
                  x1082 = x1080;
                } else {
                  x1082 = x1059;
                }
                x477 = x1082;
                x475 = x1079;
              }
            }
          } else {
            int x1090 = 1/*true*/;
            char  *x1092 = 0/*null*/;
            x1090 = 0/*false*/;
            x1092 = x784;
            int x1096 = x1090;
            if (x1096) {
              char  *x1097 = x1092;
              x476 = 0/*false*/;
            } else {
              char  *x1101 = x1092;
              char  *x1102 = p_(x1101);
              int x1104 = 1/*true*/;
              char  *x1106 = 0/*null*/;
              int x1107 = 0 == x1102;
              if (x1107) {
                x1106 = x1101;
              } else {
                x1104 = 0/*false*/;
                x1106 = x1102;
              }
              int x1115 = x1104;
              if (x1115) {
                char  *x1116 = x1106;
                x476 = 0/*false*/;
              } else {
                char  *x1120 = x1106;
                int x1121 = x477;
                int x1123;
                if (x1122) {
                  x1123 = x1121;
                } else {
                  x1123 = -2;
                }
                x477 = x1123;
                x475 = x1120;
              }
            }
          }
        }
      }
    }
    int x1154 = x477;
    char  *x1155 = x475;
    x8 = 0/*false*/;
    x9 = x1154;
    x10 = x1155;
  }
  int x1161 = x8;
  if (x1161) {
    char  *x1162 = x10;
    x7 = x1162;
  } else {
    int x1165 = x9;
    char  *x1166 = x10;
    char  *x1167 = p_(x1166);
    int x1169 = 1/*true*/;
    char  *x1171 = 0/*null*/;
    int x1172 = 0 == x1167;
    if (x1172) {
      x1171 = x1166;
    } else {
      x1169 = 0/*false*/;
      x1171 = x1167;
    }
    int x1180 = x1169;
    if (x1180) {
      char  *x1181 = x1171;
      x7 = x1181;
    } else {
      char  *x1185 = x1171;
      x5 = 0/*false*/;
      x6 = x1165;
      x7 = x1185;
    }
  }
  int x1193 = x5;
  if (x1193) {
    char  *x1194 = x7;
  } else {
    int x1196 = x6;
    char  *x1197 = x7;
    char  *x1199 = x1197;
    int x1200 = 1/*true*/;
    int x1201 = 0;
    int x343 = INT_MAX;
    int x1361 = x343 / 16;
    int x1362 = x1361 - 16;
    /*@
    loop invariant (((strlen(x1199)>=0) &&
    \valid(x1199+(0..(strlen(x1199)+1)-1))) &&
    ((x1201==-1) || (0<=x1201)));
    loop assigns x1199, x1200, x1201;
    */
    for (;;) {
      int x1202 = x1200;
      if (!x1202) break;
      char  *x1204 = x1199;
      int x1211 = 1/*true*/;
      int x1212 = 0;
      char  *x1213 = 0/*null*/;
      int x1214 = 1/*true*/;
      int x1215 = 0;
      char  *x1216 = 0/*null*/;
      int x1217 = 1/*true*/;
      int x1218 = 0;
      char  *x1219 = 0/*null*/;
      int x1220 = 1/*true*/;
      int x1221 = 0;
      char  *x1222 = 0/*null*/;
      int x1223 = 1/*true*/;
      char x1224 = '\0';
      char  *x1225 = 0/*null*/;
      char x1205 = x1204[0];
      int x1206 = x1205 == '\0';
      if (x1206) {
        x1225 = x1204;
      } else {
        int x1207 = x1205 >= '0';
        int x1209;
        if (x1207) {
          int x1208 = x1205 <= '9';
          x1209 = x1208;
        } else {
          x1209 = 0/*false*/;
        }
        if (x1209) {
          x1223 = 0/*false*/;
          x1224 = x1205;
          char  *x1210 = x1204+1;
          x1225 = x1210;
        } else {
          x1225 = x1204;
        }
      }
      int x1237 = x1223;
      if (x1237) {
        char  *x1238 = x1225;
      } else {
        char x1240 = x1224;
        char  *x1242 = x1225;
        x1220 = 0/*false*/;
        char x1241 = x1240 - '0';
        x1221 = x1241;
        x1222 = x1242;
      }
      int x1248 = x1220;
      if (x1248) {
        int x1252 = 1/*true*/;
        char x1253 = '\0';
        char  *x1254 = 0/*null*/;
        if (x1206) {
          x1254 = x1204;
        } else {
          int x1249 = x1205 >= 'a';
          int x1251;
          if (x1249) {
            int x1250 = x1205 <= 'f';
            x1251 = x1250;
          } else {
            x1251 = 0/*false*/;
          }
          if (x1251) {
            x1252 = 0/*false*/;
            x1253 = x1205;
            char  *x1210 = x1204+1;
            x1254 = x1210;
          } else {
            x1254 = x1204;
          }
        }
        int x1266 = x1252;
        if (x1266) {
          char  *x1267 = x1254;
          x1219 = x1267;
        } else {
          char x1270 = x1253;
          char  *x1273 = x1254;
          x1217 = 0/*false*/;
          char x1271 = x1270 - 'a';
          int x1272 = 10 + x1271;
          x1218 = x1272;
          x1219 = x1273;
        }
      } else {
        int x1280 = x1221;
        char  *x1281 = x1222;
        x1217 = 0/*false*/;
        x1218 = x1280;
        x1219 = x1281;
      }
      int x1287 = x1217;
      if (x1287) {
        char  *x1288 = x1219;
        x1216 = x1288;
      } else {
        int x1291 = x1218;
        char  *x1292 = x1219;
        char  *x1293 = x1292;
        int x1294 = 1/*true*/;
        int x1295 = x1291;
        /*@
        loop invariant (((strlen(x1293)>=0) &&
        \valid(x1293+(0..(strlen(x1293)+1)-1))) &&
        ((x1295==-1) || (0<=x1295)));
        loop assigns x1293, x1294, x1295;
        */
        for (;;) {
          int x1296 = x1294;
          if (!x1296) break;
          char  *x1298 = x1293;
          int x1305 = 1/*true*/;
          int x1306 = 0;
          char  *x1307 = 0/*null*/;
          int x1308 = 1/*true*/;
          char x1309 = '\0';
          char  *x1310 = 0/*null*/;
          char x1299 = x1298[0];
          int x1300 = x1299 == '\0';
          if (x1300) {
            x1310 = x1298;
          } else {
            int x1301 = x1299 >= '0';
            int x1303;
            if (x1301) {
              int x1302 = x1299 <= '9';
              x1303 = x1302;
            } else {
              x1303 = 0/*false*/;
            }
            if (x1303) {
              x1308 = 0/*false*/;
              x1309 = x1299;
              char  *x1304 = x1298+1;
              x1310 = x1304;
            } else {
              x1310 = x1298;
            }
          }
          int x1322 = x1308;
          if (x1322) {
            char  *x1323 = x1310;
          } else {
            char x1325 = x1309;
            char  *x1327 = x1310;
            x1305 = 0/*false*/;
            char x1326 = x1325 - '0';
            x1306 = x1326;
            x1307 = x1327;
          }
          int x1333 = x1305;
          if (x1333) {
            int x1337 = 1/*true*/;
            char x1338 = '\0';
            char  *x1339 = 0/*null*/;
            if (x1300) {
              x1339 = x1298;
            } else {
              int x1334 = x1299 >= 'a';
              int x1336;
              if (x1334) {
                int x1335 = x1299 <= 'f';
                x1336 = x1335;
              } else {
                x1336 = 0/*false*/;
              }
              if (x1336) {
                x1337 = 0/*false*/;
                x1338 = x1299;
                char  *x1304 = x1298+1;
                x1339 = x1304;
              } else {
                x1339 = x1298;
              }
            }
            int x1351 = x1337;
            if (x1351) {
              char  *x1352 = x1339;
              x1294 = 0/*false*/;
            } else {
              char x1355 = x1338;
              char  *x1358 = x1339;
              int x1359 = x1295;
              int x1360 = x1359 < 0;
              int x1367;
              if (x1360) {
                x1367 = x1359;
              } else {
                int x1363 = x1359 > x1362;
                int x1366;
                if (x1363) {
                  x1366 = -1;
                } else {
                  char x1356 = x1355 - 'a';
                  int x1357 = 10 + x1356;
                  int x1364 = x1359 * 16;
                  int x1365 = x1364 + x1357;
                  x1366 = x1365;
                }
                x1367 = x1366;
              }
              x1295 = x1367;
              x1293 = x1358;
            }
          } else {
            int x1373 = x1306;
            char  *x1374 = x1307;
            int x1375 = x1295;
            int x1376 = x1375 < 0;
            int x1381;
            if (x1376) {
              x1381 = x1375;
            } else {
              int x1377 = x1375 > x1362;
              int x1380;
              if (x1377) {
                x1380 = -1;
              } else {
                int x1378 = x1375 * 16;
                int x1379 = x1378 + x1373;
                x1380 = x1379;
              }
              x1381 = x1380;
            }
            x1295 = x1381;
            x1293 = x1374;
          }
        }
        int x1409 = x1295;
        char  *x1410 = x1293;
        x1214 = 0/*false*/;
        x1215 = x1409;
        x1216 = x1410;
      }
      int x1416 = x1214;
      if (x1416) {
        char  *x1417 = x1216;
        x1213 = x1417;
      } else {
        int x1420 = x1215;
        char  *x1421 = x1216;
        char  *x1422 = p_(x1421);
        int x1424 = 1/*true*/;
        char  *x1426 = 0/*null*/;
        int x1427 = 0 == x1422;
        if (x1427) {
          x1426 = x1421;
        } else {
          x1424 = 0/*false*/;
          x1426 = x1422;
        }
        int x1435 = x1424;
        if (x1435) {
          char  *x1436 = x1426;
          x1213 = x1436;
        } else {
          char  *x1440 = x1426;
          x1211 = 0/*false*/;
          x1212 = x1420;
          x1213 = x1440;
        }
      }
      int x1448 = x1211;
      if (x1448) {
        char  *x1449 = x1213;
        x1200 = 0/*false*/;
      } else {
        int x1452 = x1212;
        char  *x1453 = x1213;
        int x1455 = 1/*true*/;
        char  *x1456 = x1453;
        /*@
        loop invariant ((0<=x1458) &&
        ((strlen(x1456)>=0) &&
        \valid(x1456+(0..(strlen(x1456)+1)-1))));
        loop assigns x1458, x1455, x1456;
        loop variant (x1452-x1458);
        */
        for(int x1458=0; x1458 < x1452; x1458++) {
          int x1459 = x1455;
          if (x1459) {
            char  *x1460 = x1456;
            char x1461 = x1460[0];
            int x1462 = x1461 == '\0';
            if (x1462) {
              x1455 = 0/*false*/;
            } else {
              char  *x1463 = x1460+1;
              x1456 = x1463;
            }
          } else {
          }
        }
        int x1492 = x1455;
        char  *x1493 = x1456;
        int x1454 = x1452 < 0;
        if (x1454) {
          x1200 = 0/*false*/;
        } else {
          int x1496 = 1/*true*/;
          char  *x1498 = 0/*null*/;
          if (x1492) {
            x1496 = 0/*false*/;
            x1498 = x1493;
          } else {
            x1498 = x1453;
          }
          int x1506 = x1496;
          if (x1506) {
            char  *x1507 = x1498;
            x1200 = 0/*false*/;
          } else {
            char  *x1511 = x1498;
            int x1512 = x1201;
            int x1513 = x1512 < 0;
            int x1518;
            if (x1513) {
              x1518 = x1512;
            } else {
              int x1514 = x343 - x1452;
              int x1515 = x1512 > x1514;
              int x1517;
              if (x1515) {
                x1517 = -1;
              } else {
                int x1516 = x1512 + x1452;
                x1517 = x1516;
              }
              x1518 = x1517;
            }
            x1201 = x1518;
            x1199 = x1511;
          }
        }
      }
    }
    int x1550 = x1201;
    char  *x1551 = x1199;
    int x1553 = 1/*true*/;
    char  *x1554 = x1197;
    /*@
    loop invariant ((0<=x1556) &&
    ((strlen(x1554)>=0) &&
    \valid(x1554+(0..(strlen(x1554)+1)-1))));
    loop assigns x1556, x1553, x1554;
    loop variant (x1196-x1556);
    */
    for(int x1556=0; x1556 < x1196; x1556++) {
      int x1557 = x1553;
      if (x1557) {
        char  *x1558 = x1554;
        char x1559 = x1558[0];
        int x1560 = x1559 == '\0';
        if (x1560) {
          x1553 = 0/*false*/;
        } else {
          char  *x1561 = x1558+1;
          x1554 = x1561;
        }
      } else {
      }
    }
    int x1590 = x1553;
    char  *x1591 = x1554;
    int x1198 = x1196 == -3;
    if (x1198) {
      char x1592 = x1551[0];
      int x1593 = x1592 == '\0';
      if (x1593) {
        x2 = x1550;
      } else {
      }
    } else {
      int x1552 = x1196 < 0;
      if (x1552) {
      } else {
        int x1598 = 1/*true*/;
        char  *x1600 = 0/*null*/;
        if (x1590) {
          x1598 = 0/*false*/;
          x1600 = x1591;
        } else {
          x1600 = x1197;
        }
        int x1608 = x1598;
        if (x1608) {
          char  *x1609 = x1600;
        } else {
          char  *x1612 = x1600;
          char x1613 = x1612[0];
          int x1614 = x1613 == '\0';
          if (x1614) {
            x2 = x1196;
          } else {
          }
        }
      }
    }
  }
  int x1626 = x2;
  return x1626;
}
/*@
requires ((strlen(x1647)>=0) &&
\valid(x1647+(0..(strlen(x1647)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_HTTP(char  * x1647) {
  char  *x1649 = x1647;
  int x1654 = 1/*true*/;
  char x1655 = '\0';
  char  *x1656 = 0/*null*/;
  char x1650 = x1647[0];
  int x1651 = x1650 == '\0';
  if (x1651) {
    x1656 = x1647;
  } else {
    int x1652 = x1650 == 'H';
    if (x1652) {
      x1654 = 0/*false*/;
      x1655 = x1650;
      char  *x1653 = x1647+1;
      x1656 = x1653;
    } else {
      x1656 = x1647;
    }
  }
  int x1668 = x1654;
  if (x1668) {
    char  *x1669 = x1656;
    x1649 = 0;
  } else {
    char x1672 = x1655;
    char  *x1673 = x1656;
    int x1678 = 1/*true*/;
    char x1679 = '\0';
    char  *x1680 = 0/*null*/;
    char x1674 = x1673[0];
    int x1675 = x1674 == '\0';
    if (x1675) {
      x1680 = x1673;
    } else {
      int x1676 = x1674 == 'T';
      if (x1676) {
        x1678 = 0/*false*/;
        x1679 = x1674;
        char  *x1677 = x1673+1;
        x1680 = x1677;
      } else {
        x1680 = x1673;
      }
    }
    int x1692 = x1678;
    if (x1692) {
      char  *x1693 = x1680;
      x1649 = 0;
    } else {
      char x1696 = x1679;
      char  *x1697 = x1680;
      int x1702 = 1/*true*/;
      char x1703 = '\0';
      char  *x1704 = 0/*null*/;
      char x1698 = x1697[0];
      int x1699 = x1698 == '\0';
      if (x1699) {
        x1704 = x1697;
      } else {
        int x1700 = x1698 == 'T';
        if (x1700) {
          x1702 = 0/*false*/;
          x1703 = x1698;
          char  *x1701 = x1697+1;
          x1704 = x1701;
        } else {
          x1704 = x1697;
        }
      }
      int x1716 = x1702;
      if (x1716) {
        char  *x1717 = x1704;
        x1649 = 0;
      } else {
        char x1720 = x1703;
        char  *x1721 = x1704;
        int x1726 = 1/*true*/;
        char x1727 = '\0';
        char  *x1728 = 0/*null*/;
        char x1722 = x1721[0];
        int x1723 = x1722 == '\0';
        if (x1723) {
          x1728 = x1721;
        } else {
          int x1724 = x1722 == 'P';
          if (x1724) {
            x1726 = 0/*false*/;
            x1727 = x1722;
            char  *x1725 = x1721+1;
            x1728 = x1725;
          } else {
            x1728 = x1721;
          }
        }
        int x1740 = x1726;
        if (x1740) {
          char  *x1741 = x1728;
          x1649 = 0;
        } else {
          char x1744 = x1727;
          char  *x1745 = x1728;
          int x1750 = 1/*true*/;
          char x1751 = '\0';
          char  *x1752 = 0/*null*/;
          char x1746 = x1745[0];
          int x1747 = x1746 == '\0';
          if (x1747) {
            x1752 = x1745;
          } else {
            int x1748 = x1746 == '/';
            if (x1748) {
              x1750 = 0/*false*/;
              x1751 = x1746;
              char  *x1749 = x1745+1;
              x1752 = x1749;
            } else {
              x1752 = x1745;
            }
          }
          int x1764 = x1750;
          if (x1764) {
            char  *x1765 = x1752;
            x1649 = 0;
          } else {
            char x1768 = x1751;
            char  *x1769 = x1752;
            x1649 = x1769;
          }
        }
      }
    }
  }
  char  *x1781 = x1649;
  return x1781;
}
/*@
requires ((strlen(x1803)>=0) &&
\valid(x1803+(0..(strlen(x1803)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_(char  * x1803) {
  char  *x1805 = x1803;
  int x1810 = 1/*true*/;
  char x1811 = '\0';
  char  *x1812 = 0/*null*/;
  char x1806 = x1803[0];
  int x1807 = x1806 == '\0';
  if (x1807) {
    x1812 = x1803;
  } else {
    int x1808 = x1806 == '\r';
    if (x1808) {
      x1810 = 0/*false*/;
      x1811 = x1806;
      char  *x1809 = x1803+1;
      x1812 = x1809;
    } else {
      x1812 = x1803;
    }
  }
  int x1824 = x1810;
  if (x1824) {
    char  *x1825 = x1812;
    x1805 = 0;
  } else {
    char x1828 = x1811;
    char  *x1829 = x1812;
    int x1834 = 1/*true*/;
    char x1835 = '\0';
    char  *x1836 = 0/*null*/;
    char x1830 = x1829[0];
    int x1831 = x1830 == '\0';
    if (x1831) {
      x1836 = x1829;
    } else {
      int x1832 = x1830 == '\n';
      if (x1832) {
        x1834 = 0/*false*/;
        x1835 = x1830;
        char  *x1833 = x1829+1;
        x1836 = x1833;
      } else {
        x1836 = x1829;
      }
    }
    int x1848 = x1834;
    if (x1848) {
      char  *x1849 = x1836;
      x1805 = 0;
    } else {
      char x1852 = x1835;
      char  *x1853 = x1836;
      x1805 = x1853;
    }
  }
  char  *x1859 = x1805;
  return x1859;
}
/*@
requires ((strlen(x1881)>=0) &&
\valid(x1881+(0..(strlen(x1881)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_ContentLength(char  * x1881) {
  char  *x1883 = x1881;
  int x1888 = 1/*true*/;
  char x1889 = '\0';
  char  *x1890 = 0/*null*/;
  char x1884 = x1881[0];
  int x1885 = x1884 == '\0';
  if (x1885) {
    x1890 = x1881;
  } else {
    int x1886 = x1884 == 'C';
    if (x1886) {
      x1888 = 0/*false*/;
      x1889 = x1884;
      char  *x1887 = x1881+1;
      x1890 = x1887;
    } else {
      x1890 = x1881;
    }
  }
  int x1902 = x1888;
  if (x1902) {
    char  *x1903 = x1890;
    x1883 = 0;
  } else {
    char x1906 = x1889;
    char  *x1907 = x1890;
    int x1912 = 1/*true*/;
    char x1913 = '\0';
    char  *x1914 = 0/*null*/;
    char x1908 = x1907[0];
    int x1909 = x1908 == '\0';
    if (x1909) {
      x1914 = x1907;
    } else {
      int x1910 = x1908 == 'o';
      if (x1910) {
        x1912 = 0/*false*/;
        x1913 = x1908;
        char  *x1911 = x1907+1;
        x1914 = x1911;
      } else {
        x1914 = x1907;
      }
    }
    int x1926 = x1912;
    if (x1926) {
      char  *x1927 = x1914;
      x1883 = 0;
    } else {
      char x1930 = x1913;
      char  *x1931 = x1914;
      int x1936 = 1/*true*/;
      char x1937 = '\0';
      char  *x1938 = 0/*null*/;
      char x1932 = x1931[0];
      int x1933 = x1932 == '\0';
      if (x1933) {
        x1938 = x1931;
      } else {
        int x1934 = x1932 == 'n';
        if (x1934) {
          x1936 = 0/*false*/;
          x1937 = x1932;
          char  *x1935 = x1931+1;
          x1938 = x1935;
        } else {
          x1938 = x1931;
        }
      }
      int x1950 = x1936;
      if (x1950) {
        char  *x1951 = x1938;
        x1883 = 0;
      } else {
        char x1954 = x1937;
        char  *x1955 = x1938;
        int x1960 = 1/*true*/;
        char x1961 = '\0';
        char  *x1962 = 0/*null*/;
        char x1956 = x1955[0];
        int x1957 = x1956 == '\0';
        if (x1957) {
          x1962 = x1955;
        } else {
          int x1958 = x1956 == 't';
          if (x1958) {
            x1960 = 0/*false*/;
            x1961 = x1956;
            char  *x1959 = x1955+1;
            x1962 = x1959;
          } else {
            x1962 = x1955;
          }
        }
        int x1974 = x1960;
        if (x1974) {
          char  *x1975 = x1962;
          x1883 = 0;
        } else {
          char x1978 = x1961;
          char  *x1979 = x1962;
          int x1984 = 1/*true*/;
          char x1985 = '\0';
          char  *x1986 = 0/*null*/;
          char x1980 = x1979[0];
          int x1981 = x1980 == '\0';
          if (x1981) {
            x1986 = x1979;
          } else {
            int x1982 = x1980 == 'e';
            if (x1982) {
              x1984 = 0/*false*/;
              x1985 = x1980;
              char  *x1983 = x1979+1;
              x1986 = x1983;
            } else {
              x1986 = x1979;
            }
          }
          int x1998 = x1984;
          if (x1998) {
            char  *x1999 = x1986;
            x1883 = 0;
          } else {
            char x2002 = x1985;
            char  *x2003 = x1986;
            int x2008 = 1/*true*/;
            char x2009 = '\0';
            char  *x2010 = 0/*null*/;
            char x2004 = x2003[0];
            int x2005 = x2004 == '\0';
            if (x2005) {
              x2010 = x2003;
            } else {
              int x2006 = x2004 == 'n';
              if (x2006) {
                x2008 = 0/*false*/;
                x2009 = x2004;
                char  *x2007 = x2003+1;
                x2010 = x2007;
              } else {
                x2010 = x2003;
              }
            }
            int x2022 = x2008;
            if (x2022) {
              char  *x2023 = x2010;
              x1883 = 0;
            } else {
              char x2026 = x2009;
              char  *x2027 = x2010;
              int x2032 = 1/*true*/;
              char x2033 = '\0';
              char  *x2034 = 0/*null*/;
              char x2028 = x2027[0];
              int x2029 = x2028 == '\0';
              if (x2029) {
                x2034 = x2027;
              } else {
                int x2030 = x2028 == 't';
                if (x2030) {
                  x2032 = 0/*false*/;
                  x2033 = x2028;
                  char  *x2031 = x2027+1;
                  x2034 = x2031;
                } else {
                  x2034 = x2027;
                }
              }
              int x2046 = x2032;
              if (x2046) {
                char  *x2047 = x2034;
                x1883 = 0;
              } else {
                char x2050 = x2033;
                char  *x2051 = x2034;
                int x2056 = 1/*true*/;
                char x2057 = '\0';
                char  *x2058 = 0/*null*/;
                char x2052 = x2051[0];
                int x2053 = x2052 == '\0';
                if (x2053) {
                  x2058 = x2051;
                } else {
                  int x2054 = x2052 == '-';
                  if (x2054) {
                    x2056 = 0/*false*/;
                    x2057 = x2052;
                    char  *x2055 = x2051+1;
                    x2058 = x2055;
                  } else {
                    x2058 = x2051;
                  }
                }
                int x2070 = x2056;
                if (x2070) {
                  char  *x2071 = x2058;
                  x1883 = 0;
                } else {
                  char x2074 = x2057;
                  char  *x2075 = x2058;
                  int x2080 = 1/*true*/;
                  char x2081 = '\0';
                  char  *x2082 = 0/*null*/;
                  char x2076 = x2075[0];
                  int x2077 = x2076 == '\0';
                  if (x2077) {
                    x2082 = x2075;
                  } else {
                    int x2078 = x2076 == 'L';
                    if (x2078) {
                      x2080 = 0/*false*/;
                      x2081 = x2076;
                      char  *x2079 = x2075+1;
                      x2082 = x2079;
                    } else {
                      x2082 = x2075;
                    }
                  }
                  int x2094 = x2080;
                  if (x2094) {
                    char  *x2095 = x2082;
                    x1883 = 0;
                  } else {
                    char x2098 = x2081;
                    char  *x2099 = x2082;
                    int x2104 = 1/*true*/;
                    char x2105 = '\0';
                    char  *x2106 = 0/*null*/;
                    char x2100 = x2099[0];
                    int x2101 = x2100 == '\0';
                    if (x2101) {
                      x2106 = x2099;
                    } else {
                      int x2102 = x2100 == 'e';
                      if (x2102) {
                        x2104 = 0/*false*/;
                        x2105 = x2100;
                        char  *x2103 = x2099+1;
                        x2106 = x2103;
                      } else {
                        x2106 = x2099;
                      }
                    }
                    int x2118 = x2104;
                    if (x2118) {
                      char  *x2119 = x2106;
                      x1883 = 0;
                    } else {
                      char x2122 = x2105;
                      char  *x2123 = x2106;
                      int x2128 = 1/*true*/;
                      char x2129 = '\0';
                      char  *x2130 = 0/*null*/;
                      char x2124 = x2123[0];
                      int x2125 = x2124 == '\0';
                      if (x2125) {
                        x2130 = x2123;
                      } else {
                        int x2126 = x2124 == 'n';
                        if (x2126) {
                          x2128 = 0/*false*/;
                          x2129 = x2124;
                          char  *x2127 = x2123+1;
                          x2130 = x2127;
                        } else {
                          x2130 = x2123;
                        }
                      }
                      int x2142 = x2128;
                      if (x2142) {
                        char  *x2143 = x2130;
                        x1883 = 0;
                      } else {
                        char x2146 = x2129;
                        char  *x2147 = x2130;
                        int x2152 = 1/*true*/;
                        char x2153 = '\0';
                        char  *x2154 = 0/*null*/;
                        char x2148 = x2147[0];
                        int x2149 = x2148 == '\0';
                        if (x2149) {
                          x2154 = x2147;
                        } else {
                          int x2150 = x2148 == 'g';
                          if (x2150) {
                            x2152 = 0/*false*/;
                            x2153 = x2148;
                            char  *x2151 = x2147+1;
                            x2154 = x2151;
                          } else {
                            x2154 = x2147;
                          }
                        }
                        int x2166 = x2152;
                        if (x2166) {
                          char  *x2167 = x2154;
                          x1883 = 0;
                        } else {
                          char x2170 = x2153;
                          char  *x2171 = x2154;
                          int x2176 = 1/*true*/;
                          char x2177 = '\0';
                          char  *x2178 = 0/*null*/;
                          char x2172 = x2171[0];
                          int x2173 = x2172 == '\0';
                          if (x2173) {
                            x2178 = x2171;
                          } else {
                            int x2174 = x2172 == 't';
                            if (x2174) {
                              x2176 = 0/*false*/;
                              x2177 = x2172;
                              char  *x2175 = x2171+1;
                              x2178 = x2175;
                            } else {
                              x2178 = x2171;
                            }
                          }
                          int x2190 = x2176;
                          if (x2190) {
                            char  *x2191 = x2178;
                            x1883 = 0;
                          } else {
                            char x2194 = x2177;
                            char  *x2195 = x2178;
                            int x2200 = 1/*true*/;
                            char x2201 = '\0';
                            char  *x2202 = 0/*null*/;
                            char x2196 = x2195[0];
                            int x2197 = x2196 == '\0';
                            if (x2197) {
                              x2202 = x2195;
                            } else {
                              int x2198 = x2196 == 'h';
                              if (x2198) {
                                x2200 = 0/*false*/;
                                x2201 = x2196;
                                char  *x2199 = x2195+1;
                                x2202 = x2199;
                              } else {
                                x2202 = x2195;
                              }
                            }
                            int x2214 = x2200;
                            if (x2214) {
                              char  *x2215 = x2202;
                              x1883 = 0;
                            } else {
                              char x2218 = x2201;
                              char  *x2219 = x2202;
                              x1883 = x2219;
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
  char  *x2249 = x1883;
  return x2249;
}
/*@
requires ((strlen(x2271)>=0) &&
\valid(x2271+(0..(strlen(x2271)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_TransferEncoding(char  * x2271) {
  char  *x2273 = x2271;
  int x2278 = 1/*true*/;
  char x2279 = '\0';
  char  *x2280 = 0/*null*/;
  char x2274 = x2271[0];
  int x2275 = x2274 == '\0';
  if (x2275) {
    x2280 = x2271;
  } else {
    int x2276 = x2274 == 'T';
    if (x2276) {
      x2278 = 0/*false*/;
      x2279 = x2274;
      char  *x2277 = x2271+1;
      x2280 = x2277;
    } else {
      x2280 = x2271;
    }
  }
  int x2292 = x2278;
  if (x2292) {
    char  *x2293 = x2280;
    x2273 = 0;
  } else {
    char x2296 = x2279;
    char  *x2297 = x2280;
    int x2302 = 1/*true*/;
    char x2303 = '\0';
    char  *x2304 = 0/*null*/;
    char x2298 = x2297[0];
    int x2299 = x2298 == '\0';
    if (x2299) {
      x2304 = x2297;
    } else {
      int x2300 = x2298 == 'r';
      if (x2300) {
        x2302 = 0/*false*/;
        x2303 = x2298;
        char  *x2301 = x2297+1;
        x2304 = x2301;
      } else {
        x2304 = x2297;
      }
    }
    int x2316 = x2302;
    if (x2316) {
      char  *x2317 = x2304;
      x2273 = 0;
    } else {
      char x2320 = x2303;
      char  *x2321 = x2304;
      int x2326 = 1/*true*/;
      char x2327 = '\0';
      char  *x2328 = 0/*null*/;
      char x2322 = x2321[0];
      int x2323 = x2322 == '\0';
      if (x2323) {
        x2328 = x2321;
      } else {
        int x2324 = x2322 == 'a';
        if (x2324) {
          x2326 = 0/*false*/;
          x2327 = x2322;
          char  *x2325 = x2321+1;
          x2328 = x2325;
        } else {
          x2328 = x2321;
        }
      }
      int x2340 = x2326;
      if (x2340) {
        char  *x2341 = x2328;
        x2273 = 0;
      } else {
        char x2344 = x2327;
        char  *x2345 = x2328;
        int x2350 = 1/*true*/;
        char x2351 = '\0';
        char  *x2352 = 0/*null*/;
        char x2346 = x2345[0];
        int x2347 = x2346 == '\0';
        if (x2347) {
          x2352 = x2345;
        } else {
          int x2348 = x2346 == 'n';
          if (x2348) {
            x2350 = 0/*false*/;
            x2351 = x2346;
            char  *x2349 = x2345+1;
            x2352 = x2349;
          } else {
            x2352 = x2345;
          }
        }
        int x2364 = x2350;
        if (x2364) {
          char  *x2365 = x2352;
          x2273 = 0;
        } else {
          char x2368 = x2351;
          char  *x2369 = x2352;
          int x2374 = 1/*true*/;
          char x2375 = '\0';
          char  *x2376 = 0/*null*/;
          char x2370 = x2369[0];
          int x2371 = x2370 == '\0';
          if (x2371) {
            x2376 = x2369;
          } else {
            int x2372 = x2370 == 's';
            if (x2372) {
              x2374 = 0/*false*/;
              x2375 = x2370;
              char  *x2373 = x2369+1;
              x2376 = x2373;
            } else {
              x2376 = x2369;
            }
          }
          int x2388 = x2374;
          if (x2388) {
            char  *x2389 = x2376;
            x2273 = 0;
          } else {
            char x2392 = x2375;
            char  *x2393 = x2376;
            int x2398 = 1/*true*/;
            char x2399 = '\0';
            char  *x2400 = 0/*null*/;
            char x2394 = x2393[0];
            int x2395 = x2394 == '\0';
            if (x2395) {
              x2400 = x2393;
            } else {
              int x2396 = x2394 == 'f';
              if (x2396) {
                x2398 = 0/*false*/;
                x2399 = x2394;
                char  *x2397 = x2393+1;
                x2400 = x2397;
              } else {
                x2400 = x2393;
              }
            }
            int x2412 = x2398;
            if (x2412) {
              char  *x2413 = x2400;
              x2273 = 0;
            } else {
              char x2416 = x2399;
              char  *x2417 = x2400;
              int x2422 = 1/*true*/;
              char x2423 = '\0';
              char  *x2424 = 0/*null*/;
              char x2418 = x2417[0];
              int x2419 = x2418 == '\0';
              if (x2419) {
                x2424 = x2417;
              } else {
                int x2420 = x2418 == 'e';
                if (x2420) {
                  x2422 = 0/*false*/;
                  x2423 = x2418;
                  char  *x2421 = x2417+1;
                  x2424 = x2421;
                } else {
                  x2424 = x2417;
                }
              }
              int x2436 = x2422;
              if (x2436) {
                char  *x2437 = x2424;
                x2273 = 0;
              } else {
                char x2440 = x2423;
                char  *x2441 = x2424;
                int x2446 = 1/*true*/;
                char x2447 = '\0';
                char  *x2448 = 0/*null*/;
                char x2442 = x2441[0];
                int x2443 = x2442 == '\0';
                if (x2443) {
                  x2448 = x2441;
                } else {
                  int x2444 = x2442 == 'r';
                  if (x2444) {
                    x2446 = 0/*false*/;
                    x2447 = x2442;
                    char  *x2445 = x2441+1;
                    x2448 = x2445;
                  } else {
                    x2448 = x2441;
                  }
                }
                int x2460 = x2446;
                if (x2460) {
                  char  *x2461 = x2448;
                  x2273 = 0;
                } else {
                  char x2464 = x2447;
                  char  *x2465 = x2448;
                  int x2470 = 1/*true*/;
                  char x2471 = '\0';
                  char  *x2472 = 0/*null*/;
                  char x2466 = x2465[0];
                  int x2467 = x2466 == '\0';
                  if (x2467) {
                    x2472 = x2465;
                  } else {
                    int x2468 = x2466 == '-';
                    if (x2468) {
                      x2470 = 0/*false*/;
                      x2471 = x2466;
                      char  *x2469 = x2465+1;
                      x2472 = x2469;
                    } else {
                      x2472 = x2465;
                    }
                  }
                  int x2484 = x2470;
                  if (x2484) {
                    char  *x2485 = x2472;
                    x2273 = 0;
                  } else {
                    char x2488 = x2471;
                    char  *x2489 = x2472;
                    int x2494 = 1/*true*/;
                    char x2495 = '\0';
                    char  *x2496 = 0/*null*/;
                    char x2490 = x2489[0];
                    int x2491 = x2490 == '\0';
                    if (x2491) {
                      x2496 = x2489;
                    } else {
                      int x2492 = x2490 == 'E';
                      if (x2492) {
                        x2494 = 0/*false*/;
                        x2495 = x2490;
                        char  *x2493 = x2489+1;
                        x2496 = x2493;
                      } else {
                        x2496 = x2489;
                      }
                    }
                    int x2508 = x2494;
                    if (x2508) {
                      char  *x2509 = x2496;
                      x2273 = 0;
                    } else {
                      char x2512 = x2495;
                      char  *x2513 = x2496;
                      int x2518 = 1/*true*/;
                      char x2519 = '\0';
                      char  *x2520 = 0/*null*/;
                      char x2514 = x2513[0];
                      int x2515 = x2514 == '\0';
                      if (x2515) {
                        x2520 = x2513;
                      } else {
                        int x2516 = x2514 == 'n';
                        if (x2516) {
                          x2518 = 0/*false*/;
                          x2519 = x2514;
                          char  *x2517 = x2513+1;
                          x2520 = x2517;
                        } else {
                          x2520 = x2513;
                        }
                      }
                      int x2532 = x2518;
                      if (x2532) {
                        char  *x2533 = x2520;
                        x2273 = 0;
                      } else {
                        char x2536 = x2519;
                        char  *x2537 = x2520;
                        int x2542 = 1/*true*/;
                        char x2543 = '\0';
                        char  *x2544 = 0/*null*/;
                        char x2538 = x2537[0];
                        int x2539 = x2538 == '\0';
                        if (x2539) {
                          x2544 = x2537;
                        } else {
                          int x2540 = x2538 == 'c';
                          if (x2540) {
                            x2542 = 0/*false*/;
                            x2543 = x2538;
                            char  *x2541 = x2537+1;
                            x2544 = x2541;
                          } else {
                            x2544 = x2537;
                          }
                        }
                        int x2556 = x2542;
                        if (x2556) {
                          char  *x2557 = x2544;
                          x2273 = 0;
                        } else {
                          char x2560 = x2543;
                          char  *x2561 = x2544;
                          int x2566 = 1/*true*/;
                          char x2567 = '\0';
                          char  *x2568 = 0/*null*/;
                          char x2562 = x2561[0];
                          int x2563 = x2562 == '\0';
                          if (x2563) {
                            x2568 = x2561;
                          } else {
                            int x2564 = x2562 == 'o';
                            if (x2564) {
                              x2566 = 0/*false*/;
                              x2567 = x2562;
                              char  *x2565 = x2561+1;
                              x2568 = x2565;
                            } else {
                              x2568 = x2561;
                            }
                          }
                          int x2580 = x2566;
                          if (x2580) {
                            char  *x2581 = x2568;
                            x2273 = 0;
                          } else {
                            char x2584 = x2567;
                            char  *x2585 = x2568;
                            int x2590 = 1/*true*/;
                            char x2591 = '\0';
                            char  *x2592 = 0/*null*/;
                            char x2586 = x2585[0];
                            int x2587 = x2586 == '\0';
                            if (x2587) {
                              x2592 = x2585;
                            } else {
                              int x2588 = x2586 == 'd';
                              if (x2588) {
                                x2590 = 0/*false*/;
                                x2591 = x2586;
                                char  *x2589 = x2585+1;
                                x2592 = x2589;
                              } else {
                                x2592 = x2585;
                              }
                            }
                            int x2604 = x2590;
                            if (x2604) {
                              char  *x2605 = x2592;
                              x2273 = 0;
                            } else {
                              char x2608 = x2591;
                              char  *x2609 = x2592;
                              int x2614 = 1/*true*/;
                              char x2615 = '\0';
                              char  *x2616 = 0/*null*/;
                              char x2610 = x2609[0];
                              int x2611 = x2610 == '\0';
                              if (x2611) {
                                x2616 = x2609;
                              } else {
                                int x2612 = x2610 == 'i';
                                if (x2612) {
                                  x2614 = 0/*false*/;
                                  x2615 = x2610;
                                  char  *x2613 = x2609+1;
                                  x2616 = x2613;
                                } else {
                                  x2616 = x2609;
                                }
                              }
                              int x2628 = x2614;
                              if (x2628) {
                                char  *x2629 = x2616;
                                x2273 = 0;
                              } else {
                                char x2632 = x2615;
                                char  *x2633 = x2616;
                                int x2638 = 1/*true*/;
                                char x2639 = '\0';
                                char  *x2640 = 0/*null*/;
                                char x2634 = x2633[0];
                                int x2635 = x2634 == '\0';
                                if (x2635) {
                                  x2640 = x2633;
                                } else {
                                  int x2636 = x2634 == 'n';
                                  if (x2636) {
                                    x2638 = 0/*false*/;
                                    x2639 = x2634;
                                    char  *x2637 = x2633+1;
                                    x2640 = x2637;
                                  } else {
                                    x2640 = x2633;
                                  }
                                }
                                int x2652 = x2638;
                                if (x2652) {
                                  char  *x2653 = x2640;
                                  x2273 = 0;
                                } else {
                                  char x2656 = x2639;
                                  char  *x2657 = x2640;
                                  int x2662 = 1/*true*/;
                                  char x2663 = '\0';
                                  char  *x2664 = 0/*null*/;
                                  char x2658 = x2657[0];
                                  int x2659 = x2658 == '\0';
                                  if (x2659) {
                                    x2664 = x2657;
                                  } else {
                                    int x2660 = x2658 == 'g';
                                    if (x2660) {
                                      x2662 = 0/*false*/;
                                      x2663 = x2658;
                                      char  *x2661 = x2657+1;
                                      x2664 = x2661;
                                    } else {
                                      x2664 = x2657;
                                    }
                                  }
                                  int x2676 = x2662;
                                  if (x2676) {
                                    char  *x2677 = x2664;
                                    x2273 = 0;
                                  } else {
                                    char x2680 = x2663;
                                    char  *x2681 = x2664;
                                    x2273 = x2681;
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
  char  *x2717 = x2273;
  return x2717;
}
/*@
requires ((strlen(x2739)>=0) &&
\valid(x2739+(0..(strlen(x2739)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) &&
\valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_chunked(char  * x2739) {
  char  *x2741 = x2739;
  int x2746 = 1/*true*/;
  char x2747 = '\0';
  char  *x2748 = 0/*null*/;
  char x2742 = x2739[0];
  int x2743 = x2742 == '\0';
  if (x2743) {
    x2748 = x2739;
  } else {
    int x2744 = x2742 == 'c';
    if (x2744) {
      x2746 = 0/*false*/;
      x2747 = x2742;
      char  *x2745 = x2739+1;
      x2748 = x2745;
    } else {
      x2748 = x2739;
    }
  }
  int x2760 = x2746;
  if (x2760) {
    char  *x2761 = x2748;
    x2741 = 0;
  } else {
    char x2764 = x2747;
    char  *x2765 = x2748;
    int x2770 = 1/*true*/;
    char x2771 = '\0';
    char  *x2772 = 0/*null*/;
    char x2766 = x2765[0];
    int x2767 = x2766 == '\0';
    if (x2767) {
      x2772 = x2765;
    } else {
      int x2768 = x2766 == 'h';
      if (x2768) {
        x2770 = 0/*false*/;
        x2771 = x2766;
        char  *x2769 = x2765+1;
        x2772 = x2769;
      } else {
        x2772 = x2765;
      }
    }
    int x2784 = x2770;
    if (x2784) {
      char  *x2785 = x2772;
      x2741 = 0;
    } else {
      char x2788 = x2771;
      char  *x2789 = x2772;
      int x2794 = 1/*true*/;
      char x2795 = '\0';
      char  *x2796 = 0/*null*/;
      char x2790 = x2789[0];
      int x2791 = x2790 == '\0';
      if (x2791) {
        x2796 = x2789;
      } else {
        int x2792 = x2790 == 'u';
        if (x2792) {
          x2794 = 0/*false*/;
          x2795 = x2790;
          char  *x2793 = x2789+1;
          x2796 = x2793;
        } else {
          x2796 = x2789;
        }
      }
      int x2808 = x2794;
      if (x2808) {
        char  *x2809 = x2796;
        x2741 = 0;
      } else {
        char x2812 = x2795;
        char  *x2813 = x2796;
        int x2818 = 1/*true*/;
        char x2819 = '\0';
        char  *x2820 = 0/*null*/;
        char x2814 = x2813[0];
        int x2815 = x2814 == '\0';
        if (x2815) {
          x2820 = x2813;
        } else {
          int x2816 = x2814 == 'n';
          if (x2816) {
            x2818 = 0/*false*/;
            x2819 = x2814;
            char  *x2817 = x2813+1;
            x2820 = x2817;
          } else {
            x2820 = x2813;
          }
        }
        int x2832 = x2818;
        if (x2832) {
          char  *x2833 = x2820;
          x2741 = 0;
        } else {
          char x2836 = x2819;
          char  *x2837 = x2820;
          int x2842 = 1/*true*/;
          char x2843 = '\0';
          char  *x2844 = 0/*null*/;
          char x2838 = x2837[0];
          int x2839 = x2838 == '\0';
          if (x2839) {
            x2844 = x2837;
          } else {
            int x2840 = x2838 == 'k';
            if (x2840) {
              x2842 = 0/*false*/;
              x2843 = x2838;
              char  *x2841 = x2837+1;
              x2844 = x2841;
            } else {
              x2844 = x2837;
            }
          }
          int x2856 = x2842;
          if (x2856) {
            char  *x2857 = x2844;
            x2741 = 0;
          } else {
            char x2860 = x2843;
            char  *x2861 = x2844;
            int x2866 = 1/*true*/;
            char x2867 = '\0';
            char  *x2868 = 0/*null*/;
            char x2862 = x2861[0];
            int x2863 = x2862 == '\0';
            if (x2863) {
              x2868 = x2861;
            } else {
              int x2864 = x2862 == 'e';
              if (x2864) {
                x2866 = 0/*false*/;
                x2867 = x2862;
                char  *x2865 = x2861+1;
                x2868 = x2865;
              } else {
                x2868 = x2861;
              }
            }
            int x2880 = x2866;
            if (x2880) {
              char  *x2881 = x2868;
              x2741 = 0;
            } else {
              char x2884 = x2867;
              char  *x2885 = x2868;
              int x2890 = 1/*true*/;
              char x2891 = '\0';
              char  *x2892 = 0/*null*/;
              char x2886 = x2885[0];
              int x2887 = x2886 == '\0';
              if (x2887) {
                x2892 = x2885;
              } else {
                int x2888 = x2886 == 'd';
                if (x2888) {
                  x2890 = 0/*false*/;
                  x2891 = x2886;
                  char  *x2889 = x2885+1;
                  x2892 = x2889;
                } else {
                  x2892 = x2885;
                }
              }
              int x2904 = x2890;
              if (x2904) {
                char  *x2905 = x2892;
                x2741 = 0;
              } else {
                char x2908 = x2891;
                char  *x2909 = x2892;
                x2741 = x2909;
              }
            }
          }
        }
      }
    }
  }
  char  *x2925 = x2741;
  return x2925;
}
