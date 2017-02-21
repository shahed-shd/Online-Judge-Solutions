// ==================================================
// Problem  :   1123 - Trail Maintenance
// Runtime  :   0.136 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <set>
#include <vector>
#include <climits>
using namespace std;

#define     ff                  first
#define     ss                  second

typedef     pair<int,int>       ii;
typedef     pair<int,ii>        iii;

const int MAXN = 200 + 3;
const int INF = INT_MAX;

int adjMat[MAXN][MAXN];

struct UFDS {
    int par[MAXN], rnk[MAXN];
    int setSize;

    UFDS(int n) {
        setSize = n;
        for(int i = 1; i <= n; ++i) par[i] = i, rnk[i] = 0;
    }

    int findSet(int i) {
        return ((par[i] == i)? i : par[i] = findSet(par[i]));
    }

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

        --setSize;
        return true;
    }
};

int formMST(int n, set<iii> &edges)
{
    UFDS uf(n);
    int ans = 0;
    vector<iii> toErase;

    for(set<iii>::iterator it = edges.begin(); it != edges.end() and uf.setSize > 1; ++it) {
        int u = it->ss.ff, v = it->ss.ss, cost = it->ff;

        if(uf.unionSet(u, v))
            ans += cost;
        else
            toErase.push_back(*it);
    }

    int sz = toErase.size();

    for(int i = 0; i < sz; ++i)
        edges.erase(toErase[i]);

    if(uf.setSize > 1) ans = -1;

    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        fill(&adjMat[0][0], &adjMat[MAXN][0], INF);

        int n, w;
        scanf("%d %d", &n, &w);

        printf("Case %d:\n", tc);

        int u, v, cost;
        set<iii> edges;

        while(w--) {
            scanf("%d %d %d", &u, &v, &cost);

            if(adjMat[u][v] > cost) {
                adjMat[u][v] = adjMat[v][u] = cost;

                if(u > v) swap(u, v);
                edges.insert(iii(cost, ii(u, v)));
            }

            printf("%d\n", formMST(n, edges));
        }
    }

    return 0;
}
