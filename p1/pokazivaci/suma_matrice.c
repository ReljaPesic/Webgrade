#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);
    if(n > 50 || n < 1) {
        printf("-1\n");
        return 1;
    }

    int suma = 0;
    int matrica[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrica[i][j]);
            if(j % 2 == 0) {
                suma += matrica[i][j];
            }
        }
    }

    printf("%d\n", suma);


    return 0;
}
