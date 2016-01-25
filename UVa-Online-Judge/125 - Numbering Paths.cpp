// Run time: 0.000 sec.

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 30;

int main()
{
    //freopen("in", "r", stdin);

    int street, tc = 0;

    while(scanf("%d", &street) != EOF) {
        int u, v, n = 0, mat[MAXN][MAXN] = {0};

        while(street--) {
            scanf("%d %d", &u, &v);

            mat[u][v] = 1;
            n = max(n, max(u, v));
        }
        ++n;

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(mat[i][k] && mat[k][j])
                        mat[i][j] += mat[i][k] * mat[k][j];

        for(int k = 0; k < n; ++k)
            if(mat[k][k] != 0)  // Forms cycle.
                for(int i = 0; i < n; ++i)
                    for(int j = 0; j < n; ++j)
                        if(mat[i][k] && mat[k][j])
                            mat[i][j] = -1;

        printf("matrix for city %d\n", tc++);

        for(int i = 0; i < n; ++i) {
            printf("%d", mat[i][0]);

            for(int j = 1; j < n; ++j)
                printf(" %d", mat[i][j]);

            putchar('\n');
        }
    }

    return 0;
}


// ------------------------- Alternatively -------------------------
// Run time: 0.006 sec
/*

#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 30;

vector<bitset<MAXN> > mat;
vector<vector<int> > adjList;
vector<vector<int> > ans;
int start, n;

void dfs(int u)
{
    if(mat[u][u]) {     // Forms cycle.
        for(int i = 0; i < n; ++i)
            if(mat[u][i]) ans[start][i] = -1;

        return;
    }
    else if(start != u)
        ++ans[start][u];

    for(auto& x : adjList[u])
        dfs(x);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int street, tc = 0;

    while(scanf("%d", &street) != EOF) {
        mat.clear();
        adjList.clear();
        ans.clear();

        mat.resize(MAXN);
        adjList.resize(MAXN);

        int u, v;
        n = 0;

        for(int i = 0; i < street; ++i) {
            scanf("%d %d", &u, &v);

            mat[u][v] = true;
            adjList[u].push_back(v);

            n = max(n, max(u, v));
        }
        ++n;

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(mat[i][k] && mat[k][j])
                        mat[i][j] = true;

        ans.assign(n, vector<int>(n, 0));

        for(start = 0; start < n; ++start)
            dfs(start);

        printf("matrix for city %d\n", tc++);

        for(auto& xx : ans) {
            printf("%d", xx[0]);

            for(int i = 1; i < n; ++i)
                printf(" %d", xx[i]);

            putchar('\n');
        }
    }

    return 0;
}

*/
