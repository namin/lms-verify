#include <stdio.h>
int main(void) {

  // parse3.test.c should also still work
  printf("3 == %d\n", p("HTTP/2.0 200 OK\nTransfer-Encoding: chunked\n\n2\nab\n1\nc\n0\n\n"));
  printf("-1 == %d\n", p("HTTP/2.0 200 OK\nTransfer-Encoding: chunked\n\n2\nab\n9999999999999999999999999999999999999999999999999999999999999999999999999999999999999\nc\n0\n\n"));

  return 0;
}
