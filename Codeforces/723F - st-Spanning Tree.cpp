// ==================================================
// Problem  :   723F - st-Spanning Tree
// Run time :   0.280 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <vector>
using namespace std;

#define     ff                  first
#define     ss                  second

typedef     pair<int,int>       ii;

class UFDS {
    vector<int> par, rnk;
    int setCnt;
public:
    UFDS(int n) {
        setCnt = n;
        rnk.assign(n+3, 0);
        par.resize(n+3);
        for(int i = 1; i <= n; ++i) par[i] = i;
    }

    int findSet(int u) {
        return ((par[u] == u)? u : par[u] = findSet(par[u]));
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

        --setCnt;
        return true;
    }

    int getSetCnt() { return setCnt; }

    bool isSameSet(int u, int v) { return (findSet(u) == findSet(v)); }
};

vector<ii> allEdges, ansEdges;
vector<int> sConnection, tConnection, stConnection;

int main()
{
    //freopen("in", "r", stdin);

    int n, m, u, v, s, t, ds, dt;
    scanf("%d %d", &n, &m);

    UFDS uf(n), uf_S(n), uf_T(n);

    while(m--) {
        scanf("%d %d", &u, &v);
        allEdges.push_back(ii(u, v));
    }

    scanf("%d %d %d %d", &s, &t, &ds, &dt);

    bool stDirectConnection = false;

    for(auto &pr : allEdges) {
        u = pr.ff, v = pr.ss;

        if((u == s && v == t) || (u == t && v == s)) {
            stDirectConnection = true;
        }
        else if(u == s || v == s) {
            uf_S.unionSet(u, v);
            sConnection.push_back((u == s)? v : u);
        }
        else if(u == t || v == t) {
            uf_T.unionSet(u, v);
            tConnection.push_back((u == t)? v : u);
        }
        else if(uf.unionSet(u, v)) {
            ansEdges.push_back(ii(u, v));
        }
    }

    int dsCnt = 0, dtCnt = 0;

    for(auto &x : sConnection) {
        if(!uf_T.isSameSet(uf.findSet(x), t)) {
            if(uf.unionSet(x, s)) {
                ansEdges.push_back(ii(s, x));
                ++dsCnt;
            }
        }
        else stConnection.push_back(x);
    }

    for(auto &x : tConnection) {
        if(!uf_S.isSameSet(uf.findSet(x), s)) {
            if(uf.unionSet(x, t)) {
                ansEdges.push_back(ii(t, x));
                ++dtCnt;
            }
        }
        else stConnection.push_back(x);
    }

    if(dsCnt > ds || dtCnt > dt) {
        puts("No");
        return 0;
    }

    for(auto &x : stConnection) {
        if(dsCnt < ds && uf.unionSet(x, s)) {
            ansEdges.push_back(ii(x, s));
            ++dsCnt;
        }
        else if(dtCnt < dt && uf.unionSet(x, t)) {
            ansEdges.push_back(ii(x, t));
            ++dtCnt;
        }
    }

    if(stDirectConnection && dsCnt < ds && dtCnt < dt && uf.unionSet(s, t)) {
        ansEdges.push_back(ii(s, t));
        ++dsCnt;
        ++dtCnt;
    }

    if(uf.getSetCnt() > 1) {
        puts("No");
        return 0;
    }

    puts("Yes");

    for(auto &pr : ansEdges)
        printf("%d %d\n", pr.ff, pr.ss);

    return 0;
}
