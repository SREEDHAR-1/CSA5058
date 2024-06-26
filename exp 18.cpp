#include <stdio.h>
#include <stdint.h>
static const int IP[] = { 2, 6, 3, 1, 4, 8, 5, 7 };
static const int PC1[] = { 2, 4, 1, 6, 3, 9, 0, 8, 5, 7 };
static const int PC2[] = { 5, 2, 6, 3, 7, 4, 9, 8 };
static const uint64_t KEY = 0x0000FFFFFFFFFFFF;
uint64_t permute(uint64_t input, const int *table, int size) {
uint64_t result = 0;
int i;
for ( i = 0; i < size; i++) {
result |= ((input >> (64 - table[i])) & 1) << (size - 1 - i);
}
return result;
}
void generate_subkeys(uint64_t key, uint64_t *subkeys) {
key = permute(key, PC1, 56);
int i;
for ( i = 0; i < 16; i++) {
uint64_t shifted_key = (key << i) | (key >> (28 - i));
subkeys[i] = permute(shifted_key, PC2, 48);
}
}
int main() {
uint64_t subkeys[16];
generate_subkeys(KEY, subkeys);
int i;
printf("Generated Subkeys:\n");
for (i = 0; i < 16; i++) {
printf("K%d: 0x%012llX\n", i + 1, subkeys[i]);
}   
return 0;
} 
