#include <stdio.h>
#include <stdlib.h>

#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAX 500005

// Global variables to replace class members
int n;
int vec[MAX];

// Function prototypes
void read_data();
void quicksort_solve();
void print_data();
void _quicksort(int low, int high);

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

// Function to solve using quicksort
void quicksort_solve() {
    printf("Quick Sort Algorithm in Action!\n");
    printf("Output: algsort.out\n");
    _quicksort(0, n - 1);
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

// Private quicksort implementation
void _quicksort(int low, int high) {
    int i, j, PIVOT;
    
    i = low;
    j = high;
    
    // Choose pivot as middle element
    PIVOT = vec[(low + high) >> 1];
    
    while(i <= j) {
        // Find element greater than or equal to pivot from left
        while(vec[i] < PIVOT) {
            i++;
        }
        
        // Find element less than or equal to pivot from right
        while(vec[j] > PIVOT) {
            j--;
        }
        
        // Swap elements if pointers haven't crossed
        if(i <= j) {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j--;
        }
    }
    
    // Recursively sort left and right partitions
    if(low < j) _quicksort(low, j);
    if(i < high) _quicksort(i, high);
}

int main(int argc, char const *argv[]) {
    // Initialize and run quicksort
    printf("Quick Sort implementation in C\n");
    
    read_data();
    quicksort_solve();
    print_data();
    
    return 0;
}
