#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
#define MAX_TEXT_LENGTH 100
int char_to_index(char c) {
    return tolower(c) - 'a';
}
char index_to_char(int index) {
    return index + 'a';
}
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; 
}
int gaussian_elimination(double matrix[][MAX_TEXT_LENGTH + 1], int size) {
    for (int i = 0; i < size; i++) {
        double max_val = fabs(matrix[i][i]);
        int max_row = i;
        for (int k = i + 1; k < size; k++) {
            if (fabs(matrix[k][i]) > max_val) {
                max_val = fabs(matrix[k][i]);
                max_row = k;
            }
        }
        if (max_row != i) {
            for (int k = i; k <= size; k++) {
                double temp = matrix[i][k];
                matrix[i][k] = matrix[max_row][k];
                matrix[max_row][k] = temp;
            }
        }
        for (int k = i + 1; k < size; k++) {
            double ratio = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= size; j++) {
                matrix[k][j] -= ratio * matrix[i][j];
            }
        }
    }
    double solution[size];
    for (int i = size - 1; i >= 0; i--) {
        solution[i] = matrix[i][size];
        for (int j = i + 1; j < size; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }
    printf("Key matrix (mod 26):\n");
    for (int i = 0; i < size; i++) {
        printf("%.0f ", solution[i]);
    }
    printf("\n");

    return 0;
}
void hill_known_plaintext_attack(const char *plaintext, const char *ciphertext, int key_size) {
    int n = strlen(plaintext);
    double matrix[key_size][MAX_TEXT_LENGTH + 1]; 
    for (int i = 0; i < key_size; i++) {
        for (int j = 0; j < key_size; j++) {
            matrix[i][j] = fmod(pow(char_to_index(plaintext[i]), j), ALPHABET_SIZE); 
        }
        matrix[i][key_size] = char_to_index(ciphertext[i]);
    }
    gaussian_elimination(matrix, key_size);
}
int main() {
    const char *plaintext = "hello"; 
    const char *ciphertext = "hxqtx"; 
    int key_size = 2; 
    hill_known_plaintext_attack(plaintext, ciphertext, key_size);

    return 0;
}
