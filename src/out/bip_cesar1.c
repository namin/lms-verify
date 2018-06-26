#include <string.h>

/*@
logic integer cypher(integer s) = s==26 ? 0 : s+1;
logic integer decypher(integer s) = s==0 ? 26 : s-1;
 */
/*@
  requires 0 <= s <= 26;
  ensures 0 <= \result <= 26;
  ensures \result == cypher(s);
  assigns \nothing;
 */
int cypher(int s) {
  return s==26 ? 0 : s+1;
}

/*@
  requires 0 <= s <= 26;
  ensures 0 <= \result <= 26;
  ensures \result == decypher(s);
  assigns \nothing;
 */
int decypher(int s) {
  return s==0 ? 26 : s-1;
}

/*@
requires n > 0;
requires \valid(s1+(0..n-1));
requires \valid(s2+(0..n-1));
requires \valid(s3+(0..n-1));
requires \forall int i1,i2,i3; 0 <= i1 < n && 0 <= i2 < n && 0 <= i3 < n ==> \separated(s1+i1,s2+i2,s3+i3);
requires \forall int i; 0 <= i < n ==> 0 <= s1[i] <= 26;
ensures \forall int i; 0 <= i < n ==> s2[i]==cypher(s1[i]);
ensures \forall int i; 0 <= i < n ==> 0 <= s2[i] <= 26;
ensures \forall int i; 0 <= i < n ==> \old(s1[i])==s1[i];
ensures \forall int i; 0 <= i < n ==> \old(s3[i])==s3[i];
assigns s2[0..n-1];
*/
void encode(int* s1, int* s2, int* s3, int n) {
  /*@
    loop invariant 0 <= i <= n;
    loop invariant \forall int j; 0 <= j < n ==> 0 <= s1[j] <= 26;
    loop invariant \forall int i; 0 <= i < n ==> \at(s1[i],Pre)==s1[i];
    loop invariant \forall int i; 0 <= i < n ==> \at(s3[i],Pre)==s3[i];
    loop invariant \forall int j; 0 <= j < i ==> s2[j]==cypher(s1[j]);
    loop assigns i, s2[0..n-1];
    loop variant n - i;
  */
  for (int i=0; i<n; i++) {
    s2[i] = cypher(s1[i]);
  }
}

/*@
requires n > 0;
requires \valid(s1+(0..n-1));
requires \valid(s2+(0..n-1));
requires \valid(s3+(0..n-1));
requires \forall int i1,i2,i3; 0 <= i1 < n && 0 <= i2 < n && 0 <= i3 < n ==> \separated(s1+i1,s2+i2,s3+i3);
requires \forall int i; 0 <= i < n ==> 0 <= s1[i] <= 26;
ensures \forall int i; 0 <= i < n ==> s2[i]==decypher(s1[i]);
ensures \forall int i; 0 <= i < n ==> 0 <= s2[i] <= 26;
ensures \forall int i; 0 <= i < n ==> \old(s1[i])==s1[i];
ensures \forall int i; 0 <= i < n ==> \old(s3[i])==s3[i];
assigns s2[0..n-1];
*/
void decode(int* s1, int* s2, int* s3, int n) {
  /*@
    loop invariant 0 <= i <= n;
    loop invariant \forall int j; 0 <= j < n ==> 0 <= s1[j] <= 26;
    loop invariant \forall int i; 0 <= i < n ==> \at(s1[i],Pre)==s1[i];
    loop invariant \forall int i; 0 <= i < n ==> \at(s3[i],Pre)==s3[i];
    loop invariant \forall int j; 0 <= j < i ==> s2[j]==decypher(s1[j]);
    loop assigns i, s2[0..n-1];
    loop variant n - i;
  */
  for (int i=0; i<n; i++) {
    s2[i] = decypher(s1[i]);
  }
}

/*@
requires n > 0;
requires \valid(s1+(0..n-1));
requires \valid(s2+(0..n-1));
requires \valid(s3+(0..n-1));
requires \forall int i1,i2,i3; 0 <= i1 < n && 0 <= i2 < n && 0 <= i3 < n ==> \separated(s1+i1,s2+i2,s3+i3);
requires \forall int i; 0 <= i < n ==> 0 <= s1[i] <= 26;
ensures \forall int i; 0 <= i < n ==> s3[i]==s1[i];
ensures \forall int i; 0 <= i < n ==> \old(s1[i])==s1[i];
assigns s2[0..n-1], s3[0..n-1];
*/
void autoencode(int* s1, int* s2, int* s3, int n) {
  encode(s1, s2, s3, n);
  decode(s2, s3, s1, n);
  //@assert \forall int i; 0 <= i < n ==> \at(s1[i],Pre)==s1[i];
  //@assert \forall int i; 0 <= i < n ==> s2[i]==cypher(s1[i]);
  //@assert \forall int i; 0 <= i < n ==> s3[i]==decypher(s2[i]);
  //@assert \forall int i; 0 <= i < n ==> s3[i]==decypher(cypher(s1[i]));
  //@assert \forall int i; 0 <= i < n ==> s3[i]==s1[i];
}
