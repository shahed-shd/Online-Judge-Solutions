// ==================================================
// Problem  :   Dijkstra: Shortest Reach 2
// Score	:   60 /60
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

const int MAXN = 3000 + 3;

vector<vector<int> > adjList;
int adjMat[MAXN][MAXN];

void dijkstra(int s, int n)
{
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));

    int dist[n+3];
    fill_n(dist, n+3, INT_MAX);
    dist[s] = 0;

    int u, dist_su;

    while(!pq.empty()) {
        dist_su = pq.top().ff, u = pq.top().ss;
        pq.pop();

        for(auto& v : adjList[u]) {
            if(dist_su + adjMat[u][v] < dist[v]) {
                dist[v] = dist_su + adjMat[u][v];
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
        for(int i = 0; i < n; ++i)
            fill_n(&adjMat[i][0], n, 0);    //Fill with 0, as 1 <= r <= 10^5

        int x, y, r, s;

        while(m--) {
            scanf("%d %d %d", &x, &y, &r);
            --x, --y;

            if(adjMat[x][y]) {
                adjMat[x][y] = adjMat[y][x] = min(adjMat[x][y], r);
            }
            else {
                adjList[x].push_back(y);
                adjList[y].push_back(x);
                adjMat[x][y] = adjMat[y][x] = r;
            }
        }

        scanf("%d", &s);

        dijkstra(--s, n);
    }

    return 0;
}
