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


/*@
requires strlen(s)>0 && \valid(s+(0..strlen(s)));
assigns \nothing;
ensures \result==0 || \result==1;
ensures \result==1 ==> match_anyaab(s);
*/
int m_opt_anyaab(char* s) {
  int id = 0;
  /*@
    loop invariant (0 <= i <= strlen(s));
    loop invariant strlen(s)>=0 && \valid(s+(0..strlen(s)));
    loop invariant id==0 || id==1 || id==2;
    loop invariant (id==1 ==> i>=1 && s[i-1]=='A');
    loop invariant (id==2 ==> i>=2 && s[i-2]=='A' && s[i-1]=='A');
    loop assigns i, id;
    loop variant strlen(s)-i;
   */
  for (int i=0; s[i]!='\0'; i++) {
    if (id == 0) {
      if (s[i] == 'A') {
        id = 1;
      } else {
        id = 0;
      }
    }
    else if (id == 1) {
      if (s[i] == 'A') {
        id = 2;
      } else {
        id = 0;
      }
    } else if (id == 2) {
      if (s[i] == 'B') {
        return 1;
      } else if (s[i] == 'A') {
        id = 2;
      } else {
        id = 0;
      }
    } else {
      return -1;
    }
  }
  return 0;
}
