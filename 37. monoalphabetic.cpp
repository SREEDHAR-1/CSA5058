#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
void calculate_letter_frequency(const char *text, int *frequency) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int index = tolower(text[i]) - 'a';
            frequency[index]++;
        }
    }
}
void decrypt_with_key(const char *ciphertext, const int *key, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base_char = islower(ciphertext[i]) ? 'a' : 'A';
            int index = tolower(ciphertext[i]) - 'a';
            plaintext[i] = key[index] + base_char;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; 
}
int find_most_frequent_letter(const int *frequency) {
    int max_freq = 0;
    int max_index = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (frequency[i] > max_freq) {
            max_freq = frequency[i];
            max_index = i;
        }
    }
    return max_index;
}
void letter_frequency_attack(const char *ciphertext, char *plaintext) {
    int frequency[ALPHABET_SIZE] = {0};
    calculate_letter_frequency(ciphertext, frequency);
    int most_frequent_index = find_most_frequent_letter(frequency);
    int key[ALPHABET_SIZE];
    int shift = (most_frequent_index + ALPHABET_SIZE - ('e' - 'a')) % ALPHABET_SIZE;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        key[i] = (i - shift + ALPHABET_SIZE) % ALPHABET_SIZE;
    }
    decrypt_with_key(ciphertext, key, plaintext);
}
int main() {
    const char *ciphertext = "Gwc uivioml bw nqvl bpm zqopb apqnb";
    char plaintext[100]; 
    letter_frequency_attack(ciphertext, plaintext);
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}
