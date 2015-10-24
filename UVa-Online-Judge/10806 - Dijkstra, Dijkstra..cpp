#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define     mat(i,j)    (*(mat+n*i+j))
typedef     pair<int,int>   ii;

const int INF = INT_MAX/2;

int *mat;
vector<int> path;
int n;

int dijkstra(int time)
{
    priority_queue<ii, vector<ii>, greater<ii> > q;
    int par[n];
    int dist[n];
    fill(dist, dist+n, INF);

    q.push(ii(0,0));
    par[0] = -1;
    dist[0] = 0;

    int u;

    while(!q.empty()) {
        u = q.top().second; q.pop();

        if(u == n-1) {
            if(time == 1) {     // As we don't need the path at the 2nd time.
                path.clear();
                path.push_back(u);
                int p = par[u];
                while(p != -1) {
                    path.push_back(p);
                    p = par[p];
                }
                reverse(path.begin(), path.end());
            }
            return dist[n-1];
        }

        for(int v = 0; v < n; ++v) {
            if(mat(u,v) && dist[v] > dist[u] + mat(u,v)) {
                dist[v] = dist[u] + mat(u,v);
                par[v] = u;
                q.push(ii(dist[v], v));
            }
        }
    }

    return 0;
}

int main()
{
    //freopen("in", "r", stdin);

    while(scanf("%d", &n), n != 0) {
        mat = new int [n*n];
        fill(mat, mat+n*n, 0);

        int m, u, v, w;
        scanf("%d", &m);

        while(m--) {
            scanf("%d %d %d", &u, &v, &w);
            --u, --v;
            mat(u,v) = mat(v,u) = w;
        }

        int res1 = dijkstra(1);

        if(res1) {
            int sz = path.size() - 1;

            for(int i = 0; i < sz; ++i) {
                u = path[i];
                v = path[i+1];
                mat(u,v) = 0;
                mat(v,u) *= -1;
            }

            int res2 = dijkstra(2);

            if(res2) printf("%d\n", res1+res2);
            else printf("Back to jail\n");
        }
        else printf("Back to jail\n");
    }

    return 0;
}
