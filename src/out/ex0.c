#include <limits.h>
/*@ requires x < INT_MAX;
	ensures \result > x;
*/
int inc (int x) { return x+1; }

