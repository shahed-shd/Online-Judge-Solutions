#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <iomanip>
using namespace std;

vector<vector<int> > adjList;
vector<int> level;
bitset<21> visited;

void bfs(int src, int dest)
{
    queue<int> q;

    q.push(src);
    level[src] = 0;
    visited.set(src);

    while(!q.empty()) {
        int u = q.front();

        for(unsigned i = 0; i < adjList[u].size(); ++i) {
            int v = adjList[u][i];

            if(!visited[v]) {
                visited.set(v);
                level[v] = level[u] + 1;
                q.push(v);
            }

            if(v == dest) return;
        }

        q.pop();
    }
}

int main()
{
    int x, tc = 0;

    while(cin >> x) {
        adjList.clear();
        adjList.resize(21);   // considering index from 1 to 20, ignoring index 0.

        int j;

        while(x--) {
            cin >> j;
            adjList[1].push_back(j);
            adjList[j].push_back(1);
        }

        for(int i = 2; i <= 19; ++i) {
            cin >> x;

            while(x--) {
                cin >> j;
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }

        int n, src, dest;

        cin >> n;

        cout << "Test Set #" << ++tc << '\n';

        while(n--) {
            level.clear();
            level.resize(21);
            visited.reset();

            cin >> src >> dest;

            bfs(src, dest);

            cout.setf(ios::right);
            cout << setw(2) << src << " to " << setw(2) << dest << ": " << level[dest] << '\n';
        }
        cout << '\n';
    }

    return 0;
}
