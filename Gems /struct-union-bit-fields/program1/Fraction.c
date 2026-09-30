#include <stdio.h>
#include <stdlib.h>

typedef struct Fraction {
    int n;
    int d;
} Fraction;

int euclid(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void simplify(Fraction *f) {
    int div = euclid(f->n, f->d);
    if (div != 0) {
        f->n /= div;
        f->d /= div;
    }
    // semnul ramane mereu la numarator
    if (f->d < 0) {
        f->n = -f->n;
        f->d = -f->d;
    }
}

void read_fraction(Fraction *ptr) {
    printf("Numarator = ");
    scanf("%d", &ptr->n);
    do {
        printf("Numitor (diferit de 0) = ");
        scanf("%d", &ptr->d);
    } while (ptr->d == 0);
    simplify(ptr);
}

void display(const char name[], Fraction f) {
    printf("%s\n", name);
    printf("%d / %d\n", f.n, f.d);
}

void sum_fractions(Fraction f1, Fraction f2, Fraction *result) {
    result->n = f1.n * f2.d + f2.n * f1.d;
    result->d = f1.d * f2.d;
    simplify(result);
}

void subtract_fractions(Fraction f1, Fraction f2, Fraction *result) {
    result->n = f1.n * f2.d - f2.n * f1.d;
    result->d = f1.d * f2.d;
    simplify(result);
}

void multiply_fractions(Fraction f1, Fraction f2, Fraction *result) {
    result->n = f1.n * f2.n;
    result->d = f1.d * f2.d;
    simplify(result);
}

// returneaza 1 daca s-a putut face, 0 daca f2 este zero
int divide_fractions(Fraction f1, Fraction f2, Fraction *result) {
    if (f2.n == 0) {
        return 0;
    }
    result->n = f1.n * f2.d;
    result->d = f1.d * f2.n;
    simplify(result);   // muta si semnul la numarator
    return 1;
}

// returneaza -1 daca f1 < f2, 0 daca sunt egale, 1 daca f1 > f2
int compare_fractions(Fraction f1, Fraction f2) {
    // numitorii sunt pozitivi dupa simplify, deci inegalitatea se pastreaza
    long long left  = (long long)f1.n * f2.d;
    long long right = (long long)f2.n * f1.d;
    if (left < right) return -1;
    if (left > right) return 1;
    return 0;
}

// inversa: 1/f. Returneaza 1 daca s-a putut face, 0 daca f este zero
int inverse_fraction(Fraction f, Fraction *result) {
    if (f.n == 0) {
        return 0;
    }
    result->n = f.d;
    result->d = f.n;
    simplify(result);   // muta semnul la numarator
    return 1;
}

// ridicare la putere: f^k, cu k intreg (poate fi negativ sau 0)
// returneaza 0 daca f este zero si k <= 0 (0^0 si 0^negativ nu sunt definite)
int power_fraction(Fraction f, int k, Fraction *result) {
    Fraction base = f;
    Fraction acc = {1, 1};

    if (f.n == 0 && k <= 0) {
        return 0;
    }
    if (k < 0) {
        inverse_fraction(f, &base);
        k = -k;
    }
    for (int i = 0; i < k; i++) {
        multiply_fractions(acc, base, &acc);
    }
    *result = acc;
    return 1;
}

// media aritmetica: (f1 + f2) / 2
void average_fractions(Fraction f1, Fraction f2, Fraction *result) {
    result->n = f1.n * f2.d + f2.n * f1.d;
    result->d = f1.d * f2.d * 2;
    simplify(result);
}

int main(void) {
    Fraction f1, f2, sum, diff, prod, quot, inv1, inv2, pow1, pow2, avg;
    int k;

    read_fraction(&f1);
    read_fraction(&f2);

    display("Prima fractie:", f1);
    display("A doua fractie:", f2);

    sum_fractions(f1, f2, &sum);
    display("Suma:", sum);

    subtract_fractions(f1, f2, &diff);
    display("Diferenta:", diff);

    multiply_fractions(f1, f2, &prod);
    display("Produsul:", prod);

    if (divide_fractions(f1, f2, &quot)) {
        display("Catul:", quot);
    } else {
        printf("Impartire imposibila: a doua fractie este 0\n");
    }

    int c = compare_fractions(f1, f2);
    if (c < 0)      printf("Prima fractie este mai mica\n");
    else if (c > 0) printf("Prima fractie este mai mare\n");
    else            printf("Fractiile sunt egale\n");

    if (inverse_fraction(f1, &inv1)) {
        display("Inversa primei fractii:", inv1);
    } else {
        printf("Prima fractie este 0, nu are invers\n");
    }
    if (inverse_fraction(f2, &inv2)) {
        display("Inversa celei de-a doua fractii:", inv2);
    } else {
        printf("A doua fractie este 0, nu are invers\n");
    }

    average_fractions(f1, f2, &avg);
    display("Media aritmetica:", avg);

    printf("Exponent (numar intreg) = ");
    scanf("%d", &k);
    if (power_fraction(f1, k, &pow1)) {
        printf("Prima fractie ridicata la %d:\n%d / %d\n", k, pow1.n, pow1.d);
    } else {
        printf("Puterea nu este definita pentru prima fractie\n");
    }
    if (power_fraction(f2, k, &pow2)) {
        printf("A doua fractie ridicata la %d:\n%d / %d\n", k, pow2.n, pow2.d);
    } else {
        printf("Puterea nu este definita pentru a doua fractie\n");
    }

    return 0;
}