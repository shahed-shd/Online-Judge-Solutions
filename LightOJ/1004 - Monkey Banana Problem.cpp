#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;

int n, table[MAXN][MAXN], dp[MAXN][MAXN];

int fn(int row, int col)
{
    if(row == n || col == n) return 0;

    if(dp[row][col] != -1) return dp[row][col];

    return dp[row][col] = table[row][col] + max(fn(row+1, col), fn(row, col+1));
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) {
            int row = i;
            for(int col = 0; col <= i; ++col, --row)
                scanf("%d", &table[row][col]);
        }

        for(int i = 1; i < n; ++i) {
            int row = n-1;
            for(int col = i; col < n; ++col, --row)
                scanf("%d", &table[row][col]);
        }

        fill(&dp[0][0], &dp[MAXN][0], -1);

        printf("Case %d: %d\n", tc, fn(0, 0));
    }

    return 0;
}
