#include <limits.h>
#include <string.h>
/*@ logic integer cypher(int  x0) = (((x0==26)) ? (0) : ((x0+1)));*/
/*@
requires ((0<=x0) &&
(x0<=26));
assigns \nothing;
ensures ((0<=\result) &&
(\result<=26));
ensures \result == cypher(x0);
*/
int cypher(int  x0) {
  int x2 = x0 == 26;
  int x4;
  if (x2) {
    x4 = 0;
  } else {
    int x3 = x0 + 1;
    x4 = x3;
  }
  return x4;
}
/*@ logic integer decypher(int  x15) = (((x15==0)) ? (26) : ((x15-1)));*/
/*@
requires ((0<=x15) &&
(x15<=26));
assigns \nothing;
ensures ((0<=\result) &&
(\result<=26));
ensures \result == decypher(x15);
*/
int decypher(int  x15) {
  int x17 = x15 == 0;
  int x19;
  if (x17) {
    x19 = 26;
  } else {
    int x18 = x15 - 1;
    x19 = x18;
  }
  return x19;
}
/*@
requires ((((((x33>0) &&
\valid(x30+(0..x33-1))) &&
\valid(x31+(0..x33-1))) &&
\valid(x32+(0..x33-1))) &&
(\forall int  x117; (((0<=x117) &&
(x117<x33)) ==> (\forall int  x122; (((0<=x122) &&
(x122<x33)) ==> (\forall int  x127; (((0<=x127) &&
(x127<x33)) ==> ((\separated(x30+x117,x31+x122) &&
\separated(x30+x117,x32+x127)) &&
\separated(x31+x122,x32+x127))))))))) &&
(\forall int  x149; (((0<=x149) &&
(x149<x33)) ==> ((0<=x30[x149]) &&
(x30[x149]<=26)))));
ensures ((((\forall int  x165; (((0<=x165) &&
(x165<x33)) ==> (x31[x165]==cypher(x30[x165])))) &&
(\forall int  x177; (((0<=x177) &&
(x177<x33)) ==> ((0<=x31[x177]) &&
(x31[x177]<=26))))) &&
(\forall int  x192; (((0<=x192) &&
(x192<x33)) ==> (\old(x30[x192])==x30[x192])))) &&
(\forall int  x205; (((0<=x205) &&
(x205<x33)) ==> (\old(x32[x205])==x32[x205]))));
assigns x31[(0..x33-1)];
*/
void encode(int  * x30, int  * x31, int  * x32, int  x33) {
  /*@
  loop invariant 0<=x36<=x33;
  loop invariant (\forall int  x37; (((0<=x37) &&
  (x37<x33)) ==> ((0<=x30[x37]) &&
  (x30[x37]<=26))));
  loop invariant (\forall int  x52; (((0<=x52) &&
  (x52<x33)) ==> (\at(x30[x52],Pre)==x30[x52])));
  loop invariant (\forall int  x65; (((0<=x65) &&
  (x65<x33)) ==> (\at(x32[x65],Pre)==x32[x65])));
  loop invariant (\forall int  x78; (((0<=x78) &&
  (x78<x36)) ==> (x31[x78]==cypher(x30[x78]))));
  loop assigns x36, x31[(0..x33-1)];
  loop variant x33-x36;
  */
  for(int x36=0; x36 < x33; x36++) {
    int x95 = x30[x36];
    int x96 = cypher(x95);
    x31[x36] = x96;
    /*@assert (x31[x36]==cypher(x30[x36]));*/
  }
}
/*@
requires ((((((x222>0) &&
\valid(x219+(0..x222-1))) &&
\valid(x220+(0..x222-1))) &&
\valid(x221+(0..x222-1))) &&
(\forall int  x306; (((0<=x306) &&
(x306<x222)) ==> (\forall int  x311; (((0<=x311) &&
(x311<x222)) ==> (\forall int  x316; (((0<=x316) &&
(x316<x222)) ==> ((\separated(x219+x306,x220+x311) &&
\separated(x219+x306,x221+x316)) &&
\separated(x220+x311,x221+x316))))))))) &&
(\forall int  x338; (((0<=x338) &&
(x338<x222)) ==> ((0<=x219[x338]) &&
(x219[x338]<=26)))));
ensures ((((\forall int  x354; (((0<=x354) &&
(x354<x222)) ==> (x220[x354]==decypher(x219[x354])))) &&
(\forall int  x366; (((0<=x366) &&
(x366<x222)) ==> ((0<=x220[x366]) &&
(x220[x366]<=26))))) &&
(\forall int  x381; (((0<=x381) &&
(x381<x222)) ==> (\old(x219[x381])==x219[x381])))) &&
(\forall int  x394; (((0<=x394) &&
(x394<x222)) ==> (\old(x221[x394])==x221[x394]))));
assigns x220[(0..x222-1)];
*/
void decode(int  * x219, int  * x220, int  * x221, int  x222) {
  /*@
  loop invariant 0<=x225<=x222;
  loop invariant (\forall int  x226; (((0<=x226) &&
  (x226<x222)) ==> ((0<=x219[x226]) &&
  (x219[x226]<=26))));
  loop invariant (\forall int  x241; (((0<=x241) &&
  (x241<x222)) ==> (\at(x219[x241],Pre)==x219[x241])));
  loop invariant (\forall int  x254; (((0<=x254) &&
  (x254<x222)) ==> (\at(x221[x254],Pre)==x221[x254])));
  loop invariant (\forall int  x267; (((0<=x267) &&
  (x267<x225)) ==> (x220[x267]==decypher(x219[x267]))));
  loop assigns x225, x220[(0..x222-1)];
  loop variant x222-x225;
  */
  for(int x225=0; x225 < x222; x225++) {
    int x284 = x219[x225];
    int x285 = decypher(x284);
    x220[x225] = x285;
    /*@assert (x220[x225]==decypher(x219[x225]));*/
  }
}
/*@
requires ((((((x411>0) &&
\valid(x408+(0..x411-1))) &&
\valid(x409+(0..x411-1))) &&
\valid(x410+(0..x411-1))) &&
(\forall int  x427; (((0<=x427) &&
(x427<x411)) ==> (\forall int  x432; (((0<=x432) &&
(x432<x411)) ==> (\forall int  x437; (((0<=x437) &&
(x437<x411)) ==> ((\separated(x408+x427,x409+x432) &&
\separated(x408+x427,x410+x437)) &&
\separated(x409+x432,x410+x437))))))))) &&
(\forall int  x459; (((0<=x459) &&
(x459<x411)) ==> ((0<=x408[x459]) &&
(x408[x459]<=26)))));
ensures ((\forall int  x475; (((0<=x475) &&
(x475<x411)) ==> (x410[x475]==x408[x475]))) &&
(\forall int  x486; (((0<=x486) &&
(x486<x411)) ==> (\old(x408[x486])==x408[x486]))));
assigns x409[(0..x411-1)], x410[(0..x411-1)];
*/
void autoencode(int  * x408, int  * x409, int  * x410, int  x411) {
  encode(x408,x409,x410,x411);
  decode(x409,x410,x408,x411);
}
