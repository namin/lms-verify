#include <stdio.h>

int main(void) {
  printf("1 == %d\n", matcher_begin_a("a"));
  printf("1 == %d\n", matcher_begin_a("a_"));
  printf("0 == %d\n", matcher_begin_a(""));
  printf("0 == %d\n", matcher_begin_a("b"));
  printf("1 == %d\n", matcher_a_end("ba"));
  printf("1 == %d\n", matcher_a_end("_a"));
  printf("0 == %d\n", matcher_a_end(""));
  printf("0 == %d\n", matcher_a_end("ba"));
  printf("1 == %d\n", matcher_a("bab"));
  printf("1 == %d\n", matcher_a("_aca"));
  printf("0 == %d\n", matcher_a(""));
  printf("0 == %d\n", matcher_a("bb"));
  printf("1 == %d\n", matcher_ab_dot_star_ab("abab"));
  printf("1 == %d\n", matcher_ab_dot_star_ab("abccab"));
  printf("1 == %d\n", matcher_ab_dot_star_ab("abcabcab"));
  printf("1 == %d\n", matcher_ab_dot_star_ab("abcabcabaaa"));
  printf("0 == %d\n", matcher_ab_dot_star_ab(""));
  printf("0 == %d\n", matcher_ab_dot_star_ab("ab"));
}
