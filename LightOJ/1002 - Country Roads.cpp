// Run time : 0.156 sec.

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef     pair<int,int>   ii;
typedef     pair<int,ii>    iii;

const int MAXN = 500+3;

vector<vector<ii> > adjList;
int costs[MAXN];

class UFDS {
    int parent[MAXN], rnk[MAXN] = {0};
public:
    UFDS(int n) {
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findSet(int n) {
        return ((parent[n] == n)? n : parent[n] = findSet(parent[n]));
    }

    bool unionSet(int u, int v) {
        if(findSet(u) == findSet(v)) return false;

        int p1 = findSet(u), p2 = findSet(v);
        if(rnk[p1] > rnk[p2]) {
            parent[p2] = p1;
        }
        else {
            parent[p1] = p2;
            if(rnk[p1] == rnk[p2]) ++rnk[p2];
        }

        return true;
    }
};

void dfs(int u, int par = -1)
{
    int sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        int v = adjList[u][i].first;

        if(v != par) {
            costs[v] = max(costs[u], adjList[u][i].second);
            dfs(v, u);
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

        vector<iii> edges;
        int u, v, w, t;

        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            if(u > v) swap(u, v);
            edges.push_back(iii(w, ii(u, v)));
        }
        scanf("%d", &t);

        sort(edges.begin(), edges.end());

        vector<iii> spanningEdges;
        UFDS uf(n);

        for(vector<iii>::iterator it = edges.begin(); it != edges.end(); ++it) {
            if(uf.unionSet(it->second.first, it->second.second)) {
                spanningEdges.push_back(*it);
                if(int(spanningEdges.size()) == n-1) break;
            }
        }

        adjList.resize(n);

        for(vector<iii>::iterator it = spanningEdges.begin(); it != spanningEdges.end(); ++it) {
            w = it->first, u = it->second.first, v = it->second.second;
            adjList[u].push_back(ii(v, w));
            adjList[v].push_back(ii(u, w));
        }

        fill(costs, costs+n, -1);
        costs[t] = 0;

        dfs(t);

        printf("Case %d:\n", tc);

        for(int i = 0; i < n; ++i)
            (costs[i] == -1)? puts("Impossible") : printf("%d\n", costs[i]);
    }

    return 0;
}


// ----------------------- Alternatively -----------------------
// Run time : 0.208 sec.
/*
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
*/
