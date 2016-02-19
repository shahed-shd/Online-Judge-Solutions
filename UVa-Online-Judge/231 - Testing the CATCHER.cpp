#include <cstdio>
#include <vector>
#include <cstdint>
using namespace std;

vector<int16_t> heights, dp;
int sz;

int longest(int u)
{
    if(u == sz) return 0;

    if(dp[u] != -1) return dp[u];

    int maxi = 0;

    for(int v = u+1; v < sz; ++v)
        if(heights[v] <= heights[u])
            maxi = max(maxi, longest(v));

    return dp[u] = 1 + maxi;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int16_t h, tc = 0;

    while(scanf("%hd", &h), h != -1) {
        heights.clear();
        dp.clear();

        heights.push_back(h);

        while(scanf("%hd", &h), h != -1)
            heights.push_back(h);

        sz = heights.size();

        dp.assign(sz, -1);

        int ans = 0;

        for(int i = 0; i < sz; ++i)
            ans = max(ans, longest(i));

        if(tc) putchar('\n');

        printf("Test #%hd:\n  maximum possible interceptions: %d\n", ++tc, ans);
    }

    return 0;
}
