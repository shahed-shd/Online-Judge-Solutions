#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define     dp(i,j)     (*(dp+2*i+j))

vector<vector<int> > adjList;
vector<bool> visited;
int *dp;

int f(int u, bool isTaken, int parent)
{
    visited[u] = true;

    if(adjList[u].size() == 0) return 1;

    if(dp(u, isTaken) != -1) return dp(u, isTaken);

    int v, sz = adjList[u].size(), sum = 0;

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(v != parent) {
            if(isTaken) sum += f(v, false, u);
            else sum += max(f(v, true, u), f(v, false, u));
        }
    }

    return dp(u, isTaken) = sum + isTaken;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        visited.clear();

        int n, m, u, v;
        scanf("%d %d", &n, &m);

        adjList.resize(n);
        visited.assign(n, false);
        dp = new int [n*2];
        fill(dp, dp+n*2, -1);

        while(m--) {
            scanf("%d %d", &u, &v);
            --u, --v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int ans = 0;

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) ans += max(f(i, true, -1), f(i, false, -1));
        }

        printf("Case %d: %d\n", tc, ans);

        delete [] dp;
    }

    return 0;
}
