/*@
ensures (\result==(x0*x0));
*/
int square(int  x0) {
  int x2 = x0 * x0;
  return x2;
}
/*@
ensures (\result==(((x4*x4)*x4)*x4));
*/
int pow4(int  x4) {
  int x6 = square(x4);
  int x7 = square(x6);
  return x7;
}
/*@
ensures (\result==(((x13*x13)*x13)*x13));
*/
int pow4b(int  x13) {
  int x15 = square(x13);
  int x16 = square(x13);
  int x17 = x15 * x16;
  return x17;
}
