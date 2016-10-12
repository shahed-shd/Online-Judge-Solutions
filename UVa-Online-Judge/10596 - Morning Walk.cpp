// ==================================================
// Problem  :   10596 - Morning Walk
// Run time :   0.050 sec.
// Language :   C++11
// ===================================================

#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 200 + 3;

vector<vector<int> > adjList;
bitset<MAXN> vis;

void dfs(int u)
{
    vis[u] = true;

    for(auto &v : adjList[u])
        if(!vis[v])
            dfs(v);
}

int main()
{
    //freopen("in", "r", stdin);

    int n, r;

    while(~scanf("%d %d", &n, &r)) {
        if(!r) {                    // It's a tricky case when r == 0.
            puts("Not Possible");
            continue;
        }

        adjList.clear();
        vis.reset();

        vector<int> degreeCnt(n+3, 0);
        adjList.resize(n+3);

        int c1, c2;

        while(r--) {
            scanf("%d %d", &c1, &c2);

            adjList[c1].push_back(c2);
            adjList[c2].push_back(c1);

            ++degreeCnt[c1], ++degreeCnt[c2];
        }

        bool eulerCircuit = true;

        for(int i = 0; i < n; ++i) {
            if(degreeCnt[i] & 1) {
                eulerCircuit = false;
                break;
            }
        }

        if(eulerCircuit) {
            for(int i = 0; i < n; ++i) {
                if(degreeCnt[i]) {
                    dfs(i);
                    break;
                }
            }

            for(int i = 0; i < n; ++i) {
                if(!vis[i] && degreeCnt[i]) {
                    eulerCircuit = false;
                    break;
                }
            }
        }

        puts(((eulerCircuit)? "Possible" : "Not Possible"));
    }

    return 0;
}
