#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    int n, m;

    while(cin >> n >> m, n != 0 || m != 0) {
        int indegree[n+1];
        vector<int> adjList[n+1];

        memset(indegree, 0, sizeof(indegree));

        int u, v;
        while(m--) {
            cin >> u >> v;
            adjList[u].push_back(v);
            ++indegree[v];
        }

        // topological sort.

        queue<int> q;
        vector<int> solution;

        for(int i = 1; i <= n; ++i) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            u = q.front(); q.pop();
            solution.push_back(u);

            for(unsigned i = 0; i < adjList[u].size(); ++i) {
                v = adjList[u][i];
                --indegree[v];
                if(indegree[v] == 0) q.push(v);
            }
        }

        for(int i = 0; i < n; ++i) {
            if(i) cout << ' ';
            cout << solution[i];
        }
        cout << '\n';
    }

    return 0;
}


// Alternatively, using DFS.
/*

#include <iostream>
#include <vector>
using namespace std;

vector<bool> discovered;
vector<vector<int> > adjList;
vector<int> topoSort;

void dfs(int u)
{
    discovered[u] = true;

    int v;
    for(unsigned i = 0; i < adjList[u].size(); ++i) {
        v = adjList[u][i];
        if(!discovered[v]) dfs(v);
    }

    topoSort.push_back(u);
}

int main()
{
    int n, m;

    while(cin >> n >> m, n != 0 || m != 0) {
        discovered.clear();
        discovered.assign(n+1, 0);
        adjList.clear();
        adjList.resize(n+1);
        topoSort.clear();

        int u, v;

        while(m--) {                    // input.
            cin >> u >> v;
            adjList[u].push_back(v);
        }

        for(int i = 1; i <= n; ++i) {   // process.
            if(!discovered[i]) dfs(i);
        }

        for(int i = n-1; i >= 0; --i) { // output.
            cout << topoSort[i];
            if(i) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}

*/
