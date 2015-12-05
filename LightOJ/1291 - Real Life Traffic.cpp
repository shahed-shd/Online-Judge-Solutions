#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<bool> visited;
vector<int> disc;
vector<int> low;
vector<int> cnt;
int root, discTime;

void dfs(int u, int parent)
{
    visited[u] = true;
    low[u] = disc[u] = ++discTime;

    if(u != root && adjList[u].size() <= 1) {
        ++cnt[u];
        return;
    }
    if(u == root && adjList[u].size() <= 1)
        ++cnt[u];

    int v, sz = adjList[u].size(), childCount = 0;

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(!visited[v]) {
            ++childCount;
            dfs(v, u);

            if(u == root) {
                if(childCount > 1 && low[v] > disc[u]) cnt[u] += (cnt[v])?: 1;
                else cnt[u] += cnt[v];
            }
            if(u != root) {
                if(low[v] > disc[u]) cnt[u] += (cnt[v])?: 1;
                else cnt[u] += cnt[v];
            }

            low[u] = min(low[u], low[v]);
        }
        else if(v != parent)
            low[u] = min(low[u], disc[v]);
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        visited.clear();
        disc.clear();
        low.clear();
        cnt.clear();

        int n, m, u, v;
        scanf("%d %d", &n, &m);

        adjList.resize(n);
        visited.assign(n, false);
        disc.resize(n);
        low.resize(n);
        cnt.assign(n, 0);

        while(m--) {
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        discTime = 0;
        root = 0;

        dfs(root, -1);

        printf("Case %d: %d\n", tc, (cnt[root]+1)/2);
    }

    return 0;
}
