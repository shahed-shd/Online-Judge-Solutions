// ==================================================
// Problem  :   1127 - Funny Knapsack
// Run time :   0.080 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef     long long       LL;

const int MAXN = 30+3;

int items[MAXN];
vector<LL> v1, v2;

void backtrack(int curr, int upto, LL sum, vector<LL> &v)
{
    if(curr == upto) {
        v.push_back(sum);
        return;
    }

    backtrack(curr+1, upto, sum+items[curr], v);
    backtrack(curr+1, upto, sum, v);
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        v1.clear();
        v2.clear();

        int n, w;
        scanf("%d %d", &n, &w);

        for(int i = 0; i < n; ++i)
            scanf("%d", items+i);

        if(n == 1) {
            printf("Case %d: %d\n", tc, ((items[0] <= w)? 2 : 1));
            continue;
        }

        backtrack(0, n>>1, 0, v1);
        backtrack(n>>1, n, 0, v2);

        sort(v2.begin(), v2.end());

        int sz = v1.size(), ans = 0;

        for(int i = 0; i < sz; ++i) {
            LL toLoad = (LL) w - v1[i];

            if(toLoad < 0) continue;

            vector<LL>::iterator it = upper_bound(v2.begin(), v2.end(), toLoad);
            ans += distance(v2.begin(), it);
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
