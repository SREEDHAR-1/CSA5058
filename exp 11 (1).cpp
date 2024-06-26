#include <stdio.h>

int main() {
    long long int num_possible_keys = 1;
    int i;
    for (i = 26; i >= 22; i--) {
        num_possible_keys *= i;
    }
    num_possible_keys *= 21 * 20 * 19 * 18 * 17 / (5 * 4 * 3 * 2 * 1);

    printf("Approximate number of possible keys for Playfair cipher: %lld\n", num_possible_keys);

    return 0;
}
