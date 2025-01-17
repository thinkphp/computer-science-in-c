#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Funcție pentru generarea unei chei aleatoare de aceeași lungime ca textul
void generateKey(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256; // Generăm valori între 0 și 255
    }
}

// Funcție pentru criptare/decriptare folosind XOR
void vernamCipher(char *input, char *key, char *output, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i]; // Aplicăm XOR între text și cheie
    }
}

int main() {
    // Textul de criptat
    char text[] = "HELLO VERNAM";
    int length = strlen(text);

    // Alocăm spațiu pentru cheie și textul criptat
    char key[length];
    char encrypted[length];
    char decrypted[length];

    // Generăm o cheie aleatorie
    generateKey(key, length);

    // Criptăm textul
    vernamCipher(text, key, encrypted, length);

    // Decriptăm textul
    vernamCipher(encrypted, key, decrypted, length);

    // Afișăm rezultatele
    printf("Text original: %s\n", text);
    printf("Cheia: ");
    for (int i = 0; i < length; i++) {
        printf("%02X ", (unsigned char)key[i]); // Afișăm cheia în format hex
    }
    printf("\nText criptat: ");
    for (int i = 0; i < length; i++) {
        printf("%02X ", (unsigned char)encrypted[i]); // Afișăm textul criptat în format hex
    }
    printf("\nText decriptat: %s\n", decrypted);

    return 0;
}
