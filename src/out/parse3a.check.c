#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..(strlen(x0)+1)-1)));
assigns \nothing;
*/
int p(char  * x0) {
  int x2 = -1;
  char  *x3 = x0;
  int x4 = 1/*true*/;
  int x5 = 0;
  int x705 = INT_MAX;
  int x706 = x705 / 10;
  int x707 = x706 - 10;
  int x926 = -2 == -2;
  /*@
  loop invariant ((strlen(x3)>=0) &&
  \valid(x3+(0..(strlen(x3)+1)-1)));
  loop assigns x3, x4, x5;
  */
  for (;;) {
    int x6 = x4;
    if (!x6) break;
    char  *x8 = x3;
    int x13 = 1/*true*/;
    int x14 = 0;
    char  *x15 = 0/*null*/;
    int x16 = 1/*true*/;
    int x17 = 0;
    char  *x18 = 0/*null*/;
    int x19 = 1/*true*/;
    int x20 = 0;
    char  *x21 = 0/*null*/;
    int x22 = 1/*true*/;
    int x23 = 0;
    char  *x24 = 0/*null*/;
    int x25 = 1/*true*/;
    int x26 = 0;
    char  *x27 = 0/*null*/;
    int x28 = 1/*true*/;
    char x29 = '\0';
    char  *x30 = 0/*null*/;
    char x9 = x8[0];
    int x10 = x9 == '\0';
    if (x10) {
      x30 = x8;
    } else {
      int x11 = x9 == 'C';
      if (x11) {
        x28 = 0/*false*/;
        x29 = x9;
        char  *x12 = x8+1;
        x30 = x12;
      } else {
        x30 = x8;
      }
    }
    int x42 = x28;
    if (x42) {
      char  *x43 = x30;
    } else {
      char x45 = x29;
      char  *x46 = x30;
      int x51 = 1/*true*/;
      char x52 = '\0';
      char  *x53 = 0/*null*/;
      char x47 = x46[0];
      int x48 = x47 == '\0';
      if (x48) {
        x53 = x46;
      } else {
        int x49 = x47 == 'o';
        if (x49) {
          x51 = 0/*false*/;
          x52 = x47;
          char  *x50 = x46+1;
          x53 = x50;
        } else {
          x53 = x46;
        }
      }
      int x65 = x51;
      if (x65) {
        char  *x66 = x53;
      } else {
        char x68 = x52;
        char  *x69 = x53;
        int x74 = 1/*true*/;
        char x75 = '\0';
        char  *x76 = 0/*null*/;
        char x70 = x69[0];
        int x71 = x70 == '\0';
        if (x71) {
          x76 = x69;
        } else {
          int x72 = x70 == 'n';
          if (x72) {
            x74 = 0/*false*/;
            x75 = x70;
            char  *x73 = x69+1;
            x76 = x73;
          } else {
            x76 = x69;
          }
        }
        int x88 = x74;
        if (x88) {
          char  *x89 = x76;
        } else {
          char x91 = x75;
          char  *x92 = x76;
          int x97 = 1/*true*/;
          char x98 = '\0';
          char  *x99 = 0/*null*/;
          char x93 = x92[0];
          int x94 = x93 == '\0';
          if (x94) {
            x99 = x92;
          } else {
            int x95 = x93 == 't';
            if (x95) {
              x97 = 0/*false*/;
              x98 = x93;
              char  *x96 = x92+1;
              x99 = x96;
            } else {
              x99 = x92;
            }
          }
          int x111 = x97;
          if (x111) {
            char  *x112 = x99;
          } else {
            char x114 = x98;
            char  *x115 = x99;
            int x120 = 1/*true*/;
            char x121 = '\0';
            char  *x122 = 0/*null*/;
            char x116 = x115[0];
            int x117 = x116 == '\0';
            if (x117) {
              x122 = x115;
            } else {
              int x118 = x116 == 'e';
              if (x118) {
                x120 = 0/*false*/;
                x121 = x116;
                char  *x119 = x115+1;
                x122 = x119;
              } else {
                x122 = x115;
              }
            }
            int x134 = x120;
            if (x134) {
              char  *x135 = x122;
            } else {
              char x137 = x121;
              char  *x138 = x122;
              int x143 = 1/*true*/;
              char x144 = '\0';
              char  *x145 = 0/*null*/;
              char x139 = x138[0];
              int x140 = x139 == '\0';
              if (x140) {
                x145 = x138;
              } else {
                int x141 = x139 == 'n';
                if (x141) {
                  x143 = 0/*false*/;
                  x144 = x139;
                  char  *x142 = x138+1;
                  x145 = x142;
                } else {
                  x145 = x138;
                }
              }
              int x157 = x143;
              if (x157) {
                char  *x158 = x145;
              } else {
                char x160 = x144;
                char  *x161 = x145;
                int x166 = 1/*true*/;
                char x167 = '\0';
                char  *x168 = 0/*null*/;
                char x162 = x161[0];
                int x163 = x162 == '\0';
                if (x163) {
                  x168 = x161;
                } else {
                  int x164 = x162 == 't';
                  if (x164) {
                    x166 = 0/*false*/;
                    x167 = x162;
                    char  *x165 = x161+1;
                    x168 = x165;
                  } else {
                    x168 = x161;
                  }
                }
                int x180 = x166;
                if (x180) {
                  char  *x181 = x168;
                } else {
                  char x183 = x167;
                  char  *x184 = x168;
                  int x189 = 1/*true*/;
                  char x190 = '\0';
                  char  *x191 = 0/*null*/;
                  char x185 = x184[0];
                  int x186 = x185 == '\0';
                  if (x186) {
                    x191 = x184;
                  } else {
                    int x187 = x185 == '-';
                    if (x187) {
                      x189 = 0/*false*/;
                      x190 = x185;
                      char  *x188 = x184+1;
                      x191 = x188;
                    } else {
                      x191 = x184;
                    }
                  }
                  int x203 = x189;
                  if (x203) {
                    char  *x204 = x191;
                  } else {
                    char x206 = x190;
                    char  *x207 = x191;
                    int x212 = 1/*true*/;
                    char x213 = '\0';
                    char  *x214 = 0/*null*/;
                    char x208 = x207[0];
                    int x209 = x208 == '\0';
                    if (x209) {
                      x214 = x207;
                    } else {
                      int x210 = x208 == 'L';
                      if (x210) {
                        x212 = 0/*false*/;
                        x213 = x208;
                        char  *x211 = x207+1;
                        x214 = x211;
                      } else {
                        x214 = x207;
                      }
                    }
                    int x226 = x212;
                    if (x226) {
                      char  *x227 = x214;
                    } else {
                      char x229 = x213;
                      char  *x230 = x214;
                      int x235 = 1/*true*/;
                      char x236 = '\0';
                      char  *x237 = 0/*null*/;
                      char x231 = x230[0];
                      int x232 = x231 == '\0';
                      if (x232) {
                        x237 = x230;
                      } else {
                        int x233 = x231 == 'e';
                        if (x233) {
                          x235 = 0/*false*/;
                          x236 = x231;
                          char  *x234 = x230+1;
                          x237 = x234;
                        } else {
                          x237 = x230;
                        }
                      }
                      int x249 = x235;
                      if (x249) {
                        char  *x250 = x237;
                      } else {
                        char x252 = x236;
                        char  *x253 = x237;
                        int x258 = 1/*true*/;
                        char x259 = '\0';
                        char  *x260 = 0/*null*/;
                        char x254 = x253[0];
                        int x255 = x254 == '\0';
                        if (x255) {
                          x260 = x253;
                        } else {
                          int x256 = x254 == 'n';
                          if (x256) {
                            x258 = 0/*false*/;
                            x259 = x254;
                            char  *x257 = x253+1;
                            x260 = x257;
                          } else {
                            x260 = x253;
                          }
                        }
                        int x272 = x258;
                        if (x272) {
                          char  *x273 = x260;
                        } else {
                          char x275 = x259;
                          char  *x276 = x260;
                          int x281 = 1/*true*/;
                          char x282 = '\0';
                          char  *x283 = 0/*null*/;
                          char x277 = x276[0];
                          int x278 = x277 == '\0';
                          if (x278) {
                            x283 = x276;
                          } else {
                            int x279 = x277 == 'g';
                            if (x279) {
                              x281 = 0/*false*/;
                              x282 = x277;
                              char  *x280 = x276+1;
                              x283 = x280;
                            } else {
                              x283 = x276;
                            }
                          }
                          int x295 = x281;
                          if (x295) {
                            char  *x296 = x283;
                          } else {
                            char x298 = x282;
                            char  *x299 = x283;
                            int x304 = 1/*true*/;
                            char x305 = '\0';
                            char  *x306 = 0/*null*/;
                            char x300 = x299[0];
                            int x301 = x300 == '\0';
                            if (x301) {
                              x306 = x299;
                            } else {
                              int x302 = x300 == 't';
                              if (x302) {
                                x304 = 0/*false*/;
                                x305 = x300;
                                char  *x303 = x299+1;
                                x306 = x303;
                              } else {
                                x306 = x299;
                              }
                            }
                            int x318 = x304;
                            if (x318) {
                              char  *x319 = x306;
                            } else {
                              char x321 = x305;
                              char  *x322 = x306;
                              int x327 = 1/*true*/;
                              char x328 = '\0';
                              char  *x329 = 0/*null*/;
                              char x323 = x322[0];
                              int x324 = x323 == '\0';
                              if (x324) {
                                x329 = x322;
                              } else {
                                int x325 = x323 == 'h';
                                if (x325) {
                                  x327 = 0/*false*/;
                                  x328 = x323;
                                  char  *x326 = x322+1;
                                  x329 = x326;
                                } else {
                                  x329 = x322;
                                }
                              }
                              int x341 = x327;
                              if (x341) {
                                char  *x342 = x329;
                              } else {
                                char x344 = x328;
                                char  *x345 = x329;
                                x25 = 0/*false*/;
                                x26 = 1;
                                x27 = x345;
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
    int x377 = x25;
    if (x377) {
      char  *x378 = x8;
      int x379 = 1/*true*/;
      /*@
      loop invariant ((strlen(x378)>=0) &&
      \valid(x378+(0..(strlen(x378)+1)-1)));
      loop assigns x378, x379;
      */
      for (;;) {
        int x381 = x379;
        if (!x381) break;
        char  *x383 = x378;
        char x384 = x383[0];
        int x385 = x384 == '\0';
        if (x385) {
          x379 = 0/*false*/;
        } else {
          int x387 = x384 == ':';
          int x389;
          if (x387) {
            x389 = 0/*false*/;
          } else {
            int x388 = x384 != ' ';
            x389 = x388;
          }
          if (x389) {
            char  *x390 = x383+1;
            x378 = x390;
          } else {
            x379 = 0/*false*/;
          }
        }
      }
      char  *x421 = x378;
      x22 = 0/*false*/;
      x23 = 0;
      x24 = x421;
    } else {
      int x426 = x26;
      char  *x427 = x27;
      x22 = 0/*false*/;
      x23 = x426;
      x24 = x427;
    }
    int x433 = x22;
    if (x433) {
      char  *x434 = x24;
      x21 = x434;
    } else {
      int x437 = x23;
      char  *x438 = x24;
      char  *x439 = x438;
      int x440 = 1/*true*/;
      /*@
      loop invariant ((strlen(x439)>=0) &&
      \valid(x439+(0..(strlen(x439)+1)-1)));
      loop assigns x439, x440;
      */
      for (;;) {
        int x442 = x440;
        if (!x442) break;
        char  *x444 = x439;
        char x445 = x444[0];
        int x446 = x445 == '\0';
        if (x446) {
          x440 = 0/*false*/;
        } else {
          int x447 = x445 == ' ';
          if (x447) {
            char  *x448 = x444+1;
            x439 = x448;
          } else {
            x440 = 0/*false*/;
          }
        }
      }
      char  *x479 = x439;
      x19 = 0/*false*/;
      x20 = x437;
      x21 = x479;
    }
    int x485 = x19;
    if (x485) {
      char  *x486 = x21;
      x18 = x486;
    } else {
      int x489 = x20;
      char  *x490 = x21;
      int x495 = 1/*true*/;
      char x496 = '\0';
      char  *x497 = 0/*null*/;
      char x491 = x490[0];
      int x492 = x491 == '\0';
      if (x492) {
        x497 = x490;
      } else {
        int x493 = x491 == ':';
        if (x493) {
          x495 = 0/*false*/;
          x496 = x491;
          char  *x494 = x490+1;
          x497 = x494;
        } else {
          x497 = x490;
        }
      }
      int x509 = x495;
      if (x509) {
        char  *x510 = x497;
        x18 = x510;
      } else {
        char x513 = x496;
        char  *x514 = x497;
        x16 = 0/*false*/;
        x17 = x489;
        x18 = x514;
      }
    }
    int x522 = x16;
    if (x522) {
      char  *x523 = x18;
      x15 = x523;
    } else {
      int x526 = x17;
      char  *x527 = x18;
      char  *x528 = x527;
      int x529 = 1/*true*/;
      /*@
      loop invariant ((strlen(x528)>=0) &&
      \valid(x528+(0..(strlen(x528)+1)-1)));
      loop assigns x528, x529;
      */
      for (;;) {
        int x531 = x529;
        if (!x531) break;
        char  *x533 = x528;
        char x534 = x533[0];
        int x535 = x534 == '\0';
        if (x535) {
          x529 = 0/*false*/;
        } else {
          int x536 = x534 == ' ';
          if (x536) {
            char  *x537 = x533+1;
            x528 = x537;
          } else {
            x529 = 0/*false*/;
          }
        }
      }
      char  *x568 = x528;
      x13 = 0/*false*/;
      x14 = x526;
      x15 = x568;
    }
    int x574 = x13;
    if (x574) {
      char  *x575 = x15;
      x4 = 0/*false*/;
    } else {
      int x578 = x14;
      char  *x579 = x15;
      char  *x587 = x579;
      int x588 = 1/*true*/;
      /*@
      loop invariant ((strlen(x587)>=0) &&
      \valid(x587+(0..(strlen(x587)+1)-1)));
      loop assigns x587, x588;
      */
      for (;;) {
        int x590 = x588;
        if (!x590) break;
        char  *x592 = x587;
        char x593 = x592[0];
        int x594 = x593 == '\0';
        if (x594) {
          x588 = 0/*false*/;
        } else {
          int x599 = x593 == '\r';
          if (x599) {
            x588 = 0/*false*/;
          } else {
            char  *x596 = x592+1;
            x587 = x596;
          }
        }
      }
      char  *x628 = x587;
      int x580 = x578 == 1;
      if (x580) {
        int x629 = 1/*true*/;
        int x630 = 0;
        char  *x631 = 0/*null*/;
        int x632 = 1/*true*/;
        int x633 = 0;
        char  *x634 = 0/*null*/;
        int x635 = 1/*true*/;
        int x636 = 0;
        char  *x637 = 0/*null*/;
        int x638 = 1/*true*/;
        char x639 = '\0';
        char  *x640 = 0/*null*/;
        char x581 = x579[0];
        int x582 = x581 == '\0';
        if (x582) {
          x640 = x579;
        } else {
          int x583 = x581 >= '0';
          int x585;
          if (x583) {
            int x584 = x581 <= '9';
            x585 = x584;
          } else {
            x585 = 0/*false*/;
          }
          if (x585) {
            x638 = 0/*false*/;
            x639 = x581;
            char  *x586 = x579+1;
            x640 = x586;
          } else {
            x640 = x579;
          }
        }
        int x652 = x638;
        if (x652) {
          char  *x653 = x640;
          x637 = x653;
        } else {
          char x656 = x639;
          char  *x658 = x640;
          x635 = 0/*false*/;
          char x657 = x656 - '0';
          x636 = x657;
          x637 = x658;
        }
        int x664 = x635;
        if (x664) {
          char  *x665 = x637;
          x634 = x665;
        } else {
          int x668 = x636;
          char  *x669 = x637;
          char  *x670 = x669;
          int x671 = 1/*true*/;
          int x672 = x668;
          /*@
          loop invariant (((strlen(x670)>=0) &&
          \valid(x670+(0..(strlen(x670)+1)-1))) &&
          ((x672==-1) || (0<=x672)));
          loop assigns x670, x671, x672;
          */
          for (;;) {
            int x673 = x671;
            if (!x673) break;
            char  *x675 = x670;
            int x682 = 1/*true*/;
            char x683 = '\0';
            char  *x684 = 0/*null*/;
            char x676 = x675[0];
            int x677 = x676 == '\0';
            if (x677) {
              x684 = x675;
            } else {
              int x678 = x676 >= '0';
              int x680;
              if (x678) {
                int x679 = x676 <= '9';
                x680 = x679;
              } else {
                x680 = 0/*false*/;
              }
              if (x680) {
                x682 = 0/*false*/;
                x683 = x676;
                char  *x681 = x675+1;
                x684 = x681;
              } else {
                x684 = x675;
              }
            }
            int x696 = x682;
            if (x696) {
              char  *x697 = x684;
              x671 = 0/*false*/;
            } else {
              char x700 = x683;
              char  *x702 = x684;
              int x703 = x672;
              int x704 = x703 < 0;
              int x712;
              if (x704) {
                x712 = x703;
              } else {
                int x708 = x703 > x707;
                int x711;
                if (x708) {
                  x711 = -1;
                } else {
                  char x701 = x700 - '0';
                  int x709 = x703 * 10;
                  int x710 = x709 + x701;
                  x711 = x710;
                }
                x712 = x711;
              }
              x672 = x712;
              x670 = x702;
            }
          }
          int x740 = x672;
          char  *x741 = x670;
          x632 = 0/*false*/;
          x633 = x740;
          x634 = x741;
        }
        int x747 = x632;
        if (x747) {
          char  *x748 = x634;
          x631 = x748;
        } else {
          int x751 = x633;
          char  *x752 = x634;
          char  *x753 = x752;
          int x754 = 1/*true*/;
          /*@
          loop invariant ((strlen(x753)>=0) &&
          \valid(x753+(0..(strlen(x753)+1)-1)));
          loop assigns x753, x754;
          */
          for (;;) {
            int x756 = x754;
            if (!x756) break;
            char  *x758 = x753;
            char x759 = x758[0];
            int x760 = x759 == '\0';
            if (x760) {
              x754 = 0/*false*/;
            } else {
              int x761 = x759 == ' ';
              if (x761) {
                char  *x762 = x758+1;
                x753 = x762;
              } else {
                x754 = 0/*false*/;
              }
            }
          }
          char  *x793 = x753;
          x629 = 0/*false*/;
          x630 = x751;
          x631 = x793;
        }
        int x799 = x629;
        if (x799) {
          char  *x800 = x631;
          x4 = 0/*false*/;
        } else {
          int x803 = x630;
          char  *x804 = x631;
          int x809 = 1/*true*/;
          char x810 = '\0';
          char  *x811 = 0/*null*/;
          char x805 = x804[0];
          int x806 = x805 == '\0';
          if (x806) {
            x811 = x804;
          } else {
            int x807 = x805 == '\r';
            if (x807) {
              x809 = 0/*false*/;
              x810 = x805;
              char  *x808 = x804+1;
              x811 = x808;
            } else {
              x811 = x804;
            }
          }
          int x823 = x809;
          if (x823) {
            char  *x824 = x811;
            x4 = 0/*false*/;
          } else {
            char x827 = x810;
            char  *x828 = x811;
            int x833 = 1/*true*/;
            char x834 = '\0';
            char  *x835 = 0/*null*/;
            char x829 = x828[0];
            int x830 = x829 == '\0';
            if (x830) {
              x835 = x828;
            } else {
              int x831 = x829 == '\n';
              if (x831) {
                x833 = 0/*false*/;
                x834 = x829;
                char  *x832 = x828+1;
                x835 = x832;
              } else {
                x835 = x828;
              }
            }
            int x847 = x833;
            if (x847) {
              char  *x848 = x835;
              x4 = 0/*false*/;
            } else {
              char x851 = x834;
              char  *x852 = x835;
              int x853 = x5;
              int x854 = x803 == -2;
              int x855;
              if (x854) {
                x855 = x853;
              } else {
                x855 = x803;
              }
              x5 = x855;
              x3 = x852;
            }
          }
        }
      } else {
        int x865 = 1/*true*/;
        char  *x867 = 0/*null*/;
        x865 = 0/*false*/;
        x867 = x628;
        int x871 = x865;
        if (x871) {
          char  *x872 = x867;
          x4 = 0/*false*/;
        } else {
          char  *x876 = x867;
          int x881 = 1/*true*/;
          char x882 = '\0';
          char  *x883 = 0/*null*/;
          char x877 = x876[0];
          int x878 = x877 == '\0';
          if (x878) {
            x883 = x876;
          } else {
            int x879 = x877 == '\r';
            if (x879) {
              x881 = 0/*false*/;
              x882 = x877;
              char  *x880 = x876+1;
              x883 = x880;
            } else {
              x883 = x876;
            }
          }
          int x895 = x881;
          if (x895) {
            char  *x896 = x883;
            x4 = 0/*false*/;
          } else {
            char x899 = x882;
            char  *x900 = x883;
            int x905 = 1/*true*/;
            char x906 = '\0';
            char  *x907 = 0/*null*/;
            char x901 = x900[0];
            int x902 = x901 == '\0';
            if (x902) {
              x907 = x900;
            } else {
              int x903 = x901 == '\n';
              if (x903) {
                x905 = 0/*false*/;
                x906 = x901;
                char  *x904 = x900+1;
                x907 = x904;
              } else {
                x907 = x900;
              }
            }
            int x919 = x905;
            if (x919) {
              char  *x920 = x907;
              x4 = 0/*false*/;
            } else {
              char x923 = x906;
              char  *x924 = x907;
              int x925 = x5;
              int x927;
              if (x926) {
                x927 = x925;
              } else {
                x927 = -2;
              }
              x5 = x927;
              x3 = x924;
            }
          }
        }
      }
    }
  }
  int x958 = x5;
  char  *x959 = x3;
  char x960 = x959[0];
  int x961 = x960 == '\0';
  if (x961) {
    x2 = x958;
  } else {
  }
  int x965 = x2;
  return x965;
}
