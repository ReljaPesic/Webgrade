#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char marka[31];
    char model[31];
    int cena;
}Automobil;

int main(int argc, char **argv) {

    if(argc != 2) {
        fprintf(stderr, "-1\n");
        return 1;
    }


    char naziv_fajla[21];
    scanf("%s", naziv_fajla);
    FILE *f = fopen(naziv_fajla, "r");
    if(f == NULL) {
        fprintf(stderr, "-1\n");
        return 1;
    }


    int n;
    if(fscanf(f, "%d", &n) != 1) {
        fprintf(stderr, "-1\n");
        return 1;
    }

    Automobil auti[n];
    for(int i = 0; i < n; i++) {
        if(fscanf(f, "%s %s %d", auti[i].marka, auti[i].model, &auti[i].cena) != 3) {
            fprintf(stderr, "-1\n");
            return 1;
        }
    }

    int max_cena = atoi(argv[1]);
    //prosek po marki

    bool fleg = false;
    //sve aute cija je cena < max_cena + prosecna cena za tu marku
    for(int i = 0; i < n; i++) {
        if(auti[i].cena <= max_cena) {
            fleg = true;
            fprintf(stdout, "%s %s %d ", auti[i].marka, auti[i].model, auti[i].cena);
            char tr_marka[31];
            strcpy(tr_marka, auti[i].marka);
            double tr_suma = 0;
            int tr_n = 0;
            for(int i = 0; i < n; i++) {
                if(strcmp(tr_marka, auti[i].marka) == 0) {
                    tr_suma += auti[i].cena;
                    tr_n++;
                }
            }

            double tr_prosek = tr_suma / tr_n;
            if(tr_prosek == (int)tr_prosek) {
                fprintf(stdout, "[Prosek za %s: %.2d]\n", tr_marka, (int)tr_prosek);
            } else
                fprintf(stdout, "[Prosek za %s: %.2f]\n", tr_marka, tr_prosek);
        }
    }
    if(!fleg) {
        printf("-\n");
    }


 return 0;
}
