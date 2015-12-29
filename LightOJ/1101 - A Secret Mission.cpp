#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

typedef     pair<int,int>   ii;
typedef     pair<int,ii>    iii;

vector<vector<ii> > adjList;
vector<vector<ii> > table;
vector<int> level;

void dfs(int u, int parent)
{
    int v, sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i].first;

        if(v != parent) {
            table[v].push_back(ii(u, adjList[u][i].second));
            level[v] = level[u] + 1;
            dfs(v, u);
        }
    }
}

void formTable(int n)
{
    level[0] = 0;
    dfs(0, -1);

    ii pr;

    for(int j = 1; (1 << j) < n; ++j) {
        for(int i = 0; i < n; ++i) {
            if(int(table[i].size()) >= j && int(table[table[i][j-1].first].size()) >= j) {
                pr = table[table[i][j-1].first][j-1];
                table[i].push_back(ii(pr.first, max(table[i][j-1].second, pr.second)));
            }
        }
    }
}

int find_lca(int s, int t)
{
    if(level[s] < level[t]) swap(s, t);

    for(int i = log2(level[s]); i >= 0; --i)
        if(int(table[s].size()) > i && level[table[s][i].first] >= level[t])
            s = table[s][i].first;

    for(int i = log2(level[s]); i >= 0; --i)
        if(int(table[s].size()) > i && int(table[t].size()) > i && table[s][i].first != table[t][i].first)
            s = table[s][i].first, t = table[t][i].first;

    if(s == t) return s;

    return table[s][0].first;
}

int find_max(int a, int b)  // considering level[a] >= level[b].
{
    if(a == b) return 0;

    int maxi = INT_MIN;

    for(int i = log2(level[a]); i >= 0; --i) {
        if(int(table[a].size()) > i && level[table[a][i].first] >= level[b]) {
            maxi = max(maxi, table[a][i].second);
            a = table[a][i].first;
        }
    }

    return maxi;
}

void get_mst(int n)
{
    vector<vector<ii> > adj(n);

    bool visited[n];
    fill(visited, visited+n, false);

    priority_queue<iii, vector<iii>, greater<iii> > q;

    int sz = adjList[0].size();
    visited[0] = true;

    for(int i = 0; i < sz; ++i)
        q.push(iii(adjList[0][i].second, ii(0, adjList[0][i].first)));

    int u, v, w;

    while(!q.empty()) {
        v = q.top().second.second;

        if(visited[v]) { q.pop(); continue; }

        visited[v] = true;
        w = q.top().first;
        u = q.top().second.first;
        q.pop();

        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));

        sz = adjList[v].size();

        for(int i = 0; i < sz; ++i)
            q.push(iii(adjList[v][i].second, ii(v, adjList[v][i].first)));
    }

    adjList = adj;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        table.clear();
        level.clear();

        int n, m, u, v, w, q;
        scanf("%d %d", &n, &m);

        adjList.resize(n);
        table.resize(n);
        level.resize(n);

        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            --u, --v;
            adjList[u].push_back(ii(v, w));
            adjList[v].push_back(ii(u, w));
        }

        get_mst(n);     // getting Minimum Spanning Tree from the input graph.

        formTable(n);   // forming Sparse Table.

        scanf("%d", &q);

        printf("Case %d:\n", tc);

        while(q--) {
            scanf("%d %d", &u, &v);

            int lca = find_lca(--u, --v);

            printf("%d\n", max(find_max(u, lca), find_max(v, lca)));
        }
    }

    return 0;
}
