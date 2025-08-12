#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_ARRAY_SIZE 10

typedef struct {
  double x;
  double y;
} Tacka;

bool dominira(const Tacka *a, const Tacka *b) {
  return a->x >= b->x && a->y >= b->y;
}

bool maksimalna_tacka(const Tacka *tacke, int n, int index) {
  for (int i = 0; i < n; i++) {
    if (i != index && dominira(&tacke[i], &tacke[index])) {
      return false;
    }
  }
  return true;
}

int poredi_tacke(const void *a, const void *b) {
  const Tacka *ta = (const Tacka *)a;
  const Tacka *tb = (const Tacka *)b;

  return ta->x < tb->x ? 1 : -1; // Sortiraj po x opadajuće
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  FILE *f = fopen(argv[1], "r");
  if (!f) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  Tacka *tacke = malloc(INITIAL_ARRAY_SIZE * sizeof(Tacka));
  if (!tacke) {
    fclose(f);
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int i;
  int capacity = INITIAL_ARRAY_SIZE;
  for (i = 0;; i++) {
    if (i >= capacity) {
      capacity = 2 * capacity;
      Tacka *temp = realloc(tacke, capacity * sizeof(Tacka));
      if (!temp) {
        free(tacke);
        fclose(f);
        fprintf(stderr, "-1\n");
        return EXIT_FAILURE;
      }
      tacke = temp;
    }
    if (fscanf(f, "%lf %lf", &tacke[i].x, &tacke[i].y) != 2) {
      break;
    }
  }

  fclose(f);
  int n = i; // Broj ucitanih tacaka
  Tacka *maksimalne_tacke = malloc(n * sizeof(Tacka));
  if (!maksimalne_tacke) {
    free(tacke);
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  // prolazis kroz sve tacke i proveravas da li je maksimalna
  int j;
  for (i = 0, j = 0; i < n; i++) {
    if (maksimalna_tacka(tacke, n, i)) {
      maksimalne_tacke[j++] = tacke[i];
    }
  }

  free(tacke);
  qsort(maksimalne_tacke, j, sizeof(Tacka), poredi_tacke);
  for (int i = 0; i < j; i++) {
    fprintf(stdout, "%.2lf %.2lf\n", maksimalne_tacke[i].x,
            maksimalne_tacke[i].y);
  }
  free(maksimalne_tacke);
  return 0;
}
