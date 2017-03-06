// ==================================================
// Problem   :   580C - Kefa and Park
// Run time  :   0.062 sec.
// Language  :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 3;

int m;
bitset<MAXN> hasCat;
vector<vector<int> > adjList;
int ans, maxx[MAXN] = {0}, curr[MAXN] = {0};

void dfs(int u, int par = 0)
{
    if(hasCat[u])
        curr[u] = 1 + ((hasCat[par])? curr[par] : 0);
    else
        curr[u] = 0;

    maxx[u] = max(curr[u], maxx[par]);

    bool isLeaf = true;

    for(auto &v : adjList[u]) {
        if(v != par) {
            dfs(v, u);
            isLeaf = false;
        }
    }

    if(isLeaf and maxx[u] <= m) ++ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    scanf("%d %d", &n, &m);

    int tmp;

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        hasCat[i] = tmp;
    }

    adjList.resize(n+3);
    int u, v;

    for(int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    ans = 0;
    dfs(1);

    printf("%d\n", ans);

    return 0;
}
