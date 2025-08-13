#include <stdio.h>
#include <stdlib.h>

void f3(int *a, int na) {
  if (na < 1) {
    return;
  }
  if (na > 1 && a[0] % 2 == 0 && a[1] % 2 == 0) {
    a[0]--;
  }
  printf("%d ", a[0]);
  f3(a + 1, na - 1);
}
int main() {
  int n;
  scanf("%d", &n);
  if (n < 1 || n > 1000) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  int a[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  f3(a, n);
  printf("\n");
  return EXIT_SUCCESS;
}
