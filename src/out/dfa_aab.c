#include <string.h>

/*@
requires strlen(input)>=0 && \valid(input+(0..strlen(input)));
assigns \nothing;
ensures \result==0 || \result==1;
*/
int dfa_aab(char* input) {
  if (*input == '\0') return 0/*false*/;
  int id = 0;
  char c;
  /*@
    loop invariant strlen(input)>0 && \valid(input+(0..strlen(input)));
    loop invariant id==0 || id==3 || id==6;
    loop assigns id, c, input;
    loop variant strlen(input);
   */
  while (input[1] != '\0') {
    c = *input++;
    if (id == 0) {
      char x1 = c;
      int x2 = x1 == 'A';
      int x17;
      if (x2) {
        x17 = 3;
      } else {
        x17 = 0;
      }
      id = x17;
    }
    else if (id == 6) {
      char x7 = c;
      int x8 = x7 == 'A';
      int x14;
      if (x8) {
        x14 = 6;
      } else {
        int x10 = x7 == 'B';
        int x13;
        if (x10) {
          x13 = 0;
        } else {
          x13 = 0;
        }
        x14 = x13;
      }
      id = x14;
    }
    else if (id == 3) {
      char x4 = c;
      int x5 = x4 == 'A';
      int x15;
      if (x5) {
        x15 = 6;
      } else {
        x15 = 0;
      }
      id = x15;
    }
    else { return -1; /*error: invalid state*/ }
  }
  c = *input;
  if (id == 0) {
    char x1 = c;
    int x2 = x1 == 'A';
    int x17;
    if (x2) {
      x17 = 0/*false*/;
    } else {
      x17 = 0/*false*/;
    }
    id = x17;
  }
  else if (id == 6) {
    char x7 = c;
    int x8 = x7 == 'A';
    int x14;
    if (x8) {
      x14 = 0/*false*/;
    } else {
      int x10 = x7 == 'B';
      int x13;
      if (x10) {
        x13 = 1/*true*/;
      } else {
        x13 = 0/*false*/;
      }
      x14 = x13;
    }
    id = x14;
  }
  else if (id == 3) {
    char x4 = c;
    int x5 = x4 == 'A';
    int x15;
    if (x5) {
      x15 = 0/*false*/;
    } else {
      x15 = 0/*false*/;
    }
    id = x15;
  }
  else { return -1; /*error: invalid state */ }
  return id;
}
