#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<int> topoSort;
vector<bool> discovered;

void dfs_topoSort(int u)
{
    discovered[u] = true;

    int v;
    for(unsigned i = 0; i < adjList[u].size(); ++i) {
        v = adjList[u][i];
        if(!discovered[v]) dfs_topoSort(v);
    }

    topoSort.push_back(u);
}

void dfs(int u)
{
    discovered[u] = true;

    int v;
    for(unsigned i = 0; i < adjList[u].size(); ++i) {
        v = adjList[u][i];
        if(!discovered[v]) dfs(v);
    }
}

int main()
{
    int tc;

    cin >> tc;

    while(tc--) {
        int n, m;

        cin >> n >> m;

        adjList.clear();
        adjList.resize(n+1);
        int u, v;

        while(m--) {
            cin >> u >> v;
            adjList[u].push_back(v);
        }

        discovered.clear();
        discovered.assign(n+1, false);

        topoSort.clear();
        for(int i = 1; i <= n; ++i) {
            if(!discovered[i]) dfs_topoSort(i);
        }

        // As it may not be a DAG, so knock down the dominos ony by one and count the number.

        discovered.assign(n+1, false);

        int cnt = 0;
        for(int i = n-1; i >= 0; --i) {     // As topoSort contains elements in reversal order of topological sort.
            if(!discovered[topoSort[i]]) {
                dfs(topoSort[i]);
                ++cnt;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
