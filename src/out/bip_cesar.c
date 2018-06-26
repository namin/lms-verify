#include <string.h>

int delta = 3;

char cypher(char s) {
  return 'a' + ((s - 'a' + delta) % 26);
}

char decypher(char s) {
  return 'a' + ((s - 'a' - delta) % 26);
}

void encode(char* s1, char* s2) {
  while (*s1 != '\0') {
    *s2++ = cypher(*s1++);
  }
  //@assert *s2 == '\0';
}

void decode(char* s1, char* s2) {
  while (*s1 != '\0') {
    *s2++ = decypher(*s1++);
  }
  //@assert *s2 == '\0';
}

#include <stdio.h>
int main(void) {
  char a[] = {'h','e','l','l','o','\0'};
  char *s = a;
  char b[] = {'h','e','l','l','o','\0'};
  char *t = b;
  printf("%s ", s);
  encode(s, t);
  printf("to %s ", t);
  decode(t, s);
  printf("back to %s!\n", s);
}
