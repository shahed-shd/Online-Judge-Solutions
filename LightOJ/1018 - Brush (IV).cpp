#include <cstdio>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXN = 16+1;

int tc, n;
ii points[MAXN];

int colinearMask[MAXN][MAXN];
int memo[1<<MAXN], memoCase[1<<MAXN] = {0};

inline bool bitcheck(int n, int pos) { return (n>>pos) & 1; }
inline int biton(int n, int pos) { return n | (1<<pos); }

bool isColinear(int x1, int y1, int x2, int y2, int xx, int yy)
{
    if(x1 == x2) return (x1 == xx);
    if(y1 == y2) return (y1 == yy);

    return (x1-x2)*(yy-y1) == (xx-x1)*(y1-y2);
}

int getColinearMask(int i, int j)
{
    int mask = biton(biton(0, i), j);

    for(int k = 0; k < n; ++k)
        if(!bitcheck(mask, k) && isColinear(points[i].first, points[i].second, points[j].first, points[j].second, points[k].first, points[k].second))
            mask = biton(mask, k);

    return mask;
}

int fn(int mask)
{
    if(mask == (1<<n)-1) return 0;

    if(memoCase[mask] == tc) return memo[mask];

    int ret = INT_MAX;

    int idx = 0;
    while(bitcheck(mask, idx)) ++idx;

    int newMask = biton(mask, idx);

    for(int i = 0; i < n; ++i)
        if(!bitcheck(newMask, i))
            ret = min(ret, 1+fn(newMask | colinearMask[idx][i]));

    if(ret == INT_MAX) ret = 1;

    memoCase[mask] = tc;
    return memo[mask] = ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
            scanf("%d %d", &points[i].first, &points[i].second);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < i; ++j)
                colinearMask[i][j] = colinearMask[j][i] = getColinearMask(i, j);

        printf("Case %d: %d\n", tc, fn(0));
    }

    return 0;
}
