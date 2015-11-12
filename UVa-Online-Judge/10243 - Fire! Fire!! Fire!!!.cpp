#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<int> num_of_vertex_with, num_of_vertex_optimal;

void dfs(int u, int parent)
{
    int withNode = 1, withoutNode = 0;
    int sz = adjList[u].size(), v;

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(v != parent) {
            dfs(v, u);

            withNode += num_of_vertex_optimal[v];
            withoutNode += num_of_vertex_with[v];
        }
    }

    num_of_vertex_with[u] = withNode;
    num_of_vertex_optimal[u] = min(withNode, withoutNode);
}

int main()
{
    //freopen("in", "r", stdin);

    int n;

    while(scanf("%d", &n), n != 0) {
        adjList.clear();
        num_of_vertex_with.clear();
        num_of_vertex_optimal.clear();

        adjList.resize(n);
        num_of_vertex_with.resize(n);
        num_of_vertex_optimal.resize(n);

        for(int i = 0; i < n; ++i) {
            int ni, v;
            scanf("%d", &ni);

            while(ni--) {
                scanf("%d", &v);
                adjList[i].push_back(--v);
            }
        }

        int root = 0;

        dfs(root, -1);

        printf("%d\n", (num_of_vertex_optimal[root]?: 1));
    }

    return 0;
}



// =========================== Alternative solution ===========================
/*

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define     dp(i,j)     (*(dp+2*i+j))

vector<vector<int> > adjList;
int *dp;

int f(int u, bool isTaken, int parent)
{
    if(adjList[u].size() == 0) return 1;

    if(dp(u, isTaken) != -1) return dp(u, isTaken);

    int v, sz = adjList[u].size(), sum = 0;

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(v != parent) {
            if(!isTaken) sum += f(v, true, u);
            else sum += min(f(v, true, u), f(v, false, u));
        }
    }

    return dp(u, isTaken) = sum + isTaken;
}

int main()
{
    //freopen("in", "r", stdin);

    int n;

    while(scanf("%d", &n), n != 0) {
        adjList.clear();

        adjList.resize(n);
        dp = new int [n*2];
        memset(dp, -1, n*2*sizeof(int));

        for(int i = 0; i < n; ++i) {
            int ni, v;
            scanf("%d", &ni);

            while(ni--) {
                scanf("%d", &v);
                adjList[i].push_back(--v);
            }
        }

        printf("%d\n", min(f(0, true, -1), f(0, false, -1)));

        delete [] dp;
    }

    return 0;
}

*/
