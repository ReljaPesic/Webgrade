#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INITIAL_SIZE 128
#define GROWTH_FACTOR 2

int unesiSkup(char **s, FILE* f);
void prebroj(char* s, int *br_slova,int *br_cifara);

int main(int argc, char* argv[]) {

    if(argc != 2) {
        fprintf(stderr, "-1\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if(f == NULL) {
        fprintf(stderr, "-1\n");
        return 1;
    }

    size_t n = INITIAL_SIZE;
    char *s = (char*)malloc(n);
    if(!s) {
        fprintf(stderr, "-1\n");
        return 1;
    }

    int rez = unesiSkup(&s, f);
    if(rez == -1) {
        free(s);
        fclose(f);
        return 1;
    }

    int br_cifara = 0, br_slova = 0;
    prebroj(s, &br_slova, &br_cifara);

    printf("broj slova: %d\nbroj cifara: %d\n", br_slova, br_cifara);
    //oslobadjanje
    free(s);
    fclose(f);

    return 0;
}

int unesiSkup(char **s, FILE* f) {
    int ch;
    int brojac = 0;
    size_t n = INITIAL_SIZE;
    while((ch = fgetc(f)) != EOF) {
        if(brojac + 1 >= n) {
            //realokacija
            n *= GROWTH_FACTOR;
            char* temp = realloc(*s, n);
            if(!temp) {
                perror("-1\n");
                return -1;
            }
            *s = temp;
        }
        char c = (char)ch;
        if(!isalpha(c) && !isdigit(c)) {
            break;
        }
        (*s)[brojac++] = c;
    }
    (*s)[brojac] = '\0';
    return brojac;
}

void prebroj(char* s, int *br_slova,int *br_cifara) {
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
        if(isalpha(s[i]))
            (*br_slova)++;
        else if(isdigit(s[i]))
            (*br_cifara)++;
    }
}
