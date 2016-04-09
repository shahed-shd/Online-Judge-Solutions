#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 16, M = 1<<16;

int n, mat[MAXN][MAXN];
int dp[MAXN][M];

inline int checkbit(int n, int pos) { return n & (1<<pos); }
inline int biton(int n, int pos) { return n | (1<<pos); }

int fn(int pos, int mask)
{
    if(pos == n) return 0;

    int& ret = dp[pos][mask];
    if(ret != -1) return ret;

    ret = 0;

    for(int j = 0; j < n; ++j) {
        if(!checkbit(mask, j))
            ret = max(ret, mat[pos][j] + fn(pos+1, biton(mask, j)));
    }

    return ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &mat[i][j]);

        fill(&dp[0][0], &dp[MAXN][0], -1);

        printf("Case %d: %d\n", tc, fn(0, 0));
    }

    return 0;
}
