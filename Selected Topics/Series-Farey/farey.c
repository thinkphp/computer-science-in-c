#include <stdio.h>

// Function to find the mediant of two fractions
void mediant(int a, int b, int c, int d, int *med_num, int *med_den) {
    *med_num = a + c;
    *med_den = b + d;
}

// Function to generate the Farey sequence of order n
void farey_sequence(int n) {
    // Initialize the sequence with 0/1 and 1/1
    int numerators[1000] = {0, 1};  // Array to store numerators
    int denominators[1000] = {1, 1};  // Array to store denominators
    int size = 2;  // Current size of the sequence

    int i = 0;
    while (i < size - 1) {
        int a = numerators[i];
        int b = denominators[i];
        int c = numerators[i + 1];
        int d = denominators[i + 1];

        // Find the mediant fraction
        int med_num, med_den;
        mediant(a, b, c, d, &med_num, &med_den);

        if (med_den <= n) {
            // Insert the mediant fraction into the sequence
            for (int j = size; j > i + 1; j--) {
                numerators[j] = numerators[j - 1];
                denominators[j] = denominators[j - 1];
            }
            numerators[i + 1] = med_num;
            denominators[i + 1] = med_den;
            size++;
        } else {
            i++;
        }
    }

    // Print the Farey sequence
    for (int k = 0; k < size; k++) {
        printf("%d/%d\n", numerators[k], denominators[k]);
    }
}

int main() {
    // Generate Farey sequence of order 5
    int n = 5;
    farey_sequence(n);
    return 0;
}
