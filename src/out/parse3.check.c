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
                int x146 = x144;
                if (!x146) break;
                char  *x148 = x143;
                char x149 = x148[0];
                int x150 = x149 == '\0';
                if (x150) {
                  x144 = 0/*false*/;
                } else {
                  int x151 = x149 >= '0';
                  int x153;
                  if (x151) {
                    int x152 = x149 <= '9';
                    x153 = x152;
                  } else {
                    x153 = 0/*false*/;
                  }
                  if (x153) {
                    char  *x154 = x148+1;
                    x143 = x154;
                  } else {
                    x144 = 0/*false*/;
                  }
                }
              }
              char  *x183 = x143;
              char x184 = x183[0];
              int x185 = x184 == '\0';
              if (x185) {
              } else {
                int x186 = x184 == '.';
                if (x186) {
                  int x194 = 1/*true*/;
                  char x195 = '\0';
                  char  *x196 = 0/*null*/;
                  char  *x187 = x183+1;
                  char x188 = x187[0];
                  int x189 = x188 == '\0';
                  if (x189) {
                    x196 = x187;
                  } else {
                    int x190 = x188 >= '0';
                    int x192;
                    if (x190) {
                      int x191 = x188 <= '9';
                      x192 = x191;
                    } else {
                      x192 = 0/*false*/;
                    }
                    if (x192) {
                      x194 = 0/*false*/;
                      x195 = x188;
                      char  *x193 = x187+1;
                      x196 = x193;
                    } else {
                      x196 = x187;
                    }
                  }
                  int x208 = x194;
                  if (x208) {
                    char  *x209 = x196;
                  } else {
                    char x211 = x195;
                    char  *x212 = x196;
                    char  *x213 = x212;
                    int x214 = 1/*true*/;
                    /*@
                    loop invariant ((strlen(x213)>=0) && \valid(x213+(0..strlen(x213))));
                    loop assigns x213, x214;
                    */
                    for (;;) {
                      int x216 = x214;
                      if (!x216) break;
                      char  *x218 = x213;
                      char x219 = x218[0];
                      int x220 = x219 == '\0';
                      if (x220) {
                        x214 = 0/*false*/;
                      } else {
                        int x221 = x219 >= '0';
                        int x223;
                        if (x221) {
                          int x222 = x219 <= '9';
                          x223 = x222;
                        } else {
                          x223 = 0/*false*/;
                        }
                        if (x223) {
                          char  *x224 = x218+1;
                          x213 = x224;
                        } else {
                          x214 = 0/*false*/;
                        }
                      }
                    }
                    char  *x253 = x213;
                    char  *x254 = x253;
                    int x255 = 1/*true*/;
                    /*@
                    loop invariant ((strlen(x254)>=0) && \valid(x254+(0..strlen(x254))));
                    loop assigns x254, x255;
                    */
                    for (;;) {
                      int x257 = x255;
                      if (!x257) break;
                      char  *x259 = x254;
                      char x260 = x259[0];
                      int x261 = x260 == '\0';
                      if (x261) {
                        x255 = 0/*false*/;
                      } else {
                        int x262 = x260 == ' ';
                        if (x262) {
                          char  *x263 = x259+1;
                          x254 = x263;
                        } else {
                          x255 = 0/*false*/;
                        }
                      }
                    }
                    char  *x292 = x254;
                    int x299 = 1/*true*/;
                    char x300 = '\0';
                    char  *x301 = 0/*null*/;
                    char x293 = x292[0];
                    int x294 = x293 == '\0';
                    if (x294) {
                      x301 = x292;
                    } else {
                      int x295 = x293 >= '0';
                      int x297;
                      if (x295) {
                        int x296 = x293 <= '9';
                        x297 = x296;
                      } else {
                        x297 = 0/*false*/;
                      }
                      if (x297) {
                        x299 = 0/*false*/;
                        x300 = x293;
                        char  *x298 = x292+1;
                        x301 = x298;
                      } else {
                        x301 = x292;
                      }
                    }
                    int x313 = x299;
                    if (x313) {
                      char  *x314 = x301;
                    } else {
                      char x316 = x300;
                      char  *x318 = x301;
                      char  *x319 = x318;
                      int x320 = 1/*true*/;
                      char x317 = x316 - '0';
                      int x321 = x317;
                      int x354 = INT_MAX;
                      int x355 = x354 / 10;
                      int x356 = x355 - 10;
                      /*@
                      loop invariant (((strlen(x319)>=0) && \valid(x319+(0..strlen(x319)))) && ((x321==-1) || (0<=x321)));
                      loop assigns x319, x320, x321;
                      */
                      for (;;) {
                        int x322 = x320;
                        if (!x322) break;
                        char  *x324 = x319;
                        int x331 = 1/*true*/;
                        char x332 = '\0';
                        char  *x333 = 0/*null*/;
                        char x325 = x324[0];
                        int x326 = x325 == '\0';
                        if (x326) {
                          x333 = x324;
                        } else {
                          int x327 = x325 >= '0';
                          int x329;
                          if (x327) {
                            int x328 = x325 <= '9';
                            x329 = x328;
                          } else {
                            x329 = 0/*false*/;
                          }
                          if (x329) {
                            x331 = 0/*false*/;
                            x332 = x325;
                            char  *x330 = x324+1;
                            x333 = x330;
                          } else {
                            x333 = x324;
                          }
                        }
                        int x345 = x331;
                        if (x345) {
                          char  *x346 = x333;
                          x320 = 0/*false*/;
                        } else {
                          char x349 = x332;
                          char  *x351 = x333;
                          int x352 = x321;
                          int x353 = x352 < 0;
                          int x361;
                          if (x353) {
                            x361 = x352;
                          } else {
                            int x357 = x352 > x356;
                            int x360;
                            if (x357) {
                              x360 = -1;
                            } else {
                              char x350 = x349 - '0';
                              int x358 = x352 * 10;
                              int x359 = x358 + x350;
                              x360 = x359;
                            }
                            x361 = x360;
                          }
                          x321 = x361;
                          x319 = x351;
                        }
                      }
                      int x387 = x321;
                      char  *x388 = x319;
                      char  *x389 = x388;
                      int x390 = 1/*true*/;
                      /*@
                      loop invariant ((strlen(x389)>=0) && \valid(x389+(0..strlen(x389))));
                      loop assigns x389, x390;
                      */
                      for (;;) {
                        int x392 = x390;
                        if (!x392) break;
                        char  *x394 = x389;
                        char x395 = x394[0];
                        int x396 = x395 == '\0';
                        if (x396) {
                          x390 = 0/*false*/;
                        } else {
                          int x397 = x395 != '\n';
                          if (x397) {
                            char  *x398 = x394+1;
                            x389 = x398;
                          } else {
                            x390 = 0/*false*/;
                          }
                        }
                      }
                      char  *x427 = x389;
                      int x432 = 1/*true*/;
                      char x433 = '\0';
                      char  *x434 = 0/*null*/;
                      char x428 = x427[0];
                      int x429 = x428 == '\0';
                      if (x429) {
                        x434 = x427;
                      } else {
                        int x430 = x428 == '\n';
                        if (x430) {
                          x432 = 0/*false*/;
                          x433 = x428;
                          char  *x431 = x427+1;
                          x434 = x431;
                        } else {
                          x434 = x427;
                        }
                      }
                      int x446 = x432;
                      if (x446) {
                        char  *x447 = x434;
                      } else {
                        char x449 = x433;
                        char  *x450 = x434;
                        char  *x451 = x450;
                        int x452 = 1/*true*/;
                        int x453 = 0;
                        int x999 = 0 == 1;
                        int x1231 = -2 == -2;
                        /*@
                        loop invariant ((strlen(x451)>=0) && \valid(x451+(0..strlen(x451))));
                        loop assigns x451, x452, x453;
                        */
                        for (;;) {
                          int x454 = x452;
                          if (!x454) break;
                          char  *x456 = x451;
                          int x461 = 1/*true*/;
                          int x462 = 0;
                          char  *x463 = 0/*null*/;
                          int x464 = 1/*true*/;
                          char x465 = '\0';
                          char  *x466 = 0/*null*/;
                          char x457 = x456[0];
                          int x458 = x457 == '\0';
                          if (x458) {
                            x466 = x456;
                          } else {
                            int x459 = x457 == 'C';
                            if (x459) {
                              x464 = 0/*false*/;
                              x465 = x457;
                              char  *x460 = x456+1;
                              x466 = x460;
                            } else {
                              x466 = x456;
                            }
                          }
                          int x478 = x464;
                          if (x478) {
                            char  *x479 = x466;
                            x463 = x479;
                          } else {
                            char x482 = x465;
                            char  *x483 = x466;
                            int x488 = 1/*true*/;
                            char x489 = '\0';
                            char  *x490 = 0/*null*/;
                            char x484 = x483[0];
                            int x485 = x484 == '\0';
                            if (x485) {
                              x490 = x483;
                            } else {
                              int x486 = x484 == 'o';
                              if (x486) {
                                x488 = 0/*false*/;
                                x489 = x484;
                                char  *x487 = x483+1;
                                x490 = x487;
                              } else {
                                x490 = x483;
                              }
                            }
                            int x502 = x488;
                            if (x502) {
                              char  *x503 = x490;
                              x463 = x503;
                            } else {
                              char x506 = x489;
                              char  *x507 = x490;
                              int x512 = 1/*true*/;
                              char x513 = '\0';
                              char  *x514 = 0/*null*/;
                              char x508 = x507[0];
                              int x509 = x508 == '\0';
                              if (x509) {
                                x514 = x507;
                              } else {
                                int x510 = x508 == 'n';
                                if (x510) {
                                  x512 = 0/*false*/;
                                  x513 = x508;
                                  char  *x511 = x507+1;
                                  x514 = x511;
                                } else {
                                  x514 = x507;
                                }
                              }
                              int x526 = x512;
                              if (x526) {
                                char  *x527 = x514;
                                x463 = x527;
                              } else {
                                char x530 = x513;
                                char  *x531 = x514;
                                int x536 = 1/*true*/;
                                char x537 = '\0';
                                char  *x538 = 0/*null*/;
                                char x532 = x531[0];
                                int x533 = x532 == '\0';
                                if (x533) {
                                  x538 = x531;
                                } else {
                                  int x534 = x532 == 't';
                                  if (x534) {
                                    x536 = 0/*false*/;
                                    x537 = x532;
                                    char  *x535 = x531+1;
                                    x538 = x535;
                                  } else {
                                    x538 = x531;
                                  }
                                }
                                int x550 = x536;
                                if (x550) {
                                  char  *x551 = x538;
                                  x463 = x551;
                                } else {
                                  char x554 = x537;
                                  char  *x555 = x538;
                                  int x560 = 1/*true*/;
                                  char x561 = '\0';
                                  char  *x562 = 0/*null*/;
                                  char x556 = x555[0];
                                  int x557 = x556 == '\0';
                                  if (x557) {
                                    x562 = x555;
                                  } else {
                                    int x558 = x556 == 'e';
                                    if (x558) {
                                      x560 = 0/*false*/;
                                      x561 = x556;
                                      char  *x559 = x555+1;
                                      x562 = x559;
                                    } else {
                                      x562 = x555;
                                    }
                                  }
                                  int x574 = x560;
                                  if (x574) {
                                    char  *x575 = x562;
                                    x463 = x575;
                                  } else {
                                    char x578 = x561;
                                    char  *x579 = x562;
                                    int x584 = 1/*true*/;
                                    char x585 = '\0';
                                    char  *x586 = 0/*null*/;
                                    char x580 = x579[0];
                                    int x581 = x580 == '\0';
                                    if (x581) {
                                      x586 = x579;
                                    } else {
                                      int x582 = x580 == 'n';
                                      if (x582) {
                                        x584 = 0/*false*/;
                                        x585 = x580;
                                        char  *x583 = x579+1;
                                        x586 = x583;
                                      } else {
                                        x586 = x579;
                                      }
                                    }
                                    int x598 = x584;
                                    if (x598) {
                                      char  *x599 = x586;
                                      x463 = x599;
                                    } else {
                                      char x602 = x585;
                                      char  *x603 = x586;
                                      int x608 = 1/*true*/;
                                      char x609 = '\0';
                                      char  *x610 = 0/*null*/;
                                      char x604 = x603[0];
                                      int x605 = x604 == '\0';
                                      if (x605) {
                                        x610 = x603;
                                      } else {
                                        int x606 = x604 == 't';
                                        if (x606) {
                                          x608 = 0/*false*/;
                                          x609 = x604;
                                          char  *x607 = x603+1;
                                          x610 = x607;
                                        } else {
                                          x610 = x603;
                                        }
                                      }
                                      int x622 = x608;
                                      if (x622) {
                                        char  *x623 = x610;
                                        x463 = x623;
                                      } else {
                                        char x626 = x609;
                                        char  *x627 = x610;
                                        int x632 = 1/*true*/;
                                        char x633 = '\0';
                                        char  *x634 = 0/*null*/;
                                        char x628 = x627[0];
                                        int x629 = x628 == '\0';
                                        if (x629) {
                                          x634 = x627;
                                        } else {
                                          int x630 = x628 == '-';
                                          if (x630) {
                                            x632 = 0/*false*/;
                                            x633 = x628;
                                            char  *x631 = x627+1;
                                            x634 = x631;
                                          } else {
                                            x634 = x627;
                                          }
                                        }
                                        int x646 = x632;
                                        if (x646) {
                                          char  *x647 = x634;
                                          x463 = x647;
                                        } else {
                                          char x650 = x633;
                                          char  *x651 = x634;
                                          int x656 = 1/*true*/;
                                          char x657 = '\0';
                                          char  *x658 = 0/*null*/;
                                          char x652 = x651[0];
                                          int x653 = x652 == '\0';
                                          if (x653) {
                                            x658 = x651;
                                          } else {
                                            int x654 = x652 == 'L';
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
                                            x463 = x671;
                                          } else {
                                            char x674 = x657;
                                            char  *x675 = x658;
                                            int x680 = 1/*true*/;
                                            char x681 = '\0';
                                            char  *x682 = 0/*null*/;
                                            char x676 = x675[0];
                                            int x677 = x676 == '\0';
                                            if (x677) {
                                              x682 = x675;
                                            } else {
                                              int x678 = x676 == 'e';
                                              if (x678) {
                                                x680 = 0/*false*/;
                                                x681 = x676;
                                                char  *x679 = x675+1;
                                                x682 = x679;
                                              } else {
                                                x682 = x675;
                                              }
                                            }
                                            int x694 = x680;
                                            if (x694) {
                                              char  *x695 = x682;
                                              x463 = x695;
                                            } else {
                                              char x698 = x681;
                                              char  *x699 = x682;
                                              int x704 = 1/*true*/;
                                              char x705 = '\0';
                                              char  *x706 = 0/*null*/;
                                              char x700 = x699[0];
                                              int x701 = x700 == '\0';
                                              if (x701) {
                                                x706 = x699;
                                              } else {
                                                int x702 = x700 == 'n';
                                                if (x702) {
                                                  x704 = 0/*false*/;
                                                  x705 = x700;
                                                  char  *x703 = x699+1;
                                                  x706 = x703;
                                                } else {
                                                  x706 = x699;
                                                }
                                              }
                                              int x718 = x704;
                                              if (x718) {
                                                char  *x719 = x706;
                                                x463 = x719;
                                              } else {
                                                char x722 = x705;
                                                char  *x723 = x706;
                                                int x728 = 1/*true*/;
                                                char x729 = '\0';
                                                char  *x730 = 0/*null*/;
                                                char x724 = x723[0];
                                                int x725 = x724 == '\0';
                                                if (x725) {
                                                  x730 = x723;
                                                } else {
                                                  int x726 = x724 == 'g';
                                                  if (x726) {
                                                    x728 = 0/*false*/;
                                                    x729 = x724;
                                                    char  *x727 = x723+1;
                                                    x730 = x727;
                                                  } else {
                                                    x730 = x723;
                                                  }
                                                }
                                                int x742 = x728;
                                                if (x742) {
                                                  char  *x743 = x730;
                                                  x463 = x743;
                                                } else {
                                                  char x746 = x729;
                                                  char  *x747 = x730;
                                                  int x752 = 1/*true*/;
                                                  char x753 = '\0';
                                                  char  *x754 = 0/*null*/;
                                                  char x748 = x747[0];
                                                  int x749 = x748 == '\0';
                                                  if (x749) {
                                                    x754 = x747;
                                                  } else {
                                                    int x750 = x748 == 't';
                                                    if (x750) {
                                                      x752 = 0/*false*/;
                                                      x753 = x748;
                                                      char  *x751 = x747+1;
                                                      x754 = x751;
                                                    } else {
                                                      x754 = x747;
                                                    }
                                                  }
                                                  int x766 = x752;
                                                  if (x766) {
                                                    char  *x767 = x754;
                                                    x463 = x767;
                                                  } else {
                                                    char x770 = x753;
                                                    char  *x771 = x754;
                                                    int x776 = 1/*true*/;
                                                    char x777 = '\0';
                                                    char  *x778 = 0/*null*/;
                                                    char x772 = x771[0];
                                                    int x773 = x772 == '\0';
                                                    if (x773) {
                                                      x778 = x771;
                                                    } else {
                                                      int x774 = x772 == 'h';
                                                      if (x774) {
                                                        x776 = 0/*false*/;
                                                        x777 = x772;
                                                        char  *x775 = x771+1;
                                                        x778 = x775;
                                                      } else {
                                                        x778 = x771;
                                                      }
                                                    }
                                                    int x790 = x776;
                                                    if (x790) {
                                                      char  *x791 = x778;
                                                      x463 = x791;
                                                    } else {
                                                      char x794 = x777;
                                                      char  *x795 = x778;
                                                      x461 = 0/*false*/;
                                                      x462 = 1;
                                                      x463 = x795;
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
                          int x827 = x461;
                          if (x827) {
                            char  *x828 = x456;
                            int x829 = 1/*true*/;
                            /*@
                            loop invariant ((strlen(x828)>=0) && \valid(x828+(0..strlen(x828))));
                            loop assigns x828, x829;
                            */
                            for (;;) {
                              int x831 = x829;
                              if (!x831) break;
                              char  *x833 = x828;
                              int x844 = 1/*true*/;
                              char x845 = '\0';
                              char  *x846 = 0/*null*/;
                              char x834 = x833[0];
                              int x835 = x834 == '\0';
                              if (x835) {
                                x846 = x833;
                              } else {
                                int x836 = x834 >= 'a';
                                int x838;
                                if (x836) {
                                  int x837 = x834 <= 'z';
                                  x838 = x837;
                                } else {
                                  x838 = 0/*false*/;
                                }
                                int x839 = x834 >= 'A';
                                int x841;
                                if (x839) {
                                  int x840 = x834 <= 'Z';
                                  x841 = x840;
                                } else {
                                  x841 = 0/*false*/;
                                }
                                int x842 = x838 || x841;
                                if (x842) {
                                  x844 = 0/*false*/;
                                  x845 = x834;
                                  char  *x843 = x833+1;
                                  x846 = x843;
                                } else {
                                  x846 = x833;
                                }
                              }
                              int x858 = x844;
                              char x860 = x845;
                              char  *x861 = x846;
                              if (x858) {
                                if (x835) {
                                  x829 = 0/*false*/;
                                } else {
                                  int x859 = x834 == '-';
                                  if (x859) {
                                    char  *x843 = x833+1;
                                    x828 = x843;
                                  } else {
                                    x829 = 0/*false*/;
                                  }
                                }
                              } else {
                                x828 = x861;
                              }
                            }
                            char  *x896 = x828;
                            char  *x897 = x896;
                            int x898 = 1/*true*/;
                            /*@
                            loop invariant ((strlen(x897)>=0) && \valid(x897+(0..strlen(x897))));
                            loop assigns x897, x898;
                            */
                            for (;;) {
                              int x900 = x898;
                              if (!x900) break;
                              char  *x902 = x897;
                              char x903 = x902[0];
                              int x904 = x903 == '\0';
                              if (x904) {
                                x898 = 0/*false*/;
                              } else {
                                int x905 = x903 == ' ';
                                if (x905) {
                                  char  *x906 = x902+1;
                                  x897 = x906;
                                } else {
                                  x898 = 0/*false*/;
                                }
                              }
                            }
                            char  *x935 = x897;
                            int x940 = 1/*true*/;
                            char x941 = '\0';
                            char  *x942 = 0/*null*/;
                            char x936 = x935[0];
                            int x937 = x936 == '\0';
                            if (x937) {
                              x942 = x935;
                            } else {
                              int x938 = x936 == ':';
                              if (x938) {
                                x940 = 0/*false*/;
                                x941 = x936;
                                char  *x939 = x935+1;
                                x942 = x939;
                              } else {
                                x942 = x935;
                              }
                            }
                            int x954 = x940;
                            if (x954) {
                              char  *x955 = x942;
                              x452 = 0/*false*/;
                            } else {
                              char x958 = x941;
                              char  *x959 = x942;
                              char  *x960 = x959;
                              int x961 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x960)>=0) && \valid(x960+(0..strlen(x960))));
                              loop assigns x960, x961;
                              */
                              for (;;) {
                                int x963 = x961;
                                if (!x963) break;
                                char  *x965 = x960;
                                char x966 = x965[0];
                                int x967 = x966 == '\0';
                                if (x967) {
                                  x961 = 0/*false*/;
                                } else {
                                  int x968 = x966 == ' ';
                                  if (x968) {
                                    char  *x969 = x965+1;
                                    x960 = x969;
                                  } else {
                                    x961 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x998 = x960;
                              char  *x1006 = x998;
                              int x1007 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x1006)>=0) && \valid(x1006+(0..strlen(x1006))));
                              loop assigns x1006, x1007;
                              */
                              for (;;) {
                                int x1009 = x1007;
                                if (!x1009) break;
                                char  *x1011 = x1006;
                                char x1012 = x1011[0];
                                int x1013 = x1012 == '\0';
                                if (x1013) {
                                  x1007 = 0/*false*/;
                                } else {
                                  int x1014 = x1012 != '\n';
                                  if (x1014) {
                                    char  *x1015 = x1011+1;
                                    x1006 = x1015;
                                  } else {
                                    x1007 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x1044 = x1006;
                              if (x999) {
                                int x1045 = 1/*true*/;
                                char x1046 = '\0';
                                char  *x1047 = 0/*null*/;
                                char x1000 = x998[0];
                                int x1001 = x1000 == '\0';
                                if (x1001) {
                                  x1047 = x998;
                                } else {
                                  int x1002 = x1000 >= '0';
                                  int x1004;
                                  if (x1002) {
                                    int x1003 = x1000 <= '9';
                                    x1004 = x1003;
                                  } else {
                                    x1004 = 0/*false*/;
                                  }
                                  if (x1004) {
                                    x1045 = 0/*false*/;
                                    x1046 = x1000;
                                    char  *x1005 = x998+1;
                                    x1047 = x1005;
                                  } else {
                                    x1047 = x998;
                                  }
                                }
                                int x1059 = x1045;
                                if (x1059) {
                                  char  *x1060 = x1047;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1063 = x1046;
                                  char  *x1065 = x1047;
                                  char  *x1066 = x1065;
                                  int x1067 = 1/*true*/;
                                  char x1064 = x1063 - '0';
                                  int x1068 = x1064;
                                  /*@
                                  loop invariant (((strlen(x1066)>=0) && \valid(x1066+(0..strlen(x1066)))) && ((x1068==-1) || (0<=x1068)));
                                  loop assigns x1066, x1067, x1068;
                                  */
                                  for (;;) {
                                    int x1069 = x1067;
                                    if (!x1069) break;
                                    char  *x1071 = x1066;
                                    int x1078 = 1/*true*/;
                                    char x1079 = '\0';
                                    char  *x1080 = 0/*null*/;
                                    char x1072 = x1071[0];
                                    int x1073 = x1072 == '\0';
                                    if (x1073) {
                                      x1080 = x1071;
                                    } else {
                                      int x1074 = x1072 >= '0';
                                      int x1076;
                                      if (x1074) {
                                        int x1075 = x1072 <= '9';
                                        x1076 = x1075;
                                      } else {
                                        x1076 = 0/*false*/;
                                      }
                                      if (x1076) {
                                        x1078 = 0/*false*/;
                                        x1079 = x1072;
                                        char  *x1077 = x1071+1;
                                        x1080 = x1077;
                                      } else {
                                        x1080 = x1071;
                                      }
                                    }
                                    int x1092 = x1078;
                                    if (x1092) {
                                      char  *x1093 = x1080;
                                      x1067 = 0/*false*/;
                                    } else {
                                      char x1096 = x1079;
                                      char  *x1098 = x1080;
                                      int x1099 = x1068;
                                      int x1100 = x1099 < 0;
                                      int x1105;
                                      if (x1100) {
                                        x1105 = x1099;
                                      } else {
                                        int x1101 = x1099 > x356;
                                        int x1104;
                                        if (x1101) {
                                          x1104 = -1;
                                        } else {
                                          char x1097 = x1096 - '0';
                                          int x1102 = x1099 * 10;
                                          int x1103 = x1102 + x1097;
                                          x1104 = x1103;
                                        }
                                        x1105 = x1104;
                                      }
                                      x1068 = x1105;
                                      x1066 = x1098;
                                    }
                                  }
                                  int x1131 = x1068;
                                  char  *x1132 = x1066;
                                  char  *x1133 = x1132;
                                  int x1134 = 1/*true*/;
                                  /*@
                                  loop invariant ((strlen(x1133)>=0) && \valid(x1133+(0..strlen(x1133))));
                                  loop assigns x1133, x1134;
                                  */
                                  for (;;) {
                                    int x1136 = x1134;
                                    if (!x1136) break;
                                    char  *x1138 = x1133;
                                    char x1139 = x1138[0];
                                    int x1140 = x1139 == '\0';
                                    if (x1140) {
                                      x1134 = 0/*false*/;
                                    } else {
                                      int x1141 = x1139 == ' ';
                                      if (x1141) {
                                        char  *x1142 = x1138+1;
                                        x1133 = x1142;
                                      } else {
                                        x1134 = 0/*false*/;
                                      }
                                    }
                                  }
                                  char  *x1171 = x1133;
                                  int x1176 = 1/*true*/;
                                  char x1177 = '\0';
                                  char  *x1178 = 0/*null*/;
                                  char x1172 = x1171[0];
                                  int x1173 = x1172 == '\0';
                                  if (x1173) {
                                    x1178 = x1171;
                                  } else {
                                    int x1174 = x1172 == '\n';
                                    if (x1174) {
                                      x1176 = 0/*false*/;
                                      x1177 = x1172;
                                      char  *x1175 = x1171+1;
                                      x1178 = x1175;
                                    } else {
                                      x1178 = x1171;
                                    }
                                  }
                                  int x1190 = x1176;
                                  if (x1190) {
                                    char  *x1191 = x1178;
                                    x452 = 0/*false*/;
                                  } else {
                                    char x1194 = x1177;
                                    char  *x1195 = x1178;
                                    int x1196 = x453;
                                    int x1197 = x1131 == -2;
                                    int x1198;
                                    if (x1197) {
                                      x1198 = x1196;
                                    } else {
                                      x1198 = x1131;
                                    }
                                    x453 = x1198;
                                    x451 = x1195;
                                  }
                                }
                              } else {
                                int x1210 = 1/*true*/;
                                char x1211 = '\0';
                                char  *x1212 = 0/*null*/;
                                char x1206 = x1044[0];
                                int x1207 = x1206 == '\0';
                                if (x1207) {
                                  x1212 = x1044;
                                } else {
                                  int x1208 = x1206 == '\n';
                                  if (x1208) {
                                    x1210 = 0/*false*/;
                                    x1211 = x1206;
                                    char  *x1209 = x1044+1;
                                    x1212 = x1209;
                                  } else {
                                    x1212 = x1044;
                                  }
                                }
                                int x1224 = x1210;
                                if (x1224) {
                                  char  *x1225 = x1212;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1228 = x1211;
                                  char  *x1229 = x1212;
                                  int x1230 = x453;
                                  int x1232;
                                  if (x1231) {
                                    x1232 = x1230;
                                  } else {
                                    x1232 = -2;
                                  }
                                  x453 = x1232;
                                  x451 = x1229;
                                }
                              }
                            }
                          } else {
                            int x1242 = x462;
                            char  *x1243 = x463;
                            char  *x1244 = x1243;
                            int x1245 = 1/*true*/;
                            /*@
                            loop invariant ((strlen(x1244)>=0) && \valid(x1244+(0..strlen(x1244))));
                            loop assigns x1244, x1245;
                            */
                            for (;;) {
                              int x1247 = x1245;
                              if (!x1247) break;
                              char  *x1249 = x1244;
                              char x1250 = x1249[0];
                              int x1251 = x1250 == '\0';
                              if (x1251) {
                                x1245 = 0/*false*/;
                              } else {
                                int x1252 = x1250 == ' ';
                                if (x1252) {
                                  char  *x1253 = x1249+1;
                                  x1244 = x1253;
                                } else {
                                  x1245 = 0/*false*/;
                                }
                              }
                            }
                            char  *x1282 = x1244;
                            int x1287 = 1/*true*/;
                            char x1288 = '\0';
                            char  *x1289 = 0/*null*/;
                            char x1283 = x1282[0];
                            int x1284 = x1283 == '\0';
                            if (x1284) {
                              x1289 = x1282;
                            } else {
                              int x1285 = x1283 == ':';
                              if (x1285) {
                                x1287 = 0/*false*/;
                                x1288 = x1283;
                                char  *x1286 = x1282+1;
                                x1289 = x1286;
                              } else {
                                x1289 = x1282;
                              }
                            }
                            int x1301 = x1287;
                            if (x1301) {
                              char  *x1302 = x1289;
                              x452 = 0/*false*/;
                            } else {
                              char x1305 = x1288;
                              char  *x1306 = x1289;
                              char  *x1307 = x1306;
                              int x1308 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x1307)>=0) && \valid(x1307+(0..strlen(x1307))));
                              loop assigns x1307, x1308;
                              */
                              for (;;) {
                                int x1310 = x1308;
                                if (!x1310) break;
                                char  *x1312 = x1307;
                                char x1313 = x1312[0];
                                int x1314 = x1313 == '\0';
                                if (x1314) {
                                  x1308 = 0/*false*/;
                                } else {
                                  int x1315 = x1313 == ' ';
                                  if (x1315) {
                                    char  *x1316 = x1312+1;
                                    x1307 = x1316;
                                  } else {
                                    x1308 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x1345 = x1307;
                              char  *x1353 = x1345;
                              int x1354 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x1353)>=0) && \valid(x1353+(0..strlen(x1353))));
                              loop assigns x1353, x1354;
                              */
                              for (;;) {
                                int x1356 = x1354;
                                if (!x1356) break;
                                char  *x1358 = x1353;
                                char x1359 = x1358[0];
                                int x1360 = x1359 == '\0';
                                if (x1360) {
                                  x1354 = 0/*false*/;
                                } else {
                                  int x1361 = x1359 != '\n';
                                  if (x1361) {
                                    char  *x1362 = x1358+1;
                                    x1353 = x1362;
                                  } else {
                                    x1354 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x1391 = x1353;
                              int x1346 = x1242 == 1;
                              if (x1346) {
                                int x1392 = 1/*true*/;
                                char x1393 = '\0';
                                char  *x1394 = 0/*null*/;
                                char x1347 = x1345[0];
                                int x1348 = x1347 == '\0';
                                if (x1348) {
                                  x1394 = x1345;
                                } else {
                                  int x1349 = x1347 >= '0';
                                  int x1351;
                                  if (x1349) {
                                    int x1350 = x1347 <= '9';
                                    x1351 = x1350;
                                  } else {
                                    x1351 = 0/*false*/;
                                  }
                                  if (x1351) {
                                    x1392 = 0/*false*/;
                                    x1393 = x1347;
                                    char  *x1352 = x1345+1;
                                    x1394 = x1352;
                                  } else {
                                    x1394 = x1345;
                                  }
                                }
                                int x1406 = x1392;
                                if (x1406) {
                                  char  *x1407 = x1394;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1410 = x1393;
                                  char  *x1412 = x1394;
                                  char  *x1413 = x1412;
                                  int x1414 = 1/*true*/;
                                  char x1411 = x1410 - '0';
                                  int x1415 = x1411;
                                  /*@
                                  loop invariant (((strlen(x1413)>=0) && \valid(x1413+(0..strlen(x1413)))) && ((x1415==-1) || (0<=x1415)));
                                  loop assigns x1413, x1414, x1415;
                                  */
                                  for (;;) {
                                    int x1416 = x1414;
                                    if (!x1416) break;
                                    char  *x1418 = x1413;
                                    int x1425 = 1/*true*/;
                                    char x1426 = '\0';
                                    char  *x1427 = 0/*null*/;
                                    char x1419 = x1418[0];
                                    int x1420 = x1419 == '\0';
                                    if (x1420) {
                                      x1427 = x1418;
                                    } else {
                                      int x1421 = x1419 >= '0';
                                      int x1423;
                                      if (x1421) {
                                        int x1422 = x1419 <= '9';
                                        x1423 = x1422;
                                      } else {
                                        x1423 = 0/*false*/;
                                      }
                                      if (x1423) {
                                        x1425 = 0/*false*/;
                                        x1426 = x1419;
                                        char  *x1424 = x1418+1;
                                        x1427 = x1424;
                                      } else {
                                        x1427 = x1418;
                                      }
                                    }
                                    int x1439 = x1425;
                                    if (x1439) {
                                      char  *x1440 = x1427;
                                      x1414 = 0/*false*/;
                                    } else {
                                      char x1443 = x1426;
                                      char  *x1445 = x1427;
                                      int x1446 = x1415;
                                      int x1447 = x1446 < 0;
                                      int x1452;
                                      if (x1447) {
                                        x1452 = x1446;
                                      } else {
                                        int x1448 = x1446 > x356;
                                        int x1451;
                                        if (x1448) {
                                          x1451 = -1;
                                        } else {
                                          char x1444 = x1443 - '0';
                                          int x1449 = x1446 * 10;
                                          int x1450 = x1449 + x1444;
                                          x1451 = x1450;
                                        }
                                        x1452 = x1451;
                                      }
                                      x1415 = x1452;
                                      x1413 = x1445;
                                    }
                                  }
                                  int x1478 = x1415;
                                  char  *x1479 = x1413;
                                  char  *x1480 = x1479;
                                  int x1481 = 1/*true*/;
                                  /*@
                                  loop invariant ((strlen(x1480)>=0) && \valid(x1480+(0..strlen(x1480))));
                                  loop assigns x1480, x1481;
                                  */
                                  for (;;) {
                                    int x1483 = x1481;
                                    if (!x1483) break;
                                    char  *x1485 = x1480;
                                    char x1486 = x1485[0];
                                    int x1487 = x1486 == '\0';
                                    if (x1487) {
                                      x1481 = 0/*false*/;
                                    } else {
                                      int x1488 = x1486 == ' ';
                                      if (x1488) {
                                        char  *x1489 = x1485+1;
                                        x1480 = x1489;
                                      } else {
                                        x1481 = 0/*false*/;
                                      }
                                    }
                                  }
                                  char  *x1518 = x1480;
                                  int x1523 = 1/*true*/;
                                  char x1524 = '\0';
                                  char  *x1525 = 0/*null*/;
                                  char x1519 = x1518[0];
                                  int x1520 = x1519 == '\0';
                                  if (x1520) {
                                    x1525 = x1518;
                                  } else {
                                    int x1521 = x1519 == '\n';
                                    if (x1521) {
                                      x1523 = 0/*false*/;
                                      x1524 = x1519;
                                      char  *x1522 = x1518+1;
                                      x1525 = x1522;
                                    } else {
                                      x1525 = x1518;
                                    }
                                  }
                                  int x1537 = x1523;
                                  if (x1537) {
                                    char  *x1538 = x1525;
                                    x452 = 0/*false*/;
                                  } else {
                                    char x1541 = x1524;
                                    char  *x1542 = x1525;
                                    int x1543 = x453;
                                    int x1544 = x1478 == -2;
                                    int x1545;
                                    if (x1544) {
                                      x1545 = x1543;
                                    } else {
                                      x1545 = x1478;
                                    }
                                    x453 = x1545;
                                    x451 = x1542;
                                  }
                                }
                              } else {
                                int x1557 = 1/*true*/;
                                char x1558 = '\0';
                                char  *x1559 = 0/*null*/;
                                char x1553 = x1391[0];
                                int x1554 = x1553 == '\0';
                                if (x1554) {
                                  x1559 = x1391;
                                } else {
                                  int x1555 = x1553 == '\n';
                                  if (x1555) {
                                    x1557 = 0/*false*/;
                                    x1558 = x1553;
                                    char  *x1556 = x1391+1;
                                    x1559 = x1556;
                                  } else {
                                    x1559 = x1391;
                                  }
                                }
                                int x1571 = x1557;
                                if (x1571) {
                                  char  *x1572 = x1559;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1575 = x1558;
                                  char  *x1576 = x1559;
                                  int x1577 = x453;
                                  int x1578;
                                  if (x1231) {
                                    x1578 = x1577;
                                  } else {
                                    x1578 = -2;
                                  }
                                  x453 = x1578;
                                  x451 = x1576;
                                }
                              }
                            }
                          }
                        }
                        int x1605 = x453;
                        char  *x1606 = x451;
                        int x1611 = 1/*true*/;
                        char x1612 = '\0';
                        char  *x1613 = 0/*null*/;
                        char x1607 = x1606[0];
                        int x1608 = x1607 == '\0';
                        if (x1608) {
                          x1613 = x1606;
                        } else {
                          int x1609 = x1607 == '\n';
                          if (x1609) {
                            x1611 = 0/*false*/;
                            x1612 = x1607;
                            char  *x1610 = x1606+1;
                            x1613 = x1610;
                          } else {
                            x1613 = x1606;
                          }
                        }
                        int x1625 = x1611;
                        if (x1625) {
                          char  *x1626 = x1613;
                        } else {
                          char x1628 = x1612;
                          char  *x1629 = x1613;
                          int x1631 = 1/*true*/;
                          char  *x1632 = x1629;
                          /*@
                          loop invariant ((0<=x1634) && ((strlen(x1632)>=0) && \valid(x1632+(0..strlen(x1632)))));
                          loop assigns x1634, x1631, x1632;
                          loop variant (x453-x1634);
                          */
                          for(int x1634=0; x1634 < x1605; x1634++) {
                            int x1635 = x1631;
                            if (x1635) {
                              char  *x1636 = x1632;
                              char x1637 = x1636[0];
                              int x1638 = x1637 == '\0';
                              if (x1638) {
                                x1631 = 0/*false*/;
                              } else {
                                if (1/*true*/) {
                                  char  *x1639 = x1636+1;
                                  x1632 = x1639;
                                } else {
                                  x1631 = 0/*false*/;
                                }
                              }
                            } else {
                            }
                          }
                          int x1669 = x1631;
                          char  *x1670 = x1632;
                          int x1630 = x1605 < 0;
                          if (x1630) {
                          } else {
                            int x1671 = 1/*true*/;
                            char  *x1673 = 0/*null*/;
                            if (x1669) {
                              x1671 = 0/*false*/;
                              x1673 = x1670;
                            } else {
                              x1673 = x1629;
                            }
                            int x1681 = x1671;
                            if (x1681) {
                              char  *x1682 = x1673;
                            } else {
                              char  *x1685 = x1673;
                              int x1690 = 1/*true*/;
                              char x1691 = '\0';
                              char  *x1692 = 0/*null*/;
                              char x1686 = x1685[0];
                              int x1687 = x1686 == '\0';
                              if (x1687) {
                                x1692 = x1685;
                              } else {
                                int x1688 = x1686 == '\n';
                                if (x1688) {
                                  x1690 = 0/*false*/;
                                  x1691 = x1686;
                                  char  *x1689 = x1685+1;
                                  x1692 = x1689;
                                } else {
                                  x1692 = x1685;
                                }
                              }
                              int x1704 = x1690;
                              if (x1704) {
                                char  *x1705 = x1692;
                              } else {
                                char x1707 = x1691;
                                char  *x1708 = x1692;
                                char x1709 = x1708[0];
                                int x1710 = x1709 == '\0';
                                if (x1710) {
                                  x2 = x1605;
                                } else {
                                }
                              }
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
  int x1744 = x2;
  return x1744;
}
