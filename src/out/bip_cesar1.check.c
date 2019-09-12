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
/*@ logic integer decypher(int  x11) = (((x11==0)) ? (26) : ((x11-1)));*/
/*@
requires ((0<=x11) &&
(x11<=26));
assigns \nothing;
ensures ((0<=\result) &&
(\result<=26));
ensures \result == decypher(x11);
*/
int decypher(int  x11) {
  int x13 = x11 == 0;
  int x15;
  if (x13) {
    x15 = 26;
  } else {
    int x14 = x11 - 1;
    x15 = x14;
  }
  return x15;
}
/*@
requires ((((((x25>0) &&
\valid(x22+(0..x25-1))) &&
\valid(x23+(0..x25-1))) &&
\valid(x24+(0..x25-1))) &&
(\forall int  x88; (((0<=x88) &&
(x88<x25)) ==> (\forall int  x92; (((0<=x92) &&
(x92<x25)) ==> (\forall int  x96; (((0<=x96) &&
(x96<x25)) ==> ((\separated(x22+x88,x23+x92) &&
\separated(x22+x88,x24+x96)) &&
\separated(x23+x92,x24+x96))))))))) &&
(\forall int  x114; (((0<=x114) &&
(x114<x25)) ==> ((0<=x22[x114]) &&
(x22[x114]<=26)))));
ensures ((((\forall int  x126; (((0<=x126) &&
(x126<x25)) ==> (x23[x126]==cypher(x22[x126])))) &&
(\forall int  x137; (((0<=x137) &&
(x137<x25)) ==> ((0<=x23[x137]) &&
(x23[x137]<=26))))) &&
(\forall int  x149; (((0<=x149) &&
(x149<x25)) ==> (\old(x22[x149])==x22[x149])))) &&
(\forall int  x159; (((0<=x159) &&
(x159<x25)) ==> (\old(x24[x159])==x24[x159]))));
assigns x23[(0..x25-1)];
*/
void encode(int  * x22, int  * x23, int  * x24, int  x25) {
  /*@
  loop invariant 0<=x28<=x25;
  loop invariant (\forall int  x29; (((0<=x29) &&
  (x29<x25)) ==> ((0<=x22[x29]) &&
  (x22[x29]<=26))));
  loop invariant (\forall int  x39; (((0<=x39) &&
  (x39<x25)) ==> (\at(x22[x39],Pre)==x22[x39])));
  loop invariant (\forall int  x48; (((0<=x48) &&
  (x48<x25)) ==> (\at(x24[x48],Pre)==x24[x48])));
  loop invariant (\forall int  x57; (((0<=x57) &&
  (x57<x28)) ==> (x23[x57]==cypher(x22[x57]))));
  loop assigns x28, x23[(0..x25-1)];
  loop variant x25-x28;
  */
  for(int x28=0; x28 < x25; x28++) {
    int x72 = cypher(x71);
    x23[x28] = x72;
    /*@assert (x23[x28]==x72);*/
  }
}
/*@
requires ((((((x172>0) &&
\valid(x169+(0..x172-1))) &&
\valid(x170+(0..x172-1))) &&
\valid(x171+(0..x172-1))) &&
(\forall int  x235; (((0<=x235) &&
(x235<x172)) ==> (\forall int  x239; (((0<=x239) &&
(x239<x172)) ==> (\forall int  x243; (((0<=x243) &&
(x243<x172)) ==> ((\separated(x169+x235,x170+x239) &&
\separated(x169+x235,x171+x243)) &&
\separated(x170+x239,x171+x243))))))))) &&
(\forall int  x261; (((0<=x261) &&
(x261<x172)) ==> ((0<=x169[x261]) &&
(x169[x261]<=26)))));
ensures ((((\forall int  x273; (((0<=x273) &&
(x273<x172)) ==> (x170[x273]==decypher(x169[x273])))) &&
(\forall int  x284; (((0<=x284) &&
(x284<x172)) ==> ((0<=x170[x284]) &&
(x170[x284]<=26))))) &&
(\forall int  x296; (((0<=x296) &&
(x296<x172)) ==> (\old(x169[x296])==x169[x296])))) &&
(\forall int  x306; (((0<=x306) &&
(x306<x172)) ==> (\old(x171[x306])==x171[x306]))));
assigns x170[(0..x172-1)];
*/
void decode(int  * x169, int  * x170, int  * x171, int  x172) {
  /*@
  loop invariant 0<=x175<=x172;
  loop invariant (\forall int  x176; (((0<=x176) &&
  (x176<x172)) ==> ((0<=x169[x176]) &&
  (x169[x176]<=26))));
  loop invariant (\forall int  x186; (((0<=x186) &&
  (x186<x172)) ==> (\at(x169[x186],Pre)==x169[x186])));
  loop invariant (\forall int  x195; (((0<=x195) &&
  (x195<x172)) ==> (\at(x171[x195],Pre)==x171[x195])));
  loop invariant (\forall int  x204; (((0<=x204) &&
  (x204<x175)) ==> (x170[x204]==decypher(x169[x204]))));
  loop assigns x175, x170[(0..x172-1)];
  loop variant x172-x175;
  */
  for(int x175=0; x175 < x172; x175++) {
    int x219 = decypher(x218);
    x170[x175] = x219;
    /*@assert (x170[x175]==x219);*/
  }
}
/*@
requires ((((((x319>0) &&
\valid(x316+(0..x319-1))) &&
\valid(x317+(0..x319-1))) &&
\valid(x318+(0..x319-1))) &&
(\forall int  x332; (((0<=x332) &&
(x332<x319)) ==> (\forall int  x336; (((0<=x336) &&
(x336<x319)) ==> (\forall int  x340; (((0<=x340) &&
(x340<x319)) ==> ((\separated(x316+x332,x317+x336) &&
\separated(x316+x332,x318+x340)) &&
\separated(x317+x336,x318+x340))))))))) &&
(\forall int  x359; (((0<=x359) &&
(x359<x319)) ==> ((0<=x316[x359]) &&
(x316[x359]<=26)))));
ensures ((\forall int  x371; (((0<=x371) &&
(x371<x319)) ==> (x318[x371]==x316[x371]))) &&
(\forall int  x381; (((0<=x381) &&
(x381<x319)) ==> (\old(x316[x381])==x316[x381]))));
assigns x317[(0..x319-1)], x318[(0..x319-1)];
*/
void autoencode(int  * x316, int  * x317, int  * x318, int  x319) {
  encode(x316,x317,x318,x319);
  decode(x317,x318,x316,x319);
}
