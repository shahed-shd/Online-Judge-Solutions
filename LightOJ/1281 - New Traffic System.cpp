#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct graphNode {
    short ver;
    short cost;
    bool is_proposed;

    graphNode(short v, short c, bool isp) { ver = v, cost = c, is_proposed = isp; }
};

struct node {
    short ver;
    int cost;
    short used;

    node(short v = 0, int c = 0, short u = 0) { ver = v, cost = c, used = u; }
    bool operator<(node ob) const { return cost > ob.cost; }
};

vector<vector<graphNode> > adjList;

int dijkstra(short n, short d)
{
    priority_queue<node> q;
    int dist[d+1][n];

    memset(dist, 1, sizeof(dist));

    q.push(node(0, 0, 0));
    dist[0][0] = 0;

    node top;
    short u, v, usd, cst;

    while(!q.empty()) {
        top = q.top(); q.pop();
        u = top.ver;

        if(u == n-1) return top.cost;

        for(unsigned i = 0; i < adjList[u].size(); ++i) {
            v = adjList[u][i].ver;
            usd = top.used + ((adjList[u][i].is_proposed)? 1 : 0);
            cst = top.cost + adjList[u][i].cost;

            if(usd <= d && cst < dist[usd][v]) {
                dist[usd][v] = cst;
                q.push(node(v, cst, usd));
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);

    short t;

    cin >> t;

    for(short tc = 1; tc <= t; ++tc) {
        short n, m, k, d;

        cin >> n >> m >> k >> d;

        adjList.clear();
        adjList.resize(n);

        short u, v, w;

        while(m--) {
            cin >> u >> v >> w;
            adjList[u].push_back(graphNode(v, w, false));
        }

        while(k--) {
            cin >> u >> v >> w;
            adjList[u].push_back(graphNode(v, w, true));
        }

        int ans = dijkstra(n, d);

        cout << "Case " << tc << ": ";
        if(ans == -1) cout << "Impossible\n";
        else cout << ans << '\n';
    }

    return 0;
}
