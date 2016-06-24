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
  \forall int  * x40, integer  x41; (\forall integer  x43; (\forall integer  x44; ((((((0<=x43) && (x43<x41)) && (0<=x44)) && (x44<x41)) && (((\at((\at(x40[x43],L1)==\at(x40[x44],L2)),L1) && \at((\at(x40[x43],L1)==\at(x40[x44],L2)),L2)) && (\at((\at(x40[x44],L1)==\at(x40[x43],L2)),L1) && \at((\at(x40[x44],L1)==\at(x40[x43],L2)),L2))) && (\forall integer  x85; (((((0<=x85) && (x85<x41)) && (x85!=x43)) && (x85!=x44)) ==> (\at((\at(x40[x85],L1)==\at(x40[x85],L2)),L1) && \at((\at(x40[x85],L1)==\at(x40[x85],L2)),L2)))))) ==> Int_Permut{L1,L2}(x40,x41))));
}
*/
/*@
requires (inv_vec_Int(x123,x124) && ((((0<=x125) && (x125<x124)) && (0<=x126)) && (x126<x124)));
ensures ((inv_vec_Int(x123,x124) && (((\at((\at(x123[x125],Old)==\at(x123[x126],Post)),Old) && \at((\at(x123[x125],Old)==\at(x123[x126],Post)),Post)) && (\at((\at(x123[x126],Old)==\at(x123[x125],Post)),Old) && \at((\at(x123[x126],Old)==\at(x123[x125],Post)),Post))) && (\forall int  x182; (((((0<=x182) && (x182<x124)) && (x182!=x125)) && (x182!=x126)) ==> (\at((\at(x123[x182],Old)==\at(x123[x182],Post)),Old) && \at((\at(x123[x182],Old)==\at(x123[x182],Post)),Post)))))) && Int_Permut{Old,Post}(x123,x124));
assigns x123[(0..x124-1)];
*/
void inswap_Int(int  * x123, int  x124, int  x125, int  x126) {
  int x129 = x123[x125];
  int x130 = x123[x126];
  x123[x125] = x130;
  x123[x126] = x129;
}
/*@
requires inv_vec_Int(x216,x217);
ensures (inv_vec_Int(x216,x217) && ((\forall int  x394; (((0<=x394) && (x394<(x217-1))) ==> (x216[x394]<=x216[(x394+1)]))) && Int_Permut{Old,Post}(x216,x217)));
assigns x216[(0..x217-1)];
*/
void insort(int  * x216, int  x217) {
  int x220 = x217 - 1;
  /*@
  loop invariant (x222==0 && x220==-1) || (0<=x222<=x220);
  loop invariant (\forall int  x227; (((0<=x227) && (x227<x222)) ==> (x216[x227]<=x216[(x227+1)])));
  loop invariant ((x222>0) ==> (\forall int  x241; (((x222<=x241) && (x241<x217)) ==> (x216[(x222-1)]<=x216[x241]))));
  loop invariant Int_Permut{Pre,Here}(x216,x217);
  loop invariant ((x217==0) || ((x217>0) && \valid(x216+(0..x217-1))));
  loop assigns x222, x216[(0..x217-1)];
  loop variant x220-x222;
  */
  for(int x222=0; x222 < x220; x222++) {
    int x274 = x222;
    int x275 = x222 + 1;
    /*@
    loop invariant 0<=x277<=x217;
    loop invariant (\forall int  x278; (((x222<=x278) && (x278<x277)) ==> (x216[x274]<=x216[x278])));
    loop invariant ((x222<=x274) && (x274<x277));
    loop assigns x277, x274;
    loop variant x217-x277;
    */
    for(int x277=x275; x277 < x217; x277++) {
      int x298 = x216[x277];
      int x299 = x274;
      int x300 = x216[x299];
      int x301 = x298 <= x300;
      if (x301) {
        x274 = x277;
      } else {
        //@assert (x216[x274]<=x216[x277]);
      }
    }
    //@assert (x216[x274]<=x216[(x222+1)]);
    int x321 = x274;
    inswap_Int(x216,x217,x222,x321);
    //@assert (\forall int  x324; (((0<=x324) && (x324<(x222-1))) ==> (x216[x324]<=x216[(x324+1)])));
    //@assert (\forall int  x338; (((0<=x338) && (x338<x222)) ==> (x216[x338]<=x216[(x338+1)])));
    //@assert (x216[x222]<=x216[(x222+1)]);
    //@assert (\forall int  x359; (((0<=x359) && (x359<(x222+1))) ==> (x216[x359]<=x216[(x359+1)])));
    //@assert (\forall int  x374; ((((x222+1)<=x374) && (x374<x217)) ==> (x216[x222]<=x216[x374])));
  }
}
