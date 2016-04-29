#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100+3;

int n, k, grid[MAXN][MAXN], memo[MAXN][MAXN];

int fn(int row, int col)
{
    //if(row < 0 || row >= n || col < 0 || col >= n) return 0;

    int& ret = memo[row][col];
    if(ret != -1) return ret;

    int mx = 0, curr = grid[row][col];

    for(int i = 1; i <= k; ++i)
        if(col+i < n && grid[row][col+i] > curr)
            mx = max(mx, fn(row, col+i));

    for(int i = 1; i <= k; ++i)
        if(col-i >= 0 && grid[row][col-i] > curr)
            mx = max(mx, fn(row, col-i));

    for(int i = 1; i <= k; ++i)
        if(row+i < n && grid[row+i][col] > curr)
            mx = max(mx, fn(row+i, col));

    for(int i = 1; i <= k; ++i)
        if(row-i >= 0 && grid[row-i][col] > curr)
            mx = max(mx, fn(row-i, col));

    return ret = curr + mx;
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &grid[i][j]);


        fill(&memo[0][0], &memo[MAXN][0], -1);

        printf("%d\n", fn(0, 0));

        if(tc) putchar('\n');
    }

    return 0;
}
