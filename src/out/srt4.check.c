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
requires (inv_vec___Int_Int__(x259,x260,x261) && (\forall int  x535; (\forall int  x536; (((((0<=x535) && (x535<x261)) && (0<=x536)) && (x536<x261)) ==> \separated(x259+x535,x260+x536)))));
ensures ((inv_vec___Int_Int__(x259,x260,x261) && (\forall int  x556; (\forall int  x557; (((((0<=x556) && (x556<x261)) && (0<=x557)) && (x557<x261)) ==> \separated(x259+x556,x260+x557))))) && ((\forall int  x576; (((0<=x576) && (x576<(x261-1))) ==> ((x259[x576]<x259[(x576+1)]) || ((x259[x576]==x259[(x576+1)]) && (x260[x576]<=x260[(x576+1)]))))) && __Int_Int___Permut{Old,Post}(x259,x260,x261)));
assigns x259[(0..x261-1)], x260[(0..x261-1)];
*/
void insort_pairs(int  * x259, int  * x260, int  x261) {
  int x264 = x261 - 1;
  /*@
  loop invariant (x266==0 && x264==-1) || (0<=x266<=x264);
  loop invariant (\forall int  x272; (((0<=x272) && (x272<x266)) ==> ((x259[x272]<x259[(x272+1)]) || ((x259[x272]==x259[(x272+1)]) && (x260[x272]<=x260[(x272+1)])))));
  loop invariant ((x266>0) ==> (\forall int  x293; (((x266<=x293) && (x293<x261)) ==> ((x259[(x266-1)]<x259[x293]) || ((x259[(x266-1)]==x259[x293]) && (x260[(x266-1)]<=x260[x293]))))));
  loop invariant __Int_Int___Permut{Pre,Here}(x259,x260,x261);
  loop invariant (\forall int  x316; (\forall int  x317; (((((0<=x316) && (x316<x261)) && (0<=x317)) && (x317<x261)) ==> \separated(x259+x316,x260+x317))));
  loop invariant ((x261==0) || ((x261>0) && (\valid(x259+(0..x261-1)) && \valid(x260+(0..x261-1)))));
  loop assigns x266, x259[(0..x261-1)], x260[(0..x261-1)];
  loop variant x264-x266;
  */
  for(int x266=0; x266 < x264; x266++) {
    int x356 = x266;
    int x357 = x266 + 1;
    /*@
    loop invariant 0<=x359<=x261;
    loop invariant (\forall int  x360; (((x266<=x360) && (x360<x359)) ==> ((x259[x356]<x259[x360]) || ((x259[x356]==x259[x360]) && (x260[x356]<=x260[x360])))));
    loop invariant ((x266<=x356) && (x356<x359));
    loop assigns x359, x356;
    loop variant x261-x359;
    */
    for(int x359=x357; x359 < x261; x359++) {
      int x387 = x259[x359];
      int x388 = x260[x359];
      int x389 = x356;
      int x390 = x259[x389];
      int x391 = x260[x389];
      int x392 = x387 < x390;
      int x393 = x387 == x390;
      int x395;
      if (x393) {
        int x394 = x388 <= x391;
        x395 = x394;
      } else {
        x395 = 0/*false*/;
      }
      int x396 = x392 || x395;
      if (x396) {
        x356 = x359;
      } else {
        //@assert ((x259[x356]<x259[x359]) || ((x259[x356]==x259[x359]) && (x260[x356]<=x260[x359])));
      }
    }
    //@assert ((x259[x356]<x259[(x266+1)]) || ((x259[x356]==x259[(x266+1)]) && (x260[x356]<=x260[(x266+1)])));
    int x430 = x356;
    inswap___Int_Int__(x259,x260,x261,x266,x430);
    //@assert (\forall int  x433; (((0<=x433) && (x433<(x266-1))) ==> ((x259[x433]<x259[(x433+1)]) || ((x259[x433]==x259[(x433+1)]) && (x260[x433]<=x260[(x433+1)])))));
    //@assert (\forall int  x454; (((0<=x454) && (x454<x266)) ==> ((x259[x454]<x259[(x454+1)]) || ((x259[x454]==x259[(x454+1)]) && (x260[x454]<=x260[(x454+1)])))));
    //@assert ((x259[x266]<x259[(x266+1)]) || ((x259[x266]==x259[(x266+1)]) && (x260[x266]<=x260[(x266+1)])));
    //@assert (\forall int  x489; (((0<=x489) && (x489<(x266+1))) ==> ((x259[x489]<x259[(x489+1)]) || ((x259[x489]==x259[(x489+1)]) && (x260[x489]<=x260[(x489+1)])))));
    //@assert (\forall int  x511; ((((x266+1)<=x511) && (x511<x261)) ==> ((x259[x266]<x259[x511]) || ((x259[x266]==x259[x511]) && (x260[x266]<=x260[x511])))));
  }
}
