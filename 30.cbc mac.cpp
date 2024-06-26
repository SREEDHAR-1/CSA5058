#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define BLOCK_SIZE 16 
void aes_encrypt(uint8_t *plaintext, uint8_t *key, uint8_t *ciphertext) {
    memcpy(ciphertext, plaintext, BLOCK_SIZE);
}
void cbc_mac(uint8_t *message, size_t message_len, uint8_t *key, uint8_t *mac) {
    uint8_t iv[BLOCK_SIZE] = {0}; 
    uint8_t temp[BLOCK_SIZE];
    aes_encrypt(message, key, mac);
    for (size_t i = 0; i < message_len; i++) {
        mac[i] ^= message[i];
    }
}
int main() {
    uint8_t key[BLOCK_SIZE] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x97, 0x20, 0x43, 0x69, 0xa5, 0x89}; // 128-bit key
    uint8_t message[BLOCK_SIZE] = {0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a}; // One-block message
    uint8_t mac[BLOCK_SIZE];
    cbc_mac(message, BLOCK_SIZE, key, mac);
    printf("CBC MAC for one-block message:\n");
    for (size_t i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", mac[i]);
    }
    printf("\n");
    uint8_t two_block_message[2 * BLOCK_SIZE];
    memcpy(two_block_message, message, BLOCK_SIZE);
    for (size_t i = 0; i < BLOCK_SIZE; i++) {
        two_block_message[BLOCK_SIZE + i] = message[i] ^ mac[i];
    }
    cbc_mac(two_block_message, 2 * BLOCK_SIZE, key, mac);
    printf("CBC MAC for two-block message:\n");
    for (size_t i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", mac[i]);
    }
    printf("\n");

    return 0;
}

