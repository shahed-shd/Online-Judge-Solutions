#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long LL;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, tc = 0;

    while(scanf("%d", &n) == 1) {
        int busy[n+1];
        for(int i = 1; i <= n; ++i) scanf("%d", busy+i);

        int r;
        scanf("%d", &r);

        int edge_u[r], edge_v[r], edge_cost[r], temp;

        for(int i = 0; i < r; ++i) {
            scanf("%d %d", edge_u+i, edge_v+i);

            temp = busy[edge_v[i]] - busy[edge_u[i]];
            edge_cost[i] = temp * temp * temp;
        }

        // Bellman-Ford algorithm.

        bool isUpdated;
        LL dist[n+1];

        fill(dist, dist+n+1, INT_MAX);
        dist[1] = 0;

        for(int step = 1; step < n; ++step) {
            isUpdated = false;

            for(int i = 0; i < r; ++i) {
                if(dist[edge_v[i]] > dist[edge_u[i]] + edge_cost[i] && dist[edge_u[i]] != INT_MAX) {
                    dist[edge_v[i]] = dist[edge_u[i]] + edge_cost[i];
                    isUpdated = true;
                }
            }

            if(!isUpdated) break;
        }

        for(int i = 0; i < r; ++i)
            if(dist[edge_v[i]] > dist[edge_u[i]] + edge_cost[i] && dist[edge_u[i]] != INT_MAX)
                dist[edge_v[i]] = -INT_MIN;

        printf("Set #%d\n", ++tc);

        int q, dest;
        scanf("%d", &q);

        while(q--) {
            scanf("%d", &dest);

            if(dist[dest] < 3 || dist[dest] == INT_MAX) printf("?\n");
            else printf("%lld\n", dist[dest]);
        }
    }

    return 0;
}
