#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100, MOD = 1e8;

int k1, k2, dp[MAXN+1][MAXN+1][2];

int fn(int n1, int n2, bool flag)
{
    if(n1 == 0 && n2 == 0) return 1;

    if(dp[n1][n2][flag] != -1) return dp[n1][n2][flag];

    int ret = 0;

    if(flag == 0) {
        for(int man = 1; man <= k1 && n1-man >= 0; ++man)
            ret += fn(n1-man, n2, !flag), ret %= MOD;
    }
    else {      // flag == 1
        for(int man = 1; man <= k2 && n2-man >= 0; ++man)
            ret += fn(n1, n2-man, !flag), ret %= MOD;
    }

    return dp[n1][n2][flag] = ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int n1, n2;

    while(scanf("%d %d %d %d", &n1, &n2, &k1, &k2) != EOF) {
        fill(&dp[0][0][0], &dp[MAXN+1][0][0], -1);

        printf("%d\n", (fn(n1, n2, 0) + fn(n1, n2, 1)) % MOD);
    }

    return 0;
}
