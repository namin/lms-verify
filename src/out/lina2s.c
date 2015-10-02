#include <stdio.h>

struct vector {
  int n;
  int* v;
};

/*@ ensures \result==0 || \result==1;
    assigns \nothing;
 */
int predicate(int v) {
  return v % 2 == 0;
}

/*@ requires \valid(a);
    requires \valid(o);
    requires \valid(a->v+(0..a->n-1));
    requires \valid(o->v+(0..a->n-1));
    requires \forall int i; \forall int j; 0 <= i < a->n && 0 <= j < a->n ==> \separated(a, o, a->v+i, o->v+j);
    requires a->n > 0;
    ensures 0 <= o->n <= a->n;
    ensures \forall int i; 0 <= i < o->n ==> 0 <= o->v[i] < a->n;
    ensures \forall int i; 0 < i < o->n ==> o->v[i-1] < o->v[i];
    assigns o->n, o->v[0..a->n-1];
 */
void index_where(struct vector* a, struct vector* o) {
  int n = a->n;
  o->n = 0;
  /*@
    loop invariant n == a->n;
    loop invariant 0 <= i <= n;
    loop invariant 0 <= o->n <= i;
    loop invariant \forall int j; 0 <= j < o->n ==> 0 <= o->v[j] < i;
    loop invariant \forall int j; 0 < j < o->n ==> o->v[j-1] < o->v[j];
    loop assigns i, o->n, o->v[0..n-1];
    loop variant n-i;
   */
  for (int i = 0; i < n; i++) {
    if (predicate(a->v[i])) {
      o->v[o->n++] = i;
    }
  }
}

int main(void) {
  int av[3] = {1, 2, 3};
  int ov[3] = {0, 0, 0};
  struct vector a = {3, av};
  struct vector o = {3, ov};
  index_where(&a, &o);
  struct vector *pa = &a;
  printf("sizeof: %d %d %d %d %d\n", sizeof(int), sizeof(pa), sizeof(*(pa->v)), sizeof(*av), sizeof(av));
  printf("%d: %d %d %d\n", o.n, o.v[0], o.v[1], o.v[2]);
  return 0;
}
