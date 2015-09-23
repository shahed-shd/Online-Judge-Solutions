#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <climits>
using namespace std;

typedef    tuple<int,short,short>   edge;   // cost, start, end.

vector<edge> V;
vector<short> mstEdges;
short n;

class UFDS {
    vector<short> par, setSize;
    short numberOfSets;
public:
    UFDS(short n) {
        setSize.assign(n+1, 1);
        par.resize(n+1);
        for(short i = 1; i <= n; ++i) par[i] = i;
        numberOfSets = n;
    }

    short findSet(short i) { return ((par[i] == i)? i : par[i] = findSet(par[i])); }

    void unionSet(short i, short j) {
        if(findSet(i) != findSet(j)) {
            short p1 = findSet(i), p2 = findSet(j);
            if(setSize[p1] > setSize[p2]) {
                par[p2] = p1;
                setSize[p1] += setSize[p2];
            }
            else {
                par[p1] = p2;
                setSize[p2] += setSize[p1];
            }
            --numberOfSets;
        }
    }

    bool isSameSet(short i, short j) { return findSet(i) == findSet(j); }

    short getNumberOfSets() { return numberOfSets; }
};

int kruskal(int skip = -1)
{
    UFDS uf(n);
    int mst = 0, sz = V.size();
    short u, v, edgeCount = 0;

    for(short i = 0; i < sz && edgeCount != n-1; ++i) {
        u = get<1>(V[i]);
        v = get<2>(V[i]);

        if(uf.isSameSet(u, v) || i == skip) continue;

        uf.unionSet(u, v);
        mst += get<0>(V[i]);
        ++edgeCount;

        if(skip == -1) mstEdges.push_back(i);
    }

    if(uf.getNumberOfSets() == 1) return mst;
    else return -1;    // all the vertices haven't been connected.
}

int main()
{
    short t;
    cin >> t;

    for(short tc = 1; tc <= t; ++tc) {
        V.clear();
        short e, u, v;
        int w;

        cin >> n >> e;

        while(e--) {
            cin >> u >> v >> w;
            V.push_back(edge(w, u, v));
        }

        sort(V.begin(), V.end());
        mstEdges.clear();

        cout << "Case #" << tc << " : ";

        if(kruskal() == -1) {
            cout << "No way\n";
            continue;
        }

        int temp, minn = INT_MAX;

        for(short i = 0; i < n-1; ++i) {
            temp = kruskal(mstEdges[i]);
            if(temp != -1) minn = min(minn, temp);
        }

        if(minn == INT_MAX) cout << "No second way\n";
        else cout << minn << '\n';
    }

    return 0;
}
