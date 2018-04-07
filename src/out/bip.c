#include <string.h>

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));
requires \valid(d);
assigns *d;
ensures \result==-1 || \result==1;
ensures \result<=strlen(s);
ensures (\result==1) ==> (0<=*d<=9);
*/
int parseDigit(char *s, int *d) {
  int c = *s;
  if ('0' <= c && c <= '9') {
    *d = c - '0';
    return 1;
  }
  return -1;
}

#define N 5

/*@
logic integer pow(integer b, integer n) = (n==0) ? 1 : pow(b, n-1)*b;
*/

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));
requires \valid(d);
assigns *d;
ensures -1<=\result<=strlen(s);
ensures (\result>=0) ==> \result<N;
ensures (\result>=0) ==> (0<=*d<pow(10,\result));
*/
int parseInt(char* s, int *d) {
  int i = 0;
  *d = 0;
  /*@
    loop invariant 0<=i<N;
    loop invariant -1<=i<=strlen(s);
    loop invariant 0<=*d<pow(10,i);
    loop assigns i, *d;
    loop variant strlen(s)-i;
  */
  while (1) {
    int d1 = 0;
    int r = parseDigit(s+i, &d1);
    if (i+r >= N) {
      //@assert r==1;
      return -1;
    } else if (r>=0) {
      //@assert r==1;
      *d = *d * 10 + d1;
      i += r;
    } else {
      //@assert r==-1;
      break;
    }
  }
  return i;
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));
requires \valid(a);
requires \valid(n);
requires \separated(s, a, n);
assigns *a, *n;
ensures -1<=\result<=strlen(s);
ensures (\result>=0) ==> \exists int i; 0<=i<=strlen(s) && *a==s+i && 0<=i+*n<=strlen(s);
*/
int parseCode(char* s, char** a, int *n) {
  int r = parseInt(s, n);
  if (r<0) return r;
  if (s[r]!=' ') return -1;
  //@assert \valid(s+r+1);
  *a = s+r+1;
  //@assert 0<=r+1<=strlen(s) && *a==s+r+1;
  if (strlen(*a) < *n) return -1;
  //@assert 0<=r+1<=strlen(s) && *a==s+r+1 && 0<=r+1+*n<=strlen(s);
  return r+1+*n;
}
