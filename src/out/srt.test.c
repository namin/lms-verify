#include <stdio.h>
int main(void) {
  int a[] = {5, 2, 3, 1, 4};
  int* p = a;
  int n = 5;
  insort(p, n);
  /*@
    loop invariant (0 <= i <= n);
    loop invariant \valid(p+(0..n-1));
    loop variant n-i;
   */
  for (int i=0; i<n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}
