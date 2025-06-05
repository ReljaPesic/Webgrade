#include <stdio.h>
#include <stdlib.h>

int f14(int x) {
  if (x < 100) {
    return x;
  }

  int desni = x % 10;
  int levi = (x / 100) % 10;
  int srednji = (x / 10) % 10;
  if (levi + desni == srednji) {
    return f14(x / 100) * 10 + desni;
  } else {
    return f14(x / 10) * 10 + desni;
  }
}
int main(void) {
  int x;
  scanf("%d", &x);
  if (x < 0) {
    printf("-%d\n", f14(abs(x)));
  } else {
    printf("%d\n", f14(x));
  }
  return EXIT_SUCCESS;
}
