// ==================================================
// Problem  :   11463 - Commandos
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;


const int MAXN = 100 + 3;
const int INF = INT_MAX;

vector<vector<int> > adjList;


void bfs(int s, int n, int cost[])
{
    queue<int> q;
    q.push(s);

    fill(cost, cost+n, INF);
    cost[s] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(auto &v : adjList[u]) {
            if(cost[v] > cost[u] + 1) {
                cost[v] = cost[u] + 1;
                q.push(v);
            }
        }
    }
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        int n, r;
        scanf("%d %d", &n, &r);

        adjList.resize(n+3);
        int u, v;

        while(r--) {
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int s, d;
        scanf("%d %d", &s, &d);

        int cost_from_s[MAXN], cost_from_d[MAXN];

        bfs(s, n, cost_from_s);
        bfs(d, n, cost_from_d);

        int mx = 0;

        for(int i = 0; i < n; ++i)
            mx = max(mx, cost_from_s[i] + cost_from_d[i]);

        printf("Case %d: %d\n", tc, mx);
    }

    return 0;
}
