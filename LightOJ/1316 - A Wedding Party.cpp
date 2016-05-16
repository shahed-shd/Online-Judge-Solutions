#include <cstdio>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

typedef     pair<int,int>   ii;

const int MAXN = 500+3, MAXS = 15;

vector<vector<ii> > adjList;    // pair holds cost & node.

vector<bitset<MAXN> > reachability;
bitset<MAXN> visited;

vector<int> shopPos;
map<ii, int> dijkstraMemo;

int n, shopCnt;
ii memo[1<<MAXS][MAXS];

inline bool bitcheck(int x, int pos) { return (x>>pos) & 1; }
inline int biton(int x, int pos) { return x | (1<<pos); }

void dfs(int u)
{
    visited[u] = true;
    reachability[u][u] = true;
    int sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        int v = adjList[u][i].second;

        if(!visited[v]) dfs(v);

        reachability[u][v] = true;
        reachability[u] |= reachability[v];
    }
}

int dijkstra(int s, int t)
{
    if(s == t) return 0;
    int ret = dijkstraMemo[ii(s,t)];
    if(ret) return ret;

    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(ii(0, s));

    int dist[n];
    fill(dist, dist+n, INT_MAX);
    dist[s] = 0;

    while(!q.empty()) {
        int u = q.top().second; q.pop();

        if(u == t) {
            dijkstraMemo[ii(s,t)] = dist[t];
            return dist[t];
        }

        int sz = adjList[u].size();

        for(int i = 0; i < sz; ++i) {
            int v = adjList[u][i].second, cost_uv = adjList[u][i].first;

            if(reachability[u][v] && dist[u]+cost_uv < dist[v]) {
                dist[v] = dist[u] + cost_uv;
                q.push(ii(dist[v], v));
            }
        }
    }

    return 0;   // Just to avoid warning while compiling.
}

ii fn(int mask, int idx)
{
    ii& ret = memo[mask][idx];
    if(ret.first != -1) return ret;

    int minTime = dijkstra(shopPos[idx], n-1), maxShop = 0;

    for(int i = 0; i < shopCnt; ++i) {
        if(!bitcheck(mask, i) && reachability[shopPos[idx]][shopPos[i]]) {
            ii pr = fn(biton(mask, i), i);

            int dist = dijkstra(shopPos[idx], shopPos[i]) + pr.second;
            int cnt = 1 + pr.first;

            if(maxShop == cnt)
                minTime = min(minTime, dist);
            else if(maxShop < cnt)
                minTime = dist, maxShop = cnt;
        }
    }

    return ret = ii(maxShop, minTime);
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        reachability.clear();
        visited.reset();
        shopPos.clear();
        dijkstraMemo.clear();

        int m, s;
        scanf("%d %d %d", &n, &m, &s);

        adjList.resize(n);
        reachability.resize(n);

        int shops[s];

        for(int i = 0; i < s; ++i)
            scanf("%d", shops+i);

        int u, v, w;

        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            adjList[u].push_back(ii(w, v));
        }

        dfs(0);
        visited.reset();    // Because of cycles, we need to run dfs again & again.
        dfs(0);
        visited.reset();
        dfs(0);

        printf("Case %d: ", tc);

        if(!reachability[0][n-1]) {
            puts("Impossible");
            continue;
        }

        for(int i = 0; i < s; ++i)
            if(reachability[0][shops[i]] && reachability[shops[i]][n-1])
                shopPos.push_back(shops[i]);

        shopCnt = shopPos.size();

        fill(&memo[0][0], &memo[1<<MAXS][0], ii(-1, -1));

        int minTime = dijkstra(0, n-1), maxShop = 0;

        for(int i = 0; i < shopCnt; ++i) {
            ii pr = fn(biton(0, i), i);

            int dist = dijkstra(0, shopPos[i]) + pr.second;
            int cnt = 1 + pr.first;

            if(maxShop == cnt)
                minTime = min(minTime, dist);
            else if(maxShop < cnt)
                minTime = dist, maxShop = cnt;
        }

        printf("%d %d\n", maxShop, minTime);
    }

    return 0;
}
