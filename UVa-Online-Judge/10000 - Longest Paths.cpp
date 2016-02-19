// Run time : 0.013 sec

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100;

vector<vector<int> > adjList;
int dp[MAXN], finalPlace[MAXN];

int dfs(int u)
{
    if(dp[u] != -1) return dp[u];

    int mx = 0;
    finalPlace[u] = u;

    for(auto& v : adjList[u]) {
        if(dfs(v) > mx) {
            mx = dfs(v);
            finalPlace[u] = finalPlace[v];
        }
        else if(dfs(v) == mx && finalPlace[v] < finalPlace[u])
            finalPlace[u] = finalPlace[v];
    }

    return dp[u] = 1 + mx;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, tc = 0;

    while(scanf("%d", &n), n) {
        adjList.clear();

        adjList.resize(n);
        fill_n(dp, n, -1);
        fill_n(finalPlace, n, -1);

        int start, u, v;
        scanf("%d", &start);
        --start;

        while(scanf("%d %d", &u, &v), u || v)
            adjList[--u].push_back(--v);

        dfs(start);

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++tc, start+1, dfs(start)-1, finalPlace[start]+1);
    }

    return 0;
}


// ------------------------- Alternatively -------------------------
// Run time : 0.026 sec
/*

#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int> > adjList;

int mxDist, node;

void bellman_ford(int n, int start)     // As the graph is a directed acyclic graph with a small N.
{
    int dist[n];
    fill_n(dist, n, INT_MIN);

    dist[start] = 0;

    int times = n-1;

    while(times--)
        for(int u = 0; u < n; ++u)
            for(auto& v : adjList[u])
                if(dist[u]+1 > dist[v])
                    dist[v] = dist[u]+1;

    mxDist = INT_MIN;

    for(int i = 0; i < n; ++i)
        if(dist[i] > mxDist)
            mxDist = dist[i], node = i;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, tc = 0;

    while(scanf("%d", &n), n) {
        adjList.clear();

        adjList.resize(n);

        int start, u, v;
        scanf("%d", &start);
        --start;

        while(scanf("%d %d", &u, &v), u || v)
            adjList[--u].push_back(--v);

        bellman_ford(n, start);

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++tc, start+1, mxDist, node+1);
    }

    return 0;
}

*/
