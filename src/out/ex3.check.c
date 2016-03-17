#include <limits.h>
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
ensures (\result==(((x6*x6)*x6)*x6));
*/
int pow4(int  x6) {
  int x8 = square(x6);
  int x9 = square(x8);
  return x9;
}
/*@
assigns \nothing;
ensures (\result==(((x15*x15)*x15)*x15));
*/
int pow4b(int  x15) {
  int x17 = square(x15);
  int x18 = x17 * x17;
  return x18;
}
