/*@
requires (((x1>0) && \valid(x0+(0..x1-1))) && \valid(x2+(0..x1-1)));
ensures ((((0<=\result) && (\result<=x1)) && (\forall int  x74; (((0<=x74) && (x74<\result)) ==> ((0<=x2[x74]) && (x2[x74]<x1))))) && (\forall int  x86; (((0<x86) && (x86<\result)) ==> (x2[(x86-1)]<x2[x86]))));
assigns x2[(0..x1-1)];
*/
int index_where_even(int  * x0, int  x1, int  * x2) {
  int x5 = 0;
  /*@
  loop invariant ((((((0<=x6) && (x6<=x1)) && (0<=x5)) && (x5<=x6)) && (\forall int  x28; (((0<=x28) && (x28<x5)) ==> ((0<=x2[x28]) && (x2[x28]<x6))))) && (\forall int  x42; (((0<x42) && (x42<x5)) ==> (x2[(x42-1)]<x2[x42]))));
  loop assigns x6, x5, x2[(0..x1-1)];
  loop variant (x1-x6);
  */
  for(int x6=0; x6 < x1; x6++) {
    int x7 = x0[x6];
    int x8 = x7 % 2;
    int x9 = x8 == 0;
    if (x9) {
      int x10 = x5;
      x2[x10] = x6;
      x5 += 1;
    } else {
    }
  }
  int x62 = x5;
  return x62;
}
