// ==================================================
// Problem  :   318 - Domino Effect
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
using namespace std;


typedef     pair<int, int>      ii;


const int MAXN = 500 + 3;
const int INF = INT_MAX;

vector<vector<ii> > adjList;
int dist[MAXN];

void dijkstra(int s, int n)
{
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    fill(dist, dist+n+1, INF);

    pq.push(ii(0, s));
    dist[s] = 0;

    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();

        for(auto &pr : adjList[u]) {
            int v = pr.first;
            int w = pr.second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v));
            }
        }
    }
}


void print_output(int n)
{
    double d = -1.0;
    int node1 = -1, node2 = -1;

    for(int u = 1; u <= n; ++u) {
        if(dist[u] >= d)
            d = dist[u], node1 = u, node2 = -1;

        for(auto &pr : adjList[u]) {
            int v = pr.first;
            int w = pr.second;

            double tmp = (dist[u] + dist[v] + w) / 2.0;

            if(tmp > d)
                d = tmp, node1 = u, node2 = v;
        }
    }

    if(node2 == -1)
        printf("The last domino falls after %.1f seconds, at key domino %d.\n", d, node1);
    else
        printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n", d, node1, node2);
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int n, m, tc = 0;

    while(scanf("%d %d", &n,  &m), n or m) {
        adjList.clear();

        adjList.resize(n+3);

        int u, v, w;

        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            adjList[u].push_back(ii(v, w));
            adjList[v].push_back(ii(u, w));
        }

        printf("System #%d\n", ++tc);
        dijkstra(1, n);
        print_output(n);
        putchar('\n');
    }

    return 0;
}
