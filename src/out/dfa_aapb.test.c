#include <stdio.h>

int main(void) {
  printf("1 == %d\n", dfa("AAB"));
  printf("1 == %d\n", dfa("AAAB"));
  printf("1 == %d\n", dfa("AAAAB"));
  printf("0 == %d\n", dfa("AXAAAB"));
  printf("0 == %d\n", dfa("XYZAAB"));
  printf("0 == %d\n", dfa("XYZABAAB"));
  printf("0 == %d\n", dfa("XYZABAABX"));
  printf("0 == %d\n", dfa(""));
}

