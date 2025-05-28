#include<stdio.h>
#include<stdlib.h>

int main() {

    int n;
    if (scanf("%d", &n) != 1 || n > 100 || n < 1) {
        printf("-1\n");
        return 1;
    }

    int niz[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }
    int suma = 0;

    for(int i = 0; i < n; i++) {
        suma += niz[i];
        niz[i] = suma;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    printf("\n");

    return 0;
}
