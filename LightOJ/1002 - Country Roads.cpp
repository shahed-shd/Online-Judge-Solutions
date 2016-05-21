#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef     pair<int,int>   ii;

const int MAXN = 500+3;

vector<vector<ii> > adjList;
int costs[MAXN];

void prims(int n, int t)
{
    fill(costs, costs+n, -1);
    costs[t] = 0;

    priority_queue<ii, vector<ii>, greater<ii> > q;
    int sz = adjList[t].size();
    for(int i = 0; i < sz; ++i)
        q.push(ii(adjList[t][i].second, adjList[t][i].first));

    --n;
    int mxEdge = 0;

    while(!q.empty() && n){
        ii x = q.top(); q.pop();
        int u = x.second;

        if(costs[u] == -1) {
            --n;
            costs[u] = mxEdge = max(mxEdge, x.first);
            sz = adjList[u].size();

            for(int i = 0; i < sz; ++i)
                q.push(ii(adjList[u][i].second, adjList[u][i].first));
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; ++tc) {
        adjList.clear();

        int n, m;
        scanf("%d %d", &n, &m);

        adjList.resize(n);

        int u, v, w, t;

        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            adjList[u].push_back(ii(v, w));
            adjList[v].push_back(ii(u, w));
        }
        scanf("%d", &t);

        prims(n, t);

        printf("Case %d:\n", tc);

        for(int i = 0; i < n; ++i)
            (costs[i] == -1)? puts("Impossible") : printf("%d\n", costs[i]);
    }

    return 0;
}
