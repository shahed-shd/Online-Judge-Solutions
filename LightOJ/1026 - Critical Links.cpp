#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef     pair<int,int>   ii;

vector<vector<int> > adjList;
vector<bool> visited;
vector<int> disc;
vector<int> low;
vector<int> articulationPoints;
int n, discTime, root;

void dfs(int u, int parent)
{
    visited[u] = true;
    disc[u] = low[u] = ++discTime;

    int v, sz = adjList[u].size(), childCount = 0;

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(!visited[v]) {
            ++childCount;
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if(u >= n && u == root && childCount > 1)
                articulationPoints.push_back(u);

            if(u >= n && u != root && low[v] >= disc[u])
                articulationPoints.push_back(u);
        }
        else if(v != parent)
            low[u] = min(low[u], disc[v]);
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        visited.clear();
        disc.clear();
        low.clear();
        articulationPoints.clear();

        scanf("%d", &n);

        adjList.resize(n);

        int u, k, v, splitNode = n;

        for(int i = 0; i < n; ++i) {
            scanf("%d (%d)", &u, &k);

            while(k--) {
                scanf("%d", &v);

                if(u < v) {
                    adjList.push_back(vector<int>());
                    adjList[u].push_back(splitNode); adjList[splitNode].push_back(v);
                    adjList[v].push_back(splitNode); adjList[splitNode].push_back(u);
                    ++splitNode;
                }
            }
        }

        int sz = adjList.size();

        disc.resize(sz);
        low.resize(sz);
        visited.assign(sz, false);
        discTime = 0;

        for(int i = 0; i < sz; ++i) {
            if(!visited[i]) {
                root = i;
                dfs(i, -1);
            }
        }

        vector<ii> ans;
        sz = articulationPoints.size();

        for(int i = 0; i < sz; ++i) {
            u = articulationPoints[i];
            ans.push_back(ii(adjList[u][1], adjList[u][0]));
        }

        sort(ans.begin(), ans.end());

        printf("Case %d:\n%d critical links\n", tc, sz);

        for(int i = 0; i < sz; ++i)
            printf("%d - %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}
