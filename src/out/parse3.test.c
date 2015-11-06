#include <stdio.h>
int main(void) {

  printf("-1 == %d\n", p(""));
  printf("-1 == %d\n", p("HTTP/2.0 200 OK\nContnt-Lngth:3\nfoo:bar\n\nabc\n"));
  printf("-1 == %d\n", p("HTTP/2.0 200 OK\nfoo:bar\n\nabc\n"));
  printf("3 == %d\n", p("HTTP/2.0 200 OK\nContent-Length:3\nfoo:bar\n\nabc\n"));
  printf("3 == %d\n", p("HTTP/2.0 200 OK\nContent-Length:3\nfoo:bar\n\na\nc\n"));
  printf("0 == %d\n", p("HTTP/2.0 200 OK\nfoo:bar\n\n\n"));

  return 0;
}
