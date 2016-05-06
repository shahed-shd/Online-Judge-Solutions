#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 10000+3;

vector<vector<int> > adjList;
vector<int> topoSort;
bitset<MAXN> visited;

void dfs_topoSort(int u)
{
    visited[u] = true;

    int sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        int v = adjList[u][i];
        if(!visited[v]) dfs_topoSort(v);
    }

    topoSort.push_back(u);
}

void dfs_light(int u)
{
    visited[u] = true;

    int sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        int v = adjList[u][i];
        if(!visited[v]) dfs_light(v);
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        topoSort.clear();
        visited.reset();

        int n, m, u, v;
        scanf("%d %d", &n, &m);

        adjList.resize(n);

        while(m--) {
            scanf("%d %d", &u, &v);
            adjList[--u].push_back(--v);
        }

        for(int i = 0; i < n; ++i)
            if(!visited[i])
                dfs_topoSort(i);

        visited.reset();

        int cnt = 0;

        for(int i = n-1; i >= 0; --i) {
            u = topoSort[i];

            if(!visited[u])
                ++cnt, dfs_light(u);
        }

        printf("Case %d: %d\n", tc, cnt);
    }

    return 0;
}
