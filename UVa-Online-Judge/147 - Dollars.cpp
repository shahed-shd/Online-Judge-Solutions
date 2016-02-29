#include <cstdio>
#include <algorithm>
using namespace std;

typedef     long long   LL;

const int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
LL dp[11][30000+1];

LL fn(int idx, int amnt)
{
    if(amnt == 0) return 1;
    if(idx == 11) return 0;

    if(dp[idx][amnt] != -1) return dp[idx][amnt];

    LL cnt = 0;

    for(int i = 0; amnt - coins[idx] * i >= 0; ++i)
        cnt += fn(idx+1, amnt - coins[idx] * i);

    return dp[idx][amnt] = cnt;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    long double input;

    fill(&dp[0][0], &dp[11][0], -1);

    while(scanf("%Lf", &input), input != 0.00)
        printf("%6.2Lf%17lld\n", input, fn(0, (input*10)*10));  // input*100 causes error.
                        // Such as, (9.90 * 100) causes int casting as 989 in some compilers.
    return 0;
}
