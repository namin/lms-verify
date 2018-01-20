/*@
logic boolean row_col_bool(integer c, int r, int n, int* m, int* v) =
  (0 < c <= n) ? ((row_col_bool(c-1, r, n, m, v)) || (m[n*r+(c-1)] && v[(c-1)])) : 0;
 */

/*@
requires n>0;
requires n<3;

requires \valid(m+(0..n*n-1));
requires \valid(v+(0..n-1));
requires \valid(o+(0..n-1));
requires \separated(m+(0..n*n-1), v+(0..n-1), o+(0..n-1));

assigns o[0..n-1];

ensures \forall int i; 0 <= i < n ==>
  o[i] == row_col_bool(n, i, n, m, v);
*/
void mv_mult_bool(int n, int *m, int *v, int *o) {
  /*@
    loop invariant 0 <= r <= n;
    loop invariant \forall int i; 0 <= i < r ==> o[i] == row_col_bool(n, i, n, m, v);
    loop assigns r, o[0..n-1];
    loop variant n-r;
   */
  for (int r = 0; r < n; r++) {
    o[r] = 0;
    /*@
      loop invariant 0 <= c <= n;
      loop invariant 0 <= r < n;
      loop invariant \forall int i; 0 <= i < r ==> o[i] == row_col_bool(n, i, n, m, v);
      loop invariant o[r] == row_col_bool(c, r, n, m, v);
      loop assigns c, o[r];
      loop variant n-c;
    */
    for (int c = 0; c < n; c++) {
      o[r] = o[r] || (m[n*r+c] && v[c]);
    }
  }
}


/*@
requires n>0;
requires n==2;

requires \valid(m+(0..n*n-1));
requires \valid(v+(0..n-1));
requires \valid(o+(0..n-1));
requires \separated(m+(0..n*n-1), v+(0..n-1), o+(0..n-1));

requires m[0]==1;
requires m[1]==1;
requires m[2]==0;
requires m[3]==0;

assigns o[0..n-1];

ensures \forall int i; 0 <= i < n ==>
  o[i] == row_col_bool(n, i, n, m, v);
*/
void mv_mults_bool(int n, int *m, int *v, int *o) {
  int r = 0;
  o[r] = 0;
  /*@
    loop invariant 0 <= c <= n;
    loop invariant 0 <= r < n;
    loop invariant \forall int i; 0 <= i < r ==> o[i] == row_col_bool(n, i, n, m, v);
    loop invariant o[r] == row_col_bool(c, r, n, m, v);
    loop assigns c, o[r];
    loop variant n-c;
  */
  for (int c = 0; c < n; c++) {
    o[r] = o[r] || (m[n*r+c] && v[c]);
  }
  o[1] = 0;
}
