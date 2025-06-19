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
unsigned invertujSvakiTreci(unsigned x) {
  for (int i = 0; i < 32; i += 3) {
    x ^= (1u << i);
  }
  return x;
}
int main() {
  unsigned x;
  scanf("%u", &x);

  unsigned inv_x = invertujSvakiTreci(x);
  printf("%u\n", inv_x);
  return EXIT_SUCCESS;
}
