#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct tpl {
    int w, u, v;

    tpl(int w, int u, int v) { this->w = w; this->u = u; this->v = v; }
    bool operator<(const tpl &b) const {
        return w > b.w;
    }
};

class UFDS {
    vector<int> par, rank;
public:
    UFDS(int n) {
        rank.assign(n+1, 0);
        par.resize(n+1);
        for(int i = 1; i <= n; ++i) par[i] = i;
    }
    int findSet(int n) {
        return ((par[n] == n) ? n : par[n] = findSet(par[n]));
    }
    void unionSet(int i, int j) {
        if(findSet(i) != findSet(j)) {
            int p1 = findSet(i), p2 = findSet(j);
            if(rank[p1] > rank[p2]) {
                par[p2] = p1;
            }
            else {
                par[p1] = p2;
                if(rank[p1] == rank[p2]) ++rank[p2];
            }
        }
    }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
};

priority_queue<tpl> q;
int n;

long long kruskal()
{
    UFDS uf(n);
    long long ans = 0;

    int u, v, w, edgeCount = 0;

    while(!q.empty()) {
        w = q.top().w;
        u = q.top().u;
        v = q.top().v;
        q.pop();

        if(uf.isSameSet(u, v)) continue;

        uf.unionSet(u, v);
        ans += w;
        ++edgeCount;

        if(edgeCount == n-1) break;
    }

    return ans;
}

int main()
{
    int m;

    cin >> n >> m;

    int u, v, w;

    while(m--) {
        cin >> u >> v >> w;
        q.push(tpl(w, u, v));
    }

    cout << kruskal() << '\n';

    return 0;
}


// Alternatively, not using priority_queue,
// and using tuple (feature of C++11 and later).
/*

#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

typedef    tuple<int,int,int>   tpl;    // w, u, v.

class UFDS {
    vector<int> par, rank;
public:
    UFDS(int n) {
        rank.assign(n+1, 0);
        par.resize(n+1);
        for(int i = 1; i <= n; ++i) par[i] = i;
    }
    int findSet(int n) {
        return ((par[n] == n) ? n : par[n] = findSet(par[n]));
    }
    void unionSet(int i, int j) {
        if(findSet(i) != findSet(j)) {
            int p1 = findSet(i), p2 = findSet(j);
            if(rank[p1] > rank[p2]) {
                par[p2] = p1;
            }
            else {
                par[p1] = p2;
                if(rank[p1] == rank[p2]) ++rank[p2];
            }
        }
    }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
};

vector<tpl> edges;
int n;

long long kruskal()
{
    sort(edges.begin(), edges.end());

    UFDS uf(n);
    int sz = edges.size();
    long long ans = 0;

    int u, v, w, edgeCount = 0;

    for(int i = 0; i < sz; ++i) {
        w = get<0>(edges[i]);
        u = get<1>(edges[i]);
        v = get<2>(edges[i]);

        if(uf.isSameSet(u, v)) continue;

        uf.unionSet(u, v);
        ans += w;
        ++edgeCount;

        if(edgeCount == n-1) break;
    }

    return ans;
}

int main()
{
    int m;

    cin >> n >> m;

    int u, v, w;

    while(m--) {
        cin >> u >> v >> w;
        edges.push_back(tpl(w, u, v));
    }

    cout << kruskal() << '\n';

    return 0;
}

*/
