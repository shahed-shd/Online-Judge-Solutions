#include <cstdio>
#include <cstdlib>
using namespace std;

typedef     long long       LL;

const int MAXT = 33333333;
char str[MAXT+3];

int modular_pow(LL base, int exponent, int modulus)
{
    if(modulus == 1) return 0;

    int result = 1;
    base %= modulus;

    while(exponent > 0) {
        if(exponent & 1) {
            result = (result * base) % modulus;
        }

        exponent >>= 1;
        base = (base * base) % modulus;
    }

    return result;
}

bool isPrime(int n, int iteration)
{
    if(n < 2) return false;
    if(n <= 3) return true;
    if(!(n & 1)) return false;

    LL d = n-1;
    while(!(d & 1))
        d >>= 1;

    while(iteration--) {
        int a = rand() % (n-1) + 1;
        int x = modular_pow(a, d, n);
        int d1 = d;

        while(d1 != n-1 && x != 1 && x != n-1) {
            x = (LL(x) * x) % n;
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
    //freopen("out", "w", stdout);

    int t = 3818000;    // 3818000 gets 'Accepted' with 3.50 sec. More than 3818000 causes TLE.

    const LL MOD = 1LL << 31;
    int a, prev_a = 1;

    str[0] = '0';
    int idx = 0;

    while(--t) {
        a = (prev_a + 1234567890LL) % MOD;

        str[++idx] = isPrime(a, 5) + '0';

        prev_a = a;
    }

    str[++idx] = '\0';
    puts(str);

    return 0;
}
