#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if(argc == 1) {
        printf("-1\n");
        return 1;
    }

    int broj_malih = 0;
    int broj_velikih = 0;
    for(int i = 1; i < argc; i++) {
        int duzina_reci = strlen(argv[i]);
        for(int j = 0; j < duzina_reci; j++) {
            if(isupper(argv[i][j])) {
                broj_velikih++;
            } else if(islower(argv[i][j])) {
                broj_malih++;
            }
        }
    }

    if(broj_malih > broj_velikih) {
        printf("a\n");
    } else if(broj_malih < broj_velikih) {
        printf("A\n");
    } else {
        printf("0\n");
    }


    return 0;
}
