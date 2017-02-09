// ==================================================
// Problem  :   2 - Prime Generator
// Run time :   0.460 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

bool is_prime(int n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    int s = sqrt(n);
    for(int i = 3; i <= s; i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    short t;
    scanf("%hd", &t);


    while(t--) {
        int m, n;

        scanf("%d %d", &m, &n);

        for(int i = m; i <= n; ++i) {
            if(is_prime(i)) printf("%d\n", i);
        }

        if(t) printf("\n");
    }


    return 0;
}

// -------------------- Alternatively --------------------
// Run time	:	4.600 sec.
/*
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

        a = (a << 1) % modulus;             // a = (a * 2) % modulus.
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

bool isPrime(ULL n, int iteration)          // Miller–Rabin primality test
{
    if(n < 2) return false;
    if(n <= 3) return true;
    if(!(n & 1)) return false;              // If n is even.

    ULL d = n-1;                            // d * 2^r = n-1 where d is odd and r > 0.
    while(!(d & 1))
        d >>= 1;

    while(iteration--) {                    // Witness loop.
        ULL a = rand() % (n-1) + 1;
        ULL x = modular_pow(a, d, n);       // x = a^d % n
        ULL d1 = d;

        while(d1 != n-1 && x != 1 && x != n-1) {
            x = modular_mul(x, x, n);       // x = (x * x) % n.
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
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        ULL m, n;
        scanf("%llu %llu", &m, &n);

        if(tc > 1) putchar('\n');

        if(m <= 2) {
            puts("2");
            m = 3;
        }

        for(ULL i = (m & 1)? m : m+1; i <= n; i+=2)
            if(isPrime(i, 5)) printf("%llu\n", i);
    }

    return 0;
}
*/
