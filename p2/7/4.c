#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { MODE_NONE, MODE_M, MODE_V, MODE_MV } Mode;

Mode parse_mode(const char *argument) {
  if (strcmp(argument, "-m") == 0) {
    return MODE_M;
  } else if (strcmp(argument, "-v") == 0) {
    return MODE_V;
  } else if (strcmp(argument, "-mv") == 0) {
    return MODE_MV;
  } else if (strcmp(argument, "-vm") == 0) {
    return MODE_MV;
  } else
    return MODE_NONE;
}
int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  Mode mod = parse_mode(argv[1]);
  char *rec = argv[2];

  switch (mod) {
  case MODE_M:
    for (int i = 0; rec[i] != '\0'; i++) {
      rec[i] = tolower(rec[i]);
    }
    break;
  case MODE_V:
    for (int i = 0; rec[i] != '\0'; i++) {
      rec[i] = toupper(rec[i]);
    }
    break;
  case MODE_MV:
    for (int i = 0; rec[i] != '\0'; i++) {
      if (isupper(rec[i])) {
        rec[i] = tolower(rec[i]);
      } else {
        rec[i] = toupper(rec[i]);
      }
    }
    break;
  default:
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
    break;
  }
  printf("%s\n", rec);
  return EXIT_SUCCESS;
}
