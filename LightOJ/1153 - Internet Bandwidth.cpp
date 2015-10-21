#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define    mat(i,j)    (*(mat+n*i+j))

int *mat;
int n;
vector<int> path;

bool bfs(int s, int t)
{
    queue<int> q;
    int par[n];
    bool visited[n];
    fill(visited, visited+n, false);

    q.push(s);
    par[s] = -1;
    visited[s] = true;

    int u;

    while(!q.empty()) {
        u = q.front(); q.pop();

        if(u == t) {
            path.push_back(t);
            int p = par[t];
            while(p != -1) {
                path.push_back(p);
                p = par[p];
            }
            reverse(path.begin(), path.end());
            return true;
        }

        for(int v = 0; v < n; ++v) {
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
        int s, t, c;
        scanf("%d %d %d %d", &n, &s, &t, &c);
        --s, --t;

        mat = new int [n*n];
        fill(mat, mat+n*n, 0);

        int u, v, cap;
        while(c--) {
            scanf("%d %d %d", &u, &v, &cap);
            --u, --v;
            mat(u,v) += cap;
            mat(v,u) += cap;
        }

        // Ford-Fulkerson method.

        int totalFlow = 0;

        while(path.clear(), bfs(s, t)) {
            int sz = path.size()-1;
            int minResCap = INT_MAX;

            for(int i = 0; i < sz; ++i)
                minResCap = min(minResCap, mat(path[i], path[i+1]));

            for(int i = 0; i < sz; ++i) {
                u = path[i], v = path[i+1];

                mat(u,v) -= minResCap;
                mat(v,u) += minResCap;
            }

            totalFlow += minResCap;
        }

        printf("Case %d: %d\n", tc, totalFlow);

        delete [] mat;
    }

    return 0;
}
