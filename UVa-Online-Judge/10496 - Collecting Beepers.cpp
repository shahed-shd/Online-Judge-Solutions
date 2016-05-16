#include <cstdio>
#include <bitset>
#include <queue>
using namespace std;

typedef     pair<int,int>   ii;

const int MAXS = 20+3;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int xSize, ySize, start_x, start_y;
bitset<MAXS> grid[MAXS];

int bfs(int sx, int sy, int &tx, int &ty)
{
    queue<ii> q;

    int level[xSize][ySize];
    fill_n(&level[0][0], xSize*ySize, -1);

    level[sx][sy] = 0;
    q.push(ii(sx, sy));

    while(!q.empty()) {
        ii u = q.front(); q.pop();

        if(grid[u.first][u.second]) {
            tx = u.first, ty = u.second;
            return level[tx][ty];
        }

        for(int i = 0; i < 4; ++i) {
            int vx = u.first+dx[i], vy = u.second+dy[i];

            if(0 <= vx && vx < xSize && 0 <= vy && vy < ySize && level[vx][vy] == -1) {
                level[vx][vy] = level[u.first][u.second] + 1;
                q.push(ii(vx, vy));
            }
        }
    }

    return 0;   // Just to avoid warning.
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        for(int i = 0; i < MAXS; ++i)
            grid[i].reset();

        int beeper;

        scanf("%d %d %d %d %d", &xSize, &ySize, &start_x, &start_y, &beeper);
        --start_x, --start_y;

        int x, y;

        for(int i = 0; i < beeper; ++i) {
            scanf("%d %d", &x, &y);
            grid[--x][--y] = true;
        }

        int sx = start_x, sy = start_y, tx, ty, distSum = 0;

        for(int i = 0; i < beeper; ++i) {
            distSum += bfs(sx, sy, tx, ty);
            grid[tx][ty] = false;
            sx = tx, sy = ty;
        }

        grid[start_x][start_y] = true;
        distSum += bfs(sx, sy, tx, ty);

        printf("The shortest path has length %d\n", distSum);
    }

    return 0;
}
