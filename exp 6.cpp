#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

void count_frequency(const char *text, int *freq) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            freq[text[i] - 'A']++;
    }
}

int find_most_frequent(const int *freq) {
    int max_freq_index = 0, i;
    for (i = 1; i < ALPHABET_SIZE; i++) {
        if (freq[i] > freq[max_freq_index]) {
            max_freq_index = i;
        }
    }
    return max_freq_index;
}

int main() {
    char ciphertext[1000];
    int freq[ALPHABET_SIZE] = {0};
    int most_freq_index, second_most_freq_index;
    int b_index = 'B' - 'A';
    int u_index = 'U' - 'A';
    int a, b;

    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0'; // Remove newline character if present

    count_frequency(ciphertext, freq);

    most_freq_index = find_most_frequent(freq);

    // Replace the most frequent character with 'B'
    a = mod_inverse(most_freq_index - b_index, ALPHABET_SIZE);
    b = (b_index - (a * (most_freq_index - 'A'))) % ALPHABET_SIZE;
    if (b < 0)
        b += ALPHABET_SIZE;

    // Decipher the ciphertext
    printf("Deciphered text:\n");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int decrypted_char = (a * (ciphertext[i] - 'A') + b) % ALPHABET_SIZE;
            if (decrypted_char < 0)
                decrypted_char += ALPHABET_SIZE;
            printf("%c", decrypted_char + 'A');
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");

    return 0;
}

