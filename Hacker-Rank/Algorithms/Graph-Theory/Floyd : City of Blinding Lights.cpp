// ==================================================
// Problem  :   Floyd : City of Blinding Lights
// Score    :   75 /75
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX / 2;

int main()
{
    //freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    int adjMat[n+3][n+3];

    for(int i = 0; i < n; ++i)
        fill_n(&adjMat[i][0], n, INF);
    for(int i = 0; i < n; ++i)
        adjMat[i][i] = 0;

    int x, y, r;

    while(m--) {
        scanf("%d %d %d", &x, &y, &r);
        adjMat[--x][--y] = r;
    }

    for(int k = 0; k < n; ++k)          // Floyd-Warshall
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);

    int q;
    scanf("%d", &q);

    while(q--) {
        scanf("%d %d", &x, &y);
        --x, --y;
        printf("%d\n", ((adjMat[x][y] == INF)? -1 : adjMat[x][y]));
    }

    return 0;
}
