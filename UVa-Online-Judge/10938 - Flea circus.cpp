#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int> > adjList;
vector<vector<int> > table;
vector<int> level;

void dfs(int u, int parent)
{
    for(auto& v : adjList[u])
        if(v != parent)
            table[v].push_back(u),
            level[v] = level[u]+1,
            dfs(v, u);
}

void formSparseTable(int n)
{
    level[0] = 0;
    dfs(0, -1);     // considering 0 as root.

    int p;

    for(unsigned j = 1; (1 << j) < n; ++j) {
        for(int i = 0; i < n; ++i) {
            if(table[i].size() >= j) {
                p = table[i][j-1];

                if(table[p].size() >= j)
                    table[i].push_back(table[p][j-1]);
            }
        }
    }
}

int find_lca(int a, int b)
{
    if(level[a] < level[b]) swap(a, b);

    for(int i = log2(level[a]); i >= 0; --i)
        if(int(table[a].size()) > i && level[table[a][i]] >= level[b])
            a = table[a][i];

    for(int i = log2(level[a]); i >= 0; --i)
        if(int(table[a].size()) > i && int(table[b].size()) > i && table[a][i] != table[b][i])
            a = table[a][i], b = table[b][i];

    if(a == b) return a;

    return table[a][0];
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;

    while(scanf("%d", &n) && n) {
        adjList.clear();
        table.clear();
        level.clear();

        adjList.resize(n);
        table.resize(n);
        level.resize(n);

        int u, v;

        for(int i = 1; i < n; ++i) {
            scanf("%d %d", &u, &v);
            adjList[--u].push_back(--v);
            adjList[v].push_back(u);
        }

        formSparseTable(n);

        int q;
        scanf("%d", &q);

        while(q--) {
            scanf("%d %d", &u, &v);
            --u, --v;

            int lca = find_lca(u, v);

            int dist = level[u] + level[v] - 2 * level[lca];

            if(dist & 1) {
                dist /= 2;

                if(level[u] < level[v]) swap(u, v);

                while(dist--)
                    u = table[u][0];

                v = table[u][0];;

                if(u > v) swap(u, v);

                printf("The fleas jump forever between %d and %d.\n", u+1, v+1);
            }
            else {
                dist /= 2;

                if(level[u] < level[v]) swap(u, v);

                while(dist--)
                    u = table[u][0];

                printf("The fleas meet at %d.\n", u+1);
            }
        }
    }

    return 0;
}
