#include <cstdio>
#include <vector>
using namespace std;

#define     dist(i)     (*(dist+2*i+f))
typedef     pair<int,int>   ii;

vector<vector<ii> > adjList;
int f, *dist;

void dfs(int u, int parent)
{
    int v, sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i].first;
        if(v != parent) {
            dist(v) = dist(u) + adjList[u][i].second;
            dfs(v, u);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        int n, u, v, w;
        scanf("%d", &n);

        adjList.resize(n);
        dist = new int [n*2];   // dist will be used as a two dimensional array having n rows and 2 columns.

        for(int i = 1; i < n; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            adjList[u].push_back(ii(v, w));
            adjList[v].push_back(ii(u, w));
        }

        int diameter_end1, diameter_end2;

        // Finding one end of the diameter of the tree.
        f = 0;
        dist(0) = 0;
        dfs(0, -1);

        diameter_end1 = 0;
        for(int i = 0; i < n; ++i)
            if(dist(diameter_end1) < dist(i))
                diameter_end1 = i;

        // Finding another end of the diameter of the tree
        // and calculating the distances of all nodes from diameter_end1.

        f = 0;
        dist(diameter_end1) = 0;
        dfs(diameter_end1, -1);

        diameter_end2 = diameter_end1;
        for(int i = 0; i < n; ++i)
            if(dist(diameter_end2) < dist(i))
                diameter_end2 = i;

        // Now, calculating the distances of all nodes from diameter_end2.
        f = 1;
        dist(diameter_end2) = 0;
        dfs(diameter_end2, -1);

        printf("Case %d:\n", tc);

        // For all nodes, print max(distance from diameter_end1, distance from diameter_end2).
        for(int i = 0; i < n; ++i)
            printf("%d\n", max(*(dist+2*i+0), *(dist+2*i+1)));

        delete [] dist;
    }

    return 0;
}
