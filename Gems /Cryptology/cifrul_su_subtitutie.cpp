#include <iostream>
#include <string>
#include <map>

std::string substitutionCipher(std::string text, std::map<char, char> key, bool encrypt) {
    std::string result = "";

    // If decrypting, create a reverse key
    std::map<char, char> reverseKey;
    for (const auto& pair : key) {
        reverseKey[pair.second] = pair.first;  // map encrypted char back to original
    }

    for (char c : text) {
        if (encrypt) {
            result += (key.count(c) ? key[c] : c); // Encrypt
        } else {
            result += (reverseKey.count(c) ? reverseKey[c] : c); // Decrypt
        }
    }

    return result;
}

int main() {
    std::map<char, char> key = {
        {'a', 'q'}, {'b', 'w'}, {'c', 'e'}, {'d', 'r'}, {'e', 't'},
        {'f', 'y'}, {'g', 'u'}, {'h', 'i'}, {'i', 'o'}, {'j', 'p'},
        {'k', 'a'}, {'l', 's'}, {'m', 'd'}, {'n', 'f'}, {'o', 'g'},
        {'p', 'h'}, {'q', 'j'}, {'r', 'k'}, {'s', 'l'}, {'t', 'z'},
        {'u', 'x'}, {'v', 'c'}, {'w', 'v'}, {'x', 'b'}, {'y', 'n'},
        {'z', 'm'}
    };

    std::string text = "Hello, world!";
    std::string encrypted = substitutionCipher(text, key, true);
    std::string decrypted = substitutionCipher(encrypted, key, false);

    std::cout << "Text: " << text << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
