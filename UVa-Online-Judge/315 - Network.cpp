#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<int> disc, low;
int discTime, ans;

void dfs(int u, int parent = -1)
{
    low[u] = disc[u] = ++discTime;

    int childCount = 0;
    bool case1 = false, case2 = false;

    for(auto& v : adjList[u]) {
        if(!disc[v]) {      // That is, v isn't visited.
            ++childCount;
            dfs(v, u);

            if(parent == -1 && childCount > 1) case1 = true;
            if(parent != -1 && low[v] >= disc[u]) case2 = true;

            low[u] = min(low[u], low[v]);
        }
        else if(v != parent)
            low[u] = min(low[u], disc[v]);
    }

    if(case1 || case2) ++ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;

    while(cin >> n, n) {
        adjList.clear();
        disc.clear();
        low.clear();

        adjList.resize(n);
        disc.assign(n, 0);
        low.resize(n);

        int u, v;

        while(cin >> u, u) {
            --u;
            string str;
            getline(cin, str);
            stringstream  ss(str);

            while(ss >> v) {
                --v;
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        // Now, counting articulation points.
        discTime = ans = 0;
        dfs(0);

        cout << ans << '\n';
    }

    return 0;
}
