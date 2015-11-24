#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef     pair<int,int>   ii;

vector<vector<ii> > adjList;
int max_dist_node;
long long max_dist;

void dfs(int u, long long dist_upto_u, int parent)
{
    if(max_dist < dist_upto_u) {
        max_dist = dist_upto_u;
        max_dist_node = u;
    }

    for(auto& pr : adjList[u])
        if(pr.first != parent)
            dfs(pr.first, dist_upto_u + pr.second, u);
}

void input(char str[])
{
    int u, v, w;
    sscanf(str, "%d %d %d", &u, &v, &w);

    int mx = max(u, v);
    if(mx > (int) adjList.size()) adjList.resize(mx+5);

    adjList[--u].push_back(ii(--v, w));
    adjList[v].push_back(ii(u, w));
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char str[30];

    while(fgets(str, sizeof(str), stdin)) {
        if(strlen(str) <= 1) {
            puts("0");
            continue;
        }

        adjList.clear();

        do input(str);
        while(fgets(str, sizeof(str), stdin) && strlen(str) > 1);

        max_dist = -1;
        dfs(0, 0, -1);

        max_dist = -1;
        dfs(max_dist_node, 0, -1);

        printf("%lld\n", max_dist);
    }

    return 0;
}
