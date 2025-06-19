#include <stdio.h>
#include <stdlib.h>

void ispisiBinarno(unsigned x) {
  for (int i = 31; i >= 0; i--) {
    printf("%u", (x >> i) & 1);

    if (i % 4 == 0) {
      printf(" ");
    }
  }
  printf("\n");
}

unsigned invertujK(unsigned x, unsigned k) {
  int brojac = 0;
  for (int i = 0; i < 32; i++) {
    if (1u & (x >> i)) {
      brojac++;
      if (brojac % k == 0) {
        x ^= (1u << i);
      }
    }
  }
  return x;
}
int main() {
  unsigned x, k;
  scanf("%u%u", &x, &k);

  unsigned inv_x = invertujK(x, k);
  printf("%u\n", inv_x);
  return EXIT_SUCCESS;
}
