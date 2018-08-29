#include "verifast.h"
// use flag -disable_overflow_check

int v_mult(int* va, int na, int* vb, int nb)
  //@ requires 0 < na &*& 0 < nb &*& na == nb &*& integers(va, na) &*& integers(vb, nb);
  //@ ensures integers(va, na) &*& integers(vb, nb);
{
  int r = 0;
  for (int i = 0; i<na; i++)
    //@ invariant 0 <= i &*& i<=na &*& integers(va, na) &*& integers(vb, nb);
  {
    //@ assert 0 <= i &*& i<na;
    //@ split_integers_chunk(va, i);
    //@ open integers(va + i, na - i);
    //@ split_integers_chunk(vb, i);
    //@ open integers(vb + i, nb - i);
    r += va[i]*vb[i];
    //@ close integers(va + i, na - i);
    //@ merge_integers_chunk(va);
    //@ close integers(vb + i, nb - i);
    //@ merge_integers_chunk(vb);
  }
  return r;
}
