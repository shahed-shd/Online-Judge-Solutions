// ==================================================
// Problem  :   1122 - Digit Count
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef     long long       LL;

const int MAXN = 10 + 3;

int m, n, s[MAXN];
LL memo[MAXN][MAXN];

LL fn(int idx = -1, int digCnt = 0)
{
    if(digCnt == n) return 1;

    if(idx == -1) {     // No digit has been taken.
        LL ret = 0;
        for(int i = 0; i < m; ++i)
            ret += fn(i, digCnt+1);
        return ret;
    }

    LL &ret = memo[idx][digCnt];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i < m; ++i)
        if(abs(s[idx] - s[i]) <= 2)
            ret += fn(i, digCnt+1);

    return ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &m, &n);

        for(int i = 0; i < m; ++i) scanf("%d", s+i);

        fill(&memo[0][0], &memo[MAXN][0], -1);

        printf("Case %d: %lld\n", tc, fn());
    }

    return 0;
}
