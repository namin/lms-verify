#include<string.h>

/*@
predicate star_A(char* s, integer i, integer j) = 
  i==j || (j>i && (s[i]=='A' && star_A(s, i+1, j)));
predicate match_aapb(char* s, integer i, integer j) =
 s[i]=='A' && \exists integer m; i<m<=j && star_A(s,i,m) && s[m+1]=='B' && s[m+2]=='\0' && m+2==j;
predicate bwd0(char* s, integer i, integer j) = i>=j;
predicate bwd1(char* s, integer i, integer j) =  s[i]=='A' && \exists integer m; i<m<=j && star_A(s,i,m) && m>=j;
predicate bwd2(char* s, integer i, integer j) =
 s[i]=='A' && \exists integer m; i<m<=j && star_A(s,i,m) && s[m+1]=='B' && m+2>=j;
*/

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

requires 0<=i<=strlen(s);
requires 0<=j<=strlen(s);

requires bwd0(s, 0, j);
requires s[j]=='A';
ensures bwd1(s, 0, j+1);

assigns \nothing;
*/
void lemma01(char* s, int i, int j) {
}

/*@
requires strlen(s)>=0 && \valid(s+(0..strlen(s)));

requires strlen(s)<=INT_MAX;

requires 0<=i<=strlen(s);
requires 0<=j<=strlen(s);

requires bwd1(s, 0, j);
requires s[j]=='A';
ensures bwd1(s, 0, j+1);

assigns \nothing;
*/
void lemma11(char* s, int i, int j) {
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
