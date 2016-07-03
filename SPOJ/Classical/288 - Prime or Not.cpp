#include <cstdio>
#include <cstdlib>
using namespace std;

typedef     unsigned long long       ULL;

ULL modular_mul(ULL a, ULL b, ULL modulus)
{
    ULL result = 0;
    a %= modulus;

    while(b > 0) {
        if(b & 1) {
            result = (result + a) % modulus;
        }

        a = (2 * a) % modulus;
        b >>= 1;                            // b /= 2.
    }

    return result % modulus;
}

ULL modular_pow(ULL base, ULL exponent, ULL modulus)
{
    if(modulus == 1) return 0;

    ULL result = 1;
    base %= modulus;

    while(exponent > 0) {
        if(exponent & 1) {
            result = modular_mul(result, base, modulus);
        }

        exponent >>= 1;
        base = modular_mul(base, base, modulus);
    }

    return result;
}

bool isPrime(ULL n, int iteration)
{
    if(n < 2) return false;
    if(n <= 3) return true;
    if(!(n & 1)) return false;              // If n is even.

    ULL d = n-1;                             // d * 2^r = n-1 where d is odd and r > 0.
    while(!(d & 1))
        d >>= 1;

    while(iteration--) {                    // Witness loop.
        ULL a = rand() % (n-1) + 1;
        ULL x = modular_pow(a, d, n);        // x = a^d % n
        ULL d1 = d;

        while(d1 != n-1 && x != 1 && x != n-1) {
            x = modular_mul(x, x, n);
            d1 <<= 1;
        }

        if(x != n-1 && !(d1 & 1)) {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    scanf("%d", &t);

    ULL n;

    while(t--) {
        scanf("%llu", &n);

        (isPrime(n, 5))? puts("YES") : puts("NO");
    }

    return 0;
}
