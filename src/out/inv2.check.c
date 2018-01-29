#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, integer  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@
requires inv_vec_Int(x16,x17);
assigns \nothing;
ensures inv_vec_Int(x16,x17);
*/
int sum(int  * x16, int  x17) {
  int x19 = 0;
  /*@
  loop invariant 0<=x21<=x17;
  loop assigns x21, x19;
  loop variant x17-x21;
  */
  for(int x21=0; x21 < x17; x21++) {
    int x23 = x19;
    int x22 = x16[x21];
    int x24 = x23 + x22;
    x19 = x24;
  }
  int x28 = x19;
  return x28;
}
