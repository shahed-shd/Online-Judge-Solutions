#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<bool> visited;
vector<int> disc;
vector<int> low;
int discTime, root, ans;

void dfs(int u, int parent)
{
    visited[u] = true;
    low[u] = disc[u] = ++discTime;

    int v, sz = adjList[u].size(), childCount = 0;
    bool case1 = false, case2 = false;

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(!visited[v]) {
            ++childCount;
            dfs(v, u);

            if(u == root && childCount > 1) case1 = true;
            if(u != root && low[v] >= disc[u]) case2 = true;

            low[u] = min(low[u], low[v]);
        }
        else if(v != parent)
            low[u] = min(low[u], disc[v]);
    }

    if(case1 || case2) ++ans;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        visited.clear();
        disc.clear();
        low.clear();

        int n, m, u, v;
        scanf("%d %d", &n, &m);

        adjList.resize(n);
        disc.resize(n);
        low.resize(n);

        while(m--) {
            scanf("%d %d", &u, &v);
            adjList[--u].push_back(--v);
            adjList[v].push_back(u);
        }

        visited.assign(n, false);
        discTime = 0;
        ans = 0;

        for(int i = 0; i < n; ++i)
            if(!visited[i])
                root = i, dfs(i, -1);

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
