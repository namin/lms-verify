/*@ ensures \result==x*x;
*/
int square(int x) { return x*x; }

/*@ ensures \result==x*x*x*x;
*/
int pow4(int x) { return square(square(x)); }

/*@ ensures \result==x*x*x*x;
*/
int pow4b(int x) { return square(x)*square(x); }
