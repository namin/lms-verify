#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, int  x1) = ((x1==0) || ((x1>0) && \valid(x0+(0..x1-1))));*/
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
requires (inv_vec_Int(x123,x124) &&
((((0<=x125) && (x125<x124)) && (0<=x126)) && (x126<x124)));
ensures ((inv_vec_Int(x123,x124) &&
(((\at((\at(x123[x125],Old)==\at(x123[x126],Post)),Old) && \at((\at(x123[x125],Old)==\at(x123[x126],Post)),Post)) && (\at((\at(x123[x126],Old)==\at(x123[x125],Post)),Old) && \at((\at(x123[x126],Old)==\at(x123[x125],Post)),Post))) && (\forall int  x182; (((((0<=x182) && (x182<x124)) && (x182!=x125)) && (x182!=x126)) ==> (\at((\at(x123[x182],Old)==\at(x123[x182],Post)),Old) && \at((\at(x123[x182],Old)==\at(x123[x182],Post)),Post)))))) &&
Int_Permut{Old,Post}(x123,x124));
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
ensures (inv_vec_Int(x216,x217) &&
((\forall int  x534; (((0<=x534) && (x534<(x217-1))) ==> (x216[x534]<=x216[(x534+1)]))) && Int_Permut{Old,Post}(x216,x217)));
assigns x216[(0..x217-1)];
*/
void insort(int  * x216, int  x217) {
  /*@assert (\forall int x221; (0<=x221<x217) ==> (\forall int x224; (0<=x224<x217) ==> (\forall int x227; (0<=x227<x217) ==> (((x216[x221]<=x216[x224]) && (x216[x224]<=x216[x227])) ==> (x216[x221]<=x216[x227])))));*/
  int x360 = x217 - 1;
  /*@
  loop invariant (x362==0 && x360==-1) || (0<=x362<=x360);
  loop invariant (\forall int  x367; (((0<=x367) && (x367<x362)) ==> (x216[x367]<=x216[(x367+1)])));
  loop invariant ((x362>0) ==> (\forall int  x381; (((x362<=x381) && (x381<x217)) ==> (x216[(x362-1)]<=x216[x381]))));
  loop invariant Int_Permut{Pre,Here}(x216,x217);
  loop invariant ((x217==0) || ((x217>0) && \valid(x216+(0..x217-1))));
  loop assigns x362, x216[(0..x217-1)];
  loop variant x360-x362;
  */
  for(int x362=0; x362 < x360; x362++) {
    int x414 = x362;
    int x415 = x362 + 1;
    /*@
    loop invariant 0<=x417<=x217;
    loop invariant (\forall int  x418; (((x362<=x418) && (x418<x417)) ==> (x216[x414]<=x216[x418])));
    loop invariant ((x362<=x414) && (x414<x417));
    loop assigns x417, x414;
    loop variant x217-x417;
    */
    for(int x417=x415; x417 < x217; x417++) {
      int x438 = x216[x417];
      int x439 = x414;
      int x440 = x216[x439];
      int x441 = x438 <= x440;
      if (x441) {
        x414 = x417;
      } else {
        /*@assert (x216[x414]<=x216[x417]);*/
      }
    }
    /*@assert (x216[x414]<=x216[(x362+1)]);*/
    int x461 = x414;
    inswap_Int(x216,x217,x362,x461);
    /*@assert (\forall int  x464; (((0<=x464) && (x464<(x362-1))) ==> (x216[x464]<=x216[(x464+1)])));*/
    /*@assert (\forall int  x478; (((0<=x478) && (x478<x362)) ==> (x216[x478]<=x216[(x478+1)])));*/
    /*@assert (x216[x362]<=x216[(x362+1)]);*/
    /*@assert (\forall int  x499; (((0<=x499) && (x499<(x362+1))) ==> (x216[x499]<=x216[(x499+1)])));*/
    /*@assert (\forall int  x514; ((((x362+1)<=x514) && (x514<x217)) ==> (x216[x362]<=x216[x514])));*/
  }
}
