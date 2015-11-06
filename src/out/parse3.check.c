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
                        int x882 = 0 == 1;
                        int x1114 = -2 == -2;
                        int x1229 = 1 == 1;
                        /*@
                        loop invariant ((strlen(x451)>=0) && \valid(x451+(0..strlen(x451))));
                        loop assigns x451, x452, x453;
                        */
                        for (;;) {
                          int x454 = x452;
                          if (!x454) break;
                          char  *x456 = x451;
                          char  *x457 = x456;
                          int x458 = 1/*true*/;
                          int x459 = x458;
                          if (x459) {
                            char  *x460 = x457;
                            char x461 = x460[0];
                            int x462 = x461 == '\0';
                            if (x462) {
                              x458 = 0/*false*/;
                            } else {
                              int x465 = x461 != 'C';
                              if (x465) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x468 = x460+1;
                                x457 = x468;
                              }
                            }
                          } else {
                          }
                          int x476 = x458;
                          if (x476) {
                            char  *x477 = x457;
                            char x478 = x477[0];
                            int x479 = x478 == '\0';
                            if (x479) {
                              x458 = 0/*false*/;
                            } else {
                              int x482 = x478 != 'o';
                              if (x482) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x485 = x477+1;
                                x457 = x485;
                              }
                            }
                          } else {
                          }
                          int x493 = x458;
                          if (x493) {
                            char  *x494 = x457;
                            char x495 = x494[0];
                            int x496 = x495 == '\0';
                            if (x496) {
                              x458 = 0/*false*/;
                            } else {
                              int x499 = x495 != 'n';
                              if (x499) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x502 = x494+1;
                                x457 = x502;
                              }
                            }
                          } else {
                          }
                          int x510 = x458;
                          if (x510) {
                            char  *x511 = x457;
                            char x512 = x511[0];
                            int x513 = x512 == '\0';
                            if (x513) {
                              x458 = 0/*false*/;
                            } else {
                              int x516 = x512 != 't';
                              if (x516) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x519 = x511+1;
                                x457 = x519;
                              }
                            }
                          } else {
                          }
                          int x527 = x458;
                          if (x527) {
                            char  *x528 = x457;
                            char x529 = x528[0];
                            int x530 = x529 == '\0';
                            if (x530) {
                              x458 = 0/*false*/;
                            } else {
                              int x533 = x529 != 'e';
                              if (x533) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x536 = x528+1;
                                x457 = x536;
                              }
                            }
                          } else {
                          }
                          int x544 = x458;
                          if (x544) {
                            char  *x545 = x457;
                            char x546 = x545[0];
                            int x547 = x546 == '\0';
                            if (x547) {
                              x458 = 0/*false*/;
                            } else {
                              int x550 = x546 != 'n';
                              if (x550) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x553 = x545+1;
                                x457 = x553;
                              }
                            }
                          } else {
                          }
                          int x561 = x458;
                          if (x561) {
                            char  *x562 = x457;
                            char x563 = x562[0];
                            int x564 = x563 == '\0';
                            if (x564) {
                              x458 = 0/*false*/;
                            } else {
                              int x567 = x563 != 't';
                              if (x567) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x570 = x562+1;
                                x457 = x570;
                              }
                            }
                          } else {
                          }
                          int x578 = x458;
                          if (x578) {
                            char  *x579 = x457;
                            char x580 = x579[0];
                            int x581 = x580 == '\0';
                            if (x581) {
                              x458 = 0/*false*/;
                            } else {
                              int x584 = x580 != '-';
                              if (x584) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x587 = x579+1;
                                x457 = x587;
                              }
                            }
                          } else {
                          }
                          int x595 = x458;
                          if (x595) {
                            char  *x596 = x457;
                            char x597 = x596[0];
                            int x598 = x597 == '\0';
                            if (x598) {
                              x458 = 0/*false*/;
                            } else {
                              int x601 = x597 != 'L';
                              if (x601) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x604 = x596+1;
                                x457 = x604;
                              }
                            }
                          } else {
                          }
                          int x612 = x458;
                          if (x612) {
                            char  *x613 = x457;
                            char x614 = x613[0];
                            int x615 = x614 == '\0';
                            if (x615) {
                              x458 = 0/*false*/;
                            } else {
                              int x618 = x614 != 'e';
                              if (x618) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x621 = x613+1;
                                x457 = x621;
                              }
                            }
                          } else {
                          }
                          int x629 = x458;
                          if (x629) {
                            char  *x630 = x457;
                            char x631 = x630[0];
                            int x632 = x631 == '\0';
                            if (x632) {
                              x458 = 0/*false*/;
                            } else {
                              int x635 = x631 != 'n';
                              if (x635) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x638 = x630+1;
                                x457 = x638;
                              }
                            }
                          } else {
                          }
                          int x646 = x458;
                          if (x646) {
                            char  *x647 = x457;
                            char x648 = x647[0];
                            int x649 = x648 == '\0';
                            if (x649) {
                              x458 = 0/*false*/;
                            } else {
                              int x652 = x648 != 'g';
                              if (x652) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x655 = x647+1;
                                x457 = x655;
                              }
                            }
                          } else {
                          }
                          int x663 = x458;
                          if (x663) {
                            char  *x664 = x457;
                            char x665 = x664[0];
                            int x666 = x665 == '\0';
                            if (x666) {
                              x458 = 0/*false*/;
                            } else {
                              int x669 = x665 != 't';
                              if (x669) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x672 = x664+1;
                                x457 = x672;
                              }
                            }
                          } else {
                          }
                          int x680 = x458;
                          if (x680) {
                            char  *x681 = x457;
                            char x682 = x681[0];
                            int x683 = x682 == '\0';
                            if (x683) {
                              x458 = 0/*false*/;
                            } else {
                              int x686 = x682 != 'h';
                              if (x686) {
                                x458 = 0/*false*/;
                              } else {
                                char  *x689 = x681+1;
                                x457 = x689;
                              }
                            }
                          } else {
                          }
                          int x697 = x458;
                          char  *x698 = x457;
                          int x699 = 1/*true*/;
                          char  *x701 = 0/*null*/;
                          if (x697) {
                            x699 = 0/*false*/;
                            x701 = x698;
                          } else {
                            x701 = x456;
                          }
                          int x709 = x699;
                          if (x709) {
                            char  *x710 = x701;
                            char  *x711 = x456;
                            int x712 = 1/*true*/;
                            /*@
                            loop invariant ((strlen(x711)>=0) && \valid(x711+(0..strlen(x711))));
                            loop assigns x711, x712;
                            */
                            for (;;) {
                              int x714 = x712;
                              if (!x714) break;
                              char  *x716 = x711;
                              int x727 = 1/*true*/;
                              char x728 = '\0';
                              char  *x729 = 0/*null*/;
                              char x717 = x716[0];
                              int x718 = x717 == '\0';
                              if (x718) {
                                x729 = x716;
                              } else {
                                int x719 = x717 >= 'a';
                                int x721;
                                if (x719) {
                                  int x720 = x717 <= 'z';
                                  x721 = x720;
                                } else {
                                  x721 = 0/*false*/;
                                }
                                int x722 = x717 >= 'A';
                                int x724;
                                if (x722) {
                                  int x723 = x717 <= 'Z';
                                  x724 = x723;
                                } else {
                                  x724 = 0/*false*/;
                                }
                                int x725 = x721 || x724;
                                if (x725) {
                                  x727 = 0/*false*/;
                                  x728 = x717;
                                  char  *x726 = x716+1;
                                  x729 = x726;
                                } else {
                                  x729 = x716;
                                }
                              }
                              int x741 = x727;
                              char x743 = x728;
                              char  *x744 = x729;
                              if (x741) {
                                if (x718) {
                                  x712 = 0/*false*/;
                                } else {
                                  int x742 = x717 == '-';
                                  if (x742) {
                                    char  *x726 = x716+1;
                                    x711 = x726;
                                  } else {
                                    x712 = 0/*false*/;
                                  }
                                }
                              } else {
                                x711 = x744;
                              }
                            }
                            char  *x779 = x711;
                            char  *x780 = x779;
                            int x781 = 1/*true*/;
                            /*@
                            loop invariant ((strlen(x780)>=0) && \valid(x780+(0..strlen(x780))));
                            loop assigns x780, x781;
                            */
                            for (;;) {
                              int x783 = x781;
                              if (!x783) break;
                              char  *x785 = x780;
                              char x786 = x785[0];
                              int x787 = x786 == '\0';
                              if (x787) {
                                x781 = 0/*false*/;
                              } else {
                                int x788 = x786 == ' ';
                                if (x788) {
                                  char  *x789 = x785+1;
                                  x780 = x789;
                                } else {
                                  x781 = 0/*false*/;
                                }
                              }
                            }
                            char  *x818 = x780;
                            int x823 = 1/*true*/;
                            char x824 = '\0';
                            char  *x825 = 0/*null*/;
                            char x819 = x818[0];
                            int x820 = x819 == '\0';
                            if (x820) {
                              x825 = x818;
                            } else {
                              int x821 = x819 == ':';
                              if (x821) {
                                x823 = 0/*false*/;
                                x824 = x819;
                                char  *x822 = x818+1;
                                x825 = x822;
                              } else {
                                x825 = x818;
                              }
                            }
                            int x837 = x823;
                            if (x837) {
                              char  *x838 = x825;
                              x452 = 0/*false*/;
                            } else {
                              char x841 = x824;
                              char  *x842 = x825;
                              char  *x843 = x842;
                              int x844 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x843)>=0) && \valid(x843+(0..strlen(x843))));
                              loop assigns x843, x844;
                              */
                              for (;;) {
                                int x846 = x844;
                                if (!x846) break;
                                char  *x848 = x843;
                                char x849 = x848[0];
                                int x850 = x849 == '\0';
                                if (x850) {
                                  x844 = 0/*false*/;
                                } else {
                                  int x851 = x849 == ' ';
                                  if (x851) {
                                    char  *x852 = x848+1;
                                    x843 = x852;
                                  } else {
                                    x844 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x881 = x843;
                              char  *x889 = x881;
                              int x890 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x889)>=0) && \valid(x889+(0..strlen(x889))));
                              loop assigns x889, x890;
                              */
                              for (;;) {
                                int x892 = x890;
                                if (!x892) break;
                                char  *x894 = x889;
                                char x895 = x894[0];
                                int x896 = x895 == '\0';
                                if (x896) {
                                  x890 = 0/*false*/;
                                } else {
                                  int x897 = x895 != '\n';
                                  if (x897) {
                                    char  *x898 = x894+1;
                                    x889 = x898;
                                  } else {
                                    x890 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x927 = x889;
                              if (x882) {
                                int x928 = 1/*true*/;
                                char x929 = '\0';
                                char  *x930 = 0/*null*/;
                                char x883 = x881[0];
                                int x884 = x883 == '\0';
                                if (x884) {
                                  x930 = x881;
                                } else {
                                  int x885 = x883 >= '0';
                                  int x887;
                                  if (x885) {
                                    int x886 = x883 <= '9';
                                    x887 = x886;
                                  } else {
                                    x887 = 0/*false*/;
                                  }
                                  if (x887) {
                                    x928 = 0/*false*/;
                                    x929 = x883;
                                    char  *x888 = x881+1;
                                    x930 = x888;
                                  } else {
                                    x930 = x881;
                                  }
                                }
                                int x942 = x928;
                                if (x942) {
                                  char  *x943 = x930;
                                  x452 = 0/*false*/;
                                } else {
                                  char x946 = x929;
                                  char  *x948 = x930;
                                  char  *x949 = x948;
                                  int x950 = 1/*true*/;
                                  char x947 = x946 - '0';
                                  int x951 = x947;
                                  /*@
                                  loop invariant (((strlen(x949)>=0) && \valid(x949+(0..strlen(x949)))) && ((x951==-1) || (0<=x951)));
                                  loop assigns x949, x950, x951;
                                  */
                                  for (;;) {
                                    int x952 = x950;
                                    if (!x952) break;
                                    char  *x954 = x949;
                                    int x961 = 1/*true*/;
                                    char x962 = '\0';
                                    char  *x963 = 0/*null*/;
                                    char x955 = x954[0];
                                    int x956 = x955 == '\0';
                                    if (x956) {
                                      x963 = x954;
                                    } else {
                                      int x957 = x955 >= '0';
                                      int x959;
                                      if (x957) {
                                        int x958 = x955 <= '9';
                                        x959 = x958;
                                      } else {
                                        x959 = 0/*false*/;
                                      }
                                      if (x959) {
                                        x961 = 0/*false*/;
                                        x962 = x955;
                                        char  *x960 = x954+1;
                                        x963 = x960;
                                      } else {
                                        x963 = x954;
                                      }
                                    }
                                    int x975 = x961;
                                    if (x975) {
                                      char  *x976 = x963;
                                      x950 = 0/*false*/;
                                    } else {
                                      char x979 = x962;
                                      char  *x981 = x963;
                                      int x982 = x951;
                                      int x983 = x982 < 0;
                                      int x988;
                                      if (x983) {
                                        x988 = x982;
                                      } else {
                                        int x984 = x982 > x356;
                                        int x987;
                                        if (x984) {
                                          x987 = -1;
                                        } else {
                                          char x980 = x979 - '0';
                                          int x985 = x982 * 10;
                                          int x986 = x985 + x980;
                                          x987 = x986;
                                        }
                                        x988 = x987;
                                      }
                                      x951 = x988;
                                      x949 = x981;
                                    }
                                  }
                                  int x1014 = x951;
                                  char  *x1015 = x949;
                                  char  *x1016 = x1015;
                                  int x1017 = 1/*true*/;
                                  /*@
                                  loop invariant ((strlen(x1016)>=0) && \valid(x1016+(0..strlen(x1016))));
                                  loop assigns x1016, x1017;
                                  */
                                  for (;;) {
                                    int x1019 = x1017;
                                    if (!x1019) break;
                                    char  *x1021 = x1016;
                                    char x1022 = x1021[0];
                                    int x1023 = x1022 == '\0';
                                    if (x1023) {
                                      x1017 = 0/*false*/;
                                    } else {
                                      int x1024 = x1022 == ' ';
                                      if (x1024) {
                                        char  *x1025 = x1021+1;
                                        x1016 = x1025;
                                      } else {
                                        x1017 = 0/*false*/;
                                      }
                                    }
                                  }
                                  char  *x1054 = x1016;
                                  int x1059 = 1/*true*/;
                                  char x1060 = '\0';
                                  char  *x1061 = 0/*null*/;
                                  char x1055 = x1054[0];
                                  int x1056 = x1055 == '\0';
                                  if (x1056) {
                                    x1061 = x1054;
                                  } else {
                                    int x1057 = x1055 == '\n';
                                    if (x1057) {
                                      x1059 = 0/*false*/;
                                      x1060 = x1055;
                                      char  *x1058 = x1054+1;
                                      x1061 = x1058;
                                    } else {
                                      x1061 = x1054;
                                    }
                                  }
                                  int x1073 = x1059;
                                  if (x1073) {
                                    char  *x1074 = x1061;
                                    x452 = 0/*false*/;
                                  } else {
                                    char x1077 = x1060;
                                    char  *x1078 = x1061;
                                    int x1079 = x453;
                                    int x1080 = x1014 == -2;
                                    int x1081;
                                    if (x1080) {
                                      x1081 = x1079;
                                    } else {
                                      x1081 = x1014;
                                    }
                                    x453 = x1081;
                                    x451 = x1078;
                                  }
                                }
                              } else {
                                int x1093 = 1/*true*/;
                                char x1094 = '\0';
                                char  *x1095 = 0/*null*/;
                                char x1089 = x927[0];
                                int x1090 = x1089 == '\0';
                                if (x1090) {
                                  x1095 = x927;
                                } else {
                                  int x1091 = x1089 == '\n';
                                  if (x1091) {
                                    x1093 = 0/*false*/;
                                    x1094 = x1089;
                                    char  *x1092 = x927+1;
                                    x1095 = x1092;
                                  } else {
                                    x1095 = x927;
                                  }
                                }
                                int x1107 = x1093;
                                if (x1107) {
                                  char  *x1108 = x1095;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1111 = x1094;
                                  char  *x1112 = x1095;
                                  int x1113 = x453;
                                  int x1115;
                                  if (x1114) {
                                    x1115 = x1113;
                                  } else {
                                    x1115 = -2;
                                  }
                                  x453 = x1115;
                                  x451 = x1112;
                                }
                              }
                            }
                          } else {
                            char  *x1126 = x701;
                            char  *x1127 = x1126;
                            int x1128 = 1/*true*/;
                            /*@
                            loop invariant ((strlen(x1127)>=0) && \valid(x1127+(0..strlen(x1127))));
                            loop assigns x1127, x1128;
                            */
                            for (;;) {
                              int x1130 = x1128;
                              if (!x1130) break;
                              char  *x1132 = x1127;
                              char x1133 = x1132[0];
                              int x1134 = x1133 == '\0';
                              if (x1134) {
                                x1128 = 0/*false*/;
                              } else {
                                int x1135 = x1133 == ' ';
                                if (x1135) {
                                  char  *x1136 = x1132+1;
                                  x1127 = x1136;
                                } else {
                                  x1128 = 0/*false*/;
                                }
                              }
                            }
                            char  *x1165 = x1127;
                            int x1170 = 1/*true*/;
                            char x1171 = '\0';
                            char  *x1172 = 0/*null*/;
                            char x1166 = x1165[0];
                            int x1167 = x1166 == '\0';
                            if (x1167) {
                              x1172 = x1165;
                            } else {
                              int x1168 = x1166 == ':';
                              if (x1168) {
                                x1170 = 0/*false*/;
                                x1171 = x1166;
                                char  *x1169 = x1165+1;
                                x1172 = x1169;
                              } else {
                                x1172 = x1165;
                              }
                            }
                            int x1184 = x1170;
                            if (x1184) {
                              char  *x1185 = x1172;
                              x452 = 0/*false*/;
                            } else {
                              char x1188 = x1171;
                              char  *x1189 = x1172;
                              char  *x1190 = x1189;
                              int x1191 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x1190)>=0) && \valid(x1190+(0..strlen(x1190))));
                              loop assigns x1190, x1191;
                              */
                              for (;;) {
                                int x1193 = x1191;
                                if (!x1193) break;
                                char  *x1195 = x1190;
                                char x1196 = x1195[0];
                                int x1197 = x1196 == '\0';
                                if (x1197) {
                                  x1191 = 0/*false*/;
                                } else {
                                  int x1198 = x1196 == ' ';
                                  if (x1198) {
                                    char  *x1199 = x1195+1;
                                    x1190 = x1199;
                                  } else {
                                    x1191 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x1228 = x1190;
                              char  *x1236 = x1228;
                              int x1237 = 1/*true*/;
                              /*@
                              loop invariant ((strlen(x1236)>=0) && \valid(x1236+(0..strlen(x1236))));
                              loop assigns x1236, x1237;
                              */
                              for (;;) {
                                int x1239 = x1237;
                                if (!x1239) break;
                                char  *x1241 = x1236;
                                char x1242 = x1241[0];
                                int x1243 = x1242 == '\0';
                                if (x1243) {
                                  x1237 = 0/*false*/;
                                } else {
                                  int x1244 = x1242 != '\n';
                                  if (x1244) {
                                    char  *x1245 = x1241+1;
                                    x1236 = x1245;
                                  } else {
                                    x1237 = 0/*false*/;
                                  }
                                }
                              }
                              char  *x1274 = x1236;
                              if (x1229) {
                                int x1275 = 1/*true*/;
                                char x1276 = '\0';
                                char  *x1277 = 0/*null*/;
                                char x1230 = x1228[0];
                                int x1231 = x1230 == '\0';
                                if (x1231) {
                                  x1277 = x1228;
                                } else {
                                  int x1232 = x1230 >= '0';
                                  int x1234;
                                  if (x1232) {
                                    int x1233 = x1230 <= '9';
                                    x1234 = x1233;
                                  } else {
                                    x1234 = 0/*false*/;
                                  }
                                  if (x1234) {
                                    x1275 = 0/*false*/;
                                    x1276 = x1230;
                                    char  *x1235 = x1228+1;
                                    x1277 = x1235;
                                  } else {
                                    x1277 = x1228;
                                  }
                                }
                                int x1289 = x1275;
                                if (x1289) {
                                  char  *x1290 = x1277;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1293 = x1276;
                                  char  *x1295 = x1277;
                                  char  *x1296 = x1295;
                                  int x1297 = 1/*true*/;
                                  char x1294 = x1293 - '0';
                                  int x1298 = x1294;
                                  /*@
                                  loop invariant (((strlen(x1296)>=0) && \valid(x1296+(0..strlen(x1296)))) && ((x1298==-1) || (0<=x1298)));
                                  loop assigns x1296, x1297, x1298;
                                  */
                                  for (;;) {
                                    int x1299 = x1297;
                                    if (!x1299) break;
                                    char  *x1301 = x1296;
                                    int x1308 = 1/*true*/;
                                    char x1309 = '\0';
                                    char  *x1310 = 0/*null*/;
                                    char x1302 = x1301[0];
                                    int x1303 = x1302 == '\0';
                                    if (x1303) {
                                      x1310 = x1301;
                                    } else {
                                      int x1304 = x1302 >= '0';
                                      int x1306;
                                      if (x1304) {
                                        int x1305 = x1302 <= '9';
                                        x1306 = x1305;
                                      } else {
                                        x1306 = 0/*false*/;
                                      }
                                      if (x1306) {
                                        x1308 = 0/*false*/;
                                        x1309 = x1302;
                                        char  *x1307 = x1301+1;
                                        x1310 = x1307;
                                      } else {
                                        x1310 = x1301;
                                      }
                                    }
                                    int x1322 = x1308;
                                    if (x1322) {
                                      char  *x1323 = x1310;
                                      x1297 = 0/*false*/;
                                    } else {
                                      char x1326 = x1309;
                                      char  *x1328 = x1310;
                                      int x1329 = x1298;
                                      int x1330 = x1329 < 0;
                                      int x1335;
                                      if (x1330) {
                                        x1335 = x1329;
                                      } else {
                                        int x1331 = x1329 > x356;
                                        int x1334;
                                        if (x1331) {
                                          x1334 = -1;
                                        } else {
                                          char x1327 = x1326 - '0';
                                          int x1332 = x1329 * 10;
                                          int x1333 = x1332 + x1327;
                                          x1334 = x1333;
                                        }
                                        x1335 = x1334;
                                      }
                                      x1298 = x1335;
                                      x1296 = x1328;
                                    }
                                  }
                                  int x1361 = x1298;
                                  char  *x1362 = x1296;
                                  char  *x1363 = x1362;
                                  int x1364 = 1/*true*/;
                                  /*@
                                  loop invariant ((strlen(x1363)>=0) && \valid(x1363+(0..strlen(x1363))));
                                  loop assigns x1363, x1364;
                                  */
                                  for (;;) {
                                    int x1366 = x1364;
                                    if (!x1366) break;
                                    char  *x1368 = x1363;
                                    char x1369 = x1368[0];
                                    int x1370 = x1369 == '\0';
                                    if (x1370) {
                                      x1364 = 0/*false*/;
                                    } else {
                                      int x1371 = x1369 == ' ';
                                      if (x1371) {
                                        char  *x1372 = x1368+1;
                                        x1363 = x1372;
                                      } else {
                                        x1364 = 0/*false*/;
                                      }
                                    }
                                  }
                                  char  *x1401 = x1363;
                                  int x1406 = 1/*true*/;
                                  char x1407 = '\0';
                                  char  *x1408 = 0/*null*/;
                                  char x1402 = x1401[0];
                                  int x1403 = x1402 == '\0';
                                  if (x1403) {
                                    x1408 = x1401;
                                  } else {
                                    int x1404 = x1402 == '\n';
                                    if (x1404) {
                                      x1406 = 0/*false*/;
                                      x1407 = x1402;
                                      char  *x1405 = x1401+1;
                                      x1408 = x1405;
                                    } else {
                                      x1408 = x1401;
                                    }
                                  }
                                  int x1420 = x1406;
                                  if (x1420) {
                                    char  *x1421 = x1408;
                                    x452 = 0/*false*/;
                                  } else {
                                    char x1424 = x1407;
                                    char  *x1425 = x1408;
                                    int x1426 = x453;
                                    int x1427 = x1361 == -2;
                                    int x1428;
                                    if (x1427) {
                                      x1428 = x1426;
                                    } else {
                                      x1428 = x1361;
                                    }
                                    x453 = x1428;
                                    x451 = x1425;
                                  }
                                }
                              } else {
                                int x1440 = 1/*true*/;
                                char x1441 = '\0';
                                char  *x1442 = 0/*null*/;
                                char x1436 = x1274[0];
                                int x1437 = x1436 == '\0';
                                if (x1437) {
                                  x1442 = x1274;
                                } else {
                                  int x1438 = x1436 == '\n';
                                  if (x1438) {
                                    x1440 = 0/*false*/;
                                    x1441 = x1436;
                                    char  *x1439 = x1274+1;
                                    x1442 = x1439;
                                  } else {
                                    x1442 = x1274;
                                  }
                                }
                                int x1454 = x1440;
                                if (x1454) {
                                  char  *x1455 = x1442;
                                  x452 = 0/*false*/;
                                } else {
                                  char x1458 = x1441;
                                  char  *x1459 = x1442;
                                  int x1460 = x453;
                                  int x1461;
                                  if (x1114) {
                                    x1461 = x1460;
                                  } else {
                                    x1461 = -2;
                                  }
                                  x453 = x1461;
                                  x451 = x1459;
                                }
                              }
                            }
                          }
                        }
                        int x1488 = x453;
                        char  *x1489 = x451;
                        int x1494 = 1/*true*/;
                        char x1495 = '\0';
                        char  *x1496 = 0/*null*/;
                        char x1490 = x1489[0];
                        int x1491 = x1490 == '\0';
                        if (x1491) {
                          x1496 = x1489;
                        } else {
                          int x1492 = x1490 == '\n';
                          if (x1492) {
                            x1494 = 0/*false*/;
                            x1495 = x1490;
                            char  *x1493 = x1489+1;
                            x1496 = x1493;
                          } else {
                            x1496 = x1489;
                          }
                        }
                        int x1508 = x1494;
                        if (x1508) {
                          char  *x1509 = x1496;
                        } else {
                          char x1511 = x1495;
                          char  *x1512 = x1496;
                          int x1514 = 1/*true*/;
                          char  *x1515 = x1512;
                          /*@
                          loop invariant ((0<=x1517) && ((strlen(x1515)>=0) && \valid(x1515+(0..strlen(x1515)))));
                          loop assigns x1517, x1514, x1515;
                          loop variant (x453-x1517);
                          */
                          for(int x1517=0; x1517 < x1488; x1517++) {
                            int x1518 = x1514;
                            if (x1518) {
                              char  *x1519 = x1515;
                              char x1520 = x1519[0];
                              int x1521 = x1520 == '\0';
                              if (x1521) {
                                x1514 = 0/*false*/;
                              } else {
                                if (1/*true*/) {
                                  char  *x1522 = x1519+1;
                                  x1515 = x1522;
                                } else {
                                  x1514 = 0/*false*/;
                                }
                              }
                            } else {
                            }
                          }
                          int x1552 = x1514;
                          char  *x1553 = x1515;
                          int x1513 = x1488 < 0;
                          if (x1513) {
                          } else {
                            int x1554 = 1/*true*/;
                            char  *x1556 = 0/*null*/;
                            if (x1552) {
                              x1554 = 0/*false*/;
                              x1556 = x1553;
                            } else {
                              x1556 = x1512;
                            }
                            int x1564 = x1554;
                            if (x1564) {
                              char  *x1565 = x1556;
                            } else {
                              char  *x1568 = x1556;
                              int x1573 = 1/*true*/;
                              char x1574 = '\0';
                              char  *x1575 = 0/*null*/;
                              char x1569 = x1568[0];
                              int x1570 = x1569 == '\0';
                              if (x1570) {
                                x1575 = x1568;
                              } else {
                                int x1571 = x1569 == '\n';
                                if (x1571) {
                                  x1573 = 0/*false*/;
                                  x1574 = x1569;
                                  char  *x1572 = x1568+1;
                                  x1575 = x1572;
                                } else {
                                  x1575 = x1568;
                                }
                              }
                              int x1587 = x1573;
                              if (x1587) {
                                char  *x1588 = x1575;
                              } else {
                                char x1590 = x1574;
                                char  *x1591 = x1575;
                                char x1592 = x1591[0];
                                int x1593 = x1592 == '\0';
                                if (x1593) {
                                  x2 = x1488;
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
  int x1627 = x2;
  return x1627;
}
