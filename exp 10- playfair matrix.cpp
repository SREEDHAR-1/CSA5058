#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I'; 
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptPair(char matrix[SIZE][SIZE], char a, char b, char *cipherPair) {
    int row1, col1, row2, col2;
    findPosition(matrix, a, &row1, &col1);
    findPosition(matrix, b, &row2, &col2);

    if (row1 == row2) {
        cipherPair[0] = matrix[row1][(col1 + 1) % SIZE];
        cipherPair[1] = matrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        cipherPair[0] = matrix[(row1 + 1) % SIZE][col1];
        cipherPair[1] = matrix[(row2 + 1) % SIZE][col2];
    } else {
        cipherPair[0] = matrix[row1][col2];
        cipherPair[1] = matrix[row2][col1];
    }
}
void encryptMessage(char matrix[SIZE][SIZE], const char *message, char *encryptedMessage) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i += 2, j += 2) {
        char a = toupper(message[i]);
        char b = (message[i + 1] == '\0') ? 'X' : toupper(message[i + 1]); 
        char cipherPair[2];
        encryptPair(matrix, a, b, cipherPair);
        encryptedMessage[j] = cipherPair[0];
        encryptedMessage[j + 1] = cipherPair[1];
    }
    encryptedMessage[j] = '\0';
}
int main() {
    char matrix[SIZE][SIZE] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };
    char message[] = "Must see you over Cadogan West. Coming at once.";
    char encryptedMessage[100]; 
    encryptMessage(matrix, message, encryptedMessage);
    printf("Encrypted Message: %s\n", encryptedMessage);
    return 0;
}
