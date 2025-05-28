#include <stdio.h>
#include <stdlib.h>

int maksimum_niza(int *a, int n);

int main() {
  int velicina_niza;
  if (scanf("%d", &velicina_niza) != 1 || velicina_niza <= 0) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int *niz = (int *)malloc(velicina_niza * sizeof(int));
  if (niz == NULL) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < velicina_niza; i++)
    scanf("%d", &niz[i]);

  int max_niza = maksimum_niza(niz, velicina_niza);
  printf("%d\n", max_niza);

  free(niz);

  return 0;
}

int maksimum_niza(int *a, int n) {
  if (n == 1) {
    return a[0];
  }

  int max_ostatka = maksimum_niza(a, n - 1);
  return (a[n - 1] > max_ostatka) ? a[n - 1] : max_ostatka;
}
