#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, int  x1) = ((x1==0) || ((x1>0) && \valid(x0+(0..x1-1))));*/
/*@ predicate inv_vec_vec_Int(int  * * x16, int  * x17, int  x18) = (((x18==0) || ((x18>0) && (\valid(x16+(0..x18-1)) &&
\valid(x17+(0..x18-1))))) && (\forall int x28; (0<=x28<x18) ==> ((x17[x28]==0) || ((x17[x28]>0) && \valid(x16[x28]+(0..x17[x28]-1))))));*/
/*@
requires inv_vec_vec_Int(x66,x67,x68);
assigns \nothing;
ensures inv_vec_vec_Int(x66,x67,x68);
*/
int count_pos(int  * * x66, int  * x67, int  x68) {
  int x70 = 0;
  /*@
  loop invariant 0<=x72<=x68;
  loop invariant ((0<=x70) && (x70<=x72));
  loop assigns x72, x70;
  loop variant x68-x72;
  */
  for(int x72=0; x72 < x68; x72++) {
    int x75 = x70;
    int x81 = 0;
    int x74 = x67[x72];
    int  *x73 = x66[x72];
    /*@
    loop invariant 0<=x83<=x74;
    loop invariant ((0<=x81) && (x81<=x83));
    loop assigns x83, x81;
    loop variant x74-x83;
    */
    for(int x83=0; x83 < x74; x83++) {
      int x85 = x81;
      int x84 = x73[x83];
      int x91 = x84 > 0;
      int x92;
      if (x91) {
        x92 = 1;
      } else {
        x92 = 0;
      }
      int x93 = x85 + x92;
      x81 = x93;
    }
    int x97 = x81;
    int x98 = x97 > 0;
    int x99;
    if (x98) {
      x99 = 1;
    } else {
      x99 = 0;
    }
    int x100 = x75 + x99;
    x70 = x100;
  }
  int x104 = x70;
  return x104;
}
