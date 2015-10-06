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
requires ((((((((((((((((x27>0) && (x28>0)) && (x30>0)) && (x34>0)) && (x28==x30)) && (x27==x33)) && (x34==x31)) && (x27<100)) && (x28<100)) && (x30<100)) && (x31<100)) && (x33<100)) && (x34<100)) && \valid(x26+(0..(x27*x28)-1))) && \valid(x29+(0..(x30*x31)-1))) && \valid(x32+(0..(x33*x34)-1)));
*/
void mm_mult(int  * x26, int  x27, int  x28, int  * x29, int  x30, int  x31, int  * x32, int  x33, int  x34) {
  /*@
  loop invariant ((0<=x37) && (x37<=x27));
  loop assigns x37, x32[(0..(x33*x34)-1)];
  loop variant (x27-x37);
  */
  for(int x37=0; x37 < x27; x37++) {
    /*@
    loop invariant ((0<=x39) && (x39<=x31));
    loop assigns x39, x32[(0..(x33*x34)-1)];
    loop variant (x31-x39);
    */
    for(int x39=0; x39 < x31; x39++) {
      int x40 = index(x37,x39,x33,x34);
      x32[x40] = 0;
      /*@
      loop invariant ((0<=x43) && (x43<=x28));
      loop assigns x43, x32[(0..(x33*x34)-1)];
      loop variant (x28-x43);
      */
      for(int x43=0; x43 < x28; x43++) {
        int x44 = x32[x40];
        int x45 = index(x37,x43,x27,x28);
        int x46 = x26[x45];
        int x47 = index(x43,x39,x30,x31);
        int x48 = x29[x47];
        int x49 = x46 * x48;
        int x50 = x44 + x49;
        x32[x40] = x50;
      }
    }
  }
}
