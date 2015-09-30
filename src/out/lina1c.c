//#include <stdio.h>

#define N 100

/*@ requires ra > 0 && ca > 0;
    requires ra < N && ca < N;
    requires 0 <= r < ra;
    requires 0 <= c < ca;
    ensures 0 <= \result < ra*ca;
    assigns \nothing;
*/
int index(int r, int c, int ra, int ca) {
  return r*ca+c;
}

/*@ requires ra > 0 && ca > 0;
    requires rb > 0 && cb > 0;
    requires rc > 0 && cc > 0;
    requires ca == rb;
    requires ra == rc;
    requires cc == cb;
    requires ra<N && ca<N;
    requires \valid(ma+(0..ra*ca-1));
    requires rb<N && cb<N;
    requires \valid(mb+(0..rb*cb-1));
    requires rc<N && cc<N;
    requires \valid(mc+(0..rc*cc-1));
    requires \separated(ma, mc);
    requires \separated(mb, mc);
    assigns mc[0..rc*cc-1];
*/
void mm_mult(int* ma, int ra, int ca,
             int* mb, int rb, int cb,
             int* mc, int rc, int cc) {
  /*@
    loop invariant 0 <= r <= ra;
    loop assigns r, mc[0..rc*cc-1];
  */
  for (int r = 0; r < ra; r++) {
    /*@
      loop invariant 0 <= c <= cb;
      loop assigns c, mc[0..rc*cc-1];
    */
    for (int c = 0; c < cb; c++) {
      //@assert (rc > 0 && cc > 0 && rc < N && cc < N && 0 <= r < rc && 0 <= c < cc);
      int i_c = r*cc+c;
      //@assert (0 <= i_c < rc*cc);
      mc[i_c] = 0;
      /*@
        loop invariant 0 <= i <= ca;
        loop assigns i, mc[0..rc*cc-1];
      */
      for (int i = 0; i < ca; i++) {
        //@assert (ra > 0 && ca > 0 && ra < N && ca < N && 0 <= r < ra && 0 <= i < ca);
        int i_a = r*ca+i;
        //@assert (0 <= i_a < ra*ca);
        //@assert (rb > 0 && cb > 0 && rb < N && cb < N && 0 <= i < rb && 0 <= c < cb);
        int i_b = i*cb+c;
        //@assert (0 <= i_b < rb*cb);
        mc[i_c] += ma[i_a] * mb[i_b];
      }
    }
  }
  return;
}

int main(void) {
  int ma[] = {1, 2, 3, 4, 5, 6};
  int ra = 2; int ca = 3;

  int mb[] = {1, 2, 3, 4, 5, 6};
  int rb = 3; int cb = 2;

  int mc[] = {0, 0, 0, 0};
  int rc = 2; int cc = 2;

  mm_mult(ma, ra, ca, mb, rb, cb, mc, rc, cc);

  /*
  for (int i = 0; i < rc; i++) {
    for (int j = 0; j < cc; j++) {
      printf("%d ", mc[i*cc+j]);
    }
    printf("\n");
  }
  */

  return 0;
}
