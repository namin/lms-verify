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
  int x727 = INT_MAX;
  int x728 = x727 / 10;
  int x729 = x728 - 10;
  int x898 = -2 == -2;
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
          int x618 = x616 != '\n';
          if (x618) {
            char  *x619 = x615+1;
            x610 = x619;
          } else {
            x611 = 0/*false*/;
          }
        }
      }
      char  *x650 = x610;
      int x603 = x601 == 1;
      if (x603) {
        int x651 = 1/*true*/;
        int x652 = 0;
        char  *x653 = 0/*null*/;
        int x654 = 1/*true*/;
        int x655 = 0;
        char  *x656 = 0/*null*/;
        int x657 = 1/*true*/;
        int x658 = 0;
        char  *x659 = 0/*null*/;
        int x660 = 1/*true*/;
        char x661 = '\0';
        char  *x662 = 0/*null*/;
        char x604 = x602[0];
        int x605 = x604 == '\0';
        if (x605) {
          x662 = x602;
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
            x660 = 0/*false*/;
            x661 = x604;
            char  *x609 = x602+1;
            x662 = x609;
          } else {
            x662 = x602;
          }
        }
        int x674 = x660;
        if (x674) {
          char  *x675 = x662;
          x659 = x675;
        } else {
          char x678 = x661;
          char  *x680 = x662;
          x657 = 0/*false*/;
          char x679 = x678 - '0';
          x658 = x679;
          x659 = x680;
        }
        int x686 = x657;
        if (x686) {
          char  *x687 = x659;
          x656 = x687;
        } else {
          int x690 = x658;
          char  *x691 = x659;
          char  *x692 = x691;
          int x693 = 1/*true*/;
          int x694 = x690;
          /*@
          loop invariant (((strlen(x692)>=0) && \valid(x692+(0..(strlen(x692)+1)-1))) && ((x694==-1) || (0<=x694)));
          loop assigns x692, x693, x694;
          */
          for (;;) {
            int x695 = x693;
            if (!x695) break;
            char  *x697 = x692;
            int x704 = 1/*true*/;
            char x705 = '\0';
            char  *x706 = 0/*null*/;
            char x698 = x697[0];
            int x699 = x698 == '\0';
            if (x699) {
              x706 = x697;
            } else {
              int x700 = x698 >= '0';
              int x702;
              if (x700) {
                int x701 = x698 <= '9';
                x702 = x701;
              } else {
                x702 = 0/*false*/;
              }
              if (x702) {
                x704 = 0/*false*/;
                x705 = x698;
                char  *x703 = x697+1;
                x706 = x703;
              } else {
                x706 = x697;
              }
            }
            int x718 = x704;
            if (x718) {
              char  *x719 = x706;
              x693 = 0/*false*/;
            } else {
              char x722 = x705;
              char  *x724 = x706;
              int x725 = x694;
              int x726 = x725 < 0;
              int x734;
              if (x726) {
                x734 = x725;
              } else {
                int x730 = x725 > x729;
                int x733;
                if (x730) {
                  x733 = -1;
                } else {
                  char x723 = x722 - '0';
                  int x731 = x725 * 10;
                  int x732 = x731 + x723;
                  x733 = x732;
                }
                x734 = x733;
              }
              x694 = x734;
              x692 = x724;
            }
          }
          int x762 = x694;
          char  *x763 = x692;
          x654 = 0/*false*/;
          x655 = x762;
          x656 = x763;
        }
        int x769 = x654;
        if (x769) {
          char  *x770 = x656;
          x653 = x770;
        } else {
          int x773 = x655;
          char  *x774 = x656;
          char  *x775 = x774;
          int x776 = 1/*true*/;
          /*@
          loop invariant ((strlen(x775)>=0) && \valid(x775+(0..(strlen(x775)+1)-1)));
          loop assigns x775, x776;
          */
          for (;;) {
            int x778 = x776;
            if (!x778) break;
            char  *x780 = x775;
            char x781 = x780[0];
            int x782 = x781 == '\0';
            if (x782) {
              x776 = 0/*false*/;
            } else {
              int x783 = x781 == ' ';
              if (x783) {
                char  *x784 = x780+1;
                x775 = x784;
              } else {
                x776 = 0/*false*/;
              }
            }
          }
          char  *x815 = x775;
          x651 = 0/*false*/;
          x652 = x773;
          x653 = x815;
        }
        int x821 = x651;
        if (x821) {
          char  *x822 = x653;
          x4 = 0/*false*/;
        } else {
          int x825 = x652;
          char  *x826 = x653;
          int x831 = 1/*true*/;
          char x832 = '\0';
          char  *x833 = 0/*null*/;
          char x827 = x826[0];
          int x828 = x827 == '\0';
          if (x828) {
            x833 = x826;
          } else {
            int x829 = x827 == '\n';
            if (x829) {
              x831 = 0/*false*/;
              x832 = x827;
              char  *x830 = x826+1;
              x833 = x830;
            } else {
              x833 = x826;
            }
          }
          int x845 = x831;
          if (x845) {
            char  *x846 = x833;
            x4 = 0/*false*/;
          } else {
            char x849 = x832;
            char  *x850 = x833;
            int x851 = x5;
            int x852 = x825 == -2;
            int x853;
            if (x852) {
              x853 = x851;
            } else {
              x853 = x825;
            }
            x5 = x853;
            x3 = x850;
          }
        }
      } else {
        int x861 = 1/*true*/;
        char  *x863 = 0/*null*/;
        x861 = 0/*false*/;
        x863 = x650;
        int x867 = x861;
        if (x867) {
          char  *x868 = x863;
          x4 = 0/*false*/;
        } else {
          char  *x872 = x863;
          int x877 = 1/*true*/;
          char x878 = '\0';
          char  *x879 = 0/*null*/;
          char x873 = x872[0];
          int x874 = x873 == '\0';
          if (x874) {
            x879 = x872;
          } else {
            int x875 = x873 == '\n';
            if (x875) {
              x877 = 0/*false*/;
              x878 = x873;
              char  *x876 = x872+1;
              x879 = x876;
            } else {
              x879 = x872;
            }
          }
          int x891 = x877;
          if (x891) {
            char  *x892 = x879;
            x4 = 0/*false*/;
          } else {
            char x895 = x878;
            char  *x896 = x879;
            int x897 = x5;
            int x899;
            if (x898) {
              x899 = x897;
            } else {
              x899 = -2;
            }
            x5 = x899;
            x3 = x896;
          }
        }
      }
    }
  }
  int x928 = x5;
  char  *x929 = x3;
  char x930 = x929[0];
  int x931 = x930 == '\0';
  if (x931) {
    x2 = x928;
  } else {
  }
  int x935 = x2;
  return x935;
}
