#include <stdio.h>
#include <stdint.h>

// Define constants for block sizes
#define BLOCK_SIZE_64 64
#define BLOCK_SIZE_128 128

// Function to perform left circular shift
uint64_t left_shift(uint64_t value, int shift_amount) {
    return (value << shift_amount) | (value >> (64 - shift_amount));
}

// Function to generate subkeys for CMAC
void generate_subkeys(int block_size, uint64_t key, uint64_t *subkey1, uint64_t *subkey2) {
    // Define constants for block sizes
    uint64_t const1, const2;

    if (block_size == BLOCK_SIZE_64) {
        const1 = 0x0000000000000001;
        const2 = 0x0000000000000080;
    } else if (block_size == BLOCK_SIZE_128) {
        const1 = 0x00000000000000000000000000000001;
        const2 = 0x00000000000000000000000000000087;
    } else {
        printf("Unsupported block size\n");
        return;
    }

    // Derive the first subkey
    *subkey1 = (key << 1); // Left shift by 1 bit
    if ((key & (1 << (block_size - 1))) != 0) { // Check if leftmost bit is set
        *subkey1 ^= const1; // XOR with constant
    }

    // Derive the second subkey
    *subkey2 = (*subkey1 << 1); // Left shift by 1 bit
    if ((*subkey1 & (1 << (block_size - 1))) != 0) { // Check if leftmost bit is set
        *subkey2 ^= const2; // XOR with constant
    }
}

int main() {
    uint64_t key = 0x0123456789ABCDEF; // Example key
    uint64_t subkey1, subkey2;

    printf("Subkeys for block size 64:\n");
    generate_subkeys(BLOCK_SIZE_64, key, &subkey1, &subkey2);
    printf("Subkey 1: %llx\n", subkey1);
    printf("Subkey 2: %llx\n", subkey2);

    printf("\nSubkeys for block size 128:\n");
    generate_subkeys(BLOCK_SIZE_128, key, &subkey1, &subkey2);
    printf("Subkey 1: %llx\n", subkey1);
    printf("Subkey 2: %llx\n", subkey2);

    return 0;
}

