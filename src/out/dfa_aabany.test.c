#include <stdio.h>

int main(void) {
  printf("1 == %d\n", dfa_aabany("AAB"));
  printf("1 == %d\n", dfa_aabany("XYZAAB"));
  printf("1 == %d\n", dfa_aabany("XYZABAAB"));
  printf("1 == %d\n", dfa_aabany("XYZABAABX"));
  printf("0 == %d\n", dfa_aabany("XYZABX"));
  printf("0 == %d\n", dfa_aabany(""));
}

