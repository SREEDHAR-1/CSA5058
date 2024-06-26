#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>

#define BUFSIZE 1024
#define BLOCK_SIZE 8

void handleErrors(void);
void print_hex(const char *title, const unsigned char *s, int len);
void encrypt_ecb(const unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *ciphertext);
void decrypt_ecb(const unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *plaintext);
void encrypt_cbc(const unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext);
void decrypt_cbc(const unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext);
void encrypt_cfb(const unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext);
void decrypt_cfb(const unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext);

int main() {
    unsigned char key[24] = "012345678901234567890123";
    unsigned char iv[8] = "abcdefgh";
    unsigned char plaintext[BUFSIZE] = "This is a secret message.";
    unsigned char ciphertext_ecb[BUFSIZE], ciphertext_cbc[BUFSIZE], ciphertext_cfb[BUFSIZE];
    unsigned char decryptedtext_ecb[BUFSIZE], decryptedtext_cbc[BUFSIZE], decryptedtext_cfb[BUFSIZE];
    int ciphertext_len_ecb, ciphertext_len_cbc, ciphertext_len_cfb;
    
    // ECB Mode
    encrypt_ecb(plaintext, strlen((char *)plaintext), key, ciphertext_ecb);
    decrypt_ecb(ciphertext_ecb, BLOCK_SIZE, key, decryptedtext_ecb);
    
    // CBC Mode
    encrypt_cbc(plaintext, strlen((char *)plaintext), key, iv, ciphertext_cbc);
    decrypt_cbc(ciphertext_cbc, BLOCK_SIZE, key, iv, decryptedtext_cbc);
    
    // CFB Mode
    encrypt_cfb(plaintext, strlen((char *)plaintext), key, iv, ciphertext_cfb);
    decrypt_cfb(ciphertext_cfb, BLOCK_SIZE, key, iv, decryptedtext_cfb);
    
    printf("Plaintext: %s\n", plaintext);
    print_hex("ECB Mode - Ciphertext", ciphertext_ecb, BLOCK_SIZE);
    printf("ECB Mode - Decrypted text: %s\n", decryptedtext_ecb);
    print_hex("CBC Mode - Ciphertext", ciphertext_cbc, BLOCK_SIZE);
    printf("CBC Mode - Decrypted text: %s\n", decryptedtext_cbc);
    print_hex("CFB Mode - Ciphertext", ciphertext_cfb, BLOCK_SIZE);
    printf("CFB Mode - Decrypted text: %s\n", decryptedtext_cfb);
    
    return 0;
}

void handleErrors(void) {
    printf("Error occurred!\n");
    exit(1);
}

void print_hex(const char *title, const unsigned char *s, int len) {
    printf("%s: ", title);
    for(int i = 0; i < len; i++) {
        printf("%02X", s[i]);
    }
    printf("\n");
}

void encrypt_ecb(const unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *ciphertext) {
    DES_key_schedule ks;
    DES_set_key((const_DES_cblock *)key, &ks);
    DES_ecb_encrypt((const_DES_cblock *)plaintext, (DES_cblock *)ciphertext, &ks, DES_ENCRYPT);
}

void decrypt_ecb(const unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *plaintext) {
    DES_key_schedule ks;
    DES_set_key((const_DES_cblock *)key, &ks);
    DES_ecb_encrypt((const_DES_cblock *)ciphertext, (DES_cblock *)plaintext, &ks, DES_DECRYPT);
}

void encrypt_cbc(const unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    DES_key_schedule ks;
    DES_set_key((const_DES_cblock *)key, &ks);
    DES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &ks, (DES_cblock *)iv, DES_ENCRYPT);
}

void decrypt_cbc(const unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    DES_key_schedule ks;
    DES_set_key((const_DES_cblock *)key, &ks);
    DES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &ks, (DES_cblock *)iv, DES_DECRYPT);
}

void encrypt_cfb(const unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    DES_key_schedule ks;
    DES_set_key((const_DES_cblock *)key, &ks);
    DES_cfb_encrypt(plaintext,
