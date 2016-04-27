typedef struct _vc {
  int n;
  char* a;
} vc;

typedef struct _vvc {
  int n;
  struct _vc* a;
} vvc;

/*@
    // Invariant and equality spec for Vector[Char]
    predicate spec_Inv_VC(vc v) =
      v.n==0 || (v.n>0 && \valid(v.a+(0..v.n-1)));
    predicate spec_Eq_VC(vc v1, vc v2) =
      (v1.n==v2.n) &&
      (\forall int j; (0<=j<v1.n) ==> v1.a[j] == v2.a[j]);
    // Invariant and equality spec for Vector[Vector[Char]]
    predicate spec_Inv_VVC(vvc v) =
      v.n==0 || (v.n>0 && \valid(v.a+(0..v.n-1))) &&
      (\forall int j; (0<=j<v.n) ==> spec_Inv_VC(v.a[j]));
    predicate spec_Eq_VVC(vvc v1, vvc v2) =
      (v1.n==v2.n) &&
      (\forall int j; (0<=j<v1.n) ==> spec_Eq_VC(v1.a[j],v2.a[j]));
*/
// Contract and implementation for Vector[Char] equality
/*@ requires spec_Inv_VC(v1) && spec_Inv_VC(v2);
    ensures (\result == 1) || (\result == 0);
    ensures (\result == 1) <==> spec_Eq_VC(v1, v2);
    ensures (\result == 0) <==> !spec_Eq_VC(v1, v2);
    assigns \nothing; */
int eq_VC(vc v1, vc v2) {
  if (v1.n != v2.n) return 0;
    /*@ loop invariant (0 <= i <= v1.n);
        loop invariant \forall int j; (0 <= j < i) ==> v1.a[j]==v2.a[j];
        loop assigns i;
        loop variant (v1.n-i); */
    for (int i = 0; i < v1.n; i++) {
      if (v1.a[i] != v2.a[i]) return 0;
    }
    return 1;
}
// Contract and implementation for Vector[Vector[Char]] equality
/*@ requires spec_Inv_VVC(v1) && spec_Inv_VVC(v2);
    ensures (\result == 1) || (\result == 0);
    ensures (\result == 1) <==> spec_Eq_VVC(v1, v2);
    ensures (\result == 0) <==> !spec_Eq_VVC(v1, v2);
    assigns \nothing; */
int eq_VVC(vvc v1, vvc v2) {
  if (v1.n != v2.n) return 0;
    /*@ loop invariant (0 <= i <= v1.n);
        loop invariant \forall int j; (0 <= j < i) ==> spec_Eq_VC(v1.a[j],v2.a[j]);
        loop assigns i;
        loop variant (v1.n-i); */
    for (int i = 0; i < v1.n; i++) {
      if (eq_VC(v1.a[i],v2.a[i]) != 1) return 0;
    }
    return 1;
}
