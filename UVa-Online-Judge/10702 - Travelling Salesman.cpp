#include <cstdio>
#include <bitset>
#include <climits>
using namespace std;

const int MAXN = 100;

int C, mat[MAXN][MAXN], dp[MAXN][1000+1];
bitset<MAXN> endPoints;

int fn(int city, int t)
{
    int& ret = dp[city][t];
    if(ret != -1) return ret;

    if(t == 1) {
        for(int i = 0; i < C; ++i)
            if(endPoints[i]) ret = max(ret, mat[city][i]);

        return ret;
    }

    for(int i = 0; i < C; ++i)
        ret = max(ret, mat[city][i]+fn(i, t-1));

    return ret;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int S, E, T;

    while(scanf("%d %d %d %d", &C, &S, &E, &T), C) {
        --S;

        for(int i = 0; i < C; ++i)
            for(int j = 0; j < C; ++j)
                scanf("%d", &mat[i][j]);

        endPoints.reset();

        int tmp;

        while(E--) {
            scanf("%d", &tmp);
            endPoints[tmp-1] = true;
        }

        fill(&dp[0][0], &dp[MAXN][0], -1);

        printf("%d\n", fn(S, T));
    }

    return 0;
}
