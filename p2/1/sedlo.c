#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "-1\n");
    return 1;
  }

  int n = argv[1] - '0';
  int m = argv[2] - '0';

  if (m < 0 || n < 0 || m > 50 || n > 50) {
    fprintf(stderr, "-1\n");
    return 1;
  }

  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  int najmanji;
  int najmanji_j, najmanji_i;
  for (int i = 0; i < n; i++) {
    najmanji = INT_MAX;
    for (int j = 0; j < m; j++) {
      if (a[i][j] < najmanji) {
        najmanji = a[i][j];
        najmanji_j = j;
        najmanji_i = i;
      }
    }
    // kad nadjes najmanji prolazis kroz njegovu
    // kolonu i gledas dal je najveci
    bool ima_veci = false;
    for (int k = 0; k < n; k++) {
      if (a[k][najmanji_j] > a[najmanji_i][najmanji_j]) {
        ima_veci = true;
        break;
      }
    }
    if (!ima_veci) {
      printf("%d %d %d\n", najmanji_i, najmanji_j, a[najmanji_i][najmanji_j]);
      ima_veci = false;
    }
  }

  return 0;
}
