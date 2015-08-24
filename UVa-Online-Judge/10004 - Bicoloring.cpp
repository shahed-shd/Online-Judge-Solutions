#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adjList;
vector<int> color;
queue<int> q;

void bicolorable(int u)
{
    q.pop();

    for(unsigned i = 0; i < adjList[u].size(); ++i) {
        int v = adjList[u][i];

        if(!color[v]) {
            color[v] = 0 - color[u];
            q.push(v);
        }
        else if(color[u] == color[v]) {
            cout << "NOT BICOLORABLE.\n";
            return;
        }
    }

    if(q.empty()) {
        cout << "BICOLORABLE.\n";
        return;
    }
    else bicolorable(q.front());
}

int main()
{
    int n, l, u, v;

    while(cin >> n, n != 0) {
        adjList.clear();
        adjList.resize(n);
        color.clear();
        color.resize(n);

        while(!q.empty()) q.pop();

        cin >> l;

        for(int i = 0; i < l; ++i) {
            cin >> u >> v;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        q.push(0);
        color[0] = -1;

        bicolorable(q.front());
    }

    return 0;
}
