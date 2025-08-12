#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  char rec[51];

  FILE *r = fopen("r.txt", "r");
  FILE *b = fopen("b.txt", "w");
  FILE *o = fopen("o.txt", "w");
  if (!r || !b || !o) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  if (fscanf(r, "%d", &n) != 1 || n < 1) {
    fclose(r);
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < n; i++) {
    if (fscanf(r, "%50s", rec) != 1) {
      fclose(r);
      fprintf(stderr, "-1\n");
      return EXIT_FAILURE;
    }
    char *endptr;
    long broj = strtol(rec, &endptr, 10);
    if (*endptr != '\0') {
      fprintf(o, "%s ", rec);
    } else {
      fprintf(b, "%s ", rec);
    }
  }
  fclose(r);
  fclose(b);
  fclose(o);
  return EXIT_SUCCESS;
}
