#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

const int maxN = 10000+5;

vector<vector<int> > adjList;
vector<int> disc, low;
bitset<maxN> isAP;  // AP means articulation point.
vector<int> used;
int discTime;
int cnt, numberOfComponent, connectedAP;

void dfs_findAP(int u, int parent = -1)
{
    low[u] = disc[u] = ++discTime;

    int v, sz = adjList[u].size(), childCount = 0;

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(!disc[v]) {      // That is, v isn't visited.
            ++childCount;
            dfs_findAP(v, u);

            if(parent == -1 && childCount > 1) isAP[u] = true;
            if(parent != -1 && low[v] >= disc[u]) isAP[u] = true;

            low[u] = min(low[u], low[v]);
        }
        else if(v != parent)
            low[u] = min(low[u], disc[v]);
    }
}

void dfs_traverse(int u)
{
    ++cnt;
    used[u] = 1;

    int v, sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(!used[v] && !isAP[v])
            dfs_traverse(v);

        if(isAP[v] && used[v] != numberOfComponent) {
            ++connectedAP;
            used[v] = numberOfComponent;
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        disc.clear();
        low.clear();
        isAP.reset();
        used.clear();

        int n, m, u, v;
        scanf("%d %d", &n, &m);

        adjList.resize(n);
        disc.assign(n, 0);
        low.resize(n);
        used.assign(n, 0);

        while(m--) {
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        discTime = 0;
        dfs_findAP(0);

        numberOfComponent = 0;
        int shaft = 0;
        unsigned long long numberOfWays = 1;

        for(int i = 0; i < n; ++i) {
            if(!used[i] && !isAP[i]) {
                cnt = connectedAP = 0;
                ++numberOfComponent;
                dfs_traverse(i);

                if(connectedAP < 2) {
                    ++shaft;
                    numberOfWays *= cnt;
                }
            }
        }

        if(shaft == 1) {
            ++shaft;
            numberOfWays = (n * (n-1)) / 2;
        }

        printf("Case %d: %d %llu\n", tc, shaft, numberOfWays);
    }

    return 0;
}
