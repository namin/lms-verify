#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..strlen(x0))));
assigns \nothing;
*/
int p(char  * x0) {
  int x2 = -1;
  char  *x3 = x0;
  int x4 = 1/*true*/;
  int x5 = 0;
  int x719 = INT_MAX;
  int x720 = x719 / 10;
  int x721 = x720 - 10;
  int x886 = -2 == -2;
  /*@
  loop invariant ((strlen(x3)>=0) && \valid(x3+(0..strlen(x3))));
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
      loop invariant ((strlen(x378)>=0) && \valid(x378+(0..strlen(x378))));
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
      char  *x442 = x378;
      x22 = 0/*false*/;
      x23 = 0;
      x24 = x442;
    } else {
      int x447 = x26;
      char  *x448 = x27;
      x22 = 0/*false*/;
      x23 = x447;
      x24 = x448;
    }
    int x454 = x22;
    if (x454) {
      char  *x455 = x24;
      x21 = x455;
    } else {
      int x458 = x23;
      char  *x459 = x24;
      char  *x460 = x459;
      int x461 = 1/*true*/;
      /*@
      loop invariant ((strlen(x460)>=0) && \valid(x460+(0..strlen(x460))));
      loop assigns x460, x461;
      */
      for (;;) {
        int x463 = x461;
        if (!x463) break;
        char  *x465 = x460;
        char x466 = x465[0];
        int x467 = x466 == '\0';
        if (x467) {
          x461 = 0/*false*/;
        } else {
          int x468 = x466 == ' ';
          if (x468) {
            char  *x469 = x465+1;
            x460 = x469;
          } else {
            x461 = 0/*false*/;
          }
        }
      }
      char  *x498 = x460;
      x19 = 0/*false*/;
      x20 = x458;
      x21 = x498;
    }
    int x504 = x19;
    if (x504) {
      char  *x505 = x21;
      x18 = x505;
    } else {
      int x508 = x20;
      char  *x509 = x21;
      int x514 = 1/*true*/;
      char x515 = '\0';
      char  *x516 = 0/*null*/;
      char x510 = x509[0];
      int x511 = x510 == '\0';
      if (x511) {
        x516 = x509;
      } else {
        int x512 = x510 == ':';
        if (x512) {
          x514 = 0/*false*/;
          x515 = x510;
          char  *x513 = x509+1;
          x516 = x513;
        } else {
          x516 = x509;
        }
      }
      int x528 = x514;
      if (x528) {
        char  *x529 = x516;
        x18 = x529;
      } else {
        char x532 = x515;
        char  *x533 = x516;
        x16 = 0/*false*/;
        x17 = x508;
        x18 = x533;
      }
    }
    int x541 = x16;
    if (x541) {
      char  *x542 = x18;
      x15 = x542;
    } else {
      int x545 = x17;
      char  *x546 = x18;
      char  *x547 = x546;
      int x548 = 1/*true*/;
      /*@
      loop invariant ((strlen(x547)>=0) && \valid(x547+(0..strlen(x547))));
      loop assigns x547, x548;
      */
      for (;;) {
        int x550 = x548;
        if (!x550) break;
        char  *x552 = x547;
        char x553 = x552[0];
        int x554 = x553 == '\0';
        if (x554) {
          x548 = 0/*false*/;
        } else {
          int x555 = x553 == ' ';
          if (x555) {
            char  *x556 = x552+1;
            x547 = x556;
          } else {
            x548 = 0/*false*/;
          }
        }
      }
      char  *x585 = x547;
      x13 = 0/*false*/;
      x14 = x545;
      x15 = x585;
    }
    int x591 = x13;
    if (x591) {
      char  *x592 = x15;
      x4 = 0/*false*/;
    } else {
      int x595 = x14;
      char  *x596 = x15;
      char  *x604 = x596;
      int x605 = 1/*true*/;
      /*@
      loop invariant ((strlen(x604)>=0) && \valid(x604+(0..strlen(x604))));
      loop assigns x604, x605;
      */
      for (;;) {
        int x607 = x605;
        if (!x607) break;
        char  *x609 = x604;
        char x610 = x609[0];
        int x611 = x610 == '\0';
        if (x611) {
          x605 = 0/*false*/;
        } else {
          int x612 = x610 != '\n';
          if (x612) {
            char  *x613 = x609+1;
            x604 = x613;
          } else {
            x605 = 0/*false*/;
          }
        }
      }
      char  *x642 = x604;
      int x597 = x595 == 1;
      if (x597) {
        int x643 = 1/*true*/;
        int x644 = 0;
        char  *x645 = 0/*null*/;
        int x646 = 1/*true*/;
        int x647 = 0;
        char  *x648 = 0/*null*/;
        int x649 = 1/*true*/;
        int x650 = 0;
        char  *x651 = 0/*null*/;
        int x652 = 1/*true*/;
        char x653 = '\0';
        char  *x654 = 0/*null*/;
        char x598 = x596[0];
        int x599 = x598 == '\0';
        if (x599) {
          x654 = x596;
        } else {
          int x600 = x598 >= '0';
          int x602;
          if (x600) {
            int x601 = x598 <= '9';
            x602 = x601;
          } else {
            x602 = 0/*false*/;
          }
          if (x602) {
            x652 = 0/*false*/;
            x653 = x598;
            char  *x603 = x596+1;
            x654 = x603;
          } else {
            x654 = x596;
          }
        }
        int x666 = x652;
        if (x666) {
          char  *x667 = x654;
          x651 = x667;
        } else {
          char x670 = x653;
          char  *x672 = x654;
          x649 = 0/*false*/;
          char x671 = x670 - '0';
          x650 = x671;
          x651 = x672;
        }
        int x678 = x649;
        if (x678) {
          char  *x679 = x651;
          x648 = x679;
        } else {
          int x682 = x650;
          char  *x683 = x651;
          char  *x684 = x683;
          int x685 = 1/*true*/;
          int x686 = x682;
          /*@
          loop invariant (((strlen(x684)>=0) && \valid(x684+(0..strlen(x684)))) && ((x686==-1) || (0<=x686)));
          loop assigns x684, x685, x686;
          */
          for (;;) {
            int x687 = x685;
            if (!x687) break;
            char  *x689 = x684;
            int x696 = 1/*true*/;
            char x697 = '\0';
            char  *x698 = 0/*null*/;
            char x690 = x689[0];
            int x691 = x690 == '\0';
            if (x691) {
              x698 = x689;
            } else {
              int x692 = x690 >= '0';
              int x694;
              if (x692) {
                int x693 = x690 <= '9';
                x694 = x693;
              } else {
                x694 = 0/*false*/;
              }
              if (x694) {
                x696 = 0/*false*/;
                x697 = x690;
                char  *x695 = x689+1;
                x698 = x695;
              } else {
                x698 = x689;
              }
            }
            int x710 = x696;
            if (x710) {
              char  *x711 = x698;
              x685 = 0/*false*/;
            } else {
              char x714 = x697;
              char  *x716 = x698;
              int x717 = x686;
              int x718 = x717 < 0;
              int x726;
              if (x718) {
                x726 = x717;
              } else {
                int x722 = x717 > x721;
                int x725;
                if (x722) {
                  x725 = -1;
                } else {
                  char x715 = x714 - '0';
                  int x723 = x717 * 10;
                  int x724 = x723 + x715;
                  x725 = x724;
                }
                x726 = x725;
              }
              x686 = x726;
              x684 = x716;
            }
          }
          int x752 = x686;
          char  *x753 = x684;
          x646 = 0/*false*/;
          x647 = x752;
          x648 = x753;
        }
        int x759 = x646;
        if (x759) {
          char  *x760 = x648;
          x645 = x760;
        } else {
          int x763 = x647;
          char  *x764 = x648;
          char  *x765 = x764;
          int x766 = 1/*true*/;
          /*@
          loop invariant ((strlen(x765)>=0) && \valid(x765+(0..strlen(x765))));
          loop assigns x765, x766;
          */
          for (;;) {
            int x768 = x766;
            if (!x768) break;
            char  *x770 = x765;
            char x771 = x770[0];
            int x772 = x771 == '\0';
            if (x772) {
              x766 = 0/*false*/;
            } else {
              int x773 = x771 == ' ';
              if (x773) {
                char  *x774 = x770+1;
                x765 = x774;
              } else {
                x766 = 0/*false*/;
              }
            }
          }
          char  *x803 = x765;
          x643 = 0/*false*/;
          x644 = x763;
          x645 = x803;
        }
        int x809 = x643;
        if (x809) {
          char  *x810 = x645;
          x4 = 0/*false*/;
        } else {
          int x813 = x644;
          char  *x814 = x645;
          int x819 = 1/*true*/;
          char x820 = '\0';
          char  *x821 = 0/*null*/;
          char x815 = x814[0];
          int x816 = x815 == '\0';
          if (x816) {
            x821 = x814;
          } else {
            int x817 = x815 == '\n';
            if (x817) {
              x819 = 0/*false*/;
              x820 = x815;
              char  *x818 = x814+1;
              x821 = x818;
            } else {
              x821 = x814;
            }
          }
          int x833 = x819;
          if (x833) {
            char  *x834 = x821;
            x4 = 0/*false*/;
          } else {
            char x837 = x820;
            char  *x838 = x821;
            int x839 = x5;
            int x840 = x813 == -2;
            int x841;
            if (x840) {
              x841 = x839;
            } else {
              x841 = x813;
            }
            x5 = x841;
            x3 = x838;
          }
        }
      } else {
        int x849 = 1/*true*/;
        char  *x851 = 0/*null*/;
        x849 = 0/*false*/;
        x851 = x642;
        int x855 = x849;
        if (x855) {
          char  *x856 = x851;
          x4 = 0/*false*/;
        } else {
          char  *x860 = x851;
          int x865 = 1/*true*/;
          char x866 = '\0';
          char  *x867 = 0/*null*/;
          char x861 = x860[0];
          int x862 = x861 == '\0';
          if (x862) {
            x867 = x860;
          } else {
            int x863 = x861 == '\n';
            if (x863) {
              x865 = 0/*false*/;
              x866 = x861;
              char  *x864 = x860+1;
              x867 = x864;
            } else {
              x867 = x860;
            }
          }
          int x879 = x865;
          if (x879) {
            char  *x880 = x867;
            x4 = 0/*false*/;
          } else {
            char x883 = x866;
            char  *x884 = x867;
            int x885 = x5;
            int x887;
            if (x886) {
              x887 = x885;
            } else {
              x887 = -2;
            }
            x5 = x887;
            x3 = x884;
          }
        }
      }
    }
  }
  int x914 = x5;
  char  *x915 = x3;
  char x916 = x915[0];
  int x917 = x916 == '\0';
  if (x917) {
    x2 = x914;
  } else {
  }
  int x921 = x2;
  return x921;
}
