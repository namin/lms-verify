/*@
assigns \nothing;
ensures (\result==(x0*x0));
*/
int square(int  x0) {
  int x2 = x0 * x0;
  return x2;
}
/*@
assigns \nothing;
ensures (\result==(((x4*x4)*x4)*x4));
*/
int pow4(int  x4) {
  int x6 = square(x4);
  int x7 = square(x6);
  return x7;
}
/*@
assigns \nothing;
ensures (\result==(((x12*x12)*x12)*x12));
*/
int pow4b(int  x12) {
  int x14 = square(x12);
  int x15 = x14 * x14;
  return x15;
}
