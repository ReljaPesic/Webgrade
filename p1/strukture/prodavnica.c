#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char naziv[21];
    double cena;
    char tip;
} Proizvod;

void ispisi_iz_opsega(Proizvod prodavnica[], int n, int a, int b) {
    int brojac = 0;
    for (int i = 0; i < n; i++) {
        if (prodavnica[i].cena >= a && prodavnica[i].cena <= b) {
            printf("%s ", prodavnica[i].naziv);
            brojac++;
        }
    }
    if(brojac == 0)
        printf("0\n");
    else
        printf("\n");
}

void ispisi_isti_tip(Proizvod prodavnica[], int n, char tip) {
    int brojac = 0;
    for (int i = 0; i < n; i++) {
        if (prodavnica[i].tip == tip) {
            printf("%s ", prodavnica[i].naziv);
            brojac++;
        }
    }
    if(brojac == 0)
        printf("0\n");
    else
        printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    if(n < 0 || n > 100) {
        printf("-1\n");
        return 1;
    }

    char naziv[21];
    double cena;
    char tip;

    Proizvod prodavnica[n];

    for (int i = 0; i < n; i++) {
        scanf("%s %lf %c", naziv, &cena, &tip);
        if(strlen(naziv) > 21) {
            printf("-1\n");
            return 1;
        }
        strcpy(prodavnica[i].naziv, naziv);
        if(cena < 0 ) {
            printf("-1\n");
            return 1;
        }
        prodavnica[i].cena = cena;
        prodavnica[i].tip = tip;

    }
    char opcija_pretrage;
    scanf(" %c", &opcija_pretrage);

    if (opcija_pretrage == 'r') {
        int a, b;

        scanf("%d %d", &a, &b);
        ispisi_iz_opsega(prodavnica, n, a, b);

    } else if (opcija_pretrage == 't') {
        scanf(" %c", &tip);
        ispisi_isti_tip(prodavnica, n, tip);
    }
    else {
        printf("-1\n");
        return 1;
    }


    return 0;
}
