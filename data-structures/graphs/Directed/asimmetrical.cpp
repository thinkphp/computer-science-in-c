#include <iostream>
#include <vector>
#include <iomanip>

/**
 * Checks if an oriented graph represented as an adjacency matrix is asymmetrical.
 * An asymmetrical graph has no symmetric pairs of edges - if there's an edge 
 * from vertex i to vertex j, there should be no edge from vertex j to vertex i.
 * 
 * @param graph: 2D vector representing the adjacency matrix of the oriented graph
 *               graph[i][j] = 1 means there's an edge from vertex i to vertex j
 *               graph[i][j] = 0 means no edge from vertex i to vertex j
 * @return: true if the graph is asymmetrical, false otherwise
 */
bool isAsymmetricalGraph(const std::vector<std::vector<int>>& graph) {
    // Check if the graph is valid (valid adjacency matrix)
    if (!isValidAdjacencyMatrix(graph)) {
        return false;
    }
    
    int n = graph.size();
    
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
 * Checks if the matrix is square and contains only 0s and 1s.
 * 
 * @param graph: 2D vector to validate
 * @return: true if valid adjacency matrix, false otherwise
 */
bool isValidAdjacencyMatrix(const std::vector<std::vector<int>>& graph) {
    // Check if matrix is empty
    if (graph.empty()) {
        return false;
    }
    
    int n = graph.size();
    
    // Check if matrix is square and contains valid values
    for (int i = 0; i < n; i++) {
        // Check if row has correct size (square matrix)
        if (graph[i].size() != n) {
            return false;
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
 * Helper function to create a matrix from a 1D vector of values
 * 
 * @param values: 1D vector containing values in row-major order
 * @param n: size of the square matrix
 * @return: 2D vector representing the matrix
 */
std::vector<std::vector<int>> createMatrix(const std::vector<int>& values, int n) {
    if (values.size() != n * n) {
        throw std::invalid_argument("Values size doesn't match matrix dimensions");
    }
    
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = values[i * n + j];
        }
    }
    
    return matrix;
}

/**
 * Helper function to print a matrix
 * 
 * @param graph: 2D vector representing the matrix
 */
void printMatrix(const std::vector<std::vector<int>>& graph) {
    for (const auto& row : graph) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Helper function to print a matrix with a title
 * 
 * @param graph: 2D vector representing the matrix
 * @param title: title to print before the matrix
 */
void printMatrixWithTitle(const std::vector<std::vector<int>>& graph, const std::string& title) {
    std::cout << "\n" << title << ":\n";
    printMatrix(graph);
}

// Test function to demonstrate usage
int main() {
    try {
        // Test case 1: Asymmetrical graph
        std::vector<int> values1 = {
            0, 1, 0,
            0, 0, 1,
            1, 0, 0
        };
        
        // Test case 2: Non-asymmetrical graph (has symmetric edges)
        std::vector<int> values2 = {
            0, 1, 0,
            1, 0, 1,
            0, 1, 0
        };
        
        // Test case 3: Graph with self-loops
        std::vector<int> values3 = {
            1, 1, 0,
            0, 0, 1,
            1, 0, 1
        };
        
        // Test case 4: Empty graph (no edges)
        std::vector<int> values4 = {
            0, 0, 0,
            0, 0, 0,
            0, 0, 0
        };
        
        int n = 3; // Size of the matrices
        
        // Create matrices using the helper function
        auto graph1 = createMatrix(values1, n);
        auto graph2 = createMatrix(values2, n);
        auto graph3 = createMatrix(values3, n);
        auto graph4 = createMatrix(values4, n);
        
        // Test the function
        std::cout << "=== Asymmetrical Graph Analysis ===\n";
        
        std::cout << "Test Case 1 (Expected: Asymmetrical): ";
        std::cout << (isAsymmetricalGraph(graph1) ? "Asymmetrical" : "Not Asymmetrical") << std::endl;
        
        std::cout << "Test Case 2 (Expected: Not Asymmetrical): ";
        std::cout << (isAsymmetricalGraph(graph2) ? "Asymmetrical" : "Not Asymmetrical") << std::endl;
        
        std::cout << "Test Case 3 (Expected: Not Asymmetrical): ";
        std::cout << (isAsymmetricalGraph(graph3) ? "Asymmetrical" : "Not Asymmetrical") << std::endl;
        
        std::cout << "Test Case 4 (Expected: Asymmetrical): ";
        std::cout << (isAsymmetricalGraph(graph4) ? "Asymmetrical" : "Not Asymmetrical") << std::endl;
        
        // Print matrices for verification
        printMatrixWithTitle(graph1, "Matrix 1 (Cycle graph)");
        printMatrixWithTitle(graph2, "Matrix 2 (Bidirectional edges)");
        printMatrixWithTitle(graph3, "Matrix 3 (Self-loops and mixed edges)");
        printMatrixWithTitle(graph4, "Matrix 4 (Empty graph)");
        
        // Additional test with invalid matrix
        std::cout << "\n=== Testing Error Handling ===\n";
        
        // Test with invalid values
        std::vector<std::vector<int>> invalidGraph = {
            {0, 1, 2},  // Invalid value: 2
            {1, 0, 1},
            {0, 1, 0}
        };
        
        std::cout << "Invalid matrix test (contains value 2): ";
        std::cout << (isAsymmetricalGraph(invalidGraph) ? "Asymmetrical" : "Not Asymmetrical") << std::endl;
        
        // Test with non-square matrix
        std::vector<std::vector<int>> nonSquareGraph = {
            {0, 1},
            {1, 0},
            {0, 1}  // 3x2 matrix (not square)
        };
        
        std::cout << "Non-square matrix test: ";
        std::cout << (isAsymmetricalGraph(nonSquareGraph) ? "Asymmetrical" : "Not Asymmetrical") << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
