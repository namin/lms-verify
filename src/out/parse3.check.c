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
                        int x981 = 0 == 1;
                        int x1213 = -2 == -2;
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
                          } else {
                            char x481 = x465;
                            char  *x482 = x466;
                            int x487 = 1/*true*/;
                            char x488 = '\0';
                            char  *x489 = 0/*null*/;
                            char x483 = x482[0];
                            int x484 = x483 == '\0';
                            if (x484) {
                              x489 = x482;
                            } else {
                              int x485 = x483 == 'o';
                              if (x485) {
                                x487 = 0/*false*/;
                                x488 = x483;
                                char  *x486 = x482+1;
                                x489 = x486;
                              } else {
                                x489 = x482;
                              }
                            }
                            int x501 = x487;
                            if (x501) {
                              char  *x502 = x489;
                            } else {
                              char x504 = x488;
                              char  *x505 = x489;
                              int x510 = 1/*true*/;
                              char x511 = '\0';
                              char  *x512 = 0/*null*/;
                              char x506 = x505[0];
                              int x507 = x506 == '\0';
                              if (x507) {
                                x512 = x505;
                              } else {
                                int x508 = x506 == 'n';
                                if (x508) {
                                  x510 = 0/*false*/;
                                  x511 = x506;
                                  char  *x509 = x505+1;
                                  x512 = x509;
                                } else {
                                  x512 = x505;
                                }
                              }
                              int x524 = x510;
                              if (x524) {
                                char  *x525 = x512;
                              } else {
                                char x527 = x511;
                                char  *x528 = x512;
                                int x533 = 1/*true*/;
                                char x534 = '\0';
                                char  *x535 = 0/*null*/;
                                char x529 = x528[0];
                                int x530 = x529 == '\0';
                                if (x530) {
                                  x535 = x528;
                                } else {
                                  int x531 = x529 == 't';
                                  if (x531) {
                                    x533 = 0/*false*/;
                                    x534 = x529;
                                    char  *x532 = x528+1;
                                    x535 = x532;
                                  } else {
                                    x535 = x528;
                                  }
                                }
                                int x547 = x533;
                                if (x547) {
                                  char  *x548 = x535;
                                } else {
                                  char x550 = x534;
                                  char  *x551 = x535;
                                  int x556 = 1/*true*/;
                                  char x557 = '\0';
                                  char  *x558 = 0/*null*/;
                                  char x552 = x551[0];
                                  int x553 = x552 == '\0';
                                  if (x553) {
                                    x558 = x551;
                                  } else {
                                    int x554 = x552 == 'e';
                                    if (x554) {
                                      x556 = 0/*false*/;
                                      x557 = x552;
                                      char  *x555 = x551+1;
                                      x558 = x555;
                                    } else {
                                      x558 = x551;
                                    }
                                  }
                                  int x570 = x556;
                                  if (x570) {
                                    char  *x571 = x558;
                                  } else {
                                    char x573 = x557;
                                    char  *x574 = x558;
                                    int x579 = 1/*true*/;
                                    char x580 = '\0';
                                    char  *x581 = 0/*null*/;
                                    char x575 = x574[0];
                                    int x576 = x575 == '\0';
                                    if (x576) {
                                      x581 = x574;
                                    } else {
                                      int x577 = x575 == 'n';
                                      if (x577) {
                                        x579 = 0/*false*/;
                                        x580 = x575;
                                        char  *x578 = x574+1;
                                        x581 = x578;
                                      } else {
                                        x581 = x574;
                                      }
                                    }
                                    int x593 = x579;
                                    if (x593) {
                                      char  *x594 = x581;
                                    } else {
                                      char x596 = x580;
                                      char  *x597 = x581;
                                      int x602 = 1/*true*/;
                                      char x603 = '\0';
                                      char  *x604 = 0/*null*/;
                                      char x598 = x597[0];
                                      int x599 = x598 == '\0';
                                      if (x599) {
                                        x604 = x597;
                                      } else {
                                        int x600 = x598 == 't';
                                        if (x600) {
                                          x602 = 0/*false*/;
                                          x603 = x598;
                                          char  *x601 = x597+1;
                                          x604 = x601;
                                        } else {
                                          x604 = x597;
                                        }
                                      }
                                      int x616 = x602;
                                      if (x616) {
                                        char  *x617 = x604;
                                      } else {
                                        char x619 = x603;
                                        char  *x620 = x604;
                                        int x625 = 1/*true*/;
                                        char x626 = '\0';
                                        char  *x627 = 0/*null*/;
                                        char x621 = x620[0];
                                        int x622 = x621 == '\0';
                                        if (x622) {
                                          x627 = x620;
                                        } else {
                                          int x623 = x621 == '-';
                                          if (x623) {
                                            x625 = 0/*false*/;
                                            x626 = x621;
                                            char  *x624 = x620+1;
                                            x627 = x624;
                                          } else {
                                            x627 = x620;
                                          }
                                        }
                                        int x639 = x625;
                                        if (x639) {
                                          char  *x640 = x627;
                                        } else {
                                          char x642 = x626;
                                          char  *x643 = x627;
                                          int x648 = 1/*true*/;
                                          char x649 = '\0';
                                          char  *x650 = 0/*null*/;
                                          char x644 = x643[0];
                                          int x645 = x644 == '\0';
                                          if (x645) {
                                            x650 = x643;
                                          } else {
                                            int x646 = x644 == 'L';
                                            if (x646) {
                                              x648 = 0/*false*/;
                                              x649 = x644;
                                              char  *x647 = x643+1;
                                              x650 = x647;
                                            } else {
                                              x650 = x643;
                                            }
                                          }
                                          int x662 = x648;
                                          if (x662) {
                                            char  *x663 = x650;
                                          } else {
                                            char x665 = x649;
                                            char  *x666 = x650;
                                            int x671 = 1/*true*/;
                                            char x672 = '\0';
                                            char  *x673 = 0/*null*/;
                                            char x667 = x666[0];
                                            int x668 = x667 == '\0';
                                            if (x668) {
                                              x673 = x666;
                                            } else {
                                              int x669 = x667 == 'e';
                                              if (x669) {
                                                x671 = 0/*false*/;
                                                x672 = x667;
                                                char  *x670 = x666+1;
                                                x673 = x670;
                                              } else {
                                                x673 = x666;
                                              }
                                            }
                                            int x685 = x671;
                                            if (x685) {
                                              char  *x686 = x673;
                                            } else {
                                              char x688 = x672;
                                              char  *x689 = x673;
                                              int x694 = 1/*true*/;
                                              char x695 = '\0';
                                              char  *x696 = 0/*null*/;
                                              char x690 = x689[0];
                                              int x691 = x690 == '\0';
                                              if (x691) {
                                                x696 = x689;
                                              } else {
                                                int x692 = x690 == 'n';
                                                if (x692) {
                                                  x694 = 0/*false*/;
                                                  x695 = x690;
                                                  char  *x693 = x689+1;
                                                  x696 = x693;
                                                } else {
                                                  x696 = x689;
                                                }
                                              }
                                              int x708 = x694;
                                              if (x708) {
                                                char  *x709 = x696;
                                              } else {
                                                char x711 = x695;
                                                char  *x712 = x696;
                                                int x717 = 1/*true*/;
                                                char x718 = '\0';
                                                char  *x719 = 0/*null*/;
                                                char x713 = x712[0];
                                                int x714 = x713 == '\0';
                                                if (x714) {
                                                  x719 = x712;
                                                } else {
                                                  int x715 = x713 == 'g';
                                                  if (x715) {
                                                    x717 = 0/*false*/;
                                                    x718 = x713;
                                                    char  *x716 = x712+1;
                                                    x719 = x716;
                                                  } else {
                                                    x719 = x712;
                                                  }
                                                }
                                                int x731 = x717;
                                                if (x731) {
                                                  char  *x732 = x719;
                                                } else {
                                                  char x734 = x718;
                                                  char  *x735 = x719;
                                                  int x740 = 1/*true*/;
                                                  char x741 = '\0';
                                                  char  *x742 = 0/*null*/;
                                                  char x736 = x735[0];
                                                  int x737 = x736 == '\0';
                                                  if (x737) {
                                                    x742 = x735;
                                                  } else {
                                                    int x738 = x736 == 't';
                                                    if (x738) {
                                                      x740 = 0/*false*/;
                                                      x741 = x736;
                                                      char  *x739 = x735+1;
                                                      x742 = x739;
                                                    } else {
                                                      x742 = x735;
                                                    }
                                                  }
                                                  int x754 = x740;
                                                  if (x754) {
                                                    char  *x755 = x742;
                                                  } else {
                                                    char x757 = x741;
                                                    char  *x758 = x742;
                                                    int x763 = 1/*true*/;
                                                    char x764 = '\0';
                                                    char  *x765 = 0/*null*/;
                                                    char x759 = x758[0];
                                                    int x760 = x759 == '\0';
                                                    if (x760) {
                                                      x765 = x758;
                                                    } else {
                                                      int x761 = x759 == 'h';
                                                      if (x761) {
                                                        x763 = 0/*false*/;
                                                        x764 = x759;
                                                        char  *x762 = x758+1;
                                                        x765 = x762;
                                                      } else {
                                                        x765 = x758;
                                                      }
                                                    }
                                                    int x777 = x763;
                                                    if (x777) {
                                                      char  *x778 = x765;
                                                    } else {
                                                      char x780 = x764;
                                                      char  *x781 = x765;
                                                      x461 = 0/*false*/;
                                                      x462 = 1;
                                                      x463 = x781;
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
                          int x813 = x461;
                          if (x813) {
                            char  *x814 = x456;
                            int x815 = 1/*true*/;
                            /*@
                            loop invariant ((strlen(x814)>=0) && \valid(x814+(0..strlen(x814))));
                            loop assigns x814, x815;
                            */
                            for (;;) {
                              int x817 = x815;
                              if (!x817) break;
                              char  *x819 = x814;
                              int x830 = 1/*true*/;
                              char x831 = '\0';
                              char  *x832 = 0/*null*/;
                              char x820 = x819[0];
                              int x821 = x820 == '\0';
                              if (x821) {
                              } else {
                                int x822 = x820 >= 'a';
                                int x824;
                                if (x822) {
                                  int x823 = x820 <= 'z';
                                  x824 = x823;
                                } else {
                                  x824 = 0/*false*/;
                                }
                                int x825 = x820 >= 'A';
                                int x827;
                                if (x825) {
                                  int x826 = x820 <= 'Z';
                                  x827 = x826;
                                } else {
                                  x827 = 0/*false*/;
                                }
                                int x828 = x824 || x827;
                                if (x828) {
                                  x830 = 0/*false*/;
                                  x831 = x820;
                                  char  *x829 = x819+1;
                                  x832 = x829;
                                } else {
                                }
                              }
                              int x840 = x830;
                              char x842 = x831;
                              char  *x843 = x832;
                              if (x840) {
                                if (x821) {
                                  x815 = 0/*false*/;
                                } else {
                                  int x841 = x820 == '-';
                                  if (x841) {
                                    char  *x829 = x819+1;
                                    x814 = x829;
                                  } else {
                                    x815 = 0/*false*/;
                                  }
                                }
                              } else {
                                x814 = x843;
                              }
                            }
                            char  *x878 = x814;
                            char  *x879 = x878;
                            int x880 = 1/*true*/;
                            /*@
                            loop invariant ((strlen(x879)>=0) && \valid(x879+(0..strlen(x879))));
                            loop assigns x879, x880;
                            */
                            for (;;) {
                              int x882 = x880;
                              if (!x882) break;
                              char  *x884 = x879;
                              char x885 = x884[0];
                              int x886 = x885 == '\0';
                              if (x886) {
                                x880 = 0/*false*/;
                              } else {
                                int x887 = x885 == ' ';
                                if (x887) {
                                  char  *x888 = x884+1;
                                  x879 = x888;
                                } else {
                                  x880 = 0/*false*/;
                                }
                              }
                            }
                            char  *x917 = x879;
                            int x922 = 1/*true*/;
                            char x923 = '\0';
                            char  *x924 = 0/*null*/;
                            char x918 = x917[0];
                            int x919 = x918 == '\0';
                            if (x919) {
                              x924 = x917;
                            } else {
                              int x920 = x918 == ':';
                              if (x920) {
                                x922 = 0/*false*/;
                                x923 = x918;
                                char  *x921 = x917+1;
                                x924 = x921;
                              } else {
                                x924 = x917;
                              }
                            }
                            int x936 = x922;
                            if (x936) {
                              char  *x937 = x924;
                              x452 = 0/*false*/;
                            } else {
                              char x940 = x923;
                              char  *x941 = x924;
                              char  *x942 = x941;
                              int x943 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x942)>=0) && \valid(x942+(0..strlen(x942))));
                              loop assigns x942, x943;
                              */
                              for (;;) {
                                int x945 = x943;
                                if (!x945) break;
                                char  *x947 = x942;
                                char x948 = x947[0];
                                int x949 = x948 == '\0';
                                if (x949) {
                                  x943 = 0/*false*/;
                                } else {
                                  int x950 = x948 == ' ';
                                  if (x950) {
                                    char  *x951 = x947+1;
                                    x942 = x951;
                                  } else {
                                    x943 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x980 = x942;
                              char  *x988 = x980;
                              int x989 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x988)>=0) && \valid(x988+(0..strlen(x988))));
                              loop assigns x988, x989;
                              */
                              for (;;) {
                                int x991 = x989;
                                if (!x991) break;
                                char  *x993 = x988;
                                char x994 = x993[0];
                                int x995 = x994 == '\0';
                                if (x995) {
                                  x989 = 0/*false*/;
                                } else {
                                  int x996 = x994 != '\n';
                                  if (x996) {
                                    char  *x997 = x993+1;
                                    x988 = x997;
                                  } else {
                                    x989 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x1026 = x988;
                              if (x981) {
                                int x1027 = 1/*true*/;
                                char x1028 = '\0';
                                char  *x1029 = 0/*null*/;
                                char x982 = x980[0];
                                int x983 = x982 == '\0';
                                if (x983) {
                                  x1029 = x980;
                                } else {
                                  int x984 = x982 >= '0';
                                  int x986;
                                  if (x984) {
                                    int x985 = x982 <= '9';
                                    x986 = x985;
                                  } else {
                                    x986 = 0/*false*/;
                                  }
                                  if (x986) {
                                    x1027 = 0/*false*/;
                                    x1028 = x982;
                                    char  *x987 = x980+1;
                                    x1029 = x987;
                                  } else {
                                    x1029 = x980;
                                  }
                                }
                                int x1041 = x1027;
                                if (x1041) {
                                  char  *x1042 = x1029;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1045 = x1028;
                                  char  *x1047 = x1029;
                                  char  *x1048 = x1047;
                                  int x1049 = 1/*true*/;
                                  char x1046 = x1045 - '0';
                                  int x1050 = x1046;
                                  /*@
                                  loop invariant (((strlen(x1048)>=0) && \valid(x1048+(0..strlen(x1048)))) && ((x1050==-1) || (0<=x1050)));
                                  loop assigns x1048, x1049, x1050;
                                  */
                                  for (;;) {
                                    int x1051 = x1049;
                                    if (!x1051) break;
                                    char  *x1053 = x1048;
                                    int x1060 = 1/*true*/;
                                    char x1061 = '\0';
                                    char  *x1062 = 0/*null*/;
                                    char x1054 = x1053[0];
                                    int x1055 = x1054 == '\0';
                                    if (x1055) {
                                      x1062 = x1053;
                                    } else {
                                      int x1056 = x1054 >= '0';
                                      int x1058;
                                      if (x1056) {
                                        int x1057 = x1054 <= '9';
                                        x1058 = x1057;
                                      } else {
                                        x1058 = 0/*false*/;
                                      }
                                      if (x1058) {
                                        x1060 = 0/*false*/;
                                        x1061 = x1054;
                                        char  *x1059 = x1053+1;
                                        x1062 = x1059;
                                      } else {
                                        x1062 = x1053;
                                      }
                                    }
                                    int x1074 = x1060;
                                    if (x1074) {
                                      char  *x1075 = x1062;
                                      x1049 = 0/*false*/;
                                    } else {
                                      char x1078 = x1061;
                                      char  *x1080 = x1062;
                                      int x1081 = x1050;
                                      int x1082 = x1081 < 0;
                                      int x1087;
                                      if (x1082) {
                                        x1087 = x1081;
                                      } else {
                                        int x1083 = x1081 > x356;
                                        int x1086;
                                        if (x1083) {
                                          x1086 = -1;
                                        } else {
                                          char x1079 = x1078 - '0';
                                          int x1084 = x1081 * 10;
                                          int x1085 = x1084 + x1079;
                                          x1086 = x1085;
                                        }
                                        x1087 = x1086;
                                      }
                                      x1050 = x1087;
                                      x1048 = x1080;
                                    }
                                  }
                                  int x1113 = x1050;
                                  char  *x1114 = x1048;
                                  char  *x1115 = x1114;
                                  int x1116 = 1/*true*/;
                                  /*@
                                  loop invariant ((strlen(x1115)>=0) && \valid(x1115+(0..strlen(x1115))));
                                  loop assigns x1115, x1116;
                                  */
                                  for (;;) {
                                    int x1118 = x1116;
                                    if (!x1118) break;
                                    char  *x1120 = x1115;
                                    char x1121 = x1120[0];
                                    int x1122 = x1121 == '\0';
                                    if (x1122) {
                                      x1116 = 0/*false*/;
                                    } else {
                                      int x1123 = x1121 == ' ';
                                      if (x1123) {
                                        char  *x1124 = x1120+1;
                                        x1115 = x1124;
                                      } else {
                                        x1116 = 0/*false*/;
                                      }
                                    }
                                  }
                                  char  *x1153 = x1115;
                                  int x1158 = 1/*true*/;
                                  char x1159 = '\0';
                                  char  *x1160 = 0/*null*/;
                                  char x1154 = x1153[0];
                                  int x1155 = x1154 == '\0';
                                  if (x1155) {
                                    x1160 = x1153;
                                  } else {
                                    int x1156 = x1154 == '\n';
                                    if (x1156) {
                                      x1158 = 0/*false*/;
                                      x1159 = x1154;
                                      char  *x1157 = x1153+1;
                                      x1160 = x1157;
                                    } else {
                                      x1160 = x1153;
                                    }
                                  }
                                  int x1172 = x1158;
                                  if (x1172) {
                                    char  *x1173 = x1160;
                                    x452 = 0/*false*/;
                                  } else {
                                    char x1176 = x1159;
                                    char  *x1177 = x1160;
                                    int x1178 = x453;
                                    int x1179 = x1113 == -2;
                                    int x1180;
                                    if (x1179) {
                                      x1180 = x1178;
                                    } else {
                                      x1180 = x1113;
                                    }
                                    x453 = x1180;
                                    x451 = x1177;
                                  }
                                }
                              } else {
                                int x1192 = 1/*true*/;
                                char x1193 = '\0';
                                char  *x1194 = 0/*null*/;
                                char x1188 = x1026[0];
                                int x1189 = x1188 == '\0';
                                if (x1189) {
                                  x1194 = x1026;
                                } else {
                                  int x1190 = x1188 == '\n';
                                  if (x1190) {
                                    x1192 = 0/*false*/;
                                    x1193 = x1188;
                                    char  *x1191 = x1026+1;
                                    x1194 = x1191;
                                  } else {
                                    x1194 = x1026;
                                  }
                                }
                                int x1206 = x1192;
                                if (x1206) {
                                  char  *x1207 = x1194;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1210 = x1193;
                                  char  *x1211 = x1194;
                                  int x1212 = x453;
                                  int x1214;
                                  if (x1213) {
                                    x1214 = x1212;
                                  } else {
                                    x1214 = -2;
                                  }
                                  x453 = x1214;
                                  x451 = x1211;
                                }
                              }
                            }
                          } else {
                            int x1224 = x462;
                            char  *x1225 = x463;
                            char  *x1226 = x1225;
                            int x1227 = 1/*true*/;
                            /*@
                            loop invariant ((strlen(x1226)>=0) && \valid(x1226+(0..strlen(x1226))));
                            loop assigns x1226, x1227;
                            */
                            for (;;) {
                              int x1229 = x1227;
                              if (!x1229) break;
                              char  *x1231 = x1226;
                              char x1232 = x1231[0];
                              int x1233 = x1232 == '\0';
                              if (x1233) {
                                x1227 = 0/*false*/;
                              } else {
                                int x1234 = x1232 == ' ';
                                if (x1234) {
                                  char  *x1235 = x1231+1;
                                  x1226 = x1235;
                                } else {
                                  x1227 = 0/*false*/;
                                }
                              }
                            }
                            char  *x1264 = x1226;
                            int x1269 = 1/*true*/;
                            char x1270 = '\0';
                            char  *x1271 = 0/*null*/;
                            char x1265 = x1264[0];
                            int x1266 = x1265 == '\0';
                            if (x1266) {
                              x1271 = x1264;
                            } else {
                              int x1267 = x1265 == ':';
                              if (x1267) {
                                x1269 = 0/*false*/;
                                x1270 = x1265;
                                char  *x1268 = x1264+1;
                                x1271 = x1268;
                              } else {
                                x1271 = x1264;
                              }
                            }
                            int x1283 = x1269;
                            if (x1283) {
                              char  *x1284 = x1271;
                              x452 = 0/*false*/;
                            } else {
                              char x1287 = x1270;
                              char  *x1288 = x1271;
                              char  *x1289 = x1288;
                              int x1290 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x1289)>=0) && \valid(x1289+(0..strlen(x1289))));
                              loop assigns x1289, x1290;
                              */
                              for (;;) {
                                int x1292 = x1290;
                                if (!x1292) break;
                                char  *x1294 = x1289;
                                char x1295 = x1294[0];
                                int x1296 = x1295 == '\0';
                                if (x1296) {
                                  x1290 = 0/*false*/;
                                } else {
                                  int x1297 = x1295 == ' ';
                                  if (x1297) {
                                    char  *x1298 = x1294+1;
                                    x1289 = x1298;
                                  } else {
                                    x1290 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x1327 = x1289;
                              char  *x1335 = x1327;
                              int x1336 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x1335)>=0) && \valid(x1335+(0..strlen(x1335))));
                              loop assigns x1335, x1336;
                              */
                              for (;;) {
                                int x1338 = x1336;
                                if (!x1338) break;
                                char  *x1340 = x1335;
                                char x1341 = x1340[0];
                                int x1342 = x1341 == '\0';
                                if (x1342) {
                                  x1336 = 0/*false*/;
                                } else {
                                  int x1343 = x1341 != '\n';
                                  if (x1343) {
                                    char  *x1344 = x1340+1;
                                    x1335 = x1344;
                                  } else {
                                    x1336 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x1373 = x1335;
                              int x1328 = x1224 == 1;
                              if (x1328) {
                                int x1374 = 1/*true*/;
                                char x1375 = '\0';
                                char  *x1376 = 0/*null*/;
                                char x1329 = x1327[0];
                                int x1330 = x1329 == '\0';
                                if (x1330) {
                                  x1376 = x1327;
                                } else {
                                  int x1331 = x1329 >= '0';
                                  int x1333;
                                  if (x1331) {
                                    int x1332 = x1329 <= '9';
                                    x1333 = x1332;
                                  } else {
                                    x1333 = 0/*false*/;
                                  }
                                  if (x1333) {
                                    x1374 = 0/*false*/;
                                    x1375 = x1329;
                                    char  *x1334 = x1327+1;
                                    x1376 = x1334;
                                  } else {
                                    x1376 = x1327;
                                  }
                                }
                                int x1388 = x1374;
                                if (x1388) {
                                  char  *x1389 = x1376;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1392 = x1375;
                                  char  *x1394 = x1376;
                                  char  *x1395 = x1394;
                                  int x1396 = 1/*true*/;
                                  char x1393 = x1392 - '0';
                                  int x1397 = x1393;
                                  /*@
                                  loop invariant (((strlen(x1395)>=0) && \valid(x1395+(0..strlen(x1395)))) && ((x1397==-1) || (0<=x1397)));
                                  loop assigns x1395, x1396, x1397;
                                  */
                                  for (;;) {
                                    int x1398 = x1396;
                                    if (!x1398) break;
                                    char  *x1400 = x1395;
                                    int x1407 = 1/*true*/;
                                    char x1408 = '\0';
                                    char  *x1409 = 0/*null*/;
                                    char x1401 = x1400[0];
                                    int x1402 = x1401 == '\0';
                                    if (x1402) {
                                      x1409 = x1400;
                                    } else {
                                      int x1403 = x1401 >= '0';
                                      int x1405;
                                      if (x1403) {
                                        int x1404 = x1401 <= '9';
                                        x1405 = x1404;
                                      } else {
                                        x1405 = 0/*false*/;
                                      }
                                      if (x1405) {
                                        x1407 = 0/*false*/;
                                        x1408 = x1401;
                                        char  *x1406 = x1400+1;
                                        x1409 = x1406;
                                      } else {
                                        x1409 = x1400;
                                      }
                                    }
                                    int x1421 = x1407;
                                    if (x1421) {
                                      char  *x1422 = x1409;
                                      x1396 = 0/*false*/;
                                    } else {
                                      char x1425 = x1408;
                                      char  *x1427 = x1409;
                                      int x1428 = x1397;
                                      int x1429 = x1428 < 0;
                                      int x1434;
                                      if (x1429) {
                                        x1434 = x1428;
                                      } else {
                                        int x1430 = x1428 > x356;
                                        int x1433;
                                        if (x1430) {
                                          x1433 = -1;
                                        } else {
                                          char x1426 = x1425 - '0';
                                          int x1431 = x1428 * 10;
                                          int x1432 = x1431 + x1426;
                                          x1433 = x1432;
                                        }
                                        x1434 = x1433;
                                      }
                                      x1397 = x1434;
                                      x1395 = x1427;
                                    }
                                  }
                                  int x1460 = x1397;
                                  char  *x1461 = x1395;
                                  char  *x1462 = x1461;
                                  int x1463 = 1/*true*/;
                                  /*@
                                  loop invariant ((strlen(x1462)>=0) && \valid(x1462+(0..strlen(x1462))));
                                  loop assigns x1462, x1463;
                                  */
                                  for (;;) {
                                    int x1465 = x1463;
                                    if (!x1465) break;
                                    char  *x1467 = x1462;
                                    char x1468 = x1467[0];
                                    int x1469 = x1468 == '\0';
                                    if (x1469) {
                                      x1463 = 0/*false*/;
                                    } else {
                                      int x1470 = x1468 == ' ';
                                      if (x1470) {
                                        char  *x1471 = x1467+1;
                                        x1462 = x1471;
                                      } else {
                                        x1463 = 0/*false*/;
                                      }
                                    }
                                  }
                                  char  *x1500 = x1462;
                                  int x1505 = 1/*true*/;
                                  char x1506 = '\0';
                                  char  *x1507 = 0/*null*/;
                                  char x1501 = x1500[0];
                                  int x1502 = x1501 == '\0';
                                  if (x1502) {
                                    x1507 = x1500;
                                  } else {
                                    int x1503 = x1501 == '\n';
                                    if (x1503) {
                                      x1505 = 0/*false*/;
                                      x1506 = x1501;
                                      char  *x1504 = x1500+1;
                                      x1507 = x1504;
                                    } else {
                                      x1507 = x1500;
                                    }
                                  }
                                  int x1519 = x1505;
                                  if (x1519) {
                                    char  *x1520 = x1507;
                                    x452 = 0/*false*/;
                                  } else {
                                    char x1523 = x1506;
                                    char  *x1524 = x1507;
                                    int x1525 = x453;
                                    int x1526 = x1460 == -2;
                                    int x1527;
                                    if (x1526) {
                                      x1527 = x1525;
                                    } else {
                                      x1527 = x1460;
                                    }
                                    x453 = x1527;
                                    x451 = x1524;
                                  }
                                }
                              } else {
                                int x1539 = 1/*true*/;
                                char x1540 = '\0';
                                char  *x1541 = 0/*null*/;
                                char x1535 = x1373[0];
                                int x1536 = x1535 == '\0';
                                if (x1536) {
                                  x1541 = x1373;
                                } else {
                                  int x1537 = x1535 == '\n';
                                  if (x1537) {
                                    x1539 = 0/*false*/;
                                    x1540 = x1535;
                                    char  *x1538 = x1373+1;
                                    x1541 = x1538;
                                  } else {
                                    x1541 = x1373;
                                  }
                                }
                                int x1553 = x1539;
                                if (x1553) {
                                  char  *x1554 = x1541;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1557 = x1540;
                                  char  *x1558 = x1541;
                                  int x1559 = x453;
                                  int x1560;
                                  if (x1213) {
                                    x1560 = x1559;
                                  } else {
                                    x1560 = -2;
                                  }
                                  x453 = x1560;
                                  x451 = x1558;
                                }
                              }
                            }
                          }
                        }
                        int x1587 = x453;
                        char  *x1588 = x451;
                        int x1593 = 1/*true*/;
                        char x1594 = '\0';
                        char  *x1595 = 0/*null*/;
                        char x1589 = x1588[0];
                        int x1590 = x1589 == '\0';
                        if (x1590) {
                          x1595 = x1588;
                        } else {
                          int x1591 = x1589 == '\n';
                          if (x1591) {
                            x1593 = 0/*false*/;
                            x1594 = x1589;
                            char  *x1592 = x1588+1;
                            x1595 = x1592;
                          } else {
                            x1595 = x1588;
                          }
                        }
                        int x1607 = x1593;
                        if (x1607) {
                          char  *x1608 = x1595;
                        } else {
                          char x1610 = x1594;
                          char  *x1611 = x1595;
                          int x1613 = 1/*true*/;
                          char  *x1614 = x1611;
                          /*@
                          loop invariant ((0<=x1616) && ((strlen(x1614)>=0) && \valid(x1614+(0..strlen(x1614)))));
                          loop assigns x1616, x1613, x1614;
                          loop variant (x453-x1616);
                          */
                          for(int x1616=0; x1616 < x1587; x1616++) {
                            int x1617 = x1613;
                            if (x1617) {
                              char  *x1618 = x1614;
                              char x1619 = x1618[0];
                              int x1620 = x1619 == '\0';
                              if (x1620) {
                                x1613 = 0/*false*/;
                              } else {
                                if (1/*true*/) {
                                  char  *x1621 = x1618+1;
                                  x1614 = x1621;
                                } else {
                                  x1613 = 0/*false*/;
                                }
                              }
                            } else {
                            }
                          }
                          int x1651 = x1613;
                          char  *x1652 = x1614;
                          int x1612 = x1587 < 0;
                          if (x1612) {
                          } else {
                            int x1653 = 1/*true*/;
                            char  *x1655 = 0/*null*/;
                            if (x1651) {
                              x1653 = 0/*false*/;
                              x1655 = x1652;
                            } else {
                              x1655 = x1611;
                            }
                            int x1663 = x1653;
                            if (x1663) {
                              char  *x1664 = x1655;
                            } else {
                              char  *x1667 = x1655;
                              int x1672 = 1/*true*/;
                              char x1673 = '\0';
                              char  *x1674 = 0/*null*/;
                              char x1668 = x1667[0];
                              int x1669 = x1668 == '\0';
                              if (x1669) {
                                x1674 = x1667;
                              } else {
                                int x1670 = x1668 == '\n';
                                if (x1670) {
                                  x1672 = 0/*false*/;
                                  x1673 = x1668;
                                  char  *x1671 = x1667+1;
                                  x1674 = x1671;
                                } else {
                                  x1674 = x1667;
                                }
                              }
                              int x1686 = x1672;
                              if (x1686) {
                                char  *x1687 = x1674;
                              } else {
                                char x1689 = x1673;
                                char  *x1690 = x1674;
                                char x1691 = x1690[0];
                                int x1692 = x1691 == '\0';
                                if (x1692) {
                                  x2 = x1587;
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
  int x1726 = x2;
  return x1726;
}
