#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
double frequencies[26] = {
    0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 
    0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 
    0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 
    0.00978, 0.02360, 0.00150, 0.01974, 0.00074                     
};
void decrypt(char *ciphertext, int shift) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                ciphertext[i] = ((ciphertext[i] - 'A' - shift + 26) % 26) + 'A';
            } else {
                ciphertext[i] = ((ciphertext[i] - 'a' - shift + 26) % 26) + 'a';
            }
        }
    }
}
double calculateScore(char *plaintext) {
    int count[26] = {0};
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            count[tolower(plaintext[i]) - 'a']++;
        }
    }
    double score = 0.0;
    for (int i = 0; i < 26; i++) {
        score += frequencies[i] * count[i];
    }
    return score;
}

int main() {
    char ciphertext[] = "Uifsf jt b tfdsfu qmfbtf xbju,  bgufs ejtdjqmjobsz. Uifsf jt b tfdsfu qmfbtf xbju, xip ibt cffo opu cf upvhi gps ju boe txffqjoh ipx jg cfuufs uif cvtjoftt, bgufs ejtdjqmjobsz.";
    int len = strlen(ciphertext);

    printf("Ciphertext: %s\n\n", ciphertext);

    printf("Possible Decryptions:\n");
    for (int shift = 1; shift < 26; shift++) {
        char plaintext[len + 1];
        strcpy(plaintext, ciphertext);
        decrypt(plaintext, shift);

        printf("Shift: %d, Plaintext: %s\n", shift, plaintext);
    }

    return 0;
}

