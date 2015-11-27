/*
 * Find the diameter (longest path) of the input tree.
 * If we remove an edge, then the tree will be divided into two subtrees.
 * Remove an edge from the diameter of the input tree,
    and place it to connect the centres of the two subtrees.
    Then find the diameter of newly created tree.
 * This process is applied to every edge of the diameter of the input tree.
 * Result would be the minimum value of all the new diameters.
*/

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

#define     matrix(i,j)     (*(matrix+n*i+j))

vector<vector<int> > adjList;
vector<bool> mark;
vector<int> dist;
bool *matrix;
int n;
int max_dist, max_dist_node;    // used in dfs_max(), main().
int len, root;                  // used in dfs_len(), dfs_len2(), findTreeCentre().

void dfs_dist(int u, int dist_upto_u, int parent)
{
    dist[u] = dist_upto_u;

    for(auto& x : adjList[u])
        if(x != parent && matrix(u, x))
            dfs_dist(x, dist_upto_u+1, u);
}

void dfs_max(int u, int dist_upto_u, int parent)
{
    if(max_dist < dist_upto_u) {
        max_dist = dist_upto_u;
        max_dist_node = u;
    }

    for(auto& x : adjList[u])
        if(x != parent && matrix(u, x))
            dfs_max(x, dist_upto_u+1, u);
}

void dfs_len(int u, int dist_upto_u, int parent)
{
    if(dist_upto_u == len) {
        mark[u] = true;
        return;
    }

    for(auto& x : adjList[u])
        if(x != parent && matrix(u, x))
            dfs_len(x, dist_upto_u+1, u);
}

void dfs_len2(int u, int dist_upto_u, int parent)
{
    if(dist_upto_u == len) {
        if(mark[u]) root = u;
        return;
    }

    for(auto& x : adjList[u])
        if(x != parent && matrix(u, x))
            dfs_len2(x, dist_upto_u+1, u);
}

int find_diameter_len(int node)
{
    max_dist = -1;
    dfs_max(node, 0, -1);

    max_dist = -1;
    dfs_max(max_dist_node, 0, -1);

    return max_dist;
}

int findTreeCentre(int node)
{
    int diameterEnd1, diameterEnd2, diameterLen;

    max_dist = -1;
    dfs_max(node, 0, -1);
    diameterEnd1 = max_dist_node;

    max_dist = -1;
    dfs_max(diameterEnd1, 0, -1);
    diameterEnd2 = max_dist_node;
    diameterLen = max_dist;

    mark.assign(n, false);

    len = diameterLen / 2;
    dfs_len(diameterEnd1, 0, -1);

    if(diameterLen % 2) ++len;
    dfs_len2(diameterEnd2, 0, -1);

    return root;
}

vector<int> find_diameter_way(int dia_end1, int dia_end2)
{
    vector<int> way;
    way.push_back(dia_end2);
    int min_dist, min_dist_node=0, node = dia_end2;

    while(node != dia_end1) {
        min_dist = INT_MAX;

        for(auto& x : adjList[node])
            if(min_dist > dist[x] && matrix(node, x))
                min_dist = dist[x], min_dist_node = x;

        node = min_dist_node;
        way.push_back(node);
    }

    return way;
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        adjList.clear();
        mark.clear();
        dist.clear();

        scanf("%d", &n);

        adjList.resize(n);
        matrix = new bool [n*n];
        fill_n(matrix, n*n, false);

        int u, v;

        for(int i = 1; i < n; ++i) {
            scanf("%d %d", &u, &v);
            --u, --v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            matrix(u, v) = true;
            matrix(v, u) = true;
        }

        int dia_end1, dia_end2, dia_len;

        max_dist = -1;
        dfs_max(0, 0, -1);

        dia_end1 = max_dist_node;

        dist.resize(n);
        dfs_dist(dia_end1, 0, -1);

        max_dist = -1;
        for(int i = 0; i < n; ++i)
            if(max_dist < dist[i])
                max_dist = dist[i], max_dist_node = i;

        dia_end2 = max_dist_node;
        dia_len = max_dist;

        vector<int> dia_way(find_diameter_way(dia_end1, dia_end2));

        int minLenNow = INT_MAX, cancel_u=0, cancel_v=0, add_u=0, add_v=0;  // assigning zero for no cause,
                                                                            // just to avoid warning messages while compiling.
        for(int i = 0; i < dia_len; ++i) {    // as 'dia_way' contains dia_len+1 nodes.
            u = dia_way[i];
            v = dia_way[i+1];

            matrix(u, v) = matrix(v, u) = false;

            int c1 = findTreeCentre(u), c2 = findTreeCentre(v);

            adjList[c1].push_back(c2);
            adjList[c2].push_back(c1);

            matrix(c1, c2) = matrix(c2, c1) = true;

            int lenNow = find_diameter_len(c1);

            if(minLenNow > lenNow) {
                minLenNow = lenNow;
                cancel_u = u, cancel_v = v;
                add_u = c1, add_v = c2;
            }

            matrix(u, v) = matrix(v, u) = true;
            matrix(c1, c2) = matrix(c2, c1) = false;
            adjList[c1].pop_back();
            adjList[c2].pop_back();
        }

        printf("%d\n%d %d\n%d %d\n", minLenNow, cancel_u+1, cancel_v+1, add_u+1, add_v+1);

        delete [] matrix;
    }

    return 0;
}
