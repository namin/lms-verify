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
  loop invariant id == 6 || id == 3 || id == 0;
  loop assigns id, c, input;
  loop variant strlen(input);
  */
  while (input[1] != '\0') {
    c = *input++;
    if (id == 0) {
      char x1 = c;
      int x2 = x1 == 'A';
      int x16;
      if (x2) {
        x16 = 3;
      } else {
        x16 = 0;
      }
      id = x16;
    }
    else if (id == 6) {
      char x7 = c;
      int x8 = x7 == 'A';
      int x13;
      if (x8) {
        x13 = 6;
      } else {
        x13 = 0;
      }
      id = x13;
    }
    else if (id == 3) {
      char x4 = c;
      int x5 = x4 == 'A';
      int x14;
      if (x5) {
        x14 = 6;
      } else {
        x14 = 0;
      }
      id = x14;
    }
    else { return -1; /*error: invalid state*/ }
  }
  c = *input;
  if (id == 0) {
    char x1 = c;
    int x2 = x1 == 'A';
    int x16;
    if (x2) {
      x16 = 0/*false*/;
    } else {
      x16 = 0/*false*/;
    }
    id = x16;
  }
  else if (id == 6) {
    char x7 = c;
    int x8 = x7 == 'A';
    int x13;
    if (x8) {
      x13 = 0/*false*/;
    } else {
      x13 = 1/*true*/;
    }
    id = x13;
  }
  else if (id == 3) {
    char x4 = c;
    int x5 = x4 == 'A';
    int x14;
    if (x5) {
      x14 = 0/*false*/;
    } else {
      x14 = 0/*false*/;
    }
    id = x14;
  }
  else { return -1; /*error: invalid state */ }
  return id;
}
