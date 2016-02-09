// Run time: 0.208 sec

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 50, X = 3, MOD = 100000007;

int a[MAXN+X], c[MAXN+X], dp[MAXN+X][1000+X];
int n;

int fn(int idx, int amount)
{
    if(amount == 0) return 1;
    if(idx == n) return 0;

    if(dp[idx][amount] != -1) return dp[idx][amount];

    int ret = 0;

    for(int take = 1; take <= c[idx]; ++take) {
        if(amount - a[idx]*take >= 0)
            ret += fn(idx+1, amount - a[idx]*take);
        else break;
    }
    ret += fn(idx+1, amount);

    return dp[idx][amount] = ret % MOD;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int k;
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        for(int i = 0; i < n; ++i)
            scanf("%d", &c[i]);

        fill(&dp[0][0], &dp[MAXN+X][0], -1);

        printf("Case %d: %d\n", tc, fn(0, k));
    }

    return 0;
}



// ---------------------------- Alternatively ----------------------------
// Run time: 0.664 sec
/*
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 50, X=1, MOD = 100000007;

int a[MAXN+3], c[MAXN+X], dp[MAXN+X][20+X][1000+X];
int n;

int fn(int idx, int c_idx, int amount)
{
    if(amount == 0) return 1;
    if(idx == n || c_idx < 0) return 0;

    if(dp[idx][c_idx][amount] != -1 && c_idx > 0) return dp[idx][c_idx][amount];

    int ret1 = 0;
    if(amount-a[idx] >= 0 && c_idx > 0)
        ret1 = fn(idx, c_idx-1, amount-a[idx]);

    int ret2 = fn(idx+1, c[idx+1], amount);

    return dp[idx][c_idx][amount] = ((ret1 % MOD) + (ret2 % MOD)) % MOD;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int k;
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        for(int i = 0; i < n; ++i)
            scanf("%d", &c[i]);

        fill(&dp[0][0][0], &dp[MAXN+X][0][0], -1);

        printf("Case %d: %d\n", tc, fn(0, c[0], k));
    }

    return 0;
}
*/
