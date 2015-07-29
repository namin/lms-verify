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
requires ((x15>0) && \valid(x14+ (0..x15-1)));
assigns \nothing;
*/
int pick_first_directly(int  * x14, int  x15) {
  int x17 = x14[0];
  return x17;
}
/*@
requires (x21>0);
assigns \nothing;
ensures ((0<=\result) && (\result<x21));
*/
int picker_last(int  x21) {
  int x23 = x21 - 1;
  return x23;
}
/*@
requires ((x29>0) && \valid(x28+ (0..x29-1)));
assigns \nothing;
*/
int pick_last_element(int  * x28, int  x29) {
  int x31 = picker_last(x29);
  int x32 = x28[x31];
  return x32;
}
/*@
requires ((x37>0) && \valid(x36+ (0..x37-1)));
assigns \nothing;
*/
int pick_last_directly(int  * x36, int  x37) {
  int x39 = x37 - 1;
  int x40 = x36[x39];
  return x40;
}
