/*@ requires a>=0;
    ensures \result==a+b;
*/
int plus(int a, int b) {
  return (a==0) ? b : plus(a-1, b+1);
}
