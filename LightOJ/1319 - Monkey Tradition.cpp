#include <cstdio>
using namespace std;

typedef     long long       LL;

void extEuclid(LL a, LL b, LL &x, LL &y, LL &gcd)
{
    x = 0, y = 1, gcd = b;
    LL m, n, q, r;

    for(LL u = 1, v = 0; a != 0; gcd = a, a = r) {
        q = gcd / a; r = gcd % a;
        m = x-u*q; n = y-v*q;
        x = u; y = v; u = m; v = n;
    }
}

LL modInv(LL n, LL m)
{
    LL x, y, gcd;
    extEuclid(n, m, x, y, gcd);
    if(gcd == 1) return (x % m);
    return 0;
}

LL chinese_remainder_theorem(int num[], int rem[], int k)
{
    LL prod = 1;

    for(int i = 0; i < k; ++i)
        prod *= num[i];

    LL res = 0;

    for(int i = 0; i < k; ++i) {
        LL pp = prod / num[i];

        int inv = modInv(pp, num[i]);
        if(inv < 0) inv += num[i];

        res += rem[i] * pp * inv;
        res %= prod;
    }

    return res;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        int p[n], r[n];

        for(int i = 0; i < n; ++i)
            scanf("%d %d", p+i, r+i);

        printf("Case %d: %lld\n", tc, chinese_remainder_theorem(p, r, n));
    }

    return 0;
}
