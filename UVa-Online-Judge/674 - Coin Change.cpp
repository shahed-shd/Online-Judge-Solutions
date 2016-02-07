#include <cstdio>
#include <algorithm>
using namespace std;

const int coins[] = {50, 25, 10, 5, 1};

int dp[5][7490];

int fn(int i, int amount)
{
    if(amount == 0) return 1;
    if(i == 5) return 0;

    if(dp[i][amount] != -1) return dp[i][amount];

    int ret1 = (amount-coins[i] >= 0)? fn(i, amount-coins[i]) : 0;
    int ret2 = fn(i+1, amount);

    return dp[i][amount] = ret1 + ret2;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int toMake;

    fill(&dp[0][0], &dp[5][0], -1);

    while(scanf("%d", &toMake) != EOF)
        printf("%d\n", fn(0, toMake));

    return 0;
}
