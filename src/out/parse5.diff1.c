#include <limits.h>
#include <string.h>
char  * p_chunked(char  * x1824);
char  * p_TransferEncoding(char  * x1826);
char  * p_ContentLength(char  * x1828);
char  * p_HTTP(char  * x1830);
/*@
requires ((strlen(x0)>=0) && \valid(x0+(0..strlen(x0))));
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
  int x21 = 0;
  char  *x22 = 0/*null*/;
  int x23 = 1/*true*/;
  char x24 = '\0';
  char  *x25 = 0/*null*/;
  int x26 = 1/*true*/;
  int x27 = 0;
  char  *x28 = 0/*null*/;
  int x29 = 1/*true*/;
  char  *x31 = 0/*null*/;
  int x4 = 0 != x3;
  if (x4) {
    x29 = 0/*false*/;
    x31 = x3;
  } else {
    x31 = x0;
  }
  int x39 = x29;
  if (x39) {
    char  *x40 = x31;
    x28 = x40;
  } else {
    char  *x44 = x31;
    int x51 = 1/*true*/;
    int x52 = 0;
    char  *x53 = 0/*null*/;
    int x54 = 1/*true*/;
    char x55 = '\0';
    char  *x56 = 0/*null*/;
    char x45 = x44[0];
    int x46 = x45 == '\0';
    if (x46) {
      x56 = x44;
    } else {
      int x47 = x45 >= '0';
      int x49;
      if (x47) {
        int x48 = x45 <= '9';
        x49 = x48;
      } else {
        x49 = 0/*false*/;
      }
      if (x49) {
        x54 = 0/*false*/;
        x55 = x45;
        char  *x50 = x44+1;
        x56 = x50;
      } else {
        x56 = x44;
      }
    }
    int x68 = x54;
    if (x68) {
      char  *x69 = x56;
      x53 = x69;
    } else {
      char x72 = x55;
      char  *x74 = x56;
      x51 = 0/*false*/;
      char x73 = x72 - '0';
      x52 = x73;
      x53 = x74;
    }
    int x80 = x51;
    if (x80) {
      char  *x81 = x53;
      x28 = x81;
    } else {
      int x84 = x52;
      char  *x85 = x53;
      char  *x86 = x85;
      int x87 = 1/*true*/;
      int x88 = x84;
      int x121 = INT_MAX;
      int x122 = x121 / 10;
      int x123 = x122 - 10;
      /*@
      loop invariant (((strlen(x86)>=0) && \valid(x86+(0..strlen(x86)))) && ((x88==-1) || (0<=x88)));
      loop assigns x86, x87, x88;
      */
      for (;;) {
        int x89 = x87;
        if (!x89) break;
        char  *x91 = x86;
        int x98 = 1/*true*/;
        char x99 = '\0';
        char  *x100 = 0/*null*/;
        char x92 = x91[0];
        int x93 = x92 == '\0';
        if (x93) {
          x100 = x91;
        } else {
          int x94 = x92 >= '0';
          int x96;
          if (x94) {
            int x95 = x92 <= '9';
            x96 = x95;
          } else {
            x96 = 0/*false*/;
          }
          if (x96) {
            x98 = 0/*false*/;
            x99 = x92;
            char  *x97 = x91+1;
            x100 = x97;
          } else {
            x100 = x91;
          }
        }
        int x112 = x98;
        if (x112) {
          char  *x113 = x100;
          x87 = 0/*false*/;
        } else {
          char x116 = x99;
          char  *x118 = x100;
          int x119 = x88;
          int x120 = x119 < 0;
          int x128;
          if (x120) {
            x128 = x119;
          } else {
            int x124 = x119 > x123;
            int x127;
            if (x124) {
              x127 = -1;
            } else {
              char x117 = x116 - '0';
              int x125 = x119 * 10;
              int x126 = x125 + x117;
              x127 = x126;
            }
            x128 = x127;
          }
          x88 = x128;
          x86 = x118;
        }
      }
      int x154 = x88;
      char  *x155 = x86;
      x26 = 0/*false*/;
      x27 = x154;
      x28 = x155;
    }
  }
  int x163 = x26;
  if (x163) {
    char  *x164 = x28;
    x25 = x164;
  } else {
    int x167 = x27;
    char  *x168 = x28;
    char x169 = x168[0];
    int x170 = x169 == '\0';
    if (x170) {
      x25 = x168;
    } else {
      int x171 = x169 == '.';
      if (x171) {
        x23 = 0/*false*/;
        x24 = x169;
        char  *x172 = x168+1;
        x25 = x172;
      } else {
        x25 = x168;
      }
    }
  }
  int x186 = x23;
  if (x186) {
    char  *x187 = x25;
    x22 = x187;
  } else {
    char x190 = x24;
    char  *x191 = x25;
    int x198 = 1/*true*/;
    int x199 = 0;
    char  *x200 = 0/*null*/;
    int x201 = 1/*true*/;
    char x202 = '\0';
    char  *x203 = 0/*null*/;
    char x192 = x191[0];
    int x193 = x192 == '\0';
    if (x193) {
      x203 = x191;
    } else {
      int x194 = x192 >= '0';
      int x196;
      if (x194) {
        int x195 = x192 <= '9';
        x196 = x195;
      } else {
        x196 = 0/*false*/;
      }
      if (x196) {
        x201 = 0/*false*/;
        x202 = x192;
        char  *x197 = x191+1;
        x203 = x197;
      } else {
        x203 = x191;
      }
    }
    int x215 = x201;
    if (x215) {
      char  *x216 = x203;
      x200 = x216;
    } else {
      char x219 = x202;
      char  *x221 = x203;
      x198 = 0/*false*/;
      char x220 = x219 - '0';
      x199 = x220;
      x200 = x221;
    }
    int x227 = x198;
    if (x227) {
      char  *x228 = x200;
      x22 = x228;
    } else {
      int x231 = x199;
      char  *x232 = x200;
      char  *x233 = x232;
      int x234 = 1/*true*/;
      int x235 = x231;
      int x121 = INT_MAX;
      int x122 = x121 / 10;
      int x123 = x122 - 10;
      /*@
      loop invariant (((strlen(x233)>=0) && \valid(x233+(0..strlen(x233)))) && ((x235==-1) || (0<=x235)));
      loop assigns x233, x234, x235;
      */
      for (;;) {
        int x236 = x234;
        if (!x236) break;
        char  *x238 = x233;
        int x245 = 1/*true*/;
        char x246 = '\0';
        char  *x247 = 0/*null*/;
        char x239 = x238[0];
        int x240 = x239 == '\0';
        if (x240) {
          x247 = x238;
        } else {
          int x241 = x239 >= '0';
          int x243;
          if (x241) {
            int x242 = x239 <= '9';
            x243 = x242;
          } else {
            x243 = 0/*false*/;
          }
          if (x243) {
            x245 = 0/*false*/;
            x246 = x239;
            char  *x244 = x238+1;
            x247 = x244;
          } else {
            x247 = x238;
          }
        }
        int x259 = x245;
        if (x259) {
          char  *x260 = x247;
          x234 = 0/*false*/;
        } else {
          char x263 = x246;
          char  *x265 = x247;
          int x266 = x235;
          int x267 = x266 < 0;
          int x272;
          if (x267) {
            x272 = x266;
          } else {
            int x268 = x266 > x123;
            int x271;
            if (x268) {
              x271 = -1;
            } else {
              char x264 = x263 - '0';
              int x269 = x266 * 10;
              int x270 = x269 + x264;
              x271 = x270;
            }
            x272 = x271;
          }
          x235 = x272;
          x233 = x265;
        }
      }
      int x298 = x235;
      char  *x299 = x233;
      x20 = 0/*false*/;
      x21 = x298;
      x22 = x299;
    }
  }
  int x307 = x20;
  if (x307) {
    char  *x308 = x22;
    x19 = x308;
  } else {
    int x311 = x21;
    char  *x312 = x22;
    char  *x313 = x312;
    int x314 = 1/*true*/;
    /*@
    loop invariant ((strlen(x313)>=0) && \valid(x313+(0..strlen(x313))));
    loop assigns x313, x314;
    */
    for (;;) {
      int x315 = x314;
      if (!x315) break;
      char  *x317 = x313;
      char x318 = x317[0];
      int x319 = x318 == '\0';
      if (x319) {
        x314 = 0/*false*/;
      } else {
        int x320 = x318 == ' ';
        if (x320) {
          char  *x321 = x317+1;
          x313 = x321;
        } else {
          x314 = 0/*false*/;
        }
      }
    }
    char  *x345 = x313;
    x17 = 0/*false*/;
    x19 = x345;
  }
  int x351 = x17;
  if (x351) {
    char  *x352 = x19;
    x16 = x352;
  } else {
    char  *x356 = x19;
    int x363 = 1/*true*/;
    int x364 = 0;
    char  *x365 = 0/*null*/;
    int x366 = 1/*true*/;
    char x367 = '\0';
    char  *x368 = 0/*null*/;
    char x357 = x356[0];
    int x358 = x357 == '\0';
    if (x358) {
      x368 = x356;
    } else {
      int x359 = x357 >= '0';
      int x361;
      if (x359) {
        int x360 = x357 <= '9';
        x361 = x360;
      } else {
        x361 = 0/*false*/;
      }
      if (x361) {
        x366 = 0/*false*/;
        x367 = x357;
        char  *x362 = x356+1;
        x368 = x362;
      } else {
        x368 = x356;
      }
    }
    int x380 = x366;
    if (x380) {
      char  *x381 = x368;
      x365 = x381;
    } else {
      char x384 = x367;
      char  *x386 = x368;
      x363 = 0/*false*/;
      char x385 = x384 - '0';
      x364 = x385;
      x365 = x386;
    }
    int x392 = x363;
    if (x392) {
      char  *x393 = x365;
      x16 = x393;
    } else {
      int x396 = x364;
      char  *x397 = x365;
      char  *x398 = x397;
      int x399 = 1/*true*/;
      int x400 = x396;
      int x121 = INT_MAX;
      int x122 = x121 / 10;
      int x123 = x122 - 10;
      /*@
      loop invariant (((strlen(x398)>=0) && \valid(x398+(0..strlen(x398)))) && ((x400==-1) || (0<=x400)));
      loop assigns x398, x399, x400;
      */
      for (;;) {
        int x401 = x399;
        if (!x401) break;
        char  *x403 = x398;
        int x410 = 1/*true*/;
        char x411 = '\0';
        char  *x412 = 0/*null*/;
        char x404 = x403[0];
        int x405 = x404 == '\0';
        if (x405) {
          x412 = x403;
        } else {
          int x406 = x404 >= '0';
          int x408;
          if (x406) {
            int x407 = x404 <= '9';
            x408 = x407;
          } else {
            x408 = 0/*false*/;
          }
          if (x408) {
            x410 = 0/*false*/;
            x411 = x404;
            char  *x409 = x403+1;
            x412 = x409;
          } else {
            x412 = x403;
          }
        }
        int x424 = x410;
        if (x424) {
          char  *x425 = x412;
          x399 = 0/*false*/;
        } else {
          char x428 = x411;
          char  *x430 = x412;
          int x431 = x400;
          int x432 = x431 < 0;
          int x437;
          if (x432) {
            x437 = x431;
          } else {
            int x433 = x431 > x123;
            int x436;
            if (x433) {
              x436 = -1;
            } else {
              char x429 = x428 - '0';
              int x434 = x431 * 10;
              int x435 = x434 + x429;
              x436 = x435;
            }
            x437 = x436;
          }
          x400 = x437;
          x398 = x430;
        }
      }
      int x463 = x400;
      char  *x464 = x398;
      x14 = 0/*false*/;
      x15 = x463;
      x16 = x464;
    }
  }
  int x472 = x14;
  if (x472) {
    char  *x473 = x16;
    x13 = x473;
  } else {
    int x476 = x15;
    char  *x477 = x16;
    char  *x478 = x477;
    int x479 = 1/*true*/;
    /*@
    loop invariant ((strlen(x478)>=0) && \valid(x478+(0..strlen(x478))));
    loop assigns x478, x479;
    */
    for (;;) {
      int x480 = x479;
      if (!x480) break;
      char  *x482 = x478;
      char x483 = x482[0];
      int x484 = x483 == '\0';
      if (x484) {
        x479 = 0/*false*/;
      } else {
        int x485 = x483 != '\n';
        if (x485) {
          char  *x486 = x482+1;
          x478 = x486;
        } else {
          x479 = 0/*false*/;
        }
      }
    }
    char  *x510 = x478;
    int x511 = 1/*true*/;
    char  *x513 = 0/*null*/;
    x511 = 0/*false*/;
    x513 = x510;
    int x517 = x511;
    if (x517) {
      char  *x518 = x513;
      x13 = x518;
    } else {
      char  *x522 = x513;
      int x527 = 1/*true*/;
      char x528 = '\0';
      char  *x529 = 0/*null*/;
      char x523 = x522[0];
      int x524 = x523 == '\0';
      if (x524) {
        x529 = x522;
      } else {
        int x525 = x523 == '\n';
        if (x525) {
          x527 = 0/*false*/;
          x528 = x523;
          char  *x526 = x522+1;
          x529 = x526;
        } else {
          x529 = x522;
        }
      }
      int x541 = x527;
      if (x541) {
        char  *x542 = x529;
        x13 = x542;
      } else {
        char x545 = x528;
        char  *x546 = x529;
        x11 = 0/*false*/;
        x12 = x476;
        x13 = x546;
      }
    }
  }
  int x556 = x11;
  if (x556) {
    char  *x557 = x13;
    x10 = x557;
  } else {
    int x560 = x12;
    char  *x561 = x13;
    char  *x562 = x561;
    int x563 = 1/*true*/;
    int x564 = 0;
    int x121 = INT_MAX;
    int x122 = x121 / 10;
    int x123 = x122 - 10;
    int x1227 = -2 == -2;
    /*@
    loop invariant ((strlen(x562)>=0) && \valid(x562+(0..strlen(x562))));
    loop assigns x562, x563, x564;
    */
    for (;;) {
      int x565 = x563;
      if (!x565) break;
      char  *x567 = x562;
      char  *x568 = p_ContentLength(x567);
      int x570 = 1/*true*/;
      int x571 = 0;
      char  *x572 = 0/*null*/;
      int x573 = 1/*true*/;
      int x574 = 0;
      char  *x575 = 0/*null*/;
      int x576 = 1/*true*/;
      int x577 = 0;
      char  *x578 = 0/*null*/;
      int x579 = 1/*true*/;
      int x580 = 0;
      char  *x581 = 0/*null*/;
      int x582 = 1/*true*/;
      int x583 = 0;
      char  *x584 = 0/*null*/;
      int x585 = 1/*true*/;
      int x586 = 0;
      char  *x587 = 0/*null*/;
      int x588 = 1/*true*/;
      char  *x590 = 0/*null*/;
      int x569 = 0 != x568;
      if (x569) {
        x588 = 0/*false*/;
        x590 = x568;
      } else {
        x590 = x567;
      }
      int x598 = x588;
      if (x598) {
        char  *x599 = x590;
      } else {
        char  *x602 = x590;
        x585 = 0/*false*/;
        x586 = 1;
        x587 = x602;
      }
      int x608 = x585;
      if (x608) {
        char  *x609 = p_TransferEncoding(x567);
        int x611 = 1/*true*/;
        char  *x613 = 0/*null*/;
        int x610 = 0 != x609;
        if (x610) {
          x611 = 0/*false*/;
          x613 = x609;
        } else {
          x613 = x567;
        }
        int x621 = x611;
        if (x621) {
          char  *x622 = x613;
        } else {
          char  *x625 = x613;
          x582 = 0/*false*/;
          x583 = 2;
          x584 = x625;
        }
      } else {
        int x632 = x586;
        char  *x633 = x587;
        x582 = 0/*false*/;
        x583 = x632;
        x584 = x633;
      }
      int x639 = x582;
      if (x639) {
        char  *x640 = x567;
        int x641 = 1/*true*/;
        /*@
        loop invariant ((strlen(x640)>=0) && \valid(x640+(0..strlen(x640))));
        loop assigns x640, x641;
        */
        for (;;) {
          int x642 = x641;
          if (!x642) break;
          char  *x644 = x640;
          int x655 = 1/*true*/;
          char x656 = '\0';
          char  *x657 = 0/*null*/;
          char x645 = x644[0];
          int x646 = x645 == '\0';
          if (x646) {
          } else {
            int x647 = x645 >= 'a';
            int x649;
            if (x647) {
              int x648 = x645 <= 'z';
              x649 = x648;
            } else {
              x649 = 0/*false*/;
            }
            int x650 = x645 >= 'A';
            int x652;
            if (x650) {
              int x651 = x645 <= 'Z';
              x652 = x651;
            } else {
              x652 = 0/*false*/;
            }
            int x653 = x649 || x652;
            if (x653) {
              x655 = 0/*false*/;
              x656 = x645;
              char  *x654 = x644+1;
              x657 = x654;
            } else {
            }
          }
          int x665 = x655;
          char x667 = x656;
          char  *x668 = x657;
          if (x665) {
            if (x646) {
              x641 = 0/*false*/;
            } else {
              int x666 = x645 == '-';
              if (x666) {
                char  *x654 = x644+1;
                x640 = x654;
              } else {
                x641 = 0/*false*/;
              }
            }
          } else {
            x640 = x668;
          }
        }
        char  *x696 = x640;
        x579 = 0/*false*/;
        x580 = 0;
        x581 = x696;
      } else {
        int x701 = x583;
        char  *x702 = x584;
        x579 = 0/*false*/;
        x580 = x701;
        x581 = x702;
      }
      int x708 = x579;
      if (x708) {
        char  *x709 = x581;
        x578 = x709;
      } else {
        int x712 = x580;
        char  *x713 = x581;
        char  *x714 = x713;
        int x715 = 1/*true*/;
        /*@
        loop invariant ((strlen(x714)>=0) && \valid(x714+(0..strlen(x714))));
        loop assigns x714, x715;
        */
        for (;;) {
          int x716 = x715;
          if (!x716) break;
          char  *x718 = x714;
          char x719 = x718[0];
          int x720 = x719 == '\0';
          if (x720) {
            x715 = 0/*false*/;
          } else {
            int x721 = x719 == ' ';
            if (x721) {
              char  *x722 = x718+1;
              x714 = x722;
            } else {
              x715 = 0/*false*/;
            }
          }
        }
        char  *x746 = x714;
        x576 = 0/*false*/;
        x577 = x712;
        x578 = x746;
      }
      int x752 = x576;
      if (x752) {
        char  *x753 = x578;
        x575 = x753;
      } else {
        int x756 = x577;
        char  *x757 = x578;
        int x762 = 1/*true*/;
        char x763 = '\0';
        char  *x764 = 0/*null*/;
        char x758 = x757[0];
        int x759 = x758 == '\0';
        if (x759) {
          x764 = x757;
        } else {
          int x760 = x758 == ':';
          if (x760) {
            x762 = 0/*false*/;
            x763 = x758;
            char  *x761 = x757+1;
            x764 = x761;
          } else {
            x764 = x757;
          }
        }
        int x776 = x762;
        if (x776) {
          char  *x777 = x764;
          x575 = x777;
        } else {
          char x780 = x763;
          char  *x781 = x764;
          x573 = 0/*false*/;
          x574 = x756;
          x575 = x781;
        }
      }
      int x789 = x573;
      if (x789) {
        char  *x790 = x575;
        x572 = x790;
      } else {
        int x793 = x574;
        char  *x794 = x575;
        char  *x795 = x794;
        int x796 = 1/*true*/;
        /*@
        loop invariant ((strlen(x795)>=0) && \valid(x795+(0..strlen(x795))));
        loop assigns x795, x796;
        */
        for (;;) {
          int x797 = x796;
          if (!x797) break;
          char  *x799 = x795;
          char x800 = x799[0];
          int x801 = x800 == '\0';
          if (x801) {
            x796 = 0/*false*/;
          } else {
            int x802 = x800 == ' ';
            if (x802) {
              char  *x803 = x799+1;
              x795 = x803;
            } else {
              x796 = 0/*false*/;
            }
          }
        }
        char  *x827 = x795;
        x570 = 0/*false*/;
        x571 = x793;
        x572 = x827;
      }
      int x833 = x570;
      if (x833) {
        char  *x834 = x572;
        x563 = 0/*false*/;
      } else {
        int x837 = x571;
        char  *x838 = x572;
        char  *x840 = p_chunked(x838);
        char  *x849 = x838;
        int x850 = 1/*true*/;
        /*@
        loop invariant ((strlen(x849)>=0) && \valid(x849+(0..strlen(x849))));
        loop assigns x849, x850;
        */
        for (;;) {
          int x851 = x850;
          if (!x851) break;
          char  *x853 = x849;
          char x854 = x853[0];
          int x855 = x854 == '\0';
          if (x855) {
            x850 = 0/*false*/;
          } else {
            int x856 = x854 != '\n';
            if (x856) {
              char  *x857 = x853+1;
              x849 = x857;
            } else {
              x850 = 0/*false*/;
            }
          }
        }
        char  *x881 = x849;
        int x839 = x837 == 2;
        if (x839) {
          int x882 = 1/*true*/;
          int x883 = 0;
          char  *x884 = 0/*null*/;
          int x885 = 1/*true*/;
          int x886 = 0;
          char  *x887 = 0/*null*/;
          int x888 = 1/*true*/;
          char  *x890 = 0/*null*/;
          int x841 = 0 != x840;
          if (x841) {
            x888 = 0/*false*/;
            x890 = x840;
          } else {
            x890 = x838;
          }
          int x898 = x888;
          if (x898) {
            char  *x899 = x890;
            x887 = x899;
          } else {
            char  *x903 = x890;
            x885 = 0/*false*/;
            x886 = -3;
            x887 = x903;
          }
          int x909 = x885;
          if (x909) {
            char  *x910 = x887;
            x884 = x910;
          } else {
            int x913 = x886;
            char  *x914 = x887;
            char  *x915 = x914;
            int x916 = 1/*true*/;
            /*@
            loop invariant ((strlen(x915)>=0) && \valid(x915+(0..strlen(x915))));
            loop assigns x915, x916;
            */
            for (;;) {
              int x917 = x916;
              if (!x917) break;
              char  *x919 = x915;
              char x920 = x919[0];
              int x921 = x920 == '\0';
              if (x921) {
                x916 = 0/*false*/;
              } else {
                int x922 = x920 == ' ';
                if (x922) {
                  char  *x923 = x919+1;
                  x915 = x923;
                } else {
                  x916 = 0/*false*/;
                }
              }
            }
            char  *x947 = x915;
            x882 = 0/*false*/;
            x883 = x913;
            x884 = x947;
          }
          int x953 = x882;
          if (x953) {
            char  *x954 = x884;
            x563 = 0/*false*/;
          } else {
            int x957 = x883;
            char  *x958 = x884;
            int x963 = 1/*true*/;
            char x964 = '\0';
            char  *x965 = 0/*null*/;
            char x959 = x958[0];
            int x960 = x959 == '\0';
            if (x960) {
              x965 = x958;
            } else {
              int x961 = x959 == '\n';
              if (x961) {
                x963 = 0/*false*/;
                x964 = x959;
                char  *x962 = x958+1;
                x965 = x962;
              } else {
                x965 = x958;
              }
            }
            int x977 = x963;
            if (x977) {
              char  *x978 = x965;
              x563 = 0/*false*/;
            } else {
              char x981 = x964;
              char  *x982 = x965;
              int x983 = x564;
              int x984 = x957 == -2;
              int x985;
              if (x984) {
                x985 = x983;
              } else {
                x985 = x957;
              }
              x564 = x985;
              x562 = x982;
            }
          }
        } else {
          int x842 = x837 == 1;
          if (x842) {
            int x993 = 1/*true*/;
            int x994 = 0;
            char  *x995 = 0/*null*/;
            int x996 = 1/*true*/;
            int x997 = 0;
            char  *x998 = 0/*null*/;
            int x999 = 1/*true*/;
            int x1000 = 0;
            char  *x1001 = 0/*null*/;
            int x1002 = 1/*true*/;
            char x1003 = '\0';
            char  *x1004 = 0/*null*/;
            char x843 = x838[0];
            int x844 = x843 == '\0';
            if (x844) {
              x1004 = x838;
            } else {
              int x845 = x843 >= '0';
              int x847;
              if (x845) {
                int x846 = x843 <= '9';
                x847 = x846;
              } else {
                x847 = 0/*false*/;
              }
              if (x847) {
                x1002 = 0/*false*/;
                x1003 = x843;
                char  *x848 = x838+1;
                x1004 = x848;
              } else {
                x1004 = x838;
              }
            }
            int x1016 = x1002;
            if (x1016) {
              char  *x1017 = x1004;
              x1001 = x1017;
            } else {
              char x1020 = x1003;
              char  *x1022 = x1004;
              x999 = 0/*false*/;
              char x1021 = x1020 - '0';
              x1000 = x1021;
              x1001 = x1022;
            }
            int x1028 = x999;
            if (x1028) {
              char  *x1029 = x1001;
              x998 = x1029;
            } else {
              int x1032 = x1000;
              char  *x1033 = x1001;
              char  *x1034 = x1033;
              int x1035 = 1/*true*/;
              int x1036 = x1032;
              /*@
              loop invariant (((strlen(x1034)>=0) && \valid(x1034+(0..strlen(x1034)))) && ((x1036==-1) || (0<=x1036)));
              loop assigns x1034, x1035, x1036;
              */
              for (;;) {
                int x1037 = x1035;
                if (!x1037) break;
                char  *x1039 = x1034;
                int x1046 = 1/*true*/;
                char x1047 = '\0';
                char  *x1048 = 0/*null*/;
                char x1040 = x1039[0];
                int x1041 = x1040 == '\0';
                if (x1041) {
                  x1048 = x1039;
                } else {
                  int x1042 = x1040 >= '0';
                  int x1044;
                  if (x1042) {
                    int x1043 = x1040 <= '9';
                    x1044 = x1043;
                  } else {
                    x1044 = 0/*false*/;
                  }
                  if (x1044) {
                    x1046 = 0/*false*/;
                    x1047 = x1040;
                    char  *x1045 = x1039+1;
                    x1048 = x1045;
                  } else {
                    x1048 = x1039;
                  }
                }
                int x1060 = x1046;
                if (x1060) {
                  char  *x1061 = x1048;
                  x1035 = 0/*false*/;
                } else {
                  char x1064 = x1047;
                  char  *x1066 = x1048;
                  int x1067 = x1036;
                  int x1068 = x1067 < 0;
                  int x1073;
                  if (x1068) {
                    x1073 = x1067;
                  } else {
                    int x1069 = x1067 > x123;
                    int x1072;
                    if (x1069) {
                      x1072 = -1;
                    } else {
                      char x1065 = x1064 - '0';
                      int x1070 = x1067 * 10;
                      int x1071 = x1070 + x1065;
                      x1072 = x1071;
                    }
                    x1073 = x1072;
                  }
                  x1036 = x1073;
                  x1034 = x1066;
                }
              }
              int x1099 = x1036;
              char  *x1100 = x1034;
              x996 = 0/*false*/;
              x997 = x1099;
              x998 = x1100;
            }
            int x1106 = x996;
            if (x1106) {
              char  *x1107 = x998;
              x995 = x1107;
            } else {
              int x1110 = x997;
              char  *x1111 = x998;
              char  *x1112 = x1111;
              int x1113 = 1/*true*/;
              /*@
              loop invariant ((strlen(x1112)>=0) && \valid(x1112+(0..strlen(x1112))));
              loop assigns x1112, x1113;
              */
              for (;;) {
                int x1114 = x1113;
                if (!x1114) break;
                char  *x1116 = x1112;
                char x1117 = x1116[0];
                int x1118 = x1117 == '\0';
                if (x1118) {
                  x1113 = 0/*false*/;
                } else {
                  int x1119 = x1117 == ' ';
                  if (x1119) {
                    char  *x1120 = x1116+1;
                    x1112 = x1120;
                  } else {
                    x1113 = 0/*false*/;
                  }
                }
              }
              char  *x1144 = x1112;
              x993 = 0/*false*/;
              x994 = x1110;
              x995 = x1144;
            }
            int x1150 = x993;
            if (x1150) {
              char  *x1151 = x995;
              x563 = 0/*false*/;
            } else {
              int x1154 = x994;
              char  *x1155 = x995;
              int x1160 = 1/*true*/;
              char x1161 = '\0';
              char  *x1162 = 0/*null*/;
              char x1156 = x1155[0];
              int x1157 = x1156 == '\0';
              if (x1157) {
                x1162 = x1155;
              } else {
                int x1158 = x1156 == '\n';
                if (x1158) {
                  x1160 = 0/*false*/;
                  x1161 = x1156;
                  char  *x1159 = x1155+1;
                  x1162 = x1159;
                } else {
                  x1162 = x1155;
                }
              }
              int x1174 = x1160;
              if (x1174) {
                char  *x1175 = x1162;
                x563 = 0/*false*/;
              } else {
                char x1178 = x1161;
                char  *x1179 = x1162;
                int x1180 = x564;
                int x1181 = x1154 == -2;
                int x1182;
                if (x1181) {
                  x1182 = x1180;
                } else {
                  x1182 = x1154;
                }
                x564 = x1182;
                x562 = x1179;
              }
            }
          } else {
            int x1190 = 1/*true*/;
            char  *x1192 = 0/*null*/;
            x1190 = 0/*false*/;
            x1192 = x881;
            int x1196 = x1190;
            if (x1196) {
              char  *x1197 = x1192;
              x563 = 0/*false*/;
            } else {
              char  *x1201 = x1192;
              int x1206 = 1/*true*/;
              char x1207 = '\0';
              char  *x1208 = 0/*null*/;
              char x1202 = x1201[0];
              int x1203 = x1202 == '\0';
              if (x1203) {
                x1208 = x1201;
              } else {
                int x1204 = x1202 == '\n';
                if (x1204) {
                  x1206 = 0/*false*/;
                  x1207 = x1202;
                  char  *x1205 = x1201+1;
                  x1208 = x1205;
                } else {
                  x1208 = x1201;
                }
              }
              int x1220 = x1206;
              if (x1220) {
                char  *x1221 = x1208;
                x563 = 0/*false*/;
              } else {
                char x1224 = x1207;
                char  *x1225 = x1208;
                int x1226 = x564;
                int x1228;
                if (x1227) {
                  x1228 = x1226;
                } else {
                  x1228 = -2;
                }
                x564 = x1228;
                x562 = x1225;
              }
            }
          }
        }
      }
    }
    int x1257 = x564;
    char  *x1258 = x562;
    x8 = 0/*false*/;
    x9 = x1257;
    x10 = x1258;
  }
  int x1264 = x8;
  if (x1264) {
    char  *x1265 = x10;
    x7 = x1265;
  } else {
    int x1268 = x9;
    char  *x1269 = x10;
    int x1274 = 1/*true*/;
    char x1275 = '\0';
    char  *x1276 = 0/*null*/;
    char x1270 = x1269[0];
    int x1271 = x1270 == '\0';
    if (x1271) {
      x1276 = x1269;
    } else {
      int x1272 = x1270 == '\n';
      if (x1272) {
        x1274 = 0/*false*/;
        x1275 = x1270;
        char  *x1273 = x1269+1;
        x1276 = x1273;
      } else {
        x1276 = x1269;
      }
    }
    int x1288 = x1274;
    if (x1288) {
      char  *x1289 = x1276;
      x7 = x1289;
    } else {
      char x1292 = x1275;
      char  *x1293 = x1276;
      x5 = 0/*false*/;
      x6 = x1268;
      x7 = x1293;
    }
  }
  int x1301 = x5;
  if (x1301) {
    char  *x1302 = x7;
  } else {
    int x1304 = x6;
    char  *x1305 = x7;
    char  *x1307 = x1305;
    int x1308 = 1/*true*/;
    int x1309 = 0;
    int x121 = INT_MAX;
    int x1469 = x121 / 16;
    int x1470 = x1469 - 16;
    /*@
    loop invariant (((strlen(x1307)>=0) && \valid(x1307+(0..strlen(x1307)))) && ((x1309==-1) || (0<=x1309)));
    loop assigns x1307, x1308, x1309;
    */
    for (;;) {
      int x1310 = x1308;
      if (!x1310) break;
      char  *x1312 = x1307;
      int x1319 = 1/*true*/;
      int x1320 = 0;
      char  *x1321 = 0/*null*/;
      int x1322 = 1/*true*/;
      int x1323 = 0;
      char  *x1324 = 0/*null*/;
      int x1325 = 1/*true*/;
      int x1326 = 0;
      char  *x1327 = 0/*null*/;
      int x1328 = 1/*true*/;
      int x1329 = 0;
      char  *x1330 = 0/*null*/;
      int x1331 = 1/*true*/;
      char x1332 = '\0';
      char  *x1333 = 0/*null*/;
      char x1313 = x1312[0];
      int x1314 = x1313 == '\0';
      if (x1314) {
        x1333 = x1312;
      } else {
        int x1315 = x1313 >= '0';
        int x1317;
        if (x1315) {
          int x1316 = x1313 <= '9';
          x1317 = x1316;
        } else {
          x1317 = 0/*false*/;
        }
        if (x1317) {
          x1331 = 0/*false*/;
          x1332 = x1313;
          char  *x1318 = x1312+1;
          x1333 = x1318;
        } else {
          x1333 = x1312;
        }
      }
      int x1345 = x1331;
      if (x1345) {
        char  *x1346 = x1333;
      } else {
        char x1348 = x1332;
        char  *x1350 = x1333;
        x1328 = 0/*false*/;
        char x1349 = x1348 - '0';
        x1329 = x1349;
        x1330 = x1350;
      }
      int x1356 = x1328;
      if (x1356) {
        int x1360 = 1/*true*/;
        char x1361 = '\0';
        char  *x1362 = 0/*null*/;
        if (x1314) {
          x1362 = x1312;
        } else {
          int x1357 = x1313 >= 'a';
          int x1359;
          if (x1357) {
            int x1358 = x1313 <= 'f';
            x1359 = x1358;
          } else {
            x1359 = 0/*false*/;
          }
          if (x1359) {
            x1360 = 0/*false*/;
            x1361 = x1313;
            char  *x1318 = x1312+1;
            x1362 = x1318;
          } else {
            x1362 = x1312;
          }
        }
        int x1374 = x1360;
        if (x1374) {
          char  *x1375 = x1362;
          x1327 = x1375;
        } else {
          char x1378 = x1361;
          char  *x1381 = x1362;
          x1325 = 0/*false*/;
          char x1379 = x1378 - 'a';
          int x1380 = 10 + x1379;
          x1326 = x1380;
          x1327 = x1381;
        }
      } else {
        int x1388 = x1329;
        char  *x1389 = x1330;
        x1325 = 0/*false*/;
        x1326 = x1388;
        x1327 = x1389;
      }
      int x1395 = x1325;
      if (x1395) {
        char  *x1396 = x1327;
        x1324 = x1396;
      } else {
        int x1399 = x1326;
        char  *x1400 = x1327;
        char  *x1401 = x1400;
        int x1402 = 1/*true*/;
        int x1403 = x1399;
        /*@
        loop invariant (((strlen(x1401)>=0) && \valid(x1401+(0..strlen(x1401)))) && ((x1403==-1) || (0<=x1403)));
        loop assigns x1401, x1402, x1403;
        */
        for (;;) {
          int x1404 = x1402;
          if (!x1404) break;
          char  *x1406 = x1401;
          int x1413 = 1/*true*/;
          int x1414 = 0;
          char  *x1415 = 0/*null*/;
          int x1416 = 1/*true*/;
          char x1417 = '\0';
          char  *x1418 = 0/*null*/;
          char x1407 = x1406[0];
          int x1408 = x1407 == '\0';
          if (x1408) {
            x1418 = x1406;
          } else {
            int x1409 = x1407 >= '0';
            int x1411;
            if (x1409) {
              int x1410 = x1407 <= '9';
              x1411 = x1410;
            } else {
              x1411 = 0/*false*/;
            }
            if (x1411) {
              x1416 = 0/*false*/;
              x1417 = x1407;
              char  *x1412 = x1406+1;
              x1418 = x1412;
            } else {
              x1418 = x1406;
            }
          }
          int x1430 = x1416;
          if (x1430) {
            char  *x1431 = x1418;
          } else {
            char x1433 = x1417;
            char  *x1435 = x1418;
            x1413 = 0/*false*/;
            char x1434 = x1433 - '0';
            x1414 = x1434;
            x1415 = x1435;
          }
          int x1441 = x1413;
          if (x1441) {
            int x1445 = 1/*true*/;
            char x1446 = '\0';
            char  *x1447 = 0/*null*/;
            if (x1408) {
              x1447 = x1406;
            } else {
              int x1442 = x1407 >= 'a';
              int x1444;
              if (x1442) {
                int x1443 = x1407 <= 'f';
                x1444 = x1443;
              } else {
                x1444 = 0/*false*/;
              }
              if (x1444) {
                x1445 = 0/*false*/;
                x1446 = x1407;
                char  *x1412 = x1406+1;
                x1447 = x1412;
              } else {
                x1447 = x1406;
              }
            }
            int x1459 = x1445;
            if (x1459) {
              char  *x1460 = x1447;
              x1402 = 0/*false*/;
            } else {
              char x1463 = x1446;
              char  *x1466 = x1447;
              int x1467 = x1403;
              int x1468 = x1467 < 0;
              int x1475;
              if (x1468) {
                x1475 = x1467;
              } else {
                int x1471 = x1467 > x1470;
                int x1474;
                if (x1471) {
                  x1474 = -1;
                } else {
                  char x1464 = x1463 - 'a';
                  int x1465 = 10 + x1464;
                  int x1472 = x1467 * 16;
                  int x1473 = x1472 + x1465;
                  x1474 = x1473;
                }
                x1475 = x1474;
              }
              x1403 = x1475;
              x1401 = x1466;
            }
          } else {
            int x1481 = x1414;
            char  *x1482 = x1415;
            int x1483 = x1403;
            int x1484 = x1483 < 0;
            int x1489;
            if (x1484) {
              x1489 = x1483;
            } else {
              int x1485 = x1483 > x1470;
              int x1488;
              if (x1485) {
                x1488 = -1;
              } else {
                int x1486 = x1483 * 16;
                int x1487 = x1486 + x1481;
                x1488 = x1487;
              }
              x1489 = x1488;
            }
            x1403 = x1489;
            x1401 = x1482;
          }
        }
        int x1515 = x1403;
        char  *x1516 = x1401;
        x1322 = 0/*false*/;
        x1323 = x1515;
        x1324 = x1516;
      }
      int x1522 = x1322;
      if (x1522) {
        char  *x1523 = x1324;
        x1321 = x1523;
      } else {
        int x1526 = x1323;
        char  *x1527 = x1324;
        int x1532 = 1/*true*/;
        char x1533 = '\0';
        char  *x1534 = 0/*null*/;
        char x1528 = x1527[0];
        int x1529 = x1528 == '\0';
        if (x1529) {
          x1534 = x1527;
        } else {
          int x1530 = x1528 == '\n';
          if (x1530) {
            x1532 = 0/*false*/;
            x1533 = x1528;
            char  *x1531 = x1527+1;
            x1534 = x1531;
          } else {
            x1534 = x1527;
          }
        }
        int x1546 = x1532;
        if (x1546) {
          char  *x1547 = x1534;
          x1321 = x1547;
        } else {
          char x1550 = x1533;
          char  *x1551 = x1534;
          x1319 = 0/*false*/;
          x1320 = x1526;
          x1321 = x1551;
        }
      }
      int x1559 = x1319;
      if (x1559) {
        char  *x1560 = x1321;
        x1308 = 0/*false*/;
      } else {
        int x1563 = x1320;
        char  *x1564 = x1321;
        int x1566 = 1/*true*/;
        char  *x1567 = x1564;
        /*@
        loop invariant ((0<=x1569) && ((strlen(x1567)>=0) && \valid(x1567+(0..strlen(x1567)))));
        loop assigns x1569, x1566, x1567;
        loop variant (x1320-x1569);
        */
        for(int x1569=0; x1569 < x1563; x1569++) {
          int x1570 = x1566;
          if (x1570) {
            char  *x1571 = x1567;
            char x1572 = x1571[0];
            int x1573 = x1572 == '\0';
            if (x1573) {
              x1566 = 0/*false*/;
            } else {
              if (1/*true*/) {
                char  *x1574 = x1571+1;
                x1567 = x1574;
              } else {
                x1566 = 0/*false*/;
              }
            }
          } else {
          }
        }
        int x1604 = x1566;
        char  *x1605 = x1567;
        int x1565 = x1563 < 0;
        if (x1565) {
          x1308 = 0/*false*/;
        } else {
          int x1608 = 1/*true*/;
          int x1609 = 0;
          char  *x1610 = 0/*null*/;
          int x1611 = 1/*true*/;
          char  *x1613 = 0/*null*/;
          if (x1604) {
            x1611 = 0/*false*/;
            x1613 = x1605;
          } else {
            x1613 = x1564;
          }
          int x1621 = x1611;
          if (x1621) {
            char  *x1622 = x1613;
            x1610 = x1622;
          } else {
            char  *x1626 = x1613;
            x1608 = 0/*false*/;
            x1609 = x1563;
            x1610 = x1626;
          }
          int x1632 = x1608;
          if (x1632) {
            char  *x1633 = x1610;
            x1308 = 0/*false*/;
          } else {
            int x1636 = x1609;
            char  *x1637 = x1610;
            int x1642 = 1/*true*/;
            char x1643 = '\0';
            char  *x1644 = 0/*null*/;
            char x1638 = x1637[0];
            int x1639 = x1638 == '\0';
            if (x1639) {
              x1644 = x1637;
            } else {
              int x1640 = x1638 == '\n';
              if (x1640) {
                x1642 = 0/*false*/;
                x1643 = x1638;
                char  *x1641 = x1637+1;
                x1644 = x1641;
              } else {
                x1644 = x1637;
              }
            }
            int x1656 = x1642;
            if (x1656) {
              char  *x1657 = x1644;
              x1308 = 0/*false*/;
            } else {
              char x1660 = x1643;
              char  *x1661 = x1644;
              int x1662 = x1309;
              int x1663 = x1662 < 0;
              int x1668;
              if (x1663) {
                x1668 = x1662;
              } else {
                int x1664 = x121 - x1636;
                int x1665 = x1662 > x1664;
                int x1667;
                if (x1665) {
                  x1667 = -1;
                } else {
                  int x1666 = x1662 + x1636;
                  x1667 = x1666;
                }
                x1668 = x1667;
              }
              x1309 = x1668;
              x1307 = x1661;
            }
          }
        }
      }
    }
    int x1700 = x1309;
    char  *x1701 = x1307;
    int x1703 = 1/*true*/;
    char  *x1704 = x1305;
    /*@
    loop invariant ((0<=x1706) && ((strlen(x1704)>=0) && \valid(x1704+(0..strlen(x1704)))));
    loop assigns x1706, x1703, x1704;
    loop variant (x6-x1706);
    */
    for(int x1706=0; x1706 < x1304; x1706++) {
      int x1707 = x1703;
      if (x1707) {
        char  *x1708 = x1704;
        char x1709 = x1708[0];
        int x1710 = x1709 == '\0';
        if (x1710) {
          x1703 = 0/*false*/;
        } else {
          if (1/*true*/) {
            char  *x1711 = x1708+1;
            x1704 = x1711;
          } else {
            x1703 = 0/*false*/;
          }
        }
      } else {
      }
    }
    int x1741 = x1703;
    char  *x1742 = x1704;
    int x1306 = x1304 == -3;
    if (x1306) {
      char x1743 = x1701[0];
      int x1744 = x1743 == '\0';
      if (x1744) {
        x2 = x1700;
      } else {
      }
    } else {
      int x1702 = x1304 < 0;
      if (x1702) {
      } else {
        int x1749 = 1/*true*/;
        int x1750 = 0;
        char  *x1751 = 0/*null*/;
        int x1752 = 1/*true*/;
        char  *x1754 = 0/*null*/;
        if (x1741) {
          x1752 = 0/*false*/;
          x1754 = x1742;
        } else {
          x1754 = x1305;
        }
        int x1762 = x1752;
        if (x1762) {
          char  *x1763 = x1754;
          x1751 = x1763;
        } else {
          char  *x1767 = x1754;
          x1749 = 0/*false*/;
          x1750 = x1304;
          x1751 = x1767;
        }
        int x1773 = x1749;
        if (x1773) {
          char  *x1774 = x1751;
        } else {
          int x1776 = x1750;
          char  *x1777 = x1751;
          int x1782 = 1/*true*/;
          char x1783 = '\0';
          char  *x1784 = 0/*null*/;
          char x1778 = x1777[0];
          int x1779 = x1778 == '\0';
          if (x1779) {
            x1784 = x1777;
          } else {
            int x1780 = x1778 == '\n';
            if (x1780) {
              x1782 = 0/*false*/;
              x1783 = x1778;
              char  *x1781 = x1777+1;
              x1784 = x1781;
            } else {
              x1784 = x1777;
            }
          }
          int x1796 = x1782;
          if (x1796) {
            char  *x1797 = x1784;
          } else {
            char x1799 = x1783;
            char  *x1800 = x1784;
            char x1801 = x1800[0];
            int x1802 = x1801 == '\0';
            if (x1802) {
              x2 = x1776;
            } else {
            }
          }
        }
      }
    }
  }
  int x1816 = x2;
  return x1816;
}
/*@
requires ((strlen(x1832)>=0) && \valid(x1832+(0..strlen(x1832))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_HTTP(char  * x1832) {
  char  *x1834 = x1832;
  int x1839 = 1/*true*/;
  char x1840 = '\0';
  char  *x1841 = 0/*null*/;
  char x1835 = x1832[0];
  int x1836 = x1835 == '\0';
  if (x1836) {
    x1841 = x1832;
  } else {
    int x1837 = x1835 == 'H';
    if (x1837) {
      x1839 = 0/*false*/;
      x1840 = x1835;
      char  *x1838 = x1832+1;
      x1841 = x1838;
    } else {
      x1841 = x1832;
    }
  }
  int x1853 = x1839;
  if (x1853) {
    char  *x1854 = x1841;
    x1834 = 0;
  } else {
    char x1857 = x1840;
    char  *x1858 = x1841;
    int x1863 = 1/*true*/;
    char x1864 = '\0';
    char  *x1865 = 0/*null*/;
    char x1859 = x1858[0];
    int x1860 = x1859 == '\0';
    if (x1860) {
      x1865 = x1858;
    } else {
      int x1861 = x1859 == 'T';
      if (x1861) {
        x1863 = 0/*false*/;
        x1864 = x1859;
        char  *x1862 = x1858+1;
        x1865 = x1862;
      } else {
        x1865 = x1858;
      }
    }
    int x1877 = x1863;
    if (x1877) {
      char  *x1878 = x1865;
      x1834 = 0;
    } else {
      char x1881 = x1864;
      char  *x1882 = x1865;
      int x1887 = 1/*true*/;
      char x1888 = '\0';
      char  *x1889 = 0/*null*/;
      char x1883 = x1882[0];
      int x1884 = x1883 == '\0';
      if (x1884) {
        x1889 = x1882;
      } else {
        int x1885 = x1883 == 'T';
        if (x1885) {
          x1887 = 0/*false*/;
          x1888 = x1883;
          char  *x1886 = x1882+1;
          x1889 = x1886;
        } else {
          x1889 = x1882;
        }
      }
      int x1901 = x1887;
      if (x1901) {
        char  *x1902 = x1889;
        x1834 = 0;
      } else {
        char x1905 = x1888;
        char  *x1906 = x1889;
        int x1911 = 1/*true*/;
        char x1912 = '\0';
        char  *x1913 = 0/*null*/;
        char x1907 = x1906[0];
        int x1908 = x1907 == '\0';
        if (x1908) {
          x1913 = x1906;
        } else {
          int x1909 = x1907 == 'P';
          if (x1909) {
            x1911 = 0/*false*/;
            x1912 = x1907;
            char  *x1910 = x1906+1;
            x1913 = x1910;
          } else {
            x1913 = x1906;
          }
        }
        int x1925 = x1911;
        if (x1925) {
          char  *x1926 = x1913;
          x1834 = 0;
        } else {
          char x1929 = x1912;
          char  *x1930 = x1913;
          int x1935 = 1/*true*/;
          char x1936 = '\0';
          char  *x1937 = 0/*null*/;
          char x1931 = x1930[0];
          int x1932 = x1931 == '\0';
          if (x1932) {
            x1937 = x1930;
          } else {
            int x1933 = x1931 == '/';
            if (x1933) {
              x1935 = 0/*false*/;
              x1936 = x1931;
              char  *x1934 = x1930+1;
              x1937 = x1934;
            } else {
              x1937 = x1930;
            }
          }
          int x1949 = x1935;
          if (x1949) {
            char  *x1950 = x1937;
            x1834 = 0;
          } else {
            char x1953 = x1936;
            char  *x1954 = x1937;
            x1834 = x1954;
          }
        }
      }
    }
  }
  char  *x1966 = x1834;
  return x1966;
}
/*@
requires ((strlen(x1982)>=0) && \valid(x1982+(0..strlen(x1982))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_ContentLength(char  * x1982) {
  char  *x1984 = x1982;
  int x1989 = 1/*true*/;
  char x1990 = '\0';
  char  *x1991 = 0/*null*/;
  char x1985 = x1982[0];
  int x1986 = x1985 == '\0';
  if (x1986) {
    x1991 = x1982;
  } else {
    int x1987 = x1985 == 'C';
    if (x1987) {
      x1989 = 0/*false*/;
      x1990 = x1985;
      char  *x1988 = x1982+1;
      x1991 = x1988;
    } else {
      x1991 = x1982;
    }
  }
  int x2003 = x1989;
  if (x2003) {
    char  *x2004 = x1991;
    x1984 = 0;
  } else {
    char x2007 = x1990;
    char  *x2008 = x1991;
    int x2013 = 1/*true*/;
    char x2014 = '\0';
    char  *x2015 = 0/*null*/;
    char x2009 = x2008[0];
    int x2010 = x2009 == '\0';
    if (x2010) {
      x2015 = x2008;
    } else {
      int x2011 = x2009 == 'o';
      if (x2011) {
        x2013 = 0/*false*/;
        x2014 = x2009;
        char  *x2012 = x2008+1;
        x2015 = x2012;
      } else {
        x2015 = x2008;
      }
    }
    int x2027 = x2013;
    if (x2027) {
      char  *x2028 = x2015;
      x1984 = 0;
    } else {
      char x2031 = x2014;
      char  *x2032 = x2015;
      int x2037 = 1/*true*/;
      char x2038 = '\0';
      char  *x2039 = 0/*null*/;
      char x2033 = x2032[0];
      int x2034 = x2033 == '\0';
      if (x2034) {
        x2039 = x2032;
      } else {
        int x2035 = x2033 == 'n';
        if (x2035) {
          x2037 = 0/*false*/;
          x2038 = x2033;
          char  *x2036 = x2032+1;
          x2039 = x2036;
        } else {
          x2039 = x2032;
        }
      }
      int x2051 = x2037;
      if (x2051) {
        char  *x2052 = x2039;
        x1984 = 0;
      } else {
        char x2055 = x2038;
        char  *x2056 = x2039;
        int x2061 = 1/*true*/;
        char x2062 = '\0';
        char  *x2063 = 0/*null*/;
        char x2057 = x2056[0];
        int x2058 = x2057 == '\0';
        if (x2058) {
          x2063 = x2056;
        } else {
          int x2059 = x2057 == 't';
          if (x2059) {
            x2061 = 0/*false*/;
            x2062 = x2057;
            char  *x2060 = x2056+1;
            x2063 = x2060;
          } else {
            x2063 = x2056;
          }
        }
        int x2075 = x2061;
        if (x2075) {
          char  *x2076 = x2063;
          x1984 = 0;
        } else {
          char x2079 = x2062;
          char  *x2080 = x2063;
          int x2085 = 1/*true*/;
          char x2086 = '\0';
          char  *x2087 = 0/*null*/;
          char x2081 = x2080[0];
          int x2082 = x2081 == '\0';
          if (x2082) {
            x2087 = x2080;
          } else {
            int x2083 = x2081 == 'e';
            if (x2083) {
              x2085 = 0/*false*/;
              x2086 = x2081;
              char  *x2084 = x2080+1;
              x2087 = x2084;
            } else {
              x2087 = x2080;
            }
          }
          int x2099 = x2085;
          if (x2099) {
            char  *x2100 = x2087;
            x1984 = 0;
          } else {
            char x2103 = x2086;
            char  *x2104 = x2087;
            int x2109 = 1/*true*/;
            char x2110 = '\0';
            char  *x2111 = 0/*null*/;
            char x2105 = x2104[0];
            int x2106 = x2105 == '\0';
            if (x2106) {
              x2111 = x2104;
            } else {
              int x2107 = x2105 == 'n';
              if (x2107) {
                x2109 = 0/*false*/;
                x2110 = x2105;
                char  *x2108 = x2104+1;
                x2111 = x2108;
              } else {
                x2111 = x2104;
              }
            }
            int x2123 = x2109;
            if (x2123) {
              char  *x2124 = x2111;
              x1984 = 0;
            } else {
              char x2127 = x2110;
              char  *x2128 = x2111;
              int x2133 = 1/*true*/;
              char x2134 = '\0';
              char  *x2135 = 0/*null*/;
              char x2129 = x2128[0];
              int x2130 = x2129 == '\0';
              if (x2130) {
                x2135 = x2128;
              } else {
                int x2131 = x2129 == 't';
                if (x2131) {
                  x2133 = 0/*false*/;
                  x2134 = x2129;
                  char  *x2132 = x2128+1;
                  x2135 = x2132;
                } else {
                  x2135 = x2128;
                }
              }
              int x2147 = x2133;
              if (x2147) {
                char  *x2148 = x2135;
                x1984 = 0;
              } else {
                char x2151 = x2134;
                char  *x2152 = x2135;
                int x2157 = 1/*true*/;
                char x2158 = '\0';
                char  *x2159 = 0/*null*/;
                char x2153 = x2152[0];
                int x2154 = x2153 == '\0';
                if (x2154) {
                  x2159 = x2152;
                } else {
                  int x2155 = x2153 == '-';
                  if (x2155) {
                    x2157 = 0/*false*/;
                    x2158 = x2153;
                    char  *x2156 = x2152+1;
                    x2159 = x2156;
                  } else {
                    x2159 = x2152;
                  }
                }
                int x2171 = x2157;
                if (x2171) {
                  char  *x2172 = x2159;
                  x1984 = 0;
                } else {
                  char x2175 = x2158;
                  char  *x2176 = x2159;
                  int x2181 = 1/*true*/;
                  char x2182 = '\0';
                  char  *x2183 = 0/*null*/;
                  char x2177 = x2176[0];
                  int x2178 = x2177 == '\0';
                  if (x2178) {
                    x2183 = x2176;
                  } else {
                    int x2179 = x2177 == 'L';
                    if (x2179) {
                      x2181 = 0/*false*/;
                      x2182 = x2177;
                      char  *x2180 = x2176+1;
                      x2183 = x2180;
                    } else {
                      x2183 = x2176;
                    }
                  }
                  int x2195 = x2181;
                  if (x2195) {
                    char  *x2196 = x2183;
                    x1984 = 0;
                  } else {
                    char x2199 = x2182;
                    char  *x2200 = x2183;
                    int x2205 = 1/*true*/;
                    char x2206 = '\0';
                    char  *x2207 = 0/*null*/;
                    char x2201 = x2200[0];
                    int x2202 = x2201 == '\0';
                    if (x2202) {
                      x2207 = x2200;
                    } else {
                      int x2203 = x2201 == 'e';
                      if (x2203) {
                        x2205 = 0/*false*/;
                        x2206 = x2201;
                        char  *x2204 = x2200+1;
                        x2207 = x2204;
                      } else {
                        x2207 = x2200;
                      }
                    }
                    int x2219 = x2205;
                    if (x2219) {
                      char  *x2220 = x2207;
                      x1984 = 0;
                    } else {
                      char x2223 = x2206;
                      char  *x2224 = x2207;
                      int x2229 = 1/*true*/;
                      char x2230 = '\0';
                      char  *x2231 = 0/*null*/;
                      char x2225 = x2224[0];
                      int x2226 = x2225 == '\0';
                      if (x2226) {
                        x2231 = x2224;
                      } else {
                        int x2227 = x2225 == 'n';
                        if (x2227) {
                          x2229 = 0/*false*/;
                          x2230 = x2225;
                          char  *x2228 = x2224+1;
                          x2231 = x2228;
                        } else {
                          x2231 = x2224;
                        }
                      }
                      int x2243 = x2229;
                      if (x2243) {
                        char  *x2244 = x2231;
                        x1984 = 0;
                      } else {
                        char x2247 = x2230;
                        char  *x2248 = x2231;
                        int x2253 = 1/*true*/;
                        char x2254 = '\0';
                        char  *x2255 = 0/*null*/;
                        char x2249 = x2248[0];
                        int x2250 = x2249 == '\0';
                        if (x2250) {
                          x2255 = x2248;
                        } else {
                          int x2251 = x2249 == 'g';
                          if (x2251) {
                            x2253 = 0/*false*/;
                            x2254 = x2249;
                            char  *x2252 = x2248+1;
                            x2255 = x2252;
                          } else {
                            x2255 = x2248;
                          }
                        }
                        int x2267 = x2253;
                        if (x2267) {
                          char  *x2268 = x2255;
                          x1984 = 0;
                        } else {
                          char x2271 = x2254;
                          char  *x2272 = x2255;
                          int x2277 = 1/*true*/;
                          char x2278 = '\0';
                          char  *x2279 = 0/*null*/;
                          char x2273 = x2272[0];
                          int x2274 = x2273 == '\0';
                          if (x2274) {
                            x2279 = x2272;
                          } else {
                            int x2275 = x2273 == 't';
                            if (x2275) {
                              x2277 = 0/*false*/;
                              x2278 = x2273;
                              char  *x2276 = x2272+1;
                              x2279 = x2276;
                            } else {
                              x2279 = x2272;
                            }
                          }
                          int x2291 = x2277;
                          if (x2291) {
                            char  *x2292 = x2279;
                            x1984 = 0;
                          } else {
                            char x2295 = x2278;
                            char  *x2296 = x2279;
                            int x2301 = 1/*true*/;
                            char x2302 = '\0';
                            char  *x2303 = 0/*null*/;
                            char x2297 = x2296[0];
                            int x2298 = x2297 == '\0';
                            if (x2298) {
                              x2303 = x2296;
                            } else {
                              int x2299 = x2297 == 'h';
                              if (x2299) {
                                x2301 = 0/*false*/;
                                x2302 = x2297;
                                char  *x2300 = x2296+1;
                                x2303 = x2300;
                              } else {
                                x2303 = x2296;
                              }
                            }
                            int x2315 = x2301;
                            if (x2315) {
                              char  *x2316 = x2303;
                              x1984 = 0;
                            } else {
                              char x2319 = x2302;
                              char  *x2320 = x2303;
                              x1984 = x2320;
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
  char  *x2350 = x1984;
  return x2350;
}
/*@
requires ((strlen(x2366)>=0) && \valid(x2366+(0..strlen(x2366))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_TransferEncoding(char  * x2366) {
  char  *x2368 = x2366;
  int x2373 = 1/*true*/;
  char x2374 = '\0';
  char  *x2375 = 0/*null*/;
  char x2369 = x2366[0];
  int x2370 = x2369 == '\0';
  if (x2370) {
    x2375 = x2366;
  } else {
    int x2371 = x2369 == 'T';
    if (x2371) {
      x2373 = 0/*false*/;
      x2374 = x2369;
      char  *x2372 = x2366+1;
      x2375 = x2372;
    } else {
      x2375 = x2366;
    }
  }
  int x2387 = x2373;
  if (x2387) {
    char  *x2388 = x2375;
    x2368 = 0;
  } else {
    char x2391 = x2374;
    char  *x2392 = x2375;
    int x2397 = 1/*true*/;
    char x2398 = '\0';
    char  *x2399 = 0/*null*/;
    char x2393 = x2392[0];
    int x2394 = x2393 == '\0';
    if (x2394) {
      x2399 = x2392;
    } else {
      int x2395 = x2393 == 'r';
      if (x2395) {
        x2397 = 0/*false*/;
        x2398 = x2393;
        char  *x2396 = x2392+1;
        x2399 = x2396;
      } else {
        x2399 = x2392;
      }
    }
    int x2411 = x2397;
    if (x2411) {
      char  *x2412 = x2399;
      x2368 = 0;
    } else {
      char x2415 = x2398;
      char  *x2416 = x2399;
      int x2421 = 1/*true*/;
      char x2422 = '\0';
      char  *x2423 = 0/*null*/;
      char x2417 = x2416[0];
      int x2418 = x2417 == '\0';
      if (x2418) {
        x2423 = x2416;
      } else {
        int x2419 = x2417 == 'a';
        if (x2419) {
          x2421 = 0/*false*/;
          x2422 = x2417;
          char  *x2420 = x2416+1;
          x2423 = x2420;
        } else {
          x2423 = x2416;
        }
      }
      int x2435 = x2421;
      if (x2435) {
        char  *x2436 = x2423;
        x2368 = 0;
      } else {
        char x2439 = x2422;
        char  *x2440 = x2423;
        int x2445 = 1/*true*/;
        char x2446 = '\0';
        char  *x2447 = 0/*null*/;
        char x2441 = x2440[0];
        int x2442 = x2441 == '\0';
        if (x2442) {
          x2447 = x2440;
        } else {
          int x2443 = x2441 == 'n';
          if (x2443) {
            x2445 = 0/*false*/;
            x2446 = x2441;
            char  *x2444 = x2440+1;
            x2447 = x2444;
          } else {
            x2447 = x2440;
          }
        }
        int x2459 = x2445;
        if (x2459) {
          char  *x2460 = x2447;
          x2368 = 0;
        } else {
          char x2463 = x2446;
          char  *x2464 = x2447;
          int x2469 = 1/*true*/;
          char x2470 = '\0';
          char  *x2471 = 0/*null*/;
          char x2465 = x2464[0];
          int x2466 = x2465 == '\0';
          if (x2466) {
            x2471 = x2464;
          } else {
            int x2467 = x2465 == 's';
            if (x2467) {
              x2469 = 0/*false*/;
              x2470 = x2465;
              char  *x2468 = x2464+1;
              x2471 = x2468;
            } else {
              x2471 = x2464;
            }
          }
          int x2483 = x2469;
          if (x2483) {
            char  *x2484 = x2471;
            x2368 = 0;
          } else {
            char x2487 = x2470;
            char  *x2488 = x2471;
            int x2493 = 1/*true*/;
            char x2494 = '\0';
            char  *x2495 = 0/*null*/;
            char x2489 = x2488[0];
            int x2490 = x2489 == '\0';
            if (x2490) {
              x2495 = x2488;
            } else {
              int x2491 = x2489 == 'f';
              if (x2491) {
                x2493 = 0/*false*/;
                x2494 = x2489;
                char  *x2492 = x2488+1;
                x2495 = x2492;
              } else {
                x2495 = x2488;
              }
            }
            int x2507 = x2493;
            if (x2507) {
              char  *x2508 = x2495;
              x2368 = 0;
            } else {
              char x2511 = x2494;
              char  *x2512 = x2495;
              int x2517 = 1/*true*/;
              char x2518 = '\0';
              char  *x2519 = 0/*null*/;
              char x2513 = x2512[0];
              int x2514 = x2513 == '\0';
              if (x2514) {
                x2519 = x2512;
              } else {
                int x2515 = x2513 == 'e';
                if (x2515) {
                  x2517 = 0/*false*/;
                  x2518 = x2513;
                  char  *x2516 = x2512+1;
                  x2519 = x2516;
                } else {
                  x2519 = x2512;
                }
              }
              int x2531 = x2517;
              if (x2531) {
                char  *x2532 = x2519;
                x2368 = 0;
              } else {
                char x2535 = x2518;
                char  *x2536 = x2519;
                int x2541 = 1/*true*/;
                char x2542 = '\0';
                char  *x2543 = 0/*null*/;
                char x2537 = x2536[0];
                int x2538 = x2537 == '\0';
                if (x2538) {
                  x2543 = x2536;
                } else {
                  int x2539 = x2537 == 'r';
                  if (x2539) {
                    x2541 = 0/*false*/;
                    x2542 = x2537;
                    char  *x2540 = x2536+1;
                    x2543 = x2540;
                  } else {
                    x2543 = x2536;
                  }
                }
                int x2555 = x2541;
                if (x2555) {
                  char  *x2556 = x2543;
                  x2368 = 0;
                } else {
                  char x2559 = x2542;
                  char  *x2560 = x2543;
                  int x2565 = 1/*true*/;
                  char x2566 = '\0';
                  char  *x2567 = 0/*null*/;
                  char x2561 = x2560[0];
                  int x2562 = x2561 == '\0';
                  if (x2562) {
                    x2567 = x2560;
                  } else {
                    int x2563 = x2561 == '-';
                    if (x2563) {
                      x2565 = 0/*false*/;
                      x2566 = x2561;
                      char  *x2564 = x2560+1;
                      x2567 = x2564;
                    } else {
                      x2567 = x2560;
                    }
                  }
                  int x2579 = x2565;
                  if (x2579) {
                    char  *x2580 = x2567;
                    x2368 = 0;
                  } else {
                    char x2583 = x2566;
                    char  *x2584 = x2567;
                    int x2589 = 1/*true*/;
                    char x2590 = '\0';
                    char  *x2591 = 0/*null*/;
                    char x2585 = x2584[0];
                    int x2586 = x2585 == '\0';
                    if (x2586) {
                      x2591 = x2584;
                    } else {
                      int x2587 = x2585 == 'E';
                      if (x2587) {
                        x2589 = 0/*false*/;
                        x2590 = x2585;
                        char  *x2588 = x2584+1;
                        x2591 = x2588;
                      } else {
                        x2591 = x2584;
                      }
                    }
                    int x2603 = x2589;
                    if (x2603) {
                      char  *x2604 = x2591;
                      x2368 = 0;
                    } else {
                      char x2607 = x2590;
                      char  *x2608 = x2591;
                      int x2613 = 1/*true*/;
                      char x2614 = '\0';
                      char  *x2615 = 0/*null*/;
                      char x2609 = x2608[0];
                      int x2610 = x2609 == '\0';
                      if (x2610) {
                        x2615 = x2608;
                      } else {
                        int x2611 = x2609 == 'n';
                        if (x2611) {
                          x2613 = 0/*false*/;
                          x2614 = x2609;
                          char  *x2612 = x2608+1;
                          x2615 = x2612;
                        } else {
                          x2615 = x2608;
                        }
                      }
                      int x2627 = x2613;
                      if (x2627) {
                        char  *x2628 = x2615;
                        x2368 = 0;
                      } else {
                        char x2631 = x2614;
                        char  *x2632 = x2615;
                        int x2637 = 1/*true*/;
                        char x2638 = '\0';
                        char  *x2639 = 0/*null*/;
                        char x2633 = x2632[0];
                        int x2634 = x2633 == '\0';
                        if (x2634) {
                          x2639 = x2632;
                        } else {
                          int x2635 = x2633 == 'c';
                          if (x2635) {
                            x2637 = 0/*false*/;
                            x2638 = x2633;
                            char  *x2636 = x2632+1;
                            x2639 = x2636;
                          } else {
                            x2639 = x2632;
                          }
                        }
                        int x2651 = x2637;
                        if (x2651) {
                          char  *x2652 = x2639;
                          x2368 = 0;
                        } else {
                          char x2655 = x2638;
                          char  *x2656 = x2639;
                          int x2661 = 1/*true*/;
                          char x2662 = '\0';
                          char  *x2663 = 0/*null*/;
                          char x2657 = x2656[0];
                          int x2658 = x2657 == '\0';
                          if (x2658) {
                            x2663 = x2656;
                          } else {
                            int x2659 = x2657 == 'o';
                            if (x2659) {
                              x2661 = 0/*false*/;
                              x2662 = x2657;
                              char  *x2660 = x2656+1;
                              x2663 = x2660;
                            } else {
                              x2663 = x2656;
                            }
                          }
                          int x2675 = x2661;
                          if (x2675) {
                            char  *x2676 = x2663;
                            x2368 = 0;
                          } else {
                            char x2679 = x2662;
                            char  *x2680 = x2663;
                            int x2685 = 1/*true*/;
                            char x2686 = '\0';
                            char  *x2687 = 0/*null*/;
                            char x2681 = x2680[0];
                            int x2682 = x2681 == '\0';
                            if (x2682) {
                              x2687 = x2680;
                            } else {
                              int x2683 = x2681 == 'd';
                              if (x2683) {
                                x2685 = 0/*false*/;
                                x2686 = x2681;
                                char  *x2684 = x2680+1;
                                x2687 = x2684;
                              } else {
                                x2687 = x2680;
                              }
                            }
                            int x2699 = x2685;
                            if (x2699) {
                              char  *x2700 = x2687;
                              x2368 = 0;
                            } else {
                              char x2703 = x2686;
                              char  *x2704 = x2687;
                              int x2709 = 1/*true*/;
                              char x2710 = '\0';
                              char  *x2711 = 0/*null*/;
                              char x2705 = x2704[0];
                              int x2706 = x2705 == '\0';
                              if (x2706) {
                                x2711 = x2704;
                              } else {
                                int x2707 = x2705 == 'i';
                                if (x2707) {
                                  x2709 = 0/*false*/;
                                  x2710 = x2705;
                                  char  *x2708 = x2704+1;
                                  x2711 = x2708;
                                } else {
                                  x2711 = x2704;
                                }
                              }
                              int x2723 = x2709;
                              if (x2723) {
                                char  *x2724 = x2711;
                                x2368 = 0;
                              } else {
                                char x2727 = x2710;
                                char  *x2728 = x2711;
                                int x2733 = 1/*true*/;
                                char x2734 = '\0';
                                char  *x2735 = 0/*null*/;
                                char x2729 = x2728[0];
                                int x2730 = x2729 == '\0';
                                if (x2730) {
                                  x2735 = x2728;
                                } else {
                                  int x2731 = x2729 == 'n';
                                  if (x2731) {
                                    x2733 = 0/*false*/;
                                    x2734 = x2729;
                                    char  *x2732 = x2728+1;
                                    x2735 = x2732;
                                  } else {
                                    x2735 = x2728;
                                  }
                                }
                                int x2747 = x2733;
                                if (x2747) {
                                  char  *x2748 = x2735;
                                  x2368 = 0;
                                } else {
                                  char x2751 = x2734;
                                  char  *x2752 = x2735;
                                  int x2757 = 1/*true*/;
                                  char x2758 = '\0';
                                  char  *x2759 = 0/*null*/;
                                  char x2753 = x2752[0];
                                  int x2754 = x2753 == '\0';
                                  if (x2754) {
                                    x2759 = x2752;
                                  } else {
                                    int x2755 = x2753 == 'g';
                                    if (x2755) {
                                      x2757 = 0/*false*/;
                                      x2758 = x2753;
                                      char  *x2756 = x2752+1;
                                      x2759 = x2756;
                                    } else {
                                      x2759 = x2752;
                                    }
                                  }
                                  int x2771 = x2757;
                                  if (x2771) {
                                    char  *x2772 = x2759;
                                    x2368 = 0;
                                  } else {
                                    char x2775 = x2758;
                                    char  *x2776 = x2759;
                                    x2368 = x2776;
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
      }
    }
  }
  char  *x2812 = x2368;
  return x2812;
}
/*@
requires ((strlen(x2828)>=0) && \valid(x2828+(0..strlen(x2828))));
assigns \nothing;
ensures ((0==\result) || ((strlen(\result)>=0) && \valid(\result+(0..strlen(\result)))));
*/
char  * p_chunked(char  * x2828) {
  char  *x2830 = x2828;
  int x2835 = 1/*true*/;
  char x2836 = '\0';
  char  *x2837 = 0/*null*/;
  char x2831 = x2828[0];
  int x2832 = x2831 == '\0';
  if (x2832) {
    x2837 = x2828;
  } else {
    int x2833 = x2831 == 'c';
    if (x2833) {
      x2835 = 0/*false*/;
      x2836 = x2831;
      char  *x2834 = x2828+1;
      x2837 = x2834;
    } else {
      x2837 = x2828;
    }
  }
  int x2849 = x2835;
  if (x2849) {
    char  *x2850 = x2837;
    x2830 = 0;
  } else {
    char x2853 = x2836;
    char  *x2854 = x2837;
    int x2859 = 1/*true*/;
    char x2860 = '\0';
    char  *x2861 = 0/*null*/;
    char x2855 = x2854[0];
    int x2856 = x2855 == '\0';
    if (x2856) {
      x2861 = x2854;
    } else {
      int x2857 = x2855 == 'h';
      if (x2857) {
        x2859 = 0/*false*/;
        x2860 = x2855;
        char  *x2858 = x2854+1;
        x2861 = x2858;
      } else {
        x2861 = x2854;
      }
    }
    int x2873 = x2859;
    if (x2873) {
      char  *x2874 = x2861;
      x2830 = 0;
    } else {
      char x2877 = x2860;
      char  *x2878 = x2861;
      int x2883 = 1/*true*/;
      char x2884 = '\0';
      char  *x2885 = 0/*null*/;
      char x2879 = x2878[0];
      int x2880 = x2879 == '\0';
      if (x2880) {
        x2885 = x2878;
      } else {
        int x2881 = x2879 == 'u';
        if (x2881) {
          x2883 = 0/*false*/;
          x2884 = x2879;
          char  *x2882 = x2878+1;
          x2885 = x2882;
        } else {
          x2885 = x2878;
        }
      }
      int x2897 = x2883;
      if (x2897) {
        char  *x2898 = x2885;
        x2830 = 0;
      } else {
        char x2901 = x2884;
        char  *x2902 = x2885;
        int x2907 = 1/*true*/;
        char x2908 = '\0';
        char  *x2909 = 0/*null*/;
        char x2903 = x2902[0];
        int x2904 = x2903 == '\0';
        if (x2904) {
          x2909 = x2902;
        } else {
          int x2905 = x2903 == 'n';
          if (x2905) {
            x2907 = 0/*false*/;
            x2908 = x2903;
            char  *x2906 = x2902+1;
            x2909 = x2906;
          } else {
            x2909 = x2902;
          }
        }
        int x2921 = x2907;
        if (x2921) {
          char  *x2922 = x2909;
          x2830 = 0;
        } else {
          char x2925 = x2908;
          char  *x2926 = x2909;
          int x2931 = 1/*true*/;
          char x2932 = '\0';
          char  *x2933 = 0/*null*/;
          char x2927 = x2926[0];
          int x2928 = x2927 == '\0';
          if (x2928) {
            x2933 = x2926;
          } else {
            int x2929 = x2927 == 'k';
            if (x2929) {
              x2931 = 0/*false*/;
              x2932 = x2927;
              char  *x2930 = x2926+1;
              x2933 = x2930;
            } else {
              x2933 = x2926;
            }
          }
          int x2945 = x2931;
          if (x2945) {
            char  *x2946 = x2933;
            x2830 = 0;
          } else {
            char x2949 = x2932;
            char  *x2950 = x2933;
            int x2955 = 1/*true*/;
            char x2956 = '\0';
            char  *x2957 = 0/*null*/;
            char x2951 = x2950[0];
            int x2952 = x2951 == '\0';
            if (x2952) {
              x2957 = x2950;
            } else {
              int x2953 = x2951 == 'e';
              if (x2953) {
                x2955 = 0/*false*/;
                x2956 = x2951;
                char  *x2954 = x2950+1;
                x2957 = x2954;
              } else {
                x2957 = x2950;
              }
            }
            int x2969 = x2955;
            if (x2969) {
              char  *x2970 = x2957;
              x2830 = 0;
            } else {
              char x2973 = x2956;
              char  *x2974 = x2957;
              int x2979 = 1/*true*/;
              char x2980 = '\0';
              char  *x2981 = 0/*null*/;
              char x2975 = x2974[0];
              int x2976 = x2975 == '\0';
              if (x2976) {
                x2981 = x2974;
              } else {
                int x2977 = x2975 == 'd';
                if (x2977) {
                  x2979 = 0/*false*/;
                  x2980 = x2975;
                  char  *x2978 = x2974+1;
                  x2981 = x2978;
                } else {
                  x2981 = x2974;
                }
              }
              int x2993 = x2979;
              if (x2993) {
                char  *x2994 = x2981;
                x2830 = 0;
              } else {
                char x2997 = x2980;
                char  *x2998 = x2981;
                x2830 = x2998;
              }
            }
          }
        }
      }
    }
  }
  char  *x3014 = x2830;
  return x3014;
}
