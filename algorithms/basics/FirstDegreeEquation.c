#include <stdio.h>
    
    int main(int argc, char const *argv[]) {
        float a, b, x;
    
        printf("Linear Equation Resolver\n");
        printf("Given an equation as 'a * x + b = 0', please enter constants:\n");
    
        printf("a = ");
        if (scanf("%f", &a) != 1) {
            printf("Invalid input for a.\n");
            return 1;
        }
    
        printf("b = ");
        if (scanf("%f", &b) != 1) {
            printf("Invalid input for b.\n");
            return 1;
        }
    
        if (a != 0.0f) {
            x = -b / a;
            // Evităm afișarea lui -0.00
            if (x == -0.0f) {
                x = 0.0f;
            }
            printf("Unique solution: x = %.4f\n", x);
        } else {
            if (b == 0.0f) {
                printf("The equation has infinitely many solutions (indeterminate).\n");
            } else {
                printf("The equation has no solutions (impossible).\n");
            }
        }

        return 0;
    }
