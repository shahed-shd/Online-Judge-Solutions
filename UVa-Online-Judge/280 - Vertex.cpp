// Run time : 0.109 sec

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int n;

    while(scanf("%d", &n), n) {
        bool mat[n][n];
        fill_n(&mat[0][0], n*n, false);

        int u, v;

        while(scanf("%d", &u), u) {
            --u;
            while(scanf("%d", &v), v)
                mat[u][--v] = true;
        }

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(mat[i][k] && mat[k][j])
                        mat[i][j] = true;

        int s;
        scanf("%d", &s);

        while(s--) {
            scanf("%d", &u);
            --u;

            vector<int> inaccessible;

            for(int i = 0; i < n; ++i)
                if(!mat[u][i])
                    inaccessible.push_back(i+1);

            printf("%u", inaccessible.size());

            for(auto& x : inaccessible)
                printf(" %d", x);

            putchar('\n');
        }
    }

    return 0;
}


// ------------------------ Alternatively ------------------------
// Run time : 0.115 sec
/*

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
    ios::sync_with_stdio(false);
    
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

*/
