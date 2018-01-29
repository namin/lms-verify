#include <limits.h>
/*@ predicate unchanged{K,L}(int  * x0, integer  x1) = (\forall integer  x3; (((0<=x3) &&
(x3<x1)) ==> (\at(x0[x3],K)==\at(x0[x3],L))));*/
/*@
axiomatic MV_Prod {
  logic integer  MV_Prod{L}(integer  x16, integer  x17, integer  x18, int  * x19, int  * x20) reads x19[(0..(x18*x18)-1)], x20[(0..x18-1)];
  axiom MV_Prod_Empty{L}:
  \forall integer  x28, integer  x29, integer  x30, int  * x31, int  * x32; (((!((0<x28) &&
  (x28<=x30))) || (!((0<=x29) &&
  (x29<x30)))) ==> (MV_Prod{L}(x28,x29,x30,x31,x32)==0));
  axiom MV_Prod_One{L}:
  \forall integer  x47, integer  x48, integer  x49, int  * x50, int  * x51; (((((0<x47) &&
  (x47<=x49)) &&
  (0<=x48)) &&
  (x48<x49)) ==> (MV_Prod{L}(x47,x48,x49,x50,x51)==(MV_Prod{L}((x47-1),x48,x49,x50,x51)+(x50[((x49*x48)+(x47-1))]*x51[(x47-1)]))));
  axiom MV_Prod_Read{L1,L2}:
  \forall integer  x72, integer  x73, integer  x74, int  * x75, int  * x76; ((unchanged{L1,L2}(x75,(x74*x74)) &&
  unchanged{L1,L2}(x76,x74)) ==> (MV_Prod{L1}(x72,x73,x74,x75,x76)==MV_Prod{L2}(x72,x73,x74,x75,x76)));
}
*/
/*@
requires (((((((x91>0) &&
((0<=x89) &&
(x89<x91))) &&
\valid(x92+(0..(x91*x91)-1))) &&
\valid(x93+(0..x91-1))) &&
\valid(x88+(0..x91-1))) &&
\separated(x92+(0..(x91*x91)-1),x88+(0..x91-1))) &&
\separated(x93+(0..x91-1),x88+(0..x91-1)));
ensures (((((\forall int  x124; ((((0<=x124) &&
(x124<x91)) &&
(x124!=x89)) ==> (x88[x124]==\old(x88[x124])))) &&
(\forall int  x139; (((0<=x139) &&
(x139<(x91*x91))) ==> (x92[x139]==\old(x92[x139]))))) &&
(\forall int  x153; (((0<=x153) &&
(x153<x91)) ==> (x93[x153]==\old(x93[x153]))))) &&
(\forall int  x166; (((0<=x166) &&
(x166<x91)) ==> (MV_Prod(x91,x166,x91,x92,x93)==\old(MV_Prod(x91,x166,x91,x92,x93)))))) &&
(x88[x89]==x90));
assigns x88[x89];
*/
void put(int  * x88, int  x89, int  x90, int  x91, int  * x92, int  * x93) {
  x88[x89] = x90;
  int x96 = x88[x89];
}
/*@
requires ((((((((x183>0) &&
\valid(x184+(0..(x183*x183)-1))) &&
\valid(x185+(0..x183-1))) &&
\valid(x186+(0..x183-1))) &&
\separated(x184+(0..(x183*x183)-1),x186+(0..x183-1))) &&
\separated(x185+(0..x183-1),x186+(0..x183-1))) &&
(\forall int  x267; (((0<=x267) &&
(x267<(x183*x183))) ==> ((0<=x184[x267]) &&
(x184[x267]<=1))))) &&
(\forall int  x283; (((0<=x283) &&
(x283<x183)) ==> ((0<=x185[x283]) &&
(x185[x283]<=9)))));
ensures (\forall int  x299; (((0<=x299) &&
(x299<x183)) ==> (x186[x299]==MV_Prod(x183,x299,x183,x184,x185))));
assigns x186[(0..x183-1)];
*/
void mv_prod_impl(int  x183, int  * x184, int  * x185, int  * x186) {
  /*@
  loop invariant 0<=x189<=x183;
  loop invariant (\forall int  x190; (((0<=x190) &&
  (x190<x189)) ==> (x186[x190]==MV_Prod(x183,x190,x183,x184,x185))));
  loop assigns x189, x186[(0..x183-1)];
  loop variant x183-x189;
  */
  for(int x189=0; x189 < x183; x189++) {
    int x206 = 0;
    int x233 = x183 * x189;
    /*@
    loop invariant 0<=x207<=x183;
    loop invariant ((0<=x189) &&
    (x189<x183));
    loop invariant (\forall int  x213; (((0<=x213) &&
    (x213<x189)) ==> (x186[x213]==MV_Prod(x183,x213,x183,x184,x185))));
    loop invariant (x206==MV_Prod(x207,x189,x183,x184,x185));
    loop assigns x207, x206;
    loop variant x183-x207;
    */
    for(int x207=0; x207 < x183; x207++) {
      int x232 = x206;
      int x234 = x233 + x207;
      int x235 = x184[x234];
      int x236 = x185[x207];
      int x237 = x235 * x236;
      int x238 = x232 + x237;
      x206 = x238;
    }
    int x242 = x206;
    put(x186,x189,x242,x183,x184,x185);
  }
}
