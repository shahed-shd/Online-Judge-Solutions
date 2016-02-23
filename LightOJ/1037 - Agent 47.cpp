#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

const int MAXN = 15;

int n, targetHealth[MAXN];
char matrix[MAXN][MAXN];
int dp[(1<<MAXN)+3];

inline int biton(int n, int pos) { return n | (1<<pos); }
inline bool check(int n, int pos) { return n & (1<<pos); }

int fn(int mask)
{
    if(mask == (1<<n)-1) return 0;

    if(dp[mask] != -1) return dp[mask];

    int mini = INT_MAX;

    for(int i = 0; i < n; ++i) {
        if(check(mask, i) == 1) {
            for(int k = 0; k < n; ++k) {
                if(check(mask, k) == 0) {
                    int m = (matrix[i][k])? ceil(1.0 * targetHealth[k] / matrix[i][k]) : targetHealth[k];
                    mini = min(mini, m + fn(biton(mask, k)));
                }
            }
        }
    }

    return dp[mask] = mini;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
            scanf("%d", targetHealth+i);

        getchar();

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                matrix[i][j] = getchar() - '0';
            getchar();
        }

        fill(dp, dp+(1<<MAXN)+3, -1);

        int ans = INT_MAX;

        for(int i = 0; i < n; ++i)
            ans = min(ans, targetHealth[i] + fn(biton(0, i)));

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
