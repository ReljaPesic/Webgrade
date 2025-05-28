#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    KRALJICA,
    TOP,
    LOVAC,
    KONJ,
    INVALID
} Figura;

typedef struct {
    Figura figura;
    int red;
    char kolona;
} SAH;

int napada(SAH *f1, SAH *f2);

Figura string_to_figura(const char *str) {
    if (strcmp(str, "kraljica") == 0) return KRALJICA;
    if (strcmp(str, "top") == 0) return TOP;
    if (strcmp(str, "lovac") == 0) return LOVAC;
    if (strcmp(str, "konj") == 0) return KONJ;
    return INVALID;
}

int main() {

    char figura[11];
    int red;
    char kolona;


    scanf("%s %d %c", figura, &red, &kolona);
    SAH f1;
    f1.figura = string_to_figura(figura);
    f1.red = red;
    f1.kolona = kolona;

    scanf("%s %d %c", figura, &red, &kolona);
    SAH f2;
    f2.figura = string_to_figura(figura);
    f2.red = red;
    f2.kolona = kolona;

    printf("%d\n", napada(&f1, &f2));
    printf("%d\n", napada(&f2, &f1));


    return 0;
}

int napada(SAH *f1, SAH *f2) {
    switch(f1->figura) {
        case KRALJICA:
            if(f2->red == f1->red || f2->kolona == f1->kolona)
                return 1;
            else if(abs(f1->kolona - f2->kolona) == abs(f1->red - f2->red))
                return 1;
            else
                return 0;
        case TOP:
            if(f2->red == f1->red || f2->kolona == f1->kolona)
                return 1;
            else
                return 0;
        case LOVAC:
            if(abs(f1->kolona - f2->kolona) == abs(f1->red - f2->red))
                return 1;
            else
                return 0;
        case KONJ:
            if((abs(f1->kolona - f2->kolona) == 1 && abs(f1->red - f2->red) == 2) ||
               (abs(f1->kolona - f2->kolona) == 2 && abs(f1->red - f2->red) == 1))
                return 1;
            else
                return 0;
        default:
            return -1;
    }

}
