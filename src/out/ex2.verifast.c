#include "verifast.h"

int pick_index(int n)
//@ requires 0 < n;
//@ ensures 0 <= result &*& result < n;
{
  return 0;
}

int pick_element(int* p, int n)
//@ requires n > 0 &*& integers(p, n);
//@ ensures integers(p, n);
{
  int i = pick_index(n);
  //@ assert (0 <= i &*& i < n);
  //@ split_integers_chunk(p, i);
  //@ open integers(p + i, n - i);
  int r = p[i];
  //@ close integers(p + i, n - i);
  //@ merge_integers_chunk(p);
  return r;
}

int pick_first(int* p)
// @requires \integer(p, _);
// @ensures result == p[0];
{
  return p[0];
}
