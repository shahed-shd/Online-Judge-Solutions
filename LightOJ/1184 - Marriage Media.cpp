// ==================================================
// Problem  :   1184 - Marriage Media
// Runtime  :   0.004 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

const int MAXN = 50 + 3;
const int INF = INT_MAX;
const int NIL = 0;

struct info {
    int height, age;
    bool isDivorced;

    void takeValue(int h, int a, bool d) { height = h, age = a, isDivorced = d; }
};

int m, n;
info man[MAXN], woman[MAXN];

vector<vector<int> > adjList;
int pairU[MAXN], pairV[MAXN*2], dist[MAXN*2];

bool bfs()
{
    queue<int> q;

    for(int u = 1; u <= m; ++u) {
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

        if(dist[pairV[v]] == dist[u]+1 and dfs(pairV[v])) {
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
    fill(&pairU[1], &pairU[m+1], NIL);
    fill(&pairV[m+1], &pairV[m+n+1], NIL);

    int matching = 0;

    while(bfs()) {

        for(int u = 1; u <= m; ++u)
            if(pairU[u] == NIL and dfs(u))
                ++matching;
    }

    return matching;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        scanf("%d %d", &m, &n);

        adjList.resize(m+n+3);
        int h, a, d;

        for(int i = 1; i <= m; ++i) {
            scanf("%d %d %d", &h, &a, &d);
            man[i].takeValue(h, a, d);
        }

        for(int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &h, &a, &d);
            woman[i].takeValue(h, a, d);

            for(int j = 1; j <= m; ++j) {
                if(woman[i].isDivorced == man[j].isDivorced and abs(h - man[j].height) <= 12 and abs(a - man[j].age) <= 5) {
                    adjList[j].push_back(m+i);
                    adjList[m+i].push_back(j);
                }
            }
        }

        printf("Case %d: %d\n", tc, hopcroft_karp());
    }

    return 0;
}
