#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char ime_filma[65];
  char vreme[6];
  int sat;
} Film;

int poredi_filmove(const void *a, const void *b) {
  const Film *fa = (const Film *)a;
  const Film *fb = (const Film *)b;

  return strcmp(fa->vreme, fb->vreme);
}
int main() {
  int n = 5;
  Film *filmovi = malloc(n * sizeof(Film));
  if (!filmovi) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  FILE *f = fopen("bioskop.txt", "r");
  if (!f) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  char ime[65];
  char vreme[6];
  int i;
  for (i = 0; fscanf(f, "%64s %5s", ime, vreme) == 2; i++) {
    if (i == n) {
      n *= 2;
      Film *temp = realloc(filmovi, n * sizeof(Film));
      if (!temp) {
        free(filmovi);
        return EXIT_FAILURE;
      }
      filmovi = temp;
    }

    strcpy(filmovi[i].ime_filma, ime);
    strcpy(filmovi[i].vreme, vreme);
    sscanf(vreme, "%d", &filmovi[i].sat);
  }

  qsort(filmovi, i, sizeof(Film), poredi_filmove);

  for (int j = 0; j < i; j++) {
    printf("%s\n", filmovi[j].ime_filma);
  }

  int trenutni_sat = filmovi[0].sat;
  int brojac = 0;
  for (int j = 1; j < i; j++) {
    if (trenutni_sat != filmovi[j].sat) {
      brojac--;
      if (brojac < 0) {
        trenutni_sat = filmovi[j].sat;
        brojac = 0;
      }
    } else {
      brojac++;
    }
  }

  printf("%d:00\n", trenutni_sat);
  fclose(f);
  free(filmovi);

  return EXIT_SUCCESS;
}
