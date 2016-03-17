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
  int x165 = INT_MAX;
  int x166 = x165 / 16;
  int x167 = x166 - 16;
  /*@
  loop invariant (((strlen(x3)>=0) && \valid(x3+(0..(strlen(x3)+1)-1))) && ((x5==-1) || (0<=x5)));
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
    int x19 = 0;
    char  *x20 = 0/*null*/;
    int x21 = 1/*true*/;
    int x22 = 0;
    char  *x23 = 0/*null*/;
    int x24 = 1/*true*/;
    int x25 = 0;
    char  *x26 = 0/*null*/;
    int x27 = 1/*true*/;
    char x28 = '\0';
    char  *x29 = 0/*null*/;
    char x9 = x8[0];
    int x10 = x9 == '\0';
    if (x10) {
      x29 = x8;
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
        x27 = 0/*false*/;
        x28 = x9;
        char  *x14 = x8+1;
        x29 = x14;
      } else {
        x29 = x8;
      }
    }
    int x41 = x27;
    if (x41) {
      char  *x42 = x29;
    } else {
      char x44 = x28;
      char  *x46 = x29;
      x24 = 0/*false*/;
      char x45 = x44 - '0';
      x25 = x45;
      x26 = x46;
    }
    int x52 = x24;
    if (x52) {
      int x56 = 1/*true*/;
      char x57 = '\0';
      char  *x58 = 0/*null*/;
      if (x10) {
        x58 = x8;
      } else {
        int x53 = x9 >= 'a';
        int x55;
        if (x53) {
          int x54 = x9 <= 'f';
          x55 = x54;
        } else {
          x55 = 0/*false*/;
        }
        if (x55) {
          x56 = 0/*false*/;
          x57 = x9;
          char  *x14 = x8+1;
          x58 = x14;
        } else {
          x58 = x8;
        }
      }
      int x70 = x56;
      if (x70) {
        char  *x71 = x58;
        x23 = x71;
      } else {
        char x74 = x57;
        char  *x77 = x58;
        x21 = 0/*false*/;
        char x75 = x74 - 'a';
        int x76 = 10 + x75;
        x22 = x76;
        x23 = x77;
      }
    } else {
      int x84 = x25;
      char  *x85 = x26;
      x21 = 0/*false*/;
      x22 = x84;
      x23 = x85;
    }
    int x91 = x21;
    if (x91) {
      char  *x92 = x23;
      x20 = x92;
    } else {
      int x95 = x22;
      char  *x96 = x23;
      char  *x97 = x96;
      int x98 = 1/*true*/;
      int x99 = x95;
      /*@
      loop invariant (((strlen(x97)>=0) && \valid(x97+(0..(strlen(x97)+1)-1))) && ((x99==-1) || (0<=x99)));
      loop assigns x97, x98, x99;
      */
      for (;;) {
        int x100 = x98;
        if (!x100) break;
        char  *x102 = x97;
        int x109 = 1/*true*/;
        int x110 = 0;
        char  *x111 = 0/*null*/;
        int x112 = 1/*true*/;
        char x113 = '\0';
        char  *x114 = 0/*null*/;
        char x103 = x102[0];
        int x104 = x103 == '\0';
        if (x104) {
          x114 = x102;
        } else {
          int x105 = x103 >= '0';
          int x107;
          if (x105) {
            int x106 = x103 <= '9';
            x107 = x106;
          } else {
            x107 = 0/*false*/;
          }
          if (x107) {
            x112 = 0/*false*/;
            x113 = x103;
            char  *x108 = x102+1;
            x114 = x108;
          } else {
            x114 = x102;
          }
        }
        int x126 = x112;
        if (x126) {
          char  *x127 = x114;
        } else {
          char x129 = x113;
          char  *x131 = x114;
          x109 = 0/*false*/;
          char x130 = x129 - '0';
          x110 = x130;
          x111 = x131;
        }
        int x137 = x109;
        if (x137) {
          int x141 = 1/*true*/;
          char x142 = '\0';
          char  *x143 = 0/*null*/;
          if (x104) {
            x143 = x102;
          } else {
            int x138 = x103 >= 'a';
            int x140;
            if (x138) {
              int x139 = x103 <= 'f';
              x140 = x139;
            } else {
              x140 = 0/*false*/;
            }
            if (x140) {
              x141 = 0/*false*/;
              x142 = x103;
              char  *x108 = x102+1;
              x143 = x108;
            } else {
              x143 = x102;
            }
          }
          int x155 = x141;
          if (x155) {
            char  *x156 = x143;
            x98 = 0/*false*/;
          } else {
            char x159 = x142;
            char  *x162 = x143;
            int x163 = x99;
            int x164 = x163 < 0;
            int x172;
            if (x164) {
              x172 = x163;
            } else {
              int x168 = x163 > x167;
              int x171;
              if (x168) {
                x171 = -1;
              } else {
                char x160 = x159 - 'a';
                int x161 = 10 + x160;
                int x169 = x163 * 16;
                int x170 = x169 + x161;
                x171 = x170;
              }
              x172 = x171;
            }
            x99 = x172;
            x97 = x162;
          }
        } else {
          int x178 = x110;
          char  *x179 = x111;
          int x180 = x99;
          int x181 = x180 < 0;
          int x186;
          if (x181) {
            x186 = x180;
          } else {
            int x182 = x180 > x167;
            int x185;
            if (x182) {
              x185 = -1;
            } else {
              int x183 = x180 * 16;
              int x184 = x183 + x178;
              x185 = x184;
            }
            x186 = x185;
          }
          x99 = x186;
          x97 = x179;
        }
      }
      int x214 = x99;
      char  *x215 = x97;
      x18 = 0/*false*/;
      x19 = x214;
      x20 = x215;
    }
    int x221 = x18;
    if (x221) {
      char  *x222 = x20;
      x17 = x222;
    } else {
      int x225 = x19;
      char  *x226 = x20;
      int x231 = 1/*true*/;
      char x232 = '\0';
      char  *x233 = 0/*null*/;
      char x227 = x226[0];
      int x228 = x227 == '\0';
      if (x228) {
        x233 = x226;
      } else {
        int x229 = x227 == '\n';
        if (x229) {
          x231 = 0/*false*/;
          x232 = x227;
          char  *x230 = x226+1;
          x233 = x230;
        } else {
          x233 = x226;
        }
      }
      int x245 = x231;
      if (x245) {
        char  *x246 = x233;
        x17 = x246;
      } else {
        char x249 = x232;
        char  *x250 = x233;
        x15 = 0/*false*/;
        x16 = x225;
        x17 = x250;
      }
    }
    int x258 = x15;
    if (x258) {
      char  *x259 = x17;
      x4 = 0/*false*/;
    } else {
      int x262 = x16;
      char  *x263 = x17;
      int x265 = 1/*true*/;
      char  *x266 = x263;
      /*@
      loop invariant ((0<=x268) && ((strlen(x266)>=0) && \valid(x266+(0..(strlen(x266)+1)-1))));
      loop assigns x268, x265, x266;
      loop variant (x262-x268);
      */
      for(int x268=0; x268 < x262; x268++) {
        int x269 = x265;
        if (x269) {
          char  *x270 = x266;
          char x271 = x270[0];
          int x272 = x271 == '\0';
          if (x272) {
            x265 = 0/*false*/;
          } else {
            if (1/*true*/) {
              char  *x273 = x270+1;
              x266 = x273;
            } else {
              x265 = 0/*false*/;
            }
          }
        } else {
        }
      }
      int x306 = x265;
      char  *x307 = x266;
      int x264 = x262 < 0;
      if (x264) {
        x4 = 0/*false*/;
      } else {
        int x310 = 1/*true*/;
        int x311 = 0;
        char  *x312 = 0/*null*/;
        int x313 = 1/*true*/;
        char  *x315 = 0/*null*/;
        if (x306) {
          x313 = 0/*false*/;
          x315 = x307;
        } else {
          x315 = x263;
        }
        int x323 = x313;
        if (x323) {
          char  *x324 = x315;
          x312 = x324;
        } else {
          char  *x328 = x315;
          x310 = 0/*false*/;
          x311 = x262;
          x312 = x328;
        }
        int x334 = x310;
        if (x334) {
          char  *x335 = x312;
          x4 = 0/*false*/;
        } else {
          int x338 = x311;
          char  *x339 = x312;
          int x344 = 1/*true*/;
          char x345 = '\0';
          char  *x346 = 0/*null*/;
          char x340 = x339[0];
          int x341 = x340 == '\0';
          if (x341) {
            x346 = x339;
          } else {
            int x342 = x340 == '\n';
            if (x342) {
              x344 = 0/*false*/;
              x345 = x340;
              char  *x343 = x339+1;
              x346 = x343;
            } else {
              x346 = x339;
            }
          }
          int x358 = x344;
          if (x358) {
            char  *x359 = x346;
            x4 = 0/*false*/;
          } else {
            char x362 = x345;
            char  *x363 = x346;
            int x364 = x5;
            int x365 = x364 < 0;
            int x370;
            if (x365) {
              x370 = x364;
            } else {
              int x366 = x165 - x338;
              int x367 = x364 > x366;
              int x369;
              if (x367) {
                x369 = -1;
              } else {
                int x368 = x364 + x338;
                x369 = x368;
              }
              x370 = x369;
            }
            x5 = x370;
            x3 = x363;
          }
        }
      }
    }
  }
  int x404 = x5;
  char  *x405 = x3;
  char x406 = x405[0];
  int x407 = x406 == '\0';
  if (x407) {
    x2 = x404;
  } else {
  }
  int x411 = x2;
  return x411;
}
