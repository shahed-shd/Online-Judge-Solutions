#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > edge;
vector<bool> visited;
vector<int> level;
queue<int> q;

int ttl, reachable;

void bfs(int u)
{
    if(level[u] > ttl) return;

    q.pop();

    for(unsigned i = 0; i < edge[u].size(); ++i) {
        int v = edge[u][i];

        if(!visited[v]) {
            visited[v] = true;
            level[v] = level[u] + 1;
            q.push(v);

            if(level[v] <= ttl) ++reachable;
        }
    }

    if(!q.empty()) bfs(q.front());
}

int main()
{
    int nc, caseNo = 0;

    while(cin >> nc, nc != 0) {
        edge.clear();

        unsigned u, v, max_uv;

        while(nc--) {
            cin >> u >> v;

            max_uv = max(u, v);

            if(edge.size() < max_uv+1) edge.resize(max_uv+1);

            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        int totalNode = 0;
        for(unsigned i = 0; i < edge.size(); ++i) {
            if(edge[i].size() > 0) ++totalNode;
        }

        int init;

        while(cin >> init >> ttl, init != 0 || ttl != 0) {
            if(unsigned(init) >= edge.size() || edge[init].size() == 0) reachable = 0;
            else if(ttl == 0) reachable = 1;
            else {
                visited.clear();
                visited.resize(edge.size());
                level.clear();
                level.resize(edge.size());
                while(!q.empty()) q.pop();

                q.push(init);
                visited[init] = true;
                level[init] = 0;
                if(edge[init].size() > 0) reachable = 1;
                else reachable = 0;

                bfs(q.front());
            }

            cout << "Case " << ++caseNo << ": " << totalNode - reachable << " nodes not reachable from node " << init << " with TTL = " << ttl << ".\n";
        }
    }

    return 0;
}
