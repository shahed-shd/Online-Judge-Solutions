// ==================================================
// Problem  :   1111 - Best Picnic Ever
// Run time :   0.020 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 1000 + 3;

vector<vector<int> > adjList;
vector<int> kCities;
vector<int> reachCnt;
bitset<MAXN> vis;

void dfs(int u)
{
    vis[u] = true;
    ++reachCnt[u];

    int v, sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];
        if(!vis[v])
            dfs(v);
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        kCities.clear();
        reachCnt.clear();

        int k, n, m, u, v;
        scanf("%d %d %d", &k, &n, &m);

        adjList.resize(n+3);
        reachCnt.assign(n+3, 0);

        while(k--) {
            scanf("%d", &u);
            kCities.push_back(u-1);
        }

        sort(kCities.begin(), kCities.end());
        kCities.erase(unique(kCities.begin(), kCities.end()), kCities.end());

        k = kCities.size();

        while(m--) {
            scanf("%d %d", &u, &v);
            --u, --v;
            adjList[u].push_back(v);
        }

        for(int i = 0; i < k; ++i) {
            vis.reset();
            dfs(kCities[i]);
        }

        int ans = 0;

        for(int i = 0; i < n; ++i)
            if(reachCnt[i] == k) ++ans;

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
