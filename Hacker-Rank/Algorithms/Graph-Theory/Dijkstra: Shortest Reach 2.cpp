// ==================================================
// Problem  :   Dijkstra: Shortest Reach 2
// Run time :   60 /60
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define     ff                  first
#define     ss                  second

typedef     pair<int,int>       ii;

vector<vector<ii> > adjList;

void dijkstra(int s, int n)
{
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));

    int dist[n+3];
    fill_n(dist, n+3, INT_MAX);
    dist[s] = 0;

    vector<bool> vis(n, false);
    int u, dist_su, dist_uv, v, tot = 0;

    while(!pq.empty()) {
        dist_su = pq.top().ff, u = pq.top().ss;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;
        ++tot;
        if(tot == n) break;

        for(auto& pr : adjList[u]) {
            v = pr.ff, dist_uv = pr.ss;

            if(dist_su + dist_uv < dist[v]) {
                dist[v] = dist_su + dist_uv;
                pq.push(ii(dist[v], v));
            }
        }
    }

    bool isFirst = true;

    for(int i = 0; i < n; ++i) {
        if(i != s) {
            if(isFirst) isFirst = false;
            else putchar(' ');

            printf("%d", ((dist[i] == INT_MAX)? -1 : dist[i]));
        }
    }
    putchar('\n');
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        adjList.clear();

        int n, m;
        scanf("%d %d", &n, &m);

        adjList.resize(n);
        int x, y, r, s;

        while(m--) {
            scanf("%d %d %d", &x, &y, &r);
            --x, --y;
            adjList[x].push_back(ii(y, r));
            adjList[y].push_back(ii(x, r));
        }

        scanf("%d", &s);

        dijkstra(--s, n);
    }

    return 0;
}
