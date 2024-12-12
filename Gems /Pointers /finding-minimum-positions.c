#include <stdio.h>
#include <stdlib.h>

int* find_min_positions(int arr[], int n, int *count, int *min_value) {
    int *result = malloc(n * sizeof(int));  // Dynamically allocate memory for result
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory allocation fails
    }

    *min_value = arr[0];  // Initialize minimum value
    result[0] = 1;        // Store the first position (1-based index)
    *count = 1;           // Initialize the count of minimum positions

    for (int i = 1; i < n; ++i) {
        if (arr[i] == *min_value) {
            result[(*count)++] = i + 1;  // Store position and increment count
        } else if (arr[i] < *min_value) {
            *min_value = arr[i];         // Update minimum value
            *count = 0;                  // Reset count
            result[(*count)++] = i + 1;  // Store new position
        }
    }

    return result; // Return pointer to the array
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int sir[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; ++i) scanf("%d", &sir[i]);

    int count = 0;        // To store the number of positions
    int min_value = 0;    // To store the minimum value

    // Call the function and get the pointer to the result
    int *positions = find_min_positions(sir, n, &count, &min_value);

    // Print results
    printf("min = %d\n", min_value);
    printf("Positions: ");
    for (int i = 0; i < count; ++i) printf("%d ", positions[i]);
    printf("\n");

    // Free allocated memory
    free(positions);

    return 0;
}
