#include <stdio.h>
#include <stdlib.h>

int is_odd(int x) { return x % 2 != 0; }

int f16(int *a, int n) {
  if (n < 0) {
    return 1;
  }
  if (is_odd(a[n])) {
    return a[n] * f16(a, n - 1);
  } else {
    return f16(a, n - 1);
  }
}

int main() {
  int n;
  if (scanf("%d", &n) != 1 || n < 0) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int *a = malloc(n * sizeof(int));
  if (!a) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int svi_parni = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (is_odd(a[i])) {
      svi_parni = 0;
    }
  }
  if (svi_parni) {
    printf("-\n");
    return EXIT_SUCCESS;
  }

  int rez = f16(a, n - 1);
  printf("%d\n", rez);

  free(a);
  return EXIT_SUCCESS;
}
