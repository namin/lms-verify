#include <limits.h>
//@ predicate inv_vec_Int(int  * x0, int  x1) = ((x1==0) || ((x1>0) && \valid(x0+(0..x1-1))));
//@ predicate eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) = ((x17==x19) && (\forall int x23; (0<=x23<x17) ==> (x16[x23]==x18[x23])));
/*@
requires (inv_vec_Int(x16,x17) && inv_vec_Int(x18,x19));
assigns \nothing;
ensures (inv_vec_Int(x16,x17) && inv_vec_Int(x18,x19));
ensures \result <==> eq_vec_Int(x16, x17, x18, x19);
*/
int eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) {
  int x21 = x17 == x19;
  int x33;
  if (x21) {
    int x32 = 1;
    /*@ loop invariant (0 <= x24 <= x17);
    loop invariant \forall int x23; (0 <= x23 < x24) ==>  (x16[x23]==x18[x23]);
    loop assigns x24;
    loop variant (x17-x24); */
    for (int x24 = 0; x24 < x17; x24++) {
      int x29 = x16[x24];
      int x30 = x18[x24];
      int x31 = x29 == x30;
      if (!x31) { x32 = 0; break; }
    }
    x33 = x32;
  } else {
    x33 = 0/*false*/;
  }
  return x33;
}
//@ predicate inv_vec_vec_Int(int  * * x37, int  * x38, int  x39) = (((x39==0) || ((x39>0) && (\valid(x37+(0..x39-1)) && \valid(x38+(0..x39-1))))) && (\forall int x49; (0<=x49<x39) ==> inv_vec_Int(x37[x49],x38[x49])));
/*@
inductive vec_Int_Permut{L1,L2}(int  * * x61, int  * x62, integer  x63) {
  case vec_Int_Permut_refl{L}:
  \forall int  * * x64, int  * x65, integer  x66; vec_Int_Permut{L,L}(x64,x65,x66);
  case vec_Int_Permut_sym{L1,L2}:
  \forall int  * * x70, int  * x71, integer  x72; (vec_Int_Permut{L1,L2}(x70,x71,x72) ==> vec_Int_Permut{L2,L1}(x70,x71,x72));
  case vec_Int_Permut_trans{L1,L2,L3}:
  \forall int  * * x78, int  * x79, integer  x80; ((vec_Int_Permut{L1,L2}(x78,x79,x80) && vec_Int_Permut{L2,L3}(x78,x79,x80)) ==> vec_Int_Permut{L1,L3}(x78,x79,x80));
  case vec_Int_Permut_swap{L1,L2}:
  \forall int  * * x89, int  * x90, integer  x91; (\forall integer  x93; (\forall integer  x94; ((((((0<=x93) && (x93<x91)) && (0<=x94)) && (x94<x91)) && ((((\at(x89[x93],L1)==\at(x89[x94],L2)) && (\at(x90[x93],L1)==\at(x90[x94],L2))) && ((\at(x89[x94],L1)==\at(x89[x93],L2)) && (\at(x90[x94],L1)==\at(x90[x93],L2)))) && (\forall integer  x129; (((((0<=x129) && (x129<x91)) && (x129!=x93)) && (x129!=x94)) ==> ((\at(x89[x129],L1)==\at(x89[x129],L2)) && (\at(x90[x129],L1)==\at(x90[x129],L2))))))) ==> vec_Int_Permut{L1,L2}(x89,x90,x91))));
}
*/
/*@
requires ((inv_vec_vec_Int(x164,x165,x166) && ((((0<=x167) && (x167<x166)) && (0<=x168)) && (x168<x166))) && (\forall int  x194; (\forall int  x195; (((((0<=x194) && (x194<x166)) && (0<=x195)) && (x195<x166)) ==> \separated(x164+x194,x165+x195)))));
ensures (((inv_vec_vec_Int(x164,x165,x166) && ((((\at(x164[x167],Old)==\at(x164[x168],Post)) && (\at(x165[x167],Old)==\at(x165[x168],Post))) && ((\at(x164[x168],Old)==\at(x164[x167],Post)) && (\at(x165[x168],Old)==\at(x165[x167],Post)))) && (\forall int  x241; (((((0<=x241) && (x241<x166)) && (x241!=x167)) && (x241!=x168)) ==> ((\at(x164[x241],Old)==\at(x164[x241],Post)) && (\at(x165[x241],Old)==\at(x165[x241],Post))))))) && vec_Int_Permut{Old,Post}(x164,x165,x166)) && (\forall int  x271; (\forall int  x272; (((((0<=x271) && (x271<x166)) && (0<=x272)) && (x272<x166)) ==> \separated(x164+x271,x165+x272)))));
assigns x164[(0..x166-1)], x165[(0..x166-1)];
*/
void inswap_vec_Int(int  * * x164, int  * x165, int  x166, int  x167, int  x168) {
  int  *x171 = x164[x167];
  int x172 = x165[x167];
  int  *x173 = x164[x168];
  int x174 = x165[x168];
  x164[x167] = x173;
  x165[x167] = x174;
  x164[x168] = x171;
  x165[x168] = x172;
}
/*@
requires (inv_vec_vec_Int(x291,x292,x293) && (\forall int  x516; (\forall int  x517; (((((0<=x516) && (x516<x293)) && (0<=x517)) && (x517<x293)) ==> \separated(x291+x516,x292+x517)))));
ensures ((inv_vec_vec_Int(x291,x292,x293) && (\forall int  x537; (\forall int  x538; (((((0<=x537) && (x537<x293)) && (0<=x538)) && (x538<x293)) ==> \separated(x291+x537,x292+x538))))) && ((\forall int  x557; (((0<=x557) && (x557<(x293-1))) ==> (x292[x557]<=x292[(x557+1)]))) && vec_Int_Permut{Old,Post}(x291,x292,x293)));
assigns x291[(0..x293-1)], x292[(0..x293-1)];
*/
void insort_vecs(int  * * x291, int  * x292, int  x293) {
  int x296 = x293 - 1;
  /*@
  loop invariant (x298==0 && x296==-1) || (0<=x298<=x296);
  loop invariant (\forall int  x304; (((0<=x304) && (x304<x298)) ==> (x292[x304]<=x292[(x304+1)])));
  loop invariant ((x298>0) ==> (\forall int  x320; (((x298<=x320) && (x320<x293)) ==> (x292[(x298-1)]<=x292[x320]))));
  loop invariant vec_Int_Permut{Pre,Here}(x291,x292,x293);
  loop invariant (\forall int  x338; (\forall int  x339; (((((0<=x338) && (x338<x293)) && (0<=x339)) && (x339<x293)) ==> \separated(x291+x338,x292+x339))));
  loop invariant (((x293==0) || ((x293>0) && (\valid(x291+(0..x293-1)) && \valid(x292+(0..x293-1))))) && (\forall int x367; (0<=x367<x293) ==> inv_vec_Int(x291[x367],x292[x367])));
  loop assigns x298, x291[(0..x293-1)], x292[(0..x293-1)];
  loop variant x296-x298;
  */
  for(int x298=0; x298 < x296; x298++) {
    int x381 = x298;
    int x382 = x298 + 1;
    /*@
    loop invariant 0<=x384<=x293;
    loop invariant (\forall int  x385; (((x298<=x385) && (x385<x384)) ==> (x292[x381]<=x292[x385])));
    loop invariant ((x298<=x381) && (x381<x384));
    loop assigns x384, x381;
    loop variant x293-x384;
    */
    for(int x384=x382; x384 < x293; x384++) {
      int  *x407 = x291[x384];
      int x408 = x292[x384];
      int x409 = x381;
      int  *x410 = x291[x409];
      int x411 = x292[x409];
      int x412 = x408 <= x411;
      if (x412) {
        x381 = x384;
      } else {
        //@assert (x292[x381]<=x292[x384]);
      }
    }
    //@assert (x292[x381]<=x292[(x298+1)]);
    int x436 = x381;
    inswap_vec_Int(x291,x292,x293,x298,x436);
    //@assert (\forall int  x439; (((0<=x439) && (x439<(x298-1))) ==> (x292[x439]<=x292[(x439+1)])));
    //@assert (\forall int  x455; (((0<=x455) && (x455<x298)) ==> (x292[x455]<=x292[(x455+1)])));
    //@assert (x292[x298]<=x292[(x298+1)]);
    //@assert (\forall int  x480; (((0<=x480) && (x480<(x298+1))) ==> (x292[x480]<=x292[(x480+1)])));
    //@assert (\forall int  x497; ((((x298+1)<=x497) && (x497<x293)) ==> (x292[x298]<=x292[x497])));
  }
}
