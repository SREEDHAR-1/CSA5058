#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void encrypt(char *plaintext, const int *key, int key_length) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            int shift = key[i % key_length];
            if (isupper(plaintext[i])) {
                plaintext[i] = (plaintext[i] - 'A' + shift) % 26 + 'A';
            } else {
                plaintext[i] = (plaintext[i] - 'a' + shift) % 26 + 'a';
            }
        }
    }
}
int main() {
    char plaintext[] = "Meet me at the usual place at ten rather than eight o'clock";
    int key[] = {3, 19, 5};
	int key_length = sizeof(key) / sizeof(key[0]);
	printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for (int i = 0; i < key_length; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");
    encrypt(plaintext, key, key_length);
    printf("Ciphertext: %s\n", plaintext);

    return 0;
}

