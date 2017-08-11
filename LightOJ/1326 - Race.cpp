// ==================================================
// Problem  :   1326 - Race
// Run time :   0.012 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

const int MAXN = 1000 + 3;
const int MOD = 10056;

int bc[MAXN][MAXN];
int memo[MAXN];

int main()
{
    for(int i = 0; i < MAXN; ++i)
        bc[i][0] = bc[i][i] = 1;

    for(int i = 2; i < MAXN; ++i)
        for(int j = 1; j < i; ++j)
            bc[i][j] = (bc[i-1][j] + bc[i-1][j-1]) % MOD;

    memo[0] = memo[1] = 1;

    for(int i = 2; i < MAXN; ++i) {
        memo[i] = 0;
        for(int j = 1; j <= i; ++j) {
            memo[i] += bc[i][j] * memo[i-j];
            memo[i] %= MOD;
        }
    }

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        printf("Case %d: %d\n", tc, memo[n]);
    }

    return 0;
}
