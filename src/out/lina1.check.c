/*@
requires ((((((((x2>0) && (x3>0)) && (0<=x0)) && (x0<x2)) && (0<=x1)) && (x1<x1)) && (x2<100)) && (x3<100));
assigns \nothing;
ensures ((0<=\result) && (\result<(x2*x3)));
*/
int index(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x0 * x3;
  int x6 = x5 + x1;
  return x6;
}
