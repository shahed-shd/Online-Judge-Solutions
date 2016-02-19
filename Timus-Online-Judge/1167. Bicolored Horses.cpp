#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 500+3;

int n, k, cnt[MAXN][2], dp[MAXN][MAXN];

int fn(int idx, int stable)
{
    if(stable == k-1)
        return (cnt[n][0] - cnt[idx-1][0]) * (cnt[n][1] - cnt[idx-1][1]);

    if(dp[idx][stable] != -1) return dp[idx][stable];

    int mini = INT_MAX;

    for(int i = idx; i <= n-(k-stable)+1; ++i) {
        int coefficient = (cnt[i][0] - cnt[idx-1][0]) * (cnt[i][1] - cnt[idx-1][1]);
        mini = min(mini, coefficient + fn(i+1, stable+1));
    }

    return dp[idx][stable] = mini;
}

int main()
{
    //freopen("in", "r", stdin);

    while(scanf("%d %d", &n, &k) != EOF) {
        cnt[0][0] = cnt[0][1] = 0;

        int horse;

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &horse);

            cnt[i][horse] = 1;
            cnt[i][!horse] = 0;

            cnt[i][0] += cnt[i-1][0];
            cnt[i][1] += cnt[i-1][1];
        }

        fill(&dp[0][0], &dp[MAXN][0], -1);

        printf("%d\n", fn(1, 0));
    }

    return 0;
}
