// Run time : 0.016 sec.
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

typedef     pair<int,int>   ii;

vector<vector<ii> > adjList;

int dijkstra(int n)
{
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(ii(0, 0));

    int dist[n];
    fill(dist, dist+n, INT_MAX);
    dist[0] = 0;

    while(!q.empty()) {
        int u = q.top().second; q.pop();

        if(u == n-1) return dist[n-1];

        int sz = adjList[u].size();

        for(int i = 0; i < sz; ++i) {
            int v = adjList[u][i].first, w = adjList[u][i].second;

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(ii(dist[v], v));
            }
        }
    }

    return -1;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        int n, m, u, v, w;
        scanf("%d %d", &n, &m);

        adjList.resize(n);

        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            adjList[--u].push_back(ii(--v, w));
            adjList[v].push_back(ii(u, w));
        }

        int ans = dijkstra(n);

        printf("Case %d: ", tc);

        (ans == -1)? puts("Impossible") : printf("%d\n", ans);
    }

    return 0;
}


// -------------------- Alternatively (with BFS) --------------------
// Run time : 0.020 sec.
/*
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

typedef     pair<int,int>   ii;

vector<vector<ii> > adjList;

int shortestPath(int n)
{
    queue<int> q;
    q.push(0);

    int dist[n];
    fill(dist, dist+n, INT_MAX);
    dist[0] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        int sz = adjList[u].size();

        for(int i = 0; i < sz; ++i) {
            int v = adjList[u][i].first, w = adjList[u][i].second;

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }

    return dist[n-1];
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        int n, m, u, v, w;
        scanf("%d %d", &n, &m);

        adjList.resize(n);

        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            adjList[--u].push_back(ii(--v, w));
            adjList[v].push_back(ii(u, w));
        }

        int ans = shortestPath(n);

        printf("Case %d: ", tc);

        (ans == INT_MAX)? puts("Impossible") : printf("%d\n", ans);
    }

    return 0;
}
*/
