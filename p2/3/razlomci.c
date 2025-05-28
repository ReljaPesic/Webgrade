#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int brojilac;
  int imenilac;
} Fraction;

typedef enum { OPTION_X, OPTION_Y, OPTION_XY, INVALID_OPTION } Option;

Option get_option(char *option) {
  if (strcmp(option, "-x") == 0) {
    return OPTION_X;
  } else if (strcmp(option, "-y") == 0) {
    return OPTION_Y;
  } else if (strcmp(option, "-xy") == 0 || strcmp(option, "-yx") == 0) {
    return OPTION_XY;
  } else {
    return INVALID_OPTION;
  }
}

bool read_from_file(FILE *file, Fraction **fractions, int *n);
void write_reciprocnu(FILE *fout, Fraction *fractions, int n);
bool write_real(FILE *fout, Fraction *fractions, int n);
bool write_both(FILE *fout, Fraction *fractions, int n);

int main(int argc, char *argv[]) {

  if (argc != 4) {
    fprintf(stderr, "-1\n");
    return 1;
  }

  // open file 1
  FILE *fin = fopen(argv[1], "r");
  if (!fin) {
    fprintf(stderr, "-1\n");
    return 1;
  }

  // open file 2
  FILE *fout = fopen(argv[2], "w");
  if (!fout) {
    fprintf(stderr, "-1\n");
    return 1;
  }

  Fraction *fractions;
  int n;
  if (!read_from_file(fin, &fractions, &n)) {
    fprintf(stderr, "-1\n");
    return 1;
  }
  fclose(fin);

  char *option = argv[3];
  Option opt = get_option(option);

  switch (opt) {
  case OPTION_X:
    write_reciprocnu(fout, fractions, n);
    break;

  case OPTION_Y:
    if (!write_real(fout, fractions, n)) {
      fprintf(stderr, "-1\n");
      return 1;
    }
    break;

  case OPTION_XY:
    if (!write_both(fout, fractions, n)) {
      fprintf(stderr, "-1\n");
      return 1;
    }
    break;

  case INVALID_OPTION:
    fprintf(stderr, "-1\n");
    break;

  default:
    break;
  }
  fclose(fout);
  free(fractions);

  return 0;
}

bool read_from_file(FILE *fin, Fraction **fractions, int *n) {
  int num;
  if (fscanf(fin, "%d", &num) != 1) {
    return false;
  }

  *fractions = malloc(num * sizeof(Fraction));
  if (*fractions == NULL) {
    return false;
  }

  for (int i = 0; i < num; i++) {
    if (fscanf(fin, "%d/%d", &(*fractions)[i].brojilac,
               &(*fractions)[i].imenilac) != 2) {
      fprintf(stderr, "-1\n");
      free(*fractions);
      *fractions = NULL;
      return false;
    }
  }
  *n = num;
  return true;
}
void write_reciprocnu(FILE *fout, Fraction *fractions, int n) {
  for (int i = 0; i < n; i++) {
    int brojilac = fractions[i].brojilac;
    int imenilac = fractions[i].imenilac;

    // oba poz ili oba neg
    if ((brojilac < 0 && imenilac < 0) || (brojilac >= 0 && imenilac >= 0)) {
      fprintf(fout, "%d/%d\n", abs(imenilac), abs(brojilac));
    } else {
      fprintf(fout, "-%d/%d\n", abs(imenilac), abs(brojilac));
    }
  }
}

bool write_real(FILE *fout, Fraction *fractions, int n) {
  for (int i = 0; i < n; i++) {
    int brojilac = fractions[i].brojilac;
    int imenilac = fractions[i].imenilac;

    if (brojilac == 0) {
      return false;
    }
    double rez = imenilac * 1.0 / brojilac;
    fprintf(fout, "%.6g\n", rez);
  }
  return true;
}

bool write_both(FILE *fout, Fraction *fractions, int n) {
  for (int i = 0; i < n; i++) {
    int brojilac = fractions[i].brojilac;
    int imenilac = fractions[i].imenilac;

    // oba poz ili oba neg
    if ((brojilac < 0 && imenilac < 0) || (brojilac >= 0 && imenilac >= 0)) {
      fprintf(fout, "%d/%d ", abs(imenilac), abs(brojilac));
    } else {
      fprintf(fout, "-%d/%d ", abs(imenilac), abs(brojilac));
    }

    if (brojilac == 0) {
      return false;
    }
    double rez = imenilac * 1.0 / brojilac;
    fprintf(fout, "%.6g\n", rez);
  }
  return true;
}
