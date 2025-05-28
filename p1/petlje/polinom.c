#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double factorial(int n);
double calc_expression(int n, int m);

int main() {
    int n, m;
    scanf("%d%d", &m, &n);

    if(n < 0){
        printf("-1\n");
        return 0;
    }

    double result = 1.0; // Initialize result with the first term, 1

    for(int i = 1; i <= n; i++) {
        result += calc_expression(i, m);
    }    
    
    printf("%.4f\n", result);

    return 0;
}

double factorial(int n) {
    double fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double calc_expression(int n, int m) {
    // Compute sign
    double sign = (n % 2 == 0) ? 1 : -1;

    // Compute x^(2n)
    double power = pow(m, 2 * n);

    // Compute factorial
    double fact = factorial(2 * n);

    // Return the term value
    double result = sign * power / fact;
    return result;
}

