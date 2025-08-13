#include <stdio.h>
#include <stdlib.h>

int suma_cifara(int n) {
  int suma = 0;
  while (n > 0) {
    suma += n % 10;
    n /= 10;
  }
  return suma;
}
int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  if (a > b || a < 0 || b > 10000) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  int suma = 0;
  for (int i = a; i <= b; i++) {
    suma += suma_cifara(i);
  }
  printf("%d\n", suma);
  return EXIT_SUCCESS;
}
