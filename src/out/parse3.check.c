#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..strlen(x0))));
assigns \nothing;
*/
int p(char  * x0) {
  int x2 = -1;
  int x7 = 1/*true*/;
  char x8 = '\0';
  char  *x9 = 0/*null*/;
  char x3 = x0[0];
  int x4 = x3 == '\0';
  if (x4) {
    x9 = x0;
  } else {
    int x5 = x3 == 'H';
    if (x5) {
      x7 = 0/*false*/;
      x8 = x3;
      char  *x6 = x0+1;
      x9 = x6;
    } else {
      x9 = x0;
    }
  }
  int x21 = x7;
  if (x21) {
    char  *x22 = x9;
  } else {
    char x24 = x8;
    char  *x25 = x9;
    int x30 = 1/*true*/;
    char x31 = '\0';
    char  *x32 = 0/*null*/;
    char x26 = x25[0];
    int x27 = x26 == '\0';
    if (x27) {
      x32 = x25;
    } else {
      int x28 = x26 == 'T';
      if (x28) {
        x30 = 0/*false*/;
        x31 = x26;
        char  *x29 = x25+1;
        x32 = x29;
      } else {
        x32 = x25;
      }
    }
    int x44 = x30;
    if (x44) {
      char  *x45 = x32;
    } else {
      char x47 = x31;
      char  *x48 = x32;
      int x53 = 1/*true*/;
      char x54 = '\0';
      char  *x55 = 0/*null*/;
      char x49 = x48[0];
      int x50 = x49 == '\0';
      if (x50) {
        x55 = x48;
      } else {
        int x51 = x49 == 'T';
        if (x51) {
          x53 = 0/*false*/;
          x54 = x49;
          char  *x52 = x48+1;
          x55 = x52;
        } else {
          x55 = x48;
        }
      }
      int x67 = x53;
      if (x67) {
        char  *x68 = x55;
      } else {
        char x70 = x54;
        char  *x71 = x55;
        int x76 = 1/*true*/;
        char x77 = '\0';
        char  *x78 = 0/*null*/;
        char x72 = x71[0];
        int x73 = x72 == '\0';
        if (x73) {
          x78 = x71;
        } else {
          int x74 = x72 == 'P';
          if (x74) {
            x76 = 0/*false*/;
            x77 = x72;
            char  *x75 = x71+1;
            x78 = x75;
          } else {
            x78 = x71;
          }
        }
        int x90 = x76;
        if (x90) {
          char  *x91 = x78;
        } else {
          char x93 = x77;
          char  *x94 = x78;
          int x99 = 1/*true*/;
          char x100 = '\0';
          char  *x101 = 0/*null*/;
          char x95 = x94[0];
          int x96 = x95 == '\0';
          if (x96) {
            x101 = x94;
          } else {
            int x97 = x95 == '/';
            if (x97) {
              x99 = 0/*false*/;
              x100 = x95;
              char  *x98 = x94+1;
              x101 = x98;
            } else {
              x101 = x94;
            }
          }
          int x113 = x99;
          if (x113) {
            char  *x114 = x101;
          } else {
            char x116 = x100;
            char  *x117 = x101;
            int x124 = 1/*true*/;
            char x125 = '\0';
            char  *x126 = 0/*null*/;
            char x118 = x117[0];
            int x119 = x118 == '\0';
            if (x119) {
              x126 = x117;
            } else {
              int x120 = x118 >= '0';
              int x122;
              if (x120) {
                int x121 = x118 <= '9';
                x122 = x121;
              } else {
                x122 = 0/*false*/;
              }
              if (x122) {
                x124 = 0/*false*/;
                x125 = x118;
                char  *x123 = x117+1;
                x126 = x123;
              } else {
                x126 = x117;
              }
            }
            int x138 = x124;
            if (x138) {
              char  *x139 = x126;
            } else {
              char x141 = x125;
              char  *x142 = x126;
              char  *x143 = x142;
              int x144 = 1/*true*/;
              /*@
              loop invariant ((strlen(x143)>=0) && \valid(x143+(0..strlen(x143))));
              loop assigns x143, x144;
              */
              for (;;) {
                int x145 = x144;
                if (!x145) break;
                char  *x147 = x143;
                char x148 = x147[0];
                int x149 = x148 == '\0';
                if (x149) {
                  x144 = 0/*false*/;
                } else {
                  int x150 = x148 >= '0';
                  int x152;
                  if (x150) {
                    int x151 = x148 <= '9';
                    x152 = x151;
                  } else {
                    x152 = 0/*false*/;
                  }
                  if (x152) {
                    char  *x153 = x147+1;
                    x143 = x153;
                  } else {
                    x144 = 0/*false*/;
                  }
                }
              }
              char  *x177 = x143;
              char x178 = x177[0];
              int x179 = x178 == '\0';
              if (x179) {
              } else {
                int x180 = x178 == '.';
                if (x180) {
                  int x188 = 1/*true*/;
                  char x189 = '\0';
                  char  *x190 = 0/*null*/;
                  char  *x181 = x177+1;
                  char x182 = x181[0];
                  int x183 = x182 == '\0';
                  if (x183) {
                    x190 = x181;
                  } else {
                    int x184 = x182 >= '0';
                    int x186;
                    if (x184) {
                      int x185 = x182 <= '9';
                      x186 = x185;
                    } else {
                      x186 = 0/*false*/;
                    }
                    if (x186) {
                      x188 = 0/*false*/;
                      x189 = x182;
                      char  *x187 = x181+1;
                      x190 = x187;
                    } else {
                      x190 = x181;
                    }
                  }
                  int x202 = x188;
                  if (x202) {
                    char  *x203 = x190;
                  } else {
                    char x205 = x189;
                    char  *x206 = x190;
                    char  *x207 = x206;
                    int x208 = 1/*true*/;
                    /*@
                    loop invariant ((strlen(x207)>=0) && \valid(x207+(0..strlen(x207))));
                    loop assigns x207, x208;
                    */
                    for (;;) {
                      int x209 = x208;
                      if (!x209) break;
                      char  *x211 = x207;
                      char x212 = x211[0];
                      int x213 = x212 == '\0';
                      if (x213) {
                        x208 = 0/*false*/;
                      } else {
                        int x214 = x212 >= '0';
                        int x216;
                        if (x214) {
                          int x215 = x212 <= '9';
                          x216 = x215;
                        } else {
                          x216 = 0/*false*/;
                        }
                        if (x216) {
                          char  *x217 = x211+1;
                          x207 = x217;
                        } else {
                          x208 = 0/*false*/;
                        }
                      }
                    }
                    char  *x241 = x207;
                    char  *x242 = x241;
                    int x243 = 1/*true*/;
                    /*@
                    loop invariant ((strlen(x242)>=0) && \valid(x242+(0..strlen(x242))));
                    loop assigns x242, x243;
                    */
                    for (;;) {
                      int x244 = x243;
                      if (!x244) break;
                      char  *x246 = x242;
                      char x247 = x246[0];
                      int x248 = x247 == '\0';
                      if (x248) {
                        x243 = 0/*false*/;
                      } else {
                        int x249 = x247 == ' ';
                        if (x249) {
                          char  *x250 = x246+1;
                          x242 = x250;
                        } else {
                          x243 = 0/*false*/;
                        }
                      }
                    }
                    char  *x274 = x242;
                    int x281 = 1/*true*/;
                    char x282 = '\0';
                    char  *x283 = 0/*null*/;
                    char x275 = x274[0];
                    int x276 = x275 == '\0';
                    if (x276) {
                      x283 = x274;
                    } else {
                      int x277 = x275 >= '0';
                      int x279;
                      if (x277) {
                        int x278 = x275 <= '9';
                        x279 = x278;
                      } else {
                        x279 = 0/*false*/;
                      }
                      if (x279) {
                        x281 = 0/*false*/;
                        x282 = x275;
                        char  *x280 = x274+1;
                        x283 = x280;
                      } else {
                        x283 = x274;
                      }
                    }
                    int x295 = x281;
                    if (x295) {
                      char  *x296 = x283;
                    } else {
                      char x298 = x282;
                      char  *x300 = x283;
                      char  *x301 = x300;
                      int x302 = 1/*true*/;
                      char x299 = x298 - '0';
                      int x303 = x299;
                      int x336 = INT_MAX;
                      int x337 = x336 / 10;
                      int x338 = x337 - 10;
                      /*@
                      loop invariant (((strlen(x301)>=0) && \valid(x301+(0..strlen(x301)))) && ((x303==-1) || (0<=x303)));
                      loop assigns x301, x302, x303;
                      */
                      for (;;) {
                        int x304 = x302;
                        if (!x304) break;
                        char  *x306 = x301;
                        int x313 = 1/*true*/;
                        char x314 = '\0';
                        char  *x315 = 0/*null*/;
                        char x307 = x306[0];
                        int x308 = x307 == '\0';
                        if (x308) {
                          x315 = x306;
                        } else {
                          int x309 = x307 >= '0';
                          int x311;
                          if (x309) {
                            int x310 = x307 <= '9';
                            x311 = x310;
                          } else {
                            x311 = 0/*false*/;
                          }
                          if (x311) {
                            x313 = 0/*false*/;
                            x314 = x307;
                            char  *x312 = x306+1;
                            x315 = x312;
                          } else {
                            x315 = x306;
                          }
                        }
                        int x327 = x313;
                        if (x327) {
                          char  *x328 = x315;
                          x302 = 0/*false*/;
                        } else {
                          char x331 = x314;
                          char  *x333 = x315;
                          int x334 = x303;
                          int x335 = x334 < 0;
                          int x343;
                          if (x335) {
                            x343 = x334;
                          } else {
                            int x339 = x334 > x338;
                            int x342;
                            if (x339) {
                              x342 = -1;
                            } else {
                              char x332 = x331 - '0';
                              int x340 = x334 * 10;
                              int x341 = x340 + x332;
                              x342 = x341;
                            }
                            x343 = x342;
                          }
                          x303 = x343;
                          x301 = x333;
                        }
                      }
                      int x369 = x303;
                      char  *x370 = x301;
                      char  *x371 = x370;
                      int x372 = 1/*true*/;
                      /*@
                      loop invariant ((strlen(x371)>=0) && \valid(x371+(0..strlen(x371))));
                      loop assigns x371, x372;
                      */
                      for (;;) {
                        int x373 = x372;
                        if (!x373) break;
                        char  *x375 = x371;
                        char x376 = x375[0];
                        int x377 = x376 == '\0';
                        if (x377) {
                          x372 = 0/*false*/;
                        } else {
                          int x378 = x376 != '\n';
                          if (x378) {
                            char  *x379 = x375+1;
                            x371 = x379;
                          } else {
                            x372 = 0/*false*/;
                          }
                        }
                      }
                      char  *x403 = x371;
                      int x408 = 1/*true*/;
                      char x409 = '\0';
                      char  *x410 = 0/*null*/;
                      char x404 = x403[0];
                      int x405 = x404 == '\0';
                      if (x405) {
                        x410 = x403;
                      } else {
                        int x406 = x404 == '\n';
                        if (x406) {
                          x408 = 0/*false*/;
                          x409 = x404;
                          char  *x407 = x403+1;
                          x410 = x407;
                        } else {
                          x410 = x403;
                        }
                      }
                      int x422 = x408;
                      if (x422) {
                        char  *x423 = x410;
                      } else {
                        char x425 = x409;
                        char  *x426 = x410;
                        char  *x427 = x426;
                        int x428 = 1/*true*/;
                        int x429 = 0;
                        int x1077 = -2 == -2;
                        /*@
                        loop invariant ((strlen(x427)>=0) && \valid(x427+(0..strlen(x427))));
                        loop assigns x427, x428, x429;
                        */
                        for (;;) {
                          int x430 = x428;
                          if (!x430) break;
                          char  *x432 = x427;
                          char  *x433 = x432;
                          int x434 = 1/*true*/;
                          int x435 = x434;
                          if (x435) {
                            char  *x436 = x433;
                            char x437 = x436[0];
                            int x438 = x437 == '\0';
                            if (x438) {
                              x434 = 0/*false*/;
                            } else {
                              int x441 = x437 != 'C';
                              if (x441) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x444 = x436+1;
                                x433 = x444;
                              }
                            }
                          } else {
                          }
                          int x452 = x434;
                          if (x452) {
                            char  *x453 = x433;
                            char x454 = x453[0];
                            int x455 = x454 == '\0';
                            if (x455) {
                              x434 = 0/*false*/;
                            } else {
                              int x458 = x454 != 'o';
                              if (x458) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x461 = x453+1;
                                x433 = x461;
                              }
                            }
                          } else {
                          }
                          int x469 = x434;
                          if (x469) {
                            char  *x470 = x433;
                            char x471 = x470[0];
                            int x472 = x471 == '\0';
                            if (x472) {
                              x434 = 0/*false*/;
                            } else {
                              int x475 = x471 != 'n';
                              if (x475) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x478 = x470+1;
                                x433 = x478;
                              }
                            }
                          } else {
                          }
                          int x486 = x434;
                          if (x486) {
                            char  *x487 = x433;
                            char x488 = x487[0];
                            int x489 = x488 == '\0';
                            if (x489) {
                              x434 = 0/*false*/;
                            } else {
                              int x492 = x488 != 't';
                              if (x492) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x495 = x487+1;
                                x433 = x495;
                              }
                            }
                          } else {
                          }
                          int x503 = x434;
                          if (x503) {
                            char  *x504 = x433;
                            char x505 = x504[0];
                            int x506 = x505 == '\0';
                            if (x506) {
                              x434 = 0/*false*/;
                            } else {
                              int x509 = x505 != 'e';
                              if (x509) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x512 = x504+1;
                                x433 = x512;
                              }
                            }
                          } else {
                          }
                          int x520 = x434;
                          if (x520) {
                            char  *x521 = x433;
                            char x522 = x521[0];
                            int x523 = x522 == '\0';
                            if (x523) {
                              x434 = 0/*false*/;
                            } else {
                              int x526 = x522 != 'n';
                              if (x526) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x529 = x521+1;
                                x433 = x529;
                              }
                            }
                          } else {
                          }
                          int x537 = x434;
                          if (x537) {
                            char  *x538 = x433;
                            char x539 = x538[0];
                            int x540 = x539 == '\0';
                            if (x540) {
                              x434 = 0/*false*/;
                            } else {
                              int x543 = x539 != 't';
                              if (x543) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x546 = x538+1;
                                x433 = x546;
                              }
                            }
                          } else {
                          }
                          int x554 = x434;
                          if (x554) {
                            char  *x555 = x433;
                            char x556 = x555[0];
                            int x557 = x556 == '\0';
                            if (x557) {
                              x434 = 0/*false*/;
                            } else {
                              int x560 = x556 != '-';
                              if (x560) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x563 = x555+1;
                                x433 = x563;
                              }
                            }
                          } else {
                          }
                          int x571 = x434;
                          if (x571) {
                            char  *x572 = x433;
                            char x573 = x572[0];
                            int x574 = x573 == '\0';
                            if (x574) {
                              x434 = 0/*false*/;
                            } else {
                              int x577 = x573 != 'L';
                              if (x577) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x580 = x572+1;
                                x433 = x580;
                              }
                            }
                          } else {
                          }
                          int x588 = x434;
                          if (x588) {
                            char  *x589 = x433;
                            char x590 = x589[0];
                            int x591 = x590 == '\0';
                            if (x591) {
                              x434 = 0/*false*/;
                            } else {
                              int x594 = x590 != 'e';
                              if (x594) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x597 = x589+1;
                                x433 = x597;
                              }
                            }
                          } else {
                          }
                          int x605 = x434;
                          if (x605) {
                            char  *x606 = x433;
                            char x607 = x606[0];
                            int x608 = x607 == '\0';
                            if (x608) {
                              x434 = 0/*false*/;
                            } else {
                              int x611 = x607 != 'n';
                              if (x611) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x614 = x606+1;
                                x433 = x614;
                              }
                            }
                          } else {
                          }
                          int x622 = x434;
                          if (x622) {
                            char  *x623 = x433;
                            char x624 = x623[0];
                            int x625 = x624 == '\0';
                            if (x625) {
                              x434 = 0/*false*/;
                            } else {
                              int x628 = x624 != 'g';
                              if (x628) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x631 = x623+1;
                                x433 = x631;
                              }
                            }
                          } else {
                          }
                          int x639 = x434;
                          if (x639) {
                            char  *x640 = x433;
                            char x641 = x640[0];
                            int x642 = x641 == '\0';
                            if (x642) {
                              x434 = 0/*false*/;
                            } else {
                              int x645 = x641 != 't';
                              if (x645) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x648 = x640+1;
                                x433 = x648;
                              }
                            }
                          } else {
                          }
                          int x656 = x434;
                          if (x656) {
                            char  *x657 = x433;
                            char x658 = x657[0];
                            int x659 = x658 == '\0';
                            if (x659) {
                              x434 = 0/*false*/;
                            } else {
                              int x662 = x658 != 'h';
                              if (x662) {
                                x434 = 0/*false*/;
                              } else {
                                char  *x665 = x657+1;
                                x433 = x665;
                              }
                            }
                          } else {
                          }
                          int x673 = x434;
                          char  *x674 = x433;
                          int x675 = 1/*true*/;
                          int x676 = 0;
                          char  *x677 = 0/*null*/;
                          if (x673) {
                            x675 = 0/*false*/;
                            x676 = 1;
                            x677 = x674;
                          } else {
                            x677 = x432;
                          }
                          int x685 = x675;
                          char  *x686 = x432;
                          int x687 = 1/*true*/;
                          /*@
                          loop invariant ((strlen(x686)>=0) && \valid(x686+(0..strlen(x686))));
                          loop assigns x686, x687;
                          */
                          for (;;) {
                            int x688 = x687;
                            if (!x688) break;
                            char  *x690 = x686;
                            int x701 = 1/*true*/;
                            char x702 = '\0';
                            char  *x703 = 0/*null*/;
                            char x691 = x690[0];
                            int x692 = x691 == '\0';
                            if (x692) {
                              x703 = x690;
                            } else {
                              int x693 = x691 >= 'a';
                              int x695;
                              if (x693) {
                                int x694 = x691 <= 'z';
                                x695 = x694;
                              } else {
                                x695 = 0/*false*/;
                              }
                              int x696 = x691 >= 'A';
                              int x698;
                              if (x696) {
                                int x697 = x691 <= 'Z';
                                x698 = x697;
                              } else {
                                x698 = 0/*false*/;
                              }
                              int x699 = x695 || x698;
                              if (x699) {
                                x701 = 0/*false*/;
                                x702 = x691;
                                char  *x700 = x690+1;
                                x703 = x700;
                              } else {
                                x703 = x690;
                              }
                            }
                            int x715 = x701;
                            char x717 = x702;
                            char  *x718 = x703;
                            if (x715) {
                              if (x692) {
                                x687 = 0/*false*/;
                              } else {
                                int x716 = x691 == '-';
                                if (x716) {
                                  char  *x700 = x690+1;
                                  x686 = x700;
                                } else {
                                  x687 = 0/*false*/;
                                }
                              }
                            } else {
                              x686 = x718;
                            }
                          }
                          char  *x746 = x686;
                          int x747 = x676;
                          char  *x748 = x677;
                          int x749 = 1/*true*/;
                          int x750 = 0;
                          char  *x751 = 0/*null*/;
                          if (x685) {
                            x749 = 0/*false*/;
                            x750 = 0;
                            x751 = x746;
                          } else {
                            x749 = 0/*false*/;
                            x750 = x747;
                            x751 = x748;
                          }
                          int x761 = x749;
                          if (x761) {
                            char  *x762 = x751;
                            x428 = 0/*false*/;
                          } else {
                            int x765 = x750;
                            char  *x766 = x751;
                            char  *x767 = x766;
                            int x768 = 1/*true*/;
                            /*@
                            loop invariant ((strlen(x767)>=0) && \valid(x767+(0..strlen(x767))));
                            loop assigns x767, x768;
                            */
                            for (;;) {
                              int x769 = x768;
                              if (!x769) break;
                              char  *x771 = x767;
                              char x772 = x771[0];
                              int x773 = x772 == '\0';
                              if (x773) {
                                x768 = 0/*false*/;
                              } else {
                                int x774 = x772 == ' ';
                                if (x774) {
                                  char  *x775 = x771+1;
                                  x767 = x775;
                                } else {
                                  x768 = 0/*false*/;
                                }
                              }
                            }
                            char  *x799 = x767;
                            int x804 = 1/*true*/;
                            char x805 = '\0';
                            char  *x806 = 0/*null*/;
                            char x800 = x799[0];
                            int x801 = x800 == '\0';
                            if (x801) {
                              x806 = x799;
                            } else {
                              int x802 = x800 == ':';
                              if (x802) {
                                x804 = 0/*false*/;
                                x805 = x800;
                                char  *x803 = x799+1;
                                x806 = x803;
                              } else {
                                x806 = x799;
                              }
                            }
                            int x818 = x804;
                            if (x818) {
                              char  *x819 = x806;
                              x428 = 0/*false*/;
                            } else {
                              char x822 = x805;
                              char  *x823 = x806;
                              char  *x824 = x823;
                              int x825 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x824)>=0) && \valid(x824+(0..strlen(x824))));
                              loop assigns x824, x825;
                              */
                              for (;;) {
                                int x826 = x825;
                                if (!x826) break;
                                char  *x828 = x824;
                                char x829 = x828[0];
                                int x830 = x829 == '\0';
                                if (x830) {
                                  x825 = 0/*false*/;
                                } else {
                                  int x831 = x829 == ' ';
                                  if (x831) {
                                    char  *x832 = x828+1;
                                    x824 = x832;
                                  } else {
                                    x825 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x856 = x824;
                              char  *x864 = x856;
                              int x865 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x864)>=0) && \valid(x864+(0..strlen(x864))));
                              loop assigns x864, x865;
                              */
                              for (;;) {
                                int x866 = x865;
                                if (!x866) break;
                                char  *x868 = x864;
                                char x869 = x868[0];
                                int x870 = x869 == '\0';
                                if (x870) {
                                  x865 = 0/*false*/;
                                } else {
                                  int x871 = x869 != '\n';
                                  if (x871) {
                                    char  *x872 = x868+1;
                                    x864 = x872;
                                  } else {
                                    x865 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x896 = x864;
                              int x857 = x765 == 1;
                              if (x857) {
                                int x897 = 1/*true*/;
                                char x898 = '\0';
                                char  *x899 = 0/*null*/;
                                char x858 = x856[0];
                                int x859 = x858 == '\0';
                                if (x859) {
                                  x899 = x856;
                                } else {
                                  int x860 = x858 >= '0';
                                  int x862;
                                  if (x860) {
                                    int x861 = x858 <= '9';
                                    x862 = x861;
                                  } else {
                                    x862 = 0/*false*/;
                                  }
                                  if (x862) {
                                    x897 = 0/*false*/;
                                    x898 = x858;
                                    char  *x863 = x856+1;
                                    x899 = x863;
                                  } else {
                                    x899 = x856;
                                  }
                                }
                                int x911 = x897;
                                if (x911) {
                                  char  *x912 = x899;
                                  x428 = 0/*false*/;
                                } else {
                                  char x915 = x898;
                                  char  *x917 = x899;
                                  char  *x918 = x917;
                                  int x919 = 1/*true*/;
                                  char x916 = x915 - '0';
                                  int x920 = x916;
                                  /*@
                                  loop invariant (((strlen(x918)>=0) && \valid(x918+(0..strlen(x918)))) && ((x920==-1) || (0<=x920)));
                                  loop assigns x918, x919, x920;
                                  */
                                  for (;;) {
                                    int x921 = x919;
                                    if (!x921) break;
                                    char  *x923 = x918;
                                    int x930 = 1/*true*/;
                                    char x931 = '\0';
                                    char  *x932 = 0/*null*/;
                                    char x924 = x923[0];
                                    int x925 = x924 == '\0';
                                    if (x925) {
                                      x932 = x923;
                                    } else {
                                      int x926 = x924 >= '0';
                                      int x928;
                                      if (x926) {
                                        int x927 = x924 <= '9';
                                        x928 = x927;
                                      } else {
                                        x928 = 0/*false*/;
                                      }
                                      if (x928) {
                                        x930 = 0/*false*/;
                                        x931 = x924;
                                        char  *x929 = x923+1;
                                        x932 = x929;
                                      } else {
                                        x932 = x923;
                                      }
                                    }
                                    int x944 = x930;
                                    if (x944) {
                                      char  *x945 = x932;
                                      x919 = 0/*false*/;
                                    } else {
                                      char x948 = x931;
                                      char  *x950 = x932;
                                      int x951 = x920;
                                      int x952 = x951 < 0;
                                      int x957;
                                      if (x952) {
                                        x957 = x951;
                                      } else {
                                        int x953 = x951 > x338;
                                        int x956;
                                        if (x953) {
                                          x956 = -1;
                                        } else {
                                          char x949 = x948 - '0';
                                          int x954 = x951 * 10;
                                          int x955 = x954 + x949;
                                          x956 = x955;
                                        }
                                        x957 = x956;
                                      }
                                      x920 = x957;
                                      x918 = x950;
                                    }
                                  }
                                  int x983 = x920;
                                  char  *x984 = x918;
                                  char  *x985 = x984;
                                  int x986 = 1/*true*/;
                                  /*@
                                  loop invariant ((strlen(x985)>=0) && \valid(x985+(0..strlen(x985))));
                                  loop assigns x985, x986;
                                  */
                                  for (;;) {
                                    int x987 = x986;
                                    if (!x987) break;
                                    char  *x989 = x985;
                                    char x990 = x989[0];
                                    int x991 = x990 == '\0';
                                    if (x991) {
                                      x986 = 0/*false*/;
                                    } else {
                                      int x992 = x990 == ' ';
                                      if (x992) {
                                        char  *x993 = x989+1;
                                        x985 = x993;
                                      } else {
                                        x986 = 0/*false*/;
                                      }
                                    }
                                  }
                                  char  *x1017 = x985;
                                  int x1022 = 1/*true*/;
                                  char x1023 = '\0';
                                  char  *x1024 = 0/*null*/;
                                  char x1018 = x1017[0];
                                  int x1019 = x1018 == '\0';
                                  if (x1019) {
                                    x1024 = x1017;
                                  } else {
                                    int x1020 = x1018 == '\n';
                                    if (x1020) {
                                      x1022 = 0/*false*/;
                                      x1023 = x1018;
                                      char  *x1021 = x1017+1;
                                      x1024 = x1021;
                                    } else {
                                      x1024 = x1017;
                                    }
                                  }
                                  int x1036 = x1022;
                                  if (x1036) {
                                    char  *x1037 = x1024;
                                    x428 = 0/*false*/;
                                  } else {
                                    char x1040 = x1023;
                                    char  *x1041 = x1024;
                                    int x1042 = x429;
                                    int x1043 = x983 == -2;
                                    int x1044;
                                    if (x1043) {
                                      x1044 = x1042;
                                    } else {
                                      x1044 = x983;
                                    }
                                    x429 = x1044;
                                    x427 = x1041;
                                  }
                                }
                              } else {
                                int x1056 = 1/*true*/;
                                char x1057 = '\0';
                                char  *x1058 = 0/*null*/;
                                char x1052 = x896[0];
                                int x1053 = x1052 == '\0';
                                if (x1053) {
                                  x1058 = x896;
                                } else {
                                  int x1054 = x1052 == '\n';
                                  if (x1054) {
                                    x1056 = 0/*false*/;
                                    x1057 = x1052;
                                    char  *x1055 = x896+1;
                                    x1058 = x1055;
                                  } else {
                                    x1058 = x896;
                                  }
                                }
                                int x1070 = x1056;
                                if (x1070) {
                                  char  *x1071 = x1058;
                                  x428 = 0/*false*/;
                                } else {
                                  char x1074 = x1057;
                                  char  *x1075 = x1058;
                                  int x1076 = x429;
                                  int x1078;
                                  if (x1077) {
                                    x1078 = x1076;
                                  } else {
                                    x1078 = -2;
                                  }
                                  x429 = x1078;
                                  x427 = x1075;
                                }
                              }
                            }
                          }
                        }
                        int x1105 = x429;
                        char  *x1106 = x427;
                        int x1111 = 1/*true*/;
                        char x1112 = '\0';
                        char  *x1113 = 0/*null*/;
                        char x1107 = x1106[0];
                        int x1108 = x1107 == '\0';
                        if (x1108) {
                          x1113 = x1106;
                        } else {
                          int x1109 = x1107 == '\n';
                          if (x1109) {
                            x1111 = 0/*false*/;
                            x1112 = x1107;
                            char  *x1110 = x1106+1;
                            x1113 = x1110;
                          } else {
                            x1113 = x1106;
                          }
                        }
                        int x1125 = x1111;
                        if (x1125) {
                          char  *x1126 = x1113;
                        } else {
                          char x1128 = x1112;
                          char  *x1129 = x1113;
                          int x1131 = 1/*true*/;
                          char  *x1132 = x1129;
                          /*@
                          loop invariant ((0<=x1134) && ((strlen(x1132)>=0) && \valid(x1132+(0..strlen(x1132)))));
                          loop assigns x1134, x1131, x1132;
                          loop variant (x429-x1134);
                          */
                          for(int x1134=0; x1134 < x1105; x1134++) {
                            int x1135 = x1131;
                            if (x1135) {
                              char  *x1136 = x1132;
                              char x1137 = x1136[0];
                              int x1138 = x1137 == '\0';
                              if (x1138) {
                                x1131 = 0/*false*/;
                              } else {
                                if (1/*true*/) {
                                  char  *x1139 = x1136+1;
                                  x1132 = x1139;
                                } else {
                                  x1131 = 0/*false*/;
                                }
                              }
                            } else {
                            }
                          }
                          int x1169 = x1131;
                          char  *x1170 = x1132;
                          int x1130 = x1105 < 0;
                          if (x1130) {
                          } else {
                            if (x1169) {
                              int x1175 = 1/*true*/;
                              char x1176 = '\0';
                              char  *x1177 = 0/*null*/;
                              char x1171 = x1170[0];
                              int x1172 = x1171 == '\0';
                              if (x1172) {
                                x1177 = x1170;
                              } else {
                                int x1173 = x1171 == '\n';
                                if (x1173) {
                                  x1175 = 0/*false*/;
                                  x1176 = x1171;
                                  char  *x1174 = x1170+1;
                                  x1177 = x1174;
                                } else {
                                  x1177 = x1170;
                                }
                              }
                              int x1189 = x1175;
                              if (x1189) {
                                char  *x1190 = x1177;
                              } else {
                                char x1192 = x1176;
                                char  *x1193 = x1177;
                                char x1194 = x1193[0];
                                int x1195 = x1194 == '\0';
                                if (x1195) {
                                  x2 = x1105;
                                } else {
                                }
                              }
                            } else {
                            }
                          }
                        }
                      }
                    }
                  }
                } else {
                }
              }
            }
          }
        }
      }
    }
  }
  int x1229 = x2;
  return x1229;
}
