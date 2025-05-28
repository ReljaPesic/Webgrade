#include <stdio.h>
#include <stdlib.h>

void svaka_n_ta(char *ime, int n) {
  FILE *f = fopen(ime, "r");
  if (!f) {
    fprintf(stderr, "-1\n");
    return;
  }
  char rec[51];
  int counter = 0;
  while (fscanf(f, "%50s", rec) == 1) {
    counter++;
    if (counter % n == 0) {
      printf("%s ", rec);
    }
  }
  printf("\n");
}
int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  char *ime_fajla = argv[1];
  int n = atoi(argv[2]);
  if (n <= 0) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  svaka_n_ta(ime_fajla, n);
  return EXIT_SUCCESS;
}
