#include <stdio.h>
#include <stdlib.h>

void f12(int *a, int n) {
  if (n == 0) {
    return;
  }
  if (a[n] == a[n - 1] + a[n + 1]) {
    f12(a, n - 1);
    a[n] = 0;
  } else {
    f12(a, n - 1);
  }
}
int main(void) {
  int n;
  scanf("%d", &n);
  if (n < 1) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  if (n > 2) {
    f12(a, n - 2);
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
  return EXIT_SUCCESS;
}
