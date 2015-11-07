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
  int x137 = INT_MAX;
  int x138 = x137 / 16;
  int x139 = x138 - 16;
  /*@
  loop invariant (((strlen(x3)>=0) && \valid(x3+(0..strlen(x3)))) && ((x5==-1) || (0<=x5)));
  loop assigns x3, x4, x5;
  */
  for (;;) {
    int x6 = x4;
    if (!x6) break;
    char  *x8 = x3;
    int x15 = 1/*true*/;
    int x16 = 0;
    char  *x17 = 0/*null*/;
    int x18 = 1/*true*/;
    char x19 = '\0';
    char  *x20 = 0/*null*/;
    char x9 = x8[0];
    int x10 = x9 == '\0';
    if (x10) {
      x20 = x8;
    } else {
      int x11 = x9 >= '0';
      int x13;
      if (x11) {
        int x12 = x9 <= '9';
        x13 = x12;
      } else {
        x13 = 0/*false*/;
      }
      if (x13) {
        x18 = 0/*false*/;
        x19 = x9;
        char  *x14 = x8+1;
        x20 = x14;
      } else {
        x20 = x8;
      }
    }
    int x32 = x18;
    if (x32) {
      char  *x33 = x20;
    } else {
      char x35 = x19;
      char  *x37 = x20;
      x15 = 0/*false*/;
      char x36 = x35 - '0';
      x16 = x36;
      x17 = x37;
    }
    int x43 = x15;
    if (x43) {
      int x47 = 1/*true*/;
      char x48 = '\0';
      char  *x49 = 0/*null*/;
      if (x10) {
        x49 = x8;
      } else {
        int x44 = x9 >= 'a';
        int x46;
        if (x44) {
          int x45 = x9 <= 'f';
          x46 = x45;
        } else {
          x46 = 0/*false*/;
        }
        if (x46) {
          x47 = 0/*false*/;
          x48 = x9;
          char  *x14 = x8+1;
          x49 = x14;
        } else {
          x49 = x8;
        }
      }
      int x61 = x47;
      if (x61) {
        char  *x62 = x49;
        x4 = 0/*false*/;
      } else {
        char x65 = x48;
        char  *x68 = x49;
        char  *x69 = x68;
        int x70 = 1/*true*/;
        char x66 = x65 - 'a';
        int x67 = 10 + x66;
        int x71 = x67;
        /*@
        loop invariant (((strlen(x69)>=0) && \valid(x69+(0..strlen(x69)))) && ((x71==-1) || (0<=x71)));
        loop assigns x69, x70, x71;
        */
        for (;;) {
          int x72 = x70;
          if (!x72) break;
          char  *x74 = x69;
          int x81 = 1/*true*/;
          int x82 = 0;
          char  *x83 = 0/*null*/;
          int x84 = 1/*true*/;
          char x85 = '\0';
          char  *x86 = 0/*null*/;
          char x75 = x74[0];
          int x76 = x75 == '\0';
          if (x76) {
            x86 = x74;
          } else {
            int x77 = x75 >= '0';
            int x79;
            if (x77) {
              int x78 = x75 <= '9';
              x79 = x78;
            } else {
              x79 = 0/*false*/;
            }
            if (x79) {
              x84 = 0/*false*/;
              x85 = x75;
              char  *x80 = x74+1;
              x86 = x80;
            } else {
              x86 = x74;
            }
          }
          int x98 = x84;
          if (x98) {
            char  *x99 = x86;
          } else {
            char x101 = x85;
            char  *x103 = x86;
            x81 = 0/*false*/;
            char x102 = x101 - '0';
            x82 = x102;
            x83 = x103;
          }
          int x109 = x81;
          if (x109) {
            int x113 = 1/*true*/;
            char x114 = '\0';
            char  *x115 = 0/*null*/;
            if (x76) {
              x115 = x74;
            } else {
              int x110 = x75 >= 'a';
              int x112;
              if (x110) {
                int x111 = x75 <= 'f';
                x112 = x111;
              } else {
                x112 = 0/*false*/;
              }
              if (x112) {
                x113 = 0/*false*/;
                x114 = x75;
                char  *x80 = x74+1;
                x115 = x80;
              } else {
                x115 = x74;
              }
            }
            int x127 = x113;
            if (x127) {
              char  *x128 = x115;
              x70 = 0/*false*/;
            } else {
              char x131 = x114;
              char  *x134 = x115;
              int x135 = x71;
              int x136 = x135 < 0;
              int x144;
              if (x136) {
                x144 = x135;
              } else {
                int x140 = x135 > x139;
                int x143;
                if (x140) {
                  x143 = -1;
                } else {
                  char x132 = x131 - 'a';
                  int x133 = 10 + x132;
                  int x141 = x135 * 16;
                  int x142 = x141 + x133;
                  x143 = x142;
                }
                x144 = x143;
              }
              x71 = x144;
              x69 = x134;
            }
          } else {
            int x150 = x82;
            char  *x151 = x83;
            int x152 = x71;
            int x153 = x152 < 0;
            int x158;
            if (x153) {
              x158 = x152;
            } else {
              int x154 = x152 > x139;
              int x157;
              if (x154) {
                x157 = -1;
              } else {
                int x155 = x152 * 16;
                int x156 = x155 + x150;
                x157 = x156;
              }
              x158 = x157;
            }
            x71 = x158;
            x69 = x151;
          }
        }
        int x184 = x71;
        char  *x185 = x69;
        int x190 = 1/*true*/;
        char x191 = '\0';
        char  *x192 = 0/*null*/;
        char x186 = x185[0];
        int x187 = x186 == '\0';
        if (x187) {
          x192 = x185;
        } else {
          int x188 = x186 == '\n';
          if (x188) {
            x190 = 0/*false*/;
            x191 = x186;
            char  *x189 = x185+1;
            x192 = x189;
          } else {
            x192 = x185;
          }
        }
        int x204 = x190;
        if (x204) {
          char  *x205 = x192;
          x4 = 0/*false*/;
        } else {
          char x208 = x191;
          char  *x209 = x192;
          int x211 = 1/*true*/;
          char  *x212 = x209;
          /*@
          loop invariant ((0<=x214) && ((strlen(x212)>=0) && \valid(x212+(0..strlen(x212)))));
          loop assigns x214, x211, x212;
          loop variant (x71-x214);
          */
          for(int x214=0; x214 < x184; x214++) {
            int x215 = x211;
            if (x215) {
              char  *x216 = x212;
              char x217 = x216[0];
              int x218 = x217 == '\0';
              if (x218) {
                x211 = 0/*false*/;
              } else {
                if (1/*true*/) {
                  char  *x219 = x216+1;
                  x212 = x219;
                } else {
                  x211 = 0/*false*/;
                }
              }
            } else {
            }
          }
          int x249 = x211;
          char  *x250 = x212;
          int x210 = x184 < 0;
          if (x210) {
            x4 = 0/*false*/;
          } else {
            int x253 = 1/*true*/;
            char  *x255 = 0/*null*/;
            if (x249) {
              x253 = 0/*false*/;
              x255 = x250;
            } else {
              x255 = x209;
            }
            int x263 = x253;
            if (x263) {
              char  *x264 = x255;
              x4 = 0/*false*/;
            } else {
              char  *x268 = x255;
              int x273 = 1/*true*/;
              char x274 = '\0';
              char  *x275 = 0/*null*/;
              char x269 = x268[0];
              int x270 = x269 == '\0';
              if (x270) {
                x275 = x268;
              } else {
                int x271 = x269 == '\n';
                if (x271) {
                  x273 = 0/*false*/;
                  x274 = x269;
                  char  *x272 = x268+1;
                  x275 = x272;
                } else {
                  x275 = x268;
                }
              }
              int x287 = x273;
              if (x287) {
                char  *x288 = x275;
                x4 = 0/*false*/;
              } else {
                char x291 = x274;
                char  *x292 = x275;
                int x293 = x5;
                int x294 = x293 < 0;
                int x299;
                if (x294) {
                  x299 = x293;
                } else {
                  int x295 = x137 - x184;
                  int x296 = x293 > x295;
                  int x298;
                  if (x296) {
                    x298 = -1;
                  } else {
                    int x297 = x293 + x184;
                    x298 = x297;
                  }
                  x299 = x298;
                }
                x5 = x299;
                x3 = x292;
              }
            }
          }
        }
      }
    } else {
      int x313 = x16;
      char  *x314 = x17;
      char  *x315 = x314;
      int x316 = 1/*true*/;
      int x317 = x313;
      /*@
      loop invariant (((strlen(x315)>=0) && \valid(x315+(0..strlen(x315)))) && ((x317==-1) || (0<=x317)));
      loop assigns x315, x316, x317;
      */
      for (;;) {
        int x318 = x316;
        if (!x318) break;
        char  *x320 = x315;
        int x327 = 1/*true*/;
        int x328 = 0;
        char  *x329 = 0/*null*/;
        int x330 = 1/*true*/;
        char x331 = '\0';
        char  *x332 = 0/*null*/;
        char x321 = x320[0];
        int x322 = x321 == '\0';
        if (x322) {
          x332 = x320;
        } else {
          int x323 = x321 >= '0';
          int x325;
          if (x323) {
            int x324 = x321 <= '9';
            x325 = x324;
          } else {
            x325 = 0/*false*/;
          }
          if (x325) {
            x330 = 0/*false*/;
            x331 = x321;
            char  *x326 = x320+1;
            x332 = x326;
          } else {
            x332 = x320;
          }
        }
        int x344 = x330;
        if (x344) {
          char  *x345 = x332;
        } else {
          char x347 = x331;
          char  *x349 = x332;
          x327 = 0/*false*/;
          char x348 = x347 - '0';
          x328 = x348;
          x329 = x349;
        }
        int x355 = x327;
        if (x355) {
          int x359 = 1/*true*/;
          char x360 = '\0';
          char  *x361 = 0/*null*/;
          if (x322) {
            x361 = x320;
          } else {
            int x356 = x321 >= 'a';
            int x358;
            if (x356) {
              int x357 = x321 <= 'f';
              x358 = x357;
            } else {
              x358 = 0/*false*/;
            }
            if (x358) {
              x359 = 0/*false*/;
              x360 = x321;
              char  *x326 = x320+1;
              x361 = x326;
            } else {
              x361 = x320;
            }
          }
          int x373 = x359;
          if (x373) {
            char  *x374 = x361;
            x316 = 0/*false*/;
          } else {
            char x377 = x360;
            char  *x380 = x361;
            int x381 = x317;
            int x382 = x381 < 0;
            int x387;
            if (x382) {
              x387 = x381;
            } else {
              int x383 = x381 > x139;
              int x386;
              if (x383) {
                x386 = -1;
              } else {
                char x378 = x377 - 'a';
                int x379 = 10 + x378;
                int x384 = x381 * 16;
                int x385 = x384 + x379;
                x386 = x385;
              }
              x387 = x386;
            }
            x317 = x387;
            x315 = x380;
          }
        } else {
          int x393 = x328;
          char  *x394 = x329;
          int x395 = x317;
          int x396 = x395 < 0;
          int x401;
          if (x396) {
            x401 = x395;
          } else {
            int x397 = x395 > x139;
            int x400;
            if (x397) {
              x400 = -1;
            } else {
              int x398 = x395 * 16;
              int x399 = x398 + x393;
              x400 = x399;
            }
            x401 = x400;
          }
          x317 = x401;
          x315 = x394;
        }
      }
      int x427 = x317;
      char  *x428 = x315;
      int x433 = 1/*true*/;
      char x434 = '\0';
      char  *x435 = 0/*null*/;
      char x429 = x428[0];
      int x430 = x429 == '\0';
      if (x430) {
        x435 = x428;
      } else {
        int x431 = x429 == '\n';
        if (x431) {
          x433 = 0/*false*/;
          x434 = x429;
          char  *x432 = x428+1;
          x435 = x432;
        } else {
          x435 = x428;
        }
      }
      int x447 = x433;
      if (x447) {
        char  *x448 = x435;
        x4 = 0/*false*/;
      } else {
        char x451 = x434;
        char  *x452 = x435;
        int x454 = 1/*true*/;
        char  *x455 = x452;
        /*@
        loop invariant ((0<=x457) && ((strlen(x455)>=0) && \valid(x455+(0..strlen(x455)))));
        loop assigns x457, x454, x455;
        loop variant (x317-x457);
        */
        for(int x457=0; x457 < x427; x457++) {
          int x458 = x454;
          if (x458) {
            char  *x459 = x455;
            char x460 = x459[0];
            int x461 = x460 == '\0';
            if (x461) {
              x454 = 0/*false*/;
            } else {
              if (1/*true*/) {
                char  *x462 = x459+1;
                x455 = x462;
              } else {
                x454 = 0/*false*/;
              }
            }
          } else {
          }
        }
        int x492 = x454;
        char  *x493 = x455;
        int x453 = x427 < 0;
        if (x453) {
          x4 = 0/*false*/;
        } else {
          int x496 = 1/*true*/;
          char  *x498 = 0/*null*/;
          if (x492) {
            x496 = 0/*false*/;
            x498 = x493;
          } else {
            x498 = x452;
          }
          int x506 = x496;
          if (x506) {
            char  *x507 = x498;
            x4 = 0/*false*/;
          } else {
            char  *x511 = x498;
            int x516 = 1/*true*/;
            char x517 = '\0';
            char  *x518 = 0/*null*/;
            char x512 = x511[0];
            int x513 = x512 == '\0';
            if (x513) {
              x518 = x511;
            } else {
              int x514 = x512 == '\n';
              if (x514) {
                x516 = 0/*false*/;
                x517 = x512;
                char  *x515 = x511+1;
                x518 = x515;
              } else {
                x518 = x511;
              }
            }
            int x530 = x516;
            if (x530) {
              char  *x531 = x518;
              x4 = 0/*false*/;
            } else {
              char x534 = x517;
              char  *x535 = x518;
              int x536 = x5;
              int x537 = x536 < 0;
              int x542;
              if (x537) {
                x542 = x536;
              } else {
                int x538 = x137 - x427;
                int x539 = x536 > x538;
                int x541;
                if (x539) {
                  x541 = -1;
                } else {
                  int x540 = x536 + x427;
                  x541 = x540;
                }
                x542 = x541;
              }
              x5 = x542;
              x3 = x535;
            }
          }
        }
      }
    }
  }
  int x576 = x5;
  char  *x577 = x3;
  char x578 = x577[0];
  int x579 = x578 == '\0';
  if (x579) {
    x2 = x576;
  } else {
  }
  int x583 = x2;
  return x583;
}
