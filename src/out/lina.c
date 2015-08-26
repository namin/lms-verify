/*@ requires na > 0 && nb > 0 && na == nb;
    requires \valid(va+(0..na-1));
    requires \valid(vb+(0..nb-1));
    assigns \nothing;
 */
int vv_mult(int* va, int na, int* vb, int nb) {
  int r = 0;
  /*@
    loop invariant na==nb;
    loop invariant 0<=i<=na;
    loop assigns i, r;
  */
  for (int i = 0; i<na; i++) {
    r += va[i]*vb[i];
  }
  return r;
}

/*@ requires ra >0 && ca > 0 && nb > 0 && nc > 0;
    requires ca == nb;
    requires ra == nc;
    requires \valid(vb+(0..nb-1));
    requires \valid(vc+(0..nc-1));
    requires \valid(ma+(0..ra-1));
    requires \forall int r; 0 <= r < ra ==> \valid(ma[r]+(0..ca-1));
    requires \separated(ma, vc);
    requires \separated(vb, vc);
    assigns vc[0..nc-1];
*/
void mv_mult(int** ma, int ra, int ca,
             int* vb, int nb,
             int* vc, int nc) {
  /*@
    loop invariant ra==nc;
    loop invariant 0 <= r <= ra;
    loop assigns r, vc[0..nc-1];
  */
  for (int r = 0; r < ra; r++) {
    vc[r] = 0;
    /*@
      loop invariant ca==nb;
      loop invariant 0 <= c <= ca;
      loop assigns c, vc[0..nc-1];
    */
    for (int c = 0; c < ca; c++) {
      vc[r] += ma[r][c]*vb[c];
    }
  }
  return;
}

/*@ requires ra >0 && ca > 0 && nb > 0 && nc > 0;
    requires ca == nb;
    requires ra == nc;
    requires \valid(vb+(0..nb-1));
    requires \valid(vc+(0..nc-1));
    requires \valid(ma+(0..ra-1));
    requires \forall int r; 0 <= r < ra ==> \valid(ma[r]+(0..ca-1));
    requires \separated(ma, vc);
    requires \separated(vb, vc);
    assigns vc[0..nc-1];
*/
void mv_mult_alt(int** ma, int ra, int ca,
             int* vb, int nb,
             int* vc, int nc) {
  /*@
    loop invariant ra==nc;
    loop invariant 0 <= r <= ra;
    loop assigns r, vc[0..nc-1];
  */
  for (int r = 0; r < ra; r++) {
    vc[r] = vv_mult(ma[r], ca, vb, nb);
  }
  return;
}

/*@ requires ra >0 && ca > 0;
    requires rb >0 && cb > 0;
    requires rc >0 && cc > 0;
    requires ca == rb;
    requires ra == rc;
    requires cc == cb;
    requires \valid(ma+(0..ra-1));
    requires \forall int r; 0 <= r < ra ==> \valid(ma[r]+(0..ca-1));
    requires \valid(mb+(0..rb-1));
    requires \forall int r; 0 <= r < rb ==> \valid(mb[r]+(0..cb-1));
    requires \valid(mc+(0..rc-1));
    requires \forall int r; 0 <= r < rc ==> \valid(mc[r]+(0..cc-1));
    requires \separated(ma, mc);
    requires \separated(mb, mc);
    assigns mc[0..rc-1][0..cc-1];
*/
void mm_mult(int** ma, int ra, int ca,
             int** mb, int rb, int cb,
             int** mc, int rc, int cc) {
  /*@
    loop invariant ra==rc;
    loop invariant 0 <= r <= ra;
    loop assigns r, mc[0..rc-1][0..cc-1];
  */
  for (int r = 0; r < ra; r++) {
    /*@
      loop invariant cc==cb;
      loop invariant 0 <= c <= cb;
      loop assigns c, mc[0..rc-1][0..cc-1];
    */
    for (int c = 0; c < cb; c++) {
      mc[r][c] = 0;
      /*@
        loop invariant rb==ca;
        loop invariant 0 <= i <= ca;
        loop assigns i, mc[0..rc-1][0..cc-1];
      */
      for (int i = 0; i < ca; i++) {
        mc[r][c] += ma[r][i] * mb[i][c];
      }
    }
  }
  return;
}
