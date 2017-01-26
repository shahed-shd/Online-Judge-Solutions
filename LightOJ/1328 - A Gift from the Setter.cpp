// ==================================================
// Problem  :   1328 - A Gift from the Setter
// Run time :   0.444 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

typedef     long long       LL;

const int MAXN = 1e5 + 3;
const int MOD = 1000007;

LL a[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL k, c, n;
        scanf("%lld %lld %lld %lld", &k, &c, &n, a);

        for(int i = 1; i < n; ++i)
            a[i] = (k * a[i-1] + c) % MOD;

        sort(a, a+n);

        LL res = 0;

        for(int i = 1; i < n; ++i)
            res += (a[i] - a[i-1]) * (n-i) * i;

        printf("Case %d: %lld\n", tc, res);
    }

    return 0;
}


// -------------------- Alternatively --------------------
// Run time	:	0.468 sec.
/*
#include <cstdio>
#include <algorithm>
using namespace std;

typedef     long long       LL;

const int MAXN = 1e5 + 3;
const int MOD = 1000007;

LL a[MAXN], cumSum[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL k, c, n;
        scanf("%lld %lld %lld %lld", &k, &c, &n, a);

        for(int i = 1; i < n; ++i)
            a[i] = (k * a[i-1] + c) % MOD;

        sort(a, a+n);

        cumSum[0] = a[0];

        for(int i = 1; i < n; ++i)
            cumSum[i] = cumSum[i-1] + a[i];

        LL res = 0;

        for(int i = 0; i+1 < n; ++i)
            res += cumSum[n-1] - cumSum[i] - a[i] * (n-1-i);

        printf("Case %d: %lld\n", tc, res);
    }

    return 0;
}
*/
