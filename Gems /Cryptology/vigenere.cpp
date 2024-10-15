#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

class VigenereCipher {
private:
    std::string keyword;

    // Helper function to convert a character to uppercase
    char toUpper(char ch) {
        return std::toupper(static_cast<unsigned char>(ch));
    }

public:
    VigenereCipher(const std::string& key) : keyword(key) {
        // Convert keyword to uppercase
        std::transform(keyword.begin(), keyword.end(), keyword.begin(), 
                       [this](unsigned char c){ return toUpper(c); });
    }

    std::string encrypt(const std::string& plaintext) {
        std::string ciphertext;
        size_t keyLength = keyword.length();
        size_t keyIndex = 0;

        for (char ch : plaintext) {
            if (std::isalpha(ch)) {
                char base = std::isupper(ch) ? 'A' : 'a';
                char encryptedChar = ((toUpper(ch) - 'A' + (keyword[keyIndex] - 'A')) % 26) + base;
                ciphertext += encryptedChar;
                keyIndex = (keyIndex + 1) % keyLength;
            } else {
                ciphertext += ch;
            }
        }

        return ciphertext;
    }

    std::string decrypt(const std::string& ciphertext) {
        std::string plaintext;
        size_t keyLength = keyword.length();
        size_t keyIndex = 0;

        for (char ch : ciphertext) {
            if (std::isalpha(ch)) {
                char base = std::isupper(ch) ? 'A' : 'a';
                char decryptedChar = ((toUpper(ch) - keyword[keyIndex] + 26) % 26) + base;
                plaintext += decryptedChar;
                keyIndex = (keyIndex + 1) % keyLength;
            } else {
                plaintext += ch;
            }
        }

        return plaintext;
    }
};

int main() {
    std::string keyword, plaintext;

    std::cout << "Enter the keyword: ";
    std::getline(std::cin, keyword);

    std::cout << "Enter the plaintext: ";
    std::getline(std::cin, plaintext);

    VigenereCipher cipher(keyword);

    std::string encrypted = cipher.encrypt(plaintext);
    std::cout << "Encrypted: " << encrypted << std::endl;

    std::string decrypted = cipher.decrypt(encrypted);
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
