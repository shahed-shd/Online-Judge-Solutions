// ==================================================
// Problem   :   455C - Civilization
// Run time  :   0.327 sec.
// Language  :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 3e5 + 3;

vector<vector<int> > adjList;
int diaLen[MAXN];
int maxDist, maxDistNode;

struct UFDS {
    int par[MAXN], rnk[MAXN] = {0};

    UFDS (int totNode) {
        for(int i = 1; i <= totNode; ++i) par[i] = i;
    }

    int findSet(int i) {
        return ((par[i] == i)? i : par[i] = findSet(par[i]));
    }

    void unionSet(int i, int j) {
        if(findSet(i) == findSet(j)) return;

        int p1 = findSet(i), p2 = findSet(j);

        if(rnk[p1] < rnk[p2]) {
            par[p1] = p2;
        }
        else {
            par[p2] = p1;
            if(rnk[p1] == rnk[p2]) ++rnk[p1];
        }
    }

    bool isSameSet(int i, int j) { return (findSet(i) == findSet(j)); }
};

void dfs(int u, int par = -1, int dist = 0)
{
    if(maxDist < dist) maxDist = dist, maxDistNode = u;

    for(auto &v : adjList[u])
        if(v != par)
            dfs(v, u, dist+1);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    adjList.resize(n+3);
    UFDS uf(n);
    int u, v;

    while(m--) {
        scanf("%d %d", &u, &v);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        uf.unionSet(u, v);
    }

    for(int i = 1; i <= n; ++i) {
        if(uf.findSet(i) == i) {
            maxDist = -1;
            dfs(i);

            maxDist = -1;
            dfs(maxDistNode);

            diaLen[i] = maxDist;
        }
    }

    int type;

    while(q--) {
        scanf("%d", &type);

        if(type == 1) {
            scanf("%d", &u);
            printf("%d\n", diaLen[uf.findSet(u)]);
        }
        else {
            scanf("%d %d", &u, &v);

            if(!uf.isSameSet(u, v)) {
                int p1 = uf.findSet(u), p2 = uf.findSet(v);
                uf.unionSet(u, v);
                int p = uf.findSet(u);

                diaLen[p] = max((diaLen[p1]+1)/2 + (diaLen[p2]+1)/2 + 1, max(diaLen[p1], diaLen[p2]));
            }
        }
    }

    return 0;
}
