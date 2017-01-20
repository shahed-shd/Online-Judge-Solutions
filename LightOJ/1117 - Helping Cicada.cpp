// ==================================================
// Problem  :   1117 - Helping Cicada
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

const int MAXM = 15 + 3;

LL ans;
int N, M, arr[MAXM];

LL gcd(LL m, LL n)
{
    while(n != 0) {
        LL t = m % n;
        m = n;
        n = t;
    }

    return m;
}

LL lcm(LL m, LL n)
{
    return (m / gcd(m, n) * n);
}

void backtrack(LL currLcm, int idx, int cnt)
{
    if(currLcm > N) return;

    if(idx > M) {
        if(cnt) ans += ((cnt & 1)? (N/currLcm) : (-N/currLcm));
        return;
    }

    backtrack(currLcm, idx+1, cnt);
    backtrack(lcm(currLcm, arr[idx]), idx+1, cnt+1);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &N, &M);

        for(int i = 1; i <= M; ++i)
            scanf("%d", arr+i);

        ans = 0;
        backtrack(1, 1, 0);
        ans = N - ans;

        printf("Case %d: %lld\n", tc, ans);
    }

    return 0;
}
