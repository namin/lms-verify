//#include <stdio.h>

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
    assigns p[0..n-1];
*/
void insort(int * p, int n) {
  /*@
    loop invariant (0 <= m <= n);
    loop invariant (\forall int i; m <= i < n−1 ==> p[i] <= p[i+1]);
    loop invariant (\forall int i; 0 <= i < m <= n-1 ==> p[i] <= p[m]);
    loop assigns m, p[0..n-1];
    loop variant m;
   */
  for (int m=n; m>0; m--) {
    int maxi = 0;
    /*@
      loop invariant (0 < m <= n);
      loop invariant (0 <= i <= m);
      loop invariant (0 <= maxi <= m-1 < n);
      loop invariant (\forall int j; 0 <= j < i ==> p[j] <= p[maxi]);
      loop assigns i, maxi;
      loop variant m-i;
     */
    for (int i=0; i<m; i++)
      if (p[i] >= p[maxi])
        maxi = i;
    inswap(p, m-1, maxi);
    //@assert (m <= n-1 ==> p[m-1] <= p[m]);
  }
}

/*
int main(void) {
  int p[] = {5, 2, 3, 1, 4};
  int n = 5;
  insort(p, n);
  for (int i=0; i<n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}
*/
