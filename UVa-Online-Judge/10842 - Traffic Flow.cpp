#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

typedef     pair<int, pair<int,int> >   iii;    // w, u, v

vector<iii> edges;

class UFDS {
    vector<int> par, rnk;
public:
    UFDS (int n) {
        for(int i = 0; i < n; ++i) par.push_back(i);
        rnk.assign(n, 0);
    }

    int findSet(int i) { return ((par[i] == i)? i : par[i] = findSet(par[i])); }

    void unionSet(int i, int j) {
        if(findSet(i) == findSet(j)) return;

        int p1 = findSet(i), p2 = findSet(j);

        if(rnk[p1] < rnk[p2]) par[p1] = p2;
        else {
            par[p2] = p1;
            if(rnk[p1] == rnk[p2]) ++rnk[p1];
        }
    }

    bool isSameSet(int i, int j) { return (findSet(i) == findSet(j)); }
};

int kruskal(int n)
{
    sort(edges.begin(), edges.end(), greater<iii>());

    UFDS uf(n);

    int u, v, edgeCount = 0, minCap = INT_MAX;

    for(int i = 0; edgeCount != n-1; ++i) {
        u = edges[i].second.first;
        v = edges[i].second.second;

        if(!uf.isSameSet(u, v)) {
            uf.unionSet(u, v);
            ++edgeCount;
            minCap = min(minCap, edges[i].first);
        }
    }

    return minCap;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        edges.clear();

        int n, m;
        scanf("%d %d", &n, &m);

        int u, v, w;

        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            edges.push_back(iii(w, make_pair(u, v)));
        }

        printf("Case #%d: %d\n", tc, kruskal(n));
    }

    return 0;
}
