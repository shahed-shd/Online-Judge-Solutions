// ==================================================
// Problem  :   1417 - Forwarding Emails
// Run time :   0.216 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <bitset>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 50000 + 3;

vector<vector<int> > adjList, adj;

int sccHead[MAXN], disc[MAXN], low[MAXN];
stack<int> stk;
bitset<MAXN> vis, isDone;
vector<int> topoSort;
int visCntArr[MAXN];

void dfs_scc(int u)
{
    vis[u] = true;
    stk.push(u);
    int v, sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(!vis[v]) {
            disc[v] = low[v] = disc[u] + 1;
            dfs_scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!isDone[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    isDone[u] = true;

    if(low[u] == disc[u]) {
        vector<int> V;
        int mn = MAXN, tp;

        do {
            tp = stk.top(); stk.pop();
            V.push_back(tp);
            mn = min(mn, tp);
        } while(tp != u);

        visCntArr[mn] = V.size();

        sz = V.size();
        for(int i = 0; i < sz; ++i)
            sccHead[V[i]] = mn;
    }
}

void dfs_topoSort(int u)
{
    vis[u] = true;
    int v, sz = adj[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adj[u][i];
        if(!vis[v]) dfs_topoSort(v);
    }

    topoSort.push_back(u);
}

void dfs_getVisCnt(int u)
{
    vis[u] = true;
    int v, sz = adj[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adj[u][i];
        if(!vis[v]) dfs_getVisCnt(v);

        visCntArr[u] += visCntArr[v];
    }

    isDone[u] = true;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        adj.clear();
        topoSort.clear();
        vis.reset();
        isDone.reset();

        int n, u, v;
        scanf("%d", &n);

        adjList.resize(n+3);
        adj.resize(n+3);

        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
        }

        for(int i = 1; i <= n; ++i) sccHead[i] = i, visCntArr[i] = 1;

        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                disc[i] = low[i] = 0;
                dfs_scc(i);
            }
        }

        for(int u = 1; u <= n; ++u) {
            int v, sz = adjList[u].size();

            for(int i = 0; i < sz; ++i) {
                v = adjList[u][i];
                if(sccHead[u] != sccHead[v]) adj[sccHead[u]].push_back(sccHead[v]);
            }
        }

        // Now, adj is a DAG.

        vis.reset();

        for(int i = n; i >= 1; --i)
            if(!vis[i] && sccHead[i] == i)
                dfs_topoSort(i);

        vis.reset();
        isDone.reset();
        int mx = 0, ans;

        for(int i = topoSort.size()-1; i >= 0; --i) {
            u = topoSort[i];
            if(!vis[u]) {
                dfs_getVisCnt(u);

                if(mx < visCntArr[u])
                    mx = visCntArr[u], ans = u;
                else if(mx == visCntArr[u])
                    ans = min(ans, u);
            }
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
