#include <stdio.h>

int main(void) {
  printf("1 == %d\n", match("aaba"));
  printf("1 == %d\n", match("aacaaba"));
  printf("1 == %d\n", match("ababaabc"));
  printf("1 == %d\n", match("ababaaabc"));
  printf("0 == %d\n", match("aacab"));
  printf("0 == %d\n", match("aaacab"));
  printf("0 == %d\n", match(""));
}
