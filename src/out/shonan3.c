/*@
predicate Unchanged{K,L}(int* a, integer m, integer n) =
  \forall integer i; m <= i < n ==> \at(a[i],K) == \at(a[i],L);

predicate Unchanged{K,L}(int* a, integer n) =
  Unchanged{K,L}(a, 0, n);
*/

/*@
axiomatic MV_Prod
{
logic integer
MV_Prod{L}(integer c, integer r, integer n, int* m, int* v) reads m[0..n*n-1], v[0..n-1];

axiom
MV_Prod_Empty{L}:
\forall integer c, r, n, int* m, int* v;
  (!(0 < c <= n) || !(0 <= r < n)) ==> MV_Prod(c, r, n, m, v) == 0;

axiom
MV_Prod_One{L}:
\forall integer c, r, n, int* m, int* v;
  ((0 < c <= n) && (0 <= r < n)) ==> MV_Prod(c, r, n, m, v) == MV_Prod(c-1, r, n, m, v) + (m[n*r+(c-1)] * v[(c-1)]);

axiom
MV_Prod_Read{K,L}:
\forall integer c, r, n, int* m, int* v;
  (Unchanged{K,L}(m, n*n) && Unchanged{K,L}(v, n)) ==>
    MV_Prod{K}(c, r, n, m, v) == MV_Prod{L}(c, r, n, m, v);
}
*/

/*@
requires n>0;
requires 0 <= i < n;
requires \valid(m+(0..n*n-1));
requires \valid(v+(0..n-1));
requires \valid(o+(0..n-1));
requires \separated(m+(0..n*n-1), v+(0..n-1), o+(0..n-1));

ensures \forall int j; 0 <= j < n && j != i ==> o[j]==\old(o[j]);
ensures \forall int j; 0 <= j < n*n ==> m[j]==\old(m[j]);
ensures \forall int j; 0 <= j < n ==> v[j]==\old(v[j]);
ensures \forall int j; 0 <= j < n ==> MV_Prod(n, j, n, m, v)==\old(MV_Prod(n, j, n, m, v));
ensures o[i]==a;
assigns o[i];
*/
void put(int* o, int i, int a, int n, int* m, int* v) {
  o[i] = a;
}

/*@
requires n>0;
requires n<10;

requires \valid(m+(0..n*n-1));
requires \valid(v+(0..n-1));
requires \valid(o+(0..n-1));
requires \separated(m+(0..n*n-1), v+(0..n-1), o+(0..n-1));

requires \forall int i; 0 <= i < n*n ==> 0 <= m[i] <= 1;
requires \forall int i; 0 <= i < n ==> 0 <= v[i] <= 9;

assigns o[0..n-1];

ensures \forall int i; 0 <= i < n ==> o[i] == MV_Prod(n, i, n, m, v);
*/
void mv_prod(int n, int *m, int *v, int *o) {
  /*@
    loop invariant 0 <= r <= n;
    loop invariant \forall int i; 0 <= i < r ==> o[i] == MV_Prod(n, i, n, m, v);
    loop assigns r, o[0..n-1];
    loop variant n-r;
   */
  for (int r = 0; r < n; r++) {
    int t = 0;
    /*@
      loop invariant 0 <= c <= n;
      loop invariant 0 <= r < n;
      loop invariant \forall int i; 0 <= i < r ==> o[i] == MV_Prod(n, i, n, m, v);
      loop invariant t == MV_Prod(c, r, n, m, v);
      loop assigns c, t;
      loop variant n-c;
    */
    for (int c = 0; c < n; c++) {
      t = t + (m[n*r+c] * v[c]);
    }
    put(o, r, t, n, m, v);
  }
}
