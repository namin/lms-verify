#include<string.h>

/*@
predicate match_aab(char* s) =
 strlen(s) >= 3 && s[0]=='A' && s[1]=='A' && s[2]=='B';

predicate match_anyaab(char* s) =
 \exists int i; 0 <= i < strlen(s) && match_aab(s+i);
*/

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

ensures match_aab(s) <==> \result==1;
ensures !match_aab(s) <==> \result==0;

assigns \nothing;
*/
int m_aab(char* s) {
  return s[0]=='A' && s[1]=='A' && s[2]=='B';
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

ensures match_anyaab(s) <==> \result==1;
ensures !match_anyaab(s) <==> \result==0;

assigns \nothing;
*/
int m_anyaab(char* s) {
  /*@
    loop invariant (0 <= i <= strlen(s));
    loop invariant (\forall int j; 0 <= j < i ==> !match_aab(s+j));
    loop assigns i;
    loop variant strlen(s)-i;
  */
  for (int i=0; s[i]!='\0'; i++) {
    if (m_aab(s+i)) return 1;
    //@assert !match_aab(s+i);
  }
  return 0;
}
