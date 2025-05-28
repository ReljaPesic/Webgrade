#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    char niska1[101];
    char niska2[101];
    int brojac = 0;

    //ucitavanje niski

    //adwdwadw dawdawdawdaw
    char dnk[202];
    fgets(dnk, 202, stdin);
    int duzina_dnk = strlen(dnk);
    int i;
    for(i = 0; dnk[i] != ' '; i++) {
        niska1[i] = dnk[i];
    }
    niska1[i] = '\0';
    i++;

    int j;
    for(j = 0; dnk[i] != '\n'; i++, j++) {
        niska2[j] = dnk[i];
    }
    niska2[j] = '\0';

    // printf("prva niska: %s\n", niska1);
    // printf("druga niska: %s\n", niska2);

    int duzina = strlen(niska1);

    for(int i = 0; i < duzina; i++) {
        if((niska1[i] == 'a' && niska2[i] == 't') ||
           (niska1[i] == 't' && niska2[i] == 'a')) {
            continue;
        } else if((niska1[i] == 'c' && niska2[i] == 'g') ||
                  (niska1[i] == 'g' && niska2[i] == 'c')) {
            continue;
        } else {
            brojac++;
        }
    }

    printf("%d", brojac);


    return 0;
}
