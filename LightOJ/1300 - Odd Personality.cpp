#include <cstdio>
#include <set>
#include <vector>
using namespace std;

typedef     pair<int,int>   ii;

vector<vector<int> > adjList;
vector<int> disc, low;
set<ii> bridge;
vector<char> mark;

int discTime, cnt;
bool add;

void dfs(int u, int parent)
{
    low[u] = disc[u] = ++discTime;

    int v, sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(!disc[v]) {     // that is, v isn't visited.
            dfs(v, u);

            if(low[v] > disc[u])
                bridge.insert(ii(min(u,v), max(u,v)));

            low[u] = min(low[u], low[v]);
        }
        else if(v != parent)
            low[u] = min(low[u], disc[v]);
    }
}

void dfs2(int u)
{
    ++cnt;

    int v, sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(bridge.find(ii(min(u,v), max(u,v))) == bridge.end()) {   // u-v edge isn't a bridge.
            if(mark[v] && mark[v] == mark[u]) add = true;
            else if(!mark[v]) {
                mark[v] = 0 - mark[u];
                dfs2(v);
            }
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        disc.clear();
        low.clear();
        bridge.clear();
        mark.clear();

        int n, m, u, v;
        scanf("%d %d", &n, &m);

        adjList.resize(n);
        disc.resize(n);
        low.assign(n, 0);
        mark.assign(n, 0);

        while(m--) {
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        discTime = 0;

        for(int i = 0; i < n; ++i)
            if(!low[i])     // that is, vertex 'i' isn't visited.
                dfs(i, -1);

        int ans = 0;

        for(int i = 0; i < n; ++i) {
            if(!mark[i]) {
                cnt = 0, mark[i] = -1, add = false;
                dfs2(i);
                if(add) ans += cnt;
            }
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
