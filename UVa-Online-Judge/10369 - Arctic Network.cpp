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
