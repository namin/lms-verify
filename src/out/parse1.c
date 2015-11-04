#include <string.h>

/*@
 requires strlen(a)>=0 && \valid(a+(0..strlen(a)));
 assigns \nothing;
 ensures 0<=\result || \result==-1;
 */
int my_atoi(char* a) {
  int m = INT_MAX/10 - 10;
  int r = 0;
  char* s = a;
  /*@
    loop invariant strlen(s)>=0 && \valid(s+(0..strlen(s)));
    loop invariant 0 <= r;
    loop assigns r, s;
    loop variant strlen(s);
  */
  while ('0' <= *s && *s <= '9') {
    if (r > m) return -1;
    r = 10*r + (*s - '0');
    s++;
  }
  return r;
}
