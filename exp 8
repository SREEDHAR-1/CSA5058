#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to generate the cipher sequence from a keyword
void generateCipherSequence(const char *keyword, char *cipherSequence) {
    int i, j;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Let the compiler determine the size

    // Copy the keyword into the beginning of the cipher sequence
    strcpy(cipherSequence, keyword);
    int keywordLength = strlen(keyword);

    // Remove duplicate letters from the keyword
    for (i = 0; i < keywordLength; i++) {
        for (j = i + 1; j < keywordLength; j++) {
            if (cipherSequence[i] == cipherSequence[j]) {
                for (int k = j; k < keywordLength - 1; k++) {
                    cipherSequence[k] = cipherSequence[k + 1];
                }
                cipherSequence[keywordLength - 1] = '\0';
                keywordLength--;
                j--;
            }
        }
    }

    // Append unused letters from the alphabet to the cipher sequence
    int index = strlen(cipherSequence);
    for (i = 0; i < 26; i++) {
        if (!strchr(cipherSequence, alphabet[i])) {
            cipherSequence[index++] = alphabet[i];
        }
    }
    cipherSequence[index] = '\0';
}

// Function to encrypt plaintext using the generated cipher sequence
void encrypt(const char *plaintext, const char *cipherSequence, char *encryptedText) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                encryptedText[i] = cipherSequence[plaintext[i] - 'A'];
            } else {
                encryptedText[i] = tolower(cipherSequence[toupper(plaintext[i]) - 'A']);
            }
        } else {
            encryptedText[i] = plaintext[i]; // Preserve non-alphabetic characters
        }
    }
    encryptedText[i] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "HELLO WORLD";
    char cipherSequence[26 + 1];
    char encryptedText[strlen(plaintext) + 1];

    generateCipherSequence(keyword, cipherSequence);
    printf("Generated Cipher Sequence: %s\n", cipherSequence);

    encrypt(plaintext, cipherSequence, encryptedText);
    printf("Encrypted Text: %s\n", encryptedText);

    return 0;
}
