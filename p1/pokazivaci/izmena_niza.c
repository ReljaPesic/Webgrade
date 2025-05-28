#include <stdio.h>
#include <stdlib.h>

void premesti(int a[], int indeksi[], int n);

int main() {

    int n;
    scanf("%d", &n);
    if(n > 100 || n < 1) {
        printf("-1\n");
        return 1;
    }
    int a[n];
    int indeksi[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &indeksi[i]);
        if(indeksi[i] >= n || indeksi[i] < 0) {
            printf("-1\n");
            return 1;
        }
    }

    premesti(a, indeksi, n);

    return 0;
}

//12 9 -4
//2  1  0
void premesti(int a[], int indeksi[], int n) {
    int novi_niz[n];
    for(int i = 0; i < n; i++) {
        novi_niz[i] = a[indeksi[i]];
    }

    for(int i = 0; i < n; i++) {
        a[i] = novi_niz[i];
        printf("%d ", a[i]);
    }
    printf("\n");

    return;
}
