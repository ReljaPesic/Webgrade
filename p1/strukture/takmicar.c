#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char ime[31];
  double poeni;
} Takmicar;

int compare_takmicar(const void *a, const void *b) {
  Takmicar *takmicar1 = (Takmicar *)a;
  Takmicar *takmicar2 = (Takmicar *)b;
  return takmicar2->poeni - takmicar1->poeni;
}
void ispisi_takmicar(Takmicar *t) { printf("%s ", t->ime); }
int main() {
  int n;
  scanf("%d", &n);
  if (n < 3 || n > 100) {
    printf("-1\n");
    return 1;
  }

  char ime[31];
  double poeni;

  Takmicar takmicari[n];
  for (int i = 0; i < n; i++) {
    scanf("%s %lf", ime, &poeni);
    if (poeni < 0 || poeni > 100) {
      printf("-1\n");
      return 1;
    }
    strcpy(takmicari[i].ime, ime);
    takmicari[i].poeni = poeni;
  }

  qsort(takmicari, n, sizeof(Takmicar), compare_takmicar);
  for (int i = 0; i < 3; i++) {
    ispisi_takmicar(&takmicari[i]);
  }
  printf("\n");

  return 0;
}
