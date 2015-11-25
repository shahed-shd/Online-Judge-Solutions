#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<int> bestRoot;
vector<bool> findNode;
int max_dist, max_dist_node;
int len;

void dfs(int u, int dist_upto_u, int parent)
{
    if(max_dist < dist_upto_u) {
        max_dist = dist_upto_u;
        max_dist_node = u;
    }

    for(auto& v : adjList[u])
        if(v != parent)
            dfs(v, dist_upto_u+1, u);
}

void dfs_findByLen(int u, int dist_upto_u, int parent)
{
    if(dist_upto_u == len) {
        findNode[u] = true;
        return;
    }

    for(auto& v : adjList[u])
        if(v != parent)
            dfs_findByLen(v, dist_upto_u+1, u);
}

void dfs_findByLen2(int u, int dist_upto_u, int parent)
{
    if(dist_upto_u == len) {
        if(findNode[u]) {
            bestRoot.push_back(u);
            bestRoot.push_back(parent);
        }
        return;
    }

    for(auto& v : adjList[u])
        if(v != parent)
            dfs_findByLen2(v, dist_upto_u+1, u);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;

    while(scanf("%d", &n) == 1) {
        adjList.clear();
        bestRoot.clear();
        findNode.clear();

        adjList.resize(n);

        int k, id;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &k);
            while(k--) {
                scanf("%d", &id);
                adjList[i].push_back(id-1);
            }
        }

        // Input complete.
        // Now, finding the two ends and the length of the diameter of the tree.

        int diameterEnd1, diameterEnd2, diameterLen;

        for(id = 0; id < n; ++id)
            if(adjList[id].size() != 0)
                break;

        max_dist = -1;
        dfs(id, 0, -1);
        diameterEnd1 = max_dist_node;

        max_dist = -1;
        dfs(diameterEnd1, 0, -1);
        diameterEnd2 = max_dist_node;
        diameterLen = max_dist;

        // The two ends and the length of the diameter of the tree are found.
        // If daimeterLen is odd, there're 2 best roots, otherwise there's only one best root.

        if(diameterLen % 2) {
            len = diameterLen / 2;
            findNode.assign(n, false);
            dfs_findByLen(diameterEnd1, 0, -1);

            ++len;
            dfs_findByLen2(diameterEnd2, 0, -1);

            if(bestRoot[0] > bestRoot[1])
                swap(bestRoot[0], bestRoot[1]);
        }
        else {
            len = diameterLen / 2;
            findNode.assign(n, false);
            dfs_findByLen(diameterEnd1, 0, -1);

            dfs_findByLen2(diameterEnd2, 0, -1);
            bestRoot.pop_back();
        }

        // Best root(s) found.
        // Now, all the worst roots have 'len' length from the best root(s).

        printf("Best Roots  :");

        findNode.assign(n, false);
        for(unsigned i = 0; i < bestRoot.size(); ++i) {
            printf(" %d", bestRoot[i]+1);       // printing the best root(s).
            dfs_findByLen(bestRoot[i], 0, -1);  // finding the worst roots.
        }

        printf("\nWorst Roots :");

        for(int i = 0; i < n; ++i)
            if(findNode[i]) printf(" %d", i+1);
        putchar('\n');
    }

    return 0;
}
