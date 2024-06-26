#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

char encrypt(char letter, char key[]) {
    if (isalpha(letter)) {
        char base = isupper(letter) ? 'A' : 'a';
        return key[letter - base];
    }
    return letter;
}

void monoalphabeticEncrypt(char message[], char key[]) {
    int i = 0;
    while (message[i] != '\0') {
        message[i] = encrypt(message[i], key);
        i++;
    }
}

int main() {
    char message[1000];
    char key[ALPHABET_SIZE + 1] = "ZYXWVUTSRQPONMLKJIHGFEDCBA"; // Example key (reverse alphabet)

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Original message: %s\n", message);

    monoalphabeticEncrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
