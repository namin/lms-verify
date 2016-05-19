#include <stdio.h>

/*@ inductive Permut{L1,L2}(int* a, integer n) {
  @  case Permut_refl{L}:
  @   \forall int* a, integer n; Permut{L,L}(a, n) ;
  @  case Permut_sym{L1,L2}:
  @    \forall int* a, integer n;
  @      Permut{L1,L2}(a, n) ==> Permut{L2,L1}(a, n) ;
  @  case Permut_trans{L1,L2,L3}:
  @    \forall int* a, integer n;
  @      Permut{L1,L2}(a, n) && Permut{L2,L3}(a, n) ==>
  @        Permut{L1,L3}(a, n) ;
  @  case Permut_swap{L1,L2}:
  @    \forall int* a, integer n, i, j;
  @       0 <= i < n && 0 <= j < n &&
  @       \at(a[i],L1)==\at(a[j],L2) &&
  @       \at(a[j],L1)==\at(a[i],L2) &&
  @       (\forall integer k; 0 <= k < n && k != i && k != j ==>
  @        \at(a[k],L1) == \at(a[k],L2)) ==>
  @     Permut{L1,L2}(a, n) ;
  @ }
  @*/

/*@ requires \valid(p+i) && \valid(p+j);
    requires n>0;
    requires \valid(p+(0..n-1));
    requires 0 <= i < n && 0 <= j < n;
    ensures p[i] == \old(p[j]);
    ensures p[j] == \old(p[i]);
    ensures Permut{Old,Post}(p, n);
    assigns p[i], p[j];
*/
void inswap(int* p, int i, int j, int n) {
  int tmp = p[i];
  p[i] = p[j];
  p[j] = tmp;
}

/*@ requires n>0;
    requires \valid(p+(0..n-1));
    ensures \forall int i; 0 <= i < n−1 ==> p[i] <= p[i+1];
    ensures Permut{Old,Post}(p, n);
    assigns p[0..n-1];
*/
void insort(int * p, int n) {
  /*@
    loop invariant (0 <= m <= n);
    loop invariant (m < n-1 ==> \forall int i; m <= i < n−1 ==> p[i] <= p[i+1]);
    loop invariant (\forall int i; 0 <= i < m <= n-1 ==> p[i] <= p[m]);
    loop invariant Permut{Pre,Here}(p, n);
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
      loop invariant Permut{Pre,Here}(p, n);
      loop assigns i, maxi;
      loop variant m-i;
     */
    for (int i=0; i<m; i++)
      if (p[i] >= p[maxi])
        maxi = i;
    inswap(p, m-1, maxi, n);
    //@assert (m <= n-1 ==> p[m-1] <= p[m]);
  }
}

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
