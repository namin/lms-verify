#include <limits.h>
#include <string.h>
char  * p_HTTP(char  * x1250);
char  * p_ContentLength(char  * x1252);
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
    int x1066 = -2 == -2;
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
      char  *x531 = 0/*null*/;
      int x532 = 0 == x512;
      if (x532) {
        x531 = x511;
      } else {
        x529 = 0/*false*/;
        x531 = x512;
      }
      int x540 = x529;
      if (x540) {
        char  *x541 = x531;
      } else {
        char  *x544 = x531;
        x526 = 0/*false*/;
        x527 = 1;
        x528 = x544;
      }
      int x550 = x526;
      if (x550) {
        char  *x551 = x511;
        int x552 = 1/*true*/;
        /*@
        loop invariant ((strlen(x551)>=0) && \valid(x551+(0..(strlen(x551)+1)-1)));
        loop assigns x551, x552;
        */
        for (;;) {
          int x553 = x552;
          if (!x553) break;
          char  *x555 = x551;
          char x556 = x555[0];
          int x557 = x556 == '\0';
          if (x557) {
            x552 = 0/*false*/;
          } else {
            int x559 = x556 == ':';
            int x561;
            if (x559) {
              x561 = 0/*false*/;
            } else {
              int x560 = x556 != ' ';
              x561 = x560;
            }
            if (x561) {
              char  *x562 = x555+1;
              x551 = x562;
            } else {
              x552 = 0/*false*/;
            }
          }
        }
        char  *x588 = x551;
        x523 = 0/*false*/;
        x524 = 0;
        x525 = x588;
      } else {
        int x593 = x527;
        char  *x594 = x528;
        x523 = 0/*false*/;
        x524 = x593;
        x525 = x594;
      }
      int x600 = x523;
      if (x600) {
        char  *x601 = x525;
        x522 = x601;
      } else {
        int x604 = x524;
        char  *x605 = x525;
        char  *x606 = x605;
        int x607 = 1/*true*/;
        /*@
        loop invariant ((strlen(x606)>=0) && \valid(x606+(0..(strlen(x606)+1)-1)));
        loop assigns x606, x607;
        */
        for (;;) {
          int x608 = x607;
          if (!x608) break;
          char  *x610 = x606;
          char x611 = x610[0];
          int x612 = x611 == '\0';
          if (x612) {
            x607 = 0/*false*/;
          } else {
            int x613 = x611 == ' ';
            if (x613) {
              char  *x614 = x610+1;
              x606 = x614;
            } else {
              x607 = 0/*false*/;
            }
          }
        }
        char  *x640 = x606;
        x520 = 0/*false*/;
        x521 = x604;
        x522 = x640;
      }
      int x646 = x520;
      if (x646) {
        char  *x647 = x522;
        x519 = x647;
      } else {
        int x650 = x521;
        char  *x651 = x522;
        int x656 = 1/*true*/;
        char x657 = '\0';
        char  *x658 = 0/*null*/;
        char x652 = x651[0];
        int x653 = x652 == '\0';
        if (x653) {
          x658 = x651;
        } else {
          int x654 = x652 == ':';
          if (x654) {
            x656 = 0/*false*/;
            x657 = x652;
            char  *x655 = x651+1;
            x658 = x655;
          } else {
            x658 = x651;
          }
        }
        int x670 = x656;
        if (x670) {
          char  *x671 = x658;
          x519 = x671;
        } else {
          char x674 = x657;
          char  *x675 = x658;
          x517 = 0/*false*/;
          x518 = x650;
          x519 = x675;
        }
      }
      int x683 = x517;
      if (x683) {
        char  *x684 = x519;
        x516 = x684;
      } else {
        int x687 = x518;
        char  *x688 = x519;
        char  *x689 = x688;
        int x690 = 1/*true*/;
        /*@
        loop invariant ((strlen(x689)>=0) && \valid(x689+(0..(strlen(x689)+1)-1)));
        loop assigns x689, x690;
        */
        for (;;) {
          int x691 = x690;
          if (!x691) break;
          char  *x693 = x689;
          char x694 = x693[0];
          int x695 = x694 == '\0';
          if (x695) {
            x690 = 0/*false*/;
          } else {
            int x696 = x694 == ' ';
            if (x696) {
              char  *x697 = x693+1;
              x689 = x697;
            } else {
              x690 = 0/*false*/;
            }
          }
        }
        char  *x723 = x689;
        x514 = 0/*false*/;
        x515 = x687;
        x516 = x723;
      }
      int x729 = x514;
      if (x729) {
        char  *x730 = x516;
        x507 = 0/*false*/;
      } else {
        int x733 = x515;
        char  *x734 = x516;
        char  *x742 = x734;
        int x743 = 1/*true*/;
        /*@
        loop invariant ((strlen(x742)>=0) && \valid(x742+(0..(strlen(x742)+1)-1)));
        loop assigns x742, x743;
        */
        for (;;) {
          int x744 = x743;
          if (!x744) break;
          char  *x746 = x742;
          char x747 = x746[0];
          int x748 = x747 == '\0';
          if (x748) {
            x743 = 0/*false*/;
          } else {
            int x753 = x747 == '\r';
            if (x753) {
              x743 = 0/*false*/;
            } else {
              char  *x750 = x746+1;
              x742 = x750;
            }
          }
        }
        char  *x777 = x742;
        int x735 = x733 == 1;
        if (x735) {
          int x778 = 1/*true*/;
          int x779 = 0;
          char  *x780 = 0/*null*/;
          int x781 = 1/*true*/;
          int x782 = 0;
          char  *x783 = 0/*null*/;
          int x784 = 1/*true*/;
          int x785 = 0;
          char  *x786 = 0/*null*/;
          int x787 = 1/*true*/;
          char x788 = '\0';
          char  *x789 = 0/*null*/;
          char x736 = x734[0];
          int x737 = x736 == '\0';
          if (x737) {
            x789 = x734;
          } else {
            int x738 = x736 >= '0';
            int x740;
            if (x738) {
              int x739 = x736 <= '9';
              x740 = x739;
            } else {
              x740 = 0/*false*/;
            }
            if (x740) {
              x787 = 0/*false*/;
              x788 = x736;
              char  *x741 = x734+1;
              x789 = x741;
            } else {
              x789 = x734;
            }
          }
          int x801 = x787;
          if (x801) {
            char  *x802 = x789;
            x786 = x802;
          } else {
            char x805 = x788;
            char  *x807 = x789;
            x784 = 0/*false*/;
            char x806 = x805 - '0';
            x785 = x806;
            x786 = x807;
          }
          int x813 = x784;
          if (x813) {
            char  *x814 = x786;
            x783 = x814;
          } else {
            int x817 = x785;
            char  *x818 = x786;
            char  *x819 = x818;
            int x820 = 1/*true*/;
            int x821 = x817;
            /*@
            loop invariant (((strlen(x819)>=0) && \valid(x819+(0..(strlen(x819)+1)-1))) && ((x821==-1) || (0<=x821)));
            loop assigns x819, x820, x821;
            */
            for (;;) {
              int x822 = x820;
              if (!x822) break;
              char  *x824 = x819;
              int x831 = 1/*true*/;
              char x832 = '\0';
              char  *x833 = 0/*null*/;
              char x825 = x824[0];
              int x826 = x825 == '\0';
              if (x826) {
                x833 = x824;
              } else {
                int x827 = x825 >= '0';
                int x829;
                if (x827) {
                  int x828 = x825 <= '9';
                  x829 = x828;
                } else {
                  x829 = 0/*false*/;
                }
                if (x829) {
                  x831 = 0/*false*/;
                  x832 = x825;
                  char  *x830 = x824+1;
                  x833 = x830;
                } else {
                  x833 = x824;
                }
              }
              int x845 = x831;
              if (x845) {
                char  *x846 = x833;
                x820 = 0/*false*/;
              } else {
                char x849 = x832;
                char  *x851 = x833;
                int x852 = x821;
                int x853 = x852 < 0;
                int x858;
                if (x853) {
                  x858 = x852;
                } else {
                  int x854 = x852 > x345;
                  int x857;
                  if (x854) {
                    x857 = -1;
                  } else {
                    char x850 = x849 - '0';
                    int x855 = x852 * 10;
                    int x856 = x855 + x850;
                    x857 = x856;
                  }
                  x858 = x857;
                }
                x821 = x858;
                x819 = x851;
              }
            }
            int x886 = x821;
            char  *x887 = x819;
            x781 = 0/*false*/;
            x782 = x886;
            x783 = x887;
          }
          int x893 = x781;
          if (x893) {
            char  *x894 = x783;
            x780 = x894;
          } else {
            int x897 = x782;
            char  *x898 = x783;
            char  *x899 = x898;
            int x900 = 1/*true*/;
            /*@
            loop invariant ((strlen(x899)>=0) && \valid(x899+(0..(strlen(x899)+1)-1)));
            loop assigns x899, x900;
            */
            for (;;) {
              int x901 = x900;
              if (!x901) break;
              char  *x903 = x899;
              char x904 = x903[0];
              int x905 = x904 == '\0';
              if (x905) {
                x900 = 0/*false*/;
              } else {
                int x906 = x904 == ' ';
                if (x906) {
                  char  *x907 = x903+1;
                  x899 = x907;
                } else {
                  x900 = 0/*false*/;
                }
              }
            }
            char  *x933 = x899;
            x778 = 0/*false*/;
            x779 = x897;
            x780 = x933;
          }
          int x939 = x778;
          if (x939) {
            char  *x940 = x780;
            x507 = 0/*false*/;
          } else {
            int x943 = x779;
            char  *x944 = x780;
            int x949 = 1/*true*/;
            char x950 = '\0';
            char  *x951 = 0/*null*/;
            char x945 = x944[0];
            int x946 = x945 == '\0';
            if (x946) {
              x951 = x944;
            } else {
              int x947 = x945 == '\r';
              if (x947) {
                x949 = 0/*false*/;
                x950 = x945;
                char  *x948 = x944+1;
                x951 = x948;
              } else {
                x951 = x944;
              }
            }
            int x963 = x949;
            if (x963) {
              char  *x964 = x951;
              x507 = 0/*false*/;
            } else {
              char x967 = x950;
              char  *x968 = x951;
              int x973 = 1/*true*/;
              char x974 = '\0';
              char  *x975 = 0/*null*/;
              char x969 = x968[0];
              int x970 = x969 == '\0';
              if (x970) {
                x975 = x968;
              } else {
                int x971 = x969 == '\n';
                if (x971) {
                  x973 = 0/*false*/;
                  x974 = x969;
                  char  *x972 = x968+1;
                  x975 = x972;
                } else {
                  x975 = x968;
                }
              }
              int x987 = x973;
              if (x987) {
                char  *x988 = x975;
                x507 = 0/*false*/;
              } else {
                char x991 = x974;
                char  *x992 = x975;
                int x993 = x508;
                int x994 = x943 == -2;
                int x995;
                if (x994) {
                  x995 = x993;
                } else {
                  x995 = x943;
                }
                x508 = x995;
                x506 = x992;
              }
            }
          }
        } else {
          int x1005 = 1/*true*/;
          char  *x1007 = 0/*null*/;
          x1005 = 0/*false*/;
          x1007 = x777;
          int x1011 = x1005;
          if (x1011) {
            char  *x1012 = x1007;
            x507 = 0/*false*/;
          } else {
            char  *x1016 = x1007;
            int x1021 = 1/*true*/;
            char x1022 = '\0';
            char  *x1023 = 0/*null*/;
            char x1017 = x1016[0];
            int x1018 = x1017 == '\0';
            if (x1018) {
              x1023 = x1016;
            } else {
              int x1019 = x1017 == '\r';
              if (x1019) {
                x1021 = 0/*false*/;
                x1022 = x1017;
                char  *x1020 = x1016+1;
                x1023 = x1020;
              } else {
                x1023 = x1016;
              }
            }
            int x1035 = x1021;
            if (x1035) {
              char  *x1036 = x1023;
              x507 = 0/*false*/;
            } else {
              char x1039 = x1022;
              char  *x1040 = x1023;
              int x1045 = 1/*true*/;
              char x1046 = '\0';
              char  *x1047 = 0/*null*/;
              char x1041 = x1040[0];
              int x1042 = x1041 == '\0';
              if (x1042) {
                x1047 = x1040;
              } else {
                int x1043 = x1041 == '\n';
                if (x1043) {
                  x1045 = 0/*false*/;
                  x1046 = x1041;
                  char  *x1044 = x1040+1;
                  x1047 = x1044;
                } else {
                  x1047 = x1040;
                }
              }
              int x1059 = x1045;
              if (x1059) {
                char  *x1060 = x1047;
                x507 = 0/*false*/;
              } else {
                char x1063 = x1046;
                char  *x1064 = x1047;
                int x1065 = x508;
                int x1067;
                if (x1066) {
                  x1067 = x1065;
                } else {
                  x1067 = -2;
                }
                x508 = x1067;
                x506 = x1064;
              }
            }
          }
        }
      }
    }
    int x1098 = x508;
    char  *x1099 = x506;
    x8 = 0/*false*/;
    x9 = x1098;
    x10 = x1099;
  }
  int x1105 = x8;
  if (x1105) {
    char  *x1106 = x10;
    x7 = x1106;
  } else {
    int x1109 = x9;
    char  *x1110 = x10;
    int x1115 = 1/*true*/;
    char x1116 = '\0';
    char  *x1117 = 0/*null*/;
    char x1111 = x1110[0];
    int x1112 = x1111 == '\0';
    if (x1112) {
      x1117 = x1110;
    } else {
      int x1113 = x1111 == '\r';
      if (x1113) {
        x1115 = 0/*false*/;
        x1116 = x1111;
        char  *x1114 = x1110+1;
        x1117 = x1114;
      } else {
        x1117 = x1110;
      }
    }
    int x1129 = x1115;
    if (x1129) {
      char  *x1130 = x1117;
      x7 = x1130;
    } else {
      char x1133 = x1116;
      char  *x1134 = x1117;
      int x1139 = 1/*true*/;
      char x1140 = '\0';
      char  *x1141 = 0/*null*/;
      char x1135 = x1134[0];
      int x1136 = x1135 == '\0';
      if (x1136) {
        x1141 = x1134;
      } else {
        int x1137 = x1135 == '\n';
        if (x1137) {
          x1139 = 0/*false*/;
          x1140 = x1135;
          char  *x1138 = x1134+1;
          x1141 = x1138;
        } else {
          x1141 = x1134;
        }
      }
      int x1153 = x1139;
      if (x1153) {
        char  *x1154 = x1141;
        x7 = x1154;
      } else {
        char x1157 = x1140;
        char  *x1158 = x1141;
        x5 = 0/*false*/;
        x6 = x1109;
        x7 = x1158;
      }
    }
  }
  int x1168 = x5;
  if (x1168) {
    char  *x1169 = x7;
  } else {
    int x1171 = x6;
    char  *x1172 = x7;
    int x1174 = 1/*true*/;
    char  *x1175 = x1172;
    /*@
    loop invariant ((0<=x1177) && ((strlen(x1175)>=0) && \valid(x1175+(0..(strlen(x1175)+1)-1))));
    loop assigns x1177, x1174, x1175;
    loop variant (x1171-x1177);
    */
    for(int x1177=0; x1177 < x1171; x1177++) {
      int x1178 = x1174;
      if (x1178) {
        char  *x1179 = x1175;
        char x1180 = x1179[0];
        int x1181 = x1180 == '\0';
        if (x1181) {
          x1174 = 0/*false*/;
        } else {
          char  *x1182 = x1179+1;
          x1175 = x1182;
        }
      } else {
      }
    }
    int x1211 = x1174;
    char  *x1212 = x1175;
    int x1173 = x1171 < 0;
    if (x1173) {
    } else {
      int x1213 = 1/*true*/;
      char  *x1215 = 0/*null*/;
      if (x1211) {
        x1213 = 0/*false*/;
        x1215 = x1212;
      } else {
        x1215 = x1172;
      }
      int x1223 = x1213;
      if (x1223) {
        char  *x1224 = x1215;
      } else {
        char  *x1227 = x1215;
        char x1228 = x1227[0];
        int x1229 = x1228 == '\0';
        if (x1229) {
          x2 = x1171;
        } else {
        }
      }
    }
  }
  int x1239 = x2;
  return x1239;
}
/*@
requires ((strlen(x1254)>=0) && \valid(x1254+(0..(strlen(x1254)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_HTTP(char  * x1254) {
  char  *x1256 = x1254;
  int x1261 = 1/*true*/;
  char x1262 = '\0';
  char  *x1263 = 0/*null*/;
  char x1257 = x1254[0];
  int x1258 = x1257 == '\0';
  if (x1258) {
    x1263 = x1254;
  } else {
    int x1259 = x1257 == 'H';
    if (x1259) {
      x1261 = 0/*false*/;
      x1262 = x1257;
      char  *x1260 = x1254+1;
      x1263 = x1260;
    } else {
      x1263 = x1254;
    }
  }
  int x1275 = x1261;
  if (x1275) {
    char  *x1276 = x1263;
    x1256 = 0;
  } else {
    char x1279 = x1262;
    char  *x1280 = x1263;
    int x1285 = 1/*true*/;
    char x1286 = '\0';
    char  *x1287 = 0/*null*/;
    char x1281 = x1280[0];
    int x1282 = x1281 == '\0';
    if (x1282) {
      x1287 = x1280;
    } else {
      int x1283 = x1281 == 'T';
      if (x1283) {
        x1285 = 0/*false*/;
        x1286 = x1281;
        char  *x1284 = x1280+1;
        x1287 = x1284;
      } else {
        x1287 = x1280;
      }
    }
    int x1299 = x1285;
    if (x1299) {
      char  *x1300 = x1287;
      x1256 = 0;
    } else {
      char x1303 = x1286;
      char  *x1304 = x1287;
      int x1309 = 1/*true*/;
      char x1310 = '\0';
      char  *x1311 = 0/*null*/;
      char x1305 = x1304[0];
      int x1306 = x1305 == '\0';
      if (x1306) {
        x1311 = x1304;
      } else {
        int x1307 = x1305 == 'T';
        if (x1307) {
          x1309 = 0/*false*/;
          x1310 = x1305;
          char  *x1308 = x1304+1;
          x1311 = x1308;
        } else {
          x1311 = x1304;
        }
      }
      int x1323 = x1309;
      if (x1323) {
        char  *x1324 = x1311;
        x1256 = 0;
      } else {
        char x1327 = x1310;
        char  *x1328 = x1311;
        int x1333 = 1/*true*/;
        char x1334 = '\0';
        char  *x1335 = 0/*null*/;
        char x1329 = x1328[0];
        int x1330 = x1329 == '\0';
        if (x1330) {
          x1335 = x1328;
        } else {
          int x1331 = x1329 == 'P';
          if (x1331) {
            x1333 = 0/*false*/;
            x1334 = x1329;
            char  *x1332 = x1328+1;
            x1335 = x1332;
          } else {
            x1335 = x1328;
          }
        }
        int x1347 = x1333;
        if (x1347) {
          char  *x1348 = x1335;
          x1256 = 0;
        } else {
          char x1351 = x1334;
          char  *x1352 = x1335;
          int x1357 = 1/*true*/;
          char x1358 = '\0';
          char  *x1359 = 0/*null*/;
          char x1353 = x1352[0];
          int x1354 = x1353 == '\0';
          if (x1354) {
            x1359 = x1352;
          } else {
            int x1355 = x1353 == '/';
            if (x1355) {
              x1357 = 0/*false*/;
              x1358 = x1353;
              char  *x1356 = x1352+1;
              x1359 = x1356;
            } else {
              x1359 = x1352;
            }
          }
          int x1371 = x1357;
          if (x1371) {
            char  *x1372 = x1359;
            x1256 = 0;
          } else {
            char x1375 = x1358;
            char  *x1376 = x1359;
            x1256 = x1376;
          }
        }
      }
    }
  }
  char  *x1388 = x1256;
  return x1388;
}
/*@
requires ((strlen(x1410)>=0) && \valid(x1410+(0..(strlen(x1410)+1)-1)));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..(strlen(\result)+1)-1))));
*/
char  * p_ContentLength(char  * x1410) {
  char  *x1412 = x1410;
  int x1417 = 1/*true*/;
  char x1418 = '\0';
  char  *x1419 = 0/*null*/;
  char x1413 = x1410[0];
  int x1414 = x1413 == '\0';
  if (x1414) {
    x1419 = x1410;
  } else {
    int x1415 = x1413 == 'C';
    if (x1415) {
      x1417 = 0/*false*/;
      x1418 = x1413;
      char  *x1416 = x1410+1;
      x1419 = x1416;
    } else {
      x1419 = x1410;
    }
  }
  int x1431 = x1417;
  if (x1431) {
    char  *x1432 = x1419;
    x1412 = 0;
  } else {
    char x1435 = x1418;
    char  *x1436 = x1419;
    int x1441 = 1/*true*/;
    char x1442 = '\0';
    char  *x1443 = 0/*null*/;
    char x1437 = x1436[0];
    int x1438 = x1437 == '\0';
    if (x1438) {
      x1443 = x1436;
    } else {
      int x1439 = x1437 == 'o';
      if (x1439) {
        x1441 = 0/*false*/;
        x1442 = x1437;
        char  *x1440 = x1436+1;
        x1443 = x1440;
      } else {
        x1443 = x1436;
      }
    }
    int x1455 = x1441;
    if (x1455) {
      char  *x1456 = x1443;
      x1412 = 0;
    } else {
      char x1459 = x1442;
      char  *x1460 = x1443;
      int x1465 = 1/*true*/;
      char x1466 = '\0';
      char  *x1467 = 0/*null*/;
      char x1461 = x1460[0];
      int x1462 = x1461 == '\0';
      if (x1462) {
        x1467 = x1460;
      } else {
        int x1463 = x1461 == 'n';
        if (x1463) {
          x1465 = 0/*false*/;
          x1466 = x1461;
          char  *x1464 = x1460+1;
          x1467 = x1464;
        } else {
          x1467 = x1460;
        }
      }
      int x1479 = x1465;
      if (x1479) {
        char  *x1480 = x1467;
        x1412 = 0;
      } else {
        char x1483 = x1466;
        char  *x1484 = x1467;
        int x1489 = 1/*true*/;
        char x1490 = '\0';
        char  *x1491 = 0/*null*/;
        char x1485 = x1484[0];
        int x1486 = x1485 == '\0';
        if (x1486) {
          x1491 = x1484;
        } else {
          int x1487 = x1485 == 't';
          if (x1487) {
            x1489 = 0/*false*/;
            x1490 = x1485;
            char  *x1488 = x1484+1;
            x1491 = x1488;
          } else {
            x1491 = x1484;
          }
        }
        int x1503 = x1489;
        if (x1503) {
          char  *x1504 = x1491;
          x1412 = 0;
        } else {
          char x1507 = x1490;
          char  *x1508 = x1491;
          int x1513 = 1/*true*/;
          char x1514 = '\0';
          char  *x1515 = 0/*null*/;
          char x1509 = x1508[0];
          int x1510 = x1509 == '\0';
          if (x1510) {
            x1515 = x1508;
          } else {
            int x1511 = x1509 == 'e';
            if (x1511) {
              x1513 = 0/*false*/;
              x1514 = x1509;
              char  *x1512 = x1508+1;
              x1515 = x1512;
            } else {
              x1515 = x1508;
            }
          }
          int x1527 = x1513;
          if (x1527) {
            char  *x1528 = x1515;
            x1412 = 0;
          } else {
            char x1531 = x1514;
            char  *x1532 = x1515;
            int x1537 = 1/*true*/;
            char x1538 = '\0';
            char  *x1539 = 0/*null*/;
            char x1533 = x1532[0];
            int x1534 = x1533 == '\0';
            if (x1534) {
              x1539 = x1532;
            } else {
              int x1535 = x1533 == 'n';
              if (x1535) {
                x1537 = 0/*false*/;
                x1538 = x1533;
                char  *x1536 = x1532+1;
                x1539 = x1536;
              } else {
                x1539 = x1532;
              }
            }
            int x1551 = x1537;
            if (x1551) {
              char  *x1552 = x1539;
              x1412 = 0;
            } else {
              char x1555 = x1538;
              char  *x1556 = x1539;
              int x1561 = 1/*true*/;
              char x1562 = '\0';
              char  *x1563 = 0/*null*/;
              char x1557 = x1556[0];
              int x1558 = x1557 == '\0';
              if (x1558) {
                x1563 = x1556;
              } else {
                int x1559 = x1557 == 't';
                if (x1559) {
                  x1561 = 0/*false*/;
                  x1562 = x1557;
                  char  *x1560 = x1556+1;
                  x1563 = x1560;
                } else {
                  x1563 = x1556;
                }
              }
              int x1575 = x1561;
              if (x1575) {
                char  *x1576 = x1563;
                x1412 = 0;
              } else {
                char x1579 = x1562;
                char  *x1580 = x1563;
                int x1585 = 1/*true*/;
                char x1586 = '\0';
                char  *x1587 = 0/*null*/;
                char x1581 = x1580[0];
                int x1582 = x1581 == '\0';
                if (x1582) {
                  x1587 = x1580;
                } else {
                  int x1583 = x1581 == '-';
                  if (x1583) {
                    x1585 = 0/*false*/;
                    x1586 = x1581;
                    char  *x1584 = x1580+1;
                    x1587 = x1584;
                  } else {
                    x1587 = x1580;
                  }
                }
                int x1599 = x1585;
                if (x1599) {
                  char  *x1600 = x1587;
                  x1412 = 0;
                } else {
                  char x1603 = x1586;
                  char  *x1604 = x1587;
                  int x1609 = 1/*true*/;
                  char x1610 = '\0';
                  char  *x1611 = 0/*null*/;
                  char x1605 = x1604[0];
                  int x1606 = x1605 == '\0';
                  if (x1606) {
                    x1611 = x1604;
                  } else {
                    int x1607 = x1605 == 'L';
                    if (x1607) {
                      x1609 = 0/*false*/;
                      x1610 = x1605;
                      char  *x1608 = x1604+1;
                      x1611 = x1608;
                    } else {
                      x1611 = x1604;
                    }
                  }
                  int x1623 = x1609;
                  if (x1623) {
                    char  *x1624 = x1611;
                    x1412 = 0;
                  } else {
                    char x1627 = x1610;
                    char  *x1628 = x1611;
                    int x1633 = 1/*true*/;
                    char x1634 = '\0';
                    char  *x1635 = 0/*null*/;
                    char x1629 = x1628[0];
                    int x1630 = x1629 == '\0';
                    if (x1630) {
                      x1635 = x1628;
                    } else {
                      int x1631 = x1629 == 'e';
                      if (x1631) {
                        x1633 = 0/*false*/;
                        x1634 = x1629;
                        char  *x1632 = x1628+1;
                        x1635 = x1632;
                      } else {
                        x1635 = x1628;
                      }
                    }
                    int x1647 = x1633;
                    if (x1647) {
                      char  *x1648 = x1635;
                      x1412 = 0;
                    } else {
                      char x1651 = x1634;
                      char  *x1652 = x1635;
                      int x1657 = 1/*true*/;
                      char x1658 = '\0';
                      char  *x1659 = 0/*null*/;
                      char x1653 = x1652[0];
                      int x1654 = x1653 == '\0';
                      if (x1654) {
                        x1659 = x1652;
                      } else {
                        int x1655 = x1653 == 'n';
                        if (x1655) {
                          x1657 = 0/*false*/;
                          x1658 = x1653;
                          char  *x1656 = x1652+1;
                          x1659 = x1656;
                        } else {
                          x1659 = x1652;
                        }
                      }
                      int x1671 = x1657;
                      if (x1671) {
                        char  *x1672 = x1659;
                        x1412 = 0;
                      } else {
                        char x1675 = x1658;
                        char  *x1676 = x1659;
                        int x1681 = 1/*true*/;
                        char x1682 = '\0';
                        char  *x1683 = 0/*null*/;
                        char x1677 = x1676[0];
                        int x1678 = x1677 == '\0';
                        if (x1678) {
                          x1683 = x1676;
                        } else {
                          int x1679 = x1677 == 'g';
                          if (x1679) {
                            x1681 = 0/*false*/;
                            x1682 = x1677;
                            char  *x1680 = x1676+1;
                            x1683 = x1680;
                          } else {
                            x1683 = x1676;
                          }
                        }
                        int x1695 = x1681;
                        if (x1695) {
                          char  *x1696 = x1683;
                          x1412 = 0;
                        } else {
                          char x1699 = x1682;
                          char  *x1700 = x1683;
                          int x1705 = 1/*true*/;
                          char x1706 = '\0';
                          char  *x1707 = 0/*null*/;
                          char x1701 = x1700[0];
                          int x1702 = x1701 == '\0';
                          if (x1702) {
                            x1707 = x1700;
                          } else {
                            int x1703 = x1701 == 't';
                            if (x1703) {
                              x1705 = 0/*false*/;
                              x1706 = x1701;
                              char  *x1704 = x1700+1;
                              x1707 = x1704;
                            } else {
                              x1707 = x1700;
                            }
                          }
                          int x1719 = x1705;
                          if (x1719) {
                            char  *x1720 = x1707;
                            x1412 = 0;
                          } else {
                            char x1723 = x1706;
                            char  *x1724 = x1707;
                            int x1729 = 1/*true*/;
                            char x1730 = '\0';
                            char  *x1731 = 0/*null*/;
                            char x1725 = x1724[0];
                            int x1726 = x1725 == '\0';
                            if (x1726) {
                              x1731 = x1724;
                            } else {
                              int x1727 = x1725 == 'h';
                              if (x1727) {
                                x1729 = 0/*false*/;
                                x1730 = x1725;
                                char  *x1728 = x1724+1;
                                x1731 = x1728;
                              } else {
                                x1731 = x1724;
                              }
                            }
                            int x1743 = x1729;
                            if (x1743) {
                              char  *x1744 = x1731;
                              x1412 = 0;
                            } else {
                              char x1747 = x1730;
                              char  *x1748 = x1731;
                              x1412 = x1748;
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
  char  *x1778 = x1412;
  return x1778;
}
