// ==================================================
// Problem  :   Special Matrix
// Run time :   0.236 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

const int MAXN = 1000 + 3;
const int MOD = 1e9 + 7;

int memo[MAXN][MAXN] = {{0}};

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                memo[i][j] = -1;

        int r, c;

        while(k--) {
            scanf("%d %d", &r, &c);
            memo[r][c] = 0;
        }

        memo[0][1] = 1;

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(memo[i][j])
                    memo[i][j] = (memo[i][j-1] + memo[i-1][j]) % MOD;

        printf("%d\n", memo[n][m]);
    }

    return 0;
}
