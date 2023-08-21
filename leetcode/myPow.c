#include <stdio.h>
#include <stdlib.h>

double myPow(double, int);

int main() {
    
    double x = 34.00515;
    int n = -3;
    
    double result = myPow(x, n);

    printf("%f\n", result);

    return 0;
}

double myPow(double x, int n){
    double base = 1;
    unsigned int power;

    if (n == 0) {
        return base;
    }

    if (n < 0) {
        x = 1 / x;
        power = (unsigned int)n * -1;
    } else {
        power = n;
    }

    while(power > 0) {
        if (power % 2 == 0) {
            x = x * x;
            power = power / 2;
        } else {
            base = base * x;
            power--;
        }
    }

    return base;
}