#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<bool> visited;
int cnt;

void dfs(int u)
{
    visited[u] = true;
    ++cnt;

    for(auto& v : adjList[u]) {
        if(!visited[v]) dfs(v);
    }
}

int main()
{
    int tc;
    cin >> tc;

    while(tc--) {
        adjList.clear();
        visited.clear();

        int n, m, l;
        cin >> n >> m >> l;

        adjList.resize(n+1);
        visited.assign(n+1, false);

        int u, v;
        while(m--) {
            cin >> u >> v;
            adjList[u].push_back(v);
        }

        cnt = 0;
        while(l--) {
            cin >> u;
            if(!visited[u]) dfs(u);
        }

        cout << cnt << '\n';
    }

    return 0;
}
