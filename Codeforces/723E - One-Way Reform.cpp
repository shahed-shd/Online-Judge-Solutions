// ==================================================
// Problem  :   723E - One-Way Reform
// Run time :   0.031 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXN = 200 + 3;

vector<vector<int> > adjList;
vector<bitset<MAXN> > edgeVis;
vector<ii> edges;

void dfs(int u)
{
    for(auto &v : adjList[u]) {
        if(!edgeVis[u][v]) {
            edgeVis[u][v] = edgeVis[v][u] = true;
            edges.push_back(ii(u, v));
            dfs(v);
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
        edgeVis.clear();
        edges.clear();

        int n, m;
        scanf("%d %d", &n, &m);

        adjList.resize(n+1);
        edgeVis.resize(n+1);

        int u, v;
        vector<int> degree(n+1, 0);

        while(m--) {
            scanf("%d %d", &u, &v);

            adjList[u].push_back(v);
            adjList[v].push_back(u);

            ++degree[u], ++degree[v];
        }

        int oddDegVertices = 0;
                                              // There are even number of odd degree vertices in a graph.
        for(int i = 1; i <= n; ++i) {         // Consider vertex 0 as a virtual vertex
            if(degree[i] & 1) {               // and connect the odd degree vertices to the virtual vertex.
                adjList[0].push_back(i);      // Thus, the graph is connected and has no odd degree vertex.
                adjList[i].push_back(0);      // So, it'll form Euler circuit.
                ++oddDegVertices;
            }
        }

        for(int i = 0; i <= n; ++i)
            dfs(i);

        printf("%d\n", n - oddDegVertices);     // The answer is the number of even degree vertices.

        for(auto &pr : edges)
            if(pr.first && pr.second)           // Avoid the edges connecting the virtual vertex.
                printf("%d %d\n", pr.first, pr.second);
    }

    return 0;
}
