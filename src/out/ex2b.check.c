/*@
requires (x0>0);
assigns \nothing;
ensures ((0<=\result) && (\result<x0));
*/
int picker_first(int  x0) {
  return 0;
}
/*@
requires ((x7>0) && \valid(x6+ (0..x7-1)));
assigns \nothing;
*/
int pick_first_element(int  * x6, int  x7) {
  int x9 = picker_first(x7);
  int x10 = x6[x9];
  return x10;
}
/*@
requires ((x16>0) && \valid(x15+ (0..x16-1)));
assigns \nothing;
*/
int pick_first_directly(int  * x15, int  x16) {
  int x18 = x15[0];
  return x18;
}
/*@
requires (x22>0);
assigns \nothing;
ensures ((0<=\result) && (\result<x22));
*/
int picker_last(int  x22) {
  int x24 = x22 - 1;
  return x24;
}
/*@
requires ((x30>0) && \valid(x29+ (0..x30-1)));
assigns \nothing;
*/
int pick_last_element(int  * x29, int  x30) {
  int x32 = picker_last(x30);
  int x33 = x29[x32];
  return x33;
}
/*@
requires ((x39>0) && \valid(x38+ (0..x39-1)));
assigns \nothing;
*/
int pick_last_directly(int  * x38, int  x39) {
  int x41 = x39 - 1;
  int x42 = x38[x41];
  return x42;
}
