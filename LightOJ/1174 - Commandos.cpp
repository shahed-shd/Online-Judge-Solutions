// ==================================================
// Problem  :   1174 - Commandos
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int> > adjList;

void bfs(int s, int n, vector<int> &dist)
{
    queue<int> q;
    dist.assign(n+3, -1);

    q.push(s);
    dist[s] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        int sz = adjList[u].size();

        for(int i = 0; i < sz; ++i) {
            int v = adjList[u][i];

            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        int n, r, u, v;
        scanf("%d %d", &n, &r);

        adjList.resize(n+3);

        while(r--) {
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int s, d;
        scanf("%d %d", &s, &d);

        vector<int> distFromS;
        bfs(s, n, distFromS);

        vector<int> distFromD;
        bfs(d, n, distFromD);

        int ans = 0;

        for(int i = 0; i < n; ++i)
            ans = max(ans, distFromS[i]+distFromD[i]);

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
