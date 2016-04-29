#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100+3;

int R, C, grid[MAXN][MAXN], memo[MAXN][MAXN];

int fn(int row, int col)
{
    int& ret = memo[row][col];
    if(ret != -1) return ret;

    int mx = 0, curr = grid[row][col];

    if(row+1 < R && grid[row+1][col] < curr)
        mx = max(mx, fn(row+1, col));

    if(row-1 >= 0 && grid[row-1][col] < curr)
        mx = max(mx, fn(row-1, col));

    if(col+1 < C && grid[row][col+1] < curr)
        mx = max(mx, fn(row, col+1));

    if(col-1 >= 0 && grid[row][col-1] < curr)
        mx = max(mx, fn(row, col-1));

    return ret = 1 + mx;
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        char str[1000];
        scanf("%s %d %d", str, &R, &C);

        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j)
                scanf("%d", &grid[i][j]);

        fill(&memo[0][0], &memo[MAXN][0], -1);

        int ans = 0;

        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j)
                ans = max(ans, fn(i, j));

        printf("%s: %d\n", str, ans);
    }

    return 0;
}
