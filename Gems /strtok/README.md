#### Strtok 

```
#include <iostream>
#include <cstring>
#include <vector>

// Example 1: Splitting a sentence into words
std::vector<std::string> splitSentence(char* sentence) {
    std::vector<std::string> words;
    char* token = strtok(sentence, " ");
    while (token != nullptr) {
        words.push_back(std::string(token));
        token = strtok(nullptr, " ");
    }
    return words;
}

// Example 2: Parsing CSV data
void parseCSV(char* csvLine) {
    const char* delimiters = ",";
    char* token = strtok(csvLine, delimiters);
    int columnIndex = 0;
    while (token != nullptr) {
        std::cout << "Column " << columnIndex << ": " << token << std::endl;
        token = strtok(nullptr, delimiters);
        columnIndex++;
    }
}

// Example 3: Extracting IP address octets
void parseIPAddress(char* ipAddress) {
    const char* delimiters = ".";
    char* token = strtok(ipAddress, delimiters);
    int octetIndex = 0;
    while (token != nullptr && octetIndex < 4) {
        int octet = std::stoi(token);
        std::cout << "Octet " << octetIndex + 1 << ": " << octet << std::endl;
        token = strtok(nullptr, delimiters);
        octetIndex++;
    }
}

int main() {
    // Example 1: Splitting a sentence into words
    char sentence[] = "The quick brown fox jumps over the lazy dog";
    auto words = splitSentence(sentence);
    std::cout << "Words in the sentence:" << std::endl;
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }
    std::cout << std::endl;

    // Example 2: Parsing CSV data
    char csvLine[] = "John,Doe,30,New York,Engineer";
    std::cout << "Parsing CSV data:" << std::endl;
    parseCSV(csvLine);
    std::cout << std::endl;

    // Example 3: Extracting IP address octets
    char ipAddress[] = "192.168.1.1";
    std::cout << "Parsing IP address:" << std::endl;
    parseIPAddress(ipAddress);

    return 0;
}
```
