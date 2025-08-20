#include <stdio.h>
#include <stdlib.h>

#define MIN_VALUE -1000000
#define MAX_VALUE 1000000

int main(int argc, char **argv) {
  if (argc == 1) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int niz[argc - 1];
  for (int i = 1; i < argc; i++) {
    sscanf(argv[i], "%d", &niz[i - 1]);
  }

  int a = MAX_VALUE;
  int b = MIN_VALUE;
  int c = 0;
  for (int i = 0; i < argc - 1; i++) {
    if (niz[i] < a) {
      a = niz[i];
    }
    if (niz[i] > b) {
      b = niz[i];
    }
    c += niz[i];
  }
  c /= argc - 1;

  int prag = (a + b + c) / 3;
  for (int i = 0; i < argc - 1; i++) {
    if (niz[i] > prag) {
      printf("%d ", niz[i]);
    }
  }
  printf("\n");
  return EXIT_SUCCESS;
}
