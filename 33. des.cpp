#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

// Function to handle errors
void handleErrors() {
    printf("Error occurred\n");
    exit(1);
}

// Function to perform DES encryption
void des_encrypt(const unsigned char *plaintext, const unsigned char *key, unsigned char *ciphertext) {
    DES_key_schedule key_schedule;
    DES_set_key((const_DES_cblock *)key, &key_schedule);
    DES_ecb_encrypt((const_DES_cblock *)plaintext, (DES_cblock *)ciphertext, &key_schedule, DES_ENCRYPT);
}

// Function to perform DES decryption
void des_decrypt(const unsigned char *ciphertext, const unsigned char *key, unsigned char *plaintext) {
    DES_key_schedule key_schedule;
    DES_set_key((const_DES_cblock *)key, &key_schedule);
    DES_ecb_encrypt((const_DES_cblock *)ciphertext, (DES_cblock *)plaintext, &key_schedule, DES_DECRYPT);
}

int main() {
    unsigned char plaintext[] = "Hello World!";
    unsigned char key[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef}; // 56-bit key
    unsigned char ciphertext[8];
    unsigned char decrypted_text[8];

    // Ensure the plaintext is padded to a multiple of 8 bytes (64 bits)
    int len = strlen((char *)plaintext);
    int padding = 8 - (len % 8);
    if (padding < 8) {
        memset(plaintext + len, padding, padding);
    }

    // Perform DES encryption
    des_encrypt(plaintext, key, ciphertext);

    // Display ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < 8; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Perform DES decryption
    des_decrypt(ciphertext, key, decrypted_text);

    // Remove padding from decrypted text
    int pad = decrypted_text[7];
    decrypted_text[7] = '\0';
    printf("Decrypted Text: %s\n", (char *)decrypted_text);

    return 0;
}

