// ==================================================
// Problem  :   Grid Challenge
// Score    :   20 /20
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 3;

char grid[MAXN][MAXN];

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) {
            scanf("%s", &grid[i][0]);
            sort(&grid[i][0], &grid[i][n]);
        }

        bool flag = true;

        for(int col = 0; col < n; ++col) {
            for(int row = 1; row < n; ++row) {
                if(grid[row-1][col] > grid[row][col]) {
                    flag = false;
                    break;
                }
            }
        }

        puts((flag)? "YES" : "NO");
    }

    return 0;
}
