#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int **matrica;

  FILE *f = fopen("matrica.txt", "r");
  if (!f) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  fscanf(f, "%d", &n);
  matrica = malloc(n * sizeof(int *));
  if (!matrica) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  for (int i = 0; i < n; i++) {
    matrica[i] = malloc(n * sizeof(int));
    if (!matrica[i]) {
      fprintf(stderr, "-1\n");
      return EXIT_FAILURE;
    }
  }

  int is_neopadajuc = 1;
  for (int i = 0; i < n; i++) {
    is_neopadajuc = 1;
    for (int j = 0; j < n; j++) {
      fscanf(f, "%d", &matrica[i][j]);
      if (j == 0) {
        continue;
      }
      if (matrica[i][j - 1] > matrica[i][j]) {
        is_neopadajuc = 0;
      }
    }
    if (is_neopadajuc) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return EXIT_SUCCESS;
}
