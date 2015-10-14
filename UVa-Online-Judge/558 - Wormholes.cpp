#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long LL;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int edge_u[m], edge_v[m], edge_cost[m], dist[n];

        fill(dist, dist+n, INT_MAX);
        dist[0] = 0;

        for(int i = 0; i < m; ++i)
            scanf("%d %d %d", edge_u+i, edge_v+i, edge_cost+i);

        // Bellman-Ford algorithm.

        int u, v;
        bool isUpdated;

        for(int step = 1; step < n; ++step) {
            isUpdated = false;

            for(int i = 0; i < m; ++i) {
                u = edge_u[i], v = edge_v[i];

                if(dist[v] > LL(dist[u]) + edge_cost[i]) {
                    dist[v] = dist[u] + edge_cost[i];
                    isUpdated = true;
                }
            }

            if(!isUpdated) break;
        }

        bool isNegCycle = false;

        if(isUpdated) {
            for(int i = 0; i < m; ++i) {    // Checking for negative cycle.
                u = edge_u[i], v = edge_v[i];

                if(dist[v] > LL(dist[u]) + edge_cost[i]) {
                    isNegCycle = true;
                    break;
                }
            }
        }

        if(isNegCycle) printf("possible\n");
        else printf("not possible\n");
    }

    return 0;
}
