#include <cstdio>
#include <vector>
using namespace std;

typedef     pair<int,int>   ii;

vector<vector<ii> > adjList;
int max_dist, max_dist_node;

void dfs(int u, int dist_upto_u, int parent)
{
    if(dist_upto_u > max_dist) {
        max_dist = dist_upto_u;
        max_dist_node = u;
    }

    int v, sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i].first;
        if(v != parent) dfs(v, dist_upto_u+adjList[u][i].second, u);
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        int n, u, v, w;
        scanf("%d", &n);

        adjList.resize(n);

        while(--n) {
            scanf("%d %d %d", &u, &v, &w);
            adjList[u].push_back(ii(v, w));
            adjList[v].push_back(ii(u, w));
        }

        max_dist = -1;
        dfs(0, 0, -1);

        max_dist = -1;
        dfs(max_dist_node, 0, -1);

        printf("Case %d: %d\n", tc, max_dist);
    }

    return 0;
}
