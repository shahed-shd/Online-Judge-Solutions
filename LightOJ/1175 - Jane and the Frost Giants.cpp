// ==================================================
// Problem  :   1175 - Jane and the Frost Giants
// Run time :   0.112 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXR = 200 + 3;
const int INF = INT_MAX;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int row, col;
char mat[MAXR][MAXR];

int distF[MAXR][MAXR], distJ[MAXR][MAXR];

void bfs(vector<ii> &Vxy, int dist[MAXR][MAXR])
{
    queue<ii> q;

    for(unsigned i = 0; i < Vxy.size(); ++i) {
        q.push(Vxy[i]);
        dist[Vxy[i].first][Vxy[i].second] = 0;
    }

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int xx = x+dx[i], yy = y+dy[i];

            if(0 <= xx && xx < row && 0 <= yy && yy < col && mat[xx][yy] != '#' && dist[x][y]+1 < dist[xx][yy]) {
                dist[xx][yy] = dist[x][y] + 1;
                q.push(ii(xx, yy));
            }
        }
    }

}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &row, &col);

        for(int i = 0; i < row; ++i)
            scanf("%s", &mat[i][0]);

        fill(&distF[0][0], &distF[row][0], INF);
        fill(&distJ[0][0], &distJ[row][0], INF);

        vector<ii> Fxy;

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(mat[i][j] == 'F') {
                    Fxy.push_back(ii(i, j));
                }
                else if(mat[i][j] == 'J') {
                    vector<ii> Jxy(1, ii(i, j));
                    bfs(Jxy, distJ);
                }

            }
        }

        bfs(Fxy, distF);

        int ans = INF;

        for(int i = 0; i < col; ++i)
            if(distJ[0][i] < distF[0][i])
                ans = min(ans, distJ[0][i]+1);

        for(int i = 0; i < col; ++i)
            if(distJ[row-1][i] < distF[row-1][i])
                ans = min(ans, distJ[row-1][i]+1);

        for(int i = 0; i < row; ++i)
            if(distJ[i][0] < distF[i][0])
                ans = min(ans, distJ[i][0]+1);

        for(int i = 0; i < row; ++i)
            if(distJ[i][col-1] < distF[i][col-1])
                ans = min(ans, distJ[i][col-1]+1);

        printf("Case %d: ", tc);

        if(ans == INF) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }

    return 0;
}
