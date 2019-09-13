#include<limits.h>
#include<string.h>

/*@
predicate star_A(char* s, integer i, integer j) = 
  i==j || (j>i && (s[i]=='A' && star_A(s, i+1, j)));
predicate match_aapb(char* s, integer i, integer j) =
 s[i]=='A' && \exists integer m; i<m<=j && star_A(s,i+1,m) && s[m+1]=='B' && s[m+2]=='\0' && m+2==j;
predicate bwd0(char* s, integer i, integer j) = i>=j;
predicate bwd1(char* s, integer i, integer j) =  s[i]=='A' && \exists integer m; i<m<=j && star_A(s,i+1,m) && m>=j;
predicate bwd2(char* s, integer i, integer j) =
 s[i]=='A' && \exists integer m; i<m<=j && star_A(s,i,m) && s[m+1]=='B' && m+2>=j;
*/

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

requires 0<=i<=j<=strlen(s);

requires star_A(s, i, j);
ensures \forall integer m; 0<=i<=m<j ==> s[m]=='A';

assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  /*@
    loop invariant 0 <= i <= x <= j <= strlen(s);
    loop invariant star_A(s, x, j);
    loop invariant \forall integer m; i<=m<x ==> s[m]=='A';
    loop assigns x;
    loop variant j-x;
  */
  while (x < j) {
    x++;
  }
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

requires 0<=i<=j<=strlen(s);

requires \forall integer m; 0<=i<=m<j ==> s[m]=='A';
ensures star_A(s, i, j);

assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  /*@
    loop invariant 0 <= i <= x <= j <= strlen(s);
    loop invariant star_A(s, x, j);
    loop invariant \forall integer m; 0<=i<=m<j ==> s[m]=='A';
    loop assigns x;
    loop variant x;
  */
  while (i < x) {
    x--;
  }
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

requires 0<=i<=strlen(s);
requires 0<=j<=strlen(s);
requires i<j;

requires star_A(s, i, j);
ensures star_A(s, i, j-1);

assigns \nothing;
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

requires 0<=i<=j<=n<=strlen(s);

requires star_A(s, i, j);
requires star_A(s, j, n);
ensures star_A(s, i, n);

assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  /*@
    loop invariant 0 <= i <= x <= j <= n <= strlen(s);
    loop invariant star_A(s, x, n);
    loop invariant star_A(s, i, x);
    loop assigns x;
    loop variant x;
  */
  while (i < x) {
    //@ghost lemma_star_A_dec(s, i, x);
    //@assert i<x;
    //@ghost lemma_star_A_all(s, i, x);
    //@assert s[x-1]=='A';
    //@assert star_A(s, x, n);
    //@assert star_A(s, x-1, n);
    x--;
  }
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

requires 0<=i<=strlen(s);
requires 0<=j<=strlen(s);
requires i<=j;

requires bwd0(s, 0, j);
requires s[j]=='A';
ensures bwd1(s, 0, j+1);

assigns \nothing;
*/
void lemma01(char* s, int i, int j) {
  //@assert j==0;
  //@assert star_A(s, j+1, j+1);
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

requires 0<=i<=strlen(s);
requires 0<=j<=strlen(s);
requires i<=j;

requires bwd1(s, 0, j);
requires s[j]=='A';
ensures bwd1(s, 0, j+1);

assigns \nothing;
*/
void lemma11(char* s, int i, int j) {
  //@assert s[0]=='A';
  //@assert star_A(s, 1, j);
  //@assert s[j]=='A';
  //@assert star_A(s, j+1, j+1);
  //@ghost lemma_star_A(s, 1, j, j+1);
  //@assert star_A(s, 1, j+1);
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

requires 0<=i<=strlen(s);
requires 0<=j<=strlen(s);

requires bwd1(s, i, j);
requires s[j]=='B';
ensures bwd2(s, i, j+1);

assigns \nothing;
*/
void lemma12(char* s, int i, int j) {
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

requires 0<=i<=strlen(s);
requires 0<=j<=strlen(s);

requires bwd2(s, i, j);
ensures s[j]=='\0' ==> match_aapb(s, i, j+1);

assigns \nothing;
*/
void lemma2f(char* s, int i, int j) {
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

ensures match_aapb(s, 0, strlen(s)) ==> \result==1;
ensures \result==1 ==> match_aapb(s, 0, strlen(s));

assigns \nothing;
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;
  int m = 1;
  //@ghost int i = 0;
  /*@
    loop invariant strlen(s)>=0 && \valid(s+(0..strlen(s)));
    loop invariant strlen(cur)>=0 && \valid(cur+(0..strlen(cur)));
    loop invariant 0<=i<=strlen(s);
    loop invariant (id == 0) && (m == 1) ==> bwd0(s, 0, i);
    loop invariant (id == 1) && (m == 1) ==> bwd1(s, 0, i);
    loop invariant (id == 2) && (m == 1) ==> bwd2(s, 0, i);
    loop invariant (id == 0) || (id == 1) || (id == 2);
    loop invariant (m == 1) || (m == 0);
    loop invariant cur==s+i;
    loop invariant cur[0]==s[i];
    loop assigns cur, id, i, m;
    loop variant strlen(cur) + m;
   */
  while (cur[0] != '\0' && m) {
    m = 0;
    if (id == 0) {
      //@assert (id == 0) ==> bwd0(s, 0, i);
      //@assert bwd0(s, 0, i);
      //@assert i==0;
      if (cur[0] == 'A') {
        id = 1;
        //@ghost lemma01(s, 0, i);
        //@assert bwd1(s, 0, i+1);
        m = 1;
      }
    } else if (id == 1) {
      //@assert (id == 1) ==> bwd1(s, 0, i);
      //@assert bwd1(s, 0, i);
      if (cur[0] == 'A') {
        //@ghost lemma11(s, 0, i);
        id = 1;
        //@assert bwd1(s, 0, i+1);
        m = 1;
      } else if (cur[0] == 'B') {
        //@ghost lemma12(s, 0, i);
        id = 2;
        //@assert bwd2(s, 0, i+1);
        m = 1;
      }
    } else if (id == 2) {
      //@assert (id == 2) ==> bwd2(s, 0, i);
      //@assert bwd2(s, 0, i);
      //@ghost lemma2f(s, 0, i);
    }
    if (m==1) {
      cur++;
      //@ghost i++;
    }
  }
  return id==2 && cur[0]=='\0';
}
