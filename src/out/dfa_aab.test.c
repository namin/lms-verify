#include <stdio.h>

int main(void) {
  printf("1 == %d\n", dfa_aab("AAB"));
  printf("1 == %d\n", dfa_aab("XYZAAB"));
  printf("1 == %d\n", dfa_aab("XYZABAAB"));
  printf("0 == %d\n", dfa_aab("XYZABAABX"));
  printf("0 == %d\n", dfa_aab(""));
}

