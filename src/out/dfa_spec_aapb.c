#include<string.h>

/*@
predicate star_A(char* s, integer i, integer n) = 
  n==0 || (n>0 && (s[i+n-1]=='A' && star_A(s, i, n-1)));
predicate match_aapb(char* s) =
 strlen(s)>=2 && s[0]=='A' && star_A(s,1,strlen(s)-2) && s[strlen(s)-1]=='B';
*/

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires 0 <= i;
requires strlen(s)-i>=stop;
requires 0 <= n <= stop;
requires !star_A(s, i, n);
ensures !star_A(s, i, stop);

assigns \nothing;
 */
int lemma_not_star_A(char* s, int i, int n, int stop) {
  int j = n;
  /*@
    loop invariant 0 <= j <= stop;
    loop invariant !star_A(s, i, j);
    loop assigns j;
    loop variant stop-j;
  */
  while (j!=stop) {
    j++;
  }
  return 0;
}

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
  int n = 0;
  if (s[n]!='A') {
    //@assert !match_aapb(s);
    return 0;
  }
  //@assert s[n]=='A';
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
    //@ghost lemma_not_star_A(s, 1, n+1, strlen(s)-2);
    //@assert !star_A(s, 1, strlen(s)-2);
    //@assert !match_aapb(s);
    return 0;
  }
  //@assert star_A(s, 1, strlen(s)-2);
  n++;
  if (s[n]!='B') {
    //@assert !match_aapb(s);
    return 0;
  }
  //@assert s[n]=='B';
  n++;
  //@assert s[n]=='\0';
  //@assert match_aapb(s);
  return s[n]=='\0';
}
