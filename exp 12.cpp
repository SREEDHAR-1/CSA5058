#include <stdio.h>
#define MOD 27 
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return 1;
}
void encryptMessage(const char* message, int key[][2]) {
    int len = 0;
    while (message[len] != '\0') len++;
    int numerical_message[len];
    for (int i = 0; i < len; i++) {
        if (message[i] == ' ') {
            numerical_message[i] = 26; // Space
        } else {
            numerical_message[i] = message[i] - 'a';
        }
    }
    printf("Encrypted message: ");
    for (int i = 0; i < len; i += 2) {
        int vector[2] = {numerical_message[i], (i + 1 < len) ? numerical_message[i + 1] : 26}; // Pair with space if odd length
        int encrypted_vector[2] = {
            (key[0][0] * vector[0] + key[0][1] * vector[1]) % MOD,
            (key[1][0] * vector[0] + key[1][1] * vector[1]) % MOD
        };
		printf("%c%c", encrypted_vector[0] + 'a', encrypted_vector[1] + 'a');
    }
    printf("\n");
}
void decryptMessage(const char* ciphertext, int key[][2]) {
    int len = 0;
    while (ciphertext[len] != '\0') len++;
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % MOD;
    if (det < 0) det += MOD;
    int det_inv = modInverse(det, MOD);
    int key_adj[2][2] = {
        {key[1][1], -key[0][1]},
        {-key[1][0], key[0][0]}
    };
    int key_inv[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            key_inv[i][j] = (key_adj[i][j] * det_inv) % MOD;
            if (key_inv[i][j] < 0) key_inv[i][j] += MOD;
        }
    }
    printf("Decrypted message: ");
    for (int i = 0; i < len; i += 2) {
        int vector[2] = {ciphertext[i] - 'a', (i + 1 < len) ? ciphertext[i + 1] - 'a' : 26}; // Pair with space if odd length
        int decrypted_vector[2] = {
            (key_inv[0][0] * vector[0] + key_inv[0][1] * vector[1]) % MOD,
            (key_inv[1][0] * vector[0] + key_inv[1][1] * vector[1]) % MOD
        };
		printf("%c%c", decrypted_vector[0] + 'a', decrypted_vector[1] + 'a');
    }
    printf("\n");
}
int main() {
    int key[2][2] = {
        {9, 4},
        {5, 7}
    };
    const char message[] = "meet me at the usual place at ten rather than eight oclock";
    encryptMessage(message, key);
    const char ciphertext[] = "zdwrzghniudtivbozwmvjrtsvhydtpakyzwhosnufkiwdxtvmrfkskxudkzrmbwbzpcnzmqlmmskszhltei";
    decryptMessage(ciphertext, key);

    return 0;
}

