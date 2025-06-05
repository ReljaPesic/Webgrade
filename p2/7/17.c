#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int n = strlen(argv[1]);
  if (n == 0) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < n; i++) {
    char c = argv[1][i];

    for (int j = 0; j <= i; j++) {
      putchar(c);
    }
  }
  printf("\n");
  return EXIT_SUCCESS;
}
