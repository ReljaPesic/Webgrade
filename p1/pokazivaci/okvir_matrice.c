#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n > 50 || n < 1) {
        printf("-1\n");
        return 1;
    }

    int najveci = INT_MIN;
    int matrica[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrica[i][j]);
            if(i == 0 || i == n - 1 ||
               j == 0 || j == n - 1) {
                   if(matrica[i][j] > najveci) {
                       najveci = matrica[i][j];
                }
            }
        }
    }

    printf("%d\n", najveci);

    return 0;
}
