#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *plaintext, char *key) {
    int textLength = strlen(plaintext);
    int keyLength = strlen(key);
    for (int i = 0; i < textLength; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            int keyIndex = i % keyLength;
            int shift = tolower(key[keyIndex]) - 'a';
            plaintext[i] = (plaintext[i] - base + shift) % 26 + base;
        }
    }
}
int main() {
    char plaintext[1000];
    char key[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the key: ");
    scanf("%s", key);
    vigenereEncrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);
    return 0;
}
