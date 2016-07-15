#include <limits.h>
/*@ predicate inv_vec_Int(int  * x0, int  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@
inductive vec_Int_Permut{L1,L2}(int  * x16, integer  x17) {
  case vec_Int_Permut_refl{L}:
  \forall int  * x18, integer  x19; vec_Int_Permut{L,L}(x18,x19);
  case vec_Int_Permut_sym{L1,L2}:
  \forall int  * x23, integer  x24; (vec_Int_Permut{L1,L2}(x23,x24) ==> vec_Int_Permut{L2,L1}(x23,x24));
  case vec_Int_Permut_trans{L1,L2,L3}:
  \forall int  * x30, integer  x31; ((vec_Int_Permut{L1,L2}(x30,x31) &&
  vec_Int_Permut{L2,L3}(x30,x31)) ==> vec_Int_Permut{L1,L3}(x30,x31));
  case vec_Int_Permut_step{L1,L2}:
  \forall int  * x40, integer  x41; (\exists integer  x43; (\exists integer  x44; (((\at((\at(x40[x43],L1)==\at(x40[x44],L2)),L1) &&
  \at((\at(x40[x43],L1)==\at(x40[x44],L2)),L2)) &&
  (\at((\at(x40[x44],L1)==\at(x40[x43],L2)),L1) &&
  \at((\at(x40[x44],L1)==\at(x40[x43],L2)),L2))) &&
  (\forall integer  x75; (((((0<=x75) &&
  (x75<x41)) &&
  (x75!=x43)) &&
  (x75!=x44)) ==> (\at((\at(x40[x75],L1)==\at(x40[x75],L2)),L1) &&
  \at((\at(x40[x75],L1)==\at(x40[x75],L2)),L2)))))));
}
*/
/*@
requires (inv_vec_Int(x109,x110) &&
((((0<=x111) &&
(x111<x110)) &&
(0<=x112)) &&
(x112<x110)));
ensures ((inv_vec_Int(x109,x110) &&
(((\at((\at(x109[x111],Old)==\at(x109[x112],Post)),Old) &&
\at((\at(x109[x111],Old)==\at(x109[x112],Post)),Post)) &&
(\at((\at(x109[x112],Old)==\at(x109[x111],Post)),Old) &&
\at((\at(x109[x112],Old)==\at(x109[x111],Post)),Post))) &&
(\forall int  x168; (((((0<=x168) &&
(x168<x110)) &&
(x168!=x111)) &&
(x168!=x112)) ==> (\at((\at(x109[x168],Old)==\at(x109[x168],Post)),Old) &&
\at((\at(x109[x168],Old)==\at(x109[x168],Post)),Post)))))) &&
vec_Int_Permut{Old,Post}(x109,x110));
assigns x109[(0..x110-1)];
*/
void inswap_Int(int  * x109, int  x110, int  x111, int  x112) {
  int x115 = x109[x111];
  int x116 = x109[x112];
  x109[x111] = x116;
  x109[x112] = x115;
}
/*@
requires inv_vec_Int(x202,x203);
ensures (inv_vec_Int(x202,x203) &&
((\forall int  x520; (((0<=x520) &&
(x520<(x203-1))) ==> (x202[x520]<=x202[(x520+1)]))) &&
vec_Int_Permut{Old,Post}(x202,x203)));
assigns x202[(0..x203-1)];
*/
void insort(int  * x202, int  x203) {
  /*@assert (\forall int x207; (0<=x207<x203) ==> (\forall int x210; (0<=x210<x203) ==> (\forall int x213; (0<=x213<x203) ==> (((x202[x207]<=x202[x210]) &&
  (x202[x210]<=x202[x213])) ==> (x202[x207]<=x202[x213])))));*/
  int x346 = x203 - 1;
  /*@
  loop invariant (x348==0 && x346==-1) || (0<=x348<=x346);
  loop invariant (\forall int  x353; (((0<=x353) &&
  (x353<x348)) ==> (x202[x353]<=x202[(x353+1)])));
  loop invariant ((x348>0) ==> (\forall int  x367; (((x348<=x367) &&
  (x367<x203)) ==> (x202[(x348-1)]<=x202[x367]))));
  loop invariant vec_Int_Permut{Pre,Here}(x202,x203);
  loop invariant ((x203==0) || ((x203>0) &&
  \valid(x202+(0..x203-1))));
  loop assigns x348, x202[(0..x203-1)];
  loop variant x346-x348;
  */
  for(int x348=0; x348 < x346; x348++) {
    int x400 = x348;
    int x401 = x348 + 1;
    /*@
    loop invariant 0<=x403<=x203;
    loop invariant (\forall int  x404; (((x348<=x404) &&
    (x404<x403)) ==> (x202[x400]<=x202[x404])));
    loop invariant ((x348<=x400) &&
    (x400<x403));
    loop assigns x403, x400;
    loop variant x203-x403;
    */
    for(int x403=x401; x403 < x203; x403++) {
      int x424 = x202[x403];
      int x425 = x400;
      int x426 = x202[x425];
      int x427 = x424 <= x426;
      if (x427) {
        x400 = x403;
      } else {
        /*@assert (x202[x400]<=x202[x403]);*/
      }
    }
    /*@assert (x202[x400]<=x202[(x348+1)]);*/
    int x447 = x400;
    inswap_Int(x202,x203,x348,x447);
    /*@assert (\forall int  x450; (((0<=x450) &&
    (x450<(x348-1))) ==> (x202[x450]<=x202[(x450+1)])));*/
    /*@assert (\forall int  x464; (((0<=x464) &&
    (x464<x348)) ==> (x202[x464]<=x202[(x464+1)])));*/
    /*@assert (x202[x348]<=x202[(x348+1)]);*/
    /*@assert (\forall int  x485; (((0<=x485) &&
    (x485<(x348+1))) ==> (x202[x485]<=x202[(x485+1)])));*/
    /*@assert (\forall int  x500; ((((x348+1)<=x500) &&
    (x500<x203)) ==> (x202[x348]<=x202[x500])));*/
  }
}
