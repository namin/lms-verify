#include <limits.h>
#include <string.h>
char  * p_chunked(char  * x1767);
char  * p_TransferEncoding(char  * x1769);
char  * p_ContentLength(char  * x1771);
char  * p_HTTP(char  * x1773);
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
    int x1163 = -2 == -2;
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
      int x504 = 0;
      char  *x505 = 0/*null*/;
      int x506 = 1/*true*/;
      char  *x508 = 0/*null*/;
      int x509 = 0 == x486;
      if (x509) {
        x508 = x485;
      } else {
        x506 = 0/*false*/;
        x508 = x486;
      }
      int x517 = x506;
      if (x517) {
        char  *x518 = x508;
      } else {
        char  *x521 = x508;
        x503 = 0/*false*/;
        x504 = 1;
        x505 = x521;
      }
      int x527 = x503;
      if (x527) {
        char  *x528 = p_TransferEncoding(x485);
        int x530 = 1/*true*/;
        char  *x532 = 0/*null*/;
        int x533 = 0 == x528;
        if (x533) {
          x532 = x485;
        } else {
          x530 = 0/*false*/;
          x532 = x528;
        }
        int x541 = x530;
        if (x541) {
          char  *x542 = x532;
        } else {
          char  *x545 = x532;
          x500 = 0/*false*/;
          x501 = 2;
          x502 = x545;
        }
      } else {
        int x552 = x504;
        char  *x553 = x505;
        x500 = 0/*false*/;
        x501 = x552;
        x502 = x553;
      }
      int x559 = x500;
      if (x559) {
        char  *x560 = x485;
        int x561 = 1/*true*/;
        /*@
        loop invariant ((strlen(x560)>=0) && \valid(x560+(0..(strlen(x560)+1)-1)));
        loop assigns x560, x561;
        */
        for (;;) {
          int x562 = x561;
          if (!x562) break;
          char  *x564 = x560;
          int x575 = 1/*true*/;
          char x576 = '\0';
          char  *x577 = 0/*null*/;
          char x565 = x564[0];
          int x566 = x565 == '\0';
          if (x566) {
          } else {
            int x567 = x565 >= 'a';
            int x569;
            if (x567) {
              int x568 = x565 <= 'z';
              x569 = x568;
            } else {
              x569 = 0/*false*/;
            }
            int x570 = x565 >= 'A';
            int x572;
            if (x570) {
              int x571 = x565 <= 'Z';
              x572 = x571;
            } else {
              x572 = 0/*false*/;
            }
            int x573 = x569 || x572;
            if (x573) {
              x575 = 0/*false*/;
              x576 = x565;
              char  *x574 = x564+1;
              x577 = x574;
            } else {
            }
          }
          int x585 = x575;
          char x587 = x576;
          char  *x588 = x577;
          if (x585) {
            if (x566) {
              x561 = 0/*false*/;
            } else {
              int x586 = x565 == '-';
              if (x586) {
                char  *x574 = x564+1;
                x560 = x574;
              } else {
                x561 = 0/*false*/;
              }
            }
          } else {
            x560 = x588;
          }
        }
        char  *x618 = x560;
        x497 = 0/*false*/;
        x498 = 0;
        x499 = x618;
      } else {
        int x623 = x501;
        char  *x624 = x502;
        x497 = 0/*false*/;
        x498 = x623;
        x499 = x624;
      }
      int x630 = x497;
      if (x630) {
        char  *x631 = x499;
        x496 = x631;
      } else {
        int x634 = x498;
        char  *x635 = x499;
        char  *x636 = x635;
        int x637 = 1/*true*/;
        /*@
        loop invariant ((strlen(x636)>=0) && \valid(x636+(0..(strlen(x636)+1)-1)));
        loop assigns x636, x637;
        */
        for (;;) {
          int x638 = x637;
          if (!x638) break;
          char  *x640 = x636;
          char x641 = x640[0];
          int x642 = x641 == '\0';
          if (x642) {
            x637 = 0/*false*/;
          } else {
            int x643 = x641 == ' ';
            if (x643) {
              char  *x644 = x640+1;
              x636 = x644;
            } else {
              x637 = 0/*false*/;
            }
          }
        }
        char  *x670 = x636;
        x494 = 0/*false*/;
        x495 = x634;
        x496 = x670;
      }
      int x676 = x494;
      if (x676) {
        char  *x677 = x496;
        x493 = x677;
      } else {
        int x680 = x495;
        char  *x681 = x496;
        int x686 = 1/*true*/;
        char x687 = '\0';
        char  *x688 = 0/*null*/;
        char x682 = x681[0];
        int x683 = x682 == '\0';
        if (x683) {
          x688 = x681;
        } else {
          int x684 = x682 == ':';
          if (x684) {
            x686 = 0/*false*/;
            x687 = x682;
            char  *x685 = x681+1;
            x688 = x685;
          } else {
            x688 = x681;
          }
        }
        int x700 = x686;
        if (x700) {
          char  *x701 = x688;
          x493 = x701;
        } else {
          char x704 = x687;
          char  *x705 = x688;
          x491 = 0/*false*/;
          x492 = x680;
          x493 = x705;
        }
      }
      int x713 = x491;
      if (x713) {
        char  *x714 = x493;
        x490 = x714;
      } else {
        int x717 = x492;
        char  *x718 = x493;
        char  *x719 = x718;
        int x720 = 1/*true*/;
        /*@
        loop invariant ((strlen(x719)>=0) && \valid(x719+(0..(strlen(x719)+1)-1)));
        loop assigns x719, x720;
        */
        for (;;) {
          int x721 = x720;
          if (!x721) break;
          char  *x723 = x719;
          char x724 = x723[0];
          int x725 = x724 == '\0';
          if (x725) {
            x720 = 0/*false*/;
          } else {
            int x726 = x724 == ' ';
            if (x726) {
              char  *x727 = x723+1;
              x719 = x727;
            } else {
              x720 = 0/*false*/;
            }
          }
        }
        char  *x753 = x719;
        x488 = 0/*false*/;
        x489 = x717;
        x490 = x753;
      }
      int x759 = x488;
      if (x759) {
        char  *x760 = x490;
        x481 = 0/*false*/;
      } else {
        int x763 = x489;
        char  *x764 = x490;
        char  *x766 = p_chunked(x764);
        char  *x775 = x764;
        int x776 = 1/*true*/;
        /*@
        loop invariant ((strlen(x775)>=0) && \valid(x775+(0..(strlen(x775)+1)-1)));
        loop assigns x775, x776;
        */
        for (;;) {
          int x777 = x776;
          if (!x777) break;
          char  *x779 = x775;
          char x780 = x779[0];
          int x781 = x780 == '\0';
          if (x781) {
            x776 = 0/*false*/;
          } else {
            int x786 = x780 == '\n';
            if (x786) {
              x776 = 0/*false*/;
            } else {
              char  *x783 = x779+1;
              x775 = x783;
            }
          }
        }
        char  *x810 = x775;
        int x765 = x763 == 2;
        if (x765) {
          int x811 = 1/*true*/;
          int x812 = 0;
          char  *x813 = 0/*null*/;
          int x814 = 1/*true*/;
          int x815 = 0;
          char  *x816 = 0/*null*/;
          int x817 = 1/*true*/;
          char  *x819 = 0/*null*/;
          int x820 = 0 == x766;
          if (x820) {
            x819 = x764;
          } else {
            x817 = 0/*false*/;
            x819 = x766;
          }
          int x828 = x817;
          if (x828) {
            char  *x829 = x819;
            x816 = x829;
          } else {
            char  *x833 = x819;
            x814 = 0/*false*/;
            x815 = -3;
            x816 = x833;
          }
          int x839 = x814;
          if (x839) {
            char  *x840 = x816;
            x813 = x840;
          } else {
            int x843 = x815;
            char  *x844 = x816;
            char  *x845 = x844;
            int x846 = 1/*true*/;
            /*@
            loop invariant ((strlen(x845)>=0) && \valid(x845+(0..(strlen(x845)+1)-1)));
            loop assigns x845, x846;
            */
            for (;;) {
              int x847 = x846;
              if (!x847) break;
              char  *x849 = x845;
              char x850 = x849[0];
              int x851 = x850 == '\0';
              if (x851) {
                x846 = 0/*false*/;
              } else {
                int x852 = x850 == ' ';
                if (x852) {
                  char  *x853 = x849+1;
                  x845 = x853;
                } else {
                  x846 = 0/*false*/;
                }
              }
            }
            char  *x879 = x845;
            x811 = 0/*false*/;
            x812 = x843;
            x813 = x879;
          }
          int x885 = x811;
          if (x885) {
            char  *x886 = x813;
            x481 = 0/*false*/;
          } else {
            int x889 = x812;
            char  *x890 = x813;
            int x895 = 1/*true*/;
            char x896 = '\0';
            char  *x897 = 0/*null*/;
            char x891 = x890[0];
            int x892 = x891 == '\0';
            if (x892) {
              x897 = x890;
            } else {
              int x893 = x891 == '\n';
              if (x893) {
                x895 = 0/*false*/;
                x896 = x891;
                char  *x894 = x890+1;
                x897 = x894;
              } else {
                x897 = x890;
              }
            }
            int x909 = x895;
            if (x909) {
              char  *x910 = x897;
              x481 = 0/*false*/;
            } else {
              char x913 = x896;
              char  *x914 = x897;
              int x915 = x482;
              int x916 = x889 == -2;
              int x917;
              if (x916) {
                x917 = x915;
              } else {
                x917 = x889;
              }
              x482 = x917;
              x480 = x914;
            }
          }
        } else {
          int x768 = x763 == 1;
          if (x768) {
            int x925 = 1/*true*/;
            int x926 = 0;
            char  *x927 = 0/*null*/;
            int x928 = 1/*true*/;
            int x929 = 0;
            char  *x930 = 0/*null*/;
            int x931 = 1/*true*/;
            int x932 = 0;
            char  *x933 = 0/*null*/;
            int x934 = 1/*true*/;
            char x935 = '\0';
            char  *x936 = 0/*null*/;
            char x769 = x764[0];
            int x770 = x769 == '\0';
            if (x770) {
              x936 = x764;
            } else {
              int x771 = x769 >= '0';
              int x773;
              if (x771) {
                int x772 = x769 <= '9';
                x773 = x772;
              } else {
                x773 = 0/*false*/;
              }
              if (x773) {
                x934 = 0/*false*/;
                x935 = x769;
                char  *x774 = x764+1;
                x936 = x774;
              } else {
                x936 = x764;
              }
            }
            int x948 = x934;
            if (x948) {
              char  *x949 = x936;
              x933 = x949;
            } else {
              char x952 = x935;
              char  *x954 = x936;
              x931 = 0/*false*/;
              char x953 = x952 - '0';
              x932 = x953;
              x933 = x954;
            }
            int x960 = x931;
            if (x960) {
              char  *x961 = x933;
              x930 = x961;
            } else {
              int x964 = x932;
              char  *x965 = x933;
              char  *x966 = x965;
              int x967 = 1/*true*/;
              int x968 = x964;
              /*@
              loop invariant (((strlen(x966)>=0) && \valid(x966+(0..(strlen(x966)+1)-1))) && ((x968==-1) || (0<=x968)));
              loop assigns x966, x967, x968;
              */
              for (;;) {
                int x969 = x967;
                if (!x969) break;
                char  *x971 = x966;
                int x978 = 1/*true*/;
                char x979 = '\0';
                char  *x980 = 0/*null*/;
                char x972 = x971[0];
                int x973 = x972 == '\0';
                if (x973) {
                  x980 = x971;
                } else {
                  int x974 = x972 >= '0';
                  int x976;
                  if (x974) {
                    int x975 = x972 <= '9';
                    x976 = x975;
                  } else {
                    x976 = 0/*false*/;
                  }
                  if (x976) {
                    x978 = 0/*false*/;
                    x979 = x972;
                    char  *x977 = x971+1;
                    x980 = x977;
                  } else {
                    x980 = x971;
                  }
                }
                int x992 = x978;
                if (x992) {
                  char  *x993 = x980;
                  x967 = 0/*false*/;
                } else {
                  char x996 = x979;
                  char  *x998 = x980;
                  int x999 = x968;
                  int x1000 = x999 < 0;
                  int x1005;
                  if (x1000) {
                    x1005 = x999;
                  } else {
                    int x1001 = x999 > x345;
                    int x1004;
                    if (x1001) {
                      x1004 = -1;
                    } else {
                      char x997 = x996 - '0';
                      int x1002 = x999 * 10;
                      int x1003 = x1002 + x997;
                      x1004 = x1003;
                    }
                    x1005 = x1004;
                  }
                  x968 = x1005;
                  x966 = x998;
                }
              }
              int x1033 = x968;
              char  *x1034 = x966;
              x928 = 0/*false*/;
              x929 = x1033;
              x930 = x1034;
            }
            int x1040 = x928;
            if (x1040) {
              char  *x1041 = x930;
              x927 = x1041;
            } else {
              int x1044 = x929;
              char  *x1045 = x930;
              char  *x1046 = x1045;
              int x1047 = 1/*true*/;
              /*@
              loop invariant ((strlen(x1046)>=0) && \valid(x1046+(0..(strlen(x1046)+1)-1)));
              loop assigns x1046, x1047;
              */
              for (;;) {
                int x1048 = x1047;
                if (!x1048) break;
                char  *x1050 = x1046;
                char x1051 = x1050[0];
                int x1052 = x1051 == '\0';
                if (x1052) {
                  x1047 = 0/*false*/;
                } else {
                  int x1053 = x1051 == ' ';
                  if (x1053) {
                    char  *x1054 = x1050+1;
                    x1046 = x1054;
                  } else {
                    x1047 = 0/*false*/;
                  }
                }
              }
              char  *x1080 = x1046;
              x925 = 0/*false*/;
              x926 = x1044;
              x927 = x1080;
            }
            int x1086 = x925;
            if (x1086) {
              char  *x1087 = x927;
              x481 = 0/*false*/;
            } else {
              int x1090 = x926;
              char  *x1091 = x927;
              int x1096 = 1/*true*/;
              char x1097 = '\0';
              char  *x1098 = 0/*null*/;
              char x1092 = x1091[0];
              int x1093 = x1092 == '\0';
              if (x1093) {
                x1098 = x1091;
              } else {
                int x1094 = x1092 == '\n';
                if (x1094) {
                  x1096 = 0/*false*/;
                  x1097 = x1092;
                  char  *x1095 = x1091+1;
                  x1098 = x1095;
                } else {
                  x1098 = x1091;
                }
              }
              int x1110 = x1096;
              if (x1110) {
                char  *x1111 = x1098;
                x481 = 0/*false*/;
              } else {
                char x1114 = x1097;
                char  *x1115 = x1098;
                int x1116 = x482;
                int x1117 = x1090 == -2;
                int x1118;
                if (x1117) {
                  x1118 = x1116;
                } else {
                  x1118 = x1090;
                }
                x482 = x1118;
                x480 = x1115;
              }
            }
          } else {
            int x1126 = 1/*true*/;
            char  *x1128 = 0/*null*/;
            x1126 = 0/*false*/;
            x1128 = x810;
            int x1132 = x1126;
            if (x1132) {
              char  *x1133 = x1128;
              x481 = 0/*false*/;
            } else {
              char  *x1137 = x1128;
              int x1142 = 1/*true*/;
              char x1143 = '\0';
              char  *x1144 = 0/*null*/;
              char x1138 = x1137[0];
              int x1139 = x1138 == '\0';
              if (x1139) {
                x1144 = x1137;
              } else {
                int x1140 = x1138 == '\n';
                if (x1140) {
                  x1142 = 0/*false*/;
                  x1143 = x1138;
                  char  *x1141 = x1137+1;
                  x1144 = x1141;
                } else {
                  x1144 = x1137;
                }
              }
              int x1156 = x1142;
              if (x1156) {
                char  *x1157 = x1144;
                x481 = 0/*false*/;
              } else {
                char x1160 = x1143;
                char  *x1161 = x1144;
                int x1162 = x482;
                int x1164;
                if (x1163) {
                  x1164 = x1162;
                } else {
                  x1164 = -2;
                }
                x482 = x1164;
                x480 = x1161;
              }
            }
          }
        }
      }
    }
    int x1195 = x482;
    char  *x1196 = x480;
    x8 = 0/*false*/;
    x9 = x1195;
    x10 = x1196;
  }
  int x1202 = x8;
  if (x1202) {
    char  *x1203 = x10;
    x7 = x1203;
  } else {
    int x1206 = x9;
    char  *x1207 = x10;
    int x1212 = 1/*true*/;
    char x1213 = '\0';
    char  *x1214 = 0/*null*/;
    char x1208 = x1207[0];
    int x1209 = x1208 == '\0';
    if (x1209) {
      x1214 = x1207;
    } else {
      int x1210 = x1208 == '\n';
      if (x1210) {
        x1212 = 0/*false*/;
        x1213 = x1208;
        char  *x1211 = x1207+1;
        x1214 = x1211;
      } else {
        x1214 = x1207;
      }
    }
    int x1226 = x1212;
    if (x1226) {
      char  *x1227 = x1214;
      x7 = x1227;
    } else {
      char x1230 = x1213;
      char  *x1231 = x1214;
      x5 = 0/*false*/;
      x6 = x1206;
      x7 = x1231;
    }
  }
  int x1239 = x5;
  if (x1239) {
    char  *x1240 = x7;
  } else {
    int x1242 = x6;
    char  *x1243 = x7;
    char  *x1245 = x1243;
    int x1246 = 1/*true*/;
    int x1247 = 0;
    int x343 = INT_MAX;
    int x1407 = x343 / 16;
    int x1408 = x1407 - 16;
    /*@
    loop invariant (((strlen(x1245)>=0) && \valid(x1245+(0..(strlen(x1245)+1)-1))) && ((x1247==-1) || (0<=x1247)));
    loop assigns x1245, x1246, x1247;
    */
    for (;;) {
      int x1248 = x1246;
      if (!x1248) break;
      char  *x1250 = x1245;
      int x1257 = 1/*true*/;
      int x1258 = 0;
      char  *x1259 = 0/*null*/;
      int x1260 = 1/*true*/;
      int x1261 = 0;
      char  *x1262 = 0/*null*/;
      int x1263 = 1/*true*/;
      int x1264 = 0;
      char  *x1265 = 0/*null*/;
      int x1266 = 1/*true*/;
      int x1267 = 0;
      char  *x1268 = 0/*null*/;
      int x1269 = 1/*true*/;
      char x1270 = '\0';
      char  *x1271 = 0/*null*/;
      char x1251 = x1250[0];
      int x1252 = x1251 == '\0';
      if (x1252) {
        x1271 = x1250;
      } else {
        int x1253 = x1251 >= '0';
        int x1255;
        if (x1253) {
          int x1254 = x1251 <= '9';
          x1255 = x1254;
        } else {
          x1255 = 0/*false*/;
        }
        if (x1255) {
          x1269 = 0/*false*/;
          x1270 = x1251;
          char  *x1256 = x1250+1;
          x1271 = x1256;
        } else {
          x1271 = x1250;
        }
      }
      int x1283 = x1269;
      if (x1283) {
        char  *x1284 = x1271;
      } else {
        char x1286 = x1270;
        char  *x1288 = x1271;
        x1266 = 0/*false*/;
        char x1287 = x1286 - '0';
        x1267 = x1287;
        x1268 = x1288;
      }
      int x1294 = x1266;
      if (x1294) {
        int x1298 = 1/*true*/;
        char x1299 = '\0';
        char  *x1300 = 0/*null*/;
        if (x1252) {
          x1300 = x1250;
        } else {
          int x1295 = x1251 >= 'a';
          int x1297;
          if (x1295) {
            int x1296 = x1251 <= 'f';
            x1297 = x1296;
          } else {
            x1297 = 0/*false*/;
          }
          if (x1297) {
            x1298 = 0/*false*/;
            x1299 = x1251;
            char  *x1256 = x1250+1;
            x1300 = x1256;
          } else {
            x1300 = x1250;
          }
        }
        int x1312 = x1298;
        if (x1312) {
          char  *x1313 = x1300;
          x1265 = x1313;
        } else {
          char x1316 = x1299;
          char  *x1319 = x1300;
          x1263 = 0/*false*/;
          char x1317 = x1316 - 'a';
          int x1318 = 10 + x1317;
          x1264 = x1318;
          x1265 = x1319;
        }
      } else {
        int x1326 = x1267;
        char  *x1327 = x1268;
        x1263 = 0/*false*/;
        x1264 = x1326;
        x1265 = x1327;
      }
      int x1333 = x1263;
      if (x1333) {
        char  *x1334 = x1265;
        x1262 = x1334;
      } else {
        int x1337 = x1264;
        char  *x1338 = x1265;
        char  *x1339 = x1338;
        int x1340 = 1/*true*/;
        int x1341 = x1337;
        /*@
        loop invariant (((strlen(x1339)>=0) && \valid(x1339+(0..(strlen(x1339)+1)-1))) && ((x1341==-1) || (0<=x1341)));
        loop assigns x1339, x1340, x1341;
        */
        for (;;) {
          int x1342 = x1340;
          if (!x1342) break;
          char  *x1344 = x1339;
          int x1351 = 1/*true*/;
          int x1352 = 0;
          char  *x1353 = 0/*null*/;
          int x1354 = 1/*true*/;
          char x1355 = '\0';
          char  *x1356 = 0/*null*/;
          char x1345 = x1344[0];
          int x1346 = x1345 == '\0';
          if (x1346) {
            x1356 = x1344;
          } else {
            int x1347 = x1345 >= '0';
            int x1349;
            if (x1347) {
              int x1348 = x1345 <= '9';
              x1349 = x1348;
            } else {
              x1349 = 0/*false*/;
            }
            if (x1349) {
              x1354 = 0/*false*/;
              x1355 = x1345;
              char  *x1350 = x1344+1;
              x1356 = x1350;
            } else {
              x1356 = x1344;
            }
          }
          int x1368 = x1354;
          if (x1368) {
            char  *x1369 = x1356;
          } else {
            char x1371 = x1355;
            char  *x1373 = x1356;
            x1351 = 0/*false*/;
            char x1372 = x1371 - '0';
            x1352 = x1372;
            x1353 = x1373;
          }
          int x1379 = x1351;
          if (x1379) {
            int x1383 = 1/*true*/;
            char x1384 = '\0';
            char  *x1385 = 0/*null*/;
            if (x1346) {
              x1385 = x1344;
            } else {
              int x1380 = x1345 >= 'a';
              int x1382;
              if (x1380) {
                int x1381 = x1345 <= 'f';
                x1382 = x1381;
              } else {
                x1382 = 0/*false*/;
              }
              if (x1382) {
                x1383 = 0/*false*/;
                x1384 = x1345;
                char  *x1350 = x1344+1;
                x1385 = x1350;
              } else {
                x1385 = x1344;
              }
            }
            int x1397 = x1383;
            if (x1397) {
              char  *x1398 = x1385;
              x1340 = 0/*false*/;
            } else {
              char x1401 = x1384;
              char  *x1404 = x1385;
              int x1405 = x1341;
              int x1406 = x1405 < 0;
              int x1413;
              if (x1406) {
                x1413 = x1405;
              } else {
                int x1409 = x1405 > x1408;
                int x1412;
                if (x1409) {
                  x1412 = -1;
                } else {
                  char x1402 = x1401 - 'a';
                  int x1403 = 10 + x1402;
                  int x1410 = x1405 * 16;
                  int x1411 = x1410 + x1403;
                  x1412 = x1411;
                }
                x1413 = x1412;
              }
              x1341 = x1413;
              x1339 = x1404;
            }
          } else {
            int x1419 = x1352;
            char  *x1420 = x1353;
            int x1421 = x1341;
            int x1422 = x1421 < 0;
            int x1427;
            if (x1422) {
              x1427 = x1421;
            } else {
              int x1423 = x1421 > x1408;
              int x1426;
              if (x1423) {
                x1426 = -1;
              } else {
                int x1424 = x1421 * 16;
                int x1425 = x1424 + x1419;
                x1426 = x1425;
              }
              x1427 = x1426;
            }
            x1341 = x1427;
            x1339 = x1420;
          }
        }
        int x1455 = x1341;
        char  *x1456 = x1339;
        x1260 = 0/*false*/;
        x1261 = x1455;
        x1262 = x1456;
      }
      int x1462 = x1260;
      if (x1462) {
        char  *x1463 = x1262;
        x1259 = x1463;
      } else {
        int x1466 = x1261;
        char  *x1467 = x1262;
        int x1472 = 1/*true*/;
        char x1473 = '\0';
        char  *x1474 = 0/*null*/;
        char x1468 = x1467[0];
        int x1469 = x1468 == '\0';
        if (x1469) {
          x1474 = x1467;
        } else {
          int x1470 = x1468 == '\n';
          if (x1470) {
            x1472 = 0/*false*/;
            x1473 = x1468;
            char  *x1471 = x1467+1;
            x1474 = x1471;
          } else {
            x1474 = x1467;
          }
        }
        int x1486 = x1472;
        if (x1486) {
          char  *x1487 = x1474;
          x1259 = x1487;
        } else {
          char x1490 = x1473;
          char  *x1491 = x1474;
          x1257 = 0/*false*/;
          x1258 = x1466;
          x1259 = x1491;
        }
      }
      int x1499 = x1257;
      if (x1499) {
        char  *x1500 = x1259;
        x1246 = 0/*false*/;
      } else {
        int x1503 = x1258;
        char  *x1504 = x1259;
        int x1506 = 1/*true*/;
        char  *x1507 = x1504;
        /*@
        loop invariant ((0<=x1509) && ((strlen(x1507)>=0) && \valid(x1507+(0..(strlen(x1507)+1)-1))));
        loop assigns x1509, x1506, x1507;
        loop variant (x1503-x1509);
        */
        for(int x1509=0; x1509 < x1503; x1509++) {
          int x1510 = x1506;
          if (x1510) {
            char  *x1511 = x1507;
            char x1512 = x1511[0];
            int x1513 = x1512 == '\0';
            if (x1513) {
              x1506 = 0/*false*/;
            } else {
              char  *x1514 = x1511+1;
              x1507 = x1514;
            }
          } else {
          }
        }
        int x1543 = x1506;
        char  *x1544 = x1507;
        int x1505 = x1503 < 0;
        if (x1505) {
          x1246 = 0/*false*/;
        } else {
          int x1547 = 1/*true*/;
          int x1548 = 0;
          char  *x1549 = 0/*null*/;
          int x1550 = 1/*true*/;
          char  *x1552 = 0/*null*/;
          if (x1543) {
            x1550 = 0/*false*/;
            x1552 = x1544;
          } else {
            x1552 = x1504;
          }
          int x1560 = x1550;
          if (x1560) {
            char  *x1561 = x1552;
            x1549 = x1561;
          } else {
            char  *x1565 = x1552;
            x1547 = 0/*false*/;
            x1548 = x1503;
            x1549 = x1565;
          }
          int x1571 = x1547;
          if (x1571) {
            char  *x1572 = x1549;
            x1246 = 0/*false*/;
          } else {
            int x1575 = x1548;
            char  *x1576 = x1549;
            int x1581 = 1/*true*/;
            char x1582 = '\0';
            char  *x1583 = 0/*null*/;
            char x1577 = x1576[0];
            int x1578 = x1577 == '\0';
            if (x1578) {
              x1583 = x1576;
            } else {
              int x1579 = x1577 == '\n';
              if (x1579) {
                x1581 = 0/*false*/;
                x1582 = x1577;
                char  *x1580 = x1576+1;
                x1583 = x1580;
              } else {
                x1583 = x1576;
              }
            }
            int x1595 = x1581;
            if (x1595) {
              char  *x1596 = x1583;
              x1246 = 0/*false*/;
            } else {
              char x1599 = x1582;
              char  *x1600 = x1583;
              int x1601 = x1247;
              int x1602 = x1601 < 0;
              int x1607;
              if (x1602) {
                x1607 = x1601;
              } else {
                int x1603 = x343 - x1575;
                int x1604 = x1601 > x1603;
                int x1606;
                if (x1604) {
                  x1606 = -1;
                } else {
                  int x1605 = x1601 + x1575;
                  x1606 = x1605;
                }
                x1607 = x1606;
              }
              x1247 = x1607;
              x1245 = x1600;
            }
          }
        }
      }
    }
    int x1641 = x1247;
    char  *x1642 = x1245;
    int x1644 = 1/*true*/;
    char  *x1645 = x1243;
    /*@
    loop invariant ((0<=x1647) && ((strlen(x1645)>=0) && \valid(x1645+(0..(strlen(x1645)+1)-1))));
    loop assigns x1647, x1644, x1645;
    loop variant (x1242-x1647);
    */
    for(int x1647=0; x1647 < x1242; x1647++) {
      int x1648 = x1644;
      if (x1648) {
        char  *x1649 = x1645;
        char x1650 = x1649[0];
        int x1651 = x1650 == '\0';
        if (x1651) {
          x1644 = 0/*false*/;
        } else {
          char  *x1652 = x1649+1;
          x1645 = x1652;
        }
      } else {
      }
    }
    int x1681 = x1644;
    char  *x1682 = x1645;
    int x1244 = x1242 == -3;
    if (x1244) {
      char x1683 = x1642[0];
      int x1684 = x1683 == '\0';
      if (x1684) {
        x2 = x1641;
      } else {
      }
    } else {
      int x1643 = x1242 < 0;
      if (x1643) {
      } else {
        int x1689 = 1/*true*/;
        int x1690 = 0;
        char  *x1691 = 0/*null*/;
        int x1692 = 1/*true*/;
        char  *x1694 = 0/*null*/;
        if (x1681) {
          x1692 = 0/*false*/;
          x1694 = x1682;
        } else {
          x1694 = x1243;
        }
        int x1702 = x1692;
        if (x1702) {
          char  *x1703 = x1694;
          x1691 = x1703;
        } else {
          char  *x1707 = x1694;
          x1689 = 0/*false*/;
          x1690 = x1242;
          x1691 = x1707;
        }
        int x1713 = x1689;
        if (x1713) {
          char  *x1714 = x1691;
        } else {
          int x1716 = x1690;
          char  *x1717 = x1691;
          int x1722 = 1/*true*/;
          char x1723 = '\0';
          char  *x1724 = 0/*null*/;
          char x1718 = x1717[0];
          int x1719 = x1718 == '\0';
          if (x1719) {
            x1724 = x1717;
          } else {
            int x1720 = x1718 == '\n';
            if (x1720) {
              x1722 = 0/*false*/;
              x1723 = x1718;
              char  *x1721 = x1717+1;
              x1724 = x1721;
            } else {
              x1724 = x1717;
            }
          }
          int x1736 = x1722;
          if (x1736) {
            char  *x1737 = x1724;
          } else {
            char x1739 = x1723;
            char  *x1740 = x1724;
            char x1741 = x1740[0];
            int x1742 = x1741 == '\0';
            if (x1742) {
              x2 = x1716;
            } else {
            }
          }
        }
      }
    }
  }
  int x1756 = x2;
  return x1756;
}
/*@
requires ((strlen(x1775)>=0) && \valid(x1775+(0..(strlen(x1775)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_HTTP(char  * x1775) {
  char  *x1777 = x1775;
  int x1782 = 1/*true*/;
  char x1783 = '\0';
  char  *x1784 = 0/*null*/;
  char x1778 = x1775[0];
  int x1779 = x1778 == '\0';
  if (x1779) {
    x1784 = x1775;
  } else {
    int x1780 = x1778 == 'H';
    if (x1780) {
      x1782 = 0/*false*/;
      x1783 = x1778;
      char  *x1781 = x1775+1;
      x1784 = x1781;
    } else {
      x1784 = x1775;
    }
  }
  int x1796 = x1782;
  if (x1796) {
    char  *x1797 = x1784;
    x1777 = 0;
  } else {
    char x1800 = x1783;
    char  *x1801 = x1784;
    int x1806 = 1/*true*/;
    char x1807 = '\0';
    char  *x1808 = 0/*null*/;
    char x1802 = x1801[0];
    int x1803 = x1802 == '\0';
    if (x1803) {
      x1808 = x1801;
    } else {
      int x1804 = x1802 == 'T';
      if (x1804) {
        x1806 = 0/*false*/;
        x1807 = x1802;
        char  *x1805 = x1801+1;
        x1808 = x1805;
      } else {
        x1808 = x1801;
      }
    }
    int x1820 = x1806;
    if (x1820) {
      char  *x1821 = x1808;
      x1777 = 0;
    } else {
      char x1824 = x1807;
      char  *x1825 = x1808;
      int x1830 = 1/*true*/;
      char x1831 = '\0';
      char  *x1832 = 0/*null*/;
      char x1826 = x1825[0];
      int x1827 = x1826 == '\0';
      if (x1827) {
        x1832 = x1825;
      } else {
        int x1828 = x1826 == 'T';
        if (x1828) {
          x1830 = 0/*false*/;
          x1831 = x1826;
          char  *x1829 = x1825+1;
          x1832 = x1829;
        } else {
          x1832 = x1825;
        }
      }
      int x1844 = x1830;
      if (x1844) {
        char  *x1845 = x1832;
        x1777 = 0;
      } else {
        char x1848 = x1831;
        char  *x1849 = x1832;
        int x1854 = 1/*true*/;
        char x1855 = '\0';
        char  *x1856 = 0/*null*/;
        char x1850 = x1849[0];
        int x1851 = x1850 == '\0';
        if (x1851) {
          x1856 = x1849;
        } else {
          int x1852 = x1850 == 'P';
          if (x1852) {
            x1854 = 0/*false*/;
            x1855 = x1850;
            char  *x1853 = x1849+1;
            x1856 = x1853;
          } else {
            x1856 = x1849;
          }
        }
        int x1868 = x1854;
        if (x1868) {
          char  *x1869 = x1856;
          x1777 = 0;
        } else {
          char x1872 = x1855;
          char  *x1873 = x1856;
          int x1878 = 1/*true*/;
          char x1879 = '\0';
          char  *x1880 = 0/*null*/;
          char x1874 = x1873[0];
          int x1875 = x1874 == '\0';
          if (x1875) {
            x1880 = x1873;
          } else {
            int x1876 = x1874 == '/';
            if (x1876) {
              x1878 = 0/*false*/;
              x1879 = x1874;
              char  *x1877 = x1873+1;
              x1880 = x1877;
            } else {
              x1880 = x1873;
            }
          }
          int x1892 = x1878;
          if (x1892) {
            char  *x1893 = x1880;
            x1777 = 0;
          } else {
            char x1896 = x1879;
            char  *x1897 = x1880;
            x1777 = x1897;
          }
        }
      }
    }
  }
  char  *x1909 = x1777;
  return x1909;
}
/*@
requires ((strlen(x1931)>=0) && \valid(x1931+(0..(strlen(x1931)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_ContentLength(char  * x1931) {
  char  *x1933 = x1931;
  int x1938 = 1/*true*/;
  char x1939 = '\0';
  char  *x1940 = 0/*null*/;
  char x1934 = x1931[0];
  int x1935 = x1934 == '\0';
  if (x1935) {
    x1940 = x1931;
  } else {
    int x1936 = x1934 == 'C';
    if (x1936) {
      x1938 = 0/*false*/;
      x1939 = x1934;
      char  *x1937 = x1931+1;
      x1940 = x1937;
    } else {
      x1940 = x1931;
    }
  }
  int x1952 = x1938;
  if (x1952) {
    char  *x1953 = x1940;
    x1933 = 0;
  } else {
    char x1956 = x1939;
    char  *x1957 = x1940;
    int x1962 = 1/*true*/;
    char x1963 = '\0';
    char  *x1964 = 0/*null*/;
    char x1958 = x1957[0];
    int x1959 = x1958 == '\0';
    if (x1959) {
      x1964 = x1957;
    } else {
      int x1960 = x1958 == 'o';
      if (x1960) {
        x1962 = 0/*false*/;
        x1963 = x1958;
        char  *x1961 = x1957+1;
        x1964 = x1961;
      } else {
        x1964 = x1957;
      }
    }
    int x1976 = x1962;
    if (x1976) {
      char  *x1977 = x1964;
      x1933 = 0;
    } else {
      char x1980 = x1963;
      char  *x1981 = x1964;
      int x1986 = 1/*true*/;
      char x1987 = '\0';
      char  *x1988 = 0/*null*/;
      char x1982 = x1981[0];
      int x1983 = x1982 == '\0';
      if (x1983) {
        x1988 = x1981;
      } else {
        int x1984 = x1982 == 'n';
        if (x1984) {
          x1986 = 0/*false*/;
          x1987 = x1982;
          char  *x1985 = x1981+1;
          x1988 = x1985;
        } else {
          x1988 = x1981;
        }
      }
      int x2000 = x1986;
      if (x2000) {
        char  *x2001 = x1988;
        x1933 = 0;
      } else {
        char x2004 = x1987;
        char  *x2005 = x1988;
        int x2010 = 1/*true*/;
        char x2011 = '\0';
        char  *x2012 = 0/*null*/;
        char x2006 = x2005[0];
        int x2007 = x2006 == '\0';
        if (x2007) {
          x2012 = x2005;
        } else {
          int x2008 = x2006 == 't';
          if (x2008) {
            x2010 = 0/*false*/;
            x2011 = x2006;
            char  *x2009 = x2005+1;
            x2012 = x2009;
          } else {
            x2012 = x2005;
          }
        }
        int x2024 = x2010;
        if (x2024) {
          char  *x2025 = x2012;
          x1933 = 0;
        } else {
          char x2028 = x2011;
          char  *x2029 = x2012;
          int x2034 = 1/*true*/;
          char x2035 = '\0';
          char  *x2036 = 0/*null*/;
          char x2030 = x2029[0];
          int x2031 = x2030 == '\0';
          if (x2031) {
            x2036 = x2029;
          } else {
            int x2032 = x2030 == 'e';
            if (x2032) {
              x2034 = 0/*false*/;
              x2035 = x2030;
              char  *x2033 = x2029+1;
              x2036 = x2033;
            } else {
              x2036 = x2029;
            }
          }
          int x2048 = x2034;
          if (x2048) {
            char  *x2049 = x2036;
            x1933 = 0;
          } else {
            char x2052 = x2035;
            char  *x2053 = x2036;
            int x2058 = 1/*true*/;
            char x2059 = '\0';
            char  *x2060 = 0/*null*/;
            char x2054 = x2053[0];
            int x2055 = x2054 == '\0';
            if (x2055) {
              x2060 = x2053;
            } else {
              int x2056 = x2054 == 'n';
              if (x2056) {
                x2058 = 0/*false*/;
                x2059 = x2054;
                char  *x2057 = x2053+1;
                x2060 = x2057;
              } else {
                x2060 = x2053;
              }
            }
            int x2072 = x2058;
            if (x2072) {
              char  *x2073 = x2060;
              x1933 = 0;
            } else {
              char x2076 = x2059;
              char  *x2077 = x2060;
              int x2082 = 1/*true*/;
              char x2083 = '\0';
              char  *x2084 = 0/*null*/;
              char x2078 = x2077[0];
              int x2079 = x2078 == '\0';
              if (x2079) {
                x2084 = x2077;
              } else {
                int x2080 = x2078 == 't';
                if (x2080) {
                  x2082 = 0/*false*/;
                  x2083 = x2078;
                  char  *x2081 = x2077+1;
                  x2084 = x2081;
                } else {
                  x2084 = x2077;
                }
              }
              int x2096 = x2082;
              if (x2096) {
                char  *x2097 = x2084;
                x1933 = 0;
              } else {
                char x2100 = x2083;
                char  *x2101 = x2084;
                int x2106 = 1/*true*/;
                char x2107 = '\0';
                char  *x2108 = 0/*null*/;
                char x2102 = x2101[0];
                int x2103 = x2102 == '\0';
                if (x2103) {
                  x2108 = x2101;
                } else {
                  int x2104 = x2102 == '-';
                  if (x2104) {
                    x2106 = 0/*false*/;
                    x2107 = x2102;
                    char  *x2105 = x2101+1;
                    x2108 = x2105;
                  } else {
                    x2108 = x2101;
                  }
                }
                int x2120 = x2106;
                if (x2120) {
                  char  *x2121 = x2108;
                  x1933 = 0;
                } else {
                  char x2124 = x2107;
                  char  *x2125 = x2108;
                  int x2130 = 1/*true*/;
                  char x2131 = '\0';
                  char  *x2132 = 0/*null*/;
                  char x2126 = x2125[0];
                  int x2127 = x2126 == '\0';
                  if (x2127) {
                    x2132 = x2125;
                  } else {
                    int x2128 = x2126 == 'L';
                    if (x2128) {
                      x2130 = 0/*false*/;
                      x2131 = x2126;
                      char  *x2129 = x2125+1;
                      x2132 = x2129;
                    } else {
                      x2132 = x2125;
                    }
                  }
                  int x2144 = x2130;
                  if (x2144) {
                    char  *x2145 = x2132;
                    x1933 = 0;
                  } else {
                    char x2148 = x2131;
                    char  *x2149 = x2132;
                    int x2154 = 1/*true*/;
                    char x2155 = '\0';
                    char  *x2156 = 0/*null*/;
                    char x2150 = x2149[0];
                    int x2151 = x2150 == '\0';
                    if (x2151) {
                      x2156 = x2149;
                    } else {
                      int x2152 = x2150 == 'e';
                      if (x2152) {
                        x2154 = 0/*false*/;
                        x2155 = x2150;
                        char  *x2153 = x2149+1;
                        x2156 = x2153;
                      } else {
                        x2156 = x2149;
                      }
                    }
                    int x2168 = x2154;
                    if (x2168) {
                      char  *x2169 = x2156;
                      x1933 = 0;
                    } else {
                      char x2172 = x2155;
                      char  *x2173 = x2156;
                      int x2178 = 1/*true*/;
                      char x2179 = '\0';
                      char  *x2180 = 0/*null*/;
                      char x2174 = x2173[0];
                      int x2175 = x2174 == '\0';
                      if (x2175) {
                        x2180 = x2173;
                      } else {
                        int x2176 = x2174 == 'n';
                        if (x2176) {
                          x2178 = 0/*false*/;
                          x2179 = x2174;
                          char  *x2177 = x2173+1;
                          x2180 = x2177;
                        } else {
                          x2180 = x2173;
                        }
                      }
                      int x2192 = x2178;
                      if (x2192) {
                        char  *x2193 = x2180;
                        x1933 = 0;
                      } else {
                        char x2196 = x2179;
                        char  *x2197 = x2180;
                        int x2202 = 1/*true*/;
                        char x2203 = '\0';
                        char  *x2204 = 0/*null*/;
                        char x2198 = x2197[0];
                        int x2199 = x2198 == '\0';
                        if (x2199) {
                          x2204 = x2197;
                        } else {
                          int x2200 = x2198 == 'g';
                          if (x2200) {
                            x2202 = 0/*false*/;
                            x2203 = x2198;
                            char  *x2201 = x2197+1;
                            x2204 = x2201;
                          } else {
                            x2204 = x2197;
                          }
                        }
                        int x2216 = x2202;
                        if (x2216) {
                          char  *x2217 = x2204;
                          x1933 = 0;
                        } else {
                          char x2220 = x2203;
                          char  *x2221 = x2204;
                          int x2226 = 1/*true*/;
                          char x2227 = '\0';
                          char  *x2228 = 0/*null*/;
                          char x2222 = x2221[0];
                          int x2223 = x2222 == '\0';
                          if (x2223) {
                            x2228 = x2221;
                          } else {
                            int x2224 = x2222 == 't';
                            if (x2224) {
                              x2226 = 0/*false*/;
                              x2227 = x2222;
                              char  *x2225 = x2221+1;
                              x2228 = x2225;
                            } else {
                              x2228 = x2221;
                            }
                          }
                          int x2240 = x2226;
                          if (x2240) {
                            char  *x2241 = x2228;
                            x1933 = 0;
                          } else {
                            char x2244 = x2227;
                            char  *x2245 = x2228;
                            int x2250 = 1/*true*/;
                            char x2251 = '\0';
                            char  *x2252 = 0/*null*/;
                            char x2246 = x2245[0];
                            int x2247 = x2246 == '\0';
                            if (x2247) {
                              x2252 = x2245;
                            } else {
                              int x2248 = x2246 == 'h';
                              if (x2248) {
                                x2250 = 0/*false*/;
                                x2251 = x2246;
                                char  *x2249 = x2245+1;
                                x2252 = x2249;
                              } else {
                                x2252 = x2245;
                              }
                            }
                            int x2264 = x2250;
                            if (x2264) {
                              char  *x2265 = x2252;
                              x1933 = 0;
                            } else {
                              char x2268 = x2251;
                              char  *x2269 = x2252;
                              x1933 = x2269;
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
  char  *x2299 = x1933;
  return x2299;
}
/*@
requires ((strlen(x2321)>=0) && \valid(x2321+(0..(strlen(x2321)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_TransferEncoding(char  * x2321) {
  char  *x2323 = x2321;
  int x2328 = 1/*true*/;
  char x2329 = '\0';
  char  *x2330 = 0/*null*/;
  char x2324 = x2321[0];
  int x2325 = x2324 == '\0';
  if (x2325) {
    x2330 = x2321;
  } else {
    int x2326 = x2324 == 'T';
    if (x2326) {
      x2328 = 0/*false*/;
      x2329 = x2324;
      char  *x2327 = x2321+1;
      x2330 = x2327;
    } else {
      x2330 = x2321;
    }
  }
  int x2342 = x2328;
  if (x2342) {
    char  *x2343 = x2330;
    x2323 = 0;
  } else {
    char x2346 = x2329;
    char  *x2347 = x2330;
    int x2352 = 1/*true*/;
    char x2353 = '\0';
    char  *x2354 = 0/*null*/;
    char x2348 = x2347[0];
    int x2349 = x2348 == '\0';
    if (x2349) {
      x2354 = x2347;
    } else {
      int x2350 = x2348 == 'r';
      if (x2350) {
        x2352 = 0/*false*/;
        x2353 = x2348;
        char  *x2351 = x2347+1;
        x2354 = x2351;
      } else {
        x2354 = x2347;
      }
    }
    int x2366 = x2352;
    if (x2366) {
      char  *x2367 = x2354;
      x2323 = 0;
    } else {
      char x2370 = x2353;
      char  *x2371 = x2354;
      int x2376 = 1/*true*/;
      char x2377 = '\0';
      char  *x2378 = 0/*null*/;
      char x2372 = x2371[0];
      int x2373 = x2372 == '\0';
      if (x2373) {
        x2378 = x2371;
      } else {
        int x2374 = x2372 == 'a';
        if (x2374) {
          x2376 = 0/*false*/;
          x2377 = x2372;
          char  *x2375 = x2371+1;
          x2378 = x2375;
        } else {
          x2378 = x2371;
        }
      }
      int x2390 = x2376;
      if (x2390) {
        char  *x2391 = x2378;
        x2323 = 0;
      } else {
        char x2394 = x2377;
        char  *x2395 = x2378;
        int x2400 = 1/*true*/;
        char x2401 = '\0';
        char  *x2402 = 0/*null*/;
        char x2396 = x2395[0];
        int x2397 = x2396 == '\0';
        if (x2397) {
          x2402 = x2395;
        } else {
          int x2398 = x2396 == 'n';
          if (x2398) {
            x2400 = 0/*false*/;
            x2401 = x2396;
            char  *x2399 = x2395+1;
            x2402 = x2399;
          } else {
            x2402 = x2395;
          }
        }
        int x2414 = x2400;
        if (x2414) {
          char  *x2415 = x2402;
          x2323 = 0;
        } else {
          char x2418 = x2401;
          char  *x2419 = x2402;
          int x2424 = 1/*true*/;
          char x2425 = '\0';
          char  *x2426 = 0/*null*/;
          char x2420 = x2419[0];
          int x2421 = x2420 == '\0';
          if (x2421) {
            x2426 = x2419;
          } else {
            int x2422 = x2420 == 's';
            if (x2422) {
              x2424 = 0/*false*/;
              x2425 = x2420;
              char  *x2423 = x2419+1;
              x2426 = x2423;
            } else {
              x2426 = x2419;
            }
          }
          int x2438 = x2424;
          if (x2438) {
            char  *x2439 = x2426;
            x2323 = 0;
          } else {
            char x2442 = x2425;
            char  *x2443 = x2426;
            int x2448 = 1/*true*/;
            char x2449 = '\0';
            char  *x2450 = 0/*null*/;
            char x2444 = x2443[0];
            int x2445 = x2444 == '\0';
            if (x2445) {
              x2450 = x2443;
            } else {
              int x2446 = x2444 == 'f';
              if (x2446) {
                x2448 = 0/*false*/;
                x2449 = x2444;
                char  *x2447 = x2443+1;
                x2450 = x2447;
              } else {
                x2450 = x2443;
              }
            }
            int x2462 = x2448;
            if (x2462) {
              char  *x2463 = x2450;
              x2323 = 0;
            } else {
              char x2466 = x2449;
              char  *x2467 = x2450;
              int x2472 = 1/*true*/;
              char x2473 = '\0';
              char  *x2474 = 0/*null*/;
              char x2468 = x2467[0];
              int x2469 = x2468 == '\0';
              if (x2469) {
                x2474 = x2467;
              } else {
                int x2470 = x2468 == 'e';
                if (x2470) {
                  x2472 = 0/*false*/;
                  x2473 = x2468;
                  char  *x2471 = x2467+1;
                  x2474 = x2471;
                } else {
                  x2474 = x2467;
                }
              }
              int x2486 = x2472;
              if (x2486) {
                char  *x2487 = x2474;
                x2323 = 0;
              } else {
                char x2490 = x2473;
                char  *x2491 = x2474;
                int x2496 = 1/*true*/;
                char x2497 = '\0';
                char  *x2498 = 0/*null*/;
                char x2492 = x2491[0];
                int x2493 = x2492 == '\0';
                if (x2493) {
                  x2498 = x2491;
                } else {
                  int x2494 = x2492 == 'r';
                  if (x2494) {
                    x2496 = 0/*false*/;
                    x2497 = x2492;
                    char  *x2495 = x2491+1;
                    x2498 = x2495;
                  } else {
                    x2498 = x2491;
                  }
                }
                int x2510 = x2496;
                if (x2510) {
                  char  *x2511 = x2498;
                  x2323 = 0;
                } else {
                  char x2514 = x2497;
                  char  *x2515 = x2498;
                  int x2520 = 1/*true*/;
                  char x2521 = '\0';
                  char  *x2522 = 0/*null*/;
                  char x2516 = x2515[0];
                  int x2517 = x2516 == '\0';
                  if (x2517) {
                    x2522 = x2515;
                  } else {
                    int x2518 = x2516 == '-';
                    if (x2518) {
                      x2520 = 0/*false*/;
                      x2521 = x2516;
                      char  *x2519 = x2515+1;
                      x2522 = x2519;
                    } else {
                      x2522 = x2515;
                    }
                  }
                  int x2534 = x2520;
                  if (x2534) {
                    char  *x2535 = x2522;
                    x2323 = 0;
                  } else {
                    char x2538 = x2521;
                    char  *x2539 = x2522;
                    int x2544 = 1/*true*/;
                    char x2545 = '\0';
                    char  *x2546 = 0/*null*/;
                    char x2540 = x2539[0];
                    int x2541 = x2540 == '\0';
                    if (x2541) {
                      x2546 = x2539;
                    } else {
                      int x2542 = x2540 == 'E';
                      if (x2542) {
                        x2544 = 0/*false*/;
                        x2545 = x2540;
                        char  *x2543 = x2539+1;
                        x2546 = x2543;
                      } else {
                        x2546 = x2539;
                      }
                    }
                    int x2558 = x2544;
                    if (x2558) {
                      char  *x2559 = x2546;
                      x2323 = 0;
                    } else {
                      char x2562 = x2545;
                      char  *x2563 = x2546;
                      int x2568 = 1/*true*/;
                      char x2569 = '\0';
                      char  *x2570 = 0/*null*/;
                      char x2564 = x2563[0];
                      int x2565 = x2564 == '\0';
                      if (x2565) {
                        x2570 = x2563;
                      } else {
                        int x2566 = x2564 == 'n';
                        if (x2566) {
                          x2568 = 0/*false*/;
                          x2569 = x2564;
                          char  *x2567 = x2563+1;
                          x2570 = x2567;
                        } else {
                          x2570 = x2563;
                        }
                      }
                      int x2582 = x2568;
                      if (x2582) {
                        char  *x2583 = x2570;
                        x2323 = 0;
                      } else {
                        char x2586 = x2569;
                        char  *x2587 = x2570;
                        int x2592 = 1/*true*/;
                        char x2593 = '\0';
                        char  *x2594 = 0/*null*/;
                        char x2588 = x2587[0];
                        int x2589 = x2588 == '\0';
                        if (x2589) {
                          x2594 = x2587;
                        } else {
                          int x2590 = x2588 == 'c';
                          if (x2590) {
                            x2592 = 0/*false*/;
                            x2593 = x2588;
                            char  *x2591 = x2587+1;
                            x2594 = x2591;
                          } else {
                            x2594 = x2587;
                          }
                        }
                        int x2606 = x2592;
                        if (x2606) {
                          char  *x2607 = x2594;
                          x2323 = 0;
                        } else {
                          char x2610 = x2593;
                          char  *x2611 = x2594;
                          int x2616 = 1/*true*/;
                          char x2617 = '\0';
                          char  *x2618 = 0/*null*/;
                          char x2612 = x2611[0];
                          int x2613 = x2612 == '\0';
                          if (x2613) {
                            x2618 = x2611;
                          } else {
                            int x2614 = x2612 == 'o';
                            if (x2614) {
                              x2616 = 0/*false*/;
                              x2617 = x2612;
                              char  *x2615 = x2611+1;
                              x2618 = x2615;
                            } else {
                              x2618 = x2611;
                            }
                          }
                          int x2630 = x2616;
                          if (x2630) {
                            char  *x2631 = x2618;
                            x2323 = 0;
                          } else {
                            char x2634 = x2617;
                            char  *x2635 = x2618;
                            int x2640 = 1/*true*/;
                            char x2641 = '\0';
                            char  *x2642 = 0/*null*/;
                            char x2636 = x2635[0];
                            int x2637 = x2636 == '\0';
                            if (x2637) {
                              x2642 = x2635;
                            } else {
                              int x2638 = x2636 == 'd';
                              if (x2638) {
                                x2640 = 0/*false*/;
                                x2641 = x2636;
                                char  *x2639 = x2635+1;
                                x2642 = x2639;
                              } else {
                                x2642 = x2635;
                              }
                            }
                            int x2654 = x2640;
                            if (x2654) {
                              char  *x2655 = x2642;
                              x2323 = 0;
                            } else {
                              char x2658 = x2641;
                              char  *x2659 = x2642;
                              int x2664 = 1/*true*/;
                              char x2665 = '\0';
                              char  *x2666 = 0/*null*/;
                              char x2660 = x2659[0];
                              int x2661 = x2660 == '\0';
                              if (x2661) {
                                x2666 = x2659;
                              } else {
                                int x2662 = x2660 == 'i';
                                if (x2662) {
                                  x2664 = 0/*false*/;
                                  x2665 = x2660;
                                  char  *x2663 = x2659+1;
                                  x2666 = x2663;
                                } else {
                                  x2666 = x2659;
                                }
                              }
                              int x2678 = x2664;
                              if (x2678) {
                                char  *x2679 = x2666;
                                x2323 = 0;
                              } else {
                                char x2682 = x2665;
                                char  *x2683 = x2666;
                                int x2688 = 1/*true*/;
                                char x2689 = '\0';
                                char  *x2690 = 0/*null*/;
                                char x2684 = x2683[0];
                                int x2685 = x2684 == '\0';
                                if (x2685) {
                                  x2690 = x2683;
                                } else {
                                  int x2686 = x2684 == 'n';
                                  if (x2686) {
                                    x2688 = 0/*false*/;
                                    x2689 = x2684;
                                    char  *x2687 = x2683+1;
                                    x2690 = x2687;
                                  } else {
                                    x2690 = x2683;
                                  }
                                }
                                int x2702 = x2688;
                                if (x2702) {
                                  char  *x2703 = x2690;
                                  x2323 = 0;
                                } else {
                                  char x2706 = x2689;
                                  char  *x2707 = x2690;
                                  int x2712 = 1/*true*/;
                                  char x2713 = '\0';
                                  char  *x2714 = 0/*null*/;
                                  char x2708 = x2707[0];
                                  int x2709 = x2708 == '\0';
                                  if (x2709) {
                                    x2714 = x2707;
                                  } else {
                                    int x2710 = x2708 == 'g';
                                    if (x2710) {
                                      x2712 = 0/*false*/;
                                      x2713 = x2708;
                                      char  *x2711 = x2707+1;
                                      x2714 = x2711;
                                    } else {
                                      x2714 = x2707;
                                    }
                                  }
                                  int x2726 = x2712;
                                  if (x2726) {
                                    char  *x2727 = x2714;
                                    x2323 = 0;
                                  } else {
                                    char x2730 = x2713;
                                    char  *x2731 = x2714;
                                    x2323 = x2731;
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
  char  *x2767 = x2323;
  return x2767;
}
/*@
requires ((strlen(x2789)>=0) && \valid(x2789+(0..(strlen(x2789)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_chunked(char  * x2789) {
  char  *x2791 = x2789;
  int x2796 = 1/*true*/;
  char x2797 = '\0';
  char  *x2798 = 0/*null*/;
  char x2792 = x2789[0];
  int x2793 = x2792 == '\0';
  if (x2793) {
    x2798 = x2789;
  } else {
    int x2794 = x2792 == 'c';
    if (x2794) {
      x2796 = 0/*false*/;
      x2797 = x2792;
      char  *x2795 = x2789+1;
      x2798 = x2795;
    } else {
      x2798 = x2789;
    }
  }
  int x2810 = x2796;
  if (x2810) {
    char  *x2811 = x2798;
    x2791 = 0;
  } else {
    char x2814 = x2797;
    char  *x2815 = x2798;
    int x2820 = 1/*true*/;
    char x2821 = '\0';
    char  *x2822 = 0/*null*/;
    char x2816 = x2815[0];
    int x2817 = x2816 == '\0';
    if (x2817) {
      x2822 = x2815;
    } else {
      int x2818 = x2816 == 'h';
      if (x2818) {
        x2820 = 0/*false*/;
        x2821 = x2816;
        char  *x2819 = x2815+1;
        x2822 = x2819;
      } else {
        x2822 = x2815;
      }
    }
    int x2834 = x2820;
    if (x2834) {
      char  *x2835 = x2822;
      x2791 = 0;
    } else {
      char x2838 = x2821;
      char  *x2839 = x2822;
      int x2844 = 1/*true*/;
      char x2845 = '\0';
      char  *x2846 = 0/*null*/;
      char x2840 = x2839[0];
      int x2841 = x2840 == '\0';
      if (x2841) {
        x2846 = x2839;
      } else {
        int x2842 = x2840 == 'u';
        if (x2842) {
          x2844 = 0/*false*/;
          x2845 = x2840;
          char  *x2843 = x2839+1;
          x2846 = x2843;
        } else {
          x2846 = x2839;
        }
      }
      int x2858 = x2844;
      if (x2858) {
        char  *x2859 = x2846;
        x2791 = 0;
      } else {
        char x2862 = x2845;
        char  *x2863 = x2846;
        int x2868 = 1/*true*/;
        char x2869 = '\0';
        char  *x2870 = 0/*null*/;
        char x2864 = x2863[0];
        int x2865 = x2864 == '\0';
        if (x2865) {
          x2870 = x2863;
        } else {
          int x2866 = x2864 == 'n';
          if (x2866) {
            x2868 = 0/*false*/;
            x2869 = x2864;
            char  *x2867 = x2863+1;
            x2870 = x2867;
          } else {
            x2870 = x2863;
          }
        }
        int x2882 = x2868;
        if (x2882) {
          char  *x2883 = x2870;
          x2791 = 0;
        } else {
          char x2886 = x2869;
          char  *x2887 = x2870;
          int x2892 = 1/*true*/;
          char x2893 = '\0';
          char  *x2894 = 0/*null*/;
          char x2888 = x2887[0];
          int x2889 = x2888 == '\0';
          if (x2889) {
            x2894 = x2887;
          } else {
            int x2890 = x2888 == 'k';
            if (x2890) {
              x2892 = 0/*false*/;
              x2893 = x2888;
              char  *x2891 = x2887+1;
              x2894 = x2891;
            } else {
              x2894 = x2887;
            }
          }
          int x2906 = x2892;
          if (x2906) {
            char  *x2907 = x2894;
            x2791 = 0;
          } else {
            char x2910 = x2893;
            char  *x2911 = x2894;
            int x2916 = 1/*true*/;
            char x2917 = '\0';
            char  *x2918 = 0/*null*/;
            char x2912 = x2911[0];
            int x2913 = x2912 == '\0';
            if (x2913) {
              x2918 = x2911;
            } else {
              int x2914 = x2912 == 'e';
              if (x2914) {
                x2916 = 0/*false*/;
                x2917 = x2912;
                char  *x2915 = x2911+1;
                x2918 = x2915;
              } else {
                x2918 = x2911;
              }
            }
            int x2930 = x2916;
            if (x2930) {
              char  *x2931 = x2918;
              x2791 = 0;
            } else {
              char x2934 = x2917;
              char  *x2935 = x2918;
              int x2940 = 1/*true*/;
              char x2941 = '\0';
              char  *x2942 = 0/*null*/;
              char x2936 = x2935[0];
              int x2937 = x2936 == '\0';
              if (x2937) {
                x2942 = x2935;
              } else {
                int x2938 = x2936 == 'd';
                if (x2938) {
                  x2940 = 0/*false*/;
                  x2941 = x2936;
                  char  *x2939 = x2935+1;
                  x2942 = x2939;
                } else {
                  x2942 = x2935;
                }
              }
              int x2954 = x2940;
              if (x2954) {
                char  *x2955 = x2942;
                x2791 = 0;
              } else {
                char x2958 = x2941;
                char  *x2959 = x2942;
                x2791 = x2959;
              }
            }
          }
        }
      }
    }
  }
  char  *x2975 = x2791;
  return x2975;
}
