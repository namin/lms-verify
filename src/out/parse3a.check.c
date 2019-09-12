#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0))));
assigns \nothing;
*/
int p(char  * x0) {
  int x2 = -1;
  char  *x3 = x0;
  int x4 = 1/*true*/;
  int x5 = 0;
  int x697 = INT_MAX;
  int x698 = x697 / 10;
  int x699 = x698 - 10;
  int x914 = -2 == -2;
  /*@
  loop invariant ((strlen(x3)>=0) &&
  \valid(x3+(0..strlen(x3))));
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
      \valid(x378+(0..strlen(x378))));
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
      char  *x419 = x378;
      x22 = 0/*false*/;
      x23 = 0;
      x24 = x419;
    } else {
      int x424 = x26;
      char  *x425 = x27;
      x22 = 0/*false*/;
      x23 = x424;
      x24 = x425;
    }
    int x431 = x22;
    if (x431) {
      char  *x432 = x24;
      x21 = x432;
    } else {
      int x435 = x23;
      char  *x436 = x24;
      char  *x437 = x436;
      int x438 = 1/*true*/;
      /*@
      loop invariant ((strlen(x437)>=0) &&
      \valid(x437+(0..strlen(x437))));
      loop assigns x437, x438;
      */
      for (;;) {
        int x440 = x438;
        if (!x440) break;
        char  *x442 = x437;
        char x443 = x442[0];
        int x444 = x443 == '\0';
        if (x444) {
          x438 = 0/*false*/;
        } else {
          int x445 = x443 == ' ';
          if (x445) {
            char  *x446 = x442+1;
            x437 = x446;
          } else {
            x438 = 0/*false*/;
          }
        }
      }
      char  *x475 = x437;
      x19 = 0/*false*/;
      x20 = x435;
      x21 = x475;
    }
    int x481 = x19;
    if (x481) {
      char  *x482 = x21;
      x18 = x482;
    } else {
      int x485 = x20;
      char  *x486 = x21;
      int x491 = 1/*true*/;
      char x492 = '\0';
      char  *x493 = 0/*null*/;
      char x487 = x486[0];
      int x488 = x487 == '\0';
      if (x488) {
        x493 = x486;
      } else {
        int x489 = x487 == ':';
        if (x489) {
          x491 = 0/*false*/;
          x492 = x487;
          char  *x490 = x486+1;
          x493 = x490;
        } else {
          x493 = x486;
        }
      }
      int x505 = x491;
      if (x505) {
        char  *x506 = x493;
        x18 = x506;
      } else {
        char x509 = x492;
        char  *x510 = x493;
        x16 = 0/*false*/;
        x17 = x485;
        x18 = x510;
      }
    }
    int x518 = x16;
    if (x518) {
      char  *x519 = x18;
      x15 = x519;
    } else {
      int x522 = x17;
      char  *x523 = x18;
      char  *x524 = x523;
      int x525 = 1/*true*/;
      /*@
      loop invariant ((strlen(x524)>=0) &&
      \valid(x524+(0..strlen(x524))));
      loop assigns x524, x525;
      */
      for (;;) {
        int x527 = x525;
        if (!x527) break;
        char  *x529 = x524;
        char x530 = x529[0];
        int x531 = x530 == '\0';
        if (x531) {
          x525 = 0/*false*/;
        } else {
          int x532 = x530 == ' ';
          if (x532) {
            char  *x533 = x529+1;
            x524 = x533;
          } else {
            x525 = 0/*false*/;
          }
        }
      }
      char  *x562 = x524;
      x13 = 0/*false*/;
      x14 = x522;
      x15 = x562;
    }
    int x568 = x13;
    if (x568) {
      char  *x569 = x15;
      x4 = 0/*false*/;
    } else {
      int x572 = x14;
      char  *x573 = x15;
      char  *x581 = x573;
      int x582 = 1/*true*/;
      /*@
      loop invariant ((strlen(x581)>=0) &&
      \valid(x581+(0..strlen(x581))));
      loop assigns x581, x582;
      */
      for (;;) {
        int x584 = x582;
        if (!x584) break;
        char  *x586 = x581;
        char x587 = x586[0];
        int x588 = x587 == '\0';
        if (x588) {
          x582 = 0/*false*/;
        } else {
          int x593 = x587 == '\r';
          if (x593) {
            x582 = 0/*false*/;
          } else {
            char  *x590 = x586+1;
            x581 = x590;
          }
        }
      }
      char  *x620 = x581;
      int x574 = x572 == 1;
      if (x574) {
        int x621 = 1/*true*/;
        int x622 = 0;
        char  *x623 = 0/*null*/;
        int x624 = 1/*true*/;
        int x625 = 0;
        char  *x626 = 0/*null*/;
        int x627 = 1/*true*/;
        int x628 = 0;
        char  *x629 = 0/*null*/;
        int x630 = 1/*true*/;
        char x631 = '\0';
        char  *x632 = 0/*null*/;
        char x575 = x573[0];
        int x576 = x575 == '\0';
        if (x576) {
          x632 = x573;
        } else {
          int x577 = x575 >= '0';
          int x579;
          if (x577) {
            int x578 = x575 <= '9';
            x579 = x578;
          } else {
            x579 = 0/*false*/;
          }
          if (x579) {
            x630 = 0/*false*/;
            x631 = x575;
            char  *x580 = x573+1;
            x632 = x580;
          } else {
            x632 = x573;
          }
        }
        int x644 = x630;
        if (x644) {
          char  *x645 = x632;
          x629 = x645;
        } else {
          char x648 = x631;
          char  *x650 = x632;
          x627 = 0/*false*/;
          char x649 = x648 - '0';
          x628 = x649;
          x629 = x650;
        }
        int x656 = x627;
        if (x656) {
          char  *x657 = x629;
          x626 = x657;
        } else {
          int x660 = x628;
          char  *x661 = x629;
          char  *x662 = x661;
          int x663 = 1/*true*/;
          int x664 = x660;
          /*@
          loop invariant (((strlen(x662)>=0) &&
          \valid(x662+(0..strlen(x662)))) &&
          ((x664==-1) || (0<=x664)));
          loop assigns x662, x663, x664;
          */
          for (;;) {
            int x665 = x663;
            if (!x665) break;
            char  *x667 = x662;
            int x674 = 1/*true*/;
            char x675 = '\0';
            char  *x676 = 0/*null*/;
            char x668 = x667[0];
            int x669 = x668 == '\0';
            if (x669) {
              x676 = x667;
            } else {
              int x670 = x668 >= '0';
              int x672;
              if (x670) {
                int x671 = x668 <= '9';
                x672 = x671;
              } else {
                x672 = 0/*false*/;
              }
              if (x672) {
                x674 = 0/*false*/;
                x675 = x668;
                char  *x673 = x667+1;
                x676 = x673;
              } else {
                x676 = x667;
              }
            }
            int x688 = x674;
            if (x688) {
              char  *x689 = x676;
              x663 = 0/*false*/;
            } else {
              char x692 = x675;
              char  *x694 = x676;
              int x695 = x664;
              int x696 = x695 < 0;
              int x704;
              if (x696) {
                x704 = x695;
              } else {
                int x700 = x695 > x699;
                int x703;
                if (x700) {
                  x703 = -1;
                } else {
                  char x693 = x692 - '0';
                  int x701 = x695 * 10;
                  int x702 = x701 + x693;
                  x703 = x702;
                }
                x704 = x703;
              }
              x664 = x704;
              x662 = x694;
            }
          }
          int x730 = x664;
          char  *x731 = x662;
          x624 = 0/*false*/;
          x625 = x730;
          x626 = x731;
        }
        int x737 = x624;
        if (x737) {
          char  *x738 = x626;
          x623 = x738;
        } else {
          int x741 = x625;
          char  *x742 = x626;
          char  *x743 = x742;
          int x744 = 1/*true*/;
          /*@
          loop invariant ((strlen(x743)>=0) &&
          \valid(x743+(0..strlen(x743))));
          loop assigns x743, x744;
          */
          for (;;) {
            int x746 = x744;
            if (!x746) break;
            char  *x748 = x743;
            char x749 = x748[0];
            int x750 = x749 == '\0';
            if (x750) {
              x744 = 0/*false*/;
            } else {
              int x751 = x749 == ' ';
              if (x751) {
                char  *x752 = x748+1;
                x743 = x752;
              } else {
                x744 = 0/*false*/;
              }
            }
          }
          char  *x781 = x743;
          x621 = 0/*false*/;
          x622 = x741;
          x623 = x781;
        }
        int x787 = x621;
        if (x787) {
          char  *x788 = x623;
          x4 = 0/*false*/;
        } else {
          int x791 = x622;
          char  *x792 = x623;
          int x797 = 1/*true*/;
          char x798 = '\0';
          char  *x799 = 0/*null*/;
          char x793 = x792[0];
          int x794 = x793 == '\0';
          if (x794) {
            x799 = x792;
          } else {
            int x795 = x793 == '\r';
            if (x795) {
              x797 = 0/*false*/;
              x798 = x793;
              char  *x796 = x792+1;
              x799 = x796;
            } else {
              x799 = x792;
            }
          }
          int x811 = x797;
          if (x811) {
            char  *x812 = x799;
            x4 = 0/*false*/;
          } else {
            char x815 = x798;
            char  *x816 = x799;
            int x821 = 1/*true*/;
            char x822 = '\0';
            char  *x823 = 0/*null*/;
            char x817 = x816[0];
            int x818 = x817 == '\0';
            if (x818) {
              x823 = x816;
            } else {
              int x819 = x817 == '\n';
              if (x819) {
                x821 = 0/*false*/;
                x822 = x817;
                char  *x820 = x816+1;
                x823 = x820;
              } else {
                x823 = x816;
              }
            }
            int x835 = x821;
            if (x835) {
              char  *x836 = x823;
              x4 = 0/*false*/;
            } else {
              char x839 = x822;
              char  *x840 = x823;
              int x841 = x5;
              int x842 = x791 == -2;
              int x843;
              if (x842) {
                x843 = x841;
              } else {
                x843 = x791;
              }
              x5 = x843;
              x3 = x840;
            }
          }
        }
      } else {
        int x853 = 1/*true*/;
        char  *x855 = 0/*null*/;
        x853 = 0/*false*/;
        x855 = x620;
        int x859 = x853;
        if (x859) {
          char  *x860 = x855;
          x4 = 0/*false*/;
        } else {
          char  *x864 = x855;
          int x869 = 1/*true*/;
          char x870 = '\0';
          char  *x871 = 0/*null*/;
          char x865 = x864[0];
          int x866 = x865 == '\0';
          if (x866) {
            x871 = x864;
          } else {
            int x867 = x865 == '\r';
            if (x867) {
              x869 = 0/*false*/;
              x870 = x865;
              char  *x868 = x864+1;
              x871 = x868;
            } else {
              x871 = x864;
            }
          }
          int x883 = x869;
          if (x883) {
            char  *x884 = x871;
            x4 = 0/*false*/;
          } else {
            char x887 = x870;
            char  *x888 = x871;
            int x893 = 1/*true*/;
            char x894 = '\0';
            char  *x895 = 0/*null*/;
            char x889 = x888[0];
            int x890 = x889 == '\0';
            if (x890) {
              x895 = x888;
            } else {
              int x891 = x889 == '\n';
              if (x891) {
                x893 = 0/*false*/;
                x894 = x889;
                char  *x892 = x888+1;
                x895 = x892;
              } else {
                x895 = x888;
              }
            }
            int x907 = x893;
            if (x907) {
              char  *x908 = x895;
              x4 = 0/*false*/;
            } else {
              char x911 = x894;
              char  *x912 = x895;
              int x913 = x5;
              int x915;
              if (x914) {
                x915 = x913;
              } else {
                x915 = -2;
              }
              x5 = x915;
              x3 = x912;
            }
          }
        }
      }
    }
  }
  int x944 = x5;
  char  *x945 = x3;
  char x946 = x945[0];
  int x947 = x946 == '\0';
  if (x947) {
    x2 = x944;
  } else {
  }
  int x951 = x2;
  return x951;
}
