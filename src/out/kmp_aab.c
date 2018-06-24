#include <string.h>

/*@
predicate match_aab(char* s) =
 strlen(s) >= 3 && s[0]=='a' && s[1]=='a' && s[2]=='b';

predicate match_anyaab(char* s) =
 \exists int i; 0 <= i < strlen(s) && match_aab(s+i);
*/

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));
assigns \nothing;
ensures \result==0 || \result==1;
ensures match_anyaab(s) <==> \result==1;
ensures !match_anyaab(s) <==> \result==0;
*/
int match(char *s) {
  int j = 0;
  int k = 0;
  /*@
    loop invariant (0 <= k <= strlen(s));
    loop invariant (0 <= j <= 3);
    loop invariant strlen(s)>=0 && \valid(s+(0..strlen(s)));
    loop invariant (\forall int i; 0 <= i < k-j ==> !match_aab(s+i));
    loop invariant (j==1 ==> k>=1 && s[k-1]=='a');
    loop invariant (j==2 ==> k>=2 && s[k-2]=='a' && s[k-1]=='a');
    loop invariant (j==3 ==> k>=3 && s[k-3]=='a' && s[k-2]=='a' && s[k-1]=='b');
    loop assigns j, k;
    loop variant strlen(s)*2 - k+j; // TODO
  */
  while (s[k] != '\0' && j < 3) {
    if (j == 0) {
      if (s[k] == 'a') {
        j += 1;
        k += 1;
      } else {
        j = 0;
        k += 1;
      }
    } else if (j == 1) {
      if (s[k] == 'a') {
        j += 1;
        k += 1;
      } else {
        j = 0;
      }
    } else if (j == 2) {
      if (s[k] == 'b') {
        j += 1;
        k += 1;
      } else {
        j = 1;
      }
    } else {
      return -1;
    }
  }
  return j==3;
}

