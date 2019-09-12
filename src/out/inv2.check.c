#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, integer  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@
requires inv_vec_Int(x15,x16);
assigns \nothing;
ensures inv_vec_Int(x15,x16);
*/
int sum(int  * x15, int  x16) {
  int x18 = 0;
  /*@
  loop invariant 0<=x20<=x16;
  loop assigns x20, x18;
  loop variant x16-x20;
  */
  for(int x20=0; x20 < x16; x20++) {
    int x22 = x18;
    int x21 = x15[x20];
    int x23 = x22 + x21;
    x18 = x23;
  }
  int x27 = x18;
  return x27;
}
