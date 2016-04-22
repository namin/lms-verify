/*@
    // Invariant and equality spec for Vector[Char]
    predicate spec_Inv_VC(int **a1, int *an1, int n) = 
      \valid(a1+(0..n)) && \valid(an1+(0..n)); 
    predicate spec_eq_VC(int *a1, int *a2, int n1, int n2) = 
      \forall int j; (0<=j<n1) && n1==n2 ==> a1[j] == a2[j]);
    // Invariant and equality spec for Vector[Vector[Char]]
    predicate spec_Inv_VVC(int **a1, int *an1, int n) = 
      \valid(a1+(0..n)) && \valid(an1+(0..n)) &&
      \forall int j; (0<=j<n) ==> spec_Inv_VC(a1[j],an1[j]);
    predicate spec_eq_VVC(int **a1, int **a2, int *an1, int *an2, int n1, int n2) = 
      \forall int j; (0<=j<n1) && n1==n2 ==> spec_Eq_VC(a1[j],a2[j],an1[j],an2[j]); 
*/
// Contract and implementation for Vector[Char] equality
/*@ requires spec_Inv_VC(a1,an1,n1) && spec_Inv_VC(a2,an2,n2);
    ensures (\result == 1 ==> spec_Eq_VC(a1,a2,an1,an2,n1,n2));
    assigns \nothing; */
int eq_VC(char *a1, char *a2, int n1, int n2) { ... 12 lines elided ... }
// Contract and implementation for Vector[Vector[Char]] equality
/*@ requires spec_Inv_VVC(a1,an1,n1) && spec_Inv_VVC(a2,an2,n2);
    ensures (\result == 1 ==> spec_Eq_VVC(a1,a2,an1,an2,n1,n2));
    assigns \nothing; */
int eq_VVC(char **a1, char **a2, int *an1, int *an2, int n1, int n2) {
  if (n1 != n2) return 0;
    /*@ loop invariant (0 <= i <= n1) && 
          \forall int i; spec_Eq_VC(a1[i],a2[i],an1[i],an2[i]); 
        loop assigns i;
        loop variant (n1-i); */
    for (int i = 0; i < n1; i++) {
      if (eq_VC(a1[i],a2[i],an1[i],an2[i]) != 1) return 0;
    }
    return 1;
}
