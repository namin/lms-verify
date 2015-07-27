/*@ requires n > 0;
    ensures 0 <= \result && \result < n;
*/
int pick_index(int n) { return 0; }

/*@ requires n > 0 && \valid(p+ (0..n-1));
*/
int pick_element(int* p, int n) {
  int i = pick_index(n);
  //@ assert (0 <= i && i < n);
  return p[i];
}

/*@requires \valid(p);
  ensures \result == p[0];*/
int pick_first(int* p) {
  return p[0];
}
