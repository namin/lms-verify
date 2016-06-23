#include <limits.h>
//@ predicate inv_vec_Int(int  * x0, int  x1) = ((x1==0) || ((x1>0) && \valid(x0+(0..x1-1))));
/*@
inductive Int_Permut{L1,L2}(int  * x16, integer  x17) {
  case Int_Permut_refl{L}:
  \forall int  * x18, integer  x19; Int_Permut{L,L}(x18,x19);
  case Int_Permut_sym{L1,L2}:
  \forall int  * x23, integer  x24; (Int_Permut{L1,L2}(x23,x24) ==> Int_Permut{L2,L1}(x23,x24));
  case Int_Permut_trans{L1,L2,L3}:
  \forall int  * x30, integer  x31; ((Int_Permut{L1,L2}(x30,x31) && Int_Permut{L2,L3}(x30,x31)) ==> Int_Permut{L1,L3}(x30,x31));
  case Int_Permut_swap{L1,L2}:
  \forall int  * x40, integer  x41; (\forall integer  x43; (\forall integer  x44; ((((((((0<=x43) && (x43<x41)) && (0<=x44)) && (x44<x41)) && (\at(x40[x43],L1)==\at(x40[x44],L2))) && (\at(x40[x44],L1)==\at(x40[x43],L2))) && (\forall integer  x69; (((((0<=x69) && (x69<x41)) && (x69!=x43)) && (x69!=x44)) ==> (\at(x40[x69],L1)==\at(x40[x69],L2))))) ==> Int_Permut{L1,L2}(x40,x41))));
}
*/
/*@
requires (inv_vec_Int(x96,x97) && ((((0<=x98) && (x98<x97)) && (0<=x99)) && (x99<x97)));
ensures (((inv_vec_Int(x96,x97) && ((x96[x98]==\old(x96[x99])) && (x96[x99]==\old(x96[x98])))) && (\forall int  x136; ((((0<=x136) && (x136<x97)) && ((x136!=x98) && (x136!=x99))) ==> (x96[x136]==\old(x96[x136]))))) && Int_Permut{Old,Post}(x96,x97));
assigns x96[(0..x97-1)];
*/
void inswap_Int(int  * x96, int  x97, int  x98, int  x99) {
  int x102 = x96[x98];
  int x103 = x96[x99];
  x96[x98] = x103;
  x96[x99] = x102;
}
/*@
requires inv_vec_Int(x158,x159);
ensures ((inv_vec_Int(x158,x159) && (\forall int  x352; (((0<=x352) && (x352<(x159-1))) ==> (x158[x352]<=x158[(x352+1)])))) && Int_Permut{Old,Post}(x158,x159));
assigns x158[(0..x159-1)];
*/
void insort(int  * x158, int  x159) {
  int x162 = x159;
  /*@
  loop invariant (((((0<=x162) && (x162<=x159)) && ((x162<(x159-1)) ==> (\forall int  x299; (((x162<=x299) && (x299<(x159-1))) ==> (x158[x299]<=x158[(x299+1)]))))) && (\forall int  x316; ((((0<=x316) && (x316<x162)) && (x162<=(x159-1))) ==> (x158[x316]<=x158[x162])))) && Int_Permut{Pre,Here}(x158,x159));
  loop assigns x162, x158[(0..x159-1)];
  loop variant x162;
  */
  for (;;) {
    int x163 = x162;
    int x164 = x163 > 1;
    if (!x164) break;
    int x166 = 0;
    int x167 = x162;
    /*@
    loop invariant (((((((((0<=x162) && (x162<=x159)) && (0<=x169)) && (x169<=x162)) && (0<=x166)) && (x166<=(x162-1))) && ((x162-1)<x159)) && (\forall int  x214; (((0<=x214) && (x214<x169)) ==> (x158[x214]<=x158[x166])))) && Int_Permut{Pre,Here}(x158,x159));
    loop assigns x169, x166;
    loop variant (x162-x169);
    */
    for(int x169=0; x169 < x167; x169++) {
      int x170 = x166;
      int x171 = x158[x170];
      int x172 = x158[x169];
      int x173 = x171 <= x172;
      if (x173) {
        x166 = x169;
      } else {
        //@assert (x158[x169]<=x158[x166]);
      }
    }
    int x240 = x166;
    int x239 = x167 - 1;
    inswap_Int(x158,x159,x239,x240);
    //@assert (\forall int  x242; ((((x162-1)<x242) && (x242<(x159-1))) ==> (x158[x242]<=x158[(x242+1)])));
    //@assert ((x162<=(x159-1)) ==> (x158[(x162-1)]<=x158[x162]));
    //@assert (\forall int  x271; (((0<=x271) && (x271<x162)) ==> (x158[x271]<=x158[(x162-1)])));
    x162 = x239;
  }
}
