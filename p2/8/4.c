#include <stdio.h>
#include <stdlib.h>

int broj_sekvenci(unsigned x) {
  int brojac = 0;
  for (int i = 31; i >= 2; i--) {
    unsigned trojka = (x >> (i - 2)) & 7;
    if (trojka == 2) {
      brojac++;
    }
  }
  return brojac;
}
int main() {
  unsigned x;
  scanf("%u", &x);

  int brojac = broj_sekvenci(x);
  printf("%u\n", brojac);
  return EXIT_SUCCESS;
}
