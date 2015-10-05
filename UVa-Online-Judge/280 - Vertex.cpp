#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<bool> visited;
int cnt, start;
bool flag;

void dfs(int u)
{
    visited[u] = true;
    ++cnt;

    for(auto& v : adjList[u]) {
        if(v == start) flag = true;
        if(!visited[v]) dfs(v);
    }
}

int main()
{
    int n;

    while(cin >> n, n != 0) {
        adjList.clear();
        adjList.resize(n+1);

        int u, v;
        while(cin >> u, u != 0) {
            while(cin >> v, v != 0) {
                adjList[u].push_back(v);
            }
        }

        int howMany;
        cin >> howMany;

        while(howMany--) {
            cin >> start;

            visited.clear();
            visited.assign(n+1, false);
            cnt = 0;
            flag = false;

            dfs(start);

            if(!flag) {
                --cnt;
                visited[start] = false;
            }
            cout << n - cnt;

            for(int i = 1; i <= n; ++i) {
                if(!visited[i]) cout << ' ' << i;
            }
            cout << '\n';
        }
    }

    return 0;
}
