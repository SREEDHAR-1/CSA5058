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

int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
    int e = 31;
    int n = 3599;

    int p, q;
    for (p = 2; p < n; ++p) {
        if (n % p == 0) {
            q = n / p;
            break;
        }
    }

    int phi_n = (p - 1) * (q - 1);

    int d = mod_inverse(e, phi_n);
    printf("Private Key (d): %d\n", d);

    return 0;
}
