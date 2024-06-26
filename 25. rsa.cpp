#include <stdio.h>

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    
    int n = 3233; 
    int e = 17;   

    int plaintext_block = 561; 

    if (gcd(plaintext_block, n) > 1) {
        printf("Plaintext block shares a factor with n\n");
        printf("This information could be used as part of a larger attack strategy.\n");
    } else {
        printf("Plaintext block does not share a factor with n\n");
    }

    return 0;
}
