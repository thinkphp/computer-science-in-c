#include "math_functions.h"

int MathFunctions::euclid(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int MathFunctions::fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for(int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int MathFunctions::factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
