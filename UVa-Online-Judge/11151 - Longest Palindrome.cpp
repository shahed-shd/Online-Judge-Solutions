#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const short MAXL = 1000+3;

char str[MAXL];
short len, dp[MAXL][MAXL];

short LCS(short i, short j)
{
    if(i == len || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    short ret;

    if(str[i] == str[j])
        ret = 1 + LCS(i+1, j-1);
    else
        ret = max(LCS(i+1, j), LCS(i, j-1));

    return dp[i][j] = ret;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);
    getchar();

    while(t--) {
        fgets(str, sizeof(str), stdin);

        len = strlen(str);

        if(!len || str[0] == '\n') {
            puts("0");
            continue;
        }

        fill(&dp[0][0], &dp[MAXL][0], -1);

        int ans = LCS(0, len-1);

        printf("%d\n", ((ans)?: 1));
    }

    return 0;
}
