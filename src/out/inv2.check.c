#include <limits.h>
//@ predicate inv_vec_Int(int  * x0, int  x1) = ((0<=x1) && ((x1==0) || ((x1>0) && \valid(x0+(0..x1-1)))));
/*@
requires inv_vec_Int(x18,x19);
assigns \nothing;
*/
int sum(int  * x18, int  x19) {
  int x21 = 0;
  /*@
  loop invariant 0<=x23<=x19;
  loop assigns x23, x21;
  loop variant x19-x23;
  */
  for(int x23=0; x23 < x19; x23++) {
    int x25 = x21;
    int x24 = x18[x23];
    int x26 = x25 + x24;
    x21 = x26;
  }
  int x30 = x21;
  return x30;
}
