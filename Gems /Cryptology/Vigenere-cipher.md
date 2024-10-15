Certainly! I'll provide you with an implementation of the Vigenère cipher in C++. The Vigenère cipher is a polyalphabetic substitution cipher that uses a keyword to encrypt plaintext.



```cpp
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

```

This implementation includes a `VigenereCipher` class with methods for encryption and decryption. Here's a breakdown of the code:

1. The `VigenereCipher` class is initialized with a keyword, which is converted to uppercase.

2. The `encrypt` method takes a plaintext string and applies the Vigenère cipher:
   - It iterates through each character of the plaintext.
   - For alphabetic characters, it applies the shift based on the corresponding keyword character.
   - Non-alphabetic characters are left unchanged.

3. The `decrypt` method reverses the encryption process:
   - It iterates through each character of the ciphertext.
   - For alphabetic characters, it applies the reverse shift based on the corresponding keyword character.
   - Non-alphabetic characters are left unchanged.

4. The `main` function demonstrates how to use the `VigenereCipher` class:
   - It prompts the user for a keyword and plaintext.
   - It creates a `VigenereCipher` object with the given keyword.
   - It encrypts the plaintext and then decrypts the resulting ciphertext.

This implementation preserves the case of the original plaintext and handles non-alphabetic characters by leaving them unchanged. The keyword is used repeatedly to encrypt/decrypt the entire message.
