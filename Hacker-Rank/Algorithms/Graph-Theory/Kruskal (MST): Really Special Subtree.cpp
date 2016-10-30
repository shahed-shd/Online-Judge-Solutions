// ==================================================
// Problem  :   Kruskal (MST): Really Special Subtree
// Score    :   50 /50
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
    int u, v, w;

    edge(int uu, int vv, int ww) { u = uu, v = vv, w = ww; }

    bool operator<(const edge &ob) const { return (w < ob.w); }
};

class UFDS {
    vector<int> par, rnk;

public:
    UFDS(int n) {
        rnk.assign(n, 0);
        par.resize(n);
        for(int i = 0; i < n; ++i) par[i] = i;
    }

    int findSet(int u) { return (par[u] == u)? u : par[u] = findSet(par[u]); }

    bool unionSet(int u, int v) {
        int p1 = findSet(u), p2 = findSet(v);
        if(p1 == p2) return false;

        if(rnk[p1] < rnk[p2]) {
            par[p1] = p2;
        }
        else {
            par[p2] = p1;
            if(rnk[p1] == rnk[p2]) ++rnk[p1];
        }

        return true;
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<edge> edges;
    int u, v, w;

    while(m--) {
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back(edge(--u, --v, w));
    }
    scanf("%*d");

    sort(edges.begin(), edges.end());

    UFDS uf(n);
    int ans = 0;

    for(auto &e : edges)
        if(uf.unionSet(e.u, e.v))
            ans += e.w;

    printf("%d\n", ans);

    return 0;
}
