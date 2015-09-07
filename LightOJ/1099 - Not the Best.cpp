#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct tuple_ {
    int t;
    int dist;
    int node;

    tuple_(int t = 0, int d = 0, int nd = 0) {this->t = t; dist = d; node = nd; }
    bool operator>(tuple_ ob) const {
        if(t > ob.t) return true;
        else if(t == ob.t && dist > ob.dist) return true;
        else if(t == ob.t && dist == ob.dist && node > ob.node) return true;
        else return false;
    }
};


int dijkstra(int n, vector<int> adjList[], vector<int> cost[])
{
    priority_queue<tuple_, vector<tuple_ >, greater<tuple_ > > q;

    int dist[2][n+1];
    bool vis[2][n+1];

    for(int i = 1; i <= n; ++i) {
        dist[0][i] = dist[1][i] = INT_MAX;
        vis[0][i] = vis[1][i] = false;
    }

    q.push(tuple_(0, 0, 1));
    dist[0][1] = 0;

    tuple_ top;
    int t, u, v;
    int alt;

    while(!q.empty()) {
        top = q.top(); q.pop();
        t = top.t;
        u = top.node;

        if(vis[t][u]) continue;
        vis[t][u] = true;

        for(unsigned i = 0; i < adjList[u].size(); ++i) {
            v = adjList[u][i];

            alt = dist[t][u] + cost[u][i];

            if(alt < dist[0][v]) {
                dist[1][v] = dist[0][v];
                q.push(tuple_(1, dist[1][v], v));

                dist[0][v] = alt;
                q.push(tuple_(0, dist[0][v], v));
            }
            else if(alt > dist[0][v] && alt < dist[1][v]) {
                dist[1][v] = alt;
                q.push(tuple_(1, dist[1][v], v));
            }
        }
    }

    return dist[1][n];
}

int main()
{
    int t, n;
    int r;

    cin >> t;

    for(int tc = 1; tc <= t; ++tc) {
        cin >> n >> r;

        vector<int> adjList[n+1];
        vector<int> cost[n+1];

        int u, v, w;

        while(r--) {
            cin >> u >> v >> w;

            adjList[u].push_back(v);
            adjList[v].push_back(u);

            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        cout << "Case " << tc << ": " << dijkstra(n, adjList, cost) << '\n';
    }

    return 0;
}
