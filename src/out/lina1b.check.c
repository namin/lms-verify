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
requires ((((((((x37>0) && (x38>0)) && (x37<100)) && (x38<100)) && \valid(x36+(0..(x37*x38)-1))) && (((((x40>0) && (x41>0)) && (x40<100)) && (x41<100)) && \valid(x39+(0..(x40*x41)-1)))) && (((((x43>0) && (x44>0)) && (x43<100)) && (x44<100)) && \valid(x42+(0..(x43*x44)-1)))) && (((x38==x40) && (x37==x43)) && (x44==x41)));
*/
void mm_mult(int  * x36, int  x37, int  x38, int  * x39, int  x40, int  x41, int  * x42, int  x43, int  x44) {
  /*@
  loop invariant 0<=x49<=x37;
  loop assigns x49, x42[(0..(x43*x44)-1)];
  loop variant x37-x49;
  */
  for(int x49=0; x49 < x37; x49++) {
    /*@
    loop invariant 0<=x51<=x41;
    loop assigns x51, x42[(0..(x43*x44)-1)];
    loop variant x41-x51;
    */
    for(int x51=0; x51 < x41; x51++) {
      int x52 = index(x49,x51,x43,x44);
      x42[x52] = 0;
      /*@
      loop invariant 0<=x55<=x38;
      loop assigns x55, x42[(0..(x43*x44)-1)];
      loop variant x38-x55;
      */
      for(int x55=0; x55 < x38; x55++) {
        int x56 = x42[x52];
        int x57 = index(x49,x55,x37,x38);
        int x58 = x36[x57];
        int x59 = index(x55,x51,x40,x41);
        int x60 = x39[x59];
        int x61 = x58 * x60;
        int x62 = x56 + x61;
        x42[x52] = x62;
      }
    }
  }
}
