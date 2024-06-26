#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
void calculateLetterFrequency(char *text, int *frequency) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char c = tolower(text[i]);
            frequency[c - 'a']++;
        }
    }
}
void letterFrequencyAttack(char *cipherText, int topPlaintexts) {
    int frequency[ALPHABET_SIZE] = {0};
    calculateLetterFrequency(cipherText, frequency);
    int frequencyCopy[ALPHABET_SIZE];
    memcpy(frequencyCopy, frequency, sizeof(frequency));
	int maxFrequency, maxIndex;
    char mapping[ALPHABET_SIZE];
	printf("Top %d possible plaintexts:\n", topPlaintexts);
    for (int k = 0; k < topPlaintexts; k++) {
        maxFrequency = -1;
        maxIndex = -1;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (frequency[i] > maxFrequency) {
                maxFrequency = frequency[i];
                maxIndex = i;
            }
        }
        mapping[maxIndex] = 'e';
        frequency[maxIndex] = -1;
        printf("Mapping: %c -> %c\n", maxIndex + 'a', mapping[maxIndex]);
    }
}
int main() 
{
    char cipherText[1000];
    int topPlaintexts;
	printf("Enter the ciphertext: ");
    fgets(cipherText, sizeof(cipherText), stdin);
	printf("Enter the number of top possible plaintexts to display: ");
    scanf("%d", &topPlaintexts);
    letterFrequencyAttack(cipherText, topPlaintexts);
	return 0;
}
