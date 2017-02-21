// ==================================================
// Problem  :   1185 - Escape
// Runtime  :   0.044 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <bitset>
#include <queue>
#include <vector>
using namespace std;

typedef     pair<int,bool>      ib;

const int MAXN = 100 + 3;

vector<vector<int> > adjList;
bitset<MAXN> carrying[2];

int bfs(int n)
{
    queue<ib> q;

    int v, sz = adjList[1].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[1][i];
        carrying[0][v] = true;
        q.push(ib(v, false));
    }

    int u;
    bool uStatus, vStatus;

    while(!q.empty()) {
        u = q.front().first, uStatus = q.front().second, q.pop();

        sz = adjList[u].size();

        for(int i = 0; i < sz; ++i) {
            v = adjList[u][i];
            vStatus = !uStatus;

            if(!carrying[vStatus][v]) {
                carrying[vStatus][v] = true;
                q.push(ib(v, vStatus));
            }
        }
    }

    return carrying[1].count();
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        carrying[0].reset();
        carrying[1].reset();

        int n, m;
        scanf("%d %d", &n, &m);

        adjList.resize(n+3);
        int u, v;

        while(m--) {
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        printf("Case %d: %d\n", tc, bfs(n));
    }

    return 0;
}
