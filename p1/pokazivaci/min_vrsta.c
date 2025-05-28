#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, vrsta;
    scanf("%d", &n);
    if(n > 50 || n < 1) {
        printf("-1\n");
        return 1;
    }

    int matrica[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }

    scanf("%d", &vrsta);
    if(vrsta < 0 || vrsta >= n) {
        printf("-1\n");
        return 1;
    }

    int najmani = INT_MAX;
    for(int j = 0; j < n; j++) {
        if(matrica[vrsta][j] < najmani) {
            najmani = matrica[vrsta][j];
        }
    }


    printf("%d\n", najmani);

    return 0;
}
