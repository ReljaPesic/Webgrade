#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrom(char *string) {
  int n = strlen(string);
  if (n == 1) {
    return 1;
  }
  for (int i = 0; i < n / 2; i++) {
    if (string[i] != string[n - 1 - i]) {
      return 0;
    }
    i++;
  }
  return 1;
}
int main(int argc, char *argv[]) {
  int brojac = 0;
  for (int i = 1; i < argc; i++) {
    if (is_palindrom(argv[i])) {
      brojac++;
    }
  }
  printf("%d\n", brojac);
  return EXIT_SUCCESS;
}
