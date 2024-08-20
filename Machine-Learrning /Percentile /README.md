Calculating percentiles in C++ involves a few steps, including sorting the data and then using the appropriate formula to find the percentile value. Here’s how you can calculate the 75th percentile for an array of ages in C++:

### Steps:

1. **Sort the Data**: Use the standard library function `std::sort` to sort the data in ascending order.
2. **Calculate the Percentile Index**: Use the percentile formula to determine the index.
3. **Handle the Index Calculation**: Ensure the index is within bounds and handle the case where the index is not an integer (interpolation).

### Example Code

Here’s a complete example to calculate the 75th percentile:

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <cmath>     // For std::ceil

// Function to calculate the percentile
double calculatePercentile(std::vector<int>& data, double percentile) {
    // Sort the data
    std::sort(data.begin(), data.end());

    // Calculate the index
    double rank = percentile / 100.0 * (data.size() - 1);
    int lowerIndex = static_cast<int>(std::floor(rank));
    int upperIndex = static_cast<int>(std::ceil(rank));

    // Handle boundary cases
    if (lowerIndex < 0) lowerIndex = 0;
    if (upperIndex >= data.size()) upperIndex = data.size() - 1;

    // Interpolate if needed
    if (lowerIndex == upperIndex) {
        return data[lowerIndex];
    } else {
        double weight = rank - lowerIndex;
        return data[lowerIndex] * (1 - weight) + data[upperIndex] * weight;
    }
}

int main() {
    // Array of ages
    std::vector<int> ages = {5, 31, 43, 48, 50, 41, 7, 11, 15, 39, 80, 82, 32, 2, 8, 6, 25, 36, 27, 61, 31};

    // Percentile to calculate
    double percentile = 75.0;

    // Calculate the 75th percentile
    double result = calculatePercentile(ages, percentile);

    // Print the result
    std::cout << percentile << "th percentile: " << result << " years old" << std::endl;

    return 0;
}
```

### Explanation:

1. **Sorting**:
   ```cpp
   std::sort(data.begin(), data.end());
   ```

2. **Calculating the Index**:
   - The rank is calculated with the formula `percentile / 100.0 * (data.size() - 1)`.
   - Use `std::floor` and `std::ceil` to determine the lower and upper indices for interpolation.

3. **Interpolation**:
   - If the lower index is equal to the upper index, no interpolation is needed.
   - Otherwise, interpolate between the values at the lower and upper indices based on the fractional part of the rank.

### Key Points:

- **Handling Bounds**: Ensure indices are within valid range.
- **Interpolation**: Provides a more accurate result if the rank is not an integer.

This method calculates the percentile value and handles the sorting and interpolation required for accurate results.
