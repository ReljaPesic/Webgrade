#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int count = 0;

  for (int i = 0; i < argc; i++) {
    int n = strlen(argv[i]);
    int is_neopadajuci = 1;
    for (int j = 0; j < n - 1; j++) {
      if (j == 0 && !isdigit(argv[i][j])) {
        continue;
      }

      char trenutni = argv[i][j];
      char sledeci = argv[i][j + 1];

      if (trenutni >= sledeci) {
        is_neopadajuci = 0;
        break;
      }
    }
    if (is_neopadajuci) {
      count++;
    }
  }

  printf("%d\n", count);
  return EXIT_SUCCESS;
}
