#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define BLOCK_SIZE 1024
void initialize_state(uint64_t state[5][5]) {
    memset(state, 0, sizeof(uint64_t) * 5 * 5);
}
void sha3(const uint8_t *message, size_t message_len, uint64_t hash[5][5]) {
    uint64_t state[5][5];
    initialize_state(state);
    memcpy(hash, state, sizeof(uint64_t) * 5 * 5);
}
int main() {
    uint8_t message[] = "Hello, world!";
    size_t message_len = strlen((char *)message);
    uint64_t hash[5][5];
    sha3(message, message_len, hash);
    printf("SHA-3 hash:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%016lx ", hash[i][j]);
        }
        printf("\n");
    }

    return 0;
}

