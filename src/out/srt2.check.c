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
requires (inv_vec_Int(x162,x163) && (x163>0));
ensures inv_vec_Int(x162,x163);
assigns x162[(0..x163-1)];
*/
void insort(int  * x162, int  x163) {
  int x166 = x163 - 1;
  /*@
  loop invariant 0<=x168<=x166;
  loop invariant (\forall int  x173; (((0<=x173) && (x173<x168)) ==> (x162[x173]>=x162[(x173+1)])));
  loop invariant ((x168>0) ==> (\forall int  x187; (((x168<=x187) && (x187<x163)) ==> (x162[(x168-1)]>=x162[x187]))));
  loop assigns x168, x162[(0..x163-1)];
  loop variant x166-x168;
  */
  for(int x168=0; x168 < x166; x168++) {
    int x201 = x168;
    int x202 = x168 + 1;
    /*@
    loop invariant 0<=x204<=x163;
    loop invariant (\forall int  x205; (((x168<=x205) && (x205<x204)) ==> (x162[x201]>=x162[x205])));
    loop invariant ((x168<=x201) && (x201<x204));
    loop assigns x204, x201;
    loop variant x163-x204;
    */
    for(int x204=x202; x204 < x163; x204++) {
      int x225 = x162[x204];
      int x226 = x201;
      int x227 = x162[x226];
      int x228 = x225 >= x227;
      if (x228) {
        x201 = x204;
      } else {
        //@assert (x162[x201]>=x162[x204]);
      }
    }
    //@assert (x162[x201]>=x162[(x168+1)]);
    int x248 = x201;
    inswap_Int(x162,x163,x168,x248);
    //@assert (\forall int  x251; (((0<=x251) && (x251<(x168-1))) ==> (x162[x251]>=x162[(x251+1)])));
    //@assert (\forall int  x265; (((0<=x265) && (x265<x168)) ==> (x162[x265]>=x162[(x265+1)])));
    //@assert (x162[x168]>=x162[(x168+1)]);
    //@assert (\forall int  x286; (((0<=x286) && (x286<(x168+1))) ==> (x162[x286]>=x162[(x286+1)])));
    //@assert (\forall int  x301; ((((x168+1)<=x301) && (x301<x163)) ==> (x162[x168]>=x162[x301])));
  }
}
