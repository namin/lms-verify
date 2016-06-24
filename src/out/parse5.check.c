#include <limits.h>
#include <string.h>
char  * p_chunked(char  * x1823);
char  * p_TransferEncoding(char  * x1825);
char  * p_ContentLength(char  * x1827);
char  * p_HTTP(char  * x1829);
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
      int x445 = 1/*true*/;
      char x446 = '\0';
      char  *x447 = 0/*null*/;
      char x441 = x440[0];
      int x442 = x441 == '\0';
      if (x442) {
        x447 = x440;
      } else {
        int x443 = x441 == '\r';
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
        int x469 = 1/*true*/;
        char x470 = '\0';
        char  *x471 = 0/*null*/;
        char x465 = x464[0];
        int x466 = x465 == '\0';
        if (x466) {
          x471 = x464;
        } else {
          int x467 = x465 == '\n';
          if (x467) {
            x469 = 0/*false*/;
            x470 = x465;
            char  *x468 = x464+1;
            x471 = x468;
          } else {
            x471 = x464;
          }
        }
        int x483 = x469;
        if (x483) {
          char  *x484 = x471;
          x13 = x484;
        } else {
          char x487 = x470;
          char  *x488 = x471;
          x11 = 0/*false*/;
          x12 = x391;
          x13 = x488;
        }
      }
    }
  }
  int x500 = x11;
  if (x500) {
    char  *x501 = x13;
    x10 = x501;
  } else {
    int x504 = x12;
    char  *x505 = x13;
    char  *x506 = x505;
    int x507 = 1/*true*/;
    int x508 = 0;
    int x343 = INT_MAX;
    int x344 = x343 / 10;
    int x345 = x344 - 10;
    int x1244 = -2 == -2;
    /*@
    loop invariant ((strlen(x506)>=0) && \valid(x506+(0..(strlen(x506)+1)-1)));
    loop assigns x506, x507, x508;
    */
    for (;;) {
      int x509 = x507;
      if (!x509) break;
      char  *x511 = x506;
      char  *x512 = p_ContentLength(x511);
      int x514 = 1/*true*/;
      int x515 = 0;
      char  *x516 = 0/*null*/;
      int x517 = 1/*true*/;
      int x518 = 0;
      char  *x519 = 0/*null*/;
      int x520 = 1/*true*/;
      int x521 = 0;
      char  *x522 = 0/*null*/;
      int x523 = 1/*true*/;
      int x524 = 0;
      char  *x525 = 0/*null*/;
      int x526 = 1/*true*/;
      int x527 = 0;
      char  *x528 = 0/*null*/;
      int x529 = 1/*true*/;
      int x530 = 0;
      char  *x531 = 0/*null*/;
      int x532 = 1/*true*/;
      char  *x534 = 0/*null*/;
      int x535 = 0 == x512;
      if (x535) {
        x534 = x511;
      } else {
        x532 = 0/*false*/;
        x534 = x512;
      }
      int x543 = x532;
      if (x543) {
        char  *x544 = x534;
      } else {
        char  *x547 = x534;
        x529 = 0/*false*/;
        x530 = 1;
        x531 = x547;
      }
      int x553 = x529;
      if (x553) {
        char  *x554 = p_TransferEncoding(x511);
        int x556 = 1/*true*/;
        char  *x558 = 0/*null*/;
        int x559 = 0 == x554;
        if (x559) {
          x558 = x511;
        } else {
          x556 = 0/*false*/;
          x558 = x554;
        }
        int x567 = x556;
        if (x567) {
          char  *x568 = x558;
        } else {
          char  *x571 = x558;
          x526 = 0/*false*/;
          x527 = 2;
          x528 = x571;
        }
      } else {
        int x578 = x530;
        char  *x579 = x531;
        x526 = 0/*false*/;
        x527 = x578;
        x528 = x579;
      }
      int x585 = x526;
      if (x585) {
        char  *x586 = x511;
        int x587 = 1/*true*/;
        /*@
        loop invariant ((strlen(x586)>=0) && \valid(x586+(0..(strlen(x586)+1)-1)));
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
            int x594 = x591 == ':';
            int x596;
            if (x594) {
              x596 = 0/*false*/;
            } else {
              int x595 = x591 != ' ';
              x596 = x595;
            }
            if (x596) {
              char  *x597 = x590+1;
              x586 = x597;
            } else {
              x587 = 0/*false*/;
            }
          }
        }
        char  *x623 = x586;
        x523 = 0/*false*/;
        x524 = 0;
        x525 = x623;
      } else {
        int x628 = x527;
        char  *x629 = x528;
        x523 = 0/*false*/;
        x524 = x628;
        x525 = x629;
      }
      int x635 = x523;
      if (x635) {
        char  *x636 = x525;
        x522 = x636;
      } else {
        int x639 = x524;
        char  *x640 = x525;
        char  *x641 = x640;
        int x642 = 1/*true*/;
        /*@
        loop invariant ((strlen(x641)>=0) && \valid(x641+(0..(strlen(x641)+1)-1)));
        loop assigns x641, x642;
        */
        for (;;) {
          int x643 = x642;
          if (!x643) break;
          char  *x645 = x641;
          char x646 = x645[0];
          int x647 = x646 == '\0';
          if (x647) {
            x642 = 0/*false*/;
          } else {
            int x648 = x646 == ' ';
            if (x648) {
              char  *x649 = x645+1;
              x641 = x649;
            } else {
              x642 = 0/*false*/;
            }
          }
        }
        char  *x675 = x641;
        x520 = 0/*false*/;
        x521 = x639;
        x522 = x675;
      }
      int x681 = x520;
      if (x681) {
        char  *x682 = x522;
        x519 = x682;
      } else {
        int x685 = x521;
        char  *x686 = x522;
        int x691 = 1/*true*/;
        char x692 = '\0';
        char  *x693 = 0/*null*/;
        char x687 = x686[0];
        int x688 = x687 == '\0';
        if (x688) {
          x693 = x686;
        } else {
          int x689 = x687 == ':';
          if (x689) {
            x691 = 0/*false*/;
            x692 = x687;
            char  *x690 = x686+1;
            x693 = x690;
          } else {
            x693 = x686;
          }
        }
        int x705 = x691;
        if (x705) {
          char  *x706 = x693;
          x519 = x706;
        } else {
          char x709 = x692;
          char  *x710 = x693;
          x517 = 0/*false*/;
          x518 = x685;
          x519 = x710;
        }
      }
      int x718 = x517;
      if (x718) {
        char  *x719 = x519;
        x516 = x719;
      } else {
        int x722 = x518;
        char  *x723 = x519;
        char  *x724 = x723;
        int x725 = 1/*true*/;
        /*@
        loop invariant ((strlen(x724)>=0) && \valid(x724+(0..(strlen(x724)+1)-1)));
        loop assigns x724, x725;
        */
        for (;;) {
          int x726 = x725;
          if (!x726) break;
          char  *x728 = x724;
          char x729 = x728[0];
          int x730 = x729 == '\0';
          if (x730) {
            x725 = 0/*false*/;
          } else {
            int x731 = x729 == ' ';
            if (x731) {
              char  *x732 = x728+1;
              x724 = x732;
            } else {
              x725 = 0/*false*/;
            }
          }
        }
        char  *x758 = x724;
        x514 = 0/*false*/;
        x515 = x722;
        x516 = x758;
      }
      int x764 = x514;
      if (x764) {
        char  *x765 = x516;
        x507 = 0/*false*/;
      } else {
        int x768 = x515;
        char  *x769 = x516;
        char  *x771 = p_chunked(x769);
        char  *x780 = x769;
        int x781 = 1/*true*/;
        /*@
        loop invariant ((strlen(x780)>=0) && \valid(x780+(0..(strlen(x780)+1)-1)));
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
            int x791 = x785 == '\r';
            if (x791) {
              x781 = 0/*false*/;
            } else {
              char  *x788 = x784+1;
              x780 = x788;
            }
          }
        }
        char  *x815 = x780;
        int x770 = x768 == 2;
        if (x770) {
          int x816 = 1/*true*/;
          int x817 = 0;
          char  *x818 = 0/*null*/;
          int x819 = 1/*true*/;
          int x820 = 0;
          char  *x821 = 0/*null*/;
          int x822 = 1/*true*/;
          char  *x824 = 0/*null*/;
          int x825 = 0 == x771;
          if (x825) {
            x824 = x769;
          } else {
            x822 = 0/*false*/;
            x824 = x771;
          }
          int x833 = x822;
          if (x833) {
            char  *x834 = x824;
            x821 = x834;
          } else {
            char  *x838 = x824;
            x819 = 0/*false*/;
            x820 = -3;
            x821 = x838;
          }
          int x844 = x819;
          if (x844) {
            char  *x845 = x821;
            x818 = x845;
          } else {
            int x848 = x820;
            char  *x849 = x821;
            char  *x850 = x849;
            int x851 = 1/*true*/;
            /*@
            loop invariant ((strlen(x850)>=0) && \valid(x850+(0..(strlen(x850)+1)-1)));
            loop assigns x850, x851;
            */
            for (;;) {
              int x852 = x851;
              if (!x852) break;
              char  *x854 = x850;
              char x855 = x854[0];
              int x856 = x855 == '\0';
              if (x856) {
                x851 = 0/*false*/;
              } else {
                int x857 = x855 == ' ';
                if (x857) {
                  char  *x858 = x854+1;
                  x850 = x858;
                } else {
                  x851 = 0/*false*/;
                }
              }
            }
            char  *x884 = x850;
            x816 = 0/*false*/;
            x817 = x848;
            x818 = x884;
          }
          int x890 = x816;
          if (x890) {
            char  *x891 = x818;
            x507 = 0/*false*/;
          } else {
            int x894 = x817;
            char  *x895 = x818;
            int x900 = 1/*true*/;
            char x901 = '\0';
            char  *x902 = 0/*null*/;
            char x896 = x895[0];
            int x897 = x896 == '\0';
            if (x897) {
              x902 = x895;
            } else {
              int x898 = x896 == '\r';
              if (x898) {
                x900 = 0/*false*/;
                x901 = x896;
                char  *x899 = x895+1;
                x902 = x899;
              } else {
                x902 = x895;
              }
            }
            int x914 = x900;
            if (x914) {
              char  *x915 = x902;
              x507 = 0/*false*/;
            } else {
              char x918 = x901;
              char  *x919 = x902;
              int x924 = 1/*true*/;
              char x925 = '\0';
              char  *x926 = 0/*null*/;
              char x920 = x919[0];
              int x921 = x920 == '\0';
              if (x921) {
                x926 = x919;
              } else {
                int x922 = x920 == '\n';
                if (x922) {
                  x924 = 0/*false*/;
                  x925 = x920;
                  char  *x923 = x919+1;
                  x926 = x923;
                } else {
                  x926 = x919;
                }
              }
              int x938 = x924;
              if (x938) {
                char  *x939 = x926;
                x507 = 0/*false*/;
              } else {
                char x942 = x925;
                char  *x943 = x926;
                int x944 = x508;
                int x945 = x894 == -2;
                int x946;
                if (x945) {
                  x946 = x944;
                } else {
                  x946 = x894;
                }
                x508 = x946;
                x506 = x943;
              }
            }
          }
        } else {
          int x773 = x768 == 1;
          if (x773) {
            int x956 = 1/*true*/;
            int x957 = 0;
            char  *x958 = 0/*null*/;
            int x959 = 1/*true*/;
            int x960 = 0;
            char  *x961 = 0/*null*/;
            int x962 = 1/*true*/;
            int x963 = 0;
            char  *x964 = 0/*null*/;
            int x965 = 1/*true*/;
            char x966 = '\0';
            char  *x967 = 0/*null*/;
            char x774 = x769[0];
            int x775 = x774 == '\0';
            if (x775) {
              x967 = x769;
            } else {
              int x776 = x774 >= '0';
              int x778;
              if (x776) {
                int x777 = x774 <= '9';
                x778 = x777;
              } else {
                x778 = 0/*false*/;
              }
              if (x778) {
                x965 = 0/*false*/;
                x966 = x774;
                char  *x779 = x769+1;
                x967 = x779;
              } else {
                x967 = x769;
              }
            }
            int x979 = x965;
            if (x979) {
              char  *x980 = x967;
              x964 = x980;
            } else {
              char x983 = x966;
              char  *x985 = x967;
              x962 = 0/*false*/;
              char x984 = x983 - '0';
              x963 = x984;
              x964 = x985;
            }
            int x991 = x962;
            if (x991) {
              char  *x992 = x964;
              x961 = x992;
            } else {
              int x995 = x963;
              char  *x996 = x964;
              char  *x997 = x996;
              int x998 = 1/*true*/;
              int x999 = x995;
              /*@
              loop invariant (((strlen(x997)>=0) && \valid(x997+(0..(strlen(x997)+1)-1))) && ((x999==-1) || (0<=x999)));
              loop assigns x997, x998, x999;
              */
              for (;;) {
                int x1000 = x998;
                if (!x1000) break;
                char  *x1002 = x997;
                int x1009 = 1/*true*/;
                char x1010 = '\0';
                char  *x1011 = 0/*null*/;
                char x1003 = x1002[0];
                int x1004 = x1003 == '\0';
                if (x1004) {
                  x1011 = x1002;
                } else {
                  int x1005 = x1003 >= '0';
                  int x1007;
                  if (x1005) {
                    int x1006 = x1003 <= '9';
                    x1007 = x1006;
                  } else {
                    x1007 = 0/*false*/;
                  }
                  if (x1007) {
                    x1009 = 0/*false*/;
                    x1010 = x1003;
                    char  *x1008 = x1002+1;
                    x1011 = x1008;
                  } else {
                    x1011 = x1002;
                  }
                }
                int x1023 = x1009;
                if (x1023) {
                  char  *x1024 = x1011;
                  x998 = 0/*false*/;
                } else {
                  char x1027 = x1010;
                  char  *x1029 = x1011;
                  int x1030 = x999;
                  int x1031 = x1030 < 0;
                  int x1036;
                  if (x1031) {
                    x1036 = x1030;
                  } else {
                    int x1032 = x1030 > x345;
                    int x1035;
                    if (x1032) {
                      x1035 = -1;
                    } else {
                      char x1028 = x1027 - '0';
                      int x1033 = x1030 * 10;
                      int x1034 = x1033 + x1028;
                      x1035 = x1034;
                    }
                    x1036 = x1035;
                  }
                  x999 = x1036;
                  x997 = x1029;
                }
              }
              int x1064 = x999;
              char  *x1065 = x997;
              x959 = 0/*false*/;
              x960 = x1064;
              x961 = x1065;
            }
            int x1071 = x959;
            if (x1071) {
              char  *x1072 = x961;
              x958 = x1072;
            } else {
              int x1075 = x960;
              char  *x1076 = x961;
              char  *x1077 = x1076;
              int x1078 = 1/*true*/;
              /*@
              loop invariant ((strlen(x1077)>=0) && \valid(x1077+(0..(strlen(x1077)+1)-1)));
              loop assigns x1077, x1078;
              */
              for (;;) {
                int x1079 = x1078;
                if (!x1079) break;
                char  *x1081 = x1077;
                char x1082 = x1081[0];
                int x1083 = x1082 == '\0';
                if (x1083) {
                  x1078 = 0/*false*/;
                } else {
                  int x1084 = x1082 == ' ';
                  if (x1084) {
                    char  *x1085 = x1081+1;
                    x1077 = x1085;
                  } else {
                    x1078 = 0/*false*/;
                  }
                }
              }
              char  *x1111 = x1077;
              x956 = 0/*false*/;
              x957 = x1075;
              x958 = x1111;
            }
            int x1117 = x956;
            if (x1117) {
              char  *x1118 = x958;
              x507 = 0/*false*/;
            } else {
              int x1121 = x957;
              char  *x1122 = x958;
              int x1127 = 1/*true*/;
              char x1128 = '\0';
              char  *x1129 = 0/*null*/;
              char x1123 = x1122[0];
              int x1124 = x1123 == '\0';
              if (x1124) {
                x1129 = x1122;
              } else {
                int x1125 = x1123 == '\r';
                if (x1125) {
                  x1127 = 0/*false*/;
                  x1128 = x1123;
                  char  *x1126 = x1122+1;
                  x1129 = x1126;
                } else {
                  x1129 = x1122;
                }
              }
              int x1141 = x1127;
              if (x1141) {
                char  *x1142 = x1129;
                x507 = 0/*false*/;
              } else {
                char x1145 = x1128;
                char  *x1146 = x1129;
                int x1151 = 1/*true*/;
                char x1152 = '\0';
                char  *x1153 = 0/*null*/;
                char x1147 = x1146[0];
                int x1148 = x1147 == '\0';
                if (x1148) {
                  x1153 = x1146;
                } else {
                  int x1149 = x1147 == '\n';
                  if (x1149) {
                    x1151 = 0/*false*/;
                    x1152 = x1147;
                    char  *x1150 = x1146+1;
                    x1153 = x1150;
                  } else {
                    x1153 = x1146;
                  }
                }
                int x1165 = x1151;
                if (x1165) {
                  char  *x1166 = x1153;
                  x507 = 0/*false*/;
                } else {
                  char x1169 = x1152;
                  char  *x1170 = x1153;
                  int x1171 = x508;
                  int x1172 = x1121 == -2;
                  int x1173;
                  if (x1172) {
                    x1173 = x1171;
                  } else {
                    x1173 = x1121;
                  }
                  x508 = x1173;
                  x506 = x1170;
                }
              }
            }
          } else {
            int x1183 = 1/*true*/;
            char  *x1185 = 0/*null*/;
            x1183 = 0/*false*/;
            x1185 = x815;
            int x1189 = x1183;
            if (x1189) {
              char  *x1190 = x1185;
              x507 = 0/*false*/;
            } else {
              char  *x1194 = x1185;
              int x1199 = 1/*true*/;
              char x1200 = '\0';
              char  *x1201 = 0/*null*/;
              char x1195 = x1194[0];
              int x1196 = x1195 == '\0';
              if (x1196) {
                x1201 = x1194;
              } else {
                int x1197 = x1195 == '\r';
                if (x1197) {
                  x1199 = 0/*false*/;
                  x1200 = x1195;
                  char  *x1198 = x1194+1;
                  x1201 = x1198;
                } else {
                  x1201 = x1194;
                }
              }
              int x1213 = x1199;
              if (x1213) {
                char  *x1214 = x1201;
                x507 = 0/*false*/;
              } else {
                char x1217 = x1200;
                char  *x1218 = x1201;
                int x1223 = 1/*true*/;
                char x1224 = '\0';
                char  *x1225 = 0/*null*/;
                char x1219 = x1218[0];
                int x1220 = x1219 == '\0';
                if (x1220) {
                  x1225 = x1218;
                } else {
                  int x1221 = x1219 == '\n';
                  if (x1221) {
                    x1223 = 0/*false*/;
                    x1224 = x1219;
                    char  *x1222 = x1218+1;
                    x1225 = x1222;
                  } else {
                    x1225 = x1218;
                  }
                }
                int x1237 = x1223;
                if (x1237) {
                  char  *x1238 = x1225;
                  x507 = 0/*false*/;
                } else {
                  char x1241 = x1224;
                  char  *x1242 = x1225;
                  int x1243 = x508;
                  int x1245;
                  if (x1244) {
                    x1245 = x1243;
                  } else {
                    x1245 = -2;
                  }
                  x508 = x1245;
                  x506 = x1242;
                }
              }
            }
          }
        }
      }
    }
    int x1278 = x508;
    char  *x1279 = x506;
    x8 = 0/*false*/;
    x9 = x1278;
    x10 = x1279;
  }
  int x1285 = x8;
  if (x1285) {
    char  *x1286 = x10;
    x7 = x1286;
  } else {
    int x1289 = x9;
    char  *x1290 = x10;
    int x1295 = 1/*true*/;
    char x1296 = '\0';
    char  *x1297 = 0/*null*/;
    char x1291 = x1290[0];
    int x1292 = x1291 == '\0';
    if (x1292) {
      x1297 = x1290;
    } else {
      int x1293 = x1291 == '\r';
      if (x1293) {
        x1295 = 0/*false*/;
        x1296 = x1291;
        char  *x1294 = x1290+1;
        x1297 = x1294;
      } else {
        x1297 = x1290;
      }
    }
    int x1309 = x1295;
    if (x1309) {
      char  *x1310 = x1297;
      x7 = x1310;
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
        x7 = x1334;
      } else {
        char x1337 = x1320;
        char  *x1338 = x1321;
        x5 = 0/*false*/;
        x6 = x1289;
        x7 = x1338;
      }
    }
  }
  int x1348 = x5;
  if (x1348) {
    char  *x1349 = x7;
  } else {
    int x1351 = x6;
    char  *x1352 = x7;
    char  *x1354 = x1352;
    int x1355 = 1/*true*/;
    int x1356 = 0;
    int x343 = INT_MAX;
    int x1516 = x343 / 16;
    int x1517 = x1516 - 16;
    /*@
    loop invariant (((strlen(x1354)>=0) && \valid(x1354+(0..(strlen(x1354)+1)-1))) && ((x1356==-1) || (0<=x1356)));
    loop assigns x1354, x1355, x1356;
    */
    for (;;) {
      int x1357 = x1355;
      if (!x1357) break;
      char  *x1359 = x1354;
      int x1366 = 1/*true*/;
      int x1367 = 0;
      char  *x1368 = 0/*null*/;
      int x1369 = 1/*true*/;
      int x1370 = 0;
      char  *x1371 = 0/*null*/;
      int x1372 = 1/*true*/;
      int x1373 = 0;
      char  *x1374 = 0/*null*/;
      int x1375 = 1/*true*/;
      int x1376 = 0;
      char  *x1377 = 0/*null*/;
      int x1378 = 1/*true*/;
      char x1379 = '\0';
      char  *x1380 = 0/*null*/;
      char x1360 = x1359[0];
      int x1361 = x1360 == '\0';
      if (x1361) {
        x1380 = x1359;
      } else {
        int x1362 = x1360 >= '0';
        int x1364;
        if (x1362) {
          int x1363 = x1360 <= '9';
          x1364 = x1363;
        } else {
          x1364 = 0/*false*/;
        }
        if (x1364) {
          x1378 = 0/*false*/;
          x1379 = x1360;
          char  *x1365 = x1359+1;
          x1380 = x1365;
        } else {
          x1380 = x1359;
        }
      }
      int x1392 = x1378;
      if (x1392) {
        char  *x1393 = x1380;
      } else {
        char x1395 = x1379;
        char  *x1397 = x1380;
        x1375 = 0/*false*/;
        char x1396 = x1395 - '0';
        x1376 = x1396;
        x1377 = x1397;
      }
      int x1403 = x1375;
      if (x1403) {
        int x1407 = 1/*true*/;
        char x1408 = '\0';
        char  *x1409 = 0/*null*/;
        if (x1361) {
          x1409 = x1359;
        } else {
          int x1404 = x1360 >= 'a';
          int x1406;
          if (x1404) {
            int x1405 = x1360 <= 'f';
            x1406 = x1405;
          } else {
            x1406 = 0/*false*/;
          }
          if (x1406) {
            x1407 = 0/*false*/;
            x1408 = x1360;
            char  *x1365 = x1359+1;
            x1409 = x1365;
          } else {
            x1409 = x1359;
          }
        }
        int x1421 = x1407;
        if (x1421) {
          char  *x1422 = x1409;
          x1374 = x1422;
        } else {
          char x1425 = x1408;
          char  *x1428 = x1409;
          x1372 = 0/*false*/;
          char x1426 = x1425 - 'a';
          int x1427 = 10 + x1426;
          x1373 = x1427;
          x1374 = x1428;
        }
      } else {
        int x1435 = x1376;
        char  *x1436 = x1377;
        x1372 = 0/*false*/;
        x1373 = x1435;
        x1374 = x1436;
      }
      int x1442 = x1372;
      if (x1442) {
        char  *x1443 = x1374;
        x1371 = x1443;
      } else {
        int x1446 = x1373;
        char  *x1447 = x1374;
        char  *x1448 = x1447;
        int x1449 = 1/*true*/;
        int x1450 = x1446;
        /*@
        loop invariant (((strlen(x1448)>=0) && \valid(x1448+(0..(strlen(x1448)+1)-1))) && ((x1450==-1) || (0<=x1450)));
        loop assigns x1448, x1449, x1450;
        */
        for (;;) {
          int x1451 = x1449;
          if (!x1451) break;
          char  *x1453 = x1448;
          int x1460 = 1/*true*/;
          int x1461 = 0;
          char  *x1462 = 0/*null*/;
          int x1463 = 1/*true*/;
          char x1464 = '\0';
          char  *x1465 = 0/*null*/;
          char x1454 = x1453[0];
          int x1455 = x1454 == '\0';
          if (x1455) {
            x1465 = x1453;
          } else {
            int x1456 = x1454 >= '0';
            int x1458;
            if (x1456) {
              int x1457 = x1454 <= '9';
              x1458 = x1457;
            } else {
              x1458 = 0/*false*/;
            }
            if (x1458) {
              x1463 = 0/*false*/;
              x1464 = x1454;
              char  *x1459 = x1453+1;
              x1465 = x1459;
            } else {
              x1465 = x1453;
            }
          }
          int x1477 = x1463;
          if (x1477) {
            char  *x1478 = x1465;
          } else {
            char x1480 = x1464;
            char  *x1482 = x1465;
            x1460 = 0/*false*/;
            char x1481 = x1480 - '0';
            x1461 = x1481;
            x1462 = x1482;
          }
          int x1488 = x1460;
          if (x1488) {
            int x1492 = 1/*true*/;
            char x1493 = '\0';
            char  *x1494 = 0/*null*/;
            if (x1455) {
              x1494 = x1453;
            } else {
              int x1489 = x1454 >= 'a';
              int x1491;
              if (x1489) {
                int x1490 = x1454 <= 'f';
                x1491 = x1490;
              } else {
                x1491 = 0/*false*/;
              }
              if (x1491) {
                x1492 = 0/*false*/;
                x1493 = x1454;
                char  *x1459 = x1453+1;
                x1494 = x1459;
              } else {
                x1494 = x1453;
              }
            }
            int x1506 = x1492;
            if (x1506) {
              char  *x1507 = x1494;
              x1449 = 0/*false*/;
            } else {
              char x1510 = x1493;
              char  *x1513 = x1494;
              int x1514 = x1450;
              int x1515 = x1514 < 0;
              int x1522;
              if (x1515) {
                x1522 = x1514;
              } else {
                int x1518 = x1514 > x1517;
                int x1521;
                if (x1518) {
                  x1521 = -1;
                } else {
                  char x1511 = x1510 - 'a';
                  int x1512 = 10 + x1511;
                  int x1519 = x1514 * 16;
                  int x1520 = x1519 + x1512;
                  x1521 = x1520;
                }
                x1522 = x1521;
              }
              x1450 = x1522;
              x1448 = x1513;
            }
          } else {
            int x1528 = x1461;
            char  *x1529 = x1462;
            int x1530 = x1450;
            int x1531 = x1530 < 0;
            int x1536;
            if (x1531) {
              x1536 = x1530;
            } else {
              int x1532 = x1530 > x1517;
              int x1535;
              if (x1532) {
                x1535 = -1;
              } else {
                int x1533 = x1530 * 16;
                int x1534 = x1533 + x1528;
                x1535 = x1534;
              }
              x1536 = x1535;
            }
            x1450 = x1536;
            x1448 = x1529;
          }
        }
        int x1564 = x1450;
        char  *x1565 = x1448;
        x1369 = 0/*false*/;
        x1370 = x1564;
        x1371 = x1565;
      }
      int x1571 = x1369;
      if (x1571) {
        char  *x1572 = x1371;
        x1368 = x1572;
      } else {
        int x1575 = x1370;
        char  *x1576 = x1371;
        int x1581 = 1/*true*/;
        char x1582 = '\0';
        char  *x1583 = 0/*null*/;
        char x1577 = x1576[0];
        int x1578 = x1577 == '\0';
        if (x1578) {
          x1583 = x1576;
        } else {
          int x1579 = x1577 == '\r';
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
          x1368 = x1596;
        } else {
          char x1599 = x1582;
          char  *x1600 = x1583;
          int x1605 = 1/*true*/;
          char x1606 = '\0';
          char  *x1607 = 0/*null*/;
          char x1601 = x1600[0];
          int x1602 = x1601 == '\0';
          if (x1602) {
            x1607 = x1600;
          } else {
            int x1603 = x1601 == '\n';
            if (x1603) {
              x1605 = 0/*false*/;
              x1606 = x1601;
              char  *x1604 = x1600+1;
              x1607 = x1604;
            } else {
              x1607 = x1600;
            }
          }
          int x1619 = x1605;
          if (x1619) {
            char  *x1620 = x1607;
            x1368 = x1620;
          } else {
            char x1623 = x1606;
            char  *x1624 = x1607;
            x1366 = 0/*false*/;
            x1367 = x1575;
            x1368 = x1624;
          }
        }
      }
      int x1634 = x1366;
      if (x1634) {
        char  *x1635 = x1368;
        x1355 = 0/*false*/;
      } else {
        int x1638 = x1367;
        char  *x1639 = x1368;
        int x1641 = 1/*true*/;
        char  *x1642 = x1639;
        /*@
        loop invariant ((0<=x1644) && ((strlen(x1642)>=0) && \valid(x1642+(0..(strlen(x1642)+1)-1))));
        loop assigns x1644, x1641, x1642;
        loop variant (x1638-x1644);
        */
        for(int x1644=0; x1644 < x1638; x1644++) {
          int x1645 = x1641;
          if (x1645) {
            char  *x1646 = x1642;
            char x1647 = x1646[0];
            int x1648 = x1647 == '\0';
            if (x1648) {
              x1641 = 0/*false*/;
            } else {
              char  *x1649 = x1646+1;
              x1642 = x1649;
            }
          } else {
          }
        }
        int x1678 = x1641;
        char  *x1679 = x1642;
        int x1640 = x1638 < 0;
        if (x1640) {
          x1355 = 0/*false*/;
        } else {
          int x1682 = 1/*true*/;
          char  *x1684 = 0/*null*/;
          if (x1678) {
            x1682 = 0/*false*/;
            x1684 = x1679;
          } else {
            x1684 = x1639;
          }
          int x1692 = x1682;
          if (x1692) {
            char  *x1693 = x1684;
            x1355 = 0/*false*/;
          } else {
            char  *x1697 = x1684;
            int x1698 = x1356;
            int x1699 = x1698 < 0;
            int x1704;
            if (x1699) {
              x1704 = x1698;
            } else {
              int x1700 = x343 - x1638;
              int x1701 = x1698 > x1700;
              int x1703;
              if (x1701) {
                x1703 = -1;
              } else {
                int x1702 = x1698 + x1638;
                x1703 = x1702;
              }
              x1704 = x1703;
            }
            x1356 = x1704;
            x1354 = x1697;
          }
        }
      }
    }
    int x1736 = x1356;
    char  *x1737 = x1354;
    int x1739 = 1/*true*/;
    char  *x1740 = x1352;
    /*@
    loop invariant ((0<=x1742) && ((strlen(x1740)>=0) && \valid(x1740+(0..(strlen(x1740)+1)-1))));
    loop assigns x1742, x1739, x1740;
    loop variant (x1351-x1742);
    */
    for(int x1742=0; x1742 < x1351; x1742++) {
      int x1743 = x1739;
      if (x1743) {
        char  *x1744 = x1740;
        char x1745 = x1744[0];
        int x1746 = x1745 == '\0';
        if (x1746) {
          x1739 = 0/*false*/;
        } else {
          char  *x1747 = x1744+1;
          x1740 = x1747;
        }
      } else {
      }
    }
    int x1776 = x1739;
    char  *x1777 = x1740;
    int x1353 = x1351 == -3;
    if (x1353) {
      char x1778 = x1737[0];
      int x1779 = x1778 == '\0';
      if (x1779) {
        x2 = x1736;
      } else {
      }
    } else {
      int x1738 = x1351 < 0;
      if (x1738) {
      } else {
        int x1784 = 1/*true*/;
        char  *x1786 = 0/*null*/;
        if (x1776) {
          x1784 = 0/*false*/;
          x1786 = x1777;
        } else {
          x1786 = x1352;
        }
        int x1794 = x1784;
        if (x1794) {
          char  *x1795 = x1786;
        } else {
          char  *x1798 = x1786;
          char x1799 = x1798[0];
          int x1800 = x1799 == '\0';
          if (x1800) {
            x2 = x1351;
          } else {
          }
        }
      }
    }
  }
  int x1812 = x2;
  return x1812;
}
/*@
requires ((strlen(x1831)>=0) && \valid(x1831+(0..(strlen(x1831)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_HTTP(char  * x1831) {
  char  *x1833 = x1831;
  int x1838 = 1/*true*/;
  char x1839 = '\0';
  char  *x1840 = 0/*null*/;
  char x1834 = x1831[0];
  int x1835 = x1834 == '\0';
  if (x1835) {
    x1840 = x1831;
  } else {
    int x1836 = x1834 == 'H';
    if (x1836) {
      x1838 = 0/*false*/;
      x1839 = x1834;
      char  *x1837 = x1831+1;
      x1840 = x1837;
    } else {
      x1840 = x1831;
    }
  }
  int x1852 = x1838;
  if (x1852) {
    char  *x1853 = x1840;
    x1833 = 0;
  } else {
    char x1856 = x1839;
    char  *x1857 = x1840;
    int x1862 = 1/*true*/;
    char x1863 = '\0';
    char  *x1864 = 0/*null*/;
    char x1858 = x1857[0];
    int x1859 = x1858 == '\0';
    if (x1859) {
      x1864 = x1857;
    } else {
      int x1860 = x1858 == 'T';
      if (x1860) {
        x1862 = 0/*false*/;
        x1863 = x1858;
        char  *x1861 = x1857+1;
        x1864 = x1861;
      } else {
        x1864 = x1857;
      }
    }
    int x1876 = x1862;
    if (x1876) {
      char  *x1877 = x1864;
      x1833 = 0;
    } else {
      char x1880 = x1863;
      char  *x1881 = x1864;
      int x1886 = 1/*true*/;
      char x1887 = '\0';
      char  *x1888 = 0/*null*/;
      char x1882 = x1881[0];
      int x1883 = x1882 == '\0';
      if (x1883) {
        x1888 = x1881;
      } else {
        int x1884 = x1882 == 'T';
        if (x1884) {
          x1886 = 0/*false*/;
          x1887 = x1882;
          char  *x1885 = x1881+1;
          x1888 = x1885;
        } else {
          x1888 = x1881;
        }
      }
      int x1900 = x1886;
      if (x1900) {
        char  *x1901 = x1888;
        x1833 = 0;
      } else {
        char x1904 = x1887;
        char  *x1905 = x1888;
        int x1910 = 1/*true*/;
        char x1911 = '\0';
        char  *x1912 = 0/*null*/;
        char x1906 = x1905[0];
        int x1907 = x1906 == '\0';
        if (x1907) {
          x1912 = x1905;
        } else {
          int x1908 = x1906 == 'P';
          if (x1908) {
            x1910 = 0/*false*/;
            x1911 = x1906;
            char  *x1909 = x1905+1;
            x1912 = x1909;
          } else {
            x1912 = x1905;
          }
        }
        int x1924 = x1910;
        if (x1924) {
          char  *x1925 = x1912;
          x1833 = 0;
        } else {
          char x1928 = x1911;
          char  *x1929 = x1912;
          int x1934 = 1/*true*/;
          char x1935 = '\0';
          char  *x1936 = 0/*null*/;
          char x1930 = x1929[0];
          int x1931 = x1930 == '\0';
          if (x1931) {
            x1936 = x1929;
          } else {
            int x1932 = x1930 == '/';
            if (x1932) {
              x1934 = 0/*false*/;
              x1935 = x1930;
              char  *x1933 = x1929+1;
              x1936 = x1933;
            } else {
              x1936 = x1929;
            }
          }
          int x1948 = x1934;
          if (x1948) {
            char  *x1949 = x1936;
            x1833 = 0;
          } else {
            char x1952 = x1935;
            char  *x1953 = x1936;
            x1833 = x1953;
          }
        }
      }
    }
  }
  char  *x1965 = x1833;
  return x1965;
}
/*@
requires ((strlen(x1987)>=0) && \valid(x1987+(0..(strlen(x1987)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_ContentLength(char  * x1987) {
  char  *x1989 = x1987;
  int x1994 = 1/*true*/;
  char x1995 = '\0';
  char  *x1996 = 0/*null*/;
  char x1990 = x1987[0];
  int x1991 = x1990 == '\0';
  if (x1991) {
    x1996 = x1987;
  } else {
    int x1992 = x1990 == 'C';
    if (x1992) {
      x1994 = 0/*false*/;
      x1995 = x1990;
      char  *x1993 = x1987+1;
      x1996 = x1993;
    } else {
      x1996 = x1987;
    }
  }
  int x2008 = x1994;
  if (x2008) {
    char  *x2009 = x1996;
    x1989 = 0;
  } else {
    char x2012 = x1995;
    char  *x2013 = x1996;
    int x2018 = 1/*true*/;
    char x2019 = '\0';
    char  *x2020 = 0/*null*/;
    char x2014 = x2013[0];
    int x2015 = x2014 == '\0';
    if (x2015) {
      x2020 = x2013;
    } else {
      int x2016 = x2014 == 'o';
      if (x2016) {
        x2018 = 0/*false*/;
        x2019 = x2014;
        char  *x2017 = x2013+1;
        x2020 = x2017;
      } else {
        x2020 = x2013;
      }
    }
    int x2032 = x2018;
    if (x2032) {
      char  *x2033 = x2020;
      x1989 = 0;
    } else {
      char x2036 = x2019;
      char  *x2037 = x2020;
      int x2042 = 1/*true*/;
      char x2043 = '\0';
      char  *x2044 = 0/*null*/;
      char x2038 = x2037[0];
      int x2039 = x2038 == '\0';
      if (x2039) {
        x2044 = x2037;
      } else {
        int x2040 = x2038 == 'n';
        if (x2040) {
          x2042 = 0/*false*/;
          x2043 = x2038;
          char  *x2041 = x2037+1;
          x2044 = x2041;
        } else {
          x2044 = x2037;
        }
      }
      int x2056 = x2042;
      if (x2056) {
        char  *x2057 = x2044;
        x1989 = 0;
      } else {
        char x2060 = x2043;
        char  *x2061 = x2044;
        int x2066 = 1/*true*/;
        char x2067 = '\0';
        char  *x2068 = 0/*null*/;
        char x2062 = x2061[0];
        int x2063 = x2062 == '\0';
        if (x2063) {
          x2068 = x2061;
        } else {
          int x2064 = x2062 == 't';
          if (x2064) {
            x2066 = 0/*false*/;
            x2067 = x2062;
            char  *x2065 = x2061+1;
            x2068 = x2065;
          } else {
            x2068 = x2061;
          }
        }
        int x2080 = x2066;
        if (x2080) {
          char  *x2081 = x2068;
          x1989 = 0;
        } else {
          char x2084 = x2067;
          char  *x2085 = x2068;
          int x2090 = 1/*true*/;
          char x2091 = '\0';
          char  *x2092 = 0/*null*/;
          char x2086 = x2085[0];
          int x2087 = x2086 == '\0';
          if (x2087) {
            x2092 = x2085;
          } else {
            int x2088 = x2086 == 'e';
            if (x2088) {
              x2090 = 0/*false*/;
              x2091 = x2086;
              char  *x2089 = x2085+1;
              x2092 = x2089;
            } else {
              x2092 = x2085;
            }
          }
          int x2104 = x2090;
          if (x2104) {
            char  *x2105 = x2092;
            x1989 = 0;
          } else {
            char x2108 = x2091;
            char  *x2109 = x2092;
            int x2114 = 1/*true*/;
            char x2115 = '\0';
            char  *x2116 = 0/*null*/;
            char x2110 = x2109[0];
            int x2111 = x2110 == '\0';
            if (x2111) {
              x2116 = x2109;
            } else {
              int x2112 = x2110 == 'n';
              if (x2112) {
                x2114 = 0/*false*/;
                x2115 = x2110;
                char  *x2113 = x2109+1;
                x2116 = x2113;
              } else {
                x2116 = x2109;
              }
            }
            int x2128 = x2114;
            if (x2128) {
              char  *x2129 = x2116;
              x1989 = 0;
            } else {
              char x2132 = x2115;
              char  *x2133 = x2116;
              int x2138 = 1/*true*/;
              char x2139 = '\0';
              char  *x2140 = 0/*null*/;
              char x2134 = x2133[0];
              int x2135 = x2134 == '\0';
              if (x2135) {
                x2140 = x2133;
              } else {
                int x2136 = x2134 == 't';
                if (x2136) {
                  x2138 = 0/*false*/;
                  x2139 = x2134;
                  char  *x2137 = x2133+1;
                  x2140 = x2137;
                } else {
                  x2140 = x2133;
                }
              }
              int x2152 = x2138;
              if (x2152) {
                char  *x2153 = x2140;
                x1989 = 0;
              } else {
                char x2156 = x2139;
                char  *x2157 = x2140;
                int x2162 = 1/*true*/;
                char x2163 = '\0';
                char  *x2164 = 0/*null*/;
                char x2158 = x2157[0];
                int x2159 = x2158 == '\0';
                if (x2159) {
                  x2164 = x2157;
                } else {
                  int x2160 = x2158 == '-';
                  if (x2160) {
                    x2162 = 0/*false*/;
                    x2163 = x2158;
                    char  *x2161 = x2157+1;
                    x2164 = x2161;
                  } else {
                    x2164 = x2157;
                  }
                }
                int x2176 = x2162;
                if (x2176) {
                  char  *x2177 = x2164;
                  x1989 = 0;
                } else {
                  char x2180 = x2163;
                  char  *x2181 = x2164;
                  int x2186 = 1/*true*/;
                  char x2187 = '\0';
                  char  *x2188 = 0/*null*/;
                  char x2182 = x2181[0];
                  int x2183 = x2182 == '\0';
                  if (x2183) {
                    x2188 = x2181;
                  } else {
                    int x2184 = x2182 == 'L';
                    if (x2184) {
                      x2186 = 0/*false*/;
                      x2187 = x2182;
                      char  *x2185 = x2181+1;
                      x2188 = x2185;
                    } else {
                      x2188 = x2181;
                    }
                  }
                  int x2200 = x2186;
                  if (x2200) {
                    char  *x2201 = x2188;
                    x1989 = 0;
                  } else {
                    char x2204 = x2187;
                    char  *x2205 = x2188;
                    int x2210 = 1/*true*/;
                    char x2211 = '\0';
                    char  *x2212 = 0/*null*/;
                    char x2206 = x2205[0];
                    int x2207 = x2206 == '\0';
                    if (x2207) {
                      x2212 = x2205;
                    } else {
                      int x2208 = x2206 == 'e';
                      if (x2208) {
                        x2210 = 0/*false*/;
                        x2211 = x2206;
                        char  *x2209 = x2205+1;
                        x2212 = x2209;
                      } else {
                        x2212 = x2205;
                      }
                    }
                    int x2224 = x2210;
                    if (x2224) {
                      char  *x2225 = x2212;
                      x1989 = 0;
                    } else {
                      char x2228 = x2211;
                      char  *x2229 = x2212;
                      int x2234 = 1/*true*/;
                      char x2235 = '\0';
                      char  *x2236 = 0/*null*/;
                      char x2230 = x2229[0];
                      int x2231 = x2230 == '\0';
                      if (x2231) {
                        x2236 = x2229;
                      } else {
                        int x2232 = x2230 == 'n';
                        if (x2232) {
                          x2234 = 0/*false*/;
                          x2235 = x2230;
                          char  *x2233 = x2229+1;
                          x2236 = x2233;
                        } else {
                          x2236 = x2229;
                        }
                      }
                      int x2248 = x2234;
                      if (x2248) {
                        char  *x2249 = x2236;
                        x1989 = 0;
                      } else {
                        char x2252 = x2235;
                        char  *x2253 = x2236;
                        int x2258 = 1/*true*/;
                        char x2259 = '\0';
                        char  *x2260 = 0/*null*/;
                        char x2254 = x2253[0];
                        int x2255 = x2254 == '\0';
                        if (x2255) {
                          x2260 = x2253;
                        } else {
                          int x2256 = x2254 == 'g';
                          if (x2256) {
                            x2258 = 0/*false*/;
                            x2259 = x2254;
                            char  *x2257 = x2253+1;
                            x2260 = x2257;
                          } else {
                            x2260 = x2253;
                          }
                        }
                        int x2272 = x2258;
                        if (x2272) {
                          char  *x2273 = x2260;
                          x1989 = 0;
                        } else {
                          char x2276 = x2259;
                          char  *x2277 = x2260;
                          int x2282 = 1/*true*/;
                          char x2283 = '\0';
                          char  *x2284 = 0/*null*/;
                          char x2278 = x2277[0];
                          int x2279 = x2278 == '\0';
                          if (x2279) {
                            x2284 = x2277;
                          } else {
                            int x2280 = x2278 == 't';
                            if (x2280) {
                              x2282 = 0/*false*/;
                              x2283 = x2278;
                              char  *x2281 = x2277+1;
                              x2284 = x2281;
                            } else {
                              x2284 = x2277;
                            }
                          }
                          int x2296 = x2282;
                          if (x2296) {
                            char  *x2297 = x2284;
                            x1989 = 0;
                          } else {
                            char x2300 = x2283;
                            char  *x2301 = x2284;
                            int x2306 = 1/*true*/;
                            char x2307 = '\0';
                            char  *x2308 = 0/*null*/;
                            char x2302 = x2301[0];
                            int x2303 = x2302 == '\0';
                            if (x2303) {
                              x2308 = x2301;
                            } else {
                              int x2304 = x2302 == 'h';
                              if (x2304) {
                                x2306 = 0/*false*/;
                                x2307 = x2302;
                                char  *x2305 = x2301+1;
                                x2308 = x2305;
                              } else {
                                x2308 = x2301;
                              }
                            }
                            int x2320 = x2306;
                            if (x2320) {
                              char  *x2321 = x2308;
                              x1989 = 0;
                            } else {
                              char x2324 = x2307;
                              char  *x2325 = x2308;
                              x1989 = x2325;
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
  char  *x2355 = x1989;
  return x2355;
}
/*@
requires ((strlen(x2377)>=0) && \valid(x2377+(0..(strlen(x2377)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_TransferEncoding(char  * x2377) {
  char  *x2379 = x2377;
  int x2384 = 1/*true*/;
  char x2385 = '\0';
  char  *x2386 = 0/*null*/;
  char x2380 = x2377[0];
  int x2381 = x2380 == '\0';
  if (x2381) {
    x2386 = x2377;
  } else {
    int x2382 = x2380 == 'T';
    if (x2382) {
      x2384 = 0/*false*/;
      x2385 = x2380;
      char  *x2383 = x2377+1;
      x2386 = x2383;
    } else {
      x2386 = x2377;
    }
  }
  int x2398 = x2384;
  if (x2398) {
    char  *x2399 = x2386;
    x2379 = 0;
  } else {
    char x2402 = x2385;
    char  *x2403 = x2386;
    int x2408 = 1/*true*/;
    char x2409 = '\0';
    char  *x2410 = 0/*null*/;
    char x2404 = x2403[0];
    int x2405 = x2404 == '\0';
    if (x2405) {
      x2410 = x2403;
    } else {
      int x2406 = x2404 == 'r';
      if (x2406) {
        x2408 = 0/*false*/;
        x2409 = x2404;
        char  *x2407 = x2403+1;
        x2410 = x2407;
      } else {
        x2410 = x2403;
      }
    }
    int x2422 = x2408;
    if (x2422) {
      char  *x2423 = x2410;
      x2379 = 0;
    } else {
      char x2426 = x2409;
      char  *x2427 = x2410;
      int x2432 = 1/*true*/;
      char x2433 = '\0';
      char  *x2434 = 0/*null*/;
      char x2428 = x2427[0];
      int x2429 = x2428 == '\0';
      if (x2429) {
        x2434 = x2427;
      } else {
        int x2430 = x2428 == 'a';
        if (x2430) {
          x2432 = 0/*false*/;
          x2433 = x2428;
          char  *x2431 = x2427+1;
          x2434 = x2431;
        } else {
          x2434 = x2427;
        }
      }
      int x2446 = x2432;
      if (x2446) {
        char  *x2447 = x2434;
        x2379 = 0;
      } else {
        char x2450 = x2433;
        char  *x2451 = x2434;
        int x2456 = 1/*true*/;
        char x2457 = '\0';
        char  *x2458 = 0/*null*/;
        char x2452 = x2451[0];
        int x2453 = x2452 == '\0';
        if (x2453) {
          x2458 = x2451;
        } else {
          int x2454 = x2452 == 'n';
          if (x2454) {
            x2456 = 0/*false*/;
            x2457 = x2452;
            char  *x2455 = x2451+1;
            x2458 = x2455;
          } else {
            x2458 = x2451;
          }
        }
        int x2470 = x2456;
        if (x2470) {
          char  *x2471 = x2458;
          x2379 = 0;
        } else {
          char x2474 = x2457;
          char  *x2475 = x2458;
          int x2480 = 1/*true*/;
          char x2481 = '\0';
          char  *x2482 = 0/*null*/;
          char x2476 = x2475[0];
          int x2477 = x2476 == '\0';
          if (x2477) {
            x2482 = x2475;
          } else {
            int x2478 = x2476 == 's';
            if (x2478) {
              x2480 = 0/*false*/;
              x2481 = x2476;
              char  *x2479 = x2475+1;
              x2482 = x2479;
            } else {
              x2482 = x2475;
            }
          }
          int x2494 = x2480;
          if (x2494) {
            char  *x2495 = x2482;
            x2379 = 0;
          } else {
            char x2498 = x2481;
            char  *x2499 = x2482;
            int x2504 = 1/*true*/;
            char x2505 = '\0';
            char  *x2506 = 0/*null*/;
            char x2500 = x2499[0];
            int x2501 = x2500 == '\0';
            if (x2501) {
              x2506 = x2499;
            } else {
              int x2502 = x2500 == 'f';
              if (x2502) {
                x2504 = 0/*false*/;
                x2505 = x2500;
                char  *x2503 = x2499+1;
                x2506 = x2503;
              } else {
                x2506 = x2499;
              }
            }
            int x2518 = x2504;
            if (x2518) {
              char  *x2519 = x2506;
              x2379 = 0;
            } else {
              char x2522 = x2505;
              char  *x2523 = x2506;
              int x2528 = 1/*true*/;
              char x2529 = '\0';
              char  *x2530 = 0/*null*/;
              char x2524 = x2523[0];
              int x2525 = x2524 == '\0';
              if (x2525) {
                x2530 = x2523;
              } else {
                int x2526 = x2524 == 'e';
                if (x2526) {
                  x2528 = 0/*false*/;
                  x2529 = x2524;
                  char  *x2527 = x2523+1;
                  x2530 = x2527;
                } else {
                  x2530 = x2523;
                }
              }
              int x2542 = x2528;
              if (x2542) {
                char  *x2543 = x2530;
                x2379 = 0;
              } else {
                char x2546 = x2529;
                char  *x2547 = x2530;
                int x2552 = 1/*true*/;
                char x2553 = '\0';
                char  *x2554 = 0/*null*/;
                char x2548 = x2547[0];
                int x2549 = x2548 == '\0';
                if (x2549) {
                  x2554 = x2547;
                } else {
                  int x2550 = x2548 == 'r';
                  if (x2550) {
                    x2552 = 0/*false*/;
                    x2553 = x2548;
                    char  *x2551 = x2547+1;
                    x2554 = x2551;
                  } else {
                    x2554 = x2547;
                  }
                }
                int x2566 = x2552;
                if (x2566) {
                  char  *x2567 = x2554;
                  x2379 = 0;
                } else {
                  char x2570 = x2553;
                  char  *x2571 = x2554;
                  int x2576 = 1/*true*/;
                  char x2577 = '\0';
                  char  *x2578 = 0/*null*/;
                  char x2572 = x2571[0];
                  int x2573 = x2572 == '\0';
                  if (x2573) {
                    x2578 = x2571;
                  } else {
                    int x2574 = x2572 == '-';
                    if (x2574) {
                      x2576 = 0/*false*/;
                      x2577 = x2572;
                      char  *x2575 = x2571+1;
                      x2578 = x2575;
                    } else {
                      x2578 = x2571;
                    }
                  }
                  int x2590 = x2576;
                  if (x2590) {
                    char  *x2591 = x2578;
                    x2379 = 0;
                  } else {
                    char x2594 = x2577;
                    char  *x2595 = x2578;
                    int x2600 = 1/*true*/;
                    char x2601 = '\0';
                    char  *x2602 = 0/*null*/;
                    char x2596 = x2595[0];
                    int x2597 = x2596 == '\0';
                    if (x2597) {
                      x2602 = x2595;
                    } else {
                      int x2598 = x2596 == 'E';
                      if (x2598) {
                        x2600 = 0/*false*/;
                        x2601 = x2596;
                        char  *x2599 = x2595+1;
                        x2602 = x2599;
                      } else {
                        x2602 = x2595;
                      }
                    }
                    int x2614 = x2600;
                    if (x2614) {
                      char  *x2615 = x2602;
                      x2379 = 0;
                    } else {
                      char x2618 = x2601;
                      char  *x2619 = x2602;
                      int x2624 = 1/*true*/;
                      char x2625 = '\0';
                      char  *x2626 = 0/*null*/;
                      char x2620 = x2619[0];
                      int x2621 = x2620 == '\0';
                      if (x2621) {
                        x2626 = x2619;
                      } else {
                        int x2622 = x2620 == 'n';
                        if (x2622) {
                          x2624 = 0/*false*/;
                          x2625 = x2620;
                          char  *x2623 = x2619+1;
                          x2626 = x2623;
                        } else {
                          x2626 = x2619;
                        }
                      }
                      int x2638 = x2624;
                      if (x2638) {
                        char  *x2639 = x2626;
                        x2379 = 0;
                      } else {
                        char x2642 = x2625;
                        char  *x2643 = x2626;
                        int x2648 = 1/*true*/;
                        char x2649 = '\0';
                        char  *x2650 = 0/*null*/;
                        char x2644 = x2643[0];
                        int x2645 = x2644 == '\0';
                        if (x2645) {
                          x2650 = x2643;
                        } else {
                          int x2646 = x2644 == 'c';
                          if (x2646) {
                            x2648 = 0/*false*/;
                            x2649 = x2644;
                            char  *x2647 = x2643+1;
                            x2650 = x2647;
                          } else {
                            x2650 = x2643;
                          }
                        }
                        int x2662 = x2648;
                        if (x2662) {
                          char  *x2663 = x2650;
                          x2379 = 0;
                        } else {
                          char x2666 = x2649;
                          char  *x2667 = x2650;
                          int x2672 = 1/*true*/;
                          char x2673 = '\0';
                          char  *x2674 = 0/*null*/;
                          char x2668 = x2667[0];
                          int x2669 = x2668 == '\0';
                          if (x2669) {
                            x2674 = x2667;
                          } else {
                            int x2670 = x2668 == 'o';
                            if (x2670) {
                              x2672 = 0/*false*/;
                              x2673 = x2668;
                              char  *x2671 = x2667+1;
                              x2674 = x2671;
                            } else {
                              x2674 = x2667;
                            }
                          }
                          int x2686 = x2672;
                          if (x2686) {
                            char  *x2687 = x2674;
                            x2379 = 0;
                          } else {
                            char x2690 = x2673;
                            char  *x2691 = x2674;
                            int x2696 = 1/*true*/;
                            char x2697 = '\0';
                            char  *x2698 = 0/*null*/;
                            char x2692 = x2691[0];
                            int x2693 = x2692 == '\0';
                            if (x2693) {
                              x2698 = x2691;
                            } else {
                              int x2694 = x2692 == 'd';
                              if (x2694) {
                                x2696 = 0/*false*/;
                                x2697 = x2692;
                                char  *x2695 = x2691+1;
                                x2698 = x2695;
                              } else {
                                x2698 = x2691;
                              }
                            }
                            int x2710 = x2696;
                            if (x2710) {
                              char  *x2711 = x2698;
                              x2379 = 0;
                            } else {
                              char x2714 = x2697;
                              char  *x2715 = x2698;
                              int x2720 = 1/*true*/;
                              char x2721 = '\0';
                              char  *x2722 = 0/*null*/;
                              char x2716 = x2715[0];
                              int x2717 = x2716 == '\0';
                              if (x2717) {
                                x2722 = x2715;
                              } else {
                                int x2718 = x2716 == 'i';
                                if (x2718) {
                                  x2720 = 0/*false*/;
                                  x2721 = x2716;
                                  char  *x2719 = x2715+1;
                                  x2722 = x2719;
                                } else {
                                  x2722 = x2715;
                                }
                              }
                              int x2734 = x2720;
                              if (x2734) {
                                char  *x2735 = x2722;
                                x2379 = 0;
                              } else {
                                char x2738 = x2721;
                                char  *x2739 = x2722;
                                int x2744 = 1/*true*/;
                                char x2745 = '\0';
                                char  *x2746 = 0/*null*/;
                                char x2740 = x2739[0];
                                int x2741 = x2740 == '\0';
                                if (x2741) {
                                  x2746 = x2739;
                                } else {
                                  int x2742 = x2740 == 'n';
                                  if (x2742) {
                                    x2744 = 0/*false*/;
                                    x2745 = x2740;
                                    char  *x2743 = x2739+1;
                                    x2746 = x2743;
                                  } else {
                                    x2746 = x2739;
                                  }
                                }
                                int x2758 = x2744;
                                if (x2758) {
                                  char  *x2759 = x2746;
                                  x2379 = 0;
                                } else {
                                  char x2762 = x2745;
                                  char  *x2763 = x2746;
                                  int x2768 = 1/*true*/;
                                  char x2769 = '\0';
                                  char  *x2770 = 0/*null*/;
                                  char x2764 = x2763[0];
                                  int x2765 = x2764 == '\0';
                                  if (x2765) {
                                    x2770 = x2763;
                                  } else {
                                    int x2766 = x2764 == 'g';
                                    if (x2766) {
                                      x2768 = 0/*false*/;
                                      x2769 = x2764;
                                      char  *x2767 = x2763+1;
                                      x2770 = x2767;
                                    } else {
                                      x2770 = x2763;
                                    }
                                  }
                                  int x2782 = x2768;
                                  if (x2782) {
                                    char  *x2783 = x2770;
                                    x2379 = 0;
                                  } else {
                                    char x2786 = x2769;
                                    char  *x2787 = x2770;
                                    x2379 = x2787;
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
  char  *x2823 = x2379;
  return x2823;
}
/*@
requires ((strlen(x2845)>=0) && \valid(x2845+(0..(strlen(x2845)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_chunked(char  * x2845) {
  char  *x2847 = x2845;
  int x2852 = 1/*true*/;
  char x2853 = '\0';
  char  *x2854 = 0/*null*/;
  char x2848 = x2845[0];
  int x2849 = x2848 == '\0';
  if (x2849) {
    x2854 = x2845;
  } else {
    int x2850 = x2848 == 'c';
    if (x2850) {
      x2852 = 0/*false*/;
      x2853 = x2848;
      char  *x2851 = x2845+1;
      x2854 = x2851;
    } else {
      x2854 = x2845;
    }
  }
  int x2866 = x2852;
  if (x2866) {
    char  *x2867 = x2854;
    x2847 = 0;
  } else {
    char x2870 = x2853;
    char  *x2871 = x2854;
    int x2876 = 1/*true*/;
    char x2877 = '\0';
    char  *x2878 = 0/*null*/;
    char x2872 = x2871[0];
    int x2873 = x2872 == '\0';
    if (x2873) {
      x2878 = x2871;
    } else {
      int x2874 = x2872 == 'h';
      if (x2874) {
        x2876 = 0/*false*/;
        x2877 = x2872;
        char  *x2875 = x2871+1;
        x2878 = x2875;
      } else {
        x2878 = x2871;
      }
    }
    int x2890 = x2876;
    if (x2890) {
      char  *x2891 = x2878;
      x2847 = 0;
    } else {
      char x2894 = x2877;
      char  *x2895 = x2878;
      int x2900 = 1/*true*/;
      char x2901 = '\0';
      char  *x2902 = 0/*null*/;
      char x2896 = x2895[0];
      int x2897 = x2896 == '\0';
      if (x2897) {
        x2902 = x2895;
      } else {
        int x2898 = x2896 == 'u';
        if (x2898) {
          x2900 = 0/*false*/;
          x2901 = x2896;
          char  *x2899 = x2895+1;
          x2902 = x2899;
        } else {
          x2902 = x2895;
        }
      }
      int x2914 = x2900;
      if (x2914) {
        char  *x2915 = x2902;
        x2847 = 0;
      } else {
        char x2918 = x2901;
        char  *x2919 = x2902;
        int x2924 = 1/*true*/;
        char x2925 = '\0';
        char  *x2926 = 0/*null*/;
        char x2920 = x2919[0];
        int x2921 = x2920 == '\0';
        if (x2921) {
          x2926 = x2919;
        } else {
          int x2922 = x2920 == 'n';
          if (x2922) {
            x2924 = 0/*false*/;
            x2925 = x2920;
            char  *x2923 = x2919+1;
            x2926 = x2923;
          } else {
            x2926 = x2919;
          }
        }
        int x2938 = x2924;
        if (x2938) {
          char  *x2939 = x2926;
          x2847 = 0;
        } else {
          char x2942 = x2925;
          char  *x2943 = x2926;
          int x2948 = 1/*true*/;
          char x2949 = '\0';
          char  *x2950 = 0/*null*/;
          char x2944 = x2943[0];
          int x2945 = x2944 == '\0';
          if (x2945) {
            x2950 = x2943;
          } else {
            int x2946 = x2944 == 'k';
            if (x2946) {
              x2948 = 0/*false*/;
              x2949 = x2944;
              char  *x2947 = x2943+1;
              x2950 = x2947;
            } else {
              x2950 = x2943;
            }
          }
          int x2962 = x2948;
          if (x2962) {
            char  *x2963 = x2950;
            x2847 = 0;
          } else {
            char x2966 = x2949;
            char  *x2967 = x2950;
            int x2972 = 1/*true*/;
            char x2973 = '\0';
            char  *x2974 = 0/*null*/;
            char x2968 = x2967[0];
            int x2969 = x2968 == '\0';
            if (x2969) {
              x2974 = x2967;
            } else {
              int x2970 = x2968 == 'e';
              if (x2970) {
                x2972 = 0/*false*/;
                x2973 = x2968;
                char  *x2971 = x2967+1;
                x2974 = x2971;
              } else {
                x2974 = x2967;
              }
            }
            int x2986 = x2972;
            if (x2986) {
              char  *x2987 = x2974;
              x2847 = 0;
            } else {
              char x2990 = x2973;
              char  *x2991 = x2974;
              int x2996 = 1/*true*/;
              char x2997 = '\0';
              char  *x2998 = 0/*null*/;
              char x2992 = x2991[0];
              int x2993 = x2992 == '\0';
              if (x2993) {
                x2998 = x2991;
              } else {
                int x2994 = x2992 == 'd';
                if (x2994) {
                  x2996 = 0/*false*/;
                  x2997 = x2992;
                  char  *x2995 = x2991+1;
                  x2998 = x2995;
                } else {
                  x2998 = x2991;
                }
              }
              int x3010 = x2996;
              if (x3010) {
                char  *x3011 = x2998;
                x2847 = 0;
              } else {
                char x3014 = x2997;
                char  *x3015 = x2998;
                x2847 = x3015;
              }
            }
          }
        }
      }
    }
  }
  char  *x3031 = x2847;
  return x3031;
}
