#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int digit_sum(int num) {
    while (num >= 10) {  // Dok je broj dvocifren ili veći
        int sum = 0;
        while (num > 0) {  // Sabiramo cifre
            sum += num % 10;
            num /= 10;
        }
        num = sum;  // Postavljamo broj na zbir cifara
    }
    return num;
}

char encrypt_char(char c) {
    if(isalpha(c)) {
        int ascii_code = (int)c;
        int sum = digit_sum(ascii_code);
        return '0' + sum;
    }
    else if(isdigit(c)) {
        return 'a' + (c - '0');
    }
    else {
        return c;
    }
}
int main() {
    char niska[101];

    fgets(niska, sizeof(niska), stdin);
    printf("%s", niska);
    // niska[strcspn(niska, "\n")] = '\0';

    for(int i = 0; niska[i] != '\0'; i++) {
        niska[i] = encrypt_char(niska[i]);
    }


    printf("%s", niska);

    return 0;
}
