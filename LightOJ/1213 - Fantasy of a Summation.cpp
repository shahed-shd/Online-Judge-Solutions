// ==================================================
// Problem  :   1213 - Fantasy of a Summation
// Run time :   0.008 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

LL modular_pow(LL base, LL exponent, LL mod)
{
    if(mod == 1) return 0;

    base %= mod;
    LL result = 1;

    while(exponent) {
        if(exponent & 1) {
            result = (result * base) % mod;
        }

        exponent >>= 1;
        base = (base * base) % mod;
    }

    return result;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, k, mod;
        scanf("%d %d %d", &n, &k, &mod);

        LL s = 0, val;

        for(int i = 0; i < n; ++i) {
            scanf("%lld", &val);
            s += val;
        }

        printf("Case %d: %lld\n", tc, ((k%mod) * modular_pow(n, k-1, mod) * (s%mod)) % mod);
    }

    return 0;
}
