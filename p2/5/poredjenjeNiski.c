#include <stdio.h>

int poredi(char *s1, char *s2);

int main() {
  char s1[64];
  char s2[64];

  while (scanf("%s %s", s1, s2) != EOF) {
    printf("%d\n", poredi(s1, s2));
  }

  return 0;
}

int poredi(char *s1, char *s2) {
  if (*s1 != *s2)
    return 1;
  if (*s1 == '\0')
    return 0;
  return poredi(s1 + 1, s2 + 1);
}
