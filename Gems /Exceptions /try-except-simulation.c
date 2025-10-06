#include <stdio.h>

int main() {
    double numere[] = {5, 0, 2, 10};
    int n = sizeof(numere) / sizeof(numere[0]);

    for (int i = 0; i < n; i++) {
        double x = numere[i];

        if (x == 0) {
            printf("Eroare: împărțire la zero pentru elementul %.0f — se trece mai departe.\n", x);
            continue;  // trece la următorul element
        }

        double rezultat = 10 / x;
        printf("10 împărțit la %.0f = %.2f\n", x, rezultat);
    }

    printf("Programul a ajuns la final.\n");
    return 0;
}
