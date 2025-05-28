#include <stdio.h>
#include <stdlib.h>

void f11(int *a, int n, int x) {
  if (n == 0) {
    return;
  }
  if (a[n - 1] + a[n - 2] == x) {
    a[n - 1] = 0;
    f11(a, n - 1, x);
    a[n - 2] = 0;
  }
  f11(a, n - 1, x);
}
int main(void) {
  int x, n;
  scanf("%d%d", &x, &n);
  if (n <= 0) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  int a[n + 1];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  f11(a, n, x);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
