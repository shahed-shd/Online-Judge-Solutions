#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100+1;

int n1, n2, tower1[MAXN], tower2[MAXN], dp[MAXN][MAXN];

int LCS(int idx1, int idx2)
{
    if(idx1 == n1 || idx2 == n2) return 0;

    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

    return dp[idx1][idx2] = (tower1[idx1] == tower2[idx2])? 1+LCS(idx1+1, idx2+1) : max(LCS(idx1+1, idx2), LCS(idx1, idx2+1));
}

int main()
{
    //freopen("in", "r", stdin);

    int tc = 0;

    while(scanf("%d %d", &n1, &n2), n1 || n2) {
        for(int i = 0; i < n1; ++i) scanf("%d", tower1+i);
        for(int i = 0; i < n2; ++i) scanf("%d", tower2+i);

        fill_n(&dp[0][0], MAXN*MAXN, -1);

        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++tc, LCS(0, 0));
    }

    return 0;
}
