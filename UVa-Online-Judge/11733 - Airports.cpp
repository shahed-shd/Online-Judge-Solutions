#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

typedef    tuple<short,short,short>    tpl;    // cost, location, location.

vector<tpl> edges;
int n;

class UFDS {
    vector<short> par, rank;
    int numberOfSets;
public:
    UFDS(short n) {
        rank.assign(n+1, 0);
        par.resize(n+1);
        for(short i = 1; i <= n; ++i) par[i] = i;
        numberOfSets = n;
    }

    short findSet(short i) { return ((par[i] == i)? i : par[i] = findSet(par[i])); }

    void unionSet(short i, short j) {
        if(findSet(i) != findSet(j)) {
            short p1 = findSet(i), p2 = findSet(j);

            if(rank[p1] > rank[p2]) par[p2] = p1;
            else {
                par[p1] = p2;
                if(rank[p1] == rank[p2]) ++rank[p2];
            }

            --numberOfSets;
        }
    }

    bool isSameSet(short i, short j) { return findSet(i) == findSet(j); }

    int getNumberOfSets() { return numberOfSets; }
};

int kruskal(short &airport)
{
    sort(edges.begin(), edges.end());

    UFDS uf(n);
    int mst = 0, sz = edges.size();
    short u, v, edgeCount = 0;

    for(int i = 0; i < sz && edgeCount != n-1; ++i) {
        u = get<1>(edges[i]);
        v = get<2>(edges[i]);

        if(uf.isSameSet(u, v)) continue;

        uf.unionSet(u, v);
        mst += get<0>(edges[i]);
        ++edgeCount;
    }

    airport = uf.getNumberOfSets();
    return mst;
}

int main()
{
    short t;
    cin >> t;

    for(short tc = 1; tc <= t; ++tc) {
        int m, a;
        cin >> n >> m >> a;

        edges.clear();
        short x, y, c;

        while(m--) {
            cin >> x >> y >> c;
            if(c < a) edges.push_back(tpl(c, x, y));
        }

        short airport;
        int roadCost = kruskal(airport);

        cout << "Case #" << tc << ": " << roadCost+airport*a << ' ' << airport << '\n';
    }

    return 0;
}
