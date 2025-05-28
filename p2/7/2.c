#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char barkod[21];
  char imeArtikla[31];
  char proizvodjac[31];
  double cena;
} Artikal;

int porediArtikle(const void *a, const void *b) {
  const Artikal *artikal = (const Artikal *)a;
  const char *barkod = (const char *)b;
  return strcmp(artikal->barkod, barkod);
}

int main() {
  char imeFajla[21];
  scanf("%20s", imeFajla);

  FILE *file = fopen(imeFajla, "r");
  if (!file) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  size_t arraySize = 10, count = 0;
  Artikal *artikli = malloc(arraySize * sizeof(Artikal));
  if (!artikli) {
    fprintf(stderr, "-1\n");
    fclose(file);
    return EXIT_FAILURE;
  }
  while (fscanf(file, "%s %s %s %lf", artikli[count].barkod,
                artikli[count].imeArtikla, artikli[count].proizvodjac,
                &artikli[count].cena) == 4) {
    count++;

    if (count == arraySize) {
      arraySize *= 2;
      Artikal *temp = realloc(artikli, arraySize * sizeof(Artikal));
      if (!temp) {
        perror("-1\n");
        free(artikli);
        fclose(file);
        return EXIT_FAILURE;
      }
      artikli = temp;
    }
  }

  char barkod[21];
  double cena = 0;
  while (scanf("%s", barkod) == 1) {
    if (strcmp(barkod, "0") == 0) {
      break;
    }

    Artikal *pronadjeniElem =
        bsearch(barkod, artikli, count, sizeof(Artikal), porediArtikle);
    if (!pronadjeniElem) {
      printf("Nepostojeci bar kod\n");
      continue;
    }
    cena += pronadjeniElem->cena;
  }

  printf("%.15g\n", cena);

  free(artikli);
  fclose(file);
  return EXIT_SUCCESS;
}
