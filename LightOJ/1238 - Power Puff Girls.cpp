// ==================================================
// Problem  :   1238 - Power Puff Girls
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <queue>
using namespace std;

#define     ff          first
#define     ss          second

typedef     pair<int,int>       ii;

const int MAXN = 20 + 3;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int hr, hc, ar, ac, br, bc, cr, cc;
char grid[MAXN][MAXN];

int bfs()
{
    queue<ii> q;
    int dist[MAXN][MAXN] = {{0}};

    q.push(ii(hr, hc));
    dist[hr][hc] = 0;
    grid[hr][hc] = '#';

    while(!q.empty()) {
        int ux = q.front().ff, uy = q.front().ss; q.pop();

        for(int i = 0; i < 4; ++i) {
            int vx = ux+dx[i], vy = uy+dy[i];
            char ch = grid[vx][vy];

            if(!dist[vx][vy] && ch != '#' && ch != 'm') {
                dist[vx][vy] = dist[ux][uy] + 1;
                q.push(ii(vx, vy));
            }
        }
    }

    return max(dist[ar][ac], max(dist[br][bc], dist[cr][cc]));
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int m, n;
        scanf("%d %d", &m, &n);

        hr = -1, ar = -1, br = -1, cr = -1;

        for(int i = 0; i < m; ++i) {
            scanf("%s", &grid[i][0]);

            if(hr == -1 || ar == -1 || br == -1 || cr == -1) {
                for(int j = 0; j < n; ++j) {
                    char ch = grid[i][j];

                    if(ch == 'h') hr = i, hc = j;
                    else if(ch == 'a') ar = i, ac = j;
                    else if(ch == 'b') br = i, bc = j;
                    else if(ch == 'c') cr = i, cc = j;
                }
            }
        }

        printf("Case %d: %d\n", tc, bfs());
    }

    return 0;
}
