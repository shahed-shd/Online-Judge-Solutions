#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100+3;

int n, w, k, yy[MAXN], memo[MAXN][MAXN];

int fn(int k, int yidx)
{
    if(k == 0 || yidx >= n) return 0;

    int& ret = memo[k][yidx];
    if(ret != -1) return ret;

    int mxCnt = 0;

    for(int i = yidx; i < n; ++i) {
        int cnt = 0, idx = i;

        while(idx < n && yy[idx] <= yy[i]+w) {
            ++idx;
            ++cnt;
        }

        mxCnt = max(mxCnt, cnt+fn(k-1, idx));
    }

    return ret = mxCnt;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d %d", &n, &w, &k);

        for(int i = 0; i < n; ++i)
            scanf("%*d %d", yy+i);

        sort(yy, yy+n);

        fill(&memo[0][0], &memo[MAXN][0], -1);

        int mx = 0;

        for(int i = 0; i < n; ++i)
            mx = max(mx, fn(k, i));

        printf("Case %d: %d\n", tc, mx);
    }

    return 0;
}
