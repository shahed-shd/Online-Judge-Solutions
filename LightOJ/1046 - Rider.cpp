// ==================================================
// Problem  :   1046 - Rider
// Run time :   0.012 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <bitset>
#include <queue>
#include <climits>
using namespace std;

const int MAXN = 10 + 3;

const int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

int m, n;
int mv[MAXN][MAXN], reachedRiderCnt[MAXN][MAXN];

struct node {
    int x, y, jump;
    node(int a, int b, int c) {
        x = a, y = b, jump = c;
    }
};

void bfs(int sx, int sy, int k)
{
    queue<node> q;
    q.push(node(sx, sy, 0));

    bitset<MAXN> vis[MAXN];

    vis[sx][sy] = true;
    ++reachedRiderCnt[sx][sy];

    while(!q.empty()) {
        int x = q.front().x, y = q.front().y;
        int jump = q.front().jump + 1;
        q.pop();

        for(int i = 0; i < 8; ++i) {
            int xx = x + dx[i], yy = y + dy[i];

            if(0 <= xx && xx < m && 0 <= yy && yy < n && !vis[xx][yy]) {
                vis[xx][yy] = true;
                ++reachedRiderCnt[xx][yy];
                mv[xx][yy] += jump / k + (jump % k != 0);
                q.push(node(xx, yy, jump));
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    char board[MAXN][MAXN];

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &m, &n);

        for(int i = 0; i < m; ++i)
            scanf("%s", &board[i][0]);

        int totalRider = 0;

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                mv[i][j] = reachedRiderCnt[i][j] = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] != '.') {
                    ++totalRider;
                    bfs(i, j, board[i][j] - '0');
                }
            }
        }

        int ans = INT_MAX;

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(reachedRiderCnt[i][j] == totalRider)
                    ans = min(ans, mv[i][j]);

        if(ans == INT_MAX) ans = -1;

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
