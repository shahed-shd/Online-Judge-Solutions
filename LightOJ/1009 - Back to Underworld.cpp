#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 20000+3;

vector<vector<int> > adjList;
bitset<MAXN> visited;
int cnt1, cnt2;

void dfs(int u, bool race)
{
    int sz = adjList[u].size();
    if(!sz) return;

    visited[u] = true;
    (race)? ++cnt1 : ++cnt2;

    for(int i = 0; i < sz; ++i) {
        int v = adjList[u][i];
        if(!visited[v]) dfs(v, !race);
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        visited.reset();

        adjList.resize(MAXN);

        int n, u, v, N = 0;
        scanf("%d", &n);

        while(n--) {
            scanf("%d %d", &u, &v);

            adjList[u].push_back(v);
            adjList[v].push_back(u);

            N = max(N, max(u, v));
        }

        int maxCnt = 0;

        for(int i = 1; i <= N; ++i) {
            if(!visited[i]) {
                cnt1 = cnt2 = 0;
                dfs(i, true);
                maxCnt += max(cnt1, cnt2);
            }
        }

        printf("Case %d: %d\n", tc, maxCnt);
    }

    return 0;
}
