#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, integer  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@
requires inv_vec_Int(x15,x16);
assigns \nothing;
ensures inv_vec_Int(x15,x16);
*/
int count_pos(int  * x15, int  x16) {
  int x18 = 0;
  /*@
  loop invariant 0<=x20<=x16;
  loop invariant ((0<=x18) &&
  (x18<=x20));
  loop assigns x20, x18;
  loop variant x16-x20;
  */
  for(int x20=0; x20 < x16; x20++) {
    int x22 = x18;
    int x21 = x15[x20];
    int x26 = x21 > 0;
    int x27;
    if (x26) {
      x27 = 1;
    } else {
      x27 = 0;
    }
    int x28 = x22 + x27;
    x18 = x28;
  }
  int x32 = x18;
  return x32;
}
