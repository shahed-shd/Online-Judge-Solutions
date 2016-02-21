#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 14;

int n;
int table[MAXN+1][MAXN+1], dp[(1<<MAXN)+3];

inline int biton(int n, int pos) { return n | (1<<pos); }
inline bool check(int n, int pos) { return n & (1<<pos); }

int fn(int mask)
{
    if(mask == (1<<n)-1) return 0;

    if(dp[mask] != -1) return dp[mask];

    int mini = INT_MAX;

    for(int i = 0; i < n; ++i) {
        if(check(mask, i) == 0) {
            int price = table[i][i];

            for(int j = 0; j < n; ++j)
                if(j != i && check(mask, j))
                    price += table[i][j];

            mini = min(mini, price+fn(biton(mask, i)));
        }
    }

    return dp[mask] = mini;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &table[i][j]);

        fill(dp, dp+((1<<MAXN)+3), -1);

        printf("Case %d: %d\n", tc, fn(0));
    }

    return 0;
}
