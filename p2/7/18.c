#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  char *rec = argv[1];
  char slovo = argv[2][0];
  int x = atoi(argv[3]);

  int n = strlen(rec);
  int prvo = -1, drugo = -1;
  int i;
  for (i = 0; i < n; i++) {
    if (rec[i] == slovo) {
      prvo = i;
      break;
    }
  }
  for (int j = i + 1; j < n; j++) {
    if (rec[j] == slovo) {
      drugo = j;
      break;
    }
  }
  if (prvo == -1 || drugo == -1) {
    printf("%s\n", rec);
    return EXIT_SUCCESS;
  }

  for (int i = prvo + 1; i < drugo; i++) {
    rec[i] += x;
  }

  printf("%s\n", rec);

  return EXIT_SUCCESS;
}
