/*@
requires \valid(m+(0..3));
requires \valid(v+(0..1));
requires \valid(o+(0..1));
requires \forall int i; \forall int j;
  0 <= i < 4 && 0 <= j < 2 ==> \separated(m+i,o+j);
requires \forall int i; \forall int j;
  0 <= i < 2 && 0 <= j < 2 ==> \separated(v+i,o+j);

assigns o[0..1];

ensures o[0] == (m[0] && v[0]) || (m[1] && v[1]);
ensures o[1] == (m[2] && v[0]) || (m[3] && v[1]);
*/
void mv_mult2_bool(int *m, int *v, int *o) {
  o[0] = (m[0] && v[0]) || (m[1] && v[1]);
  o[1] = (m[2] && v[0]) || (m[3] && v[1]);
}

/*@
requires \valid(m+(0..3));
requires \valid(v+(0..1));
requires \valid(o+(0..1));
requires \forall int i; \forall int j;
  0 <= i < 4 && 0 <= j < 2 ==> \separated(m+i,o+j);
requires \forall int i; \forall int j;
  0 <= i < 2 && 0 <= j < 2 ==> \separated(v+i,o+j);

requires \forall int i; 0 <= i < 4 ==> 0 <= m[i] <= 1;
requires \forall int i; 0 <= i < 2 ==> 0 <= v[i] <= 1;

assigns o[0..1];

ensures o[0] == m[0]*v[0]+m[1]*v[1];
ensures o[1] == m[2]*v[0]+m[3]*v[1];
*/
void mv_mult2(int *m, int *v, int *o) {
  o[0] = m[0]*v[0]+m[1]*v[1];
  o[1] = m[2]*v[0]+m[3]*v[1];
}

/*@
requires n==2;

requires \valid(m+(0..n*n-1));
requires \valid(v+(0..n-1));
requires \valid(o+(0..n-1));
requires \forall int i; \forall int j;
  0 <= i < n*n && 0 <= j < n ==> \separated(m+i,o+j);
requires \forall int i; \forall int j;
  0 <= i < n && 0 <= j < n ==> \separated(v+i,o+j);

assigns o[0..n-1];

ensures \forall int i; 0 <= i < n ==> o[i] == (m[n*i+0] && v[0]) || (m[n*i+1] && v[1]);
*/
void mv_mult2r_bool(int n, int *m, int *v, int *o) {
  /*@
    loop invariant 0 <= r <= n;
    loop invariant \forall int i; 0 <= i < r ==> o[i] == (m[n*i+0] && v[0]) || (m[n*i+1] && v[1]);
    loop assigns r, o[0..n-1];
    loop variant n-r;
   */
  for (int r = 0; r < n; r++) {
    int t = 0;
    /*@
      loop invariant 0 <= c <= n;
      loop invariant t == ((c==0) ? 0 : ((m[n*r+0] && v[0]) || ((c==1)? 0 : (m[n*r+1] && v[1]))));
      loop assigns c, t;
      loop variant n-c;
    */
    for (int c = 0; c < n; c++) {
      t = t || (m[n*r+c] && v[c]);
    }
    o[r] = t;
  }  
}

/*@
requires n==2;

requires \valid(m+(0..n*n-1));
requires \valid(v+(0..n-1));
requires \valid(o+(0..n-1));
requires \forall int i; \forall int j;
  0 <= i < n*n && 0 <= j < n ==> \separated(m+i,o+j);
requires \forall int i; \forall int j;
  0 <= i < n && 0 <= j < n ==> \separated(v+i,o+j);

requires m[0]==1;
requires m[1]==1;
requires m[2]==0;
requires m[3]==0;

assigns o[0..n-1];

ensures \forall int i; 0 <= i < n ==> o[i] == (m[n*i+0] && v[0]) || (m[n*i+1] && v[1]);
*/
void mv_mult2s_bool(int n, int *m, int *v, int *o) {
  int r = 0;
  int t = 0;
  /*@
    loop invariant 0 <= c <= n;
    loop invariant t == ((c==0) ? 0 : ((m[n*r+0] && v[0]) || ((c==1)? 0 : (m[n*r+1] && v[1]))));
    loop assigns c, t;
    loop variant n-c;
  */
  for (int c = 0; c < n; c++) {
    t = t || (m[n*r+c] && v[c]);
  }
  o[r] = t;
  o[1] = 0;
}
