//@ predicate is_pos(int x) = x > 0;
//@ predicate is_nat(int x) = x >= 0;

/*@ requires is_pos(x);
    ensures is_nat(\result);
*/
int minus1(int x) {
  return x-1;
}
