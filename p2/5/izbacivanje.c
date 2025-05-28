#include <stdio.h>
#include <stdlib.h>

int izbaci_parne(int x);

int main(int argc, char *argv[]) {

    if(argc != 2) {
        fprintf(stderr, "-1\n");
        return 1;
    }

    int x = atoi(argv[1]);

    printf("%d\n", izbaci_parne(x));

 return 0;
}


//4321 -> 31
int izbaci_parne(int x) {
    if(x == 0) {
        return 0;
    }

    int poslednja = x % 10;
    int ostatak = izbaci_parne(x / 10);

    if(poslednja % 2 == 0)
        return ostatak;
    else
        return ostatak * 10 + poslednja;

}
