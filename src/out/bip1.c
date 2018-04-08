#include <string.h>

/*@
logic integer d(integer c) = (0 <= c - '0' <= 9) ? c - '0' : -1;
logic integer e(integer i) = (0 <= i <= 9) ? i + '0' : ' ';
*/

/*@
assigns \nothing;
ensures -1<=\result<=9;
ensures d(c)==\result;
*/
int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}

/*@
assigns \nothing;
ensures '0'<=\result<='9' || \result==' ';
ensures e(i)==\result;
*/
char e(int i) {
  return (0 <= i && i <= 9) ? i + '0' : ' ';
}

/*@
assigns \nothing;
ensures '0'<=c<='9' ==> \result==c;
ensures c!=\result ==> \result==' ';
ensures e(d(c))==\result;
*/
char ed(char c) {
  return e(d(c));
}

/*@
assigns \nothing;
ensures 0<=i<=9 ==> \result==i;
ensures i!=\result ==> \result==-1;
ensures d(e(i))==\result;
*/
int de(int i) {
  return d(e(i));
}

/*@
assigns \nothing;
ensures d(e(d(c)))==d(c);
*/
int ded(char c) {
  return d(e(d(c)));
}

/*@
assigns \nothing;
ensures e(d(e(i)))==e(i);
*/
char ede(int i) {
  return e(d(e(i)));
}
