#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to prepare the key matrix
void prepareKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int i, j, k;
    char *ptr, *temp;

    // Initialize key matrix with 0's
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            keyMatrix[i][j] = 0;
        }
    }

    // Insert key into key matrix
    ptr = key;
    for(i = 0; i < strlen(key); i++) {
        if(*ptr == 'j') // Replacing 'j' with 'i'
            *ptr = 'i';
        for(k = 0; k < SIZE; k++) {
            for(j = 0; j < SIZE; j++) {
                if(keyMatrix[k][j] == 0) {
                    keyMatrix[k][j] = *ptr;
                    break;
                }
            }
            if(j != SIZE)
                break;
        }
        ptr++;
    }

    // Fill the remaining key matrix with other alphabets
    temp = "abcdefghi/jklmnopqrstuvwxyz";
    ptr = temp;
    while(*ptr != '\0') {
        for(k = 0; k < SIZE; k++) {
            for(j = 0; j < SIZE; j++) {
                if(keyMatrix[k][j] == 0) {
                    keyMatrix[k][j] = *ptr;
                    break;
                }
            }
            if(j != SIZE)
                break;
        }
        ptr++;
    }
}

// Function to find the position of a character in the key matrix
void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a pair of characters
void encryptPair(char keyMatrix[SIZE][SIZE], char a, char b) {
    int row1, col1, row2, col2;

    findPosition(keyMatrix, a, &row1, &col1);
    findPosition(keyMatrix, b, &row2, &col2);

    if(row1 == row2) { // Same row
        printf("%c%c ", keyMatrix[row1][(col1 + 1) % SIZE], keyMatrix[row2][(col2 + 1) % SIZE]);
    } else if(col1 == col2) { // Same column
        printf("%c%c ", keyMatrix[(row1 + 1) % SIZE][col1], keyMatrix[(row2 + 1) % SIZE][col2]);
    } else { // Forming rectangle
        printf("%c%c ", keyMatrix[row1][col2], keyMatrix[row2][col1]);
    }
}

int main() {
    char key[] = "keyword"; // Example key
    char plaintext[] = "meet me tomorrow"; // Example plaintext
    char keyMatrix[SIZE][SIZE];
    int i;

    prepareKeyMatrix(key, keyMatrix);

    printf("Key Matrix:\n");
    for(i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", keyMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Plaintext: %s\n", plaintext);
    printf("Encrypted Text: ");

    // Encrypting the plaintext
    for(i = 0; i < strlen(plaintext); i += 2) {
        if(plaintext[i] == plaintext[i + 1]) {
            encryptPair(keyMatrix, plaintext[i], 'x');
            i--;
        } else if(plaintext[i + 1] == '\0') {
            encryptPair(keyMatrix, plaintext[i], 'x');
        } else {
            encryptPair(keyMatrix, plaintext[i], plaintext[i + 1]);
        }
    }
    printf("\n");

    return 0;
}
