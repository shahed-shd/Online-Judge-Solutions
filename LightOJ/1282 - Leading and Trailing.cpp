// ==================================================
// Problem  :   1282 - Leading and Trailing
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

typedef     long long       LL;

int modular_pow(int base, int exponent, int mod)
{
    int result = 1;
    base %= mod;

    while(exponent) {
        if(exponent & 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exponent >>= 1;
    }

    return result;
}

inline int first_three(int n, int k)
{
    double x = k * log10(n);
    return int(pow(10, x - LL(x)) * 100);
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, k;
        scanf("%d %d", &n, &k);

        printf("Case %d: %d %03d\n", tc, first_three(n, k), modular_pow(n, k, 1000));
    }

    return 0;
}
