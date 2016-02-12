#include <cstdio>
#include <algorithm>
using namespace std;

typedef     long long   LL;

int coins[21];
LL dp[21][10000];

LL fn(int idx, int toPay)
{
    if(toPay == 0) return 1;
    if(idx == 21) return 0;

    if(dp[idx][toPay] != -1) return dp[idx][toPay];

    LL ret = 0;

    for(int times = 0; toPay - coins[idx] * times >= 0; ++times)
            ret += fn(idx+1, toPay - coins[idx] * times);

    return dp[idx][toPay] = ret;
}

int main()
{
    for(int i = 1; i <= 21; ++i)
        coins[i-1] = i*i*i;

    fill(&dp[0][0], &dp[21][0], -1);

    int toPay;

    while(scanf("%d", &toPay) != EOF)
        printf("%lld\n", fn(0, toPay));

    return 0;
}
