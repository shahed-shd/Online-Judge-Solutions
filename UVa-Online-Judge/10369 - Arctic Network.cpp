#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cmath>
using namespace std;

vector<tuple<double,short,short> > edges;
short s, p;

class UFDS {
    vector<short> par, rank;
public:
    UFDS(short n) {
        rank.assign(n, 0);
        par.resize(n);
        for(short i = 0; i < p; ++i) par[i] = i;
    }

    short findSet(short i) { return ((par[i] == i)? i : par[i] = findSet(par[i])); }

    void unionSet(short i, short j) {
        if(findSet(i) != findSet(j)) {
            short p1 = findSet(i), p2 = findSet(j);

            if(rank[p1] > rank[p2]) {
                par[p2] = p1;
            }
            else {
                par[p1] = p2;
                if(rank[p1] == rank[p2]) ++rank[p2];
            }
        }
    }

    bool isSameSet(short i, short j) { return findSet(i) == findSet(j); }
};

double kruskal()
{
    sort(edges.begin(), edges.end());

    UFDS uf(p);
    int edgeCount = 0, sz = edges.size();
    short x, y;

    int i;
    for(i = 0; i < sz && edgeCount != p-s; ++i) {   // p-1-(s-1) = p-s
        x = get<1>(edges[i]);
        y = get<2>(edges[i]);

        if(uf.isSameSet(x, y)) continue;

        uf.unionSet(x, y);
        ++edgeCount;
    }

    return  get<0>(edges[i-1]);
}

int main()
{
    int n;
    cin >> n;

    while(n--) {
        vector<pair<short,short> > outposts;
        short x, y;

        cin >> s >> p;

        for(short i = 0; i < p; ++i) {
            cin >> x >> y;
            outposts.push_back(make_pair(x, y));
        }

        edges.clear();
        double dist;

        for(short i = 0; i < p; ++i) {
            for(short j = i+1; j < p; ++j) {
                dist = hypot(outposts[i].first - outposts[j].first, outposts[i].second - outposts[j].second);
                edges.push_back(make_tuple(dist, i, j));
            }
        }

        cout.precision(2); fixed(cout);
        cout << kruskal() << '\n';
    }

    return 0;
}



// Alternatively, by using Prim's algorithm.
/*

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef    pair<short,short>    xy;
typedef    pair<double,short>   pr;    // distance, vertex.

vector<pr> outposts;
vector<double> mstEdges;
short p;

void prim()
{
    priority_queue<pr, vector<pr>, greater<pr> > q;

    bool visited[p];
    memset(visited, 0, sizeof(visited));

    double dist;
    for(int i = 1; i < p; ++i) {
        dist = hypot(outposts[0].first - outposts[i].first, outposts[0].second - outposts[i].second);
        q.push(pr(dist, i));
    }
    visited[0] = true;

    short v;
    while(!q.empty()) {
        dist = q.top().first;
        v = q.top().second;
        q.pop();

        if(visited[v] || dist == 0) continue;

        visited[v] = true;
        mstEdges.push_back(dist);
        for(int i = 0; i < p; ++i) {
            dist = hypot(outposts[v].first - outposts[i].first, outposts[v].second - outposts[i].second);
            q.push(pr(dist, i));
        }
    }
}

int main()
{
    int n;

    cin >> n;

    while(n--) {
        outposts.clear();
        mstEdges.clear();

        short s, x, y;
        cin >> s >> p;

        for(int i = 0; i < p; ++i) {
            cin >> x >> y;
            outposts.push_back(xy(x, y));
        }

        prim();
        sort(mstEdges.begin(), mstEdges.end(), greater<double>());

        cout.precision(2); fixed(cout);
        cout << mstEdges[s-1] << '\n';
    }

    return 0;
}

*/
