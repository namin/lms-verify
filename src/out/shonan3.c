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

/*@
requires n>0;
requires n==5;

requires \valid(m+(0..n*n-1));
requires \valid(v+(0..n-1));
requires \valid(o+(0..n-1));
requires \separated(m+(0..n*n-1), v+(0..n-1), o+(0..n-1));

requires m[0]==1;
requires m[1]==1;
requires m[2]==1;
requires m[3]==1;
requires m[4]==1;

requires m[5]==0;
requires m[6]==0;
requires m[7]==0;
requires m[8]==0;
requires m[9]==0;

requires m[10]==0;
requires m[11]==0;
requires m[12]==1;
requires m[13]==0;
requires m[14]==0;

requires m[15]==0;
requires m[16]==0;
requires m[17]==0;
requires m[18]==0;
requires m[19]==0;

requires m[20]==0;
requires m[21]==0;
requires m[22]==1;
requires m[23]==0;
requires m[24]==1;

requires \forall int i; 0 <= i < n ==> 0 <= v[i] <= 9;

assigns o[0..n-1];

ensures \forall int i; 0 <= i < n ==> o[i] == MV_Prod(n, i, n, m, v);
*/
void mv_prod_s(int n, int *m, int *v, int *o) {
  int r = 0;
  //@assert \forall int i; 0 <= i < r ==> o[i] == MV_Prod(n, i, n, m, v);
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
    t = t + (m[c] * v[c]);
  }
  put(o, r, t, n, m, v);
  r = 1;
  //@assert \forall int i; 0 <= i < r ==> o[i] == MV_Prod(n, i, n, m, v);
  t = 0;
  //@assert t == MV_Prod(0, r, n, m, v);
  //@assert t == MV_Prod(1, r, n, m, v);
  //@assert t == MV_Prod(2, r, n, m, v);
  //@assert t == MV_Prod(3, r, n, m, v);
  //@assert t == MV_Prod(4, r, n, m, v);
  //@assert t == MV_Prod(n, r, n, m, v);
  put(o, r, t, n, m, v);
  r = 2;
  //@assert \forall int i; 0 <= i < r ==> o[i] == MV_Prod(n, i, n, m, v);
  t = 0;
  //@assert t == MV_Prod(0, r, n, m, v);
  //@assert t == MV_Prod(1, r, n, m, v);
  //@assert t == MV_Prod(2, r, n, m, v);
  t += v[2];
  //@assert t == MV_Prod(3, r, n, m, v);
  //@assert t == MV_Prod(4, r, n, m, v);
  //@assert t == MV_Prod(n, r, n, m, v);
  put(o, r, t, n, m, v);
  r = 3;
  //@assert \forall int i; 0 <= i < r ==> o[i] == MV_Prod(n, i, n, m, v);
  t = 0;
  //@assert t == MV_Prod(0, r, n, m, v);
  //@assert t == MV_Prod(1, r, n, m, v);
  //@assert t == MV_Prod(2, r, n, m, v);
  //@assert t == MV_Prod(3, r, n, m, v);
  //@assert t == MV_Prod(4, r, n, m, v);
  //@assert t == MV_Prod(n, r, n, m, v);
  put(o, r, t, n, m, v);
  r = 4;
  //@assert \forall int i; 0 <= i < r ==> o[i] == MV_Prod(n, i, n, m, v);
  t = 0;
  //@assert t == MV_Prod(0, r, n, m, v);
  //@assert t == MV_Prod(1, r, n, m, v);
  //@assert t == MV_Prod(2, r, n, m, v);
  t += v[2];
  //@assert t == MV_Prod(3, r, n, m, v);
  //@assert t == MV_Prod(4, r, n, m, v);
  t += v[4];
  //@assert t == MV_Prod(n, r, n, m, v);
  put(o, r, t, n, m, v);
  //@assert \forall int i; 0 <= i < n ==> o[i] == MV_Prod(n, i, n, m, v);
}
