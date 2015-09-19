#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;

typedef    tuple<double,int,int>    tpl;    //distance, x, y.
typedef    pair<int,int>    pr;     // x, y.

int numberOfStates;
double mstRoads, mstRailroads;

void prim(int arr[][2], int n, int r)
{
    priority_queue<tpl, vector<tpl>, greater<tpl> > q;
    map<pr, bool> visited;

    for(int i = 1; i < n; ++i) {
        q.push(tpl(hypot(arr[0][0] - arr[i][0], arr[0][1] - arr[i][1]), arr[i][0], arr[i][1]));
    }
    visited[pr(arr[0][0], arr[0][1])] = true;

    numberOfStates = 1;
    mstRoads = mstRailroads = 0;
    double dist;
    int x, y;

    while(!q.empty()) {
        dist = get<0>(q.top());
        x = get<1>(q.top());
        y = get<2>(q.top());
        q.pop();

        if(visited[pr(x,y)] || dist == 0) continue;

        if(dist > r) {
            ++numberOfStates;
            mstRailroads += dist;
        }
        else mstRoads += dist;

        visited[pr(x,y)] = true;
        for(int i = 0; i < n; ++i) {
            q.push(tpl(hypot(x - arr[i][0], y - arr[i][1]), arr[i][0], arr[i][1]));
        }
    }
}

int main()
{
    short t;

    cin >> t;

    for(short tc = 1; tc <= t; ++tc) {
        int n, r;

        cin >> n >> r;

        int arr[n][2];

        for(int i = 0; i < n; ++i) {
            cin >> arr[i][0] >> arr[i][1];
        }

        prim(arr, n, r);

        cout.precision(0);
        fixed(cout);

        cout << "Case #" << tc << ": "
            << numberOfStates << ' '
            << mstRoads << ' '
            << mstRailroads << '\n';
    }

    return 0;
}
