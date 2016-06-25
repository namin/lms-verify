// needs higher timeout, flag: -wp-timeout 50

/*@
predicate inv_vec(int *a1, int n) = n>0 && \valid(a1+(0..n-1));
predicate inv_vec_vec(int **a2, int *a1, int n) = n>0 &&
  \valid(a1+(0..n-1)) && \valid(a2+(0..n-1)) &&
  (\forall int i; 0<=i<n ==> inv_vec(a2[i],a1[i]));
predicate inv_vec_vec_vec(int ***a3, int **a2, int *a1, int n) = n>0 &&
  \valid(a1+(0..n-1)) && \valid(a2+(0..n-1)) && \valid(a3+(0..n-1)) &&
  (\forall int i; 0<=i<n ==> inv_vec_vec(a3[i],a2[i],a1[i]));
*/

/*@
requires \valid(x3);
requires \valid(x2);
requires \valid(x1);
requires \valid(y3);
requires \valid(y2);
requires \valid(y1);

requires inv_vec_vec(*x3, *x2, *x1);
requires inv_vec_vec(*y3, *y2, *y1);

requires \forall int i3; \forall int i2; \forall int j3; \forall int j2;
 (0<=i3<*x1 && 0<=i2<*x1 && 0<=j3<*y1 && 0<=j2<*y1) ==>
 \separated(x3, x2, x1, y3, y2, y1, (*x3)+i3, (*x2)+i2, (*y3)+j3, (*y2)+j2);

ensures \forall int i3; \forall int i2; \forall int j3; \forall int j2;
 (0<=i3<*x1 && 0<=i2<*x1 && 0<=j3<*y1 && 0<=j2<*y1) ==>
 \separated(x3, x2, x1, y3, y2, y1, (*x3)+i3, (*x2)+i2, (*y3)+j3, (*y2)+j2);

ensures *y3 == \old(*x3);
ensures *y2 == \old(*x2);
ensures *y1 == \old(*x1);
ensures *x3 == \old(*y3);
ensures *x2 == \old(*y2);
ensures *x1 == \old(*y1);
ensures inv_vec_vec(*x3, *x2, *x1);
ensures inv_vec_vec(*y3, *y2, *y1);

assigns *x3, *x2, *x1, *y3, *y2, *y1;
*/
void swap(int ***x3, int **x2, int *x1, int ***y3, int **y2, int *y1)
{
  int **t3 = *x3;
  int  *t2 = *x2;
  int   t1 = *x1;

  *x3 = *y3;
  *x2 = *y2;
  *x1 = *y1;

  *y3 = t3;
  *y2 = t2;
  *y1 = t1;
}

/*TODO:
- ensures inv_vec_vec_vec(a3, a2, a1, n);

incorporate into LMS-Verify:
- use range notation with separated instead of forall;
  yet still need forall for dependent ranges
- avoid quantifiers over inequalities
- decide on shallow vs deep equality
*/
/*@
requires 0<n;
requires 0<=i<n && 0<=j<n && i!=j;

requires inv_vec_vec_vec(a3, a2, a1, n);

requires
 \forall int i1; (0<=i1<n) ==> \forall int j1; (0<=j1<n) ==> (i1!=j1) ==>
 \forall int i2; (0<=i2<a1[i1]) ==> \forall int j2; (0<=j2<a1[j1]) ==>
 \separated(a3+(0..n-1), a2+(0..n-1), a1+(0..n-1),(a3[i1])+(0..a1[i1]-1),(a2[i1])+(0..a1[i1]-1),(a3[j1])+(0..a1[j1]-1),(a2[j1])+(0..a1[j1]-1),
 (a3[i1][i2])+(0..a2[i1][i2]),(a3[j1][j2])+(0..a2[j1][j2]));

requires \separated(a3+(0..n-1),a2+(0..n-1),a1+(0..n-1));

ensures \forall int i3; \forall int i2; \forall int j3; \forall int j2;
 (0<=i3<a1[i] && 0<=i2<a1[i] && 0<=j3<a1[j] && 0<=j2<a1[j]) ==>
 \separated(a3+i, a2+i, a1+i, a3+j, a2+j, a1+j, (a3[i])+i3, (a2[i])+i2, (a3[j])+j3, (a2[j])+j2);

ensures \separated(a3+(0..n-1),a2+(0..n-1),a1+(0..n-1));

ensures a3[j] == \old(a3[i]);
ensures a2[j] == \old(a2[i]);
ensures a1[j] == \old(a1[i]);
ensures a3[i] == \old(a3[j]);
ensures a2[i] == \old(a2[j]);
ensures a1[i] == \old(a1[j]);

ensures \forall int k; (0<=k<n && k!=i && k!=j) ==> a3[k] == \old(a3[k]);
ensures \forall int k; (0<=k<n && k!=i && k!=j) ==> a2[k] == \old(a2[k]);
ensures \forall int k; (0<=k<n && k!=i && k!=j) ==> a1[k] == \old(a1[k]);

ensures inv_vec_vec(a3[i], a2[i], a1[i]);
ensures inv_vec_vec(a3[j], a2[j], a1[j]);

assigns a3[0..n-1], a2[0..n-1], a1[0..n-1];
*/
void inswap(int ***a3, int **a2, int *a1, int n, int i, int j)
{
  /*@assert \forall int i3; \forall int i2; \forall int j3; \forall int j2;
  (0<=i3<a1[i] && 0<=i2<a1[i] && 0<=j3<a1[j] && 0<=j2<a1[j]) ==>
  \separated(a3+i, a2+i, a1+i, a3+j, a2+j, a1+j, (a3[i])+i3, (a2[i])+i2, (a3[j])+j3, (a2[j])+j2);*/

  int **t3 = a3[i];
  int  *t2 = a2[i];
  int   t1 = a1[i];

  a3[i] = a3[j];
  a2[i] = a2[j];
  a1[i] = a1[j];

  a3[j] = t3;
  a2[j] = t2;
  a1[j] = t1;
}
