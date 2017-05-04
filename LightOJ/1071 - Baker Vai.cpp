// ==================================================
// Problem  :   1071 - Baker Vai
// Run time :   0.024 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 3;

int mat[MAXN][MAXN] = {{0}};
int memo[MAXN][MAXN][MAXN] = {{{0}}};

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int m, n;
        scanf("%d %d", &m, &n);

        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", &mat[i][j]);

        memo[1][1][2] = mat[1][1] + mat[1][2];

        for(int i = 3; i <= n; ++i) memo[1][1][i] = memo[1][1][i-1] + mat[1][i];

        for(int i = 2; i <= m; ++i) {
            for(int j = 1; j < n; ++j)              // Move down, both paths.
                for(int k = j+1; k <= n; ++k)
                    memo[i][j][k] = memo[i-1][j][k] + mat[i][j] + mat[i][k];

            for(int k = 3; k <= n; ++k)             // Move right, only the left path.
                for(int j = 2; j < k; ++j)
                    memo[i][j][k] = max(memo[i][j][k], memo[i][j-1][k] + mat[i][j]);

            for(int j = 1; j < n-1; ++j)            // Move right, only the right path.
                for(int k = j+2; k <= n; ++k)
                    memo[i][j][k] = max(memo[i][j][k], memo[i][j][k-1] + mat[i][k]);
        }

        printf("Case %d: %d\n", tc, memo[m][n-1][n]);
    }

    return 0;
}
