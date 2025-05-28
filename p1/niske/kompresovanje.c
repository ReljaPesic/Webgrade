#include <stdio.h>
#include <string.h>


int main() {

    char rnk[40];

    //ucitavanje stringa
    fgets(rnk, 40, stdin);
    rnk[strcspn(rnk, "\n")] = '\0';

    int duzina = strlen(rnk);
    char ppodniska[4];
    for (int i = 0; i < 3; i++) {
        ppodniska[i] = rnk[i];
    }
    ppodniska[3] = '\0';

    char dpodniska[4];
    dpodniska[3] = '\0';

    int broj_pojavljivanja = 1;
    for (int i = 3; i < duzina; i += 3) {
        //initialize second char[]
        dpodniska[0] = rnk[i];
        dpodniska[1] = rnk[i + 1];
        dpodniska[2] = rnk[i + 2];

        if (strcmp(ppodniska, dpodniska) == 0) {
            broj_pojavljivanja++;
        }
        else {
            printf("%d%s", broj_pojavljivanja, ppodniska);
            broj_pojavljivanja = 1;
        }

        for (int i = 0; i < 3; i++) {
            ppodniska[i] = dpodniska[i];
        }
    }
    if (broj_pojavljivanja != 0) {
        printf("%d%s", broj_pojavljivanja, ppodniska);
    }
    printf("\n");

    return 0;
}
