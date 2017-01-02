// ==================================================
// Problem  :   DCP-02 - 6-N-Cryption
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

LL gcd(LL m, LL n)
{
    while(n != 0) {
        LL t = m % n;
        m = n;
        n = t;
    }

    return m;
}

int main()
{
    //freopen("in", "r", stdin);

    LL data;

    while(~scanf("%lld", &data)) {
        int n;
        scanf("%d", &n);

        LL encryKey1, encryKey2;
        scanf("%lld %lld", &encryKey1, &encryKey2);

        LL bigPrime = gcd(encryKey1, encryKey2);

        data -= encryKey1 / bigPrime;
        data -= encryKey2 / bigPrime;

        for(int i = 2; i < n; ++i) {
            scanf("%lld", &encryKey1);
            data -= encryKey1 / bigPrime;
        }

        printf("Output: %lld\n", data);
    }

    return 0;
}
