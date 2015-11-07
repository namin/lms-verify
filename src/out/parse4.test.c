#include <stdio.h>
int main(void) {

  printf("-1 == %d\n", p("1\n\n"));
  printf("0 == %d\n", p("0\n\n"));
  printf("1 == %d\n", p("1\na\n"));
  printf("3 == %d\n", p("1\na\n2\nbc\n"));

  return 0;
}
