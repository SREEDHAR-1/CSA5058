#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}
int decrypt(int ciphertext, int d, int n) {
    return fmod(pow(ciphertext, d), n);
}

int main() {
    int e = 65537; 
    int n = 104729 * 104723; 
    int encrypted_message[] = { 912, 280, 827, 874, 327, 613, 189, 843, 327, 448, 343, 453, 343, 613, 841, 827, 124 };
    int d = 6689906849; 
    int decrypted_message[18];
    for (int i = 0; i < 18; i++) {
        decrypted_message[i] = decrypt(encrypted_message[i], d, n);
    }
    printf("Decrypted message: ");
    for (int i = 0; i < 18; i++) {
        printf("%c", decrypted_message[i] + 'A');
    }
    printf("\n");

    return 0;
}
