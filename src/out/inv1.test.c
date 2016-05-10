#include <stdio.h>
int main(void) {
  int n1 = 3;
  int a1[] = {1, 2, 3};
  int* v1 = a1;
  //@assert inv_vec_Int(v1, n1);
  int n2 = 3;
  int a2[] = {1, 2, 4};
  int* v2 = a2;
  //@assert inv_vec_Int(v2, n2);
  int n3 = 1;
  int a3[] = {1};
  int* v3 = a3;
  //@assert inv_vec_Int(v3, n3);
  int nv1 = 3;
  int* av1[] = {v1, v2, v3};
  int** vv1 =  av1;
  int an1[] = {n1, n2, n3};
  int* vn1 = an1;
  //@assert inv_vec_vec_Int(vv1, vn1, nv1);
  int nv2 = 3;
  int* av2[] = {v1, v1, v1};
  int** vv2 = av2;
  int an2[] = {n1, n1, n1};
  int* vn2 = an2;
  //@assert inv_vec_vec_Int(vv2, vn2, nv2);
  printf("1 == %d\n", eq_vec_Int(v1, n1, v1, n1));
  printf("0 == %d\n", eq_vec_Int(v1, n1, v2, n2));
  printf("0 == %d\n", eq_vec_Int(v1, n1, v3, n3));
  printf("1 == %d\n", eq_vec_vec_Int(vv1, vn1, nv1, vv1, vn1, nv1));
  // very strange that this assert is needed!
  //@assert inv_vec_vec_Int(vv2, vn2, nv2);
  printf("0 == %d\n", eq_vec_vec_Int(vv1, vn1, nv1, vv2, vn2, nv2));
}
