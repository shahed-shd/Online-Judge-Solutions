#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > dp;
vector<int> p, w;
int n, mw;;

int fn(int idx, int weight)
{
    if(idx == n) return 0;

    if(dp[idx][weight] != -1) return dp[idx][weight];

    int value1 = (weight + w[idx] <= mw)? p[idx] + fn(idx+1, weight+w[idx]) : 0;
    int value2 = fn(idx+1, weight);

    return dp[idx][weight] = max(value1, value2);
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        dp.clear();
        p.clear();
        w.clear();

        scanf("%d", &n);

        p.resize(n);
        w.resize(n);

        for(int i = 0; i < n; ++i)
            scanf("%d %d", &p[i], &w[i]);

        int g, ans = 0;
        scanf("%d", &g);

        while(g--) {
            scanf("%d", &mw);
            dp.assign(n, vector<int>(mw+1, -1));
            ans += fn(0, 0);
        }

        printf("%d\n", ans);
    }

    return 0;
}
