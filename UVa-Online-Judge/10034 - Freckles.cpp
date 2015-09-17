#include <cstdio>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef    pair<double,double>    xy;
typedef    pair<double,xy>    pr;

double dist(xy a, xy b)
{
    double temp1, temp2;

    temp1 = a.first - b.first;
    temp2 = a.second - b.second;

    return sqrt(temp1*temp1 + temp2*temp2);
}

double prim(xy storeXY[], short n)
{
    priority_queue<pr, vector<pr>, greater<pr> > q;
    map<xy, bool> visited;

    for(short i = 1; i < n; ++i) {
        q.push(pr(dist(storeXY[0], storeXY[i]), storeXY[i]));
    }
    visited[storeXY[0]] = true;

    double cost, ans = 0;
    xy v;

    while(!q.empty()) {
        cost = q.top().first;
        v = q.top().second;
        q.pop();

        if(visited[v] || cost == 0) continue;

        visited[v] = true;
        ans += cost;

        for(short i = 0; i < n; ++i) {
            q.push(pr(dist(v, storeXY[i]), storeXY[i]));
        }
    }

    return ans;
}

int main()
{
    int tc;
    bool newline = false;

    scanf("%d", &tc);

    while(tc--) {
        short n;
        scanf("%hd", &n);

        double x, y;
        xy storeXY[n];

        for(short i = 0; i < n; ++i) {
            scanf("%lf %lf", &x, &y);
            storeXY[i] = xy(x, y);
        }

        if(newline) printf("\n");
        newline = true;

        printf("%.2lf\n", prim(storeXY, n));
    }

    return 0;
}
