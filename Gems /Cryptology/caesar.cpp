#include <iostream>
#include <string>
#include <algorithm>

std::string caesarCipher(std::string text, int shift) {
  std::string result = "";
  for (char& c : text) {
    if (std::isalpha(c)) {
      char start = std::islower(c) ? 'a' : 'A';
      c = start + (c - start + shift) % 26;
    }
    result += c;
  }
  return result;
}

int main() {
  std::string text = "Hello, world!";
  int shift = 3;
  std::string encrypted = caesarCipher(text, shift);
  std::string decrypted = caesarCipher(encrypted, -shift);
  std::cout << "Text: " << text << std::endl;
  std::cout << "Encrypted: " << encrypted << std::endl;
  std::cout << "Decrypted: " << decrypted << std::endl;
  return 0;
}
