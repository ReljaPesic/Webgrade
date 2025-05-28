#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char id[21];
  int iznos;
} Korisnik;
int main(void) {
  char id[21];
  int iznos;

  int n = 1;
  Korisnik *korisnici = malloc(n * sizeof(Korisnik));
  if (!korisnici) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  FILE *f = fopen("saldo.txt", "r");
  if (!f) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int i = 0;
  int broj_neg = 0;
  double zaduzenje = 0;
  while (fscanf(f, "%s %d", id, &iznos) == 2) {
    if (i == n) {
      n *= 2;
      Korisnik *temp = realloc(korisnici, n * sizeof(Korisnik));
      if (!temp) {
        fprintf(stderr, "-1\n");
        free(korisnici);
        return EXIT_FAILURE;
      }
      korisnici = temp;
    }

    if (iznos < 0) {
      broj_neg++;
      zaduzenje += iznos;
    }

    strcpy(korisnici[i].id, id);
    korisnici[i].iznos = iznos;

    i++;
  }

  double prosek = zaduzenje / broj_neg;
  for (int j = 0; j < i; j++) {
    if (korisnici[j].iznos < prosek) {
      printf("%s\n", korisnici[j].id);
    }
  }

  return EXIT_SUCCESS;
}
