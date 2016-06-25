#include <limits.h>
/*@
requires (((x1>0) &&
\valid(x0+(0..x1-1))) &&
\valid(x2+(0..x1-1)));
ensures ((((0<=\result) &&
(\result<=x1)) &&
(\forall int  x85; (((0<=x85) &&
(x85<\result)) ==> ((0<=x2[x85]) &&
(x2[x85]<x1))))) &&
(\forall int  x101; (((0<x101) &&
(x101<\result)) ==> (x2[(x101-1)]<x2[x101]))));
assigns x2[(0..x1-1)];
*/
int index_where_even(int  * x0, int  x1, int  * x2) {
  int x5 = 0;
  /*@
  loop invariant ((((((0<=x6) &&
  (x6<=x1)) &&
  (0<=x5)) &&
  (x5<=x6)) &&
  (\forall int  x29; (((0<=x29) &&
  (x29<x5)) ==> ((0<=x2[x29]) &&
  (x2[x29]<x6))))) &&
  (\forall int  x46; (((0<x46) &&
  (x46<x5)) ==> (x2[(x46-1)]<x2[x46]))));
  loop assigns x6, x5, x2[(0..x1-1)];
  loop variant (x1-x6);
  */
  for(int x6=0; x6 < x1; x6++) {
    int x7 = x0[x6];
    int x8 = x7 % 2;
    int x9 = x8 == 0;
    if (x9) {
      int x10 = x5;
      x2[x10] = x6;
      x5 += 1;
    } else {
    }
  }
  int x69 = x5;
  return x69;
}
