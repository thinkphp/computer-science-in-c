#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~"

// Function to generate a random password of the specified length
void generatePassword(int length, char* password) {
    int i;
    int charsetLength = strlen(CHARSET);

    srand((unsigned int)time(NULL));

    for (i = 0; i < length; ++i) {
        int index = rand() % charsetLength;
        password[i] = CHARSET[index];
    }

    password[length] = '\0';
}

int main(int argc, char* argv[]) {
    int length = 12; // Default password length

    // Parse command line arguments
    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            printf("Usage: %s [options]\n", argv[0]);
            printf("Options:\n");
            printf("  -l, --length  Length of the password (default: 12)\n");
            return 0;
        } else if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--length") == 0) {
            if (argc > 2) {
                length = atoi(argv[2]);
            } else {
                fprintf(stderr, "Error: Missing argument for password length.\n");
                return 1;
            }
        } else {
            fprintf(stderr, "Error: Invalid command-line argument.\n");
            fprintf(stderr, "Use '%s --help' for usage.\n", argv[0]);
            return 1;
        }
    }

    // Generate password
    char password[length + 1];
    generatePassword(length, password);

    // Print the generated password
    printf("Generated Password: %s\n", password);

    return 0;
}
