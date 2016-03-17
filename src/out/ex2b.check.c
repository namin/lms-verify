#include <limits.h>
/*@
requires (x0>0);
assigns \nothing;
ensures ((0<=\result) && (\result<x0));
*/
int picker_first(int  x0) {
  return 0;
}
/*@
requires ((x10>0) && \valid(x9+(0..x10-1)));
assigns \nothing;
*/
int pick_first_element(int  * x9, int  x10) {
  int x12 = picker_first(x10);
  int x13 = x9[x12];
  return x13;
}
/*@
requires ((x21>0) && \valid(x20+(0..x21-1)));
assigns \nothing;
*/
int pick_first_directly(int  * x20, int  x21) {
  int x23 = x20[0];
  return x23;
}
/*@
requires (x30>0);
assigns \nothing;
ensures ((0<=\result) && (\result<x30));
*/
int picker_last(int  x30) {
  int x32 = x30 - 1;
  return x32;
}
/*@
requires ((x41>0) && \valid(x40+(0..x41-1)));
assigns \nothing;
*/
int pick_last_element(int  * x40, int  x41) {
  int x43 = picker_last(x41);
  int x44 = x40[x43];
  return x44;
}
/*@
requires ((x52>0) && \valid(x51+(0..x52-1)));
assigns \nothing;
*/
int pick_last_directly(int  * x51, int  x52) {
  int x54 = x52 - 1;
  int x55 = x51[x54];
  return x55;
}
