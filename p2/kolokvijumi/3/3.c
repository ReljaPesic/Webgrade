#include <stdio.h>
#include <stdlib.h>

void f3(int *a, int na, int suma_prethodnih) {
  for (int i = 0; i < na; i++) {
    if (a[i] > suma_prethodnih) {
      printf("0 ");
    } else {
      printf("%d ", a[i]);
    }
    suma_prethodnih += a[i];
  }
  printf("\n");
}
int main() {
  int na;
  scanf("%d", &na);
  if (na <= 0) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  int a[na];
  for (int i = 0; i < na; i++) {
    if (scanf("%d", &a[i]) != 1) {
      fprintf(stderr, "-1\n");
      return EXIT_FAILURE;
    }
  }
  f3(a, na, 0);
  return EXIT_SUCCESS;
}
