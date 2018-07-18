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
(\forall int  x116; (((0<=x116) &&
(x116<x33)) ==> (\forall int  x121; (((0<=x121) &&
(x121<x33)) ==> (\forall int  x126; (((0<=x126) &&
(x126<x33)) ==> ((\separated(x30+x116,x31+x121) &&
\separated(x30+x116,x32+x126)) &&
\separated(x31+x121,x32+x126))))))))) &&
(\forall int  x148; (((0<=x148) &&
(x148<x33)) ==> ((0<=x30[x148]) &&
(x30[x148]<=26)))));
ensures ((((\forall int  x163; (((0<=x163) &&
(x163<x33)) ==> (x31[x163]==cypher(x30[x163])))) &&
(\forall int  x175; (((0<=x175) &&
(x175<x33)) ==> ((0<=x31[x175]) &&
(x31[x175]<=26))))) &&
(\forall int  x189; (((0<=x189) &&
(x189<x33)) ==> (\old(x30[x189])==x30[x189])))) &&
(\forall int  x202; (((0<=x202) &&
(x202<x33)) ==> (\old(x32[x202])==x32[x202]))));
assigns x31[(0..x33-1)];
*/
void encode(int  * x30, int  * x31, int  * x32, int  x33) {
  /*@
  loop invariant 0<=x36<=x33;
  loop invariant (\forall int  x37; (((0<=x37) &&
  (x37<x33)) ==> ((0<=x30[x37]) &&
  (x30[x37]<=26))));
  loop invariant (\forall int  x51; (((0<=x51) &&
  (x51<x33)) ==> (\at(x30[x51],Pre)==x30[x51])));
  loop invariant (\forall int  x64; (((0<=x64) &&
  (x64<x33)) ==> (\at(x32[x64],Pre)==x32[x64])));
  loop invariant (\forall int  x77; (((0<=x77) &&
  (x77<x36)) ==> (x31[x77]==cypher(x30[x77]))));
  loop assigns x36, x31[(0..x33-1)];
  loop variant x33-x36;
  */
  for(int x36=0; x36 < x33; x36++) {
    int x94 = x30[x36];
    int x95 = cypher(x94);
    x31[x36] = x95;
    /*@assert (x31[x36]==cypher(x30[x36]));*/
  }
}
/*@
requires ((((((x219>0) &&
\valid(x216+(0..x219-1))) &&
\valid(x217+(0..x219-1))) &&
\valid(x218+(0..x219-1))) &&
(\forall int  x302; (((0<=x302) &&
(x302<x219)) ==> (\forall int  x307; (((0<=x307) &&
(x307<x219)) ==> (\forall int  x312; (((0<=x312) &&
(x312<x219)) ==> ((\separated(x216+x302,x217+x307) &&
\separated(x216+x302,x218+x312)) &&
\separated(x217+x307,x218+x312))))))))) &&
(\forall int  x334; (((0<=x334) &&
(x334<x219)) ==> ((0<=x216[x334]) &&
(x216[x334]<=26)))));
ensures ((((\forall int  x349; (((0<=x349) &&
(x349<x219)) ==> (x217[x349]==decypher(x216[x349])))) &&
(\forall int  x361; (((0<=x361) &&
(x361<x219)) ==> ((0<=x217[x361]) &&
(x217[x361]<=26))))) &&
(\forall int  x375; (((0<=x375) &&
(x375<x219)) ==> (\old(x216[x375])==x216[x375])))) &&
(\forall int  x388; (((0<=x388) &&
(x388<x219)) ==> (\old(x218[x388])==x218[x388]))));
assigns x217[(0..x219-1)];
*/
void decode(int  * x216, int  * x217, int  * x218, int  x219) {
  /*@
  loop invariant 0<=x222<=x219;
  loop invariant (\forall int  x223; (((0<=x223) &&
  (x223<x219)) ==> ((0<=x216[x223]) &&
  (x216[x223]<=26))));
  loop invariant (\forall int  x237; (((0<=x237) &&
  (x237<x219)) ==> (\at(x216[x237],Pre)==x216[x237])));
  loop invariant (\forall int  x250; (((0<=x250) &&
  (x250<x219)) ==> (\at(x218[x250],Pre)==x218[x250])));
  loop invariant (\forall int  x263; (((0<=x263) &&
  (x263<x222)) ==> (x217[x263]==decypher(x216[x263]))));
  loop assigns x222, x217[(0..x219-1)];
  loop variant x219-x222;
  */
  for(int x222=0; x222 < x219; x222++) {
    int x280 = x216[x222];
    int x281 = decypher(x280);
    x217[x222] = x281;
    /*@assert (x217[x222]==decypher(x216[x222]));*/
  }
}
/*@
requires ((((((x405>0) &&
\valid(x402+(0..x405-1))) &&
\valid(x403+(0..x405-1))) &&
\valid(x404+(0..x405-1))) &&
(\forall int  x421; (((0<=x421) &&
(x421<x405)) ==> (\forall int  x426; (((0<=x426) &&
(x426<x405)) ==> (\forall int  x431; (((0<=x431) &&
(x431<x405)) ==> ((\separated(x402+x421,x403+x426) &&
\separated(x402+x421,x404+x431)) &&
\separated(x403+x426,x404+x431))))))))) &&
(\forall int  x453; (((0<=x453) &&
(x453<x405)) ==> ((0<=x402[x453]) &&
(x402[x453]<=26)))));
ensures ((\forall int  x468; (((0<=x468) &&
(x468<x405)) ==> (x404[x468]==x402[x468]))) &&
(\forall int  x479; (((0<=x479) &&
(x479<x405)) ==> (\old(x402[x479])==x402[x479]))));
assigns x403[(0..x405-1)], x404[(0..x405-1)];
*/
void autoencode(int  * x402, int  * x403, int  * x404, int  x405) {
  encode(x402,x403,x404,x405);
  decode(x403,x404,x402,x405);
}
