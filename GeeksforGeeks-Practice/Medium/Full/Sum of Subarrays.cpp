// ==================================================
// Problem  :   Sum of Subarrays
// Run time :   0.087 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

const LL MOD = 1e9+7;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, val;
        scanf("%d", &n);

        int nn = n;
        LL res = 0;

        for(int i = 1; i <= n; ++i, --nn) {
            scanf("%d", &val);

            res += (LL(val % MOD) * ((i * nn) % MOD)) % MOD;
            res %= MOD;
        }

        printf("%lld\n", res);
    }

    return 0;
}
