/*@
requires (x0>0);
assigns \nothing;
ensures ((0<=\result) && (\result<x0));
*/
int pick_index(int  x0) {
  return 0;
}
/*@
requires ((x7>0) && \valid(x6+ (0..x7-1)));
assigns \nothing;
*/
int pick_element(int  * x6, int  x7) {
  int x9 = pick_index(x7);
  int x10 = x6[x9];
  return x10;
}
/*@
requires ((x16>0) && \valid(x15+ (0..x16-1)));
assigns \nothing;
*/
int pick_first(int  * x15, int  x16) {
  int x18 = x15[0];
  return x18;
}
