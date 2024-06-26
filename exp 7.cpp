#include <stdio.h>
#include <string.h>

// Function to decrypt the ciphertext
void decrypt(char *ciphertext) {
    int i;
    char decrypted[strlen(ciphertext)];

    for (i = 0; i < strlen(ciphertext); i++) {
        // Perform decryption based on the given substitution algorithm
        if (ciphertext[i] == '4') {
            decrypted[i] = 'a';
        } else if (ciphertext[i] == '8') {
            decrypted[i] = 'b';
        } else if (ciphertext[i] == '5') {
            decrypted[i] = 'c';
        } else if (ciphertext[i] == '3') {
            decrypted[i] = 'd';
        } else if (ciphertext[i] == '6') {
            decrypted[i] = 'e';
        } else if (ciphertext[i] == ';') {
            decrypted[i] = 'f';
        } else if (ciphertext[i] == '0') {
            decrypted[i] = 'g';
        } else if (ciphertext[i] == '9') {
            decrypted[i] = 'h';
        } else if (ciphertext[i] == '1') {
            decrypted[i] = 'i';
        } else if (ciphertext[i] == '2') {
            decrypted[i] = 'j';
        } else if (ciphertext[i] == '‡') {
            decrypted[i] = 'k';
        } else if (ciphertext[i] == '†') {
            decrypted[i] = 'l';
        } else if (ciphertext[i] == '¶') {
            decrypted[i] = 'm';
        } else if (ciphertext[i] == ']') {
            decrypted[i] = 'n';
        } else if (ciphertext[i] == '-') {
            decrypted[i] = 'o';
        } else if (ciphertext[i] == '?') {
            decrypted[i] = 'p';
        } else if (ciphertext[i] == '(') {
            decrypted[i] = 'q';
        } else if (ciphertext[i] == ')') {
            decrypted[i] = 'r';
        } else if (ciphertext[i] == ':') {
            decrypted[i] = 's';
        } else if (ciphertext[i] == ':') {
            decrypted[i] = 't';
        } else if (ciphertext[i] == '*') {
            decrypted[i] = 'u';
        } else if (ciphertext[i] == '.') {
            decrypted[i] = 'v';
        } else if (ciphertext[i] == ']') {
            decrypted[i] = 'w';
        } else if (ciphertext[i] == '-') {
            decrypted[i] = 'x';
        } else if (ciphertext[i] == '—') {
            decrypted[i] = 'y';
        } else if (ciphertext[i] == ':') {
            decrypted[i] = 'z';
        } else {
            decrypted[i] = ciphertext[i];
        }
    }

    decrypted[i] = '\0'; // Null-terminate the decrypted string
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    decrypt(ciphertext);
    return 0;
}

