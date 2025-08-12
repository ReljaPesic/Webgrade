#include <stdio.h>
#include <stdlib.h>

int f3(int x) {
  if (x < 10) {
    // baza
    return x;
  }
  int broj = x % 10;
  if (broj % 2 != 0 && (x % 100) / 10 == 2) {
    // izbacujemo broj
    return f3(x / 10);
  } else {
    // zadrzavamo broj
    return f3(x / 10) * 10 + broj;
  }
}
int main() {
  int x;
  if (scanf("%d", &x) != 1) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  if (x < 0) {
    printf("-%d\n", f3(-x));
  } else {
    printf("%d\n", f3(x));
  }
  return EXIT_SUCCESS;
}
