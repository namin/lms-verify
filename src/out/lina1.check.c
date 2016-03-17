#include <limits.h>
/*@
requires ((((((((x2>0) && (x3>0)) && (0<=x0)) && (x0<x2)) && (0<=x1)) && (x1<x3)) && (x2<100)) && (x3<100));
assigns \nothing;
ensures ((0<=\result) && (\result<(x2*x3)));
*/
int index(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x0 * x3;
  int x6 = x5 + x1;
  return x6;
}
/*@
requires ((((((((((((((((x37>0) && (x38>0)) && (x40>0)) && (x44>0)) && (x38==x40)) && (x37==x43)) && (x44==x41)) && (x37<100)) && (x38<100)) && (x40<100)) && (x41<100)) && (x43<100)) && (x44<100)) && \valid(x36+(0..(x37*x38)-1))) && \valid(x39+(0..(x40*x41)-1))) && \valid(x42+(0..(x43*x44)-1)));
*/
void mm_mult(int  * x36, int  x37, int  x38, int  * x39, int  x40, int  x41, int  * x42, int  x43, int  x44) {
  /*@
  loop invariant ((0<=x47) && (x47<=x37));
  loop assigns x47, x42[(0..(x43*x44)-1)];
  loop variant (x37-x47);
  */
  for(int x47=0; x47 < x37; x47++) {
    /*@
    loop invariant ((0<=x49) && (x49<=x41));
    loop assigns x49, x42[(0..(x43*x44)-1)];
    loop variant (x41-x49);
    */
    for(int x49=0; x49 < x41; x49++) {
      int x50 = index(x47,x49,x43,x44);
      x42[x50] = 0;
      /*@
      loop invariant ((0<=x53) && (x53<=x38));
      loop assigns x53, x42[(0..(x43*x44)-1)];
      loop variant (x38-x53);
      */
      for(int x53=0; x53 < x38; x53++) {
        int x54 = x42[x50];
        int x55 = index(x47,x53,x37,x38);
        int x56 = x36[x55];
        int x57 = index(x53,x49,x40,x41);
        int x58 = x39[x57];
        int x59 = x56 * x58;
        int x60 = x54 + x59;
        x42[x50] = x60;
      }
    }
  }
}
