#include <cstdio>
#include <algorithm>
using namespace std;

typedef     long long   LL;

const int MAXN = 500;

LL dp[MAXN+5][MAXN+5];

LL fn(int n, int prev)
{
    if(n == 0) return 1;

    if(dp[n][prev] != -1) return dp[n][prev];

    LL ret = 0;

    for(int i = prev-1; i > 0; --i)
        if(n-i >= 0)
            ret += fn(n-i, i);

    return dp[n][prev] = ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int n;

    fill(&dp[0][0], &dp[MAXN+5][0], -1);

    while(scanf("%d", &n) != EOF) {
        LL ans = 0;

        for(int i = n-1; i > 0; --i)
            ans += fn(n-i, i);

        printf("%lld\n", ans);
    }

    return 0;
}
