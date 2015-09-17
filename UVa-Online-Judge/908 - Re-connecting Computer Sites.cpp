#include <cstdio>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

typedef tuple<int, int, int> edge;    // w, u, v.

class UFDS {
    vector<int> par, rank;
public:
    UFDS(int n) {
        rank.assign(n+1, 0);
        par.resize(n+1);
        for(int i = 0; i <= n; ++i) par[i] = i;
    }

    int findSet(int i) { return ((par[i] == i)? i : par[i] = findSet(par[i])); }

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

    bool isSameSet(int i, int j) { return (findSet(i) == findSet(j)); }
};

long long int kruskal(priority_queue<edge, vector<edge>, greater<edge> > &q, int n)
{
    UFDS uf(n);
    int edgeCount = 0;
    long long int ans = 0;

    int u, v, w;

    while(edgeCount != n-1) {
        w = get<0>(q.top());
        u = get<1>(q.top());
        v = get<2>(q.top());
        q.pop();

        if(uf.isSameSet(u, v)) continue;

        ans += w;
        uf.unionSet(u, v);
        ++edgeCount;
    }

    return ans;
}

int main()
{
    int n;
    short k;
    long long int m;
    bool newline = false;

    while(scanf("%d", &n) != EOF) {
        int u, v, w;
        long long int ans1 = 0;

        for(int i = 1; i < n; ++i) {
            scanf("%*d %*d %d", &w);
            ans1 += w;
        }

        priority_queue<edge, vector<edge>, greater<edge> > q;

        scanf("%hd", &k);
        while(k--) {
            scanf("%d %d %d", &u, &v, &w);
            q.push(edge(w, u, v));
        }

        scanf("%lld", &m);
        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            q.push(edge(w, u, v));
        }

        if(newline) printf("\n");
        newline = true;

        printf("%lld\n%lld\n", ans1, kruskal(q, n));
    }

    return 0;
}




// Alternatively by Prim's algorithm.
/*

#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef    pair<int,int>   pr;

long long int prim(vector<pr> adjList[], int n)
{
    priority_queue<pr, vector<pr>, greater<pr> > q;   // pair holds w, v.
    bool visited[n+1];

    memset(visited, 0, sizeof(visited));

    for(unsigned i = 0; i < adjList[1].size(); ++i) {
        q.push(pr(adjList[1][i].second, adjList[1][i].first));
    }
    visited[1] = true;

    long long int ans = 0;
    int w, v;

    while(!q.empty()) {
        w = q.top().first;
        v = q.top().second;
        q.pop();

        if(visited[v]) continue;

        visited[v] = true;
        ans += w;

        for(unsigned i = 0; i < adjList[v].size(); ++i) {
            q.push(pr(adjList[v][i].second, adjList[v][i].first));
        }
    }

    return ans;
}

int main()
{
    int n;
    short k;
    long long int m;
    bool newline = false;

    while(scanf("%d", &n) != EOF) {
        long long ans1 = 0;
        int u, v, w;

        for(int i = 1; i < n; ++i) {
            scanf("%*d %*d %d", &w);
            ans1 += w;
        }

        vector<pr> adjList[n+1];    // pair holds v, w.

        scanf("%hd", &k);
        while(k--) {
            scanf("%d %d %d", &u, &v, &w);
            adjList[u].push_back(pr(v, w));
            adjList[v].push_back(pr(u, w));
        }

        scanf("%lld", &m);
        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            adjList[u].push_back(pr(v, w));
            adjList[v].push_back(pr(u, w));
        }

        if(newline) printf("\n");
        newline = true;

        printf("%lld\n%lld\n", ans1, prim(adjList, n));
    }

    return 0;
}

*/
