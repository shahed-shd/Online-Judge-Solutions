// ==================================================
// Problem  :   1221 - Travel Company
// Run time :   0.264 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXN = 100 + 3;

int n, p;
vector<vector<ii> > adjList;
int dist[MAXN];

bool bellman()
{
    fill(dist, dist+n, 0);

    for(int step = 1; step < n; ++step) {
        for(int u = 0; u < n; ++u) {
            int sz = adjList[u].size();

            for(int i = 0; i < sz; ++i) {
                int v = adjList[u][i].first;
                dist[v] = min(dist[v], dist[u] + adjList[u][i].second);
            }
        }
    }

    for(int u = 0; u < n; ++u) {
        int sz = adjList[u].size();

        for(int i = 0; i < sz; ++i) {
            int v = adjList[u][i].first;
            if(dist[v] > dist[u] + adjList[u][i].second) return true;
        }
    }

    return false;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        int r;
        scanf("%d %d %d", &n, &r, &p);

        adjList.resize(n+3);

        int u, v, income, expense;

        while(r--) {
            scanf("%d %d %d %d", &u, &v, &income, &expense);
            adjList[u].push_back(ii(v, p * expense - income));
        }

        printf("Case %d: %s\n", tc, (bellman()? "YES" : "NO"));
    }

    return 0;
}
