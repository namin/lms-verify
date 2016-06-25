#include <stdio.h>

int main(void) {
  printf("1 == %d\n", matcher("aaaabbbbbbbccccccddddddddddeeeeeefffffgggg"));
  printf("0 == %d\n", matcher("aaaaaaabbbbbcccddeeaffffggggggg"));

  int N = 1000000;
  int ND = N/20;
  int nd = 'g'-'a';
  char t[N+1];
  int d = 0;
  for (int i = 0; i < N; i++) {
    t[i] = 'a'+d;
    if (d<nd && (i%ND)==0) d++;
  }
  t[N] = '\0';

  printf("1 == %d\n", matcher(t));

  return 0;
}
