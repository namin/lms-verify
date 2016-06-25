#include <limits.h>
/*@
requires (x0>0);
assigns \nothing;
ensures ((0<=\result) &&
(\result<x0));
*/
int pick_index(int  x0) {
  return 0;
}
/*@
requires ((x10>0) &&
\valid(x9+(0..x10-1)));
assigns \nothing;
*/
int pick_element(int  * x9, int  x10) {
  int x12 = pick_index(x10);
  int x13 = x9[x12];
  return x13;
}
/*@
requires \valid(x20);
assigns \nothing;
ensures (\result==x20[0]);
*/
int pick_first(int  * x20) {
  int x22 = x20[0];
  return x22;
}
