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
requires ((((((((x27>0) && (x28>0)) && (x27<100)) && (x28<100)) && \valid(x26+(0..(x27*x28)-1))) && (((((x30>0) && (x31>0)) && (x30<100)) && (x31<100)) && \valid(x29+(0..(x30*x31)-1)))) && (((((x33>0) && (x34>0)) && (x33<100)) && (x34<100)) && \valid(x32+(0..(x33*x34)-1)))) && (((x28==x30) && (x27==x33)) && (x34==x31)));
*/
void mm_mult(int  * x26, int  x27, int  x28, int  * x29, int  x30, int  x31, int  * x32, int  x33, int  x34) {
  /*@
  loop invariant 0<=x39<=x27;
  loop assigns x39, x32[(0..(x33*x34)-1)];
  loop variant x27-x39;
  */
  for(int x39=0; x39 < x27; x39++) {
    /*@
    loop invariant 0<=x41<=x31;
    loop assigns x41, x32[(0..(x33*x34)-1)];
    loop variant x31-x41;
    */
    for(int x41=0; x41 < x31; x41++) {
      int x42 = index(x39,x41,x33,x34);
      x32[x42] = 0;
      /*@
      loop invariant 0<=x45<=x28;
      loop assigns x45, x32[(0..(x33*x34)-1)];
      loop variant x28-x45;
      */
      for(int x45=0; x45 < x28; x45++) {
        int x46 = x32[x42];
        int x47 = index(x39,x45,x27,x28);
        int x48 = x26[x47];
        int x49 = index(x45,x41,x30,x31);
        int x50 = x29[x49];
        int x51 = x48 * x50;
        int x52 = x46 + x51;
        x32[x42] = x52;
      }
    }
  }
}
