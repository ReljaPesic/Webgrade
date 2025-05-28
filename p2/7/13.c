#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int brojCifara(int x) {
  int i = 0;
  while (x != 0) {
    x /= 10;
    i++;
  }
  return i;
}

int pretraga(int *niz, int k, int l, int d) {

  int najmanji = INT_MAX;
  int index = -1;

  while (l < d) {
    int sredina = (l + d) / 2;
    if (brojCifara(niz[sredina]) == k) {
      if (niz[sredina] < najmanji) {
        najmanji = niz[sredina];
        index = sredina;
      }
      d = sredina;
    } else if (brojCifara(niz[sredina]) < k) {
      l = sredina + 1;
    } else {
      d = sredina - 1;
    }
  }

  return index;
}

int main(void) {
  int k, n;
  scanf("%d%d", &k, &n);

  if (k <= 0 || n <= 0) {
    fprintf(stderr, "-1\n");
    return EXIT_FAILURE;
  }

  int niz[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &niz[i]);
  }

  int rez = pretraga(niz, k, 0, n - 1);
  if (rez != -1) {
    printf("%d\n", rez);
  }

  return EXIT_SUCCESS;
}
