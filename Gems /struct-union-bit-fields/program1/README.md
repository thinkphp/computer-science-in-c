# Fractions: Sum, Difference, Multiplication, Division, Simplify


```
void read_fraction(Fraction *ptr) {
    printf("Numarator = ");
    scanf("%d", &ptr->n);
    do {
        printf("Numitor (diferit de 0) = ");
        scanf("%d", &ptr->d);
    } while (ptr->d == 0);
    simplify(ptr);
}
```
