#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

typedef    pair<int,int>    ii;
vector<vector<ii> > revAdjList;
vector<int> starSystems;
vector<bool> visited;
int n;

bool bellman()
{
    bool isUpdated;
    int v, sz;
    long long dist[n];
    fill_n(dist, n, INT_MAX);
    dist[0] = 0;

    for(int step = 1; step < n; ++step) {
        isUpdated = false;

        for(int u = 0; u < n; ++u) {
            sz = revAdjList[u].size();

            for(int i = 0; i < sz; ++i) {
                v = revAdjList[u][i].first;

                if(dist[v] > dist[u] + revAdjList[u][i].second) {
                    dist[v] = dist[u] + revAdjList[u][i].second;
                    isUpdated = true;
                }
            }
        }

        if(!isUpdated) return false;
    }

    long long dist2[n];
    copy(dist, dist+n, dist2);

    for(int step = 1; step < n; ++step) {       // Once again Bellman-Ford algorithm.
        isUpdated = false;

        for(int u = 0; u < n; ++u) {
            sz = revAdjList[u].size();

            for(int i = 0; i < sz; ++i) {
                v = revAdjList[u][i].first;

                if(dist2[v] > dist2[u] + revAdjList[u][i].second) {
                    dist2[v] = dist2[u] + revAdjList[u][i].second;
                    isUpdated = true;
                }
            }
        }

        if(!isUpdated) break;
    }

    for(int i = 0; i < n; ++i)
        if(dist[i] > dist2[i])
            starSystems.push_back(i);

    return ((starSystems.size())? true : false);
}

void dfs(int u)
{
    visited[u] = true;
    int v, sz = revAdjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = revAdjList[u][i].first;
        if(!visited[v]) dfs(v);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        revAdjList.clear();
        starSystems.clear();
        visited.clear();

        int m, x, y, t;
        scanf("%d %d", &n, &m);

        revAdjList.resize(n);

        while(m--) {
            scanf("%d %d %d", &x, &y, &t);
            revAdjList[y].push_back(ii(x, t));
        }

        printf("Case %d:", tc);

        if(bellman()) {
            visited.assign(n, false);

            for(unsigned i = 0; i < starSystems.size(); ++i)
                if(!visited[starSystems[i]]) dfs(starSystems[i]);

            for(int i = 0; i < n; ++i)
                if(visited[i]) printf(" %d", i);

            putchar('\n');
        }
        else printf(" impossible\n");
    }

    return 0;
}
