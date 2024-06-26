#include <stdio.h>
long long power_mod(long long a, long long b, long long m) {
    long long result = 1;
    a %= m;

    while (b > 0) {
        if (b & 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }

    return result;
}

int main() {
    long long prime_modulus = 23; 
    long long generator = 5; 
    long long alice_secret = 6; 
    long long bob_secret = 15; 
    long long alice_public = alice_secret * generator % prime_modulus; 
    long long bob_public = bob_secret * generator % prime_modulus; 
    long long shared_secret_alice = power_mod(bob_public, alice_secret, prime_modulus); 
    long long shared_secret_bob = power_mod(alice_public, bob_secret, prime_modulus); 

    printf("Shared secret key (Alice): %lld\n", shared_secret_alice);
    printf("Shared secret key (Bob): %lld\n", shared_secret_bob);

    return 0;
}
