#include <stdio.h>
#include <stdlib.h>

int izmeni(int n) {
  if (abs(n) < 10) {
    return (n % 2 == 0 ? n / 2 : n);
  }
  int poslednja_cifra = n % 10;
  if (poslednja_cifra % 2 != 0) {
    return izmeni(n / 10) * 10 + poslednja_cifra;
  } else {
    return izmeni(n / 10) * 10 + poslednja_cifra / 2;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "-1\n");
    return 1;
  }

  int broj = atoi(argv[1]);
  int result = izmeni(broj);

  printf("%d\n", result);

  return EXIT_SUCCESS;
}
