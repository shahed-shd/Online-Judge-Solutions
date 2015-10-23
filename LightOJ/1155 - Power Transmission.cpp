#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define     mat(i,j)    (*(mat+node*i+j))
#define     in(i)       (2*i-1)
#define     out(i)      (2*i)

int node;
int *mat;
vector<int> path;

bool bfs()
{
    queue<int> q;
    int par[node];
    int visited[node];
    fill(visited, visited+node, false);

    q.push(0);
    par[0] = -1;
    visited[0] = true;

    int u;

    while(!q.empty()) {
        u = q.front(); q.pop();

        if(u == node-1) {
            path.clear();
            path.push_back(u);
            int p = par[u];
            while(p != -1) {
                path.push_back(p);
                p = par[p];
            }
            reverse(path.begin(), path.end());
            return true;
        }

        for(int v = 0; v < node; ++v) {
            if(mat(u,v) && !visited[v]) {
                visited[v] = true;
                par[v] = u;
                q.push(v);
            }
        }
    }

    return false;
}

int main()
{
    //freopen("in", "r", stdin);

    int testCase;
    scanf("%d", &testCase);

    for(int tc = 1; tc <= testCase; ++tc) {
        int n;
        scanf("%d", &n);
        node = n+n+2;

        mat = new int [node*node];
        fill(mat, mat+node*node, 0);

        int u, v, cap;

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &cap);
            mat(in(i), out(i)) = cap;
        }

        int m;
        scanf("%d", &m);

        while(m--) {
            scanf("%d %d %d", &u, &v, &cap);
            mat(out(u), in(v)) = cap;
        }

        int b, d;
        scanf("%d %d", &b, &d);

        while(b--) {
            scanf("%d", &u);
            mat(0, in(u)) = INT_MAX;
        }

        while(d--) {
            scanf("%d", &u);
            mat(out(u), node-1) = INT_MAX;
        }

        // Ford-Fulkerson method.

        int totalFlow = 0;

        while(bfs()) {
            int minResCap = INT_MAX;
            int sz = path.size() - 1;

            for(int i = 0; i < sz; ++i) {
                u = path[i];
                v = path[i+1];
                minResCap = min(minResCap, mat(u,v));
            }

            for(int i = 0; i < sz; ++i) {
                u = path[i];
                v = path[i+1];
                mat(u, v) -= minResCap;
                mat(v, u) += minResCap;
            }

            totalFlow += minResCap;
        }

        printf("Case %d: %d\n", tc, totalFlow);

        delete [] mat;
    }

    return 0;
}
