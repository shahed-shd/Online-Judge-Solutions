#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 30, MAXT = 1000+1;

int n, W, depth[MAXN], quantity[MAXN], dp[MAXN][MAXT];
bool dir[MAXN][MAXT];

int knapsack(int idx, int remainingTime)
{
    if(idx == n) return 0;

    if(dp[idx][remainingTime] != -1)
        return dp[idx][remainingTime];

    int ret1 = (remainingTime - W * depth[idx] >= 0)? quantity[idx] + knapsack(idx+1, remainingTime - W * depth[idx]) : 0;
    int ret2 = knapsack(idx+1, remainingTime);

    if(ret1 > ret2) {
        dp[idx][remainingTime] = ret1;
        dir[idx][remainingTime] = true;
    }
    else {
        dp[idx][remainingTime] = ret2;
        dir[idx][remainingTime] = false;
    }

    return dp[idx][remainingTime];
}

void solution_print(int n, int tm)
{
    bool isTaken[n];
    fill_n(isTaken, n, false);

    int cnt = 0;

    for(int i = 0; i < n; ++i) {
        if(dir[i][tm]) {
            isTaken[i] = true;
            ++cnt;
            tm -= depth[i] * W;
        }
    }

    printf("%d\n", cnt);

    for(int i = 0; i < n; ++i)
        if(isTaken[i])
            printf("%d %d\n", depth[i], quantity[i]);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, w;
    bool newline = false;

    while(scanf("%d %d", &t, &w) != EOF) {
        W = 3 * w;

        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
            scanf("%d %d", depth+i, quantity+i);

        fill(&dp[0][0], &dp[MAXN][0], -1);
        fill(&dir[0][0], &dir[MAXN][0], false);

        if(newline) putchar('\n');
        newline = true;

        printf("%d\n", knapsack(0, t));

        solution_print(n, t);
    }

    return 0;
}
