#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *u1 = fopen("u1.txt", "r");
  FILE *u2 = fopen("u2.txt", "r");
  if (!u1 || !u2) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  FILE *o = fopen("i.txt", "w");
  if (!o) {
    fclose(u1);
    fclose(u2);
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int n1, n2;
  if (fscanf(u1, "%d", &n1) != 1 || n1 < 1 || fscanf(u2, "%d", &n2) != 1 ||
      n2 < 1) {
    fclose(u1);
    fclose(u2);
    fclose(o);
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  char rec1[51], rec2[51];
  for (int i = 0, j = 0; i < n1 || j < n2; i++, j++) {
    if (fscanf(u1, "%50s", rec1) == 1) {
      fprintf(o, "%s ", rec1);
    }
    if (fscanf(u2, "%50s", rec2) == 1) {
      fprintf(o, "%s ", rec2);
    }
  }

  fclose(u1);
  fclose(u2);
  fclose(o);
  return EXIT_SUCCESS;
}
