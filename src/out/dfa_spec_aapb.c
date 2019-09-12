#include<string.h>

/*@
predicate star_A(char* s, integer i, integer n) = 
  n==0 || (n>0 && (s[i+n-1]=='A' && star_A(s, i, n-1)));
predicate match_aapb(char* s) =
 strlen(s)>=2 && s[0]=='A' && star_A(s,1,strlen(s)-2) && s[strlen(s)-1]=='B';
*/

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

ensures match_aapb(s) ==> \result==1;
ensures \result==1 ==> match_aapb(s);

assigns \nothing;
*/
int m_aapb(char* s) {
  if (strlen(s)<2)  {
    //@assert !match_aapb(s);
    return 0;
  }
  //@assert strlen(s)>=2;
  if (s[0]!='A') {
    //@assert !match_aapb(s);
    return 0;
  }
  //@assert s[0]=='A';
  int n = 0;
  /*@
    loop invariant 0 <= n <= strlen(s)-2;
    loop invariant star_A(s, 1, n);
    loop assigns n;
    loop variant strlen(s)-2-n;
  */
  while (n!=strlen(s)-2 && s[1+n]=='A') {
    n++;
  }
  if (n!=strlen(s)-2) {
    //@assert n < strlen(s)-2;
    //@assert s[1+n]!='A';
    //@assert star_A(s, 1, n);
    //@assert !star_A(s, 1, n+1);
    //@assert !star_A(s, 1, strlen(s)-2); // need to show this
    //@assert !match_aapb(s);
    return 0;
  }
  //@assert star_A(s, 1, strlen(s)-2);
  if (s[strlen(s)-1]!='B') {
    //@assert !match_aapb(s);
    return 0;
  }
  //@assert s[strlen(s)-1]=='B';
  //@assert s[strlen(s)]=='\0';
  //@assert match_aapb(s);
  return s[strlen(s)]=='\0';
}
