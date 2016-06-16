#include <stdio.h>

int main(void) {
  printf("1 == %d\n", matcher("acacabcccccccaba"));
  printf("0 == %d\n", matcher("acacabcccccccbca"));

  int N = 1000000;
  char t[N+1];
  for (int i = 0; i < N; i++) {
    t[i] = 'c';
  }
  t[N] = '\0';
  char b[] = "acacab";
  char e[] = "aba";
  char *p = b;
  int i = 0;
  while (*p != '\0') {
    t[i++] = *p++;
  }
  i = 0;
  p = e;
  int n = strlen(p);
  while (*p != '\0') {
    t[N-n+i++] = *p++;
  }
  //printf("%s\n", t);
  printf("1 == %d\n", matcher(t));

  return 0;
}
