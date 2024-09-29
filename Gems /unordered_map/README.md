#### Unordered_map

```
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

// Example 1: Two Sum Problem
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {}; // No solution found
}

// Example 2: Word Frequency Counter
std::unordered_map<std::string, int> wordFrequency(const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> frequency;
    for (const auto& word : words) {
        frequency[word]++;
    }
    return frequency;
}

// Example 3: First Non-Repeating Character
char firstNonRepeatingChar(const std::string& s) {
    std::unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }
    for (char c : s) {
        if (charCount[c] == 1) {
            return c;
        }
    }
    return '\0'; // No non-repeating character found
}

int main() {
    // Example 1: Two Sum
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto result = twoSum(nums, target);
    std::cout << "Two Sum Result: [" << result[0] << ", " << result[1] << "]\n";

    // Example 2: Word Frequency
    std::vector<std::string> words = {"apple", "banana", "apple", "cherry", "date", "banana"};
    auto freq = wordFrequency(words);
    std::cout << "Word Frequencies:\n";
    for (const auto& pair : freq) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    // Example 3: First Non-Repeating Character
    std::string str = "aabccdeff";
    char firstNonRepeat = firstNonRepeatingChar(str);
    std::cout << "First Non-Repeating Character: " << firstNonRepeat << "\n";

    return 0;
}
```

#### Codeforces:

https://codeforces.com/blog/entry/21853
