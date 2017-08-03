// ==================================================
// Problem  :   1232 - Coin Change (II)
// Run time :   0.672 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 3;
const int MAXK = 10000 + 3;
const int MOD = 100000007;

int coins[MAXN];
int memo[MAXK];

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, k;
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; ++i) scanf("%d", coins+i);

        fill(memo, memo+k+1, 0);
        memo[0] = 1;

        for(int i = 0; i < n; ++i) {
            for(int j = 1; j <= k; ++j) {
                if(coins[i] <= j) {
                    memo[j] += memo[j - coins[i]];
                    if(memo[j] >= MOD) memo[j] %= MOD;
                }
            }
        }

        printf("Case %d: %d\n", tc, memo[k]);
    }

    return 0;
}
