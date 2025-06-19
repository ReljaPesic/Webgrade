#include <stdio.h>
#include <stdlib.h>

unsigned invertovanje(unsigned x, unsigned k, unsigned p) {
  for (int i = 0; i < k; i++) {
    x ^= (1u << i);
  }

  unsigned mask = 0u;
  mask ^= (1u << 31);

  for (int j = 0; j < p; j++) {
    x ^= (mask >> j);
  }
  return x;
}

int main() {
  unsigned x, k, p;
  scanf("%u%u%u", &x, &k, &p);

  unsigned inv_x = invertovanje(x, k, p);
  printf("%u\n", inv_x);

  return EXIT_SUCCESS;
}
