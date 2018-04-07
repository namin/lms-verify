#include <stdio.h>

int main(int argc, char** argv) {
  char* s = "3 SKI5 hello";
  char* a;
  int n;
  while (1) {
    printf("---\n");
    int r = parseCode(s, &a, &n);
    if (r>=0) {
      for (int i=0; i<n; i++) {
        putchar(a[i]);
      }
      s = s+r;
    } else {
      break;
    }
    putchar('\n');
  }
}
