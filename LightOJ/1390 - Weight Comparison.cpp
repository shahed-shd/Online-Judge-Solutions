#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 5000+3;

vector<vector<int> > adjList;
bitset<MAXN> mat[MAXN];
bitset<MAXN> visited;

void dfs(int u)
{
    visited[u] = true;

    int sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        int v = adjList[u][i];

        if(!visited[v]) dfs(v);

        mat[u][v] = true;
        mat[u] |= mat[v];
    }
}

bool take(int u, int sz, int x)
{
    for(int i = 0; i < sz; ++i) {
        int v = adjList[u][i];

        if(v != x && mat[v][x])
            return false;
    }

    return true;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        visited.reset();

        int n, m;
        scanf("%d %d", &n, &m);

        adjList.resize(n);
        for(int i = 0; i < n; ++i) mat[i].reset();

        int u, v;

        while(m--) {
            scanf("%d %d", &u, &v);
            adjList[--u].push_back(--v);
        }

        for(int i = 0; i < n; ++i)
            if(!visited[i]) dfs(i);

        vector<pair<int,int> > ans;

        for(int i = 0; i < n; ++i) {
            int sz = adjList[i].size();

            for(int j = 0; j < sz; ++j)
                if(take(i, sz, adjList[i][j]))
                    ans.push_back(make_pair(i, adjList[i][j]));
        }

        sort(ans.begin(), ans.end());

        int sz = ans.size();

        printf("Case %d: %d\n", tc, sz);

        for(int i = 0; i < sz; ++i)
            printf("%d %d\n", ans[i].first+1, ans[i].second+1);
    }

    return 0;
}
