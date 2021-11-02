// ==================================================
// Problem  :   1593E - Gardener and Tree
// Run time :   0.342 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <queue>
#include <vector>
using namespace std;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        vector<vector<int>> adjList(n);
        vector<int> edgeCount(n, 0);

        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u, --v;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
            ++edgeCount[u];
            ++edgeCount[v];
        }

        vector<int> layer(n, 0);
        queue<int> q;

        for(int i = 0; i < n; ++i) {
            if(edgeCount[i] == 1) {
                layer[i] = 1;
                q.push(i);
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto& v: adjList[u]) {
                if(edgeCount[v] > 1) {
                    --edgeCount[v];

                    if(edgeCount[v] == 1) {
                        layer[v] = layer[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; ++i) {
            if(layer[i] > k) ++ans;
        }

        printf("%d\n", ans);
    }
    

    return 0;
}
