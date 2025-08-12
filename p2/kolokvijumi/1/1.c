#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  int k = atoi(argv[1]), l = atoi(argv[2]);
  if (k < 2 || l < k || l > 10000) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  for (int i = k; i <= l; i++) {
    int is_prime = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return EXIT_SUCCESS;
}
