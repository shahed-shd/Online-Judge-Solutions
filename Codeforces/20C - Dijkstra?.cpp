#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define    ULL     unsigned long long int
#define    INF     (0xFFFFFFFFFFFFFFFF-1)
#define    pair_   pair<int, ULL>

bool dijkstra(int n, vector<int> graph[], vector<int> cost[], int par[])
{
    auto mycmp = [] (pair_ p1, pair_ p2) { return p1.second > p2.second; };    // lambda function.

    priority_queue<pair_, vector<pair_ >, decltype(mycmp)> q(mycmp); // the pair having the smallest 2nd element gets priority.

    ULL d[n+1];     // distance can be (n-1)*w = (10^5 - 1) * 10^6 = 10^11, which is greater than int range.
    for(int i = 0; i <= n; ++i) d[i] = INF;

    q.push(make_pair(1, 0));
    d[1] = 0;
    par[1] = -1;

    pair_ top;
    int u, v;

    while(!q.empty()) {
        top = q.top(); q.pop();
        u = top.first;

        if(u == n) return true;

        for(unsigned i = 0; i < graph[u].size(); ++i) {
            v = graph[u][i];

            if(d[u]+cost[u][i] < d[v]) {
                d[v] = d[u] + cost[u][i];
                par[v] = u;
                q.push(make_pair(v, d[v]));
            }
        }
    }

    return false;
}

void print_path(int n, int par[])
{
    if(n == -1) return;

    print_path(par[n], par);
    cout << n << ' ';
}

int main()
{
    int n, m, a, b, c;

    cin >> n >> m;

    vector<int> graph[n+1], cost[n+1];
    int parent[n+1];

    while(m--) {
        cin >> a >> b >> c;

        graph[a].push_back(b);
        graph[b].push_back(a);

        cost[a].push_back(c);
        cost[b].push_back(c);
    }

    if(dijkstra(n, graph, cost, parent) == false) cout << -1 << '\n';
    else {
        print_path(parent[n], parent);
        cout << n << '\n';
    }

    return 0;
}
