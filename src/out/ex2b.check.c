/*@
requires (x0>0);
assigns \nothing;
ensures ((0<=\result) && (\result<x0));
*/
int pick_first(int  x0) {
  return 0;
}
/*@
requires ((x7>0) && \valid(x6+ (0..x7-1)));
assigns \nothing;
*/
int pick_first_element(int  * x6, int  x7) {
  int x9 = pick_first(x7);
  int x10 = x6[x9];
  return x10;
}
/*@
requires (x15>0);
assigns \nothing;
ensures ((0<=\result) && (\result<x15));
*/
int pick_last(int  x15) {
  int x17 = x15 - 1;
  return x17;
}
/*@
requires ((x23>0) && \valid(x22+ (0..x23-1)));
assigns \nothing;
*/
int pick_last_element(int  * x22, int  x23) {
  int x25 = pick_last(x23);
  int x26 = x22[x25];
  return x26;
}
