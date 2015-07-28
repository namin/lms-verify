#include <stdio.h>

/*@ requires \valid(p+i) && \valid(p+j);
    ensures p[i] == \old(p[j]);
    ensures p[j] == \old(p[i]);
    assigns p[i], p[j];
*/
void inswap(int* p, int i, int j) {
  int tmp = p[i];
  p[i] = p[j];
  p[j] = tmp;
}

/*@ requires n>0;
    requires \valid(p+(0..n-1));
    ensures \forall int i; 0 <= i < n−1 ==> p[i] <= p[i+1];
    ensures \forall int i; 0 <= i <= n−1 ==> \exists int j; 0 <= j <= n-1 ==> p[i] == \old(p[j]);
    assigns p[0..n-1];
*/
void insort(int * p, int n) {
  /*@ loop invariant
    (\forall int i; m <= i < n−1 ==> p[i] <= p[i+1]) &&
    (\forall int i; 0 <= i < m < n-1 ==> p[i] <= p[m]);
    loop assigns p[0..m-1];
    loop variant m-1;
   */
  for (int m=n; m>1; m--) {
    int maxi = 0;
    /*@ loop invariant
      (\forall int j; 0 <= j < i ==> p[maxi] >= p[j]);
      loop assigns maxi;
      loop variant m-i;
     */
    for (int i=0; i<m; i++)
      if (p[i] >= p[maxi])
        maxi = i;
    inswap(p, m-1, maxi);
    //@assert (\forall int i; 0 <= i < m-1 < n-1 ==> p[i] <= p[m-1]);
  }
}

int main(void) {
  int p[] = {5, 2, 3, 1, 4};
  int n = 5;
  insort(p, n);
  for (int i=0; i<n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}
