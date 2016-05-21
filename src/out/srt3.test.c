#include <stdio.h>
int main(void) {
  int a1[] = {5, 2, 3, 1, 1};
  int a2[] = {0, 1, 7, 1, 7};
  int* p1 = a1;
  int* p2 = a2;
  int n = 5;
  insort_pairs(p1, p2, n);
  /*@
    loop invariant (0 <= i <= n);
    loop invariant \valid(p1+(0..n-1));
    loop invariant \valid(p2+(0..n-1));
    loop variant n-i;
   */
  for (int i=0; i<n; i++) {
    printf("(%d,%d) ", p1[i], p2[i]);
  }
  printf("\n");
}
