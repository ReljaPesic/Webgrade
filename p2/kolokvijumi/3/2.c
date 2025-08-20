#include <stdio.h>
#include <stdlib.h>

int is_suffix(const char *s, const char *word) {
  int len_s = 0, len_word = 0;

  while (s[len_s] != '\0')
    len_s++;
  while (word[len_word] != '\0')
    len_word++;

  if (len_s > len_word)
    return 0;

  for (int i = 0; i < len_s; i++) {
    if (s[len_s - 1 - i] != word[len_word - 1 - i]) {
      return 0;
    }
  }

  return 1;
}
int main() {
  FILE *dat = fopen("dat.txt", "r");
  if (!dat) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }
  char s[51];
  int n;
  if (fscanf(dat, "%s %d", s, &n) != 2 || n < 0) {
    fclose(dat);
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  char niz_reci[n][51];
  for (int i = 0; i < n; i++) {
    if (fscanf(dat, "%50s", niz_reci[i]) != 1) {
      break;
    }
    if (is_suffix(s, niz_reci[i])) {
      printf("%s\n", niz_reci[i]);
    }
  }
  fclose(dat);
  return EXIT_SUCCESS;
}
