#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Function to find the mediant of two fractions
pair<int, int> mediant(int a, int b, int c, int d) {
    return make_pair(a + c, b + d);
}

// Function to generate the Farey sequence of order n
vector<pair<int, int>> farey_sequence(int n) {
    // Initialize the sequence with 0/1 and 1/1
    vector<pair<int, int>> farey_seq = { {0, 1}, {1, 1} };

    // Use a while loop to generate the Farey sequence
    size_t i = 0;
    while (i < farey_seq.size() - 1) {
        int a = farey_seq[i].first;
        int b = farey_seq[i].second;
        int c = farey_seq[i + 1].first;
        int d = farey_seq[i + 1].second;
        // Find the mediant fraction
        pair<int, int> med = mediant(a, b, c, d);
        int med_num = med.first;
        int med_den = med.second;
        if (med_den <= n) {
            farey_seq.insert(farey_seq.begin() + i + 1, med);
        } else {
            ++i;
        }
    }

    return farey_seq;
}

int main() {
    // Generate Farey sequence of order 5
    int n = 5;
    vector<pair<int, int>> farey_seq = farey_sequence(n);
    for (const auto& frac : farey_seq) {
        cout << frac.first << "/" << frac.second << endl;
    }
    return 0;
}
