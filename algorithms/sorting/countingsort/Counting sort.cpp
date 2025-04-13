#include <iostream>
#include <vector>
#include <algorithm>

void countSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum element to determine the range
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    // Create count array and initialize to 0
    std::vector<int> count(range), output(arr.size());
    
    // Store count of each element
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - min]++;
    }

    // Change count[i] so that it contains actual position of this element in output
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Copy the output array to arr
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    std::vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    countSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
