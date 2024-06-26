#include <stdio.h>
#include <string.h>
void encryptCaesarCipher(char message[], int key) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        char character = message[i];

        if (character >= 'a' && character <= 'z') {
            character = 'a' + (character - 'a' + key) % 26;
        } else if (character >= 'A' && character <= 'Z') {
            character = 'A' + (character - 'A' + key) % 26;
        }
        message[i] = character;
    }
}
void decryptCaesarCipher(char message[], int key) {
    encryptCaesarCipher(message, 26 - key);
}
int main() {
    char message[100];
    int key;
    printf("Enter a message: ");
    gets(message);  
    printf("Enter the key (shift): ");
    scanf("%d", &key);
    encryptCaesarCipher(message, key);
    printf("Encrypted message: %s\n", message);
     decryptCaesarCipher(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}
