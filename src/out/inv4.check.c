#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, integer  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@ predicate inv_vec_vec_Int(int  * * x15, int  * x16, integer  x17) = (((x17==0) || ((x17>0) &&
(\valid(x15+(0..x17-1)) &&
\valid(x16+(0..x17-1))))) &&
(\forall int x27; (0<=x27<x17) ==> ((x16[x27]==0) || ((x16[x27]>0) &&
\valid(x15[x27]+(0..x16[x27]-1))))));*/
/*@
requires inv_vec_vec_Int(x58,x59,x60);
assigns \nothing;
ensures inv_vec_vec_Int(x58,x59,x60);
*/
int count_pos(int  * * x58, int  * x59, int  x60) {
  int x62 = 0;
  /*@
  loop invariant 0<=x64<=x60;
  loop invariant ((0<=x62) &&
  (x62<=x64));
  loop assigns x64, x62;
  loop variant x60-x64;
  */
  for(int x64=0; x64 < x60; x64++) {
    int x67 = x62;
    int x71 = 0;
    int x66 = x59[x64];
    int  *x65 = x58[x64];
    /*@
    loop invariant 0<=x73<=x66;
    loop invariant ((0<=x71) &&
    (x71<=x73));
    loop assigns x73, x71;
    loop variant x66-x73;
    */
    for(int x73=0; x73 < x66; x73++) {
      int x75 = x71;
      int x74 = x65[x73];
      int x79 = x74 > 0;
      int x80;
      if (x79) {
        x80 = 1;
      } else {
        x80 = 0;
      }
      int x81 = x75 + x80;
      x71 = x81;
    }
    int x85 = x71;
    int x86 = x85 > 0;
    int x87;
    if (x86) {
      x87 = 1;
    } else {
      x87 = 0;
    }
    int x88 = x67 + x87;
    x62 = x88;
  }
  int x92 = x62;
  return x92;
}
