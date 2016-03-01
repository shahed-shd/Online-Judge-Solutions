#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 20+1;

int n, correct[MAXN], student[MAXN], dp[MAXN][MAXN];

int LCS(int i1, int i2)
{
    if(i1 == n+1 || i2 == n+1) return 0;

    if(dp[i1][i2] != -1) return dp[i1][i2];

    return dp[i1][i2] = (correct[i1] == student[i2])? 1+LCS(i1+1, i2+1) : max(LCS(i1+1, i2), LCS(i1, i2+1));
}

int main()
{
    //freopen("in", "r", stdin);

    scanf("%d", &n);

    int tmp;

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        correct[tmp] = i;
    }

    while(scanf("%d", &tmp) != EOF) {
        student[tmp] = 1;

        for(int i = 2; i <= n; ++i) {
            scanf("%d", &tmp);
            student[tmp] = i;
        }

        fill_n(&dp[0][0], MAXN*MAXN, -1);

        printf("%d\n", LCS(1, 1));
    }

    return 0;
}
