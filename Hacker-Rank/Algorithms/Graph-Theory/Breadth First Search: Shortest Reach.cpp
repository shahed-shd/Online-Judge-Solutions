// ==================================================
// Problem  :   Breadth First Search: Shortest Reach
// Score	:   55 /55
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int> > adjList;

void bfs(int s, int n)
{
    queue<int> q;
    q.push(s);

    int dist[n+3];
    fill_n(dist, n+3, -1);
    dist[s] = 0;

    int u;
    while(!q.empty()) {
        u = q.front(); q.pop();

        for(auto& v : adjList[u]) {
            if(dist[v] == -1) {     // That is, v is not visited.
                dist[v] = dist[u] + 6;
                q.push(v);
            }
        }
    }

    bool isFirst = true;

    for(int i = 0; i < n; ++i) {
        if(i != s) {
            if(isFirst) isFirst = false;
            else putchar(' ');

            printf("%d", dist[i]);
        }
    }
    putchar('\n');
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int qry;
    scanf("%d", &qry);

    while(qry--) {
        adjList.clear();

        int n, m;
        scanf("%d %d", &n, &m);

        adjList.resize(n);
        int u, v, s;

        while(m--) {
            scanf("%d %d", &u, &v);
            --u, --v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        scanf("%d", &s);

        bfs(--s, n);
    }

    return 0;
}
