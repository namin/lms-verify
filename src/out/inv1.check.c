#include <limits.h>
//@ predicate inv_vec_Int(int  * x0, int  x1) = ((0<=x1) && ((x1==0) || ((x1>0) && \valid(x0+(0..x1-1)))));
//@ predicate inv_vec_vec_Int(int  * * x18, int  * x19, int  x20) = (((0<=x20) && ((x20==0) || ((x20>0) && (\valid(x18+(0..x20-1)) && \valid(x19+(0..x20-1)))))) && (\forall int x32; (0<=x32<x20) ==> ((0<=x19[x32]) && ((x19[x32]==0) || ((x19[x32]>0) && \valid(x18[x32]+(0..x19[x32]-1)))))));
//@ predicate eq(int  * * x75, int  * x76, int  x77, int  * * x78, int  * x79, int  x80) = ((x77==x80) && (\forall int x84; (0<=x84<x77) ==> ((x76[x84]==x79[x84]) && (\forall int x92; (0<=x92<x76[x84]) ==> (x75[x84][x92]==x78[x84][x92])))));
/*@
requires (inv_vec_vec_Int(x75,x76,x77) && inv_vec_vec_Int(x78,x79,x80));
assigns \nothing;
ensures \result <==> eq(x75, x76, x77, x78, x79, x80);
*/
int eq(int  * * x75, int  * x76, int  x77, int  * * x78, int  * x79, int  x80) {
  int x82 = x77 == x80;
  int x124;
  if (x82) {
    int x123 = 1;
    /*@ loop invariant (0 <= x85 <= x77);
    loop invariant \forall int x84; (0 <= x84 < x85) ==>  ((x76[x84]==x79[x84]) && (\forall int x92; (0<=x92<x76[x84]) ==> (x75[x84][x92]==x78[x84][x92])));
    loop assigns x85;
    loop variant (x77-x85); */
    for (int x85 = 0; x85 < x77; x85++) {
      int x107 = x76[x85];
      int x109 = x79[x85];
      int x110 = x107 == x109;
      int x122;
      if (x110) {
        int  *x106 = x75[x85];
        int  *x108 = x78[x85];
        int x121 = 1;
        /*@ loop invariant (0 <= x113 <= x107);
        loop invariant \forall int x112; (0 <= x112 < x113) ==>  (x106[x112]==x108[x112]);
        loop assigns x113;
        loop variant (x107-x113); */
        for (int x113 = 0; x113 < x107; x113++) {
          int x118 = x106[x113];
          int x119 = x108[x113];
          int x120 = x118 == x119;
          if (!x120) { x121 = 0; break; }
        }
        x122 = x121;
      } else {
        x122 = 0/*false*/;
      }
      if (!x122) { x123 = 0; break; }
    }
    x124 = x123;
  } else {
    x124 = 0/*false*/;
  }
  return x124;
}
