#include <string.h>
/*@
requires strlen(input)>=0 && \valid(input+(0..strlen(input)));
assigns \nothing;
ensures \result==0 || \result==1;
*/
int dfa_aabany(char* input) {
  if (*input == '\0') return 0/*false*/;
  int id = 0;
  char c;
  /*@
  loop invariant strlen(input)>0 && \valid(input+(0..strlen(input)));
  loop invariant id == 17 || id == 14 || id == 11 || id == 6 || id == 3 || id == 0;
  loop assigns id, c, input;
  loop variant strlen(input);
  */
  while (input[1] != '\0') {
    c = *input++;
    if (id == 17) {
      char x18 = c;
      int x19 = x18 == 'A';
      int x23;
      if (x19) {
        return 1/*true*/;
      } else {
        return 1/*true*/;
      }
      id = x23;
    }
    else if (id == 14) {
      char x15 = c;
      int x16 = x15 == 'A';
      int x24;
      if (x16) {
        return 1/*true*/;
      } else {
        return 1/*true*/;
      }
      id = x24;
    }
    else if (id == 11) {
      char x12 = c;
      int x13 = x12 == 'A';
      int x26;
      if (x13) {
        return 1/*true*/;
      } else {
        return 1/*true*/;
      }
      id = x26;
    }
    else if (id == 6) {
      char x7 = c;
      int x8 = x7 == 'A';
      int x29;
      if (x8) {
        x29 = 6;
      } else {
        int x10 = x7 == 'B';
        int x28;
        if (x10) {
          return 1/*true*/;
        } else {
          x28 = 0;
        }
        x29 = x28;
      }
      id = x29;
    }
    else if (id == 3) {
      char x4 = c;
      int x5 = x4 == 'A';
      int x30;
      if (x5) {
        x30 = 6;
      } else {
        x30 = 0;
      }
      id = x30;
    }
    else if (id == 0) {
      char x1 = c;
      int x2 = x1 == 'A';
      int x32;
      if (x2) {
        x32 = 3;
      } else {
        x32 = 0;
      }
      id = x32;
    }
    else { return -1; /*error: invalid state*/ }
  }
  c = *input;
  if (id == 17) {
    char x18 = c;
    int x19 = x18 == 'A';
    int x23;
    if (x19) {
      x23 = 1/*true*/;
    } else {
      x23 = 1/*true*/;
    }
    id = x23;
  }
  else if (id == 14) {
    char x15 = c;
    int x16 = x15 == 'A';
    int x24;
    if (x16) {
      x24 = 1/*true*/;
    } else {
      x24 = 1/*true*/;
    }
    id = x24;
  }
  else if (id == 11) {
    char x12 = c;
    int x13 = x12 == 'A';
    int x26;
    if (x13) {
      x26 = 1/*true*/;
    } else {
      x26 = 1/*true*/;
    }
    id = x26;
  }
  else if (id == 6) {
    char x7 = c;
    int x8 = x7 == 'A';
    int x29;
    if (x8) {
      x29 = 0/*false*/;
    } else {
      int x10 = x7 == 'B';
      int x28;
      if (x10) {
        x28 = 1/*true*/;
      } else {
        x28 = 0/*false*/;
      }
      x29 = x28;
    }
    id = x29;
  }
  else if (id == 3) {
    char x4 = c;
    int x5 = x4 == 'A';
    int x30;
    if (x5) {
      x30 = 0/*false*/;
    } else {
      x30 = 0/*false*/;
    }
    id = x30;
  }
  else if (id == 0) {
    char x1 = c;
    int x2 = x1 == 'A';
    int x32;
    if (x2) {
      x32 = 0/*false*/;
    } else {
      x32 = 0/*false*/;
    }
    id = x32;
  }
  else { return -1; /*error: invalid state */ }
  return id;
}
