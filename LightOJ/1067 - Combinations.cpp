#include <cstdio>
using namespace std;

typedef     long long   LL;

const int MAXN = 1e6+3, MOD = 1000003;

int factMod[MAXN];

void preprocess()
{
    factMod[0] = 1;
    for(int i = 1; i < MAXN; ++i)
        factMod[i] = (LL(factMod[i-1]) * i) % MOD;
}

int bigMod(int base, int p)
{
    if(!p) return 1;

    if(p & 1) return (LL(base) * bigMod(base, p-1)) % MOD;
    else {
        LL tmp = bigMod(base, p/2);
        return (tmp * tmp) % MOD;
    }
}

int main()
{
    preprocess();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, k;
        scanf("%d %d", &n, &k);

        int b = (LL(factMod[k]) * factMod[n-k]) % MOD;
        int ans = (LL(factMod[n]) * bigMod(b, MOD-2)) % MOD;

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
