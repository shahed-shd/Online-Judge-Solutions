// ==================================================
// Problem  :   M-Coloring Problem
// Run time :   0.069 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 50 + 3;

int mat[MAXN][MAXN];
int sizeAdj[MAXN];
int colors[MAXN];
int m;

bool dfs(int u, int clr)
{
    int sz = sizeAdj[u];

    for(int i = 0; i < sz; ++i)
        if(colors[mat[u][i]] == clr)
            return false;

    colors[u] = clr;

    for(int i = 0; i < sz; ++i) {
        int v = mat[u][i];
        if(!colors[v]) {        // v has not assigned any color, that is, v is not visited.
            int vClr;
            for(vClr = 1; vClr <= m; ++vClr) {
                if(vClr == clr) continue;   // u and v can't have same color.
                if(dfs(v, vClr)) break;
            }

            if(vClr > m) {      // v can't have any of the m colors.
                colors[u] = 0;
                return false;
            }
        }
    }

    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int nodeNum, edgeNum;
        scanf("%d %d %d", &nodeNum, &m, &edgeNum);

        fill(sizeAdj, sizeAdj+nodeNum+3, 0);
        int u, v;

        while(edgeNum--) {
            scanf("%d %d", &u, &v);

            mat[u][sizeAdj[u]++] = v;
            mat[v][sizeAdj[v]++] = u;
        }

        fill(colors, colors+nodeNum+3, 0);
        bool flag = true;

        for(int i = 1; i <= nodeNum; ++i) {     // The graph may not be connected.
            if(!colors[i]) {
                if(dfs(i, 1) == false) {
                    flag = false;
                    break;
                }
            }
        }

        puts((flag)? "1" : "0");
    }

    return 0;
}
