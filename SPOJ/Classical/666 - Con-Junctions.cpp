#include <cstdio>
#include <vector>
using namespace std;

const int MOD = 10007;

vector<vector<int> > adjList;
vector<int> num_of_vertex_optimal;
vector<int> num_of_vertex_with_node;
vector<int> num_of_ways_optimal;
vector<int> num_of_ways_with_node;

void dfs(int u, int parent)
{
    int sz = adjList[u].size();
    int v;

    int withNode = 1, waysWithNode = 1, withoutNode = 0, waysWithoutNode = 1;

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(v != parent) {
            dfs(v, u);

            withNode += num_of_vertex_optimal[v];
            waysWithNode *= num_of_ways_optimal[v];
            waysWithNode %= MOD;

            withoutNode += num_of_vertex_with_node[v];
            waysWithoutNode *= num_of_ways_with_node[v];
            waysWithoutNode %= MOD;
        }
    }

    num_of_vertex_with_node[u] = withNode;
    num_of_ways_with_node[u] = waysWithNode;

    if(withNode < withoutNode) {
        num_of_vertex_optimal[u] = withNode;
        num_of_ways_optimal[u] = waysWithNode;
    }
    else if(withNode > withoutNode) {
        num_of_vertex_optimal[u] = withoutNode;
        num_of_ways_optimal[u] = waysWithoutNode;
    }
    else {
        num_of_vertex_optimal[u] = withNode;
        num_of_ways_optimal[u] = (waysWithNode + waysWithoutNode) % MOD;
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        adjList.clear();
        num_of_vertex_optimal.clear();
        num_of_vertex_with_node.clear();
        num_of_ways_optimal.clear();
        num_of_ways_with_node.clear();

        int n;
        scanf("%d", &n);

        adjList.resize(n);
        num_of_vertex_optimal.resize(n);
        num_of_vertex_with_node.resize(n);
        num_of_ways_optimal.resize(n);
        num_of_ways_with_node.resize(n);

        int u, v;

        for(int i = 1; i < n; ++i) {
            scanf("%d %d", &u, &v);
            --u, --v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int root = 0;

        dfs(root, -1);

        printf("%d %d\n", num_of_vertex_optimal[root], num_of_ways_optimal[root]);
    }
}
