#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

char encrypt_letter(int a, int b, char p) {
    int x = (p - 'a') * a + b;
    return 'a' + (x % ALPHABET_SIZE + ALPHABET_SIZE) % ALPHABET_SIZE;
}

char decrypt_letter(int a, int b, char c) {
    int a_inv;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if ((i * a) % ALPHABET_SIZE == 1) {
            a_inv = i;
            break;
        }
    }
    int x = (c - 'a' - b) * a_inv;
    return 'a' + (x % ALPHABET_SIZE + ALPHABET_SIZE) % ALPHABET_SIZE;
}

void encrypt(int a, int b, char plaintext[], char ciphertext[]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = encrypt_letter(a, b, plaintext[i]);
    }
    ciphertext[len] = '\0';
}

void decrypt(int a, int b, char ciphertext[], char plaintext[]) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        plaintext[i] = decrypt_letter(a, b, ciphertext[i]);
    }
    plaintext[len] = '\0';
}

int main() {
    int a, b;
    char plaintext[100], ciphertext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, 100, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key (a, b): ");
    scanf("%d %d", &a, &b);

    encrypt(a, b, plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(a, b, ciphertext, plaintext);
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}
