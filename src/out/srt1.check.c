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
  \forall int  * x40, integer  x41; (\forall integer  x43; (\forall integer  x44; ((((((0<=x43) && (x43<x41)) && (0<=x44)) && (x44<x41)) && (((\at(x40[x43],L1)==\at(x40[x44],L2)) && (\at(x40[x44],L1)==\at(x40[x43],L2))) && (\forall integer  x67; (((((0<=x67) && (x67<x41)) && (x67!=x43)) && (x67!=x44)) ==> (\at(x40[x67],L1)==\at(x40[x67],L2)))))) ==> Int_Permut{L1,L2}(x40,x41))));
}
*/
/*@
requires (inv_vec_Int(x96,x97) && ((((0<=x98) && (x98<x97)) && (0<=x99)) && (x99<x97)));
ensures ((inv_vec_Int(x96,x97) && (((\at(x96[x98],Old)==\at(x96[x99],Post)) && (\at(x96[x99],Old)==\at(x96[x98],Post))) && (\forall int  x137; (((((0<=x137) && (x137<x97)) && (x137!=x98)) && (x137!=x99)) ==> (\at(x96[x137],Old)==\at(x96[x137],Post)))))) && Int_Permut{Old,Post}(x96,x97));
assigns x96[(0..x97-1)];
*/
void inswap_Int(int  * x96, int  x97, int  x98, int  x99) {
  int x102 = x96[x98];
  int x103 = x96[x99];
  x96[x98] = x103;
  x96[x99] = x102;
}
/*@
requires inv_vec_Int(x162,x163);
ensures (inv_vec_Int(x162,x163) && ((\forall int  x323; (((0<=x323) && (x323<(x163-1))) ==> (x162[x323]<=x162[(x323+1)]))) && Int_Permut{Old,Post}(x162,x163)));
assigns x162[(0..x163-1)];
*/
void insort(int  * x162, int  x163) {
  int x166 = x163 - 1;
  /*@
  loop invariant (x168==0 && x166==-1) || (0<=x168<=x166);
  loop invariant (\forall int  x173; (((0<=x173) && (x173<x168)) ==> (x162[x173]<=x162[(x173+1)])));
  loop invariant ((x168>0) ==> (\forall int  x187; (((x168<=x187) && (x187<x163)) ==> (x162[(x168-1)]<=x162[x187]))));
  loop invariant Int_Permut{Pre,Here}(x162,x163);
  loop assigns x168, x162[(0..x163-1)];
  loop variant x166-x168;
  */
  for(int x168=0; x168 < x166; x168++) {
    int x203 = x168;
    int x204 = x168 + 1;
    /*@
    loop invariant 0<=x206<=x163;
    loop invariant (\forall int  x207; (((x168<=x207) && (x207<x206)) ==> (x162[x203]<=x162[x207])));
    loop invariant ((x168<=x203) && (x203<x206));
    loop assigns x206, x203;
    loop variant x163-x206;
    */
    for(int x206=x204; x206 < x163; x206++) {
      int x227 = x162[x206];
      int x228 = x203;
      int x229 = x162[x228];
      int x230 = x227 <= x229;
      if (x230) {
        x203 = x206;
      } else {
        //@assert (x162[x203]<=x162[x206]);
      }
    }
    //@assert (x162[x203]<=x162[(x168+1)]);
    int x250 = x203;
    inswap_Int(x162,x163,x168,x250);
    //@assert (\forall int  x253; (((0<=x253) && (x253<(x168-1))) ==> (x162[x253]<=x162[(x253+1)])));
    //@assert (\forall int  x267; (((0<=x267) && (x267<x168)) ==> (x162[x267]<=x162[(x267+1)])));
    //@assert (x162[x168]<=x162[(x168+1)]);
    //@assert (\forall int  x288; (((0<=x288) && (x288<(x168+1))) ==> (x162[x288]<=x162[(x288+1)])));
    //@assert (\forall int  x303; ((((x168+1)<=x303) && (x303<x163)) ==> (x162[x168]<=x162[x303])));
  }
}
