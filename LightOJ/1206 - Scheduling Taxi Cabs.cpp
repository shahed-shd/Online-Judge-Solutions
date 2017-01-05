// ==================================================
// Problem  :   1206 - Scheduling Taxi Cabs
// Run time :   0.032 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

const int MAXN = 500 + 3;
const int NIL = 0;
const int INF = INT_MAX;

int n, a[MAXN], b[MAXN], c[MAXN], d[MAXN], startTime[MAXN], finishTime[MAXN];

vector<vector<int> > adjList;
int pairU[MAXN], pairV[MAXN], dist[MAXN];

bool bfs()
{
    queue<int> q;

    for(int u = 1; u <= n; ++u) {
        if(pairU[u] == NIL) {
            dist[u] = 0;
            q.push(u);
        }
        else dist[u] = INF;
    }

    dist[NIL] = INF;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        if(dist[u] < dist[NIL]) {
            int v, sz = adjList[u].size();

            for(int i = 0; i < sz; ++i) {
                v = adjList[u][i];
                if(dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    return (dist[NIL] != INF);
}

bool dfs(int u)
{
    if(u == NIL) return true;

    int v, sz = adjList[u].size();
    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(dist[pairV[v]] == dist[u]+1 && dfs(pairV[v])) {
            pairV[v] = u;
            pairU[u] = v;
            return true;
        }
    }

    dist[u] = INF;
    return false;
}

int hopcroft_karp()
{
    fill(pairU+1, pairU+n+1, NIL);
    fill(pairV+1, pairV+n+1, NIL);

    int matching = 0;

    while(bfs()) {
        for(int u = 1; u <= n; ++u)
            if(pairU[u] == NIL && dfs(u))
                ++matching;
    }

    return matching;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        scanf("%d", &n);

        int hh, mm;

        for(int i = 1; i <= n; ++i) {
            scanf("%d:%d %d %d %d %d", &hh, &mm, a+i, b+i, c+i, d+i);
            startTime[i] = hh * 60 + mm;
            finishTime[i] = startTime[i] + abs(a[i]-c[i]) + abs(b[i]-d[i]);
        }

        adjList.resize(n+1);

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(i != j && finishTime[i]+abs(c[i]-a[j])+abs(d[i]-b[j]) < startTime[j])
                    adjList[i].push_back(j);

        printf("Case %d: %d\n", tc, n - hopcroft_karp());
    }

    return 0;
}
