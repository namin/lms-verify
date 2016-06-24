#include <limits.h>
//@ predicate eq___Int_Int__(int  x0, int  x1, int  x2, int  x3) = ((x0==x2) && (x1==x3));
/*@
assigns \nothing;
ensures \result <==> eq___Int_Int__(x0, x1, x2, x3);
*/
int eq___Int_Int__(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x0 == x2;
  int x7;
  if (x5) {
    int x6 = x1 == x3;
    x7 = x6;
  } else {
    x7 = 0/*false*/;
  }
  return x7;
}
//@ predicate inv_vec___Int_Int__(int  * x8, int  * x9, int  x10) = ((x10==0) || ((x10>0) && (\valid(x8+(0..x10-1)) && \valid(x9+(0..x10-1)))));
/*@
inductive __Int_Int___Permut{L1,L2}(int  * x29, int  * x30, integer  x31) {
  case __Int_Int___Permut_refl{L}:
  \forall int  * x32, int  * x33, integer  x34; __Int_Int___Permut{L,L}(x32,x33,x34);
  case __Int_Int___Permut_sym{L1,L2}:
  \forall int  * x38, int  * x39, integer  x40; (__Int_Int___Permut{L1,L2}(x38,x39,x40) ==> __Int_Int___Permut{L2,L1}(x38,x39,x40));
  case __Int_Int___Permut_trans{L1,L2,L3}:
  \forall int  * x46, int  * x47, integer  x48; ((__Int_Int___Permut{L1,L2}(x46,x47,x48) && __Int_Int___Permut{L2,L3}(x46,x47,x48)) ==> __Int_Int___Permut{L1,L3}(x46,x47,x48));
  case __Int_Int___Permut_swap{L1,L2}:
  \forall int  * x57, int  * x58, integer  x59; (\forall integer  x61; (\forall integer  x62; ((((((0<=x61) && (x61<x59)) && (0<=x62)) && (x62<x59)) && ((((\at(x57[x61],L1)==\at(x57[x62],L2)) && (\at(x58[x61],L1)==\at(x58[x62],L2))) && ((\at(x57[x62],L1)==\at(x57[x61],L2)) && (\at(x58[x62],L1)==\at(x58[x61],L2)))) && (\forall integer  x97; (((((0<=x97) && (x97<x59)) && (x97!=x61)) && (x97!=x62)) ==> ((\at(x57[x97],L1)==\at(x57[x97],L2)) && (\at(x58[x97],L1)==\at(x58[x97],L2))))))) ==> __Int_Int___Permut{L1,L2}(x57,x58,x59))));
}
*/
/*@
requires ((inv_vec___Int_Int__(x132,x133,x134) && ((((0<=x135) && (x135<x134)) && (0<=x136)) && (x136<x134))) && (\forall int  x162; (\forall int  x163; (((((0<=x162) && (x162<x134)) && (0<=x163)) && (x163<x134)) ==> \separated(x132+x162,x133+x163)))));
ensures (((inv_vec___Int_Int__(x132,x133,x134) && ((((\at(x132[x135],Old)==\at(x132[x136],Post)) && (\at(x133[x135],Old)==\at(x133[x136],Post))) && ((\at(x132[x136],Old)==\at(x132[x135],Post)) && (\at(x133[x136],Old)==\at(x133[x135],Post)))) && (\forall int  x209; (((((0<=x209) && (x209<x134)) && (x209!=x135)) && (x209!=x136)) ==> ((\at(x132[x209],Old)==\at(x132[x209],Post)) && (\at(x133[x209],Old)==\at(x133[x209],Post))))))) && __Int_Int___Permut{Old,Post}(x132,x133,x134)) && (\forall int  x239; (\forall int  x240; (((((0<=x239) && (x239<x134)) && (0<=x240)) && (x240<x134)) ==> \separated(x132+x239,x133+x240)))));
assigns x132[(0..x134-1)], x133[(0..x134-1)];
*/
void inswap___Int_Int__(int  * x132, int  * x133, int  x134, int  x135, int  x136) {
  int x139 = x132[x135];
  int x140 = x133[x135];
  int x141 = x132[x136];
  int x142 = x133[x136];
  x132[x135] = x141;
  x133[x135] = x142;
  x132[x136] = x139;
  x133[x136] = x140;
}
/*@
requires (inv_vec___Int_Int__(x259,x260,x261) && (\forall int  x481; (\forall int  x482; (((((0<=x481) && (x481<x261)) && (0<=x482)) && (x482<x261)) ==> \separated(x259+x481,x260+x482)))));
ensures ((inv_vec___Int_Int__(x259,x260,x261) && (\forall int  x502; (\forall int  x503; (((((0<=x502) && (x502<x261)) && (0<=x503)) && (x503<x261)) ==> \separated(x259+x502,x260+x503))))) && ((\forall int  x522; (((0<=x522) && (x522<(x261-1))) ==> (x259[x522]<=x259[(x522+1)]))) && __Int_Int___Permut{Old,Post}(x259,x260,x261)));
assigns x259[(0..x261-1)], x260[(0..x261-1)];
*/
void insort_pairs(int  * x259, int  * x260, int  x261) {
  int x264 = x261 - 1;
  /*@
  loop invariant (x266==0 && x264==-1) || (0<=x266<=x264);
  loop invariant (\forall int  x272; (((0<=x272) && (x272<x266)) ==> (x259[x272]<=x259[(x272+1)])));
  loop invariant ((x266>0) ==> (\forall int  x288; (((x266<=x288) && (x288<x261)) ==> (x259[(x266-1)]<=x259[x288]))));
  loop invariant __Int_Int___Permut{Pre,Here}(x259,x260,x261);
  loop invariant (\forall int  x306; (\forall int  x307; (((((0<=x306) && (x306<x261)) && (0<=x307)) && (x307<x261)) ==> \separated(x259+x306,x260+x307))));
  loop invariant ((x261==0) || ((x261>0) && (\valid(x259+(0..x261-1)) && \valid(x260+(0..x261-1)))));
  loop assigns x266, x259[(0..x261-1)], x260[(0..x261-1)];
  loop variant x264-x266;
  */
  for(int x266=0; x266 < x264; x266++) {
    int x346 = x266;
    int x347 = x266 + 1;
    /*@
    loop invariant 0<=x349<=x261;
    loop invariant (\forall int  x350; (((x266<=x350) && (x350<x349)) ==> (x259[x346]<=x259[x350])));
    loop invariant ((x266<=x346) && (x346<x349));
    loop assigns x349, x346;
    loop variant x261-x349;
    */
    for(int x349=x347; x349 < x261; x349++) {
      int x372 = x259[x349];
      int x373 = x260[x349];
      int x374 = x346;
      int x375 = x259[x374];
      int x376 = x260[x374];
      int x377 = x372 <= x375;
      if (x377) {
        x346 = x349;
      } else {
        //@assert (x259[x346]<=x259[x349]);
      }
    }
    //@assert (x259[x346]<=x259[(x266+1)]);
    int x401 = x346;
    inswap___Int_Int__(x259,x260,x261,x266,x401);
    //@assert (\forall int  x404; (((0<=x404) && (x404<(x266-1))) ==> (x259[x404]<=x259[(x404+1)])));
    //@assert (\forall int  x420; (((0<=x420) && (x420<x266)) ==> (x259[x420]<=x259[(x420+1)])));
    //@assert (x259[x266]<=x259[(x266+1)]);
    //@assert (\forall int  x445; (((0<=x445) && (x445<(x266+1))) ==> (x259[x445]<=x259[(x445+1)])));
    //@assert (\forall int  x462; ((((x266+1)<=x462) && (x462<x261)) ==> (x259[x266]<=x259[x462])));
  }
}
