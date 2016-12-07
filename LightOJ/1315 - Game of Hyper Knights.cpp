// ==================================================
// Problem  :   1315 - Game of Hyper Knights
// Run time :   0.044 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <bitset>
using namespace std;

const int MAXX = 500 + 3;

const int dx[] = {-3, -1, -2, -2, -1, +1};
const int dy[] = {-1, -3, +1, -1, -2, -2};

int board[MAXX][MAXX] = {0};

int main()
{
    //freopen("in", "r", stdin);

    // Preprocessing...

    for(int k = 1; k <= MAXX; ++k) {
        for(int x = k-1, y = 0; x >= 0; --x, ++y) {
            bitset<MAXX> b;

            for(int i = 0; i < 6; ++i) {
                int go_x = x + dx[i], go_y = y + dy[i];

                if(0 <= go_x && go_x < MAXX && 0 <= go_y && go_y < MAXX)
                    b[board[go_x][go_y]] = true;
            }

            for(int i = 0; ; ++i) {
                if(!b[i]) {
                    board[x][y] = i;
                    break;
                }
            }
        }
    }

    int y_start = 0;

    for(int k = MAXX-1; k >= 1; --k) {
        for(int x = MAXX-1, y = ++y_start; x >= y_start; --x, ++y) {
            bitset<MAXX> b;

            for(int i = 0; i < 6; ++i) {
                int go_x = x + dx[i], go_y = y + dy[i];

                if(0 <= go_x && go_x < MAXX && 0 <= go_y && go_y < MAXX)
                    b[board[go_x][go_y]] = true;
            }

            for(int i = 0; ; ++i) {
                if(!b[i]) {
                    board[x][y] = i;
                    break;
                }
            }
        }
    }

    // Preprocessing complete.

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, x, y;
        scanf("%d", &n);

        int res = 0;

        while(n--) {
            scanf("%d %d", &x, &y);
            res ^= board[x][y];
        }

        printf("Case %d: %s\n", tc, (res)? "Alice" : "Bob");
    }

    return 0;
}
