/*@ requires \valid(p+ (0..1));
    ensures p[0] == \old(p[1]);
    ensures p[1] == \old(p[0]);
    assigns p[0], p[1];
*/
void array_swap(int* p) {
  int tmp = p[0];
  p[0] = p[1];
  p[1] = tmp;
}
