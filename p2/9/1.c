#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char ime[21];
  int brojKoeficijenata;
  float *koeficijenti;
  double vrednostUX;
} Polinom;

int porediPolinome(const void *a, const void *b) {
  const Polinom *pa = (const Polinom *)a;
  const Polinom *pb = (const Polinom *)b;

  if (pa->vrednostUX < pb->vrednostUX) {
    return 1;
  }
  if (pa->vrednostUX > pb->vrednostUX) {
    return -1;
  }
  return 0;
}
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int x = atoi(argv[1]);

  FILE *f = fopen("polinomi.txt", "r");
  if (!f) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int n;
  fscanf(f, "%d", &n);

  Polinom *polinomi = malloc(n * sizeof(Polinom));

  if (!polinomi) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < n; i++) {
    fscanf(f, "%s %d", polinomi[i].ime, &polinomi[i].brojKoeficijenata);

    polinomi[i].koeficijenti =
        malloc(polinomi[i].brojKoeficijenata * sizeof(float));
    if (!polinomi[i].koeficijenti) {
      fprintf(stderr, "-1\n");
      return EXIT_FAILURE;
    }

    double vrednost = 0;
    for (int j = 0; j < polinomi[i].brojKoeficijenata; j++) {
      fscanf(f, "%f", &polinomi[i].koeficijenti[j]);

      vrednost += polinomi[i].koeficijenti[j] * pow(x, j);
    }

    polinomi[i].vrednostUX = vrednost;
  }

  qsort(polinomi, n, sizeof(Polinom), porediPolinome);
  for (int i = 0; i < n; i++) {
    printf("%s %.2lf\n", polinomi[i].ime, polinomi[i].vrednostUX);
  }

  for (int i = 0; i < n; i++) {
    free(polinomi[i].koeficijenti);
  }
  free(polinomi);
  fclose(f);
  return EXIT_SUCCESS;
}
