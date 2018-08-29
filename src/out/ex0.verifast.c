#include <limits.h>
int inc(int x)
/*@ requires x < INT_MAX;
@*/
/*@ ensures result > x;
@*/
{
  return x+1;
}

