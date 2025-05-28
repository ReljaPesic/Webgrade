#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

int veci_od_proseka() {
  int suma = 0, count = 0;

  int arraySize = INITIAL_CAPACITY;
  int *niz = malloc(arraySize * sizeof(int));
  if (!niz) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int x;
  while (scanf("%d", &x) == 1 && x != 0) {
    // extend array size
    if (count == arraySize) {
      arraySize *= 2;
      int *temp = realloc(niz, arraySize * sizeof(int));
      if (!temp) {
        free(niz);
        fprintf(stderr, "-1\n");
        return EXIT_FAILURE;
      }
      niz = temp;
    }
    niz[count++] = x;
    suma += x;
  }
  if (count == 0) {
    free(niz);
    return count;
  }

  // imas niz ovde
  double prosek = 1.0 * suma / count;

  int how_many_greater = 0;
  for (int i = 0; i < count; i++) {
    if (niz[i] > prosek) {
      how_many_greater++;
    }
  }

  free(niz);
  return how_many_greater;
}

int main(void) {
  printf("%d\n", veci_od_proseka());
  return EXIT_SUCCESS;
}
