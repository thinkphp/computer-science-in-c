#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Forward declaration
bool isValidAdjacencyMatrix(int** graph, int n);

/**
 * Checks if an oriented graph represented as an adjacency matrix is asymmetrical.
 * An asymmetrical graph has no symmetric pairs of edges - if there's an edge 
 * from vertex i to vertex j, there should be no edge from vertex j to vertex i.
 * 
 * @param graph: 2D array representing the adjacency matrix of the oriented graph
 *               graph[i][j] = 1 means there's an edge from vertex i to vertex j
 *               graph[i][j] = 0 means no edge from vertex i to vertex j
 * @param n: size of the square matrix (number of vertices)
 * @return: true if the graph is asymmetrical, false otherwise
 */
bool isAsymmetricalGraph(int** graph, int n) {
    // Check if the graph is valid (valid adjacency matrix)
    if (!isValidAdjacencyMatrix(graph, n)) {
        return false;
    }
    
    // Check for symmetric pairs of edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If there's an edge from i to j, check if there's also an edge from j to i
            if (graph[i][j] == 1 && graph[j][i] == 1) {
                return false; // Found a symmetric pair, not asymmetrical
            }
        }
    }
    
    return true; // No symmetric pairs found, graph is asymmetrical
}

/**
 * Helper function to validate if the input represents a valid adjacency matrix.
 * Checks if the matrix contains only 0s and 1s.
 * 
 * @param graph: 2D array to validate
 * @param n: size of the matrix
 * @return: true if valid adjacency matrix, false otherwise
 */
bool isValidAdjacencyMatrix(int** graph, int n) {
    // Check if matrix size is valid
    if (n <= 0 || graph == NULL) {
        return false;
    }
    
    // Check if matrix contains valid values
    for (int i = 0; i < n; i++) {
        if (graph[i] == NULL) {
            return false; // Row is null
        }
        
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0 && graph[i][j] != 1) {
                return false; // Invalid value (not 0 or 1)
            }
        }
    }
    
    return true;
}

/**
 * Helper function to allocate memory for a 2D matrix
 * 
 * @param n: size of the square matrix
 * @return: pointer to allocated 2D array
 */
int** allocateMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    if (matrix == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    
    return matrix;
}

/**
 * Helper function to free memory allocated for a 2D matrix
 * 
 * @param matrix: pointer to the 2D array
 * @param n: size of the matrix
 */
void freeMatrix(int** matrix, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < n; i++) {
            if (matrix[i] != NULL) {
                free(matrix[i]);
            }
        }
        free(matrix);
    }
}

/**
 * Helper function to initialize a matrix with given values
 * 
 * @param matrix: pointer to the 2D array
 * @param values: 1D array containing values in row-major order
 * @param n: size of the matrix
 */
void initializeMatrix(int** matrix, int* values, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = values[i * n + j];
        }
    }
}

/**
 * Helper function to print a matrix
 * 
 * @param matrix: pointer to the 2D array
 * @param n: size of the matrix
 */
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Test function to demonstrate usage
int main() {
    // Test case 1: Asymmetrical graph
    int values1[] = {
        0, 1, 0,
        0, 0, 1,
        1, 0, 0
    };
    
    // Test case 2: Non-asymmetrical graph (has symmetric edges)
    int values2[] = {
        0, 1, 0,
        1, 0, 1,
        0, 1, 0
    };
    
    // Test case 3: Graph with self-loops
    int values3[] = {
        1, 1, 0,
        0, 0, 1,
        1, 0, 1
    };
    
    int n = 3; // Size of the matrices
    
    // Allocate memory for test matrices
    int** graph1 = allocateMatrix(n);
    int** graph2 = allocateMatrix(n);
    int** graph3 = allocateMatrix(n);
    
    if (graph1 == NULL || graph2 == NULL || graph3 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Initialize matrices
    initializeMatrix(graph1, values1, n);
    initializeMatrix(graph2, values2, n);
    initializeMatrix(graph3, values3, n);
    
    // Test the function
    printf("Test Case 1 (Expected: Asymmetrical): ");
    printf("%s\n", isAsymmetricalGraph(graph1, n) ? "Asymmetrical" : "Not Asymmetrical");
    
    printf("Test Case 2 (Expected: Not Asymmetrical): ");
    printf("%s\n", isAsymmetricalGraph(graph2, n) ? "Asymmetrical" : "Not Asymmetrical");
    
    printf("Test Case 3 (Expected: Not Asymmetrical): ");
    printf("%s\n", isAsymmetricalGraph(graph3, n) ? "Asymmetrical" : "Not Asymmetrical");
    
    // Print matrices for verification
    printf("\nMatrix 1:\n");
    printMatrix(graph1, n);
    printf("\nMatrix 2:\n");
    printMatrix(graph2, n);
    printf("\nMatrix 3:\n");
    printMatrix(graph3, n);
    
    // Free allocated memory
    freeMatrix(graph1, n);
    freeMatrix(graph2, n);
    freeMatrix(graph3, n);
    
    return 0;
}
