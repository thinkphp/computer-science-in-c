#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;     // Size of right subarray
    
    // Create temporary arrays
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr[left..right]
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    // Free temporary arrays
    free(L);
    free(R);
}

// Main merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Utility function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test merge sort
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}

/*
Time Complexity: O(n log n) in all cases
Space Complexity: O(n) for temporary arrays

How Merge Sort Works:
1. Divide: Split array into two halves
2. Conquer: Recursively sort both halves
3. Combine: Merge the sorted halves

Example execution with array [64, 34, 25, 12]:
1. Split: [64, 34] and [25, 12]
2. Split again: [64], [34] and [25], [12]
3. Merge: [34, 64] and [12, 25]
4. Final merge: [12, 25, 34, 64]
*/
