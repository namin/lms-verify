#include <limits.h>
#include <string.h>
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..strlen(x0))));
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
  loop invariant (((strlen(x3)>=0) &&
  \valid(x3+(0..strlen(x3)))) &&
  ((x5==-1) || (0<=x5)));
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
      loop invariant (((strlen(x97)>=0) &&
      \valid(x97+(0..strlen(x97)))) &&
      ((x99==-1) || (0<=x99)));
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
      int x212 = x99;
      char  *x213 = x97;
      x18 = 0/*false*/;
      x19 = x212;
      x20 = x213;
    }
    int x219 = x18;
    if (x219) {
      char  *x220 = x20;
      x17 = x220;
    } else {
      int x223 = x19;
      char  *x224 = x20;
      int x229 = 1/*true*/;
      char x230 = '\0';
      char  *x231 = 0/*null*/;
      char x225 = x224[0];
      int x226 = x225 == '\0';
      if (x226) {
        x231 = x224;
      } else {
        int x227 = x225 == '\r';
        if (x227) {
          x229 = 0/*false*/;
          x230 = x225;
          char  *x228 = x224+1;
          x231 = x228;
        } else {
          x231 = x224;
        }
      }
      int x243 = x229;
      if (x243) {
        char  *x244 = x231;
        x17 = x244;
      } else {
        char x247 = x230;
        char  *x248 = x231;
        int x253 = 1/*true*/;
        char x254 = '\0';
        char  *x255 = 0/*null*/;
        char x249 = x248[0];
        int x250 = x249 == '\0';
        if (x250) {
          x255 = x248;
        } else {
          int x251 = x249 == '\n';
          if (x251) {
            x253 = 0/*false*/;
            x254 = x249;
            char  *x252 = x248+1;
            x255 = x252;
          } else {
            x255 = x248;
          }
        }
        int x267 = x253;
        if (x267) {
          char  *x268 = x255;
          x17 = x268;
        } else {
          char x271 = x254;
          char  *x272 = x255;
          x15 = 0/*false*/;
          x16 = x223;
          x17 = x272;
        }
      }
    }
    int x282 = x15;
    if (x282) {
      char  *x283 = x17;
      x4 = 0/*false*/;
    } else {
      int x286 = x16;
      char  *x287 = x17;
      int x289 = 1/*true*/;
      char  *x290 = x287;
      /*@
      loop invariant ((0<=x292) &&
      ((strlen(x290)>=0) &&
      \valid(x290+(0..strlen(x290)))));
      loop assigns x292, x289, x290;
      loop variant (x286-x292);
      */
      for(int x292=0; x292 < x286; x292++) {
        int x293 = x289;
        if (x293) {
          char  *x294 = x290;
          char x295 = x294[0];
          int x296 = x295 == '\0';
          if (x296) {
            x289 = 0/*false*/;
          } else {
            char  *x297 = x294+1;
            x290 = x297;
          }
        } else {
        }
      }
      int x323 = x289;
      char  *x324 = x290;
      int x288 = x286 < 0;
      if (x288) {
        x4 = 0/*false*/;
      } else {
        int x327 = 1/*true*/;
        char  *x329 = 0/*null*/;
        if (x323) {
          x327 = 0/*false*/;
          x329 = x324;
        } else {
          x329 = x287;
        }
        int x337 = x327;
        if (x337) {
          char  *x338 = x329;
          x4 = 0/*false*/;
        } else {
          char  *x342 = x329;
          int x343 = x5;
          int x344 = x343 < 0;
          int x349;
          if (x344) {
            x349 = x343;
          } else {
            int x345 = x165 - x286;
            int x346 = x343 > x345;
            int x348;
            if (x346) {
              x348 = -1;
            } else {
              int x347 = x343 + x286;
              x348 = x347;
            }
            x349 = x348;
          }
          x5 = x349;
          x3 = x342;
        }
      }
    }
  }
  int x379 = x5;
  char  *x380 = x3;
  char x381 = x380[0];
  int x382 = x381 == '\0';
  if (x382) {
    x2 = x379;
  } else {
  }
  int x386 = x2;
  return x386;
}
