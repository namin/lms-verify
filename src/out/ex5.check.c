/*@
requires \valid(x0+(0..3));
ensures ((x0[0]==\old(x0[1])) && (x0[1]==\old(x0[0])));
*/
void array_swap(int  * x0) {
  int x2 = x0[0];
  int x3 = x0[1];
  x0[0] = x3;
  x0[1] = x2;
}
