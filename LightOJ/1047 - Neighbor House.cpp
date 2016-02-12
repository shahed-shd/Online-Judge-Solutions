#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 20;

int table[MAXN+5][3], memo[MAXN+5][3];
int n;

int fn(int idx, short prevClr)
{
    if(idx == n) return 0;

    if(memo[idx][prevClr] != -1) return memo[idx][prevClr];

    short clr1, clr2;

    if(prevClr == 0) clr1 = 1, clr2 = 2;
    else if(prevClr == 1) clr1 = 0, clr2 = 2;
    else clr1 = 0, clr2 = 1;

    int ret1 = fn(idx+1, clr1) + table[idx][clr1];
    int ret2 = fn(idx+1, clr2) + table[idx][clr2];

    return memo[idx][prevClr] = min(ret1, ret2);
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
            scanf("%d %d %d", &table[i][0], &table[i][1], &table[i][2]);

        fill(&memo[0][0], &memo[MAXN+5][0], -1);

        printf("Case %d: %d\n", tc, min(fn(0, 0), min(fn(0, 1), fn(0, 2))));
    }

    return 0;
}
