#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

typedef     long long   LL;

const int MAXN = 20+2;

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        LL grid[MAXN][MAXN][MAXN] = {{{0}}};

        for(int i = 1; i <= a; ++i) {
            for(int j = 1; j <= b; ++j) {
                for(int k = 1; k <= c; ++k) {
                    LL& tmp = grid[i][j][k];

                    scanf("%lld", &tmp);

                    tmp += grid[i][j-1][k];
                    tmp += grid[i][j][k-1];
                    tmp -= grid[i][j-1][k-1];

                    tmp += grid[i-1][j][k];
                    tmp -= grid[i-1][j-1][k];
                    tmp -= grid[i-1][j][k-1];
                    tmp += grid[i-1][j-1][k-1];
                }
            }
        }

        LL mx = LLONG_MIN;

        for(int i = 1; i <= a; ++i) {
            for(int j = 1; j <= b; ++j) {
                for(int k = 1; k <= c; ++k) {

                    for(int x = i; x <= a; ++x) {
                        for(int y = j; y <= b; ++y) {
                            for(int z = k; z <= c; ++z) {
                                LL tmp = grid[x][y][z];

                                tmp -= grid[x][j-1][z];
                                tmp -= grid[x][y][k-1];
                                tmp += grid[x][j-1][k-1];

                                tmp -= grid[i-1][y][z];
                                tmp += grid[i-1][j-1][z];
                                tmp += grid[i-1][y][k-1];
                                tmp -= grid[i-1][j-1][k-1];

                                mx = max(mx, tmp);
                            }
                        }
                    }
                }
            }
        }

        printf("%lld\n", mx);
        if(tc) putchar('\n');
    }

    return 0;
}
