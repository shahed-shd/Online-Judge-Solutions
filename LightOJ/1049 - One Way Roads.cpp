#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXN = 100+3;

vector<vector<ii> > adjList;
bitset<MAXN> visited;
int goSum;

void dfs(int u)
{
    visited[u] = true;

    for(int i = 0; i < 2; ++i) {
        int v = adjList[u][i].first;

        if(!visited[v]) {
            goSum += adjList[u][i].second;
            dfs(v);
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
        visited.reset();

        int n, u, v, w, costSum = 0;
        scanf("%d", &n);

        adjList.resize(n);

        for(int i = 0; i < n; ++i) {
            scanf("%d %d %d", &u, &v, &w);

            adjList[--u].push_back(ii(--v, w));
            adjList[v].push_back(ii(u, -w));

            costSum += w;
        }

        goSum = 0;
        dfs(0);
        goSum += -adjList[0][1].second;

        goSum = (costSum - abs(goSum)) / 2;

        printf("Case %d: %d\n", tc, min(goSum, costSum - goSum));
    }

    return 0;
}
