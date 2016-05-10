#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..(strlen(x0)+1)-1)));
assigns \nothing;
*/
int p(char  * x0) {
  int x2 = -1;
  char  *x3 = x0;
  int x4 = 1/*true*/;
  int x5 = 0;
  int x728 = INT_MAX;
  int x729 = x728 / 10;
  int x730 = x729 - 10;
  int x899 = -2 == -2;
  /*@
  loop invariant ((strlen(x3)>=0) && \valid(x3+(0..(strlen(x3)+1)-1)));
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
      loop invariant ((strlen(x378)>=0) && \valid(x378+(0..(strlen(x378)+1)-1)));
      loop assigns x378, x379;
      */
      for (;;) {
        int x381 = x379;
        if (!x381) break;
        char  *x383 = x378;
        int x394 = 1/*true*/;
        char x395 = '\0';
        char  *x396 = 0/*null*/;
        char x384 = x383[0];
        int x385 = x384 == '\0';
        if (x385) {
        } else {
          int x386 = x384 >= 'a';
          int x388;
          if (x386) {
            int x387 = x384 <= 'z';
            x388 = x387;
          } else {
            x388 = 0/*false*/;
          }
          int x389 = x384 >= 'A';
          int x391;
          if (x389) {
            int x390 = x384 <= 'Z';
            x391 = x390;
          } else {
            x391 = 0/*false*/;
          }
          int x392 = x388 || x391;
          if (x392) {
            x394 = 0/*false*/;
            x395 = x384;
            char  *x393 = x383+1;
            x396 = x393;
          } else {
          }
        }
        int x404 = x394;
        char x406 = x395;
        char  *x407 = x396;
        if (x404) {
          if (x385) {
            x379 = 0/*false*/;
          } else {
            int x405 = x384 == '-';
            if (x405) {
              char  *x393 = x383+1;
              x378 = x393;
            } else {
              x379 = 0/*false*/;
            }
          }
        } else {
          x378 = x407;
        }
      }
      char  *x444 = x378;
      x22 = 0/*false*/;
      x23 = 0;
      x24 = x444;
    } else {
      int x449 = x26;
      char  *x450 = x27;
      x22 = 0/*false*/;
      x23 = x449;
      x24 = x450;
    }
    int x456 = x22;
    if (x456) {
      char  *x457 = x24;
      x21 = x457;
    } else {
      int x460 = x23;
      char  *x461 = x24;
      char  *x462 = x461;
      int x463 = 1/*true*/;
      /*@
      loop invariant ((strlen(x462)>=0) && \valid(x462+(0..(strlen(x462)+1)-1)));
      loop assigns x462, x463;
      */
      for (;;) {
        int x465 = x463;
        if (!x465) break;
        char  *x467 = x462;
        char x468 = x467[0];
        int x469 = x468 == '\0';
        if (x469) {
          x463 = 0/*false*/;
        } else {
          int x470 = x468 == ' ';
          if (x470) {
            char  *x471 = x467+1;
            x462 = x471;
          } else {
            x463 = 0/*false*/;
          }
        }
      }
      char  *x502 = x462;
      x19 = 0/*false*/;
      x20 = x460;
      x21 = x502;
    }
    int x508 = x19;
    if (x508) {
      char  *x509 = x21;
      x18 = x509;
    } else {
      int x512 = x20;
      char  *x513 = x21;
      int x518 = 1/*true*/;
      char x519 = '\0';
      char  *x520 = 0/*null*/;
      char x514 = x513[0];
      int x515 = x514 == '\0';
      if (x515) {
        x520 = x513;
      } else {
        int x516 = x514 == ':';
        if (x516) {
          x518 = 0/*false*/;
          x519 = x514;
          char  *x517 = x513+1;
          x520 = x517;
        } else {
          x520 = x513;
        }
      }
      int x532 = x518;
      if (x532) {
        char  *x533 = x520;
        x18 = x533;
      } else {
        char x536 = x519;
        char  *x537 = x520;
        x16 = 0/*false*/;
        x17 = x512;
        x18 = x537;
      }
    }
    int x545 = x16;
    if (x545) {
      char  *x546 = x18;
      x15 = x546;
    } else {
      int x549 = x17;
      char  *x550 = x18;
      char  *x551 = x550;
      int x552 = 1/*true*/;
      /*@
      loop invariant ((strlen(x551)>=0) && \valid(x551+(0..(strlen(x551)+1)-1)));
      loop assigns x551, x552;
      */
      for (;;) {
        int x554 = x552;
        if (!x554) break;
        char  *x556 = x551;
        char x557 = x556[0];
        int x558 = x557 == '\0';
        if (x558) {
          x552 = 0/*false*/;
        } else {
          int x559 = x557 == ' ';
          if (x559) {
            char  *x560 = x556+1;
            x551 = x560;
          } else {
            x552 = 0/*false*/;
          }
        }
      }
      char  *x591 = x551;
      x13 = 0/*false*/;
      x14 = x549;
      x15 = x591;
    }
    int x597 = x13;
    if (x597) {
      char  *x598 = x15;
      x4 = 0/*false*/;
    } else {
      int x601 = x14;
      char  *x602 = x15;
      char  *x610 = x602;
      int x611 = 1/*true*/;
      /*@
      loop invariant ((strlen(x610)>=0) && \valid(x610+(0..(strlen(x610)+1)-1)));
      loop assigns x610, x611;
      */
      for (;;) {
        int x613 = x611;
        if (!x613) break;
        char  *x615 = x610;
        char x616 = x615[0];
        int x617 = x616 == '\0';
        if (x617) {
          x611 = 0/*false*/;
        } else {
          int x622 = x616 == '\n';
          if (x622) {
            x611 = 0/*false*/;
          } else {
            char  *x619 = x615+1;
            x610 = x619;
          }
        }
      }
      char  *x651 = x610;
      int x603 = x601 == 1;
      if (x603) {
        int x652 = 1/*true*/;
        int x653 = 0;
        char  *x654 = 0/*null*/;
        int x655 = 1/*true*/;
        int x656 = 0;
        char  *x657 = 0/*null*/;
        int x658 = 1/*true*/;
        int x659 = 0;
        char  *x660 = 0/*null*/;
        int x661 = 1/*true*/;
        char x662 = '\0';
        char  *x663 = 0/*null*/;
        char x604 = x602[0];
        int x605 = x604 == '\0';
        if (x605) {
          x663 = x602;
        } else {
          int x606 = x604 >= '0';
          int x608;
          if (x606) {
            int x607 = x604 <= '9';
            x608 = x607;
          } else {
            x608 = 0/*false*/;
          }
          if (x608) {
            x661 = 0/*false*/;
            x662 = x604;
            char  *x609 = x602+1;
            x663 = x609;
          } else {
            x663 = x602;
          }
        }
        int x675 = x661;
        if (x675) {
          char  *x676 = x663;
          x660 = x676;
        } else {
          char x679 = x662;
          char  *x681 = x663;
          x658 = 0/*false*/;
          char x680 = x679 - '0';
          x659 = x680;
          x660 = x681;
        }
        int x687 = x658;
        if (x687) {
          char  *x688 = x660;
          x657 = x688;
        } else {
          int x691 = x659;
          char  *x692 = x660;
          char  *x693 = x692;
          int x694 = 1/*true*/;
          int x695 = x691;
          /*@
          loop invariant (((strlen(x693)>=0) && \valid(x693+(0..(strlen(x693)+1)-1))) && ((x695==-1) || (0<=x695)));
          loop assigns x693, x694, x695;
          */
          for (;;) {
            int x696 = x694;
            if (!x696) break;
            char  *x698 = x693;
            int x705 = 1/*true*/;
            char x706 = '\0';
            char  *x707 = 0/*null*/;
            char x699 = x698[0];
            int x700 = x699 == '\0';
            if (x700) {
              x707 = x698;
            } else {
              int x701 = x699 >= '0';
              int x703;
              if (x701) {
                int x702 = x699 <= '9';
                x703 = x702;
              } else {
                x703 = 0/*false*/;
              }
              if (x703) {
                x705 = 0/*false*/;
                x706 = x699;
                char  *x704 = x698+1;
                x707 = x704;
              } else {
                x707 = x698;
              }
            }
            int x719 = x705;
            if (x719) {
              char  *x720 = x707;
              x694 = 0/*false*/;
            } else {
              char x723 = x706;
              char  *x725 = x707;
              int x726 = x695;
              int x727 = x726 < 0;
              int x735;
              if (x727) {
                x735 = x726;
              } else {
                int x731 = x726 > x730;
                int x734;
                if (x731) {
                  x734 = -1;
                } else {
                  char x724 = x723 - '0';
                  int x732 = x726 * 10;
                  int x733 = x732 + x724;
                  x734 = x733;
                }
                x735 = x734;
              }
              x695 = x735;
              x693 = x725;
            }
          }
          int x763 = x695;
          char  *x764 = x693;
          x655 = 0/*false*/;
          x656 = x763;
          x657 = x764;
        }
        int x770 = x655;
        if (x770) {
          char  *x771 = x657;
          x654 = x771;
        } else {
          int x774 = x656;
          char  *x775 = x657;
          char  *x776 = x775;
          int x777 = 1/*true*/;
          /*@
          loop invariant ((strlen(x776)>=0) && \valid(x776+(0..(strlen(x776)+1)-1)));
          loop assigns x776, x777;
          */
          for (;;) {
            int x779 = x777;
            if (!x779) break;
            char  *x781 = x776;
            char x782 = x781[0];
            int x783 = x782 == '\0';
            if (x783) {
              x777 = 0/*false*/;
            } else {
              int x784 = x782 == ' ';
              if (x784) {
                char  *x785 = x781+1;
                x776 = x785;
              } else {
                x777 = 0/*false*/;
              }
            }
          }
          char  *x816 = x776;
          x652 = 0/*false*/;
          x653 = x774;
          x654 = x816;
        }
        int x822 = x652;
        if (x822) {
          char  *x823 = x654;
          x4 = 0/*false*/;
        } else {
          int x826 = x653;
          char  *x827 = x654;
          int x832 = 1/*true*/;
          char x833 = '\0';
          char  *x834 = 0/*null*/;
          char x828 = x827[0];
          int x829 = x828 == '\0';
          if (x829) {
            x834 = x827;
          } else {
            int x830 = x828 == '\n';
            if (x830) {
              x832 = 0/*false*/;
              x833 = x828;
              char  *x831 = x827+1;
              x834 = x831;
            } else {
              x834 = x827;
            }
          }
          int x846 = x832;
          if (x846) {
            char  *x847 = x834;
            x4 = 0/*false*/;
          } else {
            char x850 = x833;
            char  *x851 = x834;
            int x852 = x5;
            int x853 = x826 == -2;
            int x854;
            if (x853) {
              x854 = x852;
            } else {
              x854 = x826;
            }
            x5 = x854;
            x3 = x851;
          }
        }
      } else {
        int x862 = 1/*true*/;
        char  *x864 = 0/*null*/;
        x862 = 0/*false*/;
        x864 = x651;
        int x868 = x862;
        if (x868) {
          char  *x869 = x864;
          x4 = 0/*false*/;
        } else {
          char  *x873 = x864;
          int x878 = 1/*true*/;
          char x879 = '\0';
          char  *x880 = 0/*null*/;
          char x874 = x873[0];
          int x875 = x874 == '\0';
          if (x875) {
            x880 = x873;
          } else {
            int x876 = x874 == '\n';
            if (x876) {
              x878 = 0/*false*/;
              x879 = x874;
              char  *x877 = x873+1;
              x880 = x877;
            } else {
              x880 = x873;
            }
          }
          int x892 = x878;
          if (x892) {
            char  *x893 = x880;
            x4 = 0/*false*/;
          } else {
            char x896 = x879;
            char  *x897 = x880;
            int x898 = x5;
            int x900;
            if (x899) {
              x900 = x898;
            } else {
              x900 = -2;
            }
            x5 = x900;
            x3 = x897;
          }
        }
      }
    }
  }
  int x929 = x5;
  char  *x930 = x3;
  char x931 = x930[0];
  int x932 = x931 == '\0';
  if (x932) {
    x2 = x929;
  } else {
  }
  int x936 = x2;
  return x936;
}
