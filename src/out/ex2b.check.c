/*@
requires (x0>0);
assigns \nothing;
ensures ((0<=\result) && (\result<x0));
*/
int picker_first(int  x0) {
  return 0;
}
/*@
requires ((x7>0) && \valid(x6+(0..x7-1)));
assigns \nothing;
*/
int pick_first_element(int  * x6, int  x7) {
  int x9 = picker_first(x7);
  int x10 = x6[x9];
  return x10;
}
/*@
requires ((x16>0) && \valid(x15+(0..x16-1)));
assigns \nothing;
*/
int pick_first_directly(int  * x15, int  x16) {
  int x18 = x15[0];
  return x18;
}
/*@
requires (x23>0);
assigns \nothing;
ensures ((0<=\result) && (\result<x23));
*/
int picker_last(int  x23) {
  int x25 = x23 - 1;
  return x25;
}
/*@
requires ((x31>0) && \valid(x30+(0..x31-1)));
assigns \nothing;
*/
int pick_last_element(int  * x30, int  x31) {
  int x33 = picker_last(x31);
  int x34 = x30[x33];
  return x34;
}
/*@
requires ((x40>0) && \valid(x39+(0..x40-1)));
assigns \nothing;
*/
int pick_last_directly(int  * x39, int  x40) {
  int x42 = x40 - 1;
  int x43 = x39[x42];
  return x43;
}
