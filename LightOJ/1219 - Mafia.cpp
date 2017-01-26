// ==================================================
// Problem  :   1219 - Mafia
// Run time :   0.008 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 10000 + 3;

vector<vector<int> > adjList;
int boys[MAXN], moveCnt;

int dfs(int u, int par = -1)
{
    int v, sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];
        if(v != par)
            boys[u] += dfs(v, u);
    }

    int ret = boys[u] - 1;
    moveCnt += abs(ret);

    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        int n;
        scanf("%d", &n);

        adjList.resize(n+3);
        int u, v, boy, d;

        for(int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &v, &boy, &d);

            boys[v] = boy;

            while(d--) {
                scanf("%d", &u);
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        moveCnt = 0;
        dfs(1);

        printf("Case %d: %d\n", tc, moveCnt);
    }

    return 0;
}
