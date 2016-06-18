#include <cstdio>
using namespace std;

const int num[] = {23, 28, 33};
int pp[3], inv[3], prod;

void extEuclid(int a, int b, int &x, int &y, int &gcd)
{
    x = 0, y = 1, gcd = b;
    int m, n, q, r;

    for(int u = 1, v = 0; a != 0; gcd = a, a = r) {
        q = gcd / a; r = gcd % a;
        m = x-u*q; n = y-v*q;
        x = u; y = v; u = m; v = n;
    }
}

int modInv(int n, int m)
{
    int x, y, gcd;
    extEuclid(n, m, x, y, gcd);
    if(gcd == 1) return x % m;
    return 0;
}

void pre_process()
{
    prod = num[0] * num[1] * num[2];

    for(int i = 0; i < 3; ++i)
        pp[i] = prod / num[i];

    for(int i = 0; i < 3; ++i) {
        inv[i] = modInv(pp[i], num[i]);
        if(inv[i] < 0) inv[i] += num[i];
    }
}

int chinese_remainder_theorem(int rem[])
{
    int res = 0;

    for(int i = 0; i < 3; ++i)
        res += rem[i] * pp[i] * inv[i];

    return res % prod;
}

int main()
{
    //freopen("in", "r", stdin);

    pre_process();

    int d, tc = 0, rem[3];

    while(scanf("%d %d %d %d", rem, rem+1, rem+2, &d), d != -1) {
        int ans = chinese_remainder_theorem(rem);

        while(ans == 0 || ans < d)
            ans += prod;

        printf("Case %d: the next triple peak occurs in %d days.\n", ++tc, ans-d);
    }

    return 0;
}
