#include <stdio.h>
void xorOperation(unsigned char *plaintext, unsigned char *key, int block_size) {
    for (int i = 0; i < block_size; ++i) {
        plaintext[i] ^= key[i];
    }
}
void encryptECB(unsigned char *plaintext, unsigned char *key, int block_size) {
    xorOperation(plaintext, key, block_size);
}
void encryptCBC(unsigned char *plaintext, unsigned char *key, unsigned char *iv, int block_size, int num_blocks) {
    xorOperation(plaintext, iv, block_size);
    xorOperation(plaintext, key, block_size);

    for (int i = 1; i < num_blocks; ++i) {
        xorOperation(plaintext + i * block_size, key, block_size);
    }
}
void decryptCBC(unsigned char *ciphertext, unsigned char *key, unsigned char *iv, int block_size, int num_blocks) {
    for (int i = num_blocks - 1; i >= 1; --i) {
        xorOperation(ciphertext + i * block_size, key, block_size);
    }

    xorOperation(ciphertext, key, block_size);
    xorOperation(ciphertext, iv, block_size);
}
int main() {
    unsigned char key[] = "SECRETKEY"; 
    unsigned char iv[] = "INITVECTOR"; 
    unsigned char plaintext[] = "PLAINTEXT"; 
    int block_size = 8; 
    int num_blocks = sizeof(plaintext) / block_size;
    encryptECB(plaintext, key, block_size * num_blocks);
    unsigned char encrypted_cbc[sizeof(plaintext)];
    for (int i = 0; i < sizeof(plaintext); ++i) {
        encrypted_cbc[i] = plaintext[i];
    }
    encryptCBC(encrypted_cbc, key, iv, block_size, num_blocks);
    encrypted_cbc[0] ^= 0x01;
    decryptCBC(encrypted_cbc, key, iv, block_size, num_blocks);
    printf("Decrypted Result (ECB): %s\n", plaintext);
    printf("Decrypted Result (CBC with Error): %s\n", encrypted_cbc);
    return 0;
}
