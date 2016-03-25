#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 50+3;

int n, cuts[MAXN], dp[MAXN][MAXN];

int fn(int s, int t)
{
    if(s+1 == t) return 0;

    if(dp[s][t] != -1) return dp[s][t];

    int ret = INT_MAX;

    for(int i = s+1; i < t; ++i)
        ret = min(ret, cuts[t]-cuts[s] + fn(s, i) + fn(i, t));

    return dp[s][t] = ret;
}

int main()
{
    int len;

    while(scanf("%d", &len), len) {
        scanf("%d", &n);

        cuts[0] = 0;

        for(int i = 1; i <= n; ++i)
            scanf("%d", cuts+i);

        cuts[n+1] = len;

        fill_n(&dp[0][0], MAXN*MAXN, -1);

        printf("The minimum cutting is %d.\n", fn(0, n+1));
    }

    return 0;
}
