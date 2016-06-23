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
requires (inv_vec_Int(x158,x159) && (x159>0));
ensures inv_vec_Int(x158,x159);
assigns x158[(0..x159-1)];
*/
void insort(int  * x158, int  x159) {
  int x162 = x159 - 1;
  /*@
  loop invariant ((0<=x164) && (x164<=(x159-1)));
  loop invariant (\forall int  x165; (((0<=x165) && (x165<x164)) ==> (x158[x165]>=x158[(x165+1)])));
  loop invariant ((x164>0) ==> (\forall int  x179; (((x164<=x179) && (x179<x159)) ==> (x158[(x164-1)]>=x158[x179]))));
  loop assigns x164, x158[(0..x159-1)];
  loop variant (x162-x164);
  */
  for(int x164=0; x164 < x162; x164++) {
    int x193 = x164;
    int x194 = x164 + 1;
    /*@
    loop invariant 0<=x196<=x159;
    loop invariant (\forall int  x197; (((x164<=x197) && (x197<x196)) ==> (x158[x193]>=x158[x197])));
    loop invariant ((x164<=x193) && (x193<x196));
    loop assigns x196, x193;
    loop variant x159-x196;
    */
    for(int x196=x194; x196 < x159; x196++) {
      int x217 = x158[x196];
      int x218 = x193;
      int x219 = x158[x218];
      int x220 = x217 >= x219;
      if (x220) {
        x193 = x196;
      } else {
        //@assert (x158[x193]>=x158[x196]);
      }
    }
    //@assert (x158[x193]>=x158[(x164+1)]);
    int x240 = x193;
    inswap_Int(x158,x159,x164,x240);
    //@assert (\forall int  x243; (((0<=x243) && (x243<(x164-1))) ==> (x158[x243]>=x158[(x243+1)])));
    //@assert (\forall int  x257; (((0<=x257) && (x257<x164)) ==> (x158[x257]>=x158[(x257+1)])));
    //@assert (x158[x164]>=x158[(x164+1)]);
    //@assert (\forall int  x278; (((0<=x278) && (x278<(x164+1))) ==> (x158[x278]>=x158[(x278+1)])));
    //@assert (\forall int  x293; ((((x164+1)<=x293) && (x293<x159)) ==> (x158[x164]>=x158[x293])));
  }
}
