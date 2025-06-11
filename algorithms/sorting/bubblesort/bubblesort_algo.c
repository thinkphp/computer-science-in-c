#include <stdio.h>
#include <stdlib.h>

#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAX 500005

// Global variables
int n;
int vec[MAX];

// Function prototypes
void read_data();
void bubblesort_solve();
void print_data();
void _bubblesort();

// Function to read data from file
void read_data() {
    FILE *file = fopen(FIN, "r");
    if (file == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }
    
    fscanf(file, "%d", &n);
    for(int i = 0; i < n; i++) {
        fscanf(file, "%d", &vec[i]);
    }
    fclose(file);
    
    printf("Data read from file successfully\n");
}

// Function to solve using bubble sort
void bubblesort_solve() {
    printf("Bubble Sort Algorithm in Action!\n");
    printf("Output: algsort.out\n");
    _bubblesort();
}

// Function to print results to file
void print_data() {
    FILE *file = fopen(FOUT, "w");
    if (file == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }
    
    for(int i = 0; i < n; i++) {
        fprintf(file, "%d ", vec[i]);
    }
    fclose(file);
}

// Bubble sort implementation
void _bubblesort() {
    int i, j, temp;
    int swapped;
    
    // Outer loop for number of passes
    for(i = 0; i < n - 1; i++) {
        swapped = 0; // Flag to optimize - if no swaps occur, array is sorted
        
        // Inner loop for comparisons in each pass
        for(j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if(vec[j] > vec[j + 1]) {
                // Swap if they are in wrong order
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                swapped = 1;
            }
        }
        
        // If no swapping occurred, array is already sorted
        if(swapped == 0) {
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
    // Initialize and run bubble sort
    printf("Bubble Sort implementation in C\n");
    
    read_data();
    bubblesort_solve();
    print_data();
    
    return 0;
}
