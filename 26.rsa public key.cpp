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
void generateKeys(int p, int q, int *e, int *d, int *n) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    *e = 2; 
    while (gcd(*e, phi) != 1) {
        (*e)++;
    }
    *d = modInverse(*e, phi);
}
int encrypt(int plaintext, int e, int n) {
    return fmod(pow(plaintext, e), n);
}
int decrypt(int ciphertext, int d, int n) {
    return fmod(pow(ciphertext, d), n);
}

int main() {
    int p = 61; 
    int q = 53; 
    int e, d, n; 

    generateKeys(p, q, &e, &d, &n);

    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d, n): (%d, %d)\n", d, n);

    int plaintext = 42; // Message to be encrypted
    int ciphertext = encrypt(plaintext, e, n);
    int decryptedtext = decrypt(ciphertext, d, n);

    printf("Plaintext: %d\n", plaintext);
    printf("Encrypted text: %d\n", ciphertext);
    printf("Decrypted text: %d\n", decryptedtext);

    return 0;
}

