// ==================================================
// Problem  :   1223 - Testing Mailboxes
// Run time :   0.088 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXK = 100 + 3;

int memo[MAXK][MAXK][MAXK] = {{{0}}};   // memo[i][j][k] indicates the use of i boxes with j to k firecrackers.

int main()
{
    for(int i = 0; i < MAXK; ++i)
        for(int j = i; j < MAXK; ++j)
            memo[1][i][j] = (j-i+1) * (i+j) / 2;

    for(int i = 2; i < MAXK; ++i) {
        for(int j = MAXK-1; j >= 1; --j) {
            for(int k = j; k < MAXK; ++k) {
                int &rf = memo[i][j][k];
                rf = INT_MAX;

                for(int x = j; x <= k; ++x) {
                    rf = min(rf, x + max(memo[i-1][j][x-1], memo[i][x+1][k]));
                }
            }
        }
    }

    // DP pre-process complete.

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int k, m;
        scanf("%d %d", &k, &m);

        printf("Case %d: %d\n", tc, memo[k][1][m]);
    }

    return 0;
}
