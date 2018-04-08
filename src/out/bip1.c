#include <string.h>

/*@
assigns \nothing;
ensures -1<=\result<=9;
*/
int d(char c) {
  if ('0' <= c && c <= '9')
    return c - '0';
  return -1;
}

/*@
requires -1<=d<=9;
assigns \nothing;
ensures \result==' ' || '0'<=\result<='9';
*/
char e(int d) {
  if (d==-1) return ' ';
  return '0' + d;
}
