#include <cstdio>
using namespace std;

const int N = 20+3;

const int dr[] = {0, 0, -1, 1};
const int dc[] = {-1, 1, 0, 0};

int w, h, cnt;
char grid[N][N];

void floodfill(int r, int c)
{
    if(r < 0 || h <= r || c < 0 || w <= c) return;
    if(grid[r][c] != '.') return;

    ++cnt;
    grid[r][c] = '#';

    for(int i = 0; i < 4; ++i)
        floodfill(r+dr[i], c+dc[i]);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &w, &h);

        int start_r = -1, start_c;

        for(int i = 0; i < h; ++i) {
            scanf("%s", grid[i]);

            if(start_r == -1) {
                for(int j = 0; j < w; ++j) {
                    if(grid[i][j] == '@') {
                        start_r = i, start_c = j;
                        break;
                    }
                }
            }
        }

        cnt = 0;
        grid[start_r][start_c]  = '.';
        floodfill(start_r, start_c);

        printf("Case %d: %d\n", tc, cnt);
    }

    return 0;
}
