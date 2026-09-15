#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
 
using namespace std;
 
// Transformă textul într-un vector de cuvinte
vector<string> tokenize(const string& text) {
    vector<string> words;
    string word;
 
    stringstream ss(text);
 
    while (ss >> word) {
        // lowercase
        transform(word.begin(), word.end(),
                  word.begin(), ::tolower);
 
        words.push_back(word);
    }
 
    return words;
}
 
// Creează shingles de k cuvinte
unordered_set<string> getShingles(
    const string& text,
    int k
) {
    vector<string> words = tokenize(text);
 
    unordered_set<string> shingles;
 
    if (words.size() < k)
        return shingles;
 
    for (int i = 0; i <= words.size() - k; i++) {
 
        string shingle;
 
        for (int j = 0; j < k; j++) {
            if (!shingle.empty())
                shingle += " ";
 
            shingle += words[i + j];
        }
 
        shingles.insert(shingle);
    }
 
    return shingles;
}
 
// Calculează Jaccard similarity
double jaccard(
    const unordered_set<string>& A,
    const unordered_set<string>& B
) {
    int intersection = 0;
 
    // |A ∩ B|
    for (const string& x : A) {
        if (B.count(x))
            intersection++;
    }
 
    // |A ∪ B|
    int unionSize =
        A.size() + B.size() - intersection;
 
    if (unionSize == 0)
        return 1.0;
 
    return (double)intersection / unionSize;
}
 
int main() {
 
    string text1 =
        "Ana merge la facultate pentru examen";
 
    string text2 =
        "Ana merge la facultate pentru test";
 
    int k = 3;
 
    auto A = getShingles(text1, k);
    auto B = getShingles(text2, k);
 
    double similarity = jaccard(A, B);
 
    cout << "Similarity: "
         << similarity << endl;
 
    return 0;
}
